// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'modlineFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODLINEFORMWIN_H
#define UI_MODLINEFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modlineForm
{
public:
    QLabel *instanceLabel;
    QCheckBox *enable;
    QComboBox *initmode;
    QSpinBox *initvalue;
    QSpinBox *raw;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *gain;
    QSpinBox *offset;
    QLabel *label_3;
    QSpinBox *result;
    QComboBox *table;
    QSpinBox *min;
    QSpinBox *max;
    QSpinBox *slew;
    QSpinBox *outputvalue;
    QComboBox *destination;
    QComboBox *source;
    QComboBox *ledgreen;
    QComboBox *ledred;
    QStackedWidget *deviceViews;
    QWidget *noneDeviceView;
    QWidget *noteSetDeviceView;
    QSpinBox *notenumber;
    QSpinBox *notevelocity;
    QSpinBox *notechannel;
    QComboBox *notedevice;
    QWidget *noteLiveDeviceView;
    QComboBox *notelivedevice;
    QSpinBox *notelivevelocity;
    QSpinBox *notelivechannel;
    QSpinBox *notelivenumber;
    QWidget *controlDeviceView;
    QSpinBox *cc;
    QSpinBox *controlchannel;
    QComboBox *controldevice;
    QWidget *bankDeviceView;
    QComboBox *bankdevice;
    QSpinBox *bankmsb;
    QSpinBox *bankchannel;
    QWidget *programDeviceView;
    QComboBox *programdevice;
    QSpinBox *programchannel;
    QWidget *bendDeviceView;
    QSpinBox *bendchannel;
    QComboBox *benddevice;
    QWidget *mmcDeviceView;
    QComboBox *mmcdevice;
    QSpinBox *mmcdeviceid;
    QComboBox *mmcfunction;
    QWidget *oscDeviceView;
    QLineEdit *oscroute;
    QWidget *aftertouchDeviceView;
    QComboBox *aftertouchdevice;
    QSpinBox *aftertouchchannel;
    QWidget *polyDeviceView;
    QSpinBox *polynote;
    QSpinBox *polychannel;
    QComboBox *polydevice;
    QStackedWidget *deviceViewLabels;
    QWidget *noneDeviceLabel;
    QWidget *noteSetDeviceLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *noteLiveDeviceLabel;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *controlDeviceLabel;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *bankDeviceLabel;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QWidget *programDeviceLabel;
    QLabel *label_20;
    QLabel *label_22;
    QWidget *bendDeviceLabel;
    QLabel *label_23;
    QLabel *label_25;
    QWidget *mmcDeviceLabel;
    QLabel *label_9;
    QLabel *label_24;
    QLabel *label_26;
    QWidget *oscDeviceLabel;
    QLabel *label_21;
    QWidget *aftertouchDeviceLabel;
    QLabel *label_28;
    QLabel *label_30;
    QWidget *polyDeviceLabel;
    QLabel *label_29;
    QLabel *label_31;
    QLabel *label_32;
    QSpinBox *delay;
    QLabel *label_13;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_4;
    QRadioButton *modlinedisplayenable;
    QLabel *label_48;
    QLabel *hide_border_bleed;

    void setupUi(QWidget *modlineForm)
    {
        if (modlineForm->objectName().isEmpty())
            modlineForm->setObjectName(QString::fromUtf8("modlineForm"));
        modlineForm->resize(1132, 42);
        modlineForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgb(80, 80, 80);	\n"
"}\n"
"\n"
"/* ------- QStackedWidget ---------*/\n"
"QStackedWidget\n"
"{\n"
"	background: none;\n"
"	border-left: 2px solid rgb(0,174,239);\n"
"	border-right: 2px solid rgb(0,174,239);\n"
"}\n"
"\n"
"/* ---------- QLabels ------------*/\n"
"QLabel\n"
"{\n"
"	background:		none;\n"
"	color: 				white;\n"
"	font: 				7pt \"Tahoma\";\n"
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
"	font: 7pt \"Tahoma\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(18, 18, 18);\n"
"	color: white;\n"
"	padding: 1px 1px 1px 0px;\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"QDoubleSpinBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(18, 18, 18);\n"
"	color: white;\n"
"	padding: 1px 1px 1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::focus\n"
"{\n"
"	bord"
                        "er: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background: rgb(18, 18, 18);\n"
"	border: 1px solid rgb(0,174,239);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background: rgb(0,174,239);\n"
"	border: 1px solid white;\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background: none;\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"	border: none;\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QCheckBox:focus\n"
"{\n"
"	background: none;\n"
"}\n"
"\n"
"/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background: rgb(18, 18, 18);\n"
"	color: white;\n"
"	padding: 1px 3px 1px 4px;"
                        "\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	paddi"
                        "ng-right: 10px;\n"
"}\n"
"\n"
"/*-------QRadioButton-------*/\n"
"QRadioButton\n"
"{\n"
"	background: none;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked\n"
"{\n"
"	image: url(:/resources/modline_display_enable_off.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed\n"
"{\n"
"	image: url(:/resources/modline_display_enable_on.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"	image: url(:/resources/modline_display_enable_on.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed\n"
"{\n"
"	image: url(:/resources/modline_display_enable_off.png);\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"}"));
        instanceLabel = new QLabel(modlineForm);
        instanceLabel->setObjectName(QString::fromUtf8("instanceLabel"));
        instanceLabel->setGeometry(QRect(8, 43, 18, 18));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura")});
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        instanceLabel->setFont(font);
        instanceLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: 				white;\n"
"	font: 				8pt \"Futura\";\n"
"	border:				none;\n"
"}"));
        instanceLabel->setAlignment(Qt::AlignCenter);
        instanceLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        enable = new QCheckBox(modlineForm);
        enable->setObjectName(QString::fromUtf8("enable"));
        enable->setGeometry(QRect(2, 17, 20, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Futura")});
        font1.setPointSize(10);
        enable->setFont(font1);
        enable->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"    color: rgba(255,255,255,0);\n"
"    font: 10pt \"Futura\";\n"
"}\n"
"\n"
"QCheckBox::indicator\n"
"{\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/modline_enable1_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/modline_enable1_toggle_off.png);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        enable->setTristate(false);
        initmode = new QComboBox(modlineForm);
        initmode->addItem(QString());
        initmode->addItem(QString());
        initmode->addItem(QString());
        initmode->setObjectName(QString::fromUtf8("initmode"));
        initmode->setGeometry(QRect(25, 19, 39, 18));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tahoma")});
        font2.setPointSize(7);
        font2.setBold(false);
        font2.setItalic(false);
        initmode->setFont(font2);
        initmode->setFocusPolicy(Qt::StrongFocus);
        initmode->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
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
""
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
"QComboBox:disabled\n"
"{\n"
"	background-color: rgba(20, 20, 20, 75);\n"
"	border-color: rgba(0, 174, 239, 75);\n"
"	color: rgba(255, 255, 255, 75);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        initmode->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        initmode->setFrame(true);
        initvalue = new QSpinBox(modlineForm);
        initvalue->setObjectName(QString::fromUtf8("initvalue"));
        initvalue->setGeometry(QRect(66, 19, 22, 18));
        initvalue->setFont(font2);
        initvalue->setFocusPolicy(Qt::StrongFocus);
        initvalue->setStyleSheet(QString::fromUtf8("/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	color: white;\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(20, 20, 20);\n"
"	padding:0, 1, 0, 0;\n"
"	font: 7pt \"Tahoma\";\n"
"}\n"
"\n"
"QSpinBox::focus\n"
"{\n"
"	border: 1px solid rgb(255,255,255);\n"
"	outline: none;\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(20, 20, 20, 75);\n"
"	border-color: rgba(0, 174, 239, 75);\n"
"	font: 8pt \"Futura\";\n"
"	color: rgba(255, 255, 255, 75);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        initvalue->setFrame(true);
        initvalue->setAlignment(Qt::AlignCenter);
        initvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        initvalue->setMaximum(127);
        raw = new QSpinBox(modlineForm);
        raw->setObjectName(QString::fromUtf8("raw"));
        raw->setGeometry(QRect(201, 19, 27, 18));
        raw->setFont(font2);
        raw->setFocusPolicy(Qt::NoFocus);
        raw->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	border: 1px solid rgba(236, 0, 140, 255);\n"
"	color: rgba(255, 255, 255, 255);\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(18, 18, 18, 255);\n"
"	border-color: rgba(236, 0, 140, 90);\n"
"	font: 10pt \"Futura\";\n"
"	color: rgba(255, 255, 255, 90);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        raw->setFrame(true);
        raw->setAlignment(Qt::AlignCenter);
        raw->setReadOnly(true);
        raw->setButtonSymbols(QAbstractSpinBox::NoButtons);
        raw->setMaximum(127);
        label = new QLabel(modlineForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(233, 19, 8, 18));
        label->setFont(font2);
        label_2 = new QLabel(modlineForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(275, 19, 8, 18));
        label_2->setFont(font2);
        gain = new QDoubleSpinBox(modlineForm);
        gain->setObjectName(QString::fromUtf8("gain"));
        gain->setGeometry(QRect(243, 19, 29, 18));
        gain->setFont(font2);
        gain->setFocusPolicy(Qt::StrongFocus);
        gain->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        gain->setAlignment(Qt::AlignCenter);
        gain->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gain->setMinimum(-127.000000000000000);
        gain->setMaximum(127.000000000000000);
        offset = new QSpinBox(modlineForm);
        offset->setObjectName(QString::fromUtf8("offset"));
        offset->setGeometry(QRect(285, 19, 28, 18));
        offset->setFont(font2);
        offset->setFocusPolicy(Qt::StrongFocus);
        offset->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        offset->setAlignment(Qt::AlignCenter);
        offset->setButtonSymbols(QAbstractSpinBox::NoButtons);
        offset->setMinimum(-999);
        offset->setMaximum(999);
        label_3 = new QLabel(modlineForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(317, 19, 8, 18));
        label_3->setFont(font2);
        result = new QSpinBox(modlineForm);
        result->setObjectName(QString::fromUtf8("result"));
        result->setEnabled(true);
        result->setGeometry(QRect(327, 19, 28, 18));
        result->setFont(font2);
        result->setFocusPolicy(Qt::NoFocus);
        result->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	border: 1px solid rgba(236, 0, 140, 255);\n"
"	color: rgba(255, 255, 255, 255);\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(18, 18, 18, 255);\n"
"	border-color: rgba(236, 0, 140, 90);\n"
"	font: 10pt \"Futura\";\n"
"	color: rgba(255, 255, 255, 90);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        result->setFrame(true);
        result->setAlignment(Qt::AlignCenter);
        result->setReadOnly(true);
        result->setButtonSymbols(QAbstractSpinBox::NoButtons);
        result->setMaximum(127);
        table = new QComboBox(modlineForm);
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(365, 19, 60, 18));
        table->setFont(font2);
        table->setFocusPolicy(Qt::StrongFocus);
        table->setStyleSheet(QString::fromUtf8("QComboBox\n"
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
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 55px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        min = new QSpinBox(modlineForm);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(430, 19, 30, 18));
        min->setFont(font2);
        min->setFocusPolicy(Qt::StrongFocus);
        min->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        min->setFrame(true);
        min->setAlignment(Qt::AlignCenter);
        min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        min->setMaximum(127);
        max = new QSpinBox(modlineForm);
        max->setObjectName(QString::fromUtf8("max"));
        max->setGeometry(QRect(462, 19, 30, 18));
        max->setFont(font2);
        max->setFocusPolicy(Qt::StrongFocus);
        max->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        max->setFrame(true);
        max->setAlignment(Qt::AlignCenter);
        max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        max->setMaximum(127);
        slew = new QSpinBox(modlineForm);
        slew->setObjectName(QString::fromUtf8("slew"));
        slew->setGeometry(QRect(494, 19, 30, 18));
        slew->setFont(font2);
        slew->setFocusPolicy(Qt::StrongFocus);
        slew->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        slew->setFrame(true);
        slew->setAlignment(Qt::AlignCenter);
        slew->setButtonSymbols(QAbstractSpinBox::NoButtons);
        slew->setMaximum(5000);
        outputvalue = new QSpinBox(modlineForm);
        outputvalue->setObjectName(QString::fromUtf8("outputvalue"));
        outputvalue->setGeometry(QRect(569, 19, 27, 18));
        outputvalue->setFont(font2);
        outputvalue->setFocusPolicy(Qt::NoFocus);
        outputvalue->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	border: 1px solid rgba(236, 0, 140, 255);\n"
"	color: rgba(255, 255, 255, 255);\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid rgb(255,255,255);\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(18, 18, 18, 255);\n"
"	border-color: rgba(236, 0, 140, 90);\n"
"	font: 10pt \"Futura\";\n"
"	color: rgba(255, 255, 255, 90);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        outputvalue->setFrame(true);
        outputvalue->setAlignment(Qt::AlignCenter);
        outputvalue->setReadOnly(true);
        outputvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        outputvalue->setMaximum(127);
        destination = new QComboBox(modlineForm);
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->addItem(QString());
        destination->setObjectName(QString::fromUtf8("destination"));
        destination->setGeometry(QRect(608, 19, 77, 18));
        destination->setFont(font2);
        destination->setFocusPolicy(Qt::StrongFocus);
        destination->setContextMenuPolicy(Qt::DefaultContextMenu);
        destination->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        source = new QComboBox(modlineForm);
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->addItem(QString());
        source->setObjectName(QString::fromUtf8("source"));
        source->setGeometry(QRect(97, 19, 97, 18));
        source->setFont(font2);
        source->setMouseTracking(false);
        source->setFocusPolicy(Qt::StrongFocus);
        source->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        ledgreen = new QComboBox(modlineForm);
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->addItem(QString());
        ledgreen->setObjectName(QString::fromUtf8("ledgreen"));
        ledgreen->setGeometry(QRect(942, 19, 80, 18));
        ledgreen->setFont(font2);
        ledgreen->setFocusPolicy(Qt::StrongFocus);
        ledgreen->setContextMenuPolicy(Qt::DefaultContextMenu);
        ledgreen->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        ledred = new QComboBox(modlineForm);
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->addItem(QString());
        ledred->setObjectName(QString::fromUtf8("ledred"));
        ledred->setGeometry(QRect(1026, 19, 80, 18));
        ledred->setFont(font2);
        ledred->setFocusPolicy(Qt::StrongFocus);
        ledred->setContextMenuPolicy(Qt::DefaultContextMenu);
        ledred->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	min-width: 67px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        deviceViews = new QStackedWidget(modlineForm);
        deviceViews->setObjectName(QString::fromUtf8("deviceViews"));
        deviceViews->setGeometry(QRect(686, 19, 244, 18));
        deviceViews->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background: rgba(0, 0, 0, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	background: rgba(0, 0, 0, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(18, 18, 18);\n"
"	color: white;\n"
"	padding: 1px 1px 1px 3px;\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"QDoubleSpinBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: rgb(18, 18, 18);\n"
"	color: white;\n"
"	padding: 1px 1px 1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox:focus\n"
"{\n"
"	border: 1px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background: rgb(18, 18, 18);\n"
"	border: 1px solid rgba(0,174,239,255);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
""
                        "}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 1px solid white;\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 7pt \"Tahoma\";\n"
"	background:rgba(0,174,239,0);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"	border: none;\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QCheckBox:focus\n"
"{\n"
"	background:rgba(0,174,239,0);\n"
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
"	padding-right: 7px;\n"
" }\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 7px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstr"
                        "actItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        noneDeviceView = new QWidget();
        noneDeviceView->setObjectName(QString::fromUtf8("noneDeviceView"));
        deviceViews->addWidget(noneDeviceView);
        noteSetDeviceView = new QWidget();
        noteSetDeviceView->setObjectName(QString::fromUtf8("noteSetDeviceView"));
        noteSetDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        notenumber = new QSpinBox(noteSetDeviceView);
        notenumber->setObjectName(QString::fromUtf8("notenumber"));
        notenumber->setGeometry(QRect(5, 0, 30, 18));
        notenumber->setFont(font2);
        notenumber->setFocusPolicy(Qt::StrongFocus);
        notenumber->setStyleSheet(QString::fromUtf8(""));
        notenumber->setFrame(true);
        notenumber->setAlignment(Qt::AlignCenter);
        notenumber->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notenumber->setMaximum(127);
        notevelocity = new QSpinBox(noteSetDeviceView);
        notevelocity->setObjectName(QString::fromUtf8("notevelocity"));
        notevelocity->setGeometry(QRect(37, 0, 30, 18));
        notevelocity->setFont(font2);
        notevelocity->setFocusPolicy(Qt::StrongFocus);
        notevelocity->setStyleSheet(QString::fromUtf8(""));
        notevelocity->setFrame(true);
        notevelocity->setAlignment(Qt::AlignCenter);
        notevelocity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notevelocity->setMaximum(127);
        notechannel = new QSpinBox(noteSetDeviceView);
        notechannel->setObjectName(QString::fromUtf8("notechannel"));
        notechannel->setGeometry(QRect(69, 0, 30, 18));
        notechannel->setFont(font2);
        notechannel->setFocusPolicy(Qt::StrongFocus);
        notechannel->setStyleSheet(QString::fromUtf8(""));
        notechannel->setFrame(true);
        notechannel->setAlignment(Qt::AlignCenter);
        notechannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notechannel->setMaximum(16);
        notedevice = new QComboBox(noteSetDeviceView);
        notedevice->addItem(QString());
        notedevice->addItem(QString());
        notedevice->setObjectName(QString::fromUtf8("notedevice"));
        notedevice->setGeometry(QRect(104, 0, 116, 18));
        notedevice->setFont(font2);
        notedevice->setFocusPolicy(Qt::StrongFocus);
        notedevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        notedevice->setStyleSheet(QString::fromUtf8(""));
        notedevice->setMaxVisibleItems(16);
        notedevice->setMinimumContentsLength(100);
        notedevice->setIconSize(QSize(8, 8));
        deviceViews->addWidget(noteSetDeviceView);
        noteLiveDeviceView = new QWidget();
        noteLiveDeviceView->setObjectName(QString::fromUtf8("noteLiveDeviceView"));
        noteLiveDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        notelivedevice = new QComboBox(noteLiveDeviceView);
        notelivedevice->addItem(QString());
        notelivedevice->addItem(QString());
        notelivedevice->setObjectName(QString::fromUtf8("notelivedevice"));
        notelivedevice->setGeometry(QRect(104, 0, 116, 18));
        notelivedevice->setFont(font2);
        notelivedevice->setFocusPolicy(Qt::StrongFocus);
        notelivedevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        notelivedevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 7px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        notelivedevice->setMaxVisibleItems(16);
        notelivedevice->setMinimumContentsLength(100);
        notelivedevice->setIconSize(QSize(8, 8));
        notelivevelocity = new QSpinBox(noteLiveDeviceView);
        notelivevelocity->setObjectName(QString::fromUtf8("notelivevelocity"));
        notelivevelocity->setGeometry(QRect(37, 0, 30, 18));
        notelivevelocity->setFont(font2);
        notelivevelocity->setFocusPolicy(Qt::StrongFocus);
        notelivevelocity->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        notelivevelocity->setFrame(true);
        notelivevelocity->setAlignment(Qt::AlignCenter);
        notelivevelocity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notelivevelocity->setMaximum(127);
        notelivechannel = new QSpinBox(noteLiveDeviceView);
        notelivechannel->setObjectName(QString::fromUtf8("notelivechannel"));
        notelivechannel->setGeometry(QRect(69, 0, 30, 18));
        notelivechannel->setFont(font2);
        notelivechannel->setFocusPolicy(Qt::StrongFocus);
        notelivechannel->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        notelivechannel->setFrame(true);
        notelivechannel->setAlignment(Qt::AlignCenter);
        notelivechannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notelivechannel->setMaximum(16);
        notelivenumber = new QSpinBox(noteLiveDeviceView);
        notelivenumber->setObjectName(QString::fromUtf8("notelivenumber"));
        notelivenumber->setEnabled(false);
        notelivenumber->setGeometry(QRect(5, 0, 30, 18));
        notelivenumber->setFont(font2);
        notelivenumber->setFocusPolicy(Qt::NoFocus);
        notelivenumber->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	border: transparent;\n"
"	background: transparent;\n"
"	color: transparent;\n"
"}"));
        notelivenumber->setFrame(true);
        notelivenumber->setAlignment(Qt::AlignCenter);
        notelivenumber->setReadOnly(true);
        notelivenumber->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notelivenumber->setMaximum(127);
        deviceViews->addWidget(noteLiveDeviceView);
        controlDeviceView = new QWidget();
        controlDeviceView->setObjectName(QString::fromUtf8("controlDeviceView"));
        controlDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        cc = new QSpinBox(controlDeviceView);
        cc->setObjectName(QString::fromUtf8("cc"));
        cc->setGeometry(QRect(37, 0, 30, 18));
        cc->setFont(font2);
        cc->setFocusPolicy(Qt::StrongFocus);
        cc->setFrame(true);
        cc->setAlignment(Qt::AlignCenter);
        cc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cc->setMaximum(127);
        controlchannel = new QSpinBox(controlDeviceView);
        controlchannel->setObjectName(QString::fromUtf8("controlchannel"));
        controlchannel->setGeometry(QRect(69, 0, 30, 18));
        controlchannel->setFont(font2);
        controlchannel->setFocusPolicy(Qt::StrongFocus);
        controlchannel->setFrame(true);
        controlchannel->setAlignment(Qt::AlignCenter);
        controlchannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        controlchannel->setMaximum(16);
        controldevice = new QComboBox(controlDeviceView);
        controldevice->addItem(QString());
        controldevice->addItem(QString());
        controldevice->setObjectName(QString::fromUtf8("controldevice"));
        controldevice->setGeometry(QRect(104, 0, 116, 18));
        controldevice->setFont(font2);
        controldevice->setFocusPolicy(Qt::StrongFocus);
        controldevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        controldevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        controldevice->setMaxVisibleItems(16);
        controldevice->setMinimumContentsLength(100);
        controldevice->setIconSize(QSize(8, 8));
        deviceViews->addWidget(controlDeviceView);
        bankDeviceView = new QWidget();
        bankDeviceView->setObjectName(QString::fromUtf8("bankDeviceView"));
        bankDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        bankdevice = new QComboBox(bankDeviceView);
        bankdevice->addItem(QString());
        bankdevice->addItem(QString());
        bankdevice->setObjectName(QString::fromUtf8("bankdevice"));
        bankdevice->setGeometry(QRect(104, 0, 116, 18));
        bankdevice->setFont(font2);
        bankdevice->setFocusPolicy(Qt::StrongFocus);
        bankdevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        bankdevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        bankdevice->setMaxVisibleItems(16);
        bankdevice->setMinimumContentsLength(100);
        bankdevice->setIconSize(QSize(8, 8));
        bankmsb = new QSpinBox(bankDeviceView);
        bankmsb->setObjectName(QString::fromUtf8("bankmsb"));
        bankmsb->setGeometry(QRect(37, 0, 30, 18));
        bankmsb->setFont(font2);
        bankmsb->setFocusPolicy(Qt::StrongFocus);
        bankmsb->setFrame(true);
        bankmsb->setAlignment(Qt::AlignCenter);
        bankmsb->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bankmsb->setMaximum(127);
        bankchannel = new QSpinBox(bankDeviceView);
        bankchannel->setObjectName(QString::fromUtf8("bankchannel"));
        bankchannel->setGeometry(QRect(69, 0, 30, 18));
        bankchannel->setFont(font2);
        bankchannel->setFocusPolicy(Qt::StrongFocus);
        bankchannel->setFrame(true);
        bankchannel->setAlignment(Qt::AlignCenter);
        bankchannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bankchannel->setMaximum(16);
        deviceViews->addWidget(bankDeviceView);
        programDeviceView = new QWidget();
        programDeviceView->setObjectName(QString::fromUtf8("programDeviceView"));
        programDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        programdevice = new QComboBox(programDeviceView);
        programdevice->addItem(QString());
        programdevice->addItem(QString());
        programdevice->setObjectName(QString::fromUtf8("programdevice"));
        programdevice->setGeometry(QRect(104, 0, 116, 18));
        programdevice->setFont(font2);
        programdevice->setFocusPolicy(Qt::StrongFocus);
        programdevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        programdevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        programdevice->setMaxVisibleItems(16);
        programdevice->setMinimumContentsLength(100);
        programdevice->setIconSize(QSize(8, 8));
        programchannel = new QSpinBox(programDeviceView);
        programchannel->setObjectName(QString::fromUtf8("programchannel"));
        programchannel->setGeometry(QRect(69, 0, 30, 18));
        programchannel->setFont(font2);
        programchannel->setFocusPolicy(Qt::StrongFocus);
        programchannel->setFrame(true);
        programchannel->setAlignment(Qt::AlignCenter);
        programchannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        programchannel->setMaximum(16);
        deviceViews->addWidget(programDeviceView);
        bendDeviceView = new QWidget();
        bendDeviceView->setObjectName(QString::fromUtf8("bendDeviceView"));
        bendDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        bendchannel = new QSpinBox(bendDeviceView);
        bendchannel->setObjectName(QString::fromUtf8("bendchannel"));
        bendchannel->setGeometry(QRect(69, 0, 30, 18));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Tahoma")});
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        bendchannel->setFont(font3);
        bendchannel->setFocusPolicy(Qt::StrongFocus);
        bendchannel->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	font: 9pt \"Tahoma\";\n"
"}"));
        bendchannel->setFrame(true);
        bendchannel->setAlignment(Qt::AlignCenter);
        bendchannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bendchannel->setMaximum(16);
        benddevice = new QComboBox(bendDeviceView);
        benddevice->addItem(QString());
        benddevice->addItem(QString());
        benddevice->setObjectName(QString::fromUtf8("benddevice"));
        benddevice->setGeometry(QRect(104, 0, 116, 18));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Tahoma")});
        font4.setBold(false);
        font4.setItalic(false);
        benddevice->setFont(font4);
        benddevice->setFocusPolicy(Qt::StrongFocus);
        benddevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        benddevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"	font: 9px \"Tahoma\";\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QCombo"
                        "Box::down-arrow\n"
"{\n"
"	border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        benddevice->setMaxVisibleItems(16);
        benddevice->setMinimumContentsLength(100);
        benddevice->setIconSize(QSize(8, 8));
        deviceViews->addWidget(bendDeviceView);
        mmcDeviceView = new QWidget();
        mmcDeviceView->setObjectName(QString::fromUtf8("mmcDeviceView"));
        mmcDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        mmcdevice = new QComboBox(mmcDeviceView);
        mmcdevice->addItem(QString());
        mmcdevice->addItem(QString());
        mmcdevice->setObjectName(QString::fromUtf8("mmcdevice"));
        mmcdevice->setGeometry(QRect(104, 0, 116, 18));
        mmcdevice->setFont(font2);
        mmcdevice->setFocusPolicy(Qt::StrongFocus);
        mmcdevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        mmcdevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        mmcdevice->setMaxVisibleItems(16);
        mmcdevice->setMinimumContentsLength(100);
        mmcdevice->setIconSize(QSize(8, 8));
        mmcdeviceid = new QSpinBox(mmcDeviceView);
        mmcdeviceid->setObjectName(QString::fromUtf8("mmcdeviceid"));
        mmcdeviceid->setGeometry(QRect(5, 0, 30, 18));
        mmcdeviceid->setFont(font2);
        mmcdeviceid->setFocusPolicy(Qt::StrongFocus);
        mmcdeviceid->setFrame(true);
        mmcdeviceid->setAlignment(Qt::AlignCenter);
        mmcdeviceid->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mmcdeviceid->setMaximum(127);
        mmcfunction = new QComboBox(mmcDeviceView);
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->addItem(QString());
        mmcfunction->setObjectName(QString::fromUtf8("mmcfunction"));
        mmcfunction->setGeometry(QRect(37, 0, 64, 18));
        mmcfunction->setFont(font2);
        mmcfunction->setFocusPolicy(Qt::StrongFocus);
        mmcfunction->setContextMenuPolicy(Qt::DefaultContextMenu);
        deviceViews->addWidget(mmcDeviceView);
        mmcdeviceid->raise();
        mmcfunction->raise();
        mmcdevice->raise();
        oscDeviceView = new QWidget();
        oscDeviceView->setObjectName(QString::fromUtf8("oscDeviceView"));
        oscroute = new QLineEdit(oscDeviceView);
        oscroute->setObjectName(QString::fromUtf8("oscroute"));
        oscroute->setGeometry(QRect(104, 0, 116, 18));
        deviceViews->addWidget(oscDeviceView);
        aftertouchDeviceView = new QWidget();
        aftertouchDeviceView->setObjectName(QString::fromUtf8("aftertouchDeviceView"));
        aftertouchDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        aftertouchdevice = new QComboBox(aftertouchDeviceView);
        aftertouchdevice->addItem(QString());
        aftertouchdevice->addItem(QString());
        aftertouchdevice->setObjectName(QString::fromUtf8("aftertouchdevice"));
        aftertouchdevice->setGeometry(QRect(104, 0, 116, 18));
        aftertouchdevice->setFont(font2);
        aftertouchdevice->setFocusPolicy(Qt::StrongFocus);
        aftertouchdevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        aftertouchdevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        aftertouchdevice->setMaxVisibleItems(16);
        aftertouchdevice->setMinimumContentsLength(100);
        aftertouchdevice->setIconSize(QSize(8, 8));
        aftertouchchannel = new QSpinBox(aftertouchDeviceView);
        aftertouchchannel->setObjectName(QString::fromUtf8("aftertouchchannel"));
        aftertouchchannel->setGeometry(QRect(69, 0, 30, 18));
        aftertouchchannel->setFont(font2);
        aftertouchchannel->setFocusPolicy(Qt::StrongFocus);
        aftertouchchannel->setFrame(true);
        aftertouchchannel->setAlignment(Qt::AlignCenter);
        aftertouchchannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        aftertouchchannel->setMaximum(16);
        deviceViews->addWidget(aftertouchDeviceView);
        polyDeviceView = new QWidget();
        polyDeviceView->setObjectName(QString::fromUtf8("polyDeviceView"));
        polyDeviceView->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}\n"
""));
        polynote = new QSpinBox(polyDeviceView);
        polynote->setObjectName(QString::fromUtf8("polynote"));
        polynote->setGeometry(QRect(37, 0, 30, 18));
        polynote->setFont(font2);
        polynote->setFocusPolicy(Qt::StrongFocus);
        polynote->setFrame(true);
        polynote->setAlignment(Qt::AlignCenter);
        polynote->setButtonSymbols(QAbstractSpinBox::NoButtons);
        polynote->setMaximum(127);
        polychannel = new QSpinBox(polyDeviceView);
        polychannel->setObjectName(QString::fromUtf8("polychannel"));
        polychannel->setGeometry(QRect(69, 0, 30, 18));
        polychannel->setFont(font2);
        polychannel->setFocusPolicy(Qt::StrongFocus);
        polychannel->setFrame(true);
        polychannel->setAlignment(Qt::AlignCenter);
        polychannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        polychannel->setMaximum(16);
        polydevice = new QComboBox(polyDeviceView);
        polydevice->addItem(QString());
        polydevice->addItem(QString());
        polydevice->setObjectName(QString::fromUtf8("polydevice"));
        polydevice->setGeometry(QRect(104, 0, 116, 18));
        polydevice->setFont(font2);
        polydevice->setFocusPolicy(Qt::StrongFocus);
        polydevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        polydevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
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
"	border-bottom-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	"
                        "border: none;\n"
"	background: none;\n"
"	image: url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
"}"));
        polydevice->setMaxVisibleItems(16);
        polydevice->setMinimumContentsLength(100);
        polydevice->setIconSize(QSize(8, 8));
        deviceViews->addWidget(polyDeviceView);
        deviceViewLabels = new QStackedWidget(modlineForm);
        deviceViewLabels->setObjectName(QString::fromUtf8("deviceViewLabels"));
        deviceViewLabels->setGeometry(QRect(695, 2, 198, 18));
        deviceViewLabels->setStyleSheet(QString::fromUtf8("/* ------- QStackedWidget ---------*/\n"
"QStackedWidget\n"
"{\n"
"	border: none;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"	background: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	background: rgba(0, 0, 0, 0);\n"
"}"));
        noneDeviceLabel = new QWidget();
        noneDeviceLabel->setObjectName(QString::fromUtf8("noneDeviceLabel"));
        deviceViewLabels->addWidget(noneDeviceLabel);
        noteSetDeviceLabel = new QWidget();
        noteSetDeviceLabel->setObjectName(QString::fromUtf8("noteSetDeviceLabel"));
        noteSetDeviceLabel->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(noteSetDeviceLabel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(3, 0, 31, 16));
        label_6 = new QLabel(noteSetDeviceLabel);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(36, 0, 21, 16));
        label_7 = new QLabel(noteSetDeviceLabel);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 0, 21, 16));
        label_8 = new QLabel(noteSetDeviceLabel);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(113, 0, 72, 16));
        label_8->setAlignment(Qt::AlignCenter);
        deviceViewLabels->addWidget(noteSetDeviceLabel);
        noteLiveDeviceLabel = new QWidget();
        noteLiveDeviceLabel->setObjectName(QString::fromUtf8("noteLiveDeviceLabel"));
        noteLiveDeviceLabel->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
"QComboBox\n"
"{\n"
"	padding-right: 7px;\n"
"}\n"
"\n"
"QComboBox QListView\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 9px \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 65px;\n"
"	min-height: 25px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	min-height: 65px;\n"
"	min-width: 65px;\n"
"\n"
"}\n"
""));
        label_10 = new QLabel(noteLiveDeviceLabel);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(113, 0, 72, 16));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(noteLiveDeviceLabel);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(36, 0, 21, 16));
        label_12 = new QLabel(noteLiveDeviceLabel);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(noteLiveDeviceLabel);
        controlDeviceLabel = new QWidget();
        controlDeviceLabel->setObjectName(QString::fromUtf8("controlDeviceLabel"));
        label_14 = new QLabel(controlDeviceLabel);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(113, 0, 72, 16));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(controlDeviceLabel);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(36, 0, 21, 16));
        label_16 = new QLabel(controlDeviceLabel);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(controlDeviceLabel);
        bankDeviceLabel = new QWidget();
        bankDeviceLabel->setObjectName(QString::fromUtf8("bankDeviceLabel"));
        label_17 = new QLabel(bankDeviceLabel);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(113, 0, 72, 16));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(bankDeviceLabel);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(36, 0, 21, 16));
        label_19 = new QLabel(bankDeviceLabel);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(bankDeviceLabel);
        programDeviceLabel = new QWidget();
        programDeviceLabel->setObjectName(QString::fromUtf8("programDeviceLabel"));
        label_20 = new QLabel(programDeviceLabel);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(113, 0, 72, 16));
        label_20->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(programDeviceLabel);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(programDeviceLabel);
        bendDeviceLabel = new QWidget();
        bendDeviceLabel->setObjectName(QString::fromUtf8("bendDeviceLabel"));
        label_23 = new QLabel(bendDeviceLabel);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(113, 0, 72, 16));
        label_23->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(bendDeviceLabel);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(bendDeviceLabel);
        mmcDeviceLabel = new QWidget();
        mmcDeviceLabel->setObjectName(QString::fromUtf8("mmcDeviceLabel"));
        label_9 = new QLabel(mmcDeviceLabel);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(6, 0, 31, 16));
        label_24 = new QLabel(mmcDeviceLabel);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(113, 0, 72, 16));
        label_24->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(mmcDeviceLabel);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(42, 0, 41, 16));
        deviceViewLabels->addWidget(mmcDeviceLabel);
        oscDeviceLabel = new QWidget();
        oscDeviceLabel->setObjectName(QString::fromUtf8("oscDeviceLabel"));
        label_21 = new QLabel(oscDeviceLabel);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(113, 0, 72, 16));
        label_21->setAlignment(Qt::AlignCenter);
        deviceViewLabels->addWidget(oscDeviceLabel);
        aftertouchDeviceLabel = new QWidget();
        aftertouchDeviceLabel->setObjectName(QString::fromUtf8("aftertouchDeviceLabel"));
        label_28 = new QLabel(aftertouchDeviceLabel);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(113, 0, 72, 16));
        label_28->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(aftertouchDeviceLabel);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(aftertouchDeviceLabel);
        polyDeviceLabel = new QWidget();
        polyDeviceLabel->setObjectName(QString::fromUtf8("polyDeviceLabel"));
        label_29 = new QLabel(polyDeviceLabel);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(113, 0, 72, 16));
        label_29->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(polyDeviceLabel);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(35, 0, 31, 16));
        label_32 = new QLabel(polyDeviceLabel);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(70, 0, 21, 16));
        deviceViewLabels->addWidget(polyDeviceLabel);
        delay = new QSpinBox(modlineForm);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setGeometry(QRect(526, 19, 30, 18));
        delay->setFont(font2);
        delay->setFocusPolicy(Qt::StrongFocus);
        delay->setStyleSheet(QString::fromUtf8("QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(18, 18, 18, 255);\n"
"	border: 1px solid rgba(0,174,239,90);\n"
"	color: rgba(255, 255, 255, 90);\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        delay->setFrame(true);
        delay->setAlignment(Qt::AlignCenter);
        delay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay->setMaximum(5000);
        label_13 = new QLabel(modlineForm);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(28, 2, 31, 16));
        label_13->setAlignment(Qt::AlignCenter);
        label_33 = new QLabel(modlineForm);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(63, 2, 27, 16));
        label_33->setAlignment(Qt::AlignCenter);
        label_34 = new QLabel(modlineForm);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(129, 2, 31, 16));
        label_34->setAlignment(Qt::AlignCenter);
        label_35 = new QLabel(modlineForm);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(200, 2, 27, 16));
        label_35->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgba(255, 255, 255, 90);\n"
"}"));
        label_35->setAlignment(Qt::AlignCenter);
        label_36 = new QLabel(modlineForm);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(245, 2, 27, 16));
        label_36->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(modlineForm);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(285, 2, 27, 16));
        label_37->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(modlineForm);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(327, 2, 27, 16));
        label_38->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgba(255, 255, 255, 90);\n"
"}"));
        label_38->setAlignment(Qt::AlignCenter);
        label_39 = new QLabel(modlineForm);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(381, 2, 27, 16));
        label_39->setAlignment(Qt::AlignCenter);
        label_40 = new QLabel(modlineForm);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(430, 2, 27, 16));
        label_40->setAlignment(Qt::AlignCenter);
        label_41 = new QLabel(modlineForm);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(463, 2, 27, 16));
        label_41->setAlignment(Qt::AlignCenter);
        label_42 = new QLabel(modlineForm);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(490, 2, 37, 16));
        label_42->setAlignment(Qt::AlignCenter);
        label_43 = new QLabel(modlineForm);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(527, 2, 27, 16));
        label_43->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(modlineForm);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(568, 2, 27, 16));
        label_44->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgba(255, 255, 255, 90);\n"
"}"));
        label_44->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(modlineForm);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(606, 2, 77, 16));
        label_45->setAlignment(Qt::AlignCenter);
        label_46 = new QLabel(modlineForm);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(942, 1, 80, 16));
        label_46->setAlignment(Qt::AlignCenter);
        label_47 = new QLabel(modlineForm);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(1026, 1, 80, 16));
        label_47->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(modlineForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(914, 0, 20, 42));
        label_4->setStyleSheet(QString::fromUtf8("background: rgb(60, 60, 60);"));
        modlinedisplayenable = new QRadioButton(modlineForm);
        modlinedisplayenable->setObjectName(QString::fromUtf8("modlinedisplayenable"));
        modlinedisplayenable->setGeometry(QRect(1112, 18, 20, 20));
        modlinedisplayenable->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label_48 = new QLabel(modlineForm);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(1108, 3, 20, 16));
        label_48->setStyleSheet(QString::fromUtf8("background: none;\n"
"image: url(:/resources/modline_led_display_arrow.png);"));
        hide_border_bleed = new QLabel(modlineForm);
        hide_border_bleed->setObjectName(QString::fromUtf8("hide_border_bleed"));
        hide_border_bleed->setEnabled(false);
        hide_border_bleed->setGeometry(QRect(916, 0, 10, 42));
        hide_border_bleed->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-right: 4px solid rgb(0,174,239);\n"
