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

#include "sysexcomposer.h"

#define SERIOUS_PRUNING

#ifdef SERIOUS_PRUNING
#include "key.h"
#include "presetinterface.h"

#include "stylesheets.h"
#include "copypastehandler.h"
#include "scrolleventfilter.h"

#ifdef Q_OS_MAC
#include "ui_aboutform.h"
#include "ui_mainwindow.h"
#else
#include "ui_aboutformWin.h"
#include "ui_mainwindowWin.h"
#endif  // Q_OS_MAC
#endif // SERIOUS_PRUNING

// midi overhaul
#include "kmi_ports.h"
#include "KMI_mdm.h"
#include "RtMidi.h"
#include "KMI_DevData.h"
#include <fwupdate.h>
#include <troubleshoot.h>
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
    troubleshoot* troubleshootWindow;


    // Stylesheets
    QFile*              fwUpdateStylesFile;
    QString             fwUpdateStylesString;

    QFile*              dialogStylesFile;
    QString             dialogStylesString;



    // ------- end fw update overhaul ----------------------------

    // ------ midi overhaul --------------------------------------------------------

    // kmiPorts handles MIDI I/O changes
    KMI_Ports *kmiPorts;

    // create KMI devices
    MidiDeviceManager* SoftStep;

    // MIDI aux inputs and outputs are defined here. For products like SoftStep (advanced), you would define 8 inputs for controllers
    // and one output for hosted mode. For other editors you would likely define one output port for to mirror the
    // incoming MIDI from the controller, as a workaround for Windows not sharing ports.
    // For KMI_Central we are using these for the input/output dropdowns as a simple MIDI route demo.
    MidiDeviceManager* MIDIThru;

    QString MIDI_THRU_KEY;
    QString recallMidiThruPortName;

    // version strings for console and about window
    QString deviceBootloaderVersionString();
    QString deviceFirmwareVersionString();
    QString applicationFirmwareVersionString();

    //Buttons
    QFile* blueStyleFile;
    QString blueStyleString;
    QFile* grayStyleFile;
    QString grayStyleString;

    // ------ end midi overhaul --------------------------------------------------------
SysExComposer   *sysExComposer;
#ifdef SERIOUS_PRUNING
    StyleSheets* styleSheets;
    PresetInterface *presetInterface;
    
    CopyPasteHandler* copyPasteHandler;
    ScrollEventFilter scrollEventFilter;

#endif // SERIOUS_PRUNING
    bool connected;
    bool forceFirmwareUpdate;
#ifdef SERIOUS_PRUNING
    QWidget* aboutFormWidget;

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

    QAction* toolTipsEnable;

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
#endif // SERIOUS_PRUNING
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *);

#ifdef Q_OS_MAC
#else
    //QProcess *syxutilProcess;
#endif

signals:
#ifdef SERIOUS_PRUNING
    void signalStandaloneOn();
#endif // SERIOUS_PRUNING
public slots:

    void slotEnableDisableToolTips();

    // ------ midi overhaul --------------------------------------------------------
    void slotMIDIPortChange(QString, uchar, uchar, int); // handles changes to MIDI i/o
    void slotRefreshConnection();
    void slotBootloaderMode(bool fwUpdateRequested);
    void slotFwUpdateSuccessCloseDialog(bool);
    void slotForceFirmwareUpdate();
    void slotFirmwareDetected(MidiDeviceManager *thisMDM, bool);
    void slotUpdateMIDIThru();
    void slotCreateDialog(QString dialogText);
    void slotRecallMIDIThru();
    void slotClearMIDIThruDropdown();
    // ------ end midi overhaul --------------------------------------------------------


    void slotConnectInterfaces();
#ifdef SERIOUS_PRUNING
    void slotRecallPreset(QVariantMap preset, QVariantMap master);
    void slotUpdateAboutWindow();
#endif // SERIOUS_PRUNING
    void slotConnected(bool);
#ifdef SERIOUS_PRUNING

    void slotInitMenuBar();
    void slotUpdatePasteAvailability();
    void slotOpenDocumentation();   
    void slotOpenTroubleshooting();
    void slotDisconnectUpdate();
    void slotConnectUpdate();
    void slotDisplaySaveState(bool);
    void slotEnableDisableUseCustomPreset(bool);

    void slotEnableDisableMenu();

#endif //SERIOUS_PRUNING
private:
    Ui::MainWindow *ui;
    Ui::AboutForm *aboutForm;

};

#endif // MAINWINDOW_H
