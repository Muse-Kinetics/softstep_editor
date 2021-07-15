// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'setlistFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETLISTFORMWIN_H
#define UI_SETLISTFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setlistForm
{
public:
    QLabel *titlelabel;
    QCheckBox *enable1;
    QCheckBox *enable2;
    QCheckBox *enable3;
    QCheckBox *enable4;
    QCheckBox *enable5;
    QCheckBox *enable6;
    QCheckBox *enable7;
    QCheckBox *enable8;
    QCheckBox *enable9;
    QCheckBox *enable10;
    QCheckBox *enable11;
    QCheckBox *enable12;
    QCheckBox *enable13;
    QCheckBox *enable14;
    QCheckBox *enable15;
    QCheckBox *enable16;
    QComboBox *setlistmenu1;
    QComboBox *setlistmenu2;
    QComboBox *setlistmenu3;
    QComboBox *setlistmenu4;
    QComboBox *setlistmenu5;
    QComboBox *setlistmenu6;
    QComboBox *setlistmenu7;
    QComboBox *setlistmenu8;
    QComboBox *setlistmenu9;
    QComboBox *setlistmenu10;
    QComboBox *setlistmenu11;
    QComboBox *setlistmenu12;
    QComboBox *setlistmenu13;
    QComboBox *setlistmenu14;
    QComboBox *setlistmenu15;
    QComboBox *setlistmenu16;

    void setupUi(QWidget *setlistForm)
    {
        if (setlistForm->objectName().isEmpty())
            setlistForm->setObjectName(QString::fromUtf8("setlistForm"));
        setlistForm->resize(244, 448);
        setlistForm->setMinimumSize(QSize(200, 445));
        setlistForm->setMaximumSize(QSize(500, 500));
        setlistForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:	 rgb(60, 60, 60);\n"
"	border: 3px solid rgba(0,174,239,255);\n"
"}\n"
"\n"
"/* ------- QStackedWidget ---------*/\n"
"QStackedWidget\n"
"{\n"
"	border-left: 2px solid rgb(0,174,239);\n"
"	border-right: 2px solid rgb(0,174,239);\n"
"}\n"
"\n"
"/* ---------- QLabels ------------*/\n"
"QLabel\n"
"{\n"
"	background:		rgba(0,0,0,0);\n"
"	color: 				white;\n"
"	font: 				10pt \"Corbel\";\n"
"	border:				none;\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	border:				none;\n"
"}  \n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 10pt \"Corbel\";\n"
"	background:rgba(0,174,239,0);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"	border: none;\n"
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
"	font: 8pt \"Corbel\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background: rgb(40, 40, 40);\n"
"	color: white;\n"
"	padding: 3px 5px 3px 5px\n"
" }\n"
"\n"
"QComboBox QListVi"
                        "ew\n"
"{\n"
"	background-color: rgb(40, 40, 40);\n"
"	border: transparent;\n"
"	font: 8pt \"Corbel\";\n"
"	color: white;\n"
"	padding-left: 5px;\n"
"	min-width: 100px;\n"
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
"	width: 14px;\n"
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
"	image: url(:/resources/setlist_combobox_menu_arrows.png)\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	fo"
                        "nt: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	min-width: 16px;\n"
"}"));
        titlelabel = new QLabel(setlistForm);
        titlelabel->setObjectName(QString::fromUtf8("titlelabel"));
        titlelabel->setGeometry(QRect(10, 6, 223, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setBold(true);
        font.setItalic(false);
        titlelabel->setFont(font);
        titlelabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"	{\n"
"		font: bold 16px;\n"
"		font.underline: 1;\n"
"		border-bottom: 2px solid white;\n"
"	}"));
        enable1 = new QCheckBox(setlistForm);
        enable1->setObjectName(QString::fromUtf8("enable1"));
        enable1->setGeometry(QRect(10, 40, 22, 22));
        enable1->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable1_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable1_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable1_off.png);\n"
