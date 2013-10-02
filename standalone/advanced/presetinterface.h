// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef PRESETINTERFACE_H
#define PRESETINTERFACE_H

#include <QWidget>
#include <QDebug>
#include <QVariant>
#include <QtGui>

#include "qjson/src/parser.h"
#include "qjson/src/serializer.h"

class PresetInterface : public QWidget
{
    Q_OBJECT
public:
    explicit PresetInterface(QWidget *parent = 0);

    QVariantMap jsonMasterMap;
    QVariantMap jsonMasterMapCopy;
    QVariantMap defaultPresetMap;
    QVariantMap defaultGlobalMap;

    QSettings *settings;

    QJson::Parser       parser;
    QJson::Serializer   serializer;

    QFile *jsonFile;
    bool ok;

    QString jsonPath;

    int     currentPresetNum;
    QVariantMap currentPresetMap;

    void closeEvent(QCloseEvent *);

    void writeDefualtJSON();
    
signals:
    void signalRecallPreset(QVariantMap preset, QVariantMap jsonMasterMapCopy);
    void signalRecallGlobal(QVariantMap preset, QVariantMap jsonMasterMapCopy);
    
public slots:
    void slotStoreValue(QString name, QVariant value, int presetNum);
    void slotStoreGlobal(QString name, QVariant value);
    void slotCheckSaveState();

    void slotReadJSON();
    void slotWriteJSON(QVariantMap jsonMap);

    void slotConstructDefaultMap();
    void slotConstructGlobalDefaultMap();
    void slotRecallPreset(int i);
    void slotRecallGlobal();

    void slotUpdateClicked();
    
};

#endif // PRESETINTERFACE_H
