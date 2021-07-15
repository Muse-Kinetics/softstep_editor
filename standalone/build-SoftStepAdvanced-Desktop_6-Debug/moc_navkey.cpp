// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'navkey.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/navkey.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navkey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavKey_t {
    const uint offsetsAndSize[64];
    char stringdata0[498];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NavKey_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NavKey_t qt_meta_stringdata_NavKey = {
    {
QT_MOC_LITERAL(0, 6), // "NavKey"
QT_MOC_LITERAL(7, 16), // "signalStoreValue"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 4), // "name"
QT_MOC_LITERAL(30, 5), // "value"
QT_MOC_LITERAL(36, 9), // "presetNum"
QT_MOC_LITERAL(46, 21), // "signalCheckSavedState"
QT_MOC_LITERAL(68, 19), // "signalDeleteModline"
QT_MOC_LITERAL(88, 11), // "numModlines"
QT_MOC_LITERAL(100, 7), // "disable"
QT_MOC_LITERAL(108, 18), // "signalCounterValue"
QT_MOC_LITERAL(127, 3), // "val"
QT_MOC_LITERAL(131, 14), // "slotOpenWindow"
QT_MOC_LITERAL(146, 19), // "slotConnectElements"
QT_MOC_LITERAL(166, 22), // "slotDisconnectElements"
QT_MOC_LITERAL(189, 16), // "slotValueChanged"
QT_MOC_LITERAL(206, 16), // "slotRecallPreset"
QT_MOC_LITERAL(223, 11), // "slotSetMode"
QT_MOC_LITERAL(235, 1), // "m"
QT_MOC_LITERAL(237, 17), // "slotPopulateMenus"
QT_MOC_LITERAL(255, 12), // "displayModes"
QT_MOC_LITERAL(268, 25), // "slotSetDataCookerSettings"
QT_MOC_LITERAL(294, 23), // "slotSetAlphaNumSettings"
QT_MOC_LITERAL(318, 11), // "slotCounter"
QT_MOC_LITERAL(330, 8), // "whatToDo"
QT_MOC_LITERAL(339, 23), // "slotShowDisplaySettings"
QT_MOC_LITERAL(363, 22), // "slotRecallShowModlines"
QT_MOC_LITERAL(386, 23), // "slotAddSubtractModlines"
QT_MOC_LITERAL(410, 16), // "slotWindowHeight"
QT_MOC_LITERAL(427, 17), // "slotSetPresetName"
QT_MOC_LITERAL(445, 21), // "slotUpdateModlineMode"
QT_MOC_LITERAL(467, 30) // "slotDisplayProgramChangeDecade"

    },
    "NavKey\0signalStoreValue\0\0name\0value\0"
    "presetNum\0signalCheckSavedState\0"
    "signalDeleteModline\0numModlines\0disable\0"
    "signalCounterValue\0val\0slotOpenWindow\0"
    "slotConnectElements\0slotDisconnectElements\0"
    "slotValueChanged\0slotRecallPreset\0"
    "slotSetMode\0m\0slotPopulateMenus\0"
    "displayModes\0slotSetDataCookerSettings\0"
    "slotSetAlphaNumSettings\0slotCounter\0"
    "whatToDo\0slotShowDisplaySettings\0"
    "slotRecallShowModlines\0slotAddSubtractModlines\0"
    "slotWindowHeight\0slotSetPresetName\0"
    "slotUpdateModlineMode\0"
    "slotDisplayProgramChangeDecade"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavKey[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  140,    2, 0x06,    0 /* Public */,
       6,    0,  147,    2, 0x06,    4 /* Public */,
       7,    2,  148,    2, 0x06,    5 /* Public */,
      10,    1,  153,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  156,    2, 0x0a,   10 /* Public */,
      13,    0,  157,    2, 0x0a,   11 /* Public */,
      14,    0,  158,    2, 0x0a,   12 /* Public */,
      15,    0,  159,    2, 0x0a,   13 /* Public */,
      16,    2,  160,    2, 0x0a,   14 /* Public */,
      17,    1,  165,    2, 0x0a,   17 /* Public */,
      19,    1,  168,    2, 0x0a,   19 /* Public */,
      21,    0,  171,    2, 0x0a,   21 /* Public */,
      22,    0,  172,    2, 0x0a,   22 /* Public */,
      23,    2,  173,    2, 0x0a,   23 /* Public */,
      25,    1,  178,    2, 0x0a,   26 /* Public */,
      26,    2,  181,    2, 0x0a,   28 /* Public */,
      27,    0,  186,    2, 0x0a,   31 /* Public */,
      28,    1,  187,    2, 0x0a,   32 /* Public */,
      29,    1,  190,    2, 0x0a,   34 /* Public */,
      30,    0,  193,    2, 0x0a,   36 /* Public */,
      31,    1,  194,    2, 0x0a,   37 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QStringList,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   24,   11,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void NavKey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavKey *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->signalCheckSavedState(); break;
        case 2: _t->signalDeleteModline((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->signalCounterValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotOpenWindow(); break;
        case 5: _t->slotConnectElements(); break;
        case 6: _t->slotDisconnectElements(); break;
        case 7: _t->slotValueChanged(); break;
        case 8: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 9: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slotPopulateMenus((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 11: _t->slotSetDataCookerSettings(); break;
        case 12: _t->slotSetAlphaNumSettings(); break;
        case 13: _t->slotCounter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->slotShowDisplaySettings((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->slotRecallShowModlines((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 16: _t->slotAddSubtractModlines(); break;
        case 17: _t->slotWindowHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->slotSetPresetName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->slotUpdateModlineMode(); break;
        case 20: _t->slotDisplayProgramChangeDecade((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NavKey::*)(QString , QVariant , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavKey::signalStoreValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NavKey::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavKey::signalCheckSavedState)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NavKey::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavKey::signalDeleteModline)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NavKey::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavKey::signalCounterValue)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject NavKey::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_NavKey.offsetsAndSize,
    qt_meta_data_NavKey,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NavKey_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *NavKey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavKey::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavKey.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int NavKey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void NavKey::signalStoreValue(QString _t1, QVariant _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NavKey::signalCheckSavedState()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NavKey::signalDeleteModline(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NavKey::signalCounterValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
