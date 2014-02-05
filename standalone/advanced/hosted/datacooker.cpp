// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "datacooker.h"
#include "key.h"
#include "mainwindow.h"
#include <QDebug>

#define PEDAL_CC 86

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

    //Init Key LockoutLists
    for(int i = 0; i < 10; i++)
    {
        switch (i)
        {
        case 0:
            adjacentKeyLockoutList[i].append(1);
            adjacentKeyLockoutList[i].append(5);
            adjacentKeyLockoutList[i].append(6);
            break;
        case 1:
            adjacentKeyLockoutList[i].append(0);
            adjacentKeyLockoutList[i].append(2);
            adjacentKeyLockoutList[i].append(5);
            adjacentKeyLockoutList[i].append(6);
            adjacentKeyLockoutList[i].append(7);
            break;
        case 2:
            adjacentKeyLockoutList[i].append(1);
            adjacentKeyLockoutList[i].append(3);
            adjacentKeyLockoutList[i].append(6);
            adjacentKeyLockoutList[i].append(7);
            adjacentKeyLockoutList[i].append(8);
            break;
        case 3:
            adjacentKeyLockoutList[i].append(2);
            adjacentKeyLockoutList[i].append(4);
            adjacentKeyLockoutList[i].append(7);
            adjacentKeyLockoutList[i].append(8);
            adjacentKeyLockoutList[i].append(9);
            break;
        case 4:
            adjacentKeyLockoutList[i].append(3);
            adjacentKeyLockoutList[i].append(8);
            adjacentKeyLockoutList[i].append(9);
            break;
        case 5:
            adjacentKeyLockoutList[i].append(0);
            adjacentKeyLockoutList[i].append(1);
            adjacentKeyLockoutList[i].append(6);
            break;
        case 6:
            adjacentKeyLockoutList[i].append(0);
            adjacentKeyLockoutList[i].append(1);
            adjacentKeyLockoutList[i].append(2);
            adjacentKeyLockoutList[i].append(5);
            adjacentKeyLockoutList[i].append(7);
            break;
        case 7:
            adjacentKeyLockoutList[i].append(1);
            adjacentKeyLockoutList[i].append(2);
            adjacentKeyLockoutList[i].append(3);
            adjacentKeyLockoutList[i].append(6);
            adjacentKeyLockoutList[i].append(8);
            break;
        case 8:
            adjacentKeyLockoutList[i].append(2);
            adjacentKeyLockoutList[i].append(3);
            adjacentKeyLockoutList[i].append(4);
            adjacentKeyLockoutList[i].append(7);
            adjacentKeyLockoutList[i].append(9);
            break;
        case 9:
            adjacentKeyLockoutList[i].append(3);
            adjacentKeyLockoutList[i].append(4);
            adjacentKeyLockoutList[i].append(8);
            break;
        default:
            break;
        }
    }

    keyNum = instanceNum;

    //Init pedal windower / calibrator
    pedal = new Pedal(this, keyNum);

    //------------------------------ Init settings
    onThresh = 10;
    offThresh = 5;

    yDeadZone = 16;
    xDeadZone = 16;

    yAccel = 10;
    xAccel = 10;

    //Init counters
    yIncClock = new QTimer(this);
    xIncClock = new QTimer(this);
    yIncCount = 0;
    xIncCount = 0;

    lastXCount = -1;
    lastYCount = -1;

    sensorResponse = 0; //0 - maximum 1 - avg

    fastTrigState = false;
    dblTrigState = false;
    longTrigState = false;
    offTrigState = false;
    fastTrigLatchState = false;
    dblTrigLatchState = false;
    longTrigLatchState = false;

    navYCount = 0;
    navYDecade = 0;


    //Init sensors
    for(int i=0; i<4; i++)
    {
        sensorVals[i] = 0;
    }

    //Init raw vars
    footOnOff = false;

    //Connect Latchers
    connect(&pressureLatcher, SIGNAL(signalReturnValue(int,int)), this, SLOT(slotPressureLatchReturn(int,int)));
    connect(&xLatcher, SIGNAL(signalReturnValue(int,int)), this, SLOT(slotXLatchReturn(int,int)));
    connect(&yLatcher, SIGNAL(signalReturnValue(int,int)), this, SLOT(slotYLatchReturn(int,int)));

    //Connect Inc/Dec Clocks
    connect(yIncClock, SIGNAL(timeout()), this, SLOT(slotTickYIncrementClock()), Qt::DirectConnection);
    connect(xIncClock, SIGNAL(timeout()), this, SLOT(slotTickXIncrementClock()), Qt::DirectConnection);

    //Trigger Returns
    connect(&trigger, SIGNAL(signalFastTriggerReturn()), this, SLOT(slotFastTriggerReturn()));
    connect(&trigger, SIGNAL(signalLongTriggerReturn()), this, SLOT(slotLongTriggerReturn()));
    connect(&trigger, SIGNAL(signalDblTriggerReturn()), this, SLOT(slotDblTriggerReturn()));
    connect(&trigger, SIGNAL(signalOffTriggerReturn()), this, SLOT(slotOffTriggerReturn()));
    connect(&trigger, SIGNAL(signalFastTriggerLatchReturn()), this, SLOT(slotFastTriggerLatchReturn()));
    connect(&trigger, SIGNAL(signalLongTriggerLatchReturn()), this, SLOT(slotLongTriggerLatchReturn()));
    connect(&trigger, SIGNAL(signalDblTriggerLatchReturn()), this, SLOT(slotDblTriggerLatchReturn()));

    previousKeyPressed[0] = -1;
    previousKeyPressed[1] = -1;

    globalGain = 1.0;

    isSS2 = false;

}

