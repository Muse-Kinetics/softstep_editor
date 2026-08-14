// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navmodline.h"
#include <QAbstractItemView>

namespace
{
// Resolve a saved output-port name from any era (SSCOM Port 1/2 on SoftStep 1/2,
// pre/post-1.0.0 firmware names, and SoftStep 3 names) to whichever equivalent
// port is actually present in the given combo. Used by both standalone and hosted
// preset loading so port routing survives hardware/firmware/name changes.
QString resolveSoftStepPortAlias(QComboBox *comboBox, const QString &presetDevice)
{
    const QString normalizedDevice = presetDevice.trimmed();
    if (normalizedDevice.isEmpty() || comboBox == nullptr)
    {
        return normalizedDevice;
    }

    if (comboBox->findText(normalizedDevice) != -1)
    {
        return normalizedDevice;
    }

    const bool isPrimaryPortAlias =
        normalizedDevice == "SoftStep Share" ||
        normalizedDevice == "SoftStep Control Surface" ||
        normalizedDevice == "SoftStep USB MIDI" ||
        normalizedDevice == "SSCOM Port 1" ||
        normalizedDevice == "SoftStep Hosted Virtual Port";

    const bool isSecondaryPortAlias =
        normalizedDevice == "SoftStep Expander" ||
        normalizedDevice == "SoftStep TRS MIDI Out" ||
        normalizedDevice == "SSCOM Port 2";

    auto findFirstAvailableAlias = [comboBox](const QStringList &aliases) -> QString
    {
        for (const QString &alias : aliases)
        {
            if (comboBox->findText(alias) != -1)
            {
                return alias;
            }
        }

        return QString();
    };

    if (isPrimaryPortAlias)
    {
        const QString resolvedAlias = findFirstAvailableAlias(
            {"SoftStep Share", "SoftStep Control Surface", "SoftStep USB MIDI", "SSCOM Port 1"});
        if (!resolvedAlias.isEmpty())
        {
            return resolvedAlias;
        }
    }

    if (isSecondaryPortAlias)
    {
        const QString resolvedAlias = findFirstAvailableAlias(
            {"SoftStep TRS MIDI Out", "SoftStep Expander", "SSCOM Port 2"});
        if (!resolvedAlias.isEmpty())
        {
            return resolvedAlias;
        }
    }

    if (normalizedDevice == "SoftStep CV Out")
    {
        const QString resolvedAlias = findFirstAvailableAlias({"SoftStep CV Out"});
        if (!resolvedAlias.isEmpty())
        {
            return resolvedAlias;
        }
    }

    return normalizedDevice;
}
}

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
//    navModlineForm->deviceViews->setCurrentIndex(0);
//    navModlineForm->deviceViewLabels->setCurrentIndex(0);
    navModlineForm->raw->setValue(0);

    //dynamically set the stylesheet for the "enable" checkbox
    navModlineForm->enable->setStyleSheet(stylesheets.modlineEnableStyleSheet.at(navInstance));

    displayLinkButton = navModlineForm->modlinedisplayenable;

    connect(navModlineForm->initvalue, SIGNAL(valueChanged(int)), this, SLOT(slotTestValues(int)));
    //connect(navModlineForm->raw, SIGNAL(valueChanged(int)), this, SLOT(slotTestValues(int)));
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
                    (!spinName.contains("outputvalue")) &&
                    (!spinName.contains("notelivenumber")) &&
                    (!spinName.contains("notelivevelocity"))) //these parameters should not be saved in presets
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

            int width = combobox->minimumSizeHint().width() + 35;
            width = (width > 150) ? 150 : width;

            combobox->view()->setMinimumWidth(width);
            combobox->view()->setMaximumWidth(150);

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

    //connect the velocity boxes to eachother
    //connect(navModlineForm->notevelocity, SIGNAL(valueChanged(int)), navModlineForm->notelivevelocity, SLOT(setValue(int)));
    //connect(navModlineForm->notelivevelocity, SIGNAL(valueChanged(int)), navModlineForm->notevelocity, SLOT(setValue(int)));

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
                    (!spinName.contains("outputvalue")) &&
                    (!spinName.contains("notelivenumber")) &&
                    (!spinName.contains("notelivevelocity"))) //these parameters should not be saved in presets
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
        QString senderName = sender->objectName();

        // handle destination menu objects
        if (senderName.contains("dest_"))
        {
            if(senderName == "dest_b1")
            {
                value = navModlineForm->dest_b1->value();

                // set jsonName based on destination/index
                switch (modDest.index)
                {
                case DEST_NOTE_SET:
                    jsonName = "note";
                    break;
                case DEST_NOTE_LIVE:
                    jsonName = "transpose";
                    break;
                case DEST_MMC:
                    jsonName = "mmcid";
                    break;
                }
            }
            else if(senderName == "dest_b2")
            {
                value = navModlineForm->dest_b2->value();

                // set jsonName based on destination/index
                switch (modDest.index)
                {
                case DEST_NOTE_LIVE:
                case DEST_NOTE_SET:
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
                value = navModlineForm->dest_b3->value();

                // set jsonName based on destination/index
                switch (modDest.index)
                {
                case DEST_NOTE_SET:
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
                value = navModlineForm->dest_device->currentText();
                jsonName = "device";

            }
            else if(senderName == "dest_mmcfunction")
            {
                value = navModlineForm->dest_mmcfunction->currentText();
                jsonName = "mmcfunction";

            }
            else if(senderName == "dest_oscroute")
            {
                jsonName = "oscroute";
                value = navModlineForm->dest_oscroute->text();
            }
            qDebug() << "destination menu - jsonName: " << jsonName << " value: " << value;
        }

        //enable checkbox
        else if(sender == navModlineForm->enable)
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
//        //destination parameters
//        else if(sender == navModlineForm->notenumber)
//        {
//            jsonName = "note";
//            value = navModlineForm->notenumber->value();
//        }
//        else if(sender == navModlineForm->notevelocity)
//        {
//            jsonName = "velocity";
//            value = navModlineForm->notevelocity->value();
//        }
//        else if(sender == navModlineForm->cc)
//        {
//            jsonName = "cc";
//            value = navModlineForm->cc->value();
//        }
//        else if(sender == navModlineForm->bankmsb)
//        {
//            jsonName = "bankMSB";
//            value = navModlineForm->bankmsb->value();
//        }
//        else if(sender == navModlineForm->polynote)
//        {
//            jsonName = "note";
//            value = navModlineForm->polynote->value();
//        }
//        //channels
//        else if(sender == navModlineForm->notechannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->notechannel->value();
//        }
//        else if(sender == navModlineForm->notelivechannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->notelivechannel->value();
//        }
//        else if(sender == navModlineForm->controlchannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->controlchannel->value();
//        }
//        else if(sender == navModlineForm->bankchannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->bankchannel->value();
//        }
//        else if(sender == navModlineForm->programchannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->programchannel->value();
//        }
//        else if(sender == navModlineForm->bendchannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->bendchannel->value();
//        }
//        else if(sender == navModlineForm->aftertouchchannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->aftertouchchannel->value();
//        }
//        else if(sender == navModlineForm->polychannel)
//        {
//            jsonName = "channel";
//            value = navModlineForm->polychannel->value();
//        }
//        //devices
//        else if(sender == navModlineForm->notedevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->notedevice->currentText();
//        }
//        else if(sender == navModlineForm->notelivedevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->notelivedevice->currentText();
//        }
//        else if(sender == navModlineForm->controldevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->controldevice->currentText();
//        }
//        else if(sender == navModlineForm->bankdevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->bankdevice->currentText();
//        }
//        else if(sender == navModlineForm->programdevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->programdevice->currentText();
//        }
//        else if(sender == navModlineForm->benddevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->benddevice->currentText();
//        }
//        else if(sender == navModlineForm->aftertouchdevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->aftertouchdevice->currentText();
//        }
//        else if(sender == navModlineForm->polydevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->polydevice->currentText();
//        }
//        else if(sender == navModlineForm->mmcdeviceid)
//        {
//            jsonName = "mmcid";
//            value = navModlineForm->mmcdeviceid->value();
//        }
//        else if(sender == navModlineForm->mmcfunction)
//        {
//            jsonName = "mmcfunction";
//            value = navModlineForm->mmcfunction->currentText();
//        }
//        else if(sender == navModlineForm->mmcdevice)
//        {
//            jsonName = "device";
//            value = navModlineForm->mmcdevice->currentText();
//        }
//        else if(sender == navModlineForm->oscroute)
//        {
//            jsonName = "oscroute";
//            value = navModlineForm->oscroute->text();
//        }
        else if(sender == navModlineForm->modlinedisplayenable)
        {
            jsonName = "displaylinked";
            value = navModlineForm->modlinedisplayenable->isChecked();
        }

        if (jsonName.isEmpty() || !value.isValid())
        {
            qDebug() << "******* ERROR *** nav jsonName:" << jsonName << "-- value:" << value << "sender:" << senderName;
            return;
        }

        emit signalStoreValue(QString("nav_modline%1_").arg(navInstance+1) + jsonName, value, -1);

        //----------- disable modline if necessary
        if(mode == "standalone" && jsonName == "enable" && value == true)
        {
            emit signalModlineEnabled(QString("nav_modline%1_enable").arg(navInstance+1));
        }
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
//    navModlineForm->notenumber->setValue(preset.value(QString("nav_modline%1_note").arg(navInstance+1)).toInt());
//    navModlineForm->polynote->setValue(preset.value(QString("nav_modline%1_note").arg(navInstance+1)).toInt());

//    navModlineForm->notevelocity->setValue(preset.value(QString("nav_modline%1_velocity").arg(navInstance+1)).toInt());
//    //navModlineForm->notelivevelocity->setValue(preset.value(QString("nav_modline%1_velocity").arg(navInstance+1)).toInt());
//    navModlineForm->cc->setValue(preset.value(QString("nav_modline%1_cc").arg(navInstance+1)).toInt());
//    navModlineForm->bankmsb->setValue(preset.value(QString("nav_modline%1_bankmsb").arg(navInstance+1)).toInt());

//    navModlineForm->notechannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->notelivechannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->controlchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->bankchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->programchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->bendchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->aftertouchchannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());
//    navModlineForm->polychannel->setValue(preset.value(QString("nav_modline%1_channel").arg(navInstance+1)).toInt());


    // modDest.index = modlineForm->destination->currentIndex(); // happens in slotRecallDestinationMenu()
    modDest.channel = preset.value(QString("nav_modline%2_channel").arg(navInstance+1)).toInt();
    modDest.note = preset.value(QString("nav_modline%2_note").arg(navInstance+1)).toInt();
    modDest.velocity = preset.value(QString("nav_modline%2_velocity").arg(navInstance+1)).toInt();
    modDest.transpose = preset.value(QString("nav_modline%2_transpose").arg(navInstance+1)).toInt();
    modDest.cc = preset.value(QString("nav_modline%2_cc").arg(navInstance+1)).toInt();
    modDest.bankMSB = preset.value(QString("nav_modline%2_bankmsb").arg(navInstance+1)).toInt();
    modDest.mmcID = preset.value(QString("nav_modline%2_mmcid").arg(navInstance+1)).toInt();
    modDest.mmcFunction = preset.value(QString("nav_modline%2_mmcfunction").arg(navInstance+1)).toString();
    modDest.oscRoute = preset.value(QString("nav_modline%2_oscroute").arg(navInstance+1)).toString();

    // MODLINE OUTPUT PORT

    // string and then the index of the combobox, whose items are updated by mainWindow

    // get the port name from the preset JSON
    QString presetDevice = preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString();

    if (mode == "standalone")
    {
        // Select the output port by NAME, not by a fixed combo index. The combo is
        // [None, <ports for the current hardware>], so any hard-coded index would be
        // wrong (this was the 3.0.7 regression: presets shifted to the wrong port /
        // "None"). Resolve any-era saved name to the equivalent port in the combo.
        const QString resolvedDevice = resolveSoftStepPortAlias(navModlineForm->dest_device, presetDevice);

        if (navModlineForm->dest_device->findText(resolvedDevice) != -1)
        {
            navModlineForm->dest_device->setCurrentText(resolvedDevice);

            // Normalize a legacy/aliased name to the current one so a later save
            // persists a valid port. Only when a real equivalent exists in the combo.
            if (resolvedDevice != presetDevice)
            {
                qDebug() << "Resolved standalone nav output alias:" << presetDevice << "->" << resolvedDevice
                         << "nav modline:" << navInstance;
                emit signalStoreValue(QString("nav_modline%1_device").arg(navInstance+1), resolvedDevice, -1);
                emit signalCheckSavedState();
            }
        }
        else
        {
            // Port isn't available for the current hardware view (e.g. CV Out while a
            // SoftStep 1/2 UI is shown). Show "None" but DON'T overwrite the JSON, so
            // the routing is restored when the matching hardware is reconnected.
            navModlineForm->dest_device->setCurrentText("None");
        }
    }
    else // hosted mode
    {
        if (presetDevice == "Microsoft GS Wavetable Synth")
        {
            qDebug() << "Sanitizing invalid hosted nav output device:" << presetDevice << "nav modline:" << navInstance;
            presetDevice = "None";
            emit signalStoreValue(QString("nav_modline%1_device").arg(navInstance+1), presetDevice, -1);
            emit signalCheckSavedState();
        }
        else
        {
            const QString resolvedDevice = resolveSoftStepPortAlias(navModlineForm->dest_device, presetDevice);
            if (resolvedDevice != presetDevice)
            {
                qDebug() << "Resolved hosted nav output alias:" << presetDevice << "->" << resolvedDevice
                         << "nav modline:" << navInstance;
                presetDevice = resolvedDevice;
            }
        }

        navModlineForm->dest_device->setCurrentText(presetDevice);
    }

    //storing these in a struct for later recall when we change the destination type/index
    //modDest.outPortName = presetDevice;

    // midi port dropdown - update this after we change the destination parameters above


    // mmc function dropdown
    navModlineForm->dest_mmcfunction->setCurrentText(modDest.mmcFunction);

    // osc text field
    navModlineForm->dest_oscroute->setText(modDest.oscRoute);

    // Updating values and showing/hiding the shared ui elements elements happens in slotRecallDestinationMenu();
    slotRecallDestinationMenu();

    // old method
//    navModlineForm->notedevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->notelivedevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->controldevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->bankdevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->programdevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->benddevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->aftertouchdevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));
//    navModlineForm->polydevice->setCurrentIndex(navModlineForm->notedevice->findText(presetDevice));

//    navModlineForm->mmcdeviceid->setValue(preset.value(QString("nav_modline%1_mmcid").arg(navInstance+1)).toInt());
//    navModlineForm->mmcfunction->setCurrentIndex(navModlineForm->mmcfunction->findText(preset.value(QString("nav_modline%1_mmcfunction").arg(navInstance+1)).toString()));
//    navModlineForm->mmcdevice->setCurrentIndex(navModlineForm->mmcdevice->findText(preset.value(QString("nav_modline%1_device").arg(navInstance+1)).toString()));

//    navModlineForm->oscroute->setText(preset.value(QString("nav_modline%1_oscroute").arg(navInstance+1)).toString());

    navModlineForm->modlinedisplayenable->setChecked(preset.value(QString("nav_modline%1_displaylinked").arg(navInstance+1)).toBool());

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
            //qDebug() << "send init always val" << navModlineForm->initvalue->value();
            slotTransformSource(navModlineForm->initvalue->value(), navInstance, "Init");
        }
    }
}

