#-------------------------------------------------
#
# Project created by QtCreator 2013-09-16T15:37:17
#
#-------------------------------------------------

QT       += core gui \
            svg \
            widgets \
            qml \
            quick \
            quickwidgets

TARGET = "SoftStep Advanced Editor"
TEMPLATE = app
VERSION = 3.0.6.C
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# this is to clear warnings from the OG softstep c files
DEFINES += _CRT_SECURE_NO_WARNINGS
CONFIG+=sdk_no_version_check
CONFIG += c++17

macx {
    QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder
}

# Packaging is handled by the VS Code installer tasks and .vscode/make-installer.ps1.


# still holding onto support for High Sierra here, separate build
message("Building with Qt $${QT_VERSION}")

# build with Qt 5.11.3 to support El Capitan, Sierra, and High Sierra
lessThan(QT_MAJOR_VERSION, 6){
    macx{
        message("Building legacy MacOS Intel Binary")
        QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.11
    }
}

# build with Qt 6.2.1 to support Mojave and later
versionAtLeast(QT_VERSION, 6.2.1):!versionAtLeast(QT_VERSION, 6.9.0){
    macx{
        message("Building Apple M1/Intel Universal Binary for macOS 10.14+")
        QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
        QMAKE_APPLE_DEVICE_ARCHS = x86_64 arm64
    }
}

# build with Qt 6.9+ for macOS 12.0+ (Qt 6.9.2 requires macOS 12.0)
versionAtLeast(QT_VERSION, 6.9.0){
    macx{
        message("Building Apple M1/Intel Universal Binary for macOS 12.0+")
        QMAKE_MACOSX_DEPLOYMENT_TARGET = 12.0
        QMAKE_APPLE_DEVICE_ARCHS = x86_64 arm64
        QMAKE_LFLAGS += -Wl,-w  # suppress harmless alignment warnings in Universal builds
    }
}

INCLUDEPATH +=  forms \
                resources \
                ../../shared/sysexcomposition \
                ../../shared \
                ../../shared/images \
                ../../shared/stylesheets \
                ../../shared/KMI_MDM \
                ../../shared/KMI_MDM/fwupdate \
                ../../shared/KMI_MDM/troubleshoot \
                ../../shared/KMI_MDM/cvCal \
                ../../shared/KMI_MDM/pedalCal \
                ../../shared/KMI_MDM/kmiSysEx \
                ../../shared/KMI_MDM/qt_ui \
                ../../shared/rtmidi

SOURCES +=      main.cpp\
    ../../shared/KMI_MDM/diagnosticlogger.cpp \
    ../../shared/KMI_MDM/KMI_fwupdate.cpp \
    ../../shared/KMI_MDM/KMI_SysexMessages.c \
    ../../shared/KMI_MDM/KMI_mdm.cpp \
    ../../shared/KMI_MDM/cvCal/cvCal.cpp \
    ../../shared/KMI_MDM/fwupdate/fwupdate.cpp \
    ../../shared/KMI_MDM/kmiSysEx/kmiSysEx.cpp \
    ../../shared/KMI_MDM/pedalCal/pedalcal.cpp \
    ../../shared/KMI_MDM/qt_ui/kmiSpinBoxUpDown.cpp \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.cpp \
    ../../shared/KMI_MDM/KMI_ports.cpp \
    ../../shared/KMI_MDM/KMI_updates.cpp \
    ../../shared/rtmidi/RtMidi.cpp \
                mainwindow.cpp \
                modline.cpp \
                key.cpp \
                presetinterface.cpp \
                ../../shared/sysexcomposition/utils.c \
                ../../shared/sysexcomposition/syxtx.c \
                ../../shared/sysexcomposition/syxrx.c \
                ../../shared/sysexcomposition/query.c \
                ../../shared/sysexcomposition/maxapi.c \
                ../../shared/sysexcomposition/download.c \
                ../../shared/sysexcomposition/attribute.c \
                ../../shared/sysexcomposition/mainsysex.c \
                sysexcomposer.cpp \
                settings.cpp \
