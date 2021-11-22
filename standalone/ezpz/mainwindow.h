// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <QComboBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <qglobal.h>

#include "key.h"
#include "presetinterface.h"
#include "sysexcomposer.h"
#include "mididevicemanager.h"
#include "stylesheets.h"
#include "copypastehandler.h"
#include "scrolleventfilter.h"

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

// midi overhaul
#include "kmi_ports.h"
#include "KMI_mdm.h"
#include "RtMidi.h"
#include "KMI_DevData.h"
#include <fwupdate.h>
#include "kmi_updates.h"
#include "midi.h"
// end midi overhaul

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // ------- fw update overhaul
    QByteArray applicationVersion, thisFw;
    QString betaVersion;
    KMI_Updates * checkUpdates;
    fwUpdate* fwUpdateWindow;

    // FWUpdate Styles
    QFile*              fwUpdateStylesFile;
    QString             fwUpdateStylesString;

    // ------- end fw update overhaul ----------------------------

    // ------ midi overhaul --------------------------------------------------------

    // kmiPorts handles MIDI I/O changes
    KMI_Ports *kmiPorts;

    // create KMI devices
    MidiDeviceManager* SoftStep;

    // create a virtual port on MacOS, iOS, and Linux. Not supported on Windows.
#ifndef Q_OS_WIN
    MidiDeviceManager* virtualMidiPort;
#endif

    // MIDI aux inputs and outputs are defined here. For products like SoftStep (advanced), you would define 8 inputs for controllers
    // and one output for hosted mode. For other editors you would likely define one output port for to mirror the
    // incoming MIDI from the controller, as a workaround for Windows not sharing ports.
    // For KMI_Central we are using these for the input/output dropdowns as a simple MIDI route demo.
    MidiDeviceManager* midiAuxOut;

    // version strings for console and about window
    QString deviceBootloaderVersionString();
    QString deviceFirmwareVersionString();
    QString applicationFirmwareVersionString();

    // ------ end midi overhaul --------------------------------------------------------

    StyleSheets* styleSheets;
    PresetInterface *presetInterface;
    SysExComposer   *sysExComposer;
    CopyPasteHandler* copyPasteHandler;
    ScrollEventFilter scrollEventFilter;

    QThread* midiThread;
    SS_MidiDeviceManager *mdm;

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

    //copy&paste actions
    QAction* copyPresetAct;
    QAction* pastePresetAct;

    QAction* updatefw;

    //Ui Elements
    Key *key[10];
    QSpinBox *midiChannel;
    QDoubleSpinBox *globalGain;
    QSpinBox *pedalCC;
    QCheckBox *backlight;
    QLineEdit *sceneName;

    QComboBox *sceneTemplate;

    QString connectedVersionString;
    int connectedVersionInt;


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

#ifdef Q_OS_MAC
#else
    QProcess *syxutilProcess;
#endif

signals:
    void signalStandaloneOn();

public slots:


    // ------ midi overhaul --------------------------------------------------------
    void slotMIDIPortChange(QString, uchar, uchar, int); // handles changes to MIDI i/o
    void slotRefreshConnection();
    void slotBootloaderMode(bool fwUpdateRequested);
    void slotFwUpdateSuccessCloseDialog(bool);
    void slotForceFirmwareUpdate();
    void slotFirmwareDetected(MidiDeviceManager *thisMDM, bool);
    void slotUpdateMIDIaux();

    // ------ end midi overhaul --------------------------------------------------------


    void slotConnectInterfaces();
    void slotRecallPreset(QVariantMap preset, QVariantMap master);
    void slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion);
    void slotConnected(bool);
//    void slotUpdateFirmware();
//    void slotUpdateFwProgressBar(int);
    void slotInitMenuBar();
    void slotUpdatePasteAvailability();
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
