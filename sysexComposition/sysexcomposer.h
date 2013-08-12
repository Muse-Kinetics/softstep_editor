// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SYSEXCOMPOSER_H
#define SYSEXCOMPOSER_H

#include <QWidget>
#include <QVariant>
#include <QFile>
#include <QCoreApplication>

class SysExComposer : public QWidget
{
    Q_OBJECT
public:
    explicit SysExComposer(QWidget *parent = 0);
    ~SysExComposer();

    QVariantMap defaultAttributeList;
    int       embeddedbuildNum, connectedBuildNum;
    QString   embeddedVersion, connectedVersion;
    unsigned char*  fwFile;
    int             fwFileSize;

    
signals:
    void    signalSendSysEx(QString messageID, unsigned char* message, int messageLength, QString destinationName);
    void    signalSendBuildNums(int,QString, int, QString);
    void    signalUpdateComplete();
    
public slots:
    void    slotComposeAttributeListFromPreset(QVariantMap);
    void    slotConstructDefaultAttributeList();
    void    slotGetConnectedVersion(QByteArray);
    void    slotGetEmbeddedVersion();
    void    slotUpdateFirmware();

    
};

#endif // SYSEXCOMPOSER_H
