// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "midiinput.h"

MidiInput::MidiInput(QWidget *parent) :
    QWidget(parent)
{
}

void MidiInput::slotReceiveInput(int status, int firstByte, int secondByte, int chan, QString deviceName)
{
    Q_UNUSED(chan);

//    int status = packet->data[0];
//    int firstByte = packet->data[1];
//    int secondByte = packet->data[2];
    //qDebug() << packet->data[0];

    //If modline is on...
    if(enable && device == deviceName)
    {
        //And type is...
        if(type.contains("CC"))
        {
            //Then channel must be...
            if(channel == (status - 175)) //Offset status byte to match channels
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
        else if(type.contains("Note"))
        {
            //Note offs
            if(status >= 128 && status <= 143)
            {
                //Then channel must be...
                if(channel == (status - 127)) //Offset status byte to match channels
                {
                    //And number must be...
                    if(number == firstByte)
                    {
                        //Meets qualifications, so send it to be cooked.
                        emit signalSendInputToModlines(secondByte, instance);
                    }
                }
            }

            //Note Ons
            else if(status >= 144 && status <= 159)
            {
                //Then channel must be...
                if(channel == (status - 143)) //Offset status byte to match channels
                {
                    //And number must be...
                    if(number == firstByte)
                    {
                        //Meets qualifications, so send it to be cooked.
                        emit signalSendInputToModlines(secondByte, instance);
                    }
                }
            }

        }

        //And type is...
        else if(type.contains("Program Change"))
        {
            //Program changes
            if(status >= 192 && status <= 207)
            {
                //Then channel must be...
                if(channel == (status - 191)) //Offset status byte to match channels
                {
                    //Meets qualifications, so send it to be cooked.
                    emit signalSendInputToModlines(firstByte, instance);
                }
            }
        }
    }
}
