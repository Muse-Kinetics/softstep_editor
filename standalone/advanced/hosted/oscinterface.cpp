// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "oscinterface.h"

OscInterface::OscInterface(QObject *parent) :
    QObject(parent)
{

    //----- Init
    //Inputs
    for(int i = 0; i < 8; i++)
    {
        oscInput[i].enabled = false;
        oscInput[i].addressTag = "";
        oscInput[i].inputVal = 0;
    }

    //Ports
    inputPort = 7755;
    outputPort = 7788;

    //IP
    ip = "127.0.0.1";

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress(ip), inputPort);

    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadPendingDatagrams()));

    msgVal[0] = 0;
    msgVal[1] = 0;
    msgVal[2] = 0;
    msgVal[3] = 0;

    //slotWriteDatagram("", 0);

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
                    if(msgType != "i" && msgType != "f")
                    {
                        //qDebug() << "msg type" << msgType;
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
                if(datagram.at(i) != NULL && datagram.at(i) != ',')
                {
                    msgAddress.append(datagram.at(i));
                }
                else
                {
                    break;
                }
            }

            //qDebug() << "msgAddress" << msgAddress;
        }

        //----------------------------------------------------------- Get value

        //Must have type id (of i or f, defined above)
        if(msgType != "")
        {
            //Get 4 bytes of 32 bit data
            for(int i = 0; i < 4; i++)
            {
                //qDebug() << i << (int)datagram.at(datagram.size() - 1 - i);
                msgVal[i] = (unsigned char)datagram.at(datagram.size() - 1 - i);
            }


            //Process int
            if(msgType == "i")
            {
                int intVal = 0;
                intVal = (intVal << 8) + msgVal[3];
                intVal = (intVal << 8) + msgVal[2];
                intVal = (intVal << 8) + msgVal[1];
                intVal = (intVal << 8) + msgVal[0];

                //qDebug() << "(int) msgVal" << intVal;

                slotDistributeReceivedMessage(msgAddress, intVal);
            }
            else if(msgType == "f")
            {
                float floatVal = 0.0f;
                uchar b[] = {msgVal[0], msgVal[1], msgVal[2], msgVal[3]};
                memcpy(&floatVal, &b, sizeof(floatVal));

                //qDebug() << "(float) msgVal" << floatVal;

                slotDistributeReceivedMessage(msgAddress, (int)floatVal);
            }
            else
            {
                //ERROR
                qDebug() << "ERROR: Unrecognized OSC message type ID.";
            }
        }
    }
}

void OscInterface::slotSetInputEnable(int inputNum, bool enabled)
{
    //qDebug() << "set enabled" << inputNum << enabled;
    oscInput[inputNum].enabled = enabled;
}

void OscInterface::slotSetOSCAddressTags(int inputNum, QString tag)
{
    //qDebug() << "set address tag" << inputNum << tag;
    oscInput[inputNum].addressTag = tag;
}

void OscInterface::slotSetOutputPort(int port)
{
    outputPort = port;
}

void OscInterface::slotSetInputPort(int port)
{
    socket->close();
    //qDebug() << "port changed" << port;
    inputPort = port;
    socket->bind(QHostAddress(ip), inputPort);
}

void OscInterface::slotSetOutputIPAddress(QString ipString)
{
    ip = ipString;
}

void OscInterface::slotWriteDatagram(QString tag, int val)
{
    QByteArray data;
    //char byte[12] = {0x2F, 0x30, 0x00, 0x00, 0x2C, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};

    QByteArray address;
    address.append(tag);

    //---- Format Address
    //Must have address with size greater than 0
    if(address.size())
    {
        //Add Adress to udp packet
        data.append(address);

        //qDebug() << "address size" << address.size() << address.size()%4;
        //If adress size is not multiple of 4
        if(address.size()%4)
        {
            //Add empty bytes to make sure it's a multiple of 4
            for(int i = 0; i < 4 - address.size()%4; i++)
            {
                //qDebug() << "adding bytes" << i;
                data.append('\0');
            }
        }

        //If address size is exactly a multiple of 0, add four null byte buffer
        else
        {
            data.append('\0');
            data.append('\0');
            data.append('\0');
            data.append('\0');
        }
    }

    //If no address, make default /softstep
    else
    {
        address = "/softstep";

        //Add Adress to udp packet
        data.append(address);
        data.append('\0');
        data.append('\0');
        data.append('\0');
    }

    //qDebug() << "address - data.size" << data.size();

    //---- Format Type Tag, which will always be the same
    data.append(',');
    data.append('i');
    data.append('\0');
    data.append('\0');

    //qDebug() << "type tag - data.size" << data.size();

    //---- Format value
    char intBytes[4];

    intBytes[0] = (val >> 24) & 0xFF;
    intBytes[1] = (val >> 16) & 0xFF;
    intBytes[2] = (val >> 8) & 0xFF;
    intBytes[3] = val & 0xFF;

    data.append(intBytes[0]);
    data.append(intBytes[1]);
    data.append(intBytes[2]);
    data.append(intBytes[3]);

    //qDebug() << "val - data.size" << data.size();

    /*
    for(int i = 0; i < data.size(); i++)
    {
        qDebug() << "data i: " << i << data.at(i);
    }
    */

    socket->writeDatagram(data, data.size(), QHostAddress(ip), outputPort);
}

void OscInterface::slotDistributeReceivedMessage(QString tag, int val)
{
    //Iterate through sources
    for(int i = 0; i < 8; i++)
    {
        //If one of our inputs has a corresponding tag, and that input is enabled
        if(oscInput[i].addressTag == tag && oscInput[i].enabled)
        {
            //qDebug() << "output " << i << tag << val;

            emit signalSetOSCDisplayValue(i, val);

            //Emit that value to be used as an OSC source in the modlines
            emit signalSendOscMessageToSource(i, val);
        }
    }
}
