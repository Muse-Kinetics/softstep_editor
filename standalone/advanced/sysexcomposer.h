// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SYSEXCOMPOSER_H
#define SYSEXCOMPOSER_H

#include <QWidget>
#include <QVariant>
#include <QFile>
#include <QCoreApplication>

#include "hosted/midiformatoutput.h"

extern "C"
{
#include "softstep.h"
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

    //QList<QVariantMap> setlist;

    //t_softstep *x;

    //Standalone pedal calibration
    QString calibrationPhase;

    //---------------- Hosted Source Sending ---------------//
    MidiFormatOutput midiFormatOutput;
    QMap<QString, int> externalDests;
    QMap<QString, int> midiInputSources;

signals:
    //void    signalSendSysEx(QString messageID, unsigned char* message, int messageLength, QString destinationName);
    void    signalSendSysEx(unsigned char* message, int messageLength);
    void    signalSendBuildNums(int,QString, int, QString, int hardware);
    void    signalUpdateComplete();

    void    signalStartStandaloneCalibration();

public slots:
    void    slotComposeAttributeListFromSetlist(QList<QVariantMap> setlist, QVariantMap settingsMapGlobal, QList<int> pedalTable);
    //void    slotGetConnectedVersion(QByteArray);
    //void    slotGetEmbeddedVersion();
    //void    slotUpdateFirmware();

    void    slotSettingsSent();
    void    slotPresetsSent();

    // from old mididevicemanager

    void slotHostedOnOff(bool onOff);

    //--------------------------- Pedal Calibration
    void slotTetherOnOffInStandalone(bool onOff);

    //--------------------------- One-off sysex messages
    void slotSceneChangeOnOff(bool onOff);
    void slotBackLightOnOff(bool onOff);

    void hosted_slotParsePacket(QByteArray packet);
    void hosted_slotSendPacket(QString port, QByteArray packet);
    void hosted_slotRepopulateMidiSourceDests();

    //-------------------------- MIDI Input from Settings
    void hosted_slotParseMidiInputPacket(QByteArray packet, QString deviceName);
    void hosted_slotConnectExternalMidiInputSources();

};

#endif // SYSEXCOMPOSER_H
