// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'presetinterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ezpz/presetinterface.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'presetinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PresetInterface_t {
    const uint offsetsAndSize[48];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PresetInterface_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PresetInterface_t qt_meta_stringdata_PresetInterface = {
    {
QT_MOC_LITERAL(0, 15), // "PresetInterface"
QT_MOC_LITERAL(16, 18), // "signalRecallPreset"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 27), // "signalAttributeFormatPreset"
QT_MOC_LITERAL(64, 19), // "signalUpdateStarted"
QT_MOC_LITERAL(84, 17), // "signalPresetDirty"
QT_MOC_LITERAL(102, 24), // "signalSetPresetToFactory"
QT_MOC_LITERAL(127, 14), // "slotStoreValue"
QT_MOC_LITERAL(142, 4), // "name"
QT_MOC_LITERAL(147, 5), // "value"
QT_MOC_LITERAL(153, 9), // "presetNum"
QT_MOC_LITERAL(163, 18), // "slotCheckSaveState"
QT_MOC_LITERAL(182, 15), // "slotStoreGlobal"
QT_MOC_LITERAL(198, 12), // "slotReadJSON"
QT_MOC_LITERAL(211, 13), // "slotWriteJSON"
QT_MOC_LITERAL(225, 7), // "jsonMap"
QT_MOC_LITERAL(233, 23), // "slotConstructDefaultMap"
QT_MOC_LITERAL(257, 16), // "slotRecallPreset"
QT_MOC_LITERAL(274, 1), // "i"
QT_MOC_LITERAL(276, 16), // "slotRevertPreset"
QT_MOC_LITERAL(293, 16), // "slotImportPreset"
QT_MOC_LITERAL(310, 16), // "slotExportPreset"
QT_MOC_LITERAL(327, 17), // "slotUpdateClicked"
QT_MOC_LITERAL(345, 29) // "slotSetCurrentPresetToFactory"

    },
    "PresetInterface\0signalRecallPreset\0\0"
    "signalAttributeFormatPreset\0"
    "signalUpdateStarted\0signalPresetDirty\0"
    "signalSetPresetToFactory\0slotStoreValue\0"
    "name\0value\0presetNum\0slotCheckSaveState\0"
    "slotStoreGlobal\0slotReadJSON\0slotWriteJSON\0"
    "jsonMap\0slotConstructDefaultMap\0"
    "slotRecallPreset\0i\0slotRevertPreset\0"
    "slotImportPreset\0slotExportPreset\0"
    "slotUpdateClicked\0slotSetCurrentPresetToFactory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PresetInterface[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  116,    2, 0x06,    0 /* Public */,
       3,    3,  121,    2, 0x06,    3 /* Public */,
       4,    0,  128,    2, 0x06,    7 /* Public */,
       5,    1,  129,    2, 0x06,    8 /* Public */,
       6,    2,  132,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    3,  137,    2, 0x0a,   13 /* Public */,
      11,    0,  144,    2, 0x0a,   17 /* Public */,
      12,    0,  145,    2, 0x0a,   18 /* Public */,
      13,    0,  146,    2, 0x0a,   19 /* Public */,
      14,    1,  147,    2, 0x0a,   20 /* Public */,
      16,    0,  150,    2, 0x0a,   22 /* Public */,
      17,    1,  151,    2, 0x0a,   23 /* Public */,
      19,    0,  154,    2, 0x0a,   25 /* Public */,
      20,    0,  155,    2, 0x0a,   26 /* Public */,
      21,    0,  156,    2, 0x0a,   27 /* Public */,
      22,    0,  157,    2, 0x0a,   28 /* Public */,
      23,    0,  158,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap, QMetaType::LongLong,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PresetInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PresetInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 1: _t->signalAttributeFormatPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2])),(*reinterpret_cast< qlonglong(*)>(_a[3]))); break;
        case 2: _t->signalUpdateStarted(); break;
        case 3: _t->signalPresetDirty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->signalSetPresetToFactory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->slotStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slotCheckSaveState(); break;
        case 7: _t->slotStoreGlobal(); break;
        case 8: _t->slotReadJSON(); break;
        case 9: _t->slotWriteJSON((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 10: _t->slotConstructDefaultMap(); break;
        case 11: _t->slotRecallPreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotRevertPreset(); break;
        case 13: _t->slotImportPreset(); break;
        case 14: _t->slotExportPreset(); break;
        case 15: _t->slotUpdateClicked(); break;
        case 16: _t->slotSetCurrentPresetToFactory(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PresetInterface::*)(QVariantMap , QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalRecallPreset)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)(QVariantMap , QVariantMap , qlonglong );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalAttributeFormatPreset)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalUpdateStarted)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalPresetDirty)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalSetPresetToFactory)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject PresetInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PresetInterface.offsetsAndSize,
    qt_meta_data_PresetInterface,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PresetInterface_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<qlonglong, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PresetInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PresetInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PresetInterface.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PresetInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void PresetInterface::signalRecallPreset(QVariantMap _t1, QVariantMap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PresetInterface::signalAttributeFormatPreset(QVariantMap _t1, QVariantMap _t2, qlonglong _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PresetInterface::signalUpdateStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PresetInterface::signalPresetDirty(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PresetInterface::signalSetPresetToFactory(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
