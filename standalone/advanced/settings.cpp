// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "settings.h"

#include <QDebug>

Settings::Settings(QWidget *parent) :
    QWidget(parent),settingsForm(new Ui::settingsForm)
{
    //set up settings window
    settingsWidget = new QWidget(this);
    settingsWidget->hide();
    settingsWidget->setWindowFlags(Qt::Tool | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint| Qt::WindowStaysOnTopHint);
    settingsForm->setupUi(settingsWidget);
    //settingsWidget->setFixedSize(320,492);
    settingsWidget->setWindowTitle(QString("Settings"));
    slotSetJSONPath();

    pedal = new Pedal();

    //point dat pedallever to the pedal_top QLabel in the Settings form
    pedal->slotSetLeverPointer(settingsForm->pedal_top);

    for(int i = 0; i < NUM_MIDI_INPUTS; i++)
    {
        midiInputLine[i].hide();

        if(i == 0)
        {
            midiInputLine[i].instance = "A";
        }
        else if(i == 1)
        {
            midiInputLine[i].instance = "B";
        }
        else if(i == 2)
        {
            midiInputLine[i].instance = "C";
        }
        else if(i == 3)
        {
            midiInputLine[i].instance = "D";
        }
        else if(i == 4)
        {
            midiInputLine[i].instance = "E";
        }
        else if(i == 5)
        {
            midiInputLine[i].instance = "F";
        }
        else if(i == 6)
        {
            midiInputLine[i].instance = "G";
        }
        else if(i == 7)
        {
            midiInputLine[i].instance = "H";
        }
    }

    //slotConnectElements();

    //set which stacked widget to initiallize in and connect the buttons to the view selector--I chose the global page for now
    settingsForm->settingsViews->setCurrentIndex(0);
    connect(settingsForm->settingsglobalbutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));
    connect(settingsForm->settingskeybutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));
    connect(settingsForm->settingsinputbutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));
    connect(settingsForm->settingspedalbutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));

    //slotWriteDefaultSettings();
    //slotRecallSettings();
}

void Settings::slotOpenSettings()
{
    settingsWidget->show();
    settingsWidget->raise();
}