void DataCooker::slotSetSource(QString source, int modlineInstance)
{
    modlineSources.insert(modlineInstance, source);

    for(int i = 0; i < modlineSources.size(); i++)
    {
        //qDebug () << "key" << keyNum << i << modlineSources.value(i);
    }
}

void DataCooker::slotUpdateVals(int cc, int val)
{
    val *= globalGain;

    if(cc >= keySensorBaseCcMap[keyNum] && cc <= keySensorBaseCcMap[keyNum] + 3)
    {
        //------------------------------------------------- Update Values -------------------------------------------------//
        //Always keep values updated, even if key action is now allowed
        if(cc == keySensorBaseCcMap[keyNum])
        {
            if(isSS2)
            {
                sensorVals[N] = val;
            }
            else
            {
                sensorVals[NW] = val;
            }

        }
        else if(cc == keySensorBaseCcMap[keyNum] + 1)
        {
            if(isSS2)
            {
                sensorVals[E] = val;
            }
            else
            {
                sensorVals[NE] = val;
            }

        }
        else if(cc == keySensorBaseCcMap[keyNum] + 2)
        {
            if(isSS2)
            {
                sensorVals[W] = val;
            }
            else
            {
                sensorVals[SW] = val;
            }

        }
        else if(cc == keySensorBaseCcMap[keyNum] + 3)
        {
            if(isSS2)
            {
                sensorVals[S] = val;
            }
            else
            {
                sensorVals[SE] = val;
            }
        }

        //------------------------------------------------- Handle Lockouts -------------------------------------------------//

        cookLockout();

        //------------------------------------------- All Keys
        if(keySafetyMode == ALL_KEYS)
        {
            //Always allow action on key
            activateKey = true;
        }

        //------------------------------------------- Single Key
        else if(keySafetyMode == SINGLE_KEY)
        {
            //If there are no keys pressed the moment
            if(lockoutKeysPressed.size() == 0)
            {
                //Allow key action
                activateKey = true;
            }

            //If there are already keys pressed, and it is this one
            else if(lockoutKeysPressed.contains(keyNum))
            {
                //Continue to allow action on key
                activateKey = true;
            }

            //Otherwise...
            else
            {
                activateKey = false;
            }
        }

        //------------------------------------------- Adjacent Key
        else if(keySafetyMode == ADJACENT_KEYS)
        {

            //If there are no keys pressed the moment
            if(lockoutKeysPressed.size() == 0)
            {
                //Allow key action
                activateKey = true;
            }

            //If there are already keys pressed, and it is this one
            else if(lockoutKeysPressed.contains(keyNum))
            {
                //Continue to allow action on key
                activateKey = true;
            }

            //If this key is not in our list of currently pressed keys
            else if(!lockoutKeysPressed.contains(keyNum))
            {
                //Iterate through the current keys pressed...
                for(int i = 0; i <lockoutKeysPressed.size(); i++)
                {
                    //If this key is contained in any of the currently pressed keys' forbidden adjacent lists
                    if(adjacentKeyLockoutList[lockoutKeysPressed.at(i)].contains(keyNum))
                    {
                        //Disallow action on this key
                        activateKey = false;
                        break;
                    }

                    //This key passes each iteration... (avoids above break)
                    else
                    {
                        //Allow action on this key
                        activateKey = true;
                    }
                }
            }

            //Otherwise... this should happen, if it does don't allow for now
            else
            {
                qDebug() << "WARNING: Lockout - No conditions met. Disallowing key action on Key" << keyNum;
                activateKey = false;
            }
        }



        //qDebug() << "Key" << keyNum << "Sensor Vals" << sensorVals[NW] << sensorVals[NE] << sensorVals[SW] << sensorVals[SE];

        //Always cook raw, even if key action is now allowed

        if(activateKey == true)
        {
            //qDebug() << "cook this key" << keyNum;
            cookRaw();
            cookSources();
        }
    }

    //Pedal can always be streamed through a key, regardless of lockouts
    else if(cc == PEDAL_CC)
    {
        //qDebug() << "get pedal input" << val;
        //Run input through our pedal class (per key)
        pedalVal = pedal->slotWindowInput(val);

        //If windowing returns a valid value
        if(pedalVal != -1)
        {
            //Send value to all modlines of this key containing Pedal as a source
            for(int i = 0; i < 6; i++)
            {
                if(modlineSources.value(i) == "Pedal")
                {
                    //qDebug () << "key" << keyNum << pedalVal << i;
                    emit signalTransformSource(pedalVal, i, "Pedal");
                }
            }
        }
    }
}

