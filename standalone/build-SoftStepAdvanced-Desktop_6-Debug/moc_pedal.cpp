// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'pedal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/pedal.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pedal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pedal_t {
    const uint offsetsAndSize[46];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Pedal_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Pedal_t qt_meta_stringdata_Pedal = {
    {
QT_MOC_LITERAL(0, 5), // "Pedal"
QT_MOC_LITERAL(6, 15), // "signalDrawTable"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 12), // "QList<uchar>"
QT_MOC_LITERAL(36, 18), // "signalLivePedalVal"
QT_MOC_LITERAL(55, 22), // "signalWriteTableToDisk"
QT_MOC_LITERAL(78, 22), // "signalResetOnZeroInput"
QT_MOC_LITERAL(101, 19), // "slotSetLeverPointer"
QT_MOC_LITERAL(121, 7), // "QLabel*"
QT_MOC_LITERAL(129, 5), // "lever"
QT_MOC_LITERAL(135, 15), // "slotWindowInput"
QT_MOC_LITERAL(151, 10), // "pedalInput"
QT_MOC_LITERAL(162, 14), // "slotTableInput"
QT_MOC_LITERAL(177, 18), // "slotStartCalibrate"
QT_MOC_LITERAL(196, 13), // "slotCalibrate"
QT_MOC_LITERAL(210, 17), // "slotStopCalibrate"
QT_MOC_LITERAL(228, 18), // "slotResetCalibrate"
QT_MOC_LITERAL(247, 19), // "slotSetMinMaxLength"
QT_MOC_LITERAL(267, 23), // "slotWritePedalTableFile"
QT_MOC_LITERAL(291, 21), // "slotSetLivePedalValue"
QT_MOC_LITERAL(313, 3), // "val"
QT_MOC_LITERAL(317, 18), // "slotInitPedalTable"
QT_MOC_LITERAL(336, 5) // "table"

    },
    "Pedal\0signalDrawTable\0\0QList<uchar>\0"
    "signalLivePedalVal\0signalWriteTableToDisk\0"
    "signalResetOnZeroInput\0slotSetLeverPointer\0"
    "QLabel*\0lever\0slotWindowInput\0pedalInput\0"
    "slotTableInput\0slotStartCalibrate\0"
    "slotCalibrate\0slotStopCalibrate\0"
    "slotResetCalibrate\0slotSetMinMaxLength\0"
    "slotWritePedalTableFile\0slotSetLivePedalValue\0"
    "val\0slotInitPedalTable\0table"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pedal[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    0 /* Public */,
       4,    1,  107,    2, 0x06,    2 /* Public */,
       5,    1,  110,    2, 0x06,    4 /* Public */,
       6,    0,  113,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,  114,    2, 0x0a,    7 /* Public */,
      10,    1,  117,    2, 0x0a,    9 /* Public */,
      12,    1,  120,    2, 0x0a,   11 /* Public */,
      13,    0,  123,    2, 0x0a,   13 /* Public */,
      14,    1,  124,    2, 0x0a,   14 /* Public */,
      15,    0,  127,    2, 0x0a,   16 /* Public */,
      16,    0,  128,    2, 0x0a,   17 /* Public */,
      17,    0,  129,    2, 0x0a,   18 /* Public */,
      18,    0,  130,    2, 0x0a,   19 /* Public */,
      19,    1,  131,    2, 0x0a,   20 /* Public */,
      21,    1,  134,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Int, QMetaType::Int,   11,
    QMetaType::Int, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QByteArray,   22,

       0        // eod
};

void Pedal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pedal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalDrawTable((*reinterpret_cast< QList<uchar>(*)>(_a[1]))); break;
        case 1: _t->signalLivePedalVal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalWriteTableToDisk((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->signalResetOnZeroInput(); break;
        case 4: _t->slotSetLeverPointer((*reinterpret_cast< QLabel*(*)>(_a[1]))); break;
        case 5: { int _r = _t->slotWindowInput((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->slotTableInput((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->slotStartCalibrate(); break;
        case 8: _t->slotCalibrate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotStopCalibrate(); break;
        case 10: _t->slotResetCalibrate(); break;
        case 11: _t->slotSetMinMaxLength(); break;
        case 12: _t->slotWritePedalTableFile(); break;
        case 13: _t->slotSetLivePedalValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->slotInitPedalTable((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<uchar> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pedal::*)(QList<unsigned char> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pedal::signalDrawTable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pedal::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pedal::signalLivePedalVal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Pedal::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pedal::signalWriteTableToDisk)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Pedal::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pedal::signalResetOnZeroInput)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Pedal::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Pedal.offsetsAndSize,
    qt_meta_data_Pedal,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Pedal_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<unsigned char>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QLabel *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *Pedal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pedal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pedal.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Pedal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Pedal::signalDrawTable(QList<unsigned char> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Pedal::signalLivePedalVal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Pedal::signalWriteTableToDisk(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Pedal::signalResetOnZeroInput()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
