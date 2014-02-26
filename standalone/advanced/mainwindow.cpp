// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"
//#include "ui_mainwindowWin.h"

#define MAINWINDOW_WIDTH 690
#ifdef Q_OS_MAC
#define MAINWINDOW_HEIGHT 279
#else
#define MAINWINDOW_HEIGHT 299
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),

    saveAsDialogForm(new Ui::saveAsDialogForm),
    saveAsDialogWidget(new QWidget(this)),

    deleteDialogForm(new Ui::deleteDialogForm),
    deleteDialogWidget(new QWidget(this)),

    fwoodDialogForm(new Ui::FwoodDialog),
    fwoodDialogWidget(new QWidget(this)),

    fwProgressDialog(new Ui::FwProgressForm),
    fwProgressDialogWidget(new QWidget(this)),

    fwUpdateCompleteDialog(new Ui::FwUpdateCompleteForm),
    fwUpdateCompleteDialogWidget(new QWidget(this)),

    fwUpdateDialog(new Ui::UpdateFirmwareForm),
    fwUpdateDialogWidget(new QWidget(this)),

    aboutForm(new Ui::AboutForm),
    aboutFormWidget(new QWidget(this)),

    importOldDialog(new Ui::ImportOldPresetsForm),
    importOldDialogWidget(new QWidget(this)),

    importOldNotFoundDialog(new Ui::ImportOldNotFoundForm),
    importOldNotFoundDialogWidget(new QWidget(this)),

    modlineWarningDialog(new Ui::ModlineWarningForm),
    modlineWarningDialogWidget(new QWidget(this)),

    sysExComposer(new SysExComposer(this)),
    presetInterface(new PresetInterface(this)),
    copyPasteHandler(new CopyPasteHandler(presetInterface,this)),
    midiParse(new MidiParse()),
    disableWidget(new QWidget(this)),
    importOldPresetHandler(new ImportOldPresetHandler(presetInterface,0)),
    oscInterface(new OscInterface(0))
{
    midiDeviceManager = new MidiDeviceManager(this);

    //PList stuff
    QCoreApplication::setApplicationName("SoftStepAdvancedEditor");
    QCoreApplication::setOrganizationName("KeithMcMillenInstruments");
    QCoreApplication::setOrganizationDomain("keithmcmillen.com");

    sessionSettings = new QSettings(this);

    //Mainwindow Ui
    ui->setupUi(this);
    this->setWindowTitle("SoftStep Advanced Editor");
    this->setFixedSize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);
    QRect screenGeometry = QApplication::desktop()->availableGeometry();
    this->setGeometry(screenGeometry.width() / 4, 50, MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);

    ui->connectedLabel->setText("SOFTSTEP NOT CONNECTED");
    ui->connectedLabel->setFixedSize(162, 22);
    ui->connectedLabel->setToolTip("[ o_0 ]");
#ifdef Q_OS_MAC
    ui->connectedLabel->move(529, 81);
    ui->connectedLabel->setStyleSheet("font:10pt \"Futura\";color: rgba(200,0,0,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#else
    ui->connectedLabel->move(529, 100);
    ui->connectedLabel->setStyleSheet("font:7pt \"Futura\";color: rgba(200,0,0,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#endif

    disableWidget->hide();
    disableWidget->setGeometry(0,0,MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);
    disableWidget->setStyleSheet("background: rgba(0,0,0,200);");

    //Populates source and dest lists for modes
    slotPopulateSourceDestLists();

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
#ifdef Q_OS_MAC
#else
        QCoreApplication::processEvents();
#endif

        key[i] = new Key(this, i);
        key[i]->slotSetMainWindow(this);
    }

    //construct Nav Window
    navKey = new NavKey(this);

    connectedVersionString = "Not Connected";
    connectedVersionInt = -1;

    //------------------------------------- Dialogs
    //Some bizarre positioning happening here to center these.... don't get it at the moment.
    //SaveAs
    saveAsDialogWidget->hide();
    saveAsDialogWidget->setGeometry(this->width()/2 - saveAsDialogWidget->width()/2, this->height()/2 - saveAsDialogWidget->height(), saveAsDialogWidget->width(), saveAsDialogWidget->height());
    //saveAsDialogWidget->setWindowFlags();
    saveAsDialogForm->setupUi(saveAsDialogWidget);

    //Delete
    deleteDialogWidget->hide();
    deleteDialogWidget->setGeometry(this->width()/2 - deleteDialogWidget->width(), this->height()/2 - deleteDialogWidget->height(), deleteDialogWidget->width(), deleteDialogWidget->height());
    deleteDialogForm->setupUi(deleteDialogWidget);

    //Firmware Out of Date
    fwoodDialogWidget->hide();
    fwoodDialogWidget->setGeometry(this->width()/2 - fwoodDialogWidget->width(), this->height()/2 - fwoodDialogWidget->height(), fwoodDialogWidget->width(), fwoodDialogWidget->height());
    fwoodDialogForm->setupUi(fwoodDialogWidget);

    //Firmware Progress Bar
    fwProgressDialogWidget->hide();
    fwProgressDialog->setupUi(fwProgressDialogWidget);
    fwProgressDialogWidget->move(this->width()/2 - fwProgressDialogWidget->width()/2, this->height()/2 - fwProgressDialogWidget->height()/2);

    //Firmware Update Complete Dialog
    fwUpdateCompleteDialogWidget->hide();
    fwUpdateCompleteDialog->setupUi(fwUpdateCompleteDialogWidget);
    fwUpdateCompleteDialogWidget->move(this->width()/2 - fwUpdateCompleteDialogWidget->width()/2, this->height()/2 - fwUpdateCompleteDialogWidget->height()/2);

    //Firmware Update Confirm Dialog
    fwUpdateDialogWidget->hide();
    fwUpdateDialog->setupUi(fwUpdateDialogWidget);
    fwUpdateDialogWidget->move(this->width()/2 - fwUpdateDialogWidget->width()/2, this->height()/2 - fwUpdateDialogWidget->height()/2);

    //About Window
    aboutFormWidget->hide();
    aboutForm->setupUi(aboutFormWidget);
    aboutFormWidget->move(this->width()/2 - aboutFormWidget->width()/2, this->height()/2 - aboutFormWidget->height()/2);
    aboutForm->expected->setText(QString("%1").arg(sysExComposer->embeddedbuildNum));

    //Import Old Preset Dialog
    importOldDialogWidget->hide();
    importOldDialog->setupUi(importOldDialogWidget);
    importOldDialogWidget->move(this->width()/2 - importOldDialogWidget->width()/2, this->height()/2 - importOldDialogWidget->height()/2);

    //Import Old Not Found Dialog
    importOldNotFoundDialogWidget->hide();
    importOldNotFoundDialog->setupUi(importOldNotFoundDialogWidget);
    importOldNotFoundDialogWidget->move(this->width()/2 - importOldNotFoundDialogWidget->width()/2, this->height()/2 - importOldNotFoundDialogWidget->height()/2);

    //Modline Warning Dialog
    modlineWarningDialogWidget->hide();
    modlineWarningDialog->setupUi(modlineWarningDialogWidget);
    modlineWarningDialogWidget->move(this->width()/2 - modlineWarningDialogWidget->width()/2, this->height()/2 - modlineWarningDialogWidget->height()/2);


    //------------------------------------ Settings Window
    settingsWindow = new Settings(this);


    //------------------------------------ Setlist
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

    //typedef QList<unsigned char> UCharList;
    //qRegisterMetaType<UCharList>("UCharList");

    //connect(key[0]->dataCooker.pedal, SIGNAL(signalDrawTable(UCharList)), settingsWindow->pedalLiveTableInterface, SLOT(slotDrawTable(UCharList)), Qt::QueuedConnection);

    settingsWindow->slotLoadTableOnStartup();


    //Disable All context menus
    foreach(QWidget *widget, this->findChildren<QWidget *>())
    {
        widget->setContextMenuPolicy(Qt::NoContextMenu);
#ifdef Q_OS_MAC
        widget->setAttribute(Qt::WA_MacShowFocusRect, false);
#endif

        widget->installEventFilter(&scrollEventFilter);

    }

    //load fonts
    QString droidFont;
    QString futuraFont;
    QString fontPath = QCoreApplication::applicationDirPath();

#if defined(Q_OS_MAC) && !defined(QT_DEBUG)
    fontPath.remove(fontPath.length() - 5, fontPath.length());
    droidFont = QString("%1Resources/DroidSansMono.ttf").arg(fontPath);
    futuraFont = QString("%1Resources/Futura-Bold.ttf").arg(fontPath);

#else
    droidFont = "./resources/DroidSansMono.ttf";
    futuraFont = "./resources/Futura-Bold.ttf";

#endif
    QFontDatabase::addApplicationFont(droidFont);
    QFontDatabase::addApplicationFont(futuraFont);

#ifdef Q_OS_MAC
    midiDeviceManager->connectSource();
#else
    //Attempt to Connect SoftStep
    midiDeviceManager->devicePoller->start(500);
    //midiDeviceManager->hosted_slotRepopulateMidiSourceDests();
#endif



    midiDeviceManager->slotHostedOnOff(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
#ifdef Q_OS_MAC
    midiDeviceManager->ioGate = false;
#else
    midiDeviceManager->ioGate = false;
    midiDeviceManager->slotCloseMidiIn();
    midiDeviceManager->slotCloseMidiOut();
#endif

    qDebug() << "closing...";
    //presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
}

void MainWindow::slotSetPresetMenu(int presetNum)
{
    ui->presetmenu->setCurrentIndex(presetNum);
    presetInterface->slotRecallPreset(presetNum);
}

void MainWindow::slotConnectElements()
{
    connect(ui->displayName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));

    for(int k = 0; k < 10; k++)
    {
        connect(this, SIGNAL(signalSetPresetNameInKeys(QString)), key[k], SLOT(slotSetPresetName(QString)));
    }

    connect(this, SIGNAL(signalSetPresetNameInKeys(QString)), navKey, SLOT(slotSetPresetName(QString)));
}

void MainWindow::slotDisconnectElements()
{
    disconnect(ui->displayName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));

    for(int k = 0; k < 10; k++)
    {
        disconnect(this, SIGNAL(signalSetPresetNameInKeys(QString)), key[k], SLOT(slotSetPresetName(QString)));
    }

    disconnect(this, SIGNAL(signalSetPresetNameInKeys(QString)), navKey, SLOT(slotSetPresetName(QString)));
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
            emit signalSetPresetNameInKeys(ui->displayName->text());

            if(mode == "hosted")
            {
                navKey->alphaNumManager.slotPresetChangeDisplayPresetName();
            }
        }
    }
    emit signalCheckSavedState();
}

void MainWindow::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();

    ui->displayName->setText(preset.value(QString("preset_displayname")).toString());

    slotConnectElements();

    emit signalSetPresetNameInKeys(ui->displayName->text());
}

void MainWindow::slotConnectInterfaces()
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////// Hosted / Standalone ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------------------------- Mode Switching - children handled in slotSetMode
    connect(ui->mode, SIGNAL(clicked()), this, SLOT(slotSetMode()));

    //-------------------------------------- Hosted MIDI
#ifdef Q_OS_MAC
    connect(midiDeviceManager, SIGNAL(hosted_signalParsePacket(const MIDIPacket*)), midiParse, SLOT(slotParsePacket(const MIDIPacket*)), Qt::DirectConnection);
#else
    connect(midiDeviceManager, SIGNAL(hosted_signalParsePacket(const MIDIPacket*)), midiParse, SLOT(slotParsePacket(const MIDIPacket*)), Qt::DirectConnection);
