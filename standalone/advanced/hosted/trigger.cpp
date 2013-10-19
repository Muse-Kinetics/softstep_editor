// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "trigger.h"

Trigger::Trigger()
{
    TriggerWorker fastTriggerWorker;
    //TriggerWorker dblTriggerWorker;
    //TriggerWorker offTriggerWorker;
    //TriggerWorker deltaTriggerWorker;

    fastTriggerWorker.moveToThread(&fastTriggerThread);
    connect(&fastTriggerWorker, SIGNAL(signalSendTriggerTimeout()), this, SLOT(slotFastTriggerReturn()));
    waitTriggerThread.start();
}

void Trigger::slotWaitTrigger()
{
    //triggerWorker->slotStartTriggerClock();
}

void Trigger::slotWaitTriggerReturn()
{
    qDebug() << "Wait Returned";
    //waitTriggerThread.quit();
}

void Trigger::slotFastTrigger()
{
    qDebug() << "slotFastTriggerCalled";

    fastTriggerThread.start();
    //triggerWorker->slotStartTriggerClock();
}

void Trigger::slotFastTriggerReturn()
{
    qDebug() << "fast trigger return quit";
    fastTriggerThread.quit();
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
