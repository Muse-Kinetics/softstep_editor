// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'navmodline.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/navmodline.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navmodline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavModline_t {
    const uint offsetsAndSize[160];
    char stringdata0[1160];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NavModline_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NavModline_t qt_meta_stringdata_NavModline = {
    {
QT_MOC_LITERAL(0, 10), // "NavModline"
QT_MOC_LITERAL(11, 16), // "signalStoreValue"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 4), // "name"
QT_MOC_LITERAL(34, 5), // "value"
QT_MOC_LITERAL(40, 9), // "presetNum"
QT_MOC_LITERAL(50, 21), // "signalCheckSavedState"
QT_MOC_LITERAL(72, 20), // "signalModlineEnabled"
QT_MOC_LITERAL(93, 13), // "parameterName"
QT_MOC_LITERAL(107, 15), // "signalSetSource"
QT_MOC_LITERAL(123, 10), // "sourceName"
QT_MOC_LITERAL(134, 10), // "modlineNum"
QT_MOC_LITERAL(145, 30), // "hosted_signalSendModlineOutput"
QT_MOC_LITERAL(176, 3), // "val"
QT_MOC_LITERAL(180, 35), // "hosted_signalSendParamDisplay..."
QT_MOC_LITERAL(216, 20), // "hosted_signalNoteSet"
QT_MOC_LITERAL(237, 4), // "port"
QT_MOC_LITERAL(242, 7), // "channel"
QT_MOC_LITERAL(250, 4), // "note"
QT_MOC_LITERAL(255, 8), // "velocity"
QT_MOC_LITERAL(264, 21), // "hosted_signalNoteLive"
QT_MOC_LITERAL(286, 7), // "oldNote"
QT_MOC_LITERAL(294, 7), // "newNote"
QT_MOC_LITERAL(302, 15), // "hosted_signalCC"
QT_MOC_LITERAL(318, 5), // "ccNum"
QT_MOC_LITERAL(324, 5), // "ccVal"
QT_MOC_LITERAL(330, 17), // "hosted_signalBank"
QT_MOC_LITERAL(348, 3), // "msb"
QT_MOC_LITERAL(352, 3), // "lsb"
QT_MOC_LITERAL(356, 16), // "hosted_signalOSC"
QT_MOC_LITERAL(373, 20), // "hosted_signalProgram"
QT_MOC_LITERAL(394, 7), // "program"
QT_MOC_LITERAL(402, 22), // "hosted_signalPitchBend"
QT_MOC_LITERAL(425, 16), // "hosted_signalMMC"
QT_MOC_LITERAL(442, 2), // "id"
QT_MOC_LITERAL(445, 8), // "function"
QT_MOC_LITERAL(454, 23), // "hosted_signalAftertouch"
QT_MOC_LITERAL(478, 27), // "hosted_signalPolyAftertouch"
QT_MOC_LITERAL(506, 20), // "hosted_signalYIncSet"
QT_MOC_LITERAL(527, 20), // "hosted_signalXIncSet"
QT_MOC_LITERAL(548, 20), // "hosted_signalCounter"
QT_MOC_LITERAL(569, 8), // "whatToDo"
QT_MOC_LITERAL(578, 29), // "hosted_signalStoreToggleState"
QT_MOC_LITERAL(608, 5), // "state"
QT_MOC_LITERAL(614, 19), // "slotConnectElements"
QT_MOC_LITERAL(634, 22), // "slotDisconnectElements"
QT_MOC_LITERAL(657, 16), // "slotValueChanged"
QT_MOC_LITERAL(674, 16), // "slotRecallPreset"
QT_MOC_LITERAL(691, 14), // "slotTestValues"
QT_MOC_LITERAL(706, 25), // "slotRecallDestinationMenu"
QT_MOC_LITERAL(732, 17), // "slotDeleteModline"
QT_MOC_LITERAL(750, 3), // "num"
QT_MOC_LITERAL(754, 7), // "disable"
QT_MOC_LITERAL(762, 18), // "slotDisableModline"
QT_MOC_LITERAL(781, 11), // "slotSetMode"
QT_MOC_LITERAL(793, 1), // "m"
QT_MOC_LITERAL(795, 17), // "slotPopulateMenus"
QT_MOC_LITERAL(813, 6), // "source"
QT_MOC_LITERAL(820, 4), // "dest"
QT_MOC_LITERAL(825, 5), // "table"
QT_MOC_LITERAL(831, 19), // "slotTransformSource"
QT_MOC_LITERAL(851, 22), // "slotSetTransformValues"
QT_MOC_LITERAL(874, 20), // "slotStreamSourceData"
QT_MOC_LITERAL(895, 9), // "slotTable"
QT_MOC_LITERAL(905, 5), // "input"
QT_MOC_LITERAL(911, 17), // "slotCounterReturn"
QT_MOC_LITERAL(929, 1), // "i"
QT_MOC_LITERAL(931, 10), // "slotMinMax"
QT_MOC_LITERAL(942, 10), // "slotSmooth"
QT_MOC_LITERAL(953, 16), // "slotSmoothReturn"
QT_MOC_LITERAL(970, 9), // "slotDelay"
QT_MOC_LITERAL(980, 15), // "slotDelayReturn"
QT_MOC_LITERAL(996, 17), // "slotOutputRoutine"
QT_MOC_LITERAL(1014, 21), // "hosted_slotOutputMidi"
QT_MOC_LITERAL(1036, 9), // "outputVal"
QT_MOC_LITERAL(1046, 29), // "hosted_slotPopulateDeviceMenu"
QT_MOC_LITERAL(1076, 29), // "QMap<QString,MIDIEndpointRef>"
QT_MOC_LITERAL(1106, 15), // "externalDevices"
QT_MOC_LITERAL(1122, 15), // "slotDisplayVars"
QT_MOC_LITERAL(1138, 21) // "slotStateRecallToggle"

    },
    "NavModline\0signalStoreValue\0\0name\0"
    "value\0presetNum\0signalCheckSavedState\0"
    "signalModlineEnabled\0parameterName\0"
    "signalSetSource\0sourceName\0modlineNum\0"
    "hosted_signalSendModlineOutput\0val\0"
    "hosted_signalSendParamDisplayOutput\0"
    "hosted_signalNoteSet\0port\0channel\0"
    "note\0velocity\0hosted_signalNoteLive\0"
    "oldNote\0newNote\0hosted_signalCC\0ccNum\0"
    "ccVal\0hosted_signalBank\0msb\0lsb\0"
    "hosted_signalOSC\0hosted_signalProgram\0"
    "program\0hosted_signalPitchBend\0"
    "hosted_signalMMC\0id\0function\0"
    "hosted_signalAftertouch\0"
    "hosted_signalPolyAftertouch\0"
    "hosted_signalYIncSet\0hosted_signalXIncSet\0"
    "hosted_signalCounter\0whatToDo\0"
    "hosted_signalStoreToggleState\0state\0"
    "slotConnectElements\0slotDisconnectElements\0"
    "slotValueChanged\0slotRecallPreset\0"
    "slotTestValues\0slotRecallDestinationMenu\0"
    "slotDeleteModline\0num\0disable\0"
    "slotDisableModline\0slotSetMode\0m\0"
    "slotPopulateMenus\0source\0dest\0table\0"
    "slotTransformSource\0slotSetTransformValues\0"
    "slotStreamSourceData\0slotTable\0input\0"
    "slotCounterReturn\0i\0slotMinMax\0"
    "slotSmooth\0slotSmoothReturn\0slotDelay\0"
    "slotDelayReturn\0slotOutputRoutine\0"
    "hosted_slotOutputMidi\0outputVal\0"
    "hosted_slotPopulateDeviceMenu\0"
    "QMap<QString,MIDIEndpointRef>\0"
    "externalDevices\0slotDisplayVars\0"
    "slotStateRecallToggle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavModline[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  284,    2, 0x06,    0 /* Public */,
       6,    0,  291,    2, 0x06,    4 /* Public */,
       7,    1,  292,    2, 0x06,    5 /* Public */,
       9,    2,  295,    2, 0x06,    7 /* Public */,
      12,    2,  300,    2, 0x06,   10 /* Public */,
      14,    2,  305,    2, 0x06,   13 /* Public */,
      15,    4,  310,    2, 0x06,   16 /* Public */,
      20,    5,  319,    2, 0x06,   21 /* Public */,
      23,    4,  330,    2, 0x06,   27 /* Public */,
      26,    4,  339,    2, 0x06,   32 /* Public */,
      29,    0,  348,    2, 0x06,   37 /* Public */,
      30,    3,  349,    2, 0x06,   38 /* Public */,
      32,    4,  356,    2, 0x06,   42 /* Public */,
      33,    3,  365,    2, 0x06,   47 /* Public */,
      36,    3,  372,    2, 0x06,   51 /* Public */,
      37,    4,  379,    2, 0x06,   55 /* Public */,
      38,    1,  388,    2, 0x06,   60 /* Public */,
      39,    1,  391,    2, 0x06,   62 /* Public */,
      40,    2,  394,    2, 0x06,   64 /* Public */,
      42,    2,  399,    2, 0x06,   67 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      44,    0,  404,    2, 0x0a,   70 /* Public */,
      45,    0,  405,    2, 0x0a,   71 /* Public */,
      46,    0,  406,    2, 0x0a,   72 /* Public */,
      47,    2,  407,    2, 0x0a,   73 /* Public */,
      48,    1,  412,    2, 0x0a,   76 /* Public */,
      49,    0,  415,    2, 0x0a,   78 /* Public */,
      50,    2,  416,    2, 0x0a,   79 /* Public */,
      53,    1,  421,    2, 0x0a,   82 /* Public */,
      54,    1,  424,    2, 0x0a,   84 /* Public */,
      56,    3,  427,    2, 0x0a,   86 /* Public */,
      60,    3,  434,    2, 0x0a,   90 /* Public */,
      61,    0,  441,    2, 0x0a,   94 /* Public */,
      62,    0,  442,    2, 0x0a,   95 /* Public */,
      63,    1,  443,    2, 0x0a,   96 /* Public */,
      65,    1,  446,    2, 0x0a,   98 /* Public */,
      67,    1,  449,    2, 0x0a,  100 /* Public */,
      68,    1,  452,    2, 0x0a,  102 /* Public */,
      69,    1,  455,    2, 0x0a,  104 /* Public */,
      70,    1,  458,    2, 0x0a,  106 /* Public */,
      71,    1,  461,    2, 0x0a,  108 /* Public */,
      72,    1,  464,    2, 0x0a,  110 /* Public */,
      73,    1,  467,    2, 0x0a,  112 /* Public */,
      75,    1,  470,    2, 0x0a,  114 /* Public */,
      78,    0,  473,    2, 0x0a,  116 /* Public */,
      79,    2,  474,    2, 0x0a,  117 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   21,   22,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   24,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   27,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   16,   17,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   28,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   16,   34,   35,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   16,   17,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   18,   13,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   41,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   43,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   51,   52,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   55,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   57,   58,   59,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   13,   11,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   74,
    QMetaType::Void, 0x80000000 | 76,   77,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   43,

       0        // eod
};

