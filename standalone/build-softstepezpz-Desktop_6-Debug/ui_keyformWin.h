// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'keyformWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYFORMWIN_H
#define UI_KEYFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyForm
{
public:
    QLineEdit *name;
    QCheckBox *sourceNote;
    QCheckBox *sourcePressure;
    QCheckBox *sourceToggle;
    QCheckBox *sourceXY;
    QCheckBox *sourceYInc;
    QCheckBox *sourceProgram;
    QLabel *instanceLabel;
    QLabel *nameLabel;
    QLabel *dividerLine;
    QStackedWidget *sourcesParams;
    QWidget *notePage;
    QLabel *noteNumLabel;
    QSpinBox *noteNum;
    QLabel *noteVelocityLabel;
    QSpinBox *noteVelocity;
    QLabel *noteToggleLabel;
    QCheckBox *noteToggle;
    QWidget *pressurePage;
    QLabel *pressureCCLabel;
    QLabel *pressureSmoothLabel;
    QSpinBox *pressureCC;
    QSpinBox *pressureSmooth;
    QWidget *togglePage;
    QSpinBox *toggleCC;
    QLabel *toggleCCLabel;
    QLabel *toggleLoLabel;
    QSpinBox *toggleLo;
    QLabel *toggleHiLabel;
    QSpinBox *toggleHi;
    QWidget *xyPage;
    QSpinBox *xyXCC;
    QLabel *xyXCCLabel;
    QLabel *xyYCCLabel;
    QSpinBox *xyYCC;
    QCheckBox *xyLatch;
    QLabel *xyLatchLabel;
    QWidget *yIncPage;
    QSpinBox *yIncCC;
    QLabel *yIncCCLabel;
    QSpinBox *yIncSpeed;
    QLabel *yIncSpeedLabel;
    QWidget *programPage;
    QSpinBox *programNum;
    QLabel *programNumLabel;
    QSpinBox *programBank;
    QLabel *programBankLabel;
    QWidget *offPage;
    QLabel *label;

    void setupUi(QWidget *keyForm)
    {
        if (keyForm->objectName().isEmpty())
            keyForm->setObjectName(QString::fromUtf8("keyForm"));
        keyForm->resize(157, 157);
        keyForm->setAutoFillBackground(false);
        keyForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgba(35,31,32,255);\n"
"	border: 6px solid rgba(0,174,239,255);\n"
"}  \n"
"\n"
"QWidget:hover\n"
"{\n"
"	/*border:				3px solid rgb(0, 126, 126)*/\n"
"}        \n"
"\n"
"/* ---------- QLabels ------------*/\n"
"QLabel\n"
"{\n"
"	background:		rgba(0,0,0,0);\n"
"	color: 				white;\n"
"	font: 				8pt \"Corbel\";\n"
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
"	font: 8pt \"Corbel\";\n"
"	border: 2px solid rgb(0,174,239);\n"
"	background-color: rgba(0, 0, 0, 255);\n"
"	color: white;\n"
"	padding:0, 0, 0, 0;\n"
"}\n"
"\n"
"QSpinBox::focus\n"
"{\n"
"	border: none;\n"
"	outline: none;\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	backgr"
                        "ound: rgba(0,174,239,0);\n"
"	border: 2px solid white;\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	background:rgba(0,174,239,0);\n"
"	color: white;\n"
"	padding:0, 0, 0, 0;\n"
"	border: none;\n"
"}\n"
"\n"
"QCheckBox:focus\n"
"{\n"
"	background:rgba(0,174,239,0);\n"
"}\n"
"\n"
"\n"
"/* ------- QStackedWidget ---------*/\n"
"QStackedWidget\n"
"{\n"
"border-top: 1px solid white;\n"
"background: black;\n"
"}\n"
"\n"
""));
        name = new QLineEdit(keyForm);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(101, 80, 40, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        name->setFont(font);
        name->setFocusPolicy(Qt::WheelFocus);
        name->setStyleSheet(QString::fromUtf8(""));
        name->setMaxLength(4);
        name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sourceNote = new QCheckBox(keyForm);
        sourceNote->setObjectName(QString::fromUtf8("sourceNote"));
        sourceNote->setGeometry(QRect(15, 12, 71, 16));
        sourceNote->setFocusPolicy(Qt::WheelFocus);
        sourceNote->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 10px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"  QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:p"
                        "ressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        sourcePressure = new QCheckBox(keyForm);
        sourcePressure->setObjectName(QString::fromUtf8("sourcePressure"));
        sourcePressure->setGeometry(QRect(15, 27, 61, 16));
        sourcePressure->setFocusPolicy(Qt::WheelFocus);
        sourcePressure->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 10px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"  QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:p"
                        "ressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        sourceToggle = new QCheckBox(keyForm);
        sourceToggle->setObjectName(QString::fromUtf8("sourceToggle"));
        sourceToggle->setGeometry(QRect(15, 42, 51, 16));
        sourceToggle->setFocusPolicy(Qt::WheelFocus);
        sourceToggle->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 10px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"  QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:p"
                        "ressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        sourceXY = new QCheckBox(keyForm);
        sourceXY->setObjectName(QString::fromUtf8("sourceXY"));
        sourceXY->setGeometry(QRect(15, 57, 41, 16));
        sourceXY->setFocusPolicy(Qt::WheelFocus);
        sourceXY->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 10px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"  QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:p"
                        "ressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        sourceYInc = new QCheckBox(keyForm);
        sourceYInc->setObjectName(QString::fromUtf8("sourceYInc"));
        sourceYInc->setGeometry(QRect(15, 72, 51, 16));
        sourceYInc->setFocusPolicy(Qt::WheelFocus);
        sourceYInc->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 10px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"  QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:p"
                        "ressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        sourceProgram = new QCheckBox(keyForm);
        sourceProgram->setObjectName(QString::fromUtf8("sourceProgram"));
        sourceProgram->setGeometry(QRect(15, 87, 61, 16));
        sourceProgram->setFocusPolicy(Qt::WheelFocus);
        sourceProgram->setAutoFillBackground(false);
        sourceProgram->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"     width: 10px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"  QCheckBox::indicator::unchecked {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked {\n"
"     image: url(:/resources/radio_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/resources/radio_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::unchecked:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator::checked:focus {\n"
"     image: url(:/resources/radio_focus_on.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:p"
                        "ressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        instanceLabel = new QLabel(keyForm);
        instanceLabel->setObjectName(QString::fromUtf8("instanceLabel"));
        instanceLabel->setGeometry(QRect(100, 10, 51, 40));
        instanceLabel->setStyleSheet(QString::fromUtf8("font: 27pt \"Futura\";"));
        instanceLabel->setAlignment(Qt::AlignCenter);
        nameLabel = new QLabel(keyForm);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(101, 65, 40, 15));
        nameLabel->setAlignment(Qt::AlignCenter);
        dividerLine = new QLabel(keyForm);
        dividerLine->setObjectName(QString::fromUtf8("dividerLine"));
        dividerLine->setGeometry(QRect(15, 105, 127, 16));
        dividerLine->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"border-top: 1px solid white;\n"
"}"));
        sourcesParams = new QStackedWidget(keyForm);
        sourcesParams->setObjectName(QString::fromUtf8("sourcesParams"));
        sourcesParams->setGeometry(QRect(10, 105, 136, 44));
        sourcesParams->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"border: none;\n"
