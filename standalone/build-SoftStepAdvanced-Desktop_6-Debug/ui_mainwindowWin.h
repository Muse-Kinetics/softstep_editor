// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'mainwindowWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWWIN_H
#define UI_MAINWINDOWWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *connectedLabel;
    QFrame *frame_presets;
    QFrame *frame_innerpresets;
    QToolButton *save;
    QToolButton *saveas;
    QToolButton *revert;
    QToolButton *deletepreset;
    QComboBox *presetmenu;
    QLabel *presetlabel;
    QToolButton *update;
    QLabel *label;
    QFrame *frame_displayname;
    QLineEdit *displayName;
    QLabel *presetlabel_3;
    QLabel *label_2;
    QFrame *frame_editormode;
    QCheckBox *mode;
    QPushButton *opensetlist;
    QPushButton *opensettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(699, 345);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background: rgb(30, 30, 30);\n"
"}\n"
"\n"
"/*--------QLineEdit--------*/\n"
"QLineEdit\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	border: 2px solid rgb(0,174,239);\n"
"	font: 14pt \"Droid Sans Mono\";\n"
"	color: white;\n"
"}\n"
"\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"QMenuBar\n"
"{\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background: rgb(30,30,30);\n"
"}"));
        connectedLabel = new QLabel(centralWidget);
        connectedLabel->setObjectName(QString::fromUtf8("connectedLabel"));
        connectedLabel->setGeometry(QRect(500, 101, 202, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura-Normal")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        connectedLabel->setFont(font);
        connectedLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 12pt \"Futura-Normal\";\n"
"	color: red;\n"
"	background: rgb(40, 40, 40);\n"
"	padding: 0px 0px 0px 3px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-width: 60px;\n"
"}"));
        connectedLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        frame_presets = new QFrame(centralWidget);
        frame_presets->setObjectName(QString::fromUtf8("frame_presets"));
        frame_presets->setGeometry(QRect(10, 18, 235, 119));
        frame_presets->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background: rgba(60, 60, 60, 0);\n"
