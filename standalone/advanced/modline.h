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

class Modline : public QWidget
{
    Q_OBJECT
public:
    explicit Modline(QWidget *parent = 0, int modlineInstance = 0);

    int instance;
    
signals:
    
public slots:
    void slotConnectElements();
    void slotValueChanged();

private:
    Ui::modlineForm modlineForm;
};

#endif // MODLINE_H