void DataCooker::cookLockout()
{
    //--- !!! This Function is pre-cooking and always called when new data is received !!! ---//

    //If raw pressure is greater than on-thresh and current state of key is off
    if(pressureRaw() > onThresh && !footOnOff)
    {
        if(keySafetyMode == SINGLE_KEY)
        {
            //If this key is in the list already, or the list is empty (no keys pressed)
            if(lockoutKeysPressed.contains(keyNum) || lockoutKeysPressed.isEmpty())
            {
                parentKey->mw->slotLockoutKeyPressedReleased(keyNum, true);
            }
        }
        else if(keySafetyMode == ADJACENT_KEYS)
        {
            //If this key is in the list already, or the list is empty (no keys pressed)
            if(lockoutKeysPressed.contains(keyNum) || lockoutKeysPressed.isEmpty())
            {
                //Reiterate its inclusion-- this may be unnecessary
                parentKey->mw->slotLockoutKeyPressedReleased(keyNum, true);
            }

            //If this key is not in the list and there are items in the list
            else
            {
                int thisIsAnAdjacentKey = false;

                //Iterate through the keys currently being pressed adjacent key lists
                for(int i = 0; i < lockoutKeysPressed.size(); i++)
                {
                    if(!adjacentKeyLockoutList[lockoutKeysPressed.at(i)].contains(keyNum))
                    {
                        thisIsAnAdjacentKey = false;
                    }
                    else
                    {
                        //If adjacent to any key listed, flip flag and exit loop
                        thisIsAnAdjacentKey = true;
                        break;
                    }
                }

                //If this is not considered an adjacent key by any of the currently pressed keys
                if(!thisIsAnAdjacentKey)
                {
                    //Add it to the list
                    parentKey->mw->slotLockoutKeyPressedReleased(keyNum, true);
                }
            }
        }
        else if(keySafetyMode == ALL_KEYS)
        {
            //No need for list management
        }
    }

    //If pressure is below off-thresh and foot is currently on
    else if(pressureRaw() < offThresh && footOnOff)
    {
        parentKey->mw->slotLockoutKeyPressedReleased(keyNum, false);
    }
}

