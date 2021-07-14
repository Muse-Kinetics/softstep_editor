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
#include "../ezpz/mainwindow.h"
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
    const uint offsetsAndSize[48];
    char stringdata0[413];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 18), // "signalStandaloneOn"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 21), // "slotConnectInterfaces"
QT_MOC_LITERAL(53, 16), // "slotRecallPreset"
QT_MOC_LITERAL(70, 6), // "preset"
QT_MOC_LITERAL(77, 6), // "master"
QT_MOC_LITERAL(84, 19), // "slotReceiveVersions"
QT_MOC_LITERAL(104, 9), // "connected"
QT_MOC_LITERAL(114, 16), // "connectedVersion"
QT_MOC_LITERAL(131, 8), // "embedded"
QT_MOC_LITERAL(140, 15), // "embeddedVersion"
QT_MOC_LITERAL(156, 13), // "slotConnected"
QT_MOC_LITERAL(170, 18), // "slotUpdateFirmware"
QT_MOC_LITERAL(189, 23), // "slotUpdateFwProgressBar"
QT_MOC_LITERAL(213, 15), // "slotInitMenuBar"
QT_MOC_LITERAL(229, 27), // "slotUpdatePasteAvailability"
QT_MOC_LITERAL(257, 21), // "slotOpenDocumentation"
QT_MOC_LITERAL(279, 20), // "slotDisconnectUpdate"
QT_MOC_LITERAL(300, 17), // "slotConnectUpdate"
QT_MOC_LITERAL(318, 20), // "slotDisplaySaveState"
QT_MOC_LITERAL(339, 32), // "slotEnableDisableUseCustomPreset"
QT_MOC_LITERAL(372, 21), // "slotEnableDisableMenu"
QT_MOC_LITERAL(394, 18) // "slotDisplayFactory"

    },
    "MainWindow\0signalStandaloneOn\0\0"
    "slotConnectInterfaces\0slotRecallPreset\0"
    "preset\0master\0slotReceiveVersions\0"
    "connected\0connectedVersion\0embedded\0"
    "embeddedVersion\0slotConnected\0"
    "slotUpdateFirmware\0slotUpdateFwProgressBar\0"
    "slotInitMenuBar\0slotUpdatePasteAvailability\0"
    "slotOpenDocumentation\0slotDisconnectUpdate\0"
    "slotConnectUpdate\0slotDisplaySaveState\0"
    "slotEnableDisableUseCustomPreset\0"
    "slotEnableDisableMenu\0slotDisplayFactory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  111,    2, 0x0a,    1 /* Public */,
       4,    2,  112,    2, 0x0a,    2 /* Public */,
       7,    4,  117,    2, 0x0a,    5 /* Public */,
      12,    1,  126,    2, 0x0a,   10 /* Public */,
      13,    0,  129,    2, 0x0a,   12 /* Public */,
      14,    1,  130,    2, 0x0a,   13 /* Public */,
      15,    0,  133,    2, 0x0a,   15 /* Public */,
      16,    0,  134,    2, 0x0a,   16 /* Public */,
      17,    0,  135,    2, 0x0a,   17 /* Public */,
      18,    0,  136,    2, 0x0a,   18 /* Public */,
      19,    0,  137,    2, 0x0a,   19 /* Public */,
      20,    1,  138,    2, 0x0a,   20 /* Public */,
      21,    1,  141,    2, 0x0a,   22 /* Public */,
      22,    0,  144,    2, 0x0a,   24 /* Public */,
      23,    0,  145,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
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
        case 0: _t->signalStandaloneOn(); break;
        case 1: _t->slotConnectInterfaces(); break;
        case 2: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 3: _t->slotReceiveVersions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->slotConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotUpdateFirmware(); break;
        case 6: _t->slotUpdateFwProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotInitMenuBar(); break;
        case 8: _t->slotUpdatePasteAvailability(); break;
        case 9: _t->slotOpenDocumentation(); break;
        case 10: _t->slotDisconnectUpdate(); break;
        case 11: _t->slotConnectUpdate(); break;
        case 12: _t->slotDisplaySaveState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->slotEnableDisableUseCustomPreset((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->slotEnableDisableMenu(); break;
        case 15: _t->slotDisplayFactory(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalStandaloneOn)) {
                *result = 0;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalStandaloneOn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
