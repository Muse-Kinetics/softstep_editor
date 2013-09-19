#-------------------------------------------------
#
# Project created by QtCreator 2013-09-16T15:37:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoftStepAdvanced
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modline.cpp \
    key.cpp

HEADERS  += mainwindow.h \
    modline.h \
    key.h

FORMS    += mainwindow.ui \
    modlineForm.ui \
    keyWindowForm.ui \
    settingsForm.ui \
    keyBoxForm.ui
