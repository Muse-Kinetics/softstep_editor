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
VERSION = 3.0.2
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# this is to clear warnings from the OG softstep c files
DEFINES += _CRT_SECURE_NO_WARNINGS

macx{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
}

#uncomment this to build a console version of the app. Do this once before deploying the app.
#BUILD_CONSOLE = 1

# Uncomment this line if you want to deploy the app (codesign, xxxDeployqt, copy content, and create installer/dmg etc
DEPLOY = 1

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
versionAtLeast(QT_VERSION, 6.2.1){
    macx{
        message("Building Apple M1/Intel Universal Binary")
        QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
        QMAKE_APPLE_DEVICE_ARCHS = x86_64 arm64
    }
}

!isEmpty(BUILD_CONSOLE) {
    CONFIG += console
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
                ../../shared/KMI_Ports \
                ../../shared/KMI_Updates \
                ../../shared/rtmidi

SOURCES +=      main.cpp\
    ../../shared/KMI_MDM/KMI_SysexMessages.c \
    ../../shared/KMI_MDM/KMI_mdm.cpp \
    ../../shared/KMI_MDM/fwupdate/fwupdate.cpp \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.cpp \
    ../../shared/KMI_Ports/kmi_ports.cpp \
    ../../shared/KMI_Updates/kmi_updates.cpp \
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
    ../../shared/KMI_MDM/KMI_DevData.h \
    ../../shared/KMI_MDM/KMI_FwVersions.h \
    ../../shared/KMI_MDM/KMI_SysexMessages.h \
    ../../shared/KMI_MDM/KMI_mdm.h \
    ../../shared/KMI_MDM/fwupdate/fwupdate.h \
    ../../shared/KMI_MDM/midi.h \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.h \
    ../../shared/KMI_Ports/kmi_ports.h \
    ../../shared/KMI_Updates/kmi_updates.h \
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
    DEFINES += __WINDOWS_MM__=1
        LIBS += -lwinmm
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


# ********************************************************************************************************
# NOTE for the deployment process to work you MUST add an additional "make" build step, arguments: deploy
# ********************************************************************************************************

isEmpty(DEPLOY) {
    # Define a dummy deploy target that does nothing
    QMAKE_EXTRA_TARGETS += deploy
    deploy.commands = @echo "Deploy is disabled"
} else {


    win32 {
        package_dir = $$shell_path($$absolute_path("..\\..\\win-build\\packages\\com.keithmcmillen.softstepeditors.basic\\data\\$${TARGET}", $$PWD))
        repo_root_dir = $$shell_path($$absolute_path("..", $$PWD))

        LIBCRYPTO_SRC = $$shell_path($$absolute_path("..\\..\\shared\\KMI_Updates\\ssl\\libcrypto-1_1-x64.dll", $$PWD))
        LIBSSL_SRC = $$shell_path($$absolute_path("..\\..\\shared\\KMI_Updates\\ssl\\libssl-1_1-x64.dll", $$PWD))

        path_to_signtool = C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.22000.0\\x64\\signtool.exe
        path_to_qtwindeploy = $$[QT_INSTALL_BINS]\\windeployqt.exe


        # Corrected variable assignments without escaped quotes
        app_name = $${TARGET}

        build_subdir = release  # Default to release
        CONFIG(debug, debug|release): build_subdir = debug

        temp_out_pwd = $$replace(OUT_PWD, "/", "\\")
        binary_src = "$${temp_out_pwd}\\$${build_subdir}\\$${TARGET}.exe"
        binary_dest = "$${package_dir}\\$${TARGET}.exe"

        debug_src = "$${temp_out_pwd}\\$${build_subdir}\\$${TARGET} (debug console).exe"
        debug_dest = "$${package_dir}\\$${TARGET} (debug console).exe"


        deploy_opts = "--compiler-runtime"
        !isEmpty(INCLUDE_QML) {
            deploy_opts += " --qmldir \"$$PWD\""
        }


        # Define custom deployment commands after all variables have been defined
        DEPLOY_COMMANDS = \
            echo Deploying for Windows && \
            echo Copying executable to package_dir && \
            copy /y \"$$binary_src\" \"$$binary_dest\" && \
            copy /y \"$$debug_src\" \"$$debug_dest\" && \
            \
            echo Signing App Executable && \
            \"$$path_to_signtool\" sign /v /debug /a /tr http://timestamp.digicert.com /td SHA256 /fd certHash \"$$binary_dest\" && \
            \"$$path_to_signtool\" sign /v /debug /a /tr http://timestamp.digicert.com /td SHA256 /fd certHash \"$$debug_dest\" && \
            \
            echo Running qtwindeploy: \"$$package_dir\" && \
            \"$$path_to_qtwindeploy\" $$deploy_opts --dir \"$$package_dir\" \"$$binary_dest\" && \
            \
            echo Copying SSL dlls to package_dir && \
            copy /y \"$$LIBCRYPTO_SRC\" \"$$package_dir\" && \
            copy /y \"$$LIBSSL_SRC\" \"$$package_dir\"

        # Define a phony target for deployment
            QMAKE_EXTRA_TARGETS += deploy
            deploy.commands = $$DEPLOY_COMMANDS
            deploy.depends = first  # ensures this runs after the first build

    }
}
