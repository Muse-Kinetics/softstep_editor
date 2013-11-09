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

enum {W, E, N, S};

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

    //Triggers
    Trigger trigger;
    bool fastTrigState;
    bool dblTrigState;
    bool longTrigState;

    void cookSources();
    void cookRaw();

    int footOnOffN;
    int footOnOffS;
    int footOnOffE;
    int footOnOffW;

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
    //void signalTransformSource(int data, int modlineNum, QString source);
    
public slots:
    void slotUpdateVals(int cc, int val);
    void slotReceiveModlineOutput(int modlineNum, int val);

    void slotSetSource(QString source, int modlineInstance);

    //------------------------ IncDec clock slots
    void slotTickYIncrementClock();

    //------------------------- Trigger Return Slots
    //Fast
    void slotFastTriggerReturn();
    void slotFastTriggerOff();

    //Long
    void slotLongTriggerReturn();
    void slotLongTriggerOff();

    //Dbl
    void slotDblTriggerReturn();
    void slotDblTriggerOff();

    //-------------------------- MIDI Input
    void slotReceiveMidiInput(int val, QString instance);

};

#endif // NAVDATACOOKER_H
