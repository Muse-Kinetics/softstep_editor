// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef LATCHER_H
#define LATCHER_H

#include <QTimer>

class Latcher : public QTimer
{
public:
    Latcher();

    QList<int> fifo;

    int latchInput(int);

public slots:
    int slotDrainFIFO();
};

#endif // LATCHER_H
