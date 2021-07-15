// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'keyWindowFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYWINDOWFORMWIN_H
#define UI_KEYWINDOWFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyWindowForm
{
public:
    QCheckBox *ledDisplayCheckBox;
    QFrame *keyWindowInstanceLabel_background;
    QLabel *keyWindowInstanceLabel;
    QLabel *label;
    QLabel *initsBracketLabel;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *dataSourcesBracketLabel;
    QLabel *dataModifiersBracketLabel;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *outputSettingsBracketLabel;
    QComboBox *leddisplaymode;
    QLineEdit *keyname;
    QLineEdit *displayprefix;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QToolButton *addmodline;
    QToolButton *deletemodline;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_19;
    QSpinBox *counterMax;
    QLabel *label_22;
    QCheckBox *counterWrap;
    QSpinBox *counterMin;
    QFrame *frame;

    void setupUi(QWidget *keyWindowForm)
    {
        if (keyWindowForm->objectName().isEmpty())
            keyWindowForm->setObjectName(QString::fromUtf8("keyWindowForm"));
        keyWindowForm->resize(1150, 410);
        keyWindowForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgb(60, 60, 60);\n"
"\n"
"}\n"
"\n"
"QFrame\n"
"{\n"
"		border: 4px solid rgb(0,174,239);\n"
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
"}\n"
"\n"
"/* ---------- QSpinBox ------------*/\n"
"QSpinBox\n"
"{\n"
"	font: 8pt \"Futura-Normal\";\n"
"	border: 1px solid rgb(0,174,239);\n"
"	background-color: (18, 18, 18);\n"
"	color: white;\n"
"	padding:0, 3, 0, 0;\n"
"}\n"
"\n"
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid rgb(255,255,255);\n"
"	outline: none;\n"
"}\n"
"\n"
"/* ---------- QCheckBox ------------*/\n"
"QCheckBox\n"
"{\n"
"	font: 8pt \"Futura-Normal\";\n"
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
""
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
"	border: 1px solid rgb(255,255,255);\n"
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
"	selection-background-color: transpar"
                        "ent;\n"
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
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"}"));
        ledDisplayCheckBox = new QCheckBox(keyWindowForm);
        ledDisplayCheckBox->setObjectName(QString::fromUtf8("ledDisplayCheckBox"));
        ledDisplayCheckBox->setGeometry(QRect(760, 19, 160, 24));
        ledDisplayCheckBox->setStyleSheet(QString::fromUtf8("/* ---------- QCheckBox ------------*/\n"
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
""));
        ledDisplayCheckBox->setChecked(false);
        keyWindowInstanceLabel_background = new QFrame(keyWindowForm);
        keyWindowInstanceLabel_background->setObjectName(QString::fromUtf8("keyWindowInstanceLabel_background"));
        keyWindowInstanceLabel_background->setGeometry(QRect(430, 17, 25, 25));
        keyWindowInstanceLabel_background->setMinimumSize(QSize(25, 25));
        keyWindowInstanceLabel_background->setMaximumSize(QSize(25, 25));
        keyWindowInstanceLabel_background->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/modline_window_label_background.png);\n"
"}"));
        keyWindowInstanceLabel_background->setFrameShape(QFrame::StyledPanel);
        keyWindowInstanceLabel_background->setFrameShadow(QFrame::Raised);
        keyWindowInstanceLabel = new QLabel(keyWindowForm);
        keyWindowInstanceLabel->setObjectName(QString::fromUtf8("keyWindowInstanceLabel"));
        keyWindowInstanceLabel->setGeometry(QRect(430, 17, 25, 25));
        keyWindowInstanceLabel->setMinimumSize(QSize(25, 25));
        keyWindowInstanceLabel->setMaximumSize(QSize(25, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura-Bold")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        keyWindowInstanceLabel->setFont(font);
        keyWindowInstanceLabel->setContextMenuPolicy(Qt::NoContextMenu);
        keyWindowInstanceLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 10pt \"Futura-Bold\";\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: none;\n"
"}"));
        keyWindowInstanceLabel->setLineWidth(0);
        keyWindowInstanceLabel->setAlignment(Qt::AlignCenter);
        keyWindowInstanceLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        label = new QLabel(keyWindowForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 53, 915, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-top: 2px solid white;\n"
"}"));
        initsBracketLabel = new QLabel(keyWindowForm);
        initsBracketLabel->setObjectName(QString::fromUtf8("initsBracketLabel"));
        initsBracketLabel->setGeometry(QRect(38, 82, 53, 11));
        initsBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_inits_label_bracket.png);\n"
