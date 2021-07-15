// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/****************************************************************************
** Meta object code from reading C++ file 'modline.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../advanced/modline.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Modline_t {
    const uint offsetsAndSize[174];
    char stringdata0[1258];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Modline_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Modline_t qt_meta_stringdata_Modline = {
    {
QT_MOC_LITERAL(0, 7), // "Modline"
QT_MOC_LITERAL(8, 16), // "signalStoreValue"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 4), // "name"
QT_MOC_LITERAL(31, 5), // "value"
QT_MOC_LITERAL(37, 9), // "presetNum"
QT_MOC_LITERAL(47, 21), // "signalCheckSavedState"
QT_MOC_LITERAL(69, 20), // "signalModlineEnabled"
QT_MOC_LITERAL(90, 13), // "parameterName"
QT_MOC_LITERAL(104, 15), // "signalSetSource"
QT_MOC_LITERAL(120, 10), // "sourceName"
QT_MOC_LITERAL(131, 10), // "modlineNum"
QT_MOC_LITERAL(142, 30), // "hosted_signalSendModlineOutput"
QT_MOC_LITERAL(173, 3), // "val"
QT_MOC_LITERAL(177, 35), // "hosted_signalSendParamDisplay..."
QT_MOC_LITERAL(213, 20), // "hosted_signalNoteSet"
QT_MOC_LITERAL(234, 4), // "port"
QT_MOC_LITERAL(239, 7), // "channel"
QT_MOC_LITERAL(247, 4), // "note"
QT_MOC_LITERAL(252, 8), // "velocity"
QT_MOC_LITERAL(261, 21), // "hosted_signalNoteLive"
QT_MOC_LITERAL(283, 7), // "oldNote"
QT_MOC_LITERAL(291, 7), // "newNote"
QT_MOC_LITERAL(299, 15), // "hosted_signalCC"
QT_MOC_LITERAL(315, 5), // "ccNum"
QT_MOC_LITERAL(321, 5), // "ccVal"
QT_MOC_LITERAL(327, 17), // "hosted_signalBank"
QT_MOC_LITERAL(345, 3), // "msb"
QT_MOC_LITERAL(349, 3), // "lsb"
QT_MOC_LITERAL(353, 16), // "hosted_signalOSC"
QT_MOC_LITERAL(370, 7), // "address"
QT_MOC_LITERAL(378, 20), // "hosted_signalProgram"
QT_MOC_LITERAL(399, 7), // "program"
QT_MOC_LITERAL(407, 22), // "hosted_signalPitchBend"
QT_MOC_LITERAL(430, 16), // "hosted_signalMMC"
QT_MOC_LITERAL(447, 2), // "id"
QT_MOC_LITERAL(450, 8), // "function"
QT_MOC_LITERAL(459, 23), // "hosted_signalAftertouch"
QT_MOC_LITERAL(483, 27), // "hosted_signalPolyAftertouch"
QT_MOC_LITERAL(511, 23), // "hosted_signalGarageBand"
QT_MOC_LITERAL(535, 16), // "hosted_signalHUI"
QT_MOC_LITERAL(552, 20), // "hosted_signalYIncSet"
QT_MOC_LITERAL(573, 20), // "hosted_signalXIncSet"
QT_MOC_LITERAL(594, 23), // "hosted_signalSetLEDMode"
QT_MOC_LITERAL(618, 9), // "modlieNum"
QT_MOC_LITERAL(628, 9), // "greenMode"
QT_MOC_LITERAL(638, 7), // "redMode"
QT_MOC_LITERAL(646, 20), // "hosted_signalCounter"
QT_MOC_LITERAL(667, 8), // "whatToDo"
QT_MOC_LITERAL(676, 29), // "hosted_signalStoreToggleState"
QT_MOC_LITERAL(706, 5), // "state"
QT_MOC_LITERAL(712, 19), // "slotConnectElements"
QT_MOC_LITERAL(732, 22), // "slotDisconnectElements"
QT_MOC_LITERAL(755, 16), // "slotValueChanged"
QT_MOC_LITERAL(772, 16), // "slotRecallPreset"
QT_MOC_LITERAL(789, 14), // "slotTestValues"
QT_MOC_LITERAL(804, 25), // "slotRecallDestinationMenu"
QT_MOC_LITERAL(830, 17), // "slotDeleteModline"
QT_MOC_LITERAL(848, 3), // "num"
QT_MOC_LITERAL(852, 7), // "disable"
QT_MOC_LITERAL(860, 18), // "slotDisableModline"
QT_MOC_LITERAL(879, 11), // "slotSetMode"
QT_MOC_LITERAL(891, 1), // "m"
QT_MOC_LITERAL(893, 17), // "slotPopulateMenus"
QT_MOC_LITERAL(911, 6), // "source"
QT_MOC_LITERAL(918, 4), // "dest"
QT_MOC_LITERAL(923, 5), // "table"
QT_MOC_LITERAL(929, 19), // "slotTransformSource"
QT_MOC_LITERAL(949, 22), // "slotSetTransformValues"
QT_MOC_LITERAL(972, 20), // "slotStreamSourceData"
QT_MOC_LITERAL(993, 9), // "slotTable"
QT_MOC_LITERAL(1003, 5), // "input"
QT_MOC_LITERAL(1009, 17), // "slotCounterReturn"
QT_MOC_LITERAL(1027, 1), // "i"
QT_MOC_LITERAL(1029, 10), // "slotMinMax"
QT_MOC_LITERAL(1040, 10), // "slotSmooth"
QT_MOC_LITERAL(1051, 16), // "slotSmoothReturn"
QT_MOC_LITERAL(1068, 9), // "slotDelay"
QT_MOC_LITERAL(1078, 15), // "slotDelayReturn"
QT_MOC_LITERAL(1094, 17), // "slotOutputRoutine"
QT_MOC_LITERAL(1112, 21), // "hosted_slotOutputMidi"
QT_MOC_LITERAL(1134, 9), // "outputVal"
QT_MOC_LITERAL(1144, 29), // "hosted_slotPopulateDeviceMenu"
QT_MOC_LITERAL(1174, 29), // "QMap<QString,MIDIEndpointRef>"
QT_MOC_LITERAL(1204, 15), // "externalDevices"
QT_MOC_LITERAL(1220, 15), // "slotDisplayVars"
QT_MOC_LITERAL(1236, 21) // "slotStateRecallToggle"

    },
    "Modline\0signalStoreValue\0\0name\0value\0"
    "presetNum\0signalCheckSavedState\0"
    "signalModlineEnabled\0parameterName\0"
    "signalSetSource\0sourceName\0modlineNum\0"
    "hosted_signalSendModlineOutput\0val\0"
    "hosted_signalSendParamDisplayOutput\0"
    "hosted_signalNoteSet\0port\0channel\0"
    "note\0velocity\0hosted_signalNoteLive\0"
    "oldNote\0newNote\0hosted_signalCC\0ccNum\0"
    "ccVal\0hosted_signalBank\0msb\0lsb\0"
    "hosted_signalOSC\0address\0hosted_signalProgram\0"
    "program\0hosted_signalPitchBend\0"
    "hosted_signalMMC\0id\0function\0"
    "hosted_signalAftertouch\0"
    "hosted_signalPolyAftertouch\0"
    "hosted_signalGarageBand\0hosted_signalHUI\0"
    "hosted_signalYIncSet\0hosted_signalXIncSet\0"
    "hosted_signalSetLEDMode\0modlieNum\0"
    "greenMode\0redMode\0hosted_signalCounter\0"
    "whatToDo\0hosted_signalStoreToggleState\0"
    "state\0slotConnectElements\0"
    "slotDisconnectElements\0slotValueChanged\0"
    "slotRecallPreset\0slotTestValues\0"
    "slotRecallDestinationMenu\0slotDeleteModline\0"
    "num\0disable\0slotDisableModline\0"
    "slotSetMode\0m\0slotPopulateMenus\0source\0"
    "dest\0table\0slotTransformSource\0"
    "slotSetTransformValues\0slotStreamSourceData\0"
    "slotTable\0input\0slotCounterReturn\0i\0"
    "slotMinMax\0slotSmooth\0slotSmoothReturn\0"
    "slotDelay\0slotDelayReturn\0slotOutputRoutine\0"
    "hosted_slotOutputMidi\0outputVal\0"
    "hosted_slotPopulateDeviceMenu\0"
    "QMap<QString,MIDIEndpointRef>\0"
    "externalDevices\0slotDisplayVars\0"
    "slotStateRecallToggle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modline[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  302,    2, 0x06,    0 /* Public */,
       6,    0,  309,    2, 0x06,    4 /* Public */,
       7,    1,  310,    2, 0x06,    5 /* Public */,
       9,    2,  313,    2, 0x06,    7 /* Public */,
      12,    2,  318,    2, 0x06,   10 /* Public */,
      14,    2,  323,    2, 0x06,   13 /* Public */,
      15,    4,  328,    2, 0x06,   16 /* Public */,
      20,    5,  337,    2, 0x06,   21 /* Public */,
      23,    4,  348,    2, 0x06,   27 /* Public */,
      26,    4,  357,    2, 0x06,   32 /* Public */,
      29,    2,  366,    2, 0x06,   37 /* Public */,
      31,    3,  371,    2, 0x06,   40 /* Public */,
      33,    4,  378,    2, 0x06,   44 /* Public */,
      34,    3,  387,    2, 0x06,   49 /* Public */,
      37,    3,  394,    2, 0x06,   53 /* Public */,
      38,    4,  401,    2, 0x06,   57 /* Public */,
      39,    0,  410,    2, 0x06,   62 /* Public */,
      40,    0,  411,    2, 0x06,   63 /* Public */,
      41,    1,  412,    2, 0x06,   64 /* Public */,
      42,    1,  415,    2, 0x06,   66 /* Public */,
      43,    3,  418,    2, 0x06,   68 /* Public */,
      47,    2,  425,    2, 0x06,   72 /* Public */,
      49,    2,  430,    2, 0x06,   75 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      51,    0,  435,    2, 0x0a,   78 /* Public */,
      52,    0,  436,    2, 0x0a,   79 /* Public */,
      53,    0,  437,    2, 0x0a,   80 /* Public */,
      54,    2,  438,    2, 0x0a,   81 /* Public */,
      55,    1,  443,    2, 0x0a,   84 /* Public */,
      56,    0,  446,    2, 0x0a,   86 /* Public */,
      57,    2,  447,    2, 0x0a,   87 /* Public */,
      60,    1,  452,    2, 0x0a,   90 /* Public */,
      61,    1,  455,    2, 0x0a,   92 /* Public */,
      63,    3,  458,    2, 0x0a,   94 /* Public */,
      67,    3,  465,    2, 0x0a,   98 /* Public */,
      68,    0,  472,    2, 0x0a,  102 /* Public */,
      69,    0,  473,    2, 0x0a,  103 /* Public */,
      70,    1,  474,    2, 0x0a,  104 /* Public */,
      72,    1,  477,    2, 0x0a,  106 /* Public */,
      74,    1,  480,    2, 0x0a,  108 /* Public */,
      75,    1,  483,    2, 0x0a,  110 /* Public */,
      76,    1,  486,    2, 0x0a,  112 /* Public */,
      77,    1,  489,    2, 0x0a,  114 /* Public */,
      78,    1,  492,    2, 0x0a,  116 /* Public */,
      79,    1,  495,    2, 0x0a,  118 /* Public */,
      80,    1,  498,    2, 0x0a,  120 /* Public */,
      82,    1,  501,    2, 0x0a,  122 /* Public */,
      85,    0,  504,    2, 0x0a,  124 /* Public */,
      86,    2,  505,    2, 0x0a,  125 /* Public */,

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
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   30,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   16,   17,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   28,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   16,   35,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   16,   17,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,   18,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   44,   45,   46,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   48,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   50,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   58,   59,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   64,   65,   66,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   13,   11,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   73,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   81,
    QMetaType::Void, 0x80000000 | 83,   84,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   50,

       0        // eod
};

void Modline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Modline *>(_o);
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
        case 10: _t->hosted_signalOSC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->hosted_signalProgram((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->hosted_signalPitchBend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 13: _t->hosted_signalMMC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 14: _t->hosted_signalAftertouch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->hosted_signalPolyAftertouch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->hosted_signalGarageBand(); break;
        case 17: _t->hosted_signalHUI(); break;
        case 18: _t->hosted_signalYIncSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->hosted_signalXIncSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->hosted_signalSetLEDMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 21: _t->hosted_signalCounter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->hosted_signalStoreToggleState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->slotConnectElements(); break;
        case 24: _t->slotDisconnectElements(); break;
        case 25: _t->slotValueChanged(); break;
        case 26: _t->slotRecallPreset((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 27: _t->slotTestValues((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->slotRecallDestinationMenu(); break;
        case 29: _t->slotDeleteModline((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->slotDisableModline((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->slotSetMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->slotPopulateMenus((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 33: _t->slotTransformSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 34: _t->slotSetTransformValues(); break;
        case 35: _t->slotStreamSourceData(); break;
        case 36: _t->slotTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->slotCounterReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->slotMinMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->slotSmooth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->slotSmoothReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->slotDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->slotDelayReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->slotOutputRoutine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->hosted_slotOutputMidi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->hosted_slotPopulateDeviceMenu((*reinterpret_cast< QMap<QString,MIDIEndpointRef>(*)>(_a[1]))); break;
        case 46: _t->slotDisplayVars(); break;
        case 47: _t->slotStateRecallToggle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Modline::*)(QString , QVariant , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::signalStoreValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Modline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::signalCheckSavedState)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::signalModlineEnabled)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::signalSetSource)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Modline::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalSendModlineOutput)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Modline::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalSendParamDisplayOutput)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalNoteSet)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalNoteLive)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalCC)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalBank)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalOSC)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalProgram)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalPitchBend)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalMMC)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalAftertouch)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalPolyAftertouch)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Modline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalGarageBand)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Modline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalHUI)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Modline::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalYIncSet)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (Modline::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalXIncSet)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (Modline::*)(int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalSetLEDMode)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (Modline::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalCounter)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (Modline::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modline::hosted_signalStoreToggleState)) {
                *result = 22;
                return;
            }
        }
    }
}

const QMetaObject Modline::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Modline.offsetsAndSize,
    qt_meta_data_Modline,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Modline_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<QString,MIDIEndpointRef>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Modline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modline::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Modline.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Modline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void Modline::signalStoreValue(QString _t1, QVariant _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Modline::signalCheckSavedState()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Modline::signalModlineEnabled(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Modline::signalSetSource(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Modline::hosted_signalSendModlineOutput(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Modline::hosted_signalSendParamDisplayOutput(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Modline::hosted_signalNoteSet(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Modline::hosted_signalNoteLive(QString _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Modline::hosted_signalCC(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Modline::hosted_signalBank(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Modline::hosted_signalOSC(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Modline::hosted_signalProgram(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Modline::hosted_signalPitchBend(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Modline::hosted_signalMMC(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Modline::hosted_signalAftertouch(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Modline::hosted_signalPolyAftertouch(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Modline::hosted_signalGarageBand()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void Modline::hosted_signalHUI()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void Modline::hosted_signalYIncSet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Modline::hosted_signalXIncSet(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Modline::hosted_signalSetLEDMode(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Modline::hosted_signalCounter(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Modline::hosted_signalStoreToggleState(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
