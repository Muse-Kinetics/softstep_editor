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
#include "../advanced/key.h"
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
    const uint offsetsAndSize[76];
    char stringdata0[567];
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
QT_MOC_LITERAL(65, 19), // "signalDeleteModline"
QT_MOC_LITERAL(85, 11), // "numModlines"
QT_MOC_LITERAL(97, 7), // "disable"
QT_MOC_LITERAL(105, 18), // "signalCounterValue"
QT_MOC_LITERAL(124, 3), // "val"
QT_MOC_LITERAL(128, 17), // "signalKeySelected"
QT_MOC_LITERAL(146, 14), // "slotOpenWindow"
QT_MOC_LITERAL(161, 19), // "slotConnectElements"
QT_MOC_LITERAL(181, 22), // "slotDisconnectElements"
QT_MOC_LITERAL(204, 16), // "slotValueChanged"
QT_MOC_LITERAL(221, 16), // "slotRecallPreset"
QT_MOC_LITERAL(238, 11), // "slotSetMode"
QT_MOC_LITERAL(250, 1), // "m"
QT_MOC_LITERAL(252, 17), // "slotPopulateMenus"
QT_MOC_LITERAL(270, 12), // "displayModes"
QT_MOC_LITERAL(283, 25), // "slotSetDataCookerSettings"
QT_MOC_LITERAL(309, 23), // "slotSetAlphaNumSettings"
QT_MOC_LITERAL(333, 11), // "slotCounter"
QT_MOC_LITERAL(345, 8), // "whatToDo"
QT_MOC_LITERAL(354, 23), // "slotShowDisplaySettings"
QT_MOC_LITERAL(378, 22), // "slotRecallShowModlines"
QT_MOC_LITERAL(401, 23), // "slotAddSubtractModlines"
QT_MOC_LITERAL(425, 16), // "slotWindowHeight"
QT_MOC_LITERAL(442, 17), // "slotSetPresetName"
QT_MOC_LITERAL(460, 21), // "slotBackgroundClicked"
QT_MOC_LITERAL(482, 22), // "slotSelectedKeyOutline"
QT_MOC_LITERAL(505, 11), // "selectedKey"
QT_MOC_LITERAL(517, 8), // "outlined"
QT_MOC_LITERAL(526, 17), // "slotSetMainWindow"
QT_MOC_LITERAL(544, 11), // "MainWindow*"
QT_MOC_LITERAL(556, 10) // "mainWindow"

    },
    "Key\0signalStoreValue\0\0name\0value\0"
    "presetNum\0signalCheckSavedState\0"
    "signalDeleteModline\0numModlines\0disable\0"
    "signalCounterValue\0val\0signalKeySelected\0"
    "slotOpenWindow\0slotConnectElements\0"
    "slotDisconnectElements\0slotValueChanged\0"
    "slotRecallPreset\0slotSetMode\0m\0"
    "slotPopulateMenus\0displayModes\0"
    "slotSetDataCookerSettings\0"
    "slotSetAlphaNumSettings\0slotCounter\0"
    "whatToDo\0slotShowDisplaySettings\0"
    "slotRecallShowModlines\0slotAddSubtractModlines\0"
    "slotWindowHeight\0slotSetPresetName\0"
    "slotBackgroundClicked\0slotSelectedKeyOutline\0"
    "selectedKey\0outlined\0slotSetMainWindow\0"
    "MainWindow*\0mainWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Key[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  152,    2, 0x06,    0 /* Public */,
       6,    0,  159,    2, 0x06,    4 /* Public */,
       7,    2,  160,    2, 0x06,    5 /* Public */,
      10,    1,  165,    2, 0x06,    8 /* Public */,
      12,    1,  168,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,  171,    2, 0x0a,   12 /* Public */,
      14,    0,  172,    2, 0x0a,   13 /* Public */,
      15,    0,  173,    2, 0x0a,   14 /* Public */,
      16,    0,  174,    2, 0x0a,   15 /* Public */,
      17,    2,  175,    2, 0x0a,   16 /* Public */,
      18,    1,  180,    2, 0x0a,   19 /* Public */,
      20,    1,  183,    2, 0x0a,   21 /* Public */,
      22,    0,  186,    2, 0x0a,   23 /* Public */,
      23,    0,  187,    2, 0x0a,   24 /* Public */,
      24,    2,  188,    2, 0x0a,   25 /* Public */,
      26,    1,  193,    2, 0x0a,   28 /* Public */,
      27,    2,  196,    2, 0x0a,   30 /* Public */,
      28,    0,  201,    2, 0x0a,   33 /* Public */,
      29,    1,  202,    2, 0x0a,   34 /* Public */,
      30,    1,  205,    2, 0x0a,   36 /* Public */,
      31,    0,  208,    2, 0x0a,   38 /* Public */,
      32,    2,  209,    2, 0x0a,   39 /* Public */,
      35,    1,  214,    2, 0x0a,   42 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   25,   11,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   33,   34,
    QMetaType::Void, 0x80000000 | 36,   37,

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
        case 2: _t->signalDeleteModline((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->signalCounterValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signalKeySelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotOpenWindow(); break;
        case 6: _t->slotConnectElements(); break;
        case 7: _t->slotDisconnectElements(); break;
        case 8: _t->slotValueChanged(); break;
        case 9: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 10: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slotPopulateMenus((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 12: _t->slotSetDataCookerSettings(); break;
        case 13: _t->slotSetAlphaNumSettings(); break;
        case 14: _t->slotCounter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->slotShowDisplaySettings((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->slotRecallShowModlines((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 17: _t->slotAddSubtractModlines(); break;
        case 18: _t->slotWindowHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->slotSetPresetName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->slotBackgroundClicked(); break;
        case 21: _t->slotSelectedKeyOutline((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->slotSetMainWindow((*reinterpret_cast< MainWindow*(*)>(_a[1]))); break;
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
        {
            using _t = void (Key::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Key::signalDeleteModline)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Key::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Key::signalCounterValue)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Key::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Key::signalKeySelected)) {
                *result = 4;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MainWindow *, std::false_type>


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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
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

// SIGNAL 2
void Key::signalDeleteModline(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Key::signalCounterValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Key::signalKeySelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
