// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'alphanummanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/alphanummanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alphanummanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlphaNumManager_t {
    const uint offsetsAndSize[40];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AlphaNumManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AlphaNumManager_t qt_meta_stringdata_AlphaNumManager = {
    {
QT_MOC_LITERAL(0, 15), // "AlphaNumManager"
QT_MOC_LITERAL(16, 21), // "signalSendDisplayVals"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 4), // "port"
QT_MOC_LITERAL(44, 17), // "QList<MIDIPacket>"
QT_MOC_LITERAL(62, 6), // "packet"
QT_MOC_LITERAL(69, 18), // "slotDisplayKeyName"
QT_MOC_LITERAL(88, 6), // "keyNum"
QT_MOC_LITERAL(95, 16), // "slotDisplayParam"
QT_MOC_LITERAL(112, 10), // "modlineNum"
QT_MOC_LITERAL(123, 3), // "val"
QT_MOC_LITERAL(127, 33), // "slotPresetChangeDisplayPreset..."
QT_MOC_LITERAL(161, 25), // "slotFormatAndOutputString"
QT_MOC_LITERAL(187, 13), // "displayString"
QT_MOC_LITERAL(201, 19), // "slotReturnToKeyName"
QT_MOC_LITERAL(221, 10), // "slotKeyOff"
QT_MOC_LITERAL(232, 17), // "slotKeyOffTimeout"
QT_MOC_LITERAL(250, 20), // "slotOpenParamDisplay"
QT_MOC_LITERAL(271, 21), // "slotCloseParamDisplay"
QT_MOC_LITERAL(293, 13) // "slotDrainFIFO"

    },
    "AlphaNumManager\0signalSendDisplayVals\0"
    "\0port\0QList<MIDIPacket>\0packet\0"
    "slotDisplayKeyName\0keyNum\0slotDisplayParam\0"
    "modlineNum\0val\0slotPresetChangeDisplayPresetName\0"
    "slotFormatAndOutputString\0displayString\0"
    "slotReturnToKeyName\0slotKeyOff\0"
    "slotKeyOffTimeout\0slotOpenParamDisplay\0"
    "slotCloseParamDisplay\0slotDrainFIFO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlphaNumManager[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   80,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   85,    2, 0x0a,    3 /* Public */,
       8,    2,   88,    2, 0x0a,    5 /* Public */,
      11,    0,   93,    2, 0x0a,    8 /* Public */,
      12,    1,   94,    2, 0x0a,    9 /* Public */,
      14,    0,   97,    2, 0x0a,   11 /* Public */,
      15,    1,   98,    2, 0x0a,   12 /* Public */,
      16,    0,  101,    2, 0x0a,   14 /* Public */,
      17,    0,  102,    2, 0x0a,   15 /* Public */,
      18,    0,  103,    2, 0x0a,   16 /* Public */,
      19,    0,  104,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AlphaNumManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AlphaNumManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendDisplayVals((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<MIDIPacket>(*)>(_a[2]))); break;
        case 1: _t->slotDisplayKeyName((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotDisplayParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slotPresetChangeDisplayPresetName(); break;
        case 4: _t->slotFormatAndOutputString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotReturnToKeyName(); break;
        case 6: _t->slotKeyOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotKeyOffTimeout(); break;
        case 8: _t->slotOpenParamDisplay(); break;
        case 9: _t->slotCloseParamDisplay(); break;
        case 10: _t->slotDrainFIFO(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AlphaNumManager::*)(QString , QList<MIDIPacket> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlphaNumManager::signalSendDisplayVals)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AlphaNumManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AlphaNumManager.offsetsAndSize,
    qt_meta_data_AlphaNumManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AlphaNumManager_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<MIDIPacket>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AlphaNumManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlphaNumManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlphaNumManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AlphaNumManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AlphaNumManager::signalSendDisplayVals(QString _t1, QList<MIDIPacket> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
