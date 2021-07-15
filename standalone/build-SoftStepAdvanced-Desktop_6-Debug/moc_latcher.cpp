// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'latcher.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/latcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'latcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Latcher_t {
    const uint offsetsAndSize[16];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Latcher_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Latcher_t qt_meta_stringdata_Latcher = {
    {
QT_MOC_LITERAL(0, 7), // "Latcher"
QT_MOC_LITERAL(8, 18), // "signalProcessInput"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 3), // "val"
QT_MOC_LITERAL(32, 17), // "signalReturnValue"
QT_MOC_LITERAL(50, 10), // "modlineNum"
QT_MOC_LITERAL(61, 19), // "slotInputFromStream"
QT_MOC_LITERAL(81, 23) // "slotReceiveLatchedValue"

    },
    "Latcher\0signalProcessInput\0\0val\0"
    "signalReturnValue\0modlineNum\0"
    "slotInputFromStream\0slotReceiveLatchedValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Latcher[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    0 /* Public */,
       4,    2,   41,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   46,    2, 0x0a,    5 /* Public */,
       7,    1,   49,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Latcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Latcher *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalProcessInput((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->signalReturnValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slotInputFromStream((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->slotReceiveLatchedValue((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Latcher::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Latcher::signalProcessInput)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Latcher::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Latcher::signalReturnValue)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Latcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QTimer::staticMetaObject>(),
    qt_meta_stringdata_Latcher.offsetsAndSize,
    qt_meta_data_Latcher,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Latcher_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Latcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Latcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Latcher.stringdata0))
        return static_cast<void*>(this);
    return QTimer::qt_metacast(_clname);
}

int Latcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
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
void Latcher::signalProcessInput(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Latcher::signalReturnValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_LatcherWorker_t {
    const uint offsetsAndSize[14];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_LatcherWorker_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_LatcherWorker_t qt_meta_stringdata_LatcherWorker = {
    {
QT_MOC_LITERAL(0, 13), // "LatcherWorker"
QT_MOC_LITERAL(14, 22), // "signalSendLatchedValue"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 3), // "val"
QT_MOC_LITERAL(42, 16), // "slotProcessInput"
QT_MOC_LITERAL(59, 14), // "slotDelayInput"
QT_MOC_LITERAL(74, 15) // "slotReturnInput"

    },
    "LatcherWorker\0signalSendLatchedValue\0"
    "\0val\0slotProcessInput\0slotDelayInput\0"
    "slotReturnInput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LatcherWorker[] = {

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
       1,    1,   38,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   41,    2, 0x0a,    2 /* Public */,
       5,    0,   44,    2, 0x0a,    4 /* Public */,
       6,    1,   45,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void LatcherWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LatcherWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendLatchedValue((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->slotProcessInput((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->slotDelayInput(); break;
        case 3: _t->slotReturnInput((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LatcherWorker::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LatcherWorker::signalSendLatchedValue)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LatcherWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LatcherWorker.offsetsAndSize,
    qt_meta_data_LatcherWorker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LatcherWorker_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *LatcherWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LatcherWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LatcherWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LatcherWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void LatcherWorker::signalSendLatchedValue(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
