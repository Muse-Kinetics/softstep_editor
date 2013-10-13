// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <QDebug>
#include <QVariant>

#include "key.h"
#include "navkey.h"
#include "settings.h"
#include "setlist.h"
#include "presetinterface.h"
#include "mididevicemanager.h"
#include "sysexcomposer.h"

#include "ui_mainwindow.h"
#include "ui_saveAsForm.h"
#include "ui_deletePresetForm.h"

#include "hosted/midiparse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    SysExComposer* sysExComposer;
    PresetInterface* presetInterface;
    MidiDeviceManager* midiDeviceManager;
    MidiParse* midiParse;

    //--------------------------------- Mode Switching
    QString mode;

    QStringList standaloneDestinations;
    QStringList standaloneSources;
    QStringList standaloneTables;
    QStringList hostedDestinations;
    QStringList hostedSources;
    QStringList hostedTables;

    //Dialogs
    QWidget* saveAsDialogWidget;
    QWidget* deleteDialogWidget;

    //Menubar
    QMenuBar *menubar;
    QList<QAction *> actionList;

    //Ui Elements
    Key *key[10];
    NavKey *navKey;
    Settings *settingsWindow;
    Setlist *setlist;

signals:
    void signalSaveAs(QString presetName);
    void signalSetMode(QString mode);

public slots:
    void slotConnectInterfaces();
    void slotInitMenuBar();

    void slotConnected(bool);

    void slotSaveAs();
    void slotPopulatePresetMenu();
    void slotDisplaySaveState(bool);

    void slotSetMode();
    void slotPopulateSourceDestLists();

    void slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion);


private:
    Ui::MainWindow *ui;

    //Dialogs
    Ui::saveAsDialogForm* saveAsDialogForm;
    Ui::deleteDialogForm* deleteDialogForm;


};

#endif // MAINWINDOW_H
