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
    for(int i = 0; i < 10; i++)
    {
        key[i] = new Key(ui->keyFrame, i);
    }


    slotInitMenuBar();

    slotConnectInterfaces();

    //Load preset from last app session
    presetInterface->slotRecallPreset(1);
    //ui->scene->setValue(settings->value("lastPreset").toInt());

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

void MainWindow::slotConnectInterfaces()
{
    //Connected Indicator
    connect(mdm, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));

    //About Ok Button
    connect(aboutForm->ok, SIGNAL(clicked()), aboutFormWidget, SLOT(close()));

    //SysEx
    connect(mdm, SIGNAL(signalProcessFwQueryReply(QByteArray)), sysExComposer, SLOT(slotGetConnectedVersion(QByteArray)));
    connect(sysExComposer, SIGNAL(signalSendBuildNums(int,QString, int, QString)), this, SLOT(slotReceiveVersions(int,QString, int, QString)));

    //Firmware Update Dialog and Progress Bar
    connect(fwoodDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));
    connect(mdm, SIGNAL(signalFwBytesLeft(int)), this, SLOT(slotUpdateFwProgressBar(int)));
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), fwUpdateCompleteDialogWidget, SLOT(close()));
    connect(fwoodDialog->cancel, SIGNAL(clicked()), fwoodDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));

    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));

    //Preset Recall
    //connect(ui->scene, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));
    connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap)), this, SLOT(slotRecallPreset(QVariantMap)));

    for(int i = 0; i < 10; i++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap)), key[i], SLOT(slotRecallPreset(QVariantMap)));
    }

    //Preset Storage
    connect(ui->midiChannel, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->gain, SIGNAL(valueChanged(double)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->pedalCC, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->backlight, SIGNAL(clicked()), presetInterface, SLOT(slotStoreGlobal()));
    connect(ui->sceneName, SIGNAL(textEdited(QString)), presetInterface, SLOT(slotStoreGlobal()));

    ui->midiChannel->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->gain->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->pedalCC->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->sceneName->setContextMenuPolicy(Qt::PreventContextMenu);

    for(int i = 0; i < 10; i++)
    {
        connect(key[i], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));
    }

    //Standalone Download
    connect(sysExComposer, SIGNAL(signalSendSysEx(QString,unsigned char*, int,QString)), mdm, SLOT(slotSendSysEx(QString,unsigned char*, int,QString)));

    //Template Loading
    connect(ui->template_2, SIGNAL(currentIndexChanged(int)), this, SLOT(slotLoadTemplate(int)));
    for(int i = 0; i < 10; i++)
    {
        connect(ui->template_2, SIGNAL(currentIndexChanged(int)), key[i], SLOT(slotLoadTemplate(int)));
    }
}

void MainWindow::slotLoadTemplate(int tem)
{
    if(tem)
    {
        ui->sceneName->setText("FADR");
    }
    else
    {
        ui->sceneName->setText("EASY");
    }

    presetInterface->slotStoreValue("Global_Scene_Name", ui->sceneName->text(), -1);
}

void MainWindow::slotRecallPreset(QVariantMap preset)
{
    //------------------------------------- Recalls/Sets Global Ui components
    ui->midiChannel->setValue(preset.value(QString("Global_Midi_Channel")).toInt());
    ui->gain->setValue(preset.value(QString("Global_Gain")).toDouble());
    ui->pedalCC->setValue(preset.value(QString("Global_Pedal_CC")).toInt());
    ui->backlight->setChecked(preset.value(QString("Global_Backlight")).toBool());
    ui->sceneName->setText(preset.value(QString("Global_Scene_Name")).toString());
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
        ui->connectedFrame->setStyleSheet("border: 1px solid rgb(67,67,67);background: rgb(10,255,0);border-radius:6;");
        ui->connectedLabel->setText("Connected");

        //Update Button
        connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
        connect(presetInterface, SIGNAL(signalUpdateStarted()), this, SLOT(slotConnectDisconnectUpdate()));
        connect(sysExComposer, SIGNAL(signalUpdateComplete()), this, SLOT(slotConnectDisconnectUpdate()));
        updating = false;
        connect(presetInterface, SIGNAL(signalAttributeFormatPreset(QVariantMap)), sysExComposer, SLOT(slotComposeAttributeListFromPreset(QVariantMap)));
    }
    else
    {
        ui->connectedFrame->setStyleSheet("border: 1px solid rgb(67,67,67);background: rgb(100,100,100); border-radius:6;");
        ui->connectedLabel->setText("Not Connected");
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

    //File
    //QMenu* file = new QMenu("File");
    //menubar->addMenu(file);

    //Hardware
    QMenu* hardware = new QMenu("Hardware");
    QAction* updatefw = new QAction("Update/Reload Firmware...", hardware);
    connect(updatefw, SIGNAL(triggered()), fwUpdateDialogWidget, SLOT(show()));
    hardware->addAction(updatefw);
    menubar->addMenu(hardware);

    //Help
    QMenu* help = new QMenu("Help");
    QAction* about = new QAction("About SoftStep Easy Editor", help);
    connect(about, SIGNAL(triggered()), aboutFormWidget, SLOT(show()));
    help->addAction(about);
    QAction* doc = new QAction("Documentation...", help);
    connect(doc, SIGNAL(triggered()), this, SLOT(slotOpenDocumentation()));
    help->addAction(doc);
    menubar->addMenu(help);

}

void MainWindow::slotOpenDocumentation()
{
    QFile *file = new QFile(":doc.txt");
    file->open(QFile::ReadOnly);
    QDesktopServices::openUrl(QUrl((QLatin1String)file->readLine(0)));
    qDebug() << (QLatin1String)file->readLine(0);
    file->close();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    qDebug() << "closing...";
    presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
}

void MainWindow::slotConnectDisconnectUpdate(){
    if(updating){
        qDebug("finished updating");
        connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
        updating = false;
    }
    else{
        qDebug("starting update");
        disconnect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
        updating = true;
    }
}
