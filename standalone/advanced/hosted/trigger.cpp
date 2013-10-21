// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "trigger.h"

Trigger::Trigger()
{

    TriggerWorker* fastTriggerWorker = new TriggerWorker;
    TriggerWorker* longTriggerWorker = new TriggerWorker;
    //TriggerWorker offTriggerWorker;
    //TriggerWorker deltaTriggerWorker;

    //Fast
    fastTriggerWorker->moveToThread(&fastTriggerThread);
    connect(this, SIGNAL(signalStartFastTriggerClock()), fastTriggerWorker, SLOT(slotStartTriggerClock()));
    connect(fastTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotFastTriggerReturn()));

    //Long
    longTriggerWorker->moveToThread(&fastTriggerThread);
    connect(this, SIGNAL(signalStartLongTriggerClock()), longTriggerWorker, SLOT(slotStartTriggerClock()));
    connect(longTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotLongTriggerReturn()));
}

void Trigger::longTrigger()
{
    longTriggerThread.start();
    emit signalStartLongTriggerClock();
}

void Trigger::slotLongTriggerReturn()
{
    qDebug() << "Long Returned";
    //waitTriggerThread.quit();
}

void Trigger::fastTrigger()
{
    qDebug() << "slotFastTriggerCalled";

    fastTriggerThread.start();
    emit signalStartFastTriggerClock();
    //fastTriggerWorker->slotStartTriggerClock();
}

void Trigger::slotFastTriggerReturn()
{
    qDebug() << "fast trigger return quit";
    fastTriggerThread.quit();
    emit signalFastTriggerReturn();
}

void Trigger::slotDblTrigger()
{

}

void Trigger::slotDblTriggerReturn()
{

}

void Trigger::slotOffTrigger()
{

}

void Trigger::slotOffTriggerReturn()
{

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

void TriggerWorker::slotStartTriggerClock()
{
    qDebug() << "start trigger clock";
    QTimer::singleShot(100, this, SLOT(slotReturnTriggerTimeout()));
}

void TriggerWorker::slotReturnTriggerTimeout()
{
    emit signalSendTriggerTimeout();
}
