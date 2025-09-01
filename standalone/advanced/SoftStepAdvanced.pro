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
VERSION = 3.0.5
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# this is to clear warnings from the OG softstep c files
DEFINES += _CRT_SECURE_NO_WARNINGS
CONFIG+=sdk_no_version_check

macx {
    QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder
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
versionAtLeast(QT_VERSION, 6.2.1):!versionAtLeast(QT_VERSION, 6.9.0){
    macx{
        message("Building Apple M1/Intel Universal Binary for macOS 10.14+")
        QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
        QMAKE_APPLE_DEVICE_ARCHS = x86_64 arm64
    }
}

# build with Qt 6.9+ to support macOS 10.15+ (required for std::filesystem)
versionAtLeast(QT_VERSION, 6.9.0){
    macx{
        message("Building Apple M1/Intel Universal Binary for macOS 10.15+")
        QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
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
                ../../shared/KMI_MDM/cvCal \
                ../../shared/KMI_MDM/pedalCal \
                ../../shared/KMI_MDM/kmiSysEx \
                ../../shared/KMI_MDM/qt_ui \
                ../../shared/KMI_Ports \
                ../../shared/KMI_Updates \
                ../../shared/rtmidi

SOURCES +=      main.cpp\
    ../../shared/KMI_MDM/KMI_SysexMessages.c \
    ../../shared/KMI_MDM/KMI_mdm.cpp \
    ../../shared/KMI_MDM/cvCal/cvCal.cpp \
    ../../shared/KMI_MDM/fwupdate/fwupdate.cpp \
    ../../shared/KMI_MDM/kmiSysEx/kmiSysEx.cpp \
    ../../shared/KMI_MDM/pedalCal/pedalcal.cpp \
    ../../shared/KMI_MDM/qt_ui/kmiSpinBoxUpDown.cpp \
    ../../shared/KMI_MDM/troubleshoot/troubleshoot.cpp \
    ../../shared/KMI_Ports/kmi_ports.cpp \
    ../../shared/KMI_Updates/kmi_updates.cpp \
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
    ../../shared/KMI_MDM/KMI_DevData.h \
    ../../shared/KMI_MDM/KMI_FwVersions.h \
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
    ../../shared/KMI_Ports/kmi_ports.h \
    ../../shared/KMI_Updates/kmi_updates.h \
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
    DEFINES += __WINDOWS_MM__=1
        LIBS += -lwinmm
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



# ********************************************************************************************************
# NOTE for the deployment process to work you MUST add an additional "make" build step, arguments: deploy
# ********************************************************************************************************

isEmpty(DEPLOY) {
    # Define a dummy deploy target that does nothing
    QMAKE_EXTRA_TARGETS += deploy
    deploy.commands = @echo "Deploy is disabled"
} else {


    win32 {
        package_dir = $$shell_path($$absolute_path("..\\..\\win-build\\packages\\com.keithmcmillen.softstepeditors.advanced\\data\\$${TARGET}", $$PWD))
        content_dir = $$shell_path($$absolute_path("..\\..\\win-build\\packages\\com.keithmcmillen.softstepeditors.content\\data\\Content", $$PWD))
        repo_root_dir = $$shell_path($$absolute_path("..", $$PWD))

        changelog_src = "$${repo_root_dir}\\..\\CHANGELOG.md"
        content_src = "$${repo_root_dir}\\..\\Content"

        LIBCRYPTO_SRC = $$shell_path($$absolute_path("..\\..\\shared\\KMI_Updates\\ssl\\libcrypto-1_1-x64.dll", $$PWD))
        LIBSSL_SRC = $$shell_path($$absolute_path("..\\..\\shared\\KMI_Updates\\ssl\\libssl-1_1-x64.dll", $$PWD))

        path_to_signtool = C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.22000.0\\x64\\signtool.exe
        path_to_qtwindeploy = $$[QT_INSTALL_BINS]\\windeployqt.exe

        path_to_bincreate = C:\\Qt6\\QtIFW-4.6.0\\bin\\binarycreator.exe
        path_to_installerbase = C:\\Qt6\\QtIFW-4.6.0\\bin\\installerbase.exe
        path_to_install = $$shell_path($$absolute_path("..\\..\\win-build", $$PWD))

        # Corrected variable assignments without escaped quotes
        app_name = $${TARGET}
        installer_name = \"SoftStep Editors v$$VERSION Windows Installer\"
        installer_file = \"SoftStep Editors v$$VERSION Windows Installer.exe\"

        message("path_to_bincreate is: " $$quote($$path_to_bincreate))
        message("installer_file is: " $$quote($$installer_file))

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
            copy /y \"$$LIBSSL_SRC\" \"$$package_dir\" && \
            \
            echo Clearing content && \
            (if exist \"$$content_dir\" rmdir /s /q \"$$content_dir\" || echo Directory not found, skipping deletion) && \
            mkdir \"$$content_dir\" && \
            \
            echo Copying content && \
            Robocopy \"$$content_src\" \"$$content_dir\" /MIR && \
            echo Robocopy Exit Code: %ERRORLEVEL% & \
            \
            echo Copying changelog && \
            copy /y \"$$changelog_src\" \"$$content_dir\" && \
            \
            echo Creating Installer && \
            cd \"$$path_to_install\" && \
            \"$$path_to_bincreate\" --verbose --offline-only -c config/config.xml -p packages $$installer_name && \
            \
            echo Signing Installer && \
            \"$$path_to_signtool\" sign /v /debug /a /tr http://timestamp.globalsign.com/tsa/advanced /td SHA256 /fd certHash $$installer_file

        # Define a phony target for deployment
            QMAKE_EXTRA_TARGETS += deploy
            deploy.commands = $$DEPLOY_COMMANDS
            deploy.depends = first  # ensures this runs after the first build

    }
}

