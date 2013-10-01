#-------------------------------------------------
#
# Project created by QtCreator 2013-09-16T15:37:17
#
#-------------------------------------------------

QT       += core gui \
            svn

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoftStepAdvanced
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
                mididevicemanager.cpp

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
                mididevicemanager.h

FORMS    +=     forms/mainwindow.ui \
                forms/modlineForm.ui \
                forms/keyWindowForm.ui \
                forms/settingsForm.ui \
                forms/keyBoxForm.ui

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
RC_FILE =       softstepadvancedicon.rc.txt
}

macx{
#ICON = advanced.icns
}

RESOURCES += \
    resources.qrc