void DataCooker::slotLockoutKeyPressedReleased(int keyNumber, bool pressedReleased)
{
    //If key sending message is being pressed
    if(pressedReleased) // pressed == TRUE
    {
        //If the keyNumber is not listed in current keys pressed
        if(!lockoutKeysPressed.contains(keyNumber))
        {
            //Add it to our lockout list
            lockoutKeysPressed.append(keyNumber);
        }
    }

    //If key sending message is being released
    else
    {
        //If key number is listed in current keys pressed (should always be the case)
        if(lockoutKeysPressed.contains(keyNumber))
        {
            lockoutKeysPressed.removeAt(lockoutKeysPressed.indexOf(keyNumber));
        }

        //Trying to remove key from lockout list that is not present
        else
        {
            //qDebug() << "ERROR: trying to remove key from lockout list that is not present";
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
        //qDebug() << "emit key presed";
        emit signalThisKeyPressed(keyNum);
    }

    //If pressure is below off-thresh and foot is currently on
    else if(pressureRaw() < offThresh && footOnOff)
    {
        //Flip off
        footOnOff = false;
        emit signalThisKeyOff(keyNum);
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
            xLatch(i);
        }
        else if(modlineSources.value(i) == "Y Latch")
        {
            yLatch(i);
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

        //-------- X/Y Increment
        else if(modlineSources.value(i) == "X Increment")
        {
            xIncrement();
        }
        else if(modlineSources.value(i) == "Y Increment")
        {
            yIncrement();
        }

        //-------- Top/Bottom
        else if(modlineSources.value(i) == "Top")
        {
            emit signalTransformSource(top(), i, "Top");
        }
        else if(modlineSources.value(i) == "Bottom")
        {
            emit signalTransformSource(bottom(), i, "Bottom");
        }

        //-------- Trig
        else if(modlineSources.value(i) == "Fast Trig")
        {
            fastTrig();
        }
        else if(modlineSources.value(i) == "Dbl Trig")
        {
            dblTrig();
        }
        else if(modlineSources.value(i) == "Long Trig")
        {
            longTrig();
        }
        else if(modlineSources.value(i) == "Off Trig")
        {
            offTrig();
        }
        else if(modlineSources.value(i) == "Delta Trig")
        {
            deltaTrig();
        }

        //-------- Trig Latch
        else if(modlineSources.value(i) == "Fast Trig Latch")
        {
            fastTrigLatch();
        }
        else if(modlineSources.value(i) == "Dbl Trig Latch")
        {
            dblTrigLatch();
        }
        else if(modlineSources.value(i) == "Long Trig Latch")
        {
            longTrigLatch();
        }

        //------- Pedal
        else if(modlineSources.value(i) == "Pedal")
        {
            //emit signalTransformSource(pedalVal, i, "Pedal");
        }

        else if(modlineSources.value(i) == "Nav Yx10 & Key")
        {
            //emit signalTransformSource(navYCountFunc(), i, "Nav Yx10 & Key");
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////    Sources   //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------- Foot On/Off
int DataCooker::footOn()
{
    //If pressure is greater than on-thresh and current state of key is off
    if(footOnOff)
    {

        return 127;
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
        return 127;
    }
    else
    {
        return 0;
    }
}

//-------------------------------------------------------------------- Live
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
    int eastMass;
    int westMass;

    if(isSS2)
    {
        eastMass = sensorVals[E];
        westMass = sensorVals[W];
    }
    else
    {
        eastMass = sensorVals[NE] + sensorVals[SE];
        westMass = sensorVals[NW] + sensorVals[SW];
    }

    int totalMass = eastMass + westMass;
    int xLoc;

    if(footOnOff)
    {
        if(totalMass)
        {
            xLoc = ((westMass + eastMass*128) / totalMass) - 1;
        }
        else
        {
            xLoc = 63;
        }
    }
    else
    {
        xLoc = 63;
    }

    return xLoc;
}

int DataCooker::yLive()
{
    int northMass;
    int southMass;

    if(isSS2)
    {
        northMass = sensorVals[N];
        southMass = sensorVals[S];
    }
    else
    {
        northMass = sensorVals[NE] + sensorVals[NW];
        southMass = sensorVals[SE] + sensorVals[SW];
    }

    int totalMass = northMass + southMass;
    int yLoc;

    if(footOnOff)
    {
        if(totalMass)
        {
            yLoc = ((southMass + northMass*128) / totalMass) - 1;
        }
        else
        {
            yLoc = 63;
        }
    }
    else
    {
        yLoc = 63;
    }

    return yLoc;
}

//-------------------------------------------------------------------- Latching
int DataCooker::pressureLatch(int modlineNum)
{
    if(footOnOff)
    {
        pressureLatcher.latchOpen = true;
        pressureLatcher.receiveInput(pressureLive(), modlineNum);
    }
    else
    {
        pressureLatcher.latchOpen = false;
    }
}

void DataCooker::slotPressureLatchReturn(int val, int modlineNum)
{
    qDebug() << "pressure latch return" << val << modlineNum;

    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(val, i, "Pressure Latch");
    }
}

int DataCooker::xLatch(int modlineNum)
{
    if(footOnOff)
    {
        xLatcher.latchOpen = true;
        xLatcher.receiveInput(xLive(), modlineNum);
    }
    else
    {
        xLatcher.latchOpen = false;
    }
}

void DataCooker::slotXLatchReturn(int val, int modlineNum)
{
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(val, i, "X Latch");
    }
}

int DataCooker::yLatch(int modlineNum)
{
    if(footOnOff)
    {
        yLatcher.latchOpen = true;
        yLatcher.receiveInput(yLive(), modlineNum);
    }
    else
    {
        yLatcher.latchOpen = false;
    }
}

void DataCooker::slotYLatchReturn(int val, int modlineNum)
{
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(val, i, "Y Latch");
    }
}

