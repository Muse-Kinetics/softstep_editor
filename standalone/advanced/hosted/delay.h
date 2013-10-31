// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef DELAY_H
#define DELAY_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Delay : public QObject
{
    Q_OBJECT
public:
    explicit Delay(QObject *parent = 0);

    int delayTime;
    QList<int> buffer;
    
signals:
    void signalDelayedOutput(int);

public slots:
    void slotInputToDealy(int i);
    void slotSendOutput();
    
};

#endif // DELAY_H
