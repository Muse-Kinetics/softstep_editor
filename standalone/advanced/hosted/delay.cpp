// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "delay.h"

Delay::Delay(QObject *parent) :
    QObject(parent)
{
}

void Delay::slotInputToDealy(int i)
{
    qDebug() << "delay input";
    buffer.append(i);
    QTimer::singleShot(delayTime, this, SLOT(slotSendOutput()));
}

void Delay::slotSendOutput()
{
    emit signalDelayedOutput(buffer.first());
    buffer.removeFirst();
}
