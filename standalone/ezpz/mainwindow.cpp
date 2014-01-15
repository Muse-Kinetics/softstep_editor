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

    //Mainwindow Ui
    ui->setupUi(this);


    connected = false;

    connectedVersionString = "Not Connected";
    connectedVersionInt = -1;

    //StyleSheets
    styleSheets = new StyleSheets();

    //Settings
    QCoreApplication::setApplicationName("SoftStepEasyEditor");
    QCoreApplication::setOrganizationName("KeithMcMillenInstruments");
    QCoreApplication::setOrganizationDomain("keithmcmillen.com");
    settings = new QSettings();


    //Construct Children
    presetInterface = new PresetInterface(this);
    sysExComposer = new SysExComposer(0);



#ifdef Q_OS_MAC
    mdm = new MidiDeviceManager(this);
#else
    midiThread = new QThread(this);
    mdm = new MidiDeviceManager(0);
    mdm->moveToThread(midiThread);
    midiThread->start();
#endif

    this->installEventFilter(this);

    //QList<QWidget*> widgets = findChildren<QWidget*>();
    foreach (QWidget* widget, findChildren<QWidget*>())
    {
        widget->installEventFilter(this);
        widget->setAttribute(Qt::WA_MacShowFocusRect, false);
    }


    //Disable system focus boxt on Mac
    ui->backlight->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->sensitivity->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->midiChannel->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->navPadCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->pedalCC->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->currentPreset->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->displayName->setAttribute(Qt::WA_MacShowFocusRect, false);

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

    factoryPresetNameLabel = new QLabel(ui->centralWidget,0);
    factoryPresetNameLabel->hide();
    factoryPresetNameLabel->resize(this->size());
    factoryPresetNameLabel->setAlignment(Qt::AlignCenter);
    factoryPresetNameLabel->setStyleSheet("font: 36pt \"Futura\"; color: white");

    //Coverup for dialogs
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



    //this->installEventFilter(this);

    slotInitMenuBar();

    slotConnectInterfaces();

    //Load preset from last app session
    presetInterface->slotRecallPreset(1);
    //ui->currentPreset->setValue(settings->value("lastPreset").toInt());
    ui->currentPreset->setFocus();


    //Connect Key Elements
    for(int i = 1; i < 11; i++)
    {
        key[i-1]->slotConnectElements();
    }

#ifdef Q_OS_MAC
    mdm->connectSource();
#else
    //Attempt to Connect SoftStep
    //mdm->devicePoller->start(1000);
#endif

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

}

MainWindow::~MainWindow()
{
    delete ui;
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
    qDebug() << "closing...";
    //presetInterface->slotWriteJSON(presetInterface->jsonMasterMap);
}

void MainWindow::slotConnectInterfaces()
{
    //Connected Indicator
    connect(mdm, SIGNAL(signalConnected(bool)), this, SLOT(slotConnected(bool)));

    //About Ok Button
    connect(aboutForm->ok, SIGNAL(clicked()), aboutFormWidget, SLOT(close()));
    connect(aboutForm->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(aboutForm->ok, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //SysEx
    connect(mdm, SIGNAL(signalProcessFwQueryReply(QByteArray)), sysExComposer, SLOT(slotGetConnectedVersion(QByteArray)), Qt::DirectConnection);
    connect(sysExComposer, SIGNAL(signalSendBuildNums(int,QString, int, QString)), this, SLOT(slotReceiveVersions(int,QString, int, QString)));

    //----------------------------- Firmware Updating
    //Firmware Out of Date Dialog
    connect(fwoodDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));
    connect(fwoodDialog->cancel, SIGNAL(clicked()), fwoodDialogWidget, SLOT(close()));
    connect(fwoodDialog->cancel, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(fwoodDialog->cancel, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //Firmware Update Dialog
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), fwUpdateDialogWidget, SLOT(close()));
    connect(fwUpdateDialog->update, SIGNAL(clicked()), this, SLOT(slotUpdateFirmware()));
    connect(fwUpdateDialog->cancel, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

    //Firmware Progress Bar
    connect(mdm, SIGNAL(signalFwBytesLeft(int)), this, SLOT(slotUpdateFwProgressBar(int)));

    //Firmware Update Complete Dialog
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), fwUpdateCompleteDialogWidget, SLOT(close()));
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), disableWidget, SLOT(hide()));
    connect(fwUpdateCompleteDialog->ok, SIGNAL(clicked()), this, SLOT(slotEnableDisableMenu()));

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

    //Update Button
    connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));
    connect(presetInterface, SIGNAL(signalUpdateStarted()), this, SLOT(slotDisconnectUpdate()));
    connect(presetInterface, SIGNAL(signalAttributeFormatPreset(QVariantMap,QVariantMap, qlonglong)), sysExComposer, SLOT(slotComposeAttributeListFromPreset(QVariantMap,QVariantMap, qlonglong)));
    connect(sysExComposer, SIGNAL(signalUpdateComplete()), this, SLOT(slotConnectUpdate()));
    //set initial update button text
    ui->update->setText("SAVE");

    //Standalone Download
    connect(sysExComposer, SIGNAL(signalSendSysEx(QString,unsigned char*, int,QString)), mdm, SLOT(slotSendSysEx(QString,unsigned char*, int,QString)));
    connect(this, SIGNAL(signalStandaloneOn()), mdm, SLOT(slotStandaloneOn()));
    connect(mdm, SIGNAL(signalSettingsSent()), sysExComposer, SLOT(slotSettingsSent()));
    connect(mdm, SIGNAL(signalPresetsSent()), sysExComposer, SLOT(slotPresetsSent()));



    //!!!!!!!!!!!!!! Why is this happening in connect interfaces?
    //Load stylesheet and set initial text for connectedLabel
    ui->connectedLabel->setText("NOT CONNECTED");
