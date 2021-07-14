// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'settingsForm.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSFORM_H
#define UI_SETTINGSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_19;
    QSpinBox *navEastOnThresh;
    QLabel *label_20;
    QSpinBox *navNorthOnThresh;
    QLabel *label_21;
    QSpinBox *navSouthOnThresh;
    QSpinBox *navEastOffThresh;
    QLabel *label_22;
    QLabel *label_23;
    QSpinBox *navNorthOffThresh;
    QSpinBox *navWestOffThresh;
    QLabel *label_24;
    QSpinBox *navSouthOffThresh;
    QLabel *label_25;
    QSpinBox *navWestOnThresh;
    QLabel *label_26;
    QSpinBox *navAccelY;
    QFrame *settingsFrame;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_27;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_2;
    QSpinBox *allAccelY;
    QSpinBox *allOffThresh;
    QSpinBox *allOnThresh;
    QSpinBox *key1OnThresh;
    QSpinBox *key1OffThresh;
    QSpinBox *key1AccelY;
    QSpinBox *key2OnThresh;
    QSpinBox *key2OffThresh;
    QSpinBox *key2AccelY;
    QSpinBox *key3OnThresh;
    QSpinBox *key3OffThresh;
    QSpinBox *key3AccelY;
    QSpinBox *key4OnThresh;
    QSpinBox *key4OffThresh;
    QSpinBox *key4AccelY;
    QSpinBox *key5OnThresh;
    QSpinBox *key5OffThresh;
    QSpinBox *key5AccelY;
    QSpinBox *key6OnThresh;
    QSpinBox *key6OffThresh;
    QSpinBox *key6AccelY;
    QSpinBox *key7OnThresh;
    QSpinBox *key7OffThresh;
    QSpinBox *key7AccelY;
    QSpinBox *key8OnThresh;
    QSpinBox *key8OffThresh;
    QSpinBox *key8AccelY;
    QSpinBox *key9OnThresh;
    QSpinBox *key9OffThresh;
    QSpinBox *key9AccelY;
    QSpinBox *key10OffThresh;
    QSpinBox *key10AccelY;
    QLabel *label_31;
    QLabel *label;
    QCheckBox *sensorResponseMax;
    QCheckBox *sensorResponseAverage;
    QCheckBox *multipleKeyMode;
    QCheckBox *adjacentKeyMode;
    QSpinBox *key10OnThresh;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(350, 460);
        Form->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"	background-color: rgba(0, 0, 0, 255);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
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
"	font: 10pt \"Futura\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEd"
                        "it:focus\n"
