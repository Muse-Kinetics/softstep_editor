// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "datacooker.h"
#include <QDebug>

DataCooker::DataCooker(int instanceNum, QWidget *parent) :
    QWidget(parent)
{
    keySensorBaseCcMap[0] = 44;
    keySensorBaseCcMap[1] = 52;
    keySensorBaseCcMap[2] = 60;
    keySensorBaseCcMap[3] = 68;
    keySensorBaseCcMap[4] = 76;
    keySensorBaseCcMap[5] = 40;
    keySensorBaseCcMap[6] = 48;
    keySensorBaseCcMap[7] = 56;
    keySensorBaseCcMap[8] = 64;
    keySensorBaseCcMap[9] = 72;

    keyNum = instanceNum;

    onThresh = 10;
    offThresh = 5;

    sensorResponse = 0; //0 - maximum 1 - avg

    //Init sensors
    for(int i=0; i<4; i++)
    {
        sensorVals[i] = 0;
    }

    //Init raw vars
    footOnOff = false;

    connect(&latcher, SIGNAL(signalReturnValue(int,int)), this, SLOT(slotPressureLatchReturn(int,int)));
}

void DataCooker::slotSetSource(QString source, int modlineInstance)
{
    modlineSources.insert(modlineInstance, source);

    /* for(int i = 0; i < modlineSources.size(); i++)
    {
        qDebug () << i << modlineSources.value(i);
    }*/
}

void DataCooker::slotUpdateVals(int cc, int val)
{
    if(cc >= keySensorBaseCcMap[keyNum] && cc <= keySensorBaseCcMap[keyNum] + 3)
    {
        if(cc == keySensorBaseCcMap[keyNum])
        {
            sensorVals[NW] = val;
        }
        else if(cc == keySensorBaseCcMap[keyNum] + 1)
        {
            sensorVals[NE] = val;
        }
        else if(cc == keySensorBaseCcMap[keyNum] + 2)
        {
            sensorVals[SW] = val;
        }
        else if(cc == keySensorBaseCcMap[keyNum] + 3)
        {
            sensorVals[SE] = val;
        }

        //qDebug() << "Key" << keyNum << "Sensor Vals" << sensorVals[NW] << sensorVals[NE] << sensorVals[SW] << sensorVals[SE];

        cookRaw();

        cookSources();
    }
}

void DataCooker::slotReceiveModlineOutput(int modlineNum, int val)
{
    //qDebug() << modlineNum << val;

    //For each modline
    for(int i = 0; i < 6; i++)
    {
        //qDebug() << i <<modlineSources.value(i) << modlineNum << val;

        if(i != modlineNum)
        {
            if(modlineSources.value(i).contains(QString("Modline %1 Output").arg(modlineNum + 1)))
            {

                emit signalTransformSource(val, i, QString("Modline %1 Output").arg(modlineNum + 1));
            }
        }
    }
}

void DataCooker::cookSources()
{
    //For each modline
    for(int i = 0; i < 6; i++)
    {
        //-------- Live
        if(modlineSources.value(i) == "Pressure Live")
        {
            emit signalTransformSource(pressureLive(), i, "Pressure Live");
        }
        else if(modlineSources.value(i) == "X Live")
        {
            emit signalTransformSource(xLive(), i, "X Live");
        }
        else if(modlineSources.value(i) == "Y Live")
        {
            emit signalTransformSource(yLive(), i, "Y Live");
        }

        //-------- Latch
        else if(modlineSources.value(i) == "Pressure Latch")
        {
            pressureLatch(i);
        }
        else if(modlineSources.value(i) == "X Latch")
        {
            //pressureLive();
        }
        else if(modlineSources.value(i) == "Y Latch")
        {
            //pressureLive();
        }

        //-------- Foot On/Off
        else if(modlineSources.value(i) == "Foot On")
        {
            emit signalTransformSource(footOn(), i, "Foot On");
        }
        else if(modlineSources.value(i) == "Foot Off")
        {
            emit signalTransformSource(footOff(), i, "Foot Off");
        }
    }
}

void DataCooker::cookRaw()
{
    //If raw pressure is greater than on-thresh and current state of key is off
    if(pressureRaw() > onThresh && !footOnOff)
    {
        //Flip on
        footOnOff = true;
    }

    //If pressure is below off-thresh and foot is currently on
    else if(pressureRaw() < offThresh && footOnOff)
    {
        //Flip off
        footOnOff = false;
    }
}

int DataCooker::pressureRaw()
{
    //bool avg = false;

    //Average Sensor Val
    if(sensorResponse) //Average
    {
        int mean = 0;

        for(int i = 0; i < 4; i++)
        {
            mean +=sensorVals[i];
        }

        mean /= 4;

        return mean;
    }

    //Max Sensor Val
    else
    {
        int max = 0;

        for(int i = 0; i < 4; i++)
        {
            if(sensorVals[i] > max)
            {
                max = sensorVals[i];
            }
        }

        //qDebug() << "pressure" << max;

        return max;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////    Sources   //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------- Live
int DataCooker::pressureLive()
{
    if(footOnOff)
    {
        if((int)((float)(pressureRaw() - onThresh) / (float)(127 - onThresh) * 127.00) > 0)
        {
            return (int)((float)(pressureRaw() - onThresh) / (float)(127 - onThresh) * 127.00);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int DataCooker::xLive()
{
    int eastMass = sensorVals[NE] + sensorVals[SE];
    int westMass = sensorVals[NW] + sensorVals[SW];
    int totalMass = eastMass + westMass;
    int xLoc;

    if(totalMass)
    {
        xLoc = ((westMass + eastMass*128) / totalMass) - 1;
    }
    else
    {
        xLoc = 0;
    }

    return xLoc;
}

int DataCooker::yLive()
{
    int northMass = sensorVals[NE] + sensorVals[NW];
    int southMass = sensorVals[SE] + sensorVals[SW];
    int totalMass = northMass + southMass;
    int yLoc;

    if(totalMass)
    {
        yLoc = ((southMass + northMass*128) / totalMass) - 1;
    }
    else
    {
        yLoc = 0;
    }

    return yLoc;
}

//---------------------------------- Latching
int DataCooker::pressureLatch(int modlineNum)
{

    if(footOnOff)
    {
        latcher.latchOpen = true;
        latcher.receiveInput(pressureLive(), modlineNum);
    }
    else
    {
        latcher.latchOpen = false;
    }
}

void DataCooker::slotPressureLatchReturn(int val, int modlineNum)
{
    qDebug() << "pressure latch return" << val << modlineNum;

    emit signalTransformSource(val, modlineNum, "Pressure Latch");
}

int DataCooker::xLatch()
{

}

int DataCooker::yLatch()
{

}

int DataCooker::footOn()
{
    //If pressure is greater than on-thresh and current state of key is off
    if(footOnOff)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DataCooker::footOff()
{
    //If pressure is below off-thresh and foot is currently on
    if(!footOnOff)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


