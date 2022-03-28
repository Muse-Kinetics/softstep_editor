#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T16:45:40
#
#-------------------------------------------------

QT +=           core gui \
                svg \
                network

TARGET =        "SoftStep Basic Editor"

TEMPLATE =      app

macx{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
}

INCLUDEPATH +=  forms \
                resources \
#                ../../shared/sysexcomposition \
                ../../shared \
                ../../shared/images \
                ../../shared/stylesheets \
                ../../shared/KMI_MDM \
                ../../shared/KMI_MDM/fwupdate \
                ../../shared/KMI_Ports \
                ../../shared/KMI_Updates \
                ../../shared/rtmidi

SOURCES +=      main.cpp\
    ../../shared/KMI_MDM/KMI_mdm.cpp \
    ../../shared/KMI_MDM/fwupdate/fwupdate.cpp \
    ../../shared/KMI_Ports/kmi_ports.cpp \
    ../../shared/KMI_Updates/kmi_updates.cpp \
    ../../shared/rtmidi/RtMidi.cpp \
                mainwindow.cpp \
#                key.cpp \
#                presetinterface.cpp \
#                sysexcomposer.cpp \
#                ../../shared/sysexcomposition/utils.c \
#                ../../shared/sysexcomposition/syxtx.c \
#                ../../shared/sysexcomposition/syxrx.c \
#                ../../shared/sysexcomposition/query.c \
#                ../../shared/sysexcomposition/maxapi.c \
#                ../../shared/sysexcomposition/download.c \
#                ../../shared/sysexcomposition/attribute.c \
#                ../../shared/sysexcomposition/mainsysex.c \
#    stylesheets.cpp \
#    factorypresets.cpp \
#    scrolleventfilter.cpp \
#    copypastehandler.cpp


HEADERS  +=     mainwindow.h \
    ../../shared/KMI_MDM/KMI_DevData.h \
    ../../shared/KMI_MDM/KMI_FwVersions.h \
    ../../shared/KMI_MDM/KMI_SysexMessages.h \
    ../../shared/KMI_MDM/KMI_mdm.h \
    ../../shared/KMI_MDM/fwupdate/fwupdate.h \
    ../../shared/KMI_Ports/kmi_ports.h \
    ../../shared/KMI_Updates/kmi_updates.h \
    ../../shared/rtmidi/RtMidi.h \
#                key.h \
#                presetinterface.h \
#                sysexcomposer.h \
#                ../../shared/sysexcomposition/utils.h \
#                ../../shared/sysexcomposition/syxtx.h \
#                ../../shared/sysexcomposition/syxrx.h \
#                ../../shared/sysexcomposition/syxformats.h \
#                ../../shared/sysexcomposition/softstep.h \
#                ../../shared/sysexcomposition/query.h \
#                ../../shared/sysexcomposition/midi.h \
#                ../../shared/sysexcomposition/maxapi.h \
#                ../../shared/sysexcomposition/download.h \
#                ../../shared/sysexcomposition/attribute.h \
#                ../../shared/sysexmessages.h \
#    stylesheets.h \
#    factorypresets.h \
#    scrolleventfilter.h \
#    copypastehandler.h

FORMS    +=     forms/mainwindow.ui \
                ../../shared/KMI_MDM/fwupdate/fwupdate.ui \
#                forms/keyform.ui \
#                forms/aboutform.ui \
                forms/mainwindowWin.ui \
#                forms/keyformWin.ui \
#                forms/aboutformWin.ui \
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
    ../../shared/KMI_MDM/fwupdate/fw_stylesheets.qrc \
    ../../shared/firmware/firmware.qrc


#--------------- contents/resources --------

macx{
#    softStepSysEx.files = $$PWD/../../shared/SoftStep.syx
#    softStepSysEx.path = Contents/Resources
#    QMAKE_BUNDLE_DATA += softStepSysEx

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

#ios{
#    DEFINES += TARGET_OS_IPHONE=1
#    LIBS += -framework CoreMidi
#    LIBS += -framework CoreAudio
#    LIBS += -framework CoreFoundation

#}

#VERSION = 1.2.3

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
    DEFINES += __WINDOWS_MM__=1
        LIBS += -lwinmm
}
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

#INCLUDEPATH +=  ../../shared/qjson/src

#SOURCES +=      ../../shared/qjson/src/json_parser.cc \
#                ../../shared/qjson/src/json_scanner.cpp \
#                ../../shared/qjson/src/parser.cpp \
#                ../../shared/qjson/src/qobjecthelper.cpp \
#                ../../shared/qjson/src/serializer.cpp

#---------------------LIBS--------------------#
#---------------------------------------------#
#win32{
#LIBS +=         -lwinmm
#}

#macx{
#LIBS +=         -framework CoreMIDI
#LIBS +=         -framework CoreFoundation
#LIBS +=         -framework Cocoa
#LIBS +=         -framework CoreServices
#}

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

#win32{

#    presets.commands = $(COPY_DIR) $$shell_path(\"$$PWD/presets\") $$shell_path(\"$$OUT_PWD/presets\")
#    export(presets.commands)

#    first.depends += $(first) presets
#    export(first.depends)

#    QMAKE_EXTRA_TARGETS += first presets
#}

#DISTFILES +=
