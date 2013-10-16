// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef DATACOOKER_H
#define DATACOOKER_H

#include <QWidget>
#include <QMap>

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

    /*int     pressureLatch();
    int     xLatch();
    int     yLatch();

    int     xIncrement();
    int     yIncrement();

    void    top();
    void    bottom();

    void    waitTrig();
    void    fastTrig();
    void    doubleTrig();
    void    longTrig();
    void    offTrig();
    void    deltaTrig();

    void    waitTrigLatch();
    void    fastTrigLatch();
    void    doubleTrigLatch();
    void    longTrigLatch();*/

    //------- Settings
    int onThresh;
    int offThresh;

    int sensorResponse; //0 - maximum 1 - avg


    
signals:
    void signalTransformSource(int data, int modlineNum, QString source);
    
public slots:
    void slotUpdateVals(int cc, int val);
    void slotReceiveModlineOutput(int modlineNum, int val);

    void slotSetSource(QString source, int modlineInstance);
    void slotCloseSource(QString source, int modlineInstance);
};

#endif // DATACOOKER_H
