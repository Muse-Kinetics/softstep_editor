// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'staterecall.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/staterecall.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'staterecall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StateRecall_t {
    const uint offsetsAndSize[60];
    char stringdata0[478];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_StateRecall_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_StateRecall_t qt_meta_stringdata_StateRecall = {
    {
QT_MOC_LITERAL(0, 11), // "StateRecall"
QT_MOC_LITERAL(12, 24), // "signalStateRecallToggles"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 10), // "modlineNum"
QT_MOC_LITERAL(49, 5), // "state"
QT_MOC_LITERAL(55, 24), // "signalStateRecallCounter"
QT_MOC_LITERAL(80, 24), // "signalStateRecallYIncDec"
QT_MOC_LITERAL(105, 24), // "signalStateRecallXIncDec"
QT_MOC_LITERAL(130, 26), // "signalStateRecallLedStates"
QT_MOC_LITERAL(157, 34), // "signalStateRecallLedLastPacke..."
QT_MOC_LITERAL(192, 17), // "QList<MIDIPacket>"
QT_MOC_LITERAL(210, 6), // "pktlst"
QT_MOC_LITERAL(217, 8), // "slotInit"
QT_MOC_LITERAL(226, 11), // "presetNames"
QT_MOC_LITERAL(238, 9), // "keyNumVal"
QT_MOC_LITERAL(248, 17), // "slotInitNewPreset"
QT_MOC_LITERAL(266, 10), // "presetName"
QT_MOC_LITERAL(277, 21), // "slotStoreToggleStates"
QT_MOC_LITERAL(299, 21), // "slotStoreCounterState"
QT_MOC_LITERAL(321, 3), // "val"
QT_MOC_LITERAL(325, 20), // "slotStoreIncDecState"
QT_MOC_LITERAL(346, 1), // "x"
QT_MOC_LITERAL(348, 1), // "y"
QT_MOC_LITERAL(350, 18), // "slotStoreLedStates"
QT_MOC_LITERAL(369, 26), // "slotStoreLedLastPacketList"
QT_MOC_LITERAL(396, 30), // "slotStorePreviousKeyValueState"
QT_MOC_LITERAL(427, 22), // "slotStoreInitModeState"
QT_MOC_LITERAL(450, 6), // "called"
QT_MOC_LITERAL(457, 15), // "slotRecallState"
QT_MOC_LITERAL(473, 4) // "name"

    },
    "StateRecall\0signalStateRecallToggles\0"
    "\0modlineNum\0state\0signalStateRecallCounter\0"
    "signalStateRecallYIncDec\0"
    "signalStateRecallXIncDec\0"
    "signalStateRecallLedStates\0"
    "signalStateRecallLedLastPacketList\0"
    "QList<MIDIPacket>\0pktlst\0slotInit\0"
    "presetNames\0keyNumVal\0slotInitNewPreset\0"
    "presetName\0slotStoreToggleStates\0"
    "slotStoreCounterState\0val\0"
    "slotStoreIncDecState\0x\0y\0slotStoreLedStates\0"
    "slotStoreLedLastPacketList\0"
    "slotStorePreviousKeyValueState\0"
    "slotStoreInitModeState\0called\0"
    "slotRecallState\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StateRecall[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  110,    2, 0x06,    0 /* Public */,
       5,    1,  115,    2, 0x06,    3 /* Public */,
       6,    1,  118,    2, 0x06,    5 /* Public */,
       7,    1,  121,    2, 0x06,    7 /* Public */,
       8,    2,  124,    2, 0x06,    9 /* Public */,
       9,    1,  129,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    2,  132,    2, 0x0a,   14 /* Public */,
      15,    1,  137,    2, 0x0a,   17 /* Public */,
      17,    2,  140,    2, 0x0a,   19 /* Public */,
      18,    1,  145,    2, 0x0a,   22 /* Public */,
      20,    2,  148,    2, 0x0a,   24 /* Public */,
      23,    2,  153,    2, 0x0a,   27 /* Public */,
      24,    1,  158,    2, 0x0a,   30 /* Public */,
      25,    1,  161,    2, 0x0a,   32 /* Public */,
      26,    2,  164,    2, 0x0a,   34 /* Public */,
      28,    1,  169,    2, 0x0a,   37 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   21,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   27,
    QMetaType::Void, QMetaType::QString,   29,

       0        // eod
};

void StateRecall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StateRecall *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalStateRecallToggles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->signalStateRecallCounter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalStateRecallYIncDec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalStateRecallXIncDec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signalStateRecallLedStates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->signalStateRecallLedLastPacketList((*reinterpret_cast< QList<MIDIPacket>(*)>(_a[1]))); break;
        case 6: _t->slotInit((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slotInitNewPreset((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slotStoreToggleStates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->slotStoreCounterState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slotStoreIncDecState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotStoreLedStates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->slotStoreLedLastPacketList((*reinterpret_cast< QList<MIDIPacket>(*)>(_a[1]))); break;
        case 13: _t->slotStorePreviousKeyValueState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->slotStoreInitModeState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->slotRecallState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StateRecall::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateRecall::signalStateRecallToggles)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StateRecall::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateRecall::signalStateRecallCounter)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StateRecall::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateRecall::signalStateRecallYIncDec)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StateRecall::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateRecall::signalStateRecallXIncDec)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (StateRecall::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateRecall::signalStateRecallLedStates)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (StateRecall::*)(QList<MIDIPacket> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateRecall::signalStateRecallLedLastPacketList)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject StateRecall::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StateRecall.offsetsAndSize,
    qt_meta_data_StateRecall,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_StateRecall_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<MIDIPacket>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<MIDIPacket>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *StateRecall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StateRecall::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StateRecall.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StateRecall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void StateRecall::signalStateRecallToggles(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StateRecall::signalStateRecallCounter(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StateRecall::signalStateRecallYIncDec(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StateRecall::signalStateRecallXIncDec(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StateRecall::signalStateRecallLedStates(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StateRecall::signalStateRecallLedLastPacketList(QList<MIDIPacket> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
