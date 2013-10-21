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
    void longTrigger();

signals:
    //To DataCooker
    void signalFastTriggerReturn();
    void signalLongTriggerReturn();

    //To Trigger Worker
    void signalStartFastTriggerClock();
    void signalStartLongTriggerClock();


public slots:
    void slotFastTriggerReturn();
    void slotLongTriggerReturn();



    void slotDblTrigger();
    void slotDblTriggerReturn();

    void slotOffTrigger();
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

signals:
    void signalSendTriggerTimeout();

public slots:
    void slotStartTriggerClock();
    void slotReturnTriggerTimeout();

};
#endif // TRIGGER_H
