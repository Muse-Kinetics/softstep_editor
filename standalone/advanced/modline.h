// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MODLINE_H
#define MODLINE_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#include "ui_modlineForm.h"
//#include "ui_modlineForm_hosted.h"
#include "stylesheets.h"

class Modline : public QWidget
{
    Q_OBJECT
public:
    explicit Modline(QWidget *parent = 0, int keyInstanceNum = 0, int modlineInstanceNum = 0);

    StyleSheets stylesheets;

    QWidget* formWidget;
    //QWidget* hosted_formWidget;

    int keyInstance;
    int modlineInstance;
    
signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();
    
public slots:
    void slotConnectElements();
    void slotDisconnectElements();

    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);
    void slotRawResult();

    void slotSetMenus(QStringList source, QStringList dest, QStringList table);

private:
    Ui::modlineForm* modlineForm;
    //Ui::modlineForm_hosted* hosted_modlineForm;
};

#endif // MODLINE_H