"{\n"
"	font: 10pt \"Futura\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 2px solid white;\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 10pt \"Futura\";\n"
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
"\n"
"/* ------- QStackedWidget ---------*/\n"
"QStackedWidget\n"
"{\n"
"border-top: 1px solid white;\n"
"background: black;\n"
"}\n"
"\n"
""));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(15, 128, 16, 18));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(15, 150, 16, 18));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(15, 173, 16, 18));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Form);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(15, 196, 16, 18));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Form);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(15, 216, 16, 18));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Form);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(15, 238, 16, 18));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Form);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(15, 259, 16, 18));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Form);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(15, 282, 16, 18));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(Form);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(15, 304, 16, 18));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(Form);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(15, 327, 16, 18));
        label_12->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(Form);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 360, 255, 16));
        label_19->setStyleSheet(QString::fromUtf8("font: bold 12px;\n"
""));
        label_19->setAlignment(Qt::AlignCenter);
        navEastOnThresh = new QSpinBox(Form);
        navEastOnThresh->setObjectName(QString::fromUtf8("navEastOnThresh"));
        navEastOnThresh->setGeometry(QRect(150, 400, 40, 18));
        navEastOnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navEastOnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navEastOnThresh->setMaximum(127);
        label_20 = new QLabel(Form);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(110, 380, 31, 18));
        label_20->setAlignment(Qt::AlignCenter);
        label_20->setWordWrap(true);
        navNorthOnThresh = new QSpinBox(Form);
        navNorthOnThresh->setObjectName(QString::fromUtf8("navNorthOnThresh"));
        navNorthOnThresh->setGeometry(QRect(60, 400, 40, 18));
        navNorthOnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navNorthOnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navNorthOnThresh->setMaximum(127);
        label_21 = new QLabel(Form);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(154, 380, 31, 18));
        label_21->setAlignment(Qt::AlignCenter);
        label_21->setWordWrap(true);
        navSouthOnThresh = new QSpinBox(Form);
        navSouthOnThresh->setObjectName(QString::fromUtf8("navSouthOnThresh"));
        navSouthOnThresh->setGeometry(QRect(105, 400, 40, 18));
        navSouthOnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navSouthOnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navSouthOnThresh->setMaximum(127);
        navEastOffThresh = new QSpinBox(Form);
        navEastOffThresh->setObjectName(QString::fromUtf8("navEastOffThresh"));
        navEastOffThresh->setGeometry(QRect(150, 422, 40, 18));
        navEastOffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navEastOffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navEastOffThresh->setMaximum(127);
        label_22 = new QLabel(Form);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(64, 380, 31, 18));
        label_22->setAlignment(Qt::AlignCenter);
        label_22->setWordWrap(true);
        label_23 = new QLabel(Form);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(15, 400, 41, 18));
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        navNorthOffThresh = new QSpinBox(Form);
        navNorthOffThresh->setObjectName(QString::fromUtf8("navNorthOffThresh"));
        navNorthOffThresh->setGeometry(QRect(60, 422, 40, 18));
        navNorthOffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navNorthOffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navNorthOffThresh->setMaximum(127);
        navWestOffThresh = new QSpinBox(Form);
        navWestOffThresh->setObjectName(QString::fromUtf8("navWestOffThresh"));
        navWestOffThresh->setGeometry(QRect(195, 422, 40, 18));
        navWestOffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navWestOffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navWestOffThresh->setMaximum(127);
        label_24 = new QLabel(Form);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(15, 422, 51, 18));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        navSouthOffThresh = new QSpinBox(Form);
        navSouthOffThresh->setObjectName(QString::fromUtf8("navSouthOffThresh"));
        navSouthOffThresh->setGeometry(QRect(105, 422, 40, 18));
        navSouthOffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navSouthOffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navSouthOffThresh->setMaximum(127);
        label_25 = new QLabel(Form);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(200, 380, 31, 18));
        label_25->setAlignment(Qt::AlignCenter);
        label_25->setWordWrap(true);
        navWestOnThresh = new QSpinBox(Form);
        navWestOnThresh->setObjectName(QString::fromUtf8("navWestOnThresh"));
        navWestOnThresh->setGeometry(QRect(195, 400, 40, 18));
        navWestOnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navWestOnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navWestOnThresh->setMaximum(127);
        label_26 = new QLabel(Form);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(240, 380, 41, 18));
        label_26->setAlignment(Qt::AlignCenter);
        label_26->setWordWrap(true);
        navAccelY = new QSpinBox(Form);
        navAccelY->setObjectName(QString::fromUtf8("navAccelY"));
        navAccelY->setGeometry(QRect(241, 410, 40, 18));
        navAccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        navAccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        navAccelY->setMaximum(127);
        settingsFrame = new QFrame(Form);
        settingsFrame->setObjectName(QString::fromUtf8("settingsFrame"));
        settingsFrame->setGeometry(QRect(0, 0, 350, 460));
        settingsFrame->setFocusPolicy(Qt::NoFocus);
        settingsFrame->setStyleSheet(QString::fromUtf8(""));
        settingsFrame->setFrameShape(QFrame::StyledPanel);
        settingsFrame->setFrameShadow(QFrame::Raised);
        label_28 = new QLabel(settingsFrame);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 8, 181, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura")});
        font.setBold(false);
        font.setItalic(false);
        label_28->setFont(font);
        label_28->setStyleSheet(QString::fromUtf8("QLabel\n"
"	{\n"
"		font:							 18px;\n"
"	}"));
        label_29 = new QLabel(settingsFrame);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(15, 42, 320, 16));
        label_29->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"border-top: 2px solid white;\n"
"}"));
        label_27 = new QLabel(settingsFrame);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(195, 120, 101, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Futura")});
        font1.setBold(true);
        font1.setItalic(false);
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("font: bold 12px;"));
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_15 = new QLabel(settingsFrame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(121, 100, 48, 13));
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(true);
        label_18 = new QLabel(settingsFrame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(80, 96, 41, 21));
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(true);
        label_17 = new QLabel(settingsFrame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(36, 96, 41, 21));
        label_17->setAlignment(Qt::AlignCenter);
        label_17->setWordWrap(true);
        label_2 = new QLabel(settingsFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(74, 46, 51, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: bold 12px"));
        label_2->setAlignment(Qt::AlignCenter);
        allAccelY = new QSpinBox(settingsFrame);
        allAccelY->setObjectName(QString::fromUtf8("allAccelY"));
        allAccelY->setGeometry(QRect(125, 70, 41, 18));
        allAccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        allAccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allAccelY->setMaximum(127);
        allOffThresh = new QSpinBox(settingsFrame);
        allOffThresh->setObjectName(QString::fromUtf8("allOffThresh"));
        allOffThresh->setGeometry(QRect(80, 70, 41, 18));
        allOffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        allOffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allOffThresh->setMaximum(127);
        allOnThresh = new QSpinBox(settingsFrame);
        allOnThresh->setObjectName(QString::fromUtf8("allOnThresh"));
        allOnThresh->setGeometry(QRect(35, 70, 41, 18));
        allOnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        allOnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        allOnThresh->setMaximum(127);
        key1OnThresh = new QSpinBox(settingsFrame);
        key1OnThresh->setObjectName(QString::fromUtf8("key1OnThresh"));
        key1OnThresh->setGeometry(QRect(35, 128, 40, 18));
        key1OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key1OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key1OnThresh->setMaximum(127);
        key1OffThresh = new QSpinBox(settingsFrame);
        key1OffThresh->setObjectName(QString::fromUtf8("key1OffThresh"));
        key1OffThresh->setGeometry(QRect(80, 128, 40, 18));
        key1OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key1OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key1OffThresh->setMaximum(127);
        key1AccelY = new QSpinBox(settingsFrame);
        key1AccelY->setObjectName(QString::fromUtf8("key1AccelY"));
        key1AccelY->setGeometry(QRect(125, 128, 40, 18));
        key1AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key1AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key1AccelY->setMaximum(127);
        key2OnThresh = new QSpinBox(settingsFrame);
        key2OnThresh->setObjectName(QString::fromUtf8("key2OnThresh"));
        key2OnThresh->setGeometry(QRect(35, 150, 40, 18));
        key2OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key2OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key2OnThresh->setMaximum(127);
        key2OffThresh = new QSpinBox(settingsFrame);
        key2OffThresh->setObjectName(QString::fromUtf8("key2OffThresh"));
        key2OffThresh->setGeometry(QRect(80, 150, 40, 18));
        key2OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key2OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key2OffThresh->setMaximum(127);
        key2AccelY = new QSpinBox(settingsFrame);
        key2AccelY->setObjectName(QString::fromUtf8("key2AccelY"));
        key2AccelY->setGeometry(QRect(125, 150, 40, 18));
        key2AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key2AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key2AccelY->setMaximum(127);
        key3OnThresh = new QSpinBox(settingsFrame);
        key3OnThresh->setObjectName(QString::fromUtf8("key3OnThresh"));
        key3OnThresh->setGeometry(QRect(35, 172, 40, 18));
        key3OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key3OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key3OnThresh->setMaximum(127);
        key3OffThresh = new QSpinBox(settingsFrame);
        key3OffThresh->setObjectName(QString::fromUtf8("key3OffThresh"));
        key3OffThresh->setGeometry(QRect(80, 172, 40, 18));
        key3OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key3OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key3OffThresh->setMaximum(127);
        key3AccelY = new QSpinBox(settingsFrame);
        key3AccelY->setObjectName(QString::fromUtf8("key3AccelY"));
        key3AccelY->setGeometry(QRect(125, 172, 40, 18));
        key3AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key3AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key3AccelY->setMaximum(127);
        key4OnThresh = new QSpinBox(settingsFrame);
        key4OnThresh->setObjectName(QString::fromUtf8("key4OnThresh"));
        key4OnThresh->setGeometry(QRect(35, 194, 40, 18));
        key4OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key4OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key4OnThresh->setMaximum(127);
        key4OffThresh = new QSpinBox(settingsFrame);
        key4OffThresh->setObjectName(QString::fromUtf8("key4OffThresh"));
        key4OffThresh->setGeometry(QRect(80, 194, 40, 18));
        key4OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key4OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key4OffThresh->setMaximum(127);
        key4AccelY = new QSpinBox(settingsFrame);
        key4AccelY->setObjectName(QString::fromUtf8("key4AccelY"));
        key4AccelY->setGeometry(QRect(125, 194, 40, 18));
        key4AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key4AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key4AccelY->setMaximum(127);
        key5OnThresh = new QSpinBox(settingsFrame);
        key5OnThresh->setObjectName(QString::fromUtf8("key5OnThresh"));
        key5OnThresh->setGeometry(QRect(35, 216, 40, 18));
        key5OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key5OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key5OnThresh->setMaximum(127);
        key5OffThresh = new QSpinBox(settingsFrame);
        key5OffThresh->setObjectName(QString::fromUtf8("key5OffThresh"));
        key5OffThresh->setGeometry(QRect(80, 216, 40, 18));
        key5OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key5OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key5OffThresh->setMaximum(127);
        key5AccelY = new QSpinBox(settingsFrame);
        key5AccelY->setObjectName(QString::fromUtf8("key5AccelY"));
        key5AccelY->setGeometry(QRect(125, 216, 40, 18));
        key5AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key5AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key5AccelY->setMaximum(127);
        key6OnThresh = new QSpinBox(settingsFrame);
        key6OnThresh->setObjectName(QString::fromUtf8("key6OnThresh"));
        key6OnThresh->setGeometry(QRect(35, 238, 40, 18));
        key6OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key6OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key6OnThresh->setMaximum(127);
        key6OffThresh = new QSpinBox(settingsFrame);
        key6OffThresh->setObjectName(QString::fromUtf8("key6OffThresh"));
        key6OffThresh->setGeometry(QRect(80, 238, 40, 18));
        key6OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key6OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key6OffThresh->setMaximum(127);
        key6AccelY = new QSpinBox(settingsFrame);
        key6AccelY->setObjectName(QString::fromUtf8("key6AccelY"));
        key6AccelY->setGeometry(QRect(125, 238, 40, 18));
        key6AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key6AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key6AccelY->setMaximum(127);
        key7OnThresh = new QSpinBox(settingsFrame);
        key7OnThresh->setObjectName(QString::fromUtf8("key7OnThresh"));
        key7OnThresh->setGeometry(QRect(35, 260, 40, 18));
        key7OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key7OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key7OnThresh->setMaximum(127);
        key7OffThresh = new QSpinBox(settingsFrame);
        key7OffThresh->setObjectName(QString::fromUtf8("key7OffThresh"));
        key7OffThresh->setGeometry(QRect(80, 260, 40, 18));
        key7OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key7OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key7OffThresh->setMaximum(127);
        key7AccelY = new QSpinBox(settingsFrame);
        key7AccelY->setObjectName(QString::fromUtf8("key7AccelY"));
        key7AccelY->setGeometry(QRect(125, 260, 40, 18));
        key7AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key7AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key7AccelY->setMaximum(127);
        key8OnThresh = new QSpinBox(settingsFrame);
        key8OnThresh->setObjectName(QString::fromUtf8("key8OnThresh"));
        key8OnThresh->setGeometry(QRect(35, 282, 40, 18));
        key8OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key8OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key8OnThresh->setMaximum(127);
        key8OffThresh = new QSpinBox(settingsFrame);
        key8OffThresh->setObjectName(QString::fromUtf8("key8OffThresh"));
        key8OffThresh->setGeometry(QRect(80, 282, 40, 18));
        key8OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key8OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key8OffThresh->setMaximum(127);
        key8AccelY = new QSpinBox(settingsFrame);
        key8AccelY->setObjectName(QString::fromUtf8("key8AccelY"));
        key8AccelY->setGeometry(QRect(125, 282, 40, 18));
        key8AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key8AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key8AccelY->setMaximum(127);
        key9OnThresh = new QSpinBox(settingsFrame);
        key9OnThresh->setObjectName(QString::fromUtf8("key9OnThresh"));
        key9OnThresh->setGeometry(QRect(35, 304, 40, 18));
        key9OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key9OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key9OnThresh->setMaximum(127);
        key9OffThresh = new QSpinBox(settingsFrame);
        key9OffThresh->setObjectName(QString::fromUtf8("key9OffThresh"));
        key9OffThresh->setGeometry(QRect(80, 304, 40, 18));
        key9OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key9OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key9OffThresh->setMaximum(127);
        key9AccelY = new QSpinBox(settingsFrame);
        key9AccelY->setObjectName(QString::fromUtf8("key9AccelY"));
        key9AccelY->setGeometry(QRect(125, 304, 40, 18));
        key9AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key9AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key9AccelY->setMaximum(127);
        key10OffThresh = new QSpinBox(settingsFrame);
        key10OffThresh->setObjectName(QString::fromUtf8("key10OffThresh"));
        key10OffThresh->setGeometry(QRect(80, 326, 40, 18));
        key10OffThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key10OffThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key10OffThresh->setMaximum(127);
        key10AccelY = new QSpinBox(settingsFrame);
        key10AccelY->setObjectName(QString::fromUtf8("key10AccelY"));
        key10AccelY->setGeometry(QRect(125, 326, 40, 18));
        key10AccelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key10AccelY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key10AccelY->setMaximum(127);
        label_31 = new QLabel(settingsFrame);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(180, 60, 20, 291));
        label_31->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"border-left: 1px solid white;\n"
"}"));
        label = new QLabel(settingsFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(195, 46, 149, 21));
        label->setStyleSheet(QString::fromUtf8("font: bold 12px;"));
        sensorResponseMax = new QCheckBox(settingsFrame);
        sensorResponseMax->setObjectName(QString::fromUtf8("sensorResponseMax"));
        sensorResponseMax->setGeometry(QRect(205, 70, 123, 16));
        sensorResponseMax->setFocusPolicy(Qt::WheelFocus);
        sensorResponseMax->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"	font: 10pt \"Futura\";\n"
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
" QC"
                        "heckBox::indicator:checked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        sensorResponseAverage = new QCheckBox(settingsFrame);
        sensorResponseAverage->setObjectName(QString::fromUtf8("sensorResponseAverage"));
        sensorResponseAverage->setGeometry(QRect(205, 90, 123, 16));
        sensorResponseAverage->setFocusPolicy(Qt::WheelFocus);
        sensorResponseAverage->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"	font: 10pt \"Futura\";\n"
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
" QC"
                        "heckBox::indicator:checked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        multipleKeyMode = new QCheckBox(settingsFrame);
        multipleKeyMode->setObjectName(QString::fromUtf8("multipleKeyMode"));
        multipleKeyMode->setGeometry(QRect(205, 144, 131, 16));
        multipleKeyMode->setFocusPolicy(Qt::WheelFocus);
        multipleKeyMode->setLayoutDirection(Qt::LeftToRight);
        multipleKeyMode->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"	font: 10pt \"Futura\";\n"
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
" QC"
                        "heckBox::indicator:checked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        adjacentKeyMode = new QCheckBox(settingsFrame);
        adjacentKeyMode->setObjectName(QString::fromUtf8("adjacentKeyMode"));
        adjacentKeyMode->setGeometry(QRect(205, 164, 131, 16));
        adjacentKeyMode->setFocusPolicy(Qt::WheelFocus);
        adjacentKeyMode->setLayoutDirection(Qt::LeftToRight);
        adjacentKeyMode->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"color: rgba(255,255,255,250);\n"
