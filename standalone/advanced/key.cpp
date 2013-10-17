// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "key.h"

#include <QDebug>

/*-------KEYWINDOW SIZE CONSTANTS-------*/
#define KEYWINDOW_WIDTH 1150
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
    keyWindowForm(new Ui::keyWindowForm),
    dataCooker(keyInstanceNum, this),
    keyWindowWidget(new QWidget()),
    keyBoxWidget(new QWidget(this))
{
    keyInstance = keyInstanceNum;

    //Set up the Key Box
    //keyBoxWidget = new QWidget(this);
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
    //keyWindowWidget = new QWidget();
    keyWindowForm->setupUi(keyWindowWidget);
    keyWindowWidget->setFixedSize(KEYWINDOW_WIDTH, KEYWINDOW_HEIGHT);
    keyWindowWidget->setWindowTitle(QString("Key %1 Modulation").arg(keyInstance+1));

    //What's in the Key Box?

    //Carson commented this next line out on 10/11/2013 because there is no longer a keyInstanceLabel in the key box
    //keyBoxForm->keyInstanceLabel->setText(QString("%1").arg((keyInstance + 1)%10));

    connect(keyBoxForm->openWindow,SIGNAL(clicked()), this, SLOT(slotOpenWindow()));


    //Construct Modlines
    for(int i = 0; i < 6; i++)
    {
        modline[i] = new Modline(keyWindowWidget, keyInstance, i);
        modline[i]->slotConnectElements();
    }

    //Carson's attempt to dynamically update the key window instance label — shit works
    keyWindowForm->keyWindowInstanceLabel->setText(QString("%1").arg((keyInstance + 1) % 10));
    keyBoxForm->openWindow->setStyleSheet(stylesheets.keyBoxOpenButtonStyleSheet.at(keyInstance));
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

    //display stuff
    connect(keyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(keyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(keyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //Hosted streaming
    for(int i = 0; i < 6; i++)
    {
        connect(modline[i], SIGNAL(signalSetSource(QString,int)), &dataCooker, SLOT(slotSetSource(QString,int)));
        connect(&dataCooker, SIGNAL(signalTransformSource(int, int, QString)), modline[i], SLOT(slotTransformSource(int, int, QString)));
        connect(modline[i], SIGNAL(hosted_signalSendModlineOutput(int,int)), &dataCooker, SLOT(slotReceiveModlineOutput(int,int)));
    }
}

void Key::slotDisconnectElements()
{
    //key name (from the keyBoxForm)
    disconnect(keyBoxForm->keyName,SIGNAL(textEdited(QString)),this,SLOT(slotValueChanged()));

    //key counter stuff
    disconnect(keyWindowForm->counterMin,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(keyWindowForm->counterMax,SIGNAL(valueChanged(int)),this,SLOT(slotValueChanged()));
    disconnect(keyWindowForm->counterWrap,SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //display stuff
    disconnect(keyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(keyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(keyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));

    //Hosted streaming
    for(int i = 0; i < 6; i++)
    {
        disconnect(modline[i], SIGNAL(signalSetSource(QString,int)), &dataCooker, SLOT(slotSetSource(QString,int)));
        disconnect(&dataCooker, SIGNAL(signalTransformSource(int, int, QString)), modline[i], SLOT(slotTransformSource(int, int, QString)));
        disconnect(modline[i], SIGNAL(hosted_signalSendModlineOutput(int,int)), &dataCooker, SLOT(slotReceiveModlineOutput(int,int)));
    }
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
        //display stuff
        else if(sender == keyWindowForm->displayprefix)
        {
            jsonName = "prefix";
            value = keyWindowForm->displayprefix->text();
        }
        else if(sender == keyWindowForm->keyname)
        {
            jsonName = "name";
            value = keyWindowForm->keyname->text();
        }
        else if(sender == keyWindowForm->leddisplaymode)
        {
            jsonName = "displaymode";
            value = keyWindowForm->leddisplaymode->currentText();
        }

        emit signalStoreValue(QString("%1_key_").arg(keyInstance+1) + jsonName, value, -1);
    }
    emit signalCheckSavedState();
}

void Key::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();

    keyBoxForm->keyName->setText(preset.value(QString("%1_key_name").arg(keyInstance+1)).toString());

    keyWindowForm->counterMin->setValue(preset.value(QString("%1_key_counter_min").arg(keyInstance+1)).toInt());
    keyWindowForm->counterMax->setValue(preset.value(QString("%1_key_counter_max").arg(keyInstance+1)).toInt());
    keyWindowForm->counterWrap->setChecked(preset.value(QString("%1_key_counter_wrap").arg(keyInstance+1)).toBool());

    keyWindowForm->displayprefix->setText(preset.value(QString("%1_key_prefix").arg(keyInstance+1)).toString());
    keyWindowForm->keyname->setText(preset.value(QString("%1_key_name").arg(keyInstance+1)).toString());
    keyWindowForm->leddisplaymode->setCurrentIndex(keyWindowForm->leddisplaymode->findText(preset.value(QString("%1_key_displaymode").arg(keyInstance+1)).toString()));

    slotConnectElements();
}

void Key::slotSetMode(QString mode)
{

}
