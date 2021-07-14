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
#include "../ezpz/mididevicemanager.h"
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
    const uint offsetsAndSize[66];
    char stringdata0[549];
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
QT_MOC_LITERAL(315, 17), // "signalPresetsSent"
QT_MOC_LITERAL(333, 18), // "signalSettingsSent"
QT_MOC_LITERAL(352, 25), // "slotRequestFirmwareUpdate"
QT_MOC_LITERAL(378, 18), // "slotUpdateFirmware"
QT_MOC_LITERAL(397, 19), // "slotEnterBootloader"
QT_MOC_LITERAL(417, 13), // "slotSendSysEx"
QT_MOC_LITERAL(431, 9), // "messageID"
QT_MOC_LITERAL(441, 6), // "uchar*"
QT_MOC_LITERAL(448, 5), // "bytes"
QT_MOC_LITERAL(454, 3), // "len"
QT_MOC_LITERAL(458, 15), // "destinationName"
QT_MOC_LITERAL(474, 16), // "slotProcessSysEx"
QT_MOC_LITERAL(491, 21), // "sysExMessageByteArray"
QT_MOC_LITERAL(513, 16), // "slotStandaloneOn"
QT_MOC_LITERAL(530, 18) // "slotDrainSysexFIFO"

    },
    "MidiDeviceManager\0signalFirmwareOutOfDate\0"
    "\0expectedBoot\0foundBoot\0expectedFirmware\0"
    "foundFirmware\0signalProgressDialog\0"
    "messageType\0val\0signalFirmwareUpdateComplete\0"
    "signalSendPerKeySensitivities\0"
    "signalEncodePerKeySensitivities\0"
    "QList<int>\0signalSendSettings\0"
    "signalProcessFwQueryReply\0signalConnected\0"
    "signalFwBytesLeft\0signalPresetsSent\0"
    "signalSettingsSent\0slotRequestFirmwareUpdate\0"
    "slotUpdateFirmware\0slotEnterBootloader\0"
    "slotSendSysEx\0messageID\0uchar*\0bytes\0"
    "len\0destinationName\0slotProcessSysEx\0"
    "sysExMessageByteArray\0slotStandaloneOn\0"
    "slotDrainSysexFIFO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidiDeviceManager[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,  122,    2, 0x06,    0 /* Public */,
       7,    2,  131,    2, 0x06,    5 /* Public */,
      10,    0,  136,    2, 0x06,    8 /* Public */,
      11,    1,  137,    2, 0x06,    9 /* Public */,
      12,    2,  140,    2, 0x06,   11 /* Public */,
      14,    0,  145,    2, 0x06,   14 /* Public */,
      15,    1,  146,    2, 0x06,   15 /* Public */,
      16,    1,  149,    2, 0x06,   17 /* Public */,
      17,    1,  152,    2, 0x06,   19 /* Public */,
      18,    0,  155,    2, 0x06,   21 /* Public */,
      19,    0,  156,    2, 0x06,   22 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    0,  157,    2, 0x0a,   23 /* Public */,
      21,    0,  158,    2, 0x0a,   24 /* Public */,
      22,    0,  159,    2, 0x0a,   25 /* Public */,
      23,    4,  160,    2, 0x0a,   26 /* Public */,
      29,    1,  169,    2, 0x0a,   31 /* Public */,
      31,    0,  172,    2, 0x0a,   33 /* Public */,
      32,    0,  173,    2, 0x0a,   34 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 25, QMetaType::Int, QMetaType::QString,   24,   26,   27,   28,
    QMetaType::Void, QMetaType::QByteArray,   30,
    QMetaType::Void,
    QMetaType::Void,

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
        case 9: _t->signalPresetsSent(); break;
        case 10: _t->signalSettingsSent(); break;
        case 11: _t->slotRequestFirmwareUpdate(); break;
        case 12: _t->slotUpdateFirmware(); break;
        case 13: _t->slotEnterBootloader(); break;
        case 14: _t->slotSendSysEx((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uchar*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 15: _t->slotProcessSysEx((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 16: _t->slotStandaloneOn(); break;
        case 17: _t->slotDrainSysexFIFO(); break;
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
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalPresetsSent)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MidiDeviceManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiDeviceManager::signalSettingsSent)) {
                *result = 10;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned char *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
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
void MidiDeviceManager::signalPresetsSent()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MidiDeviceManager::signalSettingsSent()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
