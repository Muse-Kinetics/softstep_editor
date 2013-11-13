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
    sysExComposer(new SysExComposer(this)),
    presetInterface(new PresetInterface(this)),
    midiDeviceManager(new MidiDeviceManager(this)),
    midiParse(new MidiParse()),
    saveAsDialogForm(new Ui::saveAsDialogForm),
    deleteDialogForm(new Ui::deleteDialogForm),
    disableWidget(new QWidget(this))

{
    //Mainwindow Ui
    ui->setupUi(this);
    this->setWindowTitle("SoftStep Advanced Editor");
    this->setFixedSize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);
    QRect screenGeometry = QApplication::desktop()->availableGeometry();
    this->setGeometry(screenGeometry.width() / 4, 50, MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);

    disableWidget->hide();
    disableWidget->setGeometry(0,0,MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);
    disableWidget->setStyleSheet("background: rgba(0,0,0,200);");

    //Populates source and dest lists for modes
    slotPopulateSourceDestLists();

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i] = new Key(this, i);
    }

    //construct Nav Window
    navKey = new NavKey(this);

    //------------------------------------- Dialogs

    //Some bizarre positioning happening here to center these.... don't get it at the moment.

    //SaveAs
    saveAsDialogWidget = new QWidget(this);
    saveAsDialogWidget->hide();
    saveAsDialogWidget->setGeometry(MAINWINDOW_WIDTH/2 - saveAsDialogWidget->width()/2, MAINWINDOW_HEIGHT/2 - saveAsDialogWidget->height(), saveAsDialogWidget->width(), saveAsDialogWidget->height());
    //saveAsDialogWidget->setWindowFlags();
    saveAsDialogForm->setupUi(saveAsDialogWidget);

    //Delete
    deleteDialogWidget = new QWidget(this);
    deleteDialogWidget->hide();
    deleteDialogWidget->setGeometry(MAINWINDOW_WIDTH/2 - deleteDialogWidget->width(), MAINWINDOW_HEIGHT/2 - deleteDialogWidget->height(), deleteDialogWidget->width(), deleteDialogWidget->height());
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
    settingsWindow->slotReadSettings();
    settingsWindow->slotConnectElements();
    settingsWindow->slotRecallSettings();

    slotSetMode();

    //presetInterface->slotPopulatePresetMenu(ui->presetmenu);
    //presetInterface->slotRecallGlobal();
    slotSetPresetMenu(0);

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

void MainWindow::slotSetPresetMenu(int presetNum)
{
    ui->presetmenu->setCurrentIndex(presetNum);
    presetInterface->slotRecallPreset(presetNum);
}

void MainWindow::slotConnectElements()
{
    connect(ui->displayName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
}

void MainWindow::slotDisconnectElements()
{
    disconnect(ui->displayName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
}

void MainWindow::slotValueChanged()
{
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        //display name
        if(sender == ui->displayName)
        {
            emit signalStoreValue(QString("preset_displayname"), ui->displayName->text(), -1);
        }
    }
    emit signalCheckSavedState();
}

void MainWindow::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();

    ui->displayName->setText(preset.value(QString("preset_displayname")).toString());

    slotConnectElements();
}

