// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <QDebug>
#include <QVariant>
#include <QElapsedTimer>

#include "key.h"
#include "navkey.h"
#include "settings.h"
#include "setlist.h"
#include "presetinterface.h"
//#include "mididevicemanager.h"
#include "sysexcomposer.h"
#include "copypastehandler.h"
#include "scrolleventfilter.h"
#include "importoldpresethandler.h"

#ifdef Q_OS_MAC
//#include "ui_fwoodform.h"
//#include "ui_fwprogressform.h"
//#include "ui_fwupdatecompleteform.h"
//#include "ui_updatefwform.h"
#include "ui_aboutform.h"
#include "ui_mainwindow.h"
#include "ui_saveAsForm.h"
#include "ui_deletePresetForm.h"
#include "ui_importOldPresetsForm.h"
#include "ui_importOldNotFoundForm.h"
#include "ui_modlineWarningForm.h"
#include "ui_apploadform.h"
#else
//#include "ui_fwoodformWin.h"
//#include "ui_fwprogressformWin.h"
//#include "ui_fwupdatecompleteformWin.h"
//#include "ui_updatefwformWin.h"
#include "ui_apploadformWin.h"
#include "ui_aboutformWin.h"
#include "ui_mainwindowWin.h"
#include "ui_saveAsFormWin.h"
#include "ui_deletePresetFormWin.h"
#include "ui_importOldPresetsFormWin.h"
#include "ui_importOldNotFoundFormWin.h"
#include "ui_modlineWarningFormWin.h"
#endif

#include "hosted/midiparse.h"
#include "hosted/displaysink.h"
#include "hosted/oscinterface.h"

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

    bool connected;
    bool forceFirmwareUpdate;

    bool appStillLoading;

    // ------- fw update overhaul
    QByteArray applicationVersion, thisFw;
    QString betaVersion;
    KMI_Updates * checkUpdates;
    fwUpdate* fwUpdateWindow;
    troubleshoot* troubleshootWindow;

    // FWUpdate Styles
    QFile*              fwUpdateStylesFile;
    QString             fwUpdateStylesString;

    // FWUpdate Styles
    QFile*              dialogStylesFile;
    QString             dialogStylesString;

    // ------- end fw update overhaul ----------------------------

    // ------ midi overhaul --------------------------------------------------------

    // kmiPorts handles MIDI I/O changes
    KMI_Ports *kmiPorts;

    // create KMI devices
    MidiDeviceManager* SoftStep;

    // MIDI Thru port for standalone, workaround for Windows device limitations
    MidiDeviceManager* MIDIThru;

    // MIDI aux inputs and outputs are defined here. For products like SoftStep (advanced), you would define 8 inputs for controllers
    // and one output for hosted mode.
    MidiDeviceManager* midiAuxIn[8];

    // this port is used to send MIDI to various ports when in hosted mode.
    MidiDeviceManager* hostedOut;

    MidiDeviceManager* SoftStepShare; // virtual port device
    QElapsedTimer* shareElapsedTimer;
    long lastSendSoftStepShareMessage; // stuff four 8 bit bytes into a 32 bit long and compare it

    QString MIDI_THRU_KEY;
    QString MIDI_AUX_KEY[8];

    QString recallMidiThruPortName;
    QComboBox *midi_thru_dropdown;

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


    QSettings *sessionSettings;

    SysExComposer* sysExComposer;
    PresetInterface* presetInterface;
    MidiDeviceManager* midiDeviceManager;
    CopyPasteHandler* copyPasteHandler;
    MidiParse* midiParse;
    DisplaySink displaySink;
    ScrollEventFilter scrollEventFilter;
    ImportOldPresetHandler* importOldPresetHandler;
    OscInterface *oscInterface;

    //--------------------------------- Mode Switching
    QString mode;

    QStringList standaloneDestinations;
    QStringList standaloneSources;
    QStringList standaloneTables;
    QStringList hostedDestinations;
    QStringList hostedSources;
    QStringList hostedTables;
    QStringList standaloneNavSources;
    QStringList standaloneNavTables;
    QStringList hostedNavSources;
    QStringList hostedNavTables;
    QStringList hostedDisplayModes;
    QStringList standaloneDisplayModes;

    //Disabling Widget
    QWidget     *disableWidget;

    //Dialogs
    QWidget     *saveAsDialogWidget;
    QWidget     *deleteDialogWidget;
    //QWidget     *appLoadWidget;
//    QWidget     *fwoodDialogWidget;
//    QWidget     *fwProgressDialogWidget;
//    QWidget     *fwUpdateCompleteDialogWidget;
//    QWidget     *fwUpdateDialogWidget;
    QWidget     *aboutFormWidget;
    QWidget     *importOldDialogWidget;
    QWidget     *importOldNotFoundDialogWidget;
    QWidget     *modlineWarningDialogWidget;

    //Menubar
    QMenuBar *menubar;
    QList<QAction *> actionList;

    QAction* updatefw;

    //copy / paste actions
    QAction* clearPresetAct;
    QAction* copyPresetAct;
    QAction* pastePresetAct;
    QAction* pasteNewPresetAct;
    QAction* copyKeyAct;
    QAction* pasteKeyAct;
    QAction* toolTipsEnable;
    QAction* importOldPreset;

    //Ui Elements
    Key *key[10];
    NavKey *navKey;
    Settings *settingsWindow;
    Setlist *setlist;

