// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"

#include <KMI_FwVersions.h>
#include <kmi_updates.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    aboutForm(new Ui::AboutForm)
{

    //Mainwindow Ui
    ui->setupUi(this);

    connected = false;


    //StyleSheets
    styleSheets = new StyleSheets();


    //Settings
    QCoreApplication::setApplicationName("SoftStep Basic Editor");
    QCoreApplication::setOrganizationName("Keith McMillen Instruments");
    QCoreApplication::setOrganizationDomain("keithmcmillen.com");

    // ---- FW update overhaul ----------------------------

    qDebug() << "System Locale: " << QLocale::system().name();

    // application version
    applicationVersion.resize(3);

    // pre bootloader app version was 2.04, revving to 2.1.0 for bootloader trojan
    applicationVersion[0] = 2;
    applicationVersion[1] = 1;
    applicationVersion[2] = 0;
    betaVersion = "A"; // leave blank for release

    // store the SoftStep device firmware version
    thisFw = QByteArray(reinterpret_cast<char*>(_fw_ver_softstep), sizeof(_fw_ver_softstep));

    // ---- end FW update overhaul ----------------------------


    // ******************************
    // KMI_Ports
    // ******************************

    // kmiPorts reports changes in MIDI i/o
    kmiPorts = new KMI_Ports(this);

#ifndef Q_OS_WIN
    //kmiPorts->slotCreateVirtualIn("SoftStep Editor");
    //kmiPorts->slotCreateVirtualOut("SoftStep Editor");
#endif

    // connect kmiPorts to our handler
    connect(kmiPorts, SIGNAL(signalPortUpdated(QString, uchar, uchar, int)),
            this, SLOT(slotMIDIPortChange(QString, uchar, uchar, int)));

    //qDebug() << "end connect";

    // ******************************
    // create KMI device handlers
    // ******************************

    SoftStep = new MidiDeviceManager(this, PID_SOFTSTEP2_OLD, "SoftStep");

    // setup bootloader/firmware images

    QString thisBlFile = QString(":/firmware/Softstep-99-bootloader-trojan-horse.syx");
    qDebug() << "thisBlFile: " << thisBlFile;

    if (!SoftStep->slotOpenBootloaderFile(thisBlFile))
    {
       slotCreateDialog("Error: Bootloader file not found!\n\nPlease re-install the SoftStep editor.");
    }

    QString thisFwFile = QString(":/firmware/Softstep_Firmware_v%1.%2.%3.syx")
            .arg(uchar(thisFw.at(0)))
            .arg(uchar(thisFw.at(1)))
            .arg(uchar(thisFw.at(2)));

    qDebug() << "thisFwFile: " << thisFwFile;

    if (!SoftStep->slotOpenFirmwareFile(thisFwFile))
    {
       slotCreateDialog("Error: Firmware file not found!\n\nPlease re-install the SoftStep editor.");
    }

    qDebug() << "Create MIDI THRU";
    // MIDI Thru for standalone/windows
    MIDIThru = new MidiDeviceManager(this, PID_AUX, "MIDI THRU");

    // ******************************
    // end KMI_Ports and device handlers
    // ******************************

    qDebug("Load application settings");
    settings = new QSettings();

    // ******************************
    // check for updates and set default save locations
    // ******************************
#ifdef VERSION_CHECK_ENABLED
    QString jsonVersionCheckURL = "https://files.keithmcmillen.com/products/softstep/editor/softwareVersionCheck.json";
    checkUpdates = new KMI_Updates(this, "SoftStep", settings, applicationVersion, jsonVersionCheckURL);
#endif // VERSION_CHECK_ENABLED

    // default file location
    const QString DEFAULT_DIR_KEY("default_dir");

    qDebug() << "Default file save location - pre: " << settings->value(DEFAULT_DIR_KEY).toString();

    // test if this is a directory
    QFileInfo check_file(settings->value(DEFAULT_DIR_KEY).toString());
    if (!check_file.exists() || !check_file.isDir() || settings->value(DEFAULT_DIR_KEY).toString().contains("Contents/MacOS"))
    {
        QString desktop = QStandardPaths::locate(QStandardPaths::DesktopLocation, QString(), QStandardPaths::LocateDirectory);
        qDebug() << "Desktop: " << desktop;
        settings->setValue(DEFAULT_DIR_KEY, desktop);     // if key doesn't exist, set it to desktop
    }

    qDebug() << "Default file save location - post: " << settings->value(DEFAULT_DIR_KEY).toString();

    // ******************************

    //Construct Children
    qDebug("PresetInterface");
    presetInterface = new PresetInterface(this);

    qDebug("SysExComposer");
    sysExComposer = new SysExComposer(0);

    qDebug("copyPasteHandler");
    copyPasteHandler = new CopyPasteHandler(presetInterface,this);

    qDebug("EventFilter");
    this->installEventFilter(this);

    //QList<QWidget*> widgets = findChildren<QWidget*>();
    foreach (QWidget* widget, findChildren<QWidget*>())
    {
        widget->installEventFilter(this);
        widget->setAttribute(Qt::WA_MacShowFocusRect, false);
    }

#ifdef Q_OS_MAC
    //Disable system focus boxt on Mac
    ui->backlight->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->sensitivity->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->midiChannel->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->navPadCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->pedalCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->currentPreset->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->displayName->setAttribute(Qt::WA_MacShowFocusRect, false);
#endif

    //Construct Keys
    for(int i = 1; i < 11; i++)
    {
        key[i-1] = new Key(ui->centralWidget, i);
    }



    //Coverup for factory presets
    factoryPresetCoverWidget1 = new QWidget(ui->centralWidget);
    factoryPresetCoverWidget1->hide();
    factoryPresetCoverWidget1->resize(this->size());
    factoryPresetCoverWidget1->setStyleSheet("QWidget{ background: rgba(0,0,0,200); }");

    factoryPresetNameLabel = new QLabel(ui->centralWidget);
    factoryPresetNameLabel->hide();
    factoryPresetNameLabel->resize(this->size());
    factoryPresetNameLabel->setAlignment(Qt::AlignCenter);
#ifdef Q_OS_MAC
    factoryPresetNameLabel->setStyleSheet("font: 36pt \"Futura\"; color: white");
#else
    factoryPresetNameLabel->setStyleSheet("font: 26pt \"Futura\"; color: white");
#endif

    //Coverup for dialogs
    disableWidget = new QWidget(this);
    disableWidget->hide();
    disableWidget->resize(this->size());
    disableWidget->setStyleSheet("QWidget{ background: rgba(0,0,0,200); }");

 
    aboutFormWidget = new QWidget(this);
    aboutFormWidget->hide();
    aboutForm->setupUi(aboutFormWidget);
    aboutFormWidget->move(this->width()/2 - aboutFormWidget->width()/2, this->height()/2 - aboutFormWidget->height()/2);

    // Firmware update Window
    fwUpdateWindow = new fwUpdate(this, "SoftStep", applicationFirmwareVersionString());

    this->installEventFilter(this);

    slotInitMenuBar();

    slotConnectInterfaces();


    // apply stylesheets

    //Load stylesheet and set initial text for connectedLabel
    ui->connectedLabel->setText("NOT CONNECTED");
#ifdef Q_OS_MAC
    ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(200,0,0,255);");
#else
    ui->connectedLabel->setStyleSheet("font:6pt \"Futura\";color: rgba(200,0,0,255);");
#endif

    //StyleSheets for primary pushbuttons
    blueStyleFile = new QFile(":/stylesheets/fwUpdateStyles_lightBlue.qss");
    blueStyleFile->open(QFile::ReadOnly);
    blueStyleString = QLatin1String(blueStyleFile->readAll());

    //StyleSheets for secondary pushbuttons
    grayStyleFile = new QFile(":/stylesheets/GrayButtonStyleSheet.qss");
    grayStyleFile->open(QFile::ReadOnly);
    grayStyleString = QLatin1String(grayStyleFile->readAll());

    // fwupdate stylesheets
#ifdef Q_OS_MAC

    fwUpdateStylesFile = new QFile("://resources/stylesheets/fwUpdateStyles_lightBlue.qss");
#else
    fwUpdateStylesFile = new QFile(":/stylesheets/fwUpdateStyles_SoftStep_WIN.qss");
#endif
    if (fwUpdateStylesFile->open(QFile::ReadOnly))
    {
        fwUpdateStylesString = QLatin1String(fwUpdateStylesFile->readAll());
        fwUpdateWindow->setStyleSheet(fwUpdateStylesString);
    }
    else
    {
        qDebug() << "ERROR - could not find fwUpdate style file: " << fwUpdateStylesFile;
    }

    //Load preset from last app session
    presetInterface->slotRecallPreset(1);
    //ui->currentPreset->setValue(settings->value("lastPreset").toInt());
    ui->currentPreset->setFocus();


    //Connect Key Elements
    for(int i = 1; i < 11; i++)
    {
        key[i-1]->slotConnectElements();
    }

    //menubar->actions().at(0)->setEnabled(false);

    //Disable All context menus
    foreach(QWidget *widget, this->findChildren<QWidget *>())
    {
        widget->setContextMenuPolicy(Qt::NoContextMenu);
    }

    foreach(QAbstractSpinBox *spinbox, this->findChildren<QAbstractSpinBox *>())
    {
        spinbox->installEventFilter(&scrollEventFilter);
    }

    //load fonts
    QString droidFont;
    QString futuraFont;
    QString futuraBFont;
    QString corbelFont;
    QString corbelBFont;
    QString fontPath = QCoreApplication::applicationDirPath();

#if defined(Q_OS_MAC) && !defined(QT_DEBUG)
// If this is uncommented, release builds get the wrong font.
//    fontPath.remove(fontPath.length() - 5, fontPath.length());
//    droidFont = QString("%1Resources/DroidSansMono.ttf").arg(fontPath);
//    futuraFont = QString("%1Resources/Futura-Bold.ttf").arg(fontPath);

//    QFontDatabase::addApplicationFont(droidFont);
//    QFontDatabase::addApplicationFont(futuraFont);
#elif !defined(Q_OS_MAC)
    droidFont = "./resources/DroidSansMono.ttf";
    futuraFont = "./resources/futura-normal.ttf";
    futuraBFont = "./resources/Futura-Bold.ttf";
    corbelFont = "./resources/corbel.ttf";
    corbelBFont = "./resources/corbelb.ttf";

    QFontDatabase::addApplicationFont(droidFont);
    QFontDatabase::addApplicationFont(futuraFont);
    QFontDatabase::addApplicationFont(futuraBFont);
    QFontDatabase::addApplicationFont(corbelFont);
    QFontDatabase::addApplicationFont(corbelBFont);
#else
    droidFont = "./resources/DroidSansBono.ttf";
    futuraFont = "./resources/Futura-Bold.ttf";

    QFontDatabase::addApplicationFont(droidFont);
    QFontDatabase::addApplicationFont(futuraFont);
#endif

    // start polling at 100ms intervals
    kmiPorts->devicePoller->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotCreateDialog(QString dialogText)
{
    QDialog *msgBox = new QDialog(this);
    msgBox->setMinimumSize(300, 100);
    msgBox->setFixedSize(300, 100);

    QPoint centerparent(
                this->x() + ((this->frameGeometry().width() - msgBox->frameGeometry().width()) /2),
                this->y() + ((this->frameGeometry().height() - msgBox->frameGeometry().height()) /2));

    msgBox->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    msgBox->move(centerparent);


    msgBox->setStyleSheet("QWidget{background: rgba(100,100,100, 255); border-color:black; border:5px}");

    QLabel* text = new QLabel(dialogText, msgBox, Qt::WindowFlags());
    text->setAlignment(Qt::AlignCenter);
    text->setMinimumSize(300, 50);
    text->setFixedSize(300, 50);
    text->move(0, 10);

#ifdef Q_OS_MAC // EB attempt to make this cross platform
    text->setStyleSheet("font: 12pt;");
#else
    text->setStyleSheet("font: 10pt;");
#endif

    QPushButton* okButton = new QPushButton(msgBox);
    okButton->setStyleSheet(grayStyleString);
    okButton->setText("Ok");
    okButton->setGeometry(QRect(140, 60, 70, 28));
    connect(okButton, SIGNAL(clicked()), msgBox, SLOT(close()));

    msgBox->exec();
}

void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    if((keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) && ui->backlight->hasFocus() && !disableWidget->isVisible())
    {
        ui->backlight->setChecked(!ui->backlight->isChecked());
    }
}

