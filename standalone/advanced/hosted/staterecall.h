// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef STATERECALL_H
#define STATERECALL_H

#include <QObject>
#include <QMap>

#include <CoreMIDI/CoreMIDI.h>

class StateRecall : public QObject
{
    Q_OBJECT
public:
    explicit StateRecall(QObject *parent = 0);

    bool                    initGate;
    bool                    parentIsNavPad;
    QString                 presetName;
    QMap<QString, bool>                 toggleStates[6];
    QMap<QString, int>                  counterState;
    QMap<QString, int>                  yIncDecState;
    QMap<QString, int>                  xIncDecState;
    QMap<QString, bool>                 ledStates[6];
    QMap< QString, QList <MIDIPacket> > lastMidiPacketList;

signals:
    //Toggle
    void signalStateRecallToggles(int modlineNum, bool state);

    //Counter
    void signalStateRecallCounter(int);

    //Inc-Dec
    void signalStateRecallIncDec(int);

    //LEDs
    void signalStateRecallLedStates(int modlineNum, bool state);
    void signalStateRecallLedLastPacketList(QList <MIDIPacket> pktlst);
    
public slots:
    //Init
    void slotInit(QStringList presetNames, int keyNum);

    //Toggle
    void slotStoreToggleStates(int modlineNum, bool state);

    //Counter
    void slotStoreCounterState(int val);

    //Inc-Dec
    void slotStoreIncDecState(int x, int y);

    //LEDs
    void slotStoreLedStates(int modlineNum, bool state);
    void slotStoreLedLastPacketList(QList <MIDIPacket> pktlst);

    //-------- Recall
    void slotRecallState(QString name);
    
};

#endif // STATERECALL_H
