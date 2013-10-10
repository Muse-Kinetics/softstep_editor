// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "datacooker.h"
#include <QDebug>

DataCooker::DataCooker(int instanceNum, QWidget *parent) :
    QWidget(parent)
{
    keySensorBaseCcMap[1] = 44;
    keySensorBaseCcMap[2] = 52;
    keySensorBaseCcMap[3] = 60;
    keySensorBaseCcMap[4] = 68;
    keySensorBaseCcMap[5] = 76;
    keySensorBaseCcMap[6] = 40;
    keySensorBaseCcMap[7] = 48;
    keySensorBaseCcMap[8] = 56;
    keySensorBaseCcMap[9] = 64;
    keySensorBaseCcMap[0] = 72;

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

        qDebug() << "Key" << keyNum << "Sensor Vals" << sensorVals[NW] << sensorVals[NE] << sensorVals[SW] << sensorVals[SE];

        cook();
    }
}

void DataCooker::cook()
{
    pressureLive();
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

        emit signalTransformSource("Pressure Live", mean);
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

        emit signalTransformSource("Pressure Live", max);
    }


}