void Settings::slotConnectElements()
{

    //---------------------- General Settings Widgets
    foreach(QWidget* widget, settingsWidget->findChildren<QWidget *>())
    {
        //Check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
            QSpinBox* spinbox = qobject_cast<QSpinBox *>(widget);
            //qDebug() << "settings spin box name: " << widget->objectName();
            if(!QString(spinbox->objectName()).contains("value")) //the value parameters should not be saved in presets
            {
                connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
            }
        }
        else if(widget->metaObject()->className() == QString("QDoubleSpinBox"))
        {
            QDoubleSpinBox* doublespinbox = qobject_cast<QDoubleSpinBox *>(widget);
            connect(doublespinbox, SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QSlider"))
        {
            QSlider* slider = qobject_cast<QSlider *>(widget);
            connect(slider, SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QCheckBox"))
        {
            QCheckBox* checkbox = qobject_cast<QCheckBox *>(widget);

            connect(checkbox, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QComboBox"))
        {
            QComboBox* combobox = qobject_cast<QComboBox *>(widget);

            if(combobox->objectName().contains("_settings_device"))
            {
                midiInputDeviceMenus.append(combobox);
            }

            connect(combobox, SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QLineEdit"))
        {
            QLineEdit* lineedit = qobject_cast<QLineEdit *>(widget);
            connect(lineedit, SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QRadioButton"))
        {
            QRadioButton* radiobutton = qobject_cast<QRadioButton *>(widget);
            if(QString(radiobutton->objectName()).contains("sensorresponse") || QString(radiobutton->objectName()).contains("mode"))
            {
                connect(radiobutton, SIGNAL(toggled(bool)),this,SLOT(slotValueChanged()));
            }
        }
    }

    for(int i = 0; i < NUM_MIDI_INPUTS; i++)
    {
        if(i == 0)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midia_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 1)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midib_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 2)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midic_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 3)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midid_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 4)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midie_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 5)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midif_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 6)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midig_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 7)
        {
            connect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midih_settings_inputvalue, SLOT(setValue(int)));
        }
    }

    connect(this, SIGNAL(signalRecallSettings(QVariantMap,QVariantMap)),this,SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
    connect(this, SIGNAL(signalStoreValue(QString,QVariant)), this, SLOT(slotStoreSettings(QString,QVariant)));
}

void Settings::slotDisconnectElements()
{
    //---------------------- General Settings Widgets
    foreach(QWidget* widget, settingsWidget->findChildren<QWidget *>())
    {
        //Check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
            QSpinBox* spinbox = qobject_cast<QSpinBox *>(widget);
            //qDebug() << "settings spin box name: " << widget->objectName();
            if(!QString(spinbox->objectName()).contains("value")) //the value parameters should not be saved in presets
            {
                disconnect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
            }
        }
        else if(widget->metaObject()->className() == QString("QDoubleSpinBox"))
        {
            QDoubleSpinBox* doublespinbox = qobject_cast<QDoubleSpinBox *>(widget);
            disconnect(doublespinbox, SIGNAL(valueChanged(double)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QSlider"))
        {
            QSlider* slider = qobject_cast<QSlider *>(widget);
            disconnect(slider, SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QCheckBox"))
        {
            QCheckBox* checkbox = qobject_cast<QCheckBox *>(widget);

            disconnect(checkbox, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QComboBox"))
        {
            QComboBox* combobox = qobject_cast<QComboBox *>(widget);

            if(combobox->objectName().contains("_settings_device"))
            {
                midiInputDeviceMenus.append(combobox);
            }

            disconnect(combobox, SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QLineEdit"))
        {
            QLineEdit* lineedit = qobject_cast<QLineEdit *>(widget);
            disconnect(lineedit, SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));
        }
        else if(widget->metaObject()->className() == QString("QRadioButton"))
        {
            QRadioButton* radiobutton = qobject_cast<QRadioButton *>(widget);
            if(QString(radiobutton->objectName()).contains("sensorresponse") || QString(radiobutton->objectName()).contains("mode"))
            {
                disconnect(radiobutton, SIGNAL(toggled(bool)),this,SLOT(slotValueChanged()));
            }
        }
    }

    for(int i = 0; i < NUM_MIDI_INPUTS; i++)
    {
        if(i == 0)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midia_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 1)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midib_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 2)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midic_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 3)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midid_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 4)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midie_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 5)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midif_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 6)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midig_settings_inputvalue, SLOT(setValue(int)));
        }
        else if(i == 7)
        {
            disconnect(&midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), settingsForm->midih_settings_inputvalue, SLOT(setValue(int)));
        }
    }
}