#                mididevicemanager.cpp \
                stylesheets.cpp \
    setlist.cpp \
    hosted/slewer.cpp \
    hosted/midiparse.cpp \
    hosted/datacooker.cpp \
    navmodline.cpp \
    navkey.cpp \
    hosted/midiformatoutput.cpp \
    hosted/latcher.cpp \
    hosted/trigger.cpp \
    pedal.cpp \
    hosted/midiinput.cpp \
    hosted/alphanummanager.cpp \
    hosted/ledmanager.cpp \
    hosted/displaysink.cpp \
    hosted/delay.cpp \
    tables.cpp \
    hosted/navdatacooker.cpp \
    hosted/staterecall.cpp \
    copypastehandler.cpp \
    tableinterface.cpp \
    scrolleventfilter.cpp \
    importoldpresethandler.cpp \
    hosted/oscinterface.cpp

HEADERS  +=     mainwindow.h \
    ../../shared/KMI_MDM/diagnosticlogger.h \
    ../../shared/KMI_MDM/KMI_DevData.h \
    ../../shared/KMI_MDM/KMI_FwVersions.h \
    ../../shared/KMI_MDM/KMI_fwupdate.h \
    ../../shared/KMI_MDM/KMI_SysexMessages.h \
    ../../shared/KMI_MDM/KMI_mdm.h \
    ../../shared/KMI_MDM/cvCal/cvCal.h \
    ../../shared/KMI_MDM/cvCal/cvCalData.h \
    ../../shared/KMI_MDM/fwupdate/fwupdate.h \
    ../../shared/KMI_MDM/kmiSysEx/kmiSysEx.h \
    ../../shared/KMI_MDM/pedalCal/pedalcal.h \
    ../../shared/KMI_MDM/pedalCal/readOnlySlider.h \
    ../../shared/KMI_MDM/qt_ui/kmiSpinBoxUpDown.h \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.h \
    ../../shared/KMI_MDM/KMI_ports.h \
    ../../shared/KMI_MDM/KMI_updates.h \
    ../../shared/rtmidi/RtMidi.h \
    ../../shared/sysexcomposition/device_includes.h \
    ../../shared/sysexcomposition/midi_ss.h \
                modline.h \
                key.h \
                presetinterface.h \
                sysexcomposer.h \
                ../../shared/sysexcomposition/utils.h \
                ../../shared/sysexcomposition/syxtx.h \
                ../../shared/sysexcomposition/syxrx.h \
                ../../shared/sysexcomposition/syxformats.h \
                ../../shared/sysexcomposition/query.h \
                ../../shared/sysexcomposition/maxapi.h \
                ../../shared/sysexcomposition/download.h \
                ../../shared/sysexcomposition/attribute.h \
                ../../shared/sysexmessages.h \
                settings.h \
#                mididevicemanager.h \
                stylesheets.h \
    setlist.h \
    hosted/slewer.h \
    hosted/midiparse.h \
    hosted/datacooker.h \
    navmodline.h \
    navkey.h \
    hosted/midiformatoutput.h \
    hosted/latcher.h \
    hosted/trigger.h \
    pedal.h \
    hosted/midiinput.h \
    hosted/alphanummanager.h \
    hosted/ledmanager.h \
    hosted/displaysink.h \
    hosted/delay.h \
    tables.h \
    hosted/navdatacooker.h \
    hosted/staterecall.h \
    copypastehandler.h \
    tableinterface.h \
    scrolleventfilter.h \
    importoldpresethandler.h \
    hosted/oscinterface.h \
    WindowsMidiTypes.h

FORMS    +=     forms/mainwindow.ui \
    ../../shared/KMI_MDM/cvCal/cvCal.ui \
                ../../shared/KMI_MDM/fwupdate/fwupdate.ui \
    ../../shared/KMI_MDM/pedalCal/pedalcal.ui \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.ui \
    forms/aboutform.ui \
    forms/apploadform.ui \
    forms/apploadformWin.ui \
                forms/modlineForm.ui \
                forms/keyWindowForm.ui \
                forms/settingsForm.ui \
                forms/keyBoxForm.ui \
                forms/setlistForm.ui \
    forms/saveAsForm.ui \
    forms/deletePresetForm.ui \
    forms/navModlineForm.ui \
    forms/navKeyWindowForm.ui \
    forms/navBoxForm.ui \
