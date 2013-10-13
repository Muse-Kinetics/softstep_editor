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

        qDebug() << "Key" << keyNum << "Sensor Vals" << sensorVals[NW] << sensorVals[NE] << sensorVals[SW] << sensorVals[SE];

        cookRaw();

        cookSources();
    }
}

void DataCooker::cookSources()
{
    for(int i = 0; i < 6; i++)
    {
        //Live
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

        //Latch
        else if(modlineSources.value(i) == "Pressure Latch")
        {
            //pressureLive();
        }
        else if(modlineSources.value(i) == "X Latch")
        {
            //pressureLive();
        }
        else if(modlineSources.value(i) == "Y Latch")
        {
            //pressureLive();
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

int DataCooker::pressureLive()
{
    if(footOnOff)
    {

        return (int)((float)(pressureRaw() - offThresh) / (float)(127 - offThresh) * 127.00);
    }
    else
    {
        qDebug() << "here";
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

}

int DataCooker::footOn()
{
    //If pressure is greater than on-thresh and current state of key is off
    if(pressureRaw() > onThresh && !footOnOff)
    {
        //Flip on
        footOnOff = true;
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
    if(pressureRaw() < offThresh && footOnOff)
    {
        //Flip off
        footOnOff = false;
        return 1;
    }
    else
    {
        return 0;
    }
}

void DataCooker::slotSetSource(QString source, int modlineInstance)
{
    modlineSources.insert(modlineInstance, source);
}

void DataCooker::slotCloseSource(QString source, int modlineInstance)
{

}
