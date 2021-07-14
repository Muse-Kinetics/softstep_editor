// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *settingsFrame;
    QSpinBox *midiChannel;
    QSpinBox *pedalCC;
    QLineEdit *displayName;
    QLabel *midiChannelLabel;
    QLabel *sceneNameLabel;
    QLabel *gainLabel_3;
    QLabel *gainLabel_4;
    QSpinBox *navPadCC;
    QLabel *softstepLabel;
    QLabel *connectedLabel;
    QLabel *sensitivityLabel;
    QSpinBox *currentPreset;
    QPushButton *update;
    QLabel *currentPresetLabel;
    QLabel *backlightLabel;
    QDoubleSpinBox *sensitivity;
    QCheckBox *backlight;
    QPushButton *revert;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(995, 344);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(24);
        centralWidget->setFont(font);
        centralWidget->setFocusPolicy(Qt::NoFocus);
        centralWidget->setContextMenuPolicy(Qt::PreventContextMenu);
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgba(35,31,32,255);\n"
"	border: none;/*6px solid rgba(0,174,239,255);*/\n"
"}  \n"
"\n"
"/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: 9pt \"Futura\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border: 2px solid white;\n"
"	font: 9pt \"Futura\";\n"
"	background: rgba(0,174,239,255);\n"
"	color: white;\n"
"}\n"
"\n"
"\n"
"/* ---------- QLabels ------------*/\n"
"QLabel\n"
"{\n"
"	background:		rgba(0,0,0,0);\n"
"	color: 				white;\n"
"	font: 				10pt \"Futura\";\n"
"	border:				none;\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	border:				none;\n"
"}  \n"
"\n"
"/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 10pt \"Futura\";\n"
"	border: 2px solid rgb(0,174,239);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"}\n"
"\n"
"QAbstractSpinBox:focus\n"
"{\n"
"	border: 2px solid rgb(255,255,255);\n"
"	outline: none;\n"
"}\n"
"\n"
"QDoubleSpinBo"
                        "x\n"
"{\n"
"	font: 10pt \"Futura\";\n"
"	border: 2px solid rgb(0,174,239);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 10pt \"Futura\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border: 2px solid rgb(255,255,255);\n"
"	outline: none;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"color: rgba(255,255,255,0);\n"
"	font: 10pt \"Futura\";\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height: 20px;\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/toggle_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/toggle_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     im"
                        "age: url(:/resources/toggle_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/toggle_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/toggle_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/toggle_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/toggle_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/toggle_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed:focus {\n"
