// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef NAVMODLINE_H
#define NAVMODLINE_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>

#include "ui_navModlineForm.h"
#else
#include <Windows.h>
#include <MMSystem.h>
#include <Dbt.h>
#include "WindowsMidiTypes.h"

#include "ui_navModlineFormWin.h"

#endif //Q_OS_MAC

#include "stylesheets.h"
#include "tables.h"
#include "hosted/slewer.h"
#include "hosted/ledmanager.h"
#include "hosted/delay.h"



class NavModline : public QWidget
{
    Q_OBJECT
public:
    explicit NavModline(QWidget *parent = 0, int navInstanceNum = 0);

    enum
    {
        DEST_NONE,
        DEST_NOTE_SET,
        DEST_NOTE_LIVE,
        DEST_CC,
        DEST_BANK,
        DEST_PROGRAM,
        DEST_PITCH_BEND,
        DEST_MMC,
        DEST_OSC,
        DEST_AFTERTOUCH,
        DEST_POLY_AFTERTOUCH,
        DEST_X_INC,
        DEST_Y_INC
    };

    struct MOD_DEST
    {
        int index;
        int channel;
        int note;
        int velocity;
        int cc;
        int bankMSB;
        int mmcID;
        QString mmcFunction;
        QString oscRoute;
        QString outPortName;
    };

    StyleSheets stylesheets;
    Tables tablesClass;
    QRadioButton* displayLinkButton;

    QString mode;

    QWidget* formWidget;

    int navInstance;

    QString newSource;
    QString lastSource;
    int lastVal;
    int output;

    bool firstCall; //used to filter changes until first output routine called

    MOD_DEST modDest;

    //-------------- Hosted
    Slewer slewer;
    Delay delayer;

    //Transform variables
    bool enabled;
    float gain;
    int offset;
    QString table;
    int min;
    int max;
    int smooth;
    int delay;
    QString outputType;
    QString outputPort;
    QString thisModlineSource;

    bool resultState; //positive or negative? easy way to detect state changes

    //Graphical vars
    int raw;
    int result;
    int value;

    int lastNote;
    bool toggleOnMMC;

    LEDManager ledManager;

    int counter;

    bool toggleTable;
    bool tableToggleGate;

    bool initModeOnceCalled;
    int initModeVal;

signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();
    void signalModlineEnabled(QString parameterName);

    //-------------------------Hosted
    void signalSetSource(QString sourceName, int modlineNum);
    void hosted_signalSendModlineOutput(int modlineNum, int val);
    void hosted_signalSendParamDisplayOutput(int modlineNum, int val);

    //MIDI Output
    void hosted_signalNoteSet(QString port, int channel, int note, int velocity);
    void hosted_signalNoteLive(QString port,int channel, int oldNote, int newNote, int velocity);
    void hosted_signalCC(QString port, int channel, int ccNum, int ccVal);
    void hosted_signalBank(QString port, int channel, int msb, int lsb);
    void hosted_signalOSC(QString address, int val);
    void hosted_signalProgram(QString port, int channel, int program);
    void hosted_signalPitchBend(QString port, int channel, int lsb, int msb);
    void hosted_signalMMC(QString port, int id, QString function);
    void hosted_signalAftertouch(QString port, int channel, int val);
    void hosted_signalPolyAftertouch(QString port, int channel, int note, int val);
    //void hosted_signalGarageBand();
    //void hosted_signalHUI();
    void hosted_signalYIncSet(int);
    void hosted_signalXIncSet(int);

    //void hosted_signalSetLEDMode(int modlieNum, QString greenMode, QString redMode);

    void hosted_signalCounter(QString whatToDo, int val);

    //---------- State Recall
    void hosted_signalStoreToggleState(int modlineNum, bool state);

    void signalFixDropDownWidth(QComboBox*);

public slots:
    void slotConnectElements();
    void slotDisconnectElements();

    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);
    void slotTestValues(int value);
    void slotRecallDestinationMenu();
    void slotDeleteModline(int num, bool disable);
    void slotDisableModline(QString parameterName);

    void slotSetMode(QString m);
    void slotPopulateMenus(QStringList source, QStringList dest, QStringList table);

    //---------------------------- Hosted

    //Modline processing
    void slotTransformSource(int val, int modlineNum, QString source);
    void slotSetTransformValues();
    void slotStreamSourceData();
    void slotTable(int input);
    void slotCounterReturn(int i);
    void slotMinMax(int input);
    void slotSmooth(int input);
    void slotSmoothReturn(int input);
    void slotDelay(int input);
    void slotDelayReturn(int input);
    void slotOutputRoutine(int input);

    void hosted_slotOutputMidi(int outputVal);
    void hosted_slotPopulateDeviceMenu(QMap<QString, int> externalDevices);

    void slotDisplayVars();

    //------------------------ State Recall
    void slotStateRecallToggle(int modlineNum, bool state);

private:
    Ui::navModlineForm* navModlineForm;
};

#endif // NAVMODLINE_H
