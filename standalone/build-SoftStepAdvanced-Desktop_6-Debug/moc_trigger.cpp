// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'trigger.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/trigger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trigger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Trigger_t {
    const uint offsetsAndSize[46];
    char stringdata0[470];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Trigger_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Trigger_t qt_meta_stringdata_Trigger = {
    {
QT_MOC_LITERAL(0, 7), // "Trigger"
QT_MOC_LITERAL(8, 19), // "signalTriggerReturn"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 23), // "signalFastTriggerReturn"
QT_MOC_LITERAL(53, 23), // "signalLongTriggerReturn"
QT_MOC_LITERAL(77, 22), // "signalDblTriggerReturn"
QT_MOC_LITERAL(100, 22), // "signalOffTriggerReturn"
QT_MOC_LITERAL(123, 28), // "signalFastTriggerLatchReturn"
QT_MOC_LITERAL(152, 27), // "signalDblTriggerLatchReturn"
QT_MOC_LITERAL(180, 28), // "signalLongTriggerLatchReturn"
QT_MOC_LITERAL(209, 23), // "signalStartTriggerClock"
QT_MOC_LITERAL(233, 7), // "timeout"
QT_MOC_LITERAL(241, 4), // "type"
QT_MOC_LITERAL(246, 16), // "signalAbortClock"
QT_MOC_LITERAL(263, 17), // "slotTriggerReturn"
QT_MOC_LITERAL(281, 21), // "slotFastTriggerReturn"
QT_MOC_LITERAL(303, 21), // "slotLongTriggerReturn"
QT_MOC_LITERAL(325, 20), // "slotDblTriggerReturn"
QT_MOC_LITERAL(346, 20), // "slotOffTriggerReturn"
QT_MOC_LITERAL(367, 22), // "slotDeltaTriggerReturn"
QT_MOC_LITERAL(390, 26), // "slotFastTriggerLatchReturn"
QT_MOC_LITERAL(417, 25), // "slotDblTriggerLatchReturn"
QT_MOC_LITERAL(443, 26) // "slotLongTriggerLatchReturn"

    },
    "Trigger\0signalTriggerReturn\0\0"
    "signalFastTriggerReturn\0signalLongTriggerReturn\0"
    "signalDblTriggerReturn\0signalOffTriggerReturn\0"
    "signalFastTriggerLatchReturn\0"
    "signalDblTriggerLatchReturn\0"
    "signalLongTriggerLatchReturn\0"
    "signalStartTriggerClock\0timeout\0type\0"
    "signalAbortClock\0slotTriggerReturn\0"
    "slotFastTriggerReturn\0slotLongTriggerReturn\0"
    "slotDblTriggerReturn\0slotOffTriggerReturn\0"
    "slotDeltaTriggerReturn\0"
    "slotFastTriggerLatchReturn\0"
    "slotDblTriggerLatchReturn\0"
    "slotLongTriggerLatchReturn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Trigger[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x06,    0 /* Public */,
       3,    0,  129,    2, 0x06,    1 /* Public */,
       4,    0,  130,    2, 0x06,    2 /* Public */,
       5,    0,  131,    2, 0x06,    3 /* Public */,
       6,    0,  132,    2, 0x06,    4 /* Public */,
       7,    0,  133,    2, 0x06,    5 /* Public */,
       8,    0,  134,    2, 0x06,    6 /* Public */,
       9,    0,  135,    2, 0x06,    7 /* Public */,
      10,    2,  136,    2, 0x06,    8 /* Public */,
      13,    1,  141,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  144,    2, 0x0a,   13 /* Public */,
      15,    0,  145,    2, 0x0a,   14 /* Public */,
      16,    0,  146,    2, 0x0a,   15 /* Public */,
      17,    0,  147,    2, 0x0a,   16 /* Public */,
      18,    0,  148,    2, 0x0a,   17 /* Public */,
      19,    0,  149,    2, 0x0a,   18 /* Public */,
      20,    0,  150,    2, 0x0a,   19 /* Public */,
      21,    0,  151,    2, 0x0a,   20 /* Public */,
      22,    0,  152,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Trigger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Trigger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalTriggerReturn(); break;
        case 1: _t->signalFastTriggerReturn(); break;
        case 2: _t->signalLongTriggerReturn(); break;
        case 3: _t->signalDblTriggerReturn(); break;
        case 4: _t->signalOffTriggerReturn(); break;
        case 5: _t->signalFastTriggerLatchReturn(); break;
        case 6: _t->signalDblTriggerLatchReturn(); break;
        case 7: _t->signalLongTriggerLatchReturn(); break;
        case 8: _t->signalStartTriggerClock((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->signalAbortClock((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slotTriggerReturn(); break;
        case 11: _t->slotFastTriggerReturn(); break;
        case 12: _t->slotLongTriggerReturn(); break;
        case 13: _t->slotDblTriggerReturn(); break;
        case 14: _t->slotOffTriggerReturn(); break;
        case 15: _t->slotDeltaTriggerReturn(); break;
        case 16: _t->slotFastTriggerLatchReturn(); break;
        case 17: _t->slotDblTriggerLatchReturn(); break;
        case 18: _t->slotLongTriggerLatchReturn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalTriggerReturn)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalFastTriggerReturn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalLongTriggerReturn)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalDblTriggerReturn)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalOffTriggerReturn)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalFastTriggerLatchReturn)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalDblTriggerLatchReturn)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Trigger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalLongTriggerLatchReturn)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Trigger::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalStartTriggerClock)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Trigger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trigger::signalAbortClock)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject Trigger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Trigger.offsetsAndSize,
    qt_meta_data_Trigger,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Trigger_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Trigger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Trigger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Trigger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Trigger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Trigger::signalTriggerReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Trigger::signalFastTriggerReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Trigger::signalLongTriggerReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Trigger::signalDblTriggerReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Trigger::signalOffTriggerReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Trigger::signalFastTriggerLatchReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Trigger::signalDblTriggerLatchReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Trigger::signalLongTriggerLatchReturn()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Trigger::signalStartTriggerClock(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Trigger::signalAbortClock(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
struct qt_meta_stringdata_TriggerWorker_t {
    const uint offsetsAndSize[16];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TriggerWorker_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TriggerWorker_t qt_meta_stringdata_TriggerWorker = {
    {
QT_MOC_LITERAL(0, 13), // "TriggerWorker"
QT_MOC_LITERAL(14, 24), // "signalSendTriggerTimeout"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 21), // "slotStartTriggerClock"
QT_MOC_LITERAL(62, 7), // "timeout"
QT_MOC_LITERAL(70, 4), // "type"
QT_MOC_LITERAL(75, 21), // "slotAbortTriggerClock"
QT_MOC_LITERAL(97, 24) // "slotReturnTriggerTimeout"

    },
    "TriggerWorker\0signalSendTriggerTimeout\0"
    "\0slotStartTriggerClock\0timeout\0type\0"
    "slotAbortTriggerClock\0slotReturnTriggerTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TriggerWorker[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   39,    2, 0x0a,    1 /* Public */,
       6,    1,   44,    2, 0x0a,    4 /* Public */,
       7,    0,   47,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void TriggerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TriggerWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendTriggerTimeout(); break;
        case 1: _t->slotStartTriggerClock((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slotAbortTriggerClock((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotReturnTriggerTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TriggerWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TriggerWorker::signalSendTriggerTimeout)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TriggerWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TriggerWorker.offsetsAndSize,
    qt_meta_data_TriggerWorker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TriggerWorker_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TriggerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TriggerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TriggerWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TriggerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TriggerWorker::signalSendTriggerTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
