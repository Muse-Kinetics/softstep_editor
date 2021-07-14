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

    void setupUi(QWidget *FwUpdateCompleteForm)
    {
        if (FwUpdateCompleteForm->objectName().isEmpty())
            FwUpdateCompleteForm->setObjectName(QString::fromUtf8("FwUpdateCompleteForm"));
        FwUpdateCompleteForm->resize(188, 97);
        FwUpdateCompleteForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"	font: 				7pt \"Futura\";\n"
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
"	font: 7pt \"Futura\";\n"
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
"	font: 7pt \"Futura\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:"
                        "focus\n"
"{\n"
"	font: 7pt \"Futura\";\n"
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
"	font: 7pt \"Futura\";\n"
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
"	font: 7pt \"Futura\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border: 2px solid white;\n"
"	font: 7pt \"Futura\";\n"
"	background: rgba(0,174,239,255);\n"
"	color: white;\n"
"}\n"
"\n"
""));
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
        updateComplete->setStyleSheet(QString::fromUtf8("font: 10pt \"Corbel\";"));
        updateComplete->setAlignment(Qt::AlignCenter);
        ok = new QPushButton(warningSubFrame);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(66, 50, 40, 20));
        ok->setFocusPolicy(Qt::NoFocus);
        ok->setStyleSheet(QString::fromUtf8("font: 9pt \"Futura-Normal\";"));

        retranslateUi(FwUpdateCompleteForm);

        QMetaObject::connectSlotsByName(FwUpdateCompleteForm);
    } // setupUi

    void retranslateUi(QWidget *FwUpdateCompleteForm)
    {
        FwUpdateCompleteForm->setWindowTitle(QCoreApplication::translate("FwUpdateCompleteForm", "Form", nullptr));
        updateComplete->setText(QCoreApplication::translate("FwUpdateCompleteForm", "Firmware Update Complete", nullptr));
        ok->setText(QCoreApplication::translate("FwUpdateCompleteForm", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FwUpdateCompleteForm: public Ui_FwUpdateCompleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWUPDATECOMPLETEFORMWIN_H
