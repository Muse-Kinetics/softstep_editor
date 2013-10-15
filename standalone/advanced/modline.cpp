// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "modline.h"
#include "tables.h"

#include <CoreMIDI/CoreMIDI.h>
#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <AudioUnit/AudioUnit.h>

//Constants for various modline arrangement parameters
#define MODLINE_WINDOW_WIDTH 1100
#define MODLINE_WINDOW_HEIGHT 42
#define MODLINE_SPACING 5
#define MODLINE_STARTING_X_POS 9
#define MODLINE_STARTING_Y_POS 98

Modline::Modline(QWidget *parent, int keyInstanceNum, int modlineInstanceNum) :
    QWidget(parent),
    formWidget(new QWidget(this)),
    //hosted_formWidget(new QWidget(this)),
    modlineForm(new Ui::modlineForm)
  //hosted_modlineForm(new Ui::modlineForm_hosted)

{
    keyInstance = keyInstanceNum;
    modlineInstance = modlineInstanceNum;

    this->setObjectName(QString("%1_Key_%2_Modline").arg(keyInstance+1).arg(modlineInstance+1));

    //---------------------------------------- Set Up Ui
    modlineForm->setupUi(formWidget);

    rawBox = modlineForm->raw;
    resultBox = modlineForm->result;
    valueBox = modlineForm->outputvalue;


    this->setFixedSize(MODLINE_WINDOW_WIDTH, MODLINE_WINDOW_HEIGHT);
    this->setGeometry(MODLINE_STARTING_X_POS, MODLINE_STARTING_Y_POS + ((modlineInstance)*(MODLINE_WINDOW_HEIGHT + MODLINE_SPACING)), MODLINE_WINDOW_WIDTH, MODLINE_WINDOW_HEIGHT);

    modlineForm->instanceLabel->setText(QString("%1").arg((modlineInstance + 1)%10));
    modlineForm->deviceViews->setCurrentIndex(0);
    modlineForm->deviceViewLabels->setCurrentIndex(0);
    modlineForm->raw->setValue(0);
    modlineForm->enable->setStyleSheet(stylesheets.modlineEnableStyleSheet.at(modlineInstanceNum));

    raw = 0;
    result = 0;
    value = 0;

    //QTimer *updateGraphicsClock = new QTimer(this);
    //connect(updateGraphicsClock, SIGNAL(timeout()), this, SLOT(slotDisplayVars()));
    //updateGraphicsClock->start(10);
}