"background: rgba(0, 0, 0, 0);\n"
"}\n"
"/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 8pt \"Futura-Normal\";\n"
"	border: 2px solid rgb(0,174,239);\n"
"	background: rgba(0, 0, 0, 0);\n"
"	color: white;\n"
"	padding:0, 0, 0, 0;\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"outline: none;\n"
"border: 2px solid white;\n"
"}"));
        notePage = new QWidget();
        notePage->setObjectName(QString::fromUtf8("notePage"));
        QFont font1;
        font1.setPointSize(7);
        notePage->setFont(font1);
        noteNumLabel = new QLabel(notePage);
        noteNumLabel->setObjectName(QString::fromUtf8("noteNumLabel"));
        noteNumLabel->setGeometry(QRect(6, 0, 40, 20));
        noteNumLabel->setAlignment(Qt::AlignCenter);
        noteNum = new QSpinBox(notePage);
        noteNum->setObjectName(QString::fromUtf8("noteNum"));
        noteNum->setGeometry(QRect(6, 20, 40, 20));
        noteNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        noteNum->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noteNum->setMaximum(127);
        noteVelocityLabel = new QLabel(notePage);
        noteVelocityLabel->setObjectName(QString::fromUtf8("noteVelocityLabel"));
        noteVelocityLabel->setGeometry(QRect(58, 0, 40, 20));
        noteVelocityLabel->setAlignment(Qt::AlignCenter);
        noteVelocity = new QSpinBox(notePage);
        noteVelocity->setObjectName(QString::fromUtf8("noteVelocity"));
        noteVelocity->setGeometry(QRect(58, 20, 40, 20));
        noteVelocity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        noteVelocity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noteVelocity->setMaximum(127);
        noteToggleLabel = new QLabel(notePage);
        noteToggleLabel->setObjectName(QString::fromUtf8("noteToggleLabel"));
        noteToggleLabel->setGeometry(QRect(101, 0, 40, 20));
        noteToggleLabel->setAlignment(Qt::AlignCenter);
        noteToggle = new QCheckBox(notePage);
        noteToggle->setObjectName(QString::fromUtf8("noteToggle"));
        noteToggle->setGeometry(QRect(111, 19, 21, 23));
        noteToggle->setFocusPolicy(Qt::WheelFocus);
        noteToggle->setStyleSheet(QString::fromUtf8("QCheckBox::indicator\n"
"{\n"
"	width: 20px;\n"
"	height: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"	image:url(:/resources/toggle_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"	image:url(:/resources/toggle_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"	image:url(:/resources/toggle_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"	image:url(:/resources/toggle_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover\n"
"{\n"
"	image:url(:/resources/toggle_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"	image:url(:/resources/toggle_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled\n"
"{\n"
"	image:url(:/resources/toggle_off_disabled.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled\n"
"{\n"
"	image:url(:/resources/toggle_off_disabled.png)\n"
"}"));
        sourcesParams->addWidget(notePage);
        pressurePage = new QWidget();
        pressurePage->setObjectName(QString::fromUtf8("pressurePage"));
        pressurePage->setFont(font1);
        pressureCCLabel = new QLabel(pressurePage);
        pressureCCLabel->setObjectName(QString::fromUtf8("pressureCCLabel"));
        pressureCCLabel->setGeometry(QRect(8, 0, 40, 20));
        pressureCCLabel->setAlignment(Qt::AlignCenter);
        pressureSmoothLabel = new QLabel(pressurePage);
        pressureSmoothLabel->setObjectName(QString::fromUtf8("pressureSmoothLabel"));
        pressureSmoothLabel->setGeometry(QRect(81, 0, 61, 20));
        pressureSmoothLabel->setAlignment(Qt::AlignCenter);
        pressureCC = new QSpinBox(pressurePage);
        pressureCC->setObjectName(QString::fromUtf8("pressureCC"));
        pressureCC->setGeometry(QRect(6, 20, 40, 20));
        pressureCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pressureCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pressureCC->setMaximum(127);
        pressureSmooth = new QSpinBox(pressurePage);
        pressureSmooth->setObjectName(QString::fromUtf8("pressureSmooth"));
        pressureSmooth->setGeometry(QRect(91, 20, 40, 20));
        pressureSmooth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pressureSmooth->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pressureSmooth->setMaximum(127);
        sourcesParams->addWidget(pressurePage);
        togglePage = new QWidget();
        togglePage->setObjectName(QString::fromUtf8("togglePage"));
        togglePage->setFont(font1);
        toggleCC = new QSpinBox(togglePage);
        toggleCC->setObjectName(QString::fromUtf8("toggleCC"));
        toggleCC->setGeometry(QRect(6, 20, 40, 20));
        toggleCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        toggleCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        toggleCC->setMaximum(127);
        toggleCCLabel = new QLabel(togglePage);
        toggleCCLabel->setObjectName(QString::fromUtf8("toggleCCLabel"));
        toggleCCLabel->setGeometry(QRect(8, 0, 40, 20));
        toggleCCLabel->setAlignment(Qt::AlignCenter);
        toggleLoLabel = new QLabel(togglePage);
        toggleLoLabel->setObjectName(QString::fromUtf8("toggleLoLabel"));
        toggleLoLabel->setGeometry(QRect(68, 0, 30, 20));
        toggleLoLabel->setAlignment(Qt::AlignCenter);
        toggleLo = new QSpinBox(togglePage);
        toggleLo->setObjectName(QString::fromUtf8("toggleLo"));
        toggleLo->setGeometry(QRect(68, 20, 30, 20));
        toggleLo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        toggleLo->setButtonSymbols(QAbstractSpinBox::NoButtons);
        toggleLo->setMaximum(127);
        toggleHiLabel = new QLabel(togglePage);
        toggleHiLabel->setObjectName(QString::fromUtf8("toggleHiLabel"));
        toggleHiLabel->setGeometry(QRect(100, 0, 30, 20));
        toggleHiLabel->setAlignment(Qt::AlignCenter);
        toggleHi = new QSpinBox(togglePage);
        toggleHi->setObjectName(QString::fromUtf8("toggleHi"));
        toggleHi->setGeometry(QRect(101, 20, 30, 20));
        toggleHi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        toggleHi->setButtonSymbols(QAbstractSpinBox::NoButtons);
        toggleHi->setMaximum(127);
        sourcesParams->addWidget(togglePage);
        xyPage = new QWidget();
        xyPage->setObjectName(QString::fromUtf8("xyPage"));
        xyPage->setFont(font1);
        xyXCC = new QSpinBox(xyPage);
        xyXCC->setObjectName(QString::fromUtf8("xyXCC"));
        xyXCC->setGeometry(QRect(6, 20, 40, 20));
        xyXCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        xyXCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        xyXCC->setMinimum(-1);
        xyXCC->setMaximum(127);
        xyXCC->setValue(-1);
        xyXCCLabel = new QLabel(xyPage);
        xyXCCLabel->setObjectName(QString::fromUtf8("xyXCCLabel"));
        xyXCCLabel->setGeometry(QRect(6, 0, 40, 20));
        xyXCCLabel->setAlignment(Qt::AlignCenter);
        xyYCCLabel = new QLabel(xyPage);
        xyYCCLabel->setObjectName(QString::fromUtf8("xyYCCLabel"));
        xyYCCLabel->setGeometry(QRect(58, 0, 40, 20));
        xyYCCLabel->setAlignment(Qt::AlignCenter);
        xyYCC = new QSpinBox(xyPage);
        xyYCC->setObjectName(QString::fromUtf8("xyYCC"));
        xyYCC->setGeometry(QRect(58, 20, 40, 20));
        xyYCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        xyYCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        xyYCC->setMinimum(-1);
        xyYCC->setMaximum(127);
        xyYCC->setValue(-1);
        xyLatch = new QCheckBox(xyPage);
        xyLatch->setObjectName(QString::fromUtf8("xyLatch"));
        xyLatch->setGeometry(QRect(111, 20, 22, 21));
        xyLatch->setFocusPolicy(Qt::WheelFocus);
        xyLatch->setStyleSheet(QString::fromUtf8("QCheckBox::indicator\n"
"{\n"
"	width: 20px;\n"
"	height: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"	image:url(:/resources/toggle_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"	image:url(:/resources/toggle_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"	image:url(:/resources/toggle_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"	image:url(:/resources/toggle_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover\n"
"{\n"
"	image:url(:/resources/toggle_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"	image:url(:/resources/toggle_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled\n"
"{\n"
"	image:url(:/resources/toggle_off_disabled.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled\n"
"{\n"
"	image:url(:/resources/toggle_off_disabled.png)\n"
"}"));
        xyLatchLabel = new QLabel(xyPage);
        xyLatchLabel->setObjectName(QString::fromUtf8("xyLatchLabel"));
        xyLatchLabel->setGeometry(QRect(91, 0, 61, 20));
        xyLatchLabel->setAlignment(Qt::AlignCenter);
        sourcesParams->addWidget(xyPage);
        yIncPage = new QWidget();
        yIncPage->setObjectName(QString::fromUtf8("yIncPage"));
        yIncPage->setFont(font1);
        yIncCC = new QSpinBox(yIncPage);
        yIncCC->setObjectName(QString::fromUtf8("yIncCC"));
        yIncCC->setGeometry(QRect(6, 20, 40, 20));
        yIncCC->setStyleSheet(QString::fromUtf8("outline: none;"));
        yIncCC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        yIncCC->setButtonSymbols(QAbstractSpinBox::NoButtons);
        yIncCC->setMaximum(127);
        yIncCCLabel = new QLabel(yIncPage);
        yIncCCLabel->setObjectName(QString::fromUtf8("yIncCCLabel"));
        yIncCCLabel->setGeometry(QRect(8, 0, 40, 20));
        yIncCCLabel->setAlignment(Qt::AlignCenter);
        yIncSpeed = new QSpinBox(yIncPage);
        yIncSpeed->setObjectName(QString::fromUtf8("yIncSpeed"));
        yIncSpeed->setGeometry(QRect(91, 20, 40, 20));
        yIncSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        yIncSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        yIncSpeed->setMaximum(127);
        yIncSpeedLabel = new QLabel(yIncPage);
        yIncSpeedLabel->setObjectName(QString::fromUtf8("yIncSpeedLabel"));
        yIncSpeedLabel->setGeometry(QRect(65, 0, 91, 20));
        yIncSpeedLabel->setAlignment(Qt::AlignCenter);
        sourcesParams->addWidget(yIncPage);
        programPage = new QWidget();
        programPage->setObjectName(QString::fromUtf8("programPage"));
        programPage->setFont(font1);
        programNum = new QSpinBox(programPage);
        programNum->setObjectName(QString::fromUtf8("programNum"));
        programNum->setGeometry(QRect(6, 20, 40, 20));
        programNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        programNum->setButtonSymbols(QAbstractSpinBox::NoButtons);
        programNum->setMaximum(127);
        programNumLabel = new QLabel(programPage);
        programNumLabel->setObjectName(QString::fromUtf8("programNumLabel"));
        programNumLabel->setGeometry(QRect(3, 0, 51, 20));
        programNumLabel->setAlignment(Qt::AlignCenter);
        programBank = new QSpinBox(programPage);
        programBank->setObjectName(QString::fromUtf8("programBank"));
        programBank->setGeometry(QRect(91, 20, 40, 20));
        programBank->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        programBank->setButtonSymbols(QAbstractSpinBox::NoButtons);
        programBank->setMinimum(-1);
        programBank->setMaximum(127);
        programBank->setValue(-1);
        programBankLabel = new QLabel(programPage);
        programBankLabel->setObjectName(QString::fromUtf8("programBankLabel"));
        programBankLabel->setGeometry(QRect(80, 0, 61, 20));
        programBankLabel->setAlignment(Qt::AlignCenter);
        sourcesParams->addWidget(programPage);
        offPage = new QWidget();
        offPage->setObjectName(QString::fromUtf8("offPage"));
        offPage->setFont(font1);
        label = new QLabel(offPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 136, 20));
        label->setAlignment(Qt::AlignCenter);
        sourcesParams->addWidget(offPage);
        QWidget::setTabOrder(sourceNote, sourcePressure);
        QWidget::setTabOrder(sourcePressure, sourceToggle);
        QWidget::setTabOrder(sourceToggle, sourceXY);
        QWidget::setTabOrder(sourceXY, sourceYInc);
        QWidget::setTabOrder(sourceYInc, sourceProgram);
        QWidget::setTabOrder(sourceProgram, name);
        QWidget::setTabOrder(name, noteNum);
        QWidget::setTabOrder(noteNum, noteVelocity);
        QWidget::setTabOrder(noteVelocity, noteToggle);
        QWidget::setTabOrder(noteToggle, pressureCC);
        QWidget::setTabOrder(pressureCC, pressureSmooth);
        QWidget::setTabOrder(pressureSmooth, toggleCC);
        QWidget::setTabOrder(toggleCC, toggleLo);
        QWidget::setTabOrder(toggleLo, toggleHi);
        QWidget::setTabOrder(toggleHi, xyXCC);
        QWidget::setTabOrder(xyXCC, xyYCC);
        QWidget::setTabOrder(xyYCC, xyLatch);
        QWidget::setTabOrder(xyLatch, yIncCC);
        QWidget::setTabOrder(yIncCC, yIncSpeed);
        QWidget::setTabOrder(yIncSpeed, programNum);
        QWidget::setTabOrder(programNum, programBank);

        retranslateUi(keyForm);

        sourcesParams->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(keyForm);
    } // setupUi

    void retranslateUi(QWidget *keyForm)
    {
        keyForm->setWindowTitle(QCoreApplication::translate("keyForm", "Form", nullptr));
        name->setText(QCoreApplication::translate("keyForm", "KEYS", nullptr));
        sourceNote->setText(QCoreApplication::translate("keyForm", " MIDI Note", nullptr));
        sourcePressure->setText(QCoreApplication::translate("keyForm", " Pressure", nullptr));
        sourceToggle->setText(QCoreApplication::translate("keyForm", " Toggle", nullptr));
        sourceXY->setText(QCoreApplication::translate("keyForm", " X/Y", nullptr));
        sourceYInc->setText(QCoreApplication::translate("keyForm", " Y Inc", nullptr));
        sourceProgram->setText(QCoreApplication::translate("keyForm", " Program", nullptr));
        instanceLabel->setText(QCoreApplication::translate("keyForm", "0", nullptr));
        nameLabel->setText(QCoreApplication::translate("keyForm", "name", nullptr));
        dividerLine->setText(QString());
        noteNumLabel->setText(QCoreApplication::translate("keyForm", "Note #", nullptr));
        noteVelocityLabel->setText(QCoreApplication::translate("keyForm", "Velocity", nullptr));
        noteToggleLabel->setText(QCoreApplication::translate("keyForm", "Toggle", nullptr));
        noteToggle->setText(QString());
        pressureCCLabel->setText(QCoreApplication::translate("keyForm", "CC #", nullptr));
        pressureSmoothLabel->setText(QCoreApplication::translate("keyForm", "Smooth", nullptr));
        toggleCCLabel->setText(QCoreApplication::translate("keyForm", "CC #", nullptr));
        toggleLoLabel->setText(QCoreApplication::translate("keyForm", "Lo", nullptr));
        toggleHiLabel->setText(QCoreApplication::translate("keyForm", "Hi", nullptr));
        xyXCC->setSpecialValueText(QCoreApplication::translate("keyForm", "off", nullptr));
        xyXCCLabel->setText(QCoreApplication::translate("keyForm", "X CC #", nullptr));
        xyYCCLabel->setText(QCoreApplication::translate("keyForm", "Y CC #", nullptr));
        xyYCC->setSpecialValueText(QCoreApplication::translate("keyForm", "off", nullptr));
        xyLatch->setText(QString());
        xyLatchLabel->setText(QCoreApplication::translate("keyForm", "Latch", nullptr));
        yIncCCLabel->setText(QCoreApplication::translate("keyForm", "CC #", nullptr));
        yIncSpeedLabel->setText(QCoreApplication::translate("keyForm", "Inc Speed", nullptr));
        programNumLabel->setText(QCoreApplication::translate("keyForm", "Program #", nullptr));
        programBank->setSpecialValueText(QCoreApplication::translate("keyForm", "off", nullptr));
        programBankLabel->setText(QCoreApplication::translate("keyForm", "Bank #", nullptr));
        label->setText(QCoreApplication::translate("keyForm", "[ No source selected ]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keyForm: public Ui_keyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYFORMWIN_H
