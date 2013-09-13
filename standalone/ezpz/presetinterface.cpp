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
    //Globals
    defaultParamMap["midiChannel"] = 1;
    defaultParamMap["sensitivity"] = 1.00;
    defaultParamMap["navPadCC"] = 7;
    defaultParamMap["pedalCC"] = 26;
    defaultParamMap["backlight"] = true;
    defaultParamMap["displayName"] = "EASY";

    //0
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "0KEY";
    defaultParamMap["0_noteNum"] = 60;
    defaultParamMap["0_noteVelocity"] = 127;
    defaultParamMap["0_noteToggle"] = 1;
    defaultParamMap["0_pressureCC"] = 20;
    defaultParamMap["0_pressureSmooth"] = 0;
    defaultParamMap["0_toggleCC"] = 21;
    defaultParamMap["0_toggleLo"] = 0;
    defaultParamMap["0_toggleHi"] = 127;
    defaultParamMap["0_xyXCC"] = 22;
    defaultParamMap["0_xyYCC"] = 23;
    defaultParamMap["0_xyLatch"] = 0;
    defaultParamMap["0_yIncCC"] = 24;
    defaultParamMap["0_yIncSpeed"] = 0;
    defaultParamMap["0_programNum"] = 0;
    defaultParamMap["0_programBank"] = 0;

    //1
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "1KEY";
    defaultParamMap["1_noteNum"] = 61;
    defaultParamMap["1_noteVelocity"] = 127;
    defaultParamMap["1_noteToggle"] = 1;
    defaultParamMap["1_pressureCC"] = 20;
    defaultParamMap["1_pressureSmooth"] = 0;
    defaultParamMap["1_toggleCC"] = 21;
    defaultParamMap["1_toggleLo"] = 0;
    defaultParamMap["1_toggleHi"] = 127;
    defaultParamMap["1_xyXCC"] = 22;
    defaultParamMap["1_xyYCC"] = 23;
    defaultParamMap["1_xyLatch"] = 0;
    defaultParamMap["1_yIncCC"] = 24;
    defaultParamMap["1_yIncSpeed"] = 0;
    defaultParamMap["1_programNum"] = 0;
    defaultParamMap["1_programBank"] = 0;

    //2
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "2KEY";
    defaultParamMap["2_noteNum"] = 62;
    defaultParamMap["2_noteVelocity"] = 127;
    defaultParamMap["2_noteToggle"] = 1;
    defaultParamMap["2_pressureCC"] = 20;
    defaultParamMap["2_pressureSmooth"] = 0;
    defaultParamMap["2_toggleCC"] = 21;
    defaultParamMap["2_toggleLo"] = 0;
    defaultParamMap["2_toggleHi"] = 127;
    defaultParamMap["2_xyXCC"] = 22;
    defaultParamMap["2_xyYCC"] = 23;
    defaultParamMap["2_xyLatch"] = 0;
    defaultParamMap["2_yIncCC"] = 24;
    defaultParamMap["2_yIncSpeed"] = 0;
    defaultParamMap["2_programNum"] = 0;
    defaultParamMap["2_programBank"] = 0;

    //3
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "3KEY";
    defaultParamMap["3_noteNum"] = 63;
    defaultParamMap["3_noteVelocity"] = 127;
    defaultParamMap["3_noteToggle"] = 1;
    defaultParamMap["3_pressureCC"] = 20;
    defaultParamMap["3_pressureSmooth"] = 0;
    defaultParamMap["3_toggleCC"] = 21;
    defaultParamMap["3_toggleLo"] = 0;
    defaultParamMap["3_toggleHi"] = 127;
    defaultParamMap["3_xyXCC"] = 22;
    defaultParamMap["3_xyYCC"] = 23;
    defaultParamMap["3_xyLatch"] = 0;
    defaultParamMap["3_yIncCC"] = 24;
    defaultParamMap["3_yIncSpeed"] = 0;
    defaultParamMap["3_programNum"] = 0;
    defaultParamMap["3_programBank"] = 0;

    //4
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "4KEY";
    defaultParamMap["4_noteNum"] = 64;
    defaultParamMap["4_noteVelocity"] = 127;
    defaultParamMap["4_noteToggle"] = 1;
    defaultParamMap["4_pressureCC"] = 20;
    defaultParamMap["4_pressureSmooth"] = 0;
    defaultParamMap["4_toggleCC"] = 21;
    defaultParamMap["4_toggleLo"] = 0;
    defaultParamMap["4_toggleHi"] = 127;
    defaultParamMap["4_xyXCC"] = 22;
    defaultParamMap["4_xyYCC"] = 23;
    defaultParamMap["4_xyLatch"] = 0;
    defaultParamMap["4_yIncCC"] = 24;
    defaultParamMap["4_yIncSpeed"] = 0;
    defaultParamMap["4_programNum"] = 0;
    defaultParamMap["4_programBank"] = 0;

    //5
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "5KEY";
    defaultParamMap["5_noteNum"] = 65;
    defaultParamMap["5_noteVelocity"] = 127;
    defaultParamMap["5_noteToggle"] = 1;
    defaultParamMap["5_pressureCC"] = 20;
    defaultParamMap["5_pressureSmooth"] = 0;
    defaultParamMap["5_toggleCC"] = 21;
    defaultParamMap["5_toggleLo"] = 0;
    defaultParamMap["5_toggleHi"] = 127;
    defaultParamMap["5_xyXCC"] = 22;
    defaultParamMap["5_xyYCC"] = 23;
    defaultParamMap["5_xyLatch"] = 0;
    defaultParamMap["5_yIncCC"] = 24;
    defaultParamMap["5_yIncSpeed"] = 0;
    defaultParamMap["5_programNum"] = 0;
    defaultParamMap["5_programBank"] = 0;

    //6
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "6KEY";
    defaultParamMap["6_noteNum"] = 66;
    defaultParamMap["6_noteVelocity"] = 127;
    defaultParamMap["6_noteToggle"] = 1;
    defaultParamMap["6_pressureCC"] = 20;
    defaultParamMap["6_pressureSmooth"] = 0;
    defaultParamMap["6_toggleCC"] = 21;
    defaultParamMap["6_toggleLo"] = 0;
    defaultParamMap["6_toggleHi"] = 127;
    defaultParamMap["6_xyXCC"] = 22;
    defaultParamMap["6_xyYCC"] = 23;
    defaultParamMap["6_xyLatch"] = 0;
    defaultParamMap["6_yIncCC"] = 24;
    defaultParamMap["6_yIncSpeed"] = 0;
    defaultParamMap["6_programNum"] = 0;
    defaultParamMap["6_programBank"] = 0;

    //7
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "7KEY";
    defaultParamMap["7_noteNum"] = 67;
    defaultParamMap["7_noteVelocity"] = 127;
    defaultParamMap["7_noteToggle"] = 1;
    defaultParamMap["7_pressureCC"] = 20;
    defaultParamMap["7_pressureSmooth"] = 0;
    defaultParamMap["7_toggleCC"] = 21;
    defaultParamMap["7_toggleLo"] = 0;
    defaultParamMap["7_toggleHi"] = 127;
    defaultParamMap["7_xyXCC"] = 22;
    defaultParamMap["7_xyYCC"] = 23;
    defaultParamMap["7_xyLatch"] = 0;
    defaultParamMap["7_yIncCC"] = 24;
    defaultParamMap["7_yIncSpeed"] = 0;
    defaultParamMap["7_programNum"] = 0;
    defaultParamMap["7_programBank"] = 0;

    //8
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "8KEY";
    defaultParamMap["8_noteNum"] = 68;
    defaultParamMap["8_noteVelocity"] = 127;
    defaultParamMap["8_noteToggle"] = 1;
    defaultParamMap["8_pressureCC"] = 20;
    defaultParamMap["8_pressureSmooth"] = 0;
    defaultParamMap["8_toggleCC"] = 21;
    defaultParamMap["8_toggleLo"] = 0;
    defaultParamMap["8_toggleHi"] = 127;
    defaultParamMap["8_xyXCC"] = 22;
    defaultParamMap["8_xyYCC"] = 23;
    defaultParamMap["8_xyLatch"] = 0;
    defaultParamMap["8_yIncCC"] = 24;
    defaultParamMap["8_yIncSpeed"] = 0;
    defaultParamMap["8_programNum"] = 0;
    defaultParamMap["8_programBank"] = 0;

    //9
    defaultParamMap["source"] = "None";
    defaultParamMap["name"] = "9KEY";
    defaultParamMap["9_noteNum"] = 69;
    defaultParamMap["9_noteVelocity"] = 127;
    defaultParamMap["9_noteToggle"] = 1;
    defaultParamMap["9_pressureCC"] = 20;
    defaultParamMap["9_pressureSmooth"] = 0;
    defaultParamMap["9_toggleCC"] = 21;
    defaultParamMap["9_toggleLo"] = 0;
    defaultParamMap["9_toggleHi"] = 127;
    defaultParamMap["9_xyXCC"] = 22;
    defaultParamMap["9_xyYCC"] = 23;
    defaultParamMap["9_xyLatch"] = 0;
    defaultParamMap["9_yIncCC"] = 24;
    defaultParamMap["9_yIncSpeed"] = 0;
    defaultParamMap["9_programNum"] = 0;
    defaultParamMap["9_programBank"] = 0;
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
