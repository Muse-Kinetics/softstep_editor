// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef STATERECALL_H
#define STATERECALL_H

#include <QObject>
#include <QMap>

class StateRecall : public QObject
{
    Q_OBJECT
public:
    explicit StateRecall(QObject *parent = 0);
    
private:

    QMap<QString, bool>     toggleStates[6];
    QMap<QString, int>      counterState;
    QMap<QString, int>      incDecState;

signals:
    void signalStateRecallToggles();
    void signalStateRecallCounter(int);
    void signalStateRecallIncDec(int);
    void signalStateRecallLeds();
    
public slots:
    void slotStoreToggleStates();
    void slotStoreCounterState(int);
    void slotStoreIncDecState(int);
    void slotStoreLedStates();

    void slotRecallState();
    
};

#endif // STATERECALL_H
