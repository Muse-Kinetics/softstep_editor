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

    //Init sensors
    for(int i=0; i<4; i++)
    {
        sensorVals[i] = 0;
    }
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

        cook();
    }
}

void DataCooker::cook()
{
    for(int i = 0; i < 6; i++)
    {
        //Live
        if(modlineSources.value(i) == "Pressure Live")
        {
            emit signalTransformSource(pressureLive(), i);
        }
        else if(modlineSources.value(i) == "X Live")
        {
            emit signalTransformSource(xLive(), i);
        }
        else if(modlineSources.value(i) == "Y Live")
        {
            emit signalTransformSource(yLive(), i);
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

int DataCooker::pressureLive()
{
    bool avg = false;

    //Average Sensor Val
    if(avg)
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

        return max;
    }
}

int DataCooker::xLive()
{
    int eastMass = sensorVals[NE] + sensorVals[SE];
    int westMass = sensorVals[NW] + sensorVals[NE];
    int totalMass = eastMass + westMass;
    int xLoc = (westMass + eastMass*127) / totalMass;
    qDebug() << "xLoc" << xLoc;
}

int DataCooker::yLive()
{

}

void DataCooker::slotSetSource(QString source, int modlineInstance)
{
    modlineSources.insert(modlineInstance, source);
}

void DataCooker::slotCloseSource(QString source, int modlineInstance)
{

}
