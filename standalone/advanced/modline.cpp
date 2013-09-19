// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "modline.h"

Modline::Modline(QWidget *parent, int modlineInstance) :
    QWidget(parent)
{
    instance = modlineInstance;

    this->setObjectName(QString("%1_Modline").arg(modlineInstance));

    //---------------------------------------- Set Up Ui
    QWidget *formWidget = new QWidget(this);

    modlineForm.setupUi(formWidget);
    this->setFixedSize(550,30);

    modlineForm.instanceLabel->setText(QString("%1").arg((modlineInstance + 1)%10));

    this->setGeometry(10,10 + ((modlineInstance)*31),550,30);
}

void Modline::slotConnectElements()
{
    //gain
    connect(modlineForm.gain,SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
}

void Modline::slotValueChanged()
{
    //emit signalStoreValue(QString("%1_modline_gain").arg(instance), modlineForm.gain->value(), -1);
}
