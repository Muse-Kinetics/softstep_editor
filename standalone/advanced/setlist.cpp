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
    setlistWidget->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
    //setlistWidget = new QWidget();
    setlistForm->setupUi(setlistWidget);

    slotInitComponents();

    repopulating = false;

    currentSetlistSlot = -1;

    // If setlist JSON files do not exist in AppDataLocation, copy the defaults from the application bundle dir.

    // Get platform dependant path to read only setlists directory inside the app bundle/package
    QString appPackageDirPath = QCoreApplication::applicationDirPath();

#if defined(Q_OS_MAC)
    //Remove "MacOS" from path string
    appPackageDirPath.remove(appPackageDirPath.length() - 5, appPackageDirPath.length());

    QString setlistsDirSrcPath = appPackageDirPath + "Resources/presets";
#else
    QString setlistsDirSrcPath = QString("./presets");
#endif

    // Get path to writeable app data directory
    QString appDataDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    if (appDataDirPath.isEmpty()) {
        qFatal("Cannot determine setlist storage location");
    }

    // Create destination setlists subdirectory if it doesn't exist
    QString setlistsDirDestPath = appDataDirPath;

    if (!QDir(setlistsDirDestPath).exists()) {
        QDir().mkpath(setlistsDirDestPath);
    }

    // If either setlist file doesn't exist at the destination, copy it there
    QString setlistFileDestPath = setlistsDirDestPath + "/hosted_setlist.json";
    QString setlistFileSrcPath = setlistsDirSrcPath + "/hosted_setlist.json";

    if (!QFile::exists(setlistFileDestPath))
    {
        if (QFile::copy(setlistFileSrcPath, setlistFileDestPath) == false) {
            qFatal("Cannot copy default setlist file to application data path!");
        }
    }

    // Non-hosted setlists file
    setlistFileDestPath = setlistsDirDestPath + "/setlist.json";
    setlistFileSrcPath = setlistsDirSrcPath + "/setlist.json";

    if (!QFile::exists(setlistFileDestPath))
    {
        if (QFile::copy(setlistFileSrcPath, setlistFileDestPath) == false) {
            qFatal("Cannot copy default setlist file to application data path!");
        }
    }
}

QStringList Setlist::getSetlistMap()
{

    //Get's an ordered setlist, removes empties

    QStringList setlistList;

    foreach(QComboBox *menu, menus)
    {
        QString currentText = menu->currentText();

        if(currentText != "[EMPTY]")
        {
            setlistList.append(currentText);
        }
    }

    return setlistList;
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
    Q_UNUSED(menuNum);

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
    //-------- Adds items to setlist menu

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
    QString appDataDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString setlistsDirDestPath = appDataDirPath;

    jsonPath = setlistsDirDestPath;

    if(mode == "hosted") {
        jsonPath.append("/hosted_setlist.json");
    } else {
        jsonPath.append("/setlist.json");
    }

    // Fixme: don't leave this on
    // qDebug() << jsonPath;
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
