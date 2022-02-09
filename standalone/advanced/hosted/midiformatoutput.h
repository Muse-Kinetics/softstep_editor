// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MIDIFORMATOUTPUT_H
#define MIDIFORMATOUTPUT_H

#include <QWidget>
#include <QDebug>



#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>
#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <AudioUnit/AudioUnit.h>
#else
#include <Windows.h>
#include <MMSystem.h>
#include <Dbt.h>
#include "WindowsMidiTypes.h"
#endif

class MidiFormatOutput : public QWidget
{
    Q_OBJECT
public:
    explicit MidiFormatOutput(QWidget *parent = 0);
    
signals:

    void signalSendMidiPacketList(QString port, uchar status, uchar d1, uchar d2, uchar channel);
    void signalSendMidiPacketArray(QString port, QByteArray packet);

public slots:
    void slotPreparePacket();

    void slotNoteSet(QString port, int channel, int note, int velocity);
    void slotNoteLive(QString port, int channel, int oldNote, int newNote, int velocity);
    void slotCC(QString port, int channel, int ccNum, int ccVal);
    void slotBank(QString port, int channel, int msb, int lsb);
    //void slotOSC();
    void slotProgram(QString port, int channel, int program);
    void slotPitchBend(QString port, int channel, int lsb, int msb);
    void slotMMC(QString port, int id, QString function);
    void slotAftertouch(QString port, int channel, int val);
    void slotPolyAftertouch(QString port, int channel, int note, int val);
    //void slotGarageBand();
    //void slotHUI();
};

#endif // MIDIFORMATOUTPUT_H
