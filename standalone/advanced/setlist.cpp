// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "setlist.h"

Setlist::Setlist(QWidget *parent) :
    QWidget(parent),
    setlistForm(new Ui::setlistForm),
    setlistWidget(new QWidget())
{
    //setlistWidget = new QWidget();
    setlistForm->setupUi(setlistWidget);

    slotInitComponents();

    repopulating = false;


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
    slotCompileSetlist();
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

    if(!repopulating)
    {
        slotCompileSetlist();
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

void Setlist::slotCompileSetlist()
{
    setlist.clear();

    //Iterate through menus and reset setlist
    for(int i = 0; i < menus.size(); i++)
    {
        //setlist.append(menus.at(i)->currentText());
    }

    qDebug() << setlist;
}

void Setlist::slotPopulateMenus(QComboBox* presetMenu)
{
    qDebug() << "populate menus";
    repopulating = true;

    //Iterate through menus
    for(int m = 0; m < menus.size(); m++)
    {
        //Clear current menu
        menus.at(m)->clear();

        //Populate off item
        menus.at(m)->addItem("[EMPTY]");

        for(int i = 0; i < presetMenu->count(); i++)
        {
            menus.at(m)->addItem(presetMenu->itemText(i), 0);
        }
    }

    repopulating = false;
}

void Setlist::slotRefreshSetlist(QComboBox* presetMenu)
{
    qDebug() << "refresh setlist";

    repopulating = true;

    //Iterate through setlist to reset menus after a new preset has been added/deleted
    for(int i = 0; i < setlist.size(); i++)
    {
        //qDebug() << setlist.at(i) << presetMenu->findText(setlist.at(i));

        //menus.at(i)->setCurrentIndex(presetMenu->findText(setlist.at(i)) + 1); //offset because presetlist has no empty

        /*//If text of menu not found in preset menu
        if(presetMenu->findText(setlist.at(i)) == -1)
        {
            //Set it to empty
            menus.at(i)->setCurrentIndex(0);
        }
        else
        {

        }*/
    }

    repopulating = false;

    //Recompile setlist
    slotCompileSetlist();
}

void Setlist::slotSetMode(QString m)
{
    //Write setlist in whatever mode we're currently in
    slotWriteSetlist();

    //Update mode and setlist file path
    mode = m;

    jsonPath = QCoreApplication::applicationDirPath(); //get bundle path

#if defined(Q_OS_MAC) && !defined(QT_DEBUG)
    jsonPath.remove(jsonPath.length() - 5, jsonPath.length()); //Remove "MacOS" from path string
    if(mode == "hosted")
    {
        jsonPath.append("Resources/presets/hosted_setlist.json");
    }
    else
    {
        jsonPath.append("Resources/presets/setlist.json");
    }

#else
    if(mode == "hosted")
    {
        jsonPath = QString("./presets/hosted_setlist.json");
    }
    else
    {
        jsonPath = QString("./presets/setlist.json");
    }
#endif

    //Read setlist in new mode
    slotReadSetlist();
}

void Setlist::slotReadSetlist()
{
    //Load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("Setlist JSON Found");

        QByteArray setlistByteArray = jsonFile->readAll();

        setlist = parser.parse(setlistByteArray, &ok).toMap(); //parse the json data, convert it to a map and set it equal to the master jsonMap
    }
    else
    {
        qDebug() << "Setlist Not Found";
    }

    jsonFile->close();
}

void Setlist::slotWriteSetlist()
{
    //Load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //Serialize JSON, write to file
        QByteArray ba = serializer.serialize(setlist); //serialize the master json map into the byte array

        jsonFile->resize(0);
        jsonFile->write(ba);
    }
    else
    {
        qDebug() << "Setlist not found on write";
    }

    jsonFile->close();
}
