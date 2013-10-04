// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Main window size constants (magic numbers == bad)
#define MAINWINDOW_WIDTH 840
#define MAINWINDOW_HEIGHT 327

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    presetInterface = new PresetInterface(this);
    midiDeviceManager = new MidiDeviceManager(this);

    //Mainwindow Ui
    ui->setupUi(this);
    this->setWindowTitle("SoftStep Advanced Editor");
    this->setFixedSize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i] = new Key(this, i);
    }

    //Construct Settings Window
    settingsWindow = new Settings(this);
    setlist = new Setlist(this);

    this->installEventFilter(this);

    slotConnectInterfaces();

    //Connect Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i]->slotConnectElements();
    }

    //Connect Settings Window Stuff
    settingsWindow->slotConnectElements();

    presetInterface->slotPopulateSetlistMenus();
    presetInterface->slotRecallPreset(1);
    presetInterface->slotRecallGlobal();

#ifdef Q_OS_MAC
    midiDeviceManager->connectSource();
#else
    //Attempt to Connect SoftStep
    //mdm->devicePoller->start(1000);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConnectInterfaces()
{
    //Connected Indicator
    connect(midiDeviceManager, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));

    //--------------------------------------- Preset Recall

    //Keys
    for(int k = 0; k < 10; k++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));

        //Modlines
        for(int m = 0; m < 6; m++)
        {
            connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k]->modline[m], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));
        }
    }

    //Nav Pad

    //Settings
    connect(presetInterface, SIGNAL(signalRecallGlobal(QVariantMap,QVariantMap)),settingsWindow,SLOT(slotRecallPreset(QVariantMap,QVariantMap)));


    //--------------------------------------- Parameter Storage

    //Keys
    for(int k = 0; k < 10; k++)
    {
        connect(key[k], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //Modlines
        for(int m = 0; m < 6; m++)
        {
            connect(key[k]->modline[m], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));
        }
    }

    //Nav Pad

    //Settings
    connect(ui->opensettings,SIGNAL(clicked()),settingsWindow,SLOT(slotOpenSettings()));
    connect(settingsWindow, SIGNAL(signalStoreValue(QString,QVariant)), presetInterface, SLOT(slotStoreGlobal(QString,QVariant)));

    //------------- Save, Save As, Revert, Delete
    //Save Button
    connect(ui->save, SIGNAL(clicked()), presetInterface, SLOT(slotSavePreset()));
    connect(ui->saveas, SIGNAL(clicked()), presetInterface, SLOT(slotSavePresetAs()));
    connect(ui->revert, SIGNAL(clicked()), presetInterface, SLOT(slotRevertPreset()));
    connect(ui->deletepreset, SIGNAL(clicked()), presetInterface, SLOT(slotDeletePreset()));

    //preset number box (this will be switched to a comboBox soon)
    //connect(ui->presetNumber, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));
    connect(ui->presetmenu, SIGNAL(currentIndexChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));

    //setlist
    connect(ui->opensetlist, SIGNAL(clicked()), setlist, SLOT(slotShowSetlist()));
    connect(presetInterface, SIGNAL(signalPopulateSetlistMenus(QVariantMap)), setlist, SLOT(slotPopulateMenus(QVariantMap)));
}

void MainWindow::slotInitMenuBar()
{
    menubar = new QMenuBar(0);

#ifdef Q_OS_MAC
#else
    menubar->setGeometry(0,0, this->width(), 20);
#endif


    //-------------------------------------------------------------------------- File
    QMenu* file = new QMenu("File");
    qDebug() << file;
    file->setObjectName("FileMenu");
    menubar->addMenu(file);


    //-------------------------------------------------------------------------- Edit
    QMenu* edit = new QMenu("Edit ");
    qDebug() << edit;
    edit->setObjectName("EditMenu");
    menubar->addMenu(edit);

    //Custom Preset
    QAction* useCustom = new QAction("Use Custom Preset", edit);
    actionList.append(useCustom);
    edit->addAction(useCustom);

    //Factory Preset Menu
    QMenu* factoryPreset = new QMenu("Use Factory Preset");
    edit->addMenu(factoryPreset);


    //-------------------------------------------------------------------------- Hardware
    QMenu* hardware = new QMenu("Hardware");
    hardware->setObjectName("HardwareMenu");

    //Reload Firmware
    QAction* updatefw = new QAction("Update/Reload Firmware...", hardware);
    actionList.append(updatefw);
    hardware->addAction(updatefw);

    //Settings
    QAction* settings = new QAction("Update/Reload Firmware...", hardware);
    actionList.append(settings);
    hardware->addAction(settings);

    menubar->addMenu(hardware);


    //-------------------------------------------------------------------------- Help
    QMenu* help = new QMenu("Help");
    help->setObjectName("HelpMenu");

    //About
    QAction* about = new QAction("About SoftStep Advanced Editor", help);
    actionList.append(about);
    help->addAction(about);

    //Doc
    QAction* doc = new QAction("Documentation...", help);
    actionList.append(doc);
    help->addAction(doc);

    menubar->addMenu(help);
}

void MainWindow::slotConnected(bool connection)
{
    if(connection)
    {
        ui->connectedLabel->setText("CONNECTED");
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(0,200,0,255);");
        //ui->update->setText("SAVE + SEND");
    }
    else
    {
        //ui->connectedFrame->setStyleSheet("border: 1px solid rgb(67,67,67);background: rgb(100,100,100); border-radius:6;");
        //ui->connectedLabel->setText("Not Connected");
        ui->connectedLabel->setText("NOT CONNECTED");
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(200,0,0,255);");
        //ui->update->setText("SAVE");
        //aboutForm->found->setText("Not Connected");
    }
}
