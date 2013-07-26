#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T16:45:40
#
#-------------------------------------------------

QT       += core gui

TARGET = "SoftStep Easy Editor"
TEMPLATE = app

INCLUDEPATH +=  forms \
                sysexComposition

SOURCES += main.cpp\
        mainwindow.cpp \
    key.cpp \
    presetinterface.cpp \
    #atributemanager.cpp \
    mididevicemanager.cpp \
    sysexComposition/utils.c \
    sysexComposition/syxtx.c \
    sysexComposition/syxrx.c \
    sysexComposition/query.c \
    sysexComposition/maxapi.c \
    sysexComposition/download.c \
    sysexComposition/attribute.c \
    sysexComposition/mainsysex.c \
    sysexComposition/sysexcomposer.cpp

HEADERS  += mainwindow.h \
    key.h \
    presetinterface.h \
    #atributemanager.h \
    mididevicemanager.h \
    sysexComposition/utils.h \
    sysexComposition/syxtx.h \
    sysexComposition/syxrx.h \
    sysexComposition/syxformats.h \
    sysexComposition/softstep.h \
    sysexComposition/query.h \
    sysexComposition/midi.h \
    sysexComposition/maxapi.h \
    sysexComposition/download.h \
    sysexComposition/attribute.h \
    sysexComposition/sysexcomposer.h \
    sysexMessages.h


FORMS    += \
    forms/mainwindow.ui \
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
    forms/aboutformWin.ui

OTHER_FILES += \
    stylesheets/keyRadioButtonStylesheet.qss \
    doc.txt

RESOURCES += \
    Resources.qrc

#-------------------QJson-------------------#
#-------------------------------------------#
static{
DEFINES += STATIC_BUILD
}

INCLUDEPATH += qjson/src

SOURCES += \
  qjson/src/json_parser.cc \
  qjson/src/json_scanner.cpp \
  qjson/src/parser.cpp \
  qjson/src/qobjecthelper.cpp \
  qjson/src/serializer.cpp

#-------------------Max/MSP-------------------#
#---------------------------------------------#
win32{
LIBS += -lwinmm
}

macx{
LIBS += -framework CoreMIDI
LIBS += -framework CoreFoundation
LIBS += -framework Cocoa
LIBS += -framework CoreServices
}

win32{
RC_FILE = softstepEasyIcon.rc.txt
}

macx{
ICON = easy.icns
}
