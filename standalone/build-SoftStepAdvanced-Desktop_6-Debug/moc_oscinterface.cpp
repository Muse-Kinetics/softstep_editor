// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'oscinterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/oscinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oscinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OscInterface_t {
    const uint offsetsAndSize[38];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_OscInterface_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_OscInterface_t qt_meta_stringdata_OscInterface = {
    {
QT_MOC_LITERAL(0, 12), // "OscInterface"
QT_MOC_LITERAL(13, 28), // "signalSendOscMessageToSource"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 9), // "sourceNum"
QT_MOC_LITERAL(53, 3), // "val"
QT_MOC_LITERAL(57, 24), // "signalSetOSCDisplayValue"
QT_MOC_LITERAL(82, 8), // "inputNum"
QT_MOC_LITERAL(91, 24), // "slotReadPendingDatagrams"
QT_MOC_LITERAL(116, 17), // "slotWriteDatagram"
QT_MOC_LITERAL(134, 3), // "tag"
QT_MOC_LITERAL(138, 29), // "slotDistributeReceivedMessage"
QT_MOC_LITERAL(168, 18), // "slotSetInputEnable"
QT_MOC_LITERAL(187, 7), // "enabled"
QT_MOC_LITERAL(195, 21), // "slotSetOSCAddressTags"
QT_MOC_LITERAL(217, 17), // "slotSetOutputPort"
QT_MOC_LITERAL(235, 4), // "port"
QT_MOC_LITERAL(240, 16), // "slotSetInputPort"
QT_MOC_LITERAL(257, 22), // "slotSetOutputIPAddress"
QT_MOC_LITERAL(280, 8) // "ipString"

    },
    "OscInterface\0signalSendOscMessageToSource\0"
    "\0sourceNum\0val\0signalSetOSCDisplayValue\0"
    "inputNum\0slotReadPendingDatagrams\0"
    "slotWriteDatagram\0tag\0"
    "slotDistributeReceivedMessage\0"
    "slotSetInputEnable\0enabled\0"
    "slotSetOSCAddressTags\0slotSetOutputPort\0"
    "port\0slotSetInputPort\0slotSetOutputIPAddress\0"
    "ipString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscInterface[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    0 /* Public */,
       5,    2,   79,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   84,    2, 0x0a,    6 /* Public */,
       8,    2,   85,    2, 0x0a,    7 /* Public */,
      10,    2,   90,    2, 0x0a,   10 /* Public */,
      11,    2,   95,    2, 0x0a,   13 /* Public */,
      13,    2,  100,    2, 0x0a,   16 /* Public */,
      14,    1,  105,    2, 0x0a,   19 /* Public */,
      16,    1,  108,    2, 0x0a,   21 /* Public */,
      17,    1,  111,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    9,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void OscInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OscInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendOscMessageToSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->signalSetOSCDisplayValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slotReadPendingDatagrams(); break;
        case 3: _t->slotWriteDatagram((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slotDistributeReceivedMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->slotSetInputEnable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->slotSetOSCAddressTags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->slotSetOutputPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotSetInputPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotSetOutputIPAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OscInterface::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OscInterface::signalSendOscMessageToSource)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OscInterface::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OscInterface::signalSetOSCDisplayValue)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject OscInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OscInterface.offsetsAndSize,
    qt_meta_data_OscInterface,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_OscInterface_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *OscInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OscInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OscInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void OscInterface::signalSendOscMessageToSource(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OscInterface::signalSetOSCDisplayValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