#    forms/fwprogressform.ui \
#    forms/fwoodform.ui \
#    forms/updatefwform.ui \
#    forms/fwupdatecompleteform.ui \
    forms/pedalLiveTableForm.ui \
    forms/importOldPresetsForm.ui \
    forms/importOldNotFoundForm.ui \
    forms/modlineWarningForm.ui \
    forms/mainwindowWin.ui \
    forms/keyWindowFormWin.ui \
    forms/keyBoxFormWin.ui \
    forms/modlineFormWin.ui \
    forms/settingsFormWin.ui \
    forms/setlistFormWin.ui \
    forms/saveAsFormWin.ui \
    forms/pedalLiveTableFormWin.ui \
    forms/navModlineFormWin.ui \
    forms/navKeyWindowFormWin.ui \
    forms/navBoxFormWin.ui \
    forms/modlineWarningFormWin.ui \
    forms/importOldPresetsFormWin.ui \
    forms/importOldNotFoundFormWin.ui \
#    forms/fwupdatecompleteformWin.ui \
#    forms/fwprogressformWin.ui \
#    forms/fwoodformWin.ui \
    forms/deletePresetFormWin.ui \
    forms/aboutformWin.ui

#-------------------QJson-------------------#
#-------------------------------------------#
static{
    DEFINES += STATIC_BUILD
}

RESOURCES += \
    ../../shared/KMI_MDM/KMI_mdm.qrc \
    ../../shared/firmware/firmware.qrc \
    resources.qrc \
    resources/fonts/fonts.qrc


OTHER_FILES += \
    ../../shared/stylesheets/keyRadioButtonStylesheet.qss \
    resources/modline_enable1_stylesheet.qss \
    resources/modline_enable2_stylesheet.qss \
    resources/modline_enable3_stylesheet.qss \
    resources/modline_enable4_stylesheet.qss \
    resources/modline_enable5_stylesheet.qss \
    resources/modline_enable6_stylesheet.qss \
    resources/keybox_openwindow10_stylesheet.qss \
    resources/keybox_openwindow9_stylesheet.qss \
    resources/keybox_openwindow8_stylesheet.qss \
    resources/keybox_openwindow7_stylesheet.qss \
    resources/keybox_openwindow6_stylesheet.qss \
    resources/keybox_openwindow5_stylesheet.qss \
    resources/keybox_openwindow4_stylesheet.qss \
    resources/keybox_openwindow3_stylesheet.qss \
    resources/keybox_openwindow2_stylesheet.qss \
    resources/keybox_openwindow1_stylesheet.qss \
    resources/pedalTable.txt \
    resources/keybox_boxnotselected.qss \
    resources/keybox_boxselected.qss \
    CalibrationTable.qml \
    resources/devicestyle.qss \

## QML stuff

QML_IMPORT_PATH =
CONFIG += qtquickcompiler

#-------------------MIDI--------------------#
#-------------------------------------------#

#DEFINES += \
#    MDM_DEBUG_ENABLED # enable deeper deebugging for KMI Midi Device Manager

# These defines set RtMidi to the correct OS API
macx{
    DEFINES += __MACOSX_CORE__=1
    LIBS += -framework CoreMidi
    LIBS += -framework CoreAudio
    LIBS += -framework CoreFoundation
}

#ios{
#    DEFINES += TARGET_OS_IPHONE=1
#    LIBS += -framework CoreMidi
#    LIBS += -framework CoreAudio
#    LIBS += -framework CoreFoundation

#}

#android {
#    androidmanifestupdate.commands =  sed -i \'\' -E -e \'s/(versionName=)(\"([0-9]\.?)+\")/\\1\"$$VERSION\"/g\' $$ANDROID_PACKAGE_SOURCE_DIR/AndroidManifest.xml
#    QMAKE_EXTRA_TARGETS += androidmanifestupdate
#    PRE_TARGETDEPS += androidmanifestupdate
#}

#ios {
#    plistupdate.commands = /usr/libexec/PlistBuddy -c \"Set :CFBundleShortVersionString $$VERSION\" $$QMAKE_INFO_PLIST
#    QMAKE_EXTRA_TARGETS += plistupdate
#    PRE_TARGETDEPS += plistupdate
#}


