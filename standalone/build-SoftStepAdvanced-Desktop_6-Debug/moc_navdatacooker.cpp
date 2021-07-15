// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'navdatacooker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/navdatacooker.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navdatacooker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavDataCooker_t {
    const uint offsetsAndSize[108];
    char stringdata0[857];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NavDataCooker_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NavDataCooker_t qt_meta_stringdata_NavDataCooker = {
    {
QT_MOC_LITERAL(0, 13), // "NavDataCooker"
QT_MOC_LITERAL(14, 21), // "signalTransformSource"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 4), // "data"
QT_MOC_LITERAL(42, 10), // "modlineNum"
QT_MOC_LITERAL(53, 6), // "source"
QT_MOC_LITERAL(60, 10), // "signalNavY"
QT_MOC_LITERAL(71, 6), // "yCount"
QT_MOC_LITERAL(78, 15), // "signalNavDecade"
QT_MOC_LITERAL(94, 7), // "yDecade"
QT_MOC_LITERAL(102, 18), // "signalPresetChange"
QT_MOC_LITERAL(121, 20), // "signalThisKeyPressed"
QT_MOC_LITERAL(142, 16), // "signalThisKeyOff"
QT_MOC_LITERAL(159, 32), // "signalDisplayProgramChangeDecade"
QT_MOC_LITERAL(192, 14), // "slotUpdateVals"
QT_MOC_LITERAL(207, 2), // "cc"
QT_MOC_LITERAL(210, 3), // "val"
QT_MOC_LITERAL(214, 13), // "slotSetSource"
QT_MOC_LITERAL(228, 15), // "modlineInstance"
QT_MOC_LITERAL(244, 20), // "slotSetCounterParams"
QT_MOC_LITERAL(265, 3), // "min"
QT_MOC_LITERAL(269, 3), // "max"
QT_MOC_LITERAL(273, 4), // "wrap"
QT_MOC_LITERAL(278, 23), // "slotTickYIncrementClock"
QT_MOC_LITERAL(302, 18), // "slotTriggerReturnN"
QT_MOC_LITERAL(321, 15), // "slotTriggerOffN"
QT_MOC_LITERAL(337, 22), // "slotFastTriggerReturnN"
QT_MOC_LITERAL(360, 19), // "slotFastTriggerOffN"
QT_MOC_LITERAL(380, 22), // "slotLongTriggerReturnN"
QT_MOC_LITERAL(403, 19), // "slotLongTriggerOffN"
QT_MOC_LITERAL(423, 21), // "slotDblTriggerReturnN"
QT_MOC_LITERAL(445, 18), // "slotDblTriggerOffN"
QT_MOC_LITERAL(464, 18), // "slotTriggerReturnS"
QT_MOC_LITERAL(483, 15), // "slotTriggerOffS"
QT_MOC_LITERAL(499, 22), // "slotFastTriggerReturnS"
QT_MOC_LITERAL(522, 19), // "slotFastTriggerOffS"
QT_MOC_LITERAL(542, 22), // "slotLongTriggerReturnS"
QT_MOC_LITERAL(565, 19), // "slotLongTriggerOffS"
QT_MOC_LITERAL(585, 21), // "slotDblTriggerReturnS"
QT_MOC_LITERAL(607, 18), // "slotDblTriggerOffS"
QT_MOC_LITERAL(626, 20), // "slotReceiveMidiInput"
QT_MOC_LITERAL(647, 8), // "instance"
QT_MOC_LITERAL(656, 17), // "slotSetGlobalGain"
QT_MOC_LITERAL(674, 16), // "slotSetOnThreshN"
QT_MOC_LITERAL(691, 17), // "slotSetOffThreshN"
QT_MOC_LITERAL(709, 16), // "slotSetOnThreshS"
QT_MOC_LITERAL(726, 17), // "slotSetOffThreshS"
QT_MOC_LITERAL(744, 16), // "slotSetOnThreshE"
QT_MOC_LITERAL(761, 17), // "slotSetOffThreshE"
QT_MOC_LITERAL(779, 16), // "slotSetOnThreshW"
QT_MOC_LITERAL(796, 17), // "slotSetOffThreshW"
QT_MOC_LITERAL(814, 13), // "slotSetYAccel"
QT_MOC_LITERAL(828, 19), // "slotReceiveOscInput"
QT_MOC_LITERAL(848, 8) // "inputNum"

    },
    "NavDataCooker\0signalTransformSource\0"
    "\0data\0modlineNum\0source\0signalNavY\0"
    "yCount\0signalNavDecade\0yDecade\0"
    "signalPresetChange\0signalThisKeyPressed\0"
    "signalThisKeyOff\0signalDisplayProgramChangeDecade\0"
    "slotUpdateVals\0cc\0val\0slotSetSource\0"
    "modlineInstance\0slotSetCounterParams\0"
    "min\0max\0wrap\0slotTickYIncrementClock\0"
    "slotTriggerReturnN\0slotTriggerOffN\0"
    "slotFastTriggerReturnN\0slotFastTriggerOffN\0"
    "slotLongTriggerReturnN\0slotLongTriggerOffN\0"
    "slotDblTriggerReturnN\0slotDblTriggerOffN\0"
    "slotTriggerReturnS\0slotTriggerOffS\0"
    "slotFastTriggerReturnS\0slotFastTriggerOffS\0"
    "slotLongTriggerReturnS\0slotLongTriggerOffS\0"
    "slotDblTriggerReturnS\0slotDblTriggerOffS\0"
    "slotReceiveMidiInput\0instance\0"
    "slotSetGlobalGain\0slotSetOnThreshN\0"
    "slotSetOffThreshN\0slotSetOnThreshS\0"
    "slotSetOffThreshS\0slotSetOnThreshE\0"
    "slotSetOffThreshE\0slotSetOnThreshW\0"
    "slotSetOffThreshW\0slotSetYAccel\0"
    "slotReceiveOscInput\0inputNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavDataCooker[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  248,    2, 0x06,    0 /* Public */,
       6,    1,  255,    2, 0x06,    4 /* Public */,
       8,    1,  258,    2, 0x06,    6 /* Public */,
      10,    1,  261,    2, 0x06,    8 /* Public */,
      11,    1,  264,    2, 0x06,   10 /* Public */,
      12,    1,  267,    2, 0x06,   12 /* Public */,
      13,    1,  270,    2, 0x06,   14 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    2,  273,    2, 0x0a,   16 /* Public */,
      17,    2,  278,    2, 0x0a,   19 /* Public */,
      19,    3,  283,    2, 0x0a,   22 /* Public */,
      23,    0,  290,    2, 0x0a,   26 /* Public */,
      24,    0,  291,    2, 0x0a,   27 /* Public */,
      25,    0,  292,    2, 0x0a,   28 /* Public */,
      26,    0,  293,    2, 0x0a,   29 /* Public */,
      27,    0,  294,    2, 0x0a,   30 /* Public */,
      28,    0,  295,    2, 0x0a,   31 /* Public */,
      29,    0,  296,    2, 0x0a,   32 /* Public */,
      30,    0,  297,    2, 0x0a,   33 /* Public */,
      31,    0,  298,    2, 0x0a,   34 /* Public */,
      32,    0,  299,    2, 0x0a,   35 /* Public */,
      33,    0,  300,    2, 0x0a,   36 /* Public */,
      34,    0,  301,    2, 0x0a,   37 /* Public */,
      35,    0,  302,    2, 0x0a,   38 /* Public */,
      36,    0,  303,    2, 0x0a,   39 /* Public */,
      37,    0,  304,    2, 0x0a,   40 /* Public */,
      38,    0,  305,    2, 0x0a,   41 /* Public */,
      39,    0,  306,    2, 0x0a,   42 /* Public */,
      40,    2,  307,    2, 0x0a,   43 /* Public */,
      42,    1,  312,    2, 0x0a,   46 /* Public */,
      43,    1,  315,    2, 0x0a,   48 /* Public */,
      44,    1,  318,    2, 0x0a,   50 /* Public */,
      45,    1,  321,    2, 0x0a,   52 /* Public */,
      46,    1,  324,    2, 0x0a,   54 /* Public */,
      47,    1,  327,    2, 0x0a,   56 /* Public */,
      48,    1,  330,    2, 0x0a,   58 /* Public */,
      49,    1,  333,    2, 0x0a,   60 /* Public */,
      50,    1,  336,    2, 0x0a,   62 /* Public */,
      51,    1,  339,    2, 0x0a,   64 /* Public */,
      52,    2,  342,    2, 0x0a,   66 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   20,   21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,   41,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   53,   16,

       0        // eod
};

