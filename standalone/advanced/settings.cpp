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

    slotConnectElements();

    //set which stacked widget to initiallize in and connect the buttons to the view selector--I chose the global page for now
    settingsForm->settingsViews->setCurrentIndex(0);
    connect(settingsForm->settingsglobalbutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));
    connect(settingsForm->settingskeybutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));
    connect(settingsForm->settingsinputbutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));
    connect(settingsForm->settingspedalbutton,SIGNAL(clicked()),this,SLOT(slotViewSelector()));

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
                connect(radiobutton, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
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

    qDebug() << "value changed" << QObject::sender()->objectName();

    slotSetMidiInputLineParams();
}

void Settings::slotRecallPreset(QVariantMap preset, QVariantMap)
{


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

void Settings::slotSetMode(QString m)
{

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
