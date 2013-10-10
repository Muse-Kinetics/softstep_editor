// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAINWINDOW_WIDTH 690
#define MAINWINDOW_HEIGHT 303

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    presetInterface(new PresetInterface(this)),
    midiDeviceManager(new MidiDeviceManager(this)),
    midiParse(new MidiParse()),
    saveAsDialogForm(new Ui::saveAsDialogForm),
    deleteDialogForm(new Ui::deleteDialogForm)

{
    //Mainwindow Ui
    ui->setupUi(this);
    this->setWindowTitle("SoftStep Advanced Editor");
    this->setFixedSize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);


    slotPopulateSourceDestLists();

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i] = new Key(this, i);
    }

    //construct Nav Window
    navKey = new NavKey(this);

    //------------------------------------- Dialogs
    //SaveAs
    saveAsDialogWidget = new QWidget();
    saveAsDialogForm->setupUi(saveAsDialogWidget);

    //Delete
    deleteDialogWidget = new QWidget();
    deleteDialogForm->setupUi(deleteDialogWidget);


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

    //connect nav window
    navKey->slotConnectElements();

    slotInitMenuBar();

    //Connect Settings Window Stuff
    settingsWindow->slotConnectElements();

    presetInterface->slotPopulatePresetMenu(ui->presetmenu);
    presetInterface->slotPopulateSetlistMenus();
    presetInterface->slotRecallPreset(1);
    //presetInterface->slotRecallGlobal();

#ifdef Q_OS_MAC
    midiDeviceManager->connectSource();
#else
    //Attempt to Connect SoftStep
    //mdm->devicePoller->start(1000);
