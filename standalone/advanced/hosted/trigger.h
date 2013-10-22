// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef TRIGGER_H
#define TRIGGER_H

#include <QTimer>
#include <QThread>
#include <QDebug>

class Trigger : public QObject
{
    Q_OBJECT
    QThread longTriggerThread;
    QThread fastTriggerThread;
    QThread dblTriggerThread;
    QThread offTriggerThread;
    QThread deltaTriggerThread;

    QThread longTriggerLatchThread;
    QThread fastTriggerLatchThread;
    QThread dblTriggerLatchThread;

public:
    Trigger();

    void fastTrigger();

    void longTrigger();
    void longTriggerAbort();

    void dblTriggerHit();
    void dblTriggerAbort();
    bool dblWindowIsOpen;
    int  dblHitCount;

    void offTrigger();

    void deltaTrigger();

    //---------- Latch
    void fastTriggerLatch();

    void dblTriggerLatchHit();
    void dblTriggerLatchAbort();
    bool dblLatchWindowIsOpen;
    int  dblLatchHitCount;

    void longTriggerLatch();
    void longTriggerLatchAbort();

signals:
    //To DataCooker
    void signalFastTriggerReturn();
    void signalLongTriggerReturn();
    void signalDblTriggerReturn();
    void signalOffTriggerReturn();

    //---- Latch
    void signalFastTriggerLatchReturn();
    void signalDblTriggerLatchReturn();
    void signalLongTriggerLatchReturn();

    //To Trigger Worker
    void signalStartTriggerClock(int timeout);
    void signalAbortClock();

public slots:
    void slotFastTriggerReturn();
    void slotLongTriggerReturn();
    void slotDblTriggerReturn();
    void slotOffTriggerReturn();
    void slotDeltaTriggerReturn();

    //---- Latch
    void slotFastTriggerLatchReturn();
    void slotDblTriggerLatchReturn();
    void slotLongTriggerLatchReturn();
};

class TriggerWorker : public QObject
{
    Q_OBJECT

public:
    TriggerWorker();
    ~TriggerWorker();

    QTimer* clock;

signals:
    void signalSendTriggerTimeout();

public slots:
    void slotStartTriggerClock(int timeout);
    void slotAbortTriggerClock();
    void slotReturnTriggerTimeout();

};
#endif // TRIGGER_H
