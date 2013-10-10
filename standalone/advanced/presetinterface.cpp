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
    if(mode == "hosted")
    {
        jsonPath.append("Resources/presets/hosted_softstepezpz.json");
    }
    else
    {
        jsonPath.append("Resources/presets/softstepezpz.json");
    }

#else
    if(mode == "hosted")
    {
        jsonPath = QString("./presets/softstepadvanced.json");
    }
    else
    {
        jsonPath = QString("./presets/softstepadvanced.json");
    }

#endif

    slotReadJSON();

    //writeDefualtJSON();
}

void PresetInterface::slotPopulatePresetMenu(QComboBox* presetMenu)
{
    disconnect(presetMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(slotRecallPreset(int)));

    presetMenu->clear();

    //All presets should be stored and arranged in JSON before calling this function!
    presetListCopy.clear();
    presetListMaster.clear();


    int numPresets = slotGetNumPresetsInJson();

    //Iterate through presets in numerical order, which is not garunteed by map iterator
    for(int i = 0; i < numPresets; i++)
    {
        QString presetName;

        presetName = jsonMasterMapCopy.value(slotGetPresetStringFromInt(i)).toMap().value("preset_name").toString();

        //Populate preset QList in numerical order, for easy modifaction
        presetListCopy.append(jsonMasterMapCopy.value(slotGetPresetStringFromInt(i)).toMap());
        presetListMaster.append(jsonMasterMap.value(slotGetPresetStringFromInt(i)).toMap());

        presetMenu->addItem(presetName, 0);
    }

    connect(presetMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(slotRecallPreset(int)));

    emit signalPopulateSetlistMenus(presetMenu);
}

void PresetInterface::slotPopulateSetlistMenus()
{
    //emit signalPopulateSetlistMenus(jsonMasterMapCopy);
}

QString PresetInterface::slotGetPresetStringFromInt(int i)
{
    if(i < 10)
    {
        return QString("Preset_00%1").arg(i);
    }
    else if(i < 100)
    {
        return QString("Preset_0%1").arg(i);
    }
    else if(i < 1000)
    {
        return QString("Preset_%1").arg(i);
    }

    return QString();
}