//    QString connectedVersionString;
//    int connectedVersionInt;

    //Key Lockout
    QList<int> lockoutKeysPressed;

    //---------------- Hosted Source Sending ---------------//
    MidiFormatOutput midiFormatOutput;
    QMap<QString, int> externalDests;
    QMap<QString, int> midiInputSources;

    void closeEvent(QCloseEvent *);
    bool event( QEvent* ev );

#ifdef Q_OS_MAC
#else
    QProcess *syxutilProcess;
#endif

signals:
    void signalSaveAs(QString presetName);
    void signalSetMode(QString mode);
    void signalStoreValue(QString name, QVariant value, int presetNum);
    void signalCheckSavedState();
    void signalSelectedKeyOutline(int selectedKey, bool outlined);

    void signalSetPresetNameInKeys(QString);

    void signalUpdateSensor(uchar cc, uchar val);


public slots:


    // ------ midi overhaul --------------------------------------------------------
    void slotMIDIPortChange(QString, uchar, uchar, int); // handles changes to MIDI i/o
    void slotRefreshConnection();
    void slotBootloaderMode(bool fwUpdateRequested);
    void slotFwUpdateSuccessCloseDialog(bool);
    void slotForceFirmwareUpdate();
    void slotFirmwareDetected(MidiDeviceManager *thisMDM, bool);
    void slotUpdateMIDIThru();
    void slotCreateDialog(QString dialogText);

    // ext midi sources
    void slotParseMidiAuxIn_A(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_B(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_C(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_D(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_E(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_F(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_G(uchar status, uchar d1, uchar d2, uchar chan);
    void slotParseMidiAuxIn_H(uchar status, uchar d1, uchar d2, uchar chan);

    void slotParseMidiAuxIn_SoftStepShare(uchar status, uchar d1, uchar d2, uchar chan);

    void slotParseMidiAuxInputs(QString auxInput, int midiInputPortNumber, uchar status, uchar d1, uchar d2, uchar chan);

    void slotRestoreAllAuxDropdowns();
    void slotUserUpdatedMIDIAuxInputPort(QString auxInput, QString portName);
    void slotUpdateMIDIAuxInputPorts(QString auxInput, QString port);
    void slotRecallMIDIThru();
    void slotClearMIDIThruDropdown();

    // ------ end midi overhaul --------------------------------------------------------

    // replace mididevicemanager functionality
    void slotProcessInputToHostedMode(uchar chan, uchar cc, uchar val);


    void slotConnectInterfaces();
    void slotConnectElements();
    void slotDisconnectElements();

    //------------- Menu Bar
    void slotInitMenuBar();
    void slotOpenDoc();
    void slotOpenTroubleshooting();
    void slotEnableDisableToolTips();

    void slotUpdatePasteAvailability();
    void slotSelectedKey(int selectedKey);

    void slotValueChanged();
    void slotRecallPreset(QVariantMap, QVariantMap);

    void slotUpdateAboutWindow();
    void slotConnected(bool);

    void slotSaveAs();
    void slotPopulatePresetMenu();
    void slotSetPresetMenu(int presetNum);
    void slotDisplaySaveState(bool);

    void slotModlineWarning(QString modlineWarningMessage);

    void slotSetMode();
    void slotPopulateSourceDestLists();
    void slotPopulateDeviceMenus(QMap<QString, int> externalDevices);

    //void slotReceiveVersions(int connected, QString connectedVersion, int embedded, QString embeddedVersion, int hardware);

    void slotRecallPresetFromSetlist(QString presetName);

    //-------------- Lockout Handling
    void slotLockoutKeyPressedReleased(int keyNumber, bool pressedReleased);

    //-------------- Standalone Preset Updating / Sending
    void slotUpdatePresets();
    void slotUpdateSettings();
    void slotDisconnectUpdate();
    void slotConnectUpdate();

    //-------------- from previous mididevicemanager
    void slotSetModeMIDI(QString m);
    void hosted_slotSendPacket(QString portName, uchar status, uchar d1, uchar d2, uchar chan);
    void hosted_slotSendPacketOrArray(QString portName, QByteArray packetArray, uchar status, uchar d1, uchar d2, uchar chan);

    void hosted_slotSendPacketArray(QString, QByteArray);
    void hosted_slotReceiveMIDI(uchar status, uchar d1, uchar d2, uchar chan);

    void slotFixDropDownWidth(QComboBox* thisDropDown);

#ifdef Q_OS_WIN
    void slotNoSharePortDialog();
    void slotDownloadLoopMIDI();
#endif

private:
    Ui::MainWindow *ui;

    //Dialogs
    Ui::saveAsDialogForm        *saveAsDialogForm;
    Ui::deleteDialogForm        *deleteDialogForm;
    //Ui::AppLoadForm             *apploadForm;

    //Ui::FwoodDialog             *fwoodDialogForm;
    //Ui::FwProgressForm          *fwProgressDialog;
    //Ui::FwUpdateCompleteForm    *fwUpdateCompleteDialog;
    //Ui::UpdateFirmwareForm      *fwUpdateDialog;
    Ui::AboutForm               *aboutForm;
    Ui::ImportOldPresetsForm    *importOldDialog;
    Ui::ImportOldNotFoundForm   *importOldNotFoundDialog;
    Ui::ModlineWarningForm      *modlineWarningDialog;



};

#endif // MAINWINDOW_H