linux{
    DEFINES += define __LINUX_ALSA__=1
    LIBS += -lasound
}

win32{
    WMS_SDK_ROOT = C:/PROGRA~2/WI3CF2~1/10

    WMS_SDK_VERSION = $$replace($$(WindowsSDKVersion), \\\\, /)
    WMS_SDK_VERSION = $$replace(WMS_SDK_VERSION, /$, )
    isEmpty(WMS_SDK_VERSION): WMS_SDK_VERSION = 10.0.26100.0

    WMS_CPPWINRT = $${WMS_SDK_ROOT}/Include/$${WMS_SDK_VERSION}/cppwinrt
    WMS_WINDOWS_WINMD = $${WMS_SDK_ROOT}/UnionMetadata/$${WMS_SDK_VERSION}/Windows.winmd
    WMS_CPPWINRT_EXE = $${WMS_SDK_ROOT}/bin/$${WMS_SDK_VERSION}/x64/cppwinrt.exe
    WMS_RUNTIME_WINMD = C:/Program Files/Windows MIDI Services/Desktop App SDK Runtime/Microsoft.Windows.Devices.Midi2.winmd
    WMS_PROJECTION_DIR = $$OUT_PWD/generated/winrt
    WMS_PROJECTION_HEADER = $${WMS_PROJECTION_DIR}/winrt/Microsoft.Windows.Devices.Midi2.h

    !exists($$WMS_CPPWINRT): error(Windows SDK cppwinrt headers not found at $$WMS_CPPWINRT)
    !exists($$WMS_WINDOWS_WINMD): error(Windows.winmd not found at $$WMS_WINDOWS_WINMD)
    !exists($$WMS_CPPWINRT_EXE): error(cppwinrt.exe not found at $$WMS_CPPWINRT_EXE)
    !exists($$WMS_RUNTIME_WINMD): error(Windows MIDI Services runtime winmd not found at $$WMS_RUNTIME_WINMD)

    INCLUDEPATH += $$WMS_CPPWINRT $$WMS_PROJECTION_DIR
    # Both WinMM and WMS compiled in — backend is selected at runtime based on SDK availability.
    DEFINES += __WINDOWS_MM__=1
    DEFINES += __WINDOWS_MIDI_SERVICES__=1
    LIBS += -lwinmm
    LIBS += -lole32
    LIBS += -lruntimeobject
    LIBS += -lwindowsapp

    wms_projection.target = $$WMS_PROJECTION_HEADER
    export(wms_projection.target)

    wms_projection.commands = if not exist $$shell_path(\"$$WMS_PROJECTION_DIR\") mkdir $$shell_path(\"$$WMS_PROJECTION_DIR\") $$escape_expand(\n\t) \
                              $$shell_path(\"$$WMS_CPPWINRT_EXE\") -input $$shell_path(\"$$WMS_RUNTIME_WINMD\") -reference $$shell_path(\"$$WMS_WINDOWS_WINMD\") -output $$shell_path(\"$$WMS_PROJECTION_DIR\")
    export(wms_projection.commands)

    PRE_TARGETDEPS += $$WMS_PROJECTION_HEADER
    export(PRE_TARGETDEPS)

    first.depends += $(first) wms_projection
    export(first.depends)

    QMAKE_EXTRA_TARGETS += first wms_projection
}
# end rtmidi defines

# SSL support for checking for updates on windows
win32{
#    LIBS += -LC:\Qt6\Tools\OpenSSL\Win_x64\lib -llibcrypto
#    INCLUDEPATH+= C:\Qt6\Tools\OpenSSL\Win_x64\include\openssl
    LIBS += -LC:\Qt\Tools\OpenSSL\Win_x64\lib -llibcrypto
    INCLUDEPATH+= C:\Qt\Tools\OpenSSL\Win_x64\include\openssl
}

#--------------------Icons--------------------#
#---------------------------------------------#
win32{
RC_FILE =       resources/appicon.rc.txt
}

macx{
ICON = resources/appicon.icns
}

#--------------- stylesheets --------


DISTFILES += \
    ../../shared/KMI_MDM/cvCal/cvCalStyleWin.qss




