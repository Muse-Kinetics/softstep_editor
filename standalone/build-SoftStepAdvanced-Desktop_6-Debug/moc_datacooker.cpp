// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'datacooker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/hosted/datacooker.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datacooker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataCooker_t {
    const uint offsetsAndSize[160];
    char stringdata0[1295];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DataCooker_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DataCooker_t qt_meta_stringdata_DataCooker = {
    {
QT_MOC_LITERAL(0, 10), // "DataCooker"
QT_MOC_LITERAL(11, 21), // "signalTransformSource"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 4), // "data"
QT_MOC_LITERAL(39, 10), // "modlineNum"
QT_MOC_LITERAL(50, 6), // "source"
QT_MOC_LITERAL(57, 20), // "signalThisKeyPressed"
QT_MOC_LITERAL(78, 10), // "keyPressed"
QT_MOC_LITERAL(89, 16), // "signalThisKeyOff"
QT_MOC_LITERAL(106, 6), // "keyOff"
QT_MOC_LITERAL(113, 31), // "signalLockoutKeyPressedReleased"
QT_MOC_LITERAL(145, 9), // "keyNumber"
QT_MOC_LITERAL(155, 15), // "pressedReleased"
QT_MOC_LITERAL(171, 20), // "signalXIncClockStart"
QT_MOC_LITERAL(192, 3), // "num"
QT_MOC_LITERAL(196, 19), // "signalXIncClockStop"
QT_MOC_LITERAL(216, 20), // "signalYIncClockStart"
QT_MOC_LITERAL(237, 19), // "signalYIncClockStop"
QT_MOC_LITERAL(257, 14), // "slotUpdateVals"
QT_MOC_LITERAL(272, 2), // "cc"
QT_MOC_LITERAL(275, 3), // "val"
QT_MOC_LITERAL(279, 24), // "slotReceiveModlineOutput"
QT_MOC_LITERAL(304, 13), // "slotSetSource"
QT_MOC_LITERAL(318, 15), // "modlineInstance"
QT_MOC_LITERAL(334, 23), // "slotPressureLatchReturn"
QT_MOC_LITERAL(358, 16), // "slotXLatchReturn"
QT_MOC_LITERAL(375, 16), // "slotYLatchReturn"
QT_MOC_LITERAL(392, 23), // "slotTickXIncrementClock"
QT_MOC_LITERAL(416, 23), // "slotTickYIncrementClock"
QT_MOC_LITERAL(440, 11), // "slotYIncSet"
QT_MOC_LITERAL(452, 11), // "slotXIncSet"
QT_MOC_LITERAL(464, 21), // "slotFastTriggerReturn"
QT_MOC_LITERAL(486, 18), // "slotFastTriggerOff"
QT_MOC_LITERAL(505, 21), // "slotLongTriggerReturn"
QT_MOC_LITERAL(527, 18), // "slotLongTriggerOff"
QT_MOC_LITERAL(546, 20), // "slotDblTriggerReturn"
QT_MOC_LITERAL(567, 17), // "slotDblTriggerOff"
QT_MOC_LITERAL(585, 20), // "slotOffTriggerReturn"
QT_MOC_LITERAL(606, 17), // "slotOffTriggerOff"
QT_MOC_LITERAL(624, 26), // "slotFastTriggerLatchReturn"
QT_MOC_LITERAL(651, 23), // "slotFastTriggerLatchOff"
QT_MOC_LITERAL(675, 26), // "slotLongTriggerLatchReturn"
QT_MOC_LITERAL(702, 23), // "slotLongTriggerLatchOff"
QT_MOC_LITERAL(726, 25), // "slotDblTriggerLatchReturn"
QT_MOC_LITERAL(752, 22), // "slotDblTriggerLatchOff"
QT_MOC_LITERAL(775, 21), // "slotReceiveKeyPressed"
QT_MOC_LITERAL(797, 14), // "slotKeyPressed"
QT_MOC_LITERAL(812, 20), // "slotReceiveMidiInput"
QT_MOC_LITERAL(833, 8), // "instance"
QT_MOC_LITERAL(842, 15), // "slotReceiveNavY"
QT_MOC_LITERAL(858, 5), // "count"
QT_MOC_LITERAL(864, 20), // "slotReceiveNavDecade"
QT_MOC_LITERAL(885, 6), // "decade"
QT_MOC_LITERAL(892, 22), // "slotStateRecallYIncDec"
QT_MOC_LITERAL(915, 22), // "slotStateRecallXIncDec"
QT_MOC_LITERAL(938, 15), // "slotSetOnThresh"
QT_MOC_LITERAL(954, 3), // "key"
QT_MOC_LITERAL(958, 9), // "threshold"
QT_MOC_LITERAL(968, 16), // "slotSetOffThresh"
QT_MOC_LITERAL(985, 16), // "slotSetYDeadZone"
QT_MOC_LITERAL(1002, 8), // "deadZone"
QT_MOC_LITERAL(1011, 16), // "slotSetXDeadZone"
QT_MOC_LITERAL(1028, 13), // "slotSetYAccel"
QT_MOC_LITERAL(1042, 5), // "accel"
QT_MOC_LITERAL(1048, 13), // "slotSetXAccel"
QT_MOC_LITERAL(1062, 17), // "slotSetGlobalGain"
QT_MOC_LITERAL(1080, 21), // "slotSetSensorResponse"
QT_MOC_LITERAL(1102, 8), // "response"
QT_MOC_LITERAL(1111, 20), // "slotSetKeySafetyMode"
QT_MOC_LITERAL(1132, 4), // "mode"
QT_MOC_LITERAL(1137, 16), // "slotSetParentKey"
QT_MOC_LITERAL(1154, 4), // "Key*"
QT_MOC_LITERAL(1159, 2), // "pK"
QT_MOC_LITERAL(1162, 29), // "slotLockoutKeyPressedReleased"
QT_MOC_LITERAL(1192, 19), // "slotReceiveOscInput"
QT_MOC_LITERAL(1212, 8), // "inputNum"
QT_MOC_LITERAL(1221, 18), // "slotXIncClockStart"
QT_MOC_LITERAL(1240, 17), // "slotXIncClockStop"
QT_MOC_LITERAL(1258, 18), // "slotYIncClockStart"
QT_MOC_LITERAL(1277, 17) // "slotYIncClockStop"

    },
    "DataCooker\0signalTransformSource\0\0"
    "data\0modlineNum\0source\0signalThisKeyPressed\0"
    "keyPressed\0signalThisKeyOff\0keyOff\0"
    "signalLockoutKeyPressedReleased\0"
    "keyNumber\0pressedReleased\0"
    "signalXIncClockStart\0num\0signalXIncClockStop\0"
    "signalYIncClockStart\0signalYIncClockStop\0"
    "slotUpdateVals\0cc\0val\0slotReceiveModlineOutput\0"
    "slotSetSource\0modlineInstance\0"
    "slotPressureLatchReturn\0slotXLatchReturn\0"
    "slotYLatchReturn\0slotTickXIncrementClock\0"
    "slotTickYIncrementClock\0slotYIncSet\0"
    "slotXIncSet\0slotFastTriggerReturn\0"
    "slotFastTriggerOff\0slotLongTriggerReturn\0"
    "slotLongTriggerOff\0slotDblTriggerReturn\0"
    "slotDblTriggerOff\0slotOffTriggerReturn\0"
    "slotOffTriggerOff\0slotFastTriggerLatchReturn\0"
    "slotFastTriggerLatchOff\0"
    "slotLongTriggerLatchReturn\0"
    "slotLongTriggerLatchOff\0"
    "slotDblTriggerLatchReturn\0"
    "slotDblTriggerLatchOff\0slotReceiveKeyPressed\0"
    "slotKeyPressed\0slotReceiveMidiInput\0"
    "instance\0slotReceiveNavY\0count\0"
    "slotReceiveNavDecade\0decade\0"
    "slotStateRecallYIncDec\0slotStateRecallXIncDec\0"
    "slotSetOnThresh\0key\0threshold\0"
    "slotSetOffThresh\0slotSetYDeadZone\0"
    "deadZone\0slotSetXDeadZone\0slotSetYAccel\0"
    "accel\0slotSetXAccel\0slotSetGlobalGain\0"
    "slotSetSensorResponse\0response\0"
    "slotSetKeySafetyMode\0mode\0slotSetParentKey\0"
    "Key*\0pK\0slotLockoutKeyPressedReleased\0"
    "slotReceiveOscInput\0inputNum\0"
    "slotXIncClockStart\0slotXIncClockStop\0"
    "slotYIncClockStart\0slotYIncClockStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataCooker[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  344,    2, 0x06,    0 /* Public */,
       6,    1,  351,    2, 0x06,    4 /* Public */,
       8,    1,  354,    2, 0x06,    6 /* Public */,
      10,    2,  357,    2, 0x06,    8 /* Public */,
      13,    1,  362,    2, 0x06,   11 /* Public */,
      15,    0,  365,    2, 0x06,   13 /* Public */,
      16,    1,  366,    2, 0x06,   14 /* Public */,
      17,    0,  369,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    2,  370,    2, 0x0a,   17 /* Public */,
      21,    2,  375,    2, 0x0a,   20 /* Public */,
      22,    2,  380,    2, 0x0a,   23 /* Public */,
      24,    2,  385,    2, 0x0a,   26 /* Public */,
      25,    2,  390,    2, 0x0a,   29 /* Public */,
      26,    2,  395,    2, 0x0a,   32 /* Public */,
      27,    0,  400,    2, 0x0a,   35 /* Public */,
      28,    0,  401,    2, 0x0a,   36 /* Public */,
      29,    1,  402,    2, 0x0a,   37 /* Public */,
      30,    1,  405,    2, 0x0a,   39 /* Public */,
      31,    0,  408,    2, 0x0a,   41 /* Public */,
      32,    0,  409,    2, 0x0a,   42 /* Public */,
      33,    0,  410,    2, 0x0a,   43 /* Public */,
      34,    0,  411,    2, 0x0a,   44 /* Public */,
      35,    0,  412,    2, 0x0a,   45 /* Public */,
      36,    0,  413,    2, 0x0a,   46 /* Public */,
      37,    0,  414,    2, 0x0a,   47 /* Public */,
      38,    0,  415,    2, 0x0a,   48 /* Public */,
      39,    0,  416,    2, 0x0a,   49 /* Public */,
      40,    0,  417,    2, 0x0a,   50 /* Public */,
      41,    0,  418,    2, 0x0a,   51 /* Public */,
      42,    0,  419,    2, 0x0a,   52 /* Public */,
      43,    0,  420,    2, 0x0a,   53 /* Public */,
      44,    0,  421,    2, 0x0a,   54 /* Public */,
      45,    1,  422,    2, 0x0a,   55 /* Public */,
      46,    0,  425,    2, 0x0a,   57 /* Public */,
      47,    2,  426,    2, 0x0a,   58 /* Public */,
      49,    1,  431,    2, 0x0a,   61 /* Public */,
      51,    1,  434,    2, 0x0a,   63 /* Public */,
      53,    1,  437,    2, 0x0a,   65 /* Public */,
      54,    1,  440,    2, 0x0a,   67 /* Public */,
      55,    2,  443,    2, 0x0a,   69 /* Public */,
      58,    2,  448,    2, 0x0a,   72 /* Public */,
      59,    2,  453,    2, 0x0a,   75 /* Public */,
      61,    2,  458,    2, 0x0a,   78 /* Public */,
      62,    2,  463,    2, 0x0a,   81 /* Public */,
      64,    2,  468,    2, 0x0a,   84 /* Public */,
      65,    1,  473,    2, 0x0a,   87 /* Public */,
      66,    1,  476,    2, 0x0a,   89 /* Public */,
      68,    1,  479,    2, 0x0a,   91 /* Public */,
      70,    1,  482,    2, 0x0a,   93 /* Public */,
      73,    2,  485,    2, 0x0a,   95 /* Public */,
      74,    2,  490,    2, 0x0a,   98 /* Public */,
      76,    1,  495,    2, 0x0a,  101 /* Public */,
      77,    0,  498,    2, 0x0a,  103 /* Public */,
      78,    1,  499,    2, 0x0a,  104 /* Public */,
      79,    0,  502,    2, 0x0a,  106 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   48,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   57,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   57,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   60,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   60,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   63,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   63,
    QMetaType::Void, QMetaType::Float,   20,
    QMetaType::Void, QMetaType::Int,   67,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, 0x80000000 | 71,   72,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   75,   20,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

       0        // eod
};

