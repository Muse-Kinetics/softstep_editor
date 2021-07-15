// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'importOldPresetsFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTOLDPRESETSFORMWIN_H
#define UI_IMPORTOLDPRESETSFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportOldPresetsForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QLabel *importMessage;

    void setupUi(QWidget *ImportOldPresetsForm)
    {
        if (ImportOldPresetsForm->objectName().isEmpty())
            ImportOldPresetsForm->setObjectName(QString::fromUtf8("ImportOldPresetsForm"));
        ImportOldPresetsForm->resize(238, 78);
        ImportOldPresetsForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"/*---------- QProgress Bar ---------*/\n"
"QProgressBar \n"
"{\n"
"border: 2px solid rgb(60, 60, 60);\n"
"padding: 0px;\n"
"background: white;\n"
" }\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"background-color: rgba(0,174,239,255);\n"
"border-radius: 1px;\n"
"}\n"
"\n"
""));
        warningFrame = new QFrame(ImportOldPresetsForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 238, 78));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 222, 62));
        warningSubFrame->setFocusPolicy(Qt::NoFocus);
        warningSubFrame->setStyleSheet(QString::fromUtf8("QFrame \n"
"{\n"
"background: none;\n"
"border:none;\n"
"}\n"
""));
        warningSubFrame->setFrameShape(QFrame::StyledPanel);
        warningSubFrame->setFrameShadow(QFrame::Raised);
        importMessage = new QLabel(warningSubFrame);
        importMessage->setObjectName(QString::fromUtf8("importMessage"));
        importMessage->setGeometry(QRect(8, 8, 206, 48));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        importMessage->setFont(font);
        importMessage->setAlignment(Qt::AlignCenter);
        importMessage->setWordWrap(true);

        retranslateUi(ImportOldPresetsForm);

        QMetaObject::connectSlotsByName(ImportOldPresetsForm);
    } // setupUi

    void retranslateUi(QWidget *ImportOldPresetsForm)
    {
        ImportOldPresetsForm->setWindowTitle(QCoreApplication::translate("ImportOldPresetsForm", "Form", nullptr));
        importMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImportOldPresetsForm: public Ui_ImportOldPresetsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTOLDPRESETSFORMWIN_H
