// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"
//#include "ui_mainwindowWin.h"

//#include <QDesktopWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <KMI_FwVersions.h>
#include <kmi_updates.h>

#define MAINWINDOW_WIDTH 690
#define MAINWINDOW_WIDTH_SS3 880
#ifdef Q_OS_MAC
#define MAINWINDOW_HEIGHT 279
#else
#define MAINWINDOW_HEIGHT 299
#endif

// comment these out to troubleshoot issues with building
#define KEYS_ENABLED
#define OSC_ENABLED
#define MIDI_AUX_ENABLED
#define MIDI_ENABLED

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    saveAsDialogWidget(new QWidget(this)),
    deleteDialogWidget(new QWidget(this)),
    aboutFormWidget(new QWidget(this)),

    importOldDialogWidget(new QWidget(this)),
    importOldNotFoundDialogWidget(new QWidget(this)),
    modlineWarningDialogWidget(new QWidget(this)),

    pedalCalWidget(new QWidget(this)),
    cvCalWidget(new QWidget(this)),

    ui(new Ui::MainWindow),

    saveAsDialogForm(new Ui::saveAsDialogForm),
    deleteDialogForm(new Ui::deleteDialogForm),
    aboutForm(new Ui::AboutForm),
    importOldDialog(new Ui::ImportOldPresetsForm),
    importOldNotFoundDialog(new Ui::ImportOldNotFoundForm),
    modlineWarningDialog(new Ui::ModlineWarningForm),
    pedalCalForm(new Ui::pedalCal),
    cvCalForm(new Ui::cvCal)

{

    //PList stuff
    QCoreApplication::setApplicationName("SoftStep Advanced Editor");
    QCoreApplication::setOrganizationName("Keith McMillen Instruments");
    QCoreApplication::setOrganizationDomain("keithmcmillen.com");

    sessionSettings = new QSettings(this);

    ssHardware = sessionSettings->value("LAST_SS_REV_CONNECTED", SS_3).toUInt();

    // ---- FW update overhaul ----------------------------

    // application version
    QString versionString = QString(APP_VERSION);

    // Split the version string by dots and assign values directly
    QStringList parts = versionString.split('.');

    for (int i = 0; i < 3 && i < parts.size(); ++i)
    {
        applicationVersion.append(static_cast<char>(parts[i].toInt()));
        //imageFormatter.applicationVersion.append(static_cast<char>(parts[i].toInt())); // update this, used for generating 8051 compatible factory presets C file
    }

    if (parts.size() > 3)
    {
        betaVersion = parts[3]; // assume this is a letter
    }
    else
    {
        betaVersion = "";
    }

    // store the SoftStep device firmware version
    thisFw = QByteArray(reinterpret_cast<char*>(_fw_ver_softstep), sizeof(_fw_ver_softstep));

    QDateTime current = QDateTime::currentDateTime();
    QString timestamp = current.toString("yyyy::MM::dd::hh:mm:ss");
    qDebug() << "SoftStep Advanced Editor - Application Version: " << applicationVersion << " Firmware Version: " << thisFw;
    qDebug() << "System Locale: " << QLocale::system().name() << " Time: " << timestamp;

    appStillLoading = true;

    // app load progress window
    qDebug() << "------------ [Appload Widget SETUP] ---------------------------------------------------";

    QSize size = qApp->screens()[0]->size();

    int screenHeight = size.height();
    int screenWidth = size.width();

    QWidget     appLoadWidget;
    Ui::AppLoadForm apploadForm;
    apploadForm.setupUi(&appLoadWidget);
    appLoadWidget.move((screenWidth / 2) - ((appLoadWidget.width() / 2)), (screenHeight / 2) - (appLoadWidget.height() / 2));
    appLoadWidget.setWindowTitle("Loading SoftStep");
    appLoadWidget.setWindowFlags(Qt::FramelessWindowHint);
    appLoadWidget.show();


    // ---- end FW update overhaul ----------------------------

    // ******************************
    // KMI_Ports
    // ******************************

#ifdef MIDI_ENABLED
    // kmiPorts reports changes in MIDI i/o
    kmiPorts = new KMI_Ports(this);

    // connect kmiPorts to our handler
    connect(kmiPorts, SIGNAL(signalPortUpdated(QString, uchar, uchar, int)),
            this, SLOT(slotMIDIPortChange(QString, uchar, uchar, int)));
    connect(kmiPorts, SIGNAL(signalClearPortMaps()), this, SLOT(slotClearMIDIThruDropdown()));

    //qDebug() << "end connect";

    // ******************************
    // create KMI device handlers
    // ******************************

    SoftStep = new MidiDeviceManager(this, PID_SOFTSTEP2, "SoftStep", kmiPorts);
    kmiDecode = new KMI_Decode();
    kmiEncode = new KMI_Encode(PID_SOFTSTEP3); // EB TODO: update this when we connect/detect a new PID

    // setup bootloader/firmware images
    qDebug() << "\n------------ [FIRMWARE SETUP] ---------------------------------------------------";

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

    // connect firmware signals
    qDebug() << "connect signalFirmwareDetected";

    // SoftStepShare
    SoftStepShare = new MidiDeviceManager(this, PID_AUX, "SoftStep Share", kmiPorts);
    connect(SoftStepShare, SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(hosted_slotReceiveMIDI(uchar, uchar, uchar, uchar)));

    shareElapsedTimer = new QElapsedTimer(); // used to avoid feedback loop on windows
    shareElapsedTimer->start();

#ifdef MIDI_AUX_ENABLED
     //setup MIDI aux input sources A-H for settings menu, explicitly coded because we are using explicit functions for each source

    midiAuxIn[0] = new MidiDeviceManager(this, PID_AUX, "MIDI Input A", kmiPorts);
    midiAuxIn[1] = new MidiDeviceManager(this, PID_AUX, "MIDI Input B", kmiPorts);
    midiAuxIn[2] = new MidiDeviceManager(this, PID_AUX, "MIDI Input C", kmiPorts);
    midiAuxIn[3] = new MidiDeviceManager(this, PID_AUX, "MIDI Input D", kmiPorts);
    midiAuxIn[4] = new MidiDeviceManager(this, PID_AUX, "MIDI Input E", kmiPorts);
    midiAuxIn[5] = new MidiDeviceManager(this, PID_AUX, "MIDI Input F", kmiPorts);
    midiAuxIn[6] = new MidiDeviceManager(this, PID_AUX, "MIDI Input G", kmiPorts);
    midiAuxIn[7] = new MidiDeviceManager(this, PID_AUX, "MIDI Input H", kmiPorts);

    connect(midiAuxIn[0], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_A(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[1], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_B(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[2], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_C(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[3], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_D(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[4], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_E(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[5], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_F(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[6], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_G(uchar, uchar, uchar, uchar)));
    connect(midiAuxIn[7], SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_H(uchar, uchar, uchar, uchar)));

    connect(SoftStepShare, SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), this, SLOT(slotParseMidiAuxIn_SoftStepShare(uchar, uchar, uchar, uchar)));

#endif // end MIDI_AUX_ENABLED

    // MIDI Thru for standalone/windows
    MIDIThru = new MidiDeviceManager(this, PID_AUX, "MIDI THRU", kmiPorts);

    // Hosted output - we dynamically reassign the output port for each hosted modline message
    hostedOut = new MidiDeviceManager(this, PID_AUX, "Hosted Output", kmiPorts);

    // ******************************
    // end KMI_Ports and device handlers
    // ******************************

#endif // MIDI_ENABLED

    // ******************************
    // check for updates and set default save locations
    // ******************************
    QString jsonVersionCheckURL = "https://files.keithmcmillen.com/products/softstep/editor/softwareVersionCheck.json";
    checkUpdates = new KMI_Updates(this, "SoftStep", sessionSettings, applicationVersion, jsonVersionCheckURL);

    //-------------------- Pedal Calibration window
    qDebug() << "------------ [EXPRESSION PEDAL AND CV CALIBRATION] ---------------------------------------------------";
    pedalCalWindow = new pedalCal(this);
    cvCalWindow = new cvCal(this);

    // default file location
    const QString DEFAULT_DIR_KEY("default_dir");

    qDebug() << "Default file save location - pre: " << sessionSettings->value(DEFAULT_DIR_KEY).toString();

    // test if this is a directory
    QFileInfo check_file(sessionSettings->value(DEFAULT_DIR_KEY).toString());
    if (!check_file.exists() || !check_file.isDir() || sessionSettings->value(DEFAULT_DIR_KEY).toString().contains("Contents/MacOS"))
    {
        QString desktop = QStandardPaths::locate(QStandardPaths::DesktopLocation, QString(), QStandardPaths::LocateDirectory);
        qDebug() << "Desktop: " << desktop;
        sessionSettings->setValue(DEFAULT_DIR_KEY, desktop);     // if key doesn't exist, set it to desktop
    }

    qDebug() << "Default file save location - post: " << sessionSettings->value(DEFAULT_DIR_KEY).toString();

    qDebug() << "------------ [MainWindow UI SETUP] ---------------------------------------------------";
    //Mainwindow Ui
    ui->setupUi(this);
    this->setWindowTitle("SoftStep Advanced Editor");
    this->setFixedSize(MAINWINDOW_WIDTH_SS3, MAINWINDOW_HEIGHT);
    ui->statusBar->hide();

//    QRect screenGeometry = QApplication::desktop()->availableGeometry();


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->setGeometry(screenGeometry.width() / 4, 50, MAINWINDOW_WIDTH_SS3, MAINWINDOW_HEIGHT);

    // ---- FONTS --------------------------
    qDebug() << "------------ [FONTS SETUP] ---------------------------------------------------";

    QString droidFont = ":/fonts/droid-sans/DroidSansMono.ttf";
    QString futuraFont = ":/fonts/futura/futura-normal.ttf";
    QString futuraBFont = ":/fonts/futura/Futura-Bold.ttf";
    QString corbelFont = ":/fonts/corbel/corbel.ttf";
    QString corbelBFont = ":/fonts/corbel/corbelb.ttf";
    QString sourceFont = ":/fonts/source-sans-pro/SourceSansPro-Regular.otf";


    if (QFontDatabase::addApplicationFont(droidFont) == -1) qDebug() << "Could not load font: " << droidFont;
    if (QFontDatabase::addApplicationFont(futuraFont) == -1) qDebug() << "Could not load font: " << futuraFont;
    if (QFontDatabase::addApplicationFont(futuraBFont) == -1) qDebug() << "Could not load font: " << futuraBFont;
    if (QFontDatabase::addApplicationFont(corbelFont) == -1) qDebug() << "Could not load font: " << corbelFont;
    if (QFontDatabase::addApplicationFont(corbelBFont) == -1) qDebug() << "Could not load font: " << corbelBFont;
    if (QFontDatabase::addApplicationFont(sourceFont) == -1) qDebug() << "Could not load font: " << sourceFont;

    // ---- end FONTS -------------------------

    qDebug() << "------------ [LOAD STYLESHEETS] ---------------------------------------------------";

    // fwupdate stylesheets
#ifdef Q_OS_MAC

    fwUpdateStylesFile = new QFile(":/stylesheets/fwUpdateStyles_SoftStep.qss");
#else
    fwUpdateStylesFile = new QFile(":/stylesheets/fwUpdateStyles_SoftStep_WIN.qss");
#endif
    if (fwUpdateStylesFile->open(QFile::ReadOnly))
    {
        fwUpdateStylesString = QLatin1String(fwUpdateStylesFile->readAll());
    }
    else
    {
        qDebug() << "ERROR - could not find fwUpdate style file: " << fwUpdateStylesFile;
    }

    // app dialog stylesheets
#ifdef Q_OS_MAC
    dialogStylesFile = new QFile(":/stylesheets/appDialog_SoftStep.qss");
#else
    dialogStylesFile = new QFile(":/stylesheets/appDialog_SoftStep_WIN.qss");
#endif
    if (!dialogStylesFile->open(QFile::ReadOnly))
    {
        qDebug() << "ERROR: could not open stylesheet: " << dialogStylesFile->fileName();
    }
    else
    {
        dialogStylesString = QLatin1String(dialogStylesFile->readAll());
    }

    qDebug() << "------------ [SETUP CONNECTION INDICATOR] ---------------------------------------------------";
    ui->connectedLabel->setText("SOFTSTEP NOT CONNECTED");
    //ui->connectedLabel->setFixedSize(162, 22);
    //ui->connectedLabel->setToolTip("[ o_0 ]");
#ifdef Q_OS_MAC
    //ui->connectedLabel->move(529, 81);
    ui->connectedLabel->setStyleSheet("font:10pt \"Futura\";color: rgba(200,200,200,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#else
    //ui->connectedLabel->move(529, 100);
    ui->connectedLabel->setStyleSheet("font:7pt \"Futura\";color: rgba(200,200,200,255); background: rgba(40, 40, 40, 255); padding-left: 5px; padding-top: 2px; padding-bottom: 2px;");
#endif


    // ******************************

    sysExComposer = new SysExComposer(this);
//    sysExDeComposer = new SysExDeComposer(SoftStep, this);

    const std::vector<QComboBox*>& boxPointers =
    {
        ui->cv1_sources,
        ui->cv1_control,
        ui->cv1_ch,
        ui->cv1_notes,
        ui->cv2_sources,
        ui->cv2_control,
        ui->cv2_ch,
        ui->cv2_notes
    };

    presetInterface = new PresetInterface(this, boxPointers);

    qDebug() << "------------ [Copy/Paste SETUP] ---------------------------------------------------";
    copyPasteHandler = new CopyPasteHandler(presetInterface,this);
    qDebug() << "------------ [midiParse SETUP] ---------------------------------------------------";

    midiParse = new MidiParse();
    disableWidget = new QWidget(this);
    qDebug() << "------------ [Legacy Preset Import SETUP] ---------------------------------------------------";
    importOldPresetHandler = new ImportOldPresetHandler(presetInterface,0);
#ifdef OSC_ENABLED
    qDebug() << "------------ [OSC SETUP] ---------------------------------------------------";

    oscInterface = new OscInterface(0);
#endif


    disableWidget->hide();
    disableWidget->setGeometry(0,0,MAINWINDOW_WIDTH_SS3, MAINWINDOW_HEIGHT);
    disableWidget->setStyleSheet("background: rgba(0,0,0,200);");

    //Populates source and dest lists for modes
    slotPopulateSourceDestLists();


    qDebug() << "------------ [KEYS SETUP] ---------------------------------------------------";
#ifdef KEYS_ENABLED

    apploadForm.Text->setText("Loading Keys...");

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
#ifdef Q_OS_MAC
#else
        QCoreApplication::processEvents();
#endif

        key[i] = new Key(this, i);
        key[i]->slotSetMainWindow(this);
        apploadForm.progressBar->setValue(i * 9);
    }

    //construct Nav Window
    navKey = new NavKey(this);
    apploadForm.progressBar->setValue(100);
#endif // end KEYS_ENABLED
//    connectedVersionString = "Not Connected";
//    connectedVersionInt = -1;

    apploadForm.Text->setText("Loading dialogs...");
    apploadForm.progressBar->setValue(0);

    qDebug() << "------------ [DIALOGS AND WINDOWS SETUP] ---------------------------------------------------";
    //------------------------------------- Dialogs
    //Some bizarre positioning happening here to center these.... don't get it at the moment.
    //SaveAs
    saveAsDialogWidget->hide();
    saveAsDialogWidget->setGeometry(this->width()/2 - saveAsDialogWidget->width()/2, this->height()/2 - saveAsDialogWidget->height(), saveAsDialogWidget->width(), saveAsDialogWidget->height());
    //saveAsDialogWidget->setWindowFlags();
    saveAsDialogForm->setupUi(saveAsDialogWidget);
    apploadForm.progressBar->setValue(12);

    //Delete
    deleteDialogWidget->hide();
    deleteDialogWidget->setGeometry(this->width()/2 - deleteDialogWidget->width(), this->height()/2 - deleteDialogWidget->height(), deleteDialogWidget->width(), deleteDialogWidget->height());
    deleteDialogForm->setupUi(deleteDialogWidget);
    apploadForm.progressBar->setValue(25);

    //About Window
    aboutFormWidget->hide();
    aboutForm->setupUi(aboutFormWidget);
    aboutFormWidget->move(this->width()/2 - aboutFormWidget->width()/2, this->height()/2 - aboutFormWidget->height()/2);
    apploadForm.progressBar->setValue(37);

    //Import Old Preset Dialog
    importOldDialogWidget->hide();
    importOldDialog->setupUi(importOldDialogWidget);
    importOldDialogWidget->move(this->width()/2 - importOldDialogWidget->width()/2, this->height()/2 - importOldDialogWidget->height()/2);
    apploadForm.progressBar->setValue(50);

    //Import Old Not Found Dialog
    importOldNotFoundDialogWidget->hide();
    importOldNotFoundDialog->setupUi(importOldNotFoundDialogWidget);
    importOldNotFoundDialogWidget->move(this->width()/2 - importOldNotFoundDialogWidget->width()/2, this->height()/2 - importOldNotFoundDialogWidget->height()/2);
    apploadForm.progressBar->setValue(63);

    //Modline Warning Dialog
    modlineWarningDialogWidget->hide();
    modlineWarningDialog->setupUi(modlineWarningDialogWidget);
    modlineWarningDialogWidget->move(this->width()/2 - modlineWarningDialogWidget->width()/2, this->height()/2 - modlineWarningDialogWidget->height()/2);
    apploadForm.progressBar->setValue(75);

    //------------------------------------ Settings Window
    settingsWindow = new Settings(this);
    apploadForm.progressBar->setValue(88);

    //------------------------------------ Setlist
    setlist = new Setlist(this);
    apploadForm.progressBar->setValue(100);

    this->installEventFilter(this);

    midi_thru_dropdown = settingsWindow->settingsForm->midi_thru;

    qDebug() << "------------ [CONNECT INTERFACES] ---------------------------------------------------";
    apploadForm.Text->setText("Connecting Interfaces...");
    apploadForm.progressBar->setValue(0);

    slotConnectInterfaces();
#ifdef KEYS_ENABLED
    //Connect Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i]->slotConnectElements();
    }
    apploadForm.progressBar->setValue(10);

    //connect nav window
    navKey->slotConnectElements();
#endif // end KEYS_ENABLED

    slotInitMenuBar();
    apploadForm.progressBar->setValue(20);

    //Connect Settings Window Stuff
    settingsWindow->slotReadSettings();
    settingsWindow->slotConnectElements();
    settingsWindow->slotRecallSettings();
    apploadForm.progressBar->setValue(30);

    // check/initialize session mode
    if(!sessionSettings->contains("previousMode"))
    {
        sessionSettings->setValue("previousMode", "Hosted");
    }

    mode = sessionSettings->value("previousMode").toString() == "hosted" ? "standalone" : "hosted";

    qDebug() << "------------ [SET MODE] ---------------------------------------------------";
    slotSetMode();
    apploadForm.progressBar->setValue(50);

    //presetInterface->slotPopulatePresetMenu(ui->presetmenu);
    //presetInterface->slotRecallGlobal();
    qDebug() << "------------ [LOAD PRESET] ---------------------------------------------------";
    slotRecallLastSelectedPreset();
    apploadForm.progressBar->setValue(75);

    qDebug() << "------------ [LOAD TABLE] ---------------------------------------------------";
    key[0]->dataCooker->pedal->slotResetCalibrate();
    settingsWindow->slotLoadTableOnStartup();
    apploadForm.progressBar->setValue(90);

    qDebug() << "------------ [DISABLE CONTEXT MENUS] ---------------------------------------------------";
    //Disable All context menus
    foreach(QWidget *widget, this->findChildren<QWidget *>())
    {
        widget->setContextMenuPolicy(Qt::NoContextMenu);
#ifdef Q_OS_MAC
        widget->setAttribute(Qt::WA_MacShowFocusRect, false);
#endif

        widget->installEventFilter(&scrollEventFilter);

    }
    apploadForm.progressBar->setValue(100);

    slotUpdateAboutWindow();

#ifdef MIDI_ENABLED
    // poll times for each OS
    int thisPollTime = 100; // MacOS can poll slower
#ifdef Q_OS_WIN
    // Windows needs to poll fast, we have to catch the disconnects during fw
    // updates because QuNexus ports are reported the same wether they are
    // old ("port 1") or new ("QuNexus Control Surface").
    // Testing this for SoftStep
    thisPollTime = 100;
#endif

    kmiPorts->devicePoller->start(thisPollTime);
#endif // MIDI_ENABLED

    appLoadWidget.close();
    connected = false;
    appStillLoading = false;
    forceFirmwareUpdate = false;


}

MainWindow::~MainWindow()
{
    delete ui;
}

#define DIALOG_WIDTH 400
#define DIALOG_HEIGHT 125
#define DIALOG_TEXT_PADDING 10
#define DIALOG_W_CENTER (DIALOG_WIDTH / 2)
#define DIALOG_BUTT_W 70
#define DIALOG_BUTT_H 28
#define DIALOG_BUTT_X DIALOG_W_CENTER - (DIALOG_BUTT_W / 2)
#define DIALOG_BUTT_Y DIALOG_HEIGHT - DIALOG_BUTT_H - (DIALOG_TEXT_PADDING * 2)
#define DIALOG_TEXT_W (DIALOG_WIDTH - (DIALOG_TEXT_PADDING * 2))
#define DIALOG_TEXT_H (DIALOG_HEIGHT - DIALOG_BUTT_H - (DIALOG_TEXT_PADDING * 2))

void MainWindow::slotCreateDialog(QString dialogText)
{
    QDialog *msgBox = new QDialog(this);
    msgBox->setModal(true);
    msgBox->setWindowFlags(Qt::FramelessWindowHint);
    msgBox->setStyleSheet(dialogStylesString);


    msgBox->setMinimumSize(DIALOG_WIDTH, DIALOG_HEIGHT);
    msgBox->setFixedSize(DIALOG_WIDTH, DIALOG_HEIGHT);

    int x = this->width();
    int y = this->height();

    int dialogX = ((x / 2) - (DIALOG_WIDTH / 2));
    int dialogY = ((y / 2) - (DIALOG_HEIGHT / 2));

    qDebug() << "parent x: " << x << " y: " << y << " dialogX: " << dialogX << "dialogY: " << dialogY;

    msgBox->move(dialogX, dialogY);

    QLabel* text = new QLabel(dialogText, msgBox, Qt::WindowFlags());
    text->setAlignment(Qt::AlignCenter);
    text->setMinimumSize(DIALOG_TEXT_W, DIALOG_TEXT_H);
    text->setFixedSize(DIALOG_TEXT_W, DIALOG_TEXT_H);
    text->move(DIALOG_TEXT_PADDING, DIALOG_TEXT_PADDING);

    QPushButton* okButton = new QPushButton(msgBox);
    okButton->setStyleSheet(grayStyleString);
    okButton->setText("Ok");
    okButton->setGeometry(QRect(DIALOG_BUTT_X, DIALOG_BUTT_Y, DIALOG_BUTT_W,DIALOG_BUTT_H));
    connect(okButton, SIGNAL(clicked()), msgBox, SLOT(close()));

    msgBox->exec();
}

bool MainWindow::event( QEvent* ev )
{
    if (ev->type() == QEvent::WindowActivate)
    {
        // window was activated
        // Use hidden/background label to take UI focus so Qt doesn't pick something at random for us.
        ui->label_3->setFocus();
    }
    else if (ev->type() == QEvent::KeyPress)
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(ev);
        if ( (key->key()==Qt::Key_Enter) ||
             (key->key()==Qt::Key_Return) ||
             (key->key()==Qt::Key_Tab) ||
             (key->key()==Qt::Key_Escape) )
        {
           ui->label_3->setFocus();
        }
    }

    return QMainWindow::event( ev );
}

void MainWindow::closeEvent(QCloseEvent *)
{
#ifdef Q_OS_MAC

#else
#ifdef MIDI_ENABLED
    SoftStep->slotCloseMidiIn(SIGNAL_NONE);
    SoftStep->slotCloseMidiOut(SIGNAL_NONE);
#endif // MIDI_ENABLED
#endif
    qDebug() << "closing...";

    mode = "hosted";
    slotSetMode();
    //presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
}

void MainWindow::slotRecallLastSelectedPreset()
{
    int presetToLoad = 0;
    if (mode == "hosted")
    {
        presetToLoad = sessionSettings->value("LAST_HOSTED_PRESET_SELECTED", 0).toUInt();
    }
    else
    {
        presetToLoad = sessionSettings->value("LAST_STANDALONE_PRESET_SELECTED", 0).toUInt();
    }
    if (populatingPresetMenus || presetToLoad < 0 || presetToLoad > ui->presetmenu->count())
    {
        return;
    }
    slotSetPresetMenu(presetToLoad);
}

void MainWindow::slotStoreLastSelectedPreset(int presetNum)
{
    if (populatingPresetMenus || presetNum < 0 || presetNum > ui->presetmenu->count())
    {
        return;
    }

    if (mode == "hosted")
    {
        sessionSettings->setValue("LAST_HOSTED_PRESET_SELECTED", presetNum);
    }
    else
    {
        sessionSettings->setValue("LAST_STANDALONE_PRESET_SELECTED", presetNum);
    }
}

void MainWindow::slotSetPresetMenu(int presetNum)
{
    ui->presetmenu->setCurrentIndex(presetNum);
    presetInterface->slotRecallPreset(presetNum);
}

void MainWindow::slotConnectElements()
{
    connect(ui->displayName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
#ifdef KEYS_ENABLED
    for(int k = 0; k < 10; k++)
    {
        connect(this, SIGNAL(signalSetPresetNameInKeys(QString)), key[k], SLOT(slotSetPresetName(QString)));
    }

    connect(this, SIGNAL(signalSetPresetNameInKeys(QString)), navKey, SLOT(slotSetPresetName(QString)));
#endif // end KEYS_ENABLED
}

void MainWindow::slotDisconnectElements()
{
    disconnect(ui->displayName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
#ifdef KEYS_ENABLED
    for(int k = 0; k < 10; k++)
    {
        disconnect(this, SIGNAL(signalSetPresetNameInKeys(QString)), key[k], SLOT(slotSetPresetName(QString)));
    }

    disconnect(this, SIGNAL(signalSetPresetNameInKeys(QString)), navKey, SLOT(slotSetPresetName(QString)));
#endif
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
#ifdef KEYS_ENABLED
            if(mode == "hosted")
            {
                navKey->alphaNumManager.slotPresetChangeDisplayPresetName();
            }
#endif
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
    // ---- midi and firmware update overhaul --------------
#ifdef MIDI_ENABLED
    // connect dropdowns and connection status to MIDI aux ports
    connect(midi_thru_dropdown, SIGNAL(activated(int)), this, SLOT(slotUpdateMIDIThru()));
    connect(SoftStep, SIGNAL(signalConnected(bool)), this, SLOT(slotUpdateMIDIThru()));

    // connect softStep sysex handlers, the assumption here is that we can do this when the app loads and not worry about it. QuNexus does more complex handling of this signal.
    //connect(SoftStep, SIGNAL(signalRxSysExBA(QByteArray)), sysExDeComposer, SLOT(slotProcessSysEx(QByteArray)));

    // remember last selected MIDI aux port
    MIDI_THRU_KEY = "midi_thru_port";

    MIDI_AUX_KEY[0] = "midia_settings_device";
    MIDI_AUX_KEY[1] = "midib_settings_device";
    MIDI_AUX_KEY[2] = "midic_settings_device";
    MIDI_AUX_KEY[3] = "midid_settings_device";
    MIDI_AUX_KEY[4] = "midie_settings_device";
    MIDI_AUX_KEY[5] = "midif_settings_device";
    MIDI_AUX_KEY[6] = "midig_settings_device";
    MIDI_AUX_KEY[7] = "midih_settings_device";


    qDebug() << "connected midi thru port";

    // Firmware update Window
    fwUpdateWindow = new fwUpdate(this, "SoftStep", applicationFirmwareVersionString());
    fwUpdateWindow->setStyleSheet(fwUpdateStylesString);

    // Troubleshooting Window
    troubleshootWindow = new troubleshoot(this, "SoftStep", applicationFirmwareVersionString());
    //troubleshootWindow->setStyleSheet(generalStylesString);
    troubleshootWindow->hide();

    connect(kmiPorts, SIGNAL(signalInputCount(int)), troubleshootWindow, SLOT(slotInputCount(int)));
    connect(kmiPorts, SIGNAL(signalOutputCount(int)), troubleshootWindow, SLOT(slotOutputCount(int)));
    connect(kmiPorts, SIGNAL(signalInputPort(QString, int)), troubleshootWindow, SLOT(slotInputPort(QString, int)));
    connect(kmiPorts, SIGNAL(signalOutputPort(QString, int)), troubleshootWindow, SLOT(slotOutputPort(QString, int)));


    qDebug() << "------------ [CONNECT MIDI] ---------------------------------------------------";
    // MIDI

    // connect firmware detection
    connect(SoftStep, SIGNAL(signalFirmwareDetected(MidiDeviceManager*, bool)), this, SLOT(slotFirmwareDetected(MidiDeviceManager*, bool)));

    // connect firmware update window and midi device manager controls and messaging
    connect(fwUpdateWindow, SIGNAL(signalRequestFwUpdate()), SoftStep, SLOT(slotRequestFirmwareUpdate()));                      // request fw
    connect(SoftStep, SIGNAL(signalFwConsoleMessage(QString)), fwUpdateWindow, SLOT(slotAppendTextToConsole(QString)));         // messaging
    connect(SoftStep, SIGNAL(signalFwProgress(int)), fwUpdateWindow, SLOT(slotUpdateProgressBar(int)));                         // console
    connect(SoftStep, SIGNAL(signalFirmwareUpdateComplete(bool)), fwUpdateWindow, SLOT(slotFwUpdateComplete(bool)));            // Update Complete
    connect(fwUpdateWindow, SIGNAL(signalFwUpdateSuccess()), SoftStep, SLOT(slotFirmwareUpdateReset()));                        // stop timeout timers

#ifdef DEBUG_FW_BRICKED
    connect(fwUpdateWindow, SIGNAL(signalFwUpdateSuccess()), this, SLOT(slotFirmwareDebugBricked()));                        // stop timeout timers
#endif
    connect(fwUpdateWindow, SIGNAL(signalFwUpdateSuccessCloseDialog(bool)), this, SLOT(slotFwUpdateSuccessCloseDialog(bool)));  // close fw dialog and connect

    // connect fwUpdate console messages to connection troubleshooter
    connect(SoftStep, SIGNAL(signalFwConsoleMessage(QString)), troubleshootWindow, SLOT(slotAppendToStatusLog(QString)));
    connect(fwUpdateWindow, SIGNAL(signalRequestFwUpdate()), troubleshootWindow, SLOT(slotRequestFwUpdate()));
    connect(SoftStep, SIGNAL(signalFirmwareUpdateComplete(bool)), troubleshootWindow, SLOT(slotFirmwareUpdated(bool)));

    // handle device unexpectedly in bootloader mode
    connect(SoftStep, SIGNAL(signalBootloaderMode(bool)), this, SLOT(slotBootloaderMode(bool)));

    // NRPNs for pedalCal tether and cvCal
    connect(SoftStep, SIGNAL(signalRxMidi_NRPN(uchar,int,int)), this, SLOT(slotProcessNRPN(uchar,int,int)));
    connect(cvCalWindow, SIGNAL(signalSendNRPN(int,int,unsigned char)), SoftStep, SLOT(slotSendMIDI_NRPN(int,int,uchar)));
    connect(cvCalWindow, SIGNAL(signalSendStepSXPacket(uint8_t,uint8_t,uint8_t*,uint16_t)), kmiEncode, SLOT(slotEncodePacket(uint8_t,uint8_t,uint8_t*,uint16_t)));

    // sysex enc/decoding
    connect(SoftStep, SIGNAL(signalRxSysExBA(QByteArray)), kmiDecode, SLOT(slotDecodePacket(QByteArray)));
    connect(kmiDecode, SIGNAL(signalRxKMIPacket(uint8_t,uint8_t,uint8_t,uint8_t*,uint16_t)), this, SLOT(slotProcessKMIPacket(uint8_t,uint8_t,uint8_t,uint8_t*,uint16_t)));

    connect(kmiEncode, SIGNAL(signalSendSysEx(unsigned char*,int)), SoftStep, SLOT(slotSendSysEx(unsigned char*,int)));

    // ---- end midi and fw update overhaul --------------------

    //Connected Indicator
    connect(SoftStep, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////// Hosted / Standalone ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------------------------- Mode Switching - children handled in slotSetMode
    connect(ui->mode, SIGNAL(clicked()), this, SLOT(slotSetMode()));

//    //-------------------------------------- Hosted MIDI
    connect(SoftStep, SIGNAL(signalRxMidi_controlChange(uchar, uchar, uchar)), this, SLOT(slotProcessInputToHostedMode(uchar, uchar, uchar)));

// EB TODO - was at end of slotConnectInterfaces, verify theis works here
    //Send SysEx from sysexComposer
    connect(sysExComposer, SIGNAL(signalSendSysEx(unsigned char*, int)), SoftStep, SLOT(slotSendSysEx(unsigned char*, int)));

    //Signal Update Complete
    connect(sysExComposer, SIGNAL(signalUpdateComplete()), this, SLOT(slotConnectUpdate()));

#endif // MIDI_ENABLED

#ifdef KEYS_ENABLED

#ifdef MIDI_AUX_ENABLED
    //Midi Inputs from Settings
    for(int i=0; i < 8; i++)
    {
        //get signal from midi device manager
        //connect(midiDeviceManager, SIGNAL(hosted_signalParseMidiInputPacket(const MIDIPacket*, QString)), &settingsWindow->midiInputLine[i], SLOT(slotReceiveInput(const MIDIPacket*, QString)),Qt::DirectConnection);

        //send signal from midi input lines to
        for(int k = 0; k < 10; k++)
        {
            connect(&settingsWindow->midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), key[k]->dataCooker, SLOT(slotReceiveMidiInput(int,QString)));
        }
        connect(&settingsWindow->midiInputLine[i], SIGNAL(signalSendInputToModlines(int,QString)), &navKey->dataCooker, SLOT(slotReceiveMidiInput(int,QString)));

    }
#endif // MIDI_AUX_ENABLED

//    //Device menu population
//    connect(midiDeviceManager, SIGNAL(hosted_signalPopulateDeviceMenus(QMap<QString, int>)), this, SLOT(slotPopulateDeviceMenus(QMap<QString, int>)));

//    //Midi input menu population
//    connect(midiDeviceManager, SIGNAL(hosted_signalMidiInputSourceMenus(QMap<QString, int>)), settingsWindow, SLOT(slotPopulateInputMenus(QMap<QString, int>)));

    connect(&midiFormatOutput, SIGNAL(signalSendMidiPacketList(QString, uchar, uchar, uchar, uchar)), this, SLOT(hosted_slotSendPacket(QString, uchar, uchar, uchar, uchar)));
    connect(&midiFormatOutput, SIGNAL(signalSendMidiPacketArray(QString, QByteArray)), this, SLOT(hosted_slotSendPacketArray(QString, QByteArray)));

    for(int k = 0; k < 10; k++)
    {
        //Midi Parsing to each Key's data cooker
        connect(this, SIGNAL(signalUpdateSensor(uchar,uchar)), key[k]->dataCooker, SLOT(slotUpdateVals(uchar,uchar)));//, Qt::DirectConnection);

        connect(key[k], SIGNAL(signalFixDropDownWidth(QComboBox*)), this, SLOT(slotFixDropDownWidth(QComboBox*)));
        slotFixDropDownWidth(key[k]->keyWindowForm->leddisplaymode);

        for(int m = 0; m < 6; m++)
        {
            //Output signals listed in modline.h, slots in midiformat.h
            //Note Live
            connect(key[k]->modline[m], SIGNAL(hosted_signalNoteLive(QString,int,int,int,int)), &midiFormatOutput, SLOT(slotNoteLive(QString,int,int,int,int)));

            //Note Set
            connect(key[k]->modline[m], SIGNAL(hosted_signalNoteSet(QString,int,int,int)), &midiFormatOutput, SLOT(slotNoteSet(QString,int,int,int)));

            //CCs
            connect(key[k]->modline[m], SIGNAL(hosted_signalCC(QString,int,int,int)), &midiFormatOutput, SLOT(slotCC(QString,int,int,int)));

            //Bank
            connect(key[k]->modline[m], SIGNAL(hosted_signalBank(QString,int,int,int)), &midiFormatOutput, SLOT(slotBank(QString,int,int,int)));

            //OSC goes here ----------------------

            //Program
            connect(key[k]->modline[m], SIGNAL(hosted_signalProgram(QString,int,int)), &midiFormatOutput, SLOT(slotProgram(QString,int,int)));

            //Pitch Bend
            connect(key[k]->modline[m], SIGNAL(hosted_signalPitchBend(QString,int,int,int)), &midiFormatOutput, SLOT(slotPitchBend(QString,int,int,int)));

            //MMC
            connect(key[k]->modline[m], SIGNAL(hosted_signalMMC(QString,int,QString)), &midiFormatOutput, SLOT(slotMMC(QString,int,QString)));

            //Aftertouch
            connect(key[k]->modline[m], SIGNAL(hosted_signalAftertouch(QString,int,int)), &midiFormatOutput, SLOT(slotAftertouch(QString,int,int)));

            //PolyAftertouch
            connect(key[k]->modline[m], SIGNAL(hosted_signalPolyAftertouch(QString,int,int,int)), &midiFormatOutput, SLOT(slotPolyAftertouch(QString,int,int,int)));

            //Garageband goes here -------------
            //HUI goes here --------------------

            // fix dropdowns
            connect(key[k]->modline[m], SIGNAL(signalFixDropDownWidth(QComboBox*)), this, SLOT(slotFixDropDownWidth(QComboBox*)));

        }

#ifdef MIDI_ENABLED
        //Alphanumeric midi out
        //connect(&key[k]->alphaNumManager, SIGNAL(signalSendDisplayVals(QString,QList<MIDIPacket>)), &displaySink, SLOT(slotAddAlphaPacket(QString,QList<MIDIPacket>)),Qt::DirectConnection);
        connect(&key[k]->alphaNumManager, SIGNAL(signalSendPacket(uchar, uchar, uchar)), SoftStep, SLOT(slotSendMIDI(uchar, uchar, uchar))); // , Qt::DirectConnection);

        //Led and Display midi out
        connect(&key[k]->ledManager, SIGNAL(signalSendLEDControl(QString,QList<MIDIPacket>)), &displaySink, SLOT(slotAddLEDPacket(QString,QList<MIDIPacket>))); // ,Qt::DirectConnection);

        for(int l = 0; l < 10; l++)
        {
            connect(key[k]->dataCooker, SIGNAL(signalThisKeyPressed(int)), &key[l]->alphaNumManager, SLOT(slotDisplayKeyName(int)));
            connect(key[k]->dataCooker, SIGNAL(signalThisKeyOff(int)), &key[l]->alphaNumManager, SLOT(slotKeyOff(int)));
            //connect(&key[k]->dataCooker, SIGNAL(signalXIncClockStart(int)), key[k]->dataCooker, SLOT(slotXIncClockStart(int)));
            //connect(&key[k]->dataCooker, SIGNAL(signalXIncClockStop()), key[k]->dataCooker, SLOT(slotXIncClockStop()));
        }

        //qDebug() << "Connect slotResetModlinesLastVal";
        connect(key[k]->dataCooker, SIGNAL(signalThisKeyOff(int)), key[k], SLOT(slotResetModlinesLastVal()));

        //Reset nav "once" display mode
        connect(key[k]->dataCooker, SIGNAL(signalThisKeyOff(int)), &navKey->alphaNumManager, SLOT(slotCloseParamDisplay()));
#endif // MIDI_ENABLED
    }

    connect(navKey, SIGNAL(signalFixDropDownWidth(QComboBox*)), this, SLOT(slotFixDropDownWidth(QComboBox*)));

    slotFixDropDownWidth(navKey->navKeyWindowForm->leddisplaymode);

#ifdef MIDI_ENABLED
    connect(&navKey->dataCooker, SIGNAL(signalThisKeyOff(int)), &navKey->alphaNumManager, SLOT(slotKeyOff(int)));

    //nav pad
    connect(this, SIGNAL(signalUpdateSensor(uchar, uchar)), &navKey->dataCooker, SLOT(slotUpdateVals(uchar, uchar))); // , Qt::DirectConnection);
    for(int n = 0; n < 6; n++)
    {
        //output signals listed in navModline.h, slots in midiformat.h
        //Note Live
        connect(navKey->navModline[n], SIGNAL(hosted_signalNoteLive(QString,int,int,int,int)), &midiFormatOutput, SLOT(slotNoteLive(QString,int,int,int,int)));

        //Note Set
        connect(navKey->navModline[n], SIGNAL(hosted_signalNoteSet(QString,int,int,int)), &midiFormatOutput, SLOT(slotNoteSet(QString,int,int,int)));

        //CCs
        connect(navKey->navModline[n], SIGNAL(hosted_signalCC(QString,int,int,int)), &midiFormatOutput, SLOT(slotCC(QString,int,int,int)));

        //Bank
        connect(navKey->navModline[n], SIGNAL(hosted_signalBank(QString,int,int,int)), &midiFormatOutput, SLOT(slotBank(QString,int,int,int)));

        //OSC goes here ----------------------

        //Program
        connect(navKey->navModline[n], SIGNAL(hosted_signalProgram(QString,int,int)), &midiFormatOutput, SLOT(slotProgram(QString,int,int)));

        //Pitch Bend
        connect(navKey->navModline[n], SIGNAL(hosted_signalPitchBend(QString,int,int,int)), &midiFormatOutput, SLOT(slotPitchBend(QString,int,int,int)));

        //MMC
        connect(navKey->navModline[n], SIGNAL(hosted_signalMMC(QString,int,QString)), &midiFormatOutput, SLOT(slotMMC(QString,int,QString)));

        //Aftertouch
        connect(navKey->navModline[n], SIGNAL(hosted_signalAftertouch(QString,int,int)), &midiFormatOutput, SLOT(slotAftertouch(QString,int,int)));

        //PolyAftertouch
        connect(navKey->navModline[n], SIGNAL(hosted_signalPolyAftertouch(QString,int,int,int)), &midiFormatOutput, SLOT(slotPolyAftertouch(QString,int,int,int)));

        //Garageband goes here -------------
        //HUI goes here --------------------

        // fix dropdowns
        connect(navKey->navModline[n], SIGNAL(signalFixDropDownWidth(QComboBox*)), this, SLOT(slotFixDropDownWidth(QComboBox*)));
    }

    //Alphanumeric MIDI Out
    connect(&navKey->alphaNumManager, SIGNAL(signalSendDisplayVals(QString,QList<MIDIPacket>)), &displaySink, SLOT(slotAddAlphaPacket(QString,QList<MIDIPacket>)), Qt::DirectConnection);
    connect(&navKey->alphaNumManager, SIGNAL(signalSendPacket(uchar, uchar, uchar)), SoftStep, SLOT(slotSendMIDI(uchar, uchar, uchar))); //, Qt::DirectConnection);

    connect(&navKey->dataCooker, SIGNAL(signalThisKeyPressed(int)), &navKey->alphaNumManager, SLOT(slotDisplayKeyName(int)));

    // EB DONE - reconnected this, using direct method for now rather than midiFormatOutput
    connect(&displaySink, SIGNAL(signalSendPacket(uchar, uchar, uchar)), SoftStep, SLOT(slotSendMIDI(uchar, uchar, uchar))); // , Qt::DirectConnection);


    //Hosted Key Pressed Source Routing, Nav Y sources
    for(int k = 0; k < 10; k++)
    {
        //Nav Y sources
        connect(&navKey->dataCooker, SIGNAL(signalNavDecade(int)), key[k]->dataCooker, SLOT(slotReceiveNavDecade(int)));
        connect(&navKey->dataCooker, SIGNAL(signalNavY(int)), key[k]->dataCooker, SLOT(slotReceiveNavY(int)));

        for(int l = 0; l < 10; l++)
        {
            connect(key[k]->dataCooker, SIGNAL(signalThisKeyPressed(int)), key[l]->dataCooker, SLOT(slotReceiveKeyPressed(int)));
        }
    }

#endif // MIDI_ENABLED

#endif // end KEYS_ENABLED

    //connect the preset interface to the preset menu
    connect(ui->presetmenu, SIGNAL(currentIndexChanged(int)), this, SLOT(slotStoreLastSelectedPreset(int)));
    connect(presetInterface, SIGNAL(signalPresetMenu(int)), this, SLOT(slotSetPresetMenu(int)));
    connect(copyPasteHandler, SIGNAL(signalPresetMenu(int)), this, SLOT(slotSetPresetMenu(int)));
    connect(importOldPresetHandler, SIGNAL(signalPresetMenu(int)), this, SLOT(slotSetPresetMenu(int)));

    //---------- Pedal Calibration
    connect(settingsWindow, SIGNAL(signalRecallSettings(QVariantMap)), pedalCalWindow, SLOT(slotLoadJSONCalibrationValues(QVariantMap)));


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////// Preset Storage, Recall //////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //--------------------------------------- Preset Recall
    //MainWindow -- display name
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), this, SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
#ifdef KEYS_ENABLED
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
    connect(setlist, SIGNAL(signalFixDropDownWidth(QComboBox*)), this, SLOT(slotFixDropDownWidth(QComboBox*)));

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
        //connect(this, SIGNAL(signalSelectedKeyOutline(int,bool)), key[i], SLOT(slotSelectedKeyOutline(int,bool)));
    }
    connect(copyPasteHandler, SIGNAL(signalSetSelectedKey(int)), this, SLOT(slotSelectedKey(int)));
#endif // KEYS_ENABLED

    qDebug() << "------------ [CONNECT SAVE/DELETE/ETC] ---------------------------------------------------";

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

    qDebug() << "------------ [CONNECT SETLIST] ---------------------------------------------------";

    //setlist
    connect(ui->opensetlist, SIGNAL(clicked()), setlist, SLOT(slotShowSetlist()));
    connect(presetInterface, SIGNAL(signalPopulateSetlistMenus(QComboBox*)), setlist, SLOT(slotPopulateSetlistMenus(QComboBox*)));



    //Version Checking
    // EB note - these are also commented out in EZ, not necessary anymore
    //connect(midiDeviceManager, SIGNAL(signalProcessFwQueryReply(QByteArray)), sysExComposer, SLOT(slotGetConnectedVersion(QByteArray)));
    //connect(sysExComposer, SIGNAL(signalSendBuildNums(int,QString, int, QString, int)), this, SLOT(slotReceiveVersions(int,QString, int, QString, int)), Qt::DirectConnection);






    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////// Settings ////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    connect(ui->opensettings,SIGNAL(clicked()),settingsWindow,SLOT(slotOpenSettings()));
#ifdef KEYS_ENABLED
    //Keys
    for(int i = 0; i < 10; i++)
    {
        //Globals
        connect(settingsWindow, SIGNAL(signalSetGlobalGain(float)), key[i]->dataCooker, SLOT(slotSetGlobalGain(float)));
        connect(settingsWindow, SIGNAL(signalSetSensorResponse(int)), key[i]->dataCooker, SLOT(slotSetSensorResponse(int)));
        connect(settingsWindow, SIGNAL(signalSetKeySafetyMode(int)), key[i]->dataCooker, SLOT(slotSetKeySafetyMode(int)));

        connect(settingsWindow, SIGNAL(signalSetKeyOnThresh(int,int)), key[i]->dataCooker, SLOT(slotSetOnThresh(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyOffThresh(int,int)), key[i]->dataCooker, SLOT(slotSetOffThresh(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyXAccel(int,int)), key[i]->dataCooker, SLOT(slotSetXAccel(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyXDeadZone(int,int)), key[i]->dataCooker, SLOT(slotSetXDeadZone(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyYAccel(int,int)), key[i]->dataCooker, SLOT(slotSetYAccel(int,int)));
        connect(settingsWindow, SIGNAL(signalSetKeyYDeadZone(int,int)), key[i]->dataCooker, SLOT(slotSetYDeadZone(int,int)));


    }

//    // this was inside of the Keys for loop, but only key[0] deals with an expression pedal object
//    connect(settingsWindow, SIGNAL(signalStartCalibration()), key[0]->dataCooker->pedal, SLOT(slotStartCalibrate()));
//    connect(settingsWindow, SIGNAL(signalResetCalibration()), key[0]->dataCooker->pedal, SLOT(slotResetCalibrate()));

//    //Pedal Calibration file read/write
//    connect(settingsWindow, SIGNAL(signalInitPedalTable(QByteArray)), key[0]->dataCooker->pedal, SLOT(slotInitPedalTable(QByteArray)));

    //----- Pedal Nav Pad
    //connect(settingsWindow, SIGNAL(signalStartCalibration()), &navKey->dataCooker->pedal, SLOT(slotStartCalibrate()));
    //connect(settingsWindow, SIGNAL(signalResetCalibration()), &navKey->dataCooker->pedal, SLOT(slotResetCalibrate()));

    //Pedal Calibration file read/write
#ifdef PEDAL_ENABLED
    connect(settingsWindow, SIGNAL(signalInitPedalTable(QByteArray)), &navKey->dataCooker->pedal, SLOT(slotInitPedalTable(QByteArray)));
#endif // PEDAL_ENABLED
    //Pedal -- only connect key 0, we only need one data stream, while there are multiple instances of the Pedal class
    //connect(key[0]->dataCooker->pedal, SIGNAL(signalLivePedalVal(int)), settingsWindow, SLOT(slotSetLiveValue(int)), Qt::QueuedConnection);
    //connect(settingsWindow, SIGNAL(signalStopCalibration()), key[0]->dataCooker->pedal, SLOT(slotStopCalibrate()));
    //connect(key[0]->dataCooker->pedal, SIGNAL(signalWriteTableToDisk(QByteArray)), settingsWindow, SLOT(slotWritePedalTableToDisk(QByteArray)));

    //connect(key[0]->dataCooker->pedal, SIGNAL(signalResetOnZeroInput()), settingsWindow, SLOT(slotResetCalibration()), Qt::QueuedConnection);

#endif // end KEYS_ENABLED

    qDebug() << "------------ [CONNECT SYSEXCOMPOSER TO SETTINGS WINDOW] ---------------------------------------------------";
    connect(sysExComposer, SIGNAL(signalStartStandaloneCalibration()), settingsWindow, SLOT(slotStartCalibrationStandAlone()));
    //connect(sysExComposer, SIGNAL(signalStopStandaloneCalibration()), settingsWindow, SLOT(slotStopCalibrationStandAlone()));

    connect(settingsWindow, SIGNAL(signalUpdateSettings()), this, SLOT(slotUpdateSettings()));

    connect(settingsWindow, SIGNAL(signalTetherOnOffInStandalone(bool)), sysExComposer, SLOT(slotTetherOnOffInStandalone(bool)));
#ifdef KEYS_ENABLED
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
#endif // end KEYS_ENABLED

    //------------- Scene Change on/off sysex command
    connect(settingsWindow, SIGNAL(signalSetSceneChanging(bool)), sysExComposer, SLOT(slotSceneChangeOnOff(bool)));
    connect(settingsWindow, SIGNAL(signalSetBacklight(bool)), sysExComposer, SLOT(slotBackLightOnOff(bool)));
#ifdef MIDI_AUX_ENABLED
    // MIDI Aux Inputs
    connect(settingsWindow, SIGNAL(signalUpdateMIDIAuxDropdowns(QString, QString)), this, SLOT(slotUpdateMIDIAuxInputPorts(QString, QString)));
    connect(settingsWindow, SIGNAL(signalUserChangedMIDIaux(QString, QString)), this, SLOT(slotUserUpdatedMIDIAuxInputPort(QString, QString)));
#endif // end MIDI_AUX_ENABLED
#ifdef OSC_ENABLED
    //----------------------------- OSC
    connect(settingsWindow, SIGNAL(signalSetOscAddress(int,QString)), oscInterface, SLOT(slotSetOSCAddressTags(int,QString)));
    connect(settingsWindow, SIGNAL(signalSetOscEnable(int,bool)), oscInterface, SLOT(slotSetInputEnable(int,bool)));
    connect(settingsWindow, SIGNAL(signalSetOscInPort(int)), oscInterface, SLOT(slotSetInputPort(int)));
    connect(settingsWindow, SIGNAL(signalSetOscIP(QString)), oscInterface, SLOT(slotSetOutputIPAddress(QString)));
    connect(settingsWindow, SIGNAL(signalSetOscOutPort(int)), oscInterface, SLOT(slotSetOutputPort(int)));

    //Osc live input vals
    connect(oscInterface, SIGNAL(signalSetOSCDisplayValue(int,int)), settingsWindow, SLOT(slotSetOSCDisplayValue(int,int)));

#ifdef KEYS_ENABLED
    //Connect Osc to keys, vice versa
    for(int i = 0; i < 10; i++)
    {
        connect(oscInterface, SIGNAL(signalSendOscMessageToSource(int,int)), key[i]->dataCooker, SLOT(slotReceiveOscInput(int,int)));

        //Handles output from modlines
        for(int j = 0; j < 6; j++)
        {
            connect(key[i]->modline[j], SIGNAL(hosted_signalOSC(QString,int)), oscInterface, SLOT(slotWriteDatagram(QString,int)));
        }
    }

    //Connect Osc to nav pad
    connect(oscInterface, SIGNAL(signalSendOscMessageToSource(int,int)), &navKey->dataCooker, SLOT(slotReceiveOscInput(int,int)));

    //OSC output


#endif // end KEYS_ENABLED
#endif // end OSC_ENABLED

    //---------- Pedal Calibration
    connect(pedalCalWindow, SIGNAL(signalStoreValue(QString,QVariant)), settingsWindow, SLOT(slotStoreSettings(QString,QVariant)));
    connect(pedalCalWindow, SIGNAL(signalSendCalibration()), this, SLOT(slotUpdateSettings()));
    connect(pedalCalWindow, SIGNAL(signalSaveCalibration()), settingsWindow, SLOT(slotWriteSettings()));


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////// Dialogs /////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////         Menu Bar        /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::slotInitMenuBar()
{
    qDebug() << "slotInitMenuBar called";
    menubar = new QMenuBar(this);

#ifndef Q_OS_MAC
    QFile menuStyleFile = QFile(":/resources/menuBarWin.qss");
    QString menuStyleString;

    if (menuStyleFile.open(QFile::ReadOnly))
    {
        menuStyleString = QLatin1String(menuStyleFile.readAll());
        menubar->setStyleSheet(menuStyleString);

        //qDebug() << "menubar stylesheet: " << menubar->styleSheet();
    }
    else
    {
        qDebug() << "ERROR - Could not find menubar stylesheet: " << menuStyleString;
    }

    menubar->setGeometry(0,0, this->width(), 25);
#endif


    //-------------------------------------------------------------------------- File
    QMenu* file = new QMenu("File");
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

    openAppDataDir = new QAction("Open Editor Preset Directory", file);
    openAppDataDir->setObjectName("openAppDataDir");
    connect(openAppDataDir, SIGNAL(triggered()), this, SLOT(slotOpenPresetDirectory()));
    file->addAction(openAppDataDir);

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
    copyPresetAct->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_C));
    connect(copyPresetAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotCopyPreset()));
    //copyPresetAct->setDisabled(true);

    pastePresetAct = new QAction("Paste Preset", edit);
    actionList.append(pastePresetAct);
    edit->addAction(pastePresetAct);
    pastePresetAct->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_V));
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
    copyKeyAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    connect(copyKeyAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotCopyKey()));
    copyKeyAct->setDisabled(true);

    pasteKeyAct = new QAction("Paste Key", edit);
    actionList.append(pasteKeyAct);
    edit->addAction(pasteKeyAct);
    pasteKeyAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_V));
    connect(pasteKeyAct, SIGNAL(triggered()), copyPasteHandler, SLOT(slotPasteKey()));
    pasteKeyAct->setDisabled(true);

    //-------------------------------------------------------------------------- Hardware
    QMenu* hardware = new QMenu("Hardware");
    hardware->setObjectName("HardwareMenu");

    //reset settings
    resetSettings = new QAction("Reset Settings to Default", hardware);
    actionList.append(resetSettings);
    connect(resetSettings, SIGNAL(triggered()), this, SLOT(slotResetSettings()));
    hardware->addAction(resetSettings);

    //pedal calibration
    openPedalCalibration = new QAction("Calibrate Expression Pedal", hardware);
    actionList.append(openPedalCalibration);
    hardware->addAction(openPedalCalibration);

    //openPedalCalibration->setDisabled(true);

    //cv calibration
    openCVCalibration = new QAction("Calibrate CV Outs", hardware);
    actionList.append(openCVCalibration);
    hardware->addAction(openCVCalibration);
#ifndef ENABLE_SS3_HARDWARE_OPTIONS
    //openCVCalibration->setDisabled(true);
#endif
    openCVCalibration->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_O));

    connect(openPedalCalibration,  SIGNAL(triggered()), pedalCalWidget, SLOT(raise()));
    connect(openPedalCalibration,  SIGNAL(triggered()), pedalCalWidget, SLOT(show()));
    connect(openPedalCalibration, SIGNAL(triggered()), pedalCalWindow, SLOT(show()));
    connect(pedalCalWindow,  SIGNAL(signalWindowClosed()), pedalCalWidget, SLOT(hide()));

    connect(openPedalCalibration, SIGNAL(triggered()), this, SLOT(slotEnableTether()));
    connect(pedalCalWindow,  SIGNAL(signalWindowClosed()), this, SLOT(slotDisableTether()));

    connect(openCVCalibration,  SIGNAL(triggered()), cvCalWidget, SLOT(raise()));
    connect(openCVCalibration,  SIGNAL(triggered()), cvCalWidget, SLOT(show()));
    connect(openCVCalibration, SIGNAL(triggered()), cvCalWindow, SLOT(show()));
    connect(openCVCalibration, SIGNAL(triggered()), cvCalWindow, SLOT(slotGetDeviceCVCalibration()));

    connect(cvCalWindow,  SIGNAL(signalWindowClosed()), cvCalWidget, SLOT(hide()));

    // this is a pointer in settings, it needs to be set up before this is connected
    connect(settingsWindow, SIGNAL(signalUpdateNRPNChannel(int)), cvCalWindow, SLOT(slotUpdateNRPNChannel(int)));

    //Reload Firmware
    updatefw = new QAction("Force Firmware Update...", hardware);
    actionList.append(updatefw);
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(raise()));
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(updatefw, SIGNAL(triggered()), this, SLOT(slotForceFirmwareUpdate()));
    //connect(updatefw, SIGNAL(triggered()), this, SLOT(slotEnableDisableMenu()));
    hardware->addAction(updatefw);
    menubar->addMenu(hardware);

    // Submenu for selecting options
    QMenu* selectOptionMenu = new QMenu("Display Hardware Revision", hardware);
    QActionGroup* optionGroup = new QActionGroup(selectOptionMenu);
    optionGroup->setExclusive(true);

    // Helper lambda to create a checkable action and set its data
    auto createAction = [&](const QString &text, const QVariant &data) {
        QAction* action = new QAction(text, selectOptionMenu);
        action->setCheckable(true);
        action->setData(data);
        selectOptionMenu->addAction(action);
        optionGroup->addAction(action);
        return action;
    };

    // Create actions with identifiers
    createAction("SoftStep 1/2", "SoftStep 1/2");
    createAction("SoftStep 3", "SoftStep 3");
    createAction("Auto Detect", "Auto Detect");

    // Connect all actions to a single slot
    connect(optionGroup, &QActionGroup::triggered, this, [this](QAction *action) {
        QString selectedOption = action->data().toString();
        this->slotPortOptionSelected(selectedOption);
    });

    // Add the submenu to the hardware menu
    hardware->addMenu(selectOptionMenu);

    // Setting the initial selected option based on previous settings
    QString selectedOption = sessionSettings->value("HW_PORT_DISPLAY", "Auto Detect").toString();
    foreach(QAction *action, optionGroup->actions()) {
        if(action->data().toString() == selectedOption) {
            action->setChecked(true);
            break;
        }
    }

    // Add the submenu to the hardware menu
    hardware->addMenu(selectOptionMenu);

    // advanced
    // Assuming 'hardware' is already created and is a QMenu*
    QMenu *advancedMenu = hardware->addMenu(tr("Advanced"));

    // Create a checkable menu action for "Ignore FW Version Checks"
    QAction *ignoreFWCheckAction = new QAction(tr("Ignore Firmware Version Checks"), this);
    ignoreFWCheckAction->setCheckable(true);

    // Retrieve the current setting and set the checkbox state
    bool isIgnored = sessionSettings->value("IGNORE_FW_CHECKS", false).toBool();
    ignoreFWCheckAction->setChecked(isIgnored);

    // Add the action to the "Advanced" submenu
    advancedMenu->addAction(ignoreFWCheckAction);

    connect(ignoreFWCheckAction, &QAction::triggered, this, [this, ignoreFWCheckAction]()
    {
        bool checked = ignoreFWCheckAction->isChecked();
        sessionSettings->setValue("IGNORE_FW_CHECKS", checked);

        if (checked) {
            slotCreateDialog(QString("WARNING: This feature is experimental and\nmay produce unexpected results!"));
        }
    });

    // Adding the hardware menu to the menubar
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

    //Troubleshooting
    QAction* troubleShooting = new QAction("Troubleshoot Connection", help);
    connect(troubleShooting, SIGNAL(triggered()), this, SLOT(slotOpenTroubleshooting()));
    connect(ui->connectedLabel, SIGNAL(pressed()), this, SLOT(slotOpenTroubleshooting()));
    help->addAction(troubleShooting);

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
            toolTipsEnable = new QAction("Hide Tool Tips", help);
            qDebug() << "Hide Tool Tips";
        }
        else
        {
            toolTipsEnable = new QAction("Show Tool Tips", help);
            qDebug() << "Show Tool Tips";
        }
    }
    else
    {
        sessionSettings->setValue("toolTipsEnabled", true);
        toolTipsEnable = new QAction("Hide Tool Tips", help);
    }

    connect(toolTipsEnable, SIGNAL(triggered()), this, SLOT(slotEnableDisableToolTips()));

    help->addAction(toolTipsEnable);

    menubar->addMenu(help);

    menubar->show();
}

