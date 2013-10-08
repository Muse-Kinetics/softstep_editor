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

    connect(timer, SIGNAL(timeout()), this, SLOT(slotUpdate()));

}

void Slewer::slotSlew(double target, double time)
{
    if(target != destination)   //If new destination update velocity
    {
        destination = target;

        velocity = (destination - position)/time;

        if(!timer->isActive())
        {
            timer->start(1);
        }
    }
}

void Slewer::slotUpdate()
{
    if((int)position < (int)destination || (int)position > (int)destination) //Not using != here because of rounding/casting. Could cause erroneuous jump @ high velocities.
    {
        position += velocity;
    }
    else
    {
        timer->stop();
    }

    emit signalOutput(position);
}

