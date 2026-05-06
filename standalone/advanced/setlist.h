// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SETLIST_H
#define SETLIST_H

#include <QWidget>
#include <QtGui>

//#include "qjson/src/parser.h"
//#include "qjson/src/serializer.h"

#ifdef Q_OS_MAC
#include "ui_setlistForm.h"
#else
#include "ui_setlistFormWin.h"
#endif



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
    QVariantMap setlist;

//    QJson::Parser       parser;
//    QJson::Serializer   serializer;

    QString jsonPath;
    QFile *jsonFile;
    bool ok;

    bool eventFilter(QObject *obj, QEvent *event);
    //void mouseReleaseEvent(QMouseEvent* e);
    //void mousePressEvent(QMouseEvent* e);

    bool repopulating;

    int currentSetlistSlot;
    bool setlistEmpty;

    QStringList getSetlistMap();

signals:
    void signalRecallPresetFromSetlist(QString presetName);
    void signalFixDropDownWidth(QComboBox*);
    void signalSetlistChanged(bool isEmpty);

public slots:
    void slotMenuChanged(int menuNum);
    void slotCheckBoxClicked();
    void slotInitComponents();
    void slotShowSetlist();
    void slotPopulateSetlistMenus(QComboBox *presetMenu);
    void slotCompileSetlist();
    void slotRefreshSetlistMenus(QComboBox* presetMenu);

    void slotSetMode(QString m);
    void slotUpdateJSONPath();
    void slotReadSetlist();
    void slotWriteSetlist();

    void slotChangePreset(bool prevOrNext);


private:
    Ui::setlistForm *setlistForm;
    
};


#endif // SETLIST_H