void MainWindow::slotPortOptionSelected(QString selectedOption)
{
    sessionSettings->setValue("HW_PORT_DISPLAY", selectedOption);
    slotUpdateSSHardwareRevStrings();
    slotPopulateDeviceMenus(externalDests); // update menus
}

void MainWindow::slotOpenPresetDirectory()
{
    QString presetDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDesktopServices::openUrl(QUrl::fromLocalFile(presetDir));
}

void MainWindow::slotEnableDisableToolTips()
{
    if(sessionSettings->value("toolTipsEnabled").toBool())
    {
        qDebug() << "slotEnableDisableToolTips called - turn off tool tips";
        toolTipsEnable->setText("Show Tool Tips");
        sessionSettings->setValue("toolTipsEnabled", false);
        scrollEventFilter.toolTipsOn = false;
    }
    else
    {
        qDebug() << "slotEnableDisableToolTips called - turn on tool tips";
        toolTipsEnable->setText("Hide Tool Tips");
        sessionSettings->setValue("toolTipsEnabled", true);
        scrollEventFilter.toolTipsOn = true;
    }
}

void MainWindow::slotResetSettings()
{
    qDebug() << "slotResetSettings called";

    kmiEncode->slotEncodePacket(MSG_CAT_LEGACY, RESET_SETTINGS, 0, 0); // this will reset the settings and globals

    settingsWindow->slotCloseSettings();

    // exit hosted mode, this method reminds me how frankensteined this code has become...
    mode = "hosted";
    slotSetMode();
    slotTether(false, SA_SAVE_YES); // this re-sends the settings to correctly put us in standalone mode, and saves those to the globals library on the softstep

    settingsWindow->slotWriteDefaultSettings();
    settingsWindow->slotRecallSettings();
    settingsWindow->slotOpenSettings();
}