void NavModline::slotTestValues(int value)
{
    slotTransformSource(value, navInstance, "Init");
}

void NavModline::slotDisableModline(QString parameterName)
{
    if(parameterName == QString("nav_modline%1_enable").arg(navInstance+1))
    {
        navModlineForm->enable->setChecked(false);
        emit signalStoreValue(QString("nav_modline%1_").arg(navInstance+1) + "enable", false, -1);
        emit signalCheckSavedState();
    }
}

void NavModline::slotDeleteModline(int num, bool disable)
{
    if(navInstance == num - 1 && navInstance > 1)
    {
        navModlineForm->enable->setChecked(disable);
        emit signalStoreValue(QString("nav_modline%1_").arg(navInstance+1) + "enable", false, -1);
        emit signalCheckSavedState();
    }
}

void NavModline::slotRecallDestinationMenu()
{
    //qDebug() << "NavModline::slotRecallDestinationMenu called";
    //set the device view to change based on what is selected in the destination menu

    modDest.index = navModlineForm->destination->currentIndex();

    // first hide all elements...

    // input ui
    navModlineForm->dest_b1->hide();
    navModlineForm->dest_b2->hide();
    navModlineForm->dest_b3->hide();
    navModlineForm->dest_device->hide();
    navModlineForm->dest_mmcfunction->hide();
    navModlineForm->dest_oscroute->hide();

    // limits
    navModlineForm->dest_b1->setMinimum(0);
    navModlineForm->dest_b1->setMaximum(127);

    // labels
    navModlineForm->dest_label_b1->hide();
    navModlineForm->dest_label_b2->hide();
    navModlineForm->dest_label_b3->hide();
    navModlineForm->dest_label_func->hide();
    navModlineForm->dest_label_port->hide();

    // ...then individually show and update them as needed
    switch (modDest.index)
    {
    case DEST_NOTE_SET:
        navModlineForm->dest_b1->show();
        navModlineForm->dest_label_b1->setText("Note");
        navModlineForm->dest_label_b1->show();
        navModlineForm->dest_b1->setToolTip("The note # to send");

        navModlineForm->dest_b1->setValue(modDest.note);
    case DEST_NOTE_LIVE:
        if (modDest.index == DEST_NOTE_LIVE)
        {
            navModlineForm->dest_b1->show();
            navModlineForm->dest_b1->setMinimum(-48);
            navModlineForm->dest_b1->setMaximum(48);
            navModlineForm->dest_b1->setValue(modDest.transpose);
            navModlineForm->dest_label_b1->setText("Tranpose");
            navModlineForm->dest_label_b1->show();
            navModlineForm->dest_b1->setToolTip("Shift the live note by this much");
        }

        // common to both cases
        navModlineForm->dest_b2->show();
        navModlineForm->dest_label_b2->setText("Vel");
        navModlineForm->dest_label_b2->show();
        navModlineForm->dest_b2->setToolTip("The velocity value to send");
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b2->setValue(modDest.velocity);
        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_CC:
        navModlineForm->dest_b2->show();
        navModlineForm->dest_label_b2->setText("CC");
        navModlineForm->dest_label_b2->show();
        navModlineForm->dest_b2->setToolTip("The CC # to send");
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b2->setValue(modDest.cc);
        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_BANK:
        navModlineForm->dest_b2->show();
        navModlineForm->dest_label_b2->setText("MSB");
        navModlineForm->dest_label_b2->show();
        navModlineForm->dest_b2->setToolTip("The bank's most significant value to send (modline value is sent as the least significant value)");
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b2->setValue(modDest.bankMSB);
        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_PROGRAM:
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_OSC:
        qDebug() << "dest osc set";
        navModlineForm->dest_oscroute->show();
        navModlineForm->dest_label_port->setText("Output Prefix");
        navModlineForm->dest_label_port->show();
        break;
    case DEST_PITCH_BEND:
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_MMC:
        navModlineForm->dest_b1->show();
        navModlineForm->dest_label_b1->setText("ID");
        navModlineForm->dest_label_b1->show();
        navModlineForm->dest_b1->setToolTip("Sets the device ID for the receiving MMC device.");
        navModlineForm->dest_label_func->show();
        navModlineForm->dest_mmcfunction->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b1->setValue(modDest.mmcID);
        break;
    case DEST_AFTERTOUCH:
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_POLY_AFTERTOUCH:
        navModlineForm->dest_b2->show();
        navModlineForm->dest_label_b2->setText("Note");
        navModlineForm->dest_label_b2->show();
        navModlineForm->dest_b2->setToolTip("The note # to send");
        navModlineForm->dest_b3->show();
        navModlineForm->dest_label_b3->show();
        navModlineForm->dest_device->show();
        navModlineForm->dest_label_port->setText("Output Port");
        navModlineForm->dest_label_port->show();

        navModlineForm->dest_b2->setValue(modDest.note);
        navModlineForm->dest_b3->setValue(modDest.channel);
        break;
    case DEST_X_INC:
    case DEST_Y_INC:
    case DEST_NONE:
    default:
        break;
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
        navModlineForm->raw->setEnabled(true);
        navModlineForm->result->setEnabled(true);
        navModlineForm->outputvalue->setEnabled(true);
        navModlineForm->delay->setEnabled(true);
    }
    else
    {
        navModlineForm->initmode->setEnabled(false);
        navModlineForm->initvalue->setEnabled(false);
        navModlineForm->delay->setEnabled(false);
        navModlineForm->raw->setEnabled(false);
        navModlineForm->result->setEnabled(false);
        navModlineForm->outputvalue->setEnabled(false);
        navModlineForm->delay->setEnabled(false);
    }
}