#endif
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

        //Reset nav "once" display mode
        connect(&key[k]->dataCooker, SIGNAL(signalThisKeyOff(int)), &navKey->alphaNumManager, SLOT(slotCloseParamDisplay()));
    }

    connect(&navKey->dataCooker, SIGNAL(signalThisKeyOff(int)), &navKey->alphaNumManager, SLOT(slotKeyOff(int)));


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
    connect(&navKey->dataCooker, SIGNAL(signalThisKeyPressed(int)), &navKey->alphaNumManager, SLOT(slotDisplayKeyName(int)));


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
    connect(copyPasteHandler, SIGNAL(signalPresetMenu(int)), this, SLOT(slotSetPresetMenu(int)));
    connect(importOldPresetHandler, SIGNAL(signalPresetMenu(int)), this, SLOT(slotSetPresetMenu(int)));



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
    
    //For delete modline button -- so it will disable the modline
    for(int k = 0; k < 10; k++)
    {
        for(int m = 0; m < 6; m++)
        {
            connect(key[k], SIGNAL(signalDeleteModline(int,bool)), key[k]->modline[m], SLOT(slotDeleteModline(int,bool)));
        }
    }
    for(int i = 0; i < 6; i++)
    {
        connect(navKey, SIGNAL(signalDeleteModline(int,bool)), navKey->navModline[i], SLOT(slotDeleteModline(int,bool)));
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

            //modline warning
            connect(key[k]->modline[m], SIGNAL(signalModlineEnabled(QString)), presetInterface, SLOT(slotModlineWarning(QString)));
            connect(presetInterface, SIGNAL(signalDisableModline(QString)), key[k]->modline[m], SLOT(slotDisableModline(QString)));
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

        //modline warning
        connect(navKey->navModline[i], SIGNAL(signalModlineEnabled(QString)), presetInterface, SLOT(slotModlineWarning(QString)));
        connect(presetInterface, SIGNAL(signalDisableModline(QString)), navKey->navModline[i], SLOT(slotDisableModline(QString)));
    }

    //----------------------------------------------------------------------------------- Save, Save As, Revert, Delete
    //Save Button
    connect(ui->save, SIGNAL(clicked()), presetInterface, SLOT(slotSavePreset()));
    connect(ui->revert, SIGNAL(clicked()), presetInterface, SLOT(slotRevertPreset()));

    //Save Indicator
    connect(presetInterface, SIGNAL(signalPresetDirty(bool)), this, SLOT(slotDisplaySaveState(bool)));

    //Copy Paste - update paste availability based on whether anything has been copied
    connect(copyPasteHandler, SIGNAL(signalUpdatePasteAvailability()), this, SLOT(slotUpdatePasteAvailability()));
    for(int i = 0; i < 10; i++)
    {
        connect(key[i], SIGNAL(signalKeySelected(int)), this, SLOT(slotSelectedKey(int)));
        connect(key[i], SIGNAL(signalKeySelected(int)), copyPasteHandler, SLOT(slotSetCurrentKey(int)));
        connect(this, SIGNAL(signalSelectedKeyOutline(int,bool)), key[i], SLOT(slotSelectedKeyOutline(int,bool)));
    }

    //Save As
    connect(ui->saveas, SIGNAL(clicked()), disableWidget, SLOT(raise()));
    connect(ui->saveas, SIGNAL(clicked()), disableWidget, SLOT(show()));
    connect(ui->saveas, SIGNAL(clicked()), saveAsDialogWidget, SLOT(raise()));
    connect(ui->saveas, SIGNAL(clicked()), saveAsDialogWidget, SLOT(show()));
    connect(ui->saveas, SIGNAL(clicked()), saveAsDialogForm->name, SLOT(setFocus()));
    connect(saveAsDialogForm->cancel, SIGNAL(clicked()), saveAsDialogWidget, SLOT(close()));
    connect(saveAsDialogForm->cancel, SIGNAL(clicked()), disableWidget, SLOT(close()));
    connect(saveAsDialogForm->save, SIGNAL(clicked()), this, SLOT(slotSaveAs()));
    //connect(saveAsDialogForm->save, SIGNAL(clicked()), disableWidget, SLOT(close()));
    //connect(saveAsDialogForm->save, SIGNAL(clicked()), saveAsDialogWidget, SLOT(close()));
    connect(this, SIGNAL(signalSaveAs(QString)), presetInterface, SLOT(slotSavePresetAs(QString)));
    connect(presetInterface, SIGNAL(signalAddRemovePreset()), this, SLOT(slotPopulatePresetMenu()));
    connect(copyPasteHandler, SIGNAL(signalAddRemovePreset()), this, SLOT(slotPopulatePresetMenu()));
    connect(importOldPresetHandler, SIGNAL(signalAddRemovePreset()), this, SLOT(slotPopulatePresetMenu()));

    //Delete
    connect(ui->deletepreset, SIGNAL(clicked()), disableWidget, SLOT(raise()));
    connect(ui->deletepreset, SIGNAL(clicked()), disableWidget, SLOT(show()));
    connect(ui->deletepreset, SIGNAL(clicked()), deleteDialogWidget, SLOT(raise()));
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
    connect(sysExComposer, SIGNAL(signalSendBuildNums(int,QString, int, QString, int)), this, SLOT(slotReceiveVersions(int,QString, int, QString, int)), Qt::DirectConnection);






    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////// Settings ////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    connect(ui->opensettings,SIGNAL(clicked()),settingsWindow,SLOT(slotOpenSettings()));

    //Keys
    for(int i = 0; i < 10; i++)
    {
        //Globals
        connect(settingsWindow, SIGNAL(signalSetGlobalGain(float)), &key[i]->dataCooker, SLOT(slotSetGlobalGain(float)));
        connect(settingsWindow, SIGNAL(signalSetSensorResponse(int)), &key[i]->dataCooker, SLOT(slotSetSensorResponse(int)));
        connect(settingsWindow, SIGNAL(signalSetKeySafetyMode(int)), &key[i]->dataCooker, SLOT(slotSetKeySafetyMode(int)));

        connect(settingsWindow, SIGNAL(signalSetKeyOnThresh(int,int)), &key[i]->dataCooker, SLOT(slotSetOnThresh(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyOffThresh(int,int)), &key[i]->dataCooker, SLOT(slotSetOffThresh(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyXAccel(int,int)), &key[i]->dataCooker, SLOT(slotSetXAccel(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyXDeadZone(int,int)), &key[i]->dataCooker, SLOT(slotSetXDeadZone(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyYAccel(int,int)), &key[i]->dataCooker, SLOT(slotSetYAccel(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyYDeadZone(int,int)), &key[i]->dataCooker, SLOT(slotSetYDeadZone(int,int)));

        connect(settingsWindow, SIGNAL(signalStartCalibration()), key[i]->dataCooker.pedal, SLOT(slotStartCalibrate()));
        connect(settingsWindow, SIGNAL(signalResetCalibration()), key[i]->dataCooker.pedal, SLOT(slotResetCalibrate()));

        //Pedal Calibration file read/write
        connect(settingsWindow, SIGNAL(signalInitPedalTable(QByteArray)), key[i]->dataCooker.pedal, SLOT(slotInitPedalTable(QByteArray)));
    }

    //----- Pedal Nav Pad
    //connect(settingsWindow, SIGNAL(signalStartCalibration()), navKey->dataCooker.pedal, SLOT(slotStartCalibrate()));
    //connect(settingsWindow, SIGNAL(signalResetCalibration()), navKey->dataCooker.pedal, SLOT(slotResetCalibrate()));

    //Pedal Calibration file read/write
    connect(settingsWindow, SIGNAL(signalInitPedalTable(QByteArray)), navKey->dataCooker.pedal, SLOT(slotInitPedalTable(QByteArray)));

    //Pedal -- only connect key 0, we only need one data stream, while there are multiple instances of the Pedal class
    connect(key[0]->dataCooker.pedal, SIGNAL(signalLivePedalVal(int)), settingsWindow, SLOT(slotSetLiveValue(int)), Qt::QueuedConnection);
    connect(settingsWindow, SIGNAL(signalStopCalibration()), key[0]->dataCooker.pedal, SLOT(slotStopCalibrate()));
    connect(key[0]->dataCooker.pedal, SIGNAL(signalWriteTableToDisk(QByteArray)), settingsWindow, SLOT(slotWritePedalTableToDisk(QByteArray)));

    connect(key[0]->dataCooker.pedal, SIGNAL(signalResetOnZeroInput()), settingsWindow, SLOT(slotResetCalibration()), Qt::QueuedConnection);



    connect(midiDeviceManager, SIGNAL(signalStartStandaloneCalibration()), settingsWindow, SLOT(slotStartCalibrationStandAlone()));
    connect(midiDeviceManager, SIGNAL(signalStopStandaloneCalibration()), settingsWindow, SLOT(slotStopCalibrationStandAlone()));

    connect(settingsWindow, SIGNAL(signalTetherOnOffInStandalone(bool)), midiDeviceManager, SLOT(slotTetherOnOffInStandalone(bool)));

    //------------------------------- Nav
    connect(settingsWindow, SIGNAL(signalSetGlobalGain(float)), &navKey->dataCooker, SLOT(slotSetGlobalGain(float)));

    //N
    connect(settingsWindow, SIGNAL(signalSetNavNorthOnThresh(int)), &navKey->dataCooker, SLOT(slotSetOnThreshN(int)));
    connect(settingsWindow, SIGNAL(signalSetNavNorthOffThresh(int)), &navKey->dataCooker, SLOT(slotSetOffThreshN(int)));

    //S
    connect(settingsWindow, SIGNAL(signalSetNavSouthOnThresh(int)), &navKey->dataCooker, SLOT(slotSetOnThreshS(int)));
    connect(settingsWindow, SIGNAL(signalSetNavSouthOffThresh(int)), &navKey->dataCooker, SLOT(slotSetOffThreshS(int)));

    //E
    connect(settingsWindow, SIGNAL(signalSetNavEastOnThresh(int)), &navKey->dataCooker, SLOT(slotSetOnThreshE(int)));
    connect(settingsWindow, SIGNAL(signalSetNavEastOffThresh(int)), &navKey->dataCooker, SLOT(slotSetOffThreshE(int)));

    //W
    connect(settingsWindow, SIGNAL(signalSetNavWestOnThresh(int)), &navKey->dataCooker, SLOT(slotSetOnThreshW(int)));
    connect(settingsWindow, SIGNAL(signalSetNavWestOffThresh(int)), &navKey->dataCooker, SLOT(slotSetOffThreshW(int)));

    //Y-Accel
    connect(settingsWindow, SIGNAL(signalSetNavYIncAccel(int)), &navKey->dataCooker, SLOT(slotSetYAccel(int)));


    //------------- Scene Change on/off sysex command
    connect(settingsWindow, SIGNAL(signalSetSceneChanging(bool)), midiDeviceManager, SLOT(slotSceneChangeOnOff(bool)));
    connect(settingsWindow, SIGNAL(signalSetBacklight(bool)), midiDeviceManager, SLOT(slotBackLightOnOff(bool)));

    //----------------------------- OSC
    connect(settingsWindow, SIGNAL(signalSetOscAddress(int,QString)), oscInterface, SLOT(slotSetOSCAddressTags(int,QString)));
    connect(settingsWindow, SIGNAL(signalSetOscEnable(int,bool)), oscInterface, SLOT(slotSetInputEnable(int,bool)));
    connect(settingsWindow, SIGNAL(signalSetOscInPort(int)), oscInterface, SLOT(slotSetInputPort(int)));
    connect(settingsWindow, SIGNAL(signalSetOscIP(QString)), oscInterface, SLOT(slotSetOutputIPAddress(QString)));
    connect(settingsWindow, SIGNAL(signalSetOscOutPort(int)), oscInterface, SLOT(slotSetOutputPort(int)));

    //Osc live input vals
    connect(oscInterface, SIGNAL(signalSetOSCDisplayValue(int,int)), settingsWindow, SLOT(slotSetOSCDisplayValue(int,int)));

    //Connect Osc to keys, vice versa
    for(int i = 0; i < 10; i++)
    {
        connect(oscInterface, SIGNAL(signalSendOscMessageToSource(int,int)), &key[i]->dataCooker, SLOT(slotReceiveOscInput(int,int)));

        //Handles output from modlines
        for(int j = 0; j < 6; j++)
        {
            connect(key[i]->modline[j], SIGNAL(hosted_signalOSC(QString,int)), oscInterface, SLOT(slotWriteDatagram(QString,int)));
        }
    }

    //Connect Osc to nav pad
    connect(oscInterface, SIGNAL(signalSendOscMessageToSource(int,int)), &navKey->dataCooker, SLOT(slotReceiveOscInput(int,int)));

    //OSC output





    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////// Dialogs /////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Firmware Out of Date
    connect(fwoodDialogForm->cancel, SIGNAL(clicked()), fwoodDialogWidget, SLOT(close()));
    connect(fwoodDialogForm->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));
    connect(fwoodDialogForm->cancel, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    //connect(fwoodDialog->cancel, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //Firmware Update Dialog
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));
    //connect(fwUpdateDialog->cancel, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //Firmware Progress Bar
    connect(midiDeviceManager, SIGNAL(signalFwBytesLeft(int)), this, SLOT(slotUpdateFwProgressBar(int)));

    //Firmware Update Complete Dialog
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), fwUpdateCompleteDialogWidget, SLOT(close()));
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    //connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //About Ok Button
    connect(aboutForm->ok, SIGNAL(clicked()), aboutFormWidget, SLOT(close()));
    connect(aboutForm->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    //connect(aboutForm->ok, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //Import old Preset Dialoge
    connect(importOldPresetHandler, SIGNAL(signalPathFound()), importOldDialogWidget, SLOT(show()));
    connect(importOldPresetHandler, SIGNAL(signalPathFound()), importOldDialogWidget, SLOT(raise()));
    connect(importOldPresetHandler, SIGNAL(signalImportingComplete()), importOldDialogWidget, SLOT(hide()));
    connect(importOldPresetHandler, SIGNAL(signalPathNotFound()), importOldNotFoundDialogWidget, SLOT(show()));
    connect(importOldPresetHandler, SIGNAL(signalPathNotFound()), importOldNotFoundDialogWidget, SLOT(raise()));
    connect(importOldNotFoundDialog->ok, SIGNAL(clicked()), importOldNotFoundDialogWidget, SLOT(hide()));
    connect(importOldPresetHandler, SIGNAL(signalImportingPresetNum(QString)), importOldDialog->importMessage, SLOT(setText(QString)));

    //Modline Warning Dialog
    connect(presetInterface, SIGNAL(signalModlineWarning(QString)), this, SLOT(slotModlineWarning(QString)));
    connect(copyPasteHandler, SIGNAL(signalModlineWarning(QString)), this, SLOT(slotModlineWarning(QString)));
    connect(modlineWarningDialog->ok, SIGNAL(clicked()), modlineWarningDialogWidget, SLOT(hide()));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////// "Downloading" ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Update Presets Button
    connect(ui->update, SIGNAL(clicked()), this, SLOT(slotDisconnectUpdate()));
    //connect(ui->update, SIGNAL(clicked()), this, SLOT(slotUpdatePresets()));

    //Send SysEx from sysexComposer
    connect(sysExComposer, SIGNAL(signalSendSysEx(QString,unsigned char*, int,QString)), midiDeviceManager, SLOT(slotSendSysEx(QString,unsigned char*, int,QString)));

    //Standalone Download
    connect(midiDeviceManager, SIGNAL(signalSettingsSent()), sysExComposer, SLOT(slotSettingsSent()));
    connect(midiDeviceManager, SIGNAL(signalPresetsSent()), sysExComposer, SLOT(slotPresetsSent()));

    //Signal Update Complete
    connect(sysExComposer, SIGNAL(signalUpdateComplete()), this, SLOT(slotConnectUpdate()));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////         Menu Bar        /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::slotInitMenuBar()
{


#ifdef Q_OS_MAC
    menubar = new QMenuBar(0);
#else
    menubar = new QMenuBar(this);
    menubar->setGeometry(0,0, this->width(), 20);
    //menubar->setStyleSheet("background: white;");
    //menubar->setParent(ui->centralWidget);
#endif


    //-------------------------------------------------------------------------- File
    QMenu* file = new QMenu("File");
    //qDebug() << file;
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

    importOldPreset = new QAction("Import All Presets from V1.21", file);
    importOldPreset->setObjectName("importOldPresets");
    connect(importOldPreset, SIGNAL(triggered()), importOldPresetHandler, SLOT(slotImportOldPreset()));
    file->addAction(importOldPreset);

    menubar->addMenu(file);


    //-------------------------------------------------------------------------- Edit
    QMenu* edit = new QMenu("Edit ");
    //qDebug() << edit;
    edit->setObjectName("EditMenu");
    menubar->addMenu(edit);

    //----------------------------------------------------Clear Preset
    clearPresetAct = new QAction("Clear Preset", edit);
    actionList.append(clearPresetAct);
    edit->addAction(clearPresetAct);
    connect(clearPresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotClearPreset()));

    //----------------------------------------------------copy / paste
    copyPresetAct = new QAction("Copy Preset", edit);
    actionList.append(copyPresetAct);
    edit->addAction(copyPresetAct);
    copyPresetAct->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_C));
    connect(copyPresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotCopyPreset()));
    //copyPresetAct->setDisabled(true);

    pastePresetAct = new QAction("Paste Preset", edit);
    actionList.append(pastePresetAct);
    edit->addAction(pastePresetAct);
    pastePresetAct->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_V));
    connect(pastePresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotPastePreset()));
    pastePresetAct->setDisabled(true);

    pasteNewPresetAct = new QAction("Paste Preset to New", edit);
    actionList.append(pasteNewPresetAct);
    edit->addAction(pasteNewPresetAct);
    //pasteNewPresetAct->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_V));
    connect(pasteNewPresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotPasteNewPreset()));
    pasteNewPresetAct->setDisabled(true);

    copyKeyAct = new QAction("Copy Key", edit);
    actionList.append(copyKeyAct);
    edit->addAction(copyKeyAct);
    copyKeyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    connect(copyKeyAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotCopyKey()));
    copyKeyAct->setDisabled(true);

    pasteKeyAct = new QAction("Paste Key", edit);
    actionList.append(pasteKeyAct);
    edit->addAction(pasteKeyAct);
    pasteKeyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    connect(pasteKeyAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotPasteKey()));
    pasteKeyAct->setDisabled(true);

    //-------------------------------------------------------------------------- Hardware
    QMenu* hardware = new QMenu("Hardware");
    hardware->setObjectName("HardwareMenu");

    //Reload Firmware
    updatefw = new QAction("Update/Reload Firmware...", hardware);
    actionList.append(updatefw);
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(raise()));
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(updatefw, SIGNAL(triggered()), fwUpdateDialogWidget, SLOT(raise()));
    connect(updatefw, SIGNAL(triggered()), fwUpdateDialogWidget, SLOT(show()));
    //connect(updatefw, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    hardware->addAction(updatefw);
    menubar->addMenu(hardware);

    //-------------------------------------------------------------------------- Help
    QMenu* help = new QMenu("Help");
    help->setObjectName("HelpMenu");

    //About
    QAction* about = new QAction("About SoftStep Advanced Editor", help);
    actionList.append(about);
    connect(about, SIGNAL(triggered()), disableWidget, SLOT(raise()));
    connect(about, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(about, SIGNAL(triggered()), aboutFormWidget, SLOT(raise()));
    connect(about, SIGNAL(triggered()), aboutFormWidget, SLOT(show()));
    //connect(about, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    help->addAction(about);

    //Doc
    QAction* doc = new QAction("Documentation...", help);
    connect(doc, SIGNAL(triggered()), this, SLOT(slotOpenDoc()));
    actionList.append(doc);
    help->addAction(doc);

    help->addSeparator();

    //Tooltips
    if(sessionSettings->contains("toolTipsEnabled"))
    {
        if(sessionSettings->value("toolTipsEnabled").toBool())
        {
            toolTipsEnable = new QAction("Hide Tool Tips", file);
        }
        else
        {
            toolTipsEnable = new QAction("Show Tool Tips", file);
        }
    }
    else
    {
        sessionSettings->setValue("toolTipsEnabled", true);
        toolTipsEnable = new QAction("Hide Tool Tips", file);
    }

    connect(toolTipsEnable, SIGNAL(triggered()), this, SLOT(slotEnableDisableToolTips()));

    help->addAction(toolTipsEnable);

    menubar->addMenu(help);

    menubar->show();
}

