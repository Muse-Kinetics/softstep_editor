// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'fwprogressform.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FWPROGRESSFORM_H
#define UI_FWPROGRESSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FwProgressForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QLabel *found;
    QProgressBar *progressBar;

    void setupUi(QWidget *FwProgressForm)
    {
        if (FwProgressForm->objectName().isEmpty())
            FwProgressForm->setObjectName(QString::fromUtf8("FwProgressForm"));
        FwProgressForm->resize(238, 78);
        FwProgressForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: 10pt \"Futura\";\n"
"	color: white;\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"outline: none;\n"
"border: 2px solid rgba(255,255,255,255);\n"
"}\n"
"\n"
"/*---------- QProgress Bar ---------*/\n"
"QProgressBar \n"
"{\n"
"border: 2px solid rgb(25,25,25);\n"
"padding: 0px;\n"
"background"
                        ": white;\n"
" }\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"background-color: rgba(0,174,239,255);\n"
"border-radius: 1px;\n"
"}\n"
"\n"
""));
        warningFrame = new QFrame(FwProgressForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 238, 78));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background:		rgba(35,31,32,255);\n"
"	border: 6px solid rgba(0,174,239,255);\n"
"}  "));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 221, 61));
        warningSubFrame->setFocusPolicy(Qt::NoFocus);
        warningSubFrame->setStyleSheet(QString::fromUtf8("QFrame \n"
"{\n"
"background: rgba(0,0,0,0);\n"
"border:none;\n"
"}\n"
""));
        warningSubFrame->setFrameShape(QFrame::StyledPanel);
        warningSubFrame->setFrameShadow(QFrame::Raised);
        found = new QLabel(warningSubFrame);
        found->setObjectName(QString::fromUtf8("found"));
        found->setGeometry(QRect(0, -1, 221, 31));
        found->setFocusPolicy(Qt::NoFocus);
        found->setStyleSheet(QString::fromUtf8("font: 10pt;"));
        found->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(warningSubFrame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 30, 181, 23));
        progressBar->setFocusPolicy(Qt::NoFocus);
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(20);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);

        retranslateUi(FwProgressForm);

        QMetaObject::connectSlotsByName(FwProgressForm);
    } // setupUi

    void retranslateUi(QWidget *FwProgressForm)
    {
        FwProgressForm->setWindowTitle(QCoreApplication::translate("FwProgressForm", "Form", nullptr));
        found->setText(QCoreApplication::translate("FwProgressForm", "Updating Firmware...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FwProgressForm: public Ui_FwProgressForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWPROGRESSFORM_H