"}"));
        label_3 = new QLabel(keyWindowForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(48, 64, 31, 11));
        label_3->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_inits_label.png);\n"
"}"));
        label_4 = new QLabel(keyWindowForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(106, 64, 95, 11));
        label_4->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataSources_label.png);\n"
"}"));
        dataSourcesBracketLabel = new QLabel(keyWindowForm);
        dataSourcesBracketLabel->setObjectName(QString::fromUtf8("dataSourcesBracketLabel"));
        dataSourcesBracketLabel->setGeometry(QRect(106, 82, 95, 11));
        dataSourcesBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataSources_label_bracket.png);\n"
"}"));
        dataModifiersBracketLabel = new QLabel(keyWindowForm);
        dataModifiersBracketLabel->setObjectName(QString::fromUtf8("dataModifiersBracketLabel"));
        dataModifiersBracketLabel->setGeometry(QRect(250, 82, 318, 11));
        dataModifiersBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataModifiers_label_bracket.png);\n"
"}"));
        label_7 = new QLabel(keyWindowForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(341, 63, 108, 13));
        label_7->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_dataModifiers_label.png);\n"
"}"));
        label_8 = new QLabel(keyWindowForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(705, 63, 113, 14));
        label_8->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_outputSettings_label.png);\n"
"}"));
        outputSettingsBracketLabel = new QLabel(keyWindowForm);
        outputSettingsBracketLabel->setObjectName(QString::fromUtf8("outputSettingsBracketLabel"));
        outputSettingsBracketLabel->setGeometry(QRect(614, 82, 304, 11));
        outputSettingsBracketLabel->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: none;\n"
"	padding: none;\n"
"	background-image: url(:/resources/keyWindow_outputSettings_label_bracket.png);\n"
"}"));
        leddisplaymode = new QComboBox(keyWindowForm);
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->addItem(QString());
        leddisplaymode->setObjectName(QString::fromUtf8("leddisplaymode"));
        leddisplaymode->setGeometry(QRect(1044, 73, 60, 18));
        keyname = new QLineEdit(keyWindowForm);
        keyname->setObjectName(QString::fromUtf8("keyname"));
        keyname->setGeometry(QRect(976, 73, 60, 18));
        keyname->setMaxLength(4);
        displayprefix = new QLineEdit(keyWindowForm);
        displayprefix->setObjectName(QString::fromUtf8("displayprefix"));
        displayprefix->setGeometry(QRect(1111, 73, 30, 18));
        displayprefix->setMaxLength(2);
        label_2 = new QLabel(keyWindowForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(976, 58, 60, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 7pt \"Tahoma\";\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(keyWindowForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1044, 58, 60, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 7pt \"Tahoma\";\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(keyWindowForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1111, 58, 30, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 7pt \"Tahoma\";\n"
""));
        label_6->setAlignment(Qt::AlignCenter);
        addmodline = new QToolButton(keyWindowForm);
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
        deletemodline = new QToolButton(keyWindowForm);
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
        label_20 = new QLabel(keyWindowForm);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(32, 9, 21, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tahoma")});
        font1.setPointSize(7);
        font1.setBold(false);
        font1.setItalic(false);
        label_20->setFont(font1);
        label_21 = new QLabel(keyWindowForm);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(64, 9, 21, 16));
        label_21->setFont(font1);
        label_19 = new QLabel(keyWindowForm);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 10, 16, 39));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Futura")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("/*-------QLabel-------*/\n"
