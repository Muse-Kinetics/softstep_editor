// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'aboutform.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORM_H
#define UI_ABOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QPushButton *ok;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *expected;
    QLabel *found;
    QLabel *label_4;
    QLabel *editor_version;

    void setupUi(QWidget *AboutForm)
    {
        if (AboutForm->objectName().isEmpty())
            AboutForm->setObjectName(QString::fromUtf8("AboutForm"));
        AboutForm->resize(240, 155);
        AboutForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgba(35,31,32,255);\n"
"	border: 4px solid rgba(0,174,239,255);\n"
"}  \n"
"\n"
"QWidget:hover\n"
"{\n"
"	/*border:				3px solid rgb(0, 126, 126)*/\n"
"}        \n"
"\n"
"/*-------QFrame-------*/\n"
"QFrame\n"
"{\n"
"	background: rgb(60, 60, 60);\n"
"}\n"
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
""
                        "	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
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
"/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: 10pt \"Futura\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border: 2px solid white;\n"
"	font: 9pt \"Futura\";\n"
"	background: rgba(0,174,239,255);\n"
"	color: white;\n"
""
                        "}\n"
"\n"
""));
        warningFrame = new QFrame(AboutForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 240, 155));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 224, 140));
        warningSubFrame->setFocusPolicy(Qt::NoFocus);
        warningSubFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background:rgba(200, 200, 200, 0);\n"
"	border-bottom-left-radius:4.0;\n"
"	border-bottom-right-radius:4.0;\n"
"	border-top-left-radius:4.0;\n"
"	border-top-right-radius:4.0;\n"
"	border:none;\n"
"\n"
"\n"
"}\n"
""));
        warningSubFrame->setFrameShape(QFrame::StyledPanel);
        warningSubFrame->setFrameShadow(QFrame::Raised);
        ok = new QPushButton(warningSubFrame);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(92, 110, 40, 20));
        ok->setFocusPolicy(Qt::NoFocus);
        ok->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(warningSubFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 81, 16));
        label->setFocusPolicy(Qt::NoFocus);
        label->setStyleSheet(QString::fromUtf8("font: bold 10pt;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(warningSubFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 60, 61, 16));
        label_2->setFocusPolicy(Qt::NoFocus);
        label_2->setStyleSheet(QString::fromUtf8("font: bold 10pt;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(warningSubFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 224, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setStyleSheet(QString::fromUtf8("font:12pt \"Futura\";\n"
""));
        label_3->setAlignment(Qt::AlignCenter);
        expected = new QLabel(warningSubFrame);
        expected->setObjectName(QString::fromUtf8("expected"));
        expected->setGeometry(QRect(120, 40, 111, 16));
        expected->setFocusPolicy(Qt::NoFocus);
        expected->setStyleSheet(QString::fromUtf8("font: 10pt;"));
        expected->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        found = new QLabel(warningSubFrame);
        found->setObjectName(QString::fromUtf8("found"));
        found->setGeometry(QRect(120, 60, 111, 16));
        found->setFocusPolicy(Qt::NoFocus);
        found->setStyleSheet(QString::fromUtf8("font: 10pt;"));
        found->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(warningSubFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 80, 81, 16));
        label_4->setFocusPolicy(Qt::NoFocus);
        label_4->setStyleSheet(QString::fromUtf8("font: bold 10pt;"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        editor_version = new QLabel(warningSubFrame);
        editor_version->setObjectName(QString::fromUtf8("editor_version"));
        editor_version->setGeometry(QRect(120, 80, 111, 16));
        editor_version->setFocusPolicy(Qt::NoFocus);
        editor_version->setStyleSheet(QString::fromUtf8("font: 10pt;"));
        editor_version->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(AboutForm);

        QMetaObject::connectSlotsByName(AboutForm);
    } // setupUi

    void retranslateUi(QWidget *AboutForm)
    {
        AboutForm->setWindowTitle(QCoreApplication::translate("AboutForm", "Form", nullptr));
        ok->setText(QCoreApplication::translate("AboutForm", "OK", nullptr));
        label->setText(QCoreApplication::translate("AboutForm", "Expected FW:", nullptr));
        label_2->setText(QCoreApplication::translate("AboutForm", "Found FW:", nullptr));
        label_3->setText(QCoreApplication::translate("AboutForm", "About SoftStep Advanced Editor", nullptr));
        expected->setText(QString());
        found->setText(QString());
        label_4->setText(QCoreApplication::translate("AboutForm", "Editor Version:", nullptr));
        editor_version->setText(QCoreApplication::translate("AboutForm", "2.04", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutForm: public Ui_AboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORM_H