void MainWindow::slotConnectInterfaces()
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////// Hosted / Standalone ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------------------------- Mode Switching
    connect(ui->mode, SIGNAL(clicked()), this, SLOT(slotSetMode()));
    //key modulation window modes
    for(int k = 0; k < 10; k++)
    {
        connect(this, SIGNAL(signalSetMode(QString)), key[k], SLOT(slotSetMode(QString)));
        /*for(int j = 0; j < 6; j++)
        {
            connect(this, SIGNAL(signalSetMode(QString)), key[k]->modline[j], SLOT(slotSetMode(QString)));
        }*/
    }
    //nav pad modes
    connect(this, SIGNAL(signalSetMode(QString)), navKey, SLOT(slotSetMode(QString)));
    /*for(int n = 0; n < 6; n++)
    {
        connect(this, SIGNAL(signalSetMode(QString)), navKey->navModline[n], SLOT(slotSetMode(QString)));
    }*/

    //-------------------------------------- Hosted MIDI
    connect(midiDeviceManager, SIGNAL(hosted_signalParsePacket(const MIDIPacket*)), midiParse, SLOT(slotParsePacket(const MIDIPacket*)), Qt::DirectConnection);

    //Midi Inputs from Settings
    for(int i=0; i < 8; i++)
    {
        //get signal from midi device manager
        connect(midiDeviceManager, SIGNAL(hosted_signalParseMidiInputPacket(const MIDIPacket*, QString)), &settingsWindow->midiInputLine[i], SLOT(slotReceiveInput(const MIDIPacket*, QString)),Qt::DirectConnection);

        //send signal from midi input lines to
        for(int k = 0; k < 10; k++)
        {
            connect(&settingsWindow->midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), &key[k]->dataCooker, SLOT(slotReceiveMidiInput(int,QString)));
        }
        connect(&settingsWindow->midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), &navKey->dataCooker, SLOT(slotReceiveMidiInput(int,QString)));
    }

    //Device menu population
    connect(midiDeviceManager, SIGNAL(hosted_signalPopulateDeviceMenus(QMap<QString,MIDIEndpointRef>)), this, SLOT(slotPopulateDeviceMenus(QMap<QString,MIDIEndpointRef>)));

    //Midi input menu population
    connect(midiDeviceManager, SIGNAL(hosted_signalMidiInputSourceMenus(QMap<QString,MIDIEndpointRef>)), settingsWindow, SLOT(slotPopulateInputMenus(QMap<QString,MIDIEndpointRef>)));

    for(int k = 0; k < 10; k++)
    {
        //Midi Parsing to each Key's data cooker
        connect(midiParse, SIGNAL(signalUpdateSensor(int,int)), &key[k]->dataCooker, SLOT(slotUpdateVals(int,int)), Qt::DirectConnection);

        for(int m = 0; m < 6; m++)
        {
            //Output signals listed in modline.h, slots in midiformat.h
            //Note Live
            connect(key[k]->modline[m], SIGNAL(hosted_signalNoteLive(QString,int,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotNoteLive(QString,int,int,int,int)));

            //Note Set
            connect(key[k]->modline[m], SIGNAL(hosted_signalNoteSet(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotNoteSet(QString,int,int,int)));

            //CCs
            connect(key[k]->modline[m], SIGNAL(hosted_signalCC(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotCC(QString,int,int,int)));

            //Bank
            connect(key[k]->modline[m], SIGNAL(hosted_signalBank(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotBank(QString,int,int,int)));

            //OSC goes here ----------------------

            //Program
            connect(key[k]->modline[m], SIGNAL(hosted_signalProgram(QString,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotProgram(QString,int,int)));

            //Pitch Bend
            connect(key[k]->modline[m], SIGNAL(hosted_signalPitchBend(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotPitchBend(QString,int,int,int)));

            //MMC
            connect(key[k]->modline[m], SIGNAL(hosted_signalMMC(QString,int,QString)),&midiDeviceManager->midiFormatOutput, SLOT(slotMMC(QString,int,QString)));

            //Aftertouch
            connect(key[k]->modline[m], SIGNAL(hosted_signalAftertouch(QString,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotAftertouch(QString,int,int)));

            //PolyAftertouch
            connect(key[k]->modline[m], SIGNAL(hosted_signalPolyAftertouch(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotPolyAftertouch(QString,int,int,int)));

            //Garageband goes here -------------
            //HUI goes here --------------------

        }

        //Alphanumeric midi out
        connect(&key[k]->alphaNumManager, SIGNAL(signalSendDisplayVals(QString,QList<MIDIPacket>)), &displaySink, SLOT(slotAddAlphaPacket(QString,QList<MIDIPacket>)),Qt::DirectConnection);

        //Led and Display midi out
        connect(&key[k]->ledManager, SIGNAL(signalSendLEDControl(QString,QList<MIDIPacket>)), &displaySink, SLOT(slotAddLEDPacket(QString,QList<MIDIPacket>)),Qt::DirectConnection);



        for(int l = 0; l < 10; l++)
        {
            connect(&key[k]->dataCooker, SIGNAL(signalThisKeyPressed(int)), &key[l]->alphaNumManager, SLOT(slotDisplayKeyName(int)));
            connect(&key[k]->dataCooker, SIGNAL(signalThisKeyOff(int)), &key[l]->alphaNumManager, SLOT(slotKeyOff(int)));
        }
    }
    //nav pad
    connect(midiParse, SIGNAL(signalUpdateSensor(int,int)), &navKey->dataCooker, SLOT(slotUpdateVals(int,int)), Qt::DirectConnection);
    for(int n = 0; n < 6; n++)
    {
        //output signals listed in navModline.h, slots in midiformat.h
        //Note Live
        connect(navKey->navModline[n], SIGNAL(hosted_signalNoteLive(QString,int,int,int,int)), &midiDeviceManager->midiFormatOutput, SLOT(slotNoteLive(QString,int,int,int,int)));

        //Note Set
        connect(navKey->navModline[n], SIGNAL(hosted_signalNoteSet(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotNoteSet(QString,int,int,int)));

        //CCs
        connect(navKey->navModline[n], SIGNAL(hosted_signalCC(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotCC(QString,int,int,int)));

        //Bank
        connect(navKey->navModline[n], SIGNAL(hosted_signalBank(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotBank(QString,int,int,int)));

        //OSC goes here ----------------------

        //Program
        connect(navKey->navModline[n], SIGNAL(hosted_signalProgram(QString,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotProgram(QString,int,int)));

        //Pitch Bend
        connect(navKey->navModline[n], SIGNAL(hosted_signalPitchBend(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotPitchBend(QString,int,int,int)));

        //MMC
        connect(navKey->navModline[n], SIGNAL(hosted_signalMMC(QString,int,QString)),&midiDeviceManager->midiFormatOutput, SLOT(slotMMC(QString,int,QString)));

        //Aftertouch
        connect(navKey->navModline[n], SIGNAL(hosted_signalAftertouch(QString,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotAftertouch(QString,int,int)));

        //PolyAftertouch
        connect(navKey->navModline[n], SIGNAL(hosted_signalPolyAftertouch(QString,int,int,int)),&midiDeviceManager->midiFormatOutput, SLOT(slotPolyAftertouch(QString,int,int,int)));

        //Garageband goes here -------------
        //HUI goes here --------------------
    }

    //Alphanumeric MIDI Out
    connect(&navKey->alphaNumManager, SIGNAL(signalSendDisplayVals(QString,QList<MIDIPacket>)), &displaySink, SLOT(slotAddAlphaPacket(QString,QList<MIDIPacket>)), Qt::DirectConnection);

    connect(&displaySink, SIGNAL(signalSendPacket(QString,MIDIPacket)), midiDeviceManager, SLOT(hosted_slotSendPacket(QString,MIDIPacket)),Qt::DirectConnection);

    //Hosted Key Pressed Source Routing, Nav Y sources
    for(int k = 0; k < 10; k++)
    {
        //Nav Y sources
        connect(&navKey->dataCooker, SIGNAL(signalNavDecade(int)), &key[k]->dataCooker, SLOT(slotReceiveNavDecade(int)));
        connect(&navKey->dataCooker, SIGNAL(signalNavY(int)), &key[k]->dataCooker, SLOT(slotReceiveNavY(int)));

        for(int l = 0; l < 10; l++)
        {
            connect(&key[k]->dataCooker, SIGNAL(signalThisKeyPressed(int)), &key[l]->dataCooker, SLOT(slotReceiveKeyPressed(int)));
        }
    }

    //Connected Indicator
    connect(midiDeviceManager, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));

    //connect the preset interface to the preset menu
    connect(presetInterface, SIGNAL(signalPresetMenu(int)), this, SLOT(slotSetPresetMenu(int)));


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////// Preset Storage, Recall //////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //--------------------------------------- Preset Recall

    //MainWindow -- display name
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), this, SLOT(slotRecallPreset(QVariantMap,QVariantMap)));

    //Keys
    for(int k = 0; k < 10; k++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k], SLOT(slotRecallShowModlines(QVariantMap,QVariantMap)));

        //Modlines
        for(int m = 0; m < 6; m++)
        {
            connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k]->modline[m], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));
        }
    }

    //Nav Pad
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), navKey, SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), navKey, SLOT(slotRecallShowModlines(QVariantMap,QVariantMap)));
    for(int i = 0; i < 6; i++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), navKey->navModline[i], SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
    }

    //Settings -- see settings class

    //Setlist
    connect(&navKey->dataCooker, SIGNAL(signalPresetChange(bool)), setlist, SLOT(slotChangePreset(bool)));
    connect(setlist, SIGNAL(signalRecallPresetFromSetlist(QString)), this, SLOT(slotRecallPresetFromSetlist(QString)));

    //--------------------------------------- Parameter Storage

    //Main Window -- display name
    connect(this, SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));
    connect(this, SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));

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
    connect(navKey, SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

    //save state
    connect(navKey, SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));

    for(int i = 0; i < 6; i++)
    {
        connect(navKey->navModline[i], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //save state
        connect(navKey->navModline[i], SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));
    }

    //Settings
    connect(ui->opensettings,SIGNAL(clicked()),settingsWindow,SLOT(slotOpenSettings()));

    //------------- Save, Save As, Revert, Delete
    //Save Button
    connect(ui->save, SIGNAL(clicked()), presetInterface, SLOT(slotSavePreset()));
    connect(ui->revert, SIGNAL(clicked()), presetInterface, SLOT(slotRevertPreset()));

    //Save Indicator
    connect(presetInterface, SIGNAL(signalPresetDirty(bool)), this, SLOT(slotDisplaySaveState(bool)));

    //Save As
    connect(ui->saveas, SIGNAL(clicked()), disableWidget, SLOT(show()));
    connect(ui->saveas, SIGNAL(clicked()), saveAsDialogWidget, SLOT(show()));
    connect(saveAsDialogForm->cancel, SIGNAL(clicked()), saveAsDialogWidget, SLOT(close()));
    connect(saveAsDialogForm->cancel, SIGNAL(clicked()), disableWidget, SLOT(close()));
    connect(saveAsDialogForm->save, SIGNAL(clicked()), this, SLOT(slotSaveAs()));
    connect(saveAsDialogForm->save, SIGNAL(clicked()), disableWidget, SLOT(close()));
    connect(saveAsDialogForm->save, SIGNAL(clicked()), saveAsDialogWidget, SLOT(close()));
    connect(this, SIGNAL(signalSaveAs(QString)), presetInterface, SLOT(slotSavePresetAs(QString)));
    connect(presetInterface, SIGNAL(signalAddRemovePreset()), this, SLOT(slotPopulatePresetMenu()));

    //Delete
    connect(ui->deletepreset, SIGNAL(clicked()), disableWidget, SLOT(show()));
    connect(ui->deletepreset, SIGNAL(clicked()), deleteDialogWidget, SLOT(show()));
    connect(deleteDialogForm->cancel, SIGNAL(clicked()), disableWidget, SLOT(close()));
    connect(deleteDialogForm->cancel, SIGNAL(clicked()), deleteDialogWidget, SLOT(close()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), presetInterface, SLOT(slotDeletePreset()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), disableWidget, SLOT(close()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), deleteDialogWidget, SLOT(close()));
    connect(deleteDialogForm->delete_2, SIGNAL(clicked()), this, SLOT(slotPopulatePresetMenu()));

    //setlist
    connect(ui->opensetlist, SIGNAL(clicked()), setlist, SLOT(slotShowSetlist()));
    connect(presetInterface, SIGNAL(signalPopulateSetlistMenus(QComboBox*)), setlist, SLOT(slotPopulateSetlistMenus(QComboBox*)));

    //Version Checking
    connect(midiDeviceManager, SIGNAL(signalProcessFwQueryReply(QByteArray)), sysExComposer, SLOT(slotGetConnectedVersion(QByteArray)));
    connect(sysExComposer, SIGNAL(signalSendBuildNums(int,QString, int, QString)), this, SLOT(slotReceiveVersions(int,QString, int, QString)));


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

    //----------------- Import / Export ------------------//
    QAction* exportPreset = new QAction("Export Preset", file);
    exportPreset->setObjectName("exportPreset");
    connect(exportPreset, SIGNAL(triggered()), presetInterface, SLOT(slotExportPreset()));
    file->addAction(exportPreset);

    QAction* importPreset = new QAction("Import Preset", file);
    importPreset->setObjectName("importPreset");
    connect(importPreset, SIGNAL(triggered()), presetInterface, SLOT(slotImportPreset()));
    file->addAction(importPreset);

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