//-------------------------------------------------------------------- x,y Inc/Dec
void DataCooker::xIncrement()
{
    //If key is active
    if(footOnOff)
    {
        //If greater than dead zone
        if(xLive() > (63 + xDeadZone/2.5))
        {
            //Set inc/dec mode to inc
            xIncOrDec = true;

            //If clock is not running already
            if(!xIncClock->isActive())
            {
                //Start it...
                xIncClock->start(xAccel + 1); //Need to implement scaling here
            }
        }

        //If less than dead zone
        else if(xLive() < (63 - xDeadZone/2.5))
        {
            //Set inc/dec mod to dec
            xIncOrDec = false;

            //If clock is not running already
            if(!xIncClock->isActive())
            {
                //Start it...
                xIncClock->start(xAccel + 1); //Need to implement scaling here
            }
        }

        //If in dead zone, but foot is on
        else
        {
            //Stop clock
            xIncClock->stop();
        }
    }

    //If foot off, stop clock
    else
    {
        xIncClock->stop();
    }
}

void DataCooker::slotTickXIncrementClock()
{
    //Double check foot on, probably unnecessary but safe
    if(footOnOff)
    {

        if(xIncOrDec && xIncCount < 127) //True means inc, False means dec
        {
            xIncCount++;
        }
        else if(!xIncOrDec && xIncCount > 0)
        {
            xIncCount--;
        }

        if(lastXCount != xIncCount)
        {
            //Emit to all modlines because it's time based and has multiple processing threads
            for(int i = 0; i < 6; i++)
            {
                emit signalTransformSource(xIncCount, i, "X Increment");
            }


            lastXCount = xIncCount;
        }
    }

    //If foot off, stop clock
    else
    {
        xIncClock->stop();
    }
}

void DataCooker::slotXIncSet(int i)
{
    xIncCount = i;
}

