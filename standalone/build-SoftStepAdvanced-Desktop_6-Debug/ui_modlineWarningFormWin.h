// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'modlineWarningFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODLINEWARNINGFORMWIN_H
#define UI_MODLINEWARNINGFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModlineWarningForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QLabel *label;
    QPushButton *ok;

    void setupUi(QWidget *ModlineWarningForm)
    {
        if (ModlineWarningForm->objectName().isEmpty())
            ModlineWarningForm->setObjectName(QString::fromUtf8("ModlineWarningForm"));
        ModlineWarningForm->resize(258, 158);
        ModlineWarningForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"	background:	rgba(0,0,0,0);\n"
"	color: 				white;\n"
"	font: 				10pt \"Corbel\";\n"
"	border:			none;\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	border:	none;\n"
"}\n"
"\n"
"/*---------- QPushButton ---------*/\n"
"QPushButton\n"
"{\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	font: 8pt \"Corbel\";\n"
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
        warningFrame = new QFrame(ModlineWarningForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 258, 158));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 242, 142));
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
        label->setGeometry(QRect(8, 2, 226, 98));
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
        ok->setGeometry(QRect(100, 110, 40, 20));
        ok->setFocusPolicy(Qt::NoFocus);
        ok->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(ModlineWarningForm);

        QMetaObject::connectSlotsByName(ModlineWarningForm);
    } // setupUi

    void retranslateUi(QWidget *ModlineWarningForm)
    {
        ModlineWarningForm->setWindowTitle(QCoreApplication::translate("ModlineWarningForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("ModlineWarningForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Modline Limit Exceeded!</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br />Limit 50 modlines per preset </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">in Standalone mode</span></p></body></html>", nullptr));
        ok->setText(QCoreApplication::translate("ModlineWarningForm", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModlineWarningForm: public Ui_ModlineWarningForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODLINEWARNINGFORMWIN_H
