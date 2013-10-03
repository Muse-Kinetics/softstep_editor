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
    //settingsWidget->setFixedSize(319,461);
    settingsWidget->setWindowTitle(QString("Settings"));

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
        QVariant value;

        QString spinBoxName;
        QSpinBox *spinbox = reinterpret_cast<QSpinBox*>(QObject::sender());

        //spinboxes
        spinBoxName = spinbox->objectName();
        value = spinbox->value();
        emit signalStoreValue(spinBoxName,value);
    }
    //qDebug() << "value changed" << QObject::sender()->objectName();
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