void MainWindow::slotEnableDisableToolTips()
{
    if(sessionSettings->value("toolTipsEnabled").toBool())
    {
        toolTipsEnable->setText("Show Tool Tips");
        sessionSettings->setValue("toolTipsEnabled", false);
        scrollEventFilter.toolTipsOn = false;
    }
    else
    {
        toolTipsEnable->setText("Hide Tool Tips");
        sessionSettings->setValue("toolTipsEnabled", true);
        scrollEventFilter.toolTipsOn = true;
    }
}

void MainWindow::slotOpenDoc()
{
    //QFile *file = new QFile(":doc.txt");
    //file->open(QFile::ReadOnly);
    QDesktopServices::openUrl(QUrl("http://files.keithmcmillen.com/downloads/softstep/SoftStep_Manual_v2.0.pdf"));
    //qDebug() << (QLatin1String)file->readLine(0);
    //file->close();
}

void MainWindow::slotUpdatePasteAvailability()
{
    //enable and disable paste options depending on whether anything is copied
    if(copyPasteHandler->presetCopiedMap.size())
    {
        pastePresetAct->setDisabled(false);
        pasteNewPresetAct->setDisabled(false);
    }
    if(copyPasteHandler->keyCopiedMap.size())
    {
        pasteKeyAct->setDisabled(false);
    }
}

