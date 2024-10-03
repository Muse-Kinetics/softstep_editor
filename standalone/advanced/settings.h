// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>
#include "hosted/datacooker.h"

#ifdef Q_OS_MAC
//#include <CoreMIDI/CoreMIDI.h>

#include "ui_settingsForm.h"
#else
//#include <Windows.h>
//#include <MMSystem.h>
//#include <Dbt.h>
//#include "WindowsMidiTypes.h"

#include "ui_settingsFormWin.h"
#endif //Q_OS_MAC

//#include "qjson/src/parser.h"
//#include "qjson/src/serializer.h"

#include "hosted/midiinput.h"
#include "pedal.h"
#include "tableinterface.h"

#define NUM_MIDI_INPUTS 8

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);

    int ssHardware;
    QTimer *saveSettingsTimeout;

    QTimer *calibrationTicker;
    int calibrationTime;
    int calibrationBlinkTime;

    QWidget* settingsWidget;

    QList<QComboBox *> midiInputDeviceMenus;

    MidiInput midiInputLine[NUM_MIDI_INPUTS];

    QVariantMap settings;
    QVariantMap defaultGlobalMap;

//    QJson::Parser parser;
//    QJson::Serializer serializer;

    QString jsonPath;
    QFile *josnFile;
    bool ok;

    //------- Calibration
    TableInerface   *pedalLiveTableInterface;
    bool calibrating;
    QList<int> pedalValueListGraph;
    QList<int> pedalValueListTable;

    QString mode;

    //------ Form
    Ui::settingsForm *settingsForm;

    
signals:
    void signalUpdateSettings();
    void signalStoreValue(QString name, QVariant value);
    void signalRecallSettings(QVariantMap preset);

    //---- Globals
    void signalSetGlobalGain(float gain);
    void signalSetSensorResponse(int response);
    void signalSetKeySafetyMode(int mode);
    void signalSetDisplayMode(int mode);

    void signalSetSceneChanging(bool onOff); //Nav
    void signalSetBacklight(bool onOff);

    //---- Keys
    void signalSetKeyOnThresh(int key, int onThresh);
    void signalSetKeyOffThresh(int key, int offThresh);
    void signalSetKeyYDeadZone(int key, int deadZone);
    void signalSetKeyXDeadZone(int key, int deadZone);
    void signalSetKeyYAccel(int key, int accel);
    void signalSetKeyXAccel(int key, int accel);

    //---- Nav Pad
    void signalSetNavNorthOnThresh(int threshold);
    void signalSetNavNorthOffThresh(int threshold);

    void signalSetNavSouthOnThresh(int threshold);
    void signalSetNavSouthOffThresh(int threshold);

    void signalSetNavEastOnThresh(int threshold);
    void signalSetNavEastOffThresh(int threshold);

    void signalSetNavWestOnThresh(int threshold);
    void signalSetNavWestOffThresh(int threshold);

    void signalSetNavYIncAccel(int accel);

    void signalUpdateNRPNChannel(int);

    //---- Pedal Calibration
    void signalStartCalibration();
    void signalResetCalibration();
    void signalStopCalibration();
    void signalSetTestValueSlider(QSlider* slider);
    void signalInitPedalTable(QByteArray);
    void signalTetherOnOffInStandalone(bool);

    //---- MIDI Aux inputs
    void signalUpdateMIDIAuxDropdowns(QString jsonName, QString value);
    void signalUserChangedMIDIaux(QString, QString);

    //---- OSC
    void signalSetOscEnable(int inputNum, bool enabled);
    void signalSetOscAddress(int inputNum, QString addr);
    void signalSetOscIP(QString ipString);
    void signalSetOscOutPort(int outPort);
    void signalSetOscInPort(int inPort);

public slots:
    void slotSetMode(QString m);

    void slotCloseSettings();
    void slotOpenSettings();
    //void slotInitComponents();
    void slotConnectElements();
    void slotDisconnectElements();
    void slotValueChanged();
    void slotRecallPreset(QVariantMap);
    void slotRecallSettings();
    void slotViewSelector();
    void slotResetGlobalGain();
    void slotResetKeySeettings();

    //void slotSetMode(QString m);
    void slotPopulateInputMenus(QMap<QString, int> midiSources);
    //void slotCompileSettings();

    void slotSetMidiInputLineParams();

    void slotSetJSONPath();
    void slotReadSettings();
    void slotWriteSettings();
    void slotWriteDefaultSettings();
    void slotStoreSettings(QString name, QVariant value);
    void slotConstructSettingsDefaultMap();

    void slotEmitAllSettings();
    void slotSaveSettingsTimeout();

    //---- Pedal Calibration
    void slotStartCalibration();
    void slotStopCalibration();
    void slotResetCalibration();
    void slotLoadTableOnStartup();
    void slotWritePedalTableToDisk(QByteArray tableByteArray);
    void slotSetLiveValue(int val);
    void slotHideComplete();
    void slotStartCalibrationStandAlone();
    //void slotStopCalibrationStandAlone();

    //----- MIDI Aux Inputs
    void slotUserChangedMIDIaux();

    //----- OSC
    void slotSetOSCDisplayValue(int inputNum, int val);

    void slotSendSettingsMIDI();

//private:
//    Ui::settingsForm *settingsForm;
    
};

#endif // SETTINGS_H