void MainWindow::closeEvent(QCloseEvent *)
{
#ifdef Q_OS_MAC

#else
    SoftStep->slotCloseMidiIn(SIGNAL_NONE);
    SoftStep->slotCloseMidiOut(SIGNAL_NONE);
#endif
    qDebug() << "closing...";
    //presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
}

void MainWindow::slotConnectInterfaces()
{
    // ---- midi and firmware update overhaul --------------

    // connect dropdowns and connection status to MIDI aux ports
    connect(ui->midi_thru, SIGNAL(activated(int)), this, SLOT(slotUpdateMIDIThru()));
    connect(SoftStep, SIGNAL(signalConnected(bool)), this, SLOT(slotUpdateMIDIThru()));

    // remember last selected MIDI aux port
    MIDI_THRU_KEY = "midi_thru_port";
    qDebug() << "connected midi thru port";

    // MIDI

    // connect firmware detection
    connect(SoftStep, SIGNAL(signalFirmwareDetected(MidiDeviceManager*, bool)), this, SLOT(slotFirmwareDetected(MidiDeviceManager*, bool)));

    // connect firmware update window and midi device manager controls and messaging
    connect(fwUpdateWindow, SIGNAL(signalRequestFwUpdate()), SoftStep, SLOT(slotRequestFirmwareUpdate()));                      // request fw
    connect(SoftStep, SIGNAL(signalFwConsoleMessage(QString)), fwUpdateWindow, SLOT(slotAppendTextToConsole(QString)));         // messaging
    connect(SoftStep, SIGNAL(signalFwProgress(int)), fwUpdateWindow, SLOT(slotUpdateProgressBar(int)));                         // console
    connect(SoftStep, SIGNAL(signalFirmwareUpdateComplete(bool)), fwUpdateWindow, SLOT(slotFwUpdateComplete(bool)));            // Update Complete
    connect(fwUpdateWindow, SIGNAL(signalFwUpdateSuccess()), SoftStep, SLOT(slotFirmwareUpdateReset()));                        // stop timeout timers
    connect(fwUpdateWindow, SIGNAL(signalFwUpdateSuccessCloseDialog(bool)), this, SLOT(slotFwUpdateSuccessCloseDialog(bool)));  // close fw dialog and connect

    // handle device unexpectedly in bootloader mode
    connect(SoftStep, SIGNAL(signalBootloaderMode(bool)), this, SLOT(slotBootloaderMode(bool)));

    // reset portlist after sending bootloader commands, catch changes to port names
    connect(SoftStep, SIGNAL(signalBeginBlTimer()), this, SLOT(slotRefreshConnection()));
    connect(SoftStep, SIGNAL(signalBeginFwTimer()), this, SLOT(slotRefreshConnection()));

    //Connected Indicator
    connect(SoftStep, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));

    // ---- end midi and fw update overhaul --------------------

    //About Ok Button
    connect(aboutForm->ok, SIGNAL(clicked()), aboutFormWidget, SLOT(close()));
    connect(aboutForm->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(aboutForm->ok, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //Preset Recall
    connect(ui->currentPreset, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), this, SLOT(slotRecallPreset(QVariantMap,QVariantMap)));

    for(int i = 1; i < 11; i++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[i-1], SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
    }

    //Preset Storage
    connect(ui->midiChannel, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->sensitivity, SIGNAL(valueChanged(double)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->pedalCC, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->navPadCC, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->backlight, SIGNAL(clicked()), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->displayName, SIGNAL(textEdited(QString)), presetInterface, SLOT(slotStoreGlobal()));

    ui->midiChannel->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->sensitivity->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->pedalCC->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->displayName->setContextMenuPolicy(Qt::PreventContextMenu);

    for(int i = 1; i < 11; i++)
    {
        connect(key[i-1], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //Save State
        connect(key[i-1], SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));
    }

    //Save indicator
    connect(presetInterface, SIGNAL(signalPresetDirty(bool)), this, SLOT(slotDisplaySaveState(bool)));

    //Copy Paste - update paste availability based on whether anything has been copied
    connect(copyPasteHandler, SIGNAL(signalUpdatePasteAvailability()), this, SLOT(slotUpdatePasteAvailability()));

    //Update Button
    connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
    connect(presetInterface, SIGNAL(signalUpdateStarted()), this, SLOT(slotDisconnectUpdate()));
    connect(presetInterface, SIGNAL(signalAttributeFormatPreset(QVariantMap,QVariantMap, qlonglong)), sysExComposer, SLOT(slotComposeAttributeListFromPreset(QVariantMap,QVariantMap, qlonglong)));

    connect(sysExComposer, SIGNAL(signalUpdateComplete()), this, SLOT(slotConnectUpdate()));

    connect(ui->revert, SIGNAL(clicked()), presetInterface, SLOT(slotRevertPreset()));
    //set initial update button text
    ui->update->setText("SAVE");


    // MIDI overhaul
    connect(sysExComposer, SIGNAL(signalSendSysEx(unsigned char*, int)), SoftStep, SLOT(slotSendSysEx(unsigned char*, int)));



}


void MainWindow::slotRecallPreset(QVariantMap preset, QVariantMap master)
{
    //----------------------------------- Handle keyboard commands
    //Show/Hide Factory/Custom Preset
    if(!preset.value("useFactory").toString().contains("No"))
    {
        factoryPresetCoverWidget1->show();

        factoryPresetNameLabel->setText(QString("Using Factory Preset: ") + preset.value("useFactory").toString());
        factoryPresetNameLabel->show();

        ui->update->raise();
        ui->currentPreset->raise();
        ui->currentPresetLabel->raise();
        ui->sensitivity->raise();
        ui->sensitivityLabel->raise();
        ui->backlight->raise();
        ui->backlightLabel->raise();
        ui->softstepLabel->raise();
        ui->connectedLabel->raise();
        ui->revert->raise();

        ui->midiChannel->setFocusPolicy(Qt::NoFocus);
        ui->navPadCC->setFocusPolicy(Qt::NoFocus);
        ui->pedalCC->setFocusPolicy(Qt::NoFocus);
        ui->displayName->setFocusPolicy(Qt::NoFocus);

        ui->currentPreset->setFocus();
        slotEnableDisableUseCustomPreset(true);
    }
    else
    {
        ui->midiChannel->setFocusPolicy(Qt::StrongFocus);
        ui->navPadCC->setFocusPolicy(Qt::StrongFocus);
        ui->pedalCC->setFocusPolicy(Qt::StrongFocus);
        ui->displayName->setFocusPolicy(Qt::StrongFocus);

        factoryPresetCoverWidget1->hide();
        factoryPresetNameLabel->hide();
        slotEnableDisableUseCustomPreset(false);
    }

    //Disable Keys
    for(int i = 0; i < 10; i++)
    {
        foreach (QWidget* widget, key[i]->findChildren<QWidget*>())
        {
            QString type = widget->metaObject()->className();

            if(!preset.value("useFactory").toString().contains("No"))
            {
                widget->setFocusPolicy(Qt::NoFocus);
                widget->clearFocus();
            }
            else
            {
                if(type == "QSpinBox" || type == "QCheckBox" || type == "QLineEdit")
                {
                    widget->setFocusPolicy(Qt::StrongFocus);
                }
            }
        }
    }

    //------------------------------------- Sets mainwindow Ui components

    //Global
    ui->sensitivity->setValue(master.value(QString("sensitivity")).toDouble());
    ui->backlight->setChecked(master.value(QString("backlight")).toBool());

    //Preset
    ui->midiChannel->setValue(preset.value(QString("midiChannel")).toInt());
    ui->pedalCC->setValue(preset.value(QString("pedalCC")).toInt());
    ui->navPadCC->setValue(preset.value(QString("navPadCC")).toInt());
    ui->displayName->setText(preset.value(QString("displayName")).toString());
}

void MainWindow::slotDisplaySaveState(bool dirty)
{
#ifdef Q_OS_MAC
    if(dirty)
    {
        ui->update->setStyleSheet(styleSheets->sendButtonDirtyStyleSheet);
    }
    else
    {
        ui->update->setStyleSheet(styleSheets->sendButtonCleanStyleSheet);
    }
#else
    if(dirty)
    {
        ui->update->setStyleSheet(styleSheets->sendButtonDirtyStyleSheet_windows);
    }
    else
    {
        ui->update->setStyleSheet(styleSheets->sendButtonCleanStyleSheet_windows);
    }
#endif

}

void MainWindow::slotUpdateAboutWindow()
{
    qDebug() << "slotUpdateAboutWindow called";
    aboutForm->aboutTitle->setText(QString("SoftStep Basic Editor v%1.%2.%3")
                               .arg(uchar(applicationVersion.at(0)))
                               .arg(uchar(applicationVersion.at(1)))
                               .arg(uchar(applicationVersion.at(2))));

    if (betaVersion != "")
    {
        aboutForm->aboutTitle->setText(aboutForm->aboutTitle->text().append(betaVersion));
    }

    QString thisLabelString;
    if (connected)
    {
        thisLabelString = deviceBootloaderVersionString();

        thisLabelString.append(applicationFirmwareVersionString());

        thisLabelString.append(deviceFirmwareVersionString());
    }
    else
    {
        thisLabelString = applicationFirmwareVersionString();

        thisLabelString.append(QString("Device Not Connected"));
    }

    aboutForm->fwInfo->setText(thisLabelString);

}



void MainWindow::slotConnected(bool connection)
{

    //qDebug() << "slotConnected Called" << connection;

    if(connection)
    {
//
        sysExComposer->slotStandaloneOn();
//
        ui->connectedLabel->setText("CONNECTED");
#ifdef Q_OS_MAC
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(0,200,0,255);");
#else
        ui->connectedLabel->setStyleSheet("font:6pt \"Futura\";color: rgba(0,200,0,255);");
#endif
        ui->update->setText("SAVE + SEND");

        presetInterface->connected = true;

        updatefw->setEnabled(true);

        // attempt to recall midi thru port when device connects
        //slotRecallMIDIThru();
    }
    else
    {
        //ui->connectedFrame->setStyleSheet("border: 1px solid rgb(67,67,67);background: rgb(100,100,100); border-radius:6;");
        //ui->connectedLabel->setText("Not Connected");
        ui->connectedLabel->setText("NOT CONNECTED");
#ifdef Q_OS_MAC
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(200,0,0,255);");
#else
        ui->connectedLabel->setStyleSheet("font:6pt \"Futura\";color: rgba(200,0,0,255);");
#endif
        ui->update->setText("SAVE");

        presetInterface->connected = false;

        updatefw->setEnabled(false);

    }

    slotUpdateAboutWindow();

}


void MainWindow::slotInitMenuBar()
{
    menubar = new QMenuBar(this);
#ifndef Q_OS_MAC
    QFile menuStyleFile = QFile(":/resources/menuBarWin.qss");
    QString menuStyleString;

    if (menuStyleFile.open(QFile::ReadOnly))
    {
        menuStyleString = QLatin1String(menuStyleFile.readAll());
        menubar->setStyleSheet(menuStyleString);

        qDebug() << "menubar stylesheet: " << menubar->styleSheet();
    }
    else
    {
        qDebug() << "ERROR - Could not find menubar stylesheet: " << menuStyleString;
    }


    menubar->setGeometry(0,0, this->width(), 20);
#endif

    //-------------------------------------------------------------------------- File
    QMenu* file = new QMenu("File");
    qDebug() << file;
    file->setObjectName("FileMenu");

    //------------- Import / Export -------------//
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

    //Copy / Paste
    copyPresetAct = new QAction("Copy Preset", edit);
    actionList.append(copyPresetAct);
    edit->addAction(copyPresetAct);
    copyPresetAct->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_C));
    connect(copyPresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotCopyPreset()));

    pastePresetAct = new QAction("Paste Preset", edit);
    actionList.append(pastePresetAct);
    edit->addAction(pastePresetAct);
    pastePresetAct->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_V));
    connect(pastePresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotPastePreset()));
    pastePresetAct->setDisabled(true);

    //Custom Preset
    useCustom = new QAction("Use Custom Preset", edit);
    actionList.append(useCustom);
    connect(useCustom, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    connect(useCustom, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));

    edit->addAction(useCustom);

    //Factory Preset Menu
    QMenu* factoryPreset = new QMenu("Use Factory Preset");
    edit->addMenu(factoryPreset);

    //--Program Change
    QAction* factoryProgramChange = new QAction("Program Change", factoryPreset);
    actionList.append(factoryProgramChange);
    connect(factoryProgramChange, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    //connect(factoryProgramChange, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    factoryPreset->addAction(factoryProgramChange);

    //--Eleven Rack
    QAction* factoryElevenRack = new QAction("ElevenRack Control", factoryPreset);
    actionList.append(factoryElevenRack);
    connect(factoryElevenRack, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    //connect(factoryElevenRack, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    factoryPreset->addAction(factoryElevenRack);

    //--Pod
    QAction* factoryPod = new QAction("Line6 Pod Control", factoryPreset);
    actionList.append(factoryPod);
    connect(factoryPod, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    //connect(factoryPod, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    factoryPreset->addAction(factoryPod);

    //--Live
    QAction* factoryLive = new QAction("Ableton Live Control", factoryPreset);
    actionList.append(factoryLive);
    connect(factoryLive, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    //connect(factoryLive, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    factoryPreset->addAction(factoryLive);



    //-------------------------------------------------------------------------- Hardware
    QMenu* hardware = new QMenu("Hardware");
    hardware->setObjectName("HardwareMenu");

    //Reload Firmware
    updatefw = new QAction("Force Firmware Update...", hardware);
    actionList.append(updatefw);
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(show()));
    //connect(updatefw, SIGNAL(triggered()), fwUpdateDialogWidget, SLOT(show()));
    connect(updatefw, SIGNAL(triggered()), this, SLOT(slotForceFirmwareUpdate()));
    connect(updatefw, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));

    hardware->addAction(updatefw);
    menubar->addMenu(hardware);

    //-------------------------------------------------------------------------- Help
    QMenu* help = new QMenu("Help");
    help->setObjectName("HelpMenu");

    //About
    QAction* about = new QAction("About SoftStep Editor", help);
    actionList.append(about);
    connect(about, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(about, SIGNAL(triggered()), aboutFormWidget, SLOT(show()));
    connect(about, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    help->addAction(about);

    //Doc
    QAction* doc = new QAction("Documentation...", help);
    actionList.append(doc);
    connect(doc, SIGNAL(triggered()), this, SLOT(slotOpenDocumentation()));
    help->addAction(doc);
    menubar->addMenu(help);
}

void MainWindow::slotEnableDisableUseCustomPreset(bool enable)
{
    if(enable)
    {
        useCustom->setEnabled(true);
        useCustomEnabled = true;
    }
    else
    {
        useCustom->setEnabled(false);
        useCustomEnabled = false;
    }
}

void MainWindow::slotEnableDisableMenu()
{
    //Disable Menubar actions
    for(int i = 0; i < actionList.size(); i++)
    {
        actionList.at(i)->setEnabled(!disableWidget->isVisible());
    }

    //Separately Enable/Disable Use Custom Preset edit menu item.
    if(!disableWidget->isVisible())
    {
        //if all menu items are not all disabled
        if(useCustomEnabled)
        {
            //then enable or disable Use Custom.
            useCustom->setEnabled(true);
        }
        else
        {
            useCustom->setEnabled(false);
        }
    }

    //Disable MainWindow UI
    foreach (QWidget* widget, this->findChildren<QWidget*>())
    {
        QString type = widget->metaObject()->className();

        if(disableWidget->isVisible())
        {
            widget->setFocusPolicy(Qt::NoFocus);
            widget->clearFocus();
        }
        else
        {
            if(type == "QSpinBox" || type == "QCheckBox" || type == "QLineEdit")
            {
                widget->setFocusPolicy(Qt::StrongFocus);
            }
        }
    }

    //Disable Keys
    for(int i = 0; i < 10; i++)
    {
        key[i]->slotEnableDisableKeyEvents(disableWidget->isVisible());

        foreach (QWidget* widget, key[i]->findChildren<QWidget*>())
        {
            QString type = widget->metaObject()->className();

            if(disableWidget->isVisible())
            {
                widget->setFocusPolicy(Qt::NoFocus);
                widget->clearFocus();
            }
            else
            {
                if(type == "QSpinBox" || type == "QCheckBox" || type == "QLineEdit")
                {
                    widget->setFocusPolicy(Qt::StrongFocus);
                }
            }
        }
    }
}

void MainWindow::slotUpdatePasteAvailability()
{
    //enable and disable paste options depending on whether anything is copied
    if(copyPasteHandler->presetCopiedMap.size())
    {
        pastePresetAct->setDisabled(false);
    }
}

void MainWindow::slotDisplayFactory()
{

}

void MainWindow::slotOpenDocumentation()
{
    //QFile *file = new QFile(":doc.txt");
    //file->open(QFile::ReadOnly);
    QDesktopServices::openUrl(QUrl("http://files.keithmcmillen.com/downloads/softstep/SoftStep_Manual_v2.01.pdf"));
    //qDebug() << (QLatin1String)file->readLine(0);
    //file->close();
}

void MainWindow::slotDisconnectUpdate()
{
    qDebug("download preset started");
    disconnect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
}

void MainWindow::slotConnectUpdate()
{
    qDebug("download preset ended");
    connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
}



// --------------------------------------------------------------------------------------
// ------ midi overhaul -----------------------------------------------------------------
// --------------------------------------------------------------------------------------

void MainWindow::slotMIDIPortChange(QString portName, uchar inOrOut, uchar messageType, int portNum)
{
    qDebug() << "slotMIDIPortChange - " << kmiPorts->mType[messageType] << kmiPorts->inOut[inOrOut] << " portName:" << portName << " messageType: " << " portNum: " << portNum << "\n";

    switch (messageType)
    {
    case PORT_CONNECT:

        // update dropdown
        if (inOrOut == PORT_OUT && portName != SS_OUT_P1) // don't create feedback loop
        {
            ui->midi_thru->addItem(portName); // update dropdown


            if (portName == settings->value(MIDI_THRU_KEY).toString()) // if this port matches the last selected port
            {
                recallMidiThruPortName = portName; // store name
                //QTimer::singleShot(500, this, SLOT(slotRecallMIDIThru())); // wait, then set/update the port
            }

        }


        // **** SoftStep connect *****************************************
        if ((portName == SS_IN_P1 || portName == SS_OLD_IN_P1 || portName == SS_BL_PORT) && inOrOut == PORT_IN)
        {   
            SoftStep->slotSetExpectedFW(thisFw);
            SoftStep->slotUpdatePortIn(portNum);
            fwUpdateWindow->slotAppendTextToConsole("\nSoftStep Connected\n");
        }
        else if ((portName == SS_OUT_P1  || portName == SS_OLD_OUT_P1 || portName == SS_BL_PORT) && inOrOut == PORT_OUT)
        {
            // use the port names to determine if we need to upgrade the bootloader, or if we are in bootloader mode
            if (portName == SS_OLD_OUT_P1)
            {
                SoftStep->slotUpdatePID(PID_SOFTSTEP2_OLD); // this will use the old SSCOM firmware version request
            }
            else
            {
                SoftStep->slotUpdatePID(PID_SOFTSTEP); // this uses the standard SysEx ID request
            }

            SoftStep->slotUpdatePortOut(portNum);
            SoftStep->slotStartPolling("PORT_CONNECT"); // start polling when output port is added
        }

        break;
    case PORT_DISCONNECT:

        if (inOrOut == PORT_OUT)
        {
            // update dropdown
            if (ui->midi_thru->currentText() == portName)
            {
               ui->midi_thru->removeItem(ui->midi_thru->findText(portName));
            }

            ui->midi_thru->removeItem(ui->midi_thru->findText(portName));
        }

        // **** SoftStep disconnect **************************************
        if (portName == SS_IN_P1 || portName == SS_OLD_IN_P1 || portName == SS_BL_PORT)
        {
            // close ports and stop polling
            SoftStep->slotCloseMidiIn(SIGNAL_SEND);
            SoftStep->slotCloseMidiOut(SIGNAL_SEND);
            SoftStep->slotStopPolling("PORT_DISCONNECT");
            if (inOrOut == PORT_IN) fwUpdateWindow->slotAppendTextToConsole("\nSoftStep Disconnected\n");
        }

        break;
    case PORT_CHANGED:
        //qDebug() << " PORT CHANGED - name: " << portName << portName << " inOrOut: " << kmiPorts->inOut[inOrOut] << " messageType: " << kmiPorts->mType[messageType] << " portNum: " << portNum << "\n";

        // **** SoftStep renumber ****************************************
        if ((portName == SS_IN_P1 || portName == SS_OLD_IN_P1 || portName == SS_BL_PORT) && inOrOut == PORT_IN)
        {
            SoftStep->slotUpdatePortIn(portNum);
        }
        else if ((portName == SS_OUT_P1  || portName == SS_OLD_OUT_P1 || portName == SS_BL_PORT) && inOrOut == PORT_OUT)
        {
            SoftStep->slotUpdatePortOut(portNum);
        }

        break;
    default:
        break;
    }
}

// close and then reopen the SoftStep ports
// this is needed when the bootloader and app port names do not match
void MainWindow::slotRefreshConnection()
{
    qDebug() << "slotRefreshConnection called";
//#ifndef Q_OS_WIN
    if (!SoftStep->bootloaderMode) // app->bootLoader
    {
        SoftStep->slotResetConnections(SS_OLD_IN_P1, SS_BL_PORT);
    }
    else
    {
        SoftStep->slotResetConnections(SS_OUT_P1, SS_BL_PORT);
    }
//#endif
}


void MainWindow::slotBootloaderMode(bool fwUpdateRequested)
{
    qDebug() << "slotBootloaderMode called - fwUpdateRequested: "<< fwUpdateRequested;
    if (!fwUpdateRequested)
    {
        QMessageBox msgBox;
        msgBox.setText("Your device is in bootloader mode. Click OK to attempt a firmware update.");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Ok)
        {
            slotForceFirmwareUpdate();
        }
    }
}

void MainWindow::slotFwUpdateSuccessCloseDialog(bool success)
{
    qDebug() << "slotFwUpdateSuccessCloseDialog called - success: " << success;

    if (success)
    {
        SoftStep->fwUpdateRequested = false;
        slotUpdateMIDIThru();
        slotConnected(true);
    }
    else
    {
        SoftStep->slotFirmwareUpdateReset();
        slotConnected(false);
    }

    disableWidget->hide();
    slotEnableDisableMenu();

}

void MainWindow::slotForceFirmwareUpdate()
{
    slotFirmwareDetected(SoftStep, false); // act as if we received a firmware mismatch
}

void MainWindow::slotFirmwareDetected(MidiDeviceManager *thisMDM, bool matches)
{
    qDebug() << "slotFirmwareDetected called";
    qDebug() << SoftStep->connected;
    if (matches)
    {
        qDebug() << "FirmwareMatch: " << thisMDM->PID << "name:" << thisMDM->deviceName;
    }
    else
    {
        qDebug() << "Firmware MisMatch: " << thisMDM->PID << "name:" << thisMDM->deviceName;

        fwUpdateWindow->slotClearText();
        fwUpdateWindow->slotAppendTextToConsole(deviceBootloaderVersionString());
        fwUpdateWindow->slotAppendTextToConsole(deviceFirmwareVersionString());

        fwUpdateWindow->show();
    }
}

// connect SoftStep midi input to to midi thru
void MainWindow::slotUpdateMIDIThru()
{
    SoftStep->disconnect(SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)));

    QString currentPort = ui->midi_thru->currentText();

    qDebug() << "slotUpdateMIDIThru called - currentPort: " << currentPort << " connected: " << SoftStep->connected;

    if (currentPort == "")
    {
        currentPort = "None";
        ui->midi_thru->setCurrentText(currentPort);
    }

    if (!SoftStep->connected) return; // don't continue if we aren't connected


    settings->setValue(MIDI_THRU_KEY, currentPort); // store this setting for the next time we run the editor

    if (currentPort != "None")
    {
        // set and open the ports
        int thisOutPort = kmiPorts->getOutPortNumber(currentPort);
        MIDIThru->slotUpdatePortOut(thisOutPort); // also opens the port
        connect(SoftStep, SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), MIDIThru, SLOT(slotSendMIDI(uchar, uchar, uchar, uchar)));
    }
    else
    {
        MIDIThru->slotCloseMidiOut();
    }
}

