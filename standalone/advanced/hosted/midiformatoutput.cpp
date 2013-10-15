// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "midiformatoutput.h"

MidiFormatOutput::MidiFormatOutput(QWidget *parent) :
    QWidget(parent)
{
}

void MidiFormatOutput::slotPreparePacket()
{

}


//------------------------------------- Formatting
void MidiFormatOutput::slotNoteSet(QString port, int channel, int note, int velocity)
{

}

void MidiFormatOutput::slotNoteLive(int channel, int oldNote, int newNote, int velocity)
{

}

void MidiFormatOutput::slotCC(QString port, int channel, int ccNum, int ccVal)
{
    qDebug() << "slotCC called" << ccVal;
    MIDIPacket packet;

    //Byte packetData[3] = {176, ccNum, ccVal};

    packet.timeStamp = 0;
    packet.length = 3;
    packet.data[0] = 176;
    packet.data[1] = ccNum;
    packet.data[2] = ccVal;

    emit signalSendMidiPacketList(packet);
}

void MidiFormatOutput::slotBank(QString port, int channel, int msb, int lsb)
{

}

void MidiFormatOutput::slotProgram(QString port, int channel, int program)
{

}

void MidiFormatOutput::slotPitchBend(QString port, int channel)
{

}

void MidiFormatOutput::slotMMC(QString port, int id, QString function)
{

}

void MidiFormatOutput::slotAftertouch(QString port, int channel, int val)
{

}

void MidiFormatOutput::slotPolyAftertouch(QString port, int channel, int note, int val)
{

}
