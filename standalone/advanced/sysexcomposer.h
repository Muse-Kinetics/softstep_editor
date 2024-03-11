// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SYSEXCOMPOSER_H
#define SYSEXCOMPOSER_H

#include <QWidget>
#include <QVariant>
#include <QFile>
#include <QCoreApplication>
#include <QElapsedTimer>

#include "hosted/midiformatoutput.h"

extern "C"
{
#include "device_includes.h"
}

class SysExComposer : public QWidget
{
    Q_OBJECT
public:
    explicit SysExComposer(QWidget *parent = 0);
    //~SysExComposer();

    QVariantMap     defaultAttributeList;
    int             embeddedbuildNum, connectedBuildNum;
    QString         embeddedVersion, connectedVersion;
    unsigned char*  fwFile;
    int             fwFileSize;
    bool            isSoftStep2;
    bool            connected;
    QElapsedTimer   *composeSettingsTimeout;

    //QList<QVariantMap> setlist;

    //t_softstep *x;

    //Standalone pedal calibration
    QString calibrationPhase;

signals:
    void    signalSendSysEx(unsigned char* message, int messageLength);
    void    signalUpdateComplete();
    void    signalStartStandaloneCalibration();
    void    hosted_signalParsePacket(QByteArray *packet);

public slots:
    void    slotComposeSettings(QVariantMap settingsMapGlobal, QList<int> pedalTable);
    void    slotComposeAttributeListFromSetlist(QList<QVariantMap> setlist, QVariantMap settingsMapGlobal, QList<int> pedalTable);

    void    slotSettingsSent();
    void    slotPresetsSent();
    void    slotHostedOnOff(bool onOff);
    void    slotTetherOnOffInStandalone(bool onOff);

    //--------------------------- Pedal Calibration
    void    slotRequestPedalCalibration();


    //--------------------------- One-off sysex messages
    void    slotSceneChangeOnOff(bool onOff);
    void    slotBackLightOnOff(bool onOff);

};

#endif // SYSEXCOMPOSER_H
