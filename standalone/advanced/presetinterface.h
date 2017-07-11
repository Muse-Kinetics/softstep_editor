// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef PRESETINTERFACE_H
#define PRESETINTERFACE_H

#include <QWidget>
#include <QDebug>
#include <QVariant>
#include <QtGui>
#include <QComboBox>

#include "qjson/src/parser.h"
#include "qjson/src/serializer.h"

class PresetInterface : public QWidget
{
    Q_OBJECT
public:
    explicit PresetInterface(QWidget *parent = 0);

    QString mode;

    QVariantMap jsonMasterMap;
    QList<QVariantMap> presetListMaster;

    QVariantMap jsonMasterMapCopy;
    QList<QVariantMap> presetListCopy;

    QVariantMap defaultPresetMap;
    QVariantMap defaultGlobalMap;



    QJson::Parser       parser;
    QJson::Serializer   serializer;

    QFile *jsonFile;
    bool ok;

    QString jsonPath;

    int     currentPresetNum;
    QVariantMap currentPresetMap;

    void closeEvent(QCloseEvent *);

    void writeDefualtJSON();

    QVariantMap getPresetMap(int presetNum);
    
signals:
    void signalRecallPreset(QVariantMap preset, QVariantMap jsonMasterMapCopy);
    void signalPopulateSetlistMenus(QComboBox* presetMenu);
    void signalAddRemovePreset();
    void signalPresetDirty(bool);
    void signalPresetMenu(int goToPresetNum);
    void signalDisableModline(QString parameterName);
    void signalModlineWarning(QString modlineWarningMessage);
    
public slots:
    void slotStoreValue(QString name, QVariant value, int presetNum);
    void slotCheckSaveState();
    void slotModlineWarning(QString parameterName);

    void slotUpdateJSONPath();
    void slotReadJSON();
    void slotWriteJSON(QVariantMap jsonMap);

    void slotConstructDefaultStandaloneMap();
    void slotConstructDefaultHostedMap();
    void slotRecallPreset(int i);

    void slotSavePreset();
    void slotSavePresetAs(QString presetName);
    void slotDeletePreset();
    void slotPopulatePresetLists();
    void slotRevertPreset();

    void slotImportPreset();
    void slotExportPreset();

    void slotPopulatePresetMenu(QComboBox* presetMenu);
    void slotPopulateSetlistMenus();

    QString slotGetPresetStringFromInt(int);
    void slotOrderPresetsInJson();
    int slotGetNumPresetsInJson();

    void slotSetMode(QString);
};

#endif // PRESETINTERFACE_H