QString MainWindow::deviceBootloaderVersionString()
{
    qDebug() << "deviceBootloaderVersionString called";
    qDebug() << "SoftStep address: " << &SoftStep;
    qDebug() << "SoftStep pointer: " << SoftStep;
    qDebug() << "SoftStep ObjectName: " << SoftStep->objectName;
    qDebug() << "deviceFirmwareVersion: " << SoftStep->deviceFirmwareVersion;
    qDebug() << "devicebootloaderVersion: " << SoftStep->devicebootloaderVersion;

    qDebug() << "0: " << SoftStep->devicebootloaderVersion.at(0);
    qDebug() << "1: " << SoftStep->devicebootloaderVersion.at(1);
    qDebug() << "2: " << SoftStep->devicebootloaderVersion.at(2);
    return QString("Device Bootloader Version: %1.%2.%3\n\n")
            .arg(uchar(SoftStep->devicebootloaderVersion.at(0)))
            .arg(uchar(SoftStep->devicebootloaderVersion.at(1)))
            .arg(uchar(SoftStep->devicebootloaderVersion.at(2)));
}


QString MainWindow::deviceFirmwareVersionString()
{
    return QString("Device Firmware Version: %1.%2.%3")
            .arg(uchar(SoftStep->deviceFirmwareVersion.at(0)))
            .arg(uchar(SoftStep->deviceFirmwareVersion.at(1)))
            .arg(uchar(SoftStep->deviceFirmwareVersion.at(2)));
}

QString MainWindow::applicationFirmwareVersionString()
{
    return QString("Application Firmware Version: %1.%2.%3\n\n")
            .arg(uchar(thisFw.at(0)))
            .arg(uchar(thisFw.at(1)))
            .arg(uchar(thisFw.at(2)));
}

void MainWindow::slotRecallMIDIThru()
{
    qDebug() << "slotRecallMIDIThru called, connected: " << SoftStep->connected << " recallMidiThruPortName: " << recallMidiThruPortName;
    if (!SoftStep->connected || recallMidiThruPortName == "") return; // wait until connected to device and the previously saved port

    ui->midi_thru->setCurrentText(recallMidiThruPortName);
    slotUpdateMIDIThru();
}

// --------------------------------------------------------------------------------------
// ------ end midi overhaul -------------------------------------------------------------
// --------------------------------------------------------------------------------------