"}\n"
""));
        enable2 = new QCheckBox(setlistForm);
        enable2->setObjectName(QString::fromUtf8("enable2"));
        enable2->setGeometry(QRect(10, 65, 22, 22));
        enable2->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable2_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable2_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable2_off.png);\n"
"}\n"
""));
        enable3 = new QCheckBox(setlistForm);
        enable3->setObjectName(QString::fromUtf8("enable3"));
        enable3->setGeometry(QRect(10, 90, 22, 22));
        enable3->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable3_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable3_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable3_off.png);\n"
"}\n"
""));
        enable4 = new QCheckBox(setlistForm);
        enable4->setObjectName(QString::fromUtf8("enable4"));
        enable4->setGeometry(QRect(10, 115, 22, 22));
        enable4->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable4_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable4_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable4_off.png);\n"
"}\n"
""));
        enable5 = new QCheckBox(setlistForm);
        enable5->setObjectName(QString::fromUtf8("enable5"));
        enable5->setGeometry(QRect(10, 140, 22, 22));
        enable5->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable5_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable5_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable5_off.png);\n"
"}\n"
""));
        enable6 = new QCheckBox(setlistForm);
        enable6->setObjectName(QString::fromUtf8("enable6"));
        enable6->setGeometry(QRect(10, 165, 22, 22));
        enable6->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable6_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable6_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable6_off.png);\n"
"}\n"
""));
        enable7 = new QCheckBox(setlistForm);
        enable7->setObjectName(QString::fromUtf8("enable7"));
        enable7->setGeometry(QRect(10, 190, 22, 22));
        enable7->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable7_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable7_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable7_off.png);\n"
"}\n"
""));
        enable8 = new QCheckBox(setlistForm);
        enable8->setObjectName(QString::fromUtf8("enable8"));
        enable8->setGeometry(QRect(10, 215, 22, 22));
        enable8->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable8_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable8_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable8_off.png);\n"
"}\n"
""));
        enable9 = new QCheckBox(setlistForm);
        enable9->setObjectName(QString::fromUtf8("enable9"));
        enable9->setGeometry(QRect(10, 240, 22, 22));
        enable9->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable9_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setli"
                        "stWindow_enable9_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable9_off.png);\n"
"}\n"
""));
        enable10 = new QCheckBox(setlistForm);
        enable10->setObjectName(QString::fromUtf8("enable10"));
        enable10->setGeometry(QRect(10, 265, 22, 22));
        enable10->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable10_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable10_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable10_off.png);\n"
"}\n"
""));
        enable11 = new QCheckBox(setlistForm);
        enable11->setObjectName(QString::fromUtf8("enable11"));
        enable11->setGeometry(QRect(10, 290, 22, 22));
        enable11->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable11_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable11_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable11_off.png);\n"
"}\n"
""));
        enable12 = new QCheckBox(setlistForm);
        enable12->setObjectName(QString::fromUtf8("enable12"));
        enable12->setGeometry(QRect(10, 315, 22, 22));
        enable12->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable12_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable12_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable12_off.png);\n"
"}\n"
""));
        enable13 = new QCheckBox(setlistForm);
        enable13->setObjectName(QString::fromUtf8("enable13"));
        enable13->setGeometry(QRect(10, 340, 22, 22));
        enable13->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable13_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable13_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable13_off.png);\n"
"}\n"
""));
        enable14 = new QCheckBox(setlistForm);
        enable14->setObjectName(QString::fromUtf8("enable14"));
        enable14->setGeometry(QRect(10, 365, 22, 22));
        enable14->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable14_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable14_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable14_off.png);\n"
"}\n"
""));
        enable15 = new QCheckBox(setlistForm);
        enable15->setObjectName(QString::fromUtf8("enable15"));
        enable15->setGeometry(QRect(10, 390, 22, 22));
        enable15->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable15_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable15_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable15_off.png);\n"
