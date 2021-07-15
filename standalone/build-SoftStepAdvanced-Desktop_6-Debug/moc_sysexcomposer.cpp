// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'sysexcomposer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/sysexcomposer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sysexcomposer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SysExComposer_t {
    const uint offsetsAndSize[44];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SysExComposer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SysExComposer_t qt_meta_stringdata_SysExComposer = {
    {
QT_MOC_LITERAL(0, 13), // "SysExComposer"
QT_MOC_LITERAL(14, 15), // "signalSendSysEx"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 9), // "messageID"
QT_MOC_LITERAL(41, 6), // "uchar*"
QT_MOC_LITERAL(48, 7), // "message"
QT_MOC_LITERAL(56, 13), // "messageLength"
QT_MOC_LITERAL(70, 15), // "destinationName"
QT_MOC_LITERAL(86, 19), // "signalSendBuildNums"
QT_MOC_LITERAL(106, 8), // "hardware"
QT_MOC_LITERAL(115, 20), // "signalUpdateComplete"
QT_MOC_LITERAL(136, 35), // "slotComposeAttributeListFromS..."
QT_MOC_LITERAL(172, 18), // "QList<QVariantMap>"
QT_MOC_LITERAL(191, 7), // "setlist"
QT_MOC_LITERAL(199, 17), // "settingsMapGlobal"
QT_MOC_LITERAL(217, 10), // "QList<int>"
QT_MOC_LITERAL(228, 10), // "pedalTable"
QT_MOC_LITERAL(239, 23), // "slotGetConnectedVersion"
QT_MOC_LITERAL(263, 22), // "slotGetEmbeddedVersion"
QT_MOC_LITERAL(286, 18), // "slotUpdateFirmware"
QT_MOC_LITERAL(305, 16), // "slotSettingsSent"
QT_MOC_LITERAL(322, 15) // "slotPresetsSent"

    },
    "SysExComposer\0signalSendSysEx\0\0messageID\0"
    "uchar*\0message\0messageLength\0"
    "destinationName\0signalSendBuildNums\0"
    "hardware\0signalUpdateComplete\0"
    "slotComposeAttributeListFromSetlist\0"
    "QList<QVariantMap>\0setlist\0settingsMapGlobal\0"
    "QList<int>\0pedalTable\0slotGetConnectedVersion\0"
    "slotGetEmbeddedVersion\0slotUpdateFirmware\0"
    "slotSettingsSent\0slotPresetsSent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysExComposer[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   68,    2, 0x06,    0 /* Public */,
       8,    5,   77,    2, 0x06,    5 /* Public */,
      10,    0,   88,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    3,   89,    2, 0x0a,   12 /* Public */,
      17,    1,   96,    2, 0x0a,   16 /* Public */,
      18,    0,   99,    2, 0x0a,   18 /* Public */,
      19,    0,  100,    2, 0x0a,   19 /* Public */,
      20,    0,  101,    2, 0x0a,   20 /* Public */,
      21,    0,  102,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::Int, QMetaType::QString,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12, QMetaType::QVariantMap, 0x80000000 | 15,   13,   14,   16,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SysExComposer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SysExComposer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendSysEx((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uchar*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->signalSendBuildNums((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 2: _t->signalUpdateComplete(); break;
        case 3: _t->slotComposeAttributeListFromSetlist((*reinterpret_cast< QList<QVariantMap>(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2])),(*reinterpret_cast< QList<int>(*)>(_a[3]))); break;
        case 4: _t->slotGetConnectedVersion((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->slotGetEmbeddedVersion(); break;
        case 6: _t->slotUpdateFirmware(); break;
        case 7: _t->slotSettingsSent(); break;
        case 8: _t->slotPresetsSent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QVariantMap> >(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SysExComposer::*)(QString , unsigned char * , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysExComposer::signalSendSysEx)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SysExComposer::*)(int , QString , int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysExComposer::signalSendBuildNums)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SysExComposer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysExComposer::signalUpdateComplete)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SysExComposer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SysExComposer.offsetsAndSize,
    qt_meta_data_SysExComposer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SysExComposer_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned char *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QVariantMap>, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SysExComposer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysExComposer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SysExComposer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SysExComposer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SysExComposer::signalSendSysEx(QString _t1, unsigned char * _t2, int _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SysExComposer::signalSendBuildNums(int _t1, QString _t2, int _t3, QString _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SysExComposer::signalUpdateComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
