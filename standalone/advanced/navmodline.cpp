// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navmodline.h"

//constants for various modline arrangement parameters
#define MODLINE_WINDOW_WIDTH 967
#define MODLINE_WINDOW_HEIGHT 42
#define MODLINE_SPACING 5
#define MODLINE_STARTING_X_POS 9
#define MODLINE_STARTING_Y_POS 98

NavModline::NavModline(QWidget *parent, int navInstanceNum) :
    QWidget(parent),
    formWidget(new QWidget(this)),
    navModlineForm(new Ui::navModlineForm)
{
    navInstance = navInstanceNum;

    lastSource = "None";
    lastVal = -1;
    output = -1;

    firstCall = true;

    lastNote = -1;
    toggleOnMMC = false;

    //---------------- Set up Ui
    navModlineForm->setupUi(formWidget);
    this->setFixedSize(MODLINE_WINDOW_WIDTH,MODLINE_WINDOW_HEIGHT);
    this->setGeometry(MODLINE_STARTING_X_POS, MODLINE_STARTING_Y_POS + ((navInstance)*(MODLINE_WINDOW_HEIGHT + MODLINE_SPACING)), MODLINE_WINDOW_WIDTH, MODLINE_WINDOW_HEIGHT);

    navModlineForm->instanceLabel->setText(QString("%1").arg((navInstance +1)%10));
    navModlineForm->deviceViews->setCurrentIndex(0);
    navModlineForm->deviceViewLabels->setCurrentIndex(0);
    navModlineForm->raw->setValue(0);

    //dynamically set the stylesheet for the "enable" checkbox
    navModlineForm->enable->setStyleSheet(stylesheets.modlineEnableStyleSheet.at(navInstance));

    displayLinkButton = navModlineForm->modlinedisplayenable;

    raw = 0;
    result = 0;
    value = 0;
}

