// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SYSEXCOMPOSER_H
#define SYSEXCOMPOSER_H

#include <QWidget>
#include <QVariant>
#include <QFile>
#include <QCoreApplication>

#include "factorypresets.h"

extern "C"
{
#include "device_includes.h"
}

class SysExComposer : public QWidget
{
    Q_OBJECT
public:
    explicit SysExComposer(QWidget *parent = 0);
    ~SysExComposer();

    QVariantMap     defaultAttributeList;
    int             embeddedbuildNum, connectedBuildNum;
    QString         embeddedVersion, connectedVersion;
    unsigned char*  fwFile;
    int             fwFileSize;
    bool            isSoftStep2;

    FactoryPresets* factoryPresets;
    bool            isFactoryPreset[10];
    
signals:
    void    signalSendSysEx(unsigned char* message, int messageLength);
    void    signalSendBuildNums(int,QString, int, QString);
    void    signalUpdateComplete();
    
public slots:
    void    slotComposeAttributeListFromPreset(QVariantMap presetSent, QVariantMap, qlonglong);
    void    slotComposeFactoryPreset(long p, QString factoryPresetName, t_softstep *x);

    void    slotSettingsSent();
    void    slotPresetsSent();
    void    slotStandaloneOn();
};

#endif // SYSEXCOMPOSER_H