void NavModline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavModline *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalStoreValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->signalCheckSavedState(); break;
        case 2: _t->signalModlineEnabled((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signalSetSource((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->hosted_signalSendModlineOutput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->hosted_signalSendParamDisplayOutput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->hosted_signalNoteSet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->hosted_signalNoteLive((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 8: _t->hosted_signalCC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 9: _t->hosted_signalBank((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->hosted_signalOSC(); break;
        case 11: _t->hosted_signalProgram((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->hosted_signalPitchBend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 13: _t->hosted_signalMMC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 14: _t->hosted_signalAftertouch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->hosted_signalPolyAftertouch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->hosted_signalYIncSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->hosted_signalXIncSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->hosted_signalCounter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->hosted_signalStoreToggleState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->slotConnectElements(); break;
        case 21: _t->slotDisconnectElements(); break;
        case 22: _t->slotValueChanged(); break;
        case 23: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 24: _t->slotTestValues((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->slotRecallDestinationMenu(); break;
        case 26: _t->slotDeleteModline((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 27: _t->slotDisableModline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->slotPopulateMenus((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 30: _t->slotTransformSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 31: _t->slotSetTransformValues(); break;
        case 32: _t->slotStreamSourceData(); break;
        case 33: _t->slotTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->slotCounterReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->slotMinMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->slotSmooth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->slotSmoothReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->slotDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->slotDelayReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->slotOutputRoutine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->hosted_slotOutputMidi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->hosted_slotPopulateDeviceMenu((*reinterpret_cast< QMap<QString,MIDIEndpointRef>(*)>(_a[1]))); break;
        case 43: _t->slotDisplayVars(); break;
        case 44: _t->slotStateRecallToggle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NavModline::*)(QString , QVariant , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::signalStoreValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NavModline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::signalCheckSavedState)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::signalModlineEnabled)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::signalSetSource)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalSendModlineOutput)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalSendParamDisplayOutput)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalNoteSet)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalNoteLive)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalCC)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalBank)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (NavModline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalOSC)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalProgram)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalPitchBend)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalMMC)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalAftertouch)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalPolyAftertouch)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalYIncSet)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalXIncSet)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalCounter)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (NavModline::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavModline::hosted_signalStoreToggleState)) {
                *result = 19;
                return;
            }
        }
    }
}

const QMetaObject NavModline::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_NavModline.offsetsAndSize,
    qt_meta_data_NavModline,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NavModline_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<QString,MIDIEndpointRef>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *NavModline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavModline::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavModline.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int NavModline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void NavModline::signalStoreValue(QString _t1, QVariant _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NavModline::signalCheckSavedState()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NavModline::signalModlineEnabled(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NavModline::signalSetSource(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NavModline::hosted_signalSendModlineOutput(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NavModline::hosted_signalSendParamDisplayOutput(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NavModline::hosted_signalNoteSet(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void NavModline::hosted_signalNoteLive(QString _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void NavModline::hosted_signalCC(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void NavModline::hosted_signalBank(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void NavModline::hosted_signalOSC()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void NavModline::hosted_signalProgram(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void NavModline::hosted_signalPitchBend(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void NavModline::hosted_signalMMC(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void NavModline::hosted_signalAftertouch(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void NavModline::hosted_signalPolyAftertouch(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void NavModline::hosted_signalYIncSet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void NavModline::hosted_signalXIncSet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void NavModline::hosted_signalCounter(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void NavModline::hosted_signalStoreToggleState(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
