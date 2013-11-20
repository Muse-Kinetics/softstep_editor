// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "ledmanager.h"

#define LED_OFF         0
#define LED_ON          1
#define LED_FLASH       2
#define LED_FLASH_FAST  3
#define LED_BLINK       4

#define LED_GREEN       0
#define LED_RED         1

LEDManager::LEDManager(QObject *parent) :
   QObject(parent)
{
    connect(&fifoClock, SIGNAL(timeout()), this, SLOT(slotDrainFIFO()));

    for(int i = 0; i < 6; i++)
    {
        greenMode[i] = "None";
        redMode[i] = "None";

        state[i] = false;
    }
}

void LEDManager::processLED(int modlineNum, int greenOrRed, QString mode)
{
    int ledType = -1;

    if(!mode.contains("None"))
    {
        //qDebug() << "     key:" << keyInstanceNum << "     greenOrRed:" << greenOrRed << "     modlineNum:" << modlineNum << "     state:" << state[modlineNum];

        if(state[modlineNum])
        {
            if(mode == "True")
            {
                ledType = LED_ON;
            }
            else if(mode == "Flash True")
            {
                ledType = LED_FLASH;
            }
            else if(mode == "Flash Fast True")
            {
                ledType = LED_FLASH_FAST;
            }
            else if(mode == "Blink True")
            {
                ledType = LED_BLINK;
            }
            else if (mode == "Off")
            {
                ledType = LED_OFF;
            }
            else
            {
                ledType = LED_OFF;
            }
        }
        else
        {
            if(mode == "False")
            {
                ledType = LED_ON;
            }
            else if(mode == "Flash False")
            {
                ledType = LED_FLASH;
            }
            else if(mode == "Flash Fast False")
            {
                ledType = LED_FLASH_FAST;
            }
            else if(mode == "Blink False")
            {
                ledType = LED_BLINK;
            }
            else
            {
                ledType = LED_OFF;
            }
        }

        //If type specified send packet
        if(ledType != -1)
        {
            packetList.clear();

            //-------- Send Key Num
            MIDIPacket keyPacket;
            keyPacket.timeStamp = 0;
            keyPacket.length = 3;

            //----- KeyNum
            //Key / LED referred to
            keyPacket.data[0] = 176;
            keyPacket.data[1] = 40;
            keyPacket.data[2] = keyInstanceNum;

            packetList.append(keyPacket);

            MIDIPacket colorPacket;
            colorPacket.timeStamp = 0;
            colorPacket.length = 3;

            //Red or green?
            colorPacket.data[0] = 176;
            colorPacket.data[1] = 41;
            colorPacket.data[2] = greenOrRed;

            packetList.append(colorPacket);

            MIDIPacket typePacket;
            typePacket.timeStamp = 0;
            typePacket.length = 3;

            //Led mode type
            typePacket.data[0] = 176;
            typePacket.data[1] = 42;
            typePacket.data[2] = ledType;

            packetFIFOList.append(keyPacket);
            packetFIFOList.append(colorPacket);
            packetFIFOList.append(typePacket);

            packetList.append(typePacket);

            emit signalSendLEDControl("SSCOM Port 1", packetList);
            lastPacketListSent = packetList;
        }
    }
}

void LEDManager::slotReceiveModlineOutput(int modlineNum, int val)
{
    //qDebug() << modlineNum << val;

    if(state[modlineNum] && !val)
    {
        state[modlineNum] = false;

        processLED(modlineNum,LED_GREEN, greenMode[modlineNum]);
        processLED(modlineNum,LED_RED, redMode[modlineNum]);
    }
    else if(!state[modlineNum] && val)
    {
        state[modlineNum] = true;

        processLED(modlineNum,LED_GREEN, greenMode[modlineNum]);
        processLED(modlineNum,LED_RED, redMode[modlineNum]);
    }
}

void LEDManager::slotSetLedModes(int modlineNum, QString gm, QString rm)
{
    greenMode[modlineNum] = gm;
    redMode[modlineNum] = rm;
}

void LEDManager::slotDrainFIFO()
{
    if(!packetFIFOList.size())
    {
        fifoClock.stop();
    }
    else
    {
        //emit signalSendLEDControl("SSCOM Port 1", packetFIFOList.first());
        packetFIFOList.removeFirst();
    }
}

void LEDManager::slotStateRecallLedLastPacket(QList<MIDIPacket> pktlst)
{
    emit signalSendLEDControl("SSCOM Port 1", pktlst);
    lastPacketListSent = pktlst;
}
