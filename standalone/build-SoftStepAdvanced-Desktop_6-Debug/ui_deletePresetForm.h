// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'deletePresetForm.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPRESETFORM_H
#define UI_DELETEPRESETFORM_H

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
        deleteDialogForm->resize(250, 94);
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
"	font: 				10pt \"Futura\";\n"
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
"	font: 9px \"Futura\";\n"
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
"	font: 9px \"Futura\";\n"
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
"	font: 10px \"Futura\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40,"
                        " 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	width: 22px;\n"
"}"));
        label = new QLabel(deleteDialogForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 210, 16));
        label->setAlignment(Qt::AlignCenter);
        cancel = new QToolButton(deleteDialogForm);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(20, 50, 100, 26));
        delete_2 = new QToolButton(deleteDialogForm);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(130, 50, 100, 26));
        label_2 = new QLabel(deleteDialogForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 26, 210, 16));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(deleteDialogForm);

        QMetaObject::connectSlotsByName(deleteDialogForm);
    } // setupUi

    void retranslateUi(QWidget *deleteDialogForm)
    {
        deleteDialogForm->setWindowTitle(QCoreApplication::translate("deleteDialogForm", "Delete Preset", nullptr));
        label->setText(QCoreApplication::translate("deleteDialogForm", "Are you sure you want to delete this preset?", nullptr));
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
"</style></head><body style=\" font-family:'Futura'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">You </span><span style=\" font-size:12pt; text-decoration: underline;\">cannot</span><span style=\" font-size:12pt;\"> undo this action.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteDialogForm: public Ui_deleteDialogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPRESETFORM_H