void MainWindow::slotOpenDoc()
{
    QDesktopServices::openUrl(QUrl("http://files.keithmcmillen.com/products/softstep/Manuals/SoftStep_Manual_v3.0.pdf"));
}

void MainWindow::slotOpenTroubleshooting()
{
    troubleshootWindow->show();
    troubleshootWindow->slotScrollTroubleUp();
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
        bool thisState = (selectedKey != i) ? false: true;

        key[i]->slotSelectedKeyOutline(thisState);


//        {
//            qDebug() << "from mainwindow.cpp/slotSelectedKey - key/bool" << i << "false";
//            emit signalSelectedKeyOutline(selectedKey, false);
//        }
    }
//    qDebug() << "from mainwindow.cpp/slotSelectedKey - key/bool" << selectedKey << "true";
//    emit signalSelectedKeyOutline(selectedKey, true);

    copyKeyAct->setDisabled(false);
}

void MainWindow::slotUpdateAboutWindow()
{
    qDebug() << "slotUpdateAboutWindow called";
    aboutForm->aboutTitle->setText(QString("SoftStep Advanced Editor\nv%1.%2.%3")
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

unsigned char MainWindow::slotSSHardwareToDisplay()
{
    QString selectedOption = sessionSettings->value("HW_PORT_DISPLAY", "Auto Detect").toString();

    unsigned char thisSSHardware = SS_3;
    if (selectedOption == "SoftStep 1/2")
    {
        thisSSHardware = SS_2;
    }
    else if (selectedOption == "SoftStep 3")
    {
        thisSSHardware = SS_3;
    }
    else if (selectedOption == "Auto Detect")
    {
        thisSSHardware = ssHardware;
    }
    return thisSSHardware;
}

void MainWindow::slotUpdateSSHardwareRevStrings()
{
    qDebug() << "SoftStep Hardware Revision: " << ssHardware << " PID: " << SoftStep->PID_MIDI;

    unsigned char thisSSHardware = slotSSHardwareToDisplay();
    presetInterface->ssHardware = thisSSHardware;

    // update modline destinations
    for (int k = 0; k < 10; k++)
    {
        key[k]->dataCooker->SS_HW_VER = thisSSHardware;
        for (int m = 0; m < NUM_MODLINES_PER_KEY; m++)
        {
            key[k]->modline[m]->ssHardware = thisSSHardware;
        }
    }

    for (int m = 0; m < NUM_MODLINES_PER_KEY; m++)
    {
        navKey->navModline[m]->ssHardware = thisSSHardware;
    }

    // update SS3 specific UI
    if (thisSSHardware == SS_3)
    {
        openCVCalibration->setDisabled(false);

        this->setFixedSize(MAINWINDOW_WIDTH_SS3, MAINWINDOW_HEIGHT);
    }
    else
    {
        openCVCalibration->setDisabled(true);

        this->setFixedSize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);
    }
}

void MainWindow::slotConnected(bool connection)
{
    //qDebug() << "slot connected: " << connection;
    if(connection)
    {
        ui->connectedLabel->setText("SOFTSTEP CONNECTED");
        //ui->connectedLabel->setToolTip("\\(^-^)/");
#ifdef Q_OS_MAC
        ui->connectedLabel->setStyleSheet("font:12pt \"Futura\";color: rgba(0,200,0,255); background: rgba(40, 40, 40, 255); padding-top: 2px; padding-bottom: 2px;");
#else
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(0,200,0,255); background: rgba(40, 40, 40, 255); padding-top: 2px; padding-bottom: 2px;");
#endif
        connected = true;
        slotUpdateAboutWindow();

        updatefw->setEnabled(true);
        sysExComposer->connected = true;

#ifdef Q_OS_WIN
        if (SoftStep->firmwareUpdateState != FWUD_STATE_SUCCESS) // on windows reboot app after fw update, don't send any sysex during this process
        {
#endif
            if (cvCalWindow != nullptr)
            {
                cvCalWindow->slotGetDeviceCVCalibration(); // update when connected
            }
#ifdef Q_OS_WIN
        }
#endif

        //sysExComposer->slotRequestPedalCalibration(); // grab the pedal calibration
        slotUpdateSettings(); // send the current settings on connect

#ifdef MIDI_ENABLED
        // here we detect which version of SoftStep we are connected to
        switch (SoftStep->PID_MIDI)
        {
            case PID_SOFTSTEP1:
                ssHardware = SS_1;
            break;
            case PID_SOFTSTEP2:
                ssHardware = SS_2;
            break;
            case PID_SOFTSTEP3:
                ssHardware = SS_3;
            break;
        }

        sessionSettings->setValue("LAST_SS_REV_CONNECTED", ssHardware);
        slotUpdateSSHardwareRevStrings();


#endif // MIDI_ENABLED

        sysExComposer->slotHostedOnOff(mode == "hosted" ? true : false);

        slotRestoreAllAuxDropdowns();
        troubleshootWindow->slotConnected(true);
    }
    else // disconnect
    {
        ui->connectedLabel->setText("SOFTSTEP NOT CONNECTED");
        //ui->connectedLabel->setToolTip("[ o_0 ]");

#ifdef Q_OS_MAC
        //ui->connectedLabel->move(529, 81);
        ui->connectedLabel->setStyleSheet("font:12pt \"Futura\";color: rgba(200,200,200,255); background: rgba(40, 40, 40, 255); padding-top: 2px; padding-bottom: 2px;");
#else
        //ui->connectedLabel->move(529, 100);
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(200,200,200,255); background: rgba(40, 40, 40, 255); padding-top: 2px; padding-bottom: 2px;");
#endif
        updatefw->setEnabled(false); // disable firmware update menu
        sysExComposer->connected = false; // stop sysExComposer from sending data
        troubleshootWindow->slotConnected(false);
    }
    slotUpdateAboutWindow();
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
    int index = ui->presetmenu->findText(presetName);
    ui->presetmenu->setCurrentIndex(index);
}

void MainWindow::slotDisplaySaveState(bool dirty)
{
#ifdef Q_OS_WIN
    QString dirtyStyle = "QToolButton{ background: rgb(255, 0, 0);color: white;border: 2px solid rgb(255,0,0);font: 10px \"Tahoma\";padding: 0,0,0,0;} QToolButton:pressed{ background: rgb(230, 0, 134);color: white;border: 2px solid rgb(230, 0, 134);font: 10px \"Tahoma\";padding: 0, 0, 0, 0;}";
    QString cleanStyle = "QToolButton{ background: rgb(40, 40, 40);color: white;border: 2px solid rgb(230,0,134);font: 10px \"Tahoma\";padding: 0,0,0,0;} QToolButton:pressed{ background: rgb(230, 0, 134);color: white;border: 2px solid rgb(230, 0, 134);font: 10px \"Tahoma\";padding: 0, 0, 0, 0;}";
#else
    QString dirtyStyle = "QToolButton { background: rgb(255, 0, 0); color: white; border: 2px solid rgb(255,0,0); font: 10pt \"Futura PT\"; padding: 0,0,0,0;} QToolButton:pressed{ background: rgb(230, 0, 134); color: white; border: 2px solid rgb(230, 0, 134); font: 10pt \"Futura PT\"; padding: 0, 0, 0, 0; }";
    QString cleanStyle = "QToolButton { background: rgb(40, 40, 40); color: white; border: 2px solid rgb(230,0,134); font: 10pt \"Futura PT\"; padding: 0,0,0,0;} QToolButton:pressed{ background: rgb(230, 0, 134); color: white; border: 2px solid rgb(230, 0, 134); font: 10pt \"Futura PT\"; padding: 0, 0, 0, 0; }";
#endif

    if(dirty)
    {
        //qDebug() << "the preset is dirty";
        ui->save->setStyleSheet(dirtyStyle);
    }
    else
    {
        //qDebug() << "the preset is no longer dirty";
        ui->save->setStyleSheet(cleanStyle);

    }
}

void MainWindow::slotSetMode()
{
    //Check mode
    if(mode == "standalone")
    {   
        // create virtual ports
#ifndef Q_OS_WIN
        SoftStepShare->slotCreateVirtualIn(SS_SHARE_PORT);
        SoftStepShare->slotCreateVirtualOut(SS_SHARE_PORT);
#endif

        int thisInPort = kmiPorts->getInPortNumber(SS_SHARE_PORT);
        int thisOutPort = kmiPorts->getOutPortNumber(SS_SHARE_PORT);
        qDebug() << "Connect SoftStep Share - port in: " << thisInPort << " port out: " << thisOutPort;

        if (thisOutPort == -1)
        {
#ifdef Q_OS_WIN
            if (!appStillLoading)
            {
                slotNoSharePortDialog();
            }
#endif
        }
        else
        {
#ifdef Q_OS_WIN
            SoftStepShare->slotUpdatePortIn(thisInPort);
            SoftStepShare->slotUpdatePortOut(thisOutPort);
#endif
            mode = "hosted";
            ui->cv1label_sources->hide();
            ui->cv2label_sources->hide();
            ui->cv1_sources->hide();
            ui->cv2_sources->hide();

            ui->mode->setText("Hosted");
        }
    }
    else
    {
        mode = "standalone";

        ui->cv1label_sources->show();
        ui->cv2label_sources->show();
        ui->cv1_sources->show();
        ui->cv2_sources->show();

        ui->mode->setText("Standalone");

        // close virtual ports
        if (SoftStepShare->port_in_open) SoftStepShare->slotCloseMidiIn(SIGNAL_NONE);
        if (SoftStepShare->port_out_open) SoftStepShare->slotCloseMidiOut(SIGNAL_NONE);
    }

    // store value for next time we open editor
    sessionSettings->setValue("previousMode", mode);

    //----------------- Set child modes

    //Settings
    settingsWindow->slotSetMode(mode);
#ifdef KEYS_ENABLED
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
#endif // end TURNED OFF

    slotSetModeMIDI(mode); //repopulation of device menus should happen here, also reloads preset

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
    populatingPresetMenus = true; // flag to pause storing the last preset selected
    presetInterface->slotPopulatePresetMenu(ui->presetmenu); //Also calls setlist->slotPopulateSetlistMenus()

    //Set each setlist menu to correct item
    setlist->slotRefreshSetlistMenus(ui->presetmenu);

    populatingPresetMenus = false;

    //Enable/Disable the update button
    if(mode == "hosted")
    {
        ui->update->setEnabled(false);
    }
    else
    {
        ui->update->setEnabled(true);
    }


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
#ifdef KEYS_ENABLED
        for(int k = 0; k < 10; k++)
        {
            //If init has been called previously, each instance of stateRecaller blocks re-initialization
            key[k]->stateRecaller.slotInit(presetNames, k);
        }
#endif // end TURNED OFF
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

    //slotRecallLastSelectedPreset();

    settingsWindow->slotEmitAllSettings();

    //----------------- repopulate midi aux inputs
    if (mode == "hosted")
    {
        slotRestoreAllAuxDropdowns();
    }
    slotRecallMIDIThru();
}

void MainWindow::slotPopulateDeviceMenus(QMap<QString, int> externalDevices)
{
//    qDebug() << "-------------------------------- populate device menus";
//    qDebug() << externalDevices;
//    qDebug() << "------------------------------------------------------";

    QMap<QString, int> standaloneDevices;
    standaloneDevices.insert("SoftStep USB MIDI", 0);
    unsigned char thisSSHardware = slotSSHardwareToDisplay();
    if (thisSSHardware == SS_3)
    {
        standaloneDevices.insert("SoftStep TRS MIDI Out", 1);
        standaloneDevices.insert("SoftStep CV Out", 2);
    }
    else
    {
        standaloneDevices.insert("SoftStep Expander", 1);
    }


#ifdef KEYS_ENABLED
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
            navKey->navModline[n]->hosted_slotPopulateDeviceMenu(standaloneDevices);
        }

        //reconnect to slotValueChanged
        navKey->navModline[n]->slotConnectElements();
    }
#endif // end KEYS_ENABLED
    slotRecallLastSelectedPreset();
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
    standaloneSources.append("Random");
    standaloneSources.append("Random Single");
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

    hostedSources.append("Random");
    hostedSources.append("Random Single");

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

    standaloneTables.append("Random");

    // Appending scale names
    standaloneTables.append("Major");
    standaloneTables.append("Natural Minor");
    standaloneTables.append("Harmonic Minor");
    standaloneTables.append("Dorian");
    standaloneTables.append("Phrygian");
    standaloneTables.append("Lydian");
    standaloneTables.append("Mixolydian");
    standaloneTables.append("Locrian");

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

    hostedTables.append("Random");
    //hostedTables.append("Random Single");

    // Appending scale names
    hostedTables.append("Major");
    hostedTables.append("Natural Minor");
    hostedTables.append("Harmonic Minor");
    hostedTables.append("Dorian");
    hostedTables.append("Phrygian");
    hostedTables.append("Lydian");
    hostedTables.append("Mixolydian");
    hostedTables.append("Locrian");

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

