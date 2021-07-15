// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'mididevicemanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/mididevicemanager.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mididevicemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MidiDeviceManager_t {
    const uint offsetsAndSize[108];
    char stringdata0[1020];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MidiDeviceManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MidiDeviceManager_t qt_meta_stringdata_MidiDeviceManager = {
    {
QT_MOC_LITERAL(0, 17), // "MidiDeviceManager"
QT_MOC_LITERAL(18, 23), // "signalFirmwareOutOfDate"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 12), // "expectedBoot"
QT_MOC_LITERAL(56, 9), // "foundBoot"
QT_MOC_LITERAL(66, 16), // "expectedFirmware"
QT_MOC_LITERAL(83, 13), // "foundFirmware"
QT_MOC_LITERAL(97, 20), // "signalProgressDialog"
QT_MOC_LITERAL(118, 11), // "messageType"
QT_MOC_LITERAL(130, 3), // "val"
QT_MOC_LITERAL(134, 28), // "signalFirmwareUpdateComplete"
QT_MOC_LITERAL(163, 29), // "signalSendPerKeySensitivities"
QT_MOC_LITERAL(193, 31), // "signalEncodePerKeySensitivities"
QT_MOC_LITERAL(225, 10), // "QList<int>"
QT_MOC_LITERAL(236, 18), // "signalSendSettings"
QT_MOC_LITERAL(255, 25), // "signalProcessFwQueryReply"
QT_MOC_LITERAL(281, 15), // "signalConnected"
QT_MOC_LITERAL(297, 17), // "signalFwBytesLeft"
QT_MOC_LITERAL(315, 24), // "hosted_signalParsePacket"
QT_MOC_LITERAL(340, 17), // "const MIDIPacket*"
QT_MOC_LITERAL(358, 32), // "hosted_signalPopulateDeviceMenus"
QT_MOC_LITERAL(391, 29), // "QMap<QString,MIDIEndpointRef>"
QT_MOC_LITERAL(421, 33), // "hosted_signalMidiInputSourceM..."
QT_MOC_LITERAL(455, 33), // "hosted_signalParseMidiInputPa..."
QT_MOC_LITERAL(489, 31), // "signalStopStandaloneCalibration"
QT_MOC_LITERAL(521, 32), // "signalStartStandaloneCalibration"
QT_MOC_LITERAL(554, 17), // "signalPresetsSent"
QT_MOC_LITERAL(572, 18), // "signalSettingsSent"
QT_MOC_LITERAL(591, 18), // "slotUpdateFirmware"
QT_MOC_LITERAL(610, 13), // "slotSendSysEx"
QT_MOC_LITERAL(624, 9), // "messageID"
QT_MOC_LITERAL(634, 6), // "uchar*"
QT_MOC_LITERAL(641, 5), // "bytes"
QT_MOC_LITERAL(647, 3), // "len"
QT_MOC_LITERAL(651, 15), // "destinationName"
QT_MOC_LITERAL(667, 16), // "slotProcessSysEx"
QT_MOC_LITERAL(684, 21), // "sysExMessageByteArray"
QT_MOC_LITERAL(706, 11), // "slotSetMode"
QT_MOC_LITERAL(718, 1), // "m"
QT_MOC_LITERAL(720, 15), // "slotHostedOnOff"
QT_MOC_LITERAL(736, 5), // "onOff"
QT_MOC_LITERAL(742, 18), // "slotDrainSysexFIFO"
QT_MOC_LITERAL(761, 22), // "hosted_slotParsePacket"
QT_MOC_LITERAL(784, 6), // "packet"
QT_MOC_LITERAL(791, 21), // "hosted_slotSendPacket"
QT_MOC_LITERAL(813, 4), // "port"
QT_MOC_LITERAL(818, 10), // "MIDIPacket"
QT_MOC_LITERAL(829, 36), // "hosted_slotRepopulateMidiSour..."
QT_MOC_LITERAL(866, 31), // "hosted_slotParseMidiInputPacket"
QT_MOC_LITERAL(898, 10), // "deviceName"
QT_MOC_LITERAL(909, 42), // "hosted_slotConnectExternalMid..."
QT_MOC_LITERAL(952, 27), // "slotTetherOnOffInStandalone"
QT_MOC_LITERAL(980, 20), // "slotSceneChangeOnOff"
QT_MOC_LITERAL(1001, 18) // "slotBackLightOnOff"

    },
    "MidiDeviceManager\0signalFirmwareOutOfDate\0"
    "\0expectedBoot\0foundBoot\0expectedFirmware\0"
    "foundFirmware\0signalProgressDialog\0"
    "messageType\0val\0signalFirmwareUpdateComplete\0"
    "signalSendPerKeySensitivities\0"
    "signalEncodePerKeySensitivities\0"
    "QList<int>\0signalSendSettings\0"
    "signalProcessFwQueryReply\0signalConnected\0"
    "signalFwBytesLeft\0hosted_signalParsePacket\0"
    "const MIDIPacket*\0hosted_signalPopulateDeviceMenus\0"
    "QMap<QString,MIDIEndpointRef>\0"
    "hosted_signalMidiInputSourceMenus\0"
    "hosted_signalParseMidiInputPacket\0"
    "signalStopStandaloneCalibration\0"
    "signalStartStandaloneCalibration\0"
    "signalPresetsSent\0signalSettingsSent\0"
    "slotUpdateFirmware\0slotSendSysEx\0"
    "messageID\0uchar*\0bytes\0len\0destinationName\0"
    "slotProcessSysEx\0sysExMessageByteArray\0"
    "slotSetMode\0m\0slotHostedOnOff\0onOff\0"
    "slotDrainSysexFIFO\0hosted_slotParsePacket\0"
    "packet\0hosted_slotSendPacket\0port\0"
    "MIDIPacket\0hosted_slotRepopulateMidiSourceDests\0"
    "hosted_slotParseMidiInputPacket\0"
    "deviceName\0hosted_slotConnectExternalMidiInputSources\0"
    "slotTetherOnOffInStandalone\0"
    "slotSceneChangeOnOff\0slotBackLightOnOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidiDeviceManager[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,  200,    2, 0x06,    0 /* Public */,
       7,    2,  209,    2, 0x06,    5 /* Public */,
      10,    0,  214,    2, 0x06,    8 /* Public */,
      11,    1,  215,    2, 0x06,    9 /* Public */,
      12,    2,  218,    2, 0x06,   11 /* Public */,
      14,    0,  223,    2, 0x06,   14 /* Public */,
      15,    1,  224,    2, 0x06,   15 /* Public */,
      16,    1,  227,    2, 0x06,   17 /* Public */,
      17,    1,  230,    2, 0x06,   19 /* Public */,
      18,    1,  233,    2, 0x06,   21 /* Public */,
      20,    1,  236,    2, 0x06,   23 /* Public */,
      22,    1,  239,    2, 0x06,   25 /* Public */,
      23,    2,  242,    2, 0x06,   27 /* Public */,
      24,    0,  247,    2, 0x06,   30 /* Public */,
      25,    0,  248,    2, 0x06,   31 /* Public */,
      26,    0,  249,    2, 0x06,   32 /* Public */,
      27,    0,  250,    2, 0x06,   33 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      28,    0,  251,    2, 0x0a,   34 /* Public */,
      29,    4,  252,    2, 0x0a,   35 /* Public */,
      35,    1,  261,    2, 0x0a,   40 /* Public */,
      37,    1,  264,    2, 0x0a,   42 /* Public */,
      39,    1,  267,    2, 0x0a,   44 /* Public */,
      41,    0,  270,    2, 0x0a,   46 /* Public */,
      42,    1,  271,    2, 0x0a,   47 /* Public */,
      44,    2,  274,    2, 0x0a,   49 /* Public */,
      47,    0,  279,    2, 0x0a,   52 /* Public */,
      48,    2,  280,    2, 0x0a,   53 /* Public */,
      50,    0,  285,    2, 0x0a,   56 /* Public */,
      51,    1,  286,    2, 0x0a,   57 /* Public */,
      52,    1,  289,    2, 0x0a,   59 /* Public */,
      53,    1,  292,    2, 0x0a,   61 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 19, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 31, QMetaType::Int, QMetaType::QString,   30,   32,   33,   34,
    QMetaType::Void, QMetaType::QByteArray,   36,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   43,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 46,   45,   43,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, QMetaType::QString,   43,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,

       0        // eod
};

void MidiDeviceManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MidiDeviceManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalFirmwareOutOfDate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->signalProgressDialog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->signalFirmwareUpdateComplete(); break;
        case 3: _t->signalSendPerKeySensitivities((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->signalEncodePerKeySensitivities((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<int>(*)>(_a[2]))); break;
        case 5: _t->signalSendSettings(); break;
        case 6: _t->signalProcessFwQueryReply((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->signalConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->signalFwBytesLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->hosted_signalParsePacket((*reinterpret_cast< const MIDIPacket*(*)>(_a[1]))); break;
        case 10: _t->hosted_signalPopulateDeviceMenus((*reinterpret_cast< QMap<QString,MIDIEndpointRef>(*)>(_a[1]))); break;
        case 11: _t->hosted_signalMidiInputSourceMenus((*reinterpret_cast< QMap<QString,MIDIEndpointRef>(*)>(_a[1]))); break;
        case 12: _t->hosted_signalParseMidiInputPacket((*reinterpret_cast< const MIDIPacket*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->signalStopStandaloneCalibration(); break;
        case 14: _t->signalStartStandaloneCalibration(); break;
        case 15: _t->signalPresetsSent(); break;
        case 16: _t->signalSettingsSent(); break;
        case 17: _t->slotUpdateFirmware(); break;
        case 18: _t->slotSendSysEx((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uchar*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 19: _t->slotProcessSysEx((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 20: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->slotHostedOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->slotDrainSysexFIFO(); break;
        case 23: _t->hosted_slotParsePacket((*reinterpret_cast< const MIDIPacket*(*)>(_a[1]))); break;
        case 24: _t->hosted_slotSendPacket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< MIDIPacket(*)>(_a[2]))); break;
        case 25: _t->hosted_slotRepopulateMidiSourceDests(); break;
        case 26: _t->hosted_slotParseMidiInputPacket((*reinterpret_cast< const MIDIPacket*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 27: _t->hosted_slotConnectExternalMidiInputSources(); break;
        case 28: _t->slotTetherOnOffInStandalone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->slotSceneChangeOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->slotBackLightOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MidiDeviceManager::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalFirmwareOutOfDate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalProgressDialog)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalFirmwareUpdateComplete)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalSendPerKeySensitivities)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(QString , QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalEncodePerKeySensitivities)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalSendSettings)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalProcessFwQueryReply)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalConnected)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalFwBytesLeft)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(const MIDIPacket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::hosted_signalParsePacket)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(QMap<QString,MIDIEndpointRef> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::hosted_signalPopulateDeviceMenus)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(QMap<QString,MIDIEndpointRef> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::hosted_signalMidiInputSourceMenus)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)(const MIDIPacket * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::hosted_signalParseMidiInputPacket)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalStopStandaloneCalibration)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalStartStandaloneCalibration)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalPresetsSent)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalSettingsSent)) {
                *result = 16;
                return;
            }
        }
    }
}