void DataCooker::yIncrement()
{
    //If key is active
    if(footOnOff)
    {
        qDebug() << "key: " << keyNum << "ylive: " << yLive() << "deadzone: " << yDeadZone << "adjusted dead zone: " << (63 + yDeadZone/2.5);

        //If greater than dead zone
        if(yLive() > (63 + yDeadZone/2.5))
        {
            //Set inc/dec mode to inc
            yIncOrDec = true;

            //If clock is not running already
            if(!yIncClock->isActive())
            {
                //Start it...
                yIncClock->start((yAccel + 1)); //Need to implement scaling here
            }
        }

        //If less than dead zone
        else if(yLive() < (63 - yDeadZone/2.5))
        {
            //Set inc/dec mod to dec
            yIncOrDec = false;

            //If clock is not running already
            if(!yIncClock->isActive())
            {
                //Start it...
                yIncClock->start((yAccel + 1)); //Need to implement scaling here
            }
        }

        //If in dead zone, but foot is on
        else
        {
            //Stop clock
            yIncClock->stop();
        }
    }

    //If foot off, stop clock
    else
    {
        yIncClock->stop();
    }
}

void DataCooker::slotTickYIncrementClock()
{
    //Double check foot on, probably unnecessary but safe
    if(footOnOff)
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
                emit signalTransformSource(yIncCount, i, "Y Increment");
            }

            lastYCount = yIncCount;
        }
    }
    else
    {
        yIncClock->stop();
    }
}

void DataCooker::slotYIncSet(int i)
{
    yIncCount = i;
}

//-------------------------------------------------------------------- Top/Bottom
int DataCooker::top()
{
    //If key is active
    if(footOnOff)
    {
        //If greater than dead zone
        if(yLive() > (63 + yDeadZone/2.5))
        {
            return 127;
        }

        //If in not in top
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

int DataCooker::bottom()
{
    //If key is active
    if(footOnOff)
    {
        //If greater than dead zone
        if(yLive() < (63 - yDeadZone/2.5))
        {
            return 127;
        }

        //If in not bottom
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

//-------------------------------------------------------------------- Trigs
//----------------------------- Fast
void DataCooker::fastTrig()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !fastTrigState)
    {
        trigger.fastTrigger();
        fastTrigState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && fastTrigState)
    {
        fastTrigState = false;
    }
}

void DataCooker::slotFastTriggerReturn()
{
    int outputVal = pressureLive(); //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(127, i, "Fast Trig");
    }

    QTimer::singleShot(100, this, SLOT(slotFastTriggerOff()));

}

void DataCooker::slotFastTriggerOff()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Fast Trig");
    }
}

//----------------------------- Dbl
void DataCooker::dblTrig()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !dblTrigState)
    {
        trigger.dblTriggerHit();
        dblTrigState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && dblTrigState)
    {
        dblTrigState = false;
    }
}

void DataCooker::slotDblTriggerReturn()
{
    int outputVal = pressureLive(); //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(127, i, "Dbl Trig");
    }

    QTimer::singleShot(100, this, SLOT(slotDblTriggerOff()));
}

void DataCooker::slotDblTriggerOff()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Dbl Trig");
    }
}

//----------------------------- Long
void DataCooker::longTrig()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !longTrigState)
    {
        trigger.longTrigger();
        longTrigState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && longTrigState)
    {
        trigger.longTriggerAbort();
        longTrigState = false;
    }
}

void DataCooker::slotLongTriggerReturn()
{
    int outputVal = pressureLive(); //Only call once, send duplicates

    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(127, i, "Long Trig");
    }

    QTimer::singleShot(100, this, SLOT(slotLongTriggerOff()));
}

void DataCooker::slotLongTriggerOff()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Long Trig");
    }
}

//----------------------------- Off
void DataCooker::offTrig()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !offTrigState)
    {
        slotOffTriggerOff();
        offTrigState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && offTrigState)
    {
        trigger.offTrigger();
        offTrigState = false;
    }
}

void DataCooker::slotOffTriggerReturn()
{
    qDebug() << "Off Trigger";
    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(127, i, "Off Trig");
    }

    QTimer::singleShot(100, this, SLOT(slotOffTriggerOff()));
}

void DataCooker::slotOffTriggerOff()
{
    //Emit positive
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Off Trig");
    }
}

void DataCooker::deltaTrig()
{
    static int bucket[2] = {0,0};

    qDebug() << pressureLive();

    bucket[1] = bucket[0];
    bucket[0] = pressureLive();

    if(bucket[0] - bucket[1] > 10)
    {
        trigger.deltaTrigger();
    }
}

