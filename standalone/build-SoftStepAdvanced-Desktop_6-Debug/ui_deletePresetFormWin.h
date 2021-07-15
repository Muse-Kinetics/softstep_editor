// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'deletePresetFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPRESETFORMWIN_H
#define UI_DELETEPRESETFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteDialogForm
{
public:
    QLabel *label;
    QToolButton *cancel;
    QToolButton *delete_2;
    QLabel *label_2;

    void setupUi(QWidget *deleteDialogForm)
    {
        if (deleteDialogForm->objectName().isEmpty())
            deleteDialogForm->setObjectName(QString::fromUtf8("deleteDialogForm"));
        deleteDialogForm->resize(264, 94);
        deleteDialogForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:	 rgb(60, 60, 60);\n"
"	border: 4px solid rgb(0,174,239);\n"
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
"/*-------QPushButton-------*/\n"
"QPushButton\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: white;\n"
"	border: 2px solid rgb(0, 174, 239);\n"
"	background: rgb(20, 20, 20);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgb(0, 174, 239);\n"
"}\n"
"\n"
"/*-------QToolButton-------*/\n"
"QToolButton\n"
"{\n"
"	font: 12px \"Corbel\";\n"
"	color: white;\n"
"	border: 2px solid rgb(0, 174, 239);\n"
"	background: rgb(40, 40, 40);\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background-color: rgb(0, 174, 239);\n"
"}\n"
"\n"
"\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 4"
                        "0, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"}"));
        label = new QLabel(deleteDialogForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 10, 231, 16));
        label->setAlignment(Qt::AlignCenter);
        cancel = new QToolButton(deleteDialogForm);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(24, 50, 100, 26));
        cancel->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        delete_2 = new QToolButton(deleteDialogForm);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(140, 50, 100, 26));
        delete_2->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"	min-height: 16px;\n"
"}"));
        label_2 = new QLabel(deleteDialogForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(26, 26, 211, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Corbel")});
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Corbel\";"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(deleteDialogForm);

        QMetaObject::connectSlotsByName(deleteDialogForm);
    } // setupUi

    void retranslateUi(QWidget *deleteDialogForm)
    {
        deleteDialogForm->setWindowTitle(QCoreApplication::translate("deleteDialogForm", "Delete Preset", nullptr));
        label->setText(QCoreApplication::translate("deleteDialogForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Futura-Normal'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Are you sure you want to delete this preset?</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        cancel->setToolTip(QCoreApplication::translate("deleteDialogForm", "\"I've made a huge mistake.\"", nullptr));
#endif // QT_CONFIG(tooltip)
        cancel->setText(QCoreApplication::translate("deleteDialogForm", "No. Cancel.", nullptr));
#if QT_CONFIG(tooltip)
        delete_2->setToolTip(QCoreApplication::translate("deleteDialogForm", "\"Exterminate!\"", nullptr));
#endif // QT_CONFIG(tooltip)
        delete_2->setText(QCoreApplication::translate("deleteDialogForm", "Yes. Delete.", nullptr));
        label_2->setText(QCoreApplication::translate("deleteDialogForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Corbel'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">You </span><span style=\" font-size:8pt; text-decoration: underline;\">cannot</span><span style=\" font-size:8pt;\"> undo this action.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteDialogForm: public Ui_deleteDialogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPRESETFORMWIN_H