"QLabel\n"
"{\n"
"	font: 12pt \"Futura\";\n"
"	image: url(:/resources/counter_label.png);\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Futura\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	width: 22px;\n"
"	image: none;\n"
"}"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        counterMax = new QSpinBox(keyWindowForm);
        counterMax->setObjectName(QString::fromUtf8("counterMax"));
        counterMax->setGeometry(QRect(60, 25, 30, 18));
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
"QSpinBox:focus\n"
"{\n"
"	border: 1px solid rgb(255,255,255);\n"
"	outline: none;\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"	background-color: rgba(20, 20, 20, 75);\n"
"	border-color: rgba(0, 174, 239, 75);\n"
"	font: 8pt \"Futura-Normal\";\n"
"	color: rgba(255, 255, 255, 75);\n"
"}\n"
""));
        counterMax->setAlignment(Qt::AlignCenter);
        counterMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        counterMax->setMaximum(127);
        label_22 = new QLabel(keyWindowForm);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(93, 9, 31, 16));
        label_22->setFont(font1);
        counterWrap = new QCheckBox(keyWindowForm);
        counterWrap->setObjectName(QString::fromUtf8("counterWrap"));
        counterWrap->setGeometry(QRect(96, 25, 23, 20));
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
"}"));
        counterMin = new QSpinBox(keyWindowForm);
        counterMin->setObjectName(QString::fromUtf8("counterMin"));
        counterMin->setGeometry(QRect(27, 25, 30, 18));
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
"	border: 1px solid rgb(255,255,255);\n"
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
""));
        counterMin->setAlignment(Qt::AlignCenter);
        counterMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        counterMin->setMaximum(127);
        frame = new QFrame(keyWindowForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1150, 410));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        ledDisplayCheckBox->raise();
        keyWindowInstanceLabel_background->raise();
        keyWindowInstanceLabel->raise();
        label->raise();
        initsBracketLabel->raise();
        label_3->raise();
        label_4->raise();
        dataSourcesBracketLabel->raise();
        dataModifiersBracketLabel->raise();
        label_7->raise();
        label_8->raise();
        outputSettingsBracketLabel->raise();
        leddisplaymode->raise();
        keyname->raise();
        displayprefix->raise();
        label_2->raise();
        label_5->raise();
        label_6->raise();
        addmodline->raise();
        deletemodline->raise();
        label_20->raise();
        label_21->raise();
        label_19->raise();
        counterMax->raise();
        label_22->raise();
        counterWrap->raise();
        counterMin->raise();
        QWidget::setTabOrder(counterMin, counterMax);
        QWidget::setTabOrder(counterMax, counterWrap);
        QWidget::setTabOrder(counterWrap, ledDisplayCheckBox);
        QWidget::setTabOrder(ledDisplayCheckBox, keyname);
        QWidget::setTabOrder(keyname, leddisplaymode);
        QWidget::setTabOrder(leddisplaymode, displayprefix);
        QWidget::setTabOrder(displayprefix, addmodline);
        QWidget::setTabOrder(addmodline, deletemodline);

        retranslateUi(keyWindowForm);

        QMetaObject::connectSlotsByName(keyWindowForm);
    } // setupUi

    void retranslateUi(QWidget *keyWindowForm)
    {
        keyWindowForm->setWindowTitle(QCoreApplication::translate("keyWindowForm", "Form", nullptr));
#if QT_CONFIG(tooltip)
        ledDisplayCheckBox->setToolTip(QCoreApplication::translate("keyWindowForm", "Show/Hide the LED and <br>display options for this key.", nullptr));
#endif // QT_CONFIG(tooltip)
        ledDisplayCheckBox->setText(QCoreApplication::translate("keyWindowForm", "CheckBox", nullptr));
        keyWindowInstanceLabel->setText(QCoreApplication::translate("keyWindowForm", "#", nullptr));
        label->setText(QString());
        initsBracketLabel->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        dataSourcesBracketLabel->setText(QString());
        dataModifiersBracketLabel->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        outputSettingsBracketLabel->setText(QString());
        leddisplaymode->setItemText(0, QCoreApplication::translate("keyWindowForm", "None", nullptr));
        leddisplaymode->setItemText(1, QCoreApplication::translate("keyWindowForm", "Always", nullptr));
        leddisplaymode->setItemText(2, QCoreApplication::translate("keyWindowForm", "Once", nullptr));
        leddisplaymode->setItemText(3, QCoreApplication::translate("keyWindowForm", "Initial/Return", nullptr));
        leddisplaymode->setItemText(4, QCoreApplication::translate("keyWindowForm", "Immed Param", nullptr));

#if QT_CONFIG(tooltip)
        leddisplaymode->setToolTip(QCoreApplication::translate("keyWindowForm", "Sets the SoftStep display behavior.<p><b>None</b>: Pressing this key will have no effect on the display.<p><b>Always</b>: Key name will be displayed every time this key is pressed.<p><b>Once</b>: Key name will be displayed once when the key is pressed, then show the prefix + parameter value (Hosted mode only).<p><b>Initial/Return</b>: Prefix + parameter value will be displayed when this key is active, then display the key name when inactive (Hosted mode only).<p><b>Immed Param</b>: (Immediate Parameter) Displays the prefix and parameter value when this key is activated.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        keyname->setToolTip(QCoreApplication::translate("keyWindowForm", "Sets the name for this key.<p>(Four character maximum)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        displayprefix->setToolTip(QCoreApplication::translate("keyWindowForm", "One or two characters that can be added <br>before the parameter value on the SoftStep's display.<p><b>Example</b>: A prefix of \"NI\" and a value of 34 coming through the modline would show \"NI34\" on the display.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("keyWindowForm", "Key Name", nullptr));
        label_5->setText(QCoreApplication::translate("keyWindowForm", "Display Mode", nullptr));
        label_6->setText(QCoreApplication::translate("keyWindowForm", "Prefix", nullptr));
#if QT_CONFIG(tooltip)
        addmodline->setToolTip(QCoreApplication::translate("keyWindowForm", "Add a modline (maximum of 6)", nullptr));
#endif // QT_CONFIG(tooltip)
        addmodline->setText(QString());
#if QT_CONFIG(tooltip)
        deletemodline->setToolTip(QCoreApplication::translate("keyWindowForm", "Delete the bottom modline (minimum of 2)", nullptr));
#endif // QT_CONFIG(tooltip)
        deletemodline->setText(QString());
        label_20->setText(QCoreApplication::translate("keyWindowForm", "Min", nullptr));
        label_21->setText(QCoreApplication::translate("keyWindowForm", "Max", nullptr));
#if QT_CONFIG(tooltip)
        label_19->setToolTip(QCoreApplication::translate("keyWindowForm", "<b>Key Counter:</b><p>Increments between the specified<br> min and max values.<p><b>(Hosted mode only)</b>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_19->setText(QCoreApplication::translate("keyWindowForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Futura'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        counterMax->setToolTip(QCoreApplication::translate("keyWindowForm", "Sets the maximum value for the key counter.<p>No values above this number will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_22->setText(QCoreApplication::translate("keyWindowForm", "Wrap", nullptr));
#if QT_CONFIG(tooltip)
        counterWrap->setToolTip(QCoreApplication::translate("keyWindowForm", "When checked, the key counter will loop back to the minimum value once the maximum value is exceeded (and vice versa).<p>When unchecked, the counter will stop once the minimum or maximum values are reached.", nullptr));
#endif // QT_CONFIG(tooltip)
        counterWrap->setText(QString());
#if QT_CONFIG(tooltip)
        counterMin->setToolTip(QCoreApplication::translate("keyWindowForm", "Sets the minimum value for the key counter.<p>No values below this number will be output.", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class keyWindowForm: public Ui_keyWindowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYWINDOWFORMWIN_H
