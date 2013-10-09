// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef NAVKEY_H
#define NAVKEY_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#include "navmodline.h"
#include "ui_navKeyWindowForm.h"
#include "ui_navBoxForm.h"

class NavKey : public QWidget
{
    Q_OBJECT
public:
    explicit NavKey(QWidget *parent = 0);

    QWidget* navKeyWindowWidget;
    QWidget* navBoxWidget;

    //Ui Elements
    NavModline *navModline[6];
    
signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();
    
public slots:
    void slotOpenWindow();
    void slotConnectElements();
    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);

private:
    Ui::navBoxForm *navBoxForm;
    Ui::navKeyWindowForm *navKeyWindowForm;
    
};

#endif // NAVKEY_H
