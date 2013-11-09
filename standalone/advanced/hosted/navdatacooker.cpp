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

    //Set temporarily here until settings are hooked up
    globalGain = 1.00;
    navNGain = 1.1;
    navSGain = 1.1;
    navEGain = 1.0;
    navWGain = 1.0;

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
            sensorVals[W] = val*globalGain*navWGain;
        }
        else if(cc == keySensorBaseCcMap + 1)
        {
            sensorVals[E] = val*globalGain*navEGain;
        }
        else if(cc == keySensorBaseCcMap + 2)
        {
            sensorVals[N] = val*globalGain*navNGain;
        }
        else if(cc == keySensorBaseCcMap + 3)
        {
            sensorVals[S] = val*globalGain*navSGain;
        }

        cookRaw();
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

void NavDataCooker::cookRaw()
{
    //----- North
    if(sensorVals[N] > onThreshN && !footOnOffN)
    {
        footOnOffN = true;
    }
    else if(sensorVals[N] < offThreshN && footOnOffN)
    {
        footOnOffN = false;
    }

    //----- South
    if(sensorVals[S] > onThreshS && !footOnOffS)
    {
        footOnOffS = true;
    }
    else if(sensorVals[S] < offThreshS && footOnOffS)
    {
        footOnOffS = false;
    }

    //----- East
    if(sensorVals[E] > onThreshE && !footOnOffE)
    {
        footOnOffE = true;
    }
    else if(sensorVals[E] < onThreshE && footOnOffE)
    {
        footOnOffE = false;
    }

    ///----- West
    if(sensorVals[W] > onThreshW && !footOnOffW)
    {
        footOnOffW = true;
    }
    else if(sensorVals[W] < onThreshW && footOnOffW)
    {
        footOnOffW = false;
    }

    //------------ Open Counter Gates
    if(!footOnOffN && !footOnOffS)
    {
        navYGate = true;
    }
}

void NavDataCooker::cookSources()
{
    //For each modline
    for(int i = 0; i < 6; i++)
    {
        if(modlineSources.value(i) == "Nav Y")
        {
            emit signalTransformSource(navY(), i, "Nav Y");
        }
        else if(modlineSources.value(i) == "Nav Y Decade")
        {
            emit signalTransformSource(navY()*10, i, "Nav Y Decade");
        }
        else if(modlineSources.value(i) == "Nav Y Inc-Dec")
        {
            navYIncDec();
        }
        else if(modlineSources.value(i) == "Nav N Foot On")
        {
            emit signalTransformSource(navNFootOn(), i, "Nav N Foot On");
        }
        else if(modlineSources.value(i) == "Nav S Foot On")
        {
            emit signalTransformSource(navSFootOn(), i, "Nav S Foot On");
        }
        else if(modlineSources.value(i) == "Nav N Foot Off")
        {
            emit signalTransformSource(navNFootOff(), i, "Nav N Foot Off");
        }
        else if(modlineSources.value(i) == "Nav S Foot Off")
        {
            emit signalTransformSource(navNFootOff(), i, "Nav S Foot Off");
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
    if(navNFootOn() && navYGate)
    {
        navYGate = false;
        navYCount++;
    }
    else if(navSFootOn() && navYGate)
    {
        navYGate = false;
        navYCount--;
    }

    return navYCount;
}

int NavDataCooker::navYDecade()
{
    //Just multiply navY() in cookSources()
}

int NavDataCooker::navYIncDec()
{
    //If key is active
    if(footOnOffN || footOnOffS)
    {
        //Weird... copied from max, probably works, brain soggy so not sure
        //If pulled northward
        if(sensorVals[N] - sensorVals[S] > navYDeadZone/2.5)
        {
            yIncOrDec = true; //True for inc

            if(!yIncClock->isActive())
            {
                yIncClock->start(yAccel);
            }
        }

        //If pulled southward
        else if(sensorVals[S] - sensorVals[N] > navYDeadZone/2.5)
        {
            yIncOrDec = false; //False for dec

            if(!yIncClock->isActive())
            {
                yIncClock->start();
            }
        }

        //If in dead zone stop clock
        else
        {
            yIncClock->stop();
        }
    }

    //If foot off, stop clock
    else
    {
        yIncClock->stop();
    }
}

void NavDataCooker::slotTickYIncrementClock()
{
    if(yIncOrDec && yIncCount < 127) //True means inc, False means dec
    {
        yIncCount++;
    }
    else if(!yIncOrDec && yIncCount > 0)
    {
        yIncCount--;
    }

    if(lastYCount != yIncCount)
    {
        for(int i = 0; i < 6; i++)
        {
            emit signalTransformSource(yIncCount, i, "Nav Y Inc-Dec");
        }

        lastYCount = yIncCount;
    }
}

int NavDataCooker::navNFootOn()
{
    if(footOnOffN)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int NavDataCooker::navSFootOn()
{
    if(footOnOffS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int NavDataCooker::navNFootOff()
{
    if(!footOnOffN)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int NavDataCooker::navSFootOff()
{
    if(!footOnOffS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

void NavDataCooker::slotReceiveMidiInput(int val, QString instance)
{

}