void Settings::slotValueChanged()
{
    //emit values to the preset file here
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();
        QString senderClass = sender->metaObject()->className();
        QString jsonName;
        QVariant value;

        //spinboxes
        if(senderClass == "QSpinBox")
        {
            QSpinBox *spinbox = reinterpret_cast<QSpinBox*>(QObject::sender());
            jsonName = spinbox->objectName();
            value = spinbox->value();
        }
        //doublespinboxes
        else if(senderClass == "QDoubleSpinBox")
        {
            QDoubleSpinBox *doublespinbox = reinterpret_cast<QDoubleSpinBox*>(QObject::sender());
            jsonName = doublespinbox->objectName();
            value = doublespinbox->value();
        }
        //sliders
        else if(senderClass == "QSlider")
        {
            QSlider *slider = reinterpret_cast<QSlider*>(QObject::sender());
            if(slider->objectName() == "global_gain_slider")
            {
                jsonName = "global_gain";
                double gain = slider->value() * 0.01;
                value = gain;
            }
        }
        //checkboxes
        else if(senderClass == "QCheckBox")
        {
            QCheckBox *checkbox = reinterpret_cast<QCheckBox*>(QObject::sender());
            jsonName = checkbox->objectName();
            value = checkbox->isChecked();
        }
        //comboboxes
        else if(senderClass == "QComboBox")
        {
            QComboBox *combobox = reinterpret_cast<QComboBox*>(QObject::sender());
            jsonName = combobox->objectName();
            value = combobox->currentText();
        }
        //line edits (osc routes)
        else if(senderClass == "QLineEdit")
        {
            QLineEdit *lineedit = reinterpret_cast<QLineEdit*>(QObject::sender());
            jsonName = lineedit->objectName();
            value = lineedit->text();
        }
        //radio buttons
        else if(senderClass == "QRadioButton")
        {
            QRadioButton *radiobutton = reinterpret_cast<QRadioButton*>(QObject::sender());
            jsonName = radiobutton->objectName();
            value = radiobutton->isChecked();
        }
        emit signalStoreValue(jsonName,value);
    }

    //qDebug() << "value changed" << QObject::sender()->objectName();

    slotSetMidiInputLineParams();
}

void Settings::slotStoreSettings(QString name, QVariant value)
{
    QVariantMap globalMap = settings.value(QString("Global")).toMap();
    globalMap.insert(name,value);
    settings.insert(QString("Global"), globalMap);

    //qDebug() << "update the settings preset";
    slotWriteSettings();
}

void Settings::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();
    foreach(QWidget* widget, settingsWidget->findChildren<QWidget *>())
    {
        //Check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
            QSpinBox* spinbox = qobject_cast<QSpinBox *>(widget);
            QString objectName = widget->objectName();
            spinbox->setValue(preset.value(objectName).toInt());
        }
        else if(widget->metaObject()->className() == QString("QDoubleSpinBox"))
        {
            QDoubleSpinBox* doublespinbox = qobject_cast<QDoubleSpinBox *>(widget);
            QString objectName = widget->objectName();
            doublespinbox->setValue(preset.value(objectName).toDouble());
        }
        else if(widget->metaObject()->className() == QString("QSlider"))
        {
            QSlider* slider = qobject_cast<QSlider *>(widget);
            QString objectName = widget->objectName();
            if(objectName == "global_gain_slider")
            {
                int gain = preset.value("global_gain").toDouble() * 100;
                slider->setValue(gain);
            }
        }
        else if(widget->metaObject()->className() == QString("QCheckBox"))
        {
            QCheckBox* checkbox = qobject_cast<QCheckBox *>(widget);
            QString objectName = widget->objectName();
            checkbox->setChecked(preset.value(objectName).toBool());
        }
        else if(widget->metaObject()->className() == QString("QComboBox"))
        {
            QComboBox* combobox = qobject_cast<QComboBox *>(widget);
            QString objectName = widget->objectName();
            combobox->setCurrentIndex(combobox->findText(preset.value(objectName).toString()));
        }
        else if(widget->metaObject()->className() == QString("QLineEdit"))
        {
            QLineEdit* lineedit = qobject_cast<QLineEdit *>(widget);
            QString objectName = widget->objectName();
            lineedit->setText(preset.value(objectName).toString());
        }
        else if(widget->metaObject()->className() == QString("QRadioButton"))
        {
            QRadioButton* radiobutton = qobject_cast<QRadioButton *>(widget);
            QString objectName = widget->objectName();
            radiobutton->setChecked(preset.value(objectName).toBool());
        }
    }

    slotConnectElements();

    slotEmitSettings();
}

void Settings::slotRecallSettings()
{
    emit signalRecallSettings(settings.value(QString("Global")).toMap(),settings);

    //qDebug() << "Recall Settings" << settings;
}

