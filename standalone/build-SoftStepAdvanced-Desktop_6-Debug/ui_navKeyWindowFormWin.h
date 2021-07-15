// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'navKeyWindowFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVKEYWINDOWFORMWIN_H
#define UI_NAVKEYWINDOWFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_navKeyWindowForm
{
public:
    QCheckBox *showLEDSettings;
    QLabel *label;
    QLabel *label_3;
    QLabel *outputSettingsBracketLabel;
    QLabel *label_8;
    QLabel *dataModifiersBracketLabel;
    QLabel *initsBracketLabel;
    QLabel *label_4;
    QLabel *dataSourcesBracketLabel;
    QLabel *label_7;
    QLabel *label_2;
    QRadioButton *navpadmode_programchange;
    QRadioButton *navpadmode_modline;
    QPushButton *pushButton;
    QLineEdit *displayprefix;
    QLabel *label_5;
    QLineEdit *keyname;
    QLabel *label_6;
    QComboBox *leddisplaymode;
    QLabel *label_9;
    QToolButton *deletemodline;
    QToolButton *addmodline;
    QSpinBox *counterMax;
    QLabel *label_21;
    QSpinBox *counterMin;
    QCheckBox *counterWrap;
    QLabel *label_20;
    QLabel *counterlabel;
    QLabel *label_22;

    void setupUi(QWidget *navKeyWindowForm)
    {
        if (navKeyWindowForm->objectName().isEmpty())
            navKeyWindowForm->setObjectName(QString::fromUtf8("navKeyWindowForm"));
        navKeyWindowForm->resize(1118, 410);
        navKeyWindowForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgb(60, 60, 60);\n"
"	border: 4px solid rgb(0,174,239);\n"
"}\n"
"\n"
"/* ---------- QLabels ------------*/\n"
"QLabel\n"
"{\n"
"	background:		none;\n"
"	color: 				white;\n"
"	font: 				7pt \"Corbel\";\n"
"	border:				none;\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	border:				none;\n"
"}\n"
"\n"
"/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: (18, 18, 18);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"}\n"
"\n"
"QSpinBox::focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 10pt \"Corbel\";\n"
"	background: none;\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"	border: none;\n"
"}\n"
"\n"
"QCheckBox:focus\n"
"{\n"
"	background: none;\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background: rgb(18, 18, 18);\n"
"	border: 1px solid "
                        "rgb(0,174,239);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background: rgb(18, 18, 18);\n"
"	color: white;\n"
"	padding: 1px 3px 1px 4px;\n"
" }\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 7px \"Tahoma\";\n"
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
"}"
                        "\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	width: 22px;\n"
"}"));
        showLEDSettings = new QCheckBox(navKeyWindowForm);
        showLEDSettings->setObjectName(QString::fromUtf8("showLEDSettings"));
        showLEDSettings->setGeometry(QRect(760, 24, 160, 24));
        showLEDSettings->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"    color: rgba(255,255,255,0);\n"
"    font: 10pt \"Futura\";\n"
"}\n"
"\n"
"QCheckBox::indicator\n"
"{\n"
"    width: 165px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus"
                        "\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/keyWindow_ledSettings_toggle_off.png);\n"
"}\n"
"\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label = new QLabel(navKeyWindowForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 53, 915, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-top: 2px solid white;\n"
"}"));
        label_3 = new QLabel(navKeyWindowForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(49, 64, 31, 11));
        label_3->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_inits_label.png);\n"
"}"));
        outputSettingsBracketLabel = new QLabel(navKeyWindowForm);
        outputSettingsBracketLabel->setObjectName(QString::fromUtf8("outputSettingsBracketLabel"));
        outputSettingsBracketLabel->setGeometry(QRect(614, 82, 304, 11));
        outputSettingsBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_outputSettings_label_bracket.png);\n"
"}"));
        label_8 = new QLabel(navKeyWindowForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(705, 63, 113, 14));
        label_8->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_outputSettings_label.png);\n"
