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
#include "settings.h"
#include "presetinterface.h"
#include "mididevicemanager.h"

#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    PresetInterface* presetInterface;
    MidiDeviceManager* midiDeviceManager;

    //Menubar
    QMenuBar *menubar;
    QList<QAction *> actionList;

    //Ui Elements
    Key *key[10];
    Settings *settingsWindow;

public slots:
    void slotConnectInterfaces();
    void slotInitMenuBar();

    void slotConnected(bool);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