"	font: 10pt \"Futura\";\n"
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
" QC"
                        "heckBox::indicator:checked:pressed:focus {\n"
"     image: url(:/resources/radio_focus_off.png);\n"
" }"));
        key10OnThresh = new QSpinBox(settingsFrame);
        key10OnThresh->setObjectName(QString::fromUtf8("key10OnThresh"));
        key10OnThresh->setGeometry(QRect(35, 326, 40, 18));
        key10OnThresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        key10OnThresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        key10OnThresh->setMaximum(127);
        label_28->raise();
        label_29->raise();
        label_27->raise();
        label_24->raise();
        label_15->raise();
        label_18->raise();
        label_17->raise();
        label_2->raise();
        allOffThresh->raise();
        allAccelY->raise();
        allOffThresh->raise();
        allOnThresh->raise();
        key1OnThresh->raise();
        key1OffThresh->raise();
        key1AccelY->raise();
        key2OnThresh->raise();
        key2OffThresh->raise();
        key2AccelY->raise();
        key3OnThresh->raise();
        key3OffThresh->raise();
        key3AccelY->raise();
        key4OnThresh->raise();
        key4OffThresh->raise();
        key4AccelY->raise();
        key5OnThresh->raise();
        key5OffThresh->raise();
        key5AccelY->raise();
        key6OnThresh->raise();
        key6OffThresh->raise();
        key6AccelY->raise();
        key7OnThresh->raise();
        key7OffThresh->raise();
        key7AccelY->raise();
        key8OnThresh->raise();
        key8OffThresh->raise();
        key8AccelY->raise();
        key9OnThresh->raise();
        key9OffThresh->raise();
        key9AccelY->raise();
        key10OffThresh->raise();
        key10AccelY->raise();
        label_31->raise();
        label->raise();
        sensorResponseMax->raise();
        sensorResponseAverage->raise();
        multipleKeyMode->raise();
        adjacentKeyMode->raise();
        key10OnThresh->raise();
        key10OnThresh->raise();
        settingsFrame->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_19->raise();
        navEastOnThresh->raise();
        label_20->raise();
        navNorthOnThresh->raise();
        label_21->raise();
        navSouthOnThresh->raise();
        navEastOffThresh->raise();
        label_22->raise();
        label_23->raise();
        navNorthOffThresh->raise();
        navWestOffThresh->raise();
        label_24->raise();
        navSouthOffThresh->raise();
        label_25->raise();
        navWestOnThresh->raise();
        label_26->raise();
        navAccelY->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "1", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "2", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "3", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "4", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "5", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "6", nullptr));
        label_9->setText(QCoreApplication::translate("Form", "7", nullptr));
        label_10->setText(QCoreApplication::translate("Form", "8", nullptr));
        label_11->setText(QCoreApplication::translate("Form", "9", nullptr));
        label_12->setText(QCoreApplication::translate("Form", "10", nullptr));
        label_19->setText(QCoreApplication::translate("Form", "Nav Pad", nullptr));
        label_20->setText(QCoreApplication::translate("Form", "S", nullptr));
        label_21->setText(QCoreApplication::translate("Form", "E", nullptr));
        label_22->setText(QCoreApplication::translate("Form", "N", nullptr));
        label_23->setText(QCoreApplication::translate("Form", "on thresh", nullptr));
        label_24->setText(QCoreApplication::translate("Form", "off thresh", nullptr));
        label_25->setText(QCoreApplication::translate("Form", "W", nullptr));
        label_26->setText(QCoreApplication::translate("Form", "accel y", nullptr));
        label_28->setText(QCoreApplication::translate("Form", "SETTINGS", nullptr));
        label_29->setText(QString());
        label_27->setText(QCoreApplication::translate("Form", "Key Safety", nullptr));
        label_15->setText(QCoreApplication::translate("Form", "accel y", nullptr));
        label_18->setText(QCoreApplication::translate("Form", "off thresh", nullptr));
        label_17->setText(QCoreApplication::translate("Form", "on thresh", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Keys", nullptr));
        label_31->setText(QString());
        label->setText(QCoreApplication::translate("Form", "Sensor Response", nullptr));
        sensorResponseMax->setText(QCoreApplication::translate("Form", "Maximum", nullptr));
        sensorResponseAverage->setText(QCoreApplication::translate("Form", "Average", nullptr));
        multipleKeyMode->setText(QCoreApplication::translate("Form", "Multiple Key Mode", nullptr));
        adjacentKeyMode->setText(QCoreApplication::translate("Form", "Adjacent Key Lockout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSFORM_H
