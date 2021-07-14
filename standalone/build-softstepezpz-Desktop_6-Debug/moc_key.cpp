// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'key.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ezpz/key.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'key.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Key_t {
    const uint offsetsAndSize[26];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Key_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Key_t qt_meta_stringdata_Key = {
    {
QT_MOC_LITERAL(0, 3), // "Key"
QT_MOC_LITERAL(4, 16), // "signalStoreValue"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 4), // "name"
QT_MOC_LITERAL(27, 5), // "value"
QT_MOC_LITERAL(33, 9), // "presetNum"
QT_MOC_LITERAL(43, 21), // "signalCheckSavedState"
QT_MOC_LITERAL(65, 19), // "slotConnectElements"
QT_MOC_LITERAL(85, 16), // "slotValueChanged"
QT_MOC_LITERAL(102, 16), // "slotRecallPreset"
QT_MOC_LITERAL(119, 6), // "preset"
QT_MOC_LITERAL(126, 6), // "master"
QT_MOC_LITERAL(133, 26) // "slotEnableDisableKeyEvents"

    },
    "Key\0signalStoreValue\0\0name\0value\0"
    "presetNum\0signalCheckSavedState\0"
    "slotConnectElements\0slotValueChanged\0"
    "slotRecallPreset\0preset\0master\0"
    "slotEnableDisableKeyEvents"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Key[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   50,    2, 0x06,    0 /* Public */,
       6,    0,   57,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   58,    2, 0x0a,    5 /* Public */,
       8,    0,   59,    2, 0x0a,    6 /* Public */,
       9,    2,   60,    2, 0x0a,    7 /* Public */,
      12,    1,   65,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,   10,   11,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Key::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Key *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->signalCheckSavedState(); break;
        case 2: _t->slotConnectElements(); break;
        case 3: _t->slotValueChanged(); break;
        case 4: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 5: _t->slotEnableDisableKeyEvents((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Key::*)(QString , QVariant , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Key::signalStoreValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Key::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Key::signalCheckSavedState)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Key::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Key.offsetsAndSize,
    qt_meta_data_Key,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Key_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Key::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Key::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Key.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Key::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Key::signalStoreValue(QString _t1, QVariant _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Key::signalCheckSavedState()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
