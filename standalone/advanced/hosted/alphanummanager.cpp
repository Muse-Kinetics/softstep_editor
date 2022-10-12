// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "alphanummanager.h"

AlphaNumManager::AlphaNumManager(QObject *parent) :
    QObject(parent)
{
    connect(&fifoClock, SIGNAL(timeout()), this, SLOT(slotDrainFIFO()));
    connect(&keyOffTimeout, SIGNAL(timeout()), this, SLOT(slotKeyOffTimeout()));
    keyOnOff = false;

}

void AlphaNumManager::slotDisplayParam(int modlineNum, int val)
{
    Q_UNUSED(modlineNum);
    //qDebug() << "instance" << instanceNum << "display param called" << "sender name" << QObject::sender()->objectName() << "modline num" << modlineNum << "val" << val;

    //------------ Format prefix and value

    QString outputString;

    if(prefix.size() == 1)
    {
        prefix.append(" ");
    }

    if(prefix.size() == 0)
    {
        prefix.append("  ");
    }

    //If prefix exists

    if(val > 99)
    {
        outputString = QString("%1%2").arg(prefix.at(0)).arg(val);
    }
    else if(val < 10)
    {
        outputString = QString("%1 %2").arg(prefix).arg(val);
    }
    else
    {
        outputString = QString("%1%2").arg(prefix).arg(val);
    }


    //Once
    if(displayMode.contains("Once") && paramDisplay)
    {
        slotFormatAndOutputString(outputString);
        //qDebug() << "once";
    }

    //Initial/Return
    if(displayMode.contains("Initial/Return") && paramDisplay)
    {
        slotFormatAndOutputString(outputString);
        //qDebug() << "initial retrn";
    }

    if(displayMode.contains("Immed Param") && paramDisplay)
    {
        slotFormatAndOutputString(outputString);
        //qDebug() << "immed param";
    }
}

void AlphaNumManager::slotFormatAndOutputString(QString displayString)
{

    //qDebug() << "displayString" << displayString;// << "sender name" << QObject::sender()->objectName();

    //Make all messages of length 4
    if(displayString.size() < 4)
    {
        for(int i = displayString.size(); i < 4; i++)
        {
            displayString.append(" ");
        }
    }


//#ifdef Q_OS_MAC
//    ushort vals[displayString.size()];
//#else
//    ushort vals[200];
//#endif
    for(int i = 0; i < displayString.size(); i++)
    {
//        vals[i] = displayString.at(i).unicode();

//        MIDIPacket packet;
//        packet.timeStamp = 0;
//        packet.length = 3;

//        packet.data[0] = 176;
//        packet.data[1] = 50 + i;
//        packet.data[2] = vals[i];

//        packetList.append(packet);

        //qDebug() << "display send packet: " << displayString.at(i).unicode();
        emit signalSendPacket(176, 50 + i, displayString.at(i).unicode());
    }

    //emit signalSendDisplayVals("SoftStep Control Surface", packetList);
}

void AlphaNumManager::slotDisplayKeyName(int keyNum)
{
    //Called in Mainwindow -- connect(&key[k]->dataCooker, SIGNAL(signalThisKeyPressed(int)), &key[l]->alphaNumManager, SLOT(slotDisplayKeyName(int)));

    //qDebug() << "slotDisplayKeyName" << keyNum;

    if(instanceNum == keyNum)
    {
        keyOnOff = true;

        //qDebug() << "display key name" << keyName << keyNum << instanceNum << " displayMode: " << displayMode;

        //None
        if(displayMode.contains("None"))
        {
            //qDebug() << "show this name" << currentPresetName;
            slotFormatAndOutputString(currentPresetName);
        }

        //Immed Param
        else if(displayMode.contains("Immed Param"))
        {
            slotOpenParamDisplay();
        }

        //Always
        else if(displayMode.contains("Always"))
        {
            slotFormatAndOutputString(keyName);
        }

        //Once -- if set to once, and param display is closed, means this key has not been hit yet
        else if(displayMode.contains("Once") && !paramDisplay)
        {
            slotFormatAndOutputString(keyName);

            QTimer::singleShot(1000, this, SLOT(slotOpenParamDisplay()));
        }

        //Initial Return
        else if(displayMode.contains("Initial/Return"))
        {
            slotFormatAndOutputString(keyName);

            QTimer::singleShot(250, this, SLOT(slotOpenParamDisplay()));
        }
    }

    //If another key is hi, reset gates
    else
    {
        paramDisplay = false;
    }

    //qDebug() << "display key name" << keyName << vals[0] << vals[1] << vals[2] << vals[3];
}

void AlphaNumManager::slotKeyOff(int keyNum)
{
    //qDebug() << "key off called" << keyNum;

    if(instanceNum == keyNum)
    {
        keyOnOff = false;

        if(displayMode.contains("Initial/Return"))
        {
            //keyOffTimeout.start(500);
            QTimer::singleShot(250, this, SLOT(slotReturnToKeyName()));
        }
    }
}

void AlphaNumManager::slotKeyOffTimeout()
{
    //slotReturnToKeyName();
    QTimer::singleShot(250, this, SLOT(slotReturnToKeyName()));

    //slotFormatAndOutputString(keyName);

}

void AlphaNumManager::slotReturnToKeyName()
{
    slotFormatAndOutputString(keyName);
}

void AlphaNumManager::slotOpenParamDisplay()
{
    paramDisplay = true;
}

void AlphaNumManager::slotCloseParamDisplay()
{
    paramDisplay = false;
}

void AlphaNumManager::slotDrainFIFO()
{
    if(!packetFIFOList.size())
    {
        fifoClock.stop();
    }
    else
    {
        //emit signalSendDisplayVals("SoftStep Control Surface", packetFIFOList.first());
        packetFIFOList.removeFirst();
    }
}

void AlphaNumManager::slotPresetChangeDisplayPresetName()
{
    slotFormatAndOutputString(currentPresetName);
}