void Settings::slotViewSelector()
{
    qDebug() << "slotViewSelectorCalled";
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        if(sender == settingsForm->settingsglobalbutton)
        {
            settingsForm->settingsViews->setCurrentIndex(0);
        }
        else if(sender == settingsForm->settingskeybutton)
        {
            settingsForm->settingsViews->setCurrentIndex(1);
        }
        else if(sender == settingsForm->settingsinputbutton)
        {
            settingsForm->settingsViews->setCurrentIndex(2);
        }
        else if(sender == settingsForm->settingspedalbutton)
        {
            settingsForm->settingsViews->setCurrentIndex(3);
        }
    }
}

void Settings::slotPopulateInputMenus(QMap<QString, MIDIEndpointRef> midiSources)
{
    qDebug() << "slot populate input menus" << midiSources.keys();



    //Iterate through menus
    for(int m = 0;  m < midiInputDeviceMenus.size(); m++)
    {
        midiInputDeviceMenus.at(m)->clear();
        midiInputDeviceMenus.at(m)->addItems(midiSources.keys());
    }
}

void Settings::slotSetMidiInputLineParams()
{
    //There must be a better way to do this...

    for(int i = 0; i < NUM_MIDI_INPUTS; i++)
    {
        if(i == 0)
        {
            midiInputLine[i].enable = settingsForm->midia_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midia_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midia_settings_channel->value();
            midiInputLine[i].type = settingsForm->midia_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midia_settings_number->value();
        }
        else if(i == 1)
        {
            midiInputLine[i].enable = settingsForm->midib_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midib_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midib_settings_channel->value();
            midiInputLine[i].type = settingsForm->midib_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midib_settings_number->value();
        }
        else if(i == 2)
        {
            midiInputLine[i].enable = settingsForm->midic_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midic_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midic_settings_channel->value();
            midiInputLine[i].type = settingsForm->midic_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midic_settings_number->value();
        }
        else if(i == 3)
        {
            midiInputLine[i].enable = settingsForm->midid_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midid_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midid_settings_channel->value();
            midiInputLine[i].type = settingsForm->midid_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midid_settings_number->value();
        }
        else if(i == 4)
        {
            midiInputLine[i].enable = settingsForm->midie_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midie_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midie_settings_channel->value();
            midiInputLine[i].type = settingsForm->midie_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midie_settings_number->value();
        }
        else if(i == 5)
        {
            midiInputLine[i].enable = settingsForm->midif_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midif_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midif_settings_channel->value();
            midiInputLine[i].type = settingsForm->midif_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midif_settings_number->value();
        }
        else if(i == 6)
        {
            midiInputLine[i].enable = settingsForm->midig_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midig_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midig_settings_channel->value();
            midiInputLine[i].type = settingsForm->midig_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midig_settings_number->value();
        }
        else if(i == 7)
        {
            midiInputLine[i].enable = settingsForm->midih_settings_enable->isChecked();
            midiInputLine[i].device = settingsForm->midih_settings_device->currentText();
            midiInputLine[i].channel = settingsForm->midih_settings_channel->value();
            midiInputLine[i].type = settingsForm->midih_settings_messagetype->currentText();
            midiInputLine[i].number = settingsForm->midih_settings_number->value();
        }
    }
}

void Settings::slotSetJSONPath()
{
    jsonPath = QCoreApplication::applicationDirPath(); //get bundle path

#if defined(Q_OS_MAC)  && !defined(QT_DEBUG)
    jsonPath.remove(jsonPath.length() - 5, jsonPath.length());  //remove "MacOS" from path string
    jsonPath.append("Resources/presets/settings.json");

#else
    jsonPath = QString("./presets/settings.json");
#endif
}

void Settings::slotReadSettings()
{
    //load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("Settings JSON Found");

        QByteArray settingsByteArray = jsonFile->readAll();

        settings = parser.parse(settingsByteArray, &ok).toMap(); //parse the json data, convert it to a map and set it equal to the master jsonMap
    }
    else
    {
        qDebug() << "Settings JSON not found";
    }

    jsonFile->close();
}

