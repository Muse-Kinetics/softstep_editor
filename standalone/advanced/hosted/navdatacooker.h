// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef NAVDATACOOKER_H
#define NAVDATACOOKER_H

#include <QWidget>
#include <QMap>

#include "hosted/latcher.h"
#include "hosted/trigger.h"
#include "hosted/slewer.h"

enum {NAV_W, NAV_E, NAV_N, NAV_S};

class NavDataCooker : public QWidget
{
    Q_OBJECT
public:
    explicit NavDataCooker(QWidget *parent = 0);

    int pedalVal;

    int sensorVals[4];
    int keySensorBaseCcMap;

    QMap<int, QString> modlineSources;

    //Inc Dec
    QTimer* yIncClock;
    bool    yIncOrDec; //true means inc and false means dec, of course.
    int     yIncCount;
    int     yIncModlineNum;
    int     lastYCount;
    int     counterMin;
    int     counterMax;
    bool    counterWrap;

    //Triggers
    Trigger triggerN;
    bool trigStateN;
    bool fastTrigStateN;
    bool dblTrigStateN;
    bool longTrigStateN;

    Trigger triggerS;
    bool trigStateS;
    bool fastTrigStateS;
    bool dblTrigStateS;
    bool longTrigStateS;

    void cookSources();
    void cookRaw();

    int footOnOffN;
    int footOnOffS;
    int footOnOffE;
    int footOnOffW;

    bool presetChangeGate;

    //-------------------------------- Source Cooking
    bool navYGate;
    int navYCount;
    int navY();

    int navYDecade();
    int navYIncDec();

    int navNFootOn();
    int navSFootOn();
    int navNFootOff();
    int navSFootOff();

    int navEFootOn();
    int navWFootOn();

    void navNTrig();
    void navNTrigFast();
    void navNTrigDbl();
    void navNTrigLong();
    void navSTrig();
    void navSTrigFast();
    void navSTrigDbl();
    void navSTrigLong();

    //------------------------- Settings
    int onThreshN;
    int offThreshN;
    int onThreshS;
    int offThreshS;
    int onThreshE;
    int offThreshE;
    int onThreshW;
    int offThreshW;
    int yAccel;
    int navYDeadZone;

    float globalGain;
    float navNGain;
    float navSGain;
    float navEGain;
    float navWGain;
    
signals:
    void signalTransformSource(int data, int modlineNum, QString source);
    void signalNavY(int yCount);
    void signalNavDecade(int yDecade);
    void signalPresetChange(bool); //true for next, false for previous
    void signalThisKeyPressed(int);
    
public slots:
    void slotUpdateVals(int cc, int val);

    void slotSetSource(QString source, int modlineInstance);

    void slotSetCounterParams(int min, int max, bool wrap);

    //------------------------ IncDec clock slots
    void slotTickYIncrementClock();

    //------------------------- Trigger Return Slots North
    void slotTriggerReturnN();
    void slotTriggerOffN();

    //Fast
    void slotFastTriggerReturnN();
    void slotFastTriggerOffN();

    //Long
    void slotLongTriggerReturnN();
    void slotLongTriggerOffN();

    //Dbl
    void slotDblTriggerReturnN();
    void slotDblTriggerOffN();

    //------------------------- Trigger Return Slots South
    void slotTriggerReturnS();
    void slotTriggerOffS();

    //Fast
    void slotFastTriggerReturnS();
    void slotFastTriggerOffS();

    //Long
    void slotLongTriggerReturnS();
    void slotLongTriggerOffS();

    //Dbl
    void slotDblTriggerReturnS();
    void slotDblTriggerOffS();

    //-------------------------- MIDI Input
    void slotReceiveMidiInput(int val, QString instance);

    //------------------------------- Settings
    //Global Gain
    void slotSetGlobalGain(float);

    //N
    void slotSetOnThreshN(int);
    void slotSetOffThreshN(int);

    //S
    void slotSetOnThreshS(int);
    void slotSetOffThreshS(int);

    //E
    void slotSetOnThreshE(int);
    void slotSetOffThreshE(int);

    //W
    void slotSetOnThreshW(int);
    void slotSetOffThreshW(int);

    //Y Accel
    void slotSetYAccel(int);


};

#endif // NAVDATACOOKER_H
