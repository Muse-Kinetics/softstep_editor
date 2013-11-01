// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>

#include "key.h"
#include "presetinterface.h"
#include "sysexcomposer.h"
#include "mididevicemanager.h"
#include "stylesheets.h"

#ifdef Q_OS_MAC
#include "ui_fwoodform.h"
#include "ui_fwprogressform.h"
#include "ui_fwupdatecompleteform.h"
#include "ui_updatefwform.h"
#include "ui_aboutform.h"
#include "ui_mainwindow.h"
#else
#include "ui_fwoodformWin.h"
#include "ui_fwprogressformWin.h"
#include "ui_fwupdatecompleteformWin.h"
#include "ui_updatefwformWin.h"
#include "ui_aboutformWin.h"
#include "ui_mainwindowWin.h"
#endif


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    StyleSheets* styleSheets;
    PresetInterface *presetInterface;
    SysExComposer   *sysExComposer;

    MidiDeviceManager *mdm;

    bool connected;

    QWidget* fwoodDialogWidget;
    QWidget* fwProgressDialogWidget;
    QWidget* fwUpdateCompleteDialogWidget;
    QWidget* fwUpdateDialogWidget;
    QWidget* aboutFormWidget;
    QWidget* keyTestWidget;

    QWidget* disableWidget;
    QWidget* factoryPresetCoverWidget1;
    QWidget* factoryPresetCoverWidget2;
    QLabel*  factoryPresetNameLabel;

    QSettings *settings;

    QComboBox *presetMenu;

    //Menubar
    QMenuBar *menubar;
    QList<QAction *> actionList;
    QAction* useCustom; //used for enabling/disabling Use Custom Preset menu item.
    bool useCustomEnabled;

    //Ui Elements
    Key *key[10];
    QSpinBox *midiChannel;
    QDoubleSpinBox *globalGain;
    QSpinBox *pedalCC;
    QCheckBox *backlight;
    QLineEdit *sceneName;

    QComboBox *sceneTemplate;



    QLabel *midiChannelLabel;
    QLabel *globalGainLabel;
    QLabel *pedalCCLabel;
    QLabel *backlightLabel;
    QLabel *sceneNameLabel;
    QLabel *sceneTemplateLabel;

    //---- Stylesheets
    QFile *radioButtonStylesheetFile;
    QString radioButtonStylesheetString;

    QPushButton *update;
    QCheckBox *connectedLight;
    QLabel  *connectedLightLabel;
    QPushButton *reloadFactoryScenes;

    bool shiftDown;
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *);

public slots:
    void slotConnectInterfaces();
    void slotRecallPreset(QVariantMap preset, QVariantMap master);
    void slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion);
    void slotConnected(bool);
    void slotUpdateFirmware();
    void slotUpdateFwProgressBar(int);
    void slotInitMenuBar();
    void slotOpenDocumentation();   
    void slotDisconnectUpdate();
    void slotConnectUpdate();
    void slotDisplaySaveState(bool);
    void slotEnableDisableUseCustomPreset(bool);

    void slotEnableDisableMenu();

    void slotDisplayFactory();

private:
    Ui::MainWindow *ui;
    Ui::FwoodDialog *fwoodDialog;
    Ui::FwProgressForm *fwProgressDialog;
    Ui::FwUpdateCompleteForm *fwUpdateCompleteDialog;
    Ui::UpdateFirmwareForm *fwUpdateDialog;
    Ui::AboutForm *aboutForm;

};

#endif // MAINWINDOW_H