void Settings::slotWriteSettings()
{
    //load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //serialize JSON, write to file
        QByteArray ba = serializer.serialize(settings); //serialize the master json map into the byte array

        jsonFile->resize(0);
        jsonFile->write(ba);
    }
    else
    {
        qDebug() << "Settings not found on write";
    }

    jsonFile->close();
}

void Settings::slotWriteDefaultSettings()
{
    slotConstructSettingsDefaultMap();
    settings.insert(QString("Global"),defaultGlobalMap);

    slotWriteSettings();
}

void Settings::slotConstructSettingsDefaultMap()
{
    //------------------ Global Page -------------------//
    defaultGlobalMap["sensorresponse_average"] = 1;
    defaultGlobalMap["sensorresponse_max"] = 0;
    defaultGlobalMap["adjacentkeymode"] = 0;
    defaultGlobalMap["keylockoutmode"] = 0;
    defaultGlobalMap["multiplekeymode"] = 1;

    defaultGlobalMap["global_gain"] = 1.00;
    defaultGlobalMap["backlighting_enable"] = 1;

    //-------------------- Key Page --------------------//
    defaultGlobalMap["key1_settings_xdead"] = 0;
    defaultGlobalMap["key1_settings_ydead"] = 0;
    defaultGlobalMap["key1_settings_xaccel"] = 0;
    defaultGlobalMap["key1_settings_ydead"] = 0;
    defaultGlobalMap["key1_settings_onthresh"] = 10;
    defaultGlobalMap["key1_settings_offthresh"] = 5;

    defaultGlobalMap["key2_settings_xdead"] = 0;
    defaultGlobalMap["key2_settings_ydead"] = 0;
    defaultGlobalMap["key2_settings_xaccel"] = 0;
    defaultGlobalMap["key2_settings_ydead"] = 0;
    defaultGlobalMap["key2_settings_onthresh"] = 10;
    defaultGlobalMap["key2_settings_offthresh"] = 5;

    defaultGlobalMap["key3_settings_xdead"] = 0;
    defaultGlobalMap["key3_settings_ydead"] = 0;
    defaultGlobalMap["key3_settings_xaccel"] = 0;
    defaultGlobalMap["key3_settings_ydead"] = 0;
    defaultGlobalMap["key3_settings_onthresh"] = 10;
    defaultGlobalMap["key3_settings_offthresh"] = 5;

    defaultGlobalMap["key4_settings_xdead"] = 0;
    defaultGlobalMap["key4_settings_ydead"] = 0;
    defaultGlobalMap["key4_settings_xaccel"] = 0;
    defaultGlobalMap["key4_settings_ydead"] = 0;
    defaultGlobalMap["key4_settings_onthresh"] = 10;
    defaultGlobalMap["key4_settings_offthresh"] = 5;

    defaultGlobalMap["key5_settings_xdead"] = 0;
    defaultGlobalMap["key5_settings_ydead"] = 0;
    defaultGlobalMap["key5_settings_xaccel"] = 0;
    defaultGlobalMap["key5_settings_ydead"] = 0;
    defaultGlobalMap["key5_settings_onthresh"] = 10;
    defaultGlobalMap["key5_settings_offthresh"] = 5;

    defaultGlobalMap["key6_settings_xdead"] = 0;
    defaultGlobalMap["key6_settings_ydead"] = 0;
    defaultGlobalMap["key6_settings_xaccel"] = 0;
    defaultGlobalMap["key6_settings_ydead"] = 0;
    defaultGlobalMap["key6_settings_onthresh"] = 10;
    defaultGlobalMap["key6_settings_offthresh"] = 5;

    defaultGlobalMap["key7_settings_xdead"] = 0;
    defaultGlobalMap["key7_settings_ydead"] = 0;
    defaultGlobalMap["key7_settings_xaccel"] = 0;
    defaultGlobalMap["key7_settings_ydead"] = 0;
    defaultGlobalMap["key7_settings_onthresh"] = 10;
    defaultGlobalMap["key7_settings_offthresh"] = 5;

    defaultGlobalMap["key8_settings_xdead"] = 0;
    defaultGlobalMap["key8_settings_ydead"] = 0;
    defaultGlobalMap["key8_settings_xaccel"] = 0;
    defaultGlobalMap["key8_settings_ydead"] = 0;
    defaultGlobalMap["key8_settings_onthresh"] = 10;
    defaultGlobalMap["key8_settings_offthresh"] = 5;

    defaultGlobalMap["key9_settings_xdead"] = 0;
    defaultGlobalMap["key9_settings_ydead"] = 0;
    defaultGlobalMap["key9_settings_xaccel"] = 0;
    defaultGlobalMap["key9_settings_ydead"] = 0;
    defaultGlobalMap["key9_settings_onthresh"] = 10;
    defaultGlobalMap["key9_settings_offthresh"] = 5;

    defaultGlobalMap["key10_settings_xdead"] = 0;
    defaultGlobalMap["key10_settings_ydead"] = 0;
    defaultGlobalMap["key10_settings_xaccel"] = 0;
    defaultGlobalMap["key10_settings_ydead"] = 0;
    defaultGlobalMap["key10_settings_onthresh"] = 10;
    defaultGlobalMap["key10_settings_offthresh"] = 5;

    defaultGlobalMap["nav_north_settings_onthresh"] = 10;
    defaultGlobalMap["nav_north_settings_offthresh"] = 5;
    defaultGlobalMap["nav_south_settings_onthresh"] = 10;
    defaultGlobalMap["nav_south_settings_offthresh"] = 5;
    defaultGlobalMap["nav_east_settings_onthresh"] = 10;
    defaultGlobalMap["nav_east_settings_offthresh"] = 5;
    defaultGlobalMap["nav_west_settings_onthresh"] = 10;
    defaultGlobalMap["nav_west_settings_offthresh"] = 5;
    defaultGlobalMap["nav_settings_yaccel"] = 0;

    //---------------------- Input Page ---------------------//
    defaultGlobalMap["midia_settings_enable"] = 0;
    defaultGlobalMap["midia_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midia_settings_channel"] = 1;
    defaultGlobalMap["midia_settings_messagetype"] = "Note";
    defaultGlobalMap["midia_settings_number"] = 60;

    defaultGlobalMap["midib_settings_enable"] = 0;
    defaultGlobalMap["midib_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midib_settings_channel"] = 1;
    defaultGlobalMap["midib_settings_messagetype"] = "Note";
    defaultGlobalMap["midib_settings_number"] = 60;

    defaultGlobalMap["midic_settings_enable"] = 0;
    defaultGlobalMap["midic_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midic_settings_channel"] = 1;
    defaultGlobalMap["midic_settings_messagetype"] = "Note";
    defaultGlobalMap["midic_settings_number"] = 60;

    defaultGlobalMap["midid_settings_enable"] = 0;
    defaultGlobalMap["midid_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midid_settings_channel"] = 1;
    defaultGlobalMap["midid_settings_messagetype"] = "Note";
    defaultGlobalMap["midid_settings_number"] = 60;

    defaultGlobalMap["midie_settings_enable"] = 0;
    defaultGlobalMap["midie_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midie_settings_channel"] = 1;
    defaultGlobalMap["midie_settings_messagetype"] = "Note";
    defaultGlobalMap["midie_settings_number"] = 60;

    defaultGlobalMap["midif_settings_enable"] = 0;
    defaultGlobalMap["midif_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midif_settings_channel"] = 1;
    defaultGlobalMap["midif_settings_messagetype"] = "Note";
    defaultGlobalMap["midif_settings_number"] = 60;

    defaultGlobalMap["midig_settings_enable"] = 0;
    defaultGlobalMap["midig_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midig_settings_channel"] = 1;
    defaultGlobalMap["midig_settings_messagetype"] = "Note";
    defaultGlobalMap["midig_settings_number"] = 60;

    defaultGlobalMap["midih_settings_enable"] = 0;
    defaultGlobalMap["midih_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midih_settings_channel"] = 1;
    defaultGlobalMap["midih_settings_messagetype"] = "Note";
    defaultGlobalMap["midih_settings_number"] = 60;

    defaultGlobalMap["osca_input_enable"] = 0;
    defaultGlobalMap["osca_input_route"] = "";
    defaultGlobalMap["oscb_input_enable"] = 0;
    defaultGlobalMap["oscb_input_route"] = "";
    defaultGlobalMap["oscc_input_enable"] = 0;
    defaultGlobalMap["oscc_input_route"] = "";
    defaultGlobalMap["oscd_input_enable"] = 0;
    defaultGlobalMap["oscd_input_route"] = "";
    defaultGlobalMap["osce_input_enable"] = 0;
    defaultGlobalMap["osce_input_route"] = "";
    defaultGlobalMap["oscf_input_enable"] = 0;
    defaultGlobalMap["oscf_input_route"] = "";
    defaultGlobalMap["oscg_input_enable"] = 0;
    defaultGlobalMap["oscg_input_route"] = "";
    defaultGlobalMap["osch_input_enable"] = 0;
    defaultGlobalMap["osch_input_route"] = "";

    defaultGlobalMap["osc_ip_1"] = 0;
    defaultGlobalMap["osc_ip_2"] = 0;
    defaultGlobalMap["osc_ip_3"] = 0;
    defaultGlobalMap["osc_ip_4"] = 0;
    defaultGlobalMap["osc_out_port"] = 0;
    defaultGlobalMap["osc_in_port"] = 0;
}

