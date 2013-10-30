// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef DISPLAYSINK_H
#define DISPLAYSINK_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#include <CoreMIDI/CoreMIDI.h>

class DisplaySink : public QObject
{
    Q_OBJECT
public:
    explicit DisplaySink(QObject *parent = 0);

    QTimer ledFIFOClock;
    QList<MIDIPacket> ledFIFOList;

    QTimer alphaFIFOClock;
    QList<MIDIPacket> alphaFIFOList;
    
signals:
    void signalSendPacket(QString port, MIDIPacket packet);
    
public slots:
    void slotAddLEDPacket(QString port, MIDIPacket packet);
    void slotAddAlphaPacket(QString port, MIDIPacket packet);

    void slotDrainLEDList();
    void slotDrainAlphaList();

    void slotCheckLEDList();
    void slotCheckAlphaList();
};

#endif // DISPLAYSINK_H