void MainWindow::slotUpdateSettings()
{
    //qDebug() << "slotUpdateSettings called";
    sysExComposer->slotComposeSettings(settingsWindow->settings, settingsWindow->pedalValueListGraph);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////       Key Lockout       /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::slotLockoutKeyPressedReleased(int keyNumber, bool pressedReleased)
{
    //qDebug() << "slotLockoutKeyPressedReleased called from MainWindow" << keyNumber << pressedReleased;
#ifdef KEYS_ENABLED

    for(int i = 0; i < 10; i++)
    {
        //If key sending message is being pressed
        if(pressedReleased) // pressed == TRUE
        {
            //If the keyNumber is not listed in current keys pressed
            if(!key[i]->dataCooker->lockoutKeysPressed.contains(keyNumber))
            {
                //Add it to our lockout list
                key[i]->dataCooker->lockoutKeysPressed.append(keyNumber);
            }
        }

        //If key sending message is being released
        else
        {
            //If key number is listed in current keys pressed (should always be the case)
            if(key[i]->dataCooker->lockoutKeysPressed.contains(keyNumber))
            {
                key[i]->dataCooker->lockoutKeysPressed.removeAt(key[i]->dataCooker->lockoutKeysPressed.indexOf(keyNumber));
            }           //Trying to remove key from lockout list that is not present
            else
            {
                //qDebug() << "WARNING: trying to remove key from lockout list that is not present";
            }

        }

        //qDebug() << key[i]->dataCooker.lockoutKeysPressed;
    }
#endif // end KEYS_ENABLED
}

void MainWindow::slotDisconnectUpdate()
{
    qDebug() << "slotDisconnectUpdate called";
    ui->update->setEnabled(false);
    disconnect(ui->update, SIGNAL(clicked()), this, SLOT(slotDisconnectUpdate()));
    slotUpdatePresets();
}

void MainWindow::slotConnectUpdate()
{
    qDebug() << "slotConnectUpdate called";
    connect(ui->update, SIGNAL(clicked()), this, SLOT(slotDisconnectUpdate()));
    ui->update->setEnabled(true);
}


// -----------------------------
// Signal softstep hosted/standalone modes - create and delete virtual midi port
// -----------------------------

void MainWindow::slotSetModeMIDI(QString m)
{

    qDebug() << "slot set mode: " << m;

    if(m == "hosted")
    {
        sysExComposer->slotHostedOnOff(true);
    }
    else
    {


        sysExComposer->slotHostedOnOff(false);
    }

    slotPopulateDeviceMenus(externalDests); // update menus
}


// --------------------------------------------------------------------------------------
// ------ midi overhaul -----------------------------------------------------------------
// --------------------------------------------------------------------------------------

void MainWindow::slotMIDIPortChange(QString portName, uchar inOrOut, uchar messageType, int portNum)
{
#ifdef MIDI_ENABLED
    qDebug() << "slotMIDIPortChange - " << kmiPorts->mType[messageType] << kmiPorts->inOut[inOrOut] << " portName:" << portName << " messageType: " << " portNum: " << portNum << "\n";

    switch (messageType)
    {
    case PORT_CONNECT:

        // update dropdown
        if (inOrOut == PORT_OUT && portName != SS_OUT_P1) // don't create feedback loop
        {
            midi_thru_dropdown->addItem(portName); // update dropdown
            slotFixDropDownWidth(midi_thru_dropdown);

            if (portName == sessionSettings->value(MIDI_THRU_KEY).toString()) // if this port matches the last selected port
            {
                recallMidiThruPortName = portName; // store name
                //QTimer::singleShot(500, this, SLOT(slotRecallMIDIThru())); // wait, then set/update the port
            }

        }

        // **** SoftStep connect *****************************************
        if (inOrOut == PORT_IN && (portName == SS_IN_P1 || portName == SS_OLD_IN_P1 || portName == SS_BL_PORT))
        {
            SoftStep->slotSetExpectedFW(thisFw);

            troubleshootWindow->slotDetected();
            ui->connectedLabel->setText("SOFTSTEP DETECTED");
#ifdef Q_OS_MAC
            ui->connectedLabel->setStyleSheet("font: 12pt \"Futura-Normal\";"
                                              "color: yellow;"
                                              "background: rgb(255, 125, 0);"
                                              "padding: 0px 0px 0px 3px;");
#else
            ui->connectedLabel->setStyleSheet("font: 8pt \"Futura-Normal\";"
                                              "color: yellow;"
                                              "background: rgb(255, 125, 0);"
                                              "padding: 0px 0px 0px 3px;");
#endif

            if (SoftStep->installingBootloader == BL_INSTALL_PENDING && portName != SS_BL_PORT)
            {
                return; // don't try to connect to the bootloader installer v99
            }

#ifdef Q_OS_WIN
            if (SoftStep->firmwareUpdateState == FWUD_STATE_FW_SENT_WAIT && portName == SS_IN_P1)
            {
                SoftStep->firmwareUpdateState = FWUD_STATE_SUCCESS;
            }
#endif

            if (!SoftStep->slotUpdatePortIn(portNum))
            {
                slotCreateDialog(QString("ERROR: MIDI input port \"%1\"\nis currently being used by another program or process!").arg(portName));
            }
            else
            {
                fwUpdateWindow->slotAppendTextToConsole("\nSoftStep Connected\n");
            }
        }
        else if (inOrOut == PORT_OUT && (portName == SS_OUT_P1  || portName == SS_OLD_OUT_P1 || portName == SS_BL_PORT))
        {
            if (!SoftStep->slotUpdatePortOut(portNum))
            {
                slotCreateDialog(QString("ERROR: MIDI output port \"%1\"\nis currently being used by another program or process!").arg(portName));
            }
            else
            {
                if (portName == SS_OLD_OUT_P1)
                {
                    SoftStep->deviceName = "SSCOM";
                    if (SoftStep->fwVerPollSkipConnectCycles > 0)
                    {
                        SoftStep->fwVerPollSkipConnectCycles--;
                        qDebug() << "fwVerPollSkipConnectCycles = " << SoftStep->fwVerPollSkipConnectCycles;
                    }
                }
                else
                {
                    SoftStep->deviceName = "SoftStep";
                    SoftStep->fwVerPollSkipConnectCycles = 0; // don't skip if bootloader or new portname
                }
                //SoftStep->slotStartPolling("PORT CONNECT"); // start polling when output port is added
                SoftStep->pollingStatus = true;
            }
        }
        // hosted mode
        else if (inOrOut == PORT_IN && !portName.contains("SoftStep Hosted Virtual Port"))
        {
            midiInputSources.insert(portName, portNum); // store inputs
            settingsWindow->slotPopulateInputMenus(midiInputSources); // update settings dropdown menus
        }
        else if (inOrOut == PORT_OUT)
        {
            externalDests.insert(portName, portNum); // store destination
            slotPopulateDeviceMenus(externalDests); // update menus
        }

        break;
    case PORT_DISCONNECT:

        if (inOrOut == PORT_OUT)
        {
            // update dropdown
            if (midi_thru_dropdown->currentText() == portName)
            {
                midi_thru_dropdown->setCurrentIndex(0);
            }

            midi_thru_dropdown->removeItem(midi_thru_dropdown->findText(portName));
        }

        // **** SoftStep disconnect **************************************
        if (portName == SS_IN_P1 || portName == SS_OLD_IN_P1 || portName == SS_BL_PORT)
        {
            // close ports and stop polling
            if (inOrOut == PORT_IN && portName == SoftStep->portName_in) // fix for ports disconnecting late during firmware update
            {
                SoftStep->slotCloseMidiIn(SIGNAL_SEND);
                fwUpdateWindow->slotAppendTextToConsole("\nSoftStep Disconnected\n");

                ui->connectedLabel->setText("SOFTSTEP NOT CONNECTED");
        #ifdef Q_OS_MAC
                ui->connectedLabel->setStyleSheet("font: 12pt \"Futura-Normal\";"
                                                  "color: rgba(200,200,200,255);"
                                                  "padding-top: 2px; padding-bottom: 2px;"
                                                  "background: rgba(40, 40, 40, 255);");
        #else
                ui->connectedLabel->setStyleSheet("font: 8pt \"Futura-Normal\";"
                                                  "color: rgba(200,200,200,255);"
                                                  "padding-top: 2px; padding-bottom: 2px;"
                                                  "background: rgba(40, 40, 40, 255);");
        #endif
            }
            else if (portName == SoftStep->portName_out) // fix for ports disconnecting late during firmware update
            {
                SoftStep->slotCloseMidiOut(SIGNAL_SEND);
                SoftStep->pollingStatus = false;
            }
            else if (inOrOut == PORT_OUT)
            {
                ui->connectedLabel->setText("SOFTSTEP NOT CONNECTED");
        #ifdef Q_OS_MAC
                ui->connectedLabel->setStyleSheet("font: 12pt \"Futura-Normal\";"
                                                  "color: rgba(200,0,0,255);"
                                                  "padding-top: 2px; padding-bottom: 2px;"
                                                  "background: rgba(40, 40, 40, 255);");
        #else
                ui->connectedLabel->setStyleSheet("font: 8pt \"Futura-Normal\";"
                                                  "color: rgba(200,200,200,255);"
                                                  "padding-top: 2px; padding-bottom: 2px;"
                                                  "background: rgba(40, 40, 40, 255);");
        #endif
            }
        }
        // hosted mode
//        else if (inOrOut == PORT_IN && !portName.contains("SoftStep Share"))
//        {
//            midiInputSources.remove(portName); // delete portname from map
//            settingsWindow->slotPopulateInputMenus(midiInputSources); // update settings dropdown menus
//        }
        else if (inOrOut == PORT_OUT)
        {
            externalDests.remove(portName); // store destination
            slotPopulateDeviceMenus(externalDests); // update menus
        }

        break;
    case PORT_CHANGED:
        //qDebug() << " PORT CHANGED - name: " << portName << portName << " inOrOut: " << kmiPorts->inOut[inOrOut] << " messageType: " << kmiPorts->mType[messageType] << " portNum: " << portNum << "\n";

        if (SoftStep->installingBootloader == BL_INSTALL_PENDING && portName != SS_BL_PORT)
        {
            return; // don't try to connect to the bootloader installer v99
        }

        // **** SoftStep renumber ****************************************
        if ((portName == SS_IN_P1 || portName == SS_OLD_IN_P1 || portName == SS_BL_PORT) && inOrOut == PORT_IN)
        {
            if (!SoftStep->slotUpdatePortIn(portNum))
            {
                slotCreateDialog(QString("ERROR: MIDI input port \"%1\"\nis currently being used by another program or process!").arg(portName));
            }
        }
        else if ((portName == SS_OUT_P1  || portName == SS_OLD_OUT_P1 || portName == SS_BL_PORT) && inOrOut == PORT_OUT)
        {
            if (!SoftStep->slotUpdatePortOut(portNum))
            {
                slotCreateDialog(QString("ERROR: MIDI output port \"%1\"\nis currently being used by another program or process!").arg(portName));
            }
        }
        // Hosted mode
//        else if (inOrOut == PORT_IN && !portName.contains("SoftStep Hosted Virtual Port"))
//        {
//            // update input map
//            midiInputSources.remove(portName); // delete portname from map
//            midiInputSources.insert(portName, portNum); // store inputs

//            settingsWindow->slotPopulateInputMenus(midiInputSources); // update settings dropdown menus
//        }
        else if (inOrOut == PORT_OUT)
        {
            externalDests.remove(portName); // store destination
            externalDests.insert(portName, portNum); // store destination
            slotPopulateDeviceMenus(externalDests); // update menus
        }

        break;
    default:
        break;
    }
    slotRestoreAllAuxDropdowns();
#endif // MIDI_ENABLED
}

// close and then reopen the SoftStep ports
// this is needed when the bootloader and app port names do not match
void MainWindow::slotRefreshConnection()
{
//#ifdef MIDI_ENABLED
//    qDebug() << "slotRefreshConnection called";
//    if (!SoftStep->bootloaderMode) // app->bootLoader
//    {
//        SoftStep->slotResetConnections(SS_OLD_IN_P1, SS_BL_PORT);
//    }
//    else
//    {
//        SoftStep->slotResetConnections(SS_OUT_P1, SS_BL_PORT);
//    }
//#endif // MIDI_ENABLED
}


void MainWindow::slotBootloaderMode(bool fwUpdateRequested)
{
    qDebug() << "slotBootloaderMode called - fwUpdateRequested: "<< fwUpdateRequested;

    ui->connectedLabel->setText("BOOTLOADER");
#ifdef Q_OS_MAC
    ui->connectedLabel->setStyleSheet("font: 12pt \"Futura-Normal\";"
                                      "color: rgba(200,0,0,255);"
                                      "padding-top: 2px; padding-bottom: 2px;"
                                      "background: rgba(0, 0, 88, 255);");
#else
    ui->connectedLabel->setStyleSheet("font: 8pt \"Futura-Normal\";"
                                      "color: rgba(0,0,255,255);"
                                      "padding-top: 2px; padding-bottom: 2px;"
                                       "background: rgba(0, 0, 88, 255);");
#endif
    troubleshootWindow->slotSetDevVersion(deviceFirmwareVersionString(), deviceBootloaderVersionString());
    troubleshootWindow->slotBootloaderMode();

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

void MainWindow::relaunchApplication() {
    // Get the application's executable path and arguments
    QString appPath = QCoreApplication::applicationFilePath();
    QStringList args = QCoreApplication::arguments();

    // Remove the first argument, which is the path to the executable
    args.removeFirst();

    // Start a new instance of the application
    QProcess::startDetached(appPath, args);

    // Exit the current application instance
    QCoreApplication::quit();
}

#ifdef DEBUG_FW_BRICKED
void MainWindow::slotFirmwareDebugBricked() // called by fwUpdateWindow->signalFwUpdateSuccess()
{
    qDebug() << "Swapping FW files";
    static bool swapFw;

    swapFw = !swapFw;
    QString thisFwFile;

    if (swapFw)
    {
        thisFwFile = QString(":/firmware/Softstep_Firmware_v1.0.4.syx");
    }
    else
    {
        thisFwFile = QString(":/firmware/Softstep_Firmware_v2.0.2.syx");
    }

    qDebug() << "thisFwFile: " << thisFwFile;

    if (!SoftStep->slotOpenFirmwareFile(thisFwFile))
    {
       slotCreateDialog("Error: Firmware file not found!\n\nPlease re-install the SoftStep editor.");
    }

    // Create a one-shot timer
    QTimer *timerFwFile = new QTimer(this); // `this` assumes you're inside a QObject-derived class
    timerFwFile->setSingleShot(true);

    // Connect the timeout signal to a lambda function that triggers the update action
    connect(timerFwFile, &QTimer::timeout, this, [this]() {
        slotFirmwareDebugBricked2();
    });

    timerFwFile->start(1000); // Time in milliseconds
}

void MainWindow::slotFirmwareDebugBricked2() // called by fwUpdateWindow->signalFwUpdateSuccess()
{
    qDebug() << "Start timer to press DONE";
    // Create a one-shot timer
    QTimer *timerDone = new QTimer(this); // `this` assumes you're inside a QObject-derived class
    timerDone->setSingleShot(true);

    // Connect the timeout signal to a lambda function that triggers the update action
    connect(timerDone, &QTimer::timeout, this, [this]() {
        fwUpdateWindow->slotPressButtDone();
    });

    // Start the timer with a 5-second timeout
    timerDone->start(4000); // Time in milliseconds
}

void MainWindow::slotFirmwareDebugBricked3() // called by slotFwUpdateSuccessCloseDialog
{
    qDebug() << "Test and if idle, trigger another FW update...";
    if (SoftStep->firmwareUpdateState == FWUD_STATE_IDLE || SoftStep->firmwareUpdateState >= FWUD_STATE_SUCCESS)
    {
        slotUpdatePresets();
        updatefw->trigger();


        // Create a one-shot timer
        QTimer *timerRetrig = new QTimer(this); // `this` assumes you're inside a QObject-derived class
        timerRetrig->setSingleShot(true);

        // Connect the timeout signal to a lambda function that triggers the update action
        connect(timerRetrig, &QTimer::timeout, this, [this]() {
            slotFirmwareDebugBricked3();
        });
    }
}
#endif // DEBUG_FW_BRICKED

void MainWindow::slotFwUpdateSuccessCloseDialog(bool success)
{
    qDebug() << "slotFwUpdateSuccessCloseDialog called - success: " << success;

#ifdef DEBUG_FW_BRICKED
    static int fwSuccessCounter = 0;
#endif

    if (success)
    {
#ifdef DEBUG_FW_BRICKED
        fwSuccessCounter++;
        qDebug() << "---------- fwSuccessCounter: " << fwSuccessCounter << "----------------------------------";
#endif

        slotUpdateMIDIThru();
        slotConnected(true);

#ifdef DEBUG_FW_BRICKED
        // Create a one-shot timer
        QTimer *timerRetrig = new QTimer(this); // `this` assumes you're inside a QObject-derived class
        timerRetrig->setSingleShot(true);

        // Connect the timeout signal to a lambda function that triggers the update action
        connect(timerRetrig, &QTimer::timeout, this, [this]() {
            slotFirmwareDebugBricked3();
        });


        timerRetrig->start(4000); // Time in milliseconds
#endif // DEBUG_FW_BRICKED

#ifdef Q_OS_WINDOWS
        relaunchApplication();
#endif
    }
    else
    {
        SoftStep->slotFirmwareUpdateReset();
        slotConnected(false);
    }
    disableWidget->hide();
}

void MainWindow::slotForceFirmwareUpdate()
{
    if (!SoftStep->port_out_open) return;

    slotFirmwareDetected(SoftStep, false); // act as if we received a firmware mismatch
    forceFirmwareUpdate = true;
}

void MainWindow::slotFirmwareDetected(MidiDeviceManager *thisMDM, bool matches)
{
#ifdef MIDI_ENABLED
    qDebug() << "slotFirmwareDetected called";

    troubleshootWindow->slotSetDevVersion(deviceFirmwareVersionString(), deviceBootloaderVersionString());
    if (forceFirmwareUpdate)
    {
        troubleshootWindow->slotRequestFwUpdate();
        forceFirmwareUpdate = false;
    }

    if (matches)
    {
        qDebug() << "FirmwareMatch: " << thisMDM->PID << "name:" << thisMDM->deviceName;

        //---------------------------------- Sync SoftStep Dialog
        // MIDI Overhaul
        //slotSyncSoftStepDialog();
    }
    else
    {
        qDebug() << "Firmware MisMatch: " << thisMDM->PID << "name:" << thisMDM->deviceName;

        ui->connectedLabel->setText("FIRMWARE OUT OF DATE");
#ifdef Q_OS_MAC
        ui->connectedLabel->setStyleSheet("font: 12pt \"Futura-Normal\";"
                                          "color: red;"
                                          "background: rgb(50, 0, 0);"
                                          "padding: 0px 0px 0px 3px;");
#else
        ui->connectedLabel->setStyleSheet("font: 8pt \"Futura-Normal\";"
                                          "color: red;"
                                          "background: rgb(50, 0, 0);"
                                          "padding: 0px 0px 0px 3px;");
#endif
        fwUpdateWindow->slotClearText();
        fwUpdateWindow->slotAppendTextToConsole(deviceBootloaderVersionString());
        fwUpdateWindow->slotAppendTextToConsole(deviceFirmwareVersionString() + "\n\n");

        fwUpdateWindow->show();
#ifdef DEBUG_FW_BRICKED
        fwUpdateWindow->slotPressButtOk();
#endif
    }
#endif // MIDI_ENABLED
}

// connect SoftStep midi input to to midi thru
void MainWindow::slotUpdateMIDIThru()
{
#ifdef MIDI_ENABLED
    SoftStep->disconnect(SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)));

    QString currentPortName = midi_thru_dropdown->currentText();

    qDebug() << "slotUpdateMIDIThru called - currentPortName: " << currentPortName;

    if (currentPortName == "")
    {
        currentPortName = "None";
        midi_thru_dropdown->blockSignals(true);
        midi_thru_dropdown->setCurrentText(currentPortName);
        midi_thru_dropdown->blockSignals(false);
    }

    if (!SoftStep->connected) return; // don't continue if we aren't connected

    sessionSettings->setValue(MIDI_THRU_KEY, currentPortName); // store this setting for the next time we run the editor

    bool failure = false;

    int equivalentInPort = kmiPorts->getInPortNumber(currentPortName);

    if (currentPortName != "None")
    {
        // set and open the ports
        int thisOutPort = kmiPorts->getOutPortNumber(currentPortName);
        if (!MIDIThru->slotUpdatePortOut(thisOutPort)) // also opens the port
        {
            slotCreateDialog(QString("ERROR: MIDI output port \"%1\"\nis currently being used by another program or process!").arg(currentPortName));
            failure = true;
        }
        else
        {
            if (!MIDIThru->slotUpdatePortIn(equivalentInPort)) // also opens the port
            {
                slotCreateDialog(QString("ERROR: MIDI input port \"%1\"\nis currently being used by another program or process!").arg(currentPortName));
                failure = true;
            }
            else
            {
                connect(SoftStep, SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)), MIDIThru, SLOT(slotSendMIDI(uchar, uchar, uchar, uchar)));
            }
        }
    }
    else
    {
        MIDIThru->slotCloseMidiIn();
        MIDIThru->slotCloseMidiOut();
    }

    if (failure)
    {
        midi_thru_dropdown->blockSignals(true);
        midi_thru_dropdown->setCurrentText("None");
        midi_thru_dropdown->blockSignals(false);
        MIDIThru->slotCloseMidiIn();
        MIDIThru->slotCloseMidiOut();
    }
