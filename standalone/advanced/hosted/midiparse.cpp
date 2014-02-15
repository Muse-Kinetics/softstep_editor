// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "midiparse.h"

MidiParse::MidiParse(QWidget *parent) :
    QWidget(parent)
{
}

//Used only for SSCOM Port 1 data, tethered data
void MidiParse::slotParsePacket(const MIDIPacket* packet)
{
    if(packet->data[0] == 176)
    {
        //qDebug() << "midi parse call" << packet->data[1] << packet->data[2];
        emit signalUpdateSensor(packet->data[1], packet->data[2]);
    }
}
