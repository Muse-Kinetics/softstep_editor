// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef ALPHANUMMANAGER_H
#define ALPHANUMMANAGER_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>
#else
#include <Windows.h>
#include <MMSystem.h>
#include <Dbt.h>
#include "WindowsMidiTypes.h"
#endif

class AlphaNumManager : public QObject
{
    Q_OBJECT
public:
    explicit AlphaNumManager(QObject *parent = 0);

    QTimer fifoClock;
    QList<MIDIPacket> packetFIFOList;
    QList<MIDIPacket> packetList;

    int instanceNum;
    QString displayMode;
    QString keyName;
    QString prefix;
    QString postfix; //Only used with nav pad in program change mode

    QString currentPresetName;

    bool paramDisplay;

    bool keyOnOff;

    QTimer keyOffTimeout;
    
signals:
    void signalSendDisplayVals(QString port, QList<MIDIPacket> packet);
    void signalSendPacket(uchar status, uchar  d1, uchar d2);
    
public slots:
    void slotDisplayKeyName(int keyNum);
    void slotDisplayParam(int modlineNum, int val);
    void slotPresetChangeDisplayPresetName();
    void slotFormatAndOutputString(QString displayString);
    void slotReturnToKeyName();
    void slotKeyOff(int keyNum);
    void slotKeyOffTimeout();

    //---------------------- Gates
    void slotOpenParamDisplay();
    void slotCloseParamDisplay();

    void slotDrainFIFO();


    
};

#endif // ALPHANUMMANAGER_H