#ifdef Q_OS_MAC
    ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(200,0,0,255);");
#else
    ui->connectedLabel->setStyleSheet("font:6pt \"Futura\";color: rgba(200,0,0,255);");
#endif

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
    ui->backlight->setChecked(master.value(QString("backlight")).toInt());

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

void MainWindow::slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion)
{
    qDebug() << "slotReceiveVersions called connected:" << connectedVersion << connected;

    connectedVersionString = connectedVersion;
    connectedVersionInt = connected;

    aboutForm->found->setText(QString("%1 %2").arg(connectedVersionString).arg(connectedVersionInt));

    slotConnected(true);

    if(connected != embedded)
    {
        fwoodDialog->expected->setText(QString("%1 %2").arg(embeddedVersion).arg(embedded));
        fwoodDialog->found->setText(QString("%1 %2").arg(connectedVersion).arg(connected));
        disableWidget->show();
        slotEnableDisableMenu();
        fwoodDialogWidget->show();
        //qDebug() << "_____ Your firmware version is out of date _____";
    }

    //End of sysex inquiry process, put board into standalone mode
    emit signalStandaloneOn();
}

void MainWindow::slotConnected(bool connection)
{

    qDebug() << "slotConnected Called" << connection;

    if(connection)
    {
        ui->connectedLabel->setText("CONNECTED");
#ifdef Q_OS_MAC
        ui->connectedLabel->setStyleSheet("font:8pt \"Futura\";color: rgba(0,200,0,255);");
#else
        ui->connectedLabel->setStyleSheet("font:6pt \"Futura\";color: rgba(0,200,0,255);");
#endif
        ui->update->setText("SAVE + SEND");
        aboutForm->found->setText(QString("%1 %2").arg(connectedVersionString).arg(connectedVersionInt));
        presetInterface->connected = true;

        updatefw->setEnabled(true);
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

        aboutForm->found->setText("Not Connected");
        presetInterface->connected = false;

        updatefw->setEnabled(false);
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
    qDebug() << file;
    file->setObjectName("FileMenu");
    //menubar->addMenu(file);

    //-------------------------------------------------------------------------- Edit
    QMenu* edit = new QMenu("Edit ");
    qDebug() << edit;
    edit->setObjectName("EditMenu");
    menubar->addMenu(edit);

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
    updatefw = new QAction("Update/Reload Firmware...", hardware);
    actionList.append(updatefw);
    connect(updatefw, SIGNAL(triggered()), disableWidget, SLOT(show()));
    connect(updatefw, SIGNAL(triggered()), fwUpdateDialogWidget, SLOT(show()));
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

void MainWindow::slotDisplayFactory()
{

}

void MainWindow::slotOpenDocumentation()
{
    //QFile *file = new QFile(":doc.txt");
    //file->open(QFile::ReadOnly);
    QDesktopServices::openUrl(QUrl("http://www.keithmcmillen.com/"));
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
