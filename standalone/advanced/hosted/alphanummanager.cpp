// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "alphanummanager.h"

AlphaNumManager::AlphaNumManager(QObject *parent) :
    QObject(parent)
{
}

void AlphaNumManager::slotDisplayParam(int modlineNum, int val)
{
    //

    //Once
    if(displayMode.contains("Once") && paramDisplay)
    {
        qDebug() << "display param" << val;
    }
}

void AlphaNumManager::slotDisplayKeyName(int keyNum)
{
    qDebug() << "display key name" << keyName << keyNum << instanceNum;

    if(instanceNum == keyNum)
    {
        //None, Immed Param
        if(displayMode.contains("Immed Param") || displayMode.contains("None"))
        {
            //do nothing with key name
        }

        //Always
        else if(displayMode.contains("Always"))
        {
            ushort vals[4];

            for(int i = 0; i < 4; i++)
            {
                vals[i] = keyName.at(i).unicode();

                MIDIPacket packet;
                packet.timeStamp = 0;
                packet.length = 3;

                packet.data[0] = 176;
                packet.data[1] = 50 + i;
                packet.data[2] = vals[i];

                emit signalSendDisplayVals("SSCOM Port 1", packet);
            }
        }

        //Once -- if set to once, and param display is closed, means this key has not been hit yet
        else if(displayMode.contains("Once") && !paramDisplay)
        {

            //Here we send packet for key name, wait a bit, open gate for param display
            ushort vals[4];

            for(int i = 0; i < 4; i++)
            {
                vals[i] = keyName.at(i).unicode();

                MIDIPacket packet;
                packet.timeStamp = 0;
                packet.length = 3;

                packet.data[0] = 176;
                packet.data[1] = 50 + i;
                packet.data[2] = vals[i];

                emit signalSendDisplayVals("SSCOM Port 1", packet);
            }

            QTimer::singleShot(1000, this, SLOT(slotOpenParamDisplay()));
        }

        //Initial Return
        else if(displayMode.contains("Inital/Return"))
        {

        }
    }

    //Reset gates
    else
    {
        paramDisplay = false;
    }

    //qDebug() << "display key name" << keyName << vals[0] << vals[1] << vals[2] << vals[3];
}

void AlphaNumManager::slotOpenParamDisplay()
{
    paramDisplay = true;
}
