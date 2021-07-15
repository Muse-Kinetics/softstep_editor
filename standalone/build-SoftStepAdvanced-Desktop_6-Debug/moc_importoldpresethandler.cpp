// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'importoldpresethandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/importoldpresethandler.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'importoldpresethandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImportOldPresetHandler_t {
    const uint offsetsAndSize[52];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ImportOldPresetHandler_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ImportOldPresetHandler_t qt_meta_stringdata_ImportOldPresetHandler = {
    {
QT_MOC_LITERAL(0, 22), // "ImportOldPresetHandler"
QT_MOC_LITERAL(23, 16), // "signalPresetMenu"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 10), // "numPresets"
QT_MOC_LITERAL(52, 21), // "signalAddRemovePreset"
QT_MOC_LITERAL(74, 24), // "signalImportingPresetNum"
QT_MOC_LITERAL(99, 15), // "updatingMessage"
QT_MOC_LITERAL(115, 23), // "signalImportingComplete"
QT_MOC_LITERAL(139, 18), // "signalPathNotFound"
QT_MOC_LITERAL(158, 15), // "signalPathFound"
QT_MOC_LITERAL(174, 19), // "slotImportOldPreset"
QT_MOC_LITERAL(194, 17), // "slotConvertPreset"
QT_MOC_LITERAL(212, 22), // "slotNormalizePresetMap"
QT_MOC_LITERAL(235, 25), // "slotListErrorCompensation"
QT_MOC_LITERAL(261, 10), // "stringList"
QT_MOC_LITERAL(272, 25), // "slotEmptyListCompensation"
QT_MOC_LITERAL(298, 7), // "oldName"
QT_MOC_LITERAL(306, 9), // "valueList"
QT_MOC_LITERAL(316, 20), // "slotGetNewTableValue"
QT_MOC_LITERAL(337, 8), // "oldValue"
QT_MOC_LITERAL(346, 26), // "slotGetOldDestinationParam"
QT_MOC_LITERAL(373, 8), // "newParam"
QT_MOC_LITERAL(382, 6), // "keyNum"
QT_MOC_LITERAL(389, 10), // "modlineNum"
QT_MOC_LITERAL(400, 11), // "slotSetMode"
QT_MOC_LITERAL(412, 1) // "m"

    },
    "ImportOldPresetHandler\0signalPresetMenu\0"
    "\0numPresets\0signalAddRemovePreset\0"
    "signalImportingPresetNum\0updatingMessage\0"
    "signalImportingComplete\0signalPathNotFound\0"
    "signalPathFound\0slotImportOldPreset\0"
    "slotConvertPreset\0slotNormalizePresetMap\0"
    "slotListErrorCompensation\0stringList\0"
    "slotEmptyListCompensation\0oldName\0"
    "valueList\0slotGetNewTableValue\0oldValue\0"
    "slotGetOldDestinationParam\0newParam\0"
    "keyNum\0modlineNum\0slotSetMode\0m"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImportOldPresetHandler[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    0 /* Public */,
       4,    0,  101,    2, 0x06,    2 /* Public */,
       5,    1,  102,    2, 0x06,    3 /* Public */,
       7,    0,  105,    2, 0x06,    5 /* Public */,
       8,    0,  106,    2, 0x06,    6 /* Public */,
       9,    0,  107,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  108,    2, 0x0a,    8 /* Public */,
      11,    0,  109,    2, 0x0a,    9 /* Public */,
      12,    0,  110,    2, 0x0a,   10 /* Public */,
      13,    1,  111,    2, 0x0a,   11 /* Public */,
      15,    2,  114,    2, 0x0a,   13 /* Public */,
      18,    1,  119,    2, 0x0a,   16 /* Public */,
      20,    3,  122,    2, 0x0a,   18 /* Public */,
      24,    1,  129,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QVariantMap,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QVariantList,   14,
    QMetaType::Int, QMetaType::QString, QMetaType::QVariantList,   16,   17,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   21,   22,   23,
    QMetaType::Void, QMetaType::QString,   25,

       0        // eod
};

void ImportOldPresetHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImportOldPresetHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalPresetMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalAddRemovePreset(); break;
        case 2: _t->signalImportingPresetNum((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signalImportingComplete(); break;
        case 4: _t->signalPathNotFound(); break;
        case 5: _t->signalPathFound(); break;
        case 6: _t->slotImportOldPreset(); break;
        case 7: { QVariantMap _r = _t->slotConvertPreset();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->slotNormalizePresetMap(); break;
        case 9: { QString _r = _t->slotListErrorCompensation((*reinterpret_cast< QList<QVariant>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->slotEmptyListCompensation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QVariant>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->slotGetNewTableValue((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->slotGetOldDestinationParam((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImportOldPresetHandler::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImportOldPresetHandler::signalPresetMenu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImportOldPresetHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImportOldPresetHandler::signalAddRemovePreset)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImportOldPresetHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImportOldPresetHandler::signalImportingPresetNum)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ImportOldPresetHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImportOldPresetHandler::signalImportingComplete)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ImportOldPresetHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImportOldPresetHandler::signalPathNotFound)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ImportOldPresetHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImportOldPresetHandler::signalPathFound)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ImportOldPresetHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ImportOldPresetHandler.offsetsAndSize,
    qt_meta_data_ImportOldPresetHandler,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ImportOldPresetHandler_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QVariant>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QVariant>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *ImportOldPresetHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImportOldPresetHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImportOldPresetHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImportOldPresetHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ImportOldPresetHandler::signalPresetMenu(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImportOldPresetHandler::signalAddRemovePreset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ImportOldPresetHandler::signalImportingPresetNum(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImportOldPresetHandler::signalImportingComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ImportOldPresetHandler::signalPathNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ImportOldPresetHandler::signalPathFound()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