"}\n"
""));
        enable16 = new QCheckBox(setlistForm);
        enable16->setObjectName(QString::fromUtf8("enable16"));
        enable16->setGeometry(QRect(10, 415, 22, 22));
        enable16->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
"    image: url(:/resources/setlistWindow_enable16_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed:focus\n"
"{\n"
"    image: url(:/resources"
                        "/setlistWindow_enable16_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed:focus\n"
"{\n"
"    image: url(:/resources/setlistWindow_enable16_off.png);\n"
"}\n"
""));
        setlistmenu1 = new QComboBox(setlistForm);
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->addItem(QString());
        setlistmenu1->setObjectName(QString::fromUtf8("setlistmenu1"));
        setlistmenu1->setGeometry(QRect(37, 38, 195, 22));
        setlistmenu1->setAutoFillBackground(false);
        setlistmenu1->setStyleSheet(QString::fromUtf8(""));
        setlistmenu1->setEditable(false);
        setlistmenu1->setFrame(true);
        setlistmenu2 = new QComboBox(setlistForm);
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->addItem(QString());
        setlistmenu2->setObjectName(QString::fromUtf8("setlistmenu2"));
        setlistmenu2->setGeometry(QRect(37, 63, 195, 22));
        setlistmenu2->setAutoFillBackground(false);
        setlistmenu2->setStyleSheet(QString::fromUtf8(""));
        setlistmenu2->setEditable(false);
        setlistmenu2->setFrame(true);
        setlistmenu3 = new QComboBox(setlistForm);
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->addItem(QString());
        setlistmenu3->setObjectName(QString::fromUtf8("setlistmenu3"));
        setlistmenu3->setGeometry(QRect(37, 88, 195, 22));
        setlistmenu3->setAutoFillBackground(false);
        setlistmenu3->setStyleSheet(QString::fromUtf8(""));
        setlistmenu3->setEditable(false);
        setlistmenu3->setFrame(true);
        setlistmenu4 = new QComboBox(setlistForm);
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->addItem(QString());
        setlistmenu4->setObjectName(QString::fromUtf8("setlistmenu4"));
        setlistmenu4->setGeometry(QRect(37, 113, 195, 22));
        setlistmenu4->setAutoFillBackground(false);
        setlistmenu4->setStyleSheet(QString::fromUtf8(""));
        setlistmenu4->setEditable(false);
        setlistmenu4->setFrame(true);
        setlistmenu5 = new QComboBox(setlistForm);
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->addItem(QString());
        setlistmenu5->setObjectName(QString::fromUtf8("setlistmenu5"));
        setlistmenu5->setGeometry(QRect(37, 138, 195, 22));
        setlistmenu5->setAutoFillBackground(false);
        setlistmenu5->setStyleSheet(QString::fromUtf8(""));
        setlistmenu5->setEditable(false);
        setlistmenu5->setFrame(true);
        setlistmenu6 = new QComboBox(setlistForm);
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->addItem(QString());
        setlistmenu6->setObjectName(QString::fromUtf8("setlistmenu6"));
        setlistmenu6->setGeometry(QRect(37, 163, 195, 22));
        setlistmenu6->setAutoFillBackground(false);
        setlistmenu6->setStyleSheet(QString::fromUtf8(""));
        setlistmenu6->setEditable(false);
        setlistmenu6->setFrame(true);
        setlistmenu7 = new QComboBox(setlistForm);
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->addItem(QString());
        setlistmenu7->setObjectName(QString::fromUtf8("setlistmenu7"));
        setlistmenu7->setGeometry(QRect(37, 188, 195, 22));
        setlistmenu7->setAutoFillBackground(false);
        setlistmenu7->setStyleSheet(QString::fromUtf8(""));
        setlistmenu7->setEditable(false);
        setlistmenu7->setFrame(true);
        setlistmenu8 = new QComboBox(setlistForm);
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->addItem(QString());
        setlistmenu8->setObjectName(QString::fromUtf8("setlistmenu8"));
        setlistmenu8->setGeometry(QRect(37, 213, 195, 22));
        setlistmenu8->setAutoFillBackground(false);
        setlistmenu8->setStyleSheet(QString::fromUtf8(""));
        setlistmenu8->setEditable(false);
        setlistmenu8->setFrame(true);
        setlistmenu9 = new QComboBox(setlistForm);
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->addItem(QString());
        setlistmenu9->setObjectName(QString::fromUtf8("setlistmenu9"));
        setlistmenu9->setGeometry(QRect(37, 238, 195, 22));
        setlistmenu9->setAutoFillBackground(false);
        setlistmenu9->setStyleSheet(QString::fromUtf8(""));
        setlistmenu9->setEditable(false);
        setlistmenu9->setFrame(true);
        setlistmenu10 = new QComboBox(setlistForm);
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->addItem(QString());
        setlistmenu10->setObjectName(QString::fromUtf8("setlistmenu10"));
        setlistmenu10->setGeometry(QRect(37, 263, 195, 22));
        setlistmenu10->setAutoFillBackground(false);
        setlistmenu10->setStyleSheet(QString::fromUtf8(""));
        setlistmenu10->setEditable(false);
        setlistmenu10->setFrame(true);
        setlistmenu11 = new QComboBox(setlistForm);
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->addItem(QString());
        setlistmenu11->setObjectName(QString::fromUtf8("setlistmenu11"));
        setlistmenu11->setGeometry(QRect(37, 288, 195, 22));
        setlistmenu11->setAutoFillBackground(false);
        setlistmenu11->setStyleSheet(QString::fromUtf8(""));
        setlistmenu11->setEditable(false);
        setlistmenu11->setFrame(true);
        setlistmenu12 = new QComboBox(setlistForm);
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->addItem(QString());
        setlistmenu12->setObjectName(QString::fromUtf8("setlistmenu12"));
        setlistmenu12->setGeometry(QRect(37, 313, 195, 22));
        setlistmenu12->setAutoFillBackground(false);
        setlistmenu12->setStyleSheet(QString::fromUtf8(""));
        setlistmenu12->setEditable(false);
        setlistmenu12->setFrame(true);
        setlistmenu13 = new QComboBox(setlistForm);
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->addItem(QString());
        setlistmenu13->setObjectName(QString::fromUtf8("setlistmenu13"));
        setlistmenu13->setGeometry(QRect(37, 338, 195, 22));
        setlistmenu13->setAutoFillBackground(false);
        setlistmenu13->setStyleSheet(QString::fromUtf8(""));
        setlistmenu13->setEditable(false);
        setlistmenu13->setFrame(true);
        setlistmenu14 = new QComboBox(setlistForm);
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->addItem(QString());
        setlistmenu14->setObjectName(QString::fromUtf8("setlistmenu14"));
        setlistmenu14->setGeometry(QRect(37, 363, 195, 22));
        setlistmenu14->setAutoFillBackground(false);
        setlistmenu14->setStyleSheet(QString::fromUtf8(""));
        setlistmenu14->setEditable(false);
        setlistmenu14->setFrame(true);
        setlistmenu15 = new QComboBox(setlistForm);
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->addItem(QString());
        setlistmenu15->setObjectName(QString::fromUtf8("setlistmenu15"));
        setlistmenu15->setGeometry(QRect(37, 388, 195, 22));
        setlistmenu15->setAutoFillBackground(false);
        setlistmenu15->setStyleSheet(QString::fromUtf8(""));
        setlistmenu15->setEditable(false);
        setlistmenu15->setFrame(true);
        setlistmenu16 = new QComboBox(setlistForm);
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->addItem(QString());
        setlistmenu16->setObjectName(QString::fromUtf8("setlistmenu16"));
        setlistmenu16->setGeometry(QRect(37, 413, 195, 22));
        setlistmenu16->setAutoFillBackground(false);
        setlistmenu16->setStyleSheet(QString::fromUtf8(""));
        setlistmenu16->setEditable(false);
        setlistmenu16->setFrame(true);

        retranslateUi(setlistForm);

        QMetaObject::connectSlotsByName(setlistForm);
    } // setupUi

    void retranslateUi(QWidget *setlistForm)
    {
        setlistForm->setWindowTitle(QCoreApplication::translate("setlistForm", "Setlist", nullptr));
        titlelabel->setText(QCoreApplication::translate("setlistForm", "SETLIST", nullptr));
        enable1->setText(QString());
        enable2->setText(QString());
        enable3->setText(QString());
        enable4->setText(QString());
        enable5->setText(QString());
        enable6->setText(QString());
        enable7->setText(QString());
        enable8->setText(QString());
        enable9->setText(QString());
        enable10->setText(QString());
        enable11->setText(QString());
        enable12->setText(QString());
        enable13->setText(QString());
        enable14->setText(QString());
        enable15->setText(QString());
        enable16->setText(QString());
        setlistmenu1->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu1->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu1->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu1->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu1->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu1->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu1->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu1->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu1->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu1->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu1->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu2->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu2->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu2->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu2->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu2->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu2->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu2->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu2->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu2->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu2->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu2->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu3->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu3->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu3->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu3->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu3->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu3->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu3->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu3->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu3->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu3->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu3->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu4->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu4->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu4->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu4->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu4->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu4->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu4->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu4->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu4->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu4->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu4->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu5->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu5->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu5->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu5->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu5->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu5->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu5->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu5->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu5->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu5->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu5->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu6->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu6->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu6->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu6->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu6->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu6->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu6->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu6->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu6->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu6->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu6->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu7->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu7->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu7->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu7->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu7->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu7->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu7->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu7->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu7->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu7->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu7->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu8->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu8->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu8->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu8->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu8->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu8->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu8->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu8->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu8->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu8->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu8->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu9->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu9->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu9->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu9->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu9->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu9->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu9->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu9->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu9->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu9->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu9->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu10->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu10->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu10->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu10->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu10->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu10->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu10->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu10->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu10->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu10->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu10->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu11->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu11->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu11->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu11->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu11->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu11->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu11->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu11->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu11->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu11->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu11->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu12->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu12->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu12->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu12->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu12->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu12->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu12->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu12->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu12->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu12->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu12->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu13->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu13->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu13->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu13->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu13->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu13->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu13->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu13->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu13->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu13->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu13->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu14->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu14->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu14->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu14->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu14->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu14->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu14->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu14->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu14->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu14->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu14->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu15->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu15->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu15->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu15->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu15->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu15->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu15->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu15->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu15->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu15->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu15->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

        setlistmenu16->setItemText(0, QCoreApplication::translate("setlistForm", "PRESET_NAME_HERE", nullptr));
        setlistmenu16->setItemText(1, QCoreApplication::translate("setlistForm", "1", nullptr));
        setlistmenu16->setItemText(2, QCoreApplication::translate("setlistForm", "2", nullptr));
        setlistmenu16->setItemText(3, QCoreApplication::translate("setlistForm", "3", nullptr));
        setlistmenu16->setItemText(4, QCoreApplication::translate("setlistForm", "4", nullptr));
        setlistmenu16->setItemText(5, QCoreApplication::translate("setlistForm", "5", nullptr));
        setlistmenu16->setItemText(6, QCoreApplication::translate("setlistForm", "6", nullptr));
        setlistmenu16->setItemText(7, QCoreApplication::translate("setlistForm", "7", nullptr));
        setlistmenu16->setItemText(8, QCoreApplication::translate("setlistForm", "8", nullptr));
        setlistmenu16->setItemText(9, QCoreApplication::translate("setlistForm", "9", nullptr));
        setlistmenu16->setItemText(10, QCoreApplication::translate("setlistForm", "10", nullptr));

    } // retranslateUi

};

namespace Ui {
    class setlistForm: public Ui_setlistForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLISTFORMWIN_H
