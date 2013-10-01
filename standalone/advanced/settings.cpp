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

    /*connect(settingsForm->key1_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key1_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key1_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key1_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key1_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key1_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key2_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key2_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key2_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key2_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key2_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key2_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key3_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key3_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key3_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key3_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key3_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key3_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key4_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key4_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key4_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key4_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key4_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key4_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key5_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key5_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key5_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key5_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key5_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key5_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key6_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key6_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key6_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key6_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key6_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key6_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key7_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key7_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key7_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key7_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key7_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key7_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key8_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key8_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key8_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key8_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key8_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key8_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key9_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key9_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key9_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key9_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key9_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key9_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->key10_settings_xaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key10_settings_yaccel,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key10_settings_xdead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key10_settings_ydead,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key10_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->key10_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));

    connect(settingsForm->nav_north_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_north_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_south_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_south_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_east_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_east_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_west_settings_onthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(settingsForm->nav_west_settings_offthresh,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));*/
}

void Settings::slotValueChanged()
{
    //emit values to the preset file here
    qDebug() << "value changed" << QObject::sender()->objectName();
}

void Settings::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    //set values from recalled presets here
}
