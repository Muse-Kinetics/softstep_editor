// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "modline.h"
#include <QAbstractItemView>

#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>
#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <AudioUnit/AudioUnit.h>
#else
#include <Windows.h>
#include <MMSystem.h>
#include <Dbt.h>
#include "WindowsMidiTypes.h"
#endif

#include <QElapsedTimer>

//Constants for various modline arrangement parameters
#define MODLINE_WINDOW_WIDTH 1132
#define MODLINE_WINDOW_HEIGHT 42
#define MODLINE_SPACING 5
#define MODLINE_STARTING_X_POS 9
#define MODLINE_STARTING_Y_POS 98

Modline::Modline(QWidget *parent, int keyInstanceNum, int modlineInstanceNum) :
    QWidget(parent)//,
    //formWidget(new QWidget(this)),
    //hosted_formWidget(new QWidget(this)),
    //modlineForm(new Ui::modlineForm)
  //hosted_modlineForm(new Ui::modlineForm_hosted)

{
    qDebug() << "init modline - key: " << keyInstanceNum << " modline: " << modlineInstanceNum;

    QElapsedTimer eTimer;
    eTimer.start();

    keyInstance = keyInstanceNum;
    modlineInstance = modlineInstanceNum;

    lastSource = "None";
    lastVal = -1;
    output = -1;

    firstCall = true;

    lastNote = -1;
    toggleOnMMC = false;

    eTimer.restart();

    this->setObjectName(QString("%1_Key_%2_Modline").arg(keyInstance+1).arg(modlineInstance+1));

    //---------------------------------------- Set Up Ui
    eTimer.restart();

    formWidget = new QWidget(this);

    eTimer.restart();

    modlineForm = new Ui::modlineForm;

    eTimer.restart();

    modlineForm->setupUi(formWidget);

    qDebug() << "geometry - elapsed: " << eTimer.elapsed();
    eTimer.restart();

    this->setFixedSize(MODLINE_WINDOW_WIDTH, MODLINE_WINDOW_HEIGHT);
    this->setGeometry(MODLINE_STARTING_X_POS, MODLINE_STARTING_Y_POS + ((modlineInstance)*(MODLINE_WINDOW_HEIGHT + MODLINE_SPACING)), MODLINE_WINDOW_WIDTH, MODLINE_WINDOW_HEIGHT);

    eTimer.restart();

    modlineForm->instanceLabel->setText(QString("%1").arg((modlineInstance + 1)%10));
    eTimer.restart();

    //modlineForm->deviceViews->setCurrentIndex(0);

    eTimer.restart();

    //modlineForm->deviceViewLabels->setCurrentIndex(0);

    eTimer.restart();

    modlineForm->raw->setValue(0);
    modlineForm->enable->setStyleSheet(stylesheets.modlineEnableStyleSheet.at(modlineInstanceNum));

    displayLinkButton = modlineForm->modlinedisplayenable;

    eTimer.restart();

    raw = 0;
    result = 0;
    value = 0;

    //QTimer *updateGraphicsClock = new QTimer(this);
    //connect(updateGraphicsClock, SIGNAL(timeout()), this, SLOT(slotDisplayVars()));
    //updateGraphicsClock->start(10);

    toggleTable = false;
    tableToggleGate = true;

    counterGate = true;

    initModeOnceCalled = false;


    //connect(modlineForm->raw, SIGNAL(valueChanged(int)), this, SLOT(slotTestValues(int)));
}

