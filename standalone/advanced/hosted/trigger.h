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

public:
    Trigger();

    void fastTrigger();

    void longTriggerStart();
    void longTriggerAbort();

    void dblTriggerHit();
    void dblTriggerAbort();
    bool dblWindowIsOpen;
    int  dblHitCount;

    void offTrigger();

signals:
    //To DataCooker
    void signalFastTriggerReturn();
    void signalLongTriggerReturn();
    void signalDblTriggerReturn();
    void signalOffTriggerReturn();

    //To Trigger Worker
    void signalStartTriggerClock(int timeout);
    void signalAbortClock();

public slots:
    void slotFastTriggerReturn();
    void slotLongTriggerReturn();
    void slotDblTriggerReturn();
    void slotOffTriggerReturn();

    void slotDeltaTrigger();
    void slotDeltaTriggerReturn();

    //void slotAbortTrigger();
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
