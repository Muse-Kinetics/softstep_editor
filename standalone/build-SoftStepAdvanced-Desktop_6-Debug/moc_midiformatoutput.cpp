// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'midiformatoutput.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/midiformatoutput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midiformatoutput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MidiFormatOutput_t {
    const uint offsetsAndSize[58];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MidiFormatOutput_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MidiFormatOutput_t qt_meta_stringdata_MidiFormatOutput = {
    {
QT_MOC_LITERAL(0, 16), // "MidiFormatOutput"
QT_MOC_LITERAL(17, 24), // "signalSendMidiPacketList"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 4), // "port"
QT_MOC_LITERAL(48, 10), // "MIDIPacket"
QT_MOC_LITERAL(59, 6), // "packet"
QT_MOC_LITERAL(66, 17), // "slotPreparePacket"
QT_MOC_LITERAL(84, 11), // "slotNoteSet"
QT_MOC_LITERAL(96, 7), // "channel"
QT_MOC_LITERAL(104, 4), // "note"
QT_MOC_LITERAL(109, 8), // "velocity"
QT_MOC_LITERAL(118, 12), // "slotNoteLive"
QT_MOC_LITERAL(131, 7), // "oldNote"
QT_MOC_LITERAL(139, 7), // "newNote"
QT_MOC_LITERAL(147, 6), // "slotCC"
QT_MOC_LITERAL(154, 5), // "ccNum"
QT_MOC_LITERAL(160, 5), // "ccVal"
QT_MOC_LITERAL(166, 8), // "slotBank"
QT_MOC_LITERAL(175, 3), // "msb"
QT_MOC_LITERAL(179, 3), // "lsb"
QT_MOC_LITERAL(183, 11), // "slotProgram"
QT_MOC_LITERAL(195, 7), // "program"
QT_MOC_LITERAL(203, 13), // "slotPitchBend"
QT_MOC_LITERAL(217, 7), // "slotMMC"
QT_MOC_LITERAL(225, 2), // "id"
QT_MOC_LITERAL(228, 8), // "function"
QT_MOC_LITERAL(237, 14), // "slotAftertouch"
QT_MOC_LITERAL(252, 3), // "val"
QT_MOC_LITERAL(256, 18) // "slotPolyAftertouch"

    },
    "MidiFormatOutput\0signalSendMidiPacketList\0"
    "\0port\0MIDIPacket\0packet\0slotPreparePacket\0"
    "slotNoteSet\0channel\0note\0velocity\0"
    "slotNoteLive\0oldNote\0newNote\0slotCC\0"
    "ccNum\0ccVal\0slotBank\0msb\0lsb\0slotProgram\0"
    "program\0slotPitchBend\0slotMMC\0id\0"
    "function\0slotAftertouch\0val\0"
    "slotPolyAftertouch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidiFormatOutput[] = {

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
       6,    0,   85,    2, 0x0a,    3 /* Public */,
       7,    4,   86,    2, 0x0a,    4 /* Public */,
      11,    5,   95,    2, 0x0a,    9 /* Public */,
      14,    4,  106,    2, 0x0a,   15 /* Public */,
      17,    4,  115,    2, 0x0a,   20 /* Public */,
      20,    3,  124,    2, 0x0a,   25 /* Public */,
      22,    4,  131,    2, 0x0a,   29 /* Public */,
      23,    3,  140,    2, 0x0a,   34 /* Public */,
      26,    3,  147,    2, 0x0a,   38 /* Public */,
      28,    4,  154,    2, 0x0a,   42 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,   12,   13,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    8,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,   19,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,   24,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    8,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    8,    9,   27,

       0        // eod
};

void MidiFormatOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MidiFormatOutput *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendMidiPacketList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< MIDIPacket(*)>(_a[2]))); break;
        case 1: _t->slotPreparePacket(); break;
        case 2: _t->slotNoteSet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->slotNoteLive((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->slotCC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->slotBank((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->slotProgram((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slotPitchBend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: _t->slotMMC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: _t->slotAftertouch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->slotPolyAftertouch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MidiFormatOutput::*)(QString , MIDIPacket );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiFormatOutput::signalSendMidiPacketList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MidiFormatOutput::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MidiFormatOutput.offsetsAndSize,
    qt_meta_data_MidiFormatOutput,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MidiFormatOutput_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<MIDIPacket, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MidiFormatOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MidiFormatOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MidiFormatOutput.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MidiFormatOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void MidiFormatOutput::signalSendMidiPacketList(QString _t1, MIDIPacket _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
