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

#include "ui_settingsForm.h"

#include "hosted/midiinput.h"
#include "pedal.h"

#define NUM_MIDI_INPUTS 8

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);

    QWidget* settingsWidget;

    QList<QComboBox *> midiInputDeviceMenus;

    MidiInput midiInputLine[NUM_MIDI_INPUTS];

    Pedal* pedal;
    
signals:
    void signalStoreValue(QString name, QVariant value);
    
public slots:
    void slotOpenSettings();
    void slotConnectElements();
    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);
    void slotViewSelector();

    void slotSetMode(QString m);
    void slotPopulateInputMenus(QMap<QString,MIDIEndpointRef> midiSources);

    void slotSetMidiInputLineParams();

private:
    Ui::settingsForm *settingsForm;
    
};

#endif // SETTINGS_H
