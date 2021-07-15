// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'copypastehandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/copypastehandler.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'copypastehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CopyPasteHandler_t {
    const uint offsetsAndSize[36];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CopyPasteHandler_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CopyPasteHandler_t qt_meta_stringdata_CopyPasteHandler = {
    {
QT_MOC_LITERAL(0, 16), // "CopyPasteHandler"
QT_MOC_LITERAL(17, 29), // "signalUpdatePasteAvailability"
QT_MOC_LITERAL(47, 0), // ""
QT_MOC_LITERAL(48, 21), // "signalAddRemovePreset"
QT_MOC_LITERAL(70, 16), // "signalPresetMenu"
QT_MOC_LITERAL(87, 10), // "numPresets"
QT_MOC_LITERAL(98, 20), // "signalModlineWarning"
QT_MOC_LITERAL(119, 21), // "modlineWarningMessage"
QT_MOC_LITERAL(141, 15), // "slotClearPreset"
QT_MOC_LITERAL(157, 14), // "slotCopyPreset"
QT_MOC_LITERAL(172, 18), // "slotPasteNewPreset"
QT_MOC_LITERAL(191, 15), // "slotPastePreset"
QT_MOC_LITERAL(207, 11), // "slotCopyKey"
QT_MOC_LITERAL(219, 12), // "slotPasteKey"
QT_MOC_LITERAL(232, 17), // "slotSetCurrentKey"
QT_MOC_LITERAL(250, 13), // "currentKeyNum"
QT_MOC_LITERAL(264, 11), // "slotSetMode"
QT_MOC_LITERAL(276, 1) // "m"

    },
    "CopyPasteHandler\0signalUpdatePasteAvailability\0"
    "\0signalAddRemovePreset\0signalPresetMenu\0"
    "numPresets\0signalModlineWarning\0"
    "modlineWarningMessage\0slotClearPreset\0"
    "slotCopyPreset\0slotPasteNewPreset\0"
    "slotPastePreset\0slotCopyKey\0slotPasteKey\0"
    "slotSetCurrentKey\0currentKeyNum\0"
    "slotSetMode\0m"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CopyPasteHandler[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    0 /* Public */,
       3,    0,   87,    2, 0x06,    1 /* Public */,
       4,    1,   88,    2, 0x06,    2 /* Public */,
       6,    1,   91,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   94,    2, 0x0a,    6 /* Public */,
       9,    0,   95,    2, 0x0a,    7 /* Public */,
      10,    0,   96,    2, 0x0a,    8 /* Public */,
      11,    0,   97,    2, 0x0a,    9 /* Public */,
      12,    0,   98,    2, 0x0a,   10 /* Public */,
      13,    0,   99,    2, 0x0a,   11 /* Public */,
      14,    1,  100,    2, 0x0a,   12 /* Public */,
      16,    1,  103,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void CopyPasteHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CopyPasteHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalUpdatePasteAvailability(); break;
        case 1: _t->signalAddRemovePreset(); break;
        case 2: _t->signalPresetMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalModlineWarning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotClearPreset(); break;
        case 5: _t->slotCopyPreset(); break;
        case 6: _t->slotPasteNewPreset(); break;
        case 7: _t->slotPastePreset(); break;
        case 8: _t->slotCopyKey(); break;
        case 9: _t->slotPasteKey(); break;
        case 10: _t->slotSetCurrentKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CopyPasteHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CopyPasteHandler::signalUpdatePasteAvailability)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CopyPasteHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CopyPasteHandler::signalAddRemovePreset)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CopyPasteHandler::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CopyPasteHandler::signalPresetMenu)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CopyPasteHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CopyPasteHandler::signalModlineWarning)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject CopyPasteHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CopyPasteHandler.offsetsAndSize,
    qt_meta_data_CopyPasteHandler,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CopyPasteHandler_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *CopyPasteHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CopyPasteHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CopyPasteHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CopyPasteHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CopyPasteHandler::signalUpdatePasteAvailability()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CopyPasteHandler::signalAddRemovePreset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CopyPasteHandler::signalPresetMenu(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CopyPasteHandler::signalModlineWarning(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
