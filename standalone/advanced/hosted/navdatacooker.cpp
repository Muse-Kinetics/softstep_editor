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


    fastTrigStateN = false;
    dblTrigStateN = false;
    longTrigStateN = false;

    fastTrigStateS = false;
    dblTrigStateS = false;
    longTrigStateS = false;
    //offTrigState = false;

    //init sensors
    for(int i=0; i<4; i++)
    {
        sensorVals[i] = 0;
    }

    //init raw vars
    //footOnOff = false;

    presetChangeGate = true;

    //Connect Inc/Dec Clocks
    connect(yIncClock, SIGNAL(timeout()), this, SLOT(slotTickYIncrementClock()));

    //Trigger Returns
    connect(&triggerN, SIGNAL(signalTriggerReturn()), this, SLOT(slotTriggerReturnN()));
    connect(&triggerN, SIGNAL(signalFastTriggerReturn()), this, SLOT(slotFastTriggerReturnN()));
    connect(&triggerN, SIGNAL(signalLongTriggerReturn()), this, SLOT(slotLongTriggerReturnN()));
    connect(&triggerN, SIGNAL(signalDblTriggerReturn()), this, SLOT(slotDblTriggerReturnN()));

    connect(&triggerS, SIGNAL(signalTriggerReturn()), this, SLOT(slotTriggerReturnS()));
    connect(&triggerS, SIGNAL(signalFastTriggerReturn()), this, SLOT(slotFastTriggerReturnS()));
    connect(&triggerS, SIGNAL(signalLongTriggerReturn()), this, SLOT(slotLongTriggerReturnS()));
    connect(&triggerS, SIGNAL(signalDblTriggerReturn()), this, SLOT(slotDblTriggerReturnS()));

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
            sensorVals[NAV_W] = val*globalGain*navWGain;
        }
        else if(cc == keySensorBaseCcMap + 1)
        {
            sensorVals[NAV_E] = val*globalGain*navEGain;
        }
        else if(cc == keySensorBaseCcMap + 2)
        {
            sensorVals[NAV_N] = val*globalGain*navNGain;
        }
        else if(cc == keySensorBaseCcMap + 3)
        {
            sensorVals[NAV_S] = val*globalGain*navSGain;
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
                emit signalTransformSource(pedalVal, i, "Pedal");
            }
        }
    }
    //qDebug() << cc << val;
}

void NavDataCooker::slotSetCounterParams(int min, int max, bool wrap)
{
    counterMin = min;
    counterMax = max;
    counterWrap = wrap;
}

void NavDataCooker::cookRaw()
{
    //----- North
    if(sensorVals[NAV_N] > onThreshN && !footOnOffN)
    {
        footOnOffN = true;
        emit signalThisKeyPressed(0);
    }
    else if(sensorVals[NAV_N] < offThreshN && footOnOffN)
    {
        footOnOffN = false;
    }

    //----- South
    if(sensorVals[NAV_S] > onThreshS && !footOnOffS)
    {
        footOnOffS = true;
        emit signalThisKeyPressed(0);
    }
    else if(sensorVals[NAV_S] < offThreshS && footOnOffS)
    {
        footOnOffS = false;
    }

    //----- East
    if(sensorVals[NAV_E] > onThreshE && !footOnOffE)
    {
        footOnOffE = true;
    }
    else if(sensorVals[NAV_E] < onThreshE && footOnOffE)
    {
        footOnOffE = false;
    }

    ///----- West
    if(sensorVals[NAV_W] > onThreshW && !footOnOffW)
    {
        footOnOffW = true;
    }
    else if(sensorVals[NAV_W] < onThreshW && footOnOffW)
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
    if(!navEFootOn() && !navWFootOn())
    {
        presetChangeGate = true;
    }

    //If preset change
    if(navEFootOn() && presetChangeGate)
    {
        presetChangeGate = false;
        emit signalPresetChange(true);
    }
    else if(navWFootOn() && presetChangeGate)
    {
        presetChangeGate = false;
        emit signalPresetChange(false);
    }

    //If not a preset change
    else
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
                emit signalTransformSource(navYDecade(), i, "Nav Y Decade");
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
                emit signalTransformSource(navSFootOff(), i, "Nav S Foot Off");
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

        //Emit Y Counters every time
        emit signalNavY(navY());
        emit signalNavDecade(navYDecade());
    }
}