#endif // MIDI_ENABLED
}

QString MainWindow::deviceBootloaderVersionString()
{
#ifndef MIDI_ENABLED
    return "";
#endif
    return QString("Device Bootloader Version: %1.%2.%3\n\n")
            .arg(uchar(SoftStep->devicebootloaderVersion.at(0)))
            .arg(uchar(SoftStep->devicebootloaderVersion.at(1)))
            .arg(uchar(SoftStep->devicebootloaderVersion.at(2)));
}


QString MainWindow::deviceFirmwareVersionString()
{
#ifndef MIDI_ENABLED
    return "";
#endif

    return QString("Device Firmware Version: %1.%2.%3")
            .arg(uchar(SoftStep->deviceFirmwareVersion.at(0)))
            .arg(uchar(SoftStep->deviceFirmwareVersion.at(1)))
            .arg(uchar(SoftStep->deviceFirmwareVersion.at(2)));
}

QString MainWindow::applicationFirmwareVersionString()
{
#ifndef MIDI_ENABLED
    return "";
#endif
    return QString("Application Firmware Version: %1.%2.%3\n\n")
            .arg(uchar(thisFw.at(0)))
            .arg(uchar(thisFw.at(1)))
            .arg(uchar(thisFw.at(2)));
}

// Explicitly coded, single line functions for midi inputs
//
// Receive the input and call the master parse function with a identifier for the aux input
// These aux inputs represent up to 8 *different* MIDI ports that can be routed to the 8 settings window midi inputs.
//
// Because windows can't share ports among rtmidi instances, we have to capture the input port number and then
// route it to matching settings midi inputs