void Settings::slotEmitAllSettings()
{

    //Cannot escape brute force.

    //Keys
    emit signalSetKeyOnThresh(0, settingsForm->key1_settings_onthresh->value());
    emit signalSetKeyOffThresh(0, settingsForm->key1_settings_offthresh->value());
    emit signalSetKeyYDeadZone(0, settingsForm->key1_settings_ydead->value());
    emit signalSetKeyXDeadZone(0, settingsForm->key1_settings_xdead->value());
    emit signalSetKeyYAccel(0, settingsForm->key1_settings_yaccel->value());
    emit signalSetKeyXAccel(0, settingsForm->key1_settings_xaccel->value());

    emit signalSetKeyOnThresh(1, settingsForm->key2_settings_onthresh->value());
    emit signalSetKeyOffThresh(1, settingsForm->key2_settings_offthresh->value());
    emit signalSetKeyYDeadZone(1, settingsForm->key2_settings_ydead->value());
    emit signalSetKeyXDeadZone(1, settingsForm->key2_settings_xdead->value());
    emit signalSetKeyYAccel(1, settingsForm->key2_settings_yaccel->value());
    emit signalSetKeyXAccel(1, settingsForm->key2_settings_xaccel->value());

    emit signalSetKeyOnThresh(2, settingsForm->key3_settings_onthresh->value());
    emit signalSetKeyOffThresh(2, settingsForm->key3_settings_offthresh->value());
    emit signalSetKeyYDeadZone(2, settingsForm->key3_settings_ydead->value());
    emit signalSetKeyXDeadZone(2, settingsForm->key3_settings_xdead->value());
    emit signalSetKeyYAccel(2, settingsForm->key3_settings_yaccel->value());
    emit signalSetKeyXAccel(2, settingsForm->key3_settings_xaccel->value());

    emit signalSetKeyOnThresh(3, settingsForm->key4_settings_onthresh->value());
    emit signalSetKeyOffThresh(3, settingsForm->key4_settings_offthresh->value());
    emit signalSetKeyYDeadZone(3, settingsForm->key4_settings_ydead->value());
    emit signalSetKeyXDeadZone(3, settingsForm->key4_settings_xdead->value());
    emit signalSetKeyYAccel(3, settingsForm->key4_settings_yaccel->value());
    emit signalSetKeyXAccel(3, settingsForm->key4_settings_xaccel->value());

    emit signalSetKeyOnThresh(4, settingsForm->key5_settings_onthresh->value());
    emit signalSetKeyOffThresh(4, settingsForm->key5_settings_offthresh->value());
    emit signalSetKeyYDeadZone(4, settingsForm->key5_settings_ydead->value());
    emit signalSetKeyXDeadZone(4, settingsForm->key5_settings_xdead->value());
    emit signalSetKeyYAccel(4, settingsForm->key5_settings_yaccel->value());
    emit signalSetKeyXAccel(4, settingsForm->key5_settings_xaccel->value());

    emit signalSetKeyOnThresh(5, settingsForm->key6_settings_onthresh->value());
    emit signalSetKeyOffThresh(5, settingsForm->key6_settings_offthresh->value());
    emit signalSetKeyYDeadZone(5, settingsForm->key6_settings_ydead->value());
    emit signalSetKeyXDeadZone(5, settingsForm->key6_settings_xdead->value());
    emit signalSetKeyYAccel(5, settingsForm->key6_settings_yaccel->value());
    emit signalSetKeyXAccel(5, settingsForm->key6_settings_xaccel->value());

    emit signalSetKeyOnThresh(6, settingsForm->key7_settings_onthresh->value());
    emit signalSetKeyOffThresh(6, settingsForm->key7_settings_offthresh->value());
    emit signalSetKeyYDeadZone(6, settingsForm->key7_settings_ydead->value());
    emit signalSetKeyXDeadZone(6, settingsForm->key7_settings_xdead->value());
    emit signalSetKeyYAccel(6, settingsForm->key7_settings_yaccel->value());
    emit signalSetKeyXAccel(6, settingsForm->key7_settings_xaccel->value());

    emit signalSetKeyOnThresh(7, settingsForm->key8_settings_onthresh->value());
    emit signalSetKeyOffThresh(7, settingsForm->key8_settings_offthresh->value());
    emit signalSetKeyYDeadZone(7, settingsForm->key8_settings_ydead->value());
    emit signalSetKeyXDeadZone(7, settingsForm->key8_settings_xdead->value());
    emit signalSetKeyYAccel(7, settingsForm->key8_settings_yaccel->value());
    emit signalSetKeyXAccel(7, settingsForm->key8_settings_xaccel->value());

    emit signalSetKeyOnThresh(8, settingsForm->key9_settings_onthresh->value());
    emit signalSetKeyOffThresh(8, settingsForm->key9_settings_offthresh->value());
    emit signalSetKeyYDeadZone(8, settingsForm->key9_settings_ydead->value());
    emit signalSetKeyXDeadZone(8, settingsForm->key9_settings_xdead->value());
    emit signalSetKeyYAccel(8, settingsForm->key9_settings_yaccel->value());
    emit signalSetKeyXAccel(8, settingsForm->key9_settings_xaccel->value());

    emit signalSetKeyOnThresh(9, settingsForm->key10_settings_onthresh->value());
    emit signalSetKeyOffThresh(9, settingsForm->key10_settings_offthresh->value());
    emit signalSetKeyYDeadZone(9, settingsForm->key10_settings_ydead->value());
    emit signalSetKeyXDeadZone(9, settingsForm->key10_settings_xdead->value());
    emit signalSetKeyYAccel(9, settingsForm->key10_settings_yaccel->value());
    emit signalSetKeyXAccel(9, settingsForm->key10_settings_xaccel->value());

    //Nav Pad
}
