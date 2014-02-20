// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef TABLEINTERFACE_H
#define TABLEINTERFACE_H

#include <QWidget>
#include <QtGui>
#include <QLayout>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDebug>

#ifdef Q_OS_MAC
#include "ui_pedalLiveTableForm.h"
#else
#include "ui_pedalLiveTableFormWin.h"
#endif

class TableInerface : public QWidget
{
    Q_OBJECT
public:
    explicit TableInerface(QWidget *parent = 0);
    QObject* rootObject;

    QWidget *qmlWidget;

    QMap<QString, unsigned char *> tableMap;
    QList<QObject *> blocks;

signals:

public slots:
    void slotDrawTable(float x, float y, float width);
    void slotClearTable();
    void slotDrawLinear();


private:
    Ui::PedalLiveTableForm pedalLiveTableForm;
    
};

#endif // TABLEINERFACE_H
