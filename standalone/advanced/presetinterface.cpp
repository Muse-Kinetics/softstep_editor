// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "presetinterface.h"

PresetInterface::PresetInterface(QWidget *parent) :
    QWidget(parent)
{
    settings = new QSettings(this);

    //writeDefualtJSON();
}

void PresetInterface::slotUpdateJSONPath()
{
    jsonPath = QCoreApplication::applicationDirPath(); //get bundle path

#if defined(Q_OS_MAC) && !defined(QT_DEBUG)
    jsonPath.remove(jsonPath.length() - 5, jsonPath.length()); //Remove "MacOS" from path string
    if(mode == "hosted")
    {
        jsonPath.append("Resources/presets/hosted_softstepadvanced.json");
    }
    else
    {
        jsonPath.append("Resources/presets/softstepadvanced.json");
    }

#else
    if(mode == "hosted")
    {
        jsonPath = QString("./presets/hosted_softstepadvanced.json");
    }
    else
    {
        jsonPath = QString("./presets/softstepadvanced.json");
    }

#endif
}

void PresetInterface::slotPopulatePresetMenu(QComboBox* presetMenu)
{
    disconnect(presetMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(slotRecallPreset(int)));

    //All presets should be stored and arranged in JSON before calling this function!
    slotPopulatePresetLists();

    presetMenu->clear();

    int numPresets = slotGetNumPresetsInJson();

    //Iterate through presets in numerical order, which is not garunteed by map iterator
    for(int i = 0; i < numPresets; i++)
    {
        QString presetName = jsonMasterMapCopy.value(slotGetPresetStringFromInt(i)).toMap().value("preset_name").toString();

        presetMenu->addItem(presetName, 0);
    }

    connect(presetMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(slotRecallPreset(int)));

    //emit signalInitStateRecallers();

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
        //qDebug("SoftStep Advanced Editor JSON Found");

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
        qDebug() << "WARNNG: SoftStep Advanced Editor JSON Not Found";
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
        qDebug() << "SoftStep Advanced Editor JSON Not Found";
    }

    jsonFile->close();
}

