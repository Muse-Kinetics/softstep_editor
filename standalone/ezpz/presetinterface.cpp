// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "presetinterface.h"

PresetInterface::PresetInterface(QWidget *parent) :
    QWidget(parent)
{
    connected = false;
    settings = new QSettings(this);


    // If preset JSON files do not exist in AppDataLocation, copy the defaults from the application bundle dir.

    // Get platform dependant path to read only presets directory inside the app bundle/package
    QString appPackageDirPath = QCoreApplication::applicationDirPath();

#if defined(Q_OS_MAC)
    //Remove "MacOS" from path string
    appPackageDirPath.remove(appPackageDirPath.length() - 5, appPackageDirPath.length());

    QString presetsDirSrcPath = appPackageDirPath + "Resources/presets";
#else
    qDebug() << "appPackageDirPath: " << appPackageDirPath;
    QString presetsDirSrcPath = QString("./presets");
#endif

    qDebug() << "presetsDirSrcPath: " << presetsDirSrcPath;

    // Get path to writeable app data directory
    QString appDataDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug() << "appDataDirPath: " << appDataDirPath;

    if (appDataDirPath.isEmpty()) {
        qFatal("Cannot determine preset storage location");
    }

    // Create destination presets subdirectory if it doesn't exist
    QString presetsDirDestPath = appDataDirPath;

    qDebug() << "presetsDirDestPath: " << presetsDirDestPath;

    if (!QDir(presetsDirDestPath).exists()) {
        QDir().mkpath(presetsDirDestPath);
    }

    // If either preset file doesn't exist at the destination, copy it there
    QString presetFileDestPath = presetsDirDestPath + "/presets.json";
    QString presetFileSrcPath = presetsDirSrcPath + "/softstepezpz.json";

    if (!QFile::exists(presetFileDestPath))
    {
        if (QFile::copy(presetFileSrcPath, presetFileDestPath) == false) {
            qFatal("Cannot copy default preset file to application data path!");
        }
    }

    // make file path available
    jsonPath = presetFileDestPath;

    qDebug("Load Presets");
    // Read presets
    slotReadJSON();

    // For generating default preset file from app
    //writeDefualtJSON();
}

void PresetInterface::slotStoreValue(QString name, QVariant value, int presetNum)
{
    //qDebug() << "name" << name << "value" << value << "preset" << presetNum;

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
    QStringList keyList = jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().keys();

    bool dirty = false;

    for(int i = 0; i < keyList.size(); i++)
    {

        if(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)) !=
                jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)))
        {
            //qDebug() << "------------" << keyList.at(i) << jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i)) << jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap().value(keyList.at(i));

            //If not a modline param, only used in backend, not ui
            if(!keyList.at(i).contains("modline") && !keyList.at(i).contains("setting") && !keyList.at(i).contains("led"))
            {
                dirty = true;
                break;
            }
        }
    }

    //Globes
    if(jsonMasterMapCopy.value("sensitivity") != jsonMasterMap.value("sensitivity"))
    {
        qDebug() << "------------sensitivity" << jsonMasterMapCopy.value("sensitivity") << jsonMasterMap.value("sensitivity");
        dirty = true;
    }

    if(jsonMasterMapCopy.value("backlight") != jsonMasterMap.value("backlight"))
    {
        qDebug() << "------------backlight" << jsonMasterMapCopy.value("backlight") << jsonMasterMap.value("backlight");
        dirty = true;
    }

    //qDebug() << "preset Dirty?" << dirty;

    emit signalPresetDirty(dirty);
}