"}"));
        dataModifiersBracketLabel = new QLabel(navKeyWindowForm);
        dataModifiersBracketLabel->setObjectName(QString::fromUtf8("dataModifiersBracketLabel"));
        dataModifiersBracketLabel->setGeometry(QRect(250, 82, 318, 11));
        dataModifiersBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataModifiers_label_bracket.png);\n"
"}"));
        initsBracketLabel = new QLabel(navKeyWindowForm);
        initsBracketLabel->setObjectName(QString::fromUtf8("initsBracketLabel"));
        initsBracketLabel->setGeometry(QRect(39, 82, 53, 11));
        initsBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_inits_label_bracket.png);\n"
"}"));
        label_4 = new QLabel(navKeyWindowForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(106, 64, 95, 11));
        label_4->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataSources_label.png);\n"
"}"));
        dataSourcesBracketLabel = new QLabel(navKeyWindowForm);
        dataSourcesBracketLabel->setObjectName(QString::fromUtf8("dataSourcesBracketLabel"));
        dataSourcesBracketLabel->setGeometry(QRect(106, 82, 95, 11));
        dataSourcesBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataSources_label_bracket.png);\n"
"}"));
        label_7 = new QLabel(navKeyWindowForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(341, 63, 108, 13));
        label_7->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataModifiers_label.png);\n"
"}"));
        label_2 = new QLabel(navKeyWindowForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(11, 10, 16, 38));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	image: url(:/resources/mode_label.png);\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	image: none;\n"
