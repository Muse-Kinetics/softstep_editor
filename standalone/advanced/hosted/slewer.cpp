// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "slewer.h"

Slewer::Slewer(QWidget *parent):
    QWidget(parent)
{

    timer = new QTimer(this);
    position = 0;
    velocity = 0;

    lastOutput = -1;

    connect(timer, SIGNAL(timeout()), this, SLOT(slotUpdate()));

}

void Slewer::slotSlew(double target, double time) // Using int for target
{
    if(target < 0) target = 0; // Ensure target is within bounds
    else if(target > 127) target = 127;

    if(target != destination) // If new destination, update velocity
    {
        destination = target;

        // Check if time is non-zero to avoid division by zero
        if (time > 0)
            velocity = (destination - position) / time;
        else
            velocity = destination - position; // Instant jump if time is 0

        if(!timer->isActive())
            timer->start(1);
    }
}

void Slewer::slotUpdate()
{
    if((int)position != (int)destination)
    {
        position += velocity;
        position = qBound(0.0, position, 127.0); // Ensure position does not exceed MIDI bounds
    }
    else
    {
        timer->stop();
    }

    if(lastOutput != (int)position)
    {
        emit signalOutput((int)position); // Ensure output is cast to int
        lastOutput = (int)position;
    }
}

