// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "presetinterface.h"

PresetInterface::PresetInterface(QWidget *parent) :
    QWidget(parent)
{
    settings = new QSettings(this);

    jsonPath = QCoreApplication::applicationDirPath(); //get bundle path

#if defined(Q_OS_MAC) && !defined(QT_DEBUG)
    jsonPath.remove(jsonPath.length() - 5, jsonPath.length()); //Remove "MacOS" from path string
    jsonPath.append("Resources/presets/softstepezpz.json");
#else
    jsonPath = QString("./presets/softstepadvanced.json");
#endif

    slotReadJSON();

    //writeDefualtJSON();
}

void PresetInterface::slotStoreValue(QString name, QVariant value, int presetNum)
{
    qDebug() << "name" << name << "value" << value << "preset" << presetNum;

    if(presetNum == -1)
    {
        presetNum = currentPresetNum;
    }

    QVariantMap presetMap = jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap();
    presetMap.insert(name, value);
    jsonMasterMapCopy.insert(QString("Preset_00%1").arg(presetNum), presetMap);
}

void PresetInterface::slotCheckSaveState()
{

}

void PresetInterface::slotReadJSON()
{
    //Load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("SoftStep Easy Editor JSON Found");

        QByteArray jsonByteArray = jsonFile->readAll();//load json file into a byte array to be processd by the parser
        jsonMasterMap = parser.parse(jsonByteArray, &ok).toMap(); //parse the json data, convert it to a map and set it equal to the master jsonMap
        jsonMasterMapCopy = jsonMasterMap;

        //-------
        int presetNum = 1;

        QStringList keyList = jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap().keys();

        for(int i = 0; i < keyList.size(); i++)
        {
            if(jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap().value(keyList.at(i)) !=
                    jsonMasterMap.value(QString("Preset_00%1").arg(presetNum)).toMap().value(keyList.at(i)))
            {
                qDebug() << "------------" << keyList.at(i) << jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap().value(keyList.at(i)) << jsonMasterMap.value(QString("Preset_00%1").arg(presetNum)).toMap().value(keyList.at(i));
                //break;
            }
        }
    }
    else
    {
        qDebug() << "SoftStep Advanced Editor JSON Not Found";
    }

    jsonFile->close();
}

void PresetInterface::slotWriteJSON(QVariantMap jsonMap)
{

    //Load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //Serialize JSON, write to file
        QByteArray ba = serializer.serialize(jsonMap); //serialize the master json map into the byte array

        jsonFile->resize(0);
        jsonFile->write(ba);
    }
    else
    {
        qDebug() << "SoftStep Easy Editor JSON Not Found";
    }

    jsonFile->close();
}

void PresetInterface::writeDefualtJSON()
{

}

void PresetInterface::slotConstructDefaultMap()
{

}

void PresetInterface::slotRecallPreset(int i)
{

}

void PresetInterface::slotStoreGlobal()
{

}

void PresetInterface::slotUpdateClicked()
{

}

void PresetInterface::closeEvent(QCloseEvent *)
{
    //qDebug() << "closing...";
}
