// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "midiformatoutput.h"
#include "midi_ss.h"

MidiFormatOutput::MidiFormatOutput(QWidget *parent) :
    QWidget(parent)
{
}

void MidiFormatOutput::slotPreparePacket()
{

}

// ****************************************************************
// NOTE - channels sent to these functions are not zero indexed
// ****************************************************************

//------------------------------------- Formatting
void MidiFormatOutput::slotNoteSet(QString port, int channel, int note, int velocity)
{
    //qDebug() << "slotNoteSet";
    unsigned char status;

    if(velocity)
    {
        status = MIDI_NOTE_ON;

    }
    else
    {
        status = MIDI_NOTE_OFF;
    }

    emit signalSendMidiPacketList(port, status, note, velocity, channel - 1);
}

void MidiFormatOutput::slotNoteLive(QString port, int channel, int oldNote, int newNote, int velocity)
{
    qDebug() << "slotNoteLive";
    MIDIPacket packet;

    packet.timeStamp = 0;
    packet.length = 3;

    //If there is an old note
    if(oldNote != -1)
    {
        //Old note

        emit signalSendMidiPacketList(port, MIDI_NOTE_OFF + channel, oldNote, 0, channel - 1);
    }
    if (newNote == -1)
        return; // we've turned off the last note, now return

    //New Note

    emit signalSendMidiPacketList(port, MIDI_NOTE_ON, newNote, velocity, channel - 1);
}

void MidiFormatOutput::slotCC(QString port, int channel, int ccNum, int ccVal)
{
    qDebug() << "slotCC called" << ccVal;
//    MIDIPacket packet;
    unsigned char status = MIDI_CONTROL_CHANGE;

    emit signalSendMidiPacketList(port, status, ccNum, ccVal, channel - 1);
}

void MidiFormatOutput::slotBank(QString port, int channel, int msb, int lsb)
{
    qDebug() << "slotBank";
    //MIDIPacket packet;
    unsigned char status = MIDI_CONTROL_CHANGE;

    emit signalSendMidiPacketList(port, status, 0, msb, channel - 1);
    emit signalSendMidiPacketList(port, status, 32, lsb, channel - 1);
}

void MidiFormatOutput::slotProgram(QString port, int channel, int program)
{
    //qDebug() << "slotProgram";
    uchar status = MIDI_PROG_CHANGE;

    emit signalSendMidiPacketList(port, status, program, 0, channel - 1);
}

void MidiFormatOutput::slotPitchBend(QString port, int channel, int lsb, int msb)
{
    uchar status = MIDI_PITCH_BEND;

    emit signalSendMidiPacketList(port, status, lsb, msb, channel - 1);
}

void MidiFormatOutput::slotMMC(QString port, int id, QString function)
{
    QByteArray packet;

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
        unsigned char thisPacket[] =
        {
            MIDI_SX_START,
            127,
            (uchar)id,
            6,
            (uchar)functionNum,
            MIDI_SX_STOP
        };


        packet = QByteArray(reinterpret_cast<char*>(thisPacket), sizeof(thisPacket));

        emit signalSendMidiPacketArray(port, packet);
    }
}

void MidiFormatOutput::slotAftertouch(QString port, int channel, int val)
{
    uchar status = MIDI_CHANNEL_PRESSURE;

    emit signalSendMidiPacketList(port, status, val, 0, channel - 1);
}

void MidiFormatOutput::slotPolyAftertouch(QString port, int channel, int note, int val)
{
    uchar status = MIDI_NOTE_AFTERTOUCH;

    emit signalSendMidiPacketList(port, status, note, val, channel - 1);
}