"}"));
        enable->raise();
        instanceLabel->raise();
        initmode->raise();
        initvalue->raise();
        label->raise();
        label_2->raise();
        gain->raise();
        offset->raise();
        label_3->raise();
        result->raise();
        table->raise();
        max->raise();
        slew->raise();
        destination->raise();
        source->raise();
        ledgreen->raise();
        ledred->raise();
        raw->raise();
        min->raise();
        deviceViews->raise();
        outputvalue->raise();
        deviceViewLabels->raise();
        delay->raise();
        label_13->raise();
        label_33->raise();
        label_34->raise();
        label_35->raise();
        label_36->raise();
        label_37->raise();
        label_38->raise();
        label_39->raise();
        label_40->raise();
        label_41->raise();
        label_42->raise();
        label_43->raise();
        label_44->raise();
        label_45->raise();
        label_46->raise();
        label_47->raise();
        label_4->raise();
        modlinedisplayenable->raise();
        label_48->raise();
        hide_border_bleed->raise();
        QWidget::setTabOrder(enable, initmode);
        QWidget::setTabOrder(initmode, initvalue);
        QWidget::setTabOrder(initvalue, source);
        QWidget::setTabOrder(source, raw);
        QWidget::setTabOrder(raw, gain);
        QWidget::setTabOrder(gain, offset);
        QWidget::setTabOrder(offset, result);
        QWidget::setTabOrder(result, table);
        QWidget::setTabOrder(table, min);
        QWidget::setTabOrder(min, max);
        QWidget::setTabOrder(max, slew);
        QWidget::setTabOrder(slew, delay);
        QWidget::setTabOrder(delay, outputvalue);
        QWidget::setTabOrder(outputvalue, destination);
        QWidget::setTabOrder(destination, polynote);
        QWidget::setTabOrder(polynote, notenumber);
        QWidget::setTabOrder(notenumber, notelivenumber);
        QWidget::setTabOrder(notelivenumber, notevelocity);
        QWidget::setTabOrder(notevelocity, notelivevelocity);
        QWidget::setTabOrder(notelivevelocity, cc);
        QWidget::setTabOrder(cc, bankmsb);
        QWidget::setTabOrder(bankmsb, mmcdeviceid);
        QWidget::setTabOrder(mmcdeviceid, mmcfunction);
        QWidget::setTabOrder(mmcfunction, oscroute);
        QWidget::setTabOrder(oscroute, notechannel);
        QWidget::setTabOrder(notechannel, notelivechannel);
        QWidget::setTabOrder(notelivechannel, controlchannel);
        QWidget::setTabOrder(controlchannel, programchannel);
        QWidget::setTabOrder(programchannel, bankchannel);
        QWidget::setTabOrder(bankchannel, bendchannel);
        QWidget::setTabOrder(bendchannel, polychannel);
        QWidget::setTabOrder(polychannel, aftertouchchannel);
        QWidget::setTabOrder(aftertouchchannel, notedevice);
        QWidget::setTabOrder(notedevice, notelivedevice);
        QWidget::setTabOrder(notelivedevice, controldevice);
        QWidget::setTabOrder(controldevice, bankdevice);
        QWidget::setTabOrder(bankdevice, programdevice);
        QWidget::setTabOrder(programdevice, benddevice);
        QWidget::setTabOrder(benddevice, mmcdevice);
        QWidget::setTabOrder(mmcdevice, aftertouchdevice);
        QWidget::setTabOrder(aftertouchdevice, polydevice);
        QWidget::setTabOrder(polydevice, ledgreen);
        QWidget::setTabOrder(ledgreen, ledred);
        QWidget::setTabOrder(ledred, modlinedisplayenable);

        retranslateUi(modlineForm);

        deviceViews->setCurrentIndex(1);
        deviceViewLabels->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(modlineForm);
    } // setupUi

    void retranslateUi(QWidget *modlineForm)
    {
        modlineForm->setWindowTitle(QCoreApplication::translate("modlineForm", "Form", nullptr));
        instanceLabel->setText(QCoreApplication::translate("modlineForm", "#", nullptr));
#if QT_CONFIG(tooltip)
        enable->setToolTip(QCoreApplication::translate("modlineForm", "Enables/Disables the modline.", nullptr));
#endif // QT_CONFIG(tooltip)
        enable->setText(QString());
        initmode->setItemText(0, QCoreApplication::translate("modlineForm", "None", nullptr));
        initmode->setItemText(1, QCoreApplication::translate("modlineForm", "Once", nullptr));
        initmode->setItemText(2, QCoreApplication::translate("modlineForm", "Always", nullptr));

#if QT_CONFIG(tooltip)
        initmode->setToolTip(QCoreApplication::translate("modlineForm", "Sets the init mode.<p><b>None</b>: Off. No init value will be sent.<p><b>Once</b>: Outputs the set init value the first time this preset is selected/loaded.<p><b>Always</b>: Outputs the set init value every time this preset is selected/loaded.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        initvalue->setToolTip(QCoreApplication::translate("modlineForm", "This value will be sent through the modline if an init mode is enabled.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        raw->setToolTip(QCoreApplication::translate("modlineForm", "Live display of sensor data <br>coming from SoftStep.<p>(Hosted mode only)", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("modlineForm", "x", nullptr));
        label_2->setText(QCoreApplication::translate("modlineForm", "+", nullptr));
#if QT_CONFIG(tooltip)
        gain->setToolTip(QCoreApplication::translate("modlineForm", "Multiply by the set amount.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        offset->setToolTip(QCoreApplication::translate("modlineForm", "Add the set amount <br>(use negative numbers to subtract).", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("modlineForm", "=", nullptr));
#if QT_CONFIG(tooltip)
        result->setToolTip(QCoreApplication::translate("modlineForm", "Live display of the modline <br>data after the gain and offset stage.<p>(Hosted mode only)", nullptr));
#endif // QT_CONFIG(tooltip)
        table->setItemText(0, QCoreApplication::translate("modlineForm", "Lin", nullptr));
        table->setItemText(1, QCoreApplication::translate("modlineForm", "Sin", nullptr));
        table->setItemText(2, QCoreApplication::translate("modlineForm", "Cos", nullptr));
        table->setItemText(3, QCoreApplication::translate("modlineForm", "Exp", nullptr));
        table->setItemText(4, QCoreApplication::translate("modlineForm", "Log", nullptr));
        table->setItemText(5, QCoreApplication::translate("modlineForm", "Custom", nullptr));
        table->setItemText(6, QCoreApplication::translate("modlineForm", "Toggle", nullptr));
        table->setItemText(7, QCoreApplication::translate("modlineForm", "Counter Inc", nullptr));
        table->setItemText(8, QCoreApplication::translate("modlineForm", "Counter Dec", nullptr));
        table->setItemText(9, QCoreApplication::translate("modlineForm", "Counter Set", nullptr));

#if QT_CONFIG(tooltip)
        table->setToolTip(QCoreApplication::translate("modlineForm", "Sets the type of curve to apply to the modline data.<p>Also used to set up toggles and interact with the key counter.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        min->setToolTip(QCoreApplication::translate("modlineForm", "Sets the minimum value that can be output (range: 0-127).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        max->setToolTip(QCoreApplication::translate("modlineForm", "Sets the maximum value that can be output (range: 0-127).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        slew->setToolTip(QCoreApplication::translate("modlineForm", "The amount of time (in milliseconds) it takes to slide/interpolate to the next value<p>Smaller values can smooth out jumpy data, while larger values can create ramps between values.<p><b>Example</b>: A value of 127 going through the modline with a smoothing value of 3000 would result in a three second ramp up to 127.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        outputvalue->setToolTip(QCoreApplication::translate("modlineForm", "Live display of the modline <br>data after the table, min/max, smoothing, and delay.<p>(Hosted mode only)", nullptr));
#endif // QT_CONFIG(tooltip)
        destination->setItemText(0, QCoreApplication::translate("modlineForm", "None", nullptr));
        destination->setItemText(1, QCoreApplication::translate("modlineForm", "Note Set", nullptr));
        destination->setItemText(2, QCoreApplication::translate("modlineForm", "Note Live", nullptr));
        destination->setItemText(3, QCoreApplication::translate("modlineForm", "CC", nullptr));
        destination->setItemText(4, QCoreApplication::translate("modlineForm", "Bank", nullptr));
        destination->setItemText(5, QCoreApplication::translate("modlineForm", "Program", nullptr));
        destination->setItemText(6, QCoreApplication::translate("modlineForm", "OSC", nullptr));
        destination->setItemText(7, QCoreApplication::translate("modlineForm", "Pitch Bend", nullptr));
        destination->setItemText(8, QCoreApplication::translate("modlineForm", "MMC", nullptr));
        destination->setItemText(9, QCoreApplication::translate("modlineForm", "Aftertouch", nullptr));
        destination->setItemText(10, QCoreApplication::translate("modlineForm", "Poly Aftertouch", nullptr));
        destination->setItemText(11, QCoreApplication::translate("modlineForm", "X Inc Set", nullptr));
        destination->setItemText(12, QCoreApplication::translate("modlineForm", "Y Inc Set", nullptr));

#if QT_CONFIG(tooltip)
        destination->setToolTip(QCoreApplication::translate("modlineForm", "Sets the type of MIDI message to output.", nullptr));
#endif // QT_CONFIG(tooltip)
        source->setItemText(0, QCoreApplication::translate("modlineForm", "None", nullptr));
        source->setItemText(1, QCoreApplication::translate("modlineForm", "Pressure Live", nullptr));
        source->setItemText(2, QCoreApplication::translate("modlineForm", "X Live", nullptr));
        source->setItemText(3, QCoreApplication::translate("modlineForm", "Y Live", nullptr));
        source->setItemText(4, QCoreApplication::translate("modlineForm", "Pressure Latch", nullptr));
        source->setItemText(5, QCoreApplication::translate("modlineForm", "X Latch", nullptr));
        source->setItemText(6, QCoreApplication::translate("modlineForm", "Y Latch", nullptr));
        source->setItemText(7, QCoreApplication::translate("modlineForm", "X Increment", nullptr));
        source->setItemText(8, QCoreApplication::translate("modlineForm", "Y Increment", nullptr));
        source->setItemText(9, QCoreApplication::translate("modlineForm", "Foot On", nullptr));
        source->setItemText(10, QCoreApplication::translate("modlineForm", "Foot Off", nullptr));
        source->setItemText(11, QCoreApplication::translate("modlineForm", "Top", nullptr));
        source->setItemText(12, QCoreApplication::translate("modlineForm", "Bottom", nullptr));
        source->setItemText(13, QCoreApplication::translate("modlineForm", "Fast Trig", nullptr));
        source->setItemText(14, QCoreApplication::translate("modlineForm", "Dbl Trig", nullptr));
        source->setItemText(15, QCoreApplication::translate("modlineForm", "Long Trig", nullptr));
        source->setItemText(16, QCoreApplication::translate("modlineForm", "Off Trig", nullptr));
        source->setItemText(17, QCoreApplication::translate("modlineForm", "Delta Trig", nullptr));
        source->setItemText(18, QCoreApplication::translate("modlineForm", "Fast Trig Latch", nullptr));
        source->setItemText(19, QCoreApplication::translate("modlineForm", "Dbl Trig Latch", nullptr));
        source->setItemText(20, QCoreApplication::translate("modlineForm", "Long Trig Latch", nullptr));
        source->setItemText(21, QCoreApplication::translate("modlineForm", "Pedal", nullptr));
        source->setItemText(22, QCoreApplication::translate("modlineForm", "Nav Y", nullptr));
        source->setItemText(23, QCoreApplication::translate("modlineForm", "Nav Yx10 & Key", nullptr));
        source->setItemText(24, QCoreApplication::translate("modlineForm", "Any Key Value", nullptr));
        source->setItemText(25, QCoreApplication::translate("modlineForm", "Prev Key Value", nullptr));
        source->setItemText(26, QCoreApplication::translate("modlineForm", "This Key Value", nullptr));
        source->setItemText(27, QCoreApplication::translate("modlineForm", "Key 1 Pressed", nullptr));
        source->setItemText(28, QCoreApplication::translate("modlineForm", "Key 2 Pressed", nullptr));
        source->setItemText(29, QCoreApplication::translate("modlineForm", "Key 3 Pressed", nullptr));
        source->setItemText(30, QCoreApplication::translate("modlineForm", "Key 4 Pressed", nullptr));
        source->setItemText(31, QCoreApplication::translate("modlineForm", "Key 5 Pressed", nullptr));
        source->setItemText(32, QCoreApplication::translate("modlineForm", "Key 6 Pressed", nullptr));
        source->setItemText(33, QCoreApplication::translate("modlineForm", "Key 7 Pressed", nullptr));
        source->setItemText(34, QCoreApplication::translate("modlineForm", "Key 8 Pressed", nullptr));
        source->setItemText(35, QCoreApplication::translate("modlineForm", "Key 9 Pressed", nullptr));
        source->setItemText(36, QCoreApplication::translate("modlineForm", "Key 0 Pressed", nullptr));
        source->setItemText(37, QCoreApplication::translate("modlineForm", "Other Key Pressed", nullptr));
        source->setItemText(38, QCoreApplication::translate("modlineForm", "Modline 1 Output", nullptr));
        source->setItemText(39, QCoreApplication::translate("modlineForm", "Modline 2 Output", nullptr));
        source->setItemText(40, QCoreApplication::translate("modlineForm", "Modline 3 Output", nullptr));
        source->setItemText(41, QCoreApplication::translate("modlineForm", "Modline 4 Output", nullptr));
        source->setItemText(42, QCoreApplication::translate("modlineForm", "Modline 5 Output", nullptr));
        source->setItemText(43, QCoreApplication::translate("modlineForm", "Modline 6 Output", nullptr));
        source->setItemText(44, QCoreApplication::translate("modlineForm", "MIDI A", nullptr));
        source->setItemText(45, QCoreApplication::translate("modlineForm", "MIDI B", nullptr));
        source->setItemText(46, QCoreApplication::translate("modlineForm", "MIDI C", nullptr));
        source->setItemText(47, QCoreApplication::translate("modlineForm", "MIDI D", nullptr));
        source->setItemText(48, QCoreApplication::translate("modlineForm", "MIDI E", nullptr));
        source->setItemText(49, QCoreApplication::translate("modlineForm", "MIDI F", nullptr));
        source->setItemText(50, QCoreApplication::translate("modlineForm", "MIDI G", nullptr));
        source->setItemText(51, QCoreApplication::translate("modlineForm", "MIDI H", nullptr));
        source->setItemText(52, QCoreApplication::translate("modlineForm", "OSC A", nullptr));
        source->setItemText(53, QCoreApplication::translate("modlineForm", "OSC B", nullptr));
        source->setItemText(54, QCoreApplication::translate("modlineForm", "OSC C", nullptr));
        source->setItemText(55, QCoreApplication::translate("modlineForm", "OSC D", nullptr));
        source->setItemText(56, QCoreApplication::translate("modlineForm", "OSC E", nullptr));
        source->setItemText(57, QCoreApplication::translate("modlineForm", "OSC F", nullptr));
        source->setItemText(58, QCoreApplication::translate("modlineForm", "OSC G", nullptr));
        source->setItemText(59, QCoreApplication::translate("modlineForm", "OSC H", nullptr));

#if QT_CONFIG(tooltip)
        source->setToolTip(QCoreApplication::translate("modlineForm", "Sets the type of sensor data coming from the SoftStep.", nullptr));
#endif // QT_CONFIG(tooltip)
        ledgreen->setItemText(0, QCoreApplication::translate("modlineForm", "None", nullptr));
        ledgreen->setItemText(1, QCoreApplication::translate("modlineForm", "True", nullptr));
        ledgreen->setItemText(2, QCoreApplication::translate("modlineForm", "False", nullptr));
        ledgreen->setItemText(3, QCoreApplication::translate("modlineForm", "Flash True", nullptr));
        ledgreen->setItemText(4, QCoreApplication::translate("modlineForm", "Flash False", nullptr));
        ledgreen->setItemText(5, QCoreApplication::translate("modlineForm", "Flash Fast True", nullptr));
        ledgreen->setItemText(6, QCoreApplication::translate("modlineForm", "Flash Fast False", nullptr));
        ledgreen->setItemText(7, QCoreApplication::translate("modlineForm", "Blink True", nullptr));
        ledgreen->setItemText(8, QCoreApplication::translate("modlineForm", "Blink False", nullptr));
        ledgreen->setItemText(9, QCoreApplication::translate("modlineForm", "Off", nullptr));

#if QT_CONFIG(tooltip)
        ledgreen->setToolTip(QCoreApplication::translate("modlineForm", "Sets the green LED behavior.<p><b>None</b>: This modline will not affect the LED in any way.<p><b>True</b>: The LED will turn on when the modline value is greater <br>than 0 and will turn off when equal to 0.<p><b>False</b>: The LED will turn on when the modline value is equal <br>to 0 and will turn off when greater than 0.<p><b>Flash True</b>: The LED will flash repeatedly when the modline <br>value is greater than 0 and turn off when equal to 0.<p><b>Flash False</b>: The LED will flash repeatedly when the modline <br>value is equal to 0 and turn off when greater than 0.<p><b>Flash Fast True</b>: Same as Flash True with a faster flash rate.<p><b>Flash Fast False</b>: Same as Flash False with a faster flash rate.<p><b>Blink True</b>: The LED will blink once when the modline value <br>is greater than 0.<p><b>Blink Flase</b>: The LED will blink once when the modline value <br>is equal to 0.", nullptr));
#endif // QT_CONFIG(tooltip)
        ledred->setItemText(0, QCoreApplication::translate("modlineForm", "None", nullptr));
        ledred->setItemText(1, QCoreApplication::translate("modlineForm", "True", nullptr));
        ledred->setItemText(2, QCoreApplication::translate("modlineForm", "False", nullptr));
        ledred->setItemText(3, QCoreApplication::translate("modlineForm", "Flash True", nullptr));
        ledred->setItemText(4, QCoreApplication::translate("modlineForm", "Flash False", nullptr));
        ledred->setItemText(5, QCoreApplication::translate("modlineForm", "Flash Fast True", nullptr));
        ledred->setItemText(6, QCoreApplication::translate("modlineForm", "Flash Fast False", nullptr));
        ledred->setItemText(7, QCoreApplication::translate("modlineForm", "Blink True", nullptr));
        ledred->setItemText(8, QCoreApplication::translate("modlineForm", "Blink False", nullptr));
        ledred->setItemText(9, QCoreApplication::translate("modlineForm", "Off", nullptr));

#if QT_CONFIG(tooltip)
        ledred->setToolTip(QCoreApplication::translate("modlineForm", "Sets the red LED behavior.<p><b>None</b>: This modline will not affect the LED in any way.<p><b>True</b>: The LED will turn on when the modline value is greater <br>than 0 and will turn off when equal to 0.<p><b>False</b>: The LED will turn on when the modline value is equal <br>to 0 and will turn off when greater than 0.<p><b>Flash True</b>: The LED will flash repeatedly when the modline <br>value is greater than 0 and turn off when equal to 0.<p><b>Flash False</b>: The LED will flash repeatedly when the modline <br>value is equal to 0 and turn off when greater than 0.<p><b>Flash Fast True</b>: Same as Flash True with a faster flash rate.<p><b>Flash Fast False</b>: Same as Flash False with a faster flash rate.<p><b>Blink True</b>: The LED will blink once when the modline value <br>is greater than 0.<p><b>Blink Flase</b>: The LED will blink once when the modline value <br>is equal to 0.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notenumber->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI note number to output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notevelocity->setToolTip(QCoreApplication::translate("modlineForm", "Sets the velocity for the MIDI note.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notechannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        notedevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        notedevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        notedevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        notelivedevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        notelivedevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        notelivedevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notelivevelocity->setToolTip(QCoreApplication::translate("modlineForm", "Sets the velocity for the note messages.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notelivechannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cc->setToolTip(QCoreApplication::translate("modlineForm", "Sets the CC number to send the modline data on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        controlchannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        controldevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        controldevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        controldevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        bankdevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        bankdevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        bankdevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bankmsb->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MSB for the bank message. The LSB will be <br>filled in by whatever value is coming through the modline.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bankchannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        programdevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        programdevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        programdevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        programchannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bendchannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        benddevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        benddevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        benddevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        mmcdevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        mmcdevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        mmcdevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mmcdeviceid->setToolTip(QCoreApplication::translate("modlineForm", "Sets the device ID for the receiving MMC device.", nullptr));
#endif // QT_CONFIG(tooltip)
        mmcfunction->setItemText(0, QCoreApplication::translate("modlineForm", "Stop", nullptr));
        mmcfunction->setItemText(1, QCoreApplication::translate("modlineForm", "Play", nullptr));
        mmcfunction->setItemText(2, QCoreApplication::translate("modlineForm", "Deferred Play", nullptr));
        mmcfunction->setItemText(3, QCoreApplication::translate("modlineForm", "Fast Forward", nullptr));
        mmcfunction->setItemText(4, QCoreApplication::translate("modlineForm", "Rewind", nullptr));
        mmcfunction->setItemText(5, QCoreApplication::translate("modlineForm", "Punch In", nullptr));
        mmcfunction->setItemText(6, QCoreApplication::translate("modlineForm", "Punch Out", nullptr));
        mmcfunction->setItemText(7, QCoreApplication::translate("modlineForm", "Pause", nullptr));

#if QT_CONFIG(tooltip)
        mmcfunction->setToolTip(QCoreApplication::translate("modlineForm", "Sets the type of MMC message to output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        oscroute->setToolTip(QCoreApplication::translate("modlineForm", "Sets the routing prefix for the OSC message.", nullptr));
#endif // QT_CONFIG(tooltip)
        aftertouchdevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        aftertouchdevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        aftertouchdevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        aftertouchchannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        polynote->setToolTip(QCoreApplication::translate("modlineForm", "Sets the note number to send the polyphonic aftertouch for.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        polychannel->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        polydevice->setItemText(0, QCoreApplication::translate("modlineForm", "SoftStep Expander", nullptr));
        polydevice->setItemText(1, QCoreApplication::translate("modlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        polydevice->setToolTip(QCoreApplication::translate("modlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("modlineForm", "Note", nullptr));
        label_6->setText(QCoreApplication::translate("modlineForm", "Vel", nullptr));
        label_7->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_8->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_10->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_11->setText(QCoreApplication::translate("modlineForm", "Vel", nullptr));
        label_12->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_14->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_15->setText(QCoreApplication::translate("modlineForm", "CC#", nullptr));
        label_16->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_17->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_18->setText(QCoreApplication::translate("modlineForm", "MSB", nullptr));
        label_19->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_20->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_22->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_23->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_25->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_9->setText(QCoreApplication::translate("modlineForm", "ID", nullptr));
        label_24->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_26->setText(QCoreApplication::translate("modlineForm", "Function", nullptr));
        label_21->setText(QCoreApplication::translate("modlineForm", "Output Prefix", nullptr));
        label_28->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_30->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
        label_29->setText(QCoreApplication::translate("modlineForm", "Output Port", nullptr));
        label_31->setText(QCoreApplication::translate("modlineForm", "Note", nullptr));
        label_32->setText(QCoreApplication::translate("modlineForm", "Ch", nullptr));
#if QT_CONFIG(tooltip)
        delay->setToolTip(QCoreApplication::translate("modlineForm", "The amount of time (in milliseconds) to delay the modline data.<p><b>Example</b>: A delay of 2000 would delay any messages by two seconds.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("modlineForm", "Mode", nullptr));
        label_33->setText(QCoreApplication::translate("modlineForm", "Value", nullptr));
        label_34->setText(QCoreApplication::translate("modlineForm", "Source", nullptr));
        label_35->setText(QCoreApplication::translate("modlineForm", "Raw", nullptr));
        label_36->setText(QCoreApplication::translate("modlineForm", "Gain", nullptr));
        label_37->setText(QCoreApplication::translate("modlineForm", "Offset", nullptr));
        label_38->setText(QCoreApplication::translate("modlineForm", "Result", nullptr));
        label_39->setText(QCoreApplication::translate("modlineForm", "Table", nullptr));
        label_40->setText(QCoreApplication::translate("modlineForm", "Min", nullptr));
        label_41->setText(QCoreApplication::translate("modlineForm", "Max", nullptr));
        label_42->setText(QCoreApplication::translate("modlineForm", "Smooth", nullptr));
        label_43->setText(QCoreApplication::translate("modlineForm", "Delay", nullptr));
        label_44->setText(QCoreApplication::translate("modlineForm", "Value", nullptr));
        label_45->setText(QCoreApplication::translate("modlineForm", "Message Type", nullptr));
        label_46->setText(QCoreApplication::translate("modlineForm", "Green LED", nullptr));
        label_47->setText(QCoreApplication::translate("modlineForm", "Red LED", nullptr));
        label_4->setText(QString());
#if QT_CONFIG(tooltip)
        modlinedisplayenable->setToolTip(QCoreApplication::translate("modlineForm", "This selects which modline's <br>data will be used for the display parameters above. Only one may be selected per key.", nullptr));
#endif // QT_CONFIG(tooltip)
        modlinedisplayenable->setText(QString());
        label_48->setText(QString());
        hide_border_bleed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modlineForm: public Ui_modlineForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODLINEFORMWIN_H
