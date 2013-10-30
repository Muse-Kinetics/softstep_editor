// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "displaysink.h"

DisplaySink::DisplaySink(QObject *parent) :
    QObject(parent)
{
    connect(&ledFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainLEDList()));
    connect(&alphaFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainAlphaList()));
}

void DisplaySink::slotAddAlphaPacket(QString port, MIDIPacket packet)
{
    qDebug() << "add alpha packet";
    alphaFIFOList.append(packet);

    slotCheckAlphaList();
}

void DisplaySink::slotAddLEDPacket(QString port, MIDIPacket packet)
{
    qDebug() << "add LED packet";
    ledFIFOList.append(packet);

    slotCheckAlphaList(); //Always check alpha list first
}

void DisplaySink::slotCheckAlphaList()
{
    qDebug() << "check alpha list";

    if(!alphaFIFOList.isEmpty() && !alphaFIFOClock.isActive())
    {
        ledFIFOClock.stop();
        alphaFIFOClock.start(1);
    }
    else if(alphaFIFOList.isEmpty())
    {
        alphaFIFOClock.stop();
        slotCheckLEDList();
    }
}

void DisplaySink::slotCheckLEDList()
{
    qDebug() << "check led list" << ledFIFOList.size();

    if(!ledFIFOList.isEmpty() && !ledFIFOClock.isActive())
    {
        ledFIFOClock.start(1);
    }
    else if(ledFIFOList.isEmpty())
    {
        ledFIFOClock.stop();
    }
}

void DisplaySink::slotDrainAlphaList()
{
    qDebug() << "drain alpha list" << alphaFIFOList.size();

    if(!alphaFIFOList.isEmpty())
    {
        emit signalSendPacket("SSCOM Port 1", alphaFIFOList.first());
        alphaFIFOList.removeFirst();
    }
    else
    {
        alphaFIFOClock.stop();
    }
}

void DisplaySink::slotDrainLEDList()
{
    qDebug() << "drain led list";

    if(!ledFIFOList.isEmpty())
    {
        emit signalSendPacket("SSCOM Port 1", ledFIFOList.first());
        ledFIFOList.removeFirst();
    }
    else
    {
        ledFIFOClock.stop();
    }
}