"	border: none;\n"
"}"));
        frame_presets->setFrameShape(QFrame::StyledPanel);
        frame_presets->setFrameShadow(QFrame::Raised);
        frame_innerpresets = new QFrame(frame_presets);
        frame_innerpresets->setObjectName(QString::fromUtf8("frame_innerpresets"));
        frame_innerpresets->setGeometry(QRect(1, 1, 237, 108));
        frame_innerpresets->setStyleSheet(QString::fromUtf8("/*----------- QFrame ------------*/\n"
"QFrame\n"
"{\n"
"	background: rgba(125, 125, 125, 0);\n"
"}\n"
"\n"
"/*----------- QPushButton ------------*/\n"
"QPushButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	border: 2px solid rgb(230,0,134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0,1,0,0;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background: rgb(230, 0, 134);\n"
"	color: white;\n"
"	border: none;\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0, 1, 0, 0;\n"
"}\n"
"\n"
"/*----------- QToolButton ------------*/\n"
"QToolButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	border: 2px solid rgb(230,0,134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0,1,0,0;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: rgb(230, 0, 134);\n"
"	color: white;\n"
"	border: 2px solid rgb(230, 0, 134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0, 1, 0, 0;\n"
"}\n"
"\n"
"/*----------- QLabel ------------*/\n"
"QLabel\n"
"{\n"
"	background: rgba(0,0,0,0);\n"
"	color: white;\n"
"	border: non"
                        "e;\n"
"	font: 7pt \"Corbel\";\n"
"}\n"
"\n"
"/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	border: 2px solid rgb(0,174,239);\n"
"	background-color: rgba(28, 28, 29);\n"
"	color: white;\n"
" }\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 35px;\n"
"}\n"
"\n"
"QComboBox::item:alternate\n"
"{\n"
"	background: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QComboBox::item:selected\n"
"{\n"
"	border: 1px solid transparent;\n"
"	background: rgb(0,174,239);\n"
"}\n"
"\n"
"QComboBox::indicator\n"
"{\n"
"	background-color: transparent;\n"
"	selection-background-color: transparent;\n"
"	color: transparent;\n"
"	selection-color: white;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"	width: 1px;\n"
"	height: 1px;\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: right center;\n"
"	border-left-width: 0px;\n"
"	border-right-width: 0px;\n"
"	border-top-width: 0px;\n"
"	b"
                        "order-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	border: none;\n"
"	background: none;\n"
"	image: url(:/resources/setlist_combobox_menu_arrows.png);\n"
"	padding-right: 20px;\n"
"}\n"
""));
        frame_innerpresets->setFrameShape(QFrame::StyledPanel);
        frame_innerpresets->setFrameShadow(QFrame::Raised);
        save = new QToolButton(frame_innerpresets);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(15, 45, 48, 20));
        save->setStyleSheet(QString::fromUtf8("/*----------- QToolButton ------------*/\n"
"QToolButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	border: 2px solid rgb(230,0,134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: rgb(230, 0, 134);\n"
"	color: white;\n"
"	border: 2px solid rgb(230, 0, 134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0, 0, 0, 0;\n"
"}"));
        saveas = new QToolButton(frame_innerpresets);
        saveas->setObjectName(QString::fromUtf8("saveas"));
        saveas->setGeometry(QRect(69, 45, 48, 20));
        saveas->setStyleSheet(QString::fromUtf8("/*----------- QToolButton ------------*/\n"
"QToolButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	border: 2px solid rgb(230,0,134);\n"
"	font: 6pt \"Tahoma\";\n"
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: rgb(230, 0, 134);\n"
"	color: white;\n"
"	border: 2px solid rgb(230, 0, 134);\n"
"	font: 6pt \"Tahoma\";\n"
"	padding: 0, 0, 0, 0;\n"
"}"));
        revert = new QToolButton(frame_innerpresets);
        revert->setObjectName(QString::fromUtf8("revert"));
        revert->setGeometry(QRect(122, 45, 48, 20));
        revert->setStyleSheet(QString::fromUtf8("/*----------- QToolButton ------------*/\n"
"QToolButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	border: 2px solid rgb(230,0,134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: rgb(230, 0, 134);\n"
"	color: white;\n"
"	border: 2px solid rgb(230, 0, 134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0, 0, 0, 0;\n"
"}"));
        deletepreset = new QToolButton(frame_innerpresets);
        deletepreset->setObjectName(QString::fromUtf8("deletepreset"));
        deletepreset->setGeometry(QRect(176, 45, 48, 20));
        deletepreset->setStyleSheet(QString::fromUtf8("/*----------- QToolButton ------------*/\n"
"QToolButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	border: 2px solid rgb(230,0,134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: rgb(230, 0, 134);\n"
"	color: white;\n"
"	border: 2px solid rgb(230, 0, 134);\n"
"	font: 7pt \"Corbel\";\n"
"	padding: 0, 0, 0, 0;\n"
"}"));
        presetmenu = new QComboBox(frame_innerpresets);
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->addItem(QString());
        presetmenu->setObjectName(QString::fromUtf8("presetmenu"));
        presetmenu->setGeometry(QRect(15, 13, 209, 26));
        presetmenu->setAutoFillBackground(false);
        presetmenu->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	padding: 1px 3px 1px 4px;\n"
" }\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 8px \"Corbel\";\n"
"	color: white;\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 35px;\n"
"}\n"
"\n"
"QComboBox::item:alternate\n"
"{\n"
"	background: rgb(90, 90, 90);\n"
"}\n"
"\n"
"QComboBox::item:selected\n"
"{\n"
"	border: 1px solid transparent;\n"
"	background: rgb(0,174,239);\n"
"}\n"
"\n"
"QComboBox::indicator\n"
"{\n"
"	background-color: transparent;\n"
"	selection-background-color: transparent;\n"
"	color: transparent;\n"
"	selection-color: white;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"	width: 1px;\n"
"	height: 1px;\n"
"	subcontrol-origin: margin;\n"
"	subcontrol-position: right center;\n"
"	border-left-width: 0px;\n"
"	border-right-width: 0px;\n"
"	bord"
                        "er-top-width: 0px;\n"
"	border-bottom-width: 0px;\n"
"	padding: 1px 1px 1px 4px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 18px;\n"
"}"));
        presetmenu->setEditable(false);
        presetmenu->setFrame(true);
        presetlabel = new QLabel(frame_innerpresets);
        presetlabel->setObjectName(QString::fromUtf8("presetlabel"));
        presetlabel->setGeometry(QRect(-4, 12, 14, 93));
        presetlabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/mainWindow_preset_label.png);\n"
