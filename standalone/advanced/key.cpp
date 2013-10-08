// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "key.h"

#include <QDebug>

/*-------KEYWINDOW SIZE CONSTANTS-------*/
#define KEYWINDOW_WIDTH 1118
#define KEYWINDOW_HEIGHT 400

/*-------KEYBOX SIZE AND SPACING CONSTANTS-------*/

//Keybox dimensions
#define KEYBOX_WIDTH 101
#define KEYBOX_HEIGHT 64
//Space between key boxes
#define KEYBOX_X_SPACING 10
#define KEYBOX_Y_SPACING 10
//Key box starting position (refers to keybox 1 position)
#define KEYBOX_STARTING_X_POS 10
#define KEYBOX_STARTING_Y_POS 228


Key::Key(QWidget *parent, int keyInstanceNum) :
    QWidget(parent),
    keyBoxForm(new Ui::keyBoxForm),
    keyWindowForm(new Ui::keyWindowForm)
{
    keyInstance = keyInstanceNum;

    //Set up the Key Box
    keyBoxWidget = new QWidget(this);
    keyBoxForm->setupUi(keyBoxWidget);
    keyBoxWidget->setFixedSize(KEYBOX_WIDTH, KEYBOX_HEIGHT);

    if(keyInstanceNum < 5)
    {
        this->setGeometry(10 + ((keyInstance) * (KEYBOX_WIDTH + KEYBOX_X_SPACING)), KEYBOX_STARTING_Y_POS, KEYBOX_WIDTH, KEYBOX_HEIGHT);
    }
    else
    {
        this->setGeometry(10 + ((keyInstance - 5) * (KEYBOX_WIDTH + KEYBOX_X_SPACING)), KEYBOX_STARTING_Y_POS - KEYBOX_HEIGHT - KEYBOX_Y_SPACING, KEYBOX_WIDTH, KEYBOX_HEIGHT);
    }


    //Set up the Key Window
    keyWindowWidget = new QWidget();
    keyWindowForm->setupUi(keyWindowWidget);
    keyWindowWidget->setFixedSize(KEYWINDOW_WIDTH, KEYWINDOW_HEIGHT);
    keyWindowWidget->setWindowTitle(QString("Key %1 Modulation").arg(keyInstance+1));


    //What's in the Key Box?
    keyBoxForm->keyInstanceLabel->setText(QString("%1").arg((keyInstance + 1)%10));

    connect(keyBoxForm->openWindow,SIGNAL(clicked()), this, SLOT(slotOpenWindow()));


    //What's in the Key Window?

    //Construct Modlines
    for(int i = 0; i < 6; i++)
    {
        modline[i] = new Modline(keyWindowWidget, keyInstance, i);
    }

    //Connect Modlines
    for(int i = 0; i < 6; i++)
    {
        modline[i]->slotConnectElements();
    }

    //Carson's attempt to dynamically update the key window instance label — shit works
    keyWindowForm->keyWindowInstanceLabel->setText(QString("%1").arg(keyInstance + 1));

}

void Key::slotOpenWindow()
{
    //qDebug() << QString("Open Key %1 Button clicked! Open the window!").arg(keyInstance+1);
    keyWindowWidget->show();
}

void Key::slotConnectElements()
{
    //key name (from the keyBoxForm)
    connect(keyBoxForm->keyName,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));


    //key counter stuff
    connect(keyWindowForm->counterMin,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(keyWindowForm->counterMax,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    connect(keyWindowForm->counterWrap,SIGNAL(clicked()),this,SLOT(slotValueChanged()));
}

void Key::slotValueChanged()
{
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;

        //key name (from the keyBoxForm
        if(sender == keyBoxForm->keyName)
        {
            jsonName = "name";
            value = keyBoxForm->keyName->text();
        }
        //key counter stuff
        else if(sender == keyWindowForm->counterMin)
        {
            jsonName = "counter_min";
            value = keyWindowForm->counterMin->value();
        }
        else if(sender == keyWindowForm->counterMax)
        {
            jsonName = "counter_max";
            value = keyWindowForm->counterMax->value();
        }
        else if(sender == keyWindowForm->counterWrap)
        {
            jsonName = "counter_wrap";
            value = keyWindowForm->counterWrap->isChecked();
        }

        emit signalStoreValue(QString("%1_key_").arg(keyInstance+1) + jsonName, value, -1);
    }
    emit signalCheckSavedState();
}

void Key::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    keyBoxForm->keyName->setText(preset.value(QString("%1_key_name").arg(keyInstance+1)).toString());

    keyWindowForm->counterMin->setValue(preset.value(QString("%1_key_counter_min").arg(keyInstance+1)).toInt());
    keyWindowForm->counterMax->setValue(preset.value(QString("%1_key_counter_max").arg(keyInstance+1)).toInt());
    keyWindowForm->counterWrap->setChecked(preset.value(QString("%1_key_counter_wrap").arg(keyInstance+1)).toBool());
}
