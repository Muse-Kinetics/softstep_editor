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

// ****************************************************************
// NOTE - channels sent to these functions are not zero indexed
// ****************************************************************

//------------------------------------- Formatting
void MidiFormatOutput::slotNoteSet(QString port, int channel, int note, int velocity)
{
    qDebug() << "slotNoteSet";
    unsigned char status;
//    MIDIPacket packet;

//    packet.timeStamp = 0;
//    packet.length = 3;

    if(velocity)
    {
        //Note On
//        packet.data[0] = 143 + channel;
        status = 144;

    }
    else
    {
        //Note Off
//        packet.data[0] = 127 + channel;
        status = 128;
    }

//    packet.data[1] = note;
//    packet.data[2] = velocity;

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
//        packet.data[0] = 127 + channel;
//        packet.data[1] = oldNote;
//        packet.data[2] = 0;

        emit signalSendMidiPacketList(port, 128, oldNote, 0, channel - 1);
    }

    //New Note
//    packet.data[0] = 143 + channel;
//    packet.data[1] = newNote;
//    packet.data[2] = velocity;

    emit signalSendMidiPacketList(port, 144, newNote, velocity, channel - 1);
}

void MidiFormatOutput::slotCC(QString port, int channel, int ccNum, int ccVal)
{
    qDebug() << "slotCC called" << ccVal;
//    MIDIPacket packet;
    unsigned char status = 176;

    //Byte packetData[3] = {176, ccNum, ccVal};

//    packet.timeStamp = 0;
//    packet.length = 3;
//    packet.data[0] = 175 + channel;
//    packet.data[1] = ccNum;
//    packet.data[2] = ccVal;

    emit signalSendMidiPacketList(port, status, ccNum, ccVal, channel - 1);
}

void MidiFormatOutput::slotBank(QString port, int channel, int msb, int lsb)
{
    qDebug() << "slotBank";
    //MIDIPacket packet;
    unsigned char status = 176;

    //Byte packetData[3] = {176, ccNum, ccVal};

//    packet.timeStamp = 0;
//    packet.length = 6;
//    packet.data[0] = 175 + channel;
//    packet.data[1] = 0;
//    packet.data[2] = msb;
//    packet.data[3] = 175 + channel;
//    packet.data[4] = 32;
//    packet.data[5] = lsb;

    emit signalSendMidiPacketList(port, status, 0, msb, channel - 1);
    emit signalSendMidiPacketList(port, status, 32, lsb, channel - 1);
}

void MidiFormatOutput::slotProgram(QString port, int channel, int program)
{
    qDebug() << "slotProgram";
    uchar status = 192;
//    MIDIPacket packet;

//    packet.timeStamp = 0;
//    packet.length = 2;
//    packet.data[0] = 191 + channel;
//    packet.data[1] = program;

    emit signalSendMidiPacketList(port, status, program, 0, channel - 1);
}

void MidiFormatOutput::slotPitchBend(QString port, int channel, int lsb, int msb)
{
    uchar status = 224;
//    MIDIPacket packet;

//    packet.timeStamp = 0;
//    packet.length = 3;
//    packet.data[0] = 223 + channel;
//    packet.data[1] = lsb;
//    packet.data[2] = msb;

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
            240,
            127,
            (uchar)id,
            6,
            (uchar)functionNum,
            247
        };


        packet = QByteArray(reinterpret_cast<char*>(thisPacket), sizeof(thisPacket));

        emit signalSendMidiPacketArray(port, packet);
    }
}

void MidiFormatOutput::slotAftertouch(QString port, int channel, int val)
{
    uchar status = 208;
//    //MIDIPacket packet;

//    packet.timeStamp = 0;
//    packet.length = 2;
//    packet.data[0] = 207 + channel;
//    packet.data[1] = val;

    emit signalSendMidiPacketList(port, status, val, 0, channel - 1);
}

void MidiFormatOutput::slotPolyAftertouch(QString port, int channel, int note, int val)
{
    uchar status = 160;
//    //MIDIPacket packet;

//    packet.timeStamp = 0;
//    packet.length = 3;
//    packet.data[0] = 159 + channel;
//    packet.data[1] = note;
//    packet.data[2] = val;

    emit signalSendMidiPacketList(port, status, note, val, channel - 1);
}