"}"));
        update = new QToolButton(frame_presets);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(16, 72, 209, 33));
        update->setStyleSheet(QString::fromUtf8("/*---------- QToolButton ---------*/\n"
"QToolButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: rgba(0,174,239,255);\n"
"	border: none;\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QToolButton::disabled\n"
"{\n"
"	background: rgba(60, 60, 60, 75);\n"
"	border: 2px solid rgba(0, 56, 77, 255);\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: rgba(255, 255, 255, 35);\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(492, 30, 184, 65));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	background: transparent;\n"
"	background-image: url(:/resources/mainWindow_logo.png);\n"
"}"));
        frame_displayname = new QFrame(centralWidget);
        frame_displayname->setObjectName(QString::fromUtf8("frame_displayname"));
        frame_displayname->setGeometry(QRect(579, 150, 101, 64));
        frame_displayname->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background: rgba(190, 0, 94, 100);\n"
"	border: 3px solid rgb(230,0,134);\n"
"}"));
        frame_displayname->setFrameShape(QFrame::StyledPanel);
        frame_displayname->setFrameShadow(QFrame::Raised);
        displayName = new QLineEdit(frame_displayname);
        displayName->setObjectName(QString::fromUtf8("displayName"));
        displayName->setGeometry(QRect(9, 25, 83, 29));
        displayName->setContextMenuPolicy(Qt::DefaultContextMenu);
        displayName->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border: 3px solid rgb(200,0,104);\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border: 3px solid white;\n"
"	padding-bottom: 2px;\n"
"}"));
        displayName->setMaxLength(4);
        displayName->setAlignment(Qt::AlignCenter);
        presetlabel_3 = new QLabel(frame_displayname);
        presetlabel_3->setObjectName(QString::fromUtf8("presetlabel_3"));
        presetlabel_3->setGeometry(QRect(14, 11, 73, 10));
        presetlabel_3->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background: none;\n"
"	background-image: url(:/resources/mainWindow_displayname_label.png);\n"
"}"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 138, 670, 10));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-top: 2px solid rgb(200, 200, 200);\n"
"	background: none;\n"
"}"));
        frame_editormode = new QFrame(centralWidget);
        frame_editormode->setObjectName(QString::fromUtf8("frame_editormode"));
        frame_editormode->setGeometry(QRect(245, 21, 228, 109));
        frame_editormode->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background: rgba(60, 60, 60, 0);\n"
