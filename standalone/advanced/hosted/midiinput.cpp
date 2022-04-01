// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "midiinput.h"
#include "midi.h"

MidiInput::MidiInput(QWidget *parent) :
    QWidget(parent)
{
}

void MidiInput::slotReceiveInput(int status, int firstByte, int secondByte, int chan, QString deviceName)
{

    //qDebug() << "slotReceiveInput - device: " << deviceName << " s: " << status << " b1: " << firstByte << " b2: " << secondByte << " chan: " << chan;

    //If modline is on...
    if(enable && device == deviceName)
    {
        //qDebug() << "enable/device match - type: " << type << " status: " << status << " channel: " << channel << " number: " << number;
        //And type is...
        if(type.contains("CC") && status == MIDI_CONTROL_CHANGE)
        {
            //Then channel must be...
            if(channel - 1 == chan) //Offset status byte to match channels
            {
                //And number must be...
                if(number == firstByte)
                {
                    //Meets qualifications, so send it to be cooked.
                    emit signalSendInputToModlines(secondByte, instance);
                }
            }
        }

        //And type is...
        else if(type.contains("Note") &&
                (status == MIDI_NOTE_OFF || status == MIDI_NOTE_ON) )
        {

            //Then channel must be...
            if(channel - 1 == chan) //Offset status byte to match channels
            {
                //And number must be...
                if(number == firstByte)
                {
                    //Meets qualifications, so send it to be cooked.
                    emit signalSendInputToModlines(secondByte, instance);
                }
            }
        }

        //And type is...
        else if(type.contains("Program Change") && status == MIDI_PROG_CHANGE)
        {
            //Then channel must be...
            if(channel - 1 == chan) //Offset status byte to match channels
            {
                //Meets qualifications, so send it to be cooked.
                emit signalSendInputToModlines(firstByte, instance);
            }
        }
    }
}
