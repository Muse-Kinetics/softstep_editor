// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "key.h"

Key::Key(QWidget *parent, int instanceNum) :
    QWidget(parent)
{
    instance = instanceNum;

    //---------------------------------------- Set Up Ui
    QWidget *formWidget = new QWidget(this);

    keyForm.setupUi(formWidget);
    this->setFixedSize(161,129);

    keyForm.instanceLabel->setText(QString("Key %1").arg((instanceNum + 1)%10));

     if(instanceNum < 5)
    {
        this->setGeometry(1 + ((instanceNum)*123),117,150,150);
    }
    else
    {
        this->setGeometry(1 + ((instanceNum-5)*123),1,150,150);
    }

    //---------------------------------------- Populate Checkbox list
    checkBoxes.append(keyForm.footOn);
    checkBoxes.append(keyForm.pressure);
    checkBoxes.append(keyForm.yInc);
    checkBoxes.append(keyForm.toggle);
    checkBoxes.append(keyForm.xLive);

    slotConnectElements();
}


void Key::slotConnectElements()
{
    connect(keyForm.footOn, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(keyForm.pressure, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(keyForm.yInc, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(keyForm.toggle, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(keyForm.xLive, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(keyForm.name, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
    connect(keyForm.cc, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    connect(keyForm.smooth, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
}

void Key::slotValueChanged()
{

    QObject *sender = QObject::sender();

    qDebug() << "sender" << sender->objectName() << "instance" << instance;

    if(sender == keyForm.name)
    {
        emit signalStoreValue(QString("%1_Key_Key_Name").arg(instance), keyForm.name->text(), -1);
    }
    else if (sender == keyForm.cc)
    {
        emit signalStoreValue(QString("%1_Key_CC").arg(instance), keyForm.cc->value(), -1);
    }
    else if (sender == keyForm.smooth)
    {
        emit signalStoreValue(QString("%1_Key_Smooth").arg(instance), keyForm.smooth->value(), -1);
    }

    //Handle mutant radio button checkboxes
    else
    {
        for(int i = 0; i < checkBoxes.count(); i++)
        {
            if(reinterpret_cast<QCheckBox *>(sender) != checkBoxes.at(i))
            {
                checkBoxes.at(i)->setChecked(false);
            }
        }
    }

    emit signalStoreValue(QString("%1_Key_Foot_On").arg(instance), int(keyForm.footOn->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Pressure_Live").arg(instance), int(keyForm.pressure->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Y_Increment").arg(instance), int(keyForm.yInc->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Toggle").arg(instance), int(keyForm.toggle->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_X_Live").arg(instance), int(keyForm.xLive->isChecked()), -1);

    slotUpdateSourceAndTable();

}

void Key::slotUpdateSourceAndTable()
{
    if(keyForm.footOn->isChecked())
    {
        source = "Foot_On";
        table = "1_Lin";
    }
    else if(keyForm.pressure->isChecked())
    {
        source = "Pressure_Live";
        table = "1_Lin";
    }
    else if(keyForm.yInc->isChecked())
    {
        source = "Y_Increment";
        table = "1_Lin";
    }
    else if(keyForm.toggle->isChecked())
    {
        source = "Foot_On";
        table = "Toggle_127";
    }
    else if(keyForm.xLive->isChecked())
    {
        source = "X_Live";
        table = "1_Lin";
    }
    else
    {
        source = "None";
        table = "1_Lin";
    }

    emit signalStoreValue(QString("%1_Key_Source").arg(instance), source, -1);
    emit signalStoreValue(QString("%1_Key_Table").arg(instance), table, -1);

}

void Key::slotRecallPreset(QVariantMap preset)
{
    qDebug() << "--------------------------------------- recall preset" << instance;
    keyForm.footOn->setChecked(preset.value(QString("%1_Key_Foot_On").arg(instance)).toInt());
    keyForm.pressure->setChecked(preset.value(QString("%1_Key_Pressure_Live").arg(instance)).toInt());
    keyForm.yInc->setChecked(preset.value(QString("%1_Key_Y_Increment").arg(instance)).toInt());
    keyForm.toggle->setChecked(preset.value(QString("%1_Key_Toggle").arg(instance)).toInt());
    keyForm.xLive->setChecked(preset.value(QString("%1_Key_X_Live").arg(instance)).toInt());

    keyForm.name->setText(preset.value(QString("%1_Key_Key_Name").arg(instance)).toString());
    keyForm.cc->setValue(preset.value(QString("%1_Key_CC").arg(instance)).toInt());
    keyForm.smooth->setValue(preset.value(QString("%1_Key_Smooth").arg(instance)).toInt());

    source = preset.value(QString("%1_Key_Source").arg(instance)).toString();
    table = preset.value(QString("%1_Key_Table").arg(instance)).toString();
}

void Key::slotLoadTemplate(int tem)
{
    if(tem == 0)
    {
        if(instance < 5)
        {
            source = QString("Pressure_Live");
            table = QString("1_Lin");

            for(int i =0 ; i < checkBoxes.count(); i++)
            {
                checkBoxes.at(i)->setChecked(false);
            }

            keyForm.pressure->setChecked(true);

            keyForm.name->setText(QString("PRS%1").arg((instance + 1)%10));
            keyForm.cc->setValue((instance + 1)%10 + 20);
            keyForm.smooth->setValue(0);
        }
        else
        {
            source = QString("Foot_On");
            table = QString("Toggle_127");

            for(int i =0 ; i < checkBoxes.count(); i++)
            {
                checkBoxes.at(i)->setChecked(false);
            }

            keyForm.toggle->setChecked(true);

            keyForm.name->setText(QString("TOG%1").arg((instance + 1)%10));
            keyForm.cc->setValue((instance + 1) + 20);
            keyForm.smooth->setValue(0);
        }
    }
    else
    {
        source = QString("Y_INcrement");
        table = QString("1_Lin");

        for(int i =0 ; i < checkBoxes.count(); i++)
        {
            checkBoxes.at(i)->setChecked(false);
        }

        keyForm.yInc->setChecked(true);

        keyForm.name->setText(QString("FAD%1").arg((instance + 1)%10));
        keyForm.cc->setValue((instance + 1) + 80);
        keyForm.smooth->setValue(0);
    }

    emit signalStoreValue(QString("%1_Key_Foot_On").arg(instance), int(keyForm.footOn->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Pressure_Live").arg(instance), int(keyForm.pressure->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Y_Increment").arg(instance), int(keyForm.yInc->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Toggle").arg(instance), int(keyForm.toggle->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_X_Live").arg(instance), int(keyForm.xLive->isChecked()), -1);
    emit signalStoreValue(QString("%1_Key_Source").arg(instance), source, -1);
    emit signalStoreValue(QString("%1_Key_Table").arg(instance), table, -1);
    emit signalStoreValue(QString("%1_Key_Key_Name").arg(instance), keyForm.name->text(), -1);
    emit signalStoreValue(QString("%1_Key_CC").arg(instance), keyForm.cc->value(), -1);
    emit signalStoreValue(QString("%1_Key_Smooth").arg(instance), keyForm.smooth->value(), -1);
}


















