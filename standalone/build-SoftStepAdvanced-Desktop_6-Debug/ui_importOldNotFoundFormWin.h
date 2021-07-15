// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'importOldNotFoundFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTOLDNOTFOUNDFORMWIN_H
#define UI_IMPORTOLDNOTFOUNDFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportOldNotFoundForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QLabel *label;
    QPushButton *ok;

    void setupUi(QWidget *ImportOldNotFoundForm)
    {
        if (ImportOldNotFoundForm->objectName().isEmpty())
            ImportOldNotFoundForm->setObjectName(QString::fromUtf8("ImportOldNotFoundForm"));
        ImportOldNotFoundForm->resize(238, 128);
        ImportOldNotFoundForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"}\n"
"\n"
"/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: 10pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border: 2px solid white;\n"
"	font: 10pt \"Corbel\";\n"
"	background: rgba(0,174,239,255);\n"
"	color: white;\n"
"}\n"
""));
        warningFrame = new QFrame(ImportOldNotFoundForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 238, 128));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 222, 112));
        warningSubFrame->setFocusPolicy(Qt::NoFocus);
        warningSubFrame->setStyleSheet(QString::fromUtf8("QFrame \n"
"{\n"
"background: none;\n"
"border:none;\n"
"}\n"
""));
        warningSubFrame->setFrameShape(QFrame::StyledPanel);
        warningSubFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(warningSubFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(8, 2, 206, 68));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        ok = new QPushButton(warningSubFrame);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(90, 80, 40, 20));
        ok->setFocusPolicy(Qt::NoFocus);
        ok->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(ImportOldNotFoundForm);

        QMetaObject::connectSlotsByName(ImportOldNotFoundForm);
    } // setupUi

    void retranslateUi(QWidget *ImportOldNotFoundForm)
    {
        ImportOldNotFoundForm->setWindowTitle(QCoreApplication::translate("ImportOldNotFoundForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("ImportOldNotFoundForm", "Incorrect Path! You must choose the SoftStep 1.21 folder named 'Presets'.", nullptr));
        ok->setText(QCoreApplication::translate("ImportOldNotFoundForm", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportOldNotFoundForm: public Ui_ImportOldNotFoundForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTOLDNOTFOUNDFORMWIN_H
