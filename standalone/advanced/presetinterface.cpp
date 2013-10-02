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
    //qDebug() << "name" << name << "value" << value << "preset" << presetNum;

    if(presetNum == -1)
    {
        presetNum = currentPresetNum;
    }

    /*if(name.contains("settings"))
    {
        QVariantMap globalMap = jsonMasterMapCopy.value(QString("Global")).toMap();
        globalMap.insert(name, value);
        jsonMasterMapCopy.insert(QString("Global"), globalMap);
    }
    else
    {
        QVariantMap presetMap = jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap();
        presetMap.insert(name, value);
        jsonMasterMapCopy.insert(QString("Preset_00%1").arg(presetNum), presetMap);
    }*/

    QVariantMap presetMap = jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap();
    presetMap.insert(name, value);
    jsonMasterMapCopy.insert(QString("Preset_00%1").arg(presetNum), presetMap);
}

void PresetInterface::slotStoreGlobal(QString name, QVariant value)
{
    QVariantMap globalMap = jsonMasterMapCopy.value(QString("Global")).toMap();
    globalMap.insert(name, value);
    jsonMasterMapCopy.insert(QString("Global"), globalMap);
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
    slotConstructDefaultMap();
    slotConstructGlobalDefaultMap();

    //Generate fresh default json needed
    for(int i = 0; i < 4; i++)
    {
        jsonMasterMap.insert(QString("Preset_00%1").arg(i),defaultPresetMap);

        //Globals
        //jsonMasterMap.insert("sensitivity", 1.00);
        //jsonMasterMap.insert("backlight", true);
    }

    jsonMasterMap.insert(QString("Global"),defaultGlobalMap);

    slotWriteJSON(jsonMasterMap);
}

void PresetInterface::slotConstructDefaultMap()
{
    //------------------------ Key 1 ------------------------//
    defaultPresetMap["1_key_name"] = "1KEY";
    defaultPresetMap["1_key_displaymode"] = 1;
    defaultPresetMap["1_key_prefix"] = "";
    defaultPresetMap["1_key_counter_min"] = 0;
    defaultPresetMap["1_key_counter_max"] = 127;
    defaultPresetMap["1_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key1_modline1_enable"] = 0;
    defaultPresetMap["key1_modline1_initValue"] = 0;
    defaultPresetMap["key1_modline1_initMode"] = "None";
    defaultPresetMap["key1_modline1_source"] = "None";
    defaultPresetMap["key1_modline1_gain"] = 1.00;
    defaultPresetMap["key1_modline1_offset"] = 0;
    defaultPresetMap["key1_modline1_table"] = "Lin";
    defaultPresetMap["key1_modline1_min"] = 0;
    defaultPresetMap["key1_modline1_max"] = 127;
    defaultPresetMap["key1_modline1_slew"] = 0;
    defaultPresetMap["key1_modline1_delay"] = 0;
    defaultPresetMap["key1_modline1_destination"] = "None";
    defaultPresetMap["key1_modline1_note"] = 60;
    defaultPresetMap["key1_modline1_velocity"] = 127;
    defaultPresetMap["key1_modline1_cc"] = 60;
    defaultPresetMap["key1_modline1_bankMSB"] = 0;
    defaultPresetMap["key1_modline1_mmcid"] = 0;
    defaultPresetMap["key1_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key1_modline1_channel"] = 1;
    defaultPresetMap["key1_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key1_modline1_oscroute"] = "";
    defaultPresetMap["key1_modline1_ledgreen"] = "Off";
    defaultPresetMap["key1_modline1_ledred"] = "Off";
    defaultPresetMap["key1_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key1_modline2_enable"] = 0;
    defaultPresetMap["key1_modline2_initValue"] = 0;
    defaultPresetMap["key1_modline2_initMode"] = "None";
    defaultPresetMap["key1_modline2_source"] = "None";
    defaultPresetMap["key1_modline2_gain"] = 1.00;
    defaultPresetMap["key1_modline2_offset"] = 0;
    defaultPresetMap["key1_modline2_table"] = "Lin";
    defaultPresetMap["key1_modline2_min"] = 0;
    defaultPresetMap["key1_modline2_max"] = 127;
    defaultPresetMap["key1_modline2_slew"] = 0;
    defaultPresetMap["key1_modline2_delay"] = 0;
    defaultPresetMap["key1_modline2_destination"] = "None";
    defaultPresetMap["key1_modline2_note"] = 60;
    defaultPresetMap["key1_modline2_velocity"] = 127;
    defaultPresetMap["key1_modline2_cc"] = 60;
    defaultPresetMap["key1_modline2_bankMSB"] = 0;
    defaultPresetMap["key1_modline2_mmcid"] = 0;
    defaultPresetMap["key1_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key1_modline2_channel"] = 1;
    defaultPresetMap["key1_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key1_modline2_oscroute"] = "";
    defaultPresetMap["key1_modline2_ledgreen"] = "Off";
    defaultPresetMap["key1_modline2_ledred"] = "Off";
    defaultPresetMap["key1_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key1_modline3_enable"] = 0;
    defaultPresetMap["key1_modline3_initValue"] = 0;
    defaultPresetMap["key1_modline3_initMode"] = "None";
    defaultPresetMap["key1_modline3_source"] = "None";
    defaultPresetMap["key1_modline3_gain"] = 1.00;
    defaultPresetMap["key1_modline3_offset"] = 0;
    defaultPresetMap["key1_modline3_table"] = "Lin";
    defaultPresetMap["key1_modline3_min"] = 0;
    defaultPresetMap["key1_modline3_max"] = 127;
    defaultPresetMap["key1_modline3_slew"] = 0;
    defaultPresetMap["key1_modline3_delay"] = 0;
    defaultPresetMap["key1_modline3_destination"] = "None";
    defaultPresetMap["key1_modline3_note"] = 60;
    defaultPresetMap["key1_modline3_velocity"] = 127;
    defaultPresetMap["key1_modline3_cc"] = 60;
    defaultPresetMap["key1_modline3_bankMSB"] = 0;
    defaultPresetMap["key1_modline3_mmcid"] = 0;
    defaultPresetMap["key1_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key1_modline3_channel"] = 1;
    defaultPresetMap["key1_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key1_modline3_oscroute"] = "";
    defaultPresetMap["key1_modline3_ledgreen"] = "Off";
    defaultPresetMap["key1_modline3_ledred"] = "Off";
    defaultPresetMap["key1_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key1_modline4_enable"] = 0;
    defaultPresetMap["key1_modline4_initValue"] = 0;
    defaultPresetMap["key1_modline4_initMode"] = "None";
    defaultPresetMap["key1_modline4_source"] = "None";
    defaultPresetMap["key1_modline4_gain"] = 1.00;
    defaultPresetMap["key1_modline4_offset"] = 0;
    defaultPresetMap["key1_modline4_table"] = "Lin";
    defaultPresetMap["key1_modline4_min"] = 0;
    defaultPresetMap["key1_modline4_max"] = 127;
    defaultPresetMap["key1_modline4_slew"] = 0;
    defaultPresetMap["key1_modline4_delay"] = 0;
    defaultPresetMap["key1_modline4_destination"] = "None";
    defaultPresetMap["key1_modline4_note"] = 60;
    defaultPresetMap["key1_modline4_velocity"] = 127;
    defaultPresetMap["key1_modline4_cc"] = 60;
    defaultPresetMap["key1_modline4_bankMSB"] = 0;
    defaultPresetMap["key1_modline4_mmcid"] = 0;
    defaultPresetMap["key1_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key1_modline4_channel"] = 1;
    defaultPresetMap["key1_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key1_modline4_oscroute"] = "";
    defaultPresetMap["key1_modline4_ledgreen"] = "Off";
    defaultPresetMap["key1_modline4_ledred"] = "Off";
    defaultPresetMap["key1_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key1_modline5_enable"] = 0;
    defaultPresetMap["key1_modline5_initValue"] = 0;
    defaultPresetMap["key1_modline5_initMode"] = "None";
    defaultPresetMap["key1_modline5_source"] = "None";
    defaultPresetMap["key1_modline5_gain"] = 1.00;
    defaultPresetMap["key1_modline5_offset"] = 0;
    defaultPresetMap["key1_modline5_table"] = "Lin";
    defaultPresetMap["key1_modline5_min"] = 0;
    defaultPresetMap["key1_modline5_max"] = 127;
    defaultPresetMap["key1_modline5_slew"] = 0;
    defaultPresetMap["key1_modline5_delay"] = 0;
    defaultPresetMap["key1_modline5_destination"] = "None";
    defaultPresetMap["key1_modline5_note"] = 60;
    defaultPresetMap["key1_modline5_velocity"] = 127;
    defaultPresetMap["key1_modline5_cc"] = 60;
    defaultPresetMap["key1_modline5_bankMSB"] = 0;
    defaultPresetMap["key1_modline5_mmcid"] = 0;
    defaultPresetMap["key1_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key1_modline5_channel"] = 1;
    defaultPresetMap["key1_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key1_modline5_oscroute"] = "";
    defaultPresetMap["key1_modline5_ledgreen"] = "Off";
    defaultPresetMap["key1_modline5_ledred"] = "Off";
    defaultPresetMap["key1_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key1_modline6_enable"] = 0;
    defaultPresetMap["key1_modline6_initValue"] = 0;
    defaultPresetMap["key1_modline6_initMode"] = "None";
    defaultPresetMap["key1_modline6_source"] = "None";
    defaultPresetMap["key1_modline6_gain"] = 1.00;
    defaultPresetMap["key1_modline6_offset"] = 0;
    defaultPresetMap["key1_modline6_table"] = "Lin";
    defaultPresetMap["key1_modline6_min"] = 0;
    defaultPresetMap["key1_modline6_max"] = 127;
    defaultPresetMap["key1_modline6_slew"] = 0;
    defaultPresetMap["key1_modline6_delay"] = 0;
    defaultPresetMap["key1_modline6_destination"] = "None";
    defaultPresetMap["key1_modline6_note"] = 60;
    defaultPresetMap["key1_modline6_velocity"] = 127;
    defaultPresetMap["key1_modline6_cc"] = 60;
    defaultPresetMap["key1_modline6_bankMSB"] = 0;
    defaultPresetMap["key1_modline6_mmcid"] = 0;
    defaultPresetMap["key1_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key1_modline6_channel"] = 1;
    defaultPresetMap["key1_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key1_modline6_oscroute"] = "";
    defaultPresetMap["key1_modline6_ledgreen"] = "Off";
    defaultPresetMap["key1_modline6_ledred"] = "Off";
    defaultPresetMap["key1_modline6_displaylinked"] = 0;


    //------------------------ Key 2 ------------------------//
    defaultPresetMap["2_key_name"] = "2KEY";
    defaultPresetMap["2_key_displaymode"] = 1;
    defaultPresetMap["2_key_prefix"] = "";
    defaultPresetMap["2_key_counter_min"] = 0;
    defaultPresetMap["2_key_counter_max"] = 127;
    defaultPresetMap["2_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key2_modline1_enable"] = 0;
    defaultPresetMap["key2_modline1_initValue"] = 0;
    defaultPresetMap["key2_modline1_initMode"] = "None";
    defaultPresetMap["key2_modline1_source"] = "None";
    defaultPresetMap["key2_modline1_gain"] = 1.00;
    defaultPresetMap["key2_modline1_offset"] = 0;
    defaultPresetMap["key2_modline1_table"] = "Lin";
    defaultPresetMap["key2_modline1_min"] = 0;
    defaultPresetMap["key2_modline1_max"] = 127;
    defaultPresetMap["key2_modline1_slew"] = 0;
    defaultPresetMap["key2_modline1_delay"] = 0;
    defaultPresetMap["key2_modline1_destination"] = "None";
    defaultPresetMap["key2_modline1_note"] = 60;
    defaultPresetMap["key2_modline1_velocity"] = 127;
    defaultPresetMap["key2_modline1_cc"] = 60;
    defaultPresetMap["key2_modline1_bankMSB"] = 0;
    defaultPresetMap["key2_modline1_mmcid"] = 0;
    defaultPresetMap["key2_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key2_modline1_channel"] = 1;
    defaultPresetMap["key2_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key2_modline1_oscroute"] = "";
    defaultPresetMap["key2_modline1_ledgreen"] = "Off";
    defaultPresetMap["key2_modline1_ledred"] = "Off";
    defaultPresetMap["key2_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key2_modline2_enable"] = 0;
    defaultPresetMap["key2_modline2_initValue"] = 0;
    defaultPresetMap["key2_modline2_initMode"] = "None";
    defaultPresetMap["key2_modline2_source"] = "None";
    defaultPresetMap["key2_modline2_gain"] = 1.00;
    defaultPresetMap["key2_modline2_offset"] = 0;
    defaultPresetMap["key2_modline2_table"] = "Lin";
    defaultPresetMap["key2_modline2_min"] = 0;
    defaultPresetMap["key2_modline2_max"] = 127;
    defaultPresetMap["key2_modline2_slew"] = 0;
    defaultPresetMap["key2_modline2_delay"] = 0;
    defaultPresetMap["key2_modline2_destination"] = "None";
    defaultPresetMap["key2_modline2_note"] = 60;
    defaultPresetMap["key2_modline2_velocity"] = 127;
    defaultPresetMap["key2_modline2_cc"] = 60;
    defaultPresetMap["key2_modline2_bankMSB"] = 0;
    defaultPresetMap["key2_modline2_mmcid"] = 0;
    defaultPresetMap["key2_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key2_modline2_channel"] = 1;
    defaultPresetMap["key2_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key2_modline2_oscroute"] = "";
    defaultPresetMap["key2_modline2_ledgreen"] = "Off";
    defaultPresetMap["key2_modline2_ledred"] = "Off";
    defaultPresetMap["key2_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key2_modline3_enable"] = 0;
    defaultPresetMap["key2_modline3_initValue"] = 0;
    defaultPresetMap["key2_modline3_initMode"] = "None";
    defaultPresetMap["key2_modline3_source"] = "None";
    defaultPresetMap["key2_modline3_gain"] = 1.00;
    defaultPresetMap["key2_modline3_offset"] = 0;
    defaultPresetMap["key2_modline3_table"] = "Lin";
    defaultPresetMap["key2_modline3_min"] = 0;
    defaultPresetMap["key2_modline3_max"] = 127;
    defaultPresetMap["key2_modline3_slew"] = 0;
    defaultPresetMap["key2_modline3_delay"] = 0;
    defaultPresetMap["key2_modline3_destination"] = "None";
    defaultPresetMap["key2_modline3_note"] = 60;
    defaultPresetMap["key2_modline3_velocity"] = 127;
    defaultPresetMap["key2_modline3_cc"] = 60;
    defaultPresetMap["key2_modline3_bankMSB"] = 0;
    defaultPresetMap["key2_modline3_mmcid"] = 0;
    defaultPresetMap["key2_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key2_modline3_channel"] = 1;
    defaultPresetMap["key2_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key2_modline3_oscroute"] = "";
    defaultPresetMap["key2_modline3_ledgreen"] = "Off";
    defaultPresetMap["key2_modline3_ledred"] = "Off";
    defaultPresetMap["key2_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key2_modline4_enable"] = 0;
    defaultPresetMap["key2_modline4_initValue"] = 0;
    defaultPresetMap["key2_modline4_initMode"] = "None";
    defaultPresetMap["key2_modline4_source"] = "None";
    defaultPresetMap["key2_modline4_gain"] = 1.00;
    defaultPresetMap["key2_modline4_offset"] = 0;
    defaultPresetMap["key2_modline4_table"] = "Lin";
    defaultPresetMap["key2_modline4_min"] = 0;
    defaultPresetMap["key2_modline4_max"] = 127;
    defaultPresetMap["key2_modline4_slew"] = 0;
    defaultPresetMap["key2_modline4_delay"] = 0;
    defaultPresetMap["key2_modline4_destination"] = "None";
    defaultPresetMap["key2_modline4_note"] = 60;
    defaultPresetMap["key2_modline4_velocity"] = 127;
    defaultPresetMap["key2_modline4_cc"] = 60;
    defaultPresetMap["key2_modline4_bankMSB"] = 0;
    defaultPresetMap["key2_modline4_mmcid"] = 0;
    defaultPresetMap["key2_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key2_modline4_channel"] = 1;
    defaultPresetMap["key2_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key2_modline4_oscroute"] = "";
    defaultPresetMap["key2_modline4_ledgreen"] = "Off";
    defaultPresetMap["key2_modline4_ledred"] = "Off";
    defaultPresetMap["key2_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key2_modline5_enable"] = 0;
    defaultPresetMap["key2_modline5_initValue"] = 0;
    defaultPresetMap["key2_modline5_initMode"] = "None";
    defaultPresetMap["key2_modline5_source"] = "None";
    defaultPresetMap["key2_modline5_gain"] = 1.00;
    defaultPresetMap["key2_modline5_offset"] = 0;
    defaultPresetMap["key2_modline5_table"] = "Lin";
    defaultPresetMap["key2_modline5_min"] = 0;
    defaultPresetMap["key2_modline5_max"] = 127;
    defaultPresetMap["key2_modline5_slew"] = 0;
    defaultPresetMap["key2_modline5_delay"] = 0;
    defaultPresetMap["key2_modline5_destination"] = "None";
    defaultPresetMap["key2_modline5_note"] = 60;
    defaultPresetMap["key2_modline5_velocity"] = 127;
    defaultPresetMap["key2_modline5_cc"] = 60;
    defaultPresetMap["key2_modline5_bankMSB"] = 0;
    defaultPresetMap["key2_modline5_mmcid"] = 0;
    defaultPresetMap["key2_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key2_modline5_channel"] = 1;
    defaultPresetMap["key2_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key2_modline5_oscroute"] = "";
    defaultPresetMap["key2_modline5_ledgreen"] = "Off";
    defaultPresetMap["key2_modline5_ledred"] = "Off";
    defaultPresetMap["key2_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key2_modline6_enable"] = 0;
    defaultPresetMap["key2_modline6_initValue"] = 0;
    defaultPresetMap["key2_modline6_initMode"] = "None";
    defaultPresetMap["key2_modline6_source"] = "None";
    defaultPresetMap["key2_modline6_gain"] = 1.00;
    defaultPresetMap["key2_modline6_offset"] = 0;
    defaultPresetMap["key2_modline6_table"] = "Lin";
    defaultPresetMap["key2_modline6_min"] = 0;
    defaultPresetMap["key2_modline6_max"] = 127;
    defaultPresetMap["key2_modline6_slew"] = 0;
    defaultPresetMap["key2_modline6_delay"] = 0;
    defaultPresetMap["key2_modline6_destination"] = "None";
    defaultPresetMap["key2_modline6_note"] = 60;
    defaultPresetMap["key2_modline6_velocity"] = 127;
    defaultPresetMap["key2_modline6_cc"] = 60;
    defaultPresetMap["key2_modline6_bankMSB"] = 0;
    defaultPresetMap["key2_modline6_mmcid"] = 0;
    defaultPresetMap["key2_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key2_modline6_channel"] = 1;
    defaultPresetMap["key2_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key2_modline6_oscroute"] = "";
    defaultPresetMap["key2_modline6_ledgreen"] = "Off";
    defaultPresetMap["key2_modline6_ledred"] = "Off";
    defaultPresetMap["key2_modline6_displaylinked"] = 0;


    //------------------------ Key 3 ------------------------//
    defaultPresetMap["3_key_name"] = "3KEY";
    defaultPresetMap["3_key_displaymode"] = 1;
    defaultPresetMap["3_key_prefix"] = "";
    defaultPresetMap["3_key_counter_min"] = 0;
    defaultPresetMap["3_key_counter_max"] = 127;
    defaultPresetMap["3_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key3_modline1_enable"] = 0;
    defaultPresetMap["key3_modline1_initValue"] = 0;
    defaultPresetMap["key3_modline1_initMode"] = "None";
    defaultPresetMap["key3_modline1_source"] = "None";
    defaultPresetMap["key3_modline1_gain"] = 1.00;
    defaultPresetMap["key3_modline1_offset"] = 0;
    defaultPresetMap["key3_modline1_table"] = "Lin";
    defaultPresetMap["key3_modline1_min"] = 0;
    defaultPresetMap["key3_modline1_max"] = 127;
    defaultPresetMap["key3_modline1_slew"] = 0;
    defaultPresetMap["key3_modline1_delay"] = 0;
    defaultPresetMap["key3_modline1_destination"] = "None";
    defaultPresetMap["key3_modline1_note"] = 60;
    defaultPresetMap["key3_modline1_velocity"] = 127;
    defaultPresetMap["key3_modline1_cc"] = 60;
    defaultPresetMap["key3_modline1_bankMSB"] = 0;
    defaultPresetMap["key3_modline1_mmcid"] = 0;
    defaultPresetMap["key3_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key3_modline1_channel"] = 1;
    defaultPresetMap["key3_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key3_modline1_oscroute"] = "";
    defaultPresetMap["key3_modline1_ledgreen"] = "Off";
    defaultPresetMap["key3_modline1_ledred"] = "Off";
    defaultPresetMap["key3_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key3_modline2_enable"] = 0;
    defaultPresetMap["key3_modline2_initValue"] = 0;
    defaultPresetMap["key3_modline2_initMode"] = "None";
    defaultPresetMap["key3_modline2_source"] = "None";
    defaultPresetMap["key3_modline2_gain"] = 1.00;
    defaultPresetMap["key3_modline2_offset"] = 0;
    defaultPresetMap["key3_modline2_table"] = "Lin";
    defaultPresetMap["key3_modline2_min"] = 0;
    defaultPresetMap["key3_modline2_max"] = 127;
    defaultPresetMap["key3_modline2_slew"] = 0;
    defaultPresetMap["key3_modline2_delay"] = 0;
    defaultPresetMap["key3_modline2_destination"] = "None";
    defaultPresetMap["key3_modline2_note"] = 60;
    defaultPresetMap["key3_modline2_velocity"] = 127;
    defaultPresetMap["key3_modline2_cc"] = 60;
    defaultPresetMap["key3_modline2_bankMSB"] = 0;
    defaultPresetMap["key3_modline2_mmcid"] = 0;
    defaultPresetMap["key3_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key3_modline2_channel"] = 1;
    defaultPresetMap["key3_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key3_modline2_oscroute"] = "";
    defaultPresetMap["key3_modline2_ledgreen"] = "Off";
    defaultPresetMap["key3_modline2_ledred"] = "Off";
    defaultPresetMap["key3_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key3_modline3_enable"] = 0;
    defaultPresetMap["key3_modline3_initValue"] = 0;
    defaultPresetMap["key3_modline3_initMode"] = "None";
    defaultPresetMap["key3_modline3_source"] = "None";
    defaultPresetMap["key3_modline3_gain"] = 1.00;
    defaultPresetMap["key3_modline3_offset"] = 0;
    defaultPresetMap["key3_modline3_table"] = "Lin";
    defaultPresetMap["key3_modline3_min"] = 0;
    defaultPresetMap["key3_modline3_max"] = 127;
    defaultPresetMap["key3_modline3_slew"] = 0;
    defaultPresetMap["key3_modline3_delay"] = 0;
    defaultPresetMap["key3_modline3_destination"] = "None";
    defaultPresetMap["key3_modline3_note"] = 60;
    defaultPresetMap["key3_modline3_velocity"] = 127;
    defaultPresetMap["key3_modline3_cc"] = 60;
    defaultPresetMap["key3_modline3_bankMSB"] = 0;
    defaultPresetMap["key3_modline3_mmcid"] = 0;
    defaultPresetMap["key3_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key3_modline3_channel"] = 1;
    defaultPresetMap["key3_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key3_modline3_oscroute"] = "";
    defaultPresetMap["key3_modline3_ledgreen"] = "Off";
    defaultPresetMap["key3_modline3_ledred"] = "Off";
    defaultPresetMap["key3_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key3_modline4_enable"] = 0;
    defaultPresetMap["key3_modline4_initValue"] = 0;
    defaultPresetMap["key3_modline4_initMode"] = "None";
    defaultPresetMap["key3_modline4_source"] = "None";
    defaultPresetMap["key3_modline4_gain"] = 1.00;
    defaultPresetMap["key3_modline4_offset"] = 0;
    defaultPresetMap["key3_modline4_table"] = "Lin";
    defaultPresetMap["key3_modline4_min"] = 0;
    defaultPresetMap["key3_modline4_max"] = 127;
    defaultPresetMap["key3_modline4_slew"] = 0;
    defaultPresetMap["key3_modline4_delay"] = 0;
    defaultPresetMap["key3_modline4_destination"] = "None";
    defaultPresetMap["key3_modline4_note"] = 60;
    defaultPresetMap["key3_modline4_velocity"] = 127;
    defaultPresetMap["key3_modline4_cc"] = 60;
    defaultPresetMap["key3_modline4_bankMSB"] = 0;
    defaultPresetMap["key3_modline4_mmcid"] = 0;
    defaultPresetMap["key3_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key3_modline4_channel"] = 1;
    defaultPresetMap["key3_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key3_modline4_oscroute"] = "";
    defaultPresetMap["key3_modline4_ledgreen"] = "Off";
    defaultPresetMap["key3_modline4_ledred"] = "Off";
    defaultPresetMap["key3_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key3_modline5_enable"] = 0;
    defaultPresetMap["key3_modline5_initValue"] = 0;
    defaultPresetMap["key3_modline5_initMode"] = "None";
    defaultPresetMap["key3_modline5_source"] = "None";
    defaultPresetMap["key3_modline5_gain"] = 1.00;
    defaultPresetMap["key3_modline5_offset"] = 0;
    defaultPresetMap["key3_modline5_table"] = "Lin";
    defaultPresetMap["key3_modline5_min"] = 0;
    defaultPresetMap["key3_modline5_max"] = 127;
    defaultPresetMap["key3_modline5_slew"] = 0;
    defaultPresetMap["key3_modline5_delay"] = 0;
    defaultPresetMap["key3_modline5_destination"] = "None";
    defaultPresetMap["key3_modline5_note"] = 60;
    defaultPresetMap["key3_modline5_velocity"] = 127;
    defaultPresetMap["key3_modline5_cc"] = 60;
    defaultPresetMap["key3_modline5_bankMSB"] = 0;
    defaultPresetMap["key3_modline5_mmcid"] = 0;
    defaultPresetMap["key3_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key3_modline5_channel"] = 1;
    defaultPresetMap["key3_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key3_modline5_oscroute"] = "";
    defaultPresetMap["key3_modline5_ledgreen"] = "Off";
    defaultPresetMap["key3_modline5_ledred"] = "Off";
    defaultPresetMap["key3_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key3_modline6_enable"] = 0;
    defaultPresetMap["key3_modline6_initValue"] = 0;
    defaultPresetMap["key3_modline6_initMode"] = "None";
    defaultPresetMap["key3_modline6_source"] = "None";
    defaultPresetMap["key3_modline6_gain"] = 1.00;
    defaultPresetMap["key3_modline6_offset"] = 0;
    defaultPresetMap["key3_modline6_table"] = "Lin";
    defaultPresetMap["key3_modline6_min"] = 0;
    defaultPresetMap["key3_modline6_max"] = 127;
    defaultPresetMap["key3_modline6_slew"] = 0;
    defaultPresetMap["key3_modline6_delay"] = 0;
    defaultPresetMap["key3_modline6_destination"] = "None";
    defaultPresetMap["key3_modline6_note"] = 60;
    defaultPresetMap["key3_modline6_velocity"] = 127;
    defaultPresetMap["key3_modline6_cc"] = 60;
    defaultPresetMap["key3_modline6_bankMSB"] = 0;
    defaultPresetMap["key3_modline6_mmcid"] = 0;
    defaultPresetMap["key3_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key3_modline6_channel"] = 1;
    defaultPresetMap["key3_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key3_modline6_oscroute"] = "";
    defaultPresetMap["key3_modline6_ledgreen"] = "Off";
    defaultPresetMap["key3_modline6_ledred"] = "Off";
    defaultPresetMap["key3_modline6_displaylinked"] = 0;


    //------------------------ Key 4 ------------------------//
    defaultPresetMap["4_key_name"] = "4KEY";
    defaultPresetMap["4_key_displaymode"] = 1;
    defaultPresetMap["4_key_prefix"] = "";
    defaultPresetMap["4_key_counter_min"] = 0;
    defaultPresetMap["4_key_counter_max"] = 127;
    defaultPresetMap["4_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key4_modline1_enable"] = 0;
    defaultPresetMap["key4_modline1_initValue"] = 0;
    defaultPresetMap["key4_modline1_initMode"] = "None";
    defaultPresetMap["key4_modline1_source"] = "None";
    defaultPresetMap["key4_modline1_gain"] = 1.00;
    defaultPresetMap["key4_modline1_offset"] = 0;
    defaultPresetMap["key4_modline1_table"] = "Lin";
    defaultPresetMap["key4_modline1_min"] = 0;
    defaultPresetMap["key4_modline1_max"] = 127;
    defaultPresetMap["key4_modline1_slew"] = 0;
    defaultPresetMap["key4_modline1_delay"] = 0;
    defaultPresetMap["key4_modline1_destination"] = "None";
    defaultPresetMap["key4_modline1_note"] = 60;
    defaultPresetMap["key4_modline1_velocity"] = 127;
    defaultPresetMap["key4_modline1_cc"] = 60;
    defaultPresetMap["key4_modline1_bankMSB"] = 0;
    defaultPresetMap["key4_modline1_mmcid"] = 0;
    defaultPresetMap["key4_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key4_modline1_channel"] = 1;
    defaultPresetMap["key4_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key4_modline1_oscroute"] = "";
    defaultPresetMap["key4_modline1_ledgreen"] = "Off";
    defaultPresetMap["key4_modline1_ledred"] = "Off";
    defaultPresetMap["key4_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key4_modline2_enable"] = 0;
    defaultPresetMap["key4_modline2_initValue"] = 0;
    defaultPresetMap["key4_modline2_initMode"] = "None";
    defaultPresetMap["key4_modline2_source"] = "None";
    defaultPresetMap["key4_modline2_gain"] = 1.00;
    defaultPresetMap["key4_modline2_offset"] = 0;
    defaultPresetMap["key4_modline2_table"] = "Lin";
    defaultPresetMap["key4_modline2_min"] = 0;
    defaultPresetMap["key4_modline2_max"] = 127;
    defaultPresetMap["key4_modline2_slew"] = 0;
    defaultPresetMap["key4_modline2_delay"] = 0;
    defaultPresetMap["key4_modline2_destination"] = "None";
    defaultPresetMap["key4_modline2_note"] = 60;
    defaultPresetMap["key4_modline2_velocity"] = 127;
    defaultPresetMap["key4_modline2_cc"] = 60;
    defaultPresetMap["key4_modline2_bankMSB"] = 0;
    defaultPresetMap["key4_modline2_mmcid"] = 0;
    defaultPresetMap["key4_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key4_modline2_channel"] = 1;
    defaultPresetMap["key4_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key4_modline2_oscroute"] = "";
    defaultPresetMap["key4_modline2_ledgreen"] = "Off";
    defaultPresetMap["key4_modline2_ledred"] = "Off";
    defaultPresetMap["key4_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key4_modline3_enable"] = 0;
    defaultPresetMap["key4_modline3_initValue"] = 0;
    defaultPresetMap["key4_modline3_initMode"] = "None";
    defaultPresetMap["key4_modline3_source"] = "None";
    defaultPresetMap["key4_modline3_gain"] = 1.00;
    defaultPresetMap["key4_modline3_offset"] = 0;
    defaultPresetMap["key4_modline3_table"] = "Lin";
    defaultPresetMap["key4_modline3_min"] = 0;
    defaultPresetMap["key4_modline3_max"] = 127;
    defaultPresetMap["key4_modline3_slew"] = 0;
    defaultPresetMap["key4_modline3_delay"] = 0;
    defaultPresetMap["key4_modline3_destination"] = "None";
    defaultPresetMap["key4_modline3_note"] = 60;
    defaultPresetMap["key4_modline3_velocity"] = 127;
    defaultPresetMap["key4_modline3_cc"] = 60;
    defaultPresetMap["key4_modline3_bankMSB"] = 0;
    defaultPresetMap["key4_modline3_mmcid"] = 0;
    defaultPresetMap["key4_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key4_modline3_channel"] = 1;
    defaultPresetMap["key4_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key4_modline3_oscroute"] = "";
    defaultPresetMap["key4_modline3_ledgreen"] = "Off";
    defaultPresetMap["key4_modline3_ledred"] = "Off";
    defaultPresetMap["key4_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key4_modline4_enable"] = 0;
    defaultPresetMap["key4_modline4_initValue"] = 0;
    defaultPresetMap["key4_modline4_initMode"] = "None";
    defaultPresetMap["key4_modline4_source"] = "None";
    defaultPresetMap["key4_modline4_gain"] = 1.00;
    defaultPresetMap["key4_modline4_offset"] = 0;
    defaultPresetMap["key4_modline4_table"] = "Lin";
    defaultPresetMap["key4_modline4_min"] = 0;
    defaultPresetMap["key4_modline4_max"] = 127;
    defaultPresetMap["key4_modline4_slew"] = 0;
    defaultPresetMap["key4_modline4_delay"] = 0;
    defaultPresetMap["key4_modline4_destination"] = "None";
    defaultPresetMap["key4_modline4_note"] = 60;
    defaultPresetMap["key4_modline4_velocity"] = 127;
    defaultPresetMap["key4_modline4_cc"] = 60;
    defaultPresetMap["key4_modline4_bankMSB"] = 0;
    defaultPresetMap["key4_modline4_mmcid"] = 0;
    defaultPresetMap["key4_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key4_modline4_channel"] = 1;
    defaultPresetMap["key4_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key4_modline4_oscroute"] = "";
    defaultPresetMap["key4_modline4_ledgreen"] = "Off";
    defaultPresetMap["key4_modline4_ledred"] = "Off";
    defaultPresetMap["key4_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key4_modline5_enable"] = 0;
    defaultPresetMap["key4_modline5_initValue"] = 0;
    defaultPresetMap["key4_modline5_initMode"] = "None";
    defaultPresetMap["key4_modline5_source"] = "None";
    defaultPresetMap["key4_modline5_gain"] = 1.00;
    defaultPresetMap["key4_modline5_offset"] = 0;
    defaultPresetMap["key4_modline5_table"] = "Lin";
    defaultPresetMap["key4_modline5_min"] = 0;
    defaultPresetMap["key4_modline5_max"] = 127;
    defaultPresetMap["key4_modline5_slew"] = 0;
    defaultPresetMap["key4_modline5_delay"] = 0;
    defaultPresetMap["key4_modline5_destination"] = "None";
    defaultPresetMap["key4_modline5_note"] = 60;
    defaultPresetMap["key4_modline5_velocity"] = 127;
    defaultPresetMap["key4_modline5_cc"] = 60;
    defaultPresetMap["key4_modline5_bankMSB"] = 0;
    defaultPresetMap["key4_modline5_mmcid"] = 0;
    defaultPresetMap["key4_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key4_modline5_channel"] = 1;
    defaultPresetMap["key4_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key4_modline5_oscroute"] = "";
    defaultPresetMap["key4_modline5_ledgreen"] = "Off";
    defaultPresetMap["key4_modline5_ledred"] = "Off";
    defaultPresetMap["key4_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key4_modline6_enable"] = 0;
    defaultPresetMap["key4_modline6_initValue"] = 0;
    defaultPresetMap["key4_modline6_initMode"] = "None";
    defaultPresetMap["key4_modline6_source"] = "None";
    defaultPresetMap["key4_modline6_gain"] = 1.00;
    defaultPresetMap["key4_modline6_offset"] = 0;
    defaultPresetMap["key4_modline6_table"] = "Lin";
    defaultPresetMap["key4_modline6_min"] = 0;
    defaultPresetMap["key4_modline6_max"] = 127;
    defaultPresetMap["key4_modline6_slew"] = 0;
    defaultPresetMap["key4_modline6_delay"] = 0;
    defaultPresetMap["key4_modline6_destination"] = "None";
    defaultPresetMap["key4_modline6_note"] = 60;
    defaultPresetMap["key4_modline6_velocity"] = 127;
    defaultPresetMap["key4_modline6_cc"] = 60;
    defaultPresetMap["key4_modline6_bankMSB"] = 0;
    defaultPresetMap["key4_modline6_mmcid"] = 0;
    defaultPresetMap["key4_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key4_modline6_channel"] = 1;
    defaultPresetMap["key4_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key4_modline6_oscroute"] = "";
    defaultPresetMap["key4_modline6_ledgreen"] = "Off";
    defaultPresetMap["key4_modline6_ledred"] = "Off";
    defaultPresetMap["key4_modline6_displaylinked"] = 0;

    //------------------------ Key 5 ------------------------//
    defaultPresetMap["5_key_name"] = "5KEY";
    defaultPresetMap["5_key_displaymode"] = 1;
    defaultPresetMap["5_key_prefix"] = "";
    defaultPresetMap["5_key_counter_min"] = 0;
    defaultPresetMap["5_key_counter_max"] = 127;
    defaultPresetMap["5_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key5_modline1_enable"] = 0;
    defaultPresetMap["key5_modline1_initValue"] = 0;
    defaultPresetMap["key5_modline1_initMode"] = "None";
    defaultPresetMap["key5_modline1_source"] = "None";
    defaultPresetMap["key5_modline1_gain"] = 1.00;
    defaultPresetMap["key5_modline1_offset"] = 0;
    defaultPresetMap["key5_modline1_table"] = "Lin";
    defaultPresetMap["key5_modline1_min"] = 0;
    defaultPresetMap["key5_modline1_max"] = 127;
    defaultPresetMap["key5_modline1_slew"] = 0;
    defaultPresetMap["key5_modline1_delay"] = 0;
    defaultPresetMap["key5_modline1_destination"] = "None";
    defaultPresetMap["key5_modline1_note"] = 60;
    defaultPresetMap["key5_modline1_velocity"] = 127;
    defaultPresetMap["key5_modline1_cc"] = 60;
    defaultPresetMap["key5_modline1_bankMSB"] = 0;
    defaultPresetMap["key5_modline1_mmcid"] = 0;
    defaultPresetMap["key5_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key5_modline1_channel"] = 1;
    defaultPresetMap["key5_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key5_modline1_oscroute"] = "";
    defaultPresetMap["key5_modline1_ledgreen"] = "Off";
    defaultPresetMap["key5_modline1_ledred"] = "Off";
    defaultPresetMap["key5_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key5_modline2_enable"] = 0;
    defaultPresetMap["key5_modline2_initValue"] = 0;
    defaultPresetMap["key5_modline2_initMode"] = "None";
    defaultPresetMap["key5_modline2_source"] = "None";
    defaultPresetMap["key5_modline2_gain"] = 1.00;
    defaultPresetMap["key5_modline2_offset"] = 0;
    defaultPresetMap["key5_modline2_table"] = "Lin";
    defaultPresetMap["key5_modline2_min"] = 0;
    defaultPresetMap["key5_modline2_max"] = 127;
    defaultPresetMap["key5_modline2_slew"] = 0;
    defaultPresetMap["key5_modline2_delay"] = 0;
    defaultPresetMap["key5_modline2_destination"] = "None";
    defaultPresetMap["key5_modline2_note"] = 60;
    defaultPresetMap["key5_modline2_velocity"] = 127;
    defaultPresetMap["key5_modline2_cc"] = 60;
    defaultPresetMap["key5_modline2_bankMSB"] = 0;
    defaultPresetMap["key5_modline2_mmcid"] = 0;
    defaultPresetMap["key5_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key5_modline2_channel"] = 1;
    defaultPresetMap["key5_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key5_modline2_oscroute"] = "";
    defaultPresetMap["key5_modline2_ledgreen"] = "Off";
    defaultPresetMap["key5_modline2_ledred"] = "Off";
    defaultPresetMap["key5_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key5_modline3_enable"] = 0;
    defaultPresetMap["key5_modline3_initValue"] = 0;
    defaultPresetMap["key5_modline3_initMode"] = "None";
    defaultPresetMap["key5_modline3_source"] = "None";
    defaultPresetMap["key5_modline3_gain"] = 1.00;
    defaultPresetMap["key5_modline3_offset"] = 0;
    defaultPresetMap["key5_modline3_table"] = "Lin";
    defaultPresetMap["key5_modline3_min"] = 0;
    defaultPresetMap["key5_modline3_max"] = 127;
    defaultPresetMap["key5_modline3_slew"] = 0;
    defaultPresetMap["key5_modline3_delay"] = 0;
    defaultPresetMap["key5_modline3_destination"] = "None";
    defaultPresetMap["key5_modline3_note"] = 60;
    defaultPresetMap["key5_modline3_velocity"] = 127;
    defaultPresetMap["key5_modline3_cc"] = 60;
    defaultPresetMap["key5_modline3_bankMSB"] = 0;
    defaultPresetMap["key5_modline3_mmcid"] = 0;
    defaultPresetMap["key5_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key5_modline3_channel"] = 1;
    defaultPresetMap["key5_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key5_modline3_oscroute"] = "";
    defaultPresetMap["key5_modline3_ledgreen"] = "Off";
    defaultPresetMap["key5_modline3_ledred"] = "Off";
    defaultPresetMap["key5_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key5_modline4_enable"] = 0;
    defaultPresetMap["key5_modline4_initValue"] = 0;
    defaultPresetMap["key5_modline4_initMode"] = "None";
    defaultPresetMap["key5_modline4_source"] = "None";
    defaultPresetMap["key5_modline4_gain"] = 1.00;
    defaultPresetMap["key5_modline4_offset"] = 0;
    defaultPresetMap["key5_modline4_table"] = "Lin";
    defaultPresetMap["key5_modline4_min"] = 0;
    defaultPresetMap["key5_modline4_max"] = 127;
    defaultPresetMap["key5_modline4_slew"] = 0;
    defaultPresetMap["key5_modline4_delay"] = 0;
    defaultPresetMap["key5_modline4_destination"] = "None";
    defaultPresetMap["key5_modline4_note"] = 60;
    defaultPresetMap["key5_modline4_velocity"] = 127;
    defaultPresetMap["key5_modline4_cc"] = 60;
    defaultPresetMap["key5_modline4_bankMSB"] = 0;
    defaultPresetMap["key5_modline4_mmcid"] = 0;
    defaultPresetMap["key5_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key5_modline4_channel"] = 1;
    defaultPresetMap["key5_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key5_modline4_oscroute"] = "";
    defaultPresetMap["key5_modline4_ledgreen"] = "Off";
    defaultPresetMap["key5_modline4_ledred"] = "Off";
    defaultPresetMap["key5_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key5_modline5_enable"] = 0;
    defaultPresetMap["key5_modline5_initValue"] = 0;
    defaultPresetMap["key5_modline5_initMode"] = "None";
    defaultPresetMap["key5_modline5_source"] = "None";
    defaultPresetMap["key5_modline5_gain"] = 1.00;
    defaultPresetMap["key5_modline5_offset"] = 0;
    defaultPresetMap["key5_modline5_table"] = "Lin";
    defaultPresetMap["key5_modline5_min"] = 0;
    defaultPresetMap["key5_modline5_max"] = 127;
    defaultPresetMap["key5_modline5_slew"] = 0;
    defaultPresetMap["key5_modline5_delay"] = 0;
    defaultPresetMap["key5_modline5_destination"] = "None";
    defaultPresetMap["key5_modline5_note"] = 60;
    defaultPresetMap["key5_modline5_velocity"] = 127;
    defaultPresetMap["key5_modline5_cc"] = 60;
    defaultPresetMap["key5_modline5_bankMSB"] = 0;
    defaultPresetMap["key5_modline5_mmcid"] = 0;
    defaultPresetMap["key5_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key5_modline5_channel"] = 1;
    defaultPresetMap["key5_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key5_modline5_oscroute"] = "";
    defaultPresetMap["key5_modline5_ledgreen"] = "Off";
    defaultPresetMap["key5_modline5_ledred"] = "Off";
    defaultPresetMap["key5_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key5_modline6_enable"] = 0;
    defaultPresetMap["key5_modline6_initValue"] = 0;
    defaultPresetMap["key5_modline6_initMode"] = "None";
    defaultPresetMap["key5_modline6_source"] = "None";
    defaultPresetMap["key5_modline6_gain"] = 1.00;
    defaultPresetMap["key5_modline6_offset"] = 0;
    defaultPresetMap["key5_modline6_table"] = "Lin";
    defaultPresetMap["key5_modline6_min"] = 0;
    defaultPresetMap["key5_modline6_max"] = 127;
    defaultPresetMap["key5_modline6_slew"] = 0;
    defaultPresetMap["key5_modline6_delay"] = 0;
    defaultPresetMap["key5_modline6_destination"] = "None";
    defaultPresetMap["key5_modline6_note"] = 60;
    defaultPresetMap["key5_modline6_velocity"] = 127;
    defaultPresetMap["key5_modline6_cc"] = 60;
    defaultPresetMap["key5_modline6_bankMSB"] = 0;
    defaultPresetMap["key5_modline6_mmcid"] = 0;
    defaultPresetMap["key5_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key5_modline6_channel"] = 1;
    defaultPresetMap["key5_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key5_modline6_oscroute"] = "";
    defaultPresetMap["key5_modline6_ledgreen"] = "Off";
    defaultPresetMap["key5_modline6_ledred"] = "Off";
    defaultPresetMap["key5_modline6_displaylinked"] = 0;


    //------------------------ Key 6 ------------------------//
    defaultPresetMap["6_key_name"] = "6KEY";
    defaultPresetMap["6_key_displaymode"] = 1;
    defaultPresetMap["6_key_prefix"] = "";
    defaultPresetMap["6_key_counter_min"] = 0;
    defaultPresetMap["6_key_counter_max"] = 127;
    defaultPresetMap["6_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key6_modline1_enable"] = 0;
    defaultPresetMap["key6_modline1_initValue"] = 0;
    defaultPresetMap["key6_modline1_initMode"] = "None";
    defaultPresetMap["key6_modline1_source"] = "None";
    defaultPresetMap["key6_modline1_gain"] = 1.00;
    defaultPresetMap["key6_modline1_offset"] = 0;
    defaultPresetMap["key6_modline1_table"] = "Lin";
    defaultPresetMap["key6_modline1_min"] = 0;
    defaultPresetMap["key6_modline1_max"] = 127;
    defaultPresetMap["key6_modline1_slew"] = 0;
    defaultPresetMap["key6_modline1_delay"] = 0;
    defaultPresetMap["key6_modline1_destination"] = "None";
    defaultPresetMap["key6_modline1_note"] = 60;
    defaultPresetMap["key6_modline1_velocity"] = 127;
    defaultPresetMap["key6_modline1_cc"] = 60;
    defaultPresetMap["key6_modline1_bankMSB"] = 0;
    defaultPresetMap["key6_modline1_mmcid"] = 0;
    defaultPresetMap["key6_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key6_modline1_channel"] = 1;
    defaultPresetMap["key6_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key6_modline1_oscroute"] = "";
    defaultPresetMap["key6_modline1_ledgreen"] = "Off";
    defaultPresetMap["key6_modline1_ledred"] = "Off";
    defaultPresetMap["key6_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key6_modline2_enable"] = 0;
    defaultPresetMap["key6_modline2_initValue"] = 0;
    defaultPresetMap["key6_modline2_initMode"] = "None";
    defaultPresetMap["key6_modline2_source"] = "None";
    defaultPresetMap["key6_modline2_gain"] = 1.00;
    defaultPresetMap["key6_modline2_offset"] = 0;
    defaultPresetMap["key6_modline2_table"] = "Lin";
    defaultPresetMap["key6_modline2_min"] = 0;
    defaultPresetMap["key6_modline2_max"] = 127;
    defaultPresetMap["key6_modline2_slew"] = 0;
    defaultPresetMap["key6_modline2_delay"] = 0;
    defaultPresetMap["key6_modline2_destination"] = "None";
    defaultPresetMap["key6_modline2_note"] = 60;
    defaultPresetMap["key6_modline2_velocity"] = 127;
    defaultPresetMap["key6_modline2_cc"] = 60;
    defaultPresetMap["key6_modline2_bankMSB"] = 0;
    defaultPresetMap["key6_modline2_mmcid"] = 0;
    defaultPresetMap["key6_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key6_modline2_channel"] = 1;
    defaultPresetMap["key6_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key6_modline2_oscroute"] = "";
    defaultPresetMap["key6_modline2_ledgreen"] = "Off";
    defaultPresetMap["key6_modline2_ledred"] = "Off";
    defaultPresetMap["key6_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key6_modline3_enable"] = 0;
    defaultPresetMap["key6_modline3_initValue"] = 0;
    defaultPresetMap["key6_modline3_initMode"] = "None";
    defaultPresetMap["key6_modline3_source"] = "None";
    defaultPresetMap["key6_modline3_gain"] = 1.00;
    defaultPresetMap["key6_modline3_offset"] = 0;
    defaultPresetMap["key6_modline3_table"] = "Lin";
    defaultPresetMap["key6_modline3_min"] = 0;
    defaultPresetMap["key6_modline3_max"] = 127;
    defaultPresetMap["key6_modline3_slew"] = 0;
    defaultPresetMap["key6_modline3_delay"] = 0;
    defaultPresetMap["key6_modline3_destination"] = "None";
    defaultPresetMap["key6_modline3_note"] = 60;
    defaultPresetMap["key6_modline3_velocity"] = 127;
    defaultPresetMap["key6_modline3_cc"] = 60;
    defaultPresetMap["key6_modline3_bankMSB"] = 0;
    defaultPresetMap["key6_modline3_mmcid"] = 0;
    defaultPresetMap["key6_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key6_modline3_channel"] = 1;
    defaultPresetMap["key6_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key6_modline3_oscroute"] = "";
    defaultPresetMap["key6_modline3_ledgreen"] = "Off";
    defaultPresetMap["key6_modline3_ledred"] = "Off";
    defaultPresetMap["key6_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key6_modline4_enable"] = 0;
    defaultPresetMap["key6_modline4_initValue"] = 0;
    defaultPresetMap["key6_modline4_initMode"] = "None";
    defaultPresetMap["key6_modline4_source"] = "None";
    defaultPresetMap["key6_modline4_gain"] = 1.00;
    defaultPresetMap["key6_modline4_offset"] = 0;
    defaultPresetMap["key6_modline4_table"] = "Lin";
    defaultPresetMap["key6_modline4_min"] = 0;
    defaultPresetMap["key6_modline4_max"] = 127;
    defaultPresetMap["key6_modline4_slew"] = 0;
    defaultPresetMap["key6_modline4_delay"] = 0;
    defaultPresetMap["key6_modline4_destination"] = "None";
    defaultPresetMap["key6_modline4_note"] = 60;
    defaultPresetMap["key6_modline4_velocity"] = 127;
    defaultPresetMap["key6_modline4_cc"] = 60;
    defaultPresetMap["key6_modline4_bankMSB"] = 0;
    defaultPresetMap["key6_modline4_mmcid"] = 0;
    defaultPresetMap["key6_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key6_modline4_channel"] = 1;
    defaultPresetMap["key6_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key6_modline4_oscroute"] = "";
    defaultPresetMap["key6_modline4_ledgreen"] = "Off";
    defaultPresetMap["key6_modline4_ledred"] = "Off";
    defaultPresetMap["key6_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key6_modline5_enable"] = 0;
    defaultPresetMap["key6_modline5_initValue"] = 0;
    defaultPresetMap["key6_modline5_initMode"] = "None";
    defaultPresetMap["key6_modline5_source"] = "None";
    defaultPresetMap["key6_modline5_gain"] = 1.00;
    defaultPresetMap["key6_modline5_offset"] = 0;
    defaultPresetMap["key6_modline5_table"] = "Lin";
    defaultPresetMap["key6_modline5_min"] = 0;
    defaultPresetMap["key6_modline5_max"] = 127;
    defaultPresetMap["key6_modline5_slew"] = 0;
    defaultPresetMap["key6_modline5_delay"] = 0;
    defaultPresetMap["key6_modline5_destination"] = "None";
    defaultPresetMap["key6_modline5_note"] = 60;
    defaultPresetMap["key6_modline5_velocity"] = 127;
    defaultPresetMap["key6_modline5_cc"] = 60;
    defaultPresetMap["key6_modline5_bankMSB"] = 0;
    defaultPresetMap["key6_modline5_mmcid"] = 0;
    defaultPresetMap["key6_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key6_modline5_channel"] = 1;
    defaultPresetMap["key6_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key6_modline5_oscroute"] = "";
    defaultPresetMap["key6_modline5_ledgreen"] = "Off";
    defaultPresetMap["key6_modline5_ledred"] = "Off";
    defaultPresetMap["key6_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key6_modline6_enable"] = 0;
    defaultPresetMap["key6_modline6_initValue"] = 0;
    defaultPresetMap["key6_modline6_initMode"] = "None";
    defaultPresetMap["key6_modline6_source"] = "None";
    defaultPresetMap["key6_modline6_gain"] = 1.00;
    defaultPresetMap["key6_modline6_offset"] = 0;
    defaultPresetMap["key6_modline6_table"] = "Lin";
    defaultPresetMap["key6_modline6_min"] = 0;
    defaultPresetMap["key6_modline6_max"] = 127;
    defaultPresetMap["key6_modline6_slew"] = 0;
    defaultPresetMap["key6_modline6_delay"] = 0;
    defaultPresetMap["key6_modline6_destination"] = "None";
    defaultPresetMap["key6_modline6_note"] = 60;
    defaultPresetMap["key6_modline6_velocity"] = 127;
    defaultPresetMap["key6_modline6_cc"] = 60;
    defaultPresetMap["key6_modline6_bankMSB"] = 0;
    defaultPresetMap["key6_modline6_mmcid"] = 0;
    defaultPresetMap["key6_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key6_modline6_channel"] = 1;
    defaultPresetMap["key6_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key6_modline6_oscroute"] = "";
    defaultPresetMap["key6_modline6_ledgreen"] = "Off";
    defaultPresetMap["key6_modline6_ledred"] = "Off";
    defaultPresetMap["key6_modline6_displaylinked"] = 0;


    //------------------------ Key 7 ------------------------//
    defaultPresetMap["7_key_name"] = "7KEY";
    defaultPresetMap["7_key_displaymode"] = 1;
    defaultPresetMap["7_key_prefix"] = "";
    defaultPresetMap["7_key_counter_min"] = 0;
    defaultPresetMap["7_key_counter_max"] = 127;
    defaultPresetMap["7_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key7_modline1_enable"] = 0;
    defaultPresetMap["key7_modline1_initValue"] = 0;
    defaultPresetMap["key7_modline1_initMode"] = "None";
    defaultPresetMap["key7_modline1_source"] = "None";
    defaultPresetMap["key7_modline1_gain"] = 1.00;
    defaultPresetMap["key7_modline1_offset"] = 0;
    defaultPresetMap["key7_modline1_table"] = "Lin";
    defaultPresetMap["key7_modline1_min"] = 0;
    defaultPresetMap["key7_modline1_max"] = 127;
    defaultPresetMap["key7_modline1_slew"] = 0;
    defaultPresetMap["key7_modline1_delay"] = 0;
    defaultPresetMap["key7_modline1_destination"] = "None";
    defaultPresetMap["key7_modline1_note"] = 60;
    defaultPresetMap["key7_modline1_velocity"] = 127;
    defaultPresetMap["key7_modline1_cc"] = 60;
    defaultPresetMap["key7_modline1_bankMSB"] = 0;
    defaultPresetMap["key7_modline1_mmcid"] = 0;
    defaultPresetMap["key7_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key7_modline1_channel"] = 1;
    defaultPresetMap["key7_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key7_modline1_oscroute"] = "";
    defaultPresetMap["key7_modline1_ledgreen"] = "Off";
    defaultPresetMap["key7_modline1_ledred"] = "Off";
    defaultPresetMap["key7_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key7_modline2_enable"] = 0;
    defaultPresetMap["key7_modline2_initValue"] = 0;
    defaultPresetMap["key7_modline2_initMode"] = "None";
    defaultPresetMap["key7_modline2_source"] = "None";
    defaultPresetMap["key7_modline2_gain"] = 1.00;
    defaultPresetMap["key7_modline2_offset"] = 0;
    defaultPresetMap["key7_modline2_table"] = "Lin";
    defaultPresetMap["key7_modline2_min"] = 0;
    defaultPresetMap["key7_modline2_max"] = 127;
    defaultPresetMap["key7_modline2_slew"] = 0;
    defaultPresetMap["key7_modline2_delay"] = 0;
    defaultPresetMap["key7_modline2_destination"] = "None";
    defaultPresetMap["key7_modline2_note"] = 60;
    defaultPresetMap["key7_modline2_velocity"] = 127;
    defaultPresetMap["key7_modline2_cc"] = 60;
    defaultPresetMap["key7_modline2_bankMSB"] = 0;
    defaultPresetMap["key7_modline2_mmcid"] = 0;
    defaultPresetMap["key7_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key7_modline2_channel"] = 1;
    defaultPresetMap["key7_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key7_modline2_oscroute"] = "";
    defaultPresetMap["key7_modline2_ledgreen"] = "Off";
    defaultPresetMap["key7_modline2_ledred"] = "Off";
    defaultPresetMap["key7_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key7_modline3_enable"] = 0;
    defaultPresetMap["key7_modline3_initValue"] = 0;
    defaultPresetMap["key7_modline3_initMode"] = "None";
    defaultPresetMap["key7_modline3_source"] = "None";
    defaultPresetMap["key7_modline3_gain"] = 1.00;
    defaultPresetMap["key7_modline3_offset"] = 0;
    defaultPresetMap["key7_modline3_table"] = "Lin";
    defaultPresetMap["key7_modline3_min"] = 0;
    defaultPresetMap["key7_modline3_max"] = 127;
    defaultPresetMap["key7_modline3_slew"] = 0;
    defaultPresetMap["key7_modline3_delay"] = 0;
    defaultPresetMap["key7_modline3_destination"] = "None";
    defaultPresetMap["key7_modline3_note"] = 60;
    defaultPresetMap["key7_modline3_velocity"] = 127;
    defaultPresetMap["key7_modline3_cc"] = 60;
    defaultPresetMap["key7_modline3_bankMSB"] = 0;
    defaultPresetMap["key7_modline3_mmcid"] = 0;
    defaultPresetMap["key7_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key7_modline3_channel"] = 1;
    defaultPresetMap["key7_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key7_modline3_oscroute"] = "";
    defaultPresetMap["key7_modline3_ledgreen"] = "Off";
    defaultPresetMap["key7_modline3_ledred"] = "Off";
    defaultPresetMap["key7_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key7_modline4_enable"] = 0;
    defaultPresetMap["key7_modline4_initValue"] = 0;
    defaultPresetMap["key7_modline4_initMode"] = "None";
    defaultPresetMap["key7_modline4_source"] = "None";
    defaultPresetMap["key7_modline4_gain"] = 1.00;
    defaultPresetMap["key7_modline4_offset"] = 0;
    defaultPresetMap["key7_modline4_table"] = "Lin";
    defaultPresetMap["key7_modline4_min"] = 0;
    defaultPresetMap["key7_modline4_max"] = 127;
    defaultPresetMap["key7_modline4_slew"] = 0;
    defaultPresetMap["key7_modline4_delay"] = 0;
    defaultPresetMap["key7_modline4_destination"] = "None";
    defaultPresetMap["key7_modline4_note"] = 60;
    defaultPresetMap["key7_modline4_velocity"] = 127;
    defaultPresetMap["key7_modline4_cc"] = 60;
    defaultPresetMap["key7_modline4_bankMSB"] = 0;
    defaultPresetMap["key7_modline4_mmcid"] = 0;
    defaultPresetMap["key7_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key7_modline4_channel"] = 1;
    defaultPresetMap["key7_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key7_modline4_oscroute"] = "";
    defaultPresetMap["key7_modline4_ledgreen"] = "Off";
    defaultPresetMap["key7_modline4_ledred"] = "Off";
    defaultPresetMap["key7_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key7_modline5_enable"] = 0;
    defaultPresetMap["key7_modline5_initValue"] = 0;
    defaultPresetMap["key7_modline5_initMode"] = "None";
    defaultPresetMap["key7_modline5_source"] = "None";
    defaultPresetMap["key7_modline5_gain"] = 1.00;
    defaultPresetMap["key7_modline5_offset"] = 0;
    defaultPresetMap["key7_modline5_table"] = "Lin";
    defaultPresetMap["key7_modline5_min"] = 0;
    defaultPresetMap["key7_modline5_max"] = 127;
    defaultPresetMap["key7_modline5_slew"] = 0;
    defaultPresetMap["key7_modline5_delay"] = 0;
    defaultPresetMap["key7_modline5_destination"] = "None";
    defaultPresetMap["key7_modline5_note"] = 60;
    defaultPresetMap["key7_modline5_velocity"] = 127;
    defaultPresetMap["key7_modline5_cc"] = 60;
    defaultPresetMap["key7_modline5_bankMSB"] = 0;
    defaultPresetMap["key7_modline5_mmcid"] = 0;
    defaultPresetMap["key7_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key7_modline5_channel"] = 1;
    defaultPresetMap["key7_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key7_modline5_oscroute"] = "";
    defaultPresetMap["key7_modline5_ledgreen"] = "Off";
    defaultPresetMap["key7_modline5_ledred"] = "Off";
    defaultPresetMap["key7_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key7_modline6_enable"] = 0;
    defaultPresetMap["key7_modline6_initValue"] = 0;
    defaultPresetMap["key7_modline6_initMode"] = "None";
    defaultPresetMap["key7_modline6_source"] = "None";
    defaultPresetMap["key7_modline6_gain"] = 1.00;
    defaultPresetMap["key7_modline6_offset"] = 0;
    defaultPresetMap["key7_modline6_table"] = "Lin";
    defaultPresetMap["key7_modline6_min"] = 0;
    defaultPresetMap["key7_modline6_max"] = 127;
    defaultPresetMap["key7_modline6_slew"] = 0;
    defaultPresetMap["key7_modline6_delay"] = 0;
    defaultPresetMap["key7_modline6_destination"] = "None";
    defaultPresetMap["key7_modline6_note"] = 60;
    defaultPresetMap["key7_modline6_velocity"] = 127;
    defaultPresetMap["key7_modline6_cc"] = 60;
    defaultPresetMap["key7_modline6_bankMSB"] = 0;
    defaultPresetMap["key7_modline6_mmcid"] = 0;
    defaultPresetMap["key7_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key7_modline6_channel"] = 1;
    defaultPresetMap["key7_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key7_modline6_oscroute"] = "";
    defaultPresetMap["key7_modline6_ledgreen"] = "Off";
    defaultPresetMap["key7_modline6_ledred"] = "Off";
    defaultPresetMap["key7_modline6_displaylinked"] = 0;

    //------------------------ Key 8 ------------------------//
    defaultPresetMap["8_key_name"] = "8KEY";
    defaultPresetMap["8_key_displaymode"] = 1;
    defaultPresetMap["8_key_prefix"] = "";
    defaultPresetMap["8_key_counter_min"] = 0;
    defaultPresetMap["8_key_counter_max"] = 127;
    defaultPresetMap["8_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key8_modline1_enable"] = 0;
    defaultPresetMap["key8_modline1_initValue"] = 0;
    defaultPresetMap["key8_modline1_initMode"] = "None";
    defaultPresetMap["key8_modline1_source"] = "None";
    defaultPresetMap["key8_modline1_gain"] = 1.00;
    defaultPresetMap["key8_modline1_offset"] = 0;
    defaultPresetMap["key8_modline1_table"] = "Lin";
    defaultPresetMap["key8_modline1_min"] = 0;
    defaultPresetMap["key8_modline1_max"] = 127;
    defaultPresetMap["key8_modline1_slew"] = 0;
    defaultPresetMap["key8_modline1_delay"] = 0;
    defaultPresetMap["key8_modline1_destination"] = "None";
    defaultPresetMap["key8_modline1_note"] = 60;
    defaultPresetMap["key8_modline1_velocity"] = 127;
    defaultPresetMap["key8_modline1_cc"] = 60;
    defaultPresetMap["key8_modline1_bankMSB"] = 0;
    defaultPresetMap["key8_modline1_mmcid"] = 0;
    defaultPresetMap["key8_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key8_modline1_channel"] = 1;
    defaultPresetMap["key8_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key8_modline1_oscroute"] = "";
    defaultPresetMap["key8_modline1_ledgreen"] = "Off";
    defaultPresetMap["key8_modline1_ledred"] = "Off";
    defaultPresetMap["key8_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key8_modline2_enable"] = 0;
    defaultPresetMap["key8_modline2_initValue"] = 0;
    defaultPresetMap["key8_modline2_initMode"] = "None";
    defaultPresetMap["key8_modline2_source"] = "None";
    defaultPresetMap["key8_modline2_gain"] = 1.00;
    defaultPresetMap["key8_modline2_offset"] = 0;
    defaultPresetMap["key8_modline2_table"] = "Lin";
    defaultPresetMap["key8_modline2_min"] = 0;
    defaultPresetMap["key8_modline2_max"] = 127;
    defaultPresetMap["key8_modline2_slew"] = 0;
    defaultPresetMap["key8_modline2_delay"] = 0;
    defaultPresetMap["key8_modline2_destination"] = "None";
    defaultPresetMap["key8_modline2_note"] = 60;
    defaultPresetMap["key8_modline2_velocity"] = 127;
    defaultPresetMap["key8_modline2_cc"] = 60;
    defaultPresetMap["key8_modline2_bankMSB"] = 0;
    defaultPresetMap["key8_modline2_mmcid"] = 0;
    defaultPresetMap["key8_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key8_modline2_channel"] = 1;
    defaultPresetMap["key8_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key8_modline2_oscroute"] = "";
    defaultPresetMap["key8_modline2_ledgreen"] = "Off";
    defaultPresetMap["key8_modline2_ledred"] = "Off";
    defaultPresetMap["key8_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key8_modline3_enable"] = 0;
    defaultPresetMap["key8_modline3_initValue"] = 0;
    defaultPresetMap["key8_modline3_initMode"] = "None";
    defaultPresetMap["key8_modline3_source"] = "None";
    defaultPresetMap["key8_modline3_gain"] = 1.00;
    defaultPresetMap["key8_modline3_offset"] = 0;
    defaultPresetMap["key8_modline3_table"] = "Lin";
    defaultPresetMap["key8_modline3_min"] = 0;
    defaultPresetMap["key8_modline3_max"] = 127;
    defaultPresetMap["key8_modline3_slew"] = 0;
    defaultPresetMap["key8_modline3_delay"] = 0;
    defaultPresetMap["key8_modline3_destination"] = "None";
    defaultPresetMap["key8_modline3_note"] = 60;
    defaultPresetMap["key8_modline3_velocity"] = 127;
    defaultPresetMap["key8_modline3_cc"] = 60;
    defaultPresetMap["key8_modline3_bankMSB"] = 0;
    defaultPresetMap["key8_modline3_mmcid"] = 0;
    defaultPresetMap["key8_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key8_modline3_channel"] = 1;
    defaultPresetMap["key8_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key8_modline3_oscroute"] = "";
    defaultPresetMap["key8_modline3_ledgreen"] = "Off";
    defaultPresetMap["key8_modline3_ledred"] = "Off";
    defaultPresetMap["key8_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key8_modline4_enable"] = 0;
    defaultPresetMap["key8_modline4_initValue"] = 0;
    defaultPresetMap["key8_modline4_initMode"] = "None";
    defaultPresetMap["key8_modline4_source"] = "None";
    defaultPresetMap["key8_modline4_gain"] = 1.00;
    defaultPresetMap["key8_modline4_offset"] = 0;
    defaultPresetMap["key8_modline4_table"] = "Lin";
    defaultPresetMap["key8_modline4_min"] = 0;
    defaultPresetMap["key8_modline4_max"] = 127;
    defaultPresetMap["key8_modline4_slew"] = 0;
    defaultPresetMap["key8_modline4_delay"] = 0;
    defaultPresetMap["key8_modline4_destination"] = "None";
    defaultPresetMap["key8_modline4_note"] = 60;
    defaultPresetMap["key8_modline4_velocity"] = 127;
    defaultPresetMap["key8_modline4_cc"] = 60;
    defaultPresetMap["key8_modline4_bankMSB"] = 0;
    defaultPresetMap["key8_modline4_mmcid"] = 0;
    defaultPresetMap["key8_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key8_modline4_channel"] = 1;
    defaultPresetMap["key8_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key8_modline4_oscroute"] = "";
    defaultPresetMap["key8_modline4_ledgreen"] = "Off";
    defaultPresetMap["key8_modline4_ledred"] = "Off";
    defaultPresetMap["key8_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key8_modline5_enable"] = 0;
    defaultPresetMap["key8_modline5_initValue"] = 0;
    defaultPresetMap["key8_modline5_initMode"] = "None";
    defaultPresetMap["key8_modline5_source"] = "None";
    defaultPresetMap["key8_modline5_gain"] = 1.00;
    defaultPresetMap["key8_modline5_offset"] = 0;
    defaultPresetMap["key8_modline5_table"] = "Lin";
    defaultPresetMap["key8_modline5_min"] = 0;
    defaultPresetMap["key8_modline5_max"] = 127;
    defaultPresetMap["key8_modline5_slew"] = 0;
    defaultPresetMap["key8_modline5_delay"] = 0;
    defaultPresetMap["key8_modline5_destination"] = "None";
    defaultPresetMap["key8_modline5_note"] = 60;
    defaultPresetMap["key8_modline5_velocity"] = 127;
    defaultPresetMap["key8_modline5_cc"] = 60;
    defaultPresetMap["key8_modline5_bankMSB"] = 0;
    defaultPresetMap["key8_modline5_mmcid"] = 0;
    defaultPresetMap["key8_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key8_modline5_channel"] = 1;
    defaultPresetMap["key8_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key8_modline5_oscroute"] = "";
    defaultPresetMap["key8_modline5_ledgreen"] = "Off";
    defaultPresetMap["key8_modline5_ledred"] = "Off";
    defaultPresetMap["key8_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key8_modline6_enable"] = 0;
    defaultPresetMap["key8_modline6_initValue"] = 0;
    defaultPresetMap["key8_modline6_initMode"] = "None";
    defaultPresetMap["key8_modline6_source"] = "None";
    defaultPresetMap["key8_modline6_gain"] = 1.00;
    defaultPresetMap["key8_modline6_offset"] = 0;
    defaultPresetMap["key8_modline6_table"] = "Lin";
    defaultPresetMap["key8_modline6_min"] = 0;
    defaultPresetMap["key8_modline6_max"] = 127;
    defaultPresetMap["key8_modline6_slew"] = 0;
    defaultPresetMap["key8_modline6_delay"] = 0;
    defaultPresetMap["key8_modline6_destination"] = "None";
    defaultPresetMap["key8_modline6_note"] = 60;
    defaultPresetMap["key8_modline6_velocity"] = 127;
    defaultPresetMap["key8_modline6_cc"] = 60;
    defaultPresetMap["key8_modline6_bankMSB"] = 0;
    defaultPresetMap["key8_modline6_mmcid"] = 0;
    defaultPresetMap["key8_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key8_modline6_channel"] = 1;
    defaultPresetMap["key8_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key8_modline6_oscroute"] = "";
    defaultPresetMap["key8_modline6_ledgreen"] = "Off";
    defaultPresetMap["key8_modline6_ledred"] = "Off";
    defaultPresetMap["key8_modline6_displaylinked"] = 0;


    //------------------------ Key 9 ------------------------//
    defaultPresetMap["9_key_name"] = "9KEY";
    defaultPresetMap["9_key_displaymode"] = 1;
    defaultPresetMap["9_key_prefix"] = "";
    defaultPresetMap["9_key_counter_min"] = 0;
    defaultPresetMap["9_key_counter_max"] = 127;
    defaultPresetMap["9_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key9_modline1_enable"] = 0;
    defaultPresetMap["key9_modline1_initValue"] = 0;
    defaultPresetMap["key9_modline1_initMode"] = "None";
    defaultPresetMap["key9_modline1_source"] = "None";
    defaultPresetMap["key9_modline1_gain"] = 1.00;
    defaultPresetMap["key9_modline1_offset"] = 0;
    defaultPresetMap["key9_modline1_table"] = "Lin";
    defaultPresetMap["key9_modline1_min"] = 0;
    defaultPresetMap["key9_modline1_max"] = 127;
    defaultPresetMap["key9_modline1_slew"] = 0;
    defaultPresetMap["key9_modline1_delay"] = 0;
    defaultPresetMap["key9_modline1_destination"] = "None";
    defaultPresetMap["key9_modline1_note"] = 60;
    defaultPresetMap["key9_modline1_velocity"] = 127;
    defaultPresetMap["key9_modline1_cc"] = 60;
    defaultPresetMap["key9_modline1_bankMSB"] = 0;
    defaultPresetMap["key9_modline1_mmcid"] = 0;
    defaultPresetMap["key9_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key9_modline1_channel"] = 1;
    defaultPresetMap["key9_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key9_modline1_oscroute"] = "";
    defaultPresetMap["key9_modline1_ledgreen"] = "Off";
    defaultPresetMap["key9_modline1_ledred"] = "Off";
    defaultPresetMap["key9_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key9_modline2_enable"] = 0;
    defaultPresetMap["key9_modline2_initValue"] = 0;
    defaultPresetMap["key9_modline2_initMode"] = "None";
    defaultPresetMap["key9_modline2_source"] = "None";
    defaultPresetMap["key9_modline2_gain"] = 1.00;
    defaultPresetMap["key9_modline2_offset"] = 0;
    defaultPresetMap["key9_modline2_table"] = "Lin";
    defaultPresetMap["key9_modline2_min"] = 0;
    defaultPresetMap["key9_modline2_max"] = 127;
    defaultPresetMap["key9_modline2_slew"] = 0;
    defaultPresetMap["key9_modline2_delay"] = 0;
    defaultPresetMap["key9_modline2_destination"] = "None";
    defaultPresetMap["key9_modline2_note"] = 60;
    defaultPresetMap["key9_modline2_velocity"] = 127;
    defaultPresetMap["key9_modline2_cc"] = 60;
    defaultPresetMap["key9_modline2_bankMSB"] = 0;
    defaultPresetMap["key9_modline2_mmcid"] = 0;
    defaultPresetMap["key9_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key9_modline2_channel"] = 1;
    defaultPresetMap["key9_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key9_modline2_oscroute"] = "";
    defaultPresetMap["key9_modline2_ledgreen"] = "Off";
    defaultPresetMap["key9_modline2_ledred"] = "Off";
    defaultPresetMap["key9_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key9_modline3_enable"] = 0;
    defaultPresetMap["key9_modline3_initValue"] = 0;
    defaultPresetMap["key9_modline3_initMode"] = "None";
    defaultPresetMap["key9_modline3_source"] = "None";
    defaultPresetMap["key9_modline3_gain"] = 1.00;
    defaultPresetMap["key9_modline3_offset"] = 0;
    defaultPresetMap["key9_modline3_table"] = "Lin";
    defaultPresetMap["key9_modline3_min"] = 0;
    defaultPresetMap["key9_modline3_max"] = 127;
    defaultPresetMap["key9_modline3_slew"] = 0;
    defaultPresetMap["key9_modline3_delay"] = 0;
    defaultPresetMap["key9_modline3_destination"] = "None";
    defaultPresetMap["key9_modline3_note"] = 60;
    defaultPresetMap["key9_modline3_velocity"] = 127;
    defaultPresetMap["key9_modline3_cc"] = 60;
    defaultPresetMap["key9_modline3_bankMSB"] = 0;
    defaultPresetMap["key9_modline3_mmcid"] = 0;
    defaultPresetMap["key9_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key9_modline3_channel"] = 1;
    defaultPresetMap["key9_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key9_modline3_oscroute"] = "";
    defaultPresetMap["key9_modline3_ledgreen"] = "Off";
    defaultPresetMap["key9_modline3_ledred"] = "Off";
    defaultPresetMap["key9_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key9_modline4_enable"] = 0;
    defaultPresetMap["key9_modline4_initValue"] = 0;
    defaultPresetMap["key9_modline4_initMode"] = "None";
    defaultPresetMap["key9_modline4_source"] = "None";
    defaultPresetMap["key9_modline4_gain"] = 1.00;
    defaultPresetMap["key9_modline4_offset"] = 0;
    defaultPresetMap["key9_modline4_table"] = "Lin";
    defaultPresetMap["key9_modline4_min"] = 0;
    defaultPresetMap["key9_modline4_max"] = 127;
    defaultPresetMap["key9_modline4_slew"] = 0;
    defaultPresetMap["key9_modline4_delay"] = 0;
    defaultPresetMap["key9_modline4_destination"] = "None";
    defaultPresetMap["key9_modline4_note"] = 60;
    defaultPresetMap["key9_modline4_velocity"] = 127;
    defaultPresetMap["key9_modline4_cc"] = 60;
    defaultPresetMap["key9_modline4_bankMSB"] = 0;
    defaultPresetMap["key9_modline4_mmcid"] = 0;
    defaultPresetMap["key9_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key9_modline4_channel"] = 1;
    defaultPresetMap["key9_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key9_modline4_oscroute"] = "";
    defaultPresetMap["key9_modline4_ledgreen"] = "Off";
    defaultPresetMap["key9_modline4_ledred"] = "Off";
    defaultPresetMap["key9_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key9_modline5_enable"] = 0;
    defaultPresetMap["key9_modline5_initValue"] = 0;
    defaultPresetMap["key9_modline5_initMode"] = "None";
    defaultPresetMap["key9_modline5_source"] = "None";
    defaultPresetMap["key9_modline5_gain"] = 1.00;
    defaultPresetMap["key9_modline5_offset"] = 0;
    defaultPresetMap["key9_modline5_table"] = "Lin";
    defaultPresetMap["key9_modline5_min"] = 0;
    defaultPresetMap["key9_modline5_max"] = 127;
    defaultPresetMap["key9_modline5_slew"] = 0;
    defaultPresetMap["key9_modline5_delay"] = 0;
    defaultPresetMap["key9_modline5_destination"] = "None";
    defaultPresetMap["key9_modline5_note"] = 60;
    defaultPresetMap["key9_modline5_velocity"] = 127;
    defaultPresetMap["key9_modline5_cc"] = 60;
    defaultPresetMap["key9_modline5_bankMSB"] = 0;
    defaultPresetMap["key9_modline5_mmcid"] = 0;
    defaultPresetMap["key9_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key9_modline5_channel"] = 1;
    defaultPresetMap["key9_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key9_modline5_oscroute"] = "";
    defaultPresetMap["key9_modline5_ledgreen"] = "Off";
    defaultPresetMap["key9_modline5_ledred"] = "Off";
    defaultPresetMap["key9_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key9_modline6_enable"] = 0;
    defaultPresetMap["key9_modline6_initValue"] = 0;
    defaultPresetMap["key9_modline6_initMode"] = "None";
    defaultPresetMap["key9_modline6_source"] = "None";
    defaultPresetMap["key9_modline6_gain"] = 1.00;
    defaultPresetMap["key9_modline6_offset"] = 0;
    defaultPresetMap["key9_modline6_table"] = "Lin";
    defaultPresetMap["key9_modline6_min"] = 0;
    defaultPresetMap["key9_modline6_max"] = 127;
    defaultPresetMap["key9_modline6_slew"] = 0;
    defaultPresetMap["key9_modline6_delay"] = 0;
    defaultPresetMap["key9_modline6_destination"] = "None";
    defaultPresetMap["key9_modline6_note"] = 60;
    defaultPresetMap["key9_modline6_velocity"] = 127;
    defaultPresetMap["key9_modline6_cc"] = 60;
    defaultPresetMap["key9_modline6_bankMSB"] = 0;
    defaultPresetMap["key9_modline6_mmcid"] = 0;
    defaultPresetMap["key9_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key9_modline6_channel"] = 1;
    defaultPresetMap["key9_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key9_modline6_oscroute"] = "";
    defaultPresetMap["key9_modline6_ledgreen"] = "Off";
    defaultPresetMap["key9_modline6_ledred"] = "Off";
    defaultPresetMap["key9_modline6_displaylinked"] = 0;


    //------------------------ Key 10 ------------------------//
    defaultPresetMap["10_key_name"] = "0KEY";
    defaultPresetMap["10_key_displaymode"] = 1;
    defaultPresetMap["10_key_prefix"] = "";
    defaultPresetMap["10_key_counter_min"] = 0;
    defaultPresetMap["10_key_counter_max"] = 127;
    defaultPresetMap["10_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key10_modline1_enable"] = 0;
    defaultPresetMap["key10_modline1_initValue"] = 0;
    defaultPresetMap["key10_modline1_initMode"] = "None";
    defaultPresetMap["key10_modline1_source"] = "None";
    defaultPresetMap["key10_modline1_gain"] = 1.00;
    defaultPresetMap["key10_modline1_offset"] = 0;
    defaultPresetMap["key10_modline1_table"] = "Lin";
    defaultPresetMap["key10_modline1_min"] = 0;
    defaultPresetMap["key10_modline1_max"] = 127;
    defaultPresetMap["key10_modline1_slew"] = 0;
    defaultPresetMap["key10_modline1_delay"] = 0;
    defaultPresetMap["key10_modline1_destination"] = "None";
    defaultPresetMap["key10_modline1_note"] = 60;
    defaultPresetMap["key10_modline1_velocity"] = 127;
    defaultPresetMap["key10_modline1_cc"] = 60;
    defaultPresetMap["key10_modline1_bankMSB"] = 0;
    defaultPresetMap["key10_modline1_mmcid"] = 0;
    defaultPresetMap["key10_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["key10_modline1_channel"] = 1;
    defaultPresetMap["key10_modline1_device"] = "SSCOM Port 1";
    defaultPresetMap["key10_modline1_oscroute"] = "";
    defaultPresetMap["key10_modline1_ledgreen"] = "Off";
    defaultPresetMap["key10_modline1_ledred"] = "Off";
    defaultPresetMap["key10_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key10_modline2_enable"] = 0;
    defaultPresetMap["key10_modline2_initValue"] = 0;
    defaultPresetMap["key10_modline2_initMode"] = "None";
    defaultPresetMap["key10_modline2_source"] = "None";
    defaultPresetMap["key10_modline2_gain"] = 1.00;
    defaultPresetMap["key10_modline2_offset"] = 0;
    defaultPresetMap["key10_modline2_table"] = "Lin";
    defaultPresetMap["key10_modline2_min"] = 0;
    defaultPresetMap["key10_modline2_max"] = 127;
    defaultPresetMap["key10_modline2_slew"] = 0;
    defaultPresetMap["key10_modline2_delay"] = 0;
    defaultPresetMap["key10_modline2_destination"] = "None";
    defaultPresetMap["key10_modline2_note"] = 60;
    defaultPresetMap["key10_modline2_velocity"] = 127;
    defaultPresetMap["key10_modline2_cc"] = 60;
    defaultPresetMap["key10_modline2_bankMSB"] = 0;
    defaultPresetMap["key10_modline2_mmcid"] = 0;
    defaultPresetMap["key10_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["key10_modline2_channel"] = 1;
    defaultPresetMap["key10_modline2_device"] = "SSCOM Port 1";
    defaultPresetMap["key10_modline2_oscroute"] = "";
    defaultPresetMap["key10_modline2_ledgreen"] = "Off";
    defaultPresetMap["key10_modline2_ledred"] = "Off";
    defaultPresetMap["key10_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key10_modline3_enable"] = 0;
    defaultPresetMap["key10_modline3_initValue"] = 0;
    defaultPresetMap["key10_modline3_initMode"] = "None";
    defaultPresetMap["key10_modline3_source"] = "None";
    defaultPresetMap["key10_modline3_gain"] = 1.00;
    defaultPresetMap["key10_modline3_offset"] = 0;
    defaultPresetMap["key10_modline3_table"] = "Lin";
    defaultPresetMap["key10_modline3_min"] = 0;
    defaultPresetMap["key10_modline3_max"] = 127;
    defaultPresetMap["key10_modline3_slew"] = 0;
    defaultPresetMap["key10_modline3_delay"] = 0;
    defaultPresetMap["key10_modline3_destination"] = "None";
    defaultPresetMap["key10_modline3_note"] = 60;
    defaultPresetMap["key10_modline3_velocity"] = 127;
    defaultPresetMap["key10_modline3_cc"] = 60;
    defaultPresetMap["key10_modline3_bankMSB"] = 0;
    defaultPresetMap["key10_modline3_mmcid"] = 0;
    defaultPresetMap["key10_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["key10_modline3_channel"] = 1;
    defaultPresetMap["key10_modline3_device"] = "SSCOM Port 1";
    defaultPresetMap["key10_modline3_oscroute"] = "";
    defaultPresetMap["key10_modline3_ledgreen"] = "Off";
    defaultPresetMap["key10_modline3_ledred"] = "Off";
    defaultPresetMap["key10_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key10_modline4_enable"] = 0;
    defaultPresetMap["key10_modline4_initValue"] = 0;
    defaultPresetMap["key10_modline4_initMode"] = "None";
    defaultPresetMap["key10_modline4_source"] = "None";
    defaultPresetMap["key10_modline4_gain"] = 1.00;
    defaultPresetMap["key10_modline4_offset"] = 0;
    defaultPresetMap["key10_modline4_table"] = "Lin";
    defaultPresetMap["key10_modline4_min"] = 0;
    defaultPresetMap["key10_modline4_max"] = 127;
    defaultPresetMap["key10_modline4_slew"] = 0;
    defaultPresetMap["key10_modline4_delay"] = 0;
    defaultPresetMap["key10_modline4_destination"] = "None";
    defaultPresetMap["key10_modline4_note"] = 60;
    defaultPresetMap["key10_modline4_velocity"] = 127;
    defaultPresetMap["key10_modline4_cc"] = 60;
    defaultPresetMap["key10_modline4_bankMSB"] = 0;
    defaultPresetMap["key10_modline4_mmcid"] = 0;
    defaultPresetMap["key10_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["key10_modline4_channel"] = 1;
    defaultPresetMap["key10_modline4_device"] = "SSCOM Port 1";
    defaultPresetMap["key10_modline4_oscroute"] = "";
    defaultPresetMap["key10_modline4_ledgreen"] = "Off";
    defaultPresetMap["key10_modline4_ledred"] = "Off";
    defaultPresetMap["key10_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key10_modline5_enable"] = 0;
    defaultPresetMap["key10_modline5_initValue"] = 0;
    defaultPresetMap["key10_modline5_initMode"] = "None";
    defaultPresetMap["key10_modline5_source"] = "None";
    defaultPresetMap["key10_modline5_gain"] = 1.00;
    defaultPresetMap["key10_modline5_offset"] = 0;
    defaultPresetMap["key10_modline5_table"] = "Lin";
    defaultPresetMap["key10_modline5_min"] = 0;
    defaultPresetMap["key10_modline5_max"] = 127;
    defaultPresetMap["key10_modline5_slew"] = 0;
    defaultPresetMap["key10_modline5_delay"] = 0;
    defaultPresetMap["key10_modline5_destination"] = "None";
    defaultPresetMap["key10_modline5_note"] = 60;
    defaultPresetMap["key10_modline5_velocity"] = 127;
    defaultPresetMap["key10_modline5_cc"] = 60;
    defaultPresetMap["key10_modline5_bankMSB"] = 0;
    defaultPresetMap["key10_modline5_mmcid"] = 0;
    defaultPresetMap["key10_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["key10_modline5_channel"] = 1;
    defaultPresetMap["key10_modline5_device"] = "SSCOM Port 1";
    defaultPresetMap["key10_modline5_oscroute"] = "";
    defaultPresetMap["key10_modline5_ledgreen"] = "Off";
    defaultPresetMap["key10_modline5_ledred"] = "Off";
    defaultPresetMap["key10_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key10_modline6_enable"] = 0;
    defaultPresetMap["key10_modline6_initValue"] = 0;
    defaultPresetMap["key10_modline6_initMode"] = "None";
    defaultPresetMap["key10_modline6_source"] = "None";
    defaultPresetMap["key10_modline6_gain"] = 1.00;
    defaultPresetMap["key10_modline6_offset"] = 0;
    defaultPresetMap["key10_modline6_table"] = "Lin";
    defaultPresetMap["key10_modline6_min"] = 0;
    defaultPresetMap["key10_modline6_max"] = 127;
    defaultPresetMap["key10_modline6_slew"] = 0;
    defaultPresetMap["key10_modline6_delay"] = 0;
    defaultPresetMap["key10_modline6_destination"] = "None";
    defaultPresetMap["key10_modline6_note"] = 60;
    defaultPresetMap["key10_modline6_velocity"] = 127;
    defaultPresetMap["key10_modline6_cc"] = 60;
    defaultPresetMap["key10_modline6_bankMSB"] = 0;
    defaultPresetMap["key10_modline6_mmcid"] = 0;
    defaultPresetMap["key10_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["key10_modline6_channel"] = 1;
    defaultPresetMap["key10_modline6_device"] = "SSCOM Port 1";
    defaultPresetMap["key10_modline6_oscroute"] = "";
    defaultPresetMap["key10_modline6_ledgreen"] = "Off";
    defaultPresetMap["key10_modline6_ledred"] = "Off";
    defaultPresetMap["key10_modline6_displaylinked"] = 0;

    //------------------------ Nav ------------------------//
    defaultPresetMap["nav_name"] = "1KEY";
    defaultPresetMap["nav_displaymode"] = 1;
    defaultPresetMap["nav_modlinemode"] = 1;
    defaultPresetMap["nav_prefix"] = "";
    defaultPresetMap["nav_counter_min"] = 0;
    defaultPresetMap["nav_counter_max"] = 127;
    defaultPresetMap["nav_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["nav_modline1_enable"] = 0.00;
    defaultPresetMap["nav_modline1_source"] = "None";
    defaultPresetMap["nav_modline1_gain"] = 0.00;
    defaultPresetMap["nav_modline1_offset"] = 0;
    defaultPresetMap["nav_modline1_table"] = "Lin";
    defaultPresetMap["nav_modline1_min"] = 0;
    defaultPresetMap["nav_modline1_max"] = 127;
    defaultPresetMap["nav_modline1_slew"] = 0;
    defaultPresetMap["nav_modline1_destination"] = "None";
    defaultPresetMap["nav_modline1_note"] = 60;
    defaultPresetMap["nav_modline1_velocity"] = 127;
    defaultPresetMap["nav_modline1_cc"] = 1;
    defaultPresetMap["nav_modline1_mmcid"] = 0;
    defaultPresetMap["nav_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline1_channel"] = 0;
    defaultPresetMap["nav_modline1_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline1_displaylinked"] = 0;
    defaultPresetMap["nav_modline1_reminder"] = "";

    //------ Modline 2 ------//
    defaultPresetMap["nav_modline2_enable"] = 0.00;
    defaultPresetMap["nav_modline2_source"] = "None";
    defaultPresetMap["nav_modline2_gain"] = 0.00;
    defaultPresetMap["nav_modline2_offset"] = 0;
    defaultPresetMap["nav_modline2_table"] = "Lin";
    defaultPresetMap["nav_modline2_min"] = 0;
    defaultPresetMap["nav_modline2_max"] = 127;
    defaultPresetMap["nav_modline2_slew"] = 0;
    defaultPresetMap["nav_modline2_destination"] = "None";
    defaultPresetMap["nav_modline2_note"] = 60;
    defaultPresetMap["nav_modline2_velocity"] = 127;
    defaultPresetMap["nav_modline2_cc"] = 1;
    defaultPresetMap["nav_modline2_mmcid"] = 0;
    defaultPresetMap["nav_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline2_channel"] = 0;
    defaultPresetMap["nav_modline2_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline2_displaylinked"] = 0;
    defaultPresetMap["nav_modline2_reminder"] = "";

    //------ Modline 3 ------//
    defaultPresetMap["nav_modline3_enable"] = 0.00;
    defaultPresetMap["nav_modline3_source"] = "None";
    defaultPresetMap["nav_modline3_gain"] = 0.00;
    defaultPresetMap["nav_modline3_offset"] = 0;
    defaultPresetMap["nav_modline3_table"] = "Lin";
    defaultPresetMap["nav_modline3_min"] = 0;
    defaultPresetMap["nav_modline3_max"] = 127;
    defaultPresetMap["nav_modline3_slew"] = 0;
    defaultPresetMap["nav_modline3_destination"] = "None";
    defaultPresetMap["nav_modline3_note"] = 60;
    defaultPresetMap["nav_modline3_velocity"] = 127;
    defaultPresetMap["nav_modline3_cc"] = 1;
    defaultPresetMap["nav_modline3_mmcid"] = 0;
    defaultPresetMap["nav_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline3_channel"] = 0;
    defaultPresetMap["nav_modline3_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline3_displaylinked"] = 0;
    defaultPresetMap["nav_modline3_reminder"] = "";

    //------ Modline 4 ------//
    defaultPresetMap["nav_modline4_enable"] = 0.00;
    defaultPresetMap["nav_modline4_source"] = "None";
    defaultPresetMap["nav_modline4_gain"] = 0.00;
    defaultPresetMap["nav_modline4_offset"] = 0;
    defaultPresetMap["nav_modline4_table"] = "Lin";
    defaultPresetMap["nav_modline4_min"] = 0;
    defaultPresetMap["nav_modline4_max"] = 127;
    defaultPresetMap["nav_modline4_slew"] = 0;
    defaultPresetMap["nav_modline4_destination"] = "None";
    defaultPresetMap["nav_modline4_note"] = 60;
    defaultPresetMap["nav_modline4_velocity"] = 127;
    defaultPresetMap["nav_modline4_cc"] = 1;
    defaultPresetMap["nav_modline4_mmcid"] = 0;
    defaultPresetMap["nav_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline4_channel"] = 0;
    defaultPresetMap["nav_modline4_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline4_displaylinked"] = 0;
    defaultPresetMap["nav_modline4_reminder"] = "";

    //------ Modline 5 ------//
    defaultPresetMap["nav_modline5_enable"] = 0.00;
    defaultPresetMap["nav_modline5_source"] = "None";
    defaultPresetMap["nav_modline5_gain"] = 0.00;
    defaultPresetMap["nav_modline5_offset"] = 0;
    defaultPresetMap["nav_modline5_table"] = "Lin";
    defaultPresetMap["nav_modline5_min"] = 0;
    defaultPresetMap["nav_modline5_max"] = 127;
    defaultPresetMap["nav_modline5_slew"] = 0;
    defaultPresetMap["nav_modline5_destination"] = "None";
    defaultPresetMap["nav_modline5_note"] = 60;
    defaultPresetMap["nav_modline5_velocity"] = 127;
    defaultPresetMap["nav_modline5_cc"] = 1;
    defaultPresetMap["nav_modline5_mmcid"] = 0;
    defaultPresetMap["nav_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline5_channel"] = 0;
    defaultPresetMap["nav_modline5_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline5_displaylinked"] = 0;
    defaultPresetMap["nav_modline5_reminder"] = "";

    //------ Modline 6 ------//
    defaultPresetMap["nav_modline6_enable"] = 0.00;
    defaultPresetMap["nav_modline6_source"] = "None";
    defaultPresetMap["nav_modline6_gain"] = 0.00;
    defaultPresetMap["nav_modline6_offset"] = 0;
    defaultPresetMap["nav_modline6_table"] = "Lin";
    defaultPresetMap["nav_modline6_min"] = 0;
    defaultPresetMap["nav_modline6_max"] = 127;
    defaultPresetMap["nav_modline6_slew"] = 0;
    defaultPresetMap["nav_modline6_destination"] = "None";
    defaultPresetMap["nav_modline6_note"] = 60;
    defaultPresetMap["nav_modline6_velocity"] = 127;
    defaultPresetMap["nav_modline6_cc"] = 1;
    defaultPresetMap["nav_modline6_mmcid"] = 0;
    defaultPresetMap["nav_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline6_channel"] = 0;
    defaultPresetMap["nav_modline6_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline6_displaylinked"] = 0;
    defaultPresetMap["nav_modline6_reminder"] = "";
}

void PresetInterface::slotConstructGlobalDefaultMap()
{
    //-------------------- Settings --------------------//
    defaultGlobalMap["key1_settings_xdead"] = 33;
    defaultGlobalMap["key1_settings_ydead"] = 33;
    defaultGlobalMap["key1_settings_xaccel"] = 33;
    defaultGlobalMap["key1_settings_ydead"] = 33;
    defaultGlobalMap["key1_settings_onthresh"] = 10;
    defaultGlobalMap["key1_settings_offthresh"] = 5;
    defaultGlobalMap["key2_settings_xdead"] = 0;
    defaultGlobalMap["key2_settings_ydead"] = 0;
    defaultGlobalMap["key2_settings_xaccel"] = 0;
    defaultGlobalMap["key2_settings_ydead"] = 0;
    defaultGlobalMap["key2_settings_onthresh"] = 10;
    defaultGlobalMap["key2_settings_offthresh"] = 5;
    defaultGlobalMap["key3_settings_xdead"] = 0;
    defaultGlobalMap["key3_settings_ydead"] = 0;
    defaultGlobalMap["key3_settings_xaccel"] = 0;
    defaultGlobalMap["key3_settings_ydead"] = 0;
    defaultGlobalMap["key3_settings_onthresh"] = 10;
    defaultGlobalMap["key3_settings_offthresh"] = 5;
    defaultGlobalMap["key4_settings_xdead"] = 0;
    defaultGlobalMap["key4_settings_ydead"] = 0;
    defaultGlobalMap["key4_settings_xaccel"] = 0;
    defaultGlobalMap["key4_settings_ydead"] = 0;
    defaultGlobalMap["key4_settings_onthresh"] = 10;
    defaultGlobalMap["key4_settings_offthresh"] = 5;
    defaultGlobalMap["key5_settings_xdead"] = 0;
    defaultGlobalMap["key5_settings_ydead"] = 0;
    defaultGlobalMap["key5_settings_xaccel"] = 0;
    defaultGlobalMap["key5_settings_ydead"] = 0;
    defaultGlobalMap["key5_settings_onthresh"] = 10;
    defaultGlobalMap["key5_settings_offthresh"] = 5;
    defaultGlobalMap["key6_settings_xdead"] = 0;
    defaultGlobalMap["key6_settings_ydead"] = 0;
    defaultGlobalMap["key6_settings_xaccel"] = 0;
    defaultGlobalMap["key6_settings_ydead"] = 0;
    defaultGlobalMap["key6_settings_onthresh"] = 10;
    defaultGlobalMap["key6_settings_offthresh"] = 5;
    defaultGlobalMap["key7_settings_xdead"] = 0;
    defaultGlobalMap["key7_settings_ydead"] = 0;
    defaultGlobalMap["key7_settings_xaccel"] = 0;
    defaultGlobalMap["key7_settings_ydead"] = 0;
    defaultGlobalMap["key7_settings_onthresh"] = 10;
    defaultGlobalMap["key7_settings_offthresh"] = 5;
    defaultGlobalMap["key8_settings_xdead"] = 0;
    defaultGlobalMap["key8_settings_ydead"] = 0;
    defaultGlobalMap["key8_settings_xaccel"] = 0;
    defaultGlobalMap["key8_settings_ydead"] = 0;
    defaultGlobalMap["key8_settings_onthresh"] = 10;
    defaultGlobalMap["key8_settings_offthresh"] = 5;
    defaultGlobalMap["key9_settings_xdead"] = 0;
    defaultGlobalMap["key9_settings_ydead"] = 0;
    defaultGlobalMap["key9_settings_xaccel"] = 0;
    defaultGlobalMap["key9_settings_ydead"] = 0;
    defaultGlobalMap["key9_settings_onthresh"] = 10;
    defaultGlobalMap["key9_settings_offthresh"] = 5;
    defaultGlobalMap["key10_settings_xdead"] = 0;
    defaultGlobalMap["key10_settings_ydead"] = 0;
    defaultGlobalMap["key10_settings_xaccel"] = 0;
    defaultGlobalMap["key10_settings_ydead"] = 0;
    defaultGlobalMap["key10_settings_onthresh"] = 10;
    defaultGlobalMap["key10_settings_offthresh"] = 5;

    defaultGlobalMap["nav_north_settings_onThresh"] = 10;
    defaultGlobalMap["nav_north_settings_offThresh"] = 5;
    defaultGlobalMap["nav_south_settings_onThresh"] = 10;
    defaultGlobalMap["nav_south_settings_offThresh"] = 5;
    defaultGlobalMap["nav_east_settings_onThresh"] = 10;
    defaultGlobalMap["nav_east_settings_offThresh"] = 5;
    defaultGlobalMap["nav_west_settings_onThresh"] = 10;
    defaultGlobalMap["nav_west_settings_offThresh"] = 5;
    defaultGlobalMap["nav_settings_yaccel"] = 0;
}

void PresetInterface::slotRecallPreset(int i)
{
    i -= 1;
    qDebug() << "recall preset" << i;

    currentPresetNum = i;

    QMapIterator<QString, QVariant> p(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());

    while(p.hasNext())
    {
        p.next();
    }
    emit signalRecallPreset(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap(), jsonMasterMapCopy);

    slotCheckSaveState();

}

void PresetInterface::slotRecallGlobal()
{
    emit signalRecallGlobal(jsonMasterMapCopy.value(QString("Global")).toMap(),jsonMasterMapCopy);

    //slotCheckSaveState();
}

void PresetInterface::slotUpdateClicked()
{
    //Store copy of current preset into master json
    jsonMasterMap.insert(QString("Preset_00%1").arg(currentPresetNum), jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());

    //store globals goes here
    jsonMasterMap.insert(QString("Global"), jsonMasterMapCopy.value(QString("Global")).toMap());


    qDebug() << "update with this preset" << currentPresetNum;
    //emit signalUpdateStarted(); //disable the button then start the download
    //emit signalAttributeFormatPreset(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap(), jsonMasterMap, (qlonglong)currentPresetNum);

    //slotCheckSaveState();

    slotWriteJSON(jsonMasterMap);
}

void PresetInterface::closeEvent(QCloseEvent *)
{
    //qDebug() << "closing...";
}
