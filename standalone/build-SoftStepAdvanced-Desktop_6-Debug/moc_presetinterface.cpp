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
#include "../advanced/presetinterface.h"
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
    const uint offsetsAndSize[88];
    char stringdata0[739];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PresetInterface_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PresetInterface_t qt_meta_stringdata_PresetInterface = {
    {
QT_MOC_LITERAL(0, 15), // "PresetInterface"
QT_MOC_LITERAL(16, 18), // "signalRecallPreset"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 6), // "preset"
QT_MOC_LITERAL(43, 17), // "jsonMasterMapCopy"
QT_MOC_LITERAL(61, 26), // "signalPopulateSetlistMenus"
QT_MOC_LITERAL(88, 10), // "QComboBox*"
QT_MOC_LITERAL(99, 10), // "presetMenu"
QT_MOC_LITERAL(110, 21), // "signalAddRemovePreset"
QT_MOC_LITERAL(132, 17), // "signalPresetDirty"
QT_MOC_LITERAL(150, 16), // "signalPresetMenu"
QT_MOC_LITERAL(167, 13), // "goToPresetNum"
QT_MOC_LITERAL(181, 20), // "signalDisableModline"
QT_MOC_LITERAL(202, 13), // "parameterName"
QT_MOC_LITERAL(216, 20), // "signalModlineWarning"
QT_MOC_LITERAL(237, 21), // "modlineWarningMessage"
QT_MOC_LITERAL(259, 14), // "slotStoreValue"
QT_MOC_LITERAL(274, 4), // "name"
QT_MOC_LITERAL(279, 5), // "value"
QT_MOC_LITERAL(285, 9), // "presetNum"
QT_MOC_LITERAL(295, 18), // "slotCheckSaveState"
QT_MOC_LITERAL(314, 18), // "slotModlineWarning"
QT_MOC_LITERAL(333, 18), // "slotUpdateJSONPath"
QT_MOC_LITERAL(352, 12), // "slotReadJSON"
QT_MOC_LITERAL(365, 13), // "slotWriteJSON"
QT_MOC_LITERAL(379, 7), // "jsonMap"
QT_MOC_LITERAL(387, 33), // "slotConstructDefaultStandalon..."
QT_MOC_LITERAL(421, 29), // "slotConstructDefaultHostedMap"
QT_MOC_LITERAL(451, 16), // "slotRecallPreset"
QT_MOC_LITERAL(468, 1), // "i"
QT_MOC_LITERAL(470, 14), // "slotSavePreset"
QT_MOC_LITERAL(485, 16), // "slotSavePresetAs"
QT_MOC_LITERAL(502, 10), // "presetName"
QT_MOC_LITERAL(513, 16), // "slotDeletePreset"
QT_MOC_LITERAL(530, 23), // "slotPopulatePresetLists"
QT_MOC_LITERAL(554, 16), // "slotRevertPreset"
QT_MOC_LITERAL(571, 16), // "slotImportPreset"
QT_MOC_LITERAL(588, 16), // "slotExportPreset"
QT_MOC_LITERAL(605, 22), // "slotPopulatePresetMenu"
QT_MOC_LITERAL(628, 24), // "slotPopulateSetlistMenus"
QT_MOC_LITERAL(653, 26), // "slotGetPresetStringFromInt"
QT_MOC_LITERAL(680, 22), // "slotOrderPresetsInJson"
QT_MOC_LITERAL(703, 23), // "slotGetNumPresetsInJson"
QT_MOC_LITERAL(727, 11) // "slotSetMode"

    },
    "PresetInterface\0signalRecallPreset\0\0"
    "preset\0jsonMasterMapCopy\0"
    "signalPopulateSetlistMenus\0QComboBox*\0"
    "presetMenu\0signalAddRemovePreset\0"
    "signalPresetDirty\0signalPresetMenu\0"
    "goToPresetNum\0signalDisableModline\0"
    "parameterName\0signalModlineWarning\0"
    "modlineWarningMessage\0slotStoreValue\0"
    "name\0value\0presetNum\0slotCheckSaveState\0"
    "slotModlineWarning\0slotUpdateJSONPath\0"
    "slotReadJSON\0slotWriteJSON\0jsonMap\0"
    "slotConstructDefaultStandaloneMap\0"
    "slotConstructDefaultHostedMap\0"
    "slotRecallPreset\0i\0slotSavePreset\0"
    "slotSavePresetAs\0presetName\0"
    "slotDeletePreset\0slotPopulatePresetLists\0"
    "slotRevertPreset\0slotImportPreset\0"
    "slotExportPreset\0slotPopulatePresetMenu\0"
    "slotPopulateSetlistMenus\0"
    "slotGetPresetStringFromInt\0"
    "slotOrderPresetsInJson\0slotGetNumPresetsInJson\0"
    "slotSetMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PresetInterface[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  188,    2, 0x06,    0 /* Public */,
       5,    1,  193,    2, 0x06,    3 /* Public */,
       8,    0,  196,    2, 0x06,    5 /* Public */,
       9,    1,  197,    2, 0x06,    6 /* Public */,
      10,    1,  200,    2, 0x06,    8 /* Public */,
      12,    1,  203,    2, 0x06,   10 /* Public */,
      14,    1,  206,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    3,  209,    2, 0x0a,   14 /* Public */,
      20,    0,  216,    2, 0x0a,   18 /* Public */,
      21,    1,  217,    2, 0x0a,   19 /* Public */,
      22,    0,  220,    2, 0x0a,   21 /* Public */,
      23,    0,  221,    2, 0x0a,   22 /* Public */,
      24,    1,  222,    2, 0x0a,   23 /* Public */,
      26,    0,  225,    2, 0x0a,   25 /* Public */,
      27,    0,  226,    2, 0x0a,   26 /* Public */,
      28,    1,  227,    2, 0x0a,   27 /* Public */,
      30,    0,  230,    2, 0x0a,   29 /* Public */,
      31,    1,  231,    2, 0x0a,   30 /* Public */,
      33,    0,  234,    2, 0x0a,   32 /* Public */,
      34,    0,  235,    2, 0x0a,   33 /* Public */,
      35,    0,  236,    2, 0x0a,   34 /* Public */,
      36,    0,  237,    2, 0x0a,   35 /* Public */,
      37,    0,  238,    2, 0x0a,   36 /* Public */,
      38,    1,  239,    2, 0x0a,   37 /* Public */,
      39,    0,  242,    2, 0x0a,   39 /* Public */,
      40,    1,  243,    2, 0x0a,   40 /* Public */,
      41,    0,  246,    2, 0x0a,   42 /* Public */,
      42,    0,  247,    2, 0x0a,   43 /* Public */,
      43,    1,  248,    2, 0x0a,   44 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void PresetInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PresetInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 1: _t->signalPopulateSetlistMenus((*reinterpret_cast< QComboBox*(*)>(_a[1]))); break;
        case 2: _t->signalAddRemovePreset(); break;
        case 3: _t->signalPresetDirty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->signalPresetMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalDisableModline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->signalModlineWarning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slotCheckSaveState(); break;
        case 9: _t->slotModlineWarning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slotUpdateJSONPath(); break;
        case 11: _t->slotReadJSON(); break;
        case 12: _t->slotWriteJSON((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 13: _t->slotConstructDefaultStandaloneMap(); break;
        case 14: _t->slotConstructDefaultHostedMap(); break;
        case 15: _t->slotRecallPreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slotSavePreset(); break;
        case 17: _t->slotSavePresetAs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->slotDeletePreset(); break;
        case 19: _t->slotPopulatePresetLists(); break;
        case 20: _t->slotRevertPreset(); break;
        case 21: _t->slotImportPreset(); break;
        case 22: _t->slotExportPreset(); break;
        case 23: _t->slotPopulatePresetMenu((*reinterpret_cast< QComboBox*(*)>(_a[1]))); break;
        case 24: _t->slotPopulateSetlistMenus(); break;
        case 25: { QString _r = _t->slotGetPresetStringFromInt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->slotOrderPresetsInJson(); break;
        case 27: { int _r = _t->slotGetNumPresetsInJson();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QComboBox* >(); break;
            }
            break;
        case 23:
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
            using _t = void (PresetInterface::*)(QVariantMap , QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalRecallPreset)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)(QComboBox * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalPopulateSetlistMenus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalAddRemovePreset)) {
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
            using _t = void (PresetInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalPresetMenu)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalDisableModline)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PresetInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresetInterface::signalModlineWarning)) {
                *result = 6;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QComboBox *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QComboBox *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


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
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
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
void PresetInterface::signalPopulateSetlistMenus(QComboBox * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PresetInterface::signalAddRemovePreset()
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
void PresetInterface::signalPresetMenu(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PresetInterface::signalDisableModline(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PresetInterface::signalModlineWarning(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