"	border: none;\n"
"}"));
        frame_editormode->setFrameShape(QFrame::StyledPanel);
        frame_editormode->setFrameShadow(QFrame::Raised);
        mode = new QCheckBox(frame_editormode);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setEnabled(true);
        mode->setGeometry(QRect(7, 10, 215, 53));
        mode->setStyleSheet(QString::fromUtf8(" /* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	background: none;\n"
"    color: transparent;\n"
"    font: 8pt \"Corbel\";\n"
"}\n"
"\n"
"QCheckBox::indicator\n"
"{\n"
"    width: 215px;\n"
"    height: 53px;\n"
"	padding: 0px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_uncheckedPressed.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_checkedPressed.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_unchecked.png);\n"
"}\n"
"\n"
"QChe"
                        "ckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_uncheckedPressed.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/mainWindow_editormode_checkedPressed.png);\n"
"}\n"
"\n"
""));
        mode->setChecked(true);
        opensetlist = new QPushButton(frame_editormode);
        opensetlist->setObjectName(QString::fromUtf8("opensetlist"));
        opensetlist->setGeometry(QRect(7, 69, 104, 33));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(opensetlist->sizePolicy().hasHeightForWidth());
        opensetlist->setSizePolicy(sizePolicy1);
        opensetlist->setMinimumSize(QSize(96, 30));
        opensetlist->setMaximumSize(QSize(110, 35));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Corbel")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        opensetlist->setFont(font1);
        opensetlist->setStyleSheet(QString::fromUtf8("/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background: rgba(0,174,239,255);\n"
"	border: none;\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 18px;\n"
"}"));
        opensettings = new QPushButton(frame_editormode);
        opensettings->setObjectName(QString::fromUtf8("opensettings"));
        opensettings->setGeometry(QRect(117, 69, 104, 33));
        sizePolicy1.setHeightForWidth(opensettings->sizePolicy().hasHeightForWidth());
        opensettings->setSizePolicy(sizePolicy1);
        opensettings->setMinimumSize(QSize(96, 30));
        opensettings->setMaximumSize(QSize(110, 35));
        opensettings->setFont(font1);
        opensettings->setStyleSheet(QString::fromUtf8("/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	background: rgb(40, 40, 40);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background: rgba(0,174,239,255);\n"
"	border: none;\n"
"	font: bold 14pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 18px;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        connectedLabel->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        connectedLabel->setText(QCoreApplication::translate("MainWindow", "SOFTSTEP CONNECTED", nullptr));
#if QT_CONFIG(tooltip)
        save->setToolTip(QCoreApplication::translate("MainWindow", "Save any changes to the <br>current preset.", nullptr));
#endif // QT_CONFIG(tooltip)
        save->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
#if QT_CONFIG(tooltip)
        saveas->setToolTip(QCoreApplication::translate("MainWindow", "Save the current settings<br> to a new preset slot.", nullptr));
#endif // QT_CONFIG(tooltip)
        saveas->setText(QCoreApplication::translate("MainWindow", "SAVE AS", nullptr));
#if QT_CONFIG(tooltip)
        revert->setToolTip(QCoreApplication::translate("MainWindow", "Revert any unsaved <br>changes in the current <br>preset to its previously <br>saved state.", nullptr));
#endif // QT_CONFIG(tooltip)
        revert->setText(QCoreApplication::translate("MainWindow", "REVERT", nullptr));
#if QT_CONFIG(tooltip)
        deletepreset->setToolTip(QCoreApplication::translate("MainWindow", "Delete the currently selected preset.", nullptr));
#endif // QT_CONFIG(tooltip)
        deletepreset->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        presetmenu->setItemText(0, QCoreApplication::translate("MainWindow", "PRESET_NAME_HERE", nullptr));
        presetmenu->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        presetmenu->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        presetmenu->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        presetmenu->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        presetmenu->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        presetmenu->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        presetmenu->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        presetmenu->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        presetmenu->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        presetmenu->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

#if QT_CONFIG(tooltip)
        presetmenu->setToolTip(QCoreApplication::translate("MainWindow", "The preset currently being edited", nullptr));
#endif // QT_CONFIG(tooltip)
        presetlabel->setText(QString());
#if QT_CONFIG(tooltip)
        update->setToolTip(QCoreApplication::translate("MainWindow", "\"Make it so.\"<p>Update a connected SoftStep's presets with the current setlist.", nullptr));
#endif // QT_CONFIG(tooltip)
        update->setText(QCoreApplication::translate("MainWindow", "Send To SoftStep", nullptr));
        label->setText(QString());
#if QT_CONFIG(tooltip)
        displayName->setToolTip(QCoreApplication::translate("MainWindow", "Sets the current preset's display name. <p> Anything entered here appears on<br> the SoftStep's alphanumeric display<br> when the preset is selected. <p>Limited to a maximum of four characters.", nullptr));
#endif // QT_CONFIG(tooltip)
        displayName->setText(QCoreApplication::translate("MainWindow", "NEXU", nullptr));
        presetlabel_3->setText(QString());
        label_2->setText(QString());
#if QT_CONFIG(tooltip)
        mode->setToolTip(QCoreApplication::translate("MainWindow", "Switch between Hosted <br>and Standalone mode.", nullptr));
#endif // QT_CONFIG(tooltip)
        mode->setText(QString());
#if QT_CONFIG(tooltip)
        opensetlist->setToolTip(QCoreApplication::translate("MainWindow", "Open the setlist window.", nullptr));
#endif // QT_CONFIG(tooltip)
        opensetlist->setText(QCoreApplication::translate("MainWindow", "Setlist", nullptr));
#if QT_CONFIG(tooltip)
        opensettings->setToolTip(QCoreApplication::translate("MainWindow", "Open the settings window.", nullptr));
#endif // QT_CONFIG(tooltip)
        opensettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWWIN_H
