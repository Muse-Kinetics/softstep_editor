#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T16:45:40
#
#-------------------------------------------------

QT +=           core gui \
                widgets \
                svg \
                network

TARGET =        "SoftStep Basic Editor"
TEMPLATE =      app
VERSION = 3.0.8
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# this is to clear warnings from the OG softstep c files
DEFINES += _CRT_SECURE_NO_WARNINGS
CONFIG+=sdk_no_version_check

macx{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 12
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
                ../../shared/rtmidi

SOURCES +=      main.cpp\
    ../../shared/KMI_MDM/diagnosticlogger.cpp \
    ../../shared/KMI_MDM/KMI_fwupdate.cpp \
    ../../shared/KMI_MDM/KMI_SysexMessages.c \
    ../../shared/KMI_MDM/KMI_mdm.cpp \
    ../../shared/KMI_MDM/fwupdate/fwupdate.cpp \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.cpp \
    ../../shared/KMI_MDM/KMI_ports.cpp \
    ../../shared/KMI_MDM/KMI_updates.cpp \
    ../../shared/rtmidi/RtMidi.cpp \
                mainwindow.cpp \
                key.cpp \
                presetinterface.cpp \
                sysexcomposer.cpp \
                ../../shared/sysexcomposition/utils.c \
                ../../shared/sysexcomposition/syxtx.c \
                ../../shared/sysexcomposition/syxrx.c \
                ../../shared/sysexcomposition/query.c \
                ../../shared/sysexcomposition/maxapi.c \
                ../../shared/sysexcomposition/download.c \
                ../../shared/sysexcomposition/attribute.c \
                ../../shared/sysexcomposition/mainsysex.c \
    stylesheets.cpp \
    factorypresets.cpp \
    scrolleventfilter.cpp \
    copypastehandler.cpp


HEADERS  +=     mainwindow.h \
    ../../shared/KMI_MDM/diagnosticlogger.h \
    ../../shared/KMI_MDM/KMI_DevData.h \
    ../../shared/KMI_MDM/KMI_FwVersions.h \
    ../../shared/KMI_MDM/KMI_fwupdate.h \
    ../../shared/KMI_MDM/KMI_SysexMessages.h \
    ../../shared/KMI_MDM/KMI_mdm.h \
    ../../shared/KMI_MDM/fwupdate/fwupdate.h \
    ../../shared/KMI_MDM/midi.h \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.h \
    ../../shared/KMI_MDM/KMI_ports.h \
    ../../shared/KMI_MDM/KMI_updates.h \
    ../../shared/rtmidi/RtMidi.h \
    ../../shared/sysexcomposition/device_includes.h \
    ../../shared/sysexcomposition/midi_ss.h \
                key.h \
                presetinterface.h \
                sysexcomposer.h \
                ../../shared/sysexcomposition/utils.h \
                ../../shared/sysexcomposition/syxtx.h \
                ../../shared/sysexcomposition/syxrx.h \
                ../../shared/sysexcomposition/syxformats.h \
                ../../shared/sysexcomposition/device_includes.h \
                ../../shared/sysexcomposition/query.h \
                ../../shared/sysexcomposition/midi_ss.h \
                ../../shared/sysexcomposition/maxapi.h \
                ../../shared/sysexcomposition/download.h \
                ../../shared/sysexcomposition/attribute.h \
                ../../shared/sysexmessages.h \
    stylesheets.h \
    factorypresets.h \
    scrolleventfilter.h \
    copypastehandler.h

FORMS    +=     forms/mainwindow.ui \
                ../../shared/KMI_MDM/fwupdate/fwupdate.ui \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.ui \
                forms/keyform.ui \
                forms/aboutform.ui \
                forms/mainwindowWin.ui \
                forms/keyformWin.ui \
                forms/aboutformWin.ui \
#                forms/settingsForm.ui

OTHER_FILES +=  ../../shared/stylesheets/keyRadioButtonStylesheet.qss \
                resources/sendbuttondirtystylesheet.qss \
    resources/sendbuttoncleanstylesheet.qss \
    resources/sendbuttoncleanstylesheet_windows.qss \
    resources/sendbuttondirtystylesheet_windows.qss \
    resources/appicon.ico \
    resources/futura-normal.ttf \
    resources/Futura-Bold.ttf \
    resources/DroidSansMono.ttf \
    resources/corbelb.ttf \
    resources/corbel.ttf

RESOURCES =    Resources.qrc \
    ../../shared/KMI_MDM/KMI_mdm.qrc \
    ../../shared/firmware/firmware.qrc \
    resources/fonts/fonts.qrc


#--------------- contents/resources --------

macx{
    softStepPresets.files = $$PWD/presets
    softStepPresets.path = Contents/Resources
    QMAKE_BUNDLE_DATA += softStepPresets
}

#-------------------MIDI--------------------#
#-------------------------------------------#

#DEFINES += \
    MDM_DEBUG_ENABLED # enable deeper deebugging for KMI Midi Device Manager

# These defines set RtMidi to the correct OS API
macx{
    DEFINES += __MACOSX_CORE__=1
    LIBS += -framework CoreMidi
    LIBS += -framework CoreAudio
    LIBS += -framework CoreFoundation
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

linux{
    DEFINES += define __LINUX_ALSA__=1
    LIBS += -lasound
}

#ios {
#    DEFINES += TARGET_OS_IPHONE=1
#    LIBS += -framework CoreMidi
#    LIBS += -framework CoreAudio
#    LIBS += -framework CoreFoundation
#    plistupdate.commands = /usr/libexec/PlistBuddy -c \"Set :CFBundleShortVersionString $$VERSION\" $$QMAKE_INFO_PLIST
#    QMAKE_EXTRA_TARGETS += plistupdate
#    PRE_TARGETDEPS += plistupdate
#}

#android {
#    androidmanifestupdate.commands =  sed -i \'\' -E -e \'s/(versionName=)(\"([0-9]\.?)+\")/\\1\"$$VERSION\"/g\' $$ANDROID_PACKAGE_SOURCE_DIR/AndroidManifest.xml
#    QMAKE_EXTRA_TARGETS += androidmanifestupdate
#    PRE_TARGETDEPS += androidmanifestupdate
#}

# end rtmidi defines

# SSL support for checking for updates on windows
win32{
    LIBS += -LC:\Qt6\Tools\OpenSSL\Win_x64\lib -llibcrypto
    INCLUDEPATH+= C:\Qt6\Tools\OpenSSL\Win_x64\include\openssl
    LIBS += -LC:\Qt\Tools\OpenSSL\Win_x64\lib -llibcrypto
    INCLUDEPATH+= C:\Qt\Tools\OpenSSL\Win_x64\include\openssl
}


#-------------------QJson-------------------#
#-------------------------------------------#
static{
DEFINES += STATIC_BUILD
}


#--------------------Icons--------------------#
#---------------------------------------------#
win32{
RC_FILE =       softstepezpzicon.rc.txt
}

macx{
ICON = resources/appicon.icns
}


#--------------- contents/resources --------

#macx{

#    qunexusPresets.files = $$PWD/presets
#    qunexusPresets.path = Contents/Resources
#    QMAKE_BUNDLE_DATA += qunexusPresets
#}

win32{

    presets.commands = $(COPY_DIR) $$shell_path(\"$$PWD/presets\") $$shell_path(\"$$OUT_PWD/presets\")
    export(presets.commands)

    first.depends += $(first) presets
    export(first.depends)

    QMAKE_EXTRA_TARGETS += first presets
}

#DISTFILES +=


