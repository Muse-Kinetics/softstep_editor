// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "importoldpresethandler.h"

ImportOldPresetHandler::ImportOldPresetHandler(PresetInterface *pi, QObject *parent) :
    QObject(parent)
{
    presetInterface = pi;
}

void ImportOldPresetHandler::slotImportOldPreset()
{
    QString filename = NULL;
    filename = QFileDialog::getOpenFileName(presetInterface, tr("Import Presets from Old Editor"), QString("./"), tr("SoftStep Editor V1.21 Preset Files (*.json)"));

    //If file is selected
    if(filename != NULL)
    {
        //open file
        QFile* presetFile = new QFile(filename);
        presetFile->open(QIODevice::ReadOnly);

        QByteArray presetByteArray = presetFile->readAll();
        presetFile->close();

        QVariantMap importedMap = presetInterface->parser.parse(presetByteArray, &ok).toMap();

        QMapIterator<QString, QVariant> i(importedMap);

        while(i.hasNext())
        {
            i.next();

            QVariantMap patterstorage = i.value().toMap();

            QMapIterator<QString, QVariant> j(patterstorage);

            while(j.hasNext())
            {
                j.next();

                QVariantMap slot = j.value().toMap();

                QMapIterator<QString, QVariant> k(slot);

                while(k.hasNext())
                {
                    k.next();

                    //qDebug() << k.key();

                    QVariantMap slotNum = k.value().toMap();

                    QMapIterator<QString, QVariant> l(slotNum);

                    while(l.hasNext())
                    {
                        l.next();

                        if(l.key() == "data")
                        {
                            importedOldPresetMap = l.value().toMap();
                            //qDebug() << "importOldPreset Data:" << importedOldPresetMap;

                            importedNewPresetMap = slotConvertPreset();

                            //get the preset name
                            presetName = slotNum.value("name").toString();
                            importedNewPresetMap.insert("preset_name", presetName);
                            qDebug() << "Name of Importing Preset" << presetName;

                            //---------- Set Imported Preset to new preset and update ----------
                            presetInterface->presetListCopy.clear();
                            presetInterface->presetListMaster.clear();

                            int numPresets = presetInterface->slotGetNumPresetsInJson();

                            for(int i = 0; i < numPresets; i++)
                            {
                                presetInterface->presetListCopy.append(presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(i)).toMap());
                                presetInterface->presetListMaster.append(presetInterface->jsonMasterMapCopy.value(presetInterface->slotGetPresetStringFromInt(i)).toMap());
                            }
                            presetInterface->presetListCopy.append(importedNewPresetMap);
                            presetInterface->presetListMaster.append(importedNewPresetMap);

                            presetInterface->slotOrderPresetsInJson();
                            presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
                            emit signalAddRemovePreset();
                            emit signalPresetMenu(numPresets);
                        }
                    }
                }
            }
        }
        //qDebug() << importedPresetMap;
    }
    else
    {
        qDebug("nothing selected");
    }
}

QVariantMap ImportOldPresetHandler::slotConvertPreset()
{
    //set which default map we're starting with
    if(mode == "hosted")
    {
        presetInterface->slotConstructDefaultHostedMap();
    }
    else if(mode == "standalone")
    {
        presetInterface->slotConstructDefaultStandaloneMap();
    }

    QVariantMap newMap = presetInterface->defaultPresetMap;

    QMapIterator<QString, QVariant> newParams(presetInterface->defaultPresetMap);
    while(newParams.hasNext())
    {
        newParams.next();
        QString newParameterName = newParams.key();
        //iterate through all parameters pertaining to a key
        for(int i = 0; i < 10; i++)
        {
            //iterate through all parameters pertaining to a modline within the key
            for(int j = 0; j < 6; j++)
            {
                if(newParameterName.contains(QString("key%1_modline%2_").arg(i+1).arg(j+1)))
                {
                    //--------------------here's where modline parameters get converted
                    QString oldParameterName = "NULL";

                    if(newParameterName.contains(QString("enable")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::On").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("initmode")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Init_Logic").arg(i+1).arg(j+1);
                        QString value = importedOldPresetMap.value(oldParameterName).toList().at(0).toString();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("initvalue")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Init").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                }
            }
        }
    }
    return newMap;
}

void ImportOldPresetHandler::slotSetMode(QString m)
{
    mode = m;
}
