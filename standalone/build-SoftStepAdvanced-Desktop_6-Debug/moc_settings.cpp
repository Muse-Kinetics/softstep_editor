// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/settings.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    const uint offsetsAndSize[184];
    char stringdata0[1606];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 8), // "Settings"
QT_MOC_LITERAL(9, 16), // "signalStoreValue"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 4), // "name"
QT_MOC_LITERAL(32, 5), // "value"
QT_MOC_LITERAL(38, 20), // "signalRecallSettings"
QT_MOC_LITERAL(59, 6), // "preset"
QT_MOC_LITERAL(66, 8), // "settings"
QT_MOC_LITERAL(75, 19), // "signalSetGlobalGain"
QT_MOC_LITERAL(95, 4), // "gain"
QT_MOC_LITERAL(100, 23), // "signalSetSensorResponse"
QT_MOC_LITERAL(124, 8), // "response"
QT_MOC_LITERAL(133, 22), // "signalSetKeySafetyMode"
QT_MOC_LITERAL(156, 4), // "mode"
QT_MOC_LITERAL(161, 20), // "signalSetDisplayMode"
QT_MOC_LITERAL(182, 22), // "signalSetSceneChanging"
QT_MOC_LITERAL(205, 5), // "onOff"
QT_MOC_LITERAL(211, 18), // "signalSetBacklight"
QT_MOC_LITERAL(230, 20), // "signalSetKeyOnThresh"
QT_MOC_LITERAL(251, 3), // "key"
QT_MOC_LITERAL(255, 8), // "onThresh"
QT_MOC_LITERAL(264, 21), // "signalSetKeyOffThresh"
QT_MOC_LITERAL(286, 9), // "offThresh"
QT_MOC_LITERAL(296, 21), // "signalSetKeyYDeadZone"
QT_MOC_LITERAL(318, 8), // "deadZone"
QT_MOC_LITERAL(327, 21), // "signalSetKeyXDeadZone"
QT_MOC_LITERAL(349, 18), // "signalSetKeyYAccel"
QT_MOC_LITERAL(368, 5), // "accel"
QT_MOC_LITERAL(374, 18), // "signalSetKeyXAccel"
QT_MOC_LITERAL(393, 25), // "signalSetNavNorthOnThresh"
QT_MOC_LITERAL(419, 9), // "threshold"
QT_MOC_LITERAL(429, 26), // "signalSetNavNorthOffThresh"
QT_MOC_LITERAL(456, 25), // "signalSetNavSouthOnThresh"
QT_MOC_LITERAL(482, 26), // "signalSetNavSouthOffThresh"
QT_MOC_LITERAL(509, 24), // "signalSetNavEastOnThresh"
QT_MOC_LITERAL(534, 25), // "signalSetNavEastOffThresh"
QT_MOC_LITERAL(560, 24), // "signalSetNavWestOnThresh"
QT_MOC_LITERAL(585, 25), // "signalSetNavWestOffThresh"
QT_MOC_LITERAL(611, 21), // "signalSetNavYIncAccel"
QT_MOC_LITERAL(633, 22), // "signalStartCalibration"
QT_MOC_LITERAL(656, 22), // "signalResetCalibration"
QT_MOC_LITERAL(679, 21), // "signalStopCalibration"
QT_MOC_LITERAL(701, 24), // "signalSetTestValueSlider"
QT_MOC_LITERAL(726, 8), // "QSlider*"
QT_MOC_LITERAL(735, 6), // "slider"
QT_MOC_LITERAL(742, 20), // "signalInitPedalTable"
QT_MOC_LITERAL(763, 29), // "signalTetherOnOffInStandalone"
QT_MOC_LITERAL(793, 18), // "signalSetOscEnable"
QT_MOC_LITERAL(812, 8), // "inputNum"
QT_MOC_LITERAL(821, 7), // "enabled"
QT_MOC_LITERAL(829, 19), // "signalSetOscAddress"
QT_MOC_LITERAL(849, 4), // "addr"
QT_MOC_LITERAL(854, 14), // "signalSetOscIP"
QT_MOC_LITERAL(869, 8), // "ipString"
QT_MOC_LITERAL(878, 19), // "signalSetOscOutPort"
QT_MOC_LITERAL(898, 7), // "outPort"
QT_MOC_LITERAL(906, 18), // "signalSetOscInPort"
QT_MOC_LITERAL(925, 6), // "inPort"
QT_MOC_LITERAL(932, 11), // "slotSetMode"
QT_MOC_LITERAL(944, 1), // "m"
QT_MOC_LITERAL(946, 16), // "slotOpenSettings"
QT_MOC_LITERAL(963, 19), // "slotConnectElements"
QT_MOC_LITERAL(983, 22), // "slotDisconnectElements"
QT_MOC_LITERAL(1006, 16), // "slotValueChanged"
QT_MOC_LITERAL(1023, 16), // "slotRecallPreset"
QT_MOC_LITERAL(1040, 18), // "slotRecallSettings"
QT_MOC_LITERAL(1059, 16), // "slotViewSelector"
QT_MOC_LITERAL(1076, 19), // "slotResetGlobalGain"
QT_MOC_LITERAL(1096, 22), // "slotPopulateInputMenus"
QT_MOC_LITERAL(1119, 29), // "QMap<QString,MIDIEndpointRef>"
QT_MOC_LITERAL(1149, 11), // "midiSources"
QT_MOC_LITERAL(1161, 26), // "slotSetMidiInputLineParams"
QT_MOC_LITERAL(1188, 15), // "slotSetJSONPath"
QT_MOC_LITERAL(1204, 16), // "slotReadSettings"
QT_MOC_LITERAL(1221, 17), // "slotWriteSettings"
QT_MOC_LITERAL(1239, 24), // "slotWriteDefaultSettings"
QT_MOC_LITERAL(1264, 17), // "slotStoreSettings"
QT_MOC_LITERAL(1282, 31), // "slotConstructSettingsDefaultMap"
QT_MOC_LITERAL(1314, 19), // "slotEmitAllSettings"
QT_MOC_LITERAL(1334, 23), // "slotSaveSettingsTimeout"
QT_MOC_LITERAL(1358, 20), // "slotStartCalibration"
QT_MOC_LITERAL(1379, 19), // "slotStopCalibration"
QT_MOC_LITERAL(1399, 20), // "slotResetCalibration"
QT_MOC_LITERAL(1420, 22), // "slotLoadTableOnStartup"
QT_MOC_LITERAL(1443, 25), // "slotWritePedalTableToDisk"
QT_MOC_LITERAL(1469, 14), // "tableByteArray"
QT_MOC_LITERAL(1484, 16), // "slotSetLiveValue"
QT_MOC_LITERAL(1501, 3), // "val"
QT_MOC_LITERAL(1505, 16), // "slotHideComplete"
QT_MOC_LITERAL(1522, 30), // "slotStartCalibrationStandAlone"
QT_MOC_LITERAL(1553, 29), // "slotStopCalibrationStandAlone"
QT_MOC_LITERAL(1583, 22) // "slotSetOSCDisplayValue"

    },
    "Settings\0signalStoreValue\0\0name\0value\0"
    "signalRecallSettings\0preset\0settings\0"
    "signalSetGlobalGain\0gain\0"
    "signalSetSensorResponse\0response\0"
    "signalSetKeySafetyMode\0mode\0"
    "signalSetDisplayMode\0signalSetSceneChanging\0"
    "onOff\0signalSetBacklight\0signalSetKeyOnThresh\0"
    "key\0onThresh\0signalSetKeyOffThresh\0"
    "offThresh\0signalSetKeyYDeadZone\0"
    "deadZone\0signalSetKeyXDeadZone\0"
    "signalSetKeyYAccel\0accel\0signalSetKeyXAccel\0"
    "signalSetNavNorthOnThresh\0threshold\0"
    "signalSetNavNorthOffThresh\0"
    "signalSetNavSouthOnThresh\0"
    "signalSetNavSouthOffThresh\0"
    "signalSetNavEastOnThresh\0"
    "signalSetNavEastOffThresh\0"
    "signalSetNavWestOnThresh\0"
    "signalSetNavWestOffThresh\0"
    "signalSetNavYIncAccel\0signalStartCalibration\0"
    "signalResetCalibration\0signalStopCalibration\0"
    "signalSetTestValueSlider\0QSlider*\0"
    "slider\0signalInitPedalTable\0"
    "signalTetherOnOffInStandalone\0"
    "signalSetOscEnable\0inputNum\0enabled\0"
    "signalSetOscAddress\0addr\0signalSetOscIP\0"
    "ipString\0signalSetOscOutPort\0outPort\0"
    "signalSetOscInPort\0inPort\0slotSetMode\0"
    "m\0slotOpenSettings\0slotConnectElements\0"
    "slotDisconnectElements\0slotValueChanged\0"
    "slotRecallPreset\0slotRecallSettings\0"
    "slotViewSelector\0slotResetGlobalGain\0"
    "slotPopulateInputMenus\0"
    "QMap<QString,MIDIEndpointRef>\0midiSources\0"
    "slotSetMidiInputLineParams\0slotSetJSONPath\0"
    "slotReadSettings\0slotWriteSettings\0"
    "slotWriteDefaultSettings\0slotStoreSettings\0"
    "slotConstructSettingsDefaultMap\0"
    "slotEmitAllSettings\0slotSaveSettingsTimeout\0"
    "slotStartCalibration\0slotStopCalibration\0"
    "slotResetCalibration\0slotLoadTableOnStartup\0"
    "slotWritePedalTableToDisk\0tableByteArray\0"
    "slotSetLiveValue\0val\0slotHideComplete\0"
    "slotStartCalibrationStandAlone\0"
    "slotStopCalibrationStandAlone\0"
    "slotSetOSCDisplayValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      34,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  392,    2, 0x06,    0 /* Public */,
       5,    2,  397,    2, 0x06,    3 /* Public */,
       8,    1,  402,    2, 0x06,    6 /* Public */,
      10,    1,  405,    2, 0x06,    8 /* Public */,
      12,    1,  408,    2, 0x06,   10 /* Public */,
      14,    1,  411,    2, 0x06,   12 /* Public */,
      15,    1,  414,    2, 0x06,   14 /* Public */,
      17,    1,  417,    2, 0x06,   16 /* Public */,
      18,    2,  420,    2, 0x06,   18 /* Public */,
      21,    2,  425,    2, 0x06,   21 /* Public */,
      23,    2,  430,    2, 0x06,   24 /* Public */,
      25,    2,  435,    2, 0x06,   27 /* Public */,
      26,    2,  440,    2, 0x06,   30 /* Public */,
      28,    2,  445,    2, 0x06,   33 /* Public */,
      29,    1,  450,    2, 0x06,   36 /* Public */,
      31,    1,  453,    2, 0x06,   38 /* Public */,
      32,    1,  456,    2, 0x06,   40 /* Public */,
      33,    1,  459,    2, 0x06,   42 /* Public */,
      34,    1,  462,    2, 0x06,   44 /* Public */,
      35,    1,  465,    2, 0x06,   46 /* Public */,
      36,    1,  468,    2, 0x06,   48 /* Public */,
      37,    1,  471,    2, 0x06,   50 /* Public */,
      38,    1,  474,    2, 0x06,   52 /* Public */,
      39,    0,  477,    2, 0x06,   54 /* Public */,
      40,    0,  478,    2, 0x06,   55 /* Public */,
      41,    0,  479,    2, 0x06,   56 /* Public */,
      42,    1,  480,    2, 0x06,   57 /* Public */,
      45,    1,  483,    2, 0x06,   59 /* Public */,
      46,    1,  486,    2, 0x06,   61 /* Public */,
      47,    2,  489,    2, 0x06,   63 /* Public */,
      50,    2,  494,    2, 0x06,   66 /* Public */,
      52,    1,  499,    2, 0x06,   69 /* Public */,
      54,    1,  502,    2, 0x06,   71 /* Public */,
      56,    1,  505,    2, 0x06,   73 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      58,    1,  508,    2, 0x0a,   75 /* Public */,
      60,    0,  511,    2, 0x0a,   77 /* Public */,
      61,    0,  512,    2, 0x0a,   78 /* Public */,
      62,    0,  513,    2, 0x0a,   79 /* Public */,
      63,    0,  514,    2, 0x0a,   80 /* Public */,
      64,    2,  515,    2, 0x0a,   81 /* Public */,
      65,    0,  520,    2, 0x0a,   84 /* Public */,
      66,    0,  521,    2, 0x0a,   85 /* Public */,
      67,    0,  522,    2, 0x0a,   86 /* Public */,
      68,    1,  523,    2, 0x0a,   87 /* Public */,
      71,    0,  526,    2, 0x0a,   89 /* Public */,
      72,    0,  527,    2, 0x0a,   90 /* Public */,
      73,    0,  528,    2, 0x0a,   91 /* Public */,
      74,    0,  529,    2, 0x0a,   92 /* Public */,
      75,    0,  530,    2, 0x0a,   93 /* Public */,
      76,    2,  531,    2, 0x0a,   94 /* Public */,
      77,    0,  536,    2, 0x0a,   97 /* Public */,
      78,    0,  537,    2, 0x0a,   98 /* Public */,
      79,    0,  538,    2, 0x0a,   99 /* Public */,
      80,    0,  539,    2, 0x0a,  100 /* Public */,
      81,    0,  540,    2, 0x0a,  101 /* Public */,
      82,    0,  541,    2, 0x0a,  102 /* Public */,
      83,    0,  542,    2, 0x0a,  103 /* Public */,
      84,    1,  543,    2, 0x0a,  104 /* Public */,
      86,    1,  546,    2, 0x0a,  106 /* Public */,
      88,    0,  549,    2, 0x0a,  108 /* Public */,
      89,    0,  550,    2, 0x0a,  109 /* Public */,
      90,    0,  551,    2, 0x0a,  110 /* Public */,
      91,    2,  552,    2, 0x0a,  111 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    6,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   27,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 43,   44,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   48,   49,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   48,   51,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void, QMetaType::Int,   55,
    QMetaType::Void, QMetaType::Int,   57,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 69,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   85,
    QMetaType::Void, QMetaType::Int,   87,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   48,   87,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: _t->signalRecallSettings((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 2: _t->signalSetGlobalGain((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->signalSetSensorResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signalSetKeySafetyMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalSetDisplayMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signalSetSceneChanging((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->signalSetBacklight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->signalSetKeyOnThresh((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->signalSetKeyOffThresh((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->signalSetKeyYDeadZone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->signalSetKeyXDeadZone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->signalSetKeyYAccel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->signalSetKeyXAccel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->signalSetNavNorthOnThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->signalSetNavNorthOffThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->signalSetNavSouthOnThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->signalSetNavSouthOffThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->signalSetNavEastOnThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->signalSetNavEastOffThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->signalSetNavWestOnThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->signalSetNavWestOffThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->signalSetNavYIncAccel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->signalStartCalibration(); break;
        case 24: _t->signalResetCalibration(); break;
        case 25: _t->signalStopCalibration(); break;
        case 26: _t->signalSetTestValueSlider((*reinterpret_cast< QSlider*(*)>(_a[1]))); break;
        case 27: _t->signalInitPedalTable((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 28: _t->signalTetherOnOffInStandalone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->signalSetOscEnable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->signalSetOscAddress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 31: _t->signalSetOscIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->signalSetOscOutPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->signalSetOscInPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->slotOpenSettings(); break;
        case 36: _t->slotConnectElements(); break;
        case 37: _t->slotDisconnectElements(); break;
        case 38: _t->slotValueChanged(); break;
        case 39: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 40: _t->slotRecallSettings(); break;
        case 41: _t->slotViewSelector(); break;
        case 42: _t->slotResetGlobalGain(); break;
        case 43: _t->slotPopulateInputMenus((*reinterpret_cast< QMap<QString,MIDIEndpointRef>(*)>(_a[1]))); break;
        case 44: _t->slotSetMidiInputLineParams(); break;
        case 45: _t->slotSetJSONPath(); break;
        case 46: _t->slotReadSettings(); break;
        case 47: _t->slotWriteSettings(); break;
        case 48: _t->slotWriteDefaultSettings(); break;
        case 49: _t->slotStoreSettings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 50: _t->slotConstructSettingsDefaultMap(); break;
        case 51: _t->slotEmitAllSettings(); break;
        case 52: _t->slotSaveSettingsTimeout(); break;
        case 53: _t->slotStartCalibration(); break;
        case 54: _t->slotStopCalibration(); break;
        case 55: _t->slotResetCalibration(); break;
        case 56: _t->slotLoadTableOnStartup(); break;
        case 57: _t->slotWritePedalTableToDisk((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 58: _t->slotSetLiveValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->slotHideComplete(); break;
        case 60: _t->slotStartCalibrationStandAlone(); break;
        case 61: _t->slotStopCalibrationStandAlone(); break;
        case 62: _t->slotSetOSCDisplayValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSlider* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalStoreValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Settings::*)(QVariantMap , QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalRecallSettings)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Settings::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetGlobalGain)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetSensorResponse)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeySafetyMode)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetDisplayMode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Settings::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetSceneChanging)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Settings::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetBacklight)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeyOnThresh)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeyOffThresh)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeyYDeadZone)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeyXDeadZone)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeyYAccel)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetKeyXAccel)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavNorthOnThresh)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavNorthOffThresh)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavSouthOnThresh)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavSouthOffThresh)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavEastOnThresh)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavEastOffThresh)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavWestOnThresh)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavWestOffThresh)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetNavYIncAccel)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalStartCalibration)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalResetCalibration)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalStopCalibration)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (Settings::*)(QSlider * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetTestValueSlider)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (Settings::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalInitPedalTable)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (Settings::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalTetherOnOffInStandalone)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetOscEnable)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetOscAddress)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (Settings::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetOscIP)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetOscOutPort)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::signalSetOscInPort)) {
                *result = 33;
                return;
            }
        }
    }
}

