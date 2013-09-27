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

            value = modlineForm.destination->currentText();
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

void Modline::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    //basic modline parameters
    modlineForm.enable->setChecked(preset.value(QString("key%1_modline%2_enable").arg(keyInstance+1).arg(modlineInstance+1)).toBool());
    modlineForm.initValue->setValue(preset.value(QString("key%1_modline%2_initValue").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.initMode->setCurrentIndex(modlineForm.initMode->findText(preset.value(QString("key%1_modline%2_initMode").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.source->setCurrentIndex(modlineForm.source->findText(preset.value(QString("key%1_modline%2_source").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.gain->setValue(preset.value(QString("key%1_modline%2_gain").arg(keyInstance+1).arg(modlineInstance+1)).toDouble());
    modlineForm.offset->setValue(preset.value(QString("key%1_modline%2_offset").arg(keyInstance+1).arg(modlineInstance+1)).toDouble());
    modlineForm.table->setCurrentIndex(modlineForm.table->findText(preset.value(QString("key%1_modline%2_table").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.min->setValue(preset.value(QString("key%1_modline%2_min").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.max->setValue(preset.value(QString("key%1_modline%2_max").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.slew->setValue(preset.value(QString("key%1_modline%2_slew").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.destination->setCurrentIndex(modlineForm.destination->findText(preset.value(QString("key%1_modline%2_destination").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    //LED parameters
    modlineForm.ledgreen->setCurrentIndex(modlineForm.ledgreen->findText(preset.value(QString("key%1_modline%2_ledgreen").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.ledred->setCurrentIndex(modlineForm.ledred->findText(preset.value(QString("key%1_modline%2_ledred").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    /*
    //destination parameters
    modlineForm.noteNumber->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.noteLiveNumber->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.noteNumber->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

    modlineForm.noteVelocity->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.noteLiveVelocity->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.cc->setValue(preset.value(QString("key%1_modline%2_cc").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.bankMSB->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.polyNote->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

    modlineForm.noteChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.noteLiveChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.controlChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.bankChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.programChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.bendChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.aftertouchChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.polyChannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

    modlineForm.noteDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.noteLiveDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.controlDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.bankDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.programDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.bendDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.aftertouchDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.polyDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    modlineForm.mmcDeviceId->setValue(preset.value(QString("key%1_modline%2_mmcid").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm.mmcFunction->setCurrentIndex(modlineForm.mmcFunction->findText(preset.value(QString("key%1_modline%2_mmcfunction").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm.mmcDevice->setCurrentIndex(modlineForm.noteDevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    modlineForm.oscRoute->setText(preset.value(QString("key%1_modline%2_oscroute").arg(keyInstance+1).arg(modlineInstance+1)).toString());
    */
}