void PresetInterface::writeDefualtJSON()
{

    for(int i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            slotConstructDefaultStandaloneMap();

            jsonPath = QString("./presets/softstepadvanced.json");
        }
        else if(i == 1)
        {
            slotConstructDefaultHostedMap();

            jsonPath = QString("./presets/hosted_softstepadvanced.json");
        }

        //generate fresh default json needed
        for(int j = 0; j < 10; j++)
        {
            jsonMasterMap.insert(slotGetPresetStringFromInt(j),defaultPresetMap);
        }

        //Load json into QFile
        QFile *jsonFile = new QFile(jsonPath);

        if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            //Serialize JSON, write to file
            QByteArray ba = serializer.serialize(jsonMasterMap); //serialize the master json map into the byte array

            jsonFile->resize(0);
            jsonFile->write(ba);
        }
        else
        {
            qDebug() << QString("SoftStep Advanced Editor JSON Not Found: %1").arg(jsonPath);
        }

        jsonFile->close();
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////   Storage / Recall  ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PresetInterface::slotRecallPreset(int i)
{
    //i -= 1;
    //qDebug() << "recall preset" << i;

    currentPresetNum = i;

    emit signalRecallPreset(jsonMasterMapCopy.value(slotGetPresetStringFromInt(currentPresetNum)).toMap(), jsonMasterMapCopy);

    slotCheckSaveState();

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

void PresetInterface::slotCheckSaveState()
{
    QStringList keyList = jsonMasterMapCopy.value(slotGetPresetStringFromInt(currentPresetNum)).toMap().keys();

    bool dirty = false;

    for(int i = 0; i < keyList.size(); i++)
    {
        if(jsonMasterMapCopy.value(slotGetPresetStringFromInt(currentPresetNum)).toMap().value(keyList.at(i)) !=
                jsonMasterMap.value(slotGetPresetStringFromInt(currentPresetNum)).toMap().value(keyList.at(i)))
        {
            //qDebug() << "--------------" << keyList.at(i) << jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)) << jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i));
            dirty = true;
        }
    }

    emit signalPresetDirty(dirty);
    //qDebug() << "check nav pad save state";

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

    //call function to repopulate preset lists
    slotPopulatePresetLists();
}

void PresetInterface::slotSavePresetAs(QString presetName)
{
    qDebug() << "Save As: " << presetName << slotGetNumPresetsInJson();

    //copy json maps into the preset lists
    slotPopulatePresetLists();

    //Get preset params into map
    QVariantMap preset = presetListCopy.at(currentPresetNum);

    //Insert preset name param
    preset.insert("preset_name", presetName);

    //Add to active prest lists
    presetListCopy.append(preset);
    presetListMaster.append(preset);

    //Add and order json maps
    slotOrderPresetsInJson();

    slotRevertPreset();

    //Save json file
    slotWriteJSON(jsonMasterMap);

    //Repopulate preset menu-- calls slotPopulatePresetMenu()
    emit signalAddRemovePreset();

    int goToPresetNum = slotGetNumPresetsInJson();

    emit signalPresetMenu(goToPresetNum-1);
}

void PresetInterface::slotRevertPreset()
{
    if(currentPresetNum != -1)
    {
        //Load preset from master map into the copy
        jsonMasterMapCopy.insert(slotGetPresetStringFromInt(currentPresetNum), jsonMasterMap.value(slotGetPresetStringFromInt(currentPresetNum)).toMap());
        //qDebug() << "preset should revert now";
        slotRecallPreset(currentPresetNum);
    }
    else
    {
        //qDebug() << "preset will not revert";
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
    emit signalPresetMenu(0);
}

void PresetInterface::slotPopulatePresetLists()
{
    //All presets should be stored and arranged in the JSON before calling this function
    presetListCopy.clear();
    presetListMaster.clear();

    int numPresets = slotGetNumPresetsInJson();

    for(int i = 0; i < numPresets; i++)
    {
        presetListCopy.append(jsonMasterMapCopy.value(slotGetPresetStringFromInt(i)).toMap());
        presetListMaster.append(jsonMasterMap.value(slotGetPresetStringFromInt(i)).toMap());
    }
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////   Importing and Exporting Presets  /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PresetInterface::slotImportPreset()
{
    //QString sender = QObject::sender()->objectName();
    QString filename = NULL;

    filename = QFileDialog::getOpenFileName(this, tr("Import Preset"), QString("./"), tr("SoftStep Preset Files (*.softsteppreset)"));

    //If file is selected
    if(filename != NULL)
    {
        //open file
        QFile* presetFile = new QFile(filename);
        presetFile->open(QIODevice::ReadOnly);

        QByteArray presetByteArray = presetFile->readAll();
        presetFile->close();

        QVariantMap importedPresetMap = parser.parse(presetByteArray, &ok).toMap();


        //------------- Check for MISSING Parameters in the Imported Preset ----------------
        if(mode == "hosted")
        {
            slotConstructDefaultHostedMap();
        }
        else if(mode == "standalone")
        {
            slotConstructDefaultStandaloneMap();
        }

        QMapIterator<QString, QVariant> i(defaultPresetMap);

        //Iterate through default map and compare with imported preset
        while(i.hasNext())
        {
            i.next();

            if(!importedPresetMap.contains(i.key()))
            {
                //if imported preset map does not contain a value in the default map, insert it
                importedPresetMap.insert(i.key(), i.value());
                qDebug() << "From slotImportPreset - This was MISSING:" << i.key() << i.value();
            }
        }
        //------------ Check for EXTRA parameters in the Imported Preset -------------------
        QMapIterator<QString, QVariant> j(importedPresetMap);

        QStringList badKeys;  //stores keys we need to remove from the map

        while(j.hasNext())
        {
            j.next();

            //If the default map does not contain something in the preset
            if(!defaultPresetMap.contains(j.key()))
            {
                //add to list of bad keys
                badKeys.append(j.key());
                qDebug() << "From slotImportPreset - This was EXTRA:" << j.key() << j.value();
            }
        }
        //Iterate through the bad keys and remove from preset
        for(int i = 0; i<badKeys.count(); i++)
        {
            importedPresetMap.remove(badKeys.at(i));
        }

        //----------- Set Imported Preset to New preset and Update ----------
        presetListCopy.clear();
        presetListMaster.clear();

        int numPresets = slotGetNumPresetsInJson();

        for(int i = 0; i < numPresets; i++)
        {
            presetListCopy.append(jsonMasterMapCopy.value(slotGetPresetStringFromInt(i)).toMap());
            presetListMaster.append(jsonMasterMapCopy.value(slotGetPresetStringFromInt(i)).toMap());
        }
        presetListCopy.append(importedPresetMap);
        presetListMaster.append(importedPresetMap);

        slotOrderPresetsInJson();
        slotWriteJSON(jsonMasterMap);
        emit signalAddRemovePreset();
        emit signalPresetMenu(numPresets);
    }
    else
    {
        qDebug("nothing selected");
    }
}

void PresetInterface::slotExportPreset()
{
    QVariantMap exportedPresetMap = jsonMasterMapCopy.value(slotGetPresetStringFromInt(currentPresetNum)).toMap();

    //set path and filename (default filename is the preset name
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Preset"), QString("./%1").arg(exportedPresetMap.value("preset_name").toString()), tr("SoftStep Preset Files (*.softsteppreset)"));

    //This gets the file name without the path
    QFileInfo fileInfo(filename);

    //open new file to be saved
    QFile* presetFile = new QFile(filename);

    //remove extension from filename
    QString exportedPresetName = fileInfo.fileName().remove(".softsteppreset");

    qDebug() << QString("filename: %1").arg(exportedPresetName);

    //replace "preset_name" with filename typed in dialog
    exportedPresetMap.insert("preset_name", exportedPresetName);

    //------------------ Open, Write, and Close
    presetFile->open(QIODevice::WriteOnly);

    QByteArray presetByteArray = serializer.serialize(exportedPresetMap);

    presetFile->resize(0);
    presetFile->write(presetByteArray);
    presetFile->close();

    presetByteArray.clear();
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
void PresetInterface::slotConstructDefaultHostedMap()
{
    defaultPresetMap["preset_name"] = "Default Preset";
    defaultPresetMap["preset_displayname"] = "DFLT";

    //------------------------ Key 1 ------------------------//
    defaultPresetMap["1_key_name"] = "1KEY";
    defaultPresetMap["1_key_displaymode"] = "None";
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
    defaultPresetMap["key1_modline1_table"] = "Linear";
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
    defaultPresetMap["key1_modline1_ledgreen"] = "None";
    defaultPresetMap["key1_modline1_ledred"] = "None";
    defaultPresetMap["key1_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key1_modline2_enable"] = 0;
    defaultPresetMap["key1_modline2_initvalue"] = 0;
    defaultPresetMap["key1_modline2_initmode"] = "None";
    defaultPresetMap["key1_modline2_source"] = "None";
    defaultPresetMap["key1_modline2_gain"] = 1.00;
    defaultPresetMap["key1_modline2_offset"] = 0;
    defaultPresetMap["key1_modline2_table"] = "Linear";
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
    defaultPresetMap["key1_modline2_ledgreen"] = "None";
    defaultPresetMap["key1_modline2_ledred"] = "None";
    defaultPresetMap["key1_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key1_modline3_enable"] = 0;
    defaultPresetMap["key1_modline3_initvalue"] = 0;
    defaultPresetMap["key1_modline3_initmode"] = "None";
    defaultPresetMap["key1_modline3_source"] = "None";
    defaultPresetMap["key1_modline3_gain"] = 1.00;
    defaultPresetMap["key1_modline3_offset"] = 0;
    defaultPresetMap["key1_modline3_table"] = "Linear";
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
    defaultPresetMap["key1_modline3_ledgreen"] = "None";
    defaultPresetMap["key1_modline3_ledred"] = "None";
    defaultPresetMap["key1_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key1_modline4_enable"] = 0;
    defaultPresetMap["key1_modline4_initvalue"] = 0;
    defaultPresetMap["key1_modline4_initmode"] = "None";
    defaultPresetMap["key1_modline4_source"] = "None";
    defaultPresetMap["key1_modline4_gain"] = 1.00;
    defaultPresetMap["key1_modline4_offset"] = 0;
    defaultPresetMap["key1_modline4_table"] = "Linear";
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
    defaultPresetMap["key1_modline4_ledgreen"] = "None";
    defaultPresetMap["key1_modline4_ledred"] = "None";
    defaultPresetMap["key1_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key1_modline5_enable"] = 0;
    defaultPresetMap["key1_modline5_initvalue"] = 0;
    defaultPresetMap["key1_modline5_initmode"] = "None";
    defaultPresetMap["key1_modline5_source"] = "None";
    defaultPresetMap["key1_modline5_gain"] = 1.00;
    defaultPresetMap["key1_modline5_offset"] = 0;
    defaultPresetMap["key1_modline5_table"] = "Linear";
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
    defaultPresetMap["key1_modline5_ledgreen"] = "None";
    defaultPresetMap["key1_modline5_ledred"] = "None";
    defaultPresetMap["key1_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key1_modline6_enable"] = 0;
    defaultPresetMap["key1_modline6_initvalue"] = 0;
    defaultPresetMap["key1_modline6_initmode"] = "None";
    defaultPresetMap["key1_modline6_source"] = "None";
    defaultPresetMap["key1_modline6_gain"] = 1.00;
    defaultPresetMap["key1_modline6_offset"] = 0;
    defaultPresetMap["key1_modline6_table"] = "Linear";
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
    defaultPresetMap["key1_modline6_ledgreen"] = "None";
    defaultPresetMap["key1_modline6_ledred"] = "None";
    defaultPresetMap["key1_modline6_displaylinked"] = 0;


    //------------------------ Key 2 ------------------------//
    defaultPresetMap["2_key_name"] = "2KEY";
    defaultPresetMap["2_key_displaymode"] = "None";
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
    defaultPresetMap["key2_modline1_table"] = "Linear";
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
    defaultPresetMap["key2_modline1_ledgreen"] = "None";
    defaultPresetMap["key2_modline1_ledred"] = "None";
    defaultPresetMap["key2_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key2_modline2_enable"] = 0;
    defaultPresetMap["key2_modline2_initvalue"] = 0;
    defaultPresetMap["key2_modline2_initmode"] = "None";
    defaultPresetMap["key2_modline2_source"] = "None";
    defaultPresetMap["key2_modline2_gain"] = 1.00;
    defaultPresetMap["key2_modline2_offset"] = 0;
    defaultPresetMap["key2_modline2_table"] = "Linear";
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
    defaultPresetMap["key2_modline2_ledgreen"] = "None";
    defaultPresetMap["key2_modline2_ledred"] = "None";
    defaultPresetMap["key2_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key2_modline3_enable"] = 0;
    defaultPresetMap["key2_modline3_initvalue"] = 0;
    defaultPresetMap["key2_modline3_initmode"] = "None";
    defaultPresetMap["key2_modline3_source"] = "None";
    defaultPresetMap["key2_modline3_gain"] = 1.00;
    defaultPresetMap["key2_modline3_offset"] = 0;
    defaultPresetMap["key2_modline3_table"] = "Linear";
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
    defaultPresetMap["key2_modline3_ledgreen"] = "None";
    defaultPresetMap["key2_modline3_ledred"] = "None";
    defaultPresetMap["key2_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key2_modline4_enable"] = 0;
    defaultPresetMap["key2_modline4_initvalue"] = 0;
    defaultPresetMap["key2_modline4_initmode"] = "None";
    defaultPresetMap["key2_modline4_source"] = "None";
    defaultPresetMap["key2_modline4_gain"] = 1.00;
    defaultPresetMap["key2_modline4_offset"] = 0;
    defaultPresetMap["key2_modline4_table"] = "Linear";
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
    defaultPresetMap["key2_modline4_ledgreen"] = "None";
    defaultPresetMap["key2_modline4_ledred"] = "None";
    defaultPresetMap["key2_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key2_modline5_enable"] = 0;
    defaultPresetMap["key2_modline5_initvalue"] = 0;
    defaultPresetMap["key2_modline5_initmode"] = "None";
    defaultPresetMap["key2_modline5_source"] = "None";
    defaultPresetMap["key2_modline5_gain"] = 1.00;
    defaultPresetMap["key2_modline5_offset"] = 0;
    defaultPresetMap["key2_modline5_table"] = "Linear";
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
    defaultPresetMap["key2_modline5_ledgreen"] = "None";
    defaultPresetMap["key2_modline5_ledred"] = "None";
    defaultPresetMap["key2_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key2_modline6_enable"] = 0;
    defaultPresetMap["key2_modline6_initvalue"] = 0;
    defaultPresetMap["key2_modline6_initmode"] = "None";
    defaultPresetMap["key2_modline6_source"] = "None";
    defaultPresetMap["key2_modline6_gain"] = 1.00;
    defaultPresetMap["key2_modline6_offset"] = 0;
    defaultPresetMap["key2_modline6_table"] = "Linear";
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
    defaultPresetMap["key2_modline6_ledgreen"] = "None";
    defaultPresetMap["key2_modline6_ledred"] = "None";
    defaultPresetMap["key2_modline6_displaylinked"] = 0;


    //------------------------ Key 3 ------------------------//
    defaultPresetMap["3_key_name"] = "3KEY";
    defaultPresetMap["3_key_displaymode"] = "None";
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
    defaultPresetMap["key3_modline1_table"] = "Linear";
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
    defaultPresetMap["key3_modline1_ledgreen"] = "None";
    defaultPresetMap["key3_modline1_ledred"] = "None";
    defaultPresetMap["key3_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key3_modline2_enable"] = 0;
    defaultPresetMap["key3_modline2_initvalue"] = 0;
    defaultPresetMap["key3_modline2_initmode"] = "None";
    defaultPresetMap["key3_modline2_source"] = "None";
    defaultPresetMap["key3_modline2_gain"] = 1.00;
    defaultPresetMap["key3_modline2_offset"] = 0;
    defaultPresetMap["key3_modline2_table"] = "Linear";
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
    defaultPresetMap["key3_modline2_ledgreen"] = "None";
    defaultPresetMap["key3_modline2_ledred"] = "None";
    defaultPresetMap["key3_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key3_modline3_enable"] = 0;
    defaultPresetMap["key3_modline3_initvalue"] = 0;
    defaultPresetMap["key3_modline3_initmode"] = "None";
    defaultPresetMap["key3_modline3_source"] = "None";
    defaultPresetMap["key3_modline3_gain"] = 1.00;
    defaultPresetMap["key3_modline3_offset"] = 0;
    defaultPresetMap["key3_modline3_table"] = "Linear";
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
    defaultPresetMap["key3_modline3_ledgreen"] = "None";
    defaultPresetMap["key3_modline3_ledred"] = "None";
    defaultPresetMap["key3_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key3_modline4_enable"] = 0;
    defaultPresetMap["key3_modline4_initvalue"] = 0;
    defaultPresetMap["key3_modline4_initmode"] = "None";
    defaultPresetMap["key3_modline4_source"] = "None";
    defaultPresetMap["key3_modline4_gain"] = 1.00;
    defaultPresetMap["key3_modline4_offset"] = 0;
    defaultPresetMap["key3_modline4_table"] = "Linear";
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
    defaultPresetMap["key3_modline4_ledgreen"] = "None";
    defaultPresetMap["key3_modline4_ledred"] = "None";
    defaultPresetMap["key3_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key3_modline5_enable"] = 0;
    defaultPresetMap["key3_modline5_initvalue"] = 0;
    defaultPresetMap["key3_modline5_initmode"] = "None";
    defaultPresetMap["key3_modline5_source"] = "None";
    defaultPresetMap["key3_modline5_gain"] = 1.00;
    defaultPresetMap["key3_modline5_offset"] = 0;
    defaultPresetMap["key3_modline5_table"] = "Linear";
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
    defaultPresetMap["key3_modline5_ledgreen"] = "None";
    defaultPresetMap["key3_modline5_ledred"] = "None";
    defaultPresetMap["key3_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key3_modline6_enable"] = 0;
    defaultPresetMap["key3_modline6_initvalue"] = 0;
    defaultPresetMap["key3_modline6_initmode"] = "None";
    defaultPresetMap["key3_modline6_source"] = "None";
    defaultPresetMap["key3_modline6_gain"] = 1.00;
    defaultPresetMap["key3_modline6_offset"] = 0;
    defaultPresetMap["key3_modline6_table"] = "Linear";
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
    defaultPresetMap["key3_modline6_ledgreen"] = "None";
    defaultPresetMap["key3_modline6_ledred"] = "None";
    defaultPresetMap["key3_modline6_displaylinked"] = 0;


    //------------------------ Key 4 ------------------------//
    defaultPresetMap["4_key_name"] = "4KEY";
    defaultPresetMap["4_key_displaymode"] = "None";
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
    defaultPresetMap["key4_modline1_table"] = "Linear";
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
    defaultPresetMap["key4_modline1_ledgreen"] = "None";
    defaultPresetMap["key4_modline1_ledred"] = "None";
    defaultPresetMap["key4_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key4_modline2_enable"] = 0;
    defaultPresetMap["key4_modline2_initvalue"] = 0;
    defaultPresetMap["key4_modline2_initmode"] = "None";
    defaultPresetMap["key4_modline2_source"] = "None";
    defaultPresetMap["key4_modline2_gain"] = 1.00;
    defaultPresetMap["key4_modline2_offset"] = 0;
    defaultPresetMap["key4_modline2_table"] = "Linear";
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
    defaultPresetMap["key4_modline2_ledgreen"] = "None";
    defaultPresetMap["key4_modline2_ledred"] = "None";
    defaultPresetMap["key4_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key4_modline3_enable"] = 0;
    defaultPresetMap["key4_modline3_initvalue"] = 0;
    defaultPresetMap["key4_modline3_initmode"] = "None";
    defaultPresetMap["key4_modline3_source"] = "None";
    defaultPresetMap["key4_modline3_gain"] = 1.00;
    defaultPresetMap["key4_modline3_offset"] = 0;
    defaultPresetMap["key4_modline3_table"] = "Linear";
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
    defaultPresetMap["key4_modline3_ledgreen"] = "None";
    defaultPresetMap["key4_modline3_ledred"] = "None";
    defaultPresetMap["key4_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key4_modline4_enable"] = 0;
    defaultPresetMap["key4_modline4_initvalue"] = 0;
    defaultPresetMap["key4_modline4_initmode"] = "None";
    defaultPresetMap["key4_modline4_source"] = "None";
    defaultPresetMap["key4_modline4_gain"] = 1.00;
    defaultPresetMap["key4_modline4_offset"] = 0;
    defaultPresetMap["key4_modline4_table"] = "Linear";
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
    defaultPresetMap["key4_modline4_ledgreen"] = "None";
    defaultPresetMap["key4_modline4_ledred"] = "None";
    defaultPresetMap["key4_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key4_modline5_enable"] = 0;
    defaultPresetMap["key4_modline5_initvalue"] = 0;
    defaultPresetMap["key4_modline5_initmode"] = "None";
    defaultPresetMap["key4_modline5_source"] = "None";
    defaultPresetMap["key4_modline5_gain"] = 1.00;
    defaultPresetMap["key4_modline5_offset"] = 0;
    defaultPresetMap["key4_modline5_table"] = "Linear";
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
    defaultPresetMap["key4_modline5_ledgreen"] = "None";
    defaultPresetMap["key4_modline5_ledred"] = "None";
    defaultPresetMap["key4_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key4_modline6_enable"] = 0;
    defaultPresetMap["key4_modline6_initvalue"] = 0;
    defaultPresetMap["key4_modline6_initmode"] = "None";
    defaultPresetMap["key4_modline6_source"] = "None";
    defaultPresetMap["key4_modline6_gain"] = 1.00;
    defaultPresetMap["key4_modline6_offset"] = 0;
    defaultPresetMap["key4_modline6_table"] = "Linear";
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
    defaultPresetMap["key4_modline6_ledgreen"] = "None";
    defaultPresetMap["key4_modline6_ledred"] = "None";
    defaultPresetMap["key4_modline6_displaylinked"] = 0;

    //------------------------ Key 5 ------------------------//
    defaultPresetMap["5_key_name"] = "5KEY";
    defaultPresetMap["5_key_displaymode"] = "None";
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
    defaultPresetMap["key5_modline1_table"] = "Linear";
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
    defaultPresetMap["key5_modline1_ledgreen"] = "None";
    defaultPresetMap["key5_modline1_ledred"] = "None";
    defaultPresetMap["key5_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key5_modline2_enable"] = 0;
    defaultPresetMap["key5_modline2_initvalue"] = 0;
    defaultPresetMap["key5_modline2_initmode"] = "None";
    defaultPresetMap["key5_modline2_source"] = "None";
    defaultPresetMap["key5_modline2_gain"] = 1.00;
    defaultPresetMap["key5_modline2_offset"] = 0;
    defaultPresetMap["key5_modline2_table"] = "Linear";
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
    defaultPresetMap["key5_modline2_ledgreen"] = "None";
    defaultPresetMap["key5_modline2_ledred"] = "None";
    defaultPresetMap["key5_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key5_modline3_enable"] = 0;
    defaultPresetMap["key5_modline3_initvalue"] = 0;
    defaultPresetMap["key5_modline3_initmode"] = "None";
    defaultPresetMap["key5_modline3_source"] = "None";
    defaultPresetMap["key5_modline3_gain"] = 1.00;
    defaultPresetMap["key5_modline3_offset"] = 0;
    defaultPresetMap["key5_modline3_table"] = "Linear";
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
    defaultPresetMap["key5_modline3_ledgreen"] = "None";
    defaultPresetMap["key5_modline3_ledred"] = "None";
    defaultPresetMap["key5_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key5_modline4_enable"] = 0;
    defaultPresetMap["key5_modline4_initvalue"] = 0;
    defaultPresetMap["key5_modline4_initmode"] = "None";
    defaultPresetMap["key5_modline4_source"] = "None";
    defaultPresetMap["key5_modline4_gain"] = 1.00;
    defaultPresetMap["key5_modline4_offset"] = 0;
    defaultPresetMap["key5_modline4_table"] = "Linear";
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
    defaultPresetMap["key5_modline4_ledgreen"] = "None";
    defaultPresetMap["key5_modline4_ledred"] = "None";
    defaultPresetMap["key5_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key5_modline5_enable"] = 0;
    defaultPresetMap["key5_modline5_initvalue"] = 0;
    defaultPresetMap["key5_modline5_initmode"] = "None";
    defaultPresetMap["key5_modline5_source"] = "None";
    defaultPresetMap["key5_modline5_gain"] = 1.00;
    defaultPresetMap["key5_modline5_offset"] = 0;
    defaultPresetMap["key5_modline5_table"] = "Linear";
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
    defaultPresetMap["key5_modline5_ledgreen"] = "None";
    defaultPresetMap["key5_modline5_ledred"] = "None";
    defaultPresetMap["key5_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key5_modline6_enable"] = 0;
    defaultPresetMap["key5_modline6_initvalue"] = 0;
    defaultPresetMap["key5_modline6_initmode"] = "None";
    defaultPresetMap["key5_modline6_source"] = "None";
    defaultPresetMap["key5_modline6_gain"] = 1.00;
    defaultPresetMap["key5_modline6_offset"] = 0;
    defaultPresetMap["key5_modline6_table"] = "Linear";
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
    defaultPresetMap["key5_modline6_ledgreen"] = "None";
    defaultPresetMap["key5_modline6_ledred"] = "None";
    defaultPresetMap["key5_modline6_displaylinked"] = 0;


    //------------------------ Key 6 ------------------------//
    defaultPresetMap["6_key_name"] = "6KEY";
    defaultPresetMap["6_key_displaymode"] = "None";
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
    defaultPresetMap["key6_modline1_table"] = "Linear";
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
    defaultPresetMap["key6_modline1_ledgreen"] = "None";
    defaultPresetMap["key6_modline1_ledred"] = "None";
    defaultPresetMap["key6_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key6_modline2_enable"] = 0;
    defaultPresetMap["key6_modline2_initvalue"] = 0;
    defaultPresetMap["key6_modline2_initmode"] = "None";
    defaultPresetMap["key6_modline2_source"] = "None";
    defaultPresetMap["key6_modline2_gain"] = 1.00;
    defaultPresetMap["key6_modline2_offset"] = 0;
    defaultPresetMap["key6_modline2_table"] = "Linear";
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
    defaultPresetMap["key6_modline2_ledgreen"] = "None";
    defaultPresetMap["key6_modline2_ledred"] = "None";
    defaultPresetMap["key6_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key6_modline3_enable"] = 0;
    defaultPresetMap["key6_modline3_initvalue"] = 0;
    defaultPresetMap["key6_modline3_initmode"] = "None";
    defaultPresetMap["key6_modline3_source"] = "None";
    defaultPresetMap["key6_modline3_gain"] = 1.00;
    defaultPresetMap["key6_modline3_offset"] = 0;
    defaultPresetMap["key6_modline3_table"] = "Linear";
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
    defaultPresetMap["key6_modline3_ledgreen"] = "None";
    defaultPresetMap["key6_modline3_ledred"] = "None";
    defaultPresetMap["key6_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key6_modline4_enable"] = 0;
    defaultPresetMap["key6_modline4_initvalue"] = 0;
    defaultPresetMap["key6_modline4_initmode"] = "None";
    defaultPresetMap["key6_modline4_source"] = "None";
    defaultPresetMap["key6_modline4_gain"] = 1.00;
    defaultPresetMap["key6_modline4_offset"] = 0;
    defaultPresetMap["key6_modline4_table"] = "Linear";
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
    defaultPresetMap["key6_modline4_ledgreen"] = "None";
    defaultPresetMap["key6_modline4_ledred"] = "None";
    defaultPresetMap["key6_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key6_modline5_enable"] = 0;
    defaultPresetMap["key6_modline5_initvalue"] = 0;
    defaultPresetMap["key6_modline5_initmode"] = "None";
    defaultPresetMap["key6_modline5_source"] = "None";
    defaultPresetMap["key6_modline5_gain"] = 1.00;
    defaultPresetMap["key6_modline5_offset"] = 0;
    defaultPresetMap["key6_modline5_table"] = "Linear";
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
    defaultPresetMap["key6_modline5_ledgreen"] = "None";
    defaultPresetMap["key6_modline5_ledred"] = "None";
    defaultPresetMap["key6_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key6_modline6_enable"] = 0;
    defaultPresetMap["key6_modline6_initvalue"] = 0;
    defaultPresetMap["key6_modline6_initmode"] = "None";
    defaultPresetMap["key6_modline6_source"] = "None";
    defaultPresetMap["key6_modline6_gain"] = 1.00;
    defaultPresetMap["key6_modline6_offset"] = 0;
    defaultPresetMap["key6_modline6_table"] = "Linear";
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
    defaultPresetMap["key6_modline6_ledgreen"] = "None";
    defaultPresetMap["key6_modline6_ledred"] = "None";
    defaultPresetMap["key6_modline6_displaylinked"] = 0;


    //------------------------ Key 7 ------------------------//
    defaultPresetMap["7_key_name"] = "7KEY";
    defaultPresetMap["7_key_displaymode"] = "None";
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
    defaultPresetMap["key7_modline1_table"] = "Linear";
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
    defaultPresetMap["key7_modline1_ledgreen"] = "None";
    defaultPresetMap["key7_modline1_ledred"] = "None";
    defaultPresetMap["key7_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key7_modline2_enable"] = 0;
    defaultPresetMap["key7_modline2_initvalue"] = 0;
    defaultPresetMap["key7_modline2_initmode"] = "None";
    defaultPresetMap["key7_modline2_source"] = "None";
    defaultPresetMap["key7_modline2_gain"] = 1.00;
    defaultPresetMap["key7_modline2_offset"] = 0;
    defaultPresetMap["key7_modline2_table"] = "Linear";
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
    defaultPresetMap["key7_modline2_ledgreen"] = "None";
    defaultPresetMap["key7_modline2_ledred"] = "None";
    defaultPresetMap["key7_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key7_modline3_enable"] = 0;
    defaultPresetMap["key7_modline3_initvalue"] = 0;
    defaultPresetMap["key7_modline3_initmode"] = "None";
    defaultPresetMap["key7_modline3_source"] = "None";
    defaultPresetMap["key7_modline3_gain"] = 1.00;
    defaultPresetMap["key7_modline3_offset"] = 0;
    defaultPresetMap["key7_modline3_table"] = "Linear";
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
    defaultPresetMap["key7_modline3_ledgreen"] = "None";
    defaultPresetMap["key7_modline3_ledred"] = "None";
    defaultPresetMap["key7_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key7_modline4_enable"] = 0;
    defaultPresetMap["key7_modline4_initvalue"] = 0;
    defaultPresetMap["key7_modline4_initmode"] = "None";
    defaultPresetMap["key7_modline4_source"] = "None";
    defaultPresetMap["key7_modline4_gain"] = 1.00;
    defaultPresetMap["key7_modline4_offset"] = 0;
    defaultPresetMap["key7_modline4_table"] = "Linear";
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
    defaultPresetMap["key7_modline4_ledgreen"] = "None";
    defaultPresetMap["key7_modline4_ledred"] = "None";
    defaultPresetMap["key7_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key7_modline5_enable"] = 0;
    defaultPresetMap["key7_modline5_initvalue"] = 0;
    defaultPresetMap["key7_modline5_initmode"] = "None";
    defaultPresetMap["key7_modline5_source"] = "None";
    defaultPresetMap["key7_modline5_gain"] = 1.00;
    defaultPresetMap["key7_modline5_offset"] = 0;
    defaultPresetMap["key7_modline5_table"] = "Linear";
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
    defaultPresetMap["key7_modline5_ledgreen"] = "None";
    defaultPresetMap["key7_modline5_ledred"] = "None";
    defaultPresetMap["key7_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key7_modline6_enable"] = 0;
    defaultPresetMap["key7_modline6_initvalue"] = 0;
    defaultPresetMap["key7_modline6_initmode"] = "None";
    defaultPresetMap["key7_modline6_source"] = "None";
    defaultPresetMap["key7_modline6_gain"] = 1.00;
    defaultPresetMap["key7_modline6_offset"] = 0;
    defaultPresetMap["key7_modline6_table"] = "Linear";
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
    defaultPresetMap["key7_modline6_ledgreen"] = "None";
    defaultPresetMap["key7_modline6_ledred"] = "None";
    defaultPresetMap["key7_modline6_displaylinked"] = 0;

    //------------------------ Key 8 ------------------------//
    defaultPresetMap["8_key_name"] = "8KEY";
    defaultPresetMap["8_key_displaymode"] = "None";
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
    defaultPresetMap["key8_modline1_table"] = "Linear";
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
    defaultPresetMap["key8_modline1_ledgreen"] = "None";
    defaultPresetMap["key8_modline1_ledred"] = "None";
    defaultPresetMap["key8_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key8_modline2_enable"] = 0;
    defaultPresetMap["key8_modline2_initvalue"] = 0;
    defaultPresetMap["key8_modline2_initmode"] = "None";
    defaultPresetMap["key8_modline2_source"] = "None";
    defaultPresetMap["key8_modline2_gain"] = 1.00;
    defaultPresetMap["key8_modline2_offset"] = 0;
    defaultPresetMap["key8_modline2_table"] = "Linear";
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
    defaultPresetMap["key8_modline2_ledgreen"] = "None";
    defaultPresetMap["key8_modline2_ledred"] = "None";
    defaultPresetMap["key8_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key8_modline3_enable"] = 0;
    defaultPresetMap["key8_modline3_initvalue"] = 0;
    defaultPresetMap["key8_modline3_initmode"] = "None";
    defaultPresetMap["key8_modline3_source"] = "None";
    defaultPresetMap["key8_modline3_gain"] = 1.00;
    defaultPresetMap["key8_modline3_offset"] = 0;
    defaultPresetMap["key8_modline3_table"] = "Linear";
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
    defaultPresetMap["key8_modline3_ledgreen"] = "None";
    defaultPresetMap["key8_modline3_ledred"] = "None";
    defaultPresetMap["key8_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key8_modline4_enable"] = 0;
    defaultPresetMap["key8_modline4_initvalue"] = 0;
    defaultPresetMap["key8_modline4_initmode"] = "None";
    defaultPresetMap["key8_modline4_source"] = "None";
    defaultPresetMap["key8_modline4_gain"] = 1.00;
    defaultPresetMap["key8_modline4_offset"] = 0;
    defaultPresetMap["key8_modline4_table"] = "Linear";
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
    defaultPresetMap["key8_modline4_ledgreen"] = "None";
    defaultPresetMap["key8_modline4_ledred"] = "None";
    defaultPresetMap["key8_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key8_modline5_enable"] = 0;
    defaultPresetMap["key8_modline5_initvalue"] = 0;
    defaultPresetMap["key8_modline5_initmode"] = "None";
    defaultPresetMap["key8_modline5_source"] = "None";
    defaultPresetMap["key8_modline5_gain"] = 1.00;
    defaultPresetMap["key8_modline5_offset"] = 0;
    defaultPresetMap["key8_modline5_table"] = "Linear";
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
    defaultPresetMap["key8_modline5_ledgreen"] = "None";
    defaultPresetMap["key8_modline5_ledred"] = "None";
    defaultPresetMap["key8_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key8_modline6_enable"] = 0;
    defaultPresetMap["key8_modline6_initvalue"] = 0;
    defaultPresetMap["key8_modline6_initmode"] = "None";
    defaultPresetMap["key8_modline6_source"] = "None";
    defaultPresetMap["key8_modline6_gain"] = 1.00;
    defaultPresetMap["key8_modline6_offset"] = 0;
    defaultPresetMap["key8_modline6_table"] = "Linear";
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
    defaultPresetMap["key8_modline6_ledgreen"] = "None";
    defaultPresetMap["key8_modline6_ledred"] = "None";
    defaultPresetMap["key8_modline6_displaylinked"] = 0;


    //------------------------ Key 9 ------------------------//
    defaultPresetMap["9_key_name"] = "9KEY";
    defaultPresetMap["9_key_displaymode"] = "None";
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
    defaultPresetMap["key9_modline1_table"] = "Linear";
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
    defaultPresetMap["key9_modline1_ledgreen"] = "None";
    defaultPresetMap["key9_modline1_ledred"] = "None";
    defaultPresetMap["key9_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key9_modline2_enable"] = 0;
    defaultPresetMap["key9_modline2_initvalue"] = 0;
    defaultPresetMap["key9_modline2_initmode"] = "None";
    defaultPresetMap["key9_modline2_source"] = "None";
    defaultPresetMap["key9_modline2_gain"] = 1.00;
    defaultPresetMap["key9_modline2_offset"] = 0;
    defaultPresetMap["key9_modline2_table"] = "Linear";
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
    defaultPresetMap["key9_modline2_ledgreen"] = "None";
    defaultPresetMap["key9_modline2_ledred"] = "None";
    defaultPresetMap["key9_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key9_modline3_enable"] = 0;
    defaultPresetMap["key9_modline3_initvalue"] = 0;
    defaultPresetMap["key9_modline3_initmode"] = "None";
    defaultPresetMap["key9_modline3_source"] = "None";
    defaultPresetMap["key9_modline3_gain"] = 1.00;
    defaultPresetMap["key9_modline3_offset"] = 0;
    defaultPresetMap["key9_modline3_table"] = "Linear";
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
    defaultPresetMap["key9_modline3_ledgreen"] = "None";
    defaultPresetMap["key9_modline3_ledred"] = "None";
    defaultPresetMap["key9_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key9_modline4_enable"] = 0;
    defaultPresetMap["key9_modline4_initvalue"] = 0;
    defaultPresetMap["key9_modline4_initmode"] = "None";
    defaultPresetMap["key9_modline4_source"] = "None";
    defaultPresetMap["key9_modline4_gain"] = 1.00;
    defaultPresetMap["key9_modline4_offset"] = 0;
    defaultPresetMap["key9_modline4_table"] = "Linear";
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
    defaultPresetMap["key9_modline4_ledgreen"] = "None";
    defaultPresetMap["key9_modline4_ledred"] = "None";
    defaultPresetMap["key9_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key9_modline5_enable"] = 0;
    defaultPresetMap["key9_modline5_initvalue"] = 0;
    defaultPresetMap["key9_modline5_initmode"] = "None";
    defaultPresetMap["key9_modline5_source"] = "None";
    defaultPresetMap["key9_modline5_gain"] = 1.00;
    defaultPresetMap["key9_modline5_offset"] = 0;
    defaultPresetMap["key9_modline5_table"] = "Linear";
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
    defaultPresetMap["key9_modline5_ledgreen"] = "None";
    defaultPresetMap["key9_modline5_ledred"] = "None";
    defaultPresetMap["key9_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key9_modline6_enable"] = 0;
    defaultPresetMap["key9_modline6_initvalue"] = 0;
    defaultPresetMap["key9_modline6_initmode"] = "None";
    defaultPresetMap["key9_modline6_source"] = "None";
    defaultPresetMap["key9_modline6_gain"] = 1.00;
    defaultPresetMap["key9_modline6_offset"] = 0;
    defaultPresetMap["key9_modline6_table"] = "Linear";
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
    defaultPresetMap["key9_modline6_ledgreen"] = "None";
    defaultPresetMap["key9_modline6_ledred"] = "None";
    defaultPresetMap["key9_modline6_displaylinked"] = 0;


    //------------------------ Key 10 ------------------------//
    defaultPresetMap["10_key_name"] = "0KEY";
    defaultPresetMap["10_key_displaymode"] = "None";
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
    defaultPresetMap["key10_modline1_table"] = "Linear";
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
    defaultPresetMap["key10_modline1_ledgreen"] = "None";
    defaultPresetMap["key10_modline1_ledred"] = "None";
    defaultPresetMap["key10_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key10_modline2_enable"] = 0;
    defaultPresetMap["key10_modline2_initvalue"] = 0;
    defaultPresetMap["key10_modline2_initmode"] = "None";
    defaultPresetMap["key10_modline2_source"] = "None";
    defaultPresetMap["key10_modline2_gain"] = 1.00;
    defaultPresetMap["key10_modline2_offset"] = 0;
    defaultPresetMap["key10_modline2_table"] = "Linear";
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
    defaultPresetMap["key10_modline2_ledgreen"] = "None";
    defaultPresetMap["key10_modline2_ledred"] = "None";
    defaultPresetMap["key10_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key10_modline3_enable"] = 0;
    defaultPresetMap["key10_modline3_initvalue"] = 0;
    defaultPresetMap["key10_modline3_initmode"] = "None";
    defaultPresetMap["key10_modline3_source"] = "None";
    defaultPresetMap["key10_modline3_gain"] = 1.00;
    defaultPresetMap["key10_modline3_offset"] = 0;
    defaultPresetMap["key10_modline3_table"] = "Linear";
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
    defaultPresetMap["key10_modline3_ledgreen"] = "None";
    defaultPresetMap["key10_modline3_ledred"] = "None";
    defaultPresetMap["key10_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key10_modline4_enable"] = 0;
    defaultPresetMap["key10_modline4_initvalue"] = 0;
    defaultPresetMap["key10_modline4_initmode"] = "None";
    defaultPresetMap["key10_modline4_source"] = "None";
    defaultPresetMap["key10_modline4_gain"] = 1.00;
    defaultPresetMap["key10_modline4_offset"] = 0;
    defaultPresetMap["key10_modline4_table"] = "Linear";
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
    defaultPresetMap["key10_modline4_ledgreen"] = "None";
    defaultPresetMap["key10_modline4_ledred"] = "None";
    defaultPresetMap["key10_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key10_modline5_enable"] = 0;
    defaultPresetMap["key10_modline5_initvalue"] = 0;
    defaultPresetMap["key10_modline5_initmode"] = "None";
    defaultPresetMap["key10_modline5_source"] = "None";
    defaultPresetMap["key10_modline5_gain"] = 1.00;
    defaultPresetMap["key10_modline5_offset"] = 0;
    defaultPresetMap["key10_modline5_table"] = "Linear";
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
    defaultPresetMap["key10_modline5_ledgreen"] = "None";
    defaultPresetMap["key10_modline5_ledred"] = "None";
    defaultPresetMap["key10_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key10_modline6_enable"] = 0;
    defaultPresetMap["key10_modline6_initvalue"] = 0;
    defaultPresetMap["key10_modline6_initmode"] = "None";
    defaultPresetMap["key10_modline6_source"] = "None";
    defaultPresetMap["key10_modline6_gain"] = 1.00;
    defaultPresetMap["key10_modline6_offset"] = 0;
    defaultPresetMap["key10_modline6_table"] = "Linear";
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
    defaultPresetMap["key10_modline6_ledgreen"] = "None";
    defaultPresetMap["key10_modline6_ledred"] = "None";
    defaultPresetMap["key10_modline6_displaylinked"] = 0;

    //------------------------ Nav ------------------------//
    defaultPresetMap["nav_name"] = "1KEY";
    defaultPresetMap["nav_displaymode"] = "None";
    defaultPresetMap["nav_modlinemode"] = 1;
    defaultPresetMap["nav_prefix"] = "";
    defaultPresetMap["nav_counter_min"] = 0;
    defaultPresetMap["nav_counter_max"] = 127;
    defaultPresetMap["nav_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["nav_modline1_enable"] = 0;
    defaultPresetMap["nav_modline1_initvalue"] = 0;
    defaultPresetMap["nav_modline1_initmode"] = "None";
    defaultPresetMap["nav_modline1_source"] = "None";
    defaultPresetMap["nav_modline1_gain"] = 1.00;
    defaultPresetMap["nav_modline1_offset"] = 0;
    defaultPresetMap["nav_modline1_table"] = "Linear";
    defaultPresetMap["nav_modline1_min"] = 0;
    defaultPresetMap["nav_modline1_max"] = 127;
    defaultPresetMap["nav_modline1_slew"] = 0;
    defaultPresetMap["nav_modline1_delay"] = 0;
    defaultPresetMap["nav_modline1_destination"] = "None";
    defaultPresetMap["nav_modline1_note"] = 60;
    defaultPresetMap["nav_modline1_velocity"] = 127;
    defaultPresetMap["nav_modline1_cc"] = 1;
    defaultPresetMap["nav_modline1_bankmsb"] = 0;
    defaultPresetMap["nav_modline1_mmcid"] = 0;
    defaultPresetMap["nav_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline1_channel"] = 1;
    defaultPresetMap["nav_modline1_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline1_oscroute"] = "";
    defaultPresetMap["nav_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["nav_modline2_enable"] = 0;
    defaultPresetMap["nav_modline2_initvalue"] = 0;
    defaultPresetMap["nav_modline2_initmode"] = "None";
    defaultPresetMap["nav_modline2_source"] = "None";
    defaultPresetMap["nav_modline2_gain"] = 1.00;
    defaultPresetMap["nav_modline2_offset"] = 0;
    defaultPresetMap["nav_modline2_table"] = "Linear";
    defaultPresetMap["nav_modline2_min"] = 0;
    defaultPresetMap["nav_modline2_max"] = 127;
    defaultPresetMap["nav_modline2_slew"] = 0;
    defaultPresetMap["nav_modline2_delay"] = 0;
    defaultPresetMap["nav_modline2_destination"] = "None";
    defaultPresetMap["nav_modline2_note"] = 60;
    defaultPresetMap["nav_modline2_velocity"] = 127;
    defaultPresetMap["nav_modline2_cc"] = 1;
    defaultPresetMap["nav_modline2_bankmsb"] = 0;
    defaultPresetMap["nav_modline2_mmcid"] = 0;
    defaultPresetMap["nav_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline2_channel"] = 1;
    defaultPresetMap["nav_modline2_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline2_oscroute"] = "";
    defaultPresetMap["nav_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["nav_modline3_enable"] = 0;
    defaultPresetMap["nav_modline3_initvalue"] = 0;
    defaultPresetMap["nav_modline3_initmode"] = "None";
    defaultPresetMap["nav_modline3_source"] = "None";
    defaultPresetMap["nav_modline3_gain"] = 1.00;
    defaultPresetMap["nav_modline3_offset"] = 0;
    defaultPresetMap["nav_modline3_table"] = "Linear";
    defaultPresetMap["nav_modline3_min"] = 0;
    defaultPresetMap["nav_modline3_max"] = 127;
    defaultPresetMap["nav_modline3_slew"] = 0;
    defaultPresetMap["nav_modline3_delay"] = 0;
    defaultPresetMap["nav_modline3_destination"] = "None";
    defaultPresetMap["nav_modline3_note"] = 60;
    defaultPresetMap["nav_modline3_velocity"] = 127;
    defaultPresetMap["nav_modline3_cc"] = 1;
    defaultPresetMap["nav_modline3_bankmsb"] = 0;
    defaultPresetMap["nav_modline3_mmcid"] = 0;
    defaultPresetMap["nav_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline3_channel"] = 1;
    defaultPresetMap["nav_modline3_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline3_oscroute"] = "";
    defaultPresetMap["nav_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["nav_modline4_enable"] = 0;
    defaultPresetMap["nav_modline4_initvalue"] = 0;
    defaultPresetMap["nav_modline4_initmode"] = "None";
    defaultPresetMap["nav_modline4_source"] = "None";
    defaultPresetMap["nav_modline4_gain"] = 1.00;
    defaultPresetMap["nav_modline4_offset"] = 0;
    defaultPresetMap["nav_modline4_table"] = "Linear";
    defaultPresetMap["nav_modline4_min"] = 0;
    defaultPresetMap["nav_modline4_max"] = 127;
    defaultPresetMap["nav_modline4_slew"] = 0;
    defaultPresetMap["nav_modline4_delay"] = 0;
    defaultPresetMap["nav_modline4_destination"] = "None";
    defaultPresetMap["nav_modline4_note"] = 60;
    defaultPresetMap["nav_modline4_velocity"] = 127;
    defaultPresetMap["nav_modline4_cc"] = 1;
    defaultPresetMap["nav_modline4_bankmsb"] = 0;
    defaultPresetMap["nav_modline4_mmcid"] = 0;
    defaultPresetMap["nav_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline4_channel"] = 1;
    defaultPresetMap["nav_modline4_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline4_oscroute"] = "";
    defaultPresetMap["nav_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["nav_modline5_enable"] = 0;
    defaultPresetMap["nav_modline5_initvalue"] = 0;
    defaultPresetMap["nav_modline5_initmode"] = "None";
    defaultPresetMap["nav_modline5_source"] = "None";
    defaultPresetMap["nav_modline5_gain"] = 1.00;
    defaultPresetMap["nav_modline5_offset"] = 0;
    defaultPresetMap["nav_modline5_table"] = "Linear";
    defaultPresetMap["nav_modline5_min"] = 0;
    defaultPresetMap["nav_modline5_max"] = 127;
    defaultPresetMap["nav_modline5_slew"] = 0;
    defaultPresetMap["nav_modline5_delay"] = 0;
    defaultPresetMap["nav_modline5_destination"] = "None";
    defaultPresetMap["nav_modline5_note"] = 60;
    defaultPresetMap["nav_modline5_velocity"] = 127;
    defaultPresetMap["nav_modline5_cc"] = 1;
    defaultPresetMap["nav_modline5_bankmsb"] = 0;
    defaultPresetMap["nav_modline5_mmcid"] = 0;
    defaultPresetMap["nav_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline5_channel"] = 1;
    defaultPresetMap["nav_modline5_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline5_oscroute"] = "";
    defaultPresetMap["nav_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["nav_modline6_enable"] = 0;
    defaultPresetMap["nav_modline6_initvalue"] = 0;
    defaultPresetMap["nav_modline6_initmode"] = "None";
    defaultPresetMap["nav_modline6_source"] = "None";
    defaultPresetMap["nav_modline6_gain"] = 1.00;
    defaultPresetMap["nav_modline6_offset"] = 0;
    defaultPresetMap["nav_modline6_table"] = "Linear";
    defaultPresetMap["nav_modline6_min"] = 0;
    defaultPresetMap["nav_modline6_max"] = 127;
    defaultPresetMap["nav_modline6_slew"] = 0;
    defaultPresetMap["nav_modline6_delay"] = 0;
    defaultPresetMap["nav_modline6_destination"] = "None";
    defaultPresetMap["nav_modline6_note"] = 60;
    defaultPresetMap["nav_modline6_velocity"] = 127;
    defaultPresetMap["nav_modline6_cc"] = 1;
    defaultPresetMap["nav_modline6_bankmsb"] = 0;
    defaultPresetMap["nav_modline6_mmcid"] = 0;
    defaultPresetMap["nav_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline6_channel"] = 1;
    defaultPresetMap["nav_modline6_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline6_oscroute"] = "";
    defaultPresetMap["nav_modline6_displaylinked"] = 0;
}

void PresetInterface::slotConstructDefaultStandaloneMap()
{
    defaultPresetMap["preset_name"] = "Default Preset";
    defaultPresetMap["preset_displayname"] = "DFLT";

    //------------------------ Key 1 ------------------------//
    defaultPresetMap["1_key_name"] = "1KEY";
    defaultPresetMap["1_key_displaymode"] = "None";
    defaultPresetMap["1_key_prefix"] = "";
    //defaultPresetMap["1_key_counter_min"] = 0;
    //defaultPresetMap["1_key_counter_max"] = 127;
    //defaultPresetMap["1_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key1_modline1_enable"] = 0;
    //defaultPresetMap["key1_modline1_initvalue"] = 0;
    //defaultPresetMap["key1_modline1_initmode"] = "None";
    defaultPresetMap["key1_modline1_source"] = "None";
    defaultPresetMap["key1_modline1_gain"] = 1.00;
    defaultPresetMap["key1_modline1_offset"] = 0;
    defaultPresetMap["key1_modline1_table"] = "Linear";
    defaultPresetMap["key1_modline1_min"] = 0;
    defaultPresetMap["key1_modline1_max"] = 127;
    defaultPresetMap["key1_modline1_slew"] = 0;
    //defaultPresetMap["key1_modline1_delay"] = 0;
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
    defaultPresetMap["key1_modline1_ledgreen"] = "None";
    defaultPresetMap["key1_modline1_ledred"] = "None";
    defaultPresetMap["key1_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key1_modline2_enable"] = 0;
    //defaultPresetMap["key1_modline2_initvalue"] = 0;
    //defaultPresetMap["key1_modline2_initmode"] = "None";
    defaultPresetMap["key1_modline2_source"] = "None";
    defaultPresetMap["key1_modline2_gain"] = 1.00;
    defaultPresetMap["key1_modline2_offset"] = 0;
    defaultPresetMap["key1_modline2_table"] = "Linear";
    defaultPresetMap["key1_modline2_min"] = 0;
    defaultPresetMap["key1_modline2_max"] = 127;
    defaultPresetMap["key1_modline2_slew"] = 0;
    //defaultPresetMap["key1_modline2_delay"] = 0;
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
    defaultPresetMap["key1_modline2_ledgreen"] = "None";
    defaultPresetMap["key1_modline2_ledred"] = "None";
    defaultPresetMap["key1_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key1_modline3_enable"] = 0;
    //defaultPresetMap["key1_modline3_initvalue"] = 0;
    //defaultPresetMap["key1_modline3_initmode"] = "None";
    defaultPresetMap["key1_modline3_source"] = "None";
    defaultPresetMap["key1_modline3_gain"] = 1.00;
    defaultPresetMap["key1_modline3_offset"] = 0;
    defaultPresetMap["key1_modline3_table"] = "Linear";
    defaultPresetMap["key1_modline3_min"] = 0;
    defaultPresetMap["key1_modline3_max"] = 127;
    defaultPresetMap["key1_modline3_slew"] = 0;
    //defaultPresetMap["key1_modline3_delay"] = 0;
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
    defaultPresetMap["key1_modline3_ledgreen"] = "None";
    defaultPresetMap["key1_modline3_ledred"] = "None";
    defaultPresetMap["key1_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key1_modline4_enable"] = 0;
    //defaultPresetMap["key1_modline4_initvalue"] = 0;
    //defaultPresetMap["key1_modline4_initmode"] = "None";
    defaultPresetMap["key1_modline4_source"] = "None";
    defaultPresetMap["key1_modline4_gain"] = 1.00;
    defaultPresetMap["key1_modline4_offset"] = 0;
    defaultPresetMap["key1_modline4_table"] = "Linear";
    defaultPresetMap["key1_modline4_min"] = 0;
    defaultPresetMap["key1_modline4_max"] = 127;
    defaultPresetMap["key1_modline4_slew"] = 0;
    //defaultPresetMap["key1_modline4_delay"] = 0;
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
    defaultPresetMap["key1_modline4_ledgreen"] = "None";
    defaultPresetMap["key1_modline4_ledred"] = "None";
    defaultPresetMap["key1_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key1_modline5_enable"] = 0;
    //defaultPresetMap["key1_modline5_initvalue"] = 0;
    //defaultPresetMap["key1_modline5_initmode"] = "None";
    defaultPresetMap["key1_modline5_source"] = "None";
    defaultPresetMap["key1_modline5_gain"] = 1.00;
    defaultPresetMap["key1_modline5_offset"] = 0;
    defaultPresetMap["key1_modline5_table"] = "Linear";
    defaultPresetMap["key1_modline5_min"] = 0;
    defaultPresetMap["key1_modline5_max"] = 127;
    defaultPresetMap["key1_modline5_slew"] = 0;
    //defaultPresetMap["key1_modline5_delay"] = 0;
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
    defaultPresetMap["key1_modline5_ledgreen"] = "None";
    defaultPresetMap["key1_modline5_ledred"] = "None";
    defaultPresetMap["key1_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key1_modline6_enable"] = 0;
    //defaultPresetMap["key1_modline6_initvalue"] = 0;
    //defaultPresetMap["key1_modline6_initmode"] = "None";
    defaultPresetMap["key1_modline6_source"] = "None";
    defaultPresetMap["key1_modline6_gain"] = 1.00;
    defaultPresetMap["key1_modline6_offset"] = 0;
    defaultPresetMap["key1_modline6_table"] = "Linear";
    defaultPresetMap["key1_modline6_min"] = 0;
    defaultPresetMap["key1_modline6_max"] = 127;
    defaultPresetMap["key1_modline6_slew"] = 0;
    //defaultPresetMap["key1_modline6_delay"] = 0;
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
    defaultPresetMap["key1_modline6_ledgreen"] = "None";
    defaultPresetMap["key1_modline6_ledred"] = "None";
    defaultPresetMap["key1_modline6_displaylinked"] = 0;


    //------------------------ Key 2 ------------------------//
    defaultPresetMap["2_key_name"] = "2KEY";
    defaultPresetMap["2_key_displaymode"] = "None";
    defaultPresetMap["2_key_prefix"] = "";
    //defaultPresetMap["2_key_counter_min"] = 0;
    //defaultPresetMap["2_key_counter_max"] = 127;
    //defaultPresetMap["2_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key2_modline1_enable"] = 0;
    //defaultPresetMap["key2_modline1_initvalue"] = 0;
    //defaultPresetMap["key2_modline1_initmode"] = "None";
    defaultPresetMap["key2_modline1_source"] = "None";
    defaultPresetMap["key2_modline1_gain"] = 1.00;
    defaultPresetMap["key2_modline1_offset"] = 0;
    defaultPresetMap["key2_modline1_table"] = "Linear";
    defaultPresetMap["key2_modline1_min"] = 0;
    defaultPresetMap["key2_modline1_max"] = 127;
    defaultPresetMap["key2_modline1_slew"] = 0;
    //defaultPresetMap["key2_modline1_delay"] = 0;
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
    defaultPresetMap["key2_modline1_ledgreen"] = "None";
    defaultPresetMap["key2_modline1_ledred"] = "None";
    defaultPresetMap["key2_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key2_modline2_enable"] = 0;
    //defaultPresetMap["key2_modline2_initvalue"] = 0;
    //defaultPresetMap["key2_modline2_initmode"] = "None";
    defaultPresetMap["key2_modline2_source"] = "None";
    defaultPresetMap["key2_modline2_gain"] = 1.00;
    defaultPresetMap["key2_modline2_offset"] = 0;
    defaultPresetMap["key2_modline2_table"] = "Linear";
    defaultPresetMap["key2_modline2_min"] = 0;
    defaultPresetMap["key2_modline2_max"] = 127;
    defaultPresetMap["key2_modline2_slew"] = 0;
    //defaultPresetMap["key2_modline2_delay"] = 0;
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
    defaultPresetMap["key2_modline2_ledgreen"] = "None";
    defaultPresetMap["key2_modline2_ledred"] = "None";
    defaultPresetMap["key2_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key2_modline3_enable"] = 0;
    //defaultPresetMap["key2_modline3_initvalue"] = 0;
    //defaultPresetMap["key2_modline3_initmode"] = "None";
    defaultPresetMap["key2_modline3_source"] = "None";
    defaultPresetMap["key2_modline3_gain"] = 1.00;
    defaultPresetMap["key2_modline3_offset"] = 0;
    defaultPresetMap["key2_modline3_table"] = "Linear";
    defaultPresetMap["key2_modline3_min"] = 0;
    defaultPresetMap["key2_modline3_max"] = 127;
    defaultPresetMap["key2_modline3_slew"] = 0;
    //defaultPresetMap["key2_modline3_delay"] = 0;
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
    defaultPresetMap["key2_modline3_ledgreen"] = "None";
    defaultPresetMap["key2_modline3_ledred"] = "None";
    defaultPresetMap["key2_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key2_modline4_enable"] = 0;
    //defaultPresetMap["key2_modline4_initvalue"] = 0;
    //defaultPresetMap["key2_modline4_initmode"] = "None";
    defaultPresetMap["key2_modline4_source"] = "None";
    defaultPresetMap["key2_modline4_gain"] = 1.00;
    defaultPresetMap["key2_modline4_offset"] = 0;
    defaultPresetMap["key2_modline4_table"] = "Linear";
    defaultPresetMap["key2_modline4_min"] = 0;
    defaultPresetMap["key2_modline4_max"] = 127;
    defaultPresetMap["key2_modline4_slew"] = 0;
    //defaultPresetMap["key2_modline4_delay"] = 0;
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
    defaultPresetMap["key2_modline4_ledgreen"] = "None";
    defaultPresetMap["key2_modline4_ledred"] = "None";
    defaultPresetMap["key2_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key2_modline5_enable"] = 0;
    //defaultPresetMap["key2_modline5_initvalue"] = 0;
    //defaultPresetMap["key2_modline5_initmode"] = "None";
    defaultPresetMap["key2_modline5_source"] = "None";
    defaultPresetMap["key2_modline5_gain"] = 1.00;
    defaultPresetMap["key2_modline5_offset"] = 0;
    defaultPresetMap["key2_modline5_table"] = "Linear";
    defaultPresetMap["key2_modline5_min"] = 0;
    defaultPresetMap["key2_modline5_max"] = 127;
    defaultPresetMap["key2_modline5_slew"] = 0;
    //defaultPresetMap["key2_modline5_delay"] = 0;
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
    defaultPresetMap["key2_modline5_ledgreen"] = "None";
    defaultPresetMap["key2_modline5_ledred"] = "None";
    defaultPresetMap["key2_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key2_modline6_enable"] = 0;
    //defaultPresetMap["key2_modline6_initvalue"] = 0;
    //defaultPresetMap["key2_modline6_initmode"] = "None";
    defaultPresetMap["key2_modline6_source"] = "None";
    defaultPresetMap["key2_modline6_gain"] = 1.00;
    defaultPresetMap["key2_modline6_offset"] = 0;
    defaultPresetMap["key2_modline6_table"] = "Linear";
    defaultPresetMap["key2_modline6_min"] = 0;
    defaultPresetMap["key2_modline6_max"] = 127;
    defaultPresetMap["key2_modline6_slew"] = 0;
    //defaultPresetMap["key2_modline6_delay"] = 0;
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
    defaultPresetMap["key2_modline6_ledgreen"] = "None";
    defaultPresetMap["key2_modline6_ledred"] = "None";
    defaultPresetMap["key2_modline6_displaylinked"] = 0;


    //------------------------ Key 3 ------------------------//
    defaultPresetMap["3_key_name"] = "3KEY";
    defaultPresetMap["3_key_displaymode"] = "None";
    defaultPresetMap["3_key_prefix"] = "";
    //defaultPresetMap["3_key_counter_min"] = 0;
    //defaultPresetMap["3_key_counter_max"] = 127;
    //defaultPresetMap["3_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key3_modline1_enable"] = 0;
    //defaultPresetMap["key3_modline1_initvalue"] = 0;
    //defaultPresetMap["key3_modline1_initmode"] = "None";
    defaultPresetMap["key3_modline1_source"] = "None";
    defaultPresetMap["key3_modline1_gain"] = 1.00;
    defaultPresetMap["key3_modline1_offset"] = 0;
    defaultPresetMap["key3_modline1_table"] = "Linear";
    defaultPresetMap["key3_modline1_min"] = 0;
    defaultPresetMap["key3_modline1_max"] = 127;
    defaultPresetMap["key3_modline1_slew"] = 0;
    //defaultPresetMap["key3_modline1_delay"] = 0;
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
    defaultPresetMap["key3_modline1_ledgreen"] = "None";
    defaultPresetMap["key3_modline1_ledred"] = "None";
    defaultPresetMap["key3_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key3_modline2_enable"] = 0;
    //defaultPresetMap["key3_modline2_initvalue"] = 0;
    //defaultPresetMap["key3_modline2_initmode"] = "None";
    defaultPresetMap["key3_modline2_source"] = "None";
    defaultPresetMap["key3_modline2_gain"] = 1.00;
    defaultPresetMap["key3_modline2_offset"] = 0;
    defaultPresetMap["key3_modline2_table"] = "Linear";
    defaultPresetMap["key3_modline2_min"] = 0;
    defaultPresetMap["key3_modline2_max"] = 127;
    defaultPresetMap["key3_modline2_slew"] = 0;
    //defaultPresetMap["key3_modline2_delay"] = 0;
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
    defaultPresetMap["key3_modline2_ledgreen"] = "None";
    defaultPresetMap["key3_modline2_ledred"] = "None";
    defaultPresetMap["key3_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key3_modline3_enable"] = 0;
    //defaultPresetMap["key3_modline3_initvalue"] = 0;
    //defaultPresetMap["key3_modline3_initmode"] = "None";
    defaultPresetMap["key3_modline3_source"] = "None";
    defaultPresetMap["key3_modline3_gain"] = 1.00;
    defaultPresetMap["key3_modline3_offset"] = 0;
    defaultPresetMap["key3_modline3_table"] = "Linear";
    defaultPresetMap["key3_modline3_min"] = 0;
    defaultPresetMap["key3_modline3_max"] = 127;
    defaultPresetMap["key3_modline3_slew"] = 0;
    //defaultPresetMap["key3_modline3_delay"] = 0;
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
    defaultPresetMap["key3_modline3_ledgreen"] = "None";
    defaultPresetMap["key3_modline3_ledred"] = "None";
    defaultPresetMap["key3_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key3_modline4_enable"] = 0;
    //defaultPresetMap["key3_modline4_initvalue"] = 0;
    //defaultPresetMap["key3_modline4_initmode"] = "None";
    defaultPresetMap["key3_modline4_source"] = "None";
    defaultPresetMap["key3_modline4_gain"] = 1.00;
    defaultPresetMap["key3_modline4_offset"] = 0;
    defaultPresetMap["key3_modline4_table"] = "Linear";
    defaultPresetMap["key3_modline4_min"] = 0;
    defaultPresetMap["key3_modline4_max"] = 127;
    defaultPresetMap["key3_modline4_slew"] = 0;
    //defaultPresetMap["key3_modline4_delay"] = 0;
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
    defaultPresetMap["key3_modline4_ledgreen"] = "None";
    defaultPresetMap["key3_modline4_ledred"] = "None";
    defaultPresetMap["key3_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key3_modline5_enable"] = 0;
    //defaultPresetMap["key3_modline5_initvalue"] = 0;
    //defaultPresetMap["key3_modline5_initmode"] = "None";
    defaultPresetMap["key3_modline5_source"] = "None";
    defaultPresetMap["key3_modline5_gain"] = 1.00;
    defaultPresetMap["key3_modline5_offset"] = 0;
    defaultPresetMap["key3_modline5_table"] = "Linear";
    defaultPresetMap["key3_modline5_min"] = 0;
    defaultPresetMap["key3_modline5_max"] = 127;
    defaultPresetMap["key3_modline5_slew"] = 0;
    //defaultPresetMap["key3_modline5_delay"] = 0;
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
    defaultPresetMap["key3_modline5_ledgreen"] = "None";
    defaultPresetMap["key3_modline5_ledred"] = "None";
    defaultPresetMap["key3_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key3_modline6_enable"] = 0;
    //defaultPresetMap["key3_modline6_initvalue"] = 0;
    //defaultPresetMap["key3_modline6_initmode"] = "None";
    defaultPresetMap["key3_modline6_source"] = "None";
    defaultPresetMap["key3_modline6_gain"] = 1.00;
    defaultPresetMap["key3_modline6_offset"] = 0;
    defaultPresetMap["key3_modline6_table"] = "Linear";
    defaultPresetMap["key3_modline6_min"] = 0;
    defaultPresetMap["key3_modline6_max"] = 127;
    defaultPresetMap["key3_modline6_slew"] = 0;
    //defaultPresetMap["key3_modline6_delay"] = 0;
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
    defaultPresetMap["key3_modline6_ledgreen"] = "None";
    defaultPresetMap["key3_modline6_ledred"] = "None";
    defaultPresetMap["key3_modline6_displaylinked"] = 0;


    //------------------------ Key 4 ------------------------//
    defaultPresetMap["4_key_name"] = "4KEY";
    defaultPresetMap["4_key_displaymode"] = "None";
    defaultPresetMap["4_key_prefix"] = "";
    //defaultPresetMap["4_key_counter_min"] = 0;
    //defaultPresetMap["4_key_counter_max"] = 127;
    //defaultPresetMap["4_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key4_modline1_enable"] = 0;
    //defaultPresetMap["key4_modline1_initvalue"] = 0;
    //defaultPresetMap["key4_modline1_initmode"] = "None";
    defaultPresetMap["key4_modline1_source"] = "None";
    defaultPresetMap["key4_modline1_gain"] = 1.00;
    defaultPresetMap["key4_modline1_offset"] = 0;
    defaultPresetMap["key4_modline1_table"] = "Linear";
    defaultPresetMap["key4_modline1_min"] = 0;
    defaultPresetMap["key4_modline1_max"] = 127;
    defaultPresetMap["key4_modline1_slew"] = 0;
    //defaultPresetMap["key4_modline1_delay"] = 0;
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
    defaultPresetMap["key4_modline1_ledgreen"] = "None";
    defaultPresetMap["key4_modline1_ledred"] = "None";
    defaultPresetMap["key4_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key4_modline2_enable"] = 0;
    //defaultPresetMap["key4_modline2_initvalue"] = 0;
    //defaultPresetMap["key4_modline2_initmode"] = "None";
    defaultPresetMap["key4_modline2_source"] = "None";
    defaultPresetMap["key4_modline2_gain"] = 1.00;
    defaultPresetMap["key4_modline2_offset"] = 0;
    defaultPresetMap["key4_modline2_table"] = "Linear";
    defaultPresetMap["key4_modline2_min"] = 0;
    defaultPresetMap["key4_modline2_max"] = 127;
    defaultPresetMap["key4_modline2_slew"] = 0;
    //defaultPresetMap["key4_modline2_delay"] = 0;
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
    defaultPresetMap["key4_modline2_ledgreen"] = "None";
    defaultPresetMap["key4_modline2_ledred"] = "None";
    defaultPresetMap["key4_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key4_modline3_enable"] = 0;
    //defaultPresetMap["key4_modline3_initvalue"] = 0;
    //defaultPresetMap["key4_modline3_initmode"] = "None";
    defaultPresetMap["key4_modline3_source"] = "None";
    defaultPresetMap["key4_modline3_gain"] = 1.00;
    defaultPresetMap["key4_modline3_offset"] = 0;
    defaultPresetMap["key4_modline3_table"] = "Linear";
    defaultPresetMap["key4_modline3_min"] = 0;
    defaultPresetMap["key4_modline3_max"] = 127;
    defaultPresetMap["key4_modline3_slew"] = 0;
    //defaultPresetMap["key4_modline3_delay"] = 0;
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
    defaultPresetMap["key4_modline3_ledgreen"] = "None";
    defaultPresetMap["key4_modline3_ledred"] = "None";
    defaultPresetMap["key4_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key4_modline4_enable"] = 0;
    //defaultPresetMap["key4_modline4_initvalue"] = 0;
    //defaultPresetMap["key4_modline4_initmode"] = "None";
    defaultPresetMap["key4_modline4_source"] = "None";
    defaultPresetMap["key4_modline4_gain"] = 1.00;
    defaultPresetMap["key4_modline4_offset"] = 0;
    defaultPresetMap["key4_modline4_table"] = "Linear";
    defaultPresetMap["key4_modline4_min"] = 0;
    defaultPresetMap["key4_modline4_max"] = 127;
    defaultPresetMap["key4_modline4_slew"] = 0;
    //defaultPresetMap["key4_modline4_delay"] = 0;
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
    defaultPresetMap["key4_modline4_ledgreen"] = "None";
    defaultPresetMap["key4_modline4_ledred"] = "None";
    defaultPresetMap["key4_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key4_modline5_enable"] = 0;
    //defaultPresetMap["key4_modline5_initvalue"] = 0;
    //defaultPresetMap["key4_modline5_initmode"] = "None";
    defaultPresetMap["key4_modline5_source"] = "None";
    defaultPresetMap["key4_modline5_gain"] = 1.00;
    defaultPresetMap["key4_modline5_offset"] = 0;
    defaultPresetMap["key4_modline5_table"] = "Linear";
    defaultPresetMap["key4_modline5_min"] = 0;
    defaultPresetMap["key4_modline5_max"] = 127;
    defaultPresetMap["key4_modline5_slew"] = 0;
    //defaultPresetMap["key4_modline5_delay"] = 0;
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
    defaultPresetMap["key4_modline5_ledgreen"] = "None";
    defaultPresetMap["key4_modline5_ledred"] = "None";
    defaultPresetMap["key4_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key4_modline6_enable"] = 0;
    //defaultPresetMap["key4_modline6_initvalue"] = 0;
    //defaultPresetMap["key4_modline6_initmode"] = "None";
    defaultPresetMap["key4_modline6_source"] = "None";
    defaultPresetMap["key4_modline6_gain"] = 1.00;
    defaultPresetMap["key4_modline6_offset"] = 0;
    defaultPresetMap["key4_modline6_table"] = "Linear";
    defaultPresetMap["key4_modline6_min"] = 0;
    defaultPresetMap["key4_modline6_max"] = 127;
    defaultPresetMap["key4_modline6_slew"] = 0;
    //defaultPresetMap["key4_modline6_delay"] = 0;
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
    defaultPresetMap["key4_modline6_ledgreen"] = "None";
    defaultPresetMap["key4_modline6_ledred"] = "None";
    defaultPresetMap["key4_modline6_displaylinked"] = 0;

    //------------------------ Key 5 ------------------------//
    defaultPresetMap["5_key_name"] = "5KEY";
    defaultPresetMap["5_key_displaymode"] = "None";
    defaultPresetMap["5_key_prefix"] = "";
    //defaultPresetMap["5_key_counter_min"] = 0;
    //defaultPresetMap["5_key_counter_max"] = 127;
    //defaultPresetMap["5_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key5_modline1_enable"] = 0;
    //defaultPresetMap["key5_modline1_initvalue"] = 0;
    //defaultPresetMap["key5_modline1_initmode"] = "None";
    defaultPresetMap["key5_modline1_source"] = "None";
    defaultPresetMap["key5_modline1_gain"] = 1.00;
    defaultPresetMap["key5_modline1_offset"] = 0;
    defaultPresetMap["key5_modline1_table"] = "Linear";
    defaultPresetMap["key5_modline1_min"] = 0;
    defaultPresetMap["key5_modline1_max"] = 127;
    defaultPresetMap["key5_modline1_slew"] = 0;
    //defaultPresetMap["key5_modline1_delay"] = 0;
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
    defaultPresetMap["key5_modline1_ledgreen"] = "None";
    defaultPresetMap["key5_modline1_ledred"] = "None";
    defaultPresetMap["key5_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key5_modline2_enable"] = 0;
    //defaultPresetMap["key5_modline2_initvalue"] = 0;
    //defaultPresetMap["key5_modline2_initmode"] = "None";
    defaultPresetMap["key5_modline2_source"] = "None";
    defaultPresetMap["key5_modline2_gain"] = 1.00;
    defaultPresetMap["key5_modline2_offset"] = 0;
    defaultPresetMap["key5_modline2_table"] = "Linear";
    defaultPresetMap["key5_modline2_min"] = 0;
    defaultPresetMap["key5_modline2_max"] = 127;
    defaultPresetMap["key5_modline2_slew"] = 0;
    //defaultPresetMap["key5_modline2_delay"] = 0;
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
    defaultPresetMap["key5_modline2_ledgreen"] = "None";
    defaultPresetMap["key5_modline2_ledred"] = "None";
    defaultPresetMap["key5_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key5_modline3_enable"] = 0;
    //defaultPresetMap["key5_modline3_initvalue"] = 0;
    //defaultPresetMap["key5_modline3_initmode"] = "None";
    defaultPresetMap["key5_modline3_source"] = "None";
    defaultPresetMap["key5_modline3_gain"] = 1.00;
    defaultPresetMap["key5_modline3_offset"] = 0;
    defaultPresetMap["key5_modline3_table"] = "Linear";
    defaultPresetMap["key5_modline3_min"] = 0;
    defaultPresetMap["key5_modline3_max"] = 127;
    defaultPresetMap["key5_modline3_slew"] = 0;
    //defaultPresetMap["key5_modline3_delay"] = 0;
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
    defaultPresetMap["key5_modline3_ledgreen"] = "None";
    defaultPresetMap["key5_modline3_ledred"] = "None";
    defaultPresetMap["key5_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key5_modline4_enable"] = 0;
    //defaultPresetMap["key5_modline4_initvalue"] = 0;
    //defaultPresetMap["key5_modline4_initmode"] = "None";
    defaultPresetMap["key5_modline4_source"] = "None";
    defaultPresetMap["key5_modline4_gain"] = 1.00;
    defaultPresetMap["key5_modline4_offset"] = 0;
    defaultPresetMap["key5_modline4_table"] = "Linear";
    defaultPresetMap["key5_modline4_min"] = 0;
    defaultPresetMap["key5_modline4_max"] = 127;
    defaultPresetMap["key5_modline4_slew"] = 0;
    //defaultPresetMap["key5_modline4_delay"] = 0;
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
    defaultPresetMap["key5_modline4_ledgreen"] = "None";
    defaultPresetMap["key5_modline4_ledred"] = "None";
    defaultPresetMap["key5_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key5_modline5_enable"] = 0;
    //defaultPresetMap["key5_modline5_initvalue"] = 0;
    //defaultPresetMap["key5_modline5_initmode"] = "None";
    defaultPresetMap["key5_modline5_source"] = "None";
    defaultPresetMap["key5_modline5_gain"] = 1.00;
    defaultPresetMap["key5_modline5_offset"] = 0;
    defaultPresetMap["key5_modline5_table"] = "Linear";
    defaultPresetMap["key5_modline5_min"] = 0;
    defaultPresetMap["key5_modline5_max"] = 127;
    defaultPresetMap["key5_modline5_slew"] = 0;
    //defaultPresetMap["key5_modline5_delay"] = 0;
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
    defaultPresetMap["key5_modline5_ledgreen"] = "None";
    defaultPresetMap["key5_modline5_ledred"] = "None";
    defaultPresetMap["key5_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key5_modline6_enable"] = 0;
    //defaultPresetMap["key5_modline6_initvalue"] = 0;
    //defaultPresetMap["key5_modline6_initmode"] = "None";
    defaultPresetMap["key5_modline6_source"] = "None";
    defaultPresetMap["key5_modline6_gain"] = 1.00;
    defaultPresetMap["key5_modline6_offset"] = 0;
    defaultPresetMap["key5_modline6_table"] = "Linear";
    defaultPresetMap["key5_modline6_min"] = 0;
    defaultPresetMap["key5_modline6_max"] = 127;
    defaultPresetMap["key5_modline6_slew"] = 0;
    //defaultPresetMap["key5_modline6_delay"] = 0;
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
    defaultPresetMap["key5_modline6_ledgreen"] = "None";
    defaultPresetMap["key5_modline6_ledred"] = "None";
    defaultPresetMap["key5_modline6_displaylinked"] = 0;


    //------------------------ Key 6 ------------------------//
    defaultPresetMap["6_key_name"] = "6KEY";
    defaultPresetMap["6_key_displaymode"] = "None";
    defaultPresetMap["6_key_prefix"] = "";
    //defaultPresetMap["6_key_counter_min"] = 0;
    //defaultPresetMap["6_key_counter_max"] = 127;
    //defaultPresetMap["6_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key6_modline1_enable"] = 0;
    //defaultPresetMap["key6_modline1_initvalue"] = 0;
    //defaultPresetMap["key6_modline1_initmode"] = "None";
    defaultPresetMap["key6_modline1_source"] = "None";
    defaultPresetMap["key6_modline1_gain"] = 1.00;
    defaultPresetMap["key6_modline1_offset"] = 0;
    defaultPresetMap["key6_modline1_table"] = "Linear";
    defaultPresetMap["key6_modline1_min"] = 0;
    defaultPresetMap["key6_modline1_max"] = 127;
    defaultPresetMap["key6_modline1_slew"] = 0;
    //defaultPresetMap["key6_modline1_delay"] = 0;
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
    defaultPresetMap["key6_modline1_ledgreen"] = "None";
    defaultPresetMap["key6_modline1_ledred"] = "None";
    defaultPresetMap["key6_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key6_modline2_enable"] = 0;
    //defaultPresetMap["key6_modline2_initvalue"] = 0;
    //defaultPresetMap["key6_modline2_initmode"] = "None";
    defaultPresetMap["key6_modline2_source"] = "None";
    defaultPresetMap["key6_modline2_gain"] = 1.00;
    defaultPresetMap["key6_modline2_offset"] = 0;
    defaultPresetMap["key6_modline2_table"] = "Linear";
    defaultPresetMap["key6_modline2_min"] = 0;
    defaultPresetMap["key6_modline2_max"] = 127;
    defaultPresetMap["key6_modline2_slew"] = 0;
    //defaultPresetMap["key6_modline2_delay"] = 0;
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
    defaultPresetMap["key6_modline2_ledgreen"] = "None";
    defaultPresetMap["key6_modline2_ledred"] = "None";
    defaultPresetMap["key6_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key6_modline3_enable"] = 0;
    //defaultPresetMap["key6_modline3_initvalue"] = 0;
    //defaultPresetMap["key6_modline3_initmode"] = "None";
    defaultPresetMap["key6_modline3_source"] = "None";
    defaultPresetMap["key6_modline3_gain"] = 1.00;
    defaultPresetMap["key6_modline3_offset"] = 0;
    defaultPresetMap["key6_modline3_table"] = "Linear";
    defaultPresetMap["key6_modline3_min"] = 0;
    defaultPresetMap["key6_modline3_max"] = 127;
    defaultPresetMap["key6_modline3_slew"] = 0;
    //defaultPresetMap["key6_modline3_delay"] = 0;
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
    defaultPresetMap["key6_modline3_ledgreen"] = "None";
    defaultPresetMap["key6_modline3_ledred"] = "None";
    defaultPresetMap["key6_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key6_modline4_enable"] = 0;
    //defaultPresetMap["key6_modline4_initvalue"] = 0;
    //defaultPresetMap["key6_modline4_initmode"] = "None";
    defaultPresetMap["key6_modline4_source"] = "None";
    defaultPresetMap["key6_modline4_gain"] = 1.00;
    defaultPresetMap["key6_modline4_offset"] = 0;
    defaultPresetMap["key6_modline4_table"] = "Linear";
    defaultPresetMap["key6_modline4_min"] = 0;
    defaultPresetMap["key6_modline4_max"] = 127;
    defaultPresetMap["key6_modline4_slew"] = 0;
    //defaultPresetMap["key6_modline4_delay"] = 0;
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
    defaultPresetMap["key6_modline4_ledgreen"] = "None";
    defaultPresetMap["key6_modline4_ledred"] = "None";
    defaultPresetMap["key6_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key6_modline5_enable"] = 0;
    //defaultPresetMap["key6_modline5_initvalue"] = 0;
    //defaultPresetMap["key6_modline5_initmode"] = "None";
    defaultPresetMap["key6_modline5_source"] = "None";
    defaultPresetMap["key6_modline5_gain"] = 1.00;
    defaultPresetMap["key6_modline5_offset"] = 0;
    defaultPresetMap["key6_modline5_table"] = "Linear";
    defaultPresetMap["key6_modline5_min"] = 0;
    defaultPresetMap["key6_modline5_max"] = 127;
    defaultPresetMap["key6_modline5_slew"] = 0;
    //defaultPresetMap["key6_modline5_delay"] = 0;
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
    defaultPresetMap["key6_modline5_ledgreen"] = "None";
    defaultPresetMap["key6_modline5_ledred"] = "None";
    defaultPresetMap["key6_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key6_modline6_enable"] = 0;
    //defaultPresetMap["key6_modline6_initvalue"] = 0;
    //defaultPresetMap["key6_modline6_initmode"] = "None";
    defaultPresetMap["key6_modline6_source"] = "None";
    defaultPresetMap["key6_modline6_gain"] = 1.00;
    defaultPresetMap["key6_modline6_offset"] = 0;
    defaultPresetMap["key6_modline6_table"] = "Linear";
    defaultPresetMap["key6_modline6_min"] = 0;
    defaultPresetMap["key6_modline6_max"] = 127;
    defaultPresetMap["key6_modline6_slew"] = 0;
    //defaultPresetMap["key6_modline6_delay"] = 0;
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
    defaultPresetMap["key6_modline6_ledgreen"] = "None";
    defaultPresetMap["key6_modline6_ledred"] = "None";
    defaultPresetMap["key6_modline6_displaylinked"] = 0;


    //------------------------ Key 7 ------------------------//
    defaultPresetMap["7_key_name"] = "7KEY";
    defaultPresetMap["7_key_displaymode"] = "None";
    defaultPresetMap["7_key_prefix"] = "";
    //defaultPresetMap["7_key_counter_min"] = 0;
    //defaultPresetMap["7_key_counter_max"] = 127;
    //defaultPresetMap["7_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key7_modline1_enable"] = 0;
    //defaultPresetMap["key7_modline1_initvalue"] = 0;
    //defaultPresetMap["key7_modline1_initmode"] = "None";
    defaultPresetMap["key7_modline1_source"] = "None";
    defaultPresetMap["key7_modline1_gain"] = 1.00;
    defaultPresetMap["key7_modline1_offset"] = 0;
    defaultPresetMap["key7_modline1_table"] = "Linear";
    defaultPresetMap["key7_modline1_min"] = 0;
    defaultPresetMap["key7_modline1_max"] = 127;
    defaultPresetMap["key7_modline1_slew"] = 0;
    //defaultPresetMap["key7_modline1_delay"] = 0;
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
    defaultPresetMap["key7_modline1_ledgreen"] = "None";
    defaultPresetMap["key7_modline1_ledred"] = "None";
    defaultPresetMap["key7_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key7_modline2_enable"] = 0;
    //defaultPresetMap["key7_modline2_initvalue"] = 0;
    //defaultPresetMap["key7_modline2_initmode"] = "None";
    defaultPresetMap["key7_modline2_source"] = "None";
    defaultPresetMap["key7_modline2_gain"] = 1.00;
    defaultPresetMap["key7_modline2_offset"] = 0;
    defaultPresetMap["key7_modline2_table"] = "Linear";
    defaultPresetMap["key7_modline2_min"] = 0;
    defaultPresetMap["key7_modline2_max"] = 127;
    defaultPresetMap["key7_modline2_slew"] = 0;
    //defaultPresetMap["key7_modline2_delay"] = 0;
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
    defaultPresetMap["key7_modline2_ledgreen"] = "None";
    defaultPresetMap["key7_modline2_ledred"] = "None";
    defaultPresetMap["key7_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key7_modline3_enable"] = 0;
    //defaultPresetMap["key7_modline3_initvalue"] = 0;
    //defaultPresetMap["key7_modline3_initmode"] = "None";
    defaultPresetMap["key7_modline3_source"] = "None";
    defaultPresetMap["key7_modline3_gain"] = 1.00;
    defaultPresetMap["key7_modline3_offset"] = 0;
    defaultPresetMap["key7_modline3_table"] = "Linear";
    defaultPresetMap["key7_modline3_min"] = 0;
    defaultPresetMap["key7_modline3_max"] = 127;
    defaultPresetMap["key7_modline3_slew"] = 0;
    //defaultPresetMap["key7_modline3_delay"] = 0;
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
    defaultPresetMap["key7_modline3_ledgreen"] = "None";
    defaultPresetMap["key7_modline3_ledred"] = "None";
    defaultPresetMap["key7_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key7_modline4_enable"] = 0;
    //defaultPresetMap["key7_modline4_initvalue"] = 0;
    //defaultPresetMap["key7_modline4_initmode"] = "None";
    defaultPresetMap["key7_modline4_source"] = "None";
    defaultPresetMap["key7_modline4_gain"] = 1.00;
    defaultPresetMap["key7_modline4_offset"] = 0;
    defaultPresetMap["key7_modline4_table"] = "Linear";
    defaultPresetMap["key7_modline4_min"] = 0;
    defaultPresetMap["key7_modline4_max"] = 127;
    defaultPresetMap["key7_modline4_slew"] = 0;
    //defaultPresetMap["key7_modline4_delay"] = 0;
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
    defaultPresetMap["key7_modline4_ledgreen"] = "None";
    defaultPresetMap["key7_modline4_ledred"] = "None";
    defaultPresetMap["key7_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key7_modline5_enable"] = 0;
    //defaultPresetMap["key7_modline5_initvalue"] = 0;
    //defaultPresetMap["key7_modline5_initmode"] = "None";
    defaultPresetMap["key7_modline5_source"] = "None";
    defaultPresetMap["key7_modline5_gain"] = 1.00;
    defaultPresetMap["key7_modline5_offset"] = 0;
    defaultPresetMap["key7_modline5_table"] = "Linear";
    defaultPresetMap["key7_modline5_min"] = 0;
    defaultPresetMap["key7_modline5_max"] = 127;
    defaultPresetMap["key7_modline5_slew"] = 0;
    //defaultPresetMap["key7_modline5_delay"] = 0;
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
    defaultPresetMap["key7_modline5_ledgreen"] = "None";
    defaultPresetMap["key7_modline5_ledred"] = "None";
    defaultPresetMap["key7_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key7_modline6_enable"] = 0;
    //defaultPresetMap["key7_modline6_initvalue"] = 0;
    //defaultPresetMap["key7_modline6_initmode"] = "None";
    defaultPresetMap["key7_modline6_source"] = "None";
    defaultPresetMap["key7_modline6_gain"] = 1.00;
    defaultPresetMap["key7_modline6_offset"] = 0;
    defaultPresetMap["key7_modline6_table"] = "Linear";
    defaultPresetMap["key7_modline6_min"] = 0;
    defaultPresetMap["key7_modline6_max"] = 127;
    defaultPresetMap["key7_modline6_slew"] = 0;
    //defaultPresetMap["key7_modline6_delay"] = 0;
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
    defaultPresetMap["key7_modline6_ledgreen"] = "None";
    defaultPresetMap["key7_modline6_ledred"] = "None";
    defaultPresetMap["key7_modline6_displaylinked"] = 0;

    //------------------------ Key 8 ------------------------//
    defaultPresetMap["8_key_name"] = "8KEY";
    defaultPresetMap["8_key_displaymode"] = "None";
    defaultPresetMap["8_key_prefix"] = "";
    //defaultPresetMap["8_key_counter_min"] = 0;
    //defaultPresetMap["8_key_counter_max"] = 127;
    //defaultPresetMap["8_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key8_modline1_enable"] = 0;
    //defaultPresetMap["key8_modline1_initvalue"] = 0;
    //defaultPresetMap["key8_modline1_initmode"] = "None";
    defaultPresetMap["key8_modline1_source"] = "None";
    defaultPresetMap["key8_modline1_gain"] = 1.00;
    defaultPresetMap["key8_modline1_offset"] = 0;
    defaultPresetMap["key8_modline1_table"] = "Linear";
    defaultPresetMap["key8_modline1_min"] = 0;
    defaultPresetMap["key8_modline1_max"] = 127;
    defaultPresetMap["key8_modline1_slew"] = 0;
    //defaultPresetMap["key8_modline1_delay"] = 0;
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
    defaultPresetMap["key8_modline1_ledgreen"] = "None";
    defaultPresetMap["key8_modline1_ledred"] = "None";
    defaultPresetMap["key8_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key8_modline2_enable"] = 0;
    //defaultPresetMap["key8_modline2_initvalue"] = 0;
    //defaultPresetMap["key8_modline2_initmode"] = "None";
    defaultPresetMap["key8_modline2_source"] = "None";
    defaultPresetMap["key8_modline2_gain"] = 1.00;
    defaultPresetMap["key8_modline2_offset"] = 0;
    defaultPresetMap["key8_modline2_table"] = "Linear";
    defaultPresetMap["key8_modline2_min"] = 0;
    defaultPresetMap["key8_modline2_max"] = 127;
    defaultPresetMap["key8_modline2_slew"] = 0;
    //defaultPresetMap["key8_modline2_delay"] = 0;
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
    defaultPresetMap["key8_modline2_ledgreen"] = "None";
    defaultPresetMap["key8_modline2_ledred"] = "None";
    defaultPresetMap["key8_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key8_modline3_enable"] = 0;
    //defaultPresetMap["key8_modline3_initvalue"] = 0;
    //defaultPresetMap["key8_modline3_initmode"] = "None";
    defaultPresetMap["key8_modline3_source"] = "None";
    defaultPresetMap["key8_modline3_gain"] = 1.00;
    defaultPresetMap["key8_modline3_offset"] = 0;
    defaultPresetMap["key8_modline3_table"] = "Linear";
    defaultPresetMap["key8_modline3_min"] = 0;
    defaultPresetMap["key8_modline3_max"] = 127;
    defaultPresetMap["key8_modline3_slew"] = 0;
    //defaultPresetMap["key8_modline3_delay"] = 0;
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
    defaultPresetMap["key8_modline3_ledgreen"] = "None";
    defaultPresetMap["key8_modline3_ledred"] = "None";
    defaultPresetMap["key8_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key8_modline4_enable"] = 0;
    //defaultPresetMap["key8_modline4_initvalue"] = 0;
    //defaultPresetMap["key8_modline4_initmode"] = "None";
    defaultPresetMap["key8_modline4_source"] = "None";
    defaultPresetMap["key8_modline4_gain"] = 1.00;
    defaultPresetMap["key8_modline4_offset"] = 0;
    defaultPresetMap["key8_modline4_table"] = "Linear";
    defaultPresetMap["key8_modline4_min"] = 0;
    defaultPresetMap["key8_modline4_max"] = 127;
    defaultPresetMap["key8_modline4_slew"] = 0;
    //defaultPresetMap["key8_modline4_delay"] = 0;
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
    defaultPresetMap["key8_modline4_ledgreen"] = "None";
    defaultPresetMap["key8_modline4_ledred"] = "None";
    defaultPresetMap["key8_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key8_modline5_enable"] = 0;
    //defaultPresetMap["key8_modline5_initvalue"] = 0;
    //defaultPresetMap["key8_modline5_initmode"] = "None";
    defaultPresetMap["key8_modline5_source"] = "None";
    defaultPresetMap["key8_modline5_gain"] = 1.00;
    defaultPresetMap["key8_modline5_offset"] = 0;
    defaultPresetMap["key8_modline5_table"] = "Linear";
    defaultPresetMap["key8_modline5_min"] = 0;
    defaultPresetMap["key8_modline5_max"] = 127;
    defaultPresetMap["key8_modline5_slew"] = 0;
    //defaultPresetMap["key8_modline5_delay"] = 0;
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
    defaultPresetMap["key8_modline5_ledgreen"] = "None";
    defaultPresetMap["key8_modline5_ledred"] = "None";
    defaultPresetMap["key8_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key8_modline6_enable"] = 0;
    //defaultPresetMap["key8_modline6_initvalue"] = 0;
    //defaultPresetMap["key8_modline6_initmode"] = "None";
    defaultPresetMap["key8_modline6_source"] = "None";
    defaultPresetMap["key8_modline6_gain"] = 1.00;
    defaultPresetMap["key8_modline6_offset"] = 0;
    defaultPresetMap["key8_modline6_table"] = "Linear";
    defaultPresetMap["key8_modline6_min"] = 0;
    defaultPresetMap["key8_modline6_max"] = 127;
    defaultPresetMap["key8_modline6_slew"] = 0;
    //defaultPresetMap["key8_modline6_delay"] = 0;
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
    defaultPresetMap["key8_modline6_ledgreen"] = "None";
    defaultPresetMap["key8_modline6_ledred"] = "None";
    defaultPresetMap["key8_modline6_displaylinked"] = 0;


    //------------------------ Key 9 ------------------------//
    defaultPresetMap["9_key_name"] = "9KEY";
    defaultPresetMap["9_key_displaymode"] = "None";
    defaultPresetMap["9_key_prefix"] = "";
    //defaultPresetMap["9_key_counter_min"] = 0;
    //defaultPresetMap["9_key_counter_max"] = 127;
    //defaultPresetMap["9_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key9_modline1_enable"] = 0;
    //defaultPresetMap["key9_modline1_initvalue"] = 0;
    //defaultPresetMap["key9_modline1_initmode"] = "None";
    defaultPresetMap["key9_modline1_source"] = "None";
    defaultPresetMap["key9_modline1_gain"] = 1.00;
    defaultPresetMap["key9_modline1_offset"] = 0;
    defaultPresetMap["key9_modline1_table"] = "Linear";
    defaultPresetMap["key9_modline1_min"] = 0;
    defaultPresetMap["key9_modline1_max"] = 127;
    defaultPresetMap["key9_modline1_slew"] = 0;
    //defaultPresetMap["key9_modline1_delay"] = 0;
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
    defaultPresetMap["key9_modline1_ledgreen"] = "None";
    defaultPresetMap["key9_modline1_ledred"] = "None";
    defaultPresetMap["key9_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key9_modline2_enable"] = 0;
    //defaultPresetMap["key9_modline2_initvalue"] = 0;
    //defaultPresetMap["key9_modline2_initmode"] = "None";
    defaultPresetMap["key9_modline2_source"] = "None";
    defaultPresetMap["key9_modline2_gain"] = 1.00;
    defaultPresetMap["key9_modline2_offset"] = 0;
    defaultPresetMap["key9_modline2_table"] = "Linear";
    defaultPresetMap["key9_modline2_min"] = 0;
    defaultPresetMap["key9_modline2_max"] = 127;
    defaultPresetMap["key9_modline2_slew"] = 0;
    //defaultPresetMap["key9_modline2_delay"] = 0;
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
    defaultPresetMap["key9_modline2_ledgreen"] = "None";
    defaultPresetMap["key9_modline2_ledred"] = "None";
    defaultPresetMap["key9_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key9_modline3_enable"] = 0;
    //defaultPresetMap["key9_modline3_initvalue"] = 0;
    //defaultPresetMap["key9_modline3_initmode"] = "None";
    defaultPresetMap["key9_modline3_source"] = "None";
    defaultPresetMap["key9_modline3_gain"] = 1.00;
    defaultPresetMap["key9_modline3_offset"] = 0;
    defaultPresetMap["key9_modline3_table"] = "Linear";
    defaultPresetMap["key9_modline3_min"] = 0;
    defaultPresetMap["key9_modline3_max"] = 127;
    defaultPresetMap["key9_modline3_slew"] = 0;
    //defaultPresetMap["key9_modline3_delay"] = 0;
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
    defaultPresetMap["key9_modline3_ledgreen"] = "None";
    defaultPresetMap["key9_modline3_ledred"] = "None";
    defaultPresetMap["key9_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key9_modline4_enable"] = 0;
    //defaultPresetMap["key9_modline4_initvalue"] = 0;
    //defaultPresetMap["key9_modline4_initmode"] = "None";
    defaultPresetMap["key9_modline4_source"] = "None";
    defaultPresetMap["key9_modline4_gain"] = 1.00;
    defaultPresetMap["key9_modline4_offset"] = 0;
    defaultPresetMap["key9_modline4_table"] = "Linear";
    defaultPresetMap["key9_modline4_min"] = 0;
    defaultPresetMap["key9_modline4_max"] = 127;
    defaultPresetMap["key9_modline4_slew"] = 0;
    //defaultPresetMap["key9_modline4_delay"] = 0;
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
    defaultPresetMap["key9_modline4_ledgreen"] = "None";
    defaultPresetMap["key9_modline4_ledred"] = "None";
    defaultPresetMap["key9_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key9_modline5_enable"] = 0;
    //defaultPresetMap["key9_modline5_initvalue"] = 0;
    //defaultPresetMap["key9_modline5_initmode"] = "None";
    defaultPresetMap["key9_modline5_source"] = "None";
    defaultPresetMap["key9_modline5_gain"] = 1.00;
    defaultPresetMap["key9_modline5_offset"] = 0;
    defaultPresetMap["key9_modline5_table"] = "Linear";
    defaultPresetMap["key9_modline5_min"] = 0;
    defaultPresetMap["key9_modline5_max"] = 127;
    defaultPresetMap["key9_modline5_slew"] = 0;
    //defaultPresetMap["key9_modline5_delay"] = 0;
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
    defaultPresetMap["key9_modline5_ledgreen"] = "None";
    defaultPresetMap["key9_modline5_ledred"] = "None";
    defaultPresetMap["key9_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key9_modline6_enable"] = 0;
    //defaultPresetMap["key9_modline6_initvalue"] = 0;
    //defaultPresetMap["key9_modline6_initmode"] = "None";
    defaultPresetMap["key9_modline6_source"] = "None";
    defaultPresetMap["key9_modline6_gain"] = 1.00;
    defaultPresetMap["key9_modline6_offset"] = 0;
    defaultPresetMap["key9_modline6_table"] = "Linear";
    defaultPresetMap["key9_modline6_min"] = 0;
    defaultPresetMap["key9_modline6_max"] = 127;
    defaultPresetMap["key9_modline6_slew"] = 0;
    //defaultPresetMap["key9_modline6_delay"] = 0;
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
    defaultPresetMap["key9_modline6_ledgreen"] = "None";
    defaultPresetMap["key9_modline6_ledred"] = "None";
    defaultPresetMap["key9_modline6_displaylinked"] = 0;


    //------------------------ Key 10 ------------------------//
    defaultPresetMap["10_key_name"] = "0KEY";
    defaultPresetMap["10_key_displaymode"] = "None";
    defaultPresetMap["10_key_prefix"] = "";
    //defaultPresetMap["10_key_counter_min"] = 0;
    //defaultPresetMap["10_key_counter_max"] = 127;
    //defaultPresetMap["10_key_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["key10_modline1_enable"] = 0;
    //defaultPresetMap["key10_modline1_initvalue"] = 0;
    //defaultPresetMap["key10_modline1_initmode"] = "None";
    defaultPresetMap["key10_modline1_source"] = "None";
    defaultPresetMap["key10_modline1_gain"] = 1.00;
    defaultPresetMap["key10_modline1_offset"] = 0;
    defaultPresetMap["key10_modline1_table"] = "Linear";
    defaultPresetMap["key10_modline1_min"] = 0;
    defaultPresetMap["key10_modline1_max"] = 127;
    defaultPresetMap["key10_modline1_slew"] = 0;
    //defaultPresetMap["key10_modline1_delay"] = 0;
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
    defaultPresetMap["key10_modline1_ledgreen"] = "None";
    defaultPresetMap["key10_modline1_ledred"] = "None";
    defaultPresetMap["key10_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["key10_modline2_enable"] = 0;
    //defaultPresetMap["key10_modline2_initvalue"] = 0;
    //defaultPresetMap["key10_modline2_initmode"] = "None";
    defaultPresetMap["key10_modline2_source"] = "None";
    defaultPresetMap["key10_modline2_gain"] = 1.00;
    defaultPresetMap["key10_modline2_offset"] = 0;
    defaultPresetMap["key10_modline2_table"] = "Linear";
    defaultPresetMap["key10_modline2_min"] = 0;
    defaultPresetMap["key10_modline2_max"] = 127;
    defaultPresetMap["key10_modline2_slew"] = 0;
    //defaultPresetMap["key10_modline2_delay"] = 0;
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
    defaultPresetMap["key10_modline2_ledgreen"] = "None";
    defaultPresetMap["key10_modline2_ledred"] = "None";
    defaultPresetMap["key10_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["key10_modline3_enable"] = 0;
    //defaultPresetMap["key10_modline3_initvalue"] = 0;
    //defaultPresetMap["key10_modline3_initmode"] = "None";
    defaultPresetMap["key10_modline3_source"] = "None";
    defaultPresetMap["key10_modline3_gain"] = 1.00;
    defaultPresetMap["key10_modline3_offset"] = 0;
    defaultPresetMap["key10_modline3_table"] = "Linear";
    defaultPresetMap["key10_modline3_min"] = 0;
    defaultPresetMap["key10_modline3_max"] = 127;
    defaultPresetMap["key10_modline3_slew"] = 0;
    //defaultPresetMap["key10_modline3_delay"] = 0;
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
    defaultPresetMap["key10_modline3_ledgreen"] = "None";
    defaultPresetMap["key10_modline3_ledred"] = "None";
    defaultPresetMap["key10_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["key10_modline4_enable"] = 0;
    //defaultPresetMap["key10_modline4_initvalue"] = 0;
    //defaultPresetMap["key10_modline4_initmode"] = "None";
    defaultPresetMap["key10_modline4_source"] = "None";
    defaultPresetMap["key10_modline4_gain"] = 1.00;
    defaultPresetMap["key10_modline4_offset"] = 0;
    defaultPresetMap["key10_modline4_table"] = "Linear";
    defaultPresetMap["key10_modline4_min"] = 0;
    defaultPresetMap["key10_modline4_max"] = 127;
    defaultPresetMap["key10_modline4_slew"] = 0;
    //defaultPresetMap["key10_modline4_delay"] = 0;
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
    defaultPresetMap["key10_modline4_ledgreen"] = "None";
    defaultPresetMap["key10_modline4_ledred"] = "None";
    defaultPresetMap["key10_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["key10_modline5_enable"] = 0;
    //defaultPresetMap["key10_modline5_initvalue"] = 0;
    //defaultPresetMap["key10_modline5_initmode"] = "None";
    defaultPresetMap["key10_modline5_source"] = "None";
    defaultPresetMap["key10_modline5_gain"] = 1.00;
    defaultPresetMap["key10_modline5_offset"] = 0;
    defaultPresetMap["key10_modline5_table"] = "Linear";
    defaultPresetMap["key10_modline5_min"] = 0;
    defaultPresetMap["key10_modline5_max"] = 127;
    defaultPresetMap["key10_modline5_slew"] = 0;
    //defaultPresetMap["key10_modline5_delay"] = 0;
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
    defaultPresetMap["key10_modline5_ledgreen"] = "None";
    defaultPresetMap["key10_modline5_ledred"] = "None";
    defaultPresetMap["key10_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["key10_modline6_enable"] = 0;
    //defaultPresetMap["key10_modline6_initvalue"] = 0;
    //defaultPresetMap["key10_modline6_initmode"] = "None";
    defaultPresetMap["key10_modline6_source"] = "None";
    defaultPresetMap["key10_modline6_gain"] = 1.00;
    defaultPresetMap["key10_modline6_offset"] = 0;
    defaultPresetMap["key10_modline6_table"] = "Linear";
    defaultPresetMap["key10_modline6_min"] = 0;
    defaultPresetMap["key10_modline6_max"] = 127;
    defaultPresetMap["key10_modline6_slew"] = 0;
    //defaultPresetMap["key10_modline6_delay"] = 0;
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
    defaultPresetMap["key10_modline6_ledgreen"] = "None";
    defaultPresetMap["key10_modline6_ledred"] = "None";
    defaultPresetMap["key10_modline6_displaylinked"] = 0;

    //------------------------ Nav ------------------------//
    defaultPresetMap["nav_name"] = "1KEY";
    defaultPresetMap["nav_displaymode"] = "None";
    defaultPresetMap["nav_modlinemode"] = 1;
    defaultPresetMap["nav_prefix"] = "";
    //defaultPresetMap["nav_counter_min"] = 0;
    //defaultPresetMap["nav_counter_max"] = 127;
    //defaultPresetMap["nav_counter_wrap"] = 1;

    //------ Modline 1 ------//
    defaultPresetMap["nav_modline1_enable"] = 0;
    //defaultPresetMap["nav_modline1_initvalue"] = 0;
    //defaultPresetMap["nav_modline1_initmode"] = "None";
    defaultPresetMap["nav_modline1_source"] = "None";
    defaultPresetMap["nav_modline1_gain"] = 1.00;
    defaultPresetMap["nav_modline1_offset"] = 0;
    defaultPresetMap["nav_modline1_table"] = "Linear";
    defaultPresetMap["nav_modline1_min"] = 0;
    defaultPresetMap["nav_modline1_max"] = 127;
    defaultPresetMap["nav_modline1_slew"] = 0;
    //defaultPresetMap["nav_modline1_delay"] = 0;
    defaultPresetMap["nav_modline1_destination"] = "None";
    defaultPresetMap["nav_modline1_note"] = 60;
    defaultPresetMap["nav_modline1_velocity"] = 127;
    defaultPresetMap["nav_modline1_cc"] = 1;
    defaultPresetMap["nav_modline1_bankmsb"] = 0;
    defaultPresetMap["nav_modline1_mmcid"] = 0;
    defaultPresetMap["nav_modline1_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline1_channel"] = 1;
    defaultPresetMap["nav_modline1_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline1_oscroute"] = "";
    defaultPresetMap["nav_modline1_displaylinked"] = 0;

    //------ Modline 2 ------//
    defaultPresetMap["nav_modline2_enable"] = 0;
    //defaultPresetMap["nav_modline2_initvalue"] = 0;
    //defaultPresetMap["nav_modline2_initmode"] = "None";
    defaultPresetMap["nav_modline2_source"] = "None";
    defaultPresetMap["nav_modline2_gain"] = 1.00;
    defaultPresetMap["nav_modline2_offset"] = 0;
    defaultPresetMap["nav_modline2_table"] = "Linear";
    defaultPresetMap["nav_modline2_min"] = 0;
    defaultPresetMap["nav_modline2_max"] = 127;
    defaultPresetMap["nav_modline2_slew"] = 0;
    //defaultPresetMap["nav_modline2_delay"] = 0;
    defaultPresetMap["nav_modline2_destination"] = "None";
    defaultPresetMap["nav_modline2_note"] = 60;
    defaultPresetMap["nav_modline2_velocity"] = 127;
    defaultPresetMap["nav_modline2_cc"] = 1;
    defaultPresetMap["nav_modline2_bankmsb"] = 0;
    defaultPresetMap["nav_modline2_mmcid"] = 0;
    defaultPresetMap["nav_modline2_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline2_channel"] = 1;
    defaultPresetMap["nav_modline2_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline2_oscroute"] = "";
    defaultPresetMap["nav_modline2_displaylinked"] = 0;

    //------ Modline 3 ------//
    defaultPresetMap["nav_modline3_enable"] = 0;
    //defaultPresetMap["nav_modline3_initvalue"] = 0;
    //defaultPresetMap["nav_modline3_initmode"] = "None";
    defaultPresetMap["nav_modline3_source"] = "None";
    defaultPresetMap["nav_modline3_gain"] = 1.00;
    defaultPresetMap["nav_modline3_offset"] = 0;
    defaultPresetMap["nav_modline3_table"] = "Linear";
    defaultPresetMap["nav_modline3_min"] = 0;
    defaultPresetMap["nav_modline3_max"] = 127;
    defaultPresetMap["nav_modline3_slew"] = 0;
    //defaultPresetMap["nav_modline3_delay"] = 0;
    defaultPresetMap["nav_modline3_destination"] = "None";
    defaultPresetMap["nav_modline3_note"] = 60;
    defaultPresetMap["nav_modline3_velocity"] = 127;
    defaultPresetMap["nav_modline3_cc"] = 1;
    defaultPresetMap["nav_modline3_bankmsb"] = 0;
    defaultPresetMap["nav_modline3_mmcid"] = 0;
    defaultPresetMap["nav_modline3_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline3_channel"] = 1;
    defaultPresetMap["nav_modline3_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline3_oscroute"] = "";
    defaultPresetMap["nav_modline3_displaylinked"] = 0;

    //------ Modline 4 ------//
    defaultPresetMap["nav_modline4_enable"] = 0;
    //defaultPresetMap["nav_modline4_initvalue"] = 0;
    //defaultPresetMap["nav_modline4_initmode"] = "None";
    defaultPresetMap["nav_modline4_source"] = "None";
    defaultPresetMap["nav_modline4_gain"] = 1.00;
    defaultPresetMap["nav_modline4_offset"] = 0;
    defaultPresetMap["nav_modline4_table"] = "Linear";
    defaultPresetMap["nav_modline4_min"] = 0;
    defaultPresetMap["nav_modline4_max"] = 127;
    defaultPresetMap["nav_modline4_slew"] = 0;
    //defaultPresetMap["nav_modline4_delay"] = 0;
    defaultPresetMap["nav_modline4_destination"] = "None";
    defaultPresetMap["nav_modline4_note"] = 60;
    defaultPresetMap["nav_modline4_velocity"] = 127;
    defaultPresetMap["nav_modline4_cc"] = 1;
    defaultPresetMap["nav_modline4_bankmsb"] = 0;
    defaultPresetMap["nav_modline4_mmcid"] = 0;
    defaultPresetMap["nav_modline4_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline4_channel"] = 1;
    defaultPresetMap["nav_modline4_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline4_oscroute"] = "";
    defaultPresetMap["nav_modline4_displaylinked"] = 0;

    //------ Modline 5 ------//
    defaultPresetMap["nav_modline5_enable"] = 0;
    //defaultPresetMap["nav_modline5_initvalue"] = 0;
    //defaultPresetMap["nav_modline5_initmode"] = "None";
    defaultPresetMap["nav_modline5_source"] = "None";
    defaultPresetMap["nav_modline5_gain"] = 1.00;
    defaultPresetMap["nav_modline5_offset"] = 0;
    defaultPresetMap["nav_modline5_table"] = "Linear";
    defaultPresetMap["nav_modline5_min"] = 0;
    defaultPresetMap["nav_modline5_max"] = 127;
    defaultPresetMap["nav_modline5_slew"] = 0;
    //defaultPresetMap["nav_modline5_delay"] = 0;
    defaultPresetMap["nav_modline5_destination"] = "None";
    defaultPresetMap["nav_modline5_note"] = 60;
    defaultPresetMap["nav_modline5_velocity"] = 127;
    defaultPresetMap["nav_modline5_cc"] = 1;
    defaultPresetMap["nav_modline5_bankmsb"] = 0;
    defaultPresetMap["nav_modline5_mmcid"] = 0;
    defaultPresetMap["nav_modline5_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline5_channel"] = 1;
    defaultPresetMap["nav_modline5_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline5_oscroute"] = "";
    defaultPresetMap["nav_modline5_displaylinked"] = 0;

    //------ Modline 6 ------//
    defaultPresetMap["nav_modline6_enable"] = 0;
    //defaultPresetMap["nav_modline6_initvalue"] = 0;
    //defaultPresetMap["nav_modline6_initmode"] = "None";
    defaultPresetMap["nav_modline6_source"] = "None";
    defaultPresetMap["nav_modline6_gain"] = 1.00;
    defaultPresetMap["nav_modline6_offset"] = 0;
    defaultPresetMap["nav_modline6_table"] = "Linear";
    defaultPresetMap["nav_modline6_min"] = 0;
    defaultPresetMap["nav_modline6_max"] = 127;
    defaultPresetMap["nav_modline6_slew"] = 0;
    //defaultPresetMap["nav_modline6_delay"] = 0;
    defaultPresetMap["nav_modline6_destination"] = "None";
    defaultPresetMap["nav_modline6_note"] = 60;
    defaultPresetMap["nav_modline6_velocity"] = 127;
    defaultPresetMap["nav_modline6_cc"] = 1;
    defaultPresetMap["nav_modline6_bankmsb"] = 0;
    defaultPresetMap["nav_modline6_mmcid"] = 0;
    defaultPresetMap["nav_modline6_mmcfunction"] = "Stop";
    defaultPresetMap["nav_modline6_channel"] = 1;
    defaultPresetMap["nav_modline6_device"] = "SoftStep Expander";
    defaultPresetMap["nav_modline6_oscroute"] = "";
    defaultPresetMap["nav_modline6_displaylinked"] = 0;
}