"     image: url(:/resources/toggle_focus_off.png);\n"
" }\n"
"\n"
"QStackedWidget\n"
"{\n"
"border-top: 1px solid white;\n"
"background: black;\n"
"}\n"
"\n"
""));
        settingsFrame = new QFrame(centralWidget);
        settingsFrame->setObjectName(QString::fromUtf8("settingsFrame"));
        settingsFrame->setGeometry(QRect(845, 112, 141, 102));
        sizePolicy.setHeightForWidth(settingsFrame->sizePolicy().hasHeightForWidth());
        settingsFrame->setSizePolicy(sizePolicy);
        settingsFrame->setMinimumSize(QSize(0, 0));
        settingsFrame->setFocusPolicy(Qt::NoFocus);
        settingsFrame->setContextMenuPolicy(Qt::NoContextMenu);
        settingsFrame->setStyleSheet(QString::fromUtf8(""));
        settingsFrame->setFrameShape(QFrame::StyledPanel);
        settingsFrame->setFrameShadow(QFrame::Raised);
        midiChannel = new QSpinBox(settingsFrame);
        midiChannel->setObjectName(QString::fromUtf8("midiChannel"));
        midiChannel->setGeometry(QRect(100, 5, 40, 20));
        midiChannel->setFocusPolicy(Qt::WheelFocus);
        midiChannel->setContextMenuPolicy(Qt::NoContextMenu);
        midiChannel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        midiChannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        midiChannel->setMinimum(1);
        midiChannel->setMaximum(16);
        pedalCC = new QSpinBox(settingsFrame);
        pedalCC->setObjectName(QString::fromUtf8("pedalCC"));
        pedalCC->setGeometry(QRect(100, 55, 40, 20));
        pedalCC->setFocusPolicy(Qt::WheelFocus);
        pedalCC->setContextMenuPolicy(Qt::NoContextMenu);
        pedalCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pedalCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pedalCC->setMinimum(-1);
        pedalCC->setMaximum(127);
        pedalCC->setValue(7);
        displayName = new QLineEdit(settingsFrame);
        displayName->setObjectName(QString::fromUtf8("displayName"));
        displayName->setGeometry(QRect(100, 80, 40, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Futura")});
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        displayName->setFont(font1);
        displayName->setFocusPolicy(Qt::WheelFocus);
        displayName->setContextMenuPolicy(Qt::NoContextMenu);
        displayName->setStyleSheet(QString::fromUtf8(""));
        displayName->setMaxLength(4);
        displayName->setFrame(true);
        displayName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        midiChannelLabel = new QLabel(settingsFrame);
        midiChannelLabel->setObjectName(QString::fromUtf8("midiChannelLabel"));
        midiChannelLabel->setGeometry(QRect(0, 5, 89, 20));
        midiChannelLabel->setStyleSheet(QString::fromUtf8(""));
        midiChannelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sceneNameLabel = new QLabel(settingsFrame);
        sceneNameLabel->setObjectName(QString::fromUtf8("sceneNameLabel"));
        sceneNameLabel->setGeometry(QRect(0, 80, 89, 20));
        sceneNameLabel->setStyleSheet(QString::fromUtf8(""));
        sceneNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gainLabel_3 = new QLabel(settingsFrame);
        gainLabel_3->setObjectName(QString::fromUtf8("gainLabel_3"));
        gainLabel_3->setGeometry(QRect(0, 30, 89, 20));
        gainLabel_3->setStyleSheet(QString::fromUtf8(""));
        gainLabel_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gainLabel_4 = new QLabel(settingsFrame);
        gainLabel_4->setObjectName(QString::fromUtf8("gainLabel_4"));
        gainLabel_4->setGeometry(QRect(0, 55, 89, 20));
        gainLabel_4->setStyleSheet(QString::fromUtf8(""));
        gainLabel_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navPadCC = new QSpinBox(settingsFrame);
        navPadCC->setObjectName(QString::fromUtf8("navPadCC"));
        navPadCC->setGeometry(QRect(100, 30, 40, 20));
        navPadCC->setFocusPolicy(Qt::WheelFocus);
        navPadCC->setContextMenuPolicy(Qt::NoContextMenu);
        navPadCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navPadCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navPadCC->setMinimum(-1);
        navPadCC->setMaximum(127);
        navPadCC->setValue(7);
        softstepLabel = new QLabel(centralWidget);
        softstepLabel->setObjectName(QString::fromUtf8("softstepLabel"));
        softstepLabel->setGeometry(QRect(860, 0, 121, 41));
        softstepLabel->setStyleSheet(QString::fromUtf8("font: 30pt \"Futura\";"));
        softstepLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        connectedLabel = new QLabel(centralWidget);
        connectedLabel->setObjectName(QString::fromUtf8("connectedLabel"));
        connectedLabel->setGeometry(QRect(876, 31, 85, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Futura")});
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setItalic(false);
        connectedLabel->setFont(font2);
        connectedLabel->setStyleSheet(QString::fromUtf8("font:bold 8pt \"Futura\";\n"
"color: red;"));
        connectedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sensitivityLabel = new QLabel(centralWidget);
        sensitivityLabel->setObjectName(QString::fromUtf8("sensitivityLabel"));
        sensitivityLabel->setGeometry(QRect(844, 60, 89, 20));
        sensitivityLabel->setStyleSheet(QString::fromUtf8(""));
        sensitivityLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        currentPreset = new QSpinBox(centralWidget);
        currentPreset->setObjectName(QString::fromUtf8("currentPreset"));
        currentPreset->setGeometry(QRect(945, 227, 40, 20));
        currentPreset->setFocusPolicy(Qt::WheelFocus);
        currentPreset->setContextMenuPolicy(Qt::NoContextMenu);
        currentPreset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        currentPreset->setButtonSymbols(QAbstractSpinBox::NoButtons);
        currentPreset->setMinimum(1);
        currentPreset->setMaximum(10);
        currentPreset->setValue(1);
        update = new QPushButton(centralWidget);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(845, 252, 140, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Futura")});
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setItalic(false);
        update->setFont(font3);
        update->setFocusPolicy(Qt::NoFocus);
        update->setContextMenuPolicy(Qt::NoContextMenu);
        update->setStyleSheet(QString::fromUtf8("/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 6px solid rgba(0,174,239,255);\n"
"	font: 18pt \"Futura\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background: rgba(0,174,239,255);\n"
"	border: 6px solid white;\n"
"	font: 20pt \"Futura\";\n"
"	color: white;\n"
"}"));
        currentPresetLabel = new QLabel(centralWidget);
        currentPresetLabel->setObjectName(QString::fromUtf8("currentPresetLabel"));
        currentPresetLabel->setGeometry(QRect(844, 227, 89, 20));
        currentPresetLabel->setStyleSheet(QString::fromUtf8(""));
        currentPresetLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        backlightLabel = new QLabel(centralWidget);
        backlightLabel->setObjectName(QString::fromUtf8("backlightLabel"));
        backlightLabel->setGeometry(QRect(844, 88, 89, 20));
        backlightLabel->setStyleSheet(QString::fromUtf8(""));
        backlightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sensitivity = new QDoubleSpinBox(centralWidget);
        sensitivity->setObjectName(QString::fromUtf8("sensitivity"));
        sensitivity->setGeometry(QRect(945, 60, 40, 20));
        sensitivity->setFocusPolicy(Qt::WheelFocus);
        sensitivity->setContextMenuPolicy(Qt::NoContextMenu);
        sensitivity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sensitivity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sensitivity->setMinimum(0.500000000000000);
        sensitivity->setMaximum(2.550000000000000);
        sensitivity->setValue(1.000000000000000);
        backlight = new QCheckBox(centralWidget);
        backlight->setObjectName(QString::fromUtf8("backlight"));
        backlight->setGeometry(QRect(945, 87, 21, 21));
        backlight->setFocusPolicy(Qt::WheelFocus);
        backlight->setContextMenuPolicy(Qt::NoContextMenu);
        backlight->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	color: rgba(255,255,255,250);\n"
"	font: 10pt \"Futura\";\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 23px;\n"
"     height: 23px;\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/toggle_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/toggle_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/toggle_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/toggle_on.png);\n"
"	padding-left: -1px;\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/toggle_off.png);\n"
"	padding-left: -1px;\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/toggle_off_focus.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/toggle_on_focus.png);\n"
"	padding-left: -1px;\n"
""
                        " }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/toggle_on_focus.png);\n"
"	padding-left: -1px;\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed:focus {\n"
"     image: url(:/resources/toggle_off_focus.png);\n"
"	padding-left: 0px;\n"
" }\n"
""));
        revert = new QPushButton(centralWidget);
        revert->setObjectName(QString::fromUtf8("revert"));
        revert->setGeometry(QRect(845, 307, 140, 27));
        revert->setFont(font1);
        revert->setFocusPolicy(Qt::NoFocus);
        revert->setContextMenuPolicy(Qt::NoContextMenu);
        revert->setStyleSheet(QString::fromUtf8("/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 4px solid rgba(0,174,239,255);\n"
"	font: 10pt \"Futura\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background: rgba(0,174,239,255);\n"
"	border: 4px solid white;\n"
"	font: 10pt \"Futura\";\n"
"	color: white;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        settingsFrame->raise();
        softstepLabel->raise();
        connectedLabel->raise();
        sensitivityLabel->raise();
        backlightLabel->raise();
        sensitivity->raise();
        backlight->raise();
        currentPreset->raise();
        update->raise();
        currentPresetLabel->raise();
        revert->raise();
        QWidget::setTabOrder(midiChannel, sensitivity);
        QWidget::setTabOrder(sensitivity, navPadCC);
        QWidget::setTabOrder(navPadCC, pedalCC);
        QWidget::setTabOrder(pedalCC, backlight);
        QWidget::setTabOrder(backlight, displayName);
        QWidget::setTabOrder(displayName, currentPreset);
        QWidget::setTabOrder(currentPreset, update);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pedalCC->setSpecialValueText(QCoreApplication::translate("MainWindow", "off", nullptr));
        displayName->setText(QCoreApplication::translate("MainWindow", "EASY", nullptr));
        midiChannelLabel->setText(QCoreApplication::translate("MainWindow", "MIDI Channel", nullptr));
        sceneNameLabel->setText(QCoreApplication::translate("MainWindow", "Display Name", nullptr));
        gainLabel_3->setText(QCoreApplication::translate("MainWindow", "Nav Pad CC#", nullptr));
        gainLabel_4->setText(QCoreApplication::translate("MainWindow", "Pedal CC#", nullptr));
        navPadCC->setSpecialValueText(QCoreApplication::translate("MainWindow", "off", nullptr));
        softstepLabel->setText(QCoreApplication::translate("MainWindow", "SoftStep", nullptr));
        connectedLabel->setText(QCoreApplication::translate("MainWindow", "NOT CONNECTED", nullptr));
        sensitivityLabel->setText(QCoreApplication::translate("MainWindow", "Sensitivity", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "SAVE + SEND", nullptr));
        currentPresetLabel->setText(QCoreApplication::translate("MainWindow", "CURRENT PRESET", nullptr));
        backlightLabel->setText(QCoreApplication::translate("MainWindow", "Backlight", nullptr));
        backlight->setText(QString());
        revert->setText(QCoreApplication::translate("MainWindow", "REVERT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