"}"));
        navpadmode_programchange = new QRadioButton(navKeyWindowForm);
        navpadmode_programchange->setObjectName(QString::fromUtf8("navpadmode_programchange"));
        navpadmode_programchange->setGeometry(QRect(31, 29, 111, 18));
        navpadmode_programchange->setStyleSheet(QString::fromUtf8("/*-------QRadioButton-------*/\n"
"\n"
"QRadioButton\n"
"{\n"
"	color: rgba(255,255,255,250);\n"
"	font: 8pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QRadioButton::indicator  {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
" \n"
"QRadioButton::indicator::unchecked  {\n"
"    image: url(:/resources/radiobutton_unchecked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked:hover  {\n"
"    image: url(:/resources/radiobutton_unchecked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked:pressed  {\n"
"    image: url(:/resources/radiobutton_pressed.png);\n"
"}\n"
" \n"
"QRadioButton::indicator::checked  {\n"
"    image: url(:/resources/radiobutton_checked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:checked:hover  {\n"
"    image: url(:/resources/radiobutton_checked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:checked:pressed  {\n"
"    image: url(:/resources/radiobutton_pressed.png);\n"
"}"));
        navpadmode_modline = new QRadioButton(navKeyWindowForm);
        navpadmode_modline->setObjectName(QString::fromUtf8("navpadmode_modline"));
        navpadmode_modline->setGeometry(QRect(31, 9, 102, 18));
        navpadmode_modline->setStyleSheet(QString::fromUtf8("/*-------QRadioButton-------*/\n"
"\n"
"QRadioButton\n"
"{\n"
"	color: rgba(255,255,255,250);\n"
"	font: 8pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QRadioButton::indicator  {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
" \n"
"QRadioButton::indicator::unchecked  {\n"
"    image: url(:/resources/radiobutton_unchecked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked:hover  {\n"
"    image: url(:/resources/radiobutton_unchecked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:unchecked:pressed  {\n"
"    image: url(:/resources/radiobutton_pressed.png);\n"
"}\n"
" \n"
"QRadioButton::indicator::checked  {\n"
"    image: url(:/resources/radiobutton_checked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:checked:hover  {\n"
"    image: url(:/resources/radiobutton_checked.png);\n"
"}\n"
" \n"
"QRadioButton::indicator:checked:pressed  {\n"
"    image: url(:/resources/radiobutton_pressed.png);\n"
"}"));
        pushButton = new QPushButton(navKeyWindowForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 17, 25, 25));
        pushButton->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"image: url(:/resources/openkeywindowNav_inactive.png)"));
        displayprefix = new QLineEdit(navKeyWindowForm);
        displayprefix->setObjectName(QString::fromUtf8("displayprefix"));
        displayprefix->setGeometry(QRect(945, 75, 30, 18));
        displayprefix->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        displayprefix->setMaxLength(2);
        label_5 = new QLabel(navKeyWindowForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(981, 60, 60, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 7pt \"Tahoma\";\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        keyname = new QLineEdit(navKeyWindowForm);
        keyname->setObjectName(QString::fromUtf8("keyname"));
        keyname->setGeometry(QRect(1046, 75, 60, 18));
        keyname->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        keyname->setMaxLength(4);
        label_6 = new QLabel(navKeyWindowForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(945, 60, 30, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 7pt \"Tahoma\";\n"
""));
        label_6->setAlignment(Qt::AlignCenter);
        leddisplaymode = new QComboBox(navKeyWindowForm);
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->setObjectName(QString::fromUtf8("leddisplaymode"));
        leddisplaymode->setGeometry(QRect(981, 75, 60, 18));
        leddisplaymode->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label_9 = new QLabel(navKeyWindowForm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1046, 60, 60, 16));
        label_9->setStyleSheet(QString::fromUtf8("font: 7pt \"Tahoma\";\n"
""));
        label_9->setAlignment(Qt::AlignCenter);
        deletemodline = new QToolButton(navKeyWindowForm);
        deletemodline->setObjectName(QString::fromUtf8("deletemodline"));
        deletemodline->setGeometry(QRect(35, 380, 22, 22));
        deletemodline->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/keyWindow_deleteModline_button_not_clicked.png);\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/keyWindow_deleteModline_button_clicked.png);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        addmodline = new QToolButton(navKeyWindowForm);
        addmodline->setObjectName(QString::fromUtf8("addmodline"));
        addmodline->setGeometry(QRect(9, 380, 22, 22));
        addmodline->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/keyWindow_addModline_button_not_clicked.png);\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/keyWindow_addModline_button_clicked.png);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        counterMax = new QSpinBox(navKeyWindowForm);
        counterMax->setObjectName(QString::fromUtf8("counterMax"));
        counterMax->setGeometry(QRect(685, 25, 30, 18));
        counterMax->setStyleSheet(QString::fromUtf8("/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 8pt \"Futura-Normal\";\n"
"	color: white;\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(20, 20, 20);\n"
"	padding:0, 0, 0, 0;\n"
"}\n"
"\n"
"QSpinBox::focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(20, 20, 20, 75);\n"
"	border-color: rgba(0, 174, 239, 75);\n"
"	font: 8pt \"Futura-Normal\";\n"
"	color: rgba(255, 255, 255, 75)\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        counterMax->setAlignment(Qt::AlignCenter);
        counterMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        counterMax->setMaximum(12);
        label_21 = new QLabel(navKeyWindowForm);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(689, 9, 21, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(7);
        font.setBold(false);
        font.setItalic(false);
        label_21->setFont(font);
        counterMin = new QSpinBox(navKeyWindowForm);
        counterMin->setObjectName(QString::fromUtf8("counterMin"));
        counterMin->setGeometry(QRect(652, 25, 30, 18));
        counterMin->setStyleSheet(QString::fromUtf8("/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 8pt \"Futura-Normal\";\n"
"	color: white;\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(20, 20, 20);\n"
"	padding:0, 0, 0, 0;\n"
"}\n"
"\n"
"QSpinBox::focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(20, 20, 20, 75);\n"
"	border-color: rgba(0, 174, 239, 75);\n"
"	font: 8pt \"Futura-Normal\";\n"
"	color: rgba(255, 255, 255, 75)\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        counterMin->setAlignment(Qt::AlignCenter);
        counterMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        counterMin->setMaximum(12);
        counterWrap = new QCheckBox(navKeyWindowForm);
        counterWrap->setObjectName(QString::fromUtf8("counterWrap"));
        counterWrap->setGeometry(QRect(724, 25, 23, 20));
        counterWrap->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"	padding-top: 1px;\n"
"}\n"
"\n"
"QCheckBox::indicator\n"
"{\n"
"	width: 18px;\n"
"	height: 19px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"	image:url(:/resources/checkbox_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"	image:url(:/resources/checkbox_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"	image:url(:/resources/checkbox_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"	image:url(:/resources/checkbox_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover\n"
"{\n"
"	image:url(:/resources/checkbox_on.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"	image:url(:/resources/checkbox_off.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled\n"
"{\n"
"	image:url(:/resources/checkbox_off_disabled.png)\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled\n"
"{\n"
"	image:url(:/resources/checkbox_off_disabled.png)\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label_20 = new QLabel(navKeyWindowForm);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(657, 9, 21, 16));
        label_20->setFont(font);
        counterlabel = new QLabel(navKeyWindowForm);
        counterlabel->setObjectName(QString::fromUtf8("counterlabel"));
        counterlabel->setGeometry(QRect(632, 10, 16, 39));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Futura")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        counterlabel->setFont(font1);
        counterlabel->setStyleSheet(QString::fromUtf8("/*-------QLabel-------*/\n"
"QLabel\n"
"{\n"
"	font: 12pt \"Futura\";\n"
"	image: url(:/resources/counter_label.png);\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	width: 22px;\n"
"	image: none;\n"
"}"));
        counterlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_22 = new QLabel(navKeyWindowForm);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(723, 9, 31, 16));
        label_22->setFont(font);
        QWidget::setTabOrder(navpadmode_modline, navpadmode_programchange);
        QWidget::setTabOrder(navpadmode_programchange, pushButton);
        QWidget::setTabOrder(pushButton, counterMin);
        QWidget::setTabOrder(counterMin, counterMax);
        QWidget::setTabOrder(counterMax, counterWrap);
        QWidget::setTabOrder(counterWrap, showLEDSettings);
        QWidget::setTabOrder(showLEDSettings, displayprefix);
        QWidget::setTabOrder(displayprefix, leddisplaymode);
        QWidget::setTabOrder(leddisplaymode, keyname);
        QWidget::setTabOrder(keyname, addmodline);
        QWidget::setTabOrder(addmodline, deletemodline);

        retranslateUi(navKeyWindowForm);

        leddisplaymode->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(navKeyWindowForm);
    } // setupUi

    void retranslateUi(QWidget *navKeyWindowForm)
    {
        navKeyWindowForm->setWindowTitle(QCoreApplication::translate("navKeyWindowForm", "Form", nullptr));
#if QT_CONFIG(tooltip)
        showLEDSettings->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Show/Hide the LED and display options for this key.", nullptr));
#endif // QT_CONFIG(tooltip)
        showLEDSettings->setText(QCoreApplication::translate("navKeyWindowForm", "CheckBox", nullptr));
        label->setText(QString());
        label_3->setText(QString());
        outputSettingsBracketLabel->setText(QString());
        label_8->setText(QString());
        dataModifiersBracketLabel->setText(QString());
        initsBracketLabel->setText(QString());
        label_4->setText(QString());
        dataSourcesBracketLabel->setText(QString());
        label_7->setText(QString());
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the Nav Pad mode.<p><b>Modline</b>: Use the Nav Pad with the modlines below like a regular SoftStep key.<p><b>Program Change</b>: For use with the Nav Yx10 & Key\342\200\235 source \342\200\224\302\240this allows the Nav pad to count \"decades\" from 0 to 12. This option will disable the use of modlines on the Nav Pad.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QString());
#if QT_CONFIG(tooltip)
        navpadmode_programchange->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the Nav Pad mode.<p><b>Modline</b>: Use the Nav Pad with the modlines below like a regular SoftStep key.<p><b>Program Change</b>: For use with the Nav Yx10 & Key\342\200\235 source \342\200\224\302\240this allows the Nav pad to count \"decades\" from 0 to 12. This option will disable the use of modlines on the Nav Pad.", nullptr));
#endif // QT_CONFIG(tooltip)
        navpadmode_programchange->setText(QCoreApplication::translate("navKeyWindowForm", " program change", nullptr));
#if QT_CONFIG(tooltip)
        navpadmode_modline->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the Nav Pad mode.<p><b>Modline</b>: Use the Nav Pad with the modlines below like a regular SoftStep key.<p><b>Program Change</b>: For use with the Nav Yx10 & Key\342\200\235 source \342\200\224\302\240this allows the Nav pad to count \"decades\" from 0 to 12. This option will disable the use of modlines on the Nav Pad.", nullptr));
#endif // QT_CONFIG(tooltip)
        navpadmode_modline->setText(QCoreApplication::translate("navKeyWindowForm", " modline", nullptr));
        pushButton->setText(QString());
#if QT_CONFIG(tooltip)
        displayprefix->setToolTip(QCoreApplication::translate("navKeyWindowForm", "One or two characters that can be added before <br>the parameter value on the SoftStep's display.<p><b>Example</b>: A prefix of \"NI\" and a value of 34 coming through the modline would show \"NI34\" on the display.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("navKeyWindowForm", "Display Mode", nullptr));
#if QT_CONFIG(tooltip)
        keyname->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the name for this key.<p>(Four character maximum)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("navKeyWindowForm", "Prefix", nullptr));
        leddisplaymode->setItemText(0, QCoreApplication::translate("navKeyWindowForm", "None", nullptr));
        leddisplaymode->setItemText(1, QCoreApplication::translate("navKeyWindowForm", "Always", nullptr));
        leddisplaymode->setItemText(2, QCoreApplication::translate("navKeyWindowForm", "Once", nullptr));
        leddisplaymode->setItemText(3, QCoreApplication::translate("navKeyWindowForm", "Immed Param", nullptr));

#if QT_CONFIG(tooltip)
        leddisplaymode->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the SoftStep display behavior.<p><b>None</b>: Pressing this key will have no effect on the display.<p><b>Always</b>: Key name will be displayed every time this key is pressed.<p><b>Once</b>: Key name will be displayed once when the key is pressed, then show the prefix + parameter value (Hosted mode only).<p><b>Initial/Return</b>: Prefix + parameter value will be displayed when this key is active, then display the key name when inactive (Hosted mode only).<p><b>Immed Param</b>: (Immediate Parameter) Displays the prefix and parameter value when this key is activated.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("navKeyWindowForm", "Key Name", nullptr));
#if QT_CONFIG(tooltip)
        deletemodline->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Delete the bottom modline (minimum of 2)", nullptr));
#endif // QT_CONFIG(tooltip)
        deletemodline->setText(QString());
#if QT_CONFIG(tooltip)
        addmodline->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Add a modline (maximum of 6)", nullptr));
#endif // QT_CONFIG(tooltip)
        addmodline->setText(QString());
#if QT_CONFIG(tooltip)
        counterMax->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the maximum value for the key counter.<br>No values above this number will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_21->setText(QCoreApplication::translate("navKeyWindowForm", "Max", nullptr));
#if QT_CONFIG(tooltip)
        counterMin->setToolTip(QCoreApplication::translate("navKeyWindowForm", "Sets the minimum value for the key counter.<br>No values below this number will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        counterWrap->setToolTip(QCoreApplication::translate("navKeyWindowForm", "When checked, the key counter<br> will loop back to the minimum <br>value once the maximum <br>value is exceeded (and vice versa).<p>When unchecked, the counter will stop <br>once the minimum or maximum <br>values are reached.", nullptr));
#endif // QT_CONFIG(tooltip)
        counterWrap->setText(QString());
        label_20->setText(QCoreApplication::translate("navKeyWindowForm", "Min", nullptr));
#if QT_CONFIG(tooltip)
        counterlabel->setToolTip(QCoreApplication::translate("navKeyWindowForm", "<b>Key Counter:</b><p>Increments between the specified<br> min and max values.<p><b>(Hosted mode only)</b>", nullptr));
#endif // QT_CONFIG(tooltip)
        counterlabel->setText(QCoreApplication::translate("navKeyWindowForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Futura'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("navKeyWindowForm", "Wrap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class navKeyWindowForm: public Ui_navKeyWindowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVKEYWINDOWFORMWIN_H
