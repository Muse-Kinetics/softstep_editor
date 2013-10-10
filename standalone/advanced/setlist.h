// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SETLIST_H
#define SETLIST_H

#include <QWidget>
#include <QtGui>

#include "ui_setlistForm.h"

class Setlist : public QWidget
{
    Q_OBJECT
public:
    explicit Setlist(QWidget *parent = 0);

    QString mode;

    QWidget* setlistWidget;
    
    QList<QComboBox *> menus;
    QList<QCheckBox *> checkBoxes;

    QStringList standaloneSetlist;
    QStringList hostedSetlist;

    bool eventFilter(QObject *obj, QEvent *event);
    //void mouseReleaseEvent(QMouseEvent* e);
    //void mousePressEvent(QMouseEvent* e);

    bool repopulating;

signals:
    
public slots:
    void slotMenuChanged(int menuNum);
    void slotCheckBoxClicked();
    void slotInitComponents();
    void slotShowSetlist();
    void slotPopulateMenus(QComboBox *presetMenu);
    void slotCompileSetlist();
    void slotRefreshSetlist(QComboBox* presetMenu);

    void slotSetMode(QString m);


private:
    Ui::setlistForm *setlistForm;
    
};


#endif // SETLIST_H
