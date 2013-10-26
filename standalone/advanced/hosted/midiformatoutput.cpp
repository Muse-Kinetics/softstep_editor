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
    //qDebug() << "slotNoteSet";

    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 3;

    if(velocity)
    {
        //Note On
        packet.data[0] = 143 + channel;

    }
    else
    {
        //Note Off
        packet.data[0] = 127 + channel;
    }

    packet.data[1] = note;
    packet.data[2] = velocity;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotNoteLive(QString port, int channel, int oldNote, int newNote, int velocity)
{
    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 3;

    //If there is an old note
    if(oldNote != -1)
    {
        //Old note
        packet.data[0] = 127 + channel;
        packet.data[1] = oldNote;
        packet.data[2] = 0;

        emit signalSendMidiPacketList(port, packet);
    }

    //New Note
    packet.data[0] = 143 + channel;
    packet.data[1] = newNote;
    packet.data[2] = velocity;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotCC(QString port, int channel, int ccNum, int ccVal)
{
    //qDebug() << "slotCC called" << ccVal;
    MIDIPacket packet;

    //Byte packetData[3] = {176, ccNum, ccVal};

    packet.timeStamp = 0;
    packet.length = 3;
    packet.data[0] = 175 + channel;
    packet.data[1] = ccNum;
    packet.data[2] = ccVal;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotBank(QString port, int channel, int msb, int lsb)
{
    MIDIPacket packet;

    //Byte packetData[3] = {176, ccNum, ccVal};

    packet.timeStamp = 0;
    packet.length = 6;
    packet.data[0] = 175 + channel;
    packet.data[1] = 0;
    packet.data[2] = msb;
    packet.data[3] = 175 + channel;
    packet.data[4] = 32;
    packet.data[5] = lsb;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotProgram(QString port, int channel, int program)
{
    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 2;
    packet.data[0] = 191 + channel;
    packet.data[1] = program;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotPitchBend(QString port, int channel, int lsb, int msb)
{
    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 3;
    packet.data[0] = 223 + channel;
    packet.data[1] = lsb;
    packet.data[2] = msb;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotMMC(QString port, int id, QString function)
{
    MIDIPacket packet;

    int functionNum = 0;

    if(function == "Stop")
    {
        functionNum = 1;
    }
    else if (function == "Play")
    {
        functionNum = 2;
    }
    else if (function == "Deferred Play")
    {
        functionNum = 3;
    }
    else if (function == "Fast Forward")
    {
        functionNum = 4;
    }
    else if (function == "Rewind")
    {
        functionNum = 5;
    }
    else if (function == "Punch In")
    {
        functionNum = 6;
    }
    else if (function == "Punch Out")
    {
        functionNum = 7;
    }
    else if (function == "Pause")
    {
        functionNum = 8;
    }

    if(functionNum)
    {
        packet.timeStamp = 0;
        packet.length = 6;
        packet.data[0] = 240;
        packet.data[1] = 127;
        packet.data[2] = id;
        packet.data[3] = 6;
        packet.data[4] = functionNum;
        packet.data[5] = 247;

        emit signalSendMidiPacketList(port, packet);
    }
}

void MidiFormatOutput::slotAftertouch(QString port, int channel, int val)
{
    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 2;
    packet.data[0] = 207 + channel;
    packet.data[1] = val;

    emit signalSendMidiPacketList(port, packet);
}

void MidiFormatOutput::slotPolyAftertouch(QString port, int channel, int note, int val)
{
    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 3;
    packet.data[0] = 159 + channel;
    packet.data[1] = note;
    packet.data[2] = val;

    emit signalSendMidiPacketList(port, packet);
}
