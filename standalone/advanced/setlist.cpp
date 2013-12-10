// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "setlist.h"

Setlist::Setlist(QWidget *parent) :
    QWidget(parent),
    setlistForm(new Ui::setlistForm),
    setlistWidget(new QWidget(this))
{
    setlistWidget->hide();
    setlistWidget->setWindowFlags(Qt::Tool | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint| Qt::WindowStaysOnTopHint);
    //setlistWidget = new QWidget();
    setlistForm->setupUi(setlistWidget);

    slotInitComponents();

    repopulating = false;

    currentSetlistSlot = -1;


}

bool Setlist::eventFilter(QObject *obj, QEvent *event)
{
    if((event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick) && obj->objectName().contains("enable"))
    {
        QCheckBox* checkBox = (QCheckBox*)obj;
        int i = checkBox->objectName().remove("enable").toInt();

        QComboBox* menu = setlistWidget->findChild<QComboBox *>(QString("setlistmenu%1").arg(i));
        //qDebug() << "moust evnet" << i << menu->currentText();

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
    setlistWidget->raise();
}

void Setlist::slotCompileSetlist()
{
    //qDebug() << "slot compile setlist called";

    //Clears the setlist read from json
    setlist.clear();
    setlistEmpty = true;

    //Iterate through the setlist window's menus
    for(int i = 0; i < menus.size(); i++)
    {
        //Compiles setlist from contents of setlist window menus
        setlist.insert(QString("%1").arg(i), menus.at(i)->currentText());

        if(!menus.at(i)->currentText().contains("[EMPTY]"))
        {
            setlistEmpty = false;
        }
    }

    slotWriteSetlist();
}

void Setlist::slotPopulateSetlistMenus(QComboBox* presetMenu)
{
    //qDebug() << "populate setlist menus";
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

void Setlist::slotRefreshSetlistMenus(QComboBox* presetMenu)
{
    //qDebug() << "refresh setlist";

    repopulating = true;

    //Iterate through setlist and re-set current indexes to what's in the setlist, necessary after repopulating the menus (adding, deletion, mode switching)
    for(int i = 0; i < setlist.size(); i++)
    {
        //qDebug() << setlist.value(QString("%1").arg(i)).toString() << presetMenu->findText(setlist.value(QString("%1").arg(i)).toString());

        menus.at(i)->setCurrentIndex(presetMenu->findText(setlist.value(QString("%1").arg(i)).toString()) + 1); //offset because presetlist has no empty
    }

    repopulating = false;

    //Recompile setlist
    slotCompileSetlist();
}

void Setlist::slotSetMode(QString m)
{
    //Update mode and setlist file path
    mode = m;
}

void Setlist::slotUpdateJSONPath()
{
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
}

void Setlist::slotReadSetlist()
{
    //Load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //qDebug("Setlist JSON Found");

        QByteArray setlistByteArray = jsonFile->readAll();

        setlist = parser.parse(setlistByteArray, &ok).toMap(); //parse the json data, convert it to a map and set it equal to the master jsonMap
    }
    else
    {
        //qDebug() << "Setlist Not Found";
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
        //qDebug() << "Setlist not found on write";
    }

    jsonFile->close();
}

void Setlist::slotChangePreset(bool prevOrNext)
{
    //qDebug() << "setlist empty" << setlistEmpty;
    //If setlist is NOT empty
    if(!setlistEmpty)
    {
        int initialSlot = currentSetlistSlot;

        //If move to next command...
        if(prevOrNext)
        {
            //qDebug() << "current setlist slot" << currentSetlistSlot << menus.size();

            //Inc setlist slot
            currentSetlistSlot++;

            //If setlist current slot is greater than number of slots, set to 0
            if(currentSetlistSlot == -1 || (currentSetlistSlot > menus.size() - 1))
            {
                currentSetlistSlot = 0;
            }

            //If new slot is empty search for next NON-EMPTY slot
            while(menus.at(currentSetlistSlot)->currentText().contains("[EMPTY]"))
            {
                //qDebug() << "current setlist slot in loope" << currentSetlistSlot << menus.size();
                if(currentSetlistSlot < menus.size() -1)
                {
                    currentSetlistSlot++;
                }
                else
                {
                    currentSetlistSlot = 0;
                }
            }
        }

        //If move to prev command...
        else
        {
            //Dec setlist slot
            currentSetlistSlot--;

            //If slot is less than 0, wrap to last (greatest) slot
            if(currentSetlistSlot < 0)
            {
                currentSetlistSlot = menus.size() - 1;
            }

            //If new slot is empty, search backwards for next NON-EMPTY slot
            while(menus.at(currentSetlistSlot)->currentText().contains("[EMPTY]"))
            {
                if(currentSetlistSlot > 0)
                {
                    currentSetlistSlot--;
                }
                else
                {
                    currentSetlistSlot = menus.size() - 1;
                }
            }
        }

        //Recall this preset
        if(currentSetlistSlot != -1)
        {
            emit signalRecallPresetFromSetlist(setlist.value(QString("%1").arg(currentSetlistSlot)).toString());
            //setlist.value(QString("%1").arg(currentSetlistSlot));
        }
    }

    //If setlist is empty
    else
    {
        currentSetlistSlot = -1;
    }
}
