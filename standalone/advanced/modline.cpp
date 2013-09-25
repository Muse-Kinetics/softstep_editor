// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "modline.h"
//#include "ui_keyWindowForm.h"

Modline::Modline(QWidget *parent, int keyInstanceNum, int modlineInstanceNum) :
    QWidget(parent)
{
    keyInstance = keyInstanceNum;
    modlineInstance = modlineInstanceNum;

    this->setObjectName(QString("%1_Key_%2_Modline").arg(keyInstance+1).arg(modlineInstance+1));

    //---------------------------------------- Set Up Ui
    QWidget *formWidget = new QWidget(this);

    modlineForm.setupUi(formWidget);
    this->setFixedSize(1000,40);

    modlineForm.instanceLabel->setText(QString("%1").arg((modlineInstance + 1)%10));
    modlineForm.deviceViews->setCurrentIndex(0);
    modlineForm.deviceViewLabels->setCurrentIndex(0);

    this->setGeometry(10,35 + ((modlineInstance)*42),1000,40);
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
    connect(modlineForm.ledgreen,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //red LED
    connect(modlineForm.ledred,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
}

void Modline::slotValueChanged()
{    
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();
        QVariant value;

        //enable checkbox
        if(sender == modlineForm.enable)
        {
            value = modlineForm.enable->isChecked();
        }

        //initMode
        else if(sender == modlineForm.initMode)
        {
            value = modlineForm.initMode->currentText();
        }

        //initValue
        else if(sender == modlineForm.initValue)
        {
            value = modlineForm.initValue->value();
        }

        //Source Menu
        else if(sender == modlineForm.source)
        {
            value = modlineForm.source->currentText();
        }

        //Gain
        else if(sender == modlineForm.gain)
        {
            value = modlineForm.gain->value();
        }

        //Offset
        else if(sender == modlineForm.offset)
        {
            value = modlineForm.offset->value();
        }

        //Table Menu
        else if(sender == modlineForm.table)
        {
            value = modlineForm.table->currentText();
        }

        //Min
        else if(sender == modlineForm.min)
        {
            value = modlineForm.min->value();
        }

        //Max
        else if(sender == modlineForm.max)
        {
            value = modlineForm.max->value();
        }

        //slew
        else if(sender == modlineForm.slew)
        {
            value = modlineForm.slew->value();
        }

        //Destination Menu
        else if(sender == modlineForm.destination)
        {
            //set the device view to change based on what is selected in the destination menu
            if((modlineForm.destination->currentIndex()) > 10)
            {
                modlineForm.deviceViews->setCurrentIndex(0);
                modlineForm.deviceViewLabels->setCurrentIndex(0);
            }
            else
            {
                modlineForm.deviceViews->setCurrentIndex(modlineForm.destination->currentIndex());
                modlineForm.deviceViewLabels->setCurrentIndex(modlineForm.destination->currentIndex());
            }
        }

        //Green LED
        else if(sender == modlineForm.ledgreen)
        {
            value = modlineForm.ledgreen->currentText();
        }

        //Red LED
        else if(sender == modlineForm.ledred)
        {
            value = modlineForm.ledred->currentText();
        }

        emit signalStoreValue(QString("key%1_modline%2_").arg(keyInstance+1).arg(modlineInstance+1) + sender->objectName(), value, -1);
    }
}

void Modline::slotRecallPreset(QVariantMap, QVariantMap)
{

}
