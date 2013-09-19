// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "key.h"

#include <QDebug>

Key::Key(QWidget *parent, int keyInstanceNum) :
    QWidget(parent),
    keyBoxForm(new Ui::keyBoxForm),
    keyWindowForm(new Ui::keyWindowForm)
{
    keyInstance = keyInstanceNum;

    //Set up the Key Box
    keyBoxWidget = new QWidget(this);
    keyBoxForm->setupUi(keyBoxWidget);
    keyBoxWidget->setFixedSize(150,125);

    if(keyInstanceNum < 5)
    {
        this->setGeometry(10 + ((keyInstance)*150), 160,150,125);
    }
    else
    {
        this->setGeometry(10 + ((keyInstance - 5)*150), 10,150,125);
    }


    //Set up the Key Window
    keyWindowWidget = new QWidget();
    keyWindowForm->setupUi(keyWindowWidget);
    keyWindowWidget->setFixedSize(1000,250);
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
}

void Key::slotOpenWindow()
{
    qDebug() << QString("Open Key %1 Button clicked! Open the window!").arg(keyInstance+1);
    keyWindowWidget->show();
}

void Key::slotConnectElements()
{
    //something goes here
}
