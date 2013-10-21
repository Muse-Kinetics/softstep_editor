// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "trigger.h"

#define FAST_TRIG_TIMEOUT 0
#define OFF_TRIG_TIMEOUT 0
#define LONG_TRIG_TIMEOUT 1000
#define DBL_TRIG_WINDOW 600

Trigger::Trigger()
{

    TriggerWorker* fastTriggerWorker = new TriggerWorker;
    TriggerWorker* longTriggerWorker = new TriggerWorker;
    TriggerWorker* dblTriggerWorker = new TriggerWorker;
    TriggerWorker* offTriggerWorker = new TriggerWorker;

    //TriggerWorker deltaTriggerWorker;

    //Fast
    fastTriggerWorker->moveToThread(&fastTriggerThread);
    connect(this, SIGNAL(signalStartTriggerClock(int)), fastTriggerWorker, SLOT(slotStartTriggerClock(int)));
    connect(fastTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotFastTriggerReturn()));
    connect(this, SIGNAL(signalAbortClock()), fastTriggerWorker, SLOT(slotAbortTriggerClock()));

    //Long
    longTriggerWorker->moveToThread(&longTriggerThread);
    connect(this, SIGNAL(signalStartTriggerClock(int)), longTriggerWorker, SLOT(slotStartTriggerClock(int)));
    connect(longTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotLongTriggerReturn()));
    connect(this, SIGNAL(signalAbortClock()), longTriggerWorker, SLOT(slotAbortTriggerClock()));

    //Dbl
    dblWindowIsOpen = false;
    dblHitCount = 0;
    dblTriggerWorker->moveToThread(&dblTriggerThread);
    connect(this, SIGNAL(signalStartTriggerClock(int)), dblTriggerWorker, SLOT(slotStartTriggerClock(int)));
    connect(dblTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotDblTriggerReturn()));
    connect(this, SIGNAL(signalAbortClock()), dblTriggerWorker, SLOT(slotAbortTriggerClock()));

    //Off
    offTriggerWorker->moveToThread(&offTriggerThread);
    connect(this, SIGNAL(signalStartTriggerClock(int)), offTriggerWorker, SLOT(slotStartTriggerClock(int)));
    connect(offTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotOffTriggerReturn()));
    connect(this, SIGNAL(signalAbortClock()), offTriggerWorker, SLOT(slotAbortTriggerClock()));
}

//---------------------------------------- Long
void Trigger::longTriggerStart()
{
    longTriggerThread.start();
    emit signalStartTriggerClock(LONG_TRIG_TIMEOUT);
}

void Trigger::longTriggerAbort()
{
    emit signalAbortClock();
    longTriggerThread.quit();
}

void Trigger::slotLongTriggerReturn()
{
    longTriggerThread.quit();
    emit signalLongTriggerReturn();
}

//---------------------------------------- Fast
void Trigger::fastTrigger()
{
    //No delay on trigger, but still need extra thread for delayed trigger-off message
    fastTriggerThread.start();
    emit signalStartTriggerClock(FAST_TRIG_TIMEOUT);
}

void Trigger::slotFastTriggerReturn()
{
    fastTriggerThread.quit();
    emit signalFastTriggerReturn();
}

//---------------------------------------- Dbl
void Trigger::dblTriggerHit()
{
    if(!dblWindowIsOpen)
    {
        dblHitCount = 1;
        dblWindowIsOpen = true;
        dblTriggerThread.start();
        emit signalStartTriggerClock(DBL_TRIG_WINDOW);
    }
    else
    {
        dblHitCount = 0;
        dblWindowIsOpen = false;
        emit signalAbortClock();
        emit signalDblTriggerReturn();
        dblTriggerThread.quit();
    }
}

void Trigger::dblTriggerAbort()
{
    emit signalAbortClock();
}

void Trigger::slotDblTriggerReturn()
{
    dblTriggerThread.quit();
    dblHitCount = 0;
    dblWindowIsOpen = false;
}

//---------------------------------------- Off
void Trigger::offTrigger()
{
    //No delay on trigger, but still need extra thread for delayed trigger-off message
    offTriggerThread.start();
    emit signalStartTriggerClock(OFF_TRIG_TIMEOUT);
}

void Trigger::slotOffTriggerReturn()
{
    qDebug() << "off trigger";
    offTriggerThread.quit();
    emit signalOffTriggerReturn();
}

void Trigger::slotDeltaTrigger()
{

}

void Trigger::slotDeltaTriggerReturn()
{

}


//--------------------- Trigger Worker

TriggerWorker::TriggerWorker()
{

}

TriggerWorker::~TriggerWorker()
{

}

void TriggerWorker::slotStartTriggerClock(int timeout)
{
    qDebug() << "start trigger clock";

    clock = new QTimer(this);
    connect(clock, SIGNAL(timeout()), this, SLOT(slotReturnTriggerTimeout()));
    clock->setSingleShot(true);
    clock->start(timeout);
}

void TriggerWorker::slotAbortTriggerClock()
{
    clock->stop();
}

void TriggerWorker::slotReturnTriggerTimeout()
{
    qDebug() << "trigger timed out";
    emit signalSendTriggerTimeout();
}
