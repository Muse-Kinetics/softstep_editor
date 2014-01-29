// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "oscinterface.h"

OscInterface::OscInterface(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 7755);

    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadPendingDatagrams()));
}


void OscInterface::slotReadPendingDatagrams()
{
    while (socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        //qDebug() << "osc packet size ---- " << datagram.size() << datagram.data();


        for(int i = 0; i < datagram.size(); i++)
        {
            /*if(datagram.at(i) == NULL)
            {
                qDebug() << i;
            }
            else
            {
                qDebug() << "i" << i << "osc scomething happening." << datagram.at(i) << "--------" << (int)datagram.at(i);
            }*/

            //qDebug() << "i" << i << "osc scomething happening." << datagram.at(i) << "--------" << (int32_t)datagram.at(i);

        }

        //----------------------------------------------------------- Get Type Tag
        for(int i = 0; i < datagram.size(); i++)
        {
            //Check for type tag
            if(datagram.contains(','))
            {
                //If contains a type tag
                if( (datagram.at(i) == ',') && (datagram.size() > (i+1)) )
                {
                    //Get the type id
                    msgType = datagram.at(i+1);

                    //If an int or float
                    if(msgType == "i" || msgType == "f")
                    {
                        qDebug() << "msg type" << msgType;
                    }

                    //Else set to empty
                    else
                    {
                        msgType = "";
                    }
                }
            }

            //If no type tag set to empty string
            else
            {
                msgType = "";
            }
        }

        //----------------------------------------------------------- Get address tag

        msgAddress = "";

        //Must have type id (of i or f, defined above)
        if(msgType != "")
        {
            //Start from beginning of datagram
            for(int i = 0; i < datagram.size(); i++)
            {
                //Scrool up to a null or , (type tag)
                if(datagram.at(i) != NULL || datagram.at(i) != ',')
                {
                    msgAddress.append(datagram.at(i));
                }
                else
                {
                    break;
                }
            }
        }

        //----------------------------------------------------------- Get value

        //Must have type id (of i or f, defined above)
        if(msgType != "")
        {
            bool ok;

            msgVal.clear();

            //Get 4 bytes of 32 bit data
            for(int i = datagram.size() - 4; i < datagram.size(); i++)
            {
                qDebug() << i << (int)datagram.at(i);
                msgVal.append(datagram.at(i));
            }

            qDebug() << "(int) msgVal" << msgVal.toInt(&ok, 10) << "size" << msgVal.size();
            qDebug() << "(float) msgVal" << msgVal.toFloat();

            //Process int
            if(msgType == "i")
            {

            }
            else if(msgType == "f")
            {

            }
            else
            {
                //ERROR
                qDebug() << "ERROR: Unrecognized OSC message type ID.";
            }
        }
        else
        {

        }


    }
}
