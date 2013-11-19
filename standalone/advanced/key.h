// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef KEY_H
#define KEY_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#include "modline.h"
#include "stylesheets.h"

#include "ui_keyWindowForm.h"
#include "ui_keyBoxForm.h"

#include "hosted/datacooker.h"
#include "hosted/alphanummanager.h"
#include "hosted/ledmanager.h"
#include "hosted/staterecall.h"

class Key : public QWidget
{
    Q_OBJECT
public:
    explicit Key(QWidget *parent = 0, int keyInstanceNum = 0);

    StateRecall stateRecaller;

    StyleSheets stylesheets;
    QButtonGroup displayLinkedButtonGroup;

    int keyInstance;

    QWidget* keyBoxWidget;
    QWidget* keyWindowWidget;

    //Ui Elements
    Modline *modline[6];

    int numModlines;

    //------------------ Hosted ------------------//
    DataCooker dataCooker;
    AlphaNumManager alphaNumManager;
    LEDManager ledManager;

    int counter;
    
signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();

    void signalCounterValue(int val);
    
public slots:
    void slotOpenWindow();
    void slotConnectElements();
    void slotDisconnectElements();
    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);

    void slotSetMode(QString mode);

    //------------------ Hosted ------------------//
    void slotSetDataCookerSettings();
    void slotSetAlphaNumSettings();

    void slotCounter(QString whatToDo, int val);


    //window resizing functions for the add/subtract buttons and the display settings button
    void slotShowDisplaySettings(bool);
    void slotRecallShowModlines(QVariantMap, QVariantMap);
    void slotAddSubtractModlines();
    void slotWindowHeight(int);

    void slotSetPresetName(QString);

private:
    Ui::keyBoxForm *keyBoxForm;
    Ui::keyWindowForm *keyWindowForm;
    
};

#endif // KEY_H