void MainWindow::slotParseMidiAuxIn_A(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_A", midiAuxIn[0]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_B(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_B", midiAuxIn[1]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_C(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_C", midiAuxIn[2]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_D(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_D", midiAuxIn[3]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_E(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_E", midiAuxIn[4]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_F(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_F", midiAuxIn[5]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_G(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_G", midiAuxIn[6]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_H(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_H", midiAuxIn[7]->port_in, status, d1, d2, chan); }

//void MainWindow::slotParseMidiAuxIn_H(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("aux_H", midiAuxIn[7]->port_in, status, d1, d2, chan); }
void MainWindow::slotParseMidiAuxIn_SoftStepShare(uchar status, uchar d1, uchar d2, uchar chan) { slotParseMidiAuxInputs("ss_Share", SoftStepShare->port_in, status, d1, d2, chan); }

void MainWindow::slotParseMidiAuxInputs(QString auxInput, int midiInputPortNumber, uchar status, uchar d1, uchar d2, uchar chan)
{
    //qDebug() << "slotParseMidiAuxInputs called - auxInput: " << auxInput << " midiInputPortNumber: " << midiInputPortNumber;

    // iterate through the settings window inputs, route this incomming message if the port numbers match
    for (int i = 0; i < 8; i++)
    {
        QString settingsInputPortName;

        if (auxInput == "ss_Share")
        {
            settingsInputPortName = "SoftStep Share";
        }
        else
        {
            settingsInputPortName = settingsWindow->midiInputLine[i].device;
        }

        int settingsInputPortNum = kmiPorts->getInPortNumber(settingsInputPortName);

        // limit calls to slotReceiveInput, even though it will match the input port number against the dropdown
        if (midiInputPortNumber == settingsInputPortNum)
        {
            //qDebug() << "port match - settings input port: " << i;
            settingsWindow->midiInputLine[i].slotReceiveInput(status, d1, d2, chan, settingsInputPortName);
        }
    }
}

void MainWindow::slotRestoreAllAuxDropdowns()
{
    // restore last set devices
    for (int i = 0; i < 8; i++)
    {
        QString thisPortName = sessionSettings->value(MIDI_AUX_KEY[i]).toString();
        //qDebug() << "Recall: " << MIDI_AUX_KEY[i] << " value: " << thisPortName;
        int thisPort = kmiPorts->getInPortNumber(thisPortName);
        if (thisPort != -1) // only repopulate ports that are connected
        {
            if (settingsWindow->midiInputDeviceMenus.at(i)->currentText() != thisPortName) // set once
            {
                settingsWindow->midiInputDeviceMenus.at(i)->setCurrentText(thisPortName);
            }
        }
    }
}

// only called if the user changed the dropdown, in which case we should update the app settings to remember the selection
void MainWindow::slotUserUpdatedMIDIAuxInputPort(QString auxInput, QString portName)
{
    int settingsInputIndex = auxInput.at(4).toLatin1() - 97; // index A = 0
    sessionSettings->setValue(MIDI_AUX_KEY[settingsInputIndex], portName); // remember this selection
    //qDebug() << "Saved: " << MIDI_AUX_KEY[settingsInputIndex] << " to: " << sessionSettings->value(MIDI_AUX_KEY[settingsInputIndex]).toString();
}

// auxInput - "midiX_device..." where X is A through H, the json name of the dropdown from the settings window
// portName - the input port for this input
//
// We only need to open the port if it hasn't already been opened by another midiAux[x] instance
//
// In general, the midiAux[x] instances are paired with the matching settings input, ie midiAux[0] and input A.

void MainWindow::slotUpdateMIDIAuxInputPorts(QString auxInput, QString portName)
{
#ifdef MIDI_AUX_ENABLED

    int settingsInputIndex = auxInput.at(4).toLatin1() - 97; // index A = 0
    int thisMidiInPortNumber = kmiPorts->getInPortNumber(portName);
    int oldPortNumber = midiAuxIn[settingsInputIndex]->port_in;
    QString oldPortName = kmiPorts->getInPortName(oldPortNumber);
    int oldEquivalentOutPort = kmiPorts->getOutPortNumber(oldPortName);
    int newEquivalentOutPort = kmiPorts->getOutPortNumber(portName);


    //bool thisMidiAuxInputIsActive = (oldPortNumber == -1) ? false : true;

    qDebug() << "slotUpdateMIDIAuxInputPorts called - auxInput: " << auxInput << " index: " << settingsInputIndex << " portName: " << portName << " thisPort: " << thisMidiInPortNumber;

    bool reassigned = false;
    bool alreadyListening = false;

    if (midiAuxIn[settingsInputIndex]->port_in_open) // if the old port is open
    {
        qDebug() << "close old port: " << oldPortNumber << " oldEquivalentOutPort:" << oldEquivalentOutPort;
        midiAuxIn[settingsInputIndex]->slotCloseMidiIn(); // close it
        if (oldEquivalentOutPort != -1)
        {
            midiAuxIn[settingsInputIndex]->slotCloseMidiOut(); // close the corresponding out port
        }
    }

    // iterate through the input / aux pairs
    for (int i = 0; i < 8; i++)
    {
        //qDebug() << "Index: " << i;
        if (i != settingsInputIndex) // don't check the midiAuxIn[i] for this input
        {
            QString settingsInputPortName = settingsWindow->midiInputLine[i].device;
            int settingsInputPortNum = kmiPorts->getInPortNumber(settingsInputPortName);
            //qDebug() << "settingsInputPortName: " << settingsInputPortName << " settingsInputPortNum:" << settingsInputPortNum << " oldPortNumber: " << oldPortNumber << " reassigned: " << reassigned << " thisMidiInPortNumber: " << thisMidiInPortNumber << " alreadyListening: " << alreadyListening;
            if (settingsInputPortNum == oldPortNumber && reassigned == false) // if this input port matches the port this midiAuxIn was assigned to
            {
                if (oldPortNumber != -1)
                {
                    qDebug() << "Reassign: Set MidiAux[" << i <<"] to  listen to " << settingsInputPortName << " on port: " << oldPortNumber << " oldEquivalentOutPort: " << oldEquivalentOutPort;

                    settingsWindow->midiInputDeviceMenus.at(i)->blockSignals(true);
                    if (!midiAuxIn[i]->slotUpdatePortIn(oldPortNumber)) // set that port's midiAuxIn to handling the incoming midi
                    {
                        // couldn't open in port
                        settingsWindow->midiInputDeviceMenus.at(i)->setCurrentText("None");
                        slotCreateDialog(QString("ERROR: MIDI input port \"%1\"\nis currently being used by another program or process!").arg(portName));
                    }
                    if (!midiAuxIn[i]->slotUpdatePortOut(oldEquivalentOutPort)) // open the corresponding out port
                    {
                        // couldn't open correspondig out port
                        settingsWindow->midiInputDeviceMenus.at(i)->setCurrentText("None");
                        slotCreateDialog(QString("ERROR: MIDI output port \"%1\"\nis currently being used by another program or process!").arg(portName));
                    }
                    reassigned = true;
                    settingsWindow->midiInputDeviceMenus.at(i)->blockSignals(false);
                }
            }
            //qDebug() << "settingsInputPortNum: " << settingsInputPortNum << " thisMidiInPortNumber: " << thisMidiInPortNumber;
            if (settingsInputPortNum == thisMidiInPortNumber && thisMidiInPortNumber != -1)
            {
                qDebug() << "MidiAux[" << i <<"] already listening to " << settingsInputPortName << " on port: " << thisMidiInPortNumber;
                alreadyListening = true; // do nothing, we already have a midiAuxIn listening to this port
            }
        }
    }

    if (portName != "None" && portName != "" && !alreadyListening) // if we didnt find another midiAuxIn that is already assigned to this port...
    {
        qDebug() << "New Assign: Set MidiAux[" << settingsInputIndex <<"] to  listen to " << portName << " on port: " << thisMidiInPortNumber << " newEquivalentOutPort: " << newEquivalentOutPort;

        settingsWindow->midiInputDeviceMenus.at(settingsInputIndex)->blockSignals(true);
        if (!midiAuxIn[settingsInputIndex]->slotUpdatePortIn(thisMidiInPortNumber)) // ...assign this input/aux pair to listen to it
        {
            // couldn't open input
            settingsWindow->midiInputDeviceMenus.at(settingsInputIndex)->setCurrentText("None");
            slotCreateDialog(QString("ERROR: MIDI input port \"%1\"\nis currently being used by another program or process!").arg(portName));
        }
        if (!midiAuxIn[settingsInputIndex]->slotUpdatePortOut(newEquivalentOutPort)) // open the corresponding out port
        {
            // couldn't open output
            settingsWindow->midiInputDeviceMenus.at(settingsInputIndex)->setCurrentText("None");
            slotCreateDialog(QString("ERROR: MIDI output port \"%1\"\nis currently being used by another program or process!").arg(portName));
        }
        settingsWindow->midiInputDeviceMenus.at(settingsInputIndex)->blockSignals(false);
    }
#endif // end MIDI_AUX_ENABLED
}

void MainWindow::slotRecallMIDIThru()
{
#ifdef MIDI_ENABLED

    QString thisPortName = sessionSettings->value(MIDI_THRU_KEY).toString();

    qDebug() << "slotRecallMIDIThru called, connected: " << SoftStep->connected << " recallMidiThruPortName: " << thisPortName;

    if (mode == "standalone")
    {
        midi_thru_dropdown->blockSignals(true);
        midi_thru_dropdown->setCurrentText(thisPortName);
        midi_thru_dropdown->blockSignals(false);
        slotUpdateMIDIThru();
    }
    else
    {
        midi_thru_dropdown->blockSignals(true);
        midi_thru_dropdown->setCurrentText("None");
        midi_thru_dropdown->blockSignals(false);
        SoftStep->disconnect(SIGNAL(signalRxMidi_raw(uchar, uchar, uchar, uchar)));
        MIDIThru->slotCloseMidiIn();
        MIDIThru->slotCloseMidiOut();
    }
#endif // MIDI_ENABLED
}

void MainWindow::slotClearMIDIThruDropdown()
{
    midi_thru_dropdown->clear();
    midi_thru_dropdown->addItem("None");
}


void MainWindow::slotTether(bool state, bool save = SA_SAVE_NO)
{
    qDebug() << "slotTether called - state: " << state;
    uint8_t tether_mode = state ? TETHER_LIVE : TETHER_OFF;
    uint8_t tether_command[] = {0, SA_TYPE_TETHER_ONOFF, tether_mode, save}; // an int followed by two uchars
    uint8_t nav_command[] = {0, SA_TYPE_NAVSTANDALONE_ONOFF, !state, save};
    uint8_t standalone_command[] = {0, SA_TYPE_STANDALONE_ONOFF, !state, save};
    uint8_t scene_command[] = {0, SA_TYPE_SCENECHANGE_ONOFF, !state, save};


    kmiEncode->slotEncodePacket(MSG_CAT_LEGACY, STANDALONE_CLOSE, standalone_command, sizeof(standalone_command));
    kmiEncode->slotEncodePacket(MSG_CAT_LEGACY, STANDALONE_CLOSE, tether_command, sizeof(tether_command));
    kmiEncode->slotEncodePacket(MSG_CAT_LEGACY, STANDALONE_CLOSE, nav_command, sizeof(nav_command));
    kmiEncode->slotEncodePacket(MSG_CAT_LEGACY, STANDALONE_CLOSE, scene_command, sizeof(scene_command));
}

void MainWindow::slotEnableTether()
{
   slotTether(true);
}

void MainWindow::slotDisableTether()
{
   slotTether(false);
}

// parse legacy KMI packets here
void MainWindow::slotProcessKMIPacket(uint8_t PID, uint8_t category, uint8_t type, uint8_t* ptr, uint16_t length)
{
    Q_UNUSED(ptr);
    qDebug() << "slotProcessKMIPacket called - PID: " << PID  << " category: " <<  category << "type: " << type  << "payloadLength: " << length;
    switch (category)
    {
    case MSG_CAT_CALIBRATION:

        switch (type)
        {
        case PEDAL_CAL_PAYLOAD:
            break;
        case KEYS_CAL_PAYLOAD:
            break;
        case CV_CAL_PAYLOAD:
            if (cvCalWindow != nullptr)
            {
                cvCalWindow->slotParseDeviceCVCalibration(ptr, length);
            }
            break;
        }

        break;
    }
}

void MainWindow::slotProcessNRPN(uchar chan, int nrpn, int val)
{
    Q_UNUSED(chan);

    if (nrpn == 86) // 86 == 12 Step expression pedal
    {
        pedalCalWindow->slotProcessInput(val);
    }
}


// --------------------------------------------------------------------------------------
// ------ end midi overhaul -------------------------------------------------------------
// --------------------------------------------------------------------------------------

void MainWindow::slotProcessInputToHostedMode(uchar chan, uchar cc, uchar val)
{
    Q_UNUSED(chan);

    if (mode != "hosted" && key[0]->dataCooker->pedal->calibrating == false) return; // only process input if we are in hosted mode, or calibrating a pedal

    //qDebug() << "slotProcessInputToHostedMode called, cc: " << cc << " val: " << val;
    emit signalUpdateSensor(cc, val);
}


// All of this rigamarole is required because Windows MIDI drivers are terrible...
//
// Hosted mode modlines route messages to midiformatoutput, which in turn calls hosted_slotSendPacket.
// The portname is the output destination of the message. Rather than create discrete rtmidi instances
// (which would eat memory and likely cause driver collisions on windows) we will attempt to dynamiclly
// change the output port of a single rtmidi instance with each message.
// For non-windows OSes, we will route messages to "Softstep Share" directly to the virtual port rtmidi instance.

void MainWindow::hosted_slotSendPacketOrArray(QString portName, QByteArray packetArray, uchar status, uchar d1, uchar d2, uchar chan)
{
#ifdef MIDI_ENABLED

    if (mode != "hosted") return; // only process input if we are in hosted mode

    bool sendArray = (packetArray == "empty") ? false : true;

    //qDebug() << "hosted_slotSendPacket called - sendArray: " << sendArray << " portName: " << portName << " status: " << status << " d1: " << d1 << " d2: " << d2 << " chan: " << chan;

    int destPort = kmiPorts->getOutPortNumber(portName);

    // test if we already have a device manager talking to this port

    if (portName == SoftStep->portName_out)
    {
        //qDebug() << "send with SoftStep";
        if (sendArray)
        {
            SoftStep->slotSendSysExBA(packetArray);
        }
        else
        {
            SoftStep->slotSendMIDI(status, d1, d2, chan);
        }
        return;
    }
    else if (portName == SoftStepShare->portName_out)
    {
        //qDebug() << "send with SoftStepShare";
        shareElapsedTimer->restart(); // set timer window to test for feedback loop

        if (sendArray)
        {
            SoftStepShare->slotSendSysExBA(packetArray);
        }
        else
        {
            lastSendSoftStepShareMessage = (status << 24) + (d1 << 16) + (d2 << 8) + chan; // combine and store for easy comparison
            SoftStepShare->slotSendMIDI(status, d1, d2, chan);
        }
        return;
    }
    else if (portName == MIDIThru->portName_out)
    {
        //qDebug() << "send with MIDIThru";
        if (sendArray)
        {
            MIDIThru->slotSendSysExBA(packetArray);
        }
        else
        {
            MIDIThru->slotSendMIDI(status, d1, d2, chan);
        }
        return;
    }
    // scan midi aux input KMDMs
    for (int i = 0; i < 8; i++)
    {
        if (portName == midiAuxIn[i]->portName_out) // aux ins automatically open the corresponding output port when the input is opened
        {
            //qDebug() << "send with midiAuxIn[" << i << "]";
            if (sendArray)
            {
                midiAuxIn[i]->slotSendSysExBA(packetArray);
            }
            else
            {
                midiAuxIn[i]->slotSendMIDI(status, d1, d2, chan); //
            }
            midiAuxIn[i]->slotEmptyMIDIBuffer();
            return;
        }
    }

    //qDebug() << "send with hostedOut";
    // no other KMDMs are talking to this driver, so we use hostedOut

    if (!hostedOut->slotUpdatePortOut(destPort)) // try to open this port
    {
        // couldn't open input
        slotCreateDialog(QString("ERROR: MIDI input port \"%1\"\nis currently being used by another program or process!").arg(portName));
    }
    else
    {
        if (sendArray)
        {
            hostedOut->slotSendSysExBA(packetArray);
        }
        else
        {
            hostedOut->slotSendMIDI(status, d1, d2, chan);

        }
        hostedOut->slotEmptyMIDIBuffer();
    }
    hostedOut->slotCloseMidiOut();

#endif // MIDI_ENABLED
}

void MainWindow::hosted_slotSendPacketArray(QString portName, QByteArray packetArray)
{
#ifdef MIDI_ENABLED

    if (mode != "hosted") return; // only process input if we are in hosted mode

    //qDebug() << "hosted_slotSendPacketArray called";
    hosted_slotSendPacketOrArray(portName, packetArray, 0, 0, 0, 0);
#endif // MIDI_ENABLED
}

void MainWindow::hosted_slotSendPacket(QString portName, uchar status, uchar d1, uchar d2, uchar chan)
{
#ifdef MIDI_ENABLED
    if (mode != "hosted") return; // only process input if we are in hosted mode

    //qDebug() << "hosted_slotSendPacket called";
    // call the method and signal to not use the array method
    QByteArray thisArray = "empty";
    hosted_slotSendPacketOrArray(portName, thisArray, status, d1, d2, chan);
#endif // MIDI_ENABLED
}

// receives softstep share program changes
void MainWindow::hosted_slotReceiveMIDI(uchar status, uchar d1, uchar d2, uchar chan)
{
    Q_UNUSED(d2) // program changes don't use the second data byte

    if (mode != "hosted") return; // only process input if we are in hosted mode

    //qDebug() << "hosted_slotReceiveMIDI called - status: " << status << " d1: " << d1 << " d2: " << d2 << " chan: " << chan;

    shareElapsedTimer->restart(); // set timer window to test for feedback loop
    long thisLongMessage = (status << 24) + (d1 << 16) + (d2 << 8) + chan; // combine for easy comparison
    if (thisLongMessage == lastSendSoftStepShareMessage && shareElapsedTimer->elapsed() < 2) // stop matches within 2ms
    {
        qDebug() << "WARNING: Blocked SoftStep Share message/feedback";
        lastSendSoftStepShareMessage = 0;
        return;
    }


    if (status == MIDI_PROG_CHANGE) //
    {
        int progChan = cvCalWindow->nrpnChannel;
        qDebug() << "SoftStep Share Program Change received - PC: " << d1 << " RX channel: " << progChan;
        if (chan == progChan)
        {
            int progChange = d1; // offset to match setlist numbering

            if (progChange < setlist->getSetlistMap().size()) //
            {
                QString thisPreset = setlist->getSetlistMap().at(progChange);
                if (thisPreset != "[EMPTY]")
                {
                    int thisIndex = ui->presetmenu->findText(thisPreset);
                    thisIndex = (thisIndex == -1) ? 0 : thisIndex;
                    slotSetPresetMenu(thisIndex);
                }
            }
        }
    }
}



void MainWindow::slotFixDropDownWidth(QComboBox* thisDropDown)
{
    int IconWidth = thisDropDown->iconSize().width();

    int scroll = thisDropDown->count() <= thisDropDown->maxVisibleItems() ? 0 :
        QApplication::style()->pixelMetric(QStyle::PixelMetric::PM_ScrollBarExtent);

    int max = 0;

    for (int i = 0; i < thisDropDown->count(); i++)
    {
        int width = thisDropDown->view()->fontMetrics().horizontalAdvance(thisDropDown->itemText(i));
        if (max < width)max = width;
    }
    int thisWidth = scroll + max + IconWidth;
    if (thisDropDown->objectName() == "leddisplaymode")
    {
        thisWidth = 75; // hard code fix
    }
    thisDropDown->view()->setMinimumWidth(thisWidth);
    //qDebug() << "slotFixDropDownWidth called - box: " << thisDropDown->objectName() << " width: " << thisWidth;
}

#ifdef Q_OS_WIN

#define DIALOG_WIN_WIDTH 550
#define DIALOG_WIN_HEIGHT 150
#define DIALOG_WIN_X_CENTER DIALOG_WIN_WIDTH / 2
#define DIALOG_WIN_Y_CENTER DIALOG_WIN_HEIGHT / 2

#define DIALOG_WIN_PADDING 10

#define BUTT_WIDTH 130
#define BUTT_HEIGHT 24
#define BUTT_PADDING 8
#define BUTT_X_CENTER BUTT_WIDTH / 2
#define BUTT_Y_CENTER BUTT_HEIGHT / 2
#define BUTT_COL1 DIALOG_WIN_X_CENTER - (BUTT_WIDTH + BUTT_PADDING)
#define BUTT_COL2 DIALOG_WIN_X_CENTER + (BUTT_PADDING)
#define BUTT_ROW1 DIALOG_WIN_HEIGHT - BUTT_HEIGHT - DIALOG_WIN_PADDING

#define TEXT_WIDTH (DIALOG_WIN_WIDTH - (DIALOG_WIN_PADDING * 2))
#define TEXT_HEIGHT (DIALOG_WIN_HEIGHT - (DIALOG_WIN_PADDING * 2)) - BUTT_HEIGHT



void MainWindow::slotNoSharePortDialog()
{
    qDebug() << "slotNoSharePortDialog called - DIALOG_WIN_X_CENTER: " << DIALOG_WIN_X_CENTER << " bc2: " << BUTT_COL2;

    QDialog *msgBox = new QDialog(this);
    msgBox->setMinimumSize(DIALOG_WIN_WIDTH, DIALOG_WIN_HEIGHT);
    msgBox->setFixedSize(DIALOG_WIN_WIDTH, DIALOG_WIN_HEIGHT);

    int x = this->width();
    int y = this->height();

    int dialogX = ((x / 2) - (DIALOG_WIN_WIDTH / 2));
    int dialogY = ((y / 2) - (DIALOG_WIN_HEIGHT / 2));

    msgBox->setWindowFlags(Qt::FramelessWindowHint);
    msgBox->move(dialogX, dialogY);
    msgBox->setStyleSheet(dialogStylesString);

    msgBox->setWindowTitle("Virtual MIDI Port Not Detected");
    QString dialogText = QString("Hosted Mode requires a virtual MIDI port named \"SoftStep Share\".\n\nPlease download LoopMIDI, create the \"SoftStep Share\"\n virtual MIDI port and try again.");
    QLabel* text = new QLabel(dialogText, msgBox, Qt::WindowFlags());
    text->setAlignment(Qt::AlignCenter);
    text->setMinimumSize(TEXT_WIDTH, TEXT_HEIGHT);
    text->setFixedSize(TEXT_WIDTH, TEXT_HEIGHT);
    text->move(DIALOG_WIN_PADDING, DIALOG_WIN_PADDING);
    //text->setStyleSheet("border: 0px; color: white; font: 11pt \"Futura-normal\";");


    QPushButton* cancelButton = new QPushButton(msgBox);
    //cancelButton->setStyleSheet(grayStyleString);
    cancelButton->setText("Cancel");
    cancelButton->setGeometry(QRect(BUTT_COL1, BUTT_ROW1, BUTT_WIDTH, BUTT_HEIGHT));
    connect(cancelButton, SIGNAL(clicked()), msgBox, SLOT(close()));

    QPushButton* downloadButton = new QPushButton(msgBox);
    //downloadButton->setStyleSheet(blueStyleString);
    downloadButton->setText("Download LoopMIDI");
    downloadButton->setGeometry(QRect(BUTT_COL2, BUTT_ROW1, BUTT_WIDTH, BUTT_HEIGHT));
    connect(downloadButton, SIGNAL(clicked()), msgBox, SLOT(close()));
    connect(downloadButton, SIGNAL(clicked()), this, SLOT(slotDownloadLoopMIDI()));

    // breadcrumbs
    msgBox->exec();
}

void MainWindow::slotDownloadLoopMIDI()
{
    QDesktopServices::openUrl(QUrl("https://www.tobias-erichsen.de/software/loopmidi.html"));
}
#endif // Q_OS_WIN