const QMetaObject MidiDeviceManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MidiDeviceManager.offsetsAndSize,
    qt_meta_data_MidiDeviceManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MidiDeviceManager_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const MIDIPacket *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<QString,MIDIEndpointRef>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<QString,MIDIEndpointRef>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const MIDIPacket *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned char *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const MIDIPacket *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<MIDIPacket, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const MIDIPacket *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *MidiDeviceManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MidiDeviceManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MidiDeviceManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MidiDeviceManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void MidiDeviceManager::signalFirmwareOutOfDate(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MidiDeviceManager::signalProgressDialog(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MidiDeviceManager::signalFirmwareUpdateComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MidiDeviceManager::signalSendPerKeySensitivities(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MidiDeviceManager::signalEncodePerKeySensitivities(QString _t1, QList<int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MidiDeviceManager::signalSendSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MidiDeviceManager::signalProcessFwQueryReply(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MidiDeviceManager::signalConnected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MidiDeviceManager::signalFwBytesLeft(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MidiDeviceManager::hosted_signalParsePacket(const MIDIPacket * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MidiDeviceManager::hosted_signalPopulateDeviceMenus(QMap<QString,MIDIEndpointRef> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MidiDeviceManager::hosted_signalMidiInputSourceMenus(QMap<QString,MIDIEndpointRef> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MidiDeviceManager::hosted_signalParseMidiInputPacket(const MIDIPacket * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MidiDeviceManager::signalStopStandaloneCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void MidiDeviceManager::signalStartStandaloneCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void MidiDeviceManager::signalPresetsSent()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void MidiDeviceManager::signalSettingsSent()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
