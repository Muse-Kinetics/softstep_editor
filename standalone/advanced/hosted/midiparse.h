// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MIDIPARSE_H
#define MIDIPARSE_H

#include <QWidget>

#include <QDebug>

#include <CoreMIDI/CoreMIDI.h>
#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CoreFoundation.h>

class MidiParse : public QWidget
{
    Q_OBJECT
public:
    explicit MidiParse(QWidget *parent = 0);
    
signals:
    void signalUpdateSensor(int cc, int data);
    
public slots:
    void slotParsePacket(const MIDIPacket *packet);
    
};

#endif // MIDIPARSE_H
