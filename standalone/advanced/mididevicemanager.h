// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MIDIDEVICEMANAGER_H
#define MIDIDEVICEMANAGER_H

#include <QDebug>
#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QTimer>

#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>
#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <AudioUnit/AudioUnit.h>
#include <vector>


#include "hosted/midiformatoutput.h"

//#include "sysexencode.h"

enum{NORMAL, BOOTLOADER_POST_UPDATE_REQUEST, BOOTLOADER_NO_UPDATE_REQUEST};

class MidiDeviceManager : public QWidget
{
    Q_OBJECT
public:
    explicit MidiDeviceManager(QWidget *parent = 0);

    QTimer* sysexFIFOClock;
    QList<unsigned char*> sysexFIFOsQueue;
    QString mode;

    //SysExEncode*        sysExEncode;

    //Application MIDI Variables so out App can rx/tx MIDI
    MIDIClientRef appClientRef;
    MIDIPortRef appInPortRef;
    MIDIPortRef appOutPortRef;
    MIDIEndpointRef appVirtualSourceRef;
    MIDIEndpointRef appVirtualDestRef;
    MIDIPortRef midiInputPort;
    MIDIEndpointRef sscomPort1DestRef;

    QMap<MIDIEndpointRef*,QString> midiInputRefConns;

    char bootloaderVersion[3];
    char firmwareVersion[3];
    int  versionSum;

    QFile *firmware;
    QByteArray firmwareByteArray;

    QString expectedBootloaderVersion;
    QString expectedFirmwareVersion;
    QString foundBootloaderVersion;
    QString foundFirmwwareVersion;

    //Sets up MIDI rx/tx using above vars
    void createAppMidiClient();

    //Helper variables to process sysex
    QByteArray sysExMessage; //Message to be processed;
    bool isSysEx;

    //Return MIDI source/dest name,index maps
    int getDestination();
    int getSource();

    //Connects an SSCOM source to our app
    bool connectSource();

    //Describes whether or not a fw update has been requested-- useful for managing bootloader reconnects
    bool fwUpdateRequested;
    bool inBootloader;

    //------------- Helper Functions -------------//
    //Formats MIDI Device Names
    QString getDisplayName(MIDIObjectRef); //gets "name" of QuNeo device
    QString cFStringRefToQString(CFStringRef);

    bool      queryReplied;

    //---------------- Hosted Source Sending ---------------//
    MidiFormatOutput midiFormatOutput;
    QMap<QString, MIDIEndpointRef> externalDests;
    QMap<QString, MIDIEndpointRef> midiInputSources;

    //Standalone pedal calibration
    QString calibrationPhase;
    
signals:
    void signalFirmwareOutOfDate(QString expectedBoot, QString foundBoot, QString expectedFirmware, QString foundFirmware);
    void signalProgressDialog(QString messageType, int val);
    void signalFirmwareUpdateComplete();
    void signalSendPerKeySensitivities(QByteArray);
    void signalEncodePerKeySensitivities(QString, QList<int>);
    void signalSendSettings();
    void signalProcessFwQueryReply(QByteArray);
    void signalConnected(bool);
    void signalFwBytesLeft(int);

    //---------------- Hosted Source Sending ---------------//
    void hosted_signalParsePacket(const MIDIPacket*);
    void hosted_signalPopulateDeviceMenus(QMap<QString, MIDIEndpointRef>);
    void hosted_signalMidiInputSourceMenus(QMap<QString, MIDIEndpointRef>);
    void hosted_signalParseMidiInputPacket(const MIDIPacket*, QString);

    //Standalone pedal cal
    void signalStopStandaloneCalibration();
    void signalStartStandaloneCalibration();
    
public slots:
    void slotUpdateFirmware();
    void slotSendSysEx(QString messageID, unsigned char* bytes, int len, QString destinationName);
    void slotProcessSysEx(QByteArray sysExMessageByteArray);

    void slotSetMode(QString m);
    void slotHostedOnOff(bool onOff);
    void slotDrainSysexFIFO();

    void hosted_slotParsePacket(const MIDIPacket* packet);
    void hosted_slotSendPacket(QString port, MIDIPacket packet);
    void hosted_slotRepopulateMidiSourceDests();

    //-------------------------- MIDI Input from Settings
    void hosted_slotParseMidiInputPacket(const MIDIPacket* packet, QString deviceName);
    void hosted_slotConnectExternalMidiInputSources();

    //--------------------------- Pedal Calibration
    void slotTetherOnOffInStandalone(bool onOff);

};
#else
#include <Windows.h>
#include <MMSystem.h>
#include <Dbt.h>

class MidiDeviceManager : public QWidget
{
    Q_OBJECT
public:
    explicit MidiDeviceManager(QWidget *parent = 0);

    //----------------------------------------- Windows MIDI & Windowing Services -----------------------------------------//
    MIDIOUTCAPS     mocs;
    HMIDIOUT        outHandle;
    HANDLE          sysExOutBuffer;
    MIDIHDR         sysExOutHdr;
    MIDIINCAPS      mics;
    HMIDIIN         inHandle;
    HANDLE          sysExInBuffer;
    MIDIHDR         sysExInHdr;
    HANDLE          hBuffer;


    static void CALLBACK midiInCallback(HMIDIIN hMidiIn,UINT wMsg,DWORD_PTR dwInstance,DWORD_PTR dwParam1,DWORD_PTR dwParam2);
    static void CALLBACK midiOutCallback(HMIDIOUT handle, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam, DWORD_PTR dwParam1);

    bool connected;
    bool refreshDevices;

    char bootloaderVersion[3];
    char firmwareVersion[3];
    int  versionSum;

    QFile *firmware;
    QByteArray firmwareByteArray;

    QString expectedBootloaderVersion;
    QString expectedFirmwareVersion;
    QString foundBootloaderVersion;
    QString foundFirmwwareVersion;

    //Connects a source to our app
    bool connectSource();

    QString getDisplayName(int deviceIndex, QString inOrOut);

    //Return MIDI source/dest name,index maps
    int getDestination();
    int getSource();

    //Helper variables to process sysex
    QByteArray sysExMessage; //Message to be processed;
    bool isSysEx;

    //Describes whether or not a fw update has been requested-- useful for managing bootloader reconnects
    bool fwUpdateRequested;
    bool inBootloader;

    bool queryReplied;

    QByteArray globals;
    QString    sysExType;
    bool       globalsRecieved;

    //------------------- Polling
    QTimer* devicePoller;
    QTimer* versionPoller;
    bool versionReply;

    int numDevices;

signals:
    void signalFirmwareOutOfDate(QString expectedBoot, QString foundBoot, QString expectedFirmware, QString foundFirmware);
    void signalProgressDialog(QString messageType, int val);
    void signalFirmwareUpdateComplete();
    void signalSendPerKeySensitivities(QByteArray);
    void signalEncodePerKeySensitivities(QString, QList<int>);
    void signalSendSettings();
    void signalProcessFwQueryReply(QByteArray);
    void signalConnected(bool);
    void signalFwBytesLeft(int);

public slots:
    void slotSendSysEx(QString messageID, unsigned char *sysEx, int len, QString destinationName);
    void slotProcessSysEx(QByteArray sysExMessageByteArray);

    void slotOpenMidiIn(int index);
    void slotOpenMidiOut(int index);
    void slotCloseMidiIn();
    void slotCloseMidiOut();

    void slotPollDevices();
    void slotPollVersion();
};

#endif // Q_OS_MAC
#endif // MIDIDEVICEMANAGER_H
