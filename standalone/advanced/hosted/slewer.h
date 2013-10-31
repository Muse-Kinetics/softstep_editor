// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SLEWER_H
#define SLEWER_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include "math.h"

class Slewer : public QWidget
{
    Q_OBJECT
public:
    explicit Slewer(QWidget *parent = 0);

    double          position;
    double          destination;
    double          velocity;
    QTimer*         timer;

    int lastOutput;
    
signals:
    void            signalOutput(int output);

public slots:
    void            slotSlew(double target, double time);
    void            slotUpdate();


};

#endif // SLEWER_H
