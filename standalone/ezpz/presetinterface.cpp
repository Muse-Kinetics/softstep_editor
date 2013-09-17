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
    jsonPath = QString("./presets/softstepezpz.json");
#endif

    slotReadJSON();
    slotConstructDefaultMap();

    /*//Generate fresh default json needed
    for(int i = 0; i < 10; i++)
    {
        jsonMasterMap.insert(QString("Preset_00%1").arg(i), defaultParamMap);

        //Globals
        jsonMasterMap.insert("sensitivity",1.00);
        jsonMasterMap.insert("backlight", true);
    }

    slotWriteJSON(jsonMasterMap);*/

}

void PresetInterface::slotStoreValue(QString name, QVariant value, int presetNum)
{
    //qDebug() << "name" << name << "value" << value << "preset" << presetNum;

    if(presetNum == -1)
    {
        presetNum = currentPresetNum;
    }

    QVariantMap presetMap = jsonMasterMap.value(QString("Preset_00%1").arg(presetNum)).toMap();
    presetMap.insert(name, value);
    jsonMasterMap.insert(QString("Preset_00%1").arg(presetNum), presetMap);
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

void PresetInterface::slotConstructDefaultMap()
{
    //Preset Globals
    defaultParamMap["midiChannel"] = 1;
    //defaultParamMap["sensitivity"] = 1.00;
    defaultParamMap["navPadCC"] = 7;
    defaultParamMap["pedalCC"] = 26;
    //defaultParamMap["backlight"] = true;
    defaultParamMap["displayName"] = "EASY";

    //0
    defaultParamMap["0_key_modline_source"] = "None";
    defaultParamMap["0_key_modline_table"] = "None";
    defaultParamMap["0_key_modline_gain"] = 1.00;
    defaultParamMap["0_key_modline_min"] = 1;
    defaultParamMap["0_key_modline_max"] = 127;
    defaultParamMap["0_key_modline_slew"] = 0;
    defaultParamMap["0_key_modline_destination"] = "None";
    defaultParamMap["0_key_modline_cc"] = 0;
    defaultParamMap["0_key_modline2_source"] = "None";
    defaultParamMap["0_key_modline2_min"] = 1;
    defaultParamMap["0_key_modline2_max"] = 127;
    defaultParamMap["0_key_modline2_destination"] = "None";
    defaultParamMap["0_key_modline2_cc"] = 0;
    defaultParamMap["0_key_setting_yAccel"] = 85;
    defaultParamMap["0_key_led_green"] = "None";
    defaultParamMap["0_key_led_red"] ="None";
    defaultParamMap["0_key_source"] = "None";
    defaultParamMap["0_key_name"] = "0KEY";
    defaultParamMap["0_key_noteNum"] = 60;
    defaultParamMap["0_key_noteVelocity"] = 127;
    defaultParamMap["0_key_noteToggle"] = 1;
    defaultParamMap["0_key_pressureCC"] = 20;
    defaultParamMap["0_key_pressureSmooth"] = 0;
    defaultParamMap["0_key_toggleCC"] = 21;
    defaultParamMap["0_key_toggleLo"] = 0;
    defaultParamMap["0_key_toggleHi"] = 127;
    defaultParamMap["0_key_xyXCC"] = 22;
    defaultParamMap["0_key_xyYCC"] = 23;
    defaultParamMap["0_key_xyLatch"] = 0;
    defaultParamMap["0_key_yIncCC"] = 24;
    defaultParamMap["0_key_yIncSpeed"] = 0;
    defaultParamMap["0_key_programNum"] = 0;
    defaultParamMap["0_key_programBank"] = 0;

    //1
    defaultParamMap["1_key_modline_source"] = "None";
    defaultParamMap["1_key_modline_table"] = "None";
    defaultParamMap["1_key_modline_gain"] = 1.00;
    defaultParamMap["1_key_modline_min"] = 1;
    defaultParamMap["1_key_modline_max"] = 127;
    defaultParamMap["1_key_modline_slew"] = 0;
    defaultParamMap["1_key_modline_destination"] = "None";
    defaultParamMap["1_key_modline_cc"] = 0;
    defaultParamMap["1_key_modline2_source"] = "None";
    defaultParamMap["1_key_modline2_min"] = 1;
    defaultParamMap["1_key_modline2_max"] = 127;
    defaultParamMap["1_key_modline2_destination"] = "None";
    defaultParamMap["1_key_modline2_cc"] = 0;
    defaultParamMap["1_key_setting_yAccel"] = 85;
    defaultParamMap["1_key_led_green"] = "None";
    defaultParamMap["1_key_led_red"] ="None";
    defaultParamMap["1_key_source"] = "None";
    defaultParamMap["1_key_name"] = "1KEY";
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
    defaultParamMap["2_key_modline_table"] = "None";
    defaultParamMap["2_key_modline_gain"] = 1.00;
    defaultParamMap["2_key_modline_min"] = 1;
    defaultParamMap["2_key_modline_max"] = 127;
    defaultParamMap["2_key_modline_slew"] = 0;
    defaultParamMap["2_key_modline_destination"] = "None";
    defaultParamMap["2_key_modline_cc"] = 0;
    defaultParamMap["2_key_modline2_source"] = "None";
    defaultParamMap["2_key_modline2_min"] = 1;
    defaultParamMap["2_key_modline2_max"] = 127;
    defaultParamMap["2_key_modline2_destination"] = "None";
    defaultParamMap["2_key_modline2_cc"] = 0;
    defaultParamMap["2_key_setting_yAccel"] = 85;
    defaultParamMap["2_key_led_green"] = "None";
    defaultParamMap["2_key_led_red"] ="None";
    defaultParamMap["2_key_source"] = "None";
    defaultParamMap["2_key_name"] = "2KEY";
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
    defaultParamMap["3_key_modline_table"] = "None";
    defaultParamMap["3_key_modline_gain"] = 1.00;
    defaultParamMap["3_key_modline_min"] = 1;
    defaultParamMap["3_key_modline_max"] = 127;
    defaultParamMap["3_key_modline_slew"] = 0;
    defaultParamMap["3_key_modline_destination"] = "None";
    defaultParamMap["3_key_modline_cc"] = 0;
    defaultParamMap["3_key_modline2_source"] = "None";
    defaultParamMap["3_key_modline2_min"] = 1;
    defaultParamMap["3_key_modline2_max"] = 127;
    defaultParamMap["3_key_modline2_destination"] = "None";
    defaultParamMap["3_key_modline2_cc"] = 0;
    defaultParamMap["3_key_setting_yAccel"] = 85;
    defaultParamMap["3_key_led_green"] = "None";
    defaultParamMap["3_key_led_red"] ="None";
    defaultParamMap["3_key_source"] = "None";
    defaultParamMap["3_key_name"] = "3KEY";
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
    defaultParamMap["4_key_modline_table"] = "None";
    defaultParamMap["4_key_modline_gain"] = 1.00;
    defaultParamMap["4_key_modline_min"] = 1;
    defaultParamMap["4_key_modline_max"] = 127;
    defaultParamMap["4_key_modline_slew"] = 0;
    defaultParamMap["4_key_modline_destination"] = "None";
    defaultParamMap["4_key_modline_cc"] = 0;
    defaultParamMap["4_key_modline2_source"] = "None";
    defaultParamMap["4_key_modline2_min"] = 1;
    defaultParamMap["4_key_modline2_max"] = 127;
    defaultParamMap["4_key_modline2_destination"] = "None";
    defaultParamMap["4_key_modline2_cc"] = 0;
    defaultParamMap["4_key_setting_yAccel"] = 85;
    defaultParamMap["4_key_led_green"] = "None";
    defaultParamMap["4_key_led_red"] ="None";
    defaultParamMap["4_key_source"] = "None";
    defaultParamMap["4_key_name"] = "4KEY";
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
    defaultParamMap["5_key_modline_table"] = "None";
    defaultParamMap["5_key_modline_gain"] = 1.00;
    defaultParamMap["5_key_modline_min"] = 1;
    defaultParamMap["5_key_modline_max"] = 127;
    defaultParamMap["5_key_modline_slew"] = 0;
    defaultParamMap["5_key_modline_destination"] = "None";
    defaultParamMap["5_key_modline_cc"] = 0;
    defaultParamMap["5_key_modline2_source"] = "None";
    defaultParamMap["5_key_modline2_min"] = 1;
    defaultParamMap["5_key_modline2_max"] = 127;
    defaultParamMap["5_key_modline2_destination"] = "None";
    defaultParamMap["5_key_modline2_cc"] = 0;
    defaultParamMap["5_key_setting_yAccel"] = 85;
    defaultParamMap["5_key_led_green"] = "None";
    defaultParamMap["5_key_led_red"] ="None";
    defaultParamMap["5_key_source"] = "None";
    defaultParamMap["5_key_name"] = "5KEY";
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
    defaultParamMap["6_key_modline_table"] = "None";
    defaultParamMap["6_key_modline_gain"] = 1.00;
    defaultParamMap["6_key_modline_min"] = 1;
    defaultParamMap["6_key_modline_max"] = 127;
    defaultParamMap["6_key_modline_slew"] = 0;
    defaultParamMap["6_key_modline_destination"] = "None";
    defaultParamMap["6_key_modline_cc"] = 0;
    defaultParamMap["6_key_modline2_source"] = "None";
    defaultParamMap["6_key_modline2_min"] = 1;
    defaultParamMap["6_key_modline2_max"] = 127;
    defaultParamMap["6_key_modline2_destination"] = "None";
    defaultParamMap["6_key_modline2_cc"] = 0;
    defaultParamMap["6_key_setting_yAccel"] = 85;
    defaultParamMap["6_key_led_green"] = "None";
    defaultParamMap["6_key_led_red"] ="None";
    defaultParamMap["6_key_source"] = "None";
    defaultParamMap["6_key_name"] = "6KEY";
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
    defaultParamMap["7_key_modline_table"] = "None";
    defaultParamMap["7_key_modline_gain"] = 1.00;
    defaultParamMap["7_key_modline_min"] = 1;
    defaultParamMap["7_key_modline_max"] = 127;
    defaultParamMap["7_key_modline_slew"] = 0;
    defaultParamMap["7_key_modline_destination"] = "None";
    defaultParamMap["7_key_modline_cc"] = 0;
    defaultParamMap["7_key_modline2_source"] = "None";
    defaultParamMap["7_key_modline2_min"] = 1;
    defaultParamMap["7_key_modline2_max"] = 127;
    defaultParamMap["7_key_modline2_destination"] = "None";
    defaultParamMap["7_key_modline2_cc"] = 0;
    defaultParamMap["7_key_setting_yAccel"] = 85;
    defaultParamMap["7_key_led_green"] = "None";
    defaultParamMap["7_key_led_red"] ="None";
    defaultParamMap["7_key_source"] = "None";
    defaultParamMap["7_key_name"] = "7KEY";
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
    defaultParamMap["8_key_modline_table"] = "None";
    defaultParamMap["8_key_modline_gain"] = 1.00;
    defaultParamMap["8_key_modline_min"] = 1;
    defaultParamMap["8_key_modline_max"] = 127;
    defaultParamMap["8_key_modline_slew"] = 0;
    defaultParamMap["8_key_modline_destination"] = "None";
    defaultParamMap["8_key_modline_cc"] = 0;
    defaultParamMap["8_key_modline2_source"] = "None";
    defaultParamMap["8_key_modline2_min"] = 1;
    defaultParamMap["8_key_modline2_max"] = 127;
    defaultParamMap["8_key_modline2_destination"] = "None";
    defaultParamMap["8_key_modline2_cc"] = 0;
    defaultParamMap["8_key_setting_yAccel"] = 85;
    defaultParamMap["8_key_led_green"] = "None";
    defaultParamMap["8_key_led_red"] ="None";
    defaultParamMap["8_key_source"] = "None";
    defaultParamMap["8_key_name"] = "8KEY";
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
    defaultParamMap["9_key_modline_table"] = "None";
    defaultParamMap["9_key_modline_gain"] = 1.00;
    defaultParamMap["9_key_modline_min"] = 1;
    defaultParamMap["9_key_modline_max"] = 127;
    defaultParamMap["9_key_modline_slew"] = 0;
    defaultParamMap["9_key_modline_destination"] = "None";
    defaultParamMap["9_key_modline_cc"] = 0;
    defaultParamMap["9_key_modline2_source"] = "None";
    defaultParamMap["9_key_modline2_min"] = 1;
    defaultParamMap["9_key_modline2_max"] = 127;
    defaultParamMap["9_key_modline2_destination"] = "None";
    defaultParamMap["9_key_modline2_cc"] = 0;
    defaultParamMap["9_key_setting_yAccel"] = 85;
    defaultParamMap["9_key_led_green"] = "None";
    defaultParamMap["9_key_led_red"] ="None";
    defaultParamMap["9_key_source"] = "None";
    defaultParamMap["9_key_name"] = "9KEY";
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




}

void PresetInterface::slotRecallPreset(int i)
{
    settings->setValue("lastPreset", i);

    i -= 1;
    qDebug() << "recall preset" << i;
    currentPresetNum = i;

    QMapIterator<QString, QVariant> p(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());

    while (p.hasNext())
    {
        p.next();
    }

    emit signalRecallPreset(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());
}

void PresetInterface::slotStoreGlobal()
{
    //QString name;
    QVariant value;

    QString senderName = QObject::sender()->objectName();

    qDebug() << senderName;

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

    if(senderName.contains("sensitivity") || senderName.contains("backlight"))
    {
        //--------------------------------------------- Set for All Presets
        for(int i = 0; i < NUM_PRESETS; i++)
        {
            slotStoreValue(senderName, value, i);
        }
    }
    else
    {
        slotStoreValue(senderName, value, currentPresetNum);
    }
}

void PresetInterface::slotUpdateClicked()
{
    qDebug() << "update with this preset" << currentPresetNum;
    emit signalUpdateStarted(); //disable the button then start the download
    emit signalAttributeFormatPreset(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());
}

void PresetInterface::closeEvent(QCloseEvent *)
{
    //qDebug() << "closing...";
}
