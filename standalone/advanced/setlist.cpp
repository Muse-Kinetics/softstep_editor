// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "setlist.h"

Setlist::Setlist(QWidget *parent) :
    QWidget(parent),
    setlistForm(new Ui::setlistForm)
{
    setlistWidget = new QWidget();
    setlistForm->setupUi(setlistWidget);

    slotInitComponents();

}

bool Setlist::eventFilter(QObject *obj, QEvent *event)
{
    if((event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick) && obj->objectName().contains("enable"))
    {
        QCheckBox* checkBox = (QCheckBox*)obj;
        int i = checkBox->objectName().remove("enable").toInt();

        QComboBox* menu = setlistWidget->findChild<QComboBox *>(QString("setlistmenu%1").arg(i));
        qDebug() << "moust evnet" << i << menu->currentText();

        if(checkBox->isChecked())
        {
            menu->setCurrentIndex(0);
            checkBox->setChecked(false);
        }

        return true;
    }

    return false;
}

void Setlist::slotCheckBoxClicked()
{

}

void Setlist::slotMenuChanged(int menuNum)
{
    QComboBox* menu = (QComboBox*)QObject::sender();
    int i = menu->objectName().remove("setlistmenu").toInt();
    QCheckBox* checkBox = setlistWidget->findChild<QCheckBox *>(QString("enable%1").arg(i));

    if(menu->currentIndex() == 0)
    {
        checkBox->setChecked(false);
    }
    else
    {
        checkBox->setChecked(true);
    }
}

void Setlist::slotInitComponents()
{
    foreach(QWidget* widget, setlistWidget->findChildren<QWidget *>())
    {
        if(widget->objectName().contains("enable"))
        {
            QCheckBox *checkBox = reinterpret_cast<QCheckBox *>(widget);
            checkBoxes.append(checkBox);
            checkBox->installEventFilter(this);
            //connect(checkBox, SIGNAL(clicked()), this, SLOT(slotCheckBoxClicked()));
        }
        else if(widget->objectName().contains("menu"))
        {
            QComboBox *comboBox = reinterpret_cast<QComboBox *>(widget);
            menus.append(comboBox);
            connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotMenuChanged(int)));
        }
    }
}

void Setlist::slotShowSetlist()
{
    setlistWidget->show();
}

void Setlist::slotPopulateMenus(QVariantMap jsonMasterCopy)
{
    qDebug() << "populate menus";

    //Iterate through menus
    for(int m = 0; m < menus.size(); m++)
    {
        //Clear current menu
        menus.at(m)->clear();

        //Populate off item
        menus.at(m)->addItem("[EMPTY]");

        //Iterate through presets
        QVariantMap::iterator i;

        for(i = jsonMasterCopy.begin(); i != jsonMasterCopy.end(); i++)
        {
            //Current preset
            QVariantMap preset = i.value().toMap();

            if(i.key().contains("Preset_"))
            {
                //Append name to current menu
                menus.at(m)->addItem(preset.value("preset_name").toString(),0);
            }
        }
    }
}
