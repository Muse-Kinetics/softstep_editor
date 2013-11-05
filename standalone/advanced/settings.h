// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#include <CoreMIDI/CoreMIDI.h>

#include "qjson/src/parser.h"
#include "qjson/src/serializer.h"

#include "ui_settingsForm.h"

#include "hosted/midiinput.h"
#include "pedal.h"

#define NUM_MIDI_INPUTS 8

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);

    //QString mode;

    QWidget* settingsWidget;

    QList<QComboBox *> midiInputDeviceMenus;

    MidiInput midiInputLine[NUM_MIDI_INPUTS];

    QVariantMap settings;
    QVariantMap defaultGlobalMap;

    QJson::Parser parser;
    QJson::Serializer serializer;

    QString jsonPath;
    QFile *josnFile;
    bool ok;

    //bool eventFilter(QObject *obj, QEvent *event);

    Pedal* pedal;
    
signals:
    void signalStoreValue(QString name, QVariant value);
    void signalRecallSettings(QVariantMap preset, QVariantMap settings);
    
public slots:
    void slotOpenSettings();
    //void slotInitComponents();
    void slotConnectElements();
    void slotDisconnectElements();
    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);
    void slotRecallSettings();
    void slotViewSelector();

    //void slotSetMode(QString m);
    void slotPopulateInputMenus(QMap<QString,MIDIEndpointRef> midiSources);
    //void slotCompileSettings();

    void slotSetMidiInputLineParams();

    void slotSetJSONPath();
    void slotReadSettings();
    void slotWriteSettings();
    void slotWriteDefaultSettings();
    void slotStoreSettings(QString name, QVariant value);
    void slotConstructSettingsDefaultMap();

private:
    Ui::settingsForm *settingsForm;
    
};

#endif // SETTINGS_H