//----------------------------------------------- Counter
int NavDataCooker::navY()
{
    //---- Inc
    if(navNFootOn() && navYGate)
    {
        navYGate = false;
        navYCount++;

        if(navYCount > counterMax)
        {
            if(counterWrap)
            {
                navYCount = counterMin;
            }
            else
            {
                navYCount = counterMax;
            }
        }

        qDebug() << "nav y count" << navYCount;

    }

    //---- Dec
    else if(navSFootOn() && navYGate)
    {
        navYGate = false;
        navYCount--;

        if(navYCount < counterMin)
        {
            if(counterWrap)
            {
                navYCount = counterMax;
            }
            else
            {
                navYCount = counterMin;
            }
        }

        qDebug() << "nav y count" << navYCount;
    }



    return navYCount;
}

int NavDataCooker::navYDecade()
{
    return navY()*10;
}

//----------------------------------------------- Inc/Dec
int NavDataCooker::navYIncDec()
{
    //If key is active
    if(footOnOffN || footOnOffS)
    {
        //Weird... copied from max, probably works, brain soggy so not sure
        //If pulled northward
        if(sensorVals[NAV_N] - sensorVals[NAV_S] > navYDeadZone/2.5)
        {
            yIncOrDec = true; //True for inc

            if(!yIncClock->isActive())
            {
                yIncClock->start(yAccel);
            }
        }

        //If pulled southward
        else if(sensorVals[NAV_S] - sensorVals[NAV_N] > navYDeadZone/2.5)
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

        //qDebug() << "y inc count" << yIncCount;

        lastYCount = yIncCount;
    }
}

//----------------------------------------------- Foot On/Off per Quadrant
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

int NavDataCooker::navWFootOn()
{
    if(footOnOffW)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int NavDataCooker::navEFootOn()
{
    if(footOnOffE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//----------------------------------------------- Triggers
//--------------- North
void NavDataCooker::navNTrig()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffN && !trigStateN)
    {
        triggerN.trigger();
        trigStateN = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffN && trigStateN)
    {
        trigStateN = false;
    }
}

void NavDataCooker::slotTriggerReturnN()
{
    int outputVal = sensorVals[NAV_N]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav N Trig");
    }

    QTimer::singleShot(100, this, SLOT(slotTriggerOffN()));
}

void NavDataCooker::slotTriggerOffN()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav N Trig");
    }
}

void NavDataCooker::navNTrigFast()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffN && !fastTrigStateN)
    {
        triggerN.fastTrigger();
        fastTrigStateN = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffN && fastTrigStateN)
    {
        fastTrigStateN = false;
    }
}

void NavDataCooker::slotFastTriggerReturnN()
{
    int outputVal = sensorVals[NAV_N]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav N Trig Fast");
    }

    QTimer::singleShot(100, this, SLOT(slotFastTriggerOffN()));
}

void NavDataCooker::slotFastTriggerOffN()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav N Trig Fast");
    }
}

void NavDataCooker::navNTrigDbl()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffN && !dblTrigStateN)
    {
        triggerN.dblTriggerHit();
        dblTrigStateN = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffN && dblTrigStateN)
    {
        dblTrigStateN = false;
    }
}

void NavDataCooker::slotDblTriggerReturnN()
{
    int outputVal = sensorVals[NAV_N]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav N Trig Dbl");
    }

    QTimer::singleShot(100, this, SLOT(slotDblTriggerOffN()));
}

void NavDataCooker::slotDblTriggerOffN()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav N Trig Dbl");
    }
}

void NavDataCooker::navNTrigLong()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffN && !longTrigStateN)
    {
        triggerN.longTrigger();
        longTrigStateN = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffN && longTrigStateN)
    {
        longTrigStateN = false;
    }
}