void NavDataCooker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavDataCooker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalTransformSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->signalNavY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalNavDecade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalPresetChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->signalThisKeyPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalThisKeyOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signalDisplayProgramChangeDecade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotUpdateVals((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->slotSetSource((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->slotSetCounterParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->slotTickYIncrementClock(); break;
        case 11: _t->slotTriggerReturnN(); break;
        case 12: _t->slotTriggerOffN(); break;
        case 13: _t->slotFastTriggerReturnN(); break;
        case 14: _t->slotFastTriggerOffN(); break;
        case 15: _t->slotLongTriggerReturnN(); break;
        case 16: _t->slotLongTriggerOffN(); break;
        case 17: _t->slotDblTriggerReturnN(); break;
        case 18: _t->slotDblTriggerOffN(); break;
        case 19: _t->slotTriggerReturnS(); break;
        case 20: _t->slotTriggerOffS(); break;
        case 21: _t->slotFastTriggerReturnS(); break;
        case 22: _t->slotFastTriggerOffS(); break;
        case 23: _t->slotLongTriggerReturnS(); break;
        case 24: _t->slotLongTriggerOffS(); break;
        case 25: _t->slotDblTriggerReturnS(); break;
        case 26: _t->slotDblTriggerOffS(); break;
        case 27: _t->slotReceiveMidiInput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 28: _t->slotSetGlobalGain((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 29: _t->slotSetOnThreshN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->slotSetOffThreshN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->slotSetOnThreshS((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->slotSetOffThreshS((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->slotSetOnThreshE((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->slotSetOffThreshE((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->slotSetOnThreshW((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->slotSetOffThreshW((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->slotSetYAccel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->slotReceiveOscInput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NavDataCooker::*)(int , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalTransformSource)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NavDataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalNavY)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NavDataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalNavDecade)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NavDataCooker::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalPresetChange)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NavDataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalThisKeyPressed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NavDataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalThisKeyOff)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NavDataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavDataCooker::signalDisplayProgramChangeDecade)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject NavDataCooker::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_NavDataCooker.offsetsAndSize,
    qt_meta_data_NavDataCooker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NavDataCooker_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *NavDataCooker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavDataCooker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavDataCooker.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int NavDataCooker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void NavDataCooker::signalTransformSource(int _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NavDataCooker::signalNavY(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NavDataCooker::signalNavDecade(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NavDataCooker::signalPresetChange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NavDataCooker::signalThisKeyPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NavDataCooker::signalThisKeyOff(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NavDataCooker::signalDisplayProgramChangeDecade(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
