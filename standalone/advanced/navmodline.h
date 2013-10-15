// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef NAVMODLINE_H
#define NAVMODLINE_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#include "ui_navModlineForm.h"
#include "stylesheets.h"

class NavModline : public QWidget
{
    Q_OBJECT
public:
    explicit NavModline(QWidget *parent = 0, int navInstanceNum = 0);

    StyleSheets stylesheets;

    QString mode;

    QWidget* formWidget;

    int navInstance;
    
signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();
    
public slots:
    void slotConnectElements();
    void slotDisconnectElements();

    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);
    void slotRawResult();
    void slotRecallDestinationMenu();

    void slotSetMode(QString m);
    void slotSetMenus(QStringList source, QStringList dest, QStringList table);

private:
    Ui::navModlineForm* navModlineForm;
};

#endif // NAVMODLINE_H
