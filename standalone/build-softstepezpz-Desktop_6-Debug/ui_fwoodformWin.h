// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'fwoodformWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FWOODFORMWIN_H
#define UI_FWOODFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FwoodDialog
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QPushButton *update;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *expected;
    QLabel *found;
    QPushButton *cancel;
    QLabel *label_4;

    void setupUi(QWidget *FwoodDialog)
    {
        if (FwoodDialog->objectName().isEmpty())
            FwoodDialog->setObjectName(QString::fromUtf8("FwoodDialog"));
        FwoodDialog->resize(241, 137);
        FwoodDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
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
        warningFrame = new QFrame(FwoodDialog);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 241, 137));
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 224, 121));
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
"\n"
"QLabel\n"
"{\n"
"	font: 9pt \"Corbel\";\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	font: 8pt \"Corbel\";\n"
"}"));
        warningSubFrame->setFrameShape(QFrame::StyledPanel);
        warningSubFrame->setFrameShadow(QFrame::Raised);
        update = new QPushButton(warningSubFrame);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(120, 93, 51, 20));
        update->setFocusPolicy(Qt::NoFocus);
        update->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(warningSubFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 26, 51, 16));
        label->setFocusPolicy(Qt::NoFocus);
        label->setStyleSheet(QString::fromUtf8("font: 8pt;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(warningSubFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 41, 51, 16));
        label_2->setFocusPolicy(Qt::NoFocus);
        label_2->setStyleSheet(QString::fromUtf8("font: 8pt;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(warningSubFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, -3, 224, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt;"));
        label_3->setAlignment(Qt::AlignCenter);
        expected = new QLabel(warningSubFrame);
        expected->setObjectName(QString::fromUtf8("expected"));
        expected->setGeometry(QRect(120, 26, 95, 16));
        expected->setFocusPolicy(Qt::NoFocus);
        expected->setStyleSheet(QString::fromUtf8("font: 8pt;"));
        expected->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        found = new QLabel(warningSubFrame);
        found->setObjectName(QString::fromUtf8("found"));
        found->setGeometry(QRect(120, 41, 95, 16));
        found->setFocusPolicy(Qt::NoFocus);
        found->setStyleSheet(QString::fromUtf8("font: 8pt;"));
        found->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cancel = new QPushButton(warningSubFrame);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(59, 93, 51, 20));
        cancel->setFocusPolicy(Qt::NoFocus);
        cancel->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(warningSubFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 57, 224, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Corbel")});
        font1.setPointSize(6);
        font1.setBold(false);
        font1.setItalic(false);
        label_4->setFont(font1);
        label_4->setFocusPolicy(Qt::NoFocus);
        label_4->setStyleSheet(QString::fromUtf8("font: 6pt \"Corbel\";\n"
""));
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(FwoodDialog);

        QMetaObject::connectSlotsByName(FwoodDialog);
    } // setupUi

    void retranslateUi(QWidget *FwoodDialog)
    {
        FwoodDialog->setWindowTitle(QCoreApplication::translate("FwoodDialog", "Form", nullptr));
        update->setText(QCoreApplication::translate("FwoodDialog", "UPDATE", nullptr));
        label->setText(QCoreApplication::translate("FwoodDialog", "Expected:", nullptr));
        label_2->setText(QCoreApplication::translate("FwoodDialog", "Found:", nullptr));
        label_3->setText(QCoreApplication::translate("FwoodDialog", "Your firmware is out of date.", nullptr));
        expected->setText(QString());
        found->setText(QString());
        cancel->setText(QCoreApplication::translate("FwoodDialog", "CANCEL", nullptr));
        label_4->setText(QCoreApplication::translate("FwoodDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt;\">NOTE: Updating firmare will overwrite any</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt;\">presets currently on the connected SoftStep.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FwoodDialog: public Ui_FwoodDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWOODFORMWIN_H