//-------------------------------------------------------------------- Trig Latch
void DataCooker::fastTrigLatch()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !fastTrigLatchState)
    {
        trigger.fastTriggerLatch();
        fastTrigLatchState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && fastTrigLatchState)
    {
        fastTrigLatchState = false;
    }
}
//----------------------------- Fast
void DataCooker::slotFastTriggerLatchReturn()
{
    qDebug() << "fast trig latch return";
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Fast Trig Latch");
    }

    QTimer::singleShot(30, this, SLOT(slotFastTriggerLatchOff()));
}

void DataCooker::slotFastTriggerLatchOff()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        //emit signalTransformSource(pressureLive(), i, "Fast Trig Latch");
        emit signalTransformSource(127, i, "Fast Trig Latch");
    }
}

//----------------------------- Dbl
void DataCooker::dblTrigLatch()
{

    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !dblTrigLatchState)
    {
        trigger.dblTriggerLatchHit();
        dblTrigLatchState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && dblTrigLatchState)
    {
        dblTrigLatchState = false;
    }
}

void DataCooker::slotDblTriggerLatchReturn()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Dbl Trig Latch");
    }

    QTimer::singleShot(30, this, SLOT(slotDblTriggerLatchOff()));
}

void DataCooker::slotDblTriggerLatchOff()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        //emit signalTransformSource(pressureLive(), i, "Dbl Trig Latch");
        emit signalTransformSource(127, i, "Dbl Trig Latch");
    }
}

//----------------------------- Long
void DataCooker::longTrigLatch()
{
    //If foot is on and state is false, flip state on - this represents a trigger scenario
    if(footOnOff && !longTrigLatchState)
    {
        trigger.longTriggerLatch();
        longTrigLatchState = true;
    }

    //If foot is off (regardless of state), flip state off
    else if(!footOnOff && longTrigLatchState)
    {
        trigger.longTriggerLatchAbort();
        longTrigLatchState = false;
    }
}

void DataCooker::slotLongTriggerLatchReturn()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        emit signalTransformSource(0, i, "Long Trig Latch");
    }

    QTimer::singleShot(30, this, SLOT(slotLongTriggerLatchOff()));
}

void DataCooker::slotLongTriggerLatchOff()
{
    //Emit zero
    for(int i = 0; i < 6; i++)
    {
        //emit signalTransformSource(pressureLive(), i, "Long Trig Latch");
        emit signalTransformSource(127, i, "Long Trig Latch");
    }
}

//-------------------------------------------------------------------- Nav


//-------------------------------------------------------------------- Key Specific Sources
void DataCooker::slotReceiveKeyPressed(int keyPressed)
{
    keyPressed = (keyPressed + 1)%10;

    previousKeyPressed[1] = previousKeyPressed[0];
    previousKeyPressed[0] = keyPressed;

    //qDebug() << "this key:" << keyNum << "key pressed" << keyPressed;

    //For each modline
    for(int i = 0; i < 6; i++)
    {
        //------- Key Sources
        if(modlineSources.value(i) == "Any Key Value")
        {
            emit signalTransformSource(keyPressed, i, "Any Key Value");
        }
        else if(modlineSources.value(i) == "This Key Value")
        {
            if(keyPressed == (keyNum + 1)%10)
            {
                emit signalTransformSource(keyPressed, i, "This Key Value");
            }
        }
        else if(modlineSources.value(i) == "Prev Key Value")
        {
            if(previousKeyPressed[1] != -1)
            {
                emit signalTransformSource(previousKeyPressed[1], i, "Prev Key Value");
            }
        }
        else if(modlineSources.value(i).contains("Key") && modlineSources.value(i).contains("Pressed") && !modlineSources.value(i).contains("Other"))
        {
            emit signalTransformSource(0, i, QString("Key %1 Pressed").arg(keyPressed));
            emit signalTransformSource(127, i, QString("Key %1 Pressed").arg(keyPressed));
        }
        else if((modlineSources.value(i) == "Other Key Pressed") && (keyPressed != (keyNum + 1)%10))
        {
            emit signalTransformSource(0, i, "Other Key Pressed");
            emit signalTransformSource(127, i, "Other Key Pressed");
        }
        else if(modlineSources.value(i) == "Nav Yx10 & Key")
        {
            if(keyPressed == (keyNum + 1)%10)
            {
                emit signalTransformSource(navYDecade + keyPressed, i, "Nav Yx10 & Key");
            }
        }
    }
}