void NavModline::slotConnectElements()
{
    foreach(QWidget* widget, formWidget->findChildren<QWidget *>())
    {
        //check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
            QSpinBox* spinbox = qobject_cast<QSpinBox *>(widget);

            QString spinName = spinbox->objectName();

            if(spinName.contains("initvalue"))  //initvalue only exists in hosted mode
            {
                if(mode == "hosted")
                {
                    connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
                }
            }
            else if((!spinName.contains("raw")) &&
                    (!spinName.contains("result")) &&
                    (!spinName.contains("outputValue"))) //these parameters should not be saved in presets
            {
                connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
            }
        }
        else if(widget->metaObject()->className() == QString("QDoubleSpinBox"))
        {
            QDoubleSpinBox* doublespinbox = qobject_cast<QDoubleSpinBox *>(widget);
            connect(doublespinbox, SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QCheckBox"))
        {
            QCheckBox* checkbox = qobject_cast<QCheckBox *>(widget);
            connect(checkbox, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QComboBox"))
        {
            QComboBox* combobox = qobject_cast<QComboBox *>(widget);
            QString comboName = combobox->objectName();

            if(comboName == "initmode") //initmode only exists in hosted mode
            {
                if(mode == "hosted")
                {
                    connect(combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));
                }
            }
            else
            {
                connect(combobox, SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
            }
        }
        else if(widget->metaObject()->className() == QString("QLineEdit"))
        {
            QLineEdit* lineedit = qobject_cast<QLineEdit *>(widget);
            connect(lineedit, SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QRadioButton"))
        {
            QRadioButton* radiobutton = qobject_cast<QRadioButton *>(widget);
            connect(radiobutton, SIGNAL(toggled(bool)), this, SLOT(slotValueChanged()));
        }
    }

    //connect and initialize the raw value to the result (not for presets)
    //connect(navModlineForm->raw,SIGNAL(valueChanged(int)),this,SLOT(slotRawResult()));
    //connect(navModlineForm->gain,SIGNAL(valueChanged(double)),this,SLOT(slotRawResult()));
    //connect(navModlineForm->offset,SIGNAL(valueChanged(int)),this,SLOT(slotRawResult()));

    //-------------------- Hosted
    //slewer
    connect(&slewer, SIGNAL(signalOutput(int)), this, SLOT(slotSmoothReturn(int)));

    //delay
    connect(&delayer, SIGNAL(signalDelayedOutput(int)), this, SLOT(slotDelayReturn(int)));
}

void NavModline::slotDisconnectElements()
{
    foreach(QWidget* widget, formWidget->findChildren<QWidget *>())
    {
        //check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
            QSpinBox* spinbox = qobject_cast<QSpinBox *>(widget);

            QString spinName = spinbox->objectName();

            if(spinName.contains("initvalue")) //initvalue only exists in hosted mode
            {
                if(mode == "hosted")
                {
                    disconnect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
                }
            }
            else if((!spinName.contains("raw")) &&
                    (!spinName.contains("result")) &&
                    (!spinName.contains("outputValue"))) //these parameters should not be saved in presets
            {
                disconnect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
            }
        }
        else if(widget->metaObject()->className() == QString("QDoubleSpinBox"))
        {
            QDoubleSpinBox* doublespinbox = qobject_cast<QDoubleSpinBox *>(widget);
            disconnect(doublespinbox, SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QCheckBox"))
        {
            QCheckBox* checkbox = qobject_cast<QCheckBox *>(widget);
            disconnect(checkbox, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QComboBox"))
        {
            QComboBox* combobox = qobject_cast<QComboBox *>(widget);
            QString comboName = combobox->objectName();

            if(comboName == "initvalue") //initvalue only exists in hosted mode
            {
                if(mode == "hosted")
                {
                    disconnect(combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));
                }
            }
            else
            {
                disconnect(combobox, SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
            }
        }
        else if(widget->metaObject()->className() == QString("QLineEdit"))
        {
            QLineEdit* lineedit = qobject_cast<QLineEdit *>(widget);
            disconnect(lineedit, SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QRadioButton"))
        {
            QRadioButton* radiobutton = qobject_cast<QRadioButton *>(widget);
            disconnect(radiobutton, SIGNAL(toggled(bool)), this, SLOT(slotValueChanged()));
        }
    }

    //-------------------- Hosted
    //slewer
    disconnect(&slewer, SIGNAL(signalOutput(int)), this, SLOT(slotSmoothReturn(int)));

    //delay
    disconnect(&delayer, SIGNAL(signalDelayedOutput(int)), this, SLOT(slotDelayReturn(int)));
}

void NavModline::slotValueChanged()
{
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;

        //enable checkbox
        if(sender == navModlineForm->enable)
        {
            jsonName = "enable";
            value = navModlineForm->enable->isChecked();
        }
        //initMode
        else if(sender == navModlineForm->initmode)
        {
            jsonName = "initmode";
            value = navModlineForm->initmode->currentText();
        }
        //initValue
        else if(sender == navModlineForm->initvalue)
        {
            jsonName = "initvalue";
            value = navModlineForm->initvalue->value();
        }
        //Source Menu
        else if(sender == navModlineForm->source)
        {
            jsonName = "source";
            value = navModlineForm->source->currentText();
        }
        //Gain
        else if(sender == navModlineForm->gain)
        {
            jsonName = "gain";
            value = navModlineForm->gain->value();
        }
        //Offset
        else if(sender == navModlineForm->offset)
        {
            jsonName = "offset";
            value = navModlineForm->offset->value();
        }
        //Table Menu
        else if(sender == navModlineForm->table)
        {
            jsonName = "table";
            value = navModlineForm->table->currentText();
        }
        //Min
        else if(sender == navModlineForm->min)
        {
            jsonName = "min";
            value = navModlineForm->min->value();
        }
        //Max
        else if(sender == navModlineForm->max)
        {
            jsonName = "max";
            value = navModlineForm->max->value();
        }
        //slew
        else if(sender == navModlineForm->slew)
        {
            jsonName = "slew";
            value = navModlineForm->slew->value();
        }
        //delay
        else if(sender == navModlineForm->delay)
        {
            jsonName = "delay";
            value = navModlineForm->delay->value();
        }
        //Destination Menu
        else if(sender == navModlineForm->destination)
        {
            slotRecallDestinationMenu();

            jsonName = "destination";
            value = navModlineForm->destination->currentText();
        }
        //destination parameters
        else if(sender == navModlineForm->notenumber)
        {
            jsonName = "note";
            value = navModlineForm->notenumber->value();
        }
        else if(sender == navModlineForm->notevelocity)
        {
            jsonName = "velocity";
            value = navModlineForm->notevelocity->value();
        }
        else if(sender == navModlineForm->notelivevelocity)
        {
            jsonName = "velocity";
            value = navModlineForm->notelivevelocity->value();
        }
        else if(sender == navModlineForm->cc)
        {
            jsonName = "cc";
            value = navModlineForm->cc->value();
        }
        else if(sender == navModlineForm->bankmsb)
        {
            jsonName = "bankMSB";
            value = navModlineForm->bankmsb->value();
        }
        else if(sender == navModlineForm->polynote)
        {
            jsonName = "note";
            value = navModlineForm->polynote->value();
        }
        //channels
        else if(sender == navModlineForm->notechannel)
        {
            jsonName = "channel";
            value = navModlineForm->notechannel->value();
        }
        else if(sender == navModlineForm->notelivechannel)
        {
            jsonName = "channel";
            value = navModlineForm->notelivechannel->value();
        }
        else if(sender == navModlineForm->controlchannel)
        {
            jsonName = "channel";
            value = navModlineForm->controlchannel->value();
        }
        else if(sender == navModlineForm->bankchannel)
        {
            jsonName = "channel";
            value = navModlineForm->bankchannel->value();
        }
        else if(sender == navModlineForm->programchannel)
        {
            jsonName = "channel";
            value = navModlineForm->programchannel->value();
        }
        else if(sender == navModlineForm->bendchannel)
        {
            jsonName = "channel";
            value = navModlineForm->bendchannel->value();
        }
        else if(sender == navModlineForm->aftertouchchannel)
        {
            jsonName = "channel";
            value = navModlineForm->aftertouchchannel->value();
        }
        else if(sender == navModlineForm->polychannel)
        {
            jsonName = "channel";
            value = navModlineForm->polychannel->value();
        }
        //devices
        else if(sender == navModlineForm->notedevice)
        {
            jsonName = "device";
            value = navModlineForm->notedevice->currentText();
        }
        else if(sender == navModlineForm->notelivedevice)
        {
            jsonName = "device";
            value = navModlineForm->notelivedevice->currentText();
        }
        else if(sender == navModlineForm->controldevice)
        {
            jsonName = "device";
            value = navModlineForm->controldevice->currentText();
        }
        else if(sender == navModlineForm->bankdevice)
        {
            jsonName = "device";
            value = navModlineForm->bankdevice->currentText();
        }
        else if(sender == navModlineForm->programdevice)
        {
            jsonName = "device";
            value = navModlineForm->programdevice->currentText();
        }
        else if(sender == navModlineForm->benddevice)
        {
            jsonName = "device";
            value = navModlineForm->benddevice->currentText();
        }
        else if(sender == navModlineForm->aftertouchdevice)
        {
            jsonName = "device";
            value = navModlineForm->aftertouchdevice->currentText();
        }
        else if(sender == navModlineForm->polydevice)
        {
            jsonName = "device";
            value = navModlineForm->polydevice->currentText();
        }
        else if(sender == navModlineForm->mmcdeviceid)
        {
            jsonName = "mmcid";
            value = navModlineForm->mmcdeviceid->value();
        }
        else if(sender == navModlineForm->mmcfunction)
        {
            jsonName = "mmcfunction";
            value = navModlineForm->mmcfunction->currentText();
        }
        else if(sender == navModlineForm->mmcdevice)
        {
            jsonName = "device";
            value = navModlineForm->mmcdevice->currentText();
        }
        else if(sender == navModlineForm->oscroute)
        {
            jsonName = "oscroute";
            value = navModlineForm->oscroute->text();
        }
        else if(sender == navModlineForm->modlinedisplayenable)
        {
            jsonName = "displaylinked";
            value = navModlineForm->modlinedisplayenable->isChecked();
        }
        emit signalStoreValue(QString("nav_modline%1_").arg(navInstance+1) + jsonName, value, -1);
    }

    emit signalCheckSavedState();

    //---------- update hosted source streaming
    slotStreamSourceData();
}

void NavModline::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();

    //basic modline parameters
    navModlineForm->enable->setChecked(preset.value(QString("nav_modline%1_enable").arg(navInstance+1)).toBool());
    navModlineForm->initvalue->setValue(preset.value(QString("nav_modline%1_initvalue").arg(navInstance+1)).toInt());
    navModlineForm->initmode->setCurrentIndex(navModlineForm->initmode->findText(preset.value(QString("nav_modline%1_initmode").arg(navInstance+1)).toString()));
    navModlineForm->source->setCurrentIndex(navModlineForm->source->findText(preset.value(QString("nav_modline%1_source").arg(navInstance+1)).toString()));
    navModlineForm->gain->setValue(preset.value(QString("nav_modline%1_gain").arg(navInstance+1)).toDouble());
    navModlineForm->offset->setValue(preset.value(QString("nav_modline%1_offset").arg(navInstance+1)).toInt());
    navModlineForm->table->setCurrentIndex(navModlineForm->table->findText(preset.value(QString("nav_modline%1_table").arg(navInstance+1)).toString()));
    navModlineForm->min->setValue(preset.value(QString("nav_modline%1_min").arg(navInstance+1)).toInt());
    navModlineForm->max->setValue(preset.value(QString("nav_modline%1_max").arg(navInstance+1)).toInt());
    navModlineForm->slew->setValue(preset.value(QString("nav_modline%1_slew").arg(navInstance+1)).toInt());
    navModlineForm->delay->setValue(preset.value(QString("nav_modline%1_delay").arg(navInstance+1)).toInt());
    navModlineForm->destination->setCurrentIndex(navModlineForm->destination->findText(preset.value(QString("nav_modline%1_destination").arg(navInstance+1)).toString()));

    //destination parameters
    navModlineForm->notenumber->setValue(preset.value(QString("nav_modline%1_note").arg(navInstance+1)).toInt());
    navModlineForm->polynote->setValue(preset.value(QString("nav_modline%1_note").arg(navInstance+1)).toInt());

    navModlineForm->notevelocity->setValue(preset.value(QString("nav_modline%1_velocity").arg(navInstance+1)).toInt());
    navModlineForm->notelivevelocity->setValue(preset.value(QString("nav_modline%1_velocity").arg(navInstance+1)).toInt());
    navModlineForm->cc->setValue(preset.value(QString("nav_modline%1_cc").arg(navInstance+1)).toInt());
    navModlineForm->bankmsb->setValue(preset.value(QString("nav_modline%1_bankmsb").arg(navInstance+1)).toInt());

    navModlineForm->notechannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->notelivechannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->controlchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->bankchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->programchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->bendchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->aftertouchchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
    navModlineForm->polychannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());

    navModlineForm->notedevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->notelivedevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->controldevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->bankdevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->programdevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->benddevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->aftertouchdevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));
    navModlineForm->polydevice->setCurrentIndex(navModlineForm->notedevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));

    navModlineForm->mmcdeviceid->setValue(preset.value(QString("nav_modline%1_mmcid").arg(navInstance+1)).toInt());
    navModlineForm->mmcfunction->setCurrentIndex(navModlineForm->mmcfunction->findText(preset.value(QString("nav_modline%1_mmcfunction").arg(navInstance+1)).toString()));
    navModlineForm->mmcdevice->setCurrentIndex(navModlineForm->mmcdevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));

    navModlineForm->oscroute->setText(preset.value(QString("nav_modline%1_oscroute").arg(navInstance+1)).toString());

    navModlineForm->modlinedisplayenable->setChecked(preset.value(QString("nav_modline%1_displaylinked").arg(navInstance+1)).toBool());
    slotRecallDestinationMenu();
    slotConnectElements();

    //--------------- update hosted source streaming
    slotStreamSourceData();

    if(mode == "hosted")
    {
        //---------- Init Mode on Preset Change
        if(navModlineForm->initmode->currentText() == "Once" && !initModeOnceCalled)
        {
            initModeOnceCalled = true;
            slotTransformSource(navModlineForm->initvalue->value(), navInstance, "Init");
        }
        else if(navModlineForm->initmode->currentText() == "Always")
        {
            qDebug() << "send init always val" << navModlineForm->initvalue->value();
            slotTransformSource(navModlineForm->initvalue->value(), navInstance, "Init");
        }
    }
}

void NavModline::slotRawResult()
{
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        //raw-result (not sent to presets)
        if(sender == navModlineForm->raw || sender == navModlineForm->gain || sender == navModlineForm->offset)
        {
            navModlineForm->result->setValue((navModlineForm->raw->value())*(navModlineForm->gain->value())+(navModlineForm->offset->value()));
        }
    }

    //qDebug() << "initialize result value";
}

void NavModline::slotRecallDestinationMenu()
{
    //set the device view to change based on what is selected in the destination menu
    if((navModlineForm->destination->currentIndex()) > 10)
    {
        navModlineForm->deviceViews->setCurrentIndex(0);
        navModlineForm->deviceViewLabels->setCurrentIndex(0);
    }
    else
    {
        navModlineForm->deviceViews->setCurrentIndex(navModlineForm->destination->currentIndex());
        navModlineForm->deviceViewLabels->setCurrentIndex(navModlineForm->destination->currentIndex());
    }
}

void NavModline::slotSetMode(QString m)
{
    mode = m;

    if(mode == "hosted")
    {
        navModlineForm->initmode->setEnabled(true);
        navModlineForm->initvalue->setEnabled(true);
        navModlineForm->delay->setEnabled(true);
    }
    else
    {
        navModlineForm->initmode->setEnabled(false);
        navModlineForm->initvalue->setEnabled(false);
        navModlineForm->delay->setEnabled(false);
    }
}

void NavModline::slotPopulateMenus(QStringList source, QStringList dest, QStringList table)
{
    //set source menu
    navModlineForm->source->clear();
    navModlineForm->source->addItems(source);

    //set table menu
    navModlineForm->table->clear();
    navModlineForm->table->addItems(table);

    //set destination menus
    navModlineForm->destination->clear();
    navModlineForm->destination->addItems(dest);
}

void NavModline::hosted_slotPopulateDeviceMenu(QMap<QString, MIDIEndpointRef> externalDevices)
{
    //------------------------------- Clear all device menus

    //Note Set
    navModlineForm->notedevice->clear();

    //Note Live
    navModlineForm->notelivedevice->clear();

    //CC
    navModlineForm->controldevice->clear();

    //Bank
    navModlineForm->bankdevice->clear();

    //Program
    navModlineForm->programdevice->clear();

    //Pitch Bend
    navModlineForm->benddevice->clear();

    //MMC
    navModlineForm->mmcdevice->clear();

    //Aftertouch
    navModlineForm->aftertouchdevice->clear();

    //Poly Aftertouch
    navModlineForm->polydevice->clear();

    //-------------------------------- Populate all menus
    QMap<QString, MIDIEndpointRef>::iterator i;
    for (i = externalDevices.begin(); i != externalDevices.end(); ++i)
    {
        //Note Set
        navModlineForm->notedevice->addItem(i.key());

        //Note Live
        navModlineForm->notelivedevice->addItem(i.key());

        //CC
        navModlineForm->controldevice->addItem(i.key());

        //Bank
        navModlineForm->bankdevice->addItem(i.key());

        //Program
        navModlineForm->programdevice->addItem(i.key());

        //Pitch Bend
        navModlineForm->benddevice->addItem(i.key());

        //MMC
        navModlineForm->mmcdevice->addItem(i.key());

        //Aftertouch
        navModlineForm->aftertouchdevice->addItem(i.key());

        //Poly Aftertouch
        navModlineForm->polydevice->addItem(i.key());
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////    Hosted   ///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void NavModline::slotStreamSourceData()
{
    //--------------------- Hosted
    if(mode == "hosted")
    {
        //set instance modline/transform params
        slotSetTransformValues();

        //get source from key data cooker
        emit signalSetSource(navModlineForm->source->currentText(), navInstance);
    }
}

void NavModline::slotSetTransformValues()
{
    enabled = navModlineForm->enable->isChecked();
    gain = navModlineForm->gain->value();
    offset = navModlineForm->offset->value();

    //set table array here later
    table = navModlineForm->table->currentText();

    min = navModlineForm->min->value();
    max = navModlineForm->max->value();
    smooth = navModlineForm->slew->value();
    delay = navModlineForm->delay->value();
    delayer.delayTime = delay;

    outputType = navModlineForm->destination->currentText();
    thisModlineSource = navModlineForm->source->currentText();
}

void NavModline::slotTransformSource(int val, int modlineNum, QString source)
{
    if(source == "Init")
    {
        //Set raw display value
        raw = val;

        //Display Raw
        navModlineForm->raw->setValue(val);

        //Apply gain and offset
        val = val*gain + offset;

        //Set result display vaule
        result = val;

        //Display Result
        navModlineForm->result->setValue(result);

        if(enabled)
        {
            //Go to slotTable, signal continues from there
            slotTable(val);
        }
    }
    else
    {
        newSource = source;

        //Make sure this is the correct modline to receive source being emitted
        if(modlineNum == navInstance && source == thisModlineSource)
        {
            //If source value is different from last or there is a change in value...
            if(lastVal != val || lastSource != source || source.contains("Trig") || source.contains("Key"))
            {
                qDebug() << val << modlineNum << source;

                lastVal = val;
                lastSource = newSource;

                //set raw display value
                raw = val;

                //display raw
                navModlineForm->raw->setValue(val);


                //apply gain and offset
                val = val*gain + offset;

                //set result display value
                result = val;

                //display result
                navModlineForm->result->setValue(result);

                if(enabled)
                {
                    //go to slotTable, signal continues from there
                    slotTable(val);
                }
            }
        }
    }
}

//--------------------------------------------------------- Table / Counter
void NavModline::slotTable(int input)
{
    //clip table input
    if(input > 127)
    {
        input = 127;
    }

    if(input < 0)
    {
        input = 0;
    }
    if(table == "Toggle")
    {
        //qDebug() << "toggle called" << input << lastVal;

        //If input is positive and gate is open
        if(input && tableToggleGate)
        {
            //qDebug() << "flip toggle" << toggleTable;

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

void NavModline::slotCounterReturn(int val)
{
    if(navModlineForm->table->currentText().contains("Counter"))
    {
        if(navModlineForm->table->currentText().contains("Set"))
        {
            //only display counter val
            value = val;
            slotDisplayVars();
            return;
        }
        else
        {
            slotMinMax(val);
        }
    }
}

//-------------------------------------------------------------- Min / Max
void NavModline::slotMinMax(int input)
{
    //if min max are flipped... don't know... return input for now
    if(min > max)
    {
        //return input;
    }
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
        else
        {
            input = input;
        }
    }
    slotSmooth(input);
}

//----------------------------------------------------------------- Smooth
void NavModline::slotSmooth(int input)
{
    if(smooth)
    {
        //do something with slewer here and retun in slotSmoothReturn
        slewer.slotSlew(input, smooth);
        lastVal = input;
        lastSource = newSource;
        return;
    }
    else
    {
        slotDelay(input);
    }

}

void NavModline::slotSmoothReturn(int input)
{
    qDebug() << "slew return" << input;

    slotDelay(input);
}

//-------------------------------------------------------------------- Delay
void NavModline::slotDelay(int input)
{

    if(delay)
    {
        qDebug() << "delay called" << delay << input;

        //Do something with latcher, or delay here
        delayer.slotInputToDealy(input);
        return;
    }
    else
    {
        slotOutputRoutine(input);
    }
}

void NavModline::slotDelayReturn(int input)
{
    qDebug() << "delayed signal" << input;
    slotOutputRoutine(input);
}

//-------------------------------------------------------------------- Output
void NavModline::slotOutputRoutine(int input)
{
    //Prepares message type to be formatted by midiformat, and then output via mididevicemanager
    hosted_slotOutputMidi(input);

    //Set value for display
    value = input;

    //Send modline output to dataCooker for Modline # Sources, also used for key alpha and led display
    //emit hosted_signalSendModlineOutput(navInstance, input);

    //If line is display linked, send param it to alphanum
    if(displayLinkButton->isChecked())
    {
        emit hosted_signalSendParamDisplayOutput(navInstance, input);
    }

    //Update graphics only after outupt
    slotDisplayVars();
}

void NavModline::hosted_slotOutputMidi(int outputVal)
{
    if(outputType == "Note Set")
    {
        if(outputVal)
        {
            emit hosted_signalNoteSet(navModlineForm->notedevice->currentText(), navModlineForm->notechannel->value(), navModlineForm->notenumber->value(), navModlineForm->notevelocity->value());
        }
        else
        {
            emit hosted_signalNoteSet(navModlineForm->notedevice->currentText(), navModlineForm->notechannel->value(), navModlineForm->notenumber->value(), 0);
        }
    }
    else if(outputType == "Note Live")
    {
        emit hosted_signalNoteLive(navModlineForm->notelivedevice->currentText(), navModlineForm->notelivechannel->value(), lastNote, outputVal, navModlineForm->notelivevelocity->value());

        lastNote = outputVal;
    }
    else if(outputType == "CC")
    {
        emit hosted_signalCC(navModlineForm->controldevice->currentText(), navModlineForm->controlchannel->value(), navModlineForm->cc->value(), outputVal);
    }
    else if(outputType == "Bank")
    {
        emit hosted_signalBank(navModlineForm->bankdevice->currentText(),  navModlineForm->bankchannel->value(), navModlineForm->bankmsb->value(), outputVal);
    }
    else if(outputType == "Program")
    {
        emit hosted_signalProgram(navModlineForm->programdevice->currentText(), navModlineForm->programchannel->value(), outputVal);
    }
    else if(outputType == "Pitch Bend")
    {
        emit hosted_signalPitchBend(navModlineForm->benddevice->currentText(), navModlineForm->bendchannel->value(), 0, outputVal);
    }
    else if(outputType == "MMC")
    {
        toggleOnMMC = false;

        if(outputVal && !toggleOnMMC)
        {
            emit hosted_signalMMC(navModlineForm->mmcdevice->currentText(), navModlineForm->mmcdeviceid->value(), navModlineForm->mmcfunction->currentText());
            toggleOnMMC = true;
        }
        else if(!outputVal)
        {
            toggleOnMMC = false;
        }
    }
    else if(outputType == "OSC")
    {

    }
    else if(outputType == "Aftertouch")
    {
        emit hosted_signalAftertouch(navModlineForm->aftertouchdevice->currentText(), navModlineForm->aftertouchchannel->value(), outputVal);
    }
    else if(outputType == "Poly Aftertouch")
    {
        emit hosted_signalPolyAftertouch(navModlineForm->polydevice->currentText(), navModlineForm->polychannel->value(), navModlineForm->polynote->value(), outputVal);
    }
    /*else if(outputType == "GarageBand")
    {

    }
    else if(outputType == "HUI")
    {

    }*/
    else if(outputType == "Y Inc Set")
    {
        emit hosted_signalYIncSet(outputVal);
    }
    else if(outputType == "X Inc Set")
    {
        emit hosted_signalXIncSet(outputVal);
    }
}

void NavModline::slotDisplayVars()
{
    qDebug() << "nav output value display" << value;
    navModlineForm->outputvalue->setValue(value);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// State Recall /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void NavModline::slotStateRecallToggle(int modlineNum, bool state)
{
    if(modlineNum == navInstance)
    {
        toggleTable = state;
    }
}
