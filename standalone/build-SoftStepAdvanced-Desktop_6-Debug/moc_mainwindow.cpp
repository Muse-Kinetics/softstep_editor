// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[104];
    char stringdata0[887];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 12), // "signalSaveAs"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 10), // "presetName"
QT_MOC_LITERAL(36, 13), // "signalSetMode"
QT_MOC_LITERAL(50, 4), // "mode"
QT_MOC_LITERAL(55, 16), // "signalStoreValue"
QT_MOC_LITERAL(72, 4), // "name"
QT_MOC_LITERAL(77, 5), // "value"
QT_MOC_LITERAL(83, 9), // "presetNum"
QT_MOC_LITERAL(93, 21), // "signalCheckSavedState"
QT_MOC_LITERAL(115, 24), // "signalSelectedKeyOutline"
QT_MOC_LITERAL(140, 11), // "selectedKey"
QT_MOC_LITERAL(152, 8), // "outlined"
QT_MOC_LITERAL(161, 25), // "signalSetPresetNameInKeys"
QT_MOC_LITERAL(187, 21), // "slotConnectInterfaces"
QT_MOC_LITERAL(209, 19), // "slotConnectElements"
QT_MOC_LITERAL(229, 22), // "slotDisconnectElements"
QT_MOC_LITERAL(252, 15), // "slotInitMenuBar"
QT_MOC_LITERAL(268, 11), // "slotOpenDoc"
QT_MOC_LITERAL(280, 25), // "slotEnableDisableToolTips"
QT_MOC_LITERAL(306, 27), // "slotUpdatePasteAvailability"
QT_MOC_LITERAL(334, 15), // "slotSelectedKey"
QT_MOC_LITERAL(350, 16), // "slotValueChanged"
QT_MOC_LITERAL(367, 16), // "slotRecallPreset"
QT_MOC_LITERAL(384, 13), // "slotConnected"
QT_MOC_LITERAL(398, 10), // "slotSaveAs"
QT_MOC_LITERAL(409, 22), // "slotPopulatePresetMenu"
QT_MOC_LITERAL(432, 17), // "slotSetPresetMenu"
QT_MOC_LITERAL(450, 20), // "slotDisplaySaveState"
QT_MOC_LITERAL(471, 18), // "slotModlineWarning"
QT_MOC_LITERAL(490, 21), // "modlineWarningMessage"
QT_MOC_LITERAL(512, 11), // "slotSetMode"
QT_MOC_LITERAL(524, 27), // "slotPopulateSourceDestLists"
QT_MOC_LITERAL(552, 23), // "slotPopulateDeviceMenus"
QT_MOC_LITERAL(576, 29), // "QMap<QString,MIDIEndpointRef>"
QT_MOC_LITERAL(606, 15), // "externalDevices"
QT_MOC_LITERAL(622, 19), // "slotReceiveVersions"
QT_MOC_LITERAL(642, 9), // "connected"
QT_MOC_LITERAL(652, 16), // "connectedVersion"
QT_MOC_LITERAL(669, 8), // "embedded"
QT_MOC_LITERAL(678, 15), // "embeddedVersion"
QT_MOC_LITERAL(694, 8), // "hardware"
QT_MOC_LITERAL(703, 27), // "slotRecallPresetFromSetlist"
QT_MOC_LITERAL(731, 18), // "slotUpdateFirmware"
QT_MOC_LITERAL(750, 23), // "slotUpdateFwProgressBar"
QT_MOC_LITERAL(774, 29), // "slotLockoutKeyPressedReleased"
QT_MOC_LITERAL(804, 9), // "keyNumber"
QT_MOC_LITERAL(814, 15), // "pressedReleased"
QT_MOC_LITERAL(830, 17), // "slotUpdatePresets"
QT_MOC_LITERAL(848, 20), // "slotDisconnectUpdate"
QT_MOC_LITERAL(869, 17) // "slotConnectUpdate"

    },
    "MainWindow\0signalSaveAs\0\0presetName\0"
    "signalSetMode\0mode\0signalStoreValue\0"
    "name\0value\0presetNum\0signalCheckSavedState\0"
    "signalSelectedKeyOutline\0selectedKey\0"
    "outlined\0signalSetPresetNameInKeys\0"
    "slotConnectInterfaces\0slotConnectElements\0"
    "slotDisconnectElements\0slotInitMenuBar\0"
    "slotOpenDoc\0slotEnableDisableToolTips\0"
    "slotUpdatePasteAvailability\0slotSelectedKey\0"
    "slotValueChanged\0slotRecallPreset\0"
    "slotConnected\0slotSaveAs\0"
    "slotPopulatePresetMenu\0slotSetPresetMenu\0"
    "slotDisplaySaveState\0slotModlineWarning\0"
    "modlineWarningMessage\0slotSetMode\0"
    "slotPopulateSourceDestLists\0"
    "slotPopulateDeviceMenus\0"
    "QMap<QString,MIDIEndpointRef>\0"
    "externalDevices\0slotReceiveVersions\0"
    "connected\0connectedVersion\0embedded\0"
    "embeddedVersion\0hardware\0"
    "slotRecallPresetFromSetlist\0"
    "slotUpdateFirmware\0slotUpdateFwProgressBar\0"
    "slotLockoutKeyPressedReleased\0keyNumber\0"
    "pressedReleased\0slotUpdatePresets\0"
    "slotDisconnectUpdate\0slotConnectUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x06,    0 /* Public */,
       4,    1,  215,    2, 0x06,    2 /* Public */,
       6,    3,  218,    2, 0x06,    4 /* Public */,
      10,    0,  225,    2, 0x06,    8 /* Public */,
      11,    2,  226,    2, 0x06,    9 /* Public */,
      14,    1,  231,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  234,    2, 0x0a,   14 /* Public */,
      16,    0,  235,    2, 0x0a,   15 /* Public */,
      17,    0,  236,    2, 0x0a,   16 /* Public */,
      18,    0,  237,    2, 0x0a,   17 /* Public */,
      19,    0,  238,    2, 0x0a,   18 /* Public */,
      20,    0,  239,    2, 0x0a,   19 /* Public */,
      21,    0,  240,    2, 0x0a,   20 /* Public */,
      22,    1,  241,    2, 0x0a,   21 /* Public */,
      23,    0,  244,    2, 0x0a,   23 /* Public */,
      24,    2,  245,    2, 0x0a,   24 /* Public */,
      25,    1,  250,    2, 0x0a,   27 /* Public */,
      26,    0,  253,    2, 0x0a,   29 /* Public */,
      27,    0,  254,    2, 0x0a,   30 /* Public */,
      28,    1,  255,    2, 0x0a,   31 /* Public */,
      29,    1,  258,    2, 0x0a,   33 /* Public */,
      30,    1,  261,    2, 0x0a,   35 /* Public */,
      32,    0,  264,    2, 0x0a,   37 /* Public */,
      33,    0,  265,    2, 0x0a,   38 /* Public */,
      34,    1,  266,    2, 0x0a,   39 /* Public */,
      37,    5,  269,    2, 0x0a,   41 /* Public */,
      43,    1,  280,    2, 0x0a,   47 /* Public */,
      44,    0,  283,    2, 0x0a,   49 /* Public */,
      45,    1,  284,    2, 0x0a,   50 /* Public */,
      46,    2,  287,    2, 0x0a,   52 /* Public */,
      49,    0,  292,    2, 0x0a,   55 /* Public */,
      50,    0,  293,    2, 0x0a,   56 /* Public */,
      51,    0,  294,    2, 0x0a,   57 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,   38,   39,   40,   41,   42,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   47,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSaveAs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->signalCheckSavedState(); break;
        case 4: _t->signalSelectedKeyOutline((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->signalSetPresetNameInKeys((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotConnectInterfaces(); break;
        case 7: _t->slotConnectElements(); break;
        case 8: _t->slotDisconnectElements(); break;
        case 9: _t->slotInitMenuBar(); break;
        case 10: _t->slotOpenDoc(); break;
        case 11: _t->slotEnableDisableToolTips(); break;
        case 12: _t->slotUpdatePasteAvailability(); break;
        case 13: _t->slotSelectedKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->slotValueChanged(); break;
        case 15: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 16: _t->slotConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->slotSaveAs(); break;
        case 18: _t->slotPopulatePresetMenu(); break;
        case 19: _t->slotSetPresetMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->slotDisplaySaveState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->slotModlineWarning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->slotSetMode(); break;
        case 23: _t->slotPopulateSourceDestLists(); break;
        case 24: _t->slotPopulateDeviceMenus((*reinterpret_cast< QMap<QString,MIDIEndpointRef>(*)>(_a[1]))); break;
        case 25: _t->slotReceiveVersions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 26: _t->slotRecallPresetFromSetlist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->slotUpdateFirmware(); break;
        case 28: _t->slotUpdateFwProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->slotLockoutKeyPressedReleased((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->slotUpdatePresets(); break;
        case 31: _t->slotDisconnectUpdate(); break;
        case 32: _t->slotConnectUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSaveAs)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSetMode)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QVariant , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalStoreValue)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalCheckSavedState)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSelectedKeyOutline)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSetPresetNameInKeys)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<QString,MIDIEndpointRef>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalSaveAs(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalSetMode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signalStoreValue(QString _t1, QVariant _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalCheckSavedState()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::signalSelectedKeyOutline(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signalSetPresetNameInKeys(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