void Modline::slotConnectElements()
{
    // fix ui element styles
    foreach(QWidget* widget, formWidget->findChildren<QWidget *>())
    {
        //check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
           //
        }
        else if(widget->metaObject()->className() == QString("QDoubleSpinBox"))
        {
            //
        }
        else if(widget->metaObject()->className() == QString("QCheckBox"))
        {
           //
        }
        else if(widget->metaObject()->className() == QString("QComboBox"))
        {
            QComboBox* combobox = qobject_cast<QComboBox *>(widget);
            QString comboName = combobox->objectName();
            //qDebug() << "Combobox name: " << comboName;

            int width = combobox->minimumSizeHint().width() + 35;
            width = (width > 150) ? 150 : width;

            combobox->view()->setMinimumWidth(width);
            combobox->view()->setMaximumWidth(150);
        }
        else if(widget->metaObject()->className() == QString("QLineEdit"))
        {
           //
        }
        else if(widget->metaObject()->className() == QString("QRadioButton"))
        {
           //
        }
    }




    //enable checkbox
    connect(modlineForm->enable,SIGNAL(clicked()),this,SLOT(slotValueChanged()));


    //hosted only parameters
    if(mode == "hosted")
    {
        //init mode
        connect(modlineForm->initmode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

        //init value
        connect(modlineForm->initvalue,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

        //delay
        connect(modlineForm->delay,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    }

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

    //parameter destination menu
    connect(modlineForm->destination,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //destination parameters
//    connect(modlineForm->notenumber,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->notevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->notevelocity,SIGNAL(valueChanged(int)),modlineForm->notelivevelocity, SLOT(setValue(int)));
//    connect(modlineForm->notelivevelocity,SIGNAL(valueChanged(int)),modlineForm->notevelocity, SLOT(setValue(int)));
//    //connect(modlineForm->notelivevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->cc,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->bankmsb,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->polynote,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

//    connect(modlineForm->notechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->notelivechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->controlchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->bankchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->programchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->bendchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->aftertouchchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->polychannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

//    connect(modlineForm->notedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->notelivedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->controldevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->bankdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->programdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->benddevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->aftertouchdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->polydevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

//    connect(modlineForm->mmcdeviceid,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->mmcfunction,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    connect(modlineForm->mmcdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

//    connect(modlineForm->oscroute,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));

    // new, simpler method
    connect(modlineForm->dest_b1, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    connect(modlineForm->dest_b2, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    connect(modlineForm->dest_b3, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    connect(modlineForm->dest_device, SIGNAL(textActivated(QString)), this, SLOT(slotValueChanged()));
    connect(modlineForm->dest_mmcfunction, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));
    connect(modlineForm->dest_oscroute, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));


    //green LED
    connect(modlineForm->ledgreen,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //red LED
    connect(modlineForm->ledred,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //display linking
    connect(modlineForm->modlinedisplayenable,SIGNAL(toggled(bool)),this,SLOT(slotValueChanged()));

    //----------------------- Hosted
    //Slewer
    connect(&slewer, SIGNAL(signalOutput(int)), this, SLOT(slotSmoothReturn(int)));

    //Delay
    connect(&delayer, SIGNAL(signalDelayedOutput(int)), this, SLOT(slotDelayReturn(int)));

    //connect(this, SIGNAL(hosted_signalSendModlineOutput(int,int)), &ledManager, SLOT(slotReceiveModlineOutput(int,int)));

    //Init and test (manual value changing)
    connect(modlineForm->initvalue, SIGNAL(valueChanged(int)), this, SLOT(slotTestValues(int)));
}

void Modline::slotDisconnectElements()
{
    //enable checkbox
    disconnect(modlineForm->enable,SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //hosted only parameters
    if(mode == "hosted")
    {
        //init mode
        disconnect(modlineForm->initmode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

        //init value
        disconnect(modlineForm->initvalue,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

        //delay
        disconnect(modlineForm->delay,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    }

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

    //parameter destination menu
    disconnect(modlineForm->destination,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //destination parameters
//    disconnect(modlineForm->notenumber,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->notevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    //disconnect(modlineForm->notelivevelocity,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->cc,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->bankmsb,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->polynote,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

//    disconnect(modlineForm->notechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->notelivechannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->controlchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->bankchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->programchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->bendchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->aftertouchchannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->polychannel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

//    disconnect(modlineForm->notedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->notelivedevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->controldevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->bankdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->programdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->benddevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->aftertouchdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->polydevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

//    disconnect(modlineForm->mmcdeviceid,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->mmcfunction,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
//    disconnect(modlineForm->mmcdevice,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

//    disconnect(modlineForm->oscroute,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));

    // new, simpler method
    disconnect(modlineForm->dest_b1, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    disconnect(modlineForm->dest_b2, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    disconnect(modlineForm->dest_b3, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    disconnect(modlineForm->dest_device, SIGNAL(textActivated(QString)), this, SLOT(slotValueChanged()));
    disconnect(modlineForm->dest_mmcfunction, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));
    disconnect(modlineForm->dest_oscroute, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));


    //green LED
    disconnect(modlineForm->ledgreen,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //red LED
    disconnect(modlineForm->ledred,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //display linking
    disconnect(modlineForm->modlinedisplayenable,SIGNAL(toggled(bool)),this,SLOT(slotValueChanged()));

    //----------------------- Hosted
    //Slewer
    disconnect(&slewer, SIGNAL(signalOutput(int)), this, SLOT(slotSmoothReturn(int)));

    //Delay
    disconnect(&delayer, SIGNAL(signalDelayedOutput(int)), this, SLOT(slotDelayReturn(int)));

    //disconnect(this, SIGNAL(hosted_signalSendModlineOutput(int,int)), &ledManager, SLOT(slotReceiveModlineOutput(int,int)));

    //Init and test (manual value changing)
    disconnect(modlineForm->initvalue, SIGNAL(valueChanged(int)), this, SLOT(slotTestValues(int)));
}

void Modline::slotValueChanged()
{    
    //--------------------------- JSON Saving
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;
        QString senderName = sender->objectName();
        QString objectType = sender->metaObject()->className();

        qDebug() << "slotValueChanged - sender: " << sender->objectName();

        // handle destination menu objects
        if (senderName.contains("dest_"))
        {
            if(senderName == "dest_b1")
            {
                value = modlineForm->dest_b1->value();

                // set jsonName based on destination/index
                switch (modDest.index)
                {
                case DEST_NOTE_SET:
                    jsonName = "note";
                    break;
                case DEST_MMC:
                    jsonName = "mmcid";
                    break;
                }
            }
            else if(senderName == "dest_b2")
            {
                value = modlineForm->dest_b2->value();

                // set jsonName based on destination/index
                switch (modDest.index)
                {
                case DEST_NOTE_LIVE:
                    jsonName = "velocity";
                    break;
                case DEST_CC:
                    jsonName = "cc";
                    break;
                case DEST_BANK:
                    jsonName = "bankmsb";
                    break;
                case DEST_POLY_AFTERTOUCH:
                    jsonName = "note";
                    break;
                }
            }
            else if(senderName == "dest_b3")
            {
                value = modlineForm->dest_b3->value();

                // set jsonName based on destination/index
                switch (modDest.index)
                {
                case DEST_NOTE_LIVE:
                case DEST_CC:
                case DEST_BANK:
                case DEST_PROGRAM:
                case DEST_PITCH_BEND:
                case DEST_AFTERTOUCH:
                case DEST_POLY_AFTERTOUCH:
                    jsonName = "channel";
                    break;
                }
            }
            else if(senderName == "dest_device")
            {
                value = modlineForm->dest_device->currentText();
                jsonName = "device";

            }
            else if(senderName == "dest_mmcfunction")
            {
                value = modlineForm->dest_mmcfunction->currentText();
                jsonName = "mmcfunction";

            }
            else if(senderName == "dest_oscroute")
            {
                jsonName = "oscroute";
                value = modlineForm->dest_oscroute->text();
            }
            qDebug() << "destination menu - jsonName: " << jsonName << " value: " << value;
        }

        //enable checkbox
        else if(sender == modlineForm->enable)
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
            qDebug() << "modline slotvaluechanged - destination";
            slotRecallDestinationMenu();

            jsonName = "destination";
            value = modlineForm->destination->currentText();
        }
//        //destination parameters
//        else if(sender == modlineForm->dest_b1)
//        {
//            jsonName = "note";
//            value = modlineForm->dest_b1->value();
//        }
//        else if(sender == modlineForm->dest_b2)
//        {
//            jsonName = "velocity";
//            value = modlineForm->dest_b2->value();
//        }
//        else if(sender == modlineForm->cc)
//        {
//            jsonName = "cc";
//            value = modlineForm->cc->value();
//        }
//        else if(sender == modlineForm->bankmsb)
//        {
//            jsonName = "bankmsb";
//            value = modlineForm->bankmsb->value();
//        }
//        else if(sender == modlineForm->polynote)
//        {
//            jsonName = "note";
//            value = modlineForm->polynote->value();
//        }
//        //channels
//        else if(sender == modlineForm->notechannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->notechannel->value();
//        }
//        else if(sender == modlineForm->notelivechannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->notelivechannel->value();
//        }
//        else if(sender == modlineForm->controlchannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->controlchannel->value();
//        }
//        else if(sender == modlineForm->bankchannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->bankchannel->value();
//        }
//        else if(sender == modlineForm->programchannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->programchannel->value();
//        }
//        else if(sender == modlineForm->bendchannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->bendchannel->value();
//        }
//        else if(sender == modlineForm->aftertouchchannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->aftertouchchannel->value();
//        }
//        else if(sender == modlineForm->polychannel)
//        {
//            jsonName = "channel";
//            value = modlineForm->polychannel->value();
//        }
//        //devices
//        else if(sender == modlineForm->notedevice)
//        {
//            jsonName = "device";
//            value = modlineForm->notedevice->currentText();
//        }
//        else if(sender == modlineForm->notelivedevice)
//        {
//            jsonName = "device";
//            value = modlineForm->notelivedevice->currentText();
//        }
//        else if(sender == modlineForm->controldevice)
//        {
//            jsonName = "device";
//            value = modlineForm->controldevice->currentText();
//        }
//        else if(sender == modlineForm->bankdevice)
//        {
//            jsonName = "device";
//            value = modlineForm->bankdevice->currentText();
//        }
//        else if(sender == modlineForm->programdevice)
//        {
//            jsonName = "device";
//            value = modlineForm->programdevice->currentText();
//        }
//        else if(sender == modlineForm->benddevice)
//        {
//            jsonName = "device";
//            value = modlineForm->benddevice->currentText();
//        }
//        else if(sender == modlineForm->aftertouchdevice)
//        {
//            jsonName = "device";
//            value = modlineForm->aftertouchdevice->currentText();
//        }
//        else if(sender == modlineForm->polydevice)
//        {
//            jsonName = "device";
//            value = modlineForm->polydevice->currentText();
//        }
//        else if(sender == modlineForm->mmcdeviceid)
//        {
//            jsonName = "mmcid";
//            value = modlineForm->mmcdeviceid->value();
//        }
//        else if(sender == modlineForm->mmcfunction)
//        {
//            jsonName = "mmcfunction";
//            value = modlineForm->mmcfunction->currentText();
//        }
//        else if(sender == modlineForm->mmcdevice)
//        {
//            jsonName = "device";
//            value = modlineForm->mmcdevice->currentText();
//        }
//        else if(sender == modlineForm->oscroute)
//        {
//            jsonName = "oscroute";
//            value = modlineForm->oscroute->text();
//        }
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
        //display linking
        else if(sender == modlineForm->modlinedisplayenable)
        {
            jsonName = "displaylinked";
            value = modlineForm->modlinedisplayenable->isChecked();
        }

        emit signalStoreValue(QString("key%1_modline%2_").arg(keyInstance+1).arg(modlineInstance+1) + jsonName, value, -1);

        //---------- disable modline if necessary
        if(mode == "standalone" && jsonName == "enable" && value == true)
        {
            emit signalModlineEnabled(QString("key%1_modline%2_enable").arg(keyInstance+1).arg(modlineInstance+1));
            //qDebug() << "Emiting signal from the modline to say it is enabled: key#/modline#" << keyInstance+1 << modlineInstance+1;
        }
    }

    emit signalCheckSavedState();

    //---------- update hosted source streaming
    slotStreamSourceData();
    emit hosted_signalSetLEDMode(modlineInstance, modlineForm->ledgreen->currentText(), modlineForm->ledred->currentText());
}

void Modline::slotRecallPreset(QVariantMap preset, QVariantMap)
{

    slotDisconnectElements();

    //basic modline parameters
    modlineForm->enable->setChecked(preset.value(QString("key%1_modline%2_enable").arg(keyInstance+1).arg(modlineInstance+1)).toBool());
    if(mode == "hosted")  //hosted only parameters
    {
        modlineForm->initvalue->setValue(preset.value(QString("key%1_modline%2_initvalue").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
        modlineForm->initmode->setCurrentIndex(modlineForm->initmode->findText(preset.value(QString("key%1_modline%2_initmode").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
        modlineForm->delay->setValue(preset.value(QString("key%1_modline%2_delay").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    }
    modlineForm->source->setCurrentIndex(modlineForm->source->findText(preset.value(QString("key%1_modline%2_source").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->gain->setValue(preset.value(QString("key%1_modline%2_gain").arg(keyInstance+1).arg(modlineInstance+1)).toDouble());
    modlineForm->offset->setValue(preset.value(QString("key%1_modline%2_offset").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->table->setCurrentIndex(modlineForm->table->findText(preset.value(QString("key%1_modline%2_table").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->min->setValue(preset.value(QString("key%1_modline%2_min").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->max->setValue(preset.value(QString("key%1_modline%2_max").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->slew->setValue(preset.value(QString("key%1_modline%2_slew").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    modlineForm->destination->setCurrentIndex(modlineForm->destination->findText(preset.value(QString("key%1_modline%2_destination").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    //LED parameters
    modlineForm->ledgreen->setCurrentIndex(modlineForm->ledgreen->findText(preset.value(QString("key%1_modline%2_ledgreen").arg(keyInstance+1).arg(modlineInstance+1)).toString()));
    modlineForm->ledred->setCurrentIndex(modlineForm->ledred->findText(preset.value(QString("key%1_modline%2_ledred").arg(keyInstance+1).arg(modlineInstance+1)).toString()));

    //destination parameters

    QString presetDevice = preset.value(QString("key%1_modline%2_device").arg(keyInstance+1).arg(modlineInstance+1)).toString();

    // fix old port names
    if (presetDevice.contains("SSCOM"))
    {
        if (mode == "standalone")
        {
            presetDevice = "SoftStep USB MIDI";
        }
        else if (mode == "hosted")
        {
            presetDevice = "SoftStep Share";
        }
    }

    //storing these in a struct for later recall when we change the destination type/index
    modDest.outPortName = presetDevice;
    // modDest.index = modlineForm->destination->currentIndex(); // happens in slotRecallDestinationMenu()
    modDest.channel = preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt();
    modDest.note = preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt();
    modDest.velocity = preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt();
    modDest.cc = preset.value(QString("key%1_modline%2_cc").arg(keyInstance+1).arg(modlineInstance+1)).toInt();
    modDest.bankMSB = preset.value(QString("key%1_modline%2_bankmsb").arg(keyInstance+1).arg(modlineInstance+1)).toInt();
    modDest.mmcID = preset.value(QString("key%1_modline%2_mmcid").arg(keyInstance+1).arg(modlineInstance+1)).toInt();
    modDest.mmcFunction = preset.value(QString("key%1_modline%2_mmcfunction").arg(keyInstance+1).arg(modlineInstance+1)).toString();
    modDest.oscRoute = preset.value(QString("key%1_modline%2_oscroute").arg(keyInstance+1).arg(modlineInstance+1)).toString();

    // update the values in the for

    // midi port dropdown
    modlineForm->dest_device->setCurrentText(modDest.outPortName);

    // mmc function dropdown
    modlineForm->dest_mmcfunction->setCurrentText(modDest.mmcFunction);

    // osc text field
    modlineForm->dest_oscroute->setText(modDest.oscRoute);

    // Updating values and showing/hiding the shared ui elements elements happens in slotRecallDestinationMenu();
    slotRecallDestinationMenu();

    // old method
    //modlineForm->notenumber->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
    //modlineForm->polynote->setValue(preset.value(QString("key%1_modline%2_note").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

//    modlineForm->notevelocity->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->notelivevelocity->setValue(preset.value(QString("key%1_modline%2_velocity").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->cc->setValue(preset.value(QString("key%1_modline%2_cc").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->bankmsb->setValue(preset.value(QString("key%1_modline%2_bankmsb").arg(keyInstance+1).arg(modlineInstance+1)).toInt());

//    modlineForm->notechannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->notelivechannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->controlchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->bankchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->programchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->bendchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->aftertouchchannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());
//    modlineForm->polychannel->setValue(preset.value(QString("key%1_modline%2_channel").arg(keyInstance+1).arg(modlineInstance+1)).toInt());


    // EB TODO - set these based on the current destination
//    modlineForm->notedevice->setCurrentIndex(modlineForm->notedevice->findText(presetDevice));
//    modlineForm->notelivedevice->setCurrentIndex(modlineForm->notelivedevice->findText(presetDevice));
//    modlineForm->controldevice->setCurrentIndex(modlineForm->controldevice->findText(presetDevice));
//    modlineForm->bankdevice->setCurrentIndex(modlineForm->bankdevice->findText(presetDevice));
//    modlineForm->programdevice->setCurrentIndex(modlineForm->programdevice->findText(presetDevice));
//    modlineForm->benddevice->setCurrentIndex(modlineForm->benddevice->findText(presetDevice));
//    modlineForm->aftertouchdevice->setCurrentIndex(modlineForm->aftertouchdevice->findText(presetDevice));
//    modlineForm->polydevice->setCurrentIndex(modlineForm->polydevice->findText(presetDevice));




    modlineForm->modlinedisplayenable->setChecked(preset.value(QString("key%1_modline%2_displaylinked").arg(keyInstance+1).arg(modlineInstance+1)).toBool());

    slotConnectElements();

    //---------- update hosted source streaming
    slotStreamSourceData();
    emit hosted_signalSetLEDMode(modlineInstance, modlineForm->ledgreen->currentText(), modlineForm->ledred->currentText());

    if(mode == "hosted")
    {
        //---------- Init Mode on Preset Change
        if(modlineForm->initmode->currentText() == "Once" && !initModeOnceCalled)
        {
            initModeOnceCalled = true;
            slotTransformSource(modlineForm->initvalue->value(), modlineInstance, "Init");
        }
        else if(modlineForm->initmode->currentText() == "Always")
        {
            //qDebug() << "send init always val" << modlineForm->initvalue->value();
            slotTransformSource(modlineForm->initvalue->value(), modlineInstance, "Init");
        }
    }
}

void Modline::slotDisableModline(QString parameterName)
{
    if(parameterName == QString("key%1_modline%2_enable").arg(keyInstance+1).arg(modlineInstance+1))
    {
        modlineForm->enable->setChecked(false);
        emit signalStoreValue(QString("key%1_modline%2_").arg(keyInstance+1).arg(modlineInstance+1) + "enable", false, -1);
        emit signalCheckSavedState();
        //qDebug() << "disable this parameter" << parameterName;
    }
}

void Modline::slotDeleteModline(int num, bool disable)
{
    //qDebug() << QString("slotDeleteModline called: %1 %2 %3").arg(modlineInstance).arg(num).arg(disable);
    if(modlineInstance == num - 1 && modlineInstance > 1)
    {
        modlineForm->enable->setChecked(disable);
        emit signalStoreValue(QString("key%1_modline%2_").arg(keyInstance+1).arg(modlineInstance+1) + "enable", false, -1);
        emit signalCheckSavedState();
    }
}



void Modline::slotRecallDestinationMenu()
{
    //qDebug() << "Modline::slotRecallDestinationMenu called";
    //set the device view to change based on what is selected in the destination menu

    modDest.index = modlineForm->destination->currentIndex();

    // first hide all elements...

    // input ui
    modlineForm->dest_b1->hide();
    modlineForm->dest_b2->hide();
    modlineForm->dest_b3->hide();
    modlineForm->dest_device->hide();
    modlineForm->dest_mmcfunction->hide();
    modlineForm->dest_oscroute->hide();

    // labels
    modlineForm->dest_label_b1->hide();
    modlineForm->dest_label_b2->hide();
    modlineForm->dest_label_b3->hide();
    modlineForm->dest_label_func->hide();
    modlineForm->dest_label_port->hide();

    // ...then individually show and update them as needed
    switch (modDest.index)
    {
    case DEST_NOTE_SET:
        modlineForm->dest_b1->show();
        modlineForm->dest_label_b1->show();

        modlineForm->dest_b1->setValue(modDest.note);
    case DEST_NOTE_LIVE:
        modlineForm->dest_b2->show();
        modlineForm->dest_label_b2->show();
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b2->setValue(modDest.velocity);
        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_CC:
        modlineForm->dest_b2->show();
        modlineForm->dest_label_b2->show();
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b2->setValue(modDest.cc);
        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_BANK:
        modlineForm->dest_b2->show();
        modlineForm->dest_label_b2->show();
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b2->setValue(modDest.bankMSB);
        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_PROGRAM:
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_OSC:
        break;
    case DEST_PITCH_BEND:
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_MMC:
        modlineForm->dest_b1->show();
        modlineForm->dest_label_b1->show();

        modlineForm->dest_b1->setValue(modDest.mmcID);
        break;
    case DEST_AFTERTOUCH:
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_POLY_AFTERTOUCH:
        modlineForm->dest_b2->show();
        modlineForm->dest_label_b2->show();
        modlineForm->dest_b3->show();
        modlineForm->dest_label_b3->show();

        modlineForm->dest_b2->setValue(modDest.note);
        modlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_X_INC:
    case DEST_Y_INC:
    case DEST_NONE:
    default:
        break;
    }
}

void Modline::slotTestValues(int value)
{
    slotTransformSource(value, modlineInstance, "Init");
}

void Modline::slotSetMode(QString m)
{
    mode = m;

    if(mode == "hosted")
    {
        modlineForm->initmode->setEnabled(true);
        modlineForm->initvalue->setEnabled(true);
        modlineForm->delay->setEnabled(true);
        modlineForm->raw->setEnabled(true);
        modlineForm->result->setEnabled(true);
        modlineForm->outputvalue->setEnabled(true);
        modlineForm->delay->setEnabled(true);
    }
    else
    {
        modlineForm->initmode->setEnabled(false);
        modlineForm->initvalue->setEnabled(false);
        modlineForm->delay->setEnabled(false);
        modlineForm->raw->setEnabled(false);
        modlineForm->result->setEnabled(false);
        modlineForm->outputvalue->setEnabled(false);
        modlineForm->delay->setEnabled(false);
    }
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

void Modline::hosted_slotPopulateDeviceMenu(QMap<QString, int> externalDevices)
{
    //-------------------------------- Clear all device menus
    // EB TODO - update to use a single dropdown
    //Note Set

//    modlineForm->notedevice->clear();

//    //Note Live
//    modlineForm->notelivedevice->clear();

//    //CC
//    modlineForm->controldevice->clear();

//    //Bank
//    modlineForm->bankdevice->clear();

//    //Program
//    modlineForm->programdevice->clear();

//    //Pitch Bend
//    modlineForm->benddevice->clear();

//    //MMC
//    modlineForm->mmcdevice->clear();

//    //Aftertouch
//    modlineForm->aftertouchdevice->clear();

//    //Poly Aftertouch
//    modlineForm->polydevice->clear();

    modlineForm->dest_device->clear();

    //-------------------------------- Populate all menus
    QMap<QString, int>::iterator i;
    for (i = externalDevices.begin(); i != externalDevices.end(); ++i)
    {
        modlineForm->dest_device->addItem(i.key().left(25));
//        //Note Set
//        modlineForm->notedevice->addItem(i.key().left(25));

//        //Note Live
//        modlineForm->notelivedevice->addItem(i.key().left(25));

//        //CC
//        modlineForm->controldevice->addItem(i.key().left(25));

//        //Bank
//        modlineForm->bankdevice->addItem(i.key().left(25));

//        //Program
//        modlineForm->programdevice->addItem(i.key().left(25));

//        //Pitch Bend
//        modlineForm->benddevice->addItem(i.key().left(25));

//        //MMC
//        modlineForm->mmcdevice->addItem(i.key().left(25));

//        //Aftertouch
//        modlineForm->aftertouchdevice->addItem(i.key().left(25));

//        //Poly Aftertouch
//        modlineForm->polydevice->addItem(i.key().left(25));
    }


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////    Hosted   ///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Modline::slotStreamSourceData()
{

    //qDebug() << modlineForm->source->currentText() << mode;
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
    enabled = modlineForm->enable->isChecked();
    gain = modlineForm->gain->value();
    offset = modlineForm->offset->value();

    //Set table array here later
    table = modlineForm->table->currentText();

    min = modlineForm->min->value();
    max = modlineForm->max->value();
    smooth = modlineForm->slew->value();
    delay = modlineForm->delay->value();
    delayer.delayTime = delay;

    outputType = modlineForm->destination->currentText();
    thisModlineSource = modlineForm->source->currentText();

    //qDebug() << "modline: " << modlineInstance << gain << offset << table << min << max << smooth << delay;
}

//------------------------------------------------------------------------------------------- Gain / Offset
void Modline::slotTransformSource(int val, int modlineNum, QString source)
{
    //qDebug() << "Modline::slotTransformSource called - key: " << keyInstance << " modLineNum: " << modlineNum << " source: " << source;

//    if(QObject::sender())
//    {
//        qDebug() << "slotTransformSource - sender: " << QObject::sender()->objectName();
//    }

    if(source == "Init")
    {
        //Set raw display value
        raw = val;

        //Display Raw
        modlineForm->raw->setValue(val);

        //Apply gain and offset
        val = val*gain + offset;

        //Set result display vaule
        result = val;

        //Display Result
        modlineForm->result->setValue(result);

        if(enabled)
        {
            //Go to slotTable, signal continues from there
            slotTable(val);
        }

        //qDebug() << "key" << keyInstance << "init val" << val;
    }
    else
    {
        newSource = source;

        //Make sure this is the correct modline to receive source being emitted
        if((modlineNum == modlineInstance && source == thisModlineSource) || source == "Init")
        {
            //If source value is different from last or there is a change in value...
            if(lastVal != val || lastSource != source || source.contains("Trig") || source.contains("Key"))
            {
                //Filter out repititions
                lastVal = val;
                lastSource = source;

                //Set raw display value
                raw = val;

                //Display Raw
                modlineForm->raw->setValue(val);

                //Apply gain and offset
                val = val*gain + offset;

                //Set result display vaule
                result = val;

                //Display Result
                modlineForm->result->setValue(result);

                if(enabled)
                {
                    //Go to slotTable, signal continues from there
                    slotTable(val);
                }
            }
        }
    }

}

//------------------------------------------------------------------------------------------- Table / Counter
void Modline::slotTable(int input)
{
    //qDebug() << "Modline::slotTable called";
    //Clip table input
    if(input > 127)
    {
        input = 127;
    }

    if(input < 0)
    {
        input = 0;
    }

    if(table == "Counter Inc")
    {
        //qDebug() << "last val: " << lastVal << "input: " << input;

        //If input is positive and gate is open
        if(input && counterGate)
        {
            counterGate = false; //Close gate
            emit hosted_signalCounter("Inc", -1);
        }

        //If input goes false, repopen the gate
        else if(!input)
        {
            //qDebug() << "set toggle gate true";
            counterGate = true;
        }

        return;
    }
    else if(table == "Counter Dec")
    {
        //If input is positive and gate is open
        if(input && counterGate)
        {
            counterGate = false; //Close gate
            emit hosted_signalCounter("Dec", -1);
            return;
        }

        //If input goes false, repopen the gate
        else if(!input)
        {
            //qDebug() << "set toggle gate true";
            counterGate = true;
        }

        return;
    }
    else if(table == "Counter Set")
    {
        emit hosted_signalCounter("Set", input);
        return;
    }
    else if(table == "Toggle")
    {
        //qDebug() << "toggle called" << input << lastVal;

        //If input is positive and gate is open
        if(input && tableToggleGate)
        {
            tableToggleGate = false; //Close gate

            //false to true transition, so flip toggle state
            toggleTable = !toggleTable;

            //Output according to
            if(toggleTable)
            {
                input = 127;
            }
            else
            {
                input = 0;
            }

            //Store toggle state here
            emit hosted_signalStoreToggleState(modlineInstance, toggleTable);
        }

        //If input goes false, repopen the gate
        else if(!input)
        {
            //qDebug() << "set toggle gate true";
            tableToggleGate = true;
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        input = tablesClass.tableMap.value(table)[input];
    }

    slotMinMax(input);
}

void Modline::slotCounterReturn(int val)
{
    //qDebug() << "Modline::slotCounterReturn called";
    if(modlineForm->table->currentText().contains("Counter"))
    {
        if(modlineForm->table->currentText().contains("Set"))
        {
            //Only display counter val
            value = val;
            slotDisplayVars();
            //lastVal = val;
            //lastSource = newSource;
            return;
        }
        else
        {
            slotMinMax(val);
        }

        //qDebug() << "key: " << keyInstance  << "modline: " << modlineInstance << "val: " << val;
    }
}

//------------------------------------------------------------------------------------------- Min / Max
void Modline::slotMinMax(int input)
{
    //qDebug() << "Modline::slotMinMax called";
    //If min max are flipped... Don't know... return input for now
    if(min > max)
    {
        //return input;
    }

    //If they're equal or max is greater than min
    else
    {
        if(input < min)
        {
            input = min;
        }
        else if(input > max)
        {
            input = max;
        }
     }

    slotSmooth(input);
}

//------------------------------------------------------------------------------------------- Smooth
void Modline::slotSmooth(int input)
{
    //qDebug() << "Modline::slotSmooth called";
    if(smooth)
    {
        //do something with slewer here and retun in slotSmoothReturn
        slewer.slotSlew(input, smooth);
        return;
    }
    else
    {
        slotDelay(input);
    }

}

void Modline::slotSmoothReturn(int input)
{
    //qDebug() << "slew return" << input;

    slotDelay(input);
}

//------------------------------------------------------------------------------------------- Delay
void Modline::slotDelay(int input)
{
    //qDebug() << "Modline::slotDelay called";

    if(delay)
    {
        //Do something with latcher, or delay here
        delayer.slotInputToDealy(input);
        return;
    }
    else
    {
        slotOutputRoutine(input);
    }
}

void Modline::slotDelayReturn(int input)
{
    //qDebug() << "delayed signal" << input;
    slotOutputRoutine(input);
}

//------------------------------------------------------------------------------------------- Output
void Modline::slotOutputRoutine(int input)
{
    //qDebug() << "Modline::slotOutputRoutine called";

    //Prepares message type to be formatted by midiformat, and then output via mididevicemanager
    hosted_slotOutputMidi(input);


    //Set value for display
    value = input;

    //Send modline output to dataCooker for Modline # Sources, also used for key alpha and led display
    emit hosted_signalSendModlineOutput(modlineInstance, input);

    //If line is display linked, send param it to alphanum
    if(displayLinkButton->isChecked())
    {
        emit hosted_signalSendParamDisplayOutput(modlineInstance, input);
    }

    //Update graphics onl3y after outupt
    slotDisplayVars();
}

void Modline::hosted_slotOutputMidi(int outputVal)
{
    // EB TODO - update to use a single set of dropdowns
    //qDebug() << "Modline::hosted_slotOutputMidi called";
    if(outputType == "Note Set")
    {
        if(outputVal)
        {
            emit hosted_signalNoteSet(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), modlineForm->dest_b1->value(), modlineForm->dest_b2->value());
        }
        else
        {
            emit hosted_signalNoteSet(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), modlineForm->dest_b1->value(), 0);
        }
    }
    else if(outputType == "Note Live")
    {
        emit hosted_signalNoteLive(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), lastNote, outputVal, modlineForm->dest_b2->value());

        lastNote = outputVal;
    }
    else if(outputType == "CC")
    {
        emit hosted_signalCC(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), modlineForm->dest_b2->value(), outputVal);
    }
    else if(outputType == "Bank")
    {
        emit hosted_signalBank(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), modlineForm->dest_b2->value(), outputVal);
    }
    else if(outputType == "Program")
    {
        emit hosted_signalProgram(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), outputVal);
    }
    else if(outputType == "Pitch Bend")
    {
        emit hosted_signalPitchBend(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), 0, outputVal);
    }
    else if(outputType == "MMC")
    {
        toggleOnMMC = false;

        if(outputVal && !toggleOnMMC)
        {
            emit hosted_signalMMC(modlineForm->dest_device->currentText(), modlineForm->dest_b1->value(), modlineForm->dest_mmcfunction->currentText());
            toggleOnMMC = true;
        }
        else if(!outputVal)
        {
            toggleOnMMC = false;
        }
    }
    else if(outputType == "OSC")
    {
        emit hosted_signalOSC(modlineForm->dest_oscroute->text(), outputVal);
    }
    else if(outputType == "Aftertouch")
    {
        emit hosted_signalAftertouch(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), outputVal);
    }
    else if(outputType == "Poly Aftertouch")
    {
        emit hosted_signalPolyAftertouch(modlineForm->dest_device->currentText(), modlineForm->dest_b3->value(), modlineForm->dest_b2->value(), outputVal);
    }
    else if(outputType == "GarageBand")
    {

    }
    else if(outputType == "HUI")
    {

    }
    else if(outputType == "Y Inc Set")
    {
        emit hosted_signalYIncSet(outputVal);
    }
    else if(outputType == "X Inc Set")
    {
        emit hosted_signalXIncSet(outputVal);
    }
}

void Modline::slotDisplayVars()
{
    modlineForm->outputvalue->setValue(value);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// State Recall /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Modline::slotStateRecallToggle(int modlineNum, bool state)
{
    if(modlineNum == modlineInstance)
    {
        toggleTable = state;
    }
}
