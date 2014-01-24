// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef IMPORTOLDPRESETHANDLER_H
#define IMPORTOLDPRESETHANDLER_H

#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QtGui>
#include <QDesktopServices>
#include <QUrl>

#include "presetinterface.h"

class ImportOldPresetHandler : public QObject
{
    Q_OBJECT
public:
    explicit ImportOldPresetHandler(PresetInterface *pi, QObject *parent = 0);

    PresetInterface *presetInterface;

    //QJson::Parser   parser;

    //QFile *jsonFile;
    bool ok;

    QString presetName;
    QVariantMap importedOldPresetMap;
    QVariantMap importedNewPresetMap;

    QString mode;
    
signals:
    void signalPresetMenu(int numPresets);
    void signalAddRemovePreset();
    
public slots:
    void slotImportOldPreset();
    QVariantMap slotConvertPreset();
    QString slotListErrorCompensation(QList<QVariant> stringList);
    QString slotGetNewTableValue(QString oldValue);
    QString slotGetOldDestinationParam(QString newParam, int keyNum, int modlineNum);
    void slotSetMode(QString m);
};

#endif // IMPORTOLDPRESETHANDLER_H
