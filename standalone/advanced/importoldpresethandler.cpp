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
    filename = QFileDialog::getOpenFileName(presetInterface, tr("Import Presets from SoftStep Editor Version 1.21"), QString("./"), tr("SoftStep Editor V1.21 Preset Files (*SoftStep.json)"));

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
                            slotNormalizePresetMap();

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

void ImportOldPresetHandler::slotNormalizePresetMap()
{
    if(mode == "hosted")
    {
        presetInterface->slotConstructDefaultHostedMap();
    }
    else if(mode == "standalone")
    {
        presetInterface->slotConstructDefaultStandaloneMap();
    }

    QMapIterator<QString, QVariant> i(presetInterface->defaultPresetMap);

    while(i.hasNext())
    {
        i.next();

        //if copying from one mode to the other the device menu values for port 1 should change
        if(i.key().contains("_device"))
        {
            if(importedNewPresetMap.value(i.key()) == "SSCOM Port 1" && mode == "hosted")
            {
                importedNewPresetMap.insert(i.key(), "SoftStep Share");
            }
            else if(importedNewPresetMap.value(i.key()) == "SoftStep Share" && mode == "standalone")
            {
                importedNewPresetMap.insert(i.key(), "SSCOM Port 1");
            }
        }
    }

    //------------ Check for EXTRA parameters in the Imported Preset -------------------
    QMapIterator<QString, QVariant> j(importedNewPresetMap);

    QStringList badKeys;  //stores keys we need to remove from the map

    while(j.hasNext())
    {
        j.next();

        //If the default map does not contain something in the preset
        if(!presetInterface->defaultPresetMap.contains(j.key()))
        {
            //add to list of bad keys
            badKeys.append(j.key());
        }
    }
    //Iterate through the bad keys and remove from preset
    for(int i = 0; i<badKeys.count(); i++)
    {
        importedNewPresetMap.remove(badKeys.at(i));
    }

    presetInterface->defaultPresetMap.clear();
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
        QString oldParameterName = "NULL";

        if(newParameterName.contains(QString("preset_displayname")))
        {
            oldParameterName = QString("Main_Preset_Display::Scene_Abbrev::Scene_Name");
            QString presetValue = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
            newMap.insert(newParameterName, presetValue);
        }
        else
        {
            //iterate through all parameters pertaining to a key
            for(int i = 1; i <= 11; i++)
            {
                if(newParameterName.contains(QString("%1_key_").arg(i)) || newParameterName.contains("nav_"))
                {
                    if(newParameterName.contains(QString("counter_wrap")))
                    {
                        if(newParameterName.contains("nav_"))
                        {
                            oldParameterName = QString("Main_Pad_11::Modulation::Wrap_Y");
                        }
                        else
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Wrap").arg(i);
                        }
                        int keyValue = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, keyValue);
                    }
                    else if(newParameterName.contains(QString("counter_min")))
                    {
                        if(newParameterName.contains("nav_"))
                        {
                            oldParameterName = QString("Main_Pad_11::Modulation::Min_Y");
                        }
                        else
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Min").arg(i);
                        }
                        int keyValue = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, keyValue);
                    }
                    else if(newParameterName.contains(QString("counter_max")))
                    {
                        if(newParameterName.contains("nav_"))
                        {
                            oldParameterName = QString("Main_Pad_11::Modulation::Max_Y[1]");
                        }
                        else
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Max").arg(i);
                        }
                        int keyValue = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, keyValue);
                    }
                    else if(newParameterName.contains(QString("_name")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Key_Name::Key_Name").arg(i);
                        QString keyValue = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, keyValue);
                    }
                    else if(newParameterName.contains(QString("_prefix")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Prefix::Prefix_Name").arg(i);
                        QString keyValue = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, keyValue);
                    }
                    else if(newParameterName.contains(QString("_displaymode")))
                    {
                        oldParameterName = QString("Main_Pad_%1::Modulation::Display_Mode::Display_Mode").arg(i);
                        QString keyValue = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                        newMap.insert(newParameterName, keyValue);
                        //qDebug() << "Display Mode Old Parameter:" << importedOldPresetMap.value(oldParameterName);
                        //qDebug() << "Display Mode Parameter Imported:" << newParameterName << keyValue;
                    }
                    else if(newParameterName.contains("nav_modlinemode"))
                    {
                        //the nav pad's modline mode is saved in two different parameters in the old editor -- this converts it to one for the new single parameter
                        QString oldModlineMode = QString("Main_Pad_11::Modulation::Nav_Modline_Mode");
                        QString oldProgramMode = QString("Main_Pad_11::Modulation::Nav_Pgm_Change_Mode");
                        int oldModlineValue = slotEmptyListCompensation(oldModlineMode, importedOldPresetMap.value(oldModlineMode).toList());
                        int oldProgramValue = slotEmptyListCompensation(oldProgramMode, importedOldPresetMap.value(oldProgramMode).toList());
                        if(oldModlineValue == 1 && oldProgramValue == 0)
                        {
                            newMap.insert(newParameterName, oldProgramValue);
                            //qDebug() << "nav modline mode should be 0, it is:" << oldProgramValue;
                        }
                        else if(oldProgramValue == 1 && oldModlineValue == 0)
                        {
                            newMap.insert(newParameterName, oldProgramValue);
                        }
                        else
                        {
                            newMap.insert(newParameterName, 0);
                        }
                    }
                }

                //iterate through all parameters pertaining to a modline within the key
                for(int j = 1; j <= 6; j++)
                {
                    if(newParameterName.contains(QString("key%1_modline%2_").arg(i).arg(j)) || newParameterName.contains(QString("nav_modline%1").arg(j)))
                    {
                        //--------------------here's where modline parameters get converted
                        if(newParameterName.contains(QString("enable")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::On").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("initmode")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Init_Logic").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("initvalue")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Init").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("source")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Source").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("modline%1_gain").arg(j)))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Gain").arg(i).arg(j);
                            double value = importedOldPresetMap.value(oldParameterName).toList().at(0).toDouble();
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("offset")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Offset").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("table")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Table").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, slotGetNewTableValue(value));
                        }
                        else if(newParameterName.contains(QString("modline%1_min").arg(j)))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Min").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("modline%1_max").arg(j)))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Max").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("slew")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Slew").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("destination")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Destination").arg(i).arg(j);
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
                            oldParameterName = slotGetOldDestinationParam("note", i, j);
                            int value;
                            if(oldParameterName != "")
                            {
                                value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                                newMap.insert(newParameterName, value);
                            }
                        }
                        else if(newParameterName.contains(QString("cc")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Control_Number").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("velocity")))
                        {
                            oldParameterName = slotGetOldDestinationParam("velocity", i, j);
                            int value;
                            if(oldParameterName != "")
                            {
                                value = importedOldPresetMap.value(oldParameterName).toList().at(0).toInt();
                                newMap.insert(newParameterName, value);
                            }
                        }
                        else if(newParameterName.contains(QString("channel")))
                        {
                            oldParameterName = slotGetOldDestinationParam("channel", i, j);
                            int value;
                            if(oldParameterName != "")
                            {
                                value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                                newMap.insert(newParameterName, value);
                            }
                        }
                        else if(newParameterName.contains(QString("mmcid")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::MMC_Device_ID").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("mmcfunction")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::MMC_Function").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("oscroute")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::OSC_Route").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("device")))
                        {
                            oldParameterName = slotGetOldDestinationParam("device", i, j);
                            QString value;
                            if(oldParameterName != "")
                            {
                                value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                                newMap.insert(newParameterName, value);
                            }
                        }
                        else if(newParameterName.contains(QString("ledgreen")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::LED_Menu_Green").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("ledred")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::LED_Menu_Red").arg(i).arg(j);
                            QString value = slotListErrorCompensation(importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                        else if(newParameterName.contains(QString("displaylinked")))
                        {
                            oldParameterName = QString("Main_Pad_%1::Modulation::Modline_%2::Radio_Button").arg(i).arg(j);
                            int value = slotEmptyListCompensation(oldParameterName, importedOldPresetMap.value(oldParameterName).toList());
                            newMap.insert(newParameterName, value);
                        }
                    }
                }
            }
        }
    }
    presetInterface->defaultPresetMap.clear();
    return newMap;
}

int ImportOldPresetHandler::slotEmptyListCompensation(QString oldName, QList<QVariant> valueList)
{
    int valueListLength = valueList.length();
    if(valueListLength > 0)
    {
        return valueList.at(0).toInt();
    }
    else
    {
        if(oldName.contains("Wrap"))
        {
            return 1;
        }
        else if(oldName.contains("Min"))
        {
            return 0;
        }
        else if(oldName.contains("Max"))
        {
            return 127;
        }
        else
        {
            return 0;
        }
    }
}

QString ImportOldPresetHandler::slotListErrorCompensation(QList<QVariant> stringList)
{
    QString fixedString;
    int stringListLength = stringList.length();
    if(stringListLength <= 0)
    {
        fixedString = "  ";
        //qDebug() << "This String was Empty:" << stringList;
    }
    else if(stringListLength == 1)
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
