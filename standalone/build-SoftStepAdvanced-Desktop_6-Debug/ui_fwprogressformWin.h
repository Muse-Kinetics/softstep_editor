// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'fwprogressformWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FWPROGRESSFORMWIN_H
#define UI_FWPROGRESSFORMWIN_H

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
"	border: 4px solid rgba(0,174,239,255);\n"
"}  \n"
"\n"
"QWidget:hover\n"
"{\n"
"	/*border:				3px solid rgb(0, 126, 126)*/\n"
"}        \n"
"\n"
"/*-------QFrame-------*/\n"
"\n"
"QFrame\n"
"{\n"
"	background: rgb(60, 60, 60);\n"
"}\n"
"\n"
"/* ---------- QLabels ------------*/\n"
"\n"
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
"/*---------- QProgress Bar ---------*/\n"
"\n"
"QProgressBar \n"
"{\n"
"	border: 2px solid rgb(60, 60, 60);\n"
"	padding: 0px;\n"
"	background: white;\n"
" }\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"	background-color: rgba(0,174,239,255);\n"
"	border-radius: 1px;\n"
"}\n"
"\n"
""));
        warningFrame = new QFrame(FwProgressForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 238, 78));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 221, 61));
        warningSubFrame->setFocusPolicy(Qt::NoFocus);
        warningSubFrame->setStyleSheet(QString::fromUtf8("QFrame \n"
"{\n"
"background: none;\n"
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

#endif // UI_FWPROGRESSFORMWIN_H
