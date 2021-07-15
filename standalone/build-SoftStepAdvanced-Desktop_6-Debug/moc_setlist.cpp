// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'setlist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/setlist.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Setlist_t {
    const uint offsetsAndSize[42];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Setlist_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Setlist_t qt_meta_stringdata_Setlist = {
    {
QT_MOC_LITERAL(0, 7), // "Setlist"
QT_MOC_LITERAL(8, 29), // "signalRecallPresetFromSetlist"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 10), // "presetName"
QT_MOC_LITERAL(50, 15), // "slotMenuChanged"
QT_MOC_LITERAL(66, 7), // "menuNum"
QT_MOC_LITERAL(74, 19), // "slotCheckBoxClicked"
QT_MOC_LITERAL(94, 18), // "slotInitComponents"
QT_MOC_LITERAL(113, 15), // "slotShowSetlist"
QT_MOC_LITERAL(129, 24), // "slotPopulateSetlistMenus"
QT_MOC_LITERAL(154, 10), // "QComboBox*"
QT_MOC_LITERAL(165, 10), // "presetMenu"
QT_MOC_LITERAL(176, 18), // "slotCompileSetlist"
QT_MOC_LITERAL(195, 23), // "slotRefreshSetlistMenus"
QT_MOC_LITERAL(219, 11), // "slotSetMode"
QT_MOC_LITERAL(231, 1), // "m"
QT_MOC_LITERAL(233, 18), // "slotUpdateJSONPath"
QT_MOC_LITERAL(252, 15), // "slotReadSetlist"
QT_MOC_LITERAL(268, 16), // "slotWriteSetlist"
QT_MOC_LITERAL(285, 16), // "slotChangePreset"
QT_MOC_LITERAL(302, 10) // "prevOrNext"

    },
    "Setlist\0signalRecallPresetFromSetlist\0"
    "\0presetName\0slotMenuChanged\0menuNum\0"
    "slotCheckBoxClicked\0slotInitComponents\0"
    "slotShowSetlist\0slotPopulateSetlistMenus\0"
    "QComboBox*\0presetMenu\0slotCompileSetlist\0"
    "slotRefreshSetlistMenus\0slotSetMode\0"
    "m\0slotUpdateJSONPath\0slotReadSetlist\0"
    "slotWriteSetlist\0slotChangePreset\0"
    "prevOrNext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setlist[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   95,    2, 0x0a,    2 /* Public */,
       6,    0,   98,    2, 0x0a,    4 /* Public */,
       7,    0,   99,    2, 0x0a,    5 /* Public */,
       8,    0,  100,    2, 0x0a,    6 /* Public */,
       9,    1,  101,    2, 0x0a,    7 /* Public */,
      12,    0,  104,    2, 0x0a,    9 /* Public */,
      13,    1,  105,    2, 0x0a,   10 /* Public */,
      14,    1,  108,    2, 0x0a,   12 /* Public */,
      16,    0,  111,    2, 0x0a,   14 /* Public */,
      17,    0,  112,    2, 0x0a,   15 /* Public */,
      18,    0,  113,    2, 0x0a,   16 /* Public */,
      19,    1,  114,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,

       0        // eod
};

void Setlist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Setlist *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalRecallPresetFromSetlist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotMenuChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotCheckBoxClicked(); break;
        case 3: _t->slotInitComponents(); break;
        case 4: _t->slotShowSetlist(); break;
        case 5: _t->slotPopulateSetlistMenus((*reinterpret_cast< QComboBox*(*)>(_a[1]))); break;
        case 6: _t->slotCompileSetlist(); break;
        case 7: _t->slotRefreshSetlistMenus((*reinterpret_cast< QComboBox*(*)>(_a[1]))); break;
        case 8: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slotUpdateJSONPath(); break;
        case 10: _t->slotReadSetlist(); break;
        case 11: _t->slotWriteSetlist(); break;
        case 12: _t->slotChangePreset((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QComboBox* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QComboBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Setlist::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setlist::signalRecallPresetFromSetlist)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Setlist::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Setlist.offsetsAndSize,
    qt_meta_data_Setlist,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Setlist_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QComboBox *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QComboBox *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Setlist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setlist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Setlist.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Setlist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Setlist::signalRecallPresetFromSetlist(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
