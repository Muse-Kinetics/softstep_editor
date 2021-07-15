// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'fwupdatecompleteformWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FWUPDATECOMPLETEFORMWIN_H
#define UI_FWUPDATECOMPLETEFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FwUpdateCompleteForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QLabel *updateComplete;
    QPushButton *ok;
    QLabel *updateComplete_2;

    void setupUi(QWidget *FwUpdateCompleteForm)
    {
        if (FwUpdateCompleteForm->objectName().isEmpty())
            FwUpdateCompleteForm->setObjectName(QString::fromUtf8("FwUpdateCompleteForm"));
        FwUpdateCompleteForm->resize(188, 97);
        FwUpdateCompleteForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"	font: 				10pt \"Corbel\";\n"
"	border:				none;\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	border:				none;\n"
"}  \n"
"\n"
"/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: 10pt \"Corbel\";\n"
"	color: white;\n"
"	padding-top: 2;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border: 2px solid white;\n"
"	font: 9pt \"Corbel\";\n"
"	background: rgba(0,174,239,255);\n"
"	color: white;\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	bo"
                        "rder: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"}"));
        warningFrame = new QFrame(FwUpdateCompleteForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 188, 97));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 171, 81));
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
        updateComplete = new QLabel(warningSubFrame);
        updateComplete->setObjectName(QString::fromUtf8("updateComplete"));
        updateComplete->setGeometry(QRect(0, -1, 171, 31));
        updateComplete->setFocusPolicy(Qt::NoFocus);
        updateComplete->setStyleSheet(QString::fromUtf8("font: bold 10pt;"));
        updateComplete->setAlignment(Qt::AlignCenter);
        ok = new QPushButton(warningSubFrame);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(66, 50, 40, 20));
        ok->setFocusPolicy(Qt::NoFocus);
        ok->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        updateComplete_2 = new QLabel(warningSubFrame);
        updateComplete_2->setObjectName(QString::fromUtf8("updateComplete_2"));
        updateComplete_2->setGeometry(QRect(0, 20, 171, 31));
        updateComplete_2->setFocusPolicy(Qt::NoFocus);
        updateComplete_2->setStyleSheet(QString::fromUtf8("font: 10pt;"));
        updateComplete_2->setAlignment(Qt::AlignCenter);

        retranslateUi(FwUpdateCompleteForm);

        QMetaObject::connectSlotsByName(FwUpdateCompleteForm);
    } // setupUi

    void retranslateUi(QWidget *FwUpdateCompleteForm)
    {
        FwUpdateCompleteForm->setWindowTitle(QCoreApplication::translate("FwUpdateCompleteForm", "Form", nullptr));
        updateComplete->setText(QCoreApplication::translate("FwUpdateCompleteForm", "Firmware Update Complete.", nullptr));
        ok->setText(QCoreApplication::translate("FwUpdateCompleteForm", "OK", nullptr));
        updateComplete_2->setText(QCoreApplication::translate("FwUpdateCompleteForm", "Please resend presets.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FwUpdateCompleteForm: public Ui_FwUpdateCompleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWUPDATECOMPLETEFORMWIN_H
