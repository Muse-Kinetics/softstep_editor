// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "pedal.h"

Pedal::Pedal(QWidget *parent) :
    QWidget(parent)
{

    pixmap.load(QString::fromUtf8("resources/pedal_top.png"));

    QPainter painter(&pixmap);
    painter.rotate(90);
    painter.translate(22, 66);

    //Initialize bucket for windowing average
    pedalBucket.append(0);
    pedalBucket.append(0);
    pedalBucket.append(0);

    //Load pedal table file
    QFile *pedalTableFile = new QFile("resources/pedalTable.txt");

    //Open pedal table
    if(pedalTableFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //qDebug("Pedal Table Found");

        QByteArray pedalTableByteArray = pedalTableFile->readAll();

        for(int i = 0; i< pedalTableByteArray.size(); i++)
        {
            pedalValueList.append((unsigned char)pedalTableByteArray.at(i));
        }
    }
    else
    {
        qDebug() << "!!!!!!!!!!!!!!!!!!!! Pedal Table File Not Found -- ON READ. !!!!!!!!!!!!!!!!!!!!";
    }

    pedalTableFile->close();

    calibrating = false;
    pedalSampleCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////// MIDI ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Pedal::slotWindowInput(int pedalInput)
{
    //If not currently calibrating, go through windowing routine
    if(!calibrating)
    {
        pedalBucket.prepend(pedalInput);
        pedalBucket.removeLast();

        //Inc sample count
        pedalSampleCount++;

        //If third sample in cycles of three
        if(pedalSampleCount == 3)
        {
            //Reset sample count
            pedalSampleCount = 0;

            //Take new averages

        }


        //Average last three values
        int pedalAverage = (pedalBucket.at(0) + pedalBucket.at(1) + pedalBucket.at(2))/3;

        qDebug() << "pedal bucket" << pedalBucket << pedalAverage;

        //If incoming value differs from running average by 3 or more, either negatively or positively
        if( (pedalInput > (pedalAverage + 2)) || (pedalInput < (pedalAverage - 2)) )
        {
            //Return value
            return pedalInput;
        }

        //If pedal does not exceed window
        else
        {
            //Return invalid
            return -1;
        }
    }

    //If calibrating
    else
    {
        //Return invalid
        return -1;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////// Calibration /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------- Graphics
void Pedal::slotSetLeverPointer(QLabel *lever)
{
    pedallever = lever;
    pedallever->setPixmap(pixmap);
    //pedallever->setText("Chomsky");
    pedallever->show();
}

void Pedal::slotRotateLever(int degrees)
{

}

//---------------------------------------------------------------- Calibration Steps
//Start
void Pedal::slotStartCalibrate()
{
    calibrating = true;
    pedalValueList.clear();
}

//Calibrate
void Pedal::slotCalibrate(int pedalInput)
{
    //Calibration consists of collecting a dataset, finalized in slotStopCalibrate()

    //If value is not in our list of values
    if(!pedalValueList.contains(pedalInput))
    {
        //Add it to the list
        pedalValueList.append(pedalInput);
    }
}

//Stop
void Pedal::slotStopCalibrate()
{
    //Order our list
    for(int i = 1; i < pedalValueList.size(); i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(pedalValueList.at(i) < pedalValueList.at(j))
            {
                pedalValueList.swap(i, j);
            }
        }
    }

    //Write file
    slotWritePedalTableFile();
}

//Reset
void Pedal::slotResetCalibrate()
{
    //Clear whatever table we have
    pedalValueList.clear();

    //Write a linear 7-bit table (0 - 127)
    for(int i = 0; i < 128; i++)
    {
        pedalValueList.append(i);
    }

    //Write the new table
    slotWritePedalTableFile();
}

//Write
void Pedal::slotWritePedalTableFile()
{
    //Set min, max, length for this app session
    pedalValueListMin = pedalValueList.first();
    pedalValueListMax = pedalValueList.last();
    pedalValueListLength = pedalValueList.size();

    //Load Pedal file
    QFile *pedalTableFile = new QFile("resources/pedalTable.txt");

    //Open Pedal File
    if(pedalTableFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //Clear file
        pedalTableFile->resize(0);

        //New byte array to store values and write to file
        QByteArray byteArray;

        //Iterate through current table list
        for(int i = 0; i < pedalValueList.size(); i++)
        {
            //Add table list values to byte array
            byteArray.append((unsigned char)pedalValueList.at(i));
        }

        //Write byte array to file
        pedalTableFile->write(byteArray);
    }
    else
    {
        qDebug() << "!!!!!!!!!!!!!!!!!!!! Pedal Table File Not Found -- ON WRITE. !!!!!!!!!!!!!!!!!!!!";
    }

    pedalTableFile->close();

    calibrating = false;
}