void MainWindow::slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion)
{
    //aboutForm->found->setText(QString("%1 %2").arg(connectedVersion).arg(connected));

    qDebug() << QString("connected: %1,  embedded: %2").arg(connected).arg(embedded);

    if(connected != embedded)
    {
        //fwoodDialog->expected->setText(QString("%1 %2").arg(embeddedVersion).arg(embedded));
        //fwoodDialog->found->setText(QString("%1 %2").arg(connectedVersion).arg(connected));
        //disableWidget->show();
        //slotEnableDisableMenu();
        //fwoodDialogWidget->show();
        qDebug() << "_____ Your firmware version is out of date _____";
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
    setlist->slotRefreshSetlistMenus(ui->presetmenu);
}

void MainWindow::slotRecallPresetFromSetlist(QString presetName)
{
    qDebug() << "recall this preset from the setlist" << presetName;
    ui->presetmenu->setCurrentIndex(ui->presetmenu->findText(presetName));
}

void MainWindow::slotDisplaySaveState(bool dirty)
{
    if(dirty)
    {
        //qDebug() << "the preset is dirty";
        ui->save->setStyleSheet("QToolButton { background:red } QToolButton:pressed { background: rgb(230,0,134) }");
    }
    else
    {
        //qDebug() << "the preset is no longer dirty";
        ui->save->setStyleSheet("QToolButton { background-color:rgb(40,40,40) } QToolButton:pressed { background: rgb(230,0,134) }");
    }
}

void MainWindow::slotSetMode()
{
    //Check mode
    if(ui->mode->isChecked())
    {
        mode = "hosted";
    }
    else
    {
        mode = "standalone";
    }

    //----------------- Set child modes

    //Keys and Modlines
    for(int i = 0; i < 10; i++)
    {
        //Key Mode
        key[i]->slotSetMode(mode);

        for(int j = 0; j < 6; j++)
        {
            //Modline Mode
            key[i]->modline[j]->slotSetMode(mode);

            //Disconnect from slotValueChanged
            key[i]->modline[j]->slotDisconnectElements();

            //Populate modline menus according to mode-- doing this here to avoid having to embed source,dest, and table lists in modlines
            if(mode == "hosted")
            {
                key[i]->modline[j]->slotPopulateMenus(hostedSources, hostedDestinations, hostedTables);
            }
            else
            {
                key[i]->modline[j]->slotPopulateMenus(standaloneSources, standaloneDestinations, standaloneTables);
            }

            //Reconnect to slotValueChanged
            key[i]->modline[j]->slotConnectElements();
        }
    }

    //Nav Pad and Nav Modlines
    navKey->slotSetMode(mode);
    for(int i = 0; i < 6; i++)
    {
        //nav modlines
        navKey->navModline[i]->slotSetMode(mode);

        //disconnect from slotValueChanged
        navKey->navModline[i]->slotDisconnectElements();

        //populate modline menus according to mode
        if(mode == "hosted")
        {
            navKey->navModline[i]->slotPopulateMenus(hostedNavSources, hostedDestinations, hostedNavTables);
        }
        else
        {
            navKey->navModline[i]->slotPopulateMenus(standaloneNavSources, standaloneDestinations, standaloneTables);
        }

        //reconnect to slotValueChanged
        navKey->navModline[i]->slotConnectElements();
    }

    midiDeviceManager->slotSetMode(mode); //repopulation of device menus should happen here
    presetInterface->slotSetMode(mode);
    setlist->slotSetMode(mode);

    //Update paths to respective mode files
    presetInterface->slotUpdateJSONPath();
    setlist->slotUpdateJSONPath();

    //Read files
    presetInterface->slotReadJSON();
    setlist->slotReadSetlist();

    //Populate preset menu and setlist menu
    presetInterface->slotPopulatePresetMenu(ui->presetmenu); //Also calls setlist->slotPopulateSetlistMenus()

    //Set each setlist menu to correct item
    setlist->slotRefreshSetlistMenus(ui->presetmenu);

    //Recall Preset 1 in new mode
    //presetInterface->slotRecallPreset(0);

    //!!!!!!!!!!!!!!!!!! Preset recalled after port creation and device menu population in slotPopulateDeviceMenus
}


void MainWindow::slotPopulateDeviceMenus(QMap<QString, MIDIEndpointRef> externalDevices)
{
    qDebug() << "-------------------------------- populate device menus";
    QMap<QString, MIDIEndpointRef> standalone;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            //Disconnect from slotValueChanged
            key[i]->modline[j]->slotDisconnectElements();

            //Populate modline menus according to mode-- doing this here to avoid having to embed source,dest, and table lists in modlines
            if(mode == "hosted")
            {
                key[i]->modline[j]->hosted_slotPopulateDeviceMenu(externalDevices);
            }
            else
            {
                QMap<QString, MIDIEndpointRef> standaloneDevices;
                standaloneDevices.insert("SSCOM Port 1", NULL);
                standaloneDevices.insert("SoftStep Expander", NULL);

                key[i]->modline[j]->hosted_slotPopulateDeviceMenu(standaloneDevices);
            }

            //Reconnect to slotValueChanged
            key[i]->modline[j]->slotConnectElements();
        }
    }
    //nav pad
    for(int n = 0; n < 6; n++)
    {
        //disconnect from slotValueChanged
        navKey->navModline[n]->slotDisconnectElements();

        //populate modline menus according to mode-- doing this here to avoid having to embed source, dest, and table lists in modlines
        if(mode == "hosted")
        {
            navKey->navModline[n]->hosted_slotPopulateDeviceMenu(externalDevices);
        }
        else
        {
            QMap<QString, MIDIEndpointRef> standaloneDevices;
            standaloneDevices.insert("SSCOM PORT 1", NULL);
            standaloneDevices.insert("SoftStep Expander", NULL);

            navKey->navModline[n]->hosted_slotPopulateDeviceMenu(standaloneDevices);
        }

        //reconnect to slotValueChanged
        navKey->navModline[n]->slotConnectElements();
    }

    presetInterface->slotRecallPreset(0);
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
    //hostedDestinations.append("GarageBand");
    //hostedDestinations.append("HUI");
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
    standaloneSources.append("Other Key Pressed");

    standaloneSources.append("Modline 1 Output");
    standaloneSources.append("Modline 2 Output");
    standaloneSources.append("Modline 3 Output");
    standaloneSources.append("Modline 4 Output");
    standaloneSources.append("Modline 5 Output");
    standaloneSources.append("Modline 6 Output");

    //Standalone Nav Pad
    standaloneNavSources.append("None");

    standaloneNavSources.append("Nav Y Inc-Dec");

    standaloneNavSources.append("Pedal");
    standaloneNavSources.append("Init");

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

    //hostedSources.append("Wait Trig");
    hostedSources.append("Fast Trig");
    hostedSources.append("Dbl Trig");
    hostedSources.append("Long Trig");
    hostedSources.append("Off Trig");
    //hostedSources.append("Delta Trig");

    //hostedSources.append("Wait Trig Latch");
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

    //Hosted Nav Pad
    hostedNavSources.append("None");

    hostedNavSources.append("Nav Y");
    hostedNavSources.append("Nav Y Decade");
    hostedNavSources.append("Nav Y Inc-Dec");

    hostedNavSources.append("Nav N Foot On");
    hostedNavSources.append("Nav S Foot On");

    hostedNavSources.append("Nav N Foot Off");
    hostedNavSources.append("Nav S Foot Off");

    hostedNavSources.append("Nav N Trig");
    hostedNavSources.append("Nav N Trig Fast");
    hostedNavSources.append("Nav N Trig Dbl");
    hostedNavSources.append("Nav N Trig Long");

    hostedNavSources.append("Nav S Trig");
    hostedNavSources.append("Nav S Trig Fast");
    hostedNavSources.append("Nav S Trig Dbl");
    hostedNavSources.append("Nav S Trig Long");

    hostedNavSources.append("Pedal");

    hostedNavSources.append("MIDI A");
    hostedNavSources.append("MIDI B");
    hostedNavSources.append("MIDI C");
    hostedNavSources.append("MIDI D");
    hostedNavSources.append("MIDI E");
    hostedNavSources.append("MIDI F");
    hostedNavSources.append("MIDI G");
    hostedNavSources.append("MIDI H");

    //--------- Tables
    //Standalone
    standaloneTables.append("Linear");
    standaloneTables.append("Sine");
    standaloneTables.append("Cosine");
    standaloneTables.append("Exponential");
    standaloneTables.append("Logarithmic");

    standaloneTables.append("Toggle");
    //standaloneTables.append("Toggle 127");

    //Hosted
    hostedTables.append("Linear");
    hostedTables.append("Sine");
    hostedTables.append("Cosine");
    hostedTables.append("Exponential");
    hostedTables.append("Logarithmic");

    hostedTables.append("Toggle");
    //hostedTables.append("Toggle 127s");

    hostedTables.append("Counter Inc");
    hostedTables.append("Counter Dec");
    hostedTables.append("Counter Set");

    //Hosted Nav Pad
    hostedNavTables.append("Linear");
    hostedNavTables.append("Sine");
    hostedNavTables.append("Cosine");
    hostedNavTables.append("Exponential");
    hostedNavTables.append("Logarithmic");

    hostedNavTables.append("Toggle");
}

