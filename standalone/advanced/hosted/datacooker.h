// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef DATACOOKER_H
#define DATACOOKER_H

#include <QWidget>
#include <QMap>

#include "hosted/latcher.h"
#include "hosted/trigger.h"

enum {NW, NE, SW, SE};

class DataCooker : public QWidget
{
    Q_OBJECT
public:
    explicit DataCooker(int instanceNum, QWidget *parent = 0);

    int                 sensorVals[4];
    int                 keyNum;
    QMap<int, int>      keySensorBaseCcMap;

    QMap<int, QString>  modlineSources;

    //Latching sources
    Latcher pressureLatcher;
    Latcher xLatcher;
    Latcher yLatcher;

    //Inc Dec
    QTimer* yIncClock;
    bool    yIncOrDec; //True means inc and False means dec, of course.
    QTimer* xIncClock;
    bool    xIncOrDec;
    int     yIncCount;
    int     xIncCount;
    int     yIncModlineNum;
    int     xIncModlineNum;

    //Triggers
    Trigger trigger;

    void                cookRaw();
    void                cookSources();

    //------------------------------- Source Cooking
    int     pressureRaw();

    int     pressureLive();
    int     xLive();
    int     yLive();

    int    footOn();
    int    footOff();
    bool   footOnOff;

    int    modlineOutput(int modlineNum);

    int     pressureLatch(int modlineNum);
    int     xLatch(int modlineNum);
    int     yLatch(int modlineNum);

    void     xIncrement();
    void     yIncrement();

    int top();
    int bottom();


    //void    waitTrig();
    void    fastTrig();
    void    dblTrig();
    void    longTrig();
    void    offTrig();
    void    deltaTrig();

/*
    void    waitTrigLatch();
    void    fastTrigLatch();
    void    doubleTrigLatch();
    void    longTrigLatch();
*/

    //------- Settings
    int onThresh;
    int offThresh;
    int yDeadZone;
    int xDeadZone;
    int yAccel;
    int xAccel;

    int sensorResponse; //0 - maximum 1 - avg
    float globalGain;
    int keySafetyMode;

    
signals:
    void signalTransformSource(int data, int modlineNum, QString source);
    
public slots:
    void slotUpdateVals(int cc, int val);
    void slotReceiveModlineOutput(int modlineNum, int val);

    void slotSetSource(QString source, int modlineInstance);

    //----------------------------- Latching Return Slots
    void slotPressureLatchReturn(int val, int modlineNum);
    void slotXLatchReturn(int val, int modlineNum);
    void slotYLatchReturn(int val, int modlineNum);

    //----------------------------- IncDec Clock Slots
    void slotTickXIncrementClock();
    void slotTickYIncrementClock();

    //----------------------------- Trigger Return and Off Slots
    //Fast
    void slotFastTriggerReturn();
    void slotFastTriggerOff();

    //Long
    void slotLongTriggerReturn();
    void slotLongTriggerOff();

    //Dbl
    void slotDblTriggerReturn();
    void slotDblTriggerOff();

    //Off
    void slotOffTriggerReturn();
    void slotOffTriggerOff();

    //Delta
};

#endif // DATACOOKER_H
