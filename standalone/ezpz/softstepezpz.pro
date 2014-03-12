#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T16:45:40
#
#-------------------------------------------------

QT +=           core gui \
                svg

TARGET =        "SoftStep Basic Editor"

TEMPLATE =      app

INCLUDEPATH +=  forms \
                resources \
                ../../shared/sysexcomposition \
                ../../shared \
                ../../shared/images \
                ../../shared/stylesheets \

SOURCES +=      main.cpp\
                mainwindow.cpp \
                key.cpp \
                presetinterface.cpp \
                mididevicemanager.cpp \
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
                key.h \
                presetinterface.h \
                mididevicemanager.h \
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
    stylesheets.h \
    factorypresets.h \
    scrolleventfilter.h \
    copypastehandler.h

FORMS    +=     forms/mainwindow.ui \
                forms/keyform.ui \
                forms/fwoodform.ui \
                forms/fwprogressform.ui \
                forms/fwupdatecompleteform.ui \
                forms/updatefwform.ui \
                forms/aboutform.ui \
                forms/updatefwformWin.ui \
                forms/mainwindowWin.ui \
                forms/keyformWin.ui \
                forms/fwupdatecompleteformWin.ui \
                forms/fwprogressformWin.ui \
                forms/fwoodformWin.ui \
                forms/aboutformWin.ui \
                forms/settingsForm.ui

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
                #doc.txt

RESOURCES =    Resources.qrc

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
RC_FILE =       softstepezpzicon.rc.txt
}

macx{
ICON = resources/appicon.icns
}