void Modline::slotConnectElements()
{
    //enable checkbox
    connect(modlineForm->enable,SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //init mode
    connect(modlineForm->initmode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //init value
    connect(modlineForm->initvalue,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //source
    connect(modlineForm->source,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //gain
    connect(modlineForm->gain,SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));

    //offset
    connect(modlineForm->offset,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //table menu
    connect(modlineForm->table,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //min
    connect(modlineForm->min,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //max
    connect(modlineForm->max,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //slew
    connect(modlineForm->slew,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //delay
    connect(modlineForm->delay,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //parameter destination menu
    connect(modlineForm->destination,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //destination parameters
    connect(modlineForm->notenumber,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->notevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->notelivevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->cc,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->bankmsb,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->polynote,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(modlineForm->notechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->notelivechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->controlchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->bankchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->programchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->bendchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->aftertouchchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->polychannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(modlineForm->notedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->notelivedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->controldevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->bankdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->programdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->benddevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->aftertouchdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->polydevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    connect(modlineForm->mmcdeviceid,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->mmcfunction,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    connect(modlineForm->mmcdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    connect(modlineForm->oscroute,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));

    //green LED
    connect(modlineForm->ledgreen,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //red LED
    connect(modlineForm->ledred,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //connect and initialize the raw value to the result (not for preset)
    connect(modlineForm->raw,SIGNAL(valueChanged(int)),this,SLOT(slotRawResult()));
    connect(modlineForm->gain,SIGNAL(valueChanged(double)),this,SLOT(slotRawResult()));
    connect(modlineForm->offset,SIGNAL(valueChanged(int)),this,SLOT(slotRawResult()));

    //----------------------- Hosted - Slewer
    connect(&slewer, SIGNAL(signalOutput(int)), this, SLOT(slotSmooth(int)));

}

void Modline::slotDisconnectElements()
{
    //enable checkbox
    disconnect(modlineForm->enable,SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //init mode
    disconnect(modlineForm->initmode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //init value
    disconnect(modlineForm->initvalue,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //source
    disconnect(modlineForm->source,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //gain
    disconnect(modlineForm->gain,SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));

    //offset
    disconnect(modlineForm->offset,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //table menu
    disconnect(modlineForm->table,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //min
    disconnect(modlineForm->min,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //max
    disconnect(modlineForm->max,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //slew
    disconnect(modlineForm->slew,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //delay
    disconnect(modlineForm->delay,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    //parameter destination menu
    disconnect(modlineForm->destination,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //destination parameters
    disconnect(modlineForm->notenumber,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->notevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->notelivevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->cc,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->bankmsb,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->polynote,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    disconnect(modlineForm->notechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->notelivechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->controlchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->bankchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->programchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->bendchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->aftertouchchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->polychannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    disconnect(modlineForm->notedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->notelivedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->controldevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->bankdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->programdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->benddevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->aftertouchdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->polydevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    disconnect(modlineForm->mmcdeviceid,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->mmcfunction,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(modlineForm->mmcdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    disconnect(modlineForm->oscroute,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));

    //green LED
    disconnect(modlineForm->ledgreen,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //red LED
    disconnect(modlineForm->ledred,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
}

void Modline::slotValueChanged()
{    
    //--------------------------- JSON Saving
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;

        //enable checkbox
        if(sender == modlineForm->enable)
        {
            jsonName = "enable";
            value = modlineForm->enable->isChecked();
        }

        //initMode
        else if(sender == modlineForm->initmode)
        {
            jsonName = "initmode";
            value = modlineForm->initmode->currentText();
        }

        //initValue
        else if(sender == modlineForm->initvalue)
        {
            jsonName = "initvalue";
            value = modlineForm->initvalue->value();
        }

        //Source Menu
        else if(sender == modlineForm->source)
        {
            jsonName = "source";
            value = modlineForm->source->currentText();
        }

        //Gain
        else if(sender == modlineForm->gain)
        {
            jsonName = "gain";
            value = modlineForm->gain->value();
        }

        //Offset
        else if(sender == modlineForm->offset)
        {
            jsonName = "offset";
            value = modlineForm->offset->value();
        }

        //Table Menu
        else if(sender == modlineForm->table)
        {
            jsonName = "table";
            value = modlineForm->table->currentText();
        }

        //Min
        else if(sender == modlineForm->min)
        {
            jsonName = "min";
            value = modlineForm->min->value();
        }

        //Max
        else if(sender == modlineForm->max)
        {
            jsonName = "max";
            value = modlineForm->max->value();
        }

        //slew
        else if(sender == modlineForm->slew)
        {
            jsonName = "slew";
            value = modlineForm->slew->value();
        }

        //delay
        else if(sender == modlineForm->delay)
        {
            jsonName = "delay";
            value = modlineForm->delay->value();
        }

        //Destination Menu
        else if(sender == modlineForm->destination)
        {
            slotRecallDestinationMenu();

            jsonName = "destination";
            value = modlineForm->destination->currentText();
        }

        //destination parameters

        else if(sender == modlineForm->notenumber)
        {
            jsonName = "note";
            value = modlineForm->notenumber->value();
        }
        else if(sender == modlineForm->notevelocity)
        {
            jsonName = "velocity";
            value = modlineForm->notevelocity->value();
        }
        else if(sender == modlineForm->notelivevelocity)
        {
            jsonName = "velocity";
            value = modlineForm->notelivevelocity->value();
        }
        else if(sender == modlineForm->cc)
        {
            jsonName = "cc";
            value = modlineForm->cc->value();
        }
        else if(sender == modlineForm->bankmsb)
        {
            jsonName = "bankMSB";
            value = modlineForm->bankmsb->value();
        }
        else if(sender == modlineForm->polynote)
        {
            jsonName = "note";
            value = modlineForm->polynote->value();
        }

        else if(sender == modlineForm->notechannel)
        {
            jsonName = "channel";
            value = modlineForm->notechannel->value();
        }
        else if(sender == modlineForm->notelivechannel)
        {
            jsonName = "channel";
            value = modlineForm->notelivechannel->value();
        }
        else if(sender == modlineForm->controlchannel)
        {
            jsonName = "channel";
            value = modlineForm->controlchannel->value();
        }
        else if(sender == modlineForm->bankchannel)
        {
            jsonName = "channel";
            value = modlineForm->bankchannel->value();
        }
        else if(sender == modlineForm->programchannel)
        {
            jsonName = "channel";
            value = modlineForm->programchannel->value();
        }
        else if(sender == modlineForm->bendchannel)
        {
            jsonName = "channel";
            value = modlineForm->bendchannel->value();
        }
        else if(sender == modlineForm->aftertouchchannel)
        {
            jsonName = "channel";
            value = modlineForm->aftertouchchannel->value();
        }
        else if(sender == modlineForm->polychannel)
        {
            jsonName = "channel";
            value = modlineForm->polychannel->value();
        }

        else if(sender == modlineForm->notedevice)
        {
            jsonName = "device";
            value = modlineForm->notedevice->currentText();
        }
        else if(sender == modlineForm->notelivedevice)
        {
            jsonName = "device";
            value = modlineForm->notelivedevice->currentText();
        }
        else if(sender == modlineForm->controldevice)
        {
            jsonName = "device";
            value = modlineForm->controldevice->currentText();
        }
        else if(sender == modlineForm->bankdevice)
        {
            jsonName = "device";
            value = modlineForm->bankdevice->currentText();
        }
        else if(sender == modlineForm->programdevice)
        {
            jsonName = "device";
            value = modlineForm->programdevice->currentText();
        }
        else if(sender == modlineForm->benddevice)
        {
            jsonName = "device";
            value = modlineForm->benddevice->currentText();
        }
        else if(sender == modlineForm->aftertouchdevice)
        {
            jsonName = "device";
            value = modlineForm->aftertouchdevice->currentText();
        }
        else if(sender == modlineForm->polydevice)
        {
            jsonName = "device";
            value = modlineForm->polydevice->currentText();
        }

        else if(sender == modlineForm->mmcdeviceid)
        {
            jsonName = "mmcid";
            value = modlineForm->mmcdeviceid->value();
        }
        else if(sender == modlineForm->mmcfunction)
        {
            jsonName = "mmcfunction";
            value = modlineForm->mmcfunction->currentText();
        }
        else if(sender == modlineForm->mmcdevice)
        {
            jsonName = "device";
            value = modlineForm->mmcdevice->currentText();
        }

        else if(sender == modlineForm->oscroute)
        {
            jsonName = "oscroute";
            value = modlineForm->oscroute->text();
        }

        //Green LED
        else if(sender == modlineForm->ledgreen)
        {
            jsonName = "ledgreen";
            value = modlineForm->ledgreen->currentText();
        }

        //Red LED
        else if(sender == modlineForm->ledred)
        {
            jsonName = "ledred";
            value = modlineForm->ledred->currentText();
        }

        emit signalStoreValue(QString("key%1_modline%2_").arg(keyInstance+1).arg(modlineInstance+1) + jsonName, value, -1);
    }

    emit signalCheckSavedState();

    //---------- update hosted source streaming
    slotStreamSourceData();
}

void Modline::slotRecallPreset(QVariantMap preset, QVariantMap)
{

    slotDisconnectElements();

    //basic modline parameters
    modlineForm->enable->setChecked(preset.value(QString("key%1_modline%2_enable").arg(keyInstance+1).arg(modlineInstance+1)).toBool());
    modlineForm->initvalue->setValue(preset.value(QString("key%1_modline%2_initvalue").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->initmode->setCurrentIndex(modlineForm->initmode->findText(preset.value(QString("key%1_modline%2_initmode").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->source->setCurrentIndex(modlineForm->source->findText(preset.value(QString("key%1_modline%2_source").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->gain->setValue(preset.value(QString("key%1_modline%2_gain").arg(keyInstance+1).arg(modlineInstance+1)).toDouble());
    modlineForm->offset->setValue(preset.value(QString("key%1_modline%2_offset").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->table->setCurrentIndex(modlineForm->table->findText(preset.value(QString("key%1_modline%2_table").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->min->setValue(preset.value(QString("key%1_modline%2_min").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->max->setValue(preset.value(QString("key%1_modline%2_max").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->slew->setValue(preset.value(QString("key%1_modline%2_slew").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->delay->setValue(preset.value(QString("key%1_modline%2_delay").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->destination->setCurrentIndex(modlineForm->destination->findText(preset.value(QString("key%1_modline%2_destination").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    //LED parameters
    modlineForm->ledgreen->setCurrentIndex(modlineForm->ledgreen->findText(preset.value(QString("key%1_modline%2_ledgreen").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->ledred->setCurrentIndex(modlineForm->ledred->findText(preset.value(QString("key%1_modline%2_ledred").arg(keyInstance+1).arg(modlineInstance+1)).toString()));


    //destination parameters
    modlineForm->notenumber->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    //modlineForm->noteLiveNumber->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->polynote->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

    modlineForm->notevelocity->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->notelivevelocity->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->cc->setValue(preset.value(QString("key%1_modline%2_cc").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->bankmsb->setValue(preset.value(QString("key%1_modline%2_bankmsb").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

    modlineForm->notechannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->notelivechannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->controlchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->bankchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->programchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->bendchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->aftertouchchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->polychannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

    modlineForm->notedevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->notelivedevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->controldevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->bankdevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->programdevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->benddevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->aftertouchdevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->polydevice->setCurrentIndex(modlineForm->notedevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    modlineForm->mmcdeviceid->setValue(preset.value(QString("key%1_modline%2_mmcid").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->mmcfunction->setCurrentIndex(modlineForm->mmcfunction->findText(preset.value(QString("key%1_modline%2_mmcfunction").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->mmcdevice->setCurrentIndex(modlineForm->mmcdevice->findText(preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    modlineForm->oscroute->setText(preset.value(QString("key%1_modline%2_oscroute").arg(keyInstance+1).arg(modlineInstance+1)).toString());

    slotRecallDestinationMenu();

    slotConnectElements();

    //---------- update hosted source streaming
    slotStreamSourceData();
}

void Modline::slotRecallDestinationMenu()
{
    //set the device view to change based on what is selected in the destination menu
    if((modlineForm->destination->currentIndex()) > 10)
    {
        modlineForm->deviceViews->setCurrentIndex(0);
        modlineForm->deviceViewLabels->setCurrentIndex(0);
    }
    else
    {
        modlineForm->deviceViews->setCurrentIndex(modlineForm->destination->currentIndex());
        modlineForm->deviceViewLabels->setCurrentIndex(modlineForm->destination->currentIndex());
    }
}

void Modline::slotRawResult()
{
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        //raw-result (not sent to presets)
        if(sender == modlineForm->raw || sender == modlineForm->gain || sender == modlineForm->offset)
        {
            modlineForm->result->setValue((modlineForm->raw->value())*(modlineForm->gain->value())+(modlineForm->offset->value()));
        }
    }

    //qDebug() << "initialize result value";
}

void Modline::slotSetMode(QString m)
{
    mode = m;
}

void Modline::slotPopulateMenus(QStringList source, QStringList dest, QStringList table)
{
    //Set Source Menu
    modlineForm->source->clear();
    modlineForm->source->addItems(source);

    //Set Table Menu
    modlineForm->table->clear();
    modlineForm->table->addItems(table);

    //Set Destination Menu
    modlineForm->destination->clear();
    modlineForm->destination->addItems(dest);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////    Hosted   ///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Modline::slotStreamSourceData()
{

    qDebug() << modlineForm->source->currentText() << mode;
    //--------------------------- Hosted
    if(mode == "hosted")
    {
        //Set instance modline/transform params
        slotSetTransformValues();

        //Get source from key data cooker
        emit signalSetSource(modlineForm->source->currentText(), modlineInstance);
    }
}

void Modline::slotSetTransformValues()
{
    gain = modlineForm->gain->value();
    offset = modlineForm->offset->value();

    //Set table array here later
    table = modlineForm->table->currentText();

    min = modlineForm->min->value();
    max = modlineForm->max->value();
    smooth = modlineForm->slew->value();
    delay = modlineForm->delay->value();

    //qDebug() << "modline: " << modlineInstance << gain << offset << table << min << max << smooth << delay;
}

void Modline::slotTransformSource(int val, int modlineNum, QString source)
{
    //All streams are sent to all modlines, so we need arrays to filter
    static QString lastSource[6] = {"None", "None", "None", "None", "None", "None"};
    static int lastVal[6] = {-1, -1, -1, -1, -1, -1};

    static int output[6] = {0,0,0,0,0,0};

    //Make sure this is the correct modline to receive source being emitted
    if(modlineNum == modlineInstance)
    {
        //If source value is different from last or there is a change in value...
        if(lastVal[modlineNum] != val || lastSource[modlineNum] != source)
        {
            //Set raw display value
            raw = val;

            //Apply gain and offset
            val = val*gain + offset;

            //Set result display vaule
            result = val;

            //Table
            val = slotTable(val);

            //Min Max
            val = slotMinMax(val);

            //Smooth
            //If slew time specified
            if(smooth != 0)
            {
                //Handle output from slotSlew()
                slewer.slotSlew(output[modlineNum], modlineForm->slew->value());
            }
            else
            {
                //If delay and no slew...
                if(delay != 0)
                {

                }

                //If no delay and no slew...
                else
                {
                    value = val;
                }
            }

            //Delay

            qDebug() << "transform modline : " << modlineNum << "raw:" <<  raw << "result: " << result << "value:"  << value;
            emit hosted_signalCC("SoftStep Share", 1, 7, value);
        }

        lastVal[modlineNum] = val;
        lastSource[modlineNum] = source;





    }

    //table

    //min, max

    //smooth

    //delay

    slotDisplayVars();
}

int Modline::slotTable(int input)
{
    //Clip table input
    if(input > 127)
    {
        input = 127;
    }

    if(input < 0)
    {
        input = 0;
    }

    if( table == "Linear")
    {
        return linear[input];
    }
    else if(table == "Sine")
    {
        return sine[input];
    }
    else if(table == "Cosine")
    {
        return cosine[input];
    }
    else if(table == "Exponential")
    {
        return exponential[input];
    }
    else if(table == "Logarithmic")
    {
        return logarithmic[input];
    }
}

int Modline::slotMinMax(int input)
{
    //If min max are flipped... Don't know... return input for now
    if(min > max)
    {
        return input;
    }

    //If they're equal or max is greater than min
    else
    {
        if(input < min)
        {
            return min;
        }
        else if(input > max)
        {
            return max;
        }
        else
        {
            return input;
        }
    }
}

void Modline::slotSmooth(int result)
{
    //qDebug() << result;
}

int Modline::slotDelay(int input)
{

}

void Modline::slotDisplayVars()
{
    modlineForm->raw->setValue(raw);
    modlineForm->result->setValue(result);
    modlineForm->outputvalue->setValue(value);
}