void NavDataCooker::slotLongTriggerReturnN()
{
    int outputVal = sensorVals[NAV_N]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav N Trig Long");
    }

    QTimer::singleShot(100, this, SLOT(slotLongTriggerOffN()));
}

void NavDataCooker::slotLongTriggerOffN()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav N Trig Long");
    }
}

//--------------- South
void NavDataCooker::navSTrig()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffS && !trigStateS)
    {
        triggerS.trigger();
        trigStateS = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffS && trigStateS)
    {
        trigStateS = false;
    }
}

void NavDataCooker::slotTriggerReturnS()
{
    int outputVal = sensorVals[NAV_S]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav S Trig");
    }

    QTimer::singleShot(100, this, SLOT(slotTriggerOffS()));
}

void NavDataCooker::slotTriggerOffS()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav S Trig");
    }
}

void NavDataCooker::navSTrigFast()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffS && !fastTrigStateS)
    {
        triggerS.fastTrigger();
        fastTrigStateS = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffS && fastTrigStateS)
    {
        fastTrigStateS = false;
    }
}

void NavDataCooker::slotFastTriggerReturnS()
{
    int outputVal = sensorVals[NAV_S]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav S Trig Fast");
    }

    QTimer::singleShot(100, this, SLOT(slotFastTriggerOffS()));
}

void NavDataCooker::slotFastTriggerOffS()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav S Trig Fast");
    }
}

void NavDataCooker::navSTrigDbl()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffS && !dblTrigStateS)
    {
        triggerS.dblTriggerHit();
        dblTrigStateS = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffS && dblTrigStateS)
    {
        dblTrigStateS = false;
    }
}

void NavDataCooker::slotDblTriggerReturnS()
{
    int outputVal = sensorVals[NAV_S]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav S Trig Dbl");
    }

    QTimer::singleShot(100, this, SLOT(slotDblTriggerOffS()));
}

void NavDataCooker::slotDblTriggerOffS()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav S Trig Dbl");
    }
}

void NavDataCooker::navSTrigLong()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOffS && !longTrigStateS)
    {
        triggerS.longTrigger();
        longTrigStateS = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOffS && longTrigStateS)
    {
        longTrigStateS = false;
    }
}

void NavDataCooker::slotLongTriggerReturnS()
{
    int outputVal = sensorVals[NAV_S]; //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(outputVal, i, "Nav S Trig Long");
    }

    QTimer::singleShot(100, this, SLOT(slotLongTriggerOffS()));
}

void NavDataCooker::slotLongTriggerOffS()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Nav S Trig Long");
    }
}

void NavDataCooker::slotReceiveMidiInput(int val, QString instance)
{
    //For each modline
    for(int i = 0; i < 6; i++)
    {
        //qDebug() << i <<modlineSources.value(i) << modlineNum << val;

        if(modlineSources.value(i).contains(QString("MIDI %1").arg(instance)))
        {
            emit signalTransformSource(val, i, QString("MIDI %1").arg(instance));
        }
    }
}

//----------------------------------------------------------------------------------- Settings
void NavDataCooker::slotSetGlobalGain(float gain)
{
    globalGain = gain;
}

void NavDataCooker::slotSetOnThreshN(int threshold)
{
    onThreshN = threshold;
}

void NavDataCooker::slotSetOffThreshN(int threshold)
{
    offThreshN = threshold;
}

void NavDataCooker::slotSetOnThreshS(int threshold)
{
    onThreshS = threshold;
}

void NavDataCooker::slotSetOffThreshS(int threshold)
{
    offThreshS = threshold;
}

void NavDataCooker::slotSetOnThreshE(int threshold)
{
    onThreshE = threshold;
}

void NavDataCooker::slotSetOffThreshE(int threshold)
{
    offThreshE = threshold;
}

void NavDataCooker::slotSetOnThreshW(int threshold)
{
    onThreshW = threshold;
}

void NavDataCooker::slotSetOffThreshW(int threshold)
{
    offThreshW = threshold;
}

void NavDataCooker::slotSetYAccel(int accel)
{
    yAccel = accel;
}