void MainWindow::slotModlineWarning(QString modlineWarningMessage)
{
    modlineWarningDialog->label->setText(modlineWarningMessage);
    modlineWarningDialogWidget->show();
    modlineWarningDialogWidget->raise();
}

void MainWindow::slotSelectedKey(int selectedKey)
{
    for(int i = 0; i < 10; i++)
    {
        if(selectedKey != i)
        {
            //qDebug() << "from mainwindow.cpp/slotSelectedKey - key/bool" << i << "false";
            emit signalSelectedKeyOutline(selectedKey, false);
        }
    }
    //qDebug() << "from mainwindow.cpp/slotSelectedKey - key/bool" << selectedKey << "true";
    emit signalSelectedKeyOutline(selectedKey, true);

    copyKeyAct->setDisabled(false);
}

void MainWindow::slotConnected(bool connection)
{
    qDebug() << "slot connected.";
    if(connection)
    {
        ui->connectedLabel->setText("SOFTSTEP CONNECTED");
        ui->connectedLabel->setFixedSize(138, 22);
        ui->connectedLabel->setToolTip("\\(^-^)/");
#ifdef Q_OS_MAC
        //ui->connectedLabel->move(553, 81);
        ui->connectedLabel->setStyleSheet("font:10pt \"Futura\";color: rgba(0,200,0,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#else
        //ui->connectedLabel->move(553, 100);
        ui->connectedLabel->setStyleSheet("font:7pt \"Futura\";color: rgba(0,200,0,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#endif
        //ui->update->setText("SAVE + SEND");
        aboutForm->found->setText(QString("%1").arg(connectedVersionInt));
        //presetInterface->connected = true;

        updatefw->setEnabled(true);

    }
    else
    {
        //ui->connectedFrame->setStyleSheet("border: 1px solid rgb(67,67,67);background: rgb(100,100,100); border-radius:6;");
        //ui->connectedLabel->setText("Not Connected");
        ui->connectedLabel->setText("SOFTSTEP NOT CONNECTED");
        ui->connectedLabel->setFixedSize(162, 22);
        ui->connectedLabel->setToolTip("[ o_0 ]");

#ifdef Q_OS_MAC
        ui->connectedLabel->move(529, 81);
        ui->connectedLabel->setStyleSheet("font:10pt \"Futura\";color: rgba(200,0,0,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#else
        ui->connectedLabel->move(529, 100);
        ui->connectedLabel->setStyleSheet("font:6pt \"Futura\";color: rgba(200,0,0,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#endif
        //ui->update->setText("SAVE");

        aboutForm->found->setText("Not Connected");
        //presetInterface->connected = false;

        updatefw->setEnabled(false);
    }
}

void MainWindow::slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion, int hardware)
{
    qDebug() << "slotReceiveVersions";
    connectedVersionString = connectedVersion;
    connectedVersionInt = connected;

    aboutForm->found->setText(QString("%1").arg(connected));

    for(int i = 0; i < 10; i++)
    {
        key[i]->dataCooker.isSS2 = (bool)hardware;
    }

    //First reiterate tether / standalone messages

    slotConnected(true);

    if(mode == "hosted")
    {
        //qDebug() << "message sent";
        midiDeviceManager->slotHostedOnOff(true);
    }
    else
    {
        midiDeviceManager->slotHostedOnOff(false);
    }


    if(connected != embedded)
    {

        qDebug() << "slotReceiveVersions unequal versions";
        QApplication::processEvents();

        fwoodDialogForm->expected->setText(QString("%1").arg(embedded));
        fwoodDialogForm->found->setText(QString("%1").arg(connected));
        disableWidget->show();
        //slotEnableDisableMenu();
        fwoodDialogWidget->show();
        qDebug() << "_____ Your firmware version is out of date _____";
        QApplication::processEvents();
    }
}

void MainWindow::slotSaveAs()
{
    bool matchExisting = FALSE;
    int numPresets = presetInterface->slotGetNumPresetsInJson();
    QString presetName;
    QVariantMap preset;

    //here I set the matchExisting variable to true or false depending on whether the preset name typed into the save dialoge matches an existing preset's name
    for(int i = 0; i < numPresets; i++)
    {
        preset = presetInterface->jsonMasterMap.value(presetInterface->slotGetPresetStringFromInt(i)).toMap();
        presetName = preset.value(QString("preset_name")).toString();
        //qDebug() << "SAVE AS: check preset names:" << presetName;
        if(saveAsDialogForm->name->text() == presetName || matchExisting)
        {
            matchExisting = TRUE;
        }
    }

    if(saveAsDialogForm->name->text() != "" && saveAsDialogForm->name->text() != "[EMPTY]" && !matchExisting)
    {
        emit signalSaveAs(saveAsDialogForm->name->text());
        saveAsDialogWidget->close();
        disableWidget->close();
    }
    else
    {
        //qDebug() << "nothing should happen here";
    }
}

void MainWindow::slotUpdateFirmware()
{
    fwoodDialogWidget->hide();
    QApplication::processEvents();
    fwProgressDialogWidget->raise();
    QApplication::processEvents();
    fwProgressDialogWidget->show();
    QApplication::processEvents();
    fwProgressDialog->progressBar->setMinimum(0);
    QApplication::processEvents();
#ifdef Q_OS_MAC
    fwProgressDialog->progressBar->setMaximum(sysExComposer->fwFileSize);
    QApplication::processEvents();
    sysExComposer->slotUpdateFirmware();
#else
    fwProgressDialog->progressBar->setMaximum(0);
    midiDeviceManager->slotCloseMidiOut();
    midiDeviceManager->slotCloseMidiIn();
    midiDeviceManager->fwUpdateRequested = true;

    syxutilProcess = new QProcess;
    syxutilProcess->setWorkingDirectory("./");
    syxutilProcess->start("syxutil.exe");
#endif
}

void MainWindow::slotUpdateFwProgressBar(int bytes)
{
    if(bytes != 0)
    {
        fwProgressDialog->progressBar->setValue(sysExComposer->fwFileSize - bytes);
    }
    else
    {
        fwProgressDialog->progressBar->setValue(sysExComposer->fwFileSize - bytes);
        QApplication::processEvents();
        fwProgressDialogWidget->close();
        QApplication::processEvents();
        fwUpdateCompleteDialogWidget->raise();
        QApplication::processEvents();
        fwUpdateCompleteDialogWidget->show();

        qDebug() << "fw update complete;";
    }
}

void MainWindow::slotPopulatePresetMenu()
{
    //qDebug() << "add preset";
    presetInterface->slotPopulatePresetMenu(ui->presetmenu);
    setlist->slotRefreshSetlistMenus(ui->presetmenu);
}

void MainWindow::slotRecallPresetFromSetlist(QString presetName)
{
    //Just uses menu change to initiate preset recall from setlist
    //qDebug() << "recall this preset from the setlist" << presetName;
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

#ifdef Q_OS_MAC
#else
    midiDeviceManager->hosted_slotRepopulateMidiSourceDests();
#endif

    //----------------- Set child modes

    //Settings
    settingsWindow->slotSetMode(mode);

    //Keys and Modlines
    for(int i = 0; i < 10; i++)
    {
        //Key Mode
        key[i]->slotSetMode(mode);

        //populate display menus in key windows
        key[i]->slotDisconnectElements();
        if(mode == "hosted")
        {
            key[i]->slotPopulateMenus(hostedDisplayModes);
        }
        else
        {
            key[i]->slotPopulateMenus(standaloneDisplayModes);
        }
        key[i]->slotConnectElements();

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
    //populate display mode menus in nav key window
    navKey->slotDisconnectElements();
    if(mode == "hosted")
    {
        navKey->slotPopulateMenus(hostedDisplayModes);
    }
    else
    {
        navKey->slotPopulateMenus(standaloneDisplayModes);
    }
    navKey->slotConnectElements();

    midiDeviceManager->slotSetMode(mode); //repopulation of device menus should happen here
    presetInterface->slotSetMode(mode);
    setlist->slotSetMode(mode);
    copyPasteHandler->slotSetMode(mode);
    importOldPresetHandler->slotSetMode(mode);
    pasteKeyAct->setDisabled(true);

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

    //Enable/Disable the update button
    if(mode == "hosted")
    {
        ui->update->setEnabled(false);
    }
    else
    {
        ui->update->setEnabled(true);
    }

    //Recall Preset 1 in new mode
    //presetInterface->slotRecallPreset(0);

    //!!!!!!!!!!!!!!!!!! Preset recalled after port creation and device menu population in slotPopulateDeviceMenus

    if(mode == "hosted")
    {
        QList<QString> presetNames;

        //--------- State Recall
        for(int i = 0; i < ui->presetmenu->count(); i++)
        {
            //qDebug() << "state recall check" << i << ": " << ui->presetmenu->itemText(i);
            presetNames.append(ui->presetmenu->itemText(i));
        }

        for(int k = 0; k < 10; k++)
        {
            //If init has been called previously, each instance of stateRecaller blocks re-initialization
            key[k]->stateRecaller.slotInit(presetNames, k);
        }
    }

    //Import Old Preset text change
    if(mode == "hosted")
    {
        importOldPreset->setText("Import Hosted Presets from V1.21");
    }
    else
    {
        importOldPreset->setText("Import Standalone Presets from V1.21");
    }

    presetInterface->slotRecallPreset(1);

    settingsWindow->slotEmitAllSettings();
}

void MainWindow::slotPopulateDeviceMenus(QMap<QString, MIDIEndpointRef> externalDevices)
{
    //qDebug() << "-------------------------------- populate device menus";
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
            standaloneDevices.insert("SSCOM Port 1", NULL);
            standaloneDevices.insert("SoftStep Expander", NULL);

            navKey->navModline[n]->hosted_slotPopulateDeviceMenu(standaloneDevices);
        }

        //reconnect to slotValueChanged
        navKey->navModline[n]->slotConnectElements();
    }

    presetInterface->slotRecallPreset(ui->presetmenu->currentIndex());
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

    //standaloneSources.append("Any Key Value");
    //standaloneSources.append("This Key Value");
    //standaloneSources.append("Prev Key Value");

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

    //hostedSources.append("Nav Y");
    hostedSources.append("Nav Yx10 & Key");

    //hostedSources.append("Any Key Value");
    //hostedSources.append("This Key Value");
    //hostedSources.append("Prev Key Value");

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

    //------------- Display Modes
    //Hosted
    hostedDisplayModes.append("None");
    hostedDisplayModes.append("Always");
    hostedDisplayModes.append("Once");
    hostedDisplayModes.append("Initial/Return");
    hostedDisplayModes.append("Immed Param");
    //Standalone
    standaloneDisplayModes.append("None");
    standaloneDisplayModes.append("Always");
    standaloneDisplayModes.append("Initial/Return");
    standaloneDisplayModes.append("Immed Param");

}

void MainWindow::slotUpdatePresets()
{
    //"preset_name" strings
    QStringList presetNameList = setlist->getSetlistMap();

    //Stores list of actual presets
    QList<QVariantMap> setlistMapList;

    //Iterate through strings in setlist
    foreach(QString string, presetNameList)
    {
        //If there's somethingn in the slot
        if(string != "[EMPTY]")
        {
            //Get it's preset number, get preset map from number, add it to our list of maps (setlist)
            setlistMapList.append(presetInterface->getPresetMap(ui->presetmenu->findText(string)));
        }
    }

    //Send list of preset maps to be "sysex-composed" and sent to board
    sysExComposer->slotComposeAttributeListFromSetlist(setlistMapList, settingsWindow->settings, settingsWindow->pedalValueListGraph); //Temporarily send empty settings map
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////       Key Lockout       /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::slotLockoutKeyPressedReleased(int keyNumber, bool pressedReleased)
{
    //qDebug() << "slotLockoutKeyPressedReleased called from MainWindow" << keyNumber << pressedReleased;

    for(int i = 0; i < 10; i++)
    {
        //If key sending message is being pressed
        if(pressedReleased) // pressed == TRUE
        {
            //If the keyNumber is not listed in current keys pressed
            if(!key[i]->dataCooker.lockoutKeysPressed.contains(keyNumber))
            {
                //Add it to our lockout list
                key[i]->dataCooker.lockoutKeysPressed.append(keyNumber);
            }
        }

        //If key sending message is being released
        else
        {
            //If key number is listed in current keys pressed (should always be the case)
            if(key[i]->dataCooker.lockoutKeysPressed.contains(keyNumber))
            {
                key[i]->dataCooker.lockoutKeysPressed.removeAt(key[i]->dataCooker.lockoutKeysPressed.indexOf(keyNumber));
            }

            //Trying to remove key from lockout list that is not present
            else
            {
                //qDebug() << "WARNING: trying to remove key from lockout list that is not present";
            }
        }

        //qDebug() << key[i]->dataCooker.lockoutKeysPressed;
    }
}

void MainWindow::slotDisconnectUpdate()
{
    ui->update->setEnabled(false);
    disconnect(ui->update, SIGNAL(clicked()), this, SLOT(slotDisconnectUpdate()));
    slotUpdatePresets();
}

void MainWindow::slotConnectUpdate()
{
    connect(ui->update, SIGNAL(clicked()), this, SLOT(slotDisconnectUpdate()));
    ui->update->setEnabled(true);
}
