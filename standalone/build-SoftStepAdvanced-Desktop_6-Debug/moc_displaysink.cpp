// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'displaysink.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/displaysink.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaysink.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplaySink_t {
    const uint offsetsAndSize[24];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DisplaySink_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DisplaySink_t qt_meta_stringdata_DisplaySink = {
    {
QT_MOC_LITERAL(0, 11), // "DisplaySink"
QT_MOC_LITERAL(12, 16), // "signalSendPacket"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 4), // "port"
QT_MOC_LITERAL(35, 10), // "MIDIPacket"
QT_MOC_LITERAL(46, 6), // "packet"
QT_MOC_LITERAL(53, 16), // "slotAddLEDPacket"
QT_MOC_LITERAL(70, 17), // "QList<MIDIPacket>"
QT_MOC_LITERAL(88, 10), // "packetList"
QT_MOC_LITERAL(99, 18), // "slotAddAlphaPacket"
QT_MOC_LITERAL(118, 17), // "slotPollAlphaList"
QT_MOC_LITERAL(136, 20) // "slotDrainDisplayFIFO"

    },
    "DisplaySink\0signalSendPacket\0\0port\0"
    "MIDIPacket\0packet\0slotAddLEDPacket\0"
    "QList<MIDIPacket>\0packetList\0"
    "slotAddAlphaPacket\0slotPollAlphaList\0"
    "slotDrainDisplayFIFO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplaySink[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   49,    2, 0x0a,    3 /* Public */,
       9,    2,   54,    2, 0x0a,    6 /* Public */,
      10,    0,   59,    2, 0x0a,    9 /* Public */,
      11,    0,   60,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    3,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    3,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DisplaySink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DisplaySink *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendPacket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< MIDIPacket(*)>(_a[2]))); break;
        case 1: _t->slotAddLEDPacket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<MIDIPacket>(*)>(_a[2]))); break;
        case 2: _t->slotAddAlphaPacket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<MIDIPacket>(*)>(_a[2]))); break;
        case 3: _t->slotPollAlphaList(); break;
        case 4: _t->slotDrainDisplayFIFO(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DisplaySink::*)(QString , MIDIPacket );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DisplaySink::signalSendPacket)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DisplaySink::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DisplaySink.offsetsAndSize,
    qt_meta_data_DisplaySink,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DisplaySink_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<MIDIPacket, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<MIDIPacket>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<MIDIPacket>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *DisplaySink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplaySink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplaySink.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DisplaySink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DisplaySink::signalSendPacket(QString _t1, MIDIPacket _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
