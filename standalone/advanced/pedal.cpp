// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "pedal.h"

// pedal.cpp - instantiated in every key[x] object, but only key[0].datacooker.pedal is ever used. Mostly for calibration.

Pedal::Pedal(QWidget *parent, int keyInstance) :
    QWidget(parent),
    parentKeyInstance(keyInstance)
{
    //Initialize bucket for windowing average
    pedalBucket.append(0);
    pedalBucket.append(0);
    pedalBucket.append(0);

    pedalAverage = 0;
    calibrating = false;
    pedalSampleCount = 0;

    //calibratingBlinkCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////// Input ///////////////////////////////////////////////////////////////////
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
           // qDebug() << "----------------------- take new average";

            //Reset sample count
            pedalSampleCount = 0;

            //Take new average
            pedalAverage = (pedalBucket.at(0) + pedalBucket.at(1) + pedalBucket.at(2))/3;
        }

        //qDebug() << "pedal bucket" << pedalBucket << pedalAverage;

        //If incoming value differs from running average by 3 or more, either negatively or positively
        if( (pedalInput > (pedalAverage + 2)) || (pedalInput < (pedalAverage - 2)) )
        {
            //Return value
            return slotTableInput(pedalInput);
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
        slotCalibrate(pedalInput);
        slotSetLivePedalValue(pedalInput);

        //Return invalid
        return -1;
    }
}

int Pedal::slotTableInput(int pedalInput)
{
    //qDebug() << "tabling pedal input" << pedalInput;

    //Scale: [min + 4 to max - 4] --> [0 to 127]
    int inLow = pedalValueList.length() ? pedalValueListMin + 4 : 0;
    int inHigh = pedalValueList.length() ? pedalValueListMax - 4 : 127;

    int outLow = 0;
    int outHigh = 127;

    int output = (pedalInput - inLow) * (outHigh - outLow) / (inHigh - inLow) + outLow; // scaling based on calibration...

    if(output < outLow)
    {
        output = outLow;
    }

    if(output > outHigh)
    {
        output = outHigh;
    }

    //Invert table
    output = 127 - output;

    //qDebug() << "pedal output" << output << pedalInput;
    slotSetLivePedalValue(output);

    return output;

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

void Pedal::slotSetLivePedalValue(int val)
{
    qDebug() << "live value" << val;
    //testValueSlider->setValue(val);
    emit signalLivePedalVal(val);
}

//---------------------------------------------------------------- Calibration Steps
//Start
void Pedal::slotStartCalibrate()
{
    qDebug() << "start calibration";

    calibrating = true;
    pedalValueList.clear();
}

//Calibrate
void Pedal::slotCalibrate(int pedalInput)
{
    //Calibration consists of collecting a dataset, finalized in slotStopCalibrate()
    //qDebug() << "slot calibrate this input" << pedalInput;

    //If value is not in our list of values
    if(!pedalValueList.contains(pedalInput))
    {
        //Add it to the list
        pedalValueList.append(pedalInput);
    }

    if(pedalValueList.length())
    {
        //qDebug() << "emit table";
        emit signalDrawTable(pedalValueList);
    }

}

//Stop
void Pedal::slotStopCalibrate() // 2nd
{
    int count = pedalValueList.count();

    //Require at least 4 values, if under set to default
    if(count < 3)
    {

        if(parentKeyInstance == 0)
        {
            slotResetCalibrate();
            emit signalResetOnZeroInput();
        }

    }
    else
    {
        //Order our list
        for(int i = 1; i < count; i++)
        {
            int j = i;
            int t;

            while(j > 0 && pedalValueList.at(j) < pedalValueList.at(j - 1))
            {
                t = pedalValueList.at(j);

                pedalValueList.replace(j, pedalValueList.at(j - 1));

                pedalValueList.replace(j - 1, t);

                j--;
            }
        }

        qDebug() << pedalValueList;

        //Write file
        slotSetMinMaxLength();
        slotWritePedalTableFile();

    }

    calibrating = false;
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
    slotSetMinMaxLength();
    slotWritePedalTableFile();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////// Read/Write/Init ////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Init
void Pedal::slotInitPedalTable(QByteArray table)
{
    pedalValueList.clear();

    for(int i = 0; i< table.size(); i++)
    {
        pedalValueList.append((unsigned char)table.at(i));
    }

    int count = pedalValueList.count();

    //Order our list
    for(int i = 1; i < count; i++)
    {
        int j = i;
        int t;

        while(j > 0 && pedalValueList.at(j) < pedalValueList.at(j - 1))
        {
            t = pedalValueList.at(j);

            pedalValueList.replace(j, pedalValueList.at(j - 1));

            pedalValueList.replace(j - 1, t);

            j--;
        }
    }

    slotSetMinMaxLength();
}


//Write
void Pedal::slotWritePedalTableFile()
{
    //Only write using key 0, no need for writing across all instances (architecture here could be smarter)
    if(parentKeyInstance == 0)
    {
        //New byte array to store values and write to file
        QByteArray byteArray;

        //If there something in table, write its contents
        if(pedalValueList.size())
        {
            //Iterate through current table list
            for(int i = 0; i < pedalValueList.size(); i++)
            {
                //Add table list values to byte array
                byteArray.append((unsigned char)pedalValueList.at(i));
            }
        }

        //Otherwise store default
        else
        {
            //Iterate through current table list
            for(int i = 0; i < 128; i++)
            {
                //Add table list values to byte array
                byteArray.append((unsigned char)i);
            }
        }

        //Send byte array to be written in settings class
        emit signalWriteTableToDisk(byteArray);
    }
}

void Pedal::slotSetMinMaxLength()
{
    //Set min, max, length for this app session
    pedalValueListMin = (int)pedalValueList.first();
    pedalValueListMax = (int)pedalValueList.last();
    pedalValueListLength = (int)pedalValueList.size();

    //qDebug() << "min, max, lengh" << pedalValueListMin << pedalValueListMax << pedalValueListLength;
}