void PresetInterface::slotSetMode(QString m)
{
    mode = m;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////   JSON   ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

        QStringList keyList = jsonMasterMapCopy.value(slotGetPresetStringFromInt(presetNum)).toMap().keys();

        for(int i = 0; i < keyList.size(); i++)
        {
            if(jsonMasterMapCopy.value(slotGetPresetStringFromInt(presetNum)).toMap().value(keyList.at(i)) !=
                    jsonMasterMap.value(slotGetPresetStringFromInt(presetNum)).toMap().value(keyList.at(i)))
            {
                qDebug() << "------------" << keyList.at(i) << jsonMasterMapCopy.value(slotGetPresetStringFromInt(presetNum)).toMap().value(keyList.at(i)) << jsonMasterMap.value(slotGetPresetStringFromInt(presetNum)).toMap().value(keyList.at(i));
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
    for(int i = 0; i < 10; i++)
    {
        jsonMasterMap.insert(slotGetPresetStringFromInt(i),defaultPresetMap);
    }

    jsonMasterMap.insert(QString("Global"),defaultGlobalMap);

    slotWriteJSON(jsonMasterMap);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////   Storage / Recall  ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PresetInterface::slotRecallPreset(int i)
{
    //i -= 1;
    qDebug() << "recall preset" << i;

    currentPresetNum = i;

    emit signalRecallPreset(jsonMasterMapCopy.value(slotGetPresetStringFromInt(currentPresetNum)).toMap(), jsonMasterMapCopy);

    slotCheckSaveState();

}

void PresetInterface::slotRecallGlobal()
{
    emit signalRecallGlobal(jsonMasterMapCopy.value(QString("Global")).toMap(),jsonMasterMapCopy);
}

void PresetInterface::slotStoreValue(QString name, QVariant value, int presetNum)
{
    //qDebug() << "name" << name << "value" << value << "preset" << presetNum;

    if(presetNum == -1)
    {
        presetNum = currentPresetNum;
    }

    QVariantMap presetMap = jsonMasterMapCopy.value(slotGetPresetStringFromInt(presetNum)).toMap();
    presetMap.insert(name, value);
    jsonMasterMapCopy.insert(slotGetPresetStringFromInt(presetNum), presetMap);

    //slotCheckSaveState();
}

void PresetInterface::slotStoreGlobal(QString name, QVariant value)
{
    QVariantMap globalMap = jsonMasterMapCopy.value(QString("Global")).toMap();
    globalMap.insert(name, value);
    jsonMasterMapCopy.insert(QString("Global"), globalMap);

    //------------------------------------store the settings globals in master preset here----------------------------------------
    //this happens every time a parameter is modified  - it slows down the app's open time since each parameter is recalled and writes to the master copy individually
    jsonMasterMap.insert(QString("Global"), jsonMasterMapCopy.value(QString("Global")).toMap());
    qDebug() << "update the settings preset";
    slotWriteJSON(jsonMasterMap);
}

void PresetInterface::slotCheckSaveState()
{
    QStringList keyList = jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().keys();

    bool dirty = false;

    for(int i = 0; i < keyList.size(); i++)
    {
        if(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)) !=
                jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)))
        {
            //qDebug() << "--------------" << keyList.at(i) << jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)) << jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i));
            dirty = true;
        }
    }

    emit signalPresetDirty(dirty);

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////   Save, SaveAs, Revert, Delete  /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PresetInterface::slotSavePreset()
{
    //Store copy of current preset into master json
    jsonMasterMap.insert(slotGetPresetStringFromInt(currentPresetNum), jsonMasterMapCopy.value(slotGetPresetStringFromInt(currentPresetNum)).toMap());

    qDebug() << "update with this preset" << currentPresetNum;
    //emit signalUpdateStarted(); //disable the button then start the download
    //emit signalAttributeFormatPreset(jsonMasterMap.value(slotGetPresetStringFromInt(currentPresetNum)).toMap(), jsonMasterMap, (qlonglong)currentPresetNum);

    slotCheckSaveState();

    slotWriteJSON(jsonMasterMap);
}

void PresetInterface::slotSavePresetAs(QString presetName)
{
    qDebug() << "Save As: " << presetName << slotGetNumPresetsInJson();

    //Get preset params into map
    QVariantMap preset = presetListCopy.at(currentPresetNum);

    //Insert preset name param
    preset.insert("preset_name", presetName);

    //Add to active prest lists
    presetListCopy.append(preset);
    presetListMaster.append(preset);

    //Add and order json maps
    slotOrderPresetsInJson();

    //Save json file
    slotWriteJSON(jsonMasterMap);

    //Repopulate preset menu-- calls slotPopulatePresetMenu()
    emit signalAddRemovePreset();
}

void PresetInterface::slotRevertPreset()
{
    if(currentPresetNum != -1)
    {
        //Load preset from master map into the copy
        jsonMasterMapCopy.insert(slotGetPresetStringFromInt(currentPresetNum), jsonMasterMap.value(slotGetPresetStringFromInt(currentPresetNum)).toMap());
        qDebug() << "preset should revert now";
        slotRecallPreset(currentPresetNum);
    }
    else
    {
        qDebug() << "preset will not revert";
    }
}

void PresetInterface::slotDeletePreset()
{
    //Remove preset from active preset lists
    presetListMaster.removeAt(currentPresetNum);
    presetListCopy.removeAt(currentPresetNum);

    if((presetListMaster.size() - 1) < currentPresetNum)
    {
        currentPresetNum = presetListMaster.size() - 1;
    }

    //Re-iterate through active lists and set properly index in json
    slotOrderPresetsInJson();

    //Save json file
    slotWriteJSON(jsonMasterMap);

    //Repopulate preset menu-- calls slotPopulatePresetMenu()
    emit signalAddRemovePreset();
}

