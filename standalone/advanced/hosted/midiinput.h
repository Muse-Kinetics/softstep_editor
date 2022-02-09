// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MIDIINPUT_H
#define MIDIINPUT_H

#include <QWidget>
#include <QDebug>

#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>
#else
#include <Windows.h>
#include <MMSystem.h>
#include <Dbt.h>
#include "WindowsMidiTypes.h"
#endif

class MidiInput : public QWidget
{
    Q_OBJECT
public:
    explicit MidiInput(QWidget *parent = 0);

    bool enable;
    QString device;
    int channel;
    QString type;
    int number;
    QString instance;
    
signals:
    void signalSendInputToModlines(int val, QString instnace);
    
public slots:
    void slotReceiveInput(int status, int firstByte, int secondByte, int chan, QString deviceName);
    
};

#endif // MIDIINPUT_H
