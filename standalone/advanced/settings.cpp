// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "settings.h"

#include <QDebug>

Settings::Settings(QWidget *parent) :
    QWidget(parent),settingsForm(new Ui::settingsForm)
{
    //set up settings window
    settingsWidget = new QWidget();
    settingsForm->setupUi(settingsWidget);
    settingsWidget->setFixedSize(380,516);
    settingsWidget->setWindowTitle(QString("Settings"));

    slotConnectElements();


}

void Settings::slotOpenSettings()
{
    qDebug() << QString("open settings window");
    settingsWidget->show();
}

void Settings::slotConnectElements()
{
    foreach(QWidget* widget, settingsWidget->findChildren<QWidget *>())
    {
        //Check object type here
        if(widget->metaObject()->className() == QString("QSpinBox"))
        {
            QSpinBox* spinbox = qobject_cast<QSpinBox *>(widget);
            //qDebug() << "settings spin box name: " << widget->objectName();
            connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
        }
    }

}

void Settings::slotValueChanged()
{
    //emit values to the preset file here
    if(QObject::sender())
    {
        QString jsonName;
        QSpinBox *spinbox = reinterpret_cast<QSpinBox*>(QObject::sender());
        QVariant value;

        //spinboxes
        jsonName = spinbox->objectName();
        value = spinbox->value();

        emit signalStoreValue(QString("%1").arg(jsonName),value);
    }
    qDebug() << "value changed" << QObject::sender()->objectName();
}

void Settings::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    settingsForm->key1_settings_xaccel->setValue(preset.value(QString("key1_settings_xaccel")).toInt());
    settingsForm->key1_settings_yaccel->setValue(preset.value(QString("key1_settings_yaccel")).toInt());
    settingsForm->key1_settings_xdead->setValue(preset.value(QString("key1_settings_xdead")).toInt());
    settingsForm->key1_settings_ydead->setValue(preset.value(QString("key1_settings_ydead")).toInt());
    settingsForm->key1_settings_onthresh->setValue(preset.value(QString("key1_settings_onthresh")).toInt());
    settingsForm->key1_settings_offthresh->setValue(preset.value(QString("key1_settings_offthresh")).toInt());

    //the rest of the key settings could go here, or find a more efficient way to do this...
}