void PresetInterface::slotOrderPresetsInJson()
{
    //This function is used to ensure presets are kept ordered (without skpping numbers) in json

    //Get number of presets in json
    int numPresets = slotGetNumPresetsInJson();

    //Remove all presets from json (keep globals)
    for(int i = 0; i < numPresets; i++)
    {
        jsonMasterMapCopy.remove(slotGetPresetStringFromInt(i));
        jsonMasterMap.remove(slotGetPresetStringFromInt(i));
    }

    //Re-insert presets in correct order with new indexes (just use size of copy here, the number should be the same in both preset lists)
    for(int i = 0; i < presetListCopy.size(); i++)
    {
        jsonMasterMapCopy.insert(slotGetPresetStringFromInt(i), presetListCopy.at(i));
        jsonMasterMap.insert(slotGetPresetStringFromInt(i), presetListMaster.at(i));
    }
}

int PresetInterface::slotGetNumPresetsInJson()
{
    int numPresets = 0;

    //Iterate through master map, gets num presets
    QMapIterator<QString, QVariant> map(jsonMasterMapCopy);

    while(map.hasNext())
    {
        map.next();

        //If a preset within master map...
        if(map.key().contains("Preset"))
        {
            //Inc preset count
            numPresets++;
        }
    }

    return numPresets;
}