//-------------------------------------------------------------------- Key # Pressed, Other Key Pressed
void DataCooker::slotKeyPressed()
{

}

//------------------------------------------------------------------- Modline # Output
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

//-------------------------------------------------------------------- MIDI Input
void DataCooker::slotReceiveMidiInput(int val, QString instance)
{
    //qDebug() << "midi input:" << val;

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

//-------------------------------------------------------------------- OSC Input
void DataCooker::slotReceiveOscInput(int inputNum, int val)
{
    //qDebug() << "key osc input" << inputNum << "val-- " << val;

    //For each modline
    for(int i = 0; i < 6; i++)
    {
        //qDebug() << i <<modlineSources.value(i) << modlineNum << val;

        QString source = modlineSources.value(i);

        if(source.contains("OSC"))
        {
            if(source == "OSC A" && inputNum == 0)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC B" && inputNum == 1)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC C" && inputNum == 2)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC D" && inputNum == 3)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC E" && inputNum == 4)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC F" && inputNum == 5)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC G" && inputNum == 6)
            {
                emit signalTransformSource(val, i, source);
            }
            else if(source == "OSC H" && inputNum == 7)
            {
                emit signalTransformSource(val, i, source);
            }
        }
    }
}

//-------------------------------------------------------------------- Nav Sources
void DataCooker::slotReceiveNavY(int count)
{
    //For each modline
    for(int i = 0; i < 6; i++)
    {
        if(modlineSources.value(i) == "Nav Y")
        {
            qDebug() << "nav y count in key" << count << i;

            emit signalTransformSource(count, i, "Nav Y");
        }
    }
}

void DataCooker::slotReceiveNavDecade(int decade)
{
    navYDecade = decade;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// State Recall /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void DataCooker::slotStateRecallXIncDec(int val)
{
    xIncCount = val;
}

void DataCooker::slotStateRecallYIncDec(int val)
{
    yIncCount = val;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Settings ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void DataCooker::slotSetOnThresh(int key, int threshold)
{
    if(keyNum == key)
    {
        onThresh = threshold;
    }
}

void DataCooker::slotSetOffThresh(int key, int threshold)
{
    if(keyNum == key)
    {
        offThresh = threshold;
    }
}

void DataCooker::slotSetYDeadZone(int key, int deadZone)
{
    //qDebug() << "set y deadzone  key:" << key << "dZone" << deadZone;

    if(keyNum == key)
    {
        qDebug() << "key" <<  key << "y deadzone" << deadZone;
        yDeadZone = deadZone;
    }
}

void DataCooker::slotSetXDeadZone(int key, int deadZone)
{
    if(keyNum == key)
    {
        xDeadZone = deadZone;
    }
}

void DataCooker::slotSetYAccel(int key, int accel)
{
    if(keyNum == key)
    {
        yAccel = (float)(127.0f - accel + 1.0f)/127.0f * 50;
    }

}

void DataCooker::slotSetXAccel(int key, int accel)
{
    if(keyNum == key)
    {
        xAccel = (float)(127.0f - accel + 1.0f)/127.0f * 50;
    }

}

void DataCooker::slotSetGlobalGain(float val)
{
    globalGain = val;
    //qDebug() << "key global gain" << globalGain;
}

void DataCooker::slotSetSensorResponse(int response)
{
    //qDebug() << "response" << response;
    sensorResponse = response;
}

void DataCooker::slotSetKeySafetyMode(int mode)
{
    keySafetyMode = mode;
    //qDebug() << "Key Saftey Mode:" << keyNum << mode;
}

void DataCooker::slotSetParentKey(Key *pK)
{
    parentKey = pK;
}
