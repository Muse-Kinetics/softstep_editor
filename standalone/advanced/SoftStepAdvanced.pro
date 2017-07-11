#-------------------------------------------------
#
# Project created by QtCreator 2013-09-16T15:37:17
#
#-------------------------------------------------

QT       += core gui \
            svg \
            qml quick quickwidgets \
            network

QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "SoftStep Advanced Editor"
TEMPLATE = app

INCLUDEPATH +=  forms \
                resources \
                ../../shared/sysexcomposition \
                ../../shared \
                ../../shared/images \
                ../../shared/stylesheets

SOURCES +=      main.cpp\
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
                mididevicemanager.cpp \
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
                modline.h \
                key.h \
                presetinterface.h \
                sysexcomposer.h \
                ../../shared/sysexcomposition/utils.h \
                ../../shared/sysexcomposition/syxtx.h \
                ../../shared/sysexcomposition/syxrx.h \
                ../../shared/sysexcomposition/syxformats.h \
                ../../shared/sysexcomposition/softstep.h \
                ../../shared/sysexcomposition/query.h \
                ../../shared/sysexcomposition/midi.h \
                ../../shared/sysexcomposition/maxapi.h \
                ../../shared/sysexcomposition/download.h \
                ../../shared/sysexcomposition/attribute.h \
                ../../shared/sysexcomposition/sysexcomposer.h \
                ../../shared/sysexmessages.h \
                settings.h \
                mididevicemanager.h \
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
    forms/aboutform.ui \
    forms/fwprogressform.ui \
    forms/fwoodform.ui \
    forms/updatefwform.ui \
    forms/fwupdatecompleteform.ui \
    forms/pedalLiveTableForm.ui \
    forms/importOldPresetsForm.ui \
    forms/importOldNotFoundForm.ui \
    forms/modlineWarningForm.ui \
    forms/mainwindowWin.ui \
    forms/keyWindowFormWin.ui \
    forms/keyBoxFormWin.ui \
    forms/modlineFormWin.ui \
    forms/updatefwformWin.ui \
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
    forms/fwupdatecompleteformWin.ui \
    forms/fwprogressformWin.ui \
    forms/fwoodformWin.ui \
    forms/deletePresetFormWin.ui \
    forms/aboutformWin.ui

#-------------------QJson-------------------#
#-------------------------------------------#
static{
DEFINES += STATIC_BUILD
}

INCLUDEPATH +=  ../../shared/qjson/src

SOURCES +=      ../../shared/qjson/src/json_parser.cc \
                ../../shared/qjson/src/json_scanner.cpp \
                ../../shared/qjson/src/parser.cpp \
                ../../shared/qjson/src/qobjecthelper.cpp \
                ../../shared/qjson/src/serializer.cpp

#------------------oscpack------------------#
#-------------------------------------------#
INCLUDEPATH +=

SOURCES +=


#---------------------LIBS--------------------#
#---------------------------------------------#
win32{
LIBS +=         -lwinmm
}

macx{
LIBS +=         -framework CoreMIDI
LIBS +=         -framework CoreFoundation
LIBS +=         -framework Cocoa
LIBS +=         -framework CoreServices
}

#--------------------Icons--------------------#
#---------------------------------------------#
win32{
RC_FILE =       resources/appicon.rc.txt
}

macx{
ICON = resources/appicon.icns
}

RESOURCES += \
    resources.qrc

OTHER_FILES += \
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
    resources/DroidSansMono.ttf \
    resources/Futura-Bold.ttf \
    resources/futura-normal.ttf \
    resources/corbelb.ttf \
    resources/corbel.ttf
