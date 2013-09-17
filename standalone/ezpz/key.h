// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef KEY_H
#define KEY_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
#include <QVariant>

#ifdef Q_OS_MAC
#include "ui_keyform.h"
#else
#include "ui_keyformWin.h"
#endif


class Key : public QWidget
{
    Q_OBJECT
public:
    explicit Key(QWidget *parent = 0, int instanceNum = 0);

    int instance;
    QList<QCheckBox *> checkBoxes;

    QString source;
    QString table;

    bool isKeyOff();

    void keyPressEvent(QKeyEvent *);

signals:
    void signalStoreValue(QString name, QVariant value, int presetNum);
    
public slots:
    void slotConnectElements();
    void slotValueChanged();
    void slotUpdateSourceAndTable();
    void slotRecallPreset(QVariantMap preset, QVariantMap master);

private:
    Ui::keyForm keyForm;
};

#endif // KEY_H
