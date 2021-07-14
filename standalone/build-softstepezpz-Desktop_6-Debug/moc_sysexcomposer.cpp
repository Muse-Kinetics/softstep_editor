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
#include "../ezpz/sysexcomposer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
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
    char stringdata0[331];
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
QT_MOC_LITERAL(106, 20), // "signalUpdateComplete"
QT_MOC_LITERAL(127, 34), // "slotComposeAttributeListFromP..."
QT_MOC_LITERAL(162, 10), // "presetSent"
QT_MOC_LITERAL(173, 23), // "slotGetConnectedVersion"
QT_MOC_LITERAL(197, 22), // "slotGetEmbeddedVersion"
QT_MOC_LITERAL(220, 18), // "slotUpdateFirmware"
QT_MOC_LITERAL(239, 24), // "slotComposeFactoryPreset"
QT_MOC_LITERAL(264, 1), // "p"
QT_MOC_LITERAL(266, 17), // "factoryPresetName"
QT_MOC_LITERAL(284, 11), // "t_softstep*"
QT_MOC_LITERAL(296, 1), // "x"
QT_MOC_LITERAL(298, 16), // "slotSettingsSent"
QT_MOC_LITERAL(315, 15) // "slotPresetsSent"

    },
    "SysExComposer\0signalSendSysEx\0\0messageID\0"
    "uchar*\0message\0messageLength\0"
    "destinationName\0signalSendBuildNums\0"
    "signalUpdateComplete\0"
    "slotComposeAttributeListFromPreset\0"
    "presetSent\0slotGetConnectedVersion\0"
    "slotGetEmbeddedVersion\0slotUpdateFirmware\0"
    "slotComposeFactoryPreset\0p\0factoryPresetName\0"
    "t_softstep*\0x\0slotSettingsSent\0"
    "slotPresetsSent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysExComposer[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   74,    2, 0x06,    0 /* Public */,
       8,    4,   83,    2, 0x06,    5 /* Public */,
       9,    0,   92,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    3,   93,    2, 0x0a,   11 /* Public */,
      12,    1,  100,    2, 0x0a,   15 /* Public */,
      13,    0,  103,    2, 0x0a,   17 /* Public */,
      14,    0,  104,    2, 0x0a,   18 /* Public */,
      15,    3,  105,    2, 0x0a,   19 /* Public */,
      20,    0,  112,    2, 0x0a,   23 /* Public */,
      21,    0,  113,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::Int, QMetaType::QString,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap, QMetaType::LongLong,   11,    2,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Long, QMetaType::QString, 0x80000000 | 18,   16,   17,   19,
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
        case 1: _t->signalSendBuildNums((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->signalUpdateComplete(); break;
        case 3: _t->slotComposeAttributeListFromPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2])),(*reinterpret_cast< qlonglong(*)>(_a[3]))); break;
        case 4: _t->slotGetConnectedVersion((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->slotGetEmbeddedVersion(); break;
        case 6: _t->slotUpdateFirmware(); break;
        case 7: _t->slotComposeFactoryPreset((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< t_softstep*(*)>(_a[3]))); break;
        case 8: _t->slotSettingsSent(); break;
        case 9: _t->slotPresetsSent(); break;
        default: ;
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
            using _t = void (SysExComposer::*)(int , QString , int , QString );
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned char *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<qlonglong, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<long, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<t_softstep *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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
void SysExComposer::signalSendBuildNums(int _t1, QString _t2, int _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SysExComposer::signalUpdateComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