void DataCooker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataCooker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalTransformSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->signalThisKeyPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalThisKeyOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalLockoutKeyPressedReleased((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->signalXIncClockStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalXIncClockStop(); break;
        case 6: _t->signalYIncClockStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->signalYIncClockStop(); break;
        case 8: _t->slotUpdateVals((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->slotReceiveModlineOutput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->slotSetSource((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotPressureLatchReturn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->slotXLatchReturn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->slotYLatchReturn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->slotTickXIncrementClock(); break;
        case 15: _t->slotTickYIncrementClock(); break;
        case 16: _t->slotYIncSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->slotXIncSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->slotFastTriggerReturn(); break;
        case 19: _t->slotFastTriggerOff(); break;
        case 20: _t->slotLongTriggerReturn(); break;
        case 21: _t->slotLongTriggerOff(); break;
        case 22: _t->slotDblTriggerReturn(); break;
        case 23: _t->slotDblTriggerOff(); break;
        case 24: _t->slotOffTriggerReturn(); break;
        case 25: _t->slotOffTriggerOff(); break;
        case 26: _t->slotFastTriggerLatchReturn(); break;
        case 27: _t->slotFastTriggerLatchOff(); break;
        case 28: _t->slotLongTriggerLatchReturn(); break;
        case 29: _t->slotLongTriggerLatchOff(); break;
        case 30: _t->slotDblTriggerLatchReturn(); break;
        case 31: _t->slotDblTriggerLatchOff(); break;
        case 32: _t->slotReceiveKeyPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->slotKeyPressed(); break;
        case 34: _t->slotReceiveMidiInput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 35: _t->slotReceiveNavY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->slotReceiveNavDecade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->slotStateRecallYIncDec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->slotStateRecallXIncDec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->slotSetOnThresh((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 40: _t->slotSetOffThresh((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->slotSetYDeadZone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 42: _t->slotSetXDeadZone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: _t->slotSetYAccel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 44: _t->slotSetXAccel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 45: _t->slotSetGlobalGain((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 46: _t->slotSetSensorResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->slotSetKeySafetyMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->slotSetParentKey((*reinterpret_cast< Key*(*)>(_a[1]))); break;
        case 49: _t->slotLockoutKeyPressedReleased((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 50: _t->slotReceiveOscInput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 51: _t->slotXIncClockStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->slotXIncClockStop(); break;
        case 53: _t->slotYIncClockStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->slotYIncClockStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataCooker::*)(int , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalTransformSource)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalThisKeyPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalThisKeyOff)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalLockoutKeyPressedReleased)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalXIncClockStart)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalXIncClockStop)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalYIncClockStart)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DataCooker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCooker::signalYIncClockStop)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject DataCooker::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DataCooker.offsetsAndSize,
    qt_meta_data_DataCooker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DataCooker_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Key *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *DataCooker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataCooker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataCooker.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DataCooker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void DataCooker::signalTransformSource(int _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataCooker::signalThisKeyPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataCooker::signalThisKeyOff(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataCooker::signalLockoutKeyPressedReleased(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataCooker::signalXIncClockStart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataCooker::signalXIncClockStop()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DataCooker::signalYIncClockStart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DataCooker::signalYIncClockStop()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
