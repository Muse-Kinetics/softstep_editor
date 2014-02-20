// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef NAVKEY_H
#define NAVKEY_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#include "navmodline.h"
#include "stylesheets.h"

#ifdef Q_OS_MAC
#include "ui_navKeyWindowForm.h"
#include "ui_navBoxForm.h"
#else
#include "ui_navKeyWindowFormWin.h"
#include "ui_navBoxFormWin.h"
#endif

#include "hosted/navdatacooker.h"
#include "hosted/alphanummanager.h"
//#include "hosted/ledmanager.h"
#include "hosted/staterecall.h"

class NavKey : public QWidget
{
    Q_OBJECT
public:
    explicit NavKey(QWidget *parent = 0);

    QWidget* navKeyWindowWidget;
    QWidget* navBoxWidget;

    //Ui Elements
    NavModline *navModline[6];
    QButtonGroup displayLinkedButtonGroup;

    int numModlines;
    QString mode;

    //--------------------------------------- Hosted
    NavDataCooker dataCooker;
    AlphaNumManager alphaNumManager;
    //LEDManager ledManager;
    StateRecall stateRecaller;

    int counter;

    QString currentPreset;
    QWidget *disableOverlay;
    
signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();
    void signalDeleteModline(int numModlines, bool disable);

    void signalCounterValue(int val);
    
public slots:
    void slotOpenWindow();
    void slotConnectElements();
    void slotDisconnectElements();
    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);

    void slotSetMode(QString m);
    void slotPopulateMenus(QStringList displayModes);

    //--------------------------------------- Hosted
    void slotSetDataCookerSettings();
    void slotSetAlphaNumSettings();

    void slotCounter(QString whatToDo, int val);

    //window resizing functions for the add/subtract buttons and the display settings button
    void slotShowDisplaySettings(bool);
    void slotRecallShowModlines(QVariantMap, QVariantMap);
    void slotAddSubtractModlines();
    void slotWindowHeight(int);

    void slotSetPresetName(QString);

    //Program Change Mode
    void slotUpdateModlineMode();
    void slotDisplayProgramChangeDecade(int);

private:
    Ui::navBoxForm *navBoxForm;
    Ui::navKeyWindowForm *navKeyWindowForm;
    
};

#endif // NAVKEY_H