#endif

    midiDeviceManager->slotHostedOnOff(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConnectInterfaces()
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////// Hosted / Standalone ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------------------------- Mode Switching
    for(int k = 0; k < 10; k++)
    {
        connect(this, SIGNAL(signalSetMode(QString)), key[k], SLOT(slotSetMode(QString)));
    }


    //-------------------------------------- Hosted MIDI
    connect(midiDeviceManager, SIGNAL(hosted_signalParsePacket(const MIDIPacket*)), midiParse, SLOT(slotParsePacket(const MIDIPacket*)));

    //Midi Parsing to each Key's data cooker
    for(int k = 0; k < 10; k++)
    {
        connect(midiParse, SIGNAL(signalUpdateSensor(int,int)), &key[k]->dataCooker, SLOT(slotUpdateVals(int,int)));
    }


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
    for(int i = 0; i < 6; i++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), navKey->navModline[i], SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
    }

    //Settings
    connect(presetInterface, SIGNAL(signalRecallGlobal(QVariantMap,QVariantMap)),settingsWindow,SLOT(slotRecallPreset(QVariantMap,QVariantMap)));


    //--------------------------------------- Parameter Storage

    //Keys
    for(int k = 0; k < 10; k++)
    {
        connect(key[k], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //save state
        connect(key[k], SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));

        //Modlines
        for(int m = 0; m < 6; m++)
        {
            connect(key[k]->modline[m], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

            //save state
            connect(key[k]->modline[m], SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));
        }
    }

    //Nav Pad
    for(int i = 0; i < 6; i++)
    {
        connect(navKey->navModline[i], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //save state
        //connect(navKey->navModline[i], SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));
    }

    //Settings
    connect(ui->opensettings,SIGNAL(clicked()),settingsWindow,SLOT(slotOpenSettings()));
    connect(settingsWindow, SIGNAL(signalStoreValue(QString,QVariant)), presetInterface, SLOT(slotStoreGlobal(QString,QVariant)));
    //connect(settingsWindow, SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));

    //------------- Save, Save As, Revert, Delete
    //Save Button
    connect(ui->save, SIGNAL(clicked()), presetInterface, SLOT(slotSavePreset()));
    connect(ui->revert, SIGNAL(clicked()), presetInterface, SLOT(slotRevertPreset()));

    //Save Indicator
    connect(presetInterface, SIGNAL(signalPresetDirty(bool)), this, SLOT(slotDisplaySaveState(bool)));

    //Save As
    connect(ui->saveas, SIGNAL(clicked()), saveAsDialogWidget, SLOT(show()));
    connect(saveAsDialogForm->cancel, SIGNAL(clicked()), saveAsDialogWidget, SLOT(close()));
    connect(saveAsDialogForm->save, SIGNAL(clicked()), this, SLOT(slotSaveAs()));
    connect(this, SIGNAL(signalSaveAs(QString)), presetInterface, SLOT(slotSavePresetAs(QString)));
    connect(presetInterface, SIGNAL(signalAddRemovePreset()), this, SLOT(slotPopulatePresetMenu()));

    //Delete
    connect(ui->deletepreset, SIGNAL(clicked()), deleteDialogWidget, SLOT(show()));
    connect(deleteDialogForm->cancel, SIGNAL(clicked()), deleteDialogWidget, SLOT(close()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), presetInterface, SLOT(slotDeletePreset()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), deleteDialogWidget, SLOT(close()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), this, SLOT(slotPopulatePresetMenu()));

    //preset menu
    //connect(ui->presetmenu, SIGNAL(currentIndexChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));

    //setlist
    connect(ui->opensetlist, SIGNAL(clicked()), setlist, SLOT(slotShowSetlist()));
    connect(presetInterface, SIGNAL(signalPopulateSetlistMenus(QComboBox*)), setlist, SLOT(slotPopulateMenus(QComboBox*)));
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

    menubar->addMenu(hardware);


    //-------------------------------------------------------------------------- Mode
    QMenu* mode = new QMenu("Mode");
    qDebug() << edit;
    edit->setObjectName("Mode");
    menubar->addMenu(edit);

    //Hosted
    QAction* hosted = new QAction("Hosted", mode);
    actionList.append(hosted);
    hosted->setObjectName("hosted");
    mode->addAction(hosted);
    connect(hosted, SIGNAL(triggered()), this, SLOT(slotSetMode()));

    //Standalone
    QAction* standalone = new QAction("Standalone", mode);
    actionList.append(standalone);
    standalone->setObjectName("standalone");
    mode->addAction(standalone);
    connect(standalone, SIGNAL(triggered()), this, SLOT(slotSetMode()));

    menubar->addMenu(mode);


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

void MainWindow::slotSaveAs()
{
    if(saveAsDialogForm->name->text() != "")
    {
        emit signalSaveAs(saveAsDialogForm->name->text());
        saveAsDialogWidget->close();
    }
    else
    {

    }
}

void MainWindow::slotPopulatePresetMenu()
{
    qDebug() << "add preset";
    presetInterface->slotPopulatePresetMenu(ui->presetmenu);
    setlist->slotRefreshSetlist(ui->presetmenu);
}

void MainWindow::slotDisplaySaveState(bool dirty)
{
    if(dirty)
    {
        //qDebug() << "the preset is dirty";
    }
    else
    {
        //qDebug() << "the preset is no longer dirty";
    }
}

void MainWindow::slotSetMode()
{
    mode = QObject::sender()->objectName();

    //Preset Iterface
    presetInterface->slotSetMode(mode);

    //Keys and Modlines
    for(int i = 0; i < 10; i++)
    {
        key[i]->slotSetMode(mode);

        for(int j = 0; j < 6; j++)
        {
            key[i]->modline[j]->slotDisconnectElements();

            if(mode == "hosted")
            {

                key[i]->modline[j]->slotSetMenus(hostedSources, hostedDestinations, hostedTables);
            }
            else
            {
                key[i]->modline[j]->slotSetMenus(standaloneSources, standaloneDestinations, standaloneTables);
            }

            key[i]->modline[j]->slotConnectElements();
        }
    }

    //Will reload JSON here
}

void MainWindow::slotPopulateSourceDestLists()
{
    //--------- Destinations
    //Standalone
    standaloneDestinations.append("None");
    standaloneDestinations.append("Note Set");
    standaloneDestinations.append("Note Live");
    standaloneDestinations.append("CC");
    standaloneDestinations.append("Bank");
    standaloneDestinations.append("Program");
    standaloneDestinations.append("Pitch Bend");
    standaloneDestinations.append("MMC");

    //Hosted
    hostedDestinations.append("None");
    hostedDestinations.append("Note Set");
    hostedDestinations.append("Note Live");
    hostedDestinations.append("CC");
    hostedDestinations.append("Bank");
    hostedDestinations.append("Program");
    hostedDestinations.append("Pitch Bend");
    hostedDestinations.append("MMC");
    hostedDestinations.append("OSC");
    hostedDestinations.append("Aftertouch");
    hostedDestinations.append("Poly Aftertouch");
    hostedDestinations.append("GarageBand");
    hostedDestinations.append("HUI");
    hostedDestinations.append("Y Inc Set");
    hostedDestinations.append("X Inc Set");

    //--------- Sources
    //Standalone
    standaloneSources.append("None");

    standaloneSources.append("Pressure Live");
    standaloneSources.append("X Live");
    standaloneSources.append("Y Live");

    standaloneSources.append("Pressure Latch");
    standaloneSources.append("X Latch");
    standaloneSources.append("Y Latch");

    standaloneSources.append("X Increment");
    standaloneSources.append("Y Increment");

    standaloneSources.append("Foot On");
    standaloneSources.append("Foot Off");
    standaloneSources.append("Dbl Trig");
    standaloneSources.append("Long Trig");

    standaloneSources.append("Pedal");
    standaloneSources.append("Init");

    standaloneSources.append("Nav Yx10 & Key");

    standaloneSources.append("Any Key Value");
    standaloneSources.append("This Key Value");
    standaloneSources.append("Prev Key Value");

    standaloneSources.append("Key 1 Pressed");
    standaloneSources.append("Key 2 Pressed");
    standaloneSources.append("Key 3 Pressed");
    standaloneSources.append("Key 4 Pressed");
    standaloneSources.append("Key 5 Pressed");
    standaloneSources.append("Key 6 Pressed");
    standaloneSources.append("Key 7 Pressed");
    standaloneSources.append("Key 8 Pressed");
    standaloneSources.append("Key 9 Pressed");
    standaloneSources.append("Key 0 Pressed");

    standaloneSources.append("Modline 1 Output");
    standaloneSources.append("Modline 2 Output");
    standaloneSources.append("Modline 3 Output");
    standaloneSources.append("Modline 4 Output");
    standaloneSources.append("Modline 5 Output");
    standaloneSources.append("Modline 6 Output");

    //Hosted
    hostedSources.append("None");

    hostedSources.append("Pressure Live");
    hostedSources.append("X Live");
    hostedSources.append("Y Live");

    hostedSources.append("Pressure Latch");
    hostedSources.append("X Latch");
    hostedSources.append("Y Latch");

    hostedSources.append("X Increment");
    hostedSources.append("Y Increment");

    hostedSources.append("Foot On");
    hostedSources.append("Foot Off");

    hostedSources.append("Top");
    hostedSources.append("Bottom");

    hostedSources.append("Wait Trig");
    hostedSources.append("Fast Trig");
    hostedSources.append("Dbl Trig");
    hostedSources.append("Long Trig");
    hostedSources.append("Off Trig");
    hostedSources.append("Delta Trig");

    hostedSources.append("Wait Trig Latch");
    hostedSources.append("Fast Trig Latch");
    hostedSources.append("Dbl Trig Latch");
    hostedSources.append("Long Trig Latch");

    hostedSources.append("Pedal");

    hostedSources.append("Nav Y");
    hostedSources.append("Nav Yx10 & Key");

    hostedSources.append("Any Key Value");
    hostedSources.append("This Key Value");
    hostedSources.append("Prev Key Value");

    hostedSources.append("Key 1 Pressed");
    hostedSources.append("Key 2 Pressed");
    hostedSources.append("Key 3 Pressed");
    hostedSources.append("Key 4 Pressed");
    hostedSources.append("Key 5 Pressed");
    hostedSources.append("Key 6 Pressed");
    hostedSources.append("Key 7 Pressed");
    hostedSources.append("Key 8 Pressed");
    hostedSources.append("Key 9 Pressed");
    hostedSources.append("Key 0 Pressed");
    hostedSources.append("Other Key Pressed");

    hostedSources.append("Modline 1 Output");
    hostedSources.append("Modline 2 Output");
    hostedSources.append("Modline 3 Output");
    hostedSources.append("Modline 4 Output");
    hostedSources.append("Modline 5 Output");
    hostedSources.append("Modline 6 Output");

    hostedSources.append("MIDI A");
    hostedSources.append("MIDI B");
    hostedSources.append("MIDI C");
    hostedSources.append("MIDI D");
    hostedSources.append("MIDI E");
    hostedSources.append("MIDI F");
    hostedSources.append("MIDI G");
    hostedSources.append("MIDI H");

    hostedSources.append("OSC A");
    hostedSources.append("OSC B");
    hostedSources.append("OSC C");
    hostedSources.append("OSC D");
    hostedSources.append("OSC E");
    hostedSources.append("OSC F");
    hostedSources.append("OSC G");
    hostedSources.append("OSC H");

    //--------- Tables
    //Standalone
    standaloneTables.append("Linear");
    standaloneTables.append("Sine");
    standaloneTables.append("Cosine");
    standaloneTables.append("Exponential");
    standaloneTables.append("Logarithmic");

    standaloneTables.append("Toggle");
    standaloneTables.append("Toggle 127");


    //Hosted
    hostedTables.append("Linear");
    hostedTables.append("Sine");
    hostedTables.append("Cosine");
    hostedTables.append("Exponential");
    hostedTables.append("Logarithmic");

    hostedTables.append("Toggle");
    hostedTables.append("Toggle 127s");

    hostedTables.append("Counter Inc");
    hostedTables.append("Counter Dec");
    hostedTables.append("Counter Set");
}
