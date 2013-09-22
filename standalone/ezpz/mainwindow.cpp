// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fwoodDialog(new Ui::FwoodDialog),
    fwProgressDialog(new Ui::FwProgressForm),
    fwUpdateCompleteDialog(new Ui::FwUpdateCompleteForm),
    fwUpdateDialog(new Ui::UpdateFirmwareForm),
    aboutForm(new Ui::AboutForm)
{
    connected = false;

    //StyleSheets
    styleSheets = new StyleSheets();

    //Settings
    QCoreApplication::setApplicationName("SoftStepEasyEditor");
    QCoreApplication::setOrganizationName("KeithMcMillenInstruments");
    QCoreApplication::setOrganizationDomain("keithmcmillen.com");
    settings = new QSettings();

    //Construct Children
    presetInterface = new PresetInterface(this);
    sysExComposer = new SysExComposer(this);
    mdm = new MidiDeviceManager(this);

    //Mainwindow Ui
    this->setWindowTitle("SoftStep Easy Editor");
    ui->setupUi(this);

    //Coverup
    disableWidget = new QWidget(this);
    disableWidget->hide();
    disableWidget->resize(this->size());
    disableWidget->setStyleSheet("QWidget{ background: rgba(0,0,0,200); }");

    //Child Dialogs
    fwoodDialogWidget = new QWidget(this);
    fwoodDialogWidget->hide();
    fwoodDialog->setupUi(fwoodDialogWidget);
    fwoodDialogWidget->move(this->width()/2 - fwoodDialogWidget->width()/2, this->height()/2 - fwoodDialogWidget->height()/2);

    fwProgressDialogWidget = new QWidget(this);
    fwProgressDialogWidget->hide();
    fwProgressDialog->setupUi(fwProgressDialogWidget);
    fwProgressDialogWidget->move(this->width()/2 - fwProgressDialogWidget->width()/2, this->height()/2 - fwProgressDialogWidget->height()/2);

    fwUpdateCompleteDialogWidget = new QWidget(this);
    fwUpdateCompleteDialogWidget->hide();
    fwUpdateCompleteDialog->setupUi(fwUpdateCompleteDialogWidget);
    fwUpdateCompleteDialogWidget->move(this->width()/2 - fwUpdateCompleteDialogWidget->width()/2, this->height()/2 - fwUpdateCompleteDialogWidget->height()/2);

    fwUpdateDialogWidget = new QWidget(this);
    fwUpdateDialogWidget->hide();
    fwUpdateDialog->setupUi(fwUpdateDialogWidget);
    fwUpdateDialogWidget->move(this->width()/2 - fwUpdateDialogWidget->width()/2, this->height()/2 - fwUpdateDialogWidget->height()/2);

    aboutFormWidget = new QWidget(this);
    aboutFormWidget->hide();
    aboutForm->setupUi(aboutFormWidget);
    aboutFormWidget->move(this->width()/2 - aboutFormWidget->width()/2, this->height()/2 - aboutFormWidget->height()/2);

    aboutForm->expected->setText(QString("%1 %2").arg(sysExComposer->embeddedVersion).arg(sysExComposer->embeddedbuildNum));

    //Construct Keys
    for(int i = 1; i < 11; i++)
    {
        key[i] = new Key(this, i);
    }

    this->installEventFilter(this);

    slotInitMenuBar();

    slotConnectInterfaces();

    //Load preset from last app session
    presetInterface->slotRecallPreset(1);
    //ui->currentPreset->setValue(settings->value("lastPreset").toInt());
    ui->currentPreset->setFocus();


    //Construct Keys
    for(int i = 1; i < 11; i++)
    {
        key[i]->slotConnectElements();
    }

#ifdef Q_OS_MAC
    mdm->connectSource();
#else
    //Attempt to Connect SoftStep
    mdm->devicePoller->start(1000);
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    if((keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) && ui->backlight->hasFocus())
    {
        ui->backlight->setChecked(!ui->backlight->isChecked());
    }
}

void MainWindow::closeEvent(QCloseEvent *)
{
    qDebug() << "closing...";
    presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
}

void MainWindow::slotConnectInterfaces()
{
    //Connected Indicator
    connect(mdm, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));

    //About Ok Button
    connect(aboutForm->ok, SIGNAL(clicked()), aboutFormWidget, SLOT(close()));
    connect(aboutForm->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));

    //SysEx
    connect(mdm, SIGNAL(signalProcessFwQueryReply(QByteArray)), sysExComposer, SLOT(slotGetConnectedVersion(QByteArray)));
    connect(sysExComposer, SIGNAL(signalSendBuildNums(int,QString, int, QString)), this, SLOT(slotReceiveVersions(int,QString, int, QString)));

    //----------------------------- Firmware Updating
    //Firmware Out of Date Dialog
    connect(fwoodDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));
    connect(fwoodDialog->cancel, SIGNAL(clicked()), fwoodDialogWidget, SLOT(close()));

    //Firmware Update Dialog
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));

    //Firmware Progress Bar
    connect(mdm, SIGNAL(signalFwBytesLeft(int)), this, SLOT(slotUpdateFwProgressBar(int)));

    //Firmware Update Complete Dialog
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), fwUpdateCompleteDialogWidget, SLOT(close()));
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));

    //Preset Recall
    connect(ui->currentPreset, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), this, SLOT(slotRecallPreset(QVariantMap,QVariantMap)));

    for(int i = 1; i < 11; i++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[i], SLOT(slotRecallPreset(QVariantMap,QVariantMap)));
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
        connect(key[i], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //Save State
        connect(key[i], SIGNAL(signalCheckSavedState()), presetInterface, SLOT(slotCheckSaveState()));
    }

    //Save indicator
    connect(presetInterface, SIGNAL(signalPresetDirty(bool)), this, SLOT(slotDisplaySaveState(bool)));

    //Update Button
    connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
    connect(presetInterface, SIGNAL(signalUpdateStarted()), this, SLOT(slotDisconnectUpdate()));
    connect(presetInterface, SIGNAL(signalAttributeFormatPreset(QVariantMap,QVariantMap, qlonglong)), sysExComposer, SLOT(slotComposeAttributeListFromPreset(QVariantMap,QVariantMap, qlonglong)));
    connect(sysExComposer, SIGNAL(signalUpdateComplete()), this, SLOT(slotConnectUpdate()));

    //Standalone Download
    connect(sysExComposer, SIGNAL(signalSendSysEx(QString,unsigned char*, int,QString)), mdm, SLOT(slotSendSysEx(QString,unsigned char*, int,QString)));

    ui->backlight->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->sensitivity->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->midiChannel->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->navPadCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->pedalCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->currentPreset->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->displayName->setAttribute(Qt::WA_MacShowFocusRect, false);
}

void MainWindow::slotRecallPreset(QVariantMap preset, QVariantMap master)
{
    //------------------------------------- Sets mainwindow Ui components

    //Global
    ui->sensitivity->setValue(master.value(QString("sensitivity")).toDouble());
    ui->backlight->setChecked(master.value(QString("backlight")).toInt());

    //Preset
    ui->midiChannel->setValue(preset.value(QString("midiChannel")).toInt());
    ui->pedalCC->setValue(preset.value(QString("pedalCC")).toInt());
    ui->navPadCC->setValue(preset.value(QString("navPadCC")).toInt());
    ui->displayName->setText(preset.value(QString("displayName")).toString());
}

void MainWindow::slotDisplaySaveState(bool dirty)
{
    if(dirty)
    {
        ui->update->setStyleSheet(styleSheets->sendButtonDirtyStyleSheet);
    }
    else
    {
        ui->update->setStyleSheet(styleSheets->sendButtonCleanStyleSheet);
    }
}

void MainWindow::slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion)
{
    aboutForm->found->setText(QString("%1 %2").arg(connectedVersion).arg(connected));

    if(connected != embedded)
    {
        fwoodDialog->expected->setText(QString("%1 %2").arg(embeddedVersion).arg(embedded));
        fwoodDialog->found->setText(QString("%1 %2").arg(connectedVersion).arg(connected));
        fwoodDialogWidget->show();
        //qDebug() << "_____ Your firmware version is out of date _____";
    }
}

