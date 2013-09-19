// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "modline.h"

Modline::Modline(QWidget *parent, int keyInstanceNum, int modlineInstanceNum) :
    QWidget(parent)
{
    keyInstance = keyInstanceNum;
    modlineInstance = modlineInstanceNum;

    this->setObjectName(QString("%1_Key_%2_Modline").arg(keyInstance+1).arg(modlineInstance+1));

    //---------------------------------------- Set Up Ui
    QWidget *formWidget = new QWidget(this);

    modlineForm.setupUi(formWidget);
    this->setFixedSize(1000,30);

    modlineForm.instanceLabel->setText(QString("%1").arg((modlineInstance + 1)%10));

    this->setGeometry(10,35 + ((modlineInstance)*31),1000,30);
}

void Modline::slotConnectElements()
{
    //enable checkbox
    connect(modlineForm.enable,SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //init mode
    connect(modlineForm.initMode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //init value
    connect(modlineForm.initValue,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //source
    connect(modlineForm.source,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //raw value (not for preset)
    connect(modlineForm.raw,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //gain
    connect(modlineForm.gain,SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));

    //offset
    connect(modlineForm.offset,SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));

    //table menu
    connect(modlineForm.table,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //min
    connect(modlineForm.min,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //max
    connect(modlineForm.max,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //slew
    connect(modlineForm.slew,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //parameter destination menu
    connect(modlineForm.destination,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //green LED
    connect(modlineForm.greenLED,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //red LED
    connect(modlineForm.redLED,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
}

void Modline::slotValueChanged()
{    
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        //enable checkbox
        if(sender == modlineForm.enable)
        {
            qDebug() << QString("Pad %1 Modline %2 Enable [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.enable->isChecked());
        }

        //initMode
        else if(sender == modlineForm.initMode)
        {
            qDebug() << QString("Pad %1 Modline %2 Init Mode [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.initMode->currentText());
        }

        //initValue
        else if(sender == modlineForm.initValue)
        {
            qDebug() << QString("Pad %1 Modline %2 Init Value [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.initValue->value());
        }

        //Source Menu
        else if(sender == modlineForm.source)
        {
            qDebug() << QString("Pad %1 Modline %2 Source [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.source->currentText());
        }

        //Gain
        else if(sender == modlineForm.gain)
        {
            qDebug() << QString("Pad %1 Modline %2 Gain [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.gain->value());
        }

        //Offset
        else if(sender == modlineForm.offset)
        {
            qDebug() << QString("Pad %1 Modline%2 Offset [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.offset->value());
        }

        //Table Menu
        else if(sender == modlineForm.table)
        {
            qDebug() << QString("Pad %1 Modline %2 Table [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.table->currentText());
        }

        //Min
        else if(sender == modlineForm.min)
        {
            qDebug() << QString("Pad %1 Modline %2 Min [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.min->value());
        }

        //Max
        else if(sender == modlineForm.max)
        {
            qDebug() << QString("Pad %1 Modline %2 Max [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.max->value());
        }

        //slew
        else if(sender == modlineForm.slew)
        {
            qDebug() << QString("Pad %1 Modline %2 Slew [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.slew->value());
        }

        //Destination Menu
        else if(sender == modlineForm.destination)
        {
            qDebug() << QString("Pad %1 Modline %2 Source [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.destination->currentText());
        }

        //Green LED
        else if(sender == modlineForm.destination)
        {
            qDebug() << QString("Pad %1 Modline %2 Source [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.greenLED->currentText());
        }

        //Red LED
        else if(sender == modlineForm.destination)
        {
            qDebug() << QString("Pad %1 Modline %2 Source [%3]").arg(keyInstance+1).arg(modlineInstance+1).arg(modlineForm.redLED->currentText());
        }

    }
    //emit signalStoreValue(QString("%1_modline_gain").arg(instance), modlineForm.gain->value(), -1);
}
