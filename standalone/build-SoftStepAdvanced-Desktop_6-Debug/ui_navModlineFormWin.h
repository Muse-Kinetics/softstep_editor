// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'navModlineFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVMODLINEFORMWIN_H
#define UI_NAVMODLINEFORMWIN_H

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

class Ui_navModlineForm
{
public:
    QLabel *label_33;
    QSpinBox *outputvalue;
    QLabel *instanceLabel;
    QSpinBox *result;
    QLabel *label_41;
    QLabel *label_3;
    QLabel *label_36;
    QSpinBox *delay;
    QLabel *label;
    QLabel *label_39;
    QSpinBox *min;
    QSpinBox *offset;
    QSpinBox *max;
    QLabel *label_35;
    QLabel *label_40;
    QLabel *label_38;
    QSpinBox *slew;
    QSpinBox *initvalue;
    QLabel *label_43;
    QComboBox *destination;
    QCheckBox *enable;
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
    QLabel *label_13;
    QStackedWidget *deviceViewLabels;
    QWidget *noneDeviceLabel;
    QWidget *noteSetDeviceLabel;
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
    QComboBox *source;
    QLabel *label_34;
    QLabel *label_37;
    QLabel *label_45;
    QSpinBox *raw;
    QLabel *label_42;
    QLabel *label_2;
    QComboBox *table;
    QDoubleSpinBox *gain;
    QComboBox *initmode;
    QLabel *label_44;
    QLabel *label_48;
    QRadioButton *modlinedisplayenable;
    QLabel *label_4;
    QLabel *hide_border_bleed;

    void setupUi(QWidget *navModlineForm)
    {
        if (navModlineForm->objectName().isEmpty())
            navModlineForm->setObjectName(QString::fromUtf8("navModlineForm"));
        navModlineForm->resize(967, 42);
        navModlineForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"/*	background: rgb(0,0,0); */\n"
"	background:		rgb(80, 80, 80);	\n"
"	border: 3px rgb(25, 25, 25);\n"
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
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QSpinBox::focus\n"
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
"	padding: 1px 1px "
                        "1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::focus\n"
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
"	background: rgb(1"
                        "8, 18, 18);\n"
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
"	image: "
                        "url(:/resources/modline_combobox_menu_arrows.png);\n"
"	padding-right: 10px;\n"
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
        label_33 = new QLabel(navModlineForm);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(65, 1, 27, 16));
        label_33->setAlignment(Qt::AlignCenter);
        outputvalue = new QSpinBox(navModlineForm);
        outputvalue->setObjectName(QString::fromUtf8("outputvalue"));
        outputvalue->setGeometry(QRect(571, 18, 27, 18));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setPointSize(7);
        font.setBold(false);
        font.setItalic(false);
        outputvalue->setFont(font);
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
        instanceLabel = new QLabel(navModlineForm);
        instanceLabel->setObjectName(QString::fromUtf8("instanceLabel"));
        instanceLabel->setGeometry(QRect(10, 42, 18, 18));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Futura")});
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        instanceLabel->setFont(font1);
        instanceLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: 				white;\n"
"	font: 				8pt \"Futura\";\n"
"	border:				none;\n"
"}"));
        instanceLabel->setAlignment(Qt::AlignCenter);
        instanceLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        result = new QSpinBox(navModlineForm);
        result->setObjectName(QString::fromUtf8("result"));
        result->setEnabled(true);
        result->setGeometry(QRect(329, 18, 28, 18));
        result->setFont(font);
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
        label_41 = new QLabel(navModlineForm);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(465, 1, 27, 16));
        label_41->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(navModlineForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(319, 18, 8, 18));
        label_3->setFont(font);
        label_36 = new QLabel(navModlineForm);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(247, 1, 27, 16));
        label_36->setAlignment(Qt::AlignCenter);
        delay = new QSpinBox(navModlineForm);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setGeometry(QRect(528, 18, 30, 18));
        delay->setFont(font);
        delay->setFocusPolicy(Qt::StrongFocus);
        delay->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
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
        label = new QLabel(navModlineForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(235, 18, 8, 18));
        label->setFont(font);
        label_39 = new QLabel(navModlineForm);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(383, 1, 27, 16));
        label_39->setAlignment(Qt::AlignCenter);
        min = new QSpinBox(navModlineForm);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(432, 18, 30, 18));
        min->setFont(font);
        min->setFocusPolicy(Qt::StrongFocus);
        min->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        min->setFrame(true);
        min->setAlignment(Qt::AlignCenter);
        min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        min->setMaximum(127);
        offset = new QSpinBox(navModlineForm);
        offset->setObjectName(QString::fromUtf8("offset"));
        offset->setGeometry(QRect(287, 18, 28, 18));
        offset->setFont(font);
        offset->setFocusPolicy(Qt::StrongFocus);
        offset->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        offset->setAlignment(Qt::AlignCenter);
        offset->setButtonSymbols(QAbstractSpinBox::NoButtons);
        offset->setMinimum(-999);
        offset->setMaximum(999);
        max = new QSpinBox(navModlineForm);
        max->setObjectName(QString::fromUtf8("max"));
        max->setGeometry(QRect(464, 18, 30, 18));
        max->setFont(font);
        max->setFocusPolicy(Qt::StrongFocus);
        max->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        max->setFrame(true);
        max->setAlignment(Qt::AlignCenter);
        max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        max->setMaximum(127);
        label_35 = new QLabel(navModlineForm);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(202, 1, 27, 16));
        label_35->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgba(255, 255, 255, 90);\n"
"}"));
        label_35->setAlignment(Qt::AlignCenter);
        label_40 = new QLabel(navModlineForm);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(432, 1, 27, 16));
        label_40->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(navModlineForm);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(329, 1, 27, 16));
        label_38->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgba(255, 255, 255, 90);\n"
"}"));
        label_38->setAlignment(Qt::AlignCenter);
        slew = new QSpinBox(navModlineForm);
        slew->setObjectName(QString::fromUtf8("slew"));
        slew->setGeometry(QRect(496, 18, 30, 18));
        slew->setFont(font);
        slew->setFocusPolicy(Qt::StrongFocus);
        slew->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        slew->setFrame(true);
        slew->setAlignment(Qt::AlignCenter);
        slew->setButtonSymbols(QAbstractSpinBox::NoButtons);
        slew->setMaximum(5000);
        initvalue = new QSpinBox(navModlineForm);
        initvalue->setObjectName(QString::fromUtf8("initvalue"));
        initvalue->setGeometry(QRect(68, 18, 22, 18));
        initvalue->setFont(font);
        initvalue->setFocusPolicy(Qt::StrongFocus);
        initvalue->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        initvalue->setFrame(true);
        initvalue->setAlignment(Qt::AlignCenter);
        initvalue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        initvalue->setMaximum(127);
        label_43 = new QLabel(navModlineForm);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(529, 1, 27, 16));
        label_43->setAlignment(Qt::AlignCenter);
        destination = new QComboBox(navModlineForm);
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
        destination->setGeometry(QRect(610, 18, 77, 18));
        destination->setFont(font);
        destination->setFocusPolicy(Qt::StrongFocus);
        destination->setContextMenuPolicy(Qt::DefaultContextMenu);
        destination->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        enable = new QCheckBox(navModlineForm);
        enable->setObjectName(QString::fromUtf8("enable"));
        enable->setGeometry(QRect(4, 16, 20, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Futura")});
        font2.setPointSize(10);
        enable->setFont(font2);
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
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        enable->setTristate(false);
        deviceViews = new QStackedWidget(navModlineForm);
        deviceViews->setObjectName(QString::fromUtf8("deviceViews"));
        deviceViews->setGeometry(QRect(688, 18, 244, 18));
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
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QSpinBox::focus\n"
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
"	padding: 0,0,0,0;\n"
"}\n"
"\n"
"QDoubleSpinBox::focus\n"
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
"}\n"
"\n"
"QLi"
                        "neEdit:focus\n"
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
""
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
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Tahoma")});
        font3.setBold(false);
        font3.setItalic(false);
        notenumber->setFont(font3);
        notenumber->setFocusPolicy(Qt::StrongFocus);
        notenumber->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	font: 9px \"Tahoma\";\n"
"}"));
        notenumber->setFrame(true);
        notenumber->setAlignment(Qt::AlignCenter);
        notenumber->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notenumber->setMaximum(127);
        notevelocity = new QSpinBox(noteSetDeviceView);
        notevelocity->setObjectName(QString::fromUtf8("notevelocity"));
        notevelocity->setGeometry(QRect(37, 0, 30, 18));
        notevelocity->setFont(font3);
        notevelocity->setFocusPolicy(Qt::StrongFocus);
        notevelocity->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	font: 9px \"Tahoma\";\n"
"}"));
        notevelocity->setFrame(true);
        notevelocity->setAlignment(Qt::AlignCenter);
        notevelocity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notevelocity->setMaximum(127);
        notechannel = new QSpinBox(noteSetDeviceView);
        notechannel->setObjectName(QString::fromUtf8("notechannel"));
        notechannel->setGeometry(QRect(69, 0, 30, 18));
        notechannel->setFont(font3);
        notechannel->setFocusPolicy(Qt::StrongFocus);
        notechannel->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	font: 9px \"Tahoma\";\n"
"}"));
        notechannel->setFrame(true);
        notechannel->setAlignment(Qt::AlignCenter);
        notechannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notechannel->setMaximum(16);
        notedevice = new QComboBox(noteSetDeviceView);
        notedevice->addItem(QString());
        notedevice->addItem(QString());
        notedevice->setObjectName(QString::fromUtf8("notedevice"));
        notedevice->setGeometry(QRect(104, 0, 116, 18));
        notedevice->setFont(font3);
        notedevice->setFocusPolicy(Qt::StrongFocus);
        notedevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        notedevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
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
        notelivedevice->setFont(font);
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
        notelivedevice->setMaxVisibleItems(16);
        notelivedevice->setMinimumContentsLength(100);
        notelivedevice->setIconSize(QSize(8, 8));
        notelivevelocity = new QSpinBox(noteLiveDeviceView);
        notelivevelocity->setObjectName(QString::fromUtf8("notelivevelocity"));
        notelivevelocity->setGeometry(QRect(37, 0, 30, 18));
        notelivevelocity->setFont(font);
        notelivevelocity->setFocusPolicy(Qt::StrongFocus);
        notelivevelocity->setFrame(true);
        notelivevelocity->setAlignment(Qt::AlignCenter);
        notelivevelocity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notelivevelocity->setMaximum(127);
        notelivechannel = new QSpinBox(noteLiveDeviceView);
        notelivechannel->setObjectName(QString::fromUtf8("notelivechannel"));
        notelivechannel->setGeometry(QRect(69, 0, 30, 18));
        notelivechannel->setFont(font);
        notelivechannel->setFocusPolicy(Qt::StrongFocus);
        notelivechannel->setFrame(true);
        notelivechannel->setAlignment(Qt::AlignCenter);
        notelivechannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        notelivechannel->setMaximum(16);
        notelivenumber = new QSpinBox(noteLiveDeviceView);
        notelivenumber->setObjectName(QString::fromUtf8("notelivenumber"));
        notelivenumber->setEnabled(false);
        notelivenumber->setGeometry(QRect(5, 0, 30, 18));
        notelivenumber->setFont(font);
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
        cc->setFont(font);
        cc->setFocusPolicy(Qt::StrongFocus);
        cc->setFrame(true);
        cc->setAlignment(Qt::AlignCenter);
        cc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cc->setMaximum(127);
        controlchannel = new QSpinBox(controlDeviceView);
        controlchannel->setObjectName(QString::fromUtf8("controlchannel"));
        controlchannel->setGeometry(QRect(69, 0, 30, 18));
        controlchannel->setFont(font);
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
        controldevice->setFont(font);
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
        bankdevice->setFont(font);
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
        bankmsb->setFont(font);
        bankmsb->setFocusPolicy(Qt::StrongFocus);
        bankmsb->setFrame(true);
        bankmsb->setAlignment(Qt::AlignCenter);
        bankmsb->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bankmsb->setMaximum(127);
        bankchannel = new QSpinBox(bankDeviceView);
        bankchannel->setObjectName(QString::fromUtf8("bankchannel"));
        bankchannel->setGeometry(QRect(69, 0, 30, 18));
        bankchannel->setFont(font);
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
        programdevice->setFont(font);
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
        programchannel->setFont(font);
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
        bendchannel->setFont(font);
        bendchannel->setFocusPolicy(Qt::StrongFocus);
        bendchannel->setFrame(true);
        bendchannel->setAlignment(Qt::AlignCenter);
        bendchannel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bendchannel->setMaximum(16);
        benddevice = new QComboBox(bendDeviceView);
        benddevice->addItem(QString());
        benddevice->addItem(QString());
        benddevice->setObjectName(QString::fromUtf8("benddevice"));
        benddevice->setGeometry(QRect(104, 0, 116, 18));
        benddevice->setFont(font);
        benddevice->setFocusPolicy(Qt::StrongFocus);
        benddevice->setContextMenuPolicy(Qt::DefaultContextMenu);
        benddevice->setStyleSheet(QString::fromUtf8("/*----------- QComboBox ------------*/\n"
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
        mmcdevice->setFont(font);
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
        mmcdeviceid->setFont(font);
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
        mmcfunction->setFont(font);
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
        aftertouchdevice->setFont(font);
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
        aftertouchchannel->setFont(font);
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
        polynote->setFont(font);
        polynote->setFocusPolicy(Qt::StrongFocus);
        polynote->setFrame(true);
        polynote->setAlignment(Qt::AlignCenter);
        polynote->setButtonSymbols(QAbstractSpinBox::NoButtons);
        polynote->setMaximum(127);
        polychannel = new QSpinBox(polyDeviceView);
        polychannel->setObjectName(QString::fromUtf8("polychannel"));
        polychannel->setGeometry(QRect(69, 0, 30, 18));
        polychannel->setFont(font);
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
        polydevice->setFont(font);
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
        label_13 = new QLabel(navModlineForm);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(34, 1, 21, 16));
        label_13->setAlignment(Qt::AlignCenter);
        deviceViewLabels = new QStackedWidget(navModlineForm);
        deviceViewLabels->setObjectName(QString::fromUtf8("deviceViewLabels"));
        deviceViewLabels->setGeometry(QRect(697, 1, 198, 18));
        deviceViewLabels->setStyleSheet(QString::fromUtf8("/* ------- QStackedWidget ---------*/\n"
"QStackedWidget\n"
"{\n"
"	border-left: none;\n"
"	border-right: none;\n"
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
        source = new QComboBox(navModlineForm);
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
        source->setGeometry(QRect(99, 18, 97, 18));
        source->setFont(font);
        source->setFocusPolicy(Qt::StrongFocus);
        source->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label_34 = new QLabel(navModlineForm);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(131, 1, 31, 16));
        label_34->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(navModlineForm);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(287, 1, 27, 16));
        label_37->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(navModlineForm);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(608, 1, 77, 16));
        label_45->setAlignment(Qt::AlignCenter);
        raw = new QSpinBox(navModlineForm);
        raw->setObjectName(QString::fromUtf8("raw"));
        raw->setGeometry(QRect(203, 18, 27, 18));
        raw->setFont(font);
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
        label_42 = new QLabel(navModlineForm);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(495, 1, 32, 16));
        label_42->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(navModlineForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(277, 18, 8, 18));
        label_2->setFont(font);
        table = new QComboBox(navModlineForm);
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->addItem(QString());
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(367, 18, 60, 18));
        table->setFont(font);
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
"	font: 7pt \"Tahoma\";\n"
"	padding-left: 3px;\n"
"	padding-right: 3px;\n"
"	min-width: 55px;\n"
"}\n"
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        gain = new QDoubleSpinBox(navModlineForm);
        gain->setObjectName(QString::fromUtf8("gain"));
        gain->setGeometry(QRect(245, 18, 29, 18));
        gain->setFont(font);
        gain->setFocusPolicy(Qt::StrongFocus);
        gain->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        gain->setAlignment(Qt::AlignCenter);
        gain->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gain->setMinimum(-127.000000000000000);
        gain->setMaximum(127.000000000000000);
        initmode = new QComboBox(navModlineForm);
        initmode->addItem(QString());
        initmode->addItem(QString());
        initmode->addItem(QString());
        initmode->setObjectName(QString::fromUtf8("initmode"));
        initmode->setGeometry(QRect(27, 18, 39, 18));
        initmode->setFont(font);
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
"\n"
"QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        initmode->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        initmode->setFrame(true);
        label_44 = new QLabel(navModlineForm);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(570, 1, 27, 16));
        label_44->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgba(255, 255, 255, 90);\n"
"}"));
        label_44->setAlignment(Qt::AlignCenter);
        label_48 = new QLabel(navModlineForm);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(940, 5, 20, 16));
        label_48->setStyleSheet(QString::fromUtf8("background: none;\n"
"image: url(:/resources/modline_led_display_arrow.png);"));
        modlinedisplayenable = new QRadioButton(navModlineForm);
        modlinedisplayenable->setObjectName(QString::fromUtf8("modlinedisplayenable"));
        modlinedisplayenable->setGeometry(QRect(944, 18, 20, 20));
        modlinedisplayenable->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label_4 = new QLabel(navModlineForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(914, 0, 20, 42));
        label_4->setStyleSheet(QString::fromUtf8("background: rgb(60, 60, 60);"));
        hide_border_bleed = new QLabel(navModlineForm);
        hide_border_bleed->setObjectName(QString::fromUtf8("hide_border_bleed"));
        hide_border_bleed->setEnabled(false);
        hide_border_bleed->setGeometry(QRect(916, 0, 10, 42));
        hide_border_bleed->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-right: 4px solid rgb(0,174,239);\n"
"}"));
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
        QWidget::setTabOrder(destination, modlinedisplayenable);
        QWidget::setTabOrder(modlinedisplayenable, notenumber);
        QWidget::setTabOrder(notenumber, notevelocity);
        QWidget::setTabOrder(notevelocity, notechannel);
        QWidget::setTabOrder(notechannel, notedevice);
        QWidget::setTabOrder(notedevice, notelivenumber);
        QWidget::setTabOrder(notelivenumber, notelivevelocity);
        QWidget::setTabOrder(notelivevelocity, notelivechannel);
        QWidget::setTabOrder(notelivechannel, notelivedevice);
        QWidget::setTabOrder(notelivedevice, cc);
        QWidget::setTabOrder(cc, controlchannel);
        QWidget::setTabOrder(controlchannel, controldevice);
        QWidget::setTabOrder(controldevice, bankmsb);
        QWidget::setTabOrder(bankmsb, bankchannel);
        QWidget::setTabOrder(bankchannel, bankdevice);
        QWidget::setTabOrder(bankdevice, programchannel);
        QWidget::setTabOrder(programchannel, programdevice);
        QWidget::setTabOrder(programdevice, bendchannel);
        QWidget::setTabOrder(bendchannel, benddevice);
        QWidget::setTabOrder(benddevice, mmcdeviceid);
        QWidget::setTabOrder(mmcdeviceid, mmcfunction);
        QWidget::setTabOrder(mmcfunction, mmcdevice);
        QWidget::setTabOrder(mmcdevice, oscroute);
        QWidget::setTabOrder(oscroute, aftertouchchannel);
        QWidget::setTabOrder(aftertouchchannel, aftertouchdevice);
        QWidget::setTabOrder(aftertouchdevice, polynote);
        QWidget::setTabOrder(polynote, polychannel);
        QWidget::setTabOrder(polychannel, polydevice);

        retranslateUi(navModlineForm);

        deviceViews->setCurrentIndex(8);
        deviceViewLabels->setCurrentIndex(9);


        QMetaObject::connectSlotsByName(navModlineForm);
    } // setupUi

    void retranslateUi(QWidget *navModlineForm)
    {
        navModlineForm->setWindowTitle(QCoreApplication::translate("navModlineForm", "Form", nullptr));
        label_33->setText(QCoreApplication::translate("navModlineForm", "Value", nullptr));
#if QT_CONFIG(tooltip)
        outputvalue->setToolTip(QCoreApplication::translate("navModlineForm", "Live display of the modline <br>data after the table, min/max, smoothing, and delay.<p>(Hosted mode only)", nullptr));
#endif // QT_CONFIG(tooltip)
        instanceLabel->setText(QCoreApplication::translate("navModlineForm", "#", nullptr));
#if QT_CONFIG(tooltip)
        result->setToolTip(QCoreApplication::translate("navModlineForm", "Live display of the modline <br>data after the gain and offset stage.<p>(Hosted mode only)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_41->setText(QCoreApplication::translate("navModlineForm", "Max", nullptr));
        label_3->setText(QCoreApplication::translate("navModlineForm", "=", nullptr));
        label_36->setText(QCoreApplication::translate("navModlineForm", "Gain", nullptr));
#if QT_CONFIG(tooltip)
        delay->setToolTip(QCoreApplication::translate("navModlineForm", "The amount of time (in milliseconds) to delay the modline data.<p><b>Example</b>: A delay of 2000 would delay any messages by two seconds.", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("navModlineForm", "x", nullptr));
        label_39->setText(QCoreApplication::translate("navModlineForm", "Table", nullptr));
#if QT_CONFIG(tooltip)
        min->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the minimum value that can be output (range: 0-127).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        offset->setToolTip(QCoreApplication::translate("navModlineForm", "Add the set amount <br>(use negative numbers to subtract).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        max->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the maximum value that can be output (range: 0-127).", nullptr));
#endif // QT_CONFIG(tooltip)
        label_35->setText(QCoreApplication::translate("navModlineForm", "Raw", nullptr));
        label_40->setText(QCoreApplication::translate("navModlineForm", "Min", nullptr));
        label_38->setText(QCoreApplication::translate("navModlineForm", "Result", nullptr));
#if QT_CONFIG(tooltip)
        slew->setToolTip(QCoreApplication::translate("navModlineForm", "The amount of time (in milliseconds) it takes to slide/interpolate to the next value<p>Smaller values can smooth out jumpy data, while larger values can create ramps between values.<p><b>Example</b>: A value of 127 going through the modline with a smoothing value of 3000 would result in a three second ramp up to 127.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        initvalue->setToolTip(QCoreApplication::translate("navModlineForm", "This value will be sent through the modline if an init mode is enabled.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_43->setText(QCoreApplication::translate("navModlineForm", "Delay", nullptr));
        destination->setItemText(0, QCoreApplication::translate("navModlineForm", "None", nullptr));
        destination->setItemText(1, QCoreApplication::translate("navModlineForm", "Note Set", nullptr));
        destination->setItemText(2, QCoreApplication::translate("navModlineForm", "Note Live", nullptr));
        destination->setItemText(3, QCoreApplication::translate("navModlineForm", "CC", nullptr));
        destination->setItemText(4, QCoreApplication::translate("navModlineForm", "Bank", nullptr));
        destination->setItemText(5, QCoreApplication::translate("navModlineForm", "Program", nullptr));
        destination->setItemText(6, QCoreApplication::translate("navModlineForm", "OSC", nullptr));
        destination->setItemText(7, QCoreApplication::translate("navModlineForm", "Pitch Bend", nullptr));
        destination->setItemText(8, QCoreApplication::translate("navModlineForm", "MMC", nullptr));
        destination->setItemText(9, QCoreApplication::translate("navModlineForm", "Aftertouch", nullptr));
        destination->setItemText(10, QCoreApplication::translate("navModlineForm", "Poly Aftertouch", nullptr));
        destination->setItemText(11, QCoreApplication::translate("navModlineForm", "X Inc Set", nullptr));
        destination->setItemText(12, QCoreApplication::translate("navModlineForm", "Y Inc Set", nullptr));

#if QT_CONFIG(tooltip)
        destination->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the type of MIDI message to output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        enable->setToolTip(QCoreApplication::translate("navModlineForm", "Enables/Disables the modline.", nullptr));
#endif // QT_CONFIG(tooltip)
        enable->setText(QString());
#if QT_CONFIG(tooltip)
        notenumber->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI note number to output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notevelocity->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the velocity for the MIDI note.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notechannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        notedevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        notedevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        notedevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        notelivedevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        notelivedevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        notelivedevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notelivevelocity->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the velocity for the note messages.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        notelivechannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cc->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the CC number to send the modline data on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        controlchannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        controldevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        controldevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        controldevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        bankdevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        bankdevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        bankdevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bankmsb->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MSB for the bank message. The LSB will be <br>filled in by whatever value is coming through the modline.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bankchannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        programdevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        programdevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        programdevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        programchannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bendchannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        benddevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        benddevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        benddevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        mmcdevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        mmcdevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        mmcdevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mmcdeviceid->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the device ID for the receiving MMC device.", nullptr));
#endif // QT_CONFIG(tooltip)
        mmcfunction->setItemText(0, QCoreApplication::translate("navModlineForm", "Stop", nullptr));
        mmcfunction->setItemText(1, QCoreApplication::translate("navModlineForm", "Play", nullptr));
        mmcfunction->setItemText(2, QCoreApplication::translate("navModlineForm", "Deferred Play", nullptr));
        mmcfunction->setItemText(3, QCoreApplication::translate("navModlineForm", "Fast Forward", nullptr));
        mmcfunction->setItemText(4, QCoreApplication::translate("navModlineForm", "Rewind", nullptr));
        mmcfunction->setItemText(5, QCoreApplication::translate("navModlineForm", "Punch In", nullptr));
        mmcfunction->setItemText(6, QCoreApplication::translate("navModlineForm", "Punch Out", nullptr));
        mmcfunction->setItemText(7, QCoreApplication::translate("navModlineForm", "Pause", nullptr));

#if QT_CONFIG(tooltip)
        mmcfunction->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the type of MMC message to output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        oscroute->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the routing prefix for the OSC message.", nullptr));
#endif // QT_CONFIG(tooltip)
        aftertouchdevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        aftertouchdevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        aftertouchdevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        aftertouchchannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        polynote->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the note number to send the polyphonic aftertouch for.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        polychannel->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI channel to output on.", nullptr));
#endif // QT_CONFIG(tooltip)
        polydevice->setItemText(0, QCoreApplication::translate("navModlineForm", "SoftStep Expander", nullptr));
        polydevice->setItemText(1, QCoreApplication::translate("navModlineForm", "SSCOM Port 1", nullptr));

#if QT_CONFIG(tooltip)
        polydevice->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the MIDI port to which the message will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("navModlineForm", "Mode", nullptr));
        label_6->setText(QCoreApplication::translate("navModlineForm", "Vel", nullptr));
        label_7->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_8->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_10->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_11->setText(QCoreApplication::translate("navModlineForm", "Vel", nullptr));
        label_12->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_14->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_15->setText(QCoreApplication::translate("navModlineForm", "CC#", nullptr));
        label_16->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_17->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_18->setText(QCoreApplication::translate("navModlineForm", "MSB", nullptr));
        label_19->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_20->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_22->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_23->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_25->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_9->setText(QCoreApplication::translate("navModlineForm", "ID", nullptr));
        label_24->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_26->setText(QCoreApplication::translate("navModlineForm", "Function", nullptr));
        label_21->setText(QCoreApplication::translate("navModlineForm", "Output Prefix", nullptr));
        label_28->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_30->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        label_29->setText(QCoreApplication::translate("navModlineForm", "Output Port", nullptr));
        label_31->setText(QCoreApplication::translate("navModlineForm", "Note", nullptr));
        label_32->setText(QCoreApplication::translate("navModlineForm", "Ch", nullptr));
        source->setItemText(0, QCoreApplication::translate("navModlineForm", "None", nullptr));
        source->setItemText(1, QCoreApplication::translate("navModlineForm", "Nav Y", nullptr));
        source->setItemText(2, QCoreApplication::translate("navModlineForm", "Nav Y Decade", nullptr));
        source->setItemText(3, QCoreApplication::translate("navModlineForm", "Nav Y Inc-Dec", nullptr));
        source->setItemText(4, QCoreApplication::translate("navModlineForm", "Nav N Foot On", nullptr));
        source->setItemText(5, QCoreApplication::translate("navModlineForm", "Nav S Foot On", nullptr));
        source->setItemText(6, QCoreApplication::translate("navModlineForm", "Nav N Foot Off", nullptr));
        source->setItemText(7, QCoreApplication::translate("navModlineForm", "Nav S Foot Off", nullptr));
        source->setItemText(8, QCoreApplication::translate("navModlineForm", "Nav N Trig", nullptr));
        source->setItemText(9, QCoreApplication::translate("navModlineForm", "Nav N Trig Fast", nullptr));
        source->setItemText(10, QCoreApplication::translate("navModlineForm", "Nav N Trig Dbl", nullptr));
        source->setItemText(11, QCoreApplication::translate("navModlineForm", "Nav N Trig Long", nullptr));
        source->setItemText(12, QCoreApplication::translate("navModlineForm", "Nav S Trig", nullptr));
        source->setItemText(13, QCoreApplication::translate("navModlineForm", "Nav S Trig Fast", nullptr));
        source->setItemText(14, QCoreApplication::translate("navModlineForm", "Nav S Trig Dbl", nullptr));
        source->setItemText(15, QCoreApplication::translate("navModlineForm", "Nav S Trig Long", nullptr));
        source->setItemText(16, QCoreApplication::translate("navModlineForm", "Pedal", nullptr));
        source->setItemText(17, QCoreApplication::translate("navModlineForm", "MIDI A", nullptr));
        source->setItemText(18, QCoreApplication::translate("navModlineForm", "MIDI B", nullptr));
        source->setItemText(19, QCoreApplication::translate("navModlineForm", "MIDI C", nullptr));
        source->setItemText(20, QCoreApplication::translate("navModlineForm", "MIDI D", nullptr));
        source->setItemText(21, QCoreApplication::translate("navModlineForm", "MIDI E", nullptr));
        source->setItemText(22, QCoreApplication::translate("navModlineForm", "MIDI F", nullptr));
        source->setItemText(23, QCoreApplication::translate("navModlineForm", "MIDI G", nullptr));
        source->setItemText(24, QCoreApplication::translate("navModlineForm", "MIDI H", nullptr));

#if QT_CONFIG(tooltip)
        source->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the type of sensor data coming from the SoftStep.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_34->setText(QCoreApplication::translate("navModlineForm", "Source", nullptr));
        label_37->setText(QCoreApplication::translate("navModlineForm", "Offset", nullptr));
        label_45->setText(QCoreApplication::translate("navModlineForm", "Message Type", nullptr));
#if QT_CONFIG(tooltip)
        raw->setToolTip(QCoreApplication::translate("navModlineForm", "Live display of sensor data <br>coming from SoftStep.<p>(Hosted mode only)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_42->setText(QCoreApplication::translate("navModlineForm", "Smooth", nullptr));
        label_2->setText(QCoreApplication::translate("navModlineForm", "+", nullptr));
        table->setItemText(0, QCoreApplication::translate("navModlineForm", "Lin", nullptr));
        table->setItemText(1, QCoreApplication::translate("navModlineForm", "Sin", nullptr));
        table->setItemText(2, QCoreApplication::translate("navModlineForm", "Cos", nullptr));
        table->setItemText(3, QCoreApplication::translate("navModlineForm", "Exp", nullptr));
        table->setItemText(4, QCoreApplication::translate("navModlineForm", "Log", nullptr));
        table->setItemText(5, QCoreApplication::translate("navModlineForm", "Custom", nullptr));
        table->setItemText(6, QCoreApplication::translate("navModlineForm", "Toggle", nullptr));

#if QT_CONFIG(tooltip)
        table->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the type of curve to apply to the modline data.<p>Also used to set up toggles and interact with the key counter.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        gain->setToolTip(QCoreApplication::translate("navModlineForm", "Multiply by the set amount.", nullptr));
#endif // QT_CONFIG(tooltip)
        initmode->setItemText(0, QCoreApplication::translate("navModlineForm", "None", nullptr));
        initmode->setItemText(1, QCoreApplication::translate("navModlineForm", "Once", nullptr));
        initmode->setItemText(2, QCoreApplication::translate("navModlineForm", "Always", nullptr));

#if QT_CONFIG(tooltip)
        initmode->setToolTip(QCoreApplication::translate("navModlineForm", "Sets the init mode.<p><b>None</b>: Off. No init value will be sent.<p><b>Once</b>: Outputs the set init value the first time this preset is selected/loaded.<p><b>Always</b>: Outputs the set init value every time this preset is selected/loaded.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_44->setText(QCoreApplication::translate("navModlineForm", "Value", nullptr));
        label_48->setText(QString());
#if QT_CONFIG(tooltip)
        modlinedisplayenable->setToolTip(QCoreApplication::translate("navModlineForm", "This selects which modline's <br>data will be used for the display parameters above. Only one may be selected per key.", nullptr));
#endif // QT_CONFIG(tooltip)
        modlinedisplayenable->setText(QString());
        label_4->setText(QString());
        hide_border_bleed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class navModlineForm: public Ui_navModlineForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVMODLINEFORMWIN_H
