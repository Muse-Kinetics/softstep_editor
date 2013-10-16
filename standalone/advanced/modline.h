// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MODLINE_H
#define MODLINE_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#ifdef Q_OS_MAC
#include <CoreMIDI/CoreMIDI.h>
#else

#endif //Q_OS_MAC

#include "ui_modlineForm.h"
#include "stylesheets.h"
#include "hosted/slewer.h"

class Modline : public QWidget
{
    Q_OBJECT
public:
    explicit Modline(QWidget *parent = 0, int keyInstanceNum = 0, int modlineInstanceNum = 0);

    StyleSheets stylesheets;

    QString mode;

    QWidget* formWidget;
    //QWidget* hosted_formWidget;

    int keyInstance;
    int modlineInstance;

    //-------------------- Hosted
    Slewer slewer;

    //Transform variables
    float gain;
    int offset;
    QString table;
    int min;
    int max;
    int smooth;
    int delay;
    QString outputType;
    QString outputPort;

    //Graphical vars
    int raw;
    int result;
    int value;

    
signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();

    //---------------------------- Hosted
    void signalSetSource(QString sourceName, int modlineNum);

    //Midi output
    void hosted_signalNoteSet(QString port, int channel, int note, int velocity);
    void hosted_signalNoteLive(QString port,int channel, int oldNote, int newNote, int velocity);
    void hosted_signalCC(QString port, int channel, int ccNum, int ccVal);
    void hosted_signalBank(QString port, int channel, int msb, int lsb);
    //void hosted_signalOSC();
    void hosted_signalProgram(QString port, int channel, int program);
    void hosted_signalPitchBend(QString port, int channel, int lsb, int msb);
    void hosted_signalMMC(QString port, int id, QString function);
    void hosted_signalAftertouch(QString port, int channel, int val);
    void hosted_signalPolyAftertouch(QString port, int channel, int note, int val);
    //void hosted_signalGarageBand();
    //void hosted_signalHUI();


public slots:
    void slotConnectElements();
    void slotDisconnectElements();

    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);
    void slotRawResult();
    void slotRecallDestinationMenu();

    void slotSetMode(QString m);
    void slotPopulateMenus(QStringList source, QStringList dest, QStringList table);

    //---------------------------- Hosted
    void slotTransformSource(int val, int modlineNum, QString source);
    void slotSetTransformValues();
    void slotStreamSourceData();
    int  slotTable(int input);
    int  slotMinMax(int input);
    void slotSmooth(int result);
    int  slotDelay(int input);

    void hosted_slotOutputMidi(int outputVal);
    void hosted_slotPopulateDeviceMenu(QMap<QString, MIDIEndpointRef> externalDevices);

    void slotDisplayVars();


private:
    Ui::modlineForm* modlineForm;
};

#endif // MODLINE_H