void PresetInterface::closeEvent(QCloseEvent *)
{
    //qDebug() << "closing...";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////   Default Maps  ///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PresetInterface::slotConstructDefaultMap()
{

    defaultPresetMap["preset_name"] = "Default Preset";
    defaultPresetMap["preset_displayname"] = "DFLT";

    //------------------------ Key 1 ------------------------//
    defaultPresetMap["1_key_name"] = "1KEY";
    defaultPresetMap["1_key_displaymode"] = 1;
    defaultPresetMap["1_key_prefix"] = "";
    defaultPresetMap["1_key_counter_min"] = 0;
    defaultPresetMap["1_key_counter_max"] = 127;
    defaultPresetMap["1_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key1_modline1_enable"] = 0;
    defaultPresetMap["key1_modline1_initvalue"] = 0;
    defaultPresetMap["key1_modline1_initmode"] = "None";
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
    defaultPresetMap["key1_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key1_modline2_initvalue"] = 0;
    defaultPresetMap["key1_modline2_initmode"] = "None";
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
    defaultPresetMap["key1_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key1_modline3_initvalue"] = 0;
    defaultPresetMap["key1_modline3_initmode"] = "None";
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
    defaultPresetMap["key1_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key1_modline4_initvalue"] = 0;
    defaultPresetMap["key1_modline4_initmode"] = "None";
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
    defaultPresetMap["key1_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key1_modline5_initvalue"] = 0;
    defaultPresetMap["key1_modline5_initmode"] = "None";
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
    defaultPresetMap["key1_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key1_modline6_initvalue"] = 0;
    defaultPresetMap["key1_modline6_initmode"] = "None";
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
    defaultPresetMap["key1_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key2_modline1_initvalue"] = 0;
    defaultPresetMap["key2_modline1_initmode"] = "None";
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
    defaultPresetMap["key2_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key2_modline2_initvalue"] = 0;
    defaultPresetMap["key2_modline2_initmode"] = "None";
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
    defaultPresetMap["key2_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key2_modline3_initvalue"] = 0;
    defaultPresetMap["key2_modline3_initmode"] = "None";
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
    defaultPresetMap["key2_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key2_modline4_initvalue"] = 0;
    defaultPresetMap["key2_modline4_initmode"] = "None";
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
    defaultPresetMap["key2_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key2_modline5_initvalue"] = 0;
    defaultPresetMap["key2_modline5_initmode"] = "None";
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
    defaultPresetMap["key2_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key2_modline6_initvalue"] = 0;
    defaultPresetMap["key2_modline6_initmode"] = "None";
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
    defaultPresetMap["key2_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key3_modline1_initvalue"] = 0;
    defaultPresetMap["key3_modline1_initmode"] = "None";
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
    defaultPresetMap["key3_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key3_modline2_initvalue"] = 0;
    defaultPresetMap["key3_modline2_initmode"] = "None";
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
    defaultPresetMap["key3_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key3_modline3_initvalue"] = 0;
    defaultPresetMap["key3_modline3_initmode"] = "None";
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
    defaultPresetMap["key3_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key3_modline4_initvalue"] = 0;
    defaultPresetMap["key3_modline4_initmode"] = "None";
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
    defaultPresetMap["key3_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key3_modline5_initvalue"] = 0;
    defaultPresetMap["key3_modline5_initmode"] = "None";
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
    defaultPresetMap["key3_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key3_modline6_initvalue"] = 0;
    defaultPresetMap["key3_modline6_initmode"] = "None";
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
    defaultPresetMap["key3_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key4_modline1_initvalue"] = 0;
    defaultPresetMap["key4_modline1_initmode"] = "None";
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
    defaultPresetMap["key4_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key4_modline2_initvalue"] = 0;
    defaultPresetMap["key4_modline2_initmode"] = "None";
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
    defaultPresetMap["key4_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key4_modline3_initvalue"] = 0;
    defaultPresetMap["key4_modline3_initmode"] = "None";
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
    defaultPresetMap["key4_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key4_modline4_initvalue"] = 0;
    defaultPresetMap["key4_modline4_initmode"] = "None";
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
    defaultPresetMap["key4_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key4_modline5_initvalue"] = 0;
    defaultPresetMap["key4_modline5_initmode"] = "None";
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
    defaultPresetMap["key4_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key4_modline6_initvalue"] = 0;
    defaultPresetMap["key4_modline6_initmode"] = "None";
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
    defaultPresetMap["key4_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key5_modline1_initvalue"] = 0;
    defaultPresetMap["key5_modline1_initmode"] = "None";
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
    defaultPresetMap["key5_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key5_modline2_initvalue"] = 0;
    defaultPresetMap["key5_modline2_initmode"] = "None";
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
    defaultPresetMap["key5_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key5_modline3_initvalue"] = 0;
    defaultPresetMap["key5_modline3_initmode"] = "None";
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
    defaultPresetMap["key5_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key5_modline4_initvalue"] = 0;
    defaultPresetMap["key5_modline4_initmode"] = "None";
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
    defaultPresetMap["key5_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key5_modline5_initvalue"] = 0;
    defaultPresetMap["key5_modline5_initmode"] = "None";
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
    defaultPresetMap["key5_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key5_modline6_initvalue"] = 0;
    defaultPresetMap["key5_modline6_initmode"] = "None";
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
    defaultPresetMap["key5_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key6_modline1_initvalue"] = 0;
    defaultPresetMap["key6_modline1_initmode"] = "None";
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
    defaultPresetMap["key6_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key6_modline2_initvalue"] = 0;
    defaultPresetMap["key6_modline2_initmode"] = "None";
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
    defaultPresetMap["key6_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key6_modline3_initvalue"] = 0;
    defaultPresetMap["key6_modline3_initmode"] = "None";
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
    defaultPresetMap["key6_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key6_modline4_initvalue"] = 0;
    defaultPresetMap["key6_modline4_initmode"] = "None";
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
    defaultPresetMap["key6_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key6_modline5_initvalue"] = 0;
    defaultPresetMap["key6_modline5_initmode"] = "None";
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
    defaultPresetMap["key6_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key6_modline6_initvalue"] = 0;
    defaultPresetMap["key6_modline6_initmode"] = "None";
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
    defaultPresetMap["key6_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key7_modline1_initvalue"] = 0;
    defaultPresetMap["key7_modline1_initmode"] = "None";
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
    defaultPresetMap["key7_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key7_modline2_initvalue"] = 0;
    defaultPresetMap["key7_modline2_initmode"] = "None";
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
    defaultPresetMap["key7_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key7_modline3_initvalue"] = 0;
    defaultPresetMap["key7_modline3_initmode"] = "None";
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
    defaultPresetMap["key7_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key7_modline4_initvalue"] = 0;
    defaultPresetMap["key7_modline4_initmode"] = "None";
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
    defaultPresetMap["key7_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key7_modline5_initvalue"] = 0;
    defaultPresetMap["key7_modline5_initmode"] = "None";
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
    defaultPresetMap["key7_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key7_modline6_initvalue"] = 0;
    defaultPresetMap["key7_modline6_initmode"] = "None";
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
    defaultPresetMap["key7_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key8_modline1_initvalue"] = 0;
    defaultPresetMap["key8_modline1_initmode"] = "None";
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
    defaultPresetMap["key8_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key8_modline2_initvalue"] = 0;
    defaultPresetMap["key8_modline2_initmode"] = "None";
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
    defaultPresetMap["key8_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key8_modline3_initvalue"] = 0;
    defaultPresetMap["key8_modline3_initmode"] = "None";
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
    defaultPresetMap["key8_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key8_modline4_initvalue"] = 0;
    defaultPresetMap["key8_modline4_initmode"] = "None";
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
    defaultPresetMap["key8_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key8_modline5_initvalue"] = 0;
    defaultPresetMap["key8_modline5_initmode"] = "None";
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
    defaultPresetMap["key8_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key8_modline6_initvalue"] = 0;
    defaultPresetMap["key8_modline6_initmode"] = "None";
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
    defaultPresetMap["key8_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key9_modline1_initvalue"] = 0;
    defaultPresetMap["key9_modline1_initmode"] = "None";
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
    defaultPresetMap["key9_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key9_modline2_initvalue"] = 0;
    defaultPresetMap["key9_modline2_initmode"] = "None";
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
    defaultPresetMap["key9_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key9_modline3_initvalue"] = 0;
    defaultPresetMap["key9_modline3_initmode"] = "None";
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
    defaultPresetMap["key9_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key9_modline4_initvalue"] = 0;
    defaultPresetMap["key9_modline4_initmode"] = "None";
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
    defaultPresetMap["key9_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key9_modline5_initvalue"] = 0;
    defaultPresetMap["key9_modline5_initmode"] = "None";
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
    defaultPresetMap["key9_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key9_modline6_initvalue"] = 0;
    defaultPresetMap["key9_modline6_initmode"] = "None";
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
    defaultPresetMap["key9_modline6_bankmsb"] = 0;
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
    defaultPresetMap["key10_modline1_initvalue"] = 0;
    defaultPresetMap["key10_modline1_initmode"] = "None";
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
    defaultPresetMap["key10_modline1_bankmsb"] = 0;
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
    defaultPresetMap["key10_modline2_initvalue"] = 0;
    defaultPresetMap["key10_modline2_initmode"] = "None";
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
    defaultPresetMap["key10_modline2_bankmsb"] = 0;
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
    defaultPresetMap["key10_modline3_initvalue"] = 0;
    defaultPresetMap["key10_modline3_initmode"] = "None";
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
    defaultPresetMap["key10_modline3_bankmsb"] = 0;
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
    defaultPresetMap["key10_modline4_initvalue"] = 0;
    defaultPresetMap["key10_modline4_initmode"] = "None";
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
    defaultPresetMap["key10_modline4_bankmsb"] = 0;
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
    defaultPresetMap["key10_modline5_initvalue"] = 0;
    defaultPresetMap["key10_modline5_initmode"] = "None";
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
    defaultPresetMap["key10_modline5_bankmsb"] = 0;
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
    defaultPresetMap["key10_modline6_initvalue"] = 0;
    defaultPresetMap["key10_modline6_initmode"] = "None";
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
    defaultPresetMap["key10_modline6_bankmsb"] = 0;
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
    //------------------ Global Page -------------------//
    defaultGlobalMap["sensorresponse_average"] = 1;
    defaultGlobalMap["sensorresponse_max"] = 0;
    defaultGlobalMap["adjacentkeymode"] = 0;
    defaultGlobalMap["keylockoutmode"] = 0;
    defaultGlobalMap["multiplekeymode"] = 1;

    defaultGlobalMap["global_gain"] = 1.00;
    defaultGlobalMap["backlighting_enable"] = 1;

    //-------------------- Key Page --------------------//
    defaultGlobalMap["key1_settings_xdead"] = 0;
    defaultGlobalMap["key1_settings_ydead"] = 0;
    defaultGlobalMap["key1_settings_xaccel"] = 0;
    defaultGlobalMap["key1_settings_ydead"] = 0;
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

    defaultGlobalMap["nav_north_settings_onthresh"] = 10;
    defaultGlobalMap["nav_north_settings_offthresh"] = 5;
    defaultGlobalMap["nav_south_settings_onthresh"] = 10;
    defaultGlobalMap["nav_south_settings_offthresh"] = 5;
    defaultGlobalMap["nav_east_settings_onthresh"] = 10;
    defaultGlobalMap["nav_east_settings_offthresh"] = 5;
    defaultGlobalMap["nav_west_settings_onthresh"] = 10;
    defaultGlobalMap["nav_west_settings_offthresh"] = 5;
    defaultGlobalMap["nav_settings_yaccel"] = 0;

    //---------------------- Input Page ---------------------//
    defaultGlobalMap["midia_settings_enable"] = 0;
    defaultGlobalMap["midia_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midia_settings_channel"] = 1;
    defaultGlobalMap["midia_settings_messagetype"] = "Note";
    defaultGlobalMap["midia_settings_number"] = 60;

    defaultGlobalMap["midib_settings_enable"] = 0;
    defaultGlobalMap["midib_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midib_settings_channel"] = 1;
    defaultGlobalMap["midib_settings_messagetype"] = "Note";
    defaultGlobalMap["midib_settings_number"] = 60;

    defaultGlobalMap["midic_settings_enable"] = 0;
    defaultGlobalMap["midic_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midic_settings_channel"] = 1;
    defaultGlobalMap["midic_settings_messagetype"] = "Note";
    defaultGlobalMap["midic_settings_number"] = 60;

    defaultGlobalMap["midid_settings_enable"] = 0;
    defaultGlobalMap["midid_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midid_settings_channel"] = 1;
    defaultGlobalMap["midid_settings_messagetype"] = "Note";
    defaultGlobalMap["midid_settings_number"] = 60;

    defaultGlobalMap["midie_settings_enable"] = 0;
    defaultGlobalMap["midie_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midie_settings_channel"] = 1;
    defaultGlobalMap["midie_settings_messagetype"] = "Note";
    defaultGlobalMap["midie_settings_number"] = 60;

    defaultGlobalMap["midif_settings_enable"] = 0;
    defaultGlobalMap["midif_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midif_settings_channel"] = 1;
    defaultGlobalMap["midif_settings_messagetype"] = "Note";
    defaultGlobalMap["midif_settings_number"] = 60;

    defaultGlobalMap["midig_settings_enable"] = 0;
    defaultGlobalMap["midig_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midig_settings_channel"] = 1;
    defaultGlobalMap["midig_settings_messagetype"] = "Note";
    defaultGlobalMap["midig_settings_number"] = 60;

    defaultGlobalMap["midih_settings_enable"] = 0;
    defaultGlobalMap["midih_settings_device"] = "IAC Driver Bus";
    defaultGlobalMap["midih_settings_channel"] = 1;
    defaultGlobalMap["midih_settings_messagetype"] = "Note";
    defaultGlobalMap["midih_settings_number"] = 60;

    defaultGlobalMap["osca_input_enable"] = 0;
    defaultGlobalMap["osca_input_route"] = "";
    defaultGlobalMap["oscb_input_enable"] = 0;
    defaultGlobalMap["oscb_input_route"] = "";
    defaultGlobalMap["oscc_input_enable"] = 0;
    defaultGlobalMap["oscc_input_route"] = "";
    defaultGlobalMap["oscd_input_enable"] = 0;
    defaultGlobalMap["oscd_input_route"] = "";
    defaultGlobalMap["osce_input_enable"] = 0;
    defaultGlobalMap["osce_input_route"] = "";
    defaultGlobalMap["oscf_input_enable"] = 0;
    defaultGlobalMap["oscf_input_route"] = "";
    defaultGlobalMap["oscg_input_enable"] = 0;
    defaultGlobalMap["oscg_input_route"] = "";
    defaultGlobalMap["osch_input_enable"] = 0;
    defaultGlobalMap["osch_input_route"] = "";

    defaultGlobalMap["osc_ip_1"] = 0;
    defaultGlobalMap["osc_ip_2"] = 0;
    defaultGlobalMap["osc_ip_3"] = 0;
    defaultGlobalMap["osc_ip_4"] = 0;
    defaultGlobalMap["osc_out_port"] = 0;
    defaultGlobalMap["osc_in_port"] = 0;
}
