// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef OSCINTERFACE_H
#define OSCINTERFACE_H

#include <QObject>
#include <QVariant>
#include <QtNetwork/QUdpSocket>

class OscInterface : public QObject
{
    Q_OBJECT
public:
    explicit OscInterface(QObject *parent = 0);

    QUdpSocket *socket;
    QString msgAddress;
    QString msgType;
    QByteArray msgVal;

    
signals:
    
public slots:
    void slotReadPendingDatagrams();
    
};

#endif // OSCINTERFACE_H
