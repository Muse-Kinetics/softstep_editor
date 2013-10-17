// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "latcher.h"

Latcher::Latcher()
{
    connect(this, SIGNAL(timeout()), this, SLOT(slotDrainFIFO()));
}

int Latcher::latchInput(int input)
{
    //Put input in the buffer
    fifo.append(input);

    if(!isActive())
    {
        start(100);
    }
}

int Latcher::slotDrainFIFO()
{
    //Return off the oldest value in the list
    if(fifo.count())
    {
        return fifo.first();
    }

    //If nothing in buffer, turn off timer
    else
    {
        stop();
    }
}