void PresetInterface::slotReadJSON()
{
    //Load json into QFile
    QFile *jsonFile = new QFile(jsonPath);

    if(jsonFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("SoftStep Easy Editor JSON Found");

//        QByteArray jsonByteArray = jsonFile->readAll();//load json file into a byte array to be processd by the parser
        // error object
        QJsonParseError JsonParseError;
        // convert file to QJsonDocument. this can be read/written to
        QJsonDocument JsonDocument = QJsonDocument::fromJson(jsonFile->readAll(), &JsonParseError);
        // close jsonFile
        jsonFile->close();
        // convert QJsonDocument to QJsonObject. this can be queried and modified in a human-readable way
        QJsonObject RootObject = JsonDocument.object();
        QByteArray jsonByteArray = JsonDocument.toJson();
        jsonMasterMap = RootObject.toVariantMap();

//        jsonMasterMap = parser.parse(jsonByteArray, &ok).toMap(); //parse the json data, convert it to a map and set it equal to the master jsonMap
        jsonMasterMapCopy = jsonMasterMap;

        //-------
        int presetNum = 1;

        QStringList keyList = jsonMasterMapCopy.value(QString("Preset_00%1").arg(presetNum)).toMap().keys();

        for(int i = 0; i < keyList.size(); i++)
        {
            //qDebug() << "k: " << i << " /" << keyList.size();
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
        qDebug() << "SoftStep Easy Editor JSON Not Found";
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
//        QByteArray ba = serializer.serialize(jsonMap); //serialize the master json map into the byte array
        QJsonDocument jsonPresets = QJsonDocument::fromVariant(jsonMap);

        jsonFile->resize(0);
//        jsonFile->write(ba);
        jsonFile->write(jsonPresets.toJson()); //write json byte array to file
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

    ///Generate fresh default json needed
    for(int i = 0; i < 10; i++)
    {
        jsonMasterMap.insert(QString("Preset_00%1").arg(i), defaultParamMap);

        //Globals
        jsonMasterMap.insert("sensitivity",1.00);
        jsonMasterMap.insert("backlight", true);
    }

    slotWriteJSON(jsonMasterMap);
}

void PresetInterface::slotRevertPreset()
{
    if(currentPresetNum != -1)
    {
        //Load preset from master map into the copy
        jsonMasterMapCopy.insert(QString("Preset_00%1").arg(currentPresetNum), jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());
        //global parameters
        jsonMasterMapCopy.insert("backlight", jsonMasterMap.value("backlight").toBool());
        jsonMasterMapCopy.insert("sensitivity", jsonMasterMap.value("sensitivity").toDouble());
        qDebug() << "preset" << currentPresetNum << "should revert now";
        emit signalRecallPreset(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap(), jsonMasterMapCopy);
        slotCheckSaveState();
    }
    else
    {
        qDebug() << "preset will not revert";
    }
}

void PresetInterface::slotImportPreset()
{
    QString filename = NULL;

    QSettings settings;

    const QString DEFAULT_DIR_KEY("default_dir");

    filename = QFileDialog::getOpenFileName(this, tr("Import Preset"), settings.value(DEFAULT_DIR_KEY).toString(), tr("SoftStep Basic Editor Preset Files (*.softstepbasicpreset)"));

    //If file is selected
    if(!filename.isEmpty() && !filename.isNull())
    {
        //this gets the filename without the path
        QFileInfo fileInfo(filename);

        // store this folder location for the next time we open a file
        QString thisDirectory = fileInfo.absolutePath();
        settings.setValue(DEFAULT_DIR_KEY, thisDirectory);

        //open file
        QFile* presetFile = new QFile(filename);
        presetFile->open(QIODevice::ReadOnly | QIODevice::Text);

        // error object
        QJsonParseError JsonParseError;
        // convert file to QJsonDocument. this can be read/written to
        QJsonDocument JsonDocument = QJsonDocument::fromJson(presetFile->readAll(), &JsonParseError);

        // convert QJsonDocument to QJsonObject. this can be queried and modified in a human-readable way
        QJsonObject RootObject = JsonDocument.object();

//        QByteArray presetByteArray = presetFile->readAll();
//        QByteArray presetByteArray = JsonDocument.toJson();
        presetFile->close();

//        QVariantMap importedPresetMap = parser.parse(presetByteArray, &ok).toMap();

        QVariantMap importedPresetMap = RootObject.toVariantMap();

        //--------------- Check for MISSING parameters in the Imported Preset --------------
        slotConstructDefaultMap();

        QMapIterator<QString, QVariant> i(defaultParamMap);
        //Iterate through default map and compare with imported preset
        while(i.hasNext())
        {
            i.next();

            if(!importedPresetMap.contains(i.key()))
            {
                //if imported preset map does not contain a value in the default map, insert it
                importedPresetMap.insert(i.key(), i.value());
                qDebug() << "from slotImportPreset - this was MISSING:" << i.key() << i.value();
            }
        }

        //----------- Check for EXTRA parameters in the Imported Preset -------------------
        QMapIterator<QString, QVariant> j(importedPresetMap);

        QStringList badKeys; //stores keys we need to remove from the map

        while(j.hasNext())
        {
            j.next();

            //If the default map does not contain something in the preset, add to list of bad keys
            if(!defaultParamMap.contains(j.key()))
            {
                badKeys.append(j.key());
                qDebug() << "From slotImportPreset - this was EXTRA:" << j.key() << j.value();
            }
        }
        //Iterate through the bad keys and remove from preset
        for(int i = 0; i<badKeys.count(); i++)
        {
            importedPresetMap.remove(badKeys.at(i));
        }

        //------------- Set Imported Preset to current and update ------------
        jsonMasterMapCopy.insert(QString("Preset_00%1").arg(currentPresetNum), importedPresetMap);
        slotRecallPreset(currentPresetNum); // was +1, slotRecallPreset now adds 1 to the preset val to modify zero indexing
        slotCheckSaveState();
    }
}

void PresetInterface::slotExportPreset()
{
    QVariantMap exportedPresetMap = jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap();

    QSettings settings;

    const QString DEFAULT_DIR_KEY("default_dir");

    //set path and filename (default filename is the preset name
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Preset"), QString("%1/%2").arg(settings.value(DEFAULT_DIR_KEY).toString()).arg(exportedPresetMap.value("displayName").toString()), tr("SoftStep Basic Editor Preset Files (*.softstepbasicpreset)"));

    if(!filename.isEmpty() && !filename.isNull())
    {
        //this gets the filename without the path
        QFileInfo fileInfo(filename);

        // store this folder location for the next time we open a file
        QString thisDirectory = fileInfo.absolutePath();
        settings.setValue(DEFAULT_DIR_KEY, thisDirectory);

        //open new file to be saved
        QFile* presetFile = new QFile(filename);

        //remove extension from filename
        QString exportedPresetName = fileInfo.fileName().remove(".softstepbasicpreset");

        qDebug() << QString("filename: %1").arg(exportedPresetName);

        //------------------- Open, Write, and Close
        presetFile->open(QIODevice::WriteOnly);

    //    QByteArray presetByteArray = serializer.serialize(exportedPresetMap);

        QJsonDocument jsonPresets = QJsonDocument::fromVariant(exportedPresetMap);

        presetFile->resize(0);
    //    presetFile->write(presetByteArray);
        presetFile->write(jsonPresets.toJson()); //write json byte array to file
        presetFile->close();

    //    presetByteArray.clear();
    }
}

void PresetInterface::slotConstructDefaultMap()
{
    //Preset Globals
    defaultParamMap["midiChannel"] = 1;
    //defaultParamMap["sensitivity"] = 1.00;
    defaultParamMap["navPadCC"] = -1;
    defaultParamMap["pedalCC"] = -1;
    //defaultParamMap["backlight"] = true;
    defaultParamMap["displayName"] = "";
    defaultParamMap["useFactory"] = "No";

    //1
    defaultParamMap["1_key_modline_source"] = "None";
    defaultParamMap["1_key_modline_table"] = "1_Lin";
    defaultParamMap["1_key_modline_gain"] = 1.00;
    defaultParamMap["1_key_modline_min"] = 0;
    defaultParamMap["1_key_modline_max"] = 127;
    defaultParamMap["1_key_modline_slew"] = 0;
    defaultParamMap["1_key_modline_destination"] = "None";
    defaultParamMap["1_key_modline_cc"] = 0;
    defaultParamMap["1_key_modline2_source"] = "None";
    defaultParamMap["1_key_modline2_min"] = 0;
    defaultParamMap["1_key_modline2_max"] = 127;
    defaultParamMap["1_key_modline2_destination"] = "None";
    defaultParamMap["1_key_modline2_cc"] = 0;
    defaultParamMap["1_key_setting_yAccel"] = 85;
    defaultParamMap["1_key_led_green"] = "None";
    defaultParamMap["1_key_led_red"] ="None";
    defaultParamMap["1_key_source"] = "None";
    defaultParamMap["1_key_name"] = "";
    defaultParamMap["1_key_noteNum"] = 61;
    defaultParamMap["1_key_noteVelocity"] = 127;
    defaultParamMap["1_key_noteToggle"] = 1;
    defaultParamMap["1_key_pressureCC"] = 20;
    defaultParamMap["1_key_pressureSmooth"] = 0;
    defaultParamMap["1_key_toggleCC"] = 21;
    defaultParamMap["1_key_toggleLo"] = 0;
    defaultParamMap["1_key_toggleHi"] = 127;
    defaultParamMap["1_key_xyXCC"] = 22;
    defaultParamMap["1_key_xyYCC"] = 23;
    defaultParamMap["1_key_xyLatch"] = 0;
    defaultParamMap["1_key_yIncCC"] = 24;
    defaultParamMap["1_key_yIncSpeed"] = 0;
    defaultParamMap["1_key_programNum"] = 0;
    defaultParamMap["1_key_programBank"] = 0;

    //2
    defaultParamMap["2_key_modline_source"] = "None";
    defaultParamMap["2_key_modline_table"] = "1_Lin";
    defaultParamMap["2_key_modline_gain"] = 1.00;
    defaultParamMap["2_key_modline_min"] = 0;
    defaultParamMap["2_key_modline_max"] = 127;
    defaultParamMap["2_key_modline_slew"] = 0;
    defaultParamMap["2_key_modline_destination"] = "None";
    defaultParamMap["2_key_modline_cc"] = 0;
    defaultParamMap["2_key_modline2_source"] = "None";
    defaultParamMap["2_key_modline2_min"] = 0;
    defaultParamMap["2_key_modline2_max"] = 127;
    defaultParamMap["2_key_modline2_destination"] = "None";
    defaultParamMap["2_key_modline2_cc"] = 0;
    defaultParamMap["2_key_setting_yAccel"] = 85;
    defaultParamMap["2_key_led_green"] = "None";
    defaultParamMap["2_key_led_red"] ="None";
    defaultParamMap["2_key_source"] = "None";
    defaultParamMap["2_key_name"] = "";
    defaultParamMap["2_key_noteNum"] = 62;
    defaultParamMap["2_key_noteVelocity"] = 127;
    defaultParamMap["2_key_noteToggle"] = 1;
    defaultParamMap["2_key_pressureCC"] = 20;
    defaultParamMap["2_key_pressureSmooth"] = 0;
    defaultParamMap["2_key_toggleCC"] = 21;
    defaultParamMap["2_key_toggleLo"] = 0;
    defaultParamMap["2_key_toggleHi"] = 127;
    defaultParamMap["2_key_xyXCC"] = 22;
    defaultParamMap["2_key_xyYCC"] = 23;
    defaultParamMap["2_key_xyLatch"] = 0;
    defaultParamMap["2_key_yIncCC"] = 24;
    defaultParamMap["2_key_yIncSpeed"] = 0;
    defaultParamMap["2_key_programNum"] = 0;
    defaultParamMap["2_key_programBank"] = 0;

    //3
    defaultParamMap["3_key_modline_source"] = "None";
    defaultParamMap["3_key_modline_table"] = "1_Lin";
    defaultParamMap["3_key_modline_gain"] = 1.00;
    defaultParamMap["3_key_modline_min"] = 0;
    defaultParamMap["3_key_modline_max"] = 127;
    defaultParamMap["3_key_modline_slew"] = 0;
    defaultParamMap["3_key_modline_destination"] = "None";
    defaultParamMap["3_key_modline_cc"] = 0;
    defaultParamMap["3_key_modline2_source"] = "None";
    defaultParamMap["3_key_modline2_min"] = 0;
    defaultParamMap["3_key_modline2_max"] = 127;
    defaultParamMap["3_key_modline2_destination"] = "None";
    defaultParamMap["3_key_modline2_cc"] = 0;
    defaultParamMap["3_key_setting_yAccel"] = 85;
    defaultParamMap["3_key_led_green"] = "None";
    defaultParamMap["3_key_led_red"] ="None";
    defaultParamMap["3_key_source"] = "None";
    defaultParamMap["3_key_name"] = "";
    defaultParamMap["3_key_noteNum"] = 63;
    defaultParamMap["3_key_noteVelocity"] = 127;
    defaultParamMap["3_key_noteToggle"] = 1;
    defaultParamMap["3_key_pressureCC"] = 20;
    defaultParamMap["3_key_pressureSmooth"] = 0;
    defaultParamMap["3_key_toggleCC"] = 21;
    defaultParamMap["3_key_toggleLo"] = 0;
    defaultParamMap["3_key_toggleHi"] = 127;
    defaultParamMap["3_key_xyXCC"] = 22;
    defaultParamMap["3_key_xyYCC"] = 23;
    defaultParamMap["3_key_xyLatch"] = 0;
    defaultParamMap["3_key_yIncCC"] = 24;
    defaultParamMap["3_key_yIncSpeed"] = 0;
    defaultParamMap["3_key_programNum"] = 0;
    defaultParamMap["3_key_programBank"] = 0;

    //4
    defaultParamMap["4_key_modline_source"] = "None";
    defaultParamMap["4_key_modline_table"] = "1_Lin";
    defaultParamMap["4_key_modline_gain"] = 1.00;
    defaultParamMap["4_key_modline_min"] = 0;
    defaultParamMap["4_key_modline_max"] = 127;
    defaultParamMap["4_key_modline_slew"] = 0;
    defaultParamMap["4_key_modline_destination"] = "None";
    defaultParamMap["4_key_modline_cc"] = 0;
    defaultParamMap["4_key_modline2_source"] = "None";
    defaultParamMap["4_key_modline2_min"] = 0;
    defaultParamMap["4_key_modline2_max"] = 127;
    defaultParamMap["4_key_modline2_destination"] = "None";
    defaultParamMap["4_key_modline2_cc"] = 0;
    defaultParamMap["4_key_setting_yAccel"] = 85;
    defaultParamMap["4_key_led_green"] = "None";
    defaultParamMap["4_key_led_red"] ="None";
    defaultParamMap["4_key_source"] = "None";
    defaultParamMap["4_key_name"] = "";
    defaultParamMap["4_key_noteNum"] = 64;
    defaultParamMap["4_key_noteVelocity"] = 127;
    defaultParamMap["4_key_noteToggle"] = 1;
    defaultParamMap["4_key_pressureCC"] = 20;
    defaultParamMap["4_key_pressureSmooth"] = 0;
    defaultParamMap["4_key_toggleCC"] = 21;
    defaultParamMap["4_key_toggleLo"] = 0;
    defaultParamMap["4_key_toggleHi"] = 127;
    defaultParamMap["4_key_xyXCC"] = 22;
    defaultParamMap["4_key_xyYCC"] = 23;
    defaultParamMap["4_key_xyLatch"] = 0;
    defaultParamMap["4_key_yIncCC"] = 24;
    defaultParamMap["4_key_yIncSpeed"] = 0;
    defaultParamMap["4_key_programNum"] = 0;
    defaultParamMap["4_key_programBank"] = 0;

    //5
    defaultParamMap["5_key_modline_source"] = "None";
    defaultParamMap["5_key_modline_table"] = "1_Lin";
    defaultParamMap["5_key_modline_gain"] = 1.00;
    defaultParamMap["5_key_modline_min"] = 0;
    defaultParamMap["5_key_modline_max"] = 127;
    defaultParamMap["5_key_modline_slew"] = 0;
    defaultParamMap["5_key_modline_destination"] = "None";
    defaultParamMap["5_key_modline_cc"] = 0;
    defaultParamMap["5_key_modline2_source"] = "None";
    defaultParamMap["5_key_modline2_min"] = 0;
    defaultParamMap["5_key_modline2_max"] = 127;
    defaultParamMap["5_key_modline2_destination"] = "None";
    defaultParamMap["5_key_modline2_cc"] = 0;
    defaultParamMap["5_key_setting_yAccel"] = 85;
    defaultParamMap["5_key_led_green"] = "None";
    defaultParamMap["5_key_led_red"] ="None";
    defaultParamMap["5_key_source"] = "None";
    defaultParamMap["5_key_name"] = "";
    defaultParamMap["5_key_noteNum"] = 65;
    defaultParamMap["5_key_noteVelocity"] = 127;
    defaultParamMap["5_key_noteToggle"] = 1;
    defaultParamMap["5_key_pressureCC"] = 20;
    defaultParamMap["5_key_pressureSmooth"] = 0;
    defaultParamMap["5_key_toggleCC"] = 21;
    defaultParamMap["5_key_toggleLo"] = 0;
    defaultParamMap["5_key_toggleHi"] = 127;
    defaultParamMap["5_key_xyXCC"] = 22;
    defaultParamMap["5_key_xyYCC"] = 23;
    defaultParamMap["5_key_xyLatch"] = 0;
    defaultParamMap["5_key_yIncCC"] = 24;
    defaultParamMap["5_key_yIncSpeed"] = 0;
    defaultParamMap["5_key_programNum"] = 0;
    defaultParamMap["5_key_programBank"] = 0;

    //6
    defaultParamMap["6_key_modline_source"] = "None";
    defaultParamMap["6_key_modline_table"] = "1_Lin";
    defaultParamMap["6_key_modline_gain"] = 1.00;
    defaultParamMap["6_key_modline_min"] = 0;
    defaultParamMap["6_key_modline_max"] = 127;
    defaultParamMap["6_key_modline_slew"] = 0;
    defaultParamMap["6_key_modline_destination"] = "None";
    defaultParamMap["6_key_modline_cc"] = 0;
    defaultParamMap["6_key_modline2_source"] = "None";
    defaultParamMap["6_key_modline2_min"] = 0;
    defaultParamMap["6_key_modline2_max"] = 127;
    defaultParamMap["6_key_modline2_destination"] = "None";
    defaultParamMap["6_key_modline2_cc"] = 0;
    defaultParamMap["6_key_setting_yAccel"] = 85;
    defaultParamMap["6_key_led_green"] = "None";
    defaultParamMap["6_key_led_red"] ="None";
    defaultParamMap["6_key_source"] = "None";
    defaultParamMap["6_key_name"] = "";
    defaultParamMap["6_key_noteNum"] = 66;
    defaultParamMap["6_key_noteVelocity"] = 127;
    defaultParamMap["6_key_noteToggle"] = 1;
    defaultParamMap["6_key_pressureCC"] = 20;
    defaultParamMap["6_key_pressureSmooth"] = 0;
    defaultParamMap["6_key_toggleCC"] = 21;
    defaultParamMap["6_key_toggleLo"] = 0;
    defaultParamMap["6_key_toggleHi"] = 127;
    defaultParamMap["6_key_xyXCC"] = 22;
    defaultParamMap["6_key_xyYCC"] = 23;
    defaultParamMap["6_key_xyLatch"] = 0;
    defaultParamMap["6_key_yIncCC"] = 24;
    defaultParamMap["6_key_yIncSpeed"] = 0;
    defaultParamMap["6_key_programNum"] = 0;
    defaultParamMap["6_key_programBank"] = 0;

    //7
    defaultParamMap["7_key_modline_source"] = "None";
    defaultParamMap["7_key_modline_table"] = "1_Lin";
    defaultParamMap["7_key_modline_gain"] = 1.00;
    defaultParamMap["7_key_modline_min"] = 0;
    defaultParamMap["7_key_modline_max"] = 127;
    defaultParamMap["7_key_modline_slew"] = 0;
    defaultParamMap["7_key_modline_destination"] = "None";
    defaultParamMap["7_key_modline_cc"] = 0;
    defaultParamMap["7_key_modline2_source"] = "None";
    defaultParamMap["7_key_modline2_min"] = 0;
    defaultParamMap["7_key_modline2_max"] = 127;
    defaultParamMap["7_key_modline2_destination"] = "None";
    defaultParamMap["7_key_modline2_cc"] = 0;
    defaultParamMap["7_key_setting_yAccel"] = 85;
    defaultParamMap["7_key_led_green"] = "None";
    defaultParamMap["7_key_led_red"] ="None";
    defaultParamMap["7_key_source"] = "None";
    defaultParamMap["7_key_name"] = "";
    defaultParamMap["7_key_noteNum"] = 67;
    defaultParamMap["7_key_noteVelocity"] = 127;
    defaultParamMap["7_key_noteToggle"] = 1;
    defaultParamMap["7_key_pressureCC"] = 20;
    defaultParamMap["7_key_pressureSmooth"] = 0;
    defaultParamMap["7_key_toggleCC"] = 21;
    defaultParamMap["7_key_toggleLo"] = 0;
    defaultParamMap["7_key_toggleHi"] = 127;
    defaultParamMap["7_key_xyXCC"] = 22;
    defaultParamMap["7_key_xyYCC"] = 23;
    defaultParamMap["7_key_xyLatch"] = 0;
    defaultParamMap["7_key_yIncCC"] = 24;
    defaultParamMap["7_key_yIncSpeed"] = 0;
    defaultParamMap["7_key_programNum"] = 0;
    defaultParamMap["7_key_programBank"] = 0;

    //8
    defaultParamMap["8_key_modline_source"] = "None";
    defaultParamMap["8_key_modline_table"] = "1_Lin";
    defaultParamMap["8_key_modline_gain"] = 1.00;
    defaultParamMap["8_key_modline_min"] = 0;
    defaultParamMap["8_key_modline_max"] = 127;
    defaultParamMap["8_key_modline_slew"] = 0;
    defaultParamMap["8_key_modline_destination"] = "None";
    defaultParamMap["8_key_modline_cc"] = 0;
    defaultParamMap["8_key_modline2_source"] = "None";
    defaultParamMap["8_key_modline2_min"] = 0;
    defaultParamMap["8_key_modline2_max"] = 127;
    defaultParamMap["8_key_modline2_destination"] = "None";
    defaultParamMap["8_key_modline2_cc"] = 0;
    defaultParamMap["8_key_setting_yAccel"] = 85;
    defaultParamMap["8_key_led_green"] = "None";
    defaultParamMap["8_key_led_red"] ="None";
    defaultParamMap["8_key_source"] = "None";
    defaultParamMap["8_key_name"] = "";
    defaultParamMap["8_key_noteNum"] = 68;
    defaultParamMap["8_key_noteVelocity"] = 127;
    defaultParamMap["8_key_noteToggle"] = 1;
    defaultParamMap["8_key_pressureCC"] = 20;
    defaultParamMap["8_key_pressureSmooth"] = 0;
    defaultParamMap["8_key_toggleCC"] = 21;
    defaultParamMap["8_key_toggleLo"] = 0;
    defaultParamMap["8_key_toggleHi"] = 127;
    defaultParamMap["8_key_xyXCC"] = 22;
    defaultParamMap["8_key_xyYCC"] = 23;
    defaultParamMap["8_key_xyLatch"] = 0;
    defaultParamMap["8_key_yIncCC"] = 24;
    defaultParamMap["8_key_yIncSpeed"] = 0;
    defaultParamMap["8_key_programNum"] = 0;
    defaultParamMap["8_key_programBank"] = 0;

    //9
    defaultParamMap["9_key_modline_source"] = "None";
    defaultParamMap["9_key_modline_table"] = "1_Lin";
    defaultParamMap["9_key_modline_gain"] = 1.00;
    defaultParamMap["9_key_modline_min"] = 0;
    defaultParamMap["9_key_modline_max"] = 127;
    defaultParamMap["9_key_modline_slew"] = 0;
    defaultParamMap["9_key_modline_destination"] = "None";
    defaultParamMap["9_key_modline_cc"] = 0;
    defaultParamMap["9_key_modline2_source"] = "None";
    defaultParamMap["9_key_modline2_min"] = 0;
    defaultParamMap["9_key_modline2_max"] = 127;
    defaultParamMap["9_key_modline2_destination"] = "None";
    defaultParamMap["9_key_modline2_cc"] = 0;
    defaultParamMap["9_key_setting_yAccel"] = 85;
    defaultParamMap["9_key_led_green"] = "None";
    defaultParamMap["9_key_led_red"] ="None";
    defaultParamMap["9_key_source"] = "None";
    defaultParamMap["9_key_name"] = "";
    defaultParamMap["9_key_noteNum"] = 69;
    defaultParamMap["9_key_noteVelocity"] = 127;
    defaultParamMap["9_key_noteToggle"] = 1;
    defaultParamMap["9_key_pressureCC"] = 20;
    defaultParamMap["9_key_pressureSmooth"] = 0;
    defaultParamMap["9_key_toggleCC"] = 21;
    defaultParamMap["9_key_toggleLo"] = 0;
    defaultParamMap["9_key_toggleHi"] = 127;
    defaultParamMap["9_key_xyXCC"] = 22;
    defaultParamMap["9_key_xyYCC"] = 23;
    defaultParamMap["9_key_xyLatch"] = 0;
    defaultParamMap["9_key_yIncCC"] = 24;
    defaultParamMap["9_key_yIncSpeed"] = 0;
    defaultParamMap["9_key_programNum"] = 0;
    defaultParamMap["9_key_programBank"] = 0;

    //10
    defaultParamMap["10_key_modline_source"] = "None";
    defaultParamMap["10_key_modline_table"] = "1_Lin";
    defaultParamMap["10_key_modline_gain"] = 1.00;
    defaultParamMap["10_key_modline_min"] = 0;
    defaultParamMap["10_key_modline_max"] = 127;
    defaultParamMap["10_key_modline_slew"] = 0;
    defaultParamMap["10_key_modline_destination"] = "None";
    defaultParamMap["10_key_modline_cc"] = 0;
    defaultParamMap["10_key_modline2_source"] = "None";
    defaultParamMap["10_key_modline2_min"] = 0;
    defaultParamMap["10_key_modline2_max"] = 127;
    defaultParamMap["10_key_modline2_destination"] = "None";
    defaultParamMap["10_key_modline2_cc"] = 0;
    defaultParamMap["10_key_setting_yAccel"] = 85;
    defaultParamMap["10_key_led_green"] = "None";
    defaultParamMap["10_key_led_red"] ="None";
    defaultParamMap["10_key_source"] = "None";
    defaultParamMap["10_key_name"] = "";
    defaultParamMap["10_key_noteNum"] = 70;
    defaultParamMap["10_key_noteVelocity"] = 127;
    defaultParamMap["10_key_noteToggle"] = 1;
    defaultParamMap["10_key_pressureCC"] = 20;
    defaultParamMap["10_key_pressureSmooth"] = 0;
    defaultParamMap["10_key_toggleCC"] = 21;
    defaultParamMap["10_key_toggleLo"] = 0;
    defaultParamMap["10_key_toggleHi"] = 127;
    defaultParamMap["10_key_xyXCC"] = 22;
    defaultParamMap["10_key_xyYCC"] = 23;
    defaultParamMap["10_key_xyLatch"] = 0;
    defaultParamMap["10_key_yIncCC"] = 24;
    defaultParamMap["10_key_yIncSpeed"] = 0;
    defaultParamMap["10_key_programNum"] = 0;
    defaultParamMap["10_key_programBank"] = 0;
}

void PresetInterface::slotRecallPreset(int i)
{
    settings->setValue("lastPreset", i-1);

    //i -= 1;
    qDebug() << "recall preset" << i;
    currentPresetNum = i;

    QMapIterator<QString, QVariant> p(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());

    while (p.hasNext())
    {
        p.next();
    }

    emit signalRecallPreset(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap(), jsonMasterMapCopy);

    slotCheckSaveState();
}

void PresetInterface::slotStoreGlobal()
{
    //QString name;
    QVariant value;

    QString senderName = QObject::sender()->objectName();

    if(senderName == "midiChannel")
    {
        value = reinterpret_cast<QSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "sensitivity")
    {
        value = reinterpret_cast<QDoubleSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "navPadCC")
    {
        value = reinterpret_cast<QSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "pedalCC")
    {
        value = reinterpret_cast<QSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "backlight")
    {
        value = reinterpret_cast<QCheckBox *>(QObject::sender())->isChecked();
    }
    else if(senderName == "displayName")
    {
        value = reinterpret_cast<QLineEdit *>(QObject::sender())->text();
    }

    qDebug() << "slotStoreGlobal - " << senderName << " val: " << value;

    if(senderName.contains("sensitivity") || senderName.contains("backlight"))
    {
        jsonMasterMapCopy.insert(senderName, value);
    }
    else
    {
        slotStoreValue(senderName, value, currentPresetNum);
    }

    slotCheckSaveState();
}

void PresetInterface::slotUpdateClicked()
{
    //Store copy of current preset into master json
    jsonMasterMap.insert(QString("Preset_00%1").arg(currentPresetNum), jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());

    //Store globals
    jsonMasterMap.insert("sensitivity", jsonMasterMapCopy.value("sensitivity"));
    jsonMasterMap.insert("backlight", jsonMasterMapCopy.value("backlight").toBool());

    if(connected){
        qDebug() << "update with this preset" << currentPresetNum;
        emit signalUpdateStarted(); //disable the button then start the download
        emit signalAttributeFormatPreset(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap(), jsonMasterMap, (qlonglong)currentPresetNum);
    }

    slotCheckSaveState();
    slotWriteJSON(jsonMasterMap);
}

void PresetInterface::slotSetCurrentPresetToFactory()
{
    QString factoryPresetName = reinterpret_cast<QAction *>(QObject::sender())->text();
    qDebug() << factoryPresetName;

    if(factoryPresetName.contains("Use Custom Preset"))
    {
        slotStoreValue("useFactory", "No", -1);
    }
    else
    {
        slotStoreValue("useFactory", factoryPresetName, -1);
    }

    emit signalRecallPreset(jsonMasterMapCopy.value(QString("Preset_00%1").arg(currentPresetNum)).toMap(), jsonMasterMapCopy);

    slotCheckSaveState();

}

void PresetInterface::closeEvent(QCloseEvent *)
{
    //qDebug() << "closing...";
}
