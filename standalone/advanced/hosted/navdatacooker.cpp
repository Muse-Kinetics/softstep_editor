// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navdatacooker.h"
#include <QDebug>

#define PEDAL_CC 86

NavDataCooker::NavDataCooker(QWidget *parent) :
    QWidget(parent)
{
    keySensorBaseCcMap = 80;

    //------------------------------- Init settings
    onThreshN = 10;
    offThreshN = 5;
    onThreshS = 10;
    offThreshS = 5;
    onThreshE = 10;
    offThreshE = 5;
    onThreshW = 10;
    offThreshW = 5;

    yAccel = 10;

    //Init counters
    yIncClock = new QTimer(this);
    yIncCount = 0;

    lastYCount = -1;

    fastTrigState = false;
    dblTrigState = false;
    longTrigState = false;
    //offTrigState = false;

    //init sensors
    for(int i=0; i<4; i++)
    {
        sensorVals[i] = 0;
    }

    //init raw vars
    //footOnOff = false;

    //Connect Inc/Dec Clocks
    connect(yIncClock, SIGNAL(timeout()), this, SLOT(slotTickYIncrementClock()));

    //Trigger Returns
    connect(&trigger, SIGNAL(signalFastTriggerReturn()), this, SLOT(slotFastTriggerReturn()));
    connect(&trigger, SIGNAL(signalLongTriggerReturn()), this, SLOT(slotLongTriggerReturn()));
    connect(&trigger, SIGNAL(signalDblTriggerReturn()), this, SLOT(slotDblTriggerReturn()));
    //connect(&trigger, SIGNAL(signalOffTriggerReturn()), this, SLOT(slotOffTriggerOff()));
}

void NavDataCooker::slotSetSource(QString source, int modlineInstance)
{
    modlineSources.insert(modlineInstance, source);

    for(int i=0; i < modlineSources.size(); i++)
    {
        //qDebug() << "nav pad" << i << modlineSources.value(i);
    }
}

void NavDataCooker::slotUpdateVals(int cc, int val)
{
    if(cc >= keySensorBaseCcMap && cc <= keySensorBaseCcMap + 3)
    {
        if(cc == keySensorBaseCcMap)
        {
            sensorVals[W] = val;
        }
        else if(cc == keySensorBaseCcMap + 1)
        {
            sensorVals[E] = val;
        }
        else if(cc == keySensorBaseCcMap + 2)
        {
            sensorVals[N] = val;
        }
        else if(cc == keySensorBaseCcMap + 3)
        {
            sensorVals[S] = val;
        }

        //cookRaw();
        cookSources();
    }
    else if(cc == PEDAL_CC)
    {
        //Will need to use calibration pedal class in future
        pedalVal = val;

        for(int i = 0; i < 6; i++)
        {
            if(modlineSources.value(i) == "Pedal")
            {
                qDebug() << "nav pad" << pedalVal << i;
                //emit signalTransformSource(pedalVal, i, "Pedal");
            }
        }
    }
    qDebug() << cc << val;
}

void NavDataCooker::cookSources()
{
    //For each modline
    for(int i = 0; i < 6; i++)
    {
        if(modlineSources.value(i) == "Nav Y")
        {
            navY();
        }
        else if(modlineSources.value(i) == "Nav Y Decade")
        {
            navYDecade();
        }
        else if(modlineSources.value(i) == "Nav Y Inc-Dec")
        {
            navYIncDec();
        }
        else if(modlineSources.value(i) == "Nav N Foot On")
        {
            navNFootOn();
        }
        else if(modlineSources.value(i) == "Nav S Foot On")
        {
            navSFootOn();
        }
        else if(modlineSources.value(i) == "Nav N Foot Off")
        {
            navNFootOff();
        }
        else if(modlineSources.value(i) == "Nav S Foot Off")
        {
            navSFootOff();
        }
        else if(modlineSources.value(i) == "Nav N Trig")
        {
            navNTrig();
        }
        else if(modlineSources.value(i) == "Nav N Trig Fast")
        {
            navNTrigFast();
        }
        else if(modlineSources.value(i) == "Nav N Trig Dbl")
        {
            navNTrigDbl();
        }
        else if(modlineSources.value(i) == "Nav N Trig Long")
        {
            navNTrigLong();
        }
        else if(modlineSources.value(i) == "Nav S Trig")
        {
            navSTrig();
        }
        else if(modlineSources.value(i) == "Nav S Trig Fast")
        {
            navSTrigFast();
        }
        else if(modlineSources.value(i) == "Nav S Trig Dbl")
        {
            navSTrigDbl();
        }
        else if(modlineSources.value(i) == "Nav S Trig Long")
        {
            navSTrigLong();
        }
    }
}

int NavDataCooker::navY()
{

}

int NavDataCooker::navYDecade()
{

}

int NavDataCooker::navYIncDec()
{

}

void NavDataCooker::slotTickYIncrementClock()
{

}

void NavDataCooker::slotYIncSet(int i)
{

}

int NavDataCooker::navNFootOn()
{

}

int NavDataCooker::navSFootOn()
{

}

int NavDataCooker::navNFootOff()
{

}

int NavDataCooker::navSFootOff()
{

}

void NavDataCooker::navNTrig()
{

}

void NavDataCooker::navNTrigFast()
{

}

void NavDataCooker::slotFastTriggerReturn()
{

}

void NavDataCooker::slotFastTriggerOff()
{

}

void NavDataCooker::navNTrigDbl()
{

}

void NavDataCooker::slotDblTriggerReturn()
{

}

void NavDataCooker::slotDblTriggerOff()
{

}

void NavDataCooker::navNTrigLong()
{

}

void NavDataCooker::slotLongTriggerReturn()
{

}

void NavDataCooker::slotLongTriggerOff()
{

}

void NavDataCooker::navSTrig()
{

}

void NavDataCooker::navSTrigFast()
{

}

void NavDataCooker::navSTrigDbl()
{

}

void NavDataCooker::navSTrigLong()
{

}

void NavDataCooker::slotReceiveModlineOutput(int modlineNum, int val)
{

}

void NavDataCooker::slotReceiveMidiInput(int val, QString instance)
{

}