void NavModline::slotPopulateMenus(QStringList source, QStringList dest, QStringList table)
{
    //set source menu
    navModlineForm->source->clear();
    navModlineForm->source->addItems(source);
    emit signalFixDropDownWidth(navModlineForm->source);

    //set table menu
    navModlineForm->table->clear();
    navModlineForm->table->addItems(table);
    emit signalFixDropDownWidth(navModlineForm->table);

    //set destination menus
    navModlineForm->destination->clear();
    navModlineForm->destination->addItems(dest);
    emit signalFixDropDownWidth(navModlineForm->destination);
}

void NavModline::hosted_slotPopulateDeviceMenu(QMap<QString, int> externalDevices)
{
    //------------------------------- Clear all device menus

    //Note Set
//    navModlineForm->notedevice->clear();

//    //Note Live
//    navModlineForm->notelivedevice->clear();

//    //CC
//    navModlineForm->controldevice->clear();

//    //Bank
//    navModlineForm->bankdevice->clear();

//    //Program
//    navModlineForm->programdevice->clear();

//    //Pitch Bend
//    navModlineForm->benddevice->clear();

//    //MMC
//    navModlineForm->mmcdevice->clear();

//    //Aftertouch
//    navModlineForm->aftertouchdevice->clear();

//    //Poly Aftertouch
//    navModlineForm->polydevice->clear();

    navModlineForm->dest_device->clear();
    navModlineForm->dest_device->addItem("None");
    if (mode == "hosted")
    {
        navModlineForm->dest_device->addItem("SoftStep Share");
    }

    //-------------------------------- Populate all menus        
    // Step 1: Load the QMap into a QList, inverting the key and value for sorting
    QList<QPair<int, QString>> sortedList;
    for (auto it = externalDevices.begin(); it != externalDevices.end(); ++it) {
        sortedList.append(qMakePair(it.value(), it.key()));
    }

    // Step 2: Sort the QList by the values, which are now the first element of the pair
    std::sort(sortedList.begin(), sortedList.end(), [](const QPair<int, QString> &a, const QPair<int, QString> &b) {
        return a.first < b.first;
    });

    // Step 3: Iterate through the sorted QList and add items to the combobox
    for (const auto &item : sortedList)
    {
        if (item.second != "SoftStep Share" && item.second != "Microsoft GS Wavetable Synth")
        {
            navModlineForm->dest_device->addItem(item.second);
        }

//        //Note Set
//        navModlineForm->notedevice->addItem(i.key());

//        //Note Live
//        navModlineForm->notelivedevice->addItem(i.key());

//        //CC
//        navModlineForm->controldevice->addItem(i.key());

//        //Bank
//        navModlineForm->bankdevice->addItem(i.key());

//        //Program
//        navModlineForm->programdevice->addItem(i.key());

//        //Pitch Bend
//        navModlineForm->benddevice->addItem(i.key());

//        //MMC
//        navModlineForm->mmcdevice->addItem(i.key());

//        //Aftertouch
//        navModlineForm->aftertouchdevice->addItem(i.key());

//        //Poly Aftertouch
//        navModlineForm->polydevice->addItem(i.key());
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
                //qDebug() << val << modlineNum << source;

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
    //qDebug() << "slew return" << input;

    slotDelay(input);
}

//-------------------------------------------------------------------- Delay
void NavModline::slotDelay(int input)
{

    if(delay)
    {
        //qDebug() << "delay called" << delay << input;

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
    //qDebug() << "delayed signal" << input;
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
    // EB TODO - update to use a single set of dropdowns
    //qDebug() << "Modline::hosted_slotOutputMidi called";
    if(outputType == "Note Set")
    {
        if(outputVal)
        {
            emit hosted_signalNoteSet(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), navModlineForm->dest_b1->value(), navModlineForm->dest_b2->value());
        }
        else
        {
            emit hosted_signalNoteSet(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), navModlineForm->dest_b1->value(), 0);
        }
    }
    else if(outputType == "Note Live")
    {     
        char thisTranspose = navModlineForm->dest_b1->value();
        if (thisTranspose)
        {
            int thisVal = (thisTranspose + outputVal);
            outputVal = std::min(std::max(thisVal, 0), 127);
        }

        emit hosted_signalNoteLive(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), lastNote, outputVal, navModlineForm->dest_b2->value());

        lastNote = outputVal;
    }
    else if(outputType == "CC")
    {
        emit hosted_signalCC(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), navModlineForm->dest_b2->value(), outputVal);
    }
    else if(outputType == "Bank")
    {
        emit hosted_signalBank(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), navModlineForm->dest_b2->value(), outputVal);
    }
    else if(outputType == "Program")
    {
        emit hosted_signalProgram(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), outputVal);
    }
    else if(outputType == "Pitch Bend")
    {
        emit hosted_signalPitchBend(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), 0, outputVal);
    }
    else if(outputType == "MMC")
    {
        toggleOnMMC = false;

        if(outputVal && !toggleOnMMC)
        {
            emit hosted_signalMMC(navModlineForm->dest_device->currentText(), navModlineForm->dest_b1->value(), navModlineForm->dest_mmcfunction->currentText());
            toggleOnMMC = true;
        }
        else if(!outputVal)
        {
            toggleOnMMC = false;
        }
    }
    else if(outputType == "OSC")
    {
        emit hosted_signalOSC(navModlineForm->dest_oscroute->text(), outputVal);
    }
    else if(outputType == "Aftertouch")
    {
        emit hosted_signalAftertouch(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), outputVal);
    }
    else if(outputType == "Poly Aftertouch")
    {
        emit hosted_signalPolyAftertouch(navModlineForm->dest_device->currentText(), navModlineForm->dest_b3->value(), navModlineForm->dest_b2->value(), outputVal);
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

void NavModline::slotDisplayVars()
{
    //qDebug() << "nav output value display" << value;
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
