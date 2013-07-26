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
    jsonPath.append("Resources/presets/SoftStepEasyEditor.json");
#else
    jsonPath = QString("./presets/SoftStepEasyEditor.json");
#endif

    slotReadJSON();
    slotConstructDefaultMap();
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
    defaultParamMap["Global_Gain"] =  1.5;
    defaultParamMap["Global_Pedal_CC"] = 7 ;
    defaultParamMap["Global_Backlight"] = 1 ;
    defaultParamMap["Global_Midi_Channel"] = 1 ;
    defaultParamMap["Global_Scene_Name"] = "EASY";
    defaultParamMap["0_Key_Source"] = "Foot On" ;
    defaultParamMap["0_Key_Foot_On"] = 0 ;
    defaultParamMap["0_Key_Pressure_Live"] = 1 ;
    defaultParamMap["0_Key_Y_Increment"] = 0 ;
    defaultParamMap["0_Key_Toggle"] = 0 ;
    defaultParamMap["0_Key_X_Live"] = 0 ;
    defaultParamMap["0_Key_CC"] = 21 ;
    defaultParamMap["0_Key_Smooth"] = 0 ;
    defaultParamMap["0_Key_Prefix"] = "_" ;
    defaultParamMap["0_Key_Display_Mode"] = 1 ;
    defaultParamMap["0_Key_On"] = 1 ;
    defaultParamMap["0_Key_Table"] = "1_Lin" ;
    defaultParamMap["0_Key_Key_Name"] = "PRS1" ;
    defaultParamMap["1_Key_Source"] = "Foot On" ;
    defaultParamMap["1_Key_Foot_On"] = 0 ;
    defaultParamMap["1_Key_Pressure_Live"] = 1 ;
    defaultParamMap["1_Key_Y_Increment"] = 0 ;
    defaultParamMap["1_Key_Toggle"] = 0 ;
    defaultParamMap["1_Key_X_Live"] = 0 ;
    defaultParamMap["1_Key_CC"] = 21 ;
    defaultParamMap["1_Key_Smooth"] = 0 ;
    defaultParamMap["1_Key_Prefix"] = "_" ;
    defaultParamMap["1_Key_Display_Mode"] = 1 ;
    defaultParamMap["1_Key_On"] = 1 ;
    defaultParamMap["1_Key_Table"] = "1_Lin" ;
    defaultParamMap["1_Key_Key_Name"] = "PRS1" ;
    defaultParamMap["2_Key_Source"] = "Foot On" ;
    defaultParamMap["2_Key_Foot_On"] = 0 ;
    defaultParamMap["2_Key_Pressure_Live"] = 1 ;
    defaultParamMap["2_Key_Y_Increment"] = 0 ;
    defaultParamMap["2_Key_Toggle"] = 0 ;
    defaultParamMap["2_Key_X_Live"] = 0 ;
    defaultParamMap["2_Key_CC"] = 22 ;
    defaultParamMap["2_Key_Smooth"] = 0 ;
    defaultParamMap["2_Key_Prefix"] = "_" ;
    defaultParamMap["2_Key_Display_Mode"] = 1 ;
    defaultParamMap["2_Key_On"] = 1 ;
    defaultParamMap["2_Key_Table"] = "1_Lin" ;
    defaultParamMap["2_Key_Key_Name"] = "PRS2" ;
    defaultParamMap["3_Key_Source"] = "Foot On" ;
    defaultParamMap["3_Key_Foot_On"] = 0 ;
    defaultParamMap["3_Key_Pressure_Live"] = 1 ;
    defaultParamMap["3_Key_Y_Increment"] = 0 ;
    defaultParamMap["3_Key_Toggle"] = 0 ;
    defaultParamMap["3_Key_X_Live"] = 0 ;
    defaultParamMap["3_Key_CC"] = 23 ;
    defaultParamMap["3_Key_Smooth"] = 0 ;
    defaultParamMap["3_Key_Prefix"] = "_" ;
    defaultParamMap["3_Key_Display_Mode"] = 1 ;
    defaultParamMap["3_Key_On"] = 1 ;
    defaultParamMap["3_Key_Table"] = "1_Lin" ;
    defaultParamMap["3_Key_Key_Name"] = "PRS3" ;
    defaultParamMap["4_Key_Source"] = "Foot On" ;
    defaultParamMap["4_Key_Foot_On"] = 0 ;
    defaultParamMap["4_Key_Pressure_Live"] = 1 ;
    defaultParamMap["4_Key_Y_Increment"] = 0 ;
    defaultParamMap["4_Key_Toggle"] = 0 ;
    defaultParamMap["4_Key_X_Live"] = 0 ;
    defaultParamMap["4_Key_CC"] = 24 ;
    defaultParamMap["4_Key_Smooth"] = 0 ;
    defaultParamMap["4_Key_Prefix"] = "_" ;
    defaultParamMap["4_Key_Display_Mode"] = 1 ;
    defaultParamMap["4_Key_On"] = 1 ;
    defaultParamMap["4_Key_Table"] = "1_Lin" ;
    defaultParamMap["4_Key_Key_Name"] = "PRS4" ;
    defaultParamMap["5_Key_Source"] = "Foot On" ;
    defaultParamMap["5_Key_Foot_On"] = 0 ;
    defaultParamMap["5_Key_Pressure_Live"] = 1 ;
    defaultParamMap["5_Key_Y_Increment"] = 0 ;
    defaultParamMap["5_Key_Toggle"] = 0 ;
    defaultParamMap["5_Key_X_Live"] = 0 ;
    defaultParamMap["5_Key_CC"] = 25 ;
    defaultParamMap["5_Key_Smooth"] = 0 ;
    defaultParamMap["5_Key_Prefix"] = "_" ;
    defaultParamMap["5_Key_Display_Mode"] = 1 ;
    defaultParamMap["5_Key_On"] = 1 ;
    defaultParamMap["5_Key_Table"] = "1_Lin" ;
    defaultParamMap["5_Key_Key_Name"] = "PRS5" ;
    defaultParamMap["6_Key_Source"] = "Foot On" ;
    defaultParamMap["6_Key_Foot_On"] = 0 ;
    defaultParamMap["6_Key_Pressure_Live"] = 0 ;
    defaultParamMap["6_Key_Y_Increment"] = 0 ;
    defaultParamMap["6_Key_Toggle"] = 1 ;
    defaultParamMap["6_Key_X_Live"] = 0 ;
    defaultParamMap["6_Key_CC"] = 26 ;
    defaultParamMap["6_Key_Smooth"] = 0 ;
    defaultParamMap["6_Key_Prefix"] = "_" ;
    defaultParamMap["6_Key_Display_Mode"] = 1 ;
    defaultParamMap["6_Key_On"] = 1 ;
    defaultParamMap["6_Key_Table"] = "Toggle_127" ;
    defaultParamMap["6_Key_Key_Name"] = "TOG6" ;
    defaultParamMap["7_Key_Source"] = "Foot On" ;
    defaultParamMap["7_Key_Foot_On"] = 0 ;
    defaultParamMap["7_Key_Pressure_Live"] = 0 ;
    defaultParamMap["7_Key_Y_Increment"] = 0 ;
    defaultParamMap["7_Key_Toggle"] = 1 ;
    defaultParamMap["7_Key_X_Live"] = 0 ;
    defaultParamMap["7_Key_CC"] = 27 ;
    defaultParamMap["7_Key_Smooth"] = 0 ;
    defaultParamMap["7_Key_Prefix"] = "_" ;
    defaultParamMap["7_Key_Display_Mode"] = 1 ;
    defaultParamMap["7_Key_On"] = 1 ;
    defaultParamMap["7_Key_Table"] = "Toggle_127" ;
    defaultParamMap["7_Key_Key_Name"] = "TOG7" ;
    defaultParamMap["8_Key_Source"] = "Foot On" ;
    defaultParamMap["8_Key_Foot_On"] = 0 ;
    defaultParamMap["8_Key_Pressure_Live"] = 0 ;
    defaultParamMap["8_Key_Y_Increment"] = 0 ;
    defaultParamMap["8_Key_Toggle"] = 1 ;
    defaultParamMap["8_Key_X_Live"] = 0 ;
    defaultParamMap["8_Key_CC"] = 28 ;
    defaultParamMap["8_Key_Smooth"] = 0 ;
    defaultParamMap["8_Key_Prefix"] = "_" ;
    defaultParamMap["8_Key_Display_Mode"] = 1 ;
    defaultParamMap["8_Key_On"] = 1 ;
    defaultParamMap["8_Key_Table"] = "Toggle_127" ;
    defaultParamMap["8_Key_Key_Name"] = "TOG8" ;
    defaultParamMap["9_Key_Source"] = "Foot On" ;
    defaultParamMap["9_Key_Foot_On"] = 0 ;
    defaultParamMap["9_Key_Pressure_Live"] = 0 ;
    defaultParamMap["9_Key_Y_Increment"] = 0 ;
    defaultParamMap["9_Key_Toggle"] = 1 ;
    defaultParamMap["9_Key_X_Live"] = 0 ;
    defaultParamMap["9_Key_CC"] = 29 ;
    defaultParamMap["9_Key_Smooth"] = 0 ;
    defaultParamMap["9_Key_Prefix"] = "_" ;
    defaultParamMap["9_Key_Display_Mode"] = 1 ;
    defaultParamMap["9_Key_On"] = 1 ;
    defaultParamMap["9_Key_Table"] = "Toggle_127" ;
    defaultParamMap["9_Key_Key_Name"] = "TOG9" ;

    defaultParamMap["10_Key_Source"] = "Foot On" ;
    defaultParamMap["10_Key_Foot_On"] = 0 ;
    defaultParamMap["10_Key_Pressure_Live"] = 0 ;
    defaultParamMap["10_Key_Y_Increment"] = 0 ;
    defaultParamMap["10_Key_Toggle"] = 1 ;
    defaultParamMap["10_Key_X_Live"] = 0 ;
    defaultParamMap["10_Key_CC"] = 29 ;
    defaultParamMap["10_Key_Smooth"] = 0 ;
    defaultParamMap["10_Key_Prefix"] = "_" ;
    defaultParamMap["10_Key_Display_Mode"] = 1 ;
    defaultParamMap["10_Key_On"] = 1 ;
    defaultParamMap["10_Key_Table"] = "Toggle_127" ;
    defaultParamMap["10_Key_Key_Name"] = "TOG9" ;

}

void PresetInterface::slotRecallPreset(int i)
{

    settings->setValue("lastPreset", i);

    i -= 1;
    qDebug() << "recall preset" << i;
    currentPresetNum = i;

    QMapIterator<QString, QVariant> p(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());

    while (p.hasNext()) {
        p.next();
        //qDebug() << p.key() << "-- : --" << p.value();
    }

    emit signalRecallPreset(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());
}

void PresetInterface::slotStoreGlobal()
{
    QString name;
    QVariant value;

    QString senderName = QObject::sender()->objectName();

    if(senderName == "midiChannel")
    {
        name = "Global_Midi_Channel";
        value = reinterpret_cast<QSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "gain")
    {
        name = "Global_Gain";
        value = reinterpret_cast<QDoubleSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "pedalCC")
    {
        name = "Global_Pedal_CC";
        value = reinterpret_cast<QSpinBox *>(QObject::sender())->value();
    }
    else if(senderName == "backlight")
    {
        name = "Global_Backlight";
        value = reinterpret_cast<QCheckBox *>(QObject::sender())->isChecked();
    }
    else if(senderName == "sceneName")
    {
        name = "Global_Scene_Name";
        value = reinterpret_cast<QLineEdit *>(QObject::sender())->text();
    }

    if(name.contains("Gain") || name.contains("Backlight"))
    {
        //--------------------------------------------- Set for All Presets
        for(int i = 0; i < NUM_PRESETS; i++)
        {
            slotStoreValue(name, value, i);
        }
    }
    else
    {
        slotStoreValue(name, value, currentPresetNum);
    }
}

void PresetInterface::slotUpdateClicked()
{
    qDebug() << "update with this preset" << currentPresetNum;
    emit signalAttributeFormatPreset(jsonMasterMap.value(QString("Preset_00%1").arg(currentPresetNum)).toMap());
}

void PresetInterface::closeEvent(QCloseEvent *)
{
    //qDebug() << "closing...";
}
