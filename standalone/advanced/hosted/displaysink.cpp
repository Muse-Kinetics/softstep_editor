// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "displaysink.h"

#define ALPHA_CLOCK_SPEED 100

DisplaySink::DisplaySink(QObject *parent) :
    QObject(parent)
{
    connect(&alphaFIFOClock, SIGNAL(timeout()), this, SLOT(slotPollAlphaList()));
    connect(&displayFIFOClock, SIGNAL(timeout()), this, SLOT(slotDrainDisplayFIFO()));

    MIDIPacket voidPacket;
    voidPacket.timeStamp = 0;
    voidPacket.length = 3;

    //Led mode type
    voidPacket.data[0] = -1;
    voidPacket.data[1] = -1;
    voidPacket.data[2] = -1;

    for(int i = 0; i < 4; i++)
    {
        alphaLastPacketList.append(voidPacket);
    }

    for(int i = 0; i < 3; i++)
    {
        ledLastPacketList.append(voidPacket);
    }

    displayFIFOClock.start(1);
    alphaFIFOClock.start(ALPHA_CLOCK_SPEED);
}

void DisplaySink::slotAddAlphaPacket(QString port, QList<MIDIPacket> packetList)
{
    //qDebug() << "add alpha packet" << alphaLastPacketList.size() << packetList.size();// << alphaLastPacketList.at(0).data[0];s

    bool newPacket = false;

    for(int i = 0; i < packetList.size(); i++)
    {
        //Check each packet in list for new data, if anything new, output

        if(packetList.at(i).data[0] != alphaLastPacketList.at(i).data[0])
        {
            newPacket = true;
            break;
        }
        else if(packetList.at(i).data[1] != alphaLastPacketList.at(i).data[1])
        {
            newPacket = true;
            break;
        }
        else if(packetList.at(i).data[2] != alphaLastPacketList.at(i).data[2])
        {
            newPacket = true;
            break;
        }
    }

    //If newest packet is not a duplicate, output
    if(newPacket)
    {
        mostRecentAlphaList.clear();

        //Iterate through packets and emit them
        for(int i = 0; i < packetList.size(); i++)
        {
            mostRecentAlphaList.append(packetList.at(i));
            //emit signalSendPacket("SSCOM Port 1", packetList.at(i));
        }

        if(!alphaFIFOClock.isActive())
        {
            alphaFIFOClock.start(ALPHA_CLOCK_SPEED);
        }

        //Set last packet to newest packet to maintain change filter
        alphaLastPacketList = packetList;
    }
}

void DisplaySink::slotAddLEDPacket(QString port, QList<MIDIPacket> packetList)
{
    bool newPacket = false;

    //Only three packets in list, always
    for(int i = 0; i < packetList.size(); i++)
    {
        //Check each packet in list for new data, if anything new, output

        if(packetList.at(i).data[0] != ledLastPacketList.at(i).data[0])
        {
            newPacket = true;
            break;
        }
        else if(packetList.at(i).data[1] != ledLastPacketList.at(i).data[1])
        {
            newPacket = true;
            break;
        }
        else if(packetList.at(i).data[2] != ledLastPacketList.at(i).data[2])
        {
            newPacket = true;
            break;
        }
    }

    //If newest packet is not a duplicate, output
    if(newPacket)
    {
        //Iterate through packets and emit them
        for(int i = 0; i < packetList.size(); i++)
        {
            //emit signalSendPacket("SSCOM Port 1", packetList.at(i));

            displayFIFO.append(packetList.at(i));
        }

        //Set last packet to newest packet to maintain change filter
        ledLastPacketList = packetList;
    }
}

void DisplaySink::slotPollAlphaList()
{
    //qDebug() << "drain alpha list";

    if(!mostRecentAlphaList.isEmpty())
    {
        //emit signalSendPacket("SSCOM Port 1", alphaFIFOList.first());
        for(int i = 0; i < mostRecentAlphaList.size(); i++)
        {
            displayFIFO.append(mostRecentAlphaList.at(i));
        }

        mostRecentAlphaList.clear();
    }
    else
    {
        alphaFIFOClock.stop();
    }
}

void DisplaySink::slotDrainDisplayFIFO()
{
    if(!displayFIFO.isEmpty())
    {
        emit signalSendPacket("SSCOM Port 1", displayFIFO.first());
        displayFIFO.removeFirst();
    }
}
