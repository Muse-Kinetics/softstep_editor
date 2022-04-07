// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef COPYPASTEHANDLER_H
#define COPYPASTEHANDLER_H

#include <QObject>
#include <QVariant>
#include <QtGui>
#include <QDesktopServices>
#include <QUrl>

#include "presetinterface.h"
//#include "mididevicemanager.h"

//#include "qjson/src/parser.h"

class CopyPasteHandler : public QObject
{
    Q_OBJECT
public:
    explicit CopyPasteHandler(PresetInterface *presetInterfacer, QObject *parent = 0);

    PresetInterface *presetInterface;

    QVariantMap presetCopiedMap;
    QVariantMap keyCopiedMap;

//    QJson::Parser parser;

    QString mode;

    bool ok;

    int currentKeyNumber;
    
signals:
    void signalUpdatePasteAvailability();
    void signalAddRemovePreset();
    void signalPresetMenu(int numPresets);
    void signalModlineWarning(QString modlineWarningMessage);
    void signalSetSelectedKey(int keyNum);
    
public slots:
    void slotClearPreset();
    void slotCopyPreset();
    void slotPasteNewPreset();
    void slotPastePreset();
    void slotCopyKey();
    void slotPasteKey();
    void slotSetCurrentKey(int currentKeyNum);
    void slotSetMode(QString m);
};

#endif // COPYPASTEHANDLER_H