void MainWindow::slotConnected(bool connection)
{
    if(connection)
    {
        ui->connectedLabel->setText("CONNECTED");
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(0,200,0,255);");
        ui->update->setText("SAVE + SEND");
    }
    else
    {
        //ui->connectedFrame->setStyleSheet("border: 1px solid rgb(67,67,67);background: rgb(100,100,100); border-radius:6;");
        //ui->connectedLabel->setText("Not Connected");
        ui->connectedLabel->setText("NOT CONNECTED");
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(200,0,0,255);");
        ui->update->setText("SAVE");
        aboutForm->found->setText("Not Connected");
    }
}

void MainWindow::slotUpdateFirmware()
{
    fwoodDialogWidget->hide();
    QApplication::processEvents();
    fwProgressDialogWidget->show();
    QApplication::processEvents();
    fwProgressDialog->progressBar->setMinimum(0);
    QApplication::processEvents();
#ifdef Q_OS_MAC
    fwProgressDialog->progressBar->setMaximum(sysExComposer->fwFileSize);
#else
    fwProgressDialog->progressBar->setMaximum(0);
#endif
    QApplication::processEvents();
    sysExComposer->slotUpdateFirmware();
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
        fwProgressDialogWidget->close();
        fwUpdateCompleteDialogWidget->show();
    }
}

void MainWindow::slotInitMenuBar()
{
    menubar = new QMenuBar(this);

#ifdef Q_OS_MAC
#else
    menubar->setGeometry(0,0, this->width(), 20);
#endif


    //-------------------------------------------------------------------------- File
    QMenu* file = new QMenu("File");
    menubar->addMenu(file);

    //-------------------------------------------------------------------------- Edit
    QMenu* edit = new QMenu("Edit ");
    menubar->addMenu(edit);

    QAction* useCustom = new QAction("Use Custom Preset", edit);
    connect(useCustom, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    edit->addAction(useCustom);

    QMenu* factoryPreset = new QMenu("Use Factory Preset");
    edit->addMenu(factoryPreset);

    QAction* factoryProgramChange = new QAction("Program Change", factoryPreset);
    connect(factoryProgramChange, SIGNAL(triggered()), presetInterface, SLOT(slotSetCurrentPresetToFactory()));
    factoryPreset->addAction(factoryProgramChange);


    //-------------------------------------------------------------------------- Hardware
    QMenu* hardware = new QMenu("Hardware");
    QAction* updatefw = new QAction("Update/Reload Firmware...", hardware);
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(updatefw, SIGNAL(triggered()), fwUpdateDialogWidget, SLOT(show()));

    hardware->addAction(updatefw);
    menubar->addMenu(hardware);

    //-------------------------------------------------------------------------- Help
    QMenu* help = new QMenu("Help");
    QAction* about = new QAction("About SoftStep Easy Editor", help);
    connect(about, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(about, SIGNAL(triggered()), aboutFormWidget, SLOT(show()));
    help->addAction(about);

    QAction* doc = new QAction("Documentation...", help);
    connect(doc, SIGNAL(triggered()), this, SLOT(slotOpenDocumentation()));
    help->addAction(doc);
    menubar->addMenu(help);
}

void MainWindow::slotShowDisableWindow()
{
    qDebug() << "Show";
}

void MainWindow::slotHideDisableWindow()
{

}

void MainWindow::slotOpenDocumentation()
{
    QFile *file = new QFile(":doc.txt");
    file->open(QFile::ReadOnly);
    QDesktopServices::openUrl(QUrl((QLatin1String)file->readLine(0)));
    qDebug() << (QLatin1String)file->readLine(0);
    file->close();
}

void MainWindow::slotDisconnectUpdate()
{
    qDebug("download preset started");
    disconnect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
}


void MainWindow::slotConnectUpdate(){
    qDebug("download preset ended");
    connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
}
