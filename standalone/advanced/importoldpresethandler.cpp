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
                        QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("initvalue")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Init").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("source")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Source").arg(i+1).arg(j+1);
                        QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("gain")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Gain").arg(i+1).arg(j+1);
                        double value = importedOldPresetMap.value(oldParameterName).toList().at(0).toDouble();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("offset")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Offset").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("table")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Table").arg(i+1).arg(j+1);
                        QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, slotGetNewTableValue(value));
                    }
                    else if(newParameterName.contains(QString("min")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Min").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("max")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Max").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("slew")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Slew").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("destination")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Destination").arg(i+1).arg(j+1);
                        QString tempValue = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());;
                        QString value;
                        //no more garage band or hui parameters, yay!
                        if(tempValue == "GarageBand" || tempValue == "HUI")
                        {
                            value = "None";
                        }
                        else
                        {
                            value = tempValue;
                        }
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("note")))
                    {
                        oldParameterName = slotGetOldDestinationParam("note", i+1, j+1);
                        int value;
                        if(oldParameterName != "")
                        {
                            value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                            newMap.insert(newParameterName, value);
                        }
                    }
                    else if(newParameterName.contains(QString("cc")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Control_Number").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("velocity")))
                    {
                        oldParameterName = slotGetOldDestinationParam("velocity", i+1, j+1);
                        int value;
                        if(oldParameterName != "")
                        {
                            value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                            newMap.insert(newParameterName, value);
                        }
                    }
                    else if(newParameterName.contains(QString("channel")))
                    {
                        oldParameterName = slotGetOldDestinationParam("channel", i+1, j+1);
                        int value;
                        if(oldParameterName != "")
                        {
                            value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                            newMap.insert(newParameterName, value);
                        }
                    }
                    else if(newParameterName.contains(QString("mmcid")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::MMC_Device_ID").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("mmcfunction")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::MMC_Function").arg(i+1).arg(j+1);
                        QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("oscroute")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::OSC_Route").arg(i+1).arg(j+1);
                        QString value = importedOldPresetMap.value(oldParameterName).toList().at(0).toString();
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("device")))
                    {
                        oldParameterName = slotGetOldDestinationParam("device", i+1, j+1);
                        QString value;
                        if(oldParameterName != "")
                        {
                            QString tempValue = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            //--------------------------add the stuff here for Hosted vs Standalone device name changing!!!!!!!!!!!!!!!!!!!!
                            if(tempValue == "SSCOM Port 1" && mode == "hosted")
                            {
                                value = "SoftStep Share";
                            }
                            else if(tempValue == "SoftStep Share" && mode == "standalone")
                            {
                                value = "SSCOM Port 1";
                            }
                            else
                            {
                                value = tempValue;
                            }
                            newMap.insert(newParameterName, value);
                        }
                    }
                    else if(newParameterName.contains(QString("ledgreen")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::LED_Menu_Green").arg(i+1).arg(j+1);
                        QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("ledred")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::LED_Menu_Red").arg(i+1).arg(j+1);
                        QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, value);
                    }
                    else if(newParameterName.contains(QString("displaylinked")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Radio_Button").arg(i+1).arg(j+1);
                        int value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                        newMap.insert(newParameterName, value-1);
                    }
                }
            }
        }
    }
    return newMap;
}

QString ImportOldPresetHandler::slotListErrorCompensation(QList<QVariant> stringList)
{
    QString fixedString;
    int stringListLength = stringList.length();
    //qDebug() << "String:" << stringList << stringListLength;
    if(stringListLength <= 1)
    {
        fixedString = stringList.at(0).toString();
        //qDebug() << "This String didn't need to be FIXED:" << fixedString;
    }
    else
    {
        for(int i = 0; i < stringListLength; i++)
        {
            fixedString.append(stringList.at(i).toString());
            if(i != stringListLength-1)
            {
                fixedString.append(" ");
            }
        }
        //qDebug() << "This String has been FIXED:" << fixedString;
    }

    return fixedString;
}

QString ImportOldPresetHandler::slotGetNewTableValue(QString oldValue)
{
    QString newValue;

    if(oldValue == "1 Lin")
    {
        newValue = "Linear";
    }
    else if(oldValue == "2 Sin")
    {
        newValue = "Sine";
    }
    else if(oldValue == "3 Cos")
    {
        newValue = "Cosine";
    }
    else if(oldValue == "4 Exponential")
    {
        newValue = "Exponential";
    }
    else if(oldValue == "5 Logarithmic")
    {
        newValue = "Logarithmic";
    }
    else if(oldValue == "Toggle")
    {
        newValue = "Toggle";
    }
    else if(oldValue == "Toggle 127")
    {
        newValue = "Toggle";
    }
    else if(oldValue == "Counter Inc")
    {
        newValue = "Counter Inc";
    }
    else if(oldValue == "Counter Dec")
    {
        newValue = "Counter Dec";
    }
    else if(oldValue == "Counter Set")
    {
        newValue = "Counter Set";
    }
    else
    {
        newValue = "Linear";
    }
    return newValue;
}

QString ImportOldPresetHandler::slotGetOldDestinationParam(QString newParam, int keyNum, int modlineNum)
{
    QString oldName;
    QString destinationType = importedOldPresetMap.value(QString("Main_Pad_%1::Modulation::Modline_%2::Destination").arg(keyNum).arg(modlineNum)).toList().at(0).toString();

    if(newParam == "note")
    {
        if(destinationType == "Note Set")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Number").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Poly Aftertouch")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Poly_Note").arg(keyNum).arg(modlineNum);
        }
        else
        {
            oldName = "";
        }

    }
    else if(newParam == "velocity")
    {
        if(destinationType == "Note Set")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Velocity").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Note Live")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Live_Velocity").arg(keyNum).arg(modlineNum);
        }
        else
        {
            oldName = "";
        }
    }
    else if(newParam == "channel")
    {
        if(destinationType == "Note Set")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Note Live")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Live_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "CC")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Control_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Bank")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Bank_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Program")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Program_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Pitch Bend")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Bend_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Aftertouch")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Aftertouch_Channel").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Poly Aftertouch")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Poly_Channel").arg(keyNum).arg(modlineNum);
        }
        else
        {
            oldName = "";
        }

    }
    else if(newParam == "device")
    {
        if(destinationType == "Note Set")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Note Live")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Note_Live_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "CC")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Control_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Bank")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Bank_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Program")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Program_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Pitch Bend")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Bend_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "MMC")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::MMC_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Aftertouch")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Aftertouch_Device").arg(keyNum).arg(modlineNum);
        }
        else if(destinationType == "Poly Aftertouch")
        {
            oldName = QString("Main_Pad_%1::Modulation::Modline_%2::Poly_Device").arg(keyNum).arg(modlineNum);
        }
        else
        {
            oldName = "";
        }
    }

    return oldName;

}

void ImportOldPresetHandler::slotSetMode(QString m)
{
    mode = m;
}