const QMetaObject Settings::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Settings.offsetsAndSize,
    qt_meta_data_Settings,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Settings_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSlider *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<QString,MIDIEndpointRef>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    }
    return _id;
}

// SIGNAL 0
void Settings::signalStoreValue(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::signalRecallSettings(QVariantMap _t1, QVariantMap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Settings::signalSetGlobalGain(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Settings::signalSetSensorResponse(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Settings::signalSetKeySafetyMode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Settings::signalSetDisplayMode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Settings::signalSetSceneChanging(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Settings::signalSetBacklight(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Settings::signalSetKeyOnThresh(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Settings::signalSetKeyOffThresh(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Settings::signalSetKeyYDeadZone(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Settings::signalSetKeyXDeadZone(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Settings::signalSetKeyYAccel(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Settings::signalSetKeyXAccel(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Settings::signalSetNavNorthOnThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Settings::signalSetNavNorthOffThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Settings::signalSetNavSouthOnThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Settings::signalSetNavSouthOffThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Settings::signalSetNavEastOnThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Settings::signalSetNavEastOffThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Settings::signalSetNavWestOnThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Settings::signalSetNavWestOffThresh(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Settings::signalSetNavYIncAccel(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Settings::signalStartCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void Settings::signalResetCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void Settings::signalStopCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void Settings::signalSetTestValueSlider(QSlider * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void Settings::signalInitPedalTable(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void Settings::signalTetherOnOffInStandalone(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void Settings::signalSetOscEnable(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void Settings::signalSetOscAddress(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void Settings::signalSetOscIP(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void Settings::signalSetOscOutPort(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void Settings::signalSetOscInPort(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
