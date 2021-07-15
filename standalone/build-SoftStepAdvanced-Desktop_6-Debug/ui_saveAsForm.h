// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'saveAsForm.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEASFORM_H
#define UI_SAVEASFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saveAsDialogForm
{
public:
    QLineEdit *name;
    QToolButton *cancel;
    QToolButton *save;
    QLabel *label;

    void setupUi(QWidget *saveAsDialogForm)
    {
        if (saveAsDialogForm->objectName().isEmpty())
            saveAsDialogForm->setObjectName(QString::fromUtf8("saveAsDialogForm"));
        saveAsDialogForm->resize(150, 113);
        saveAsDialogForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:	 rgb(40, 40, 40);\n"
"	border: 3px solid rgb(0,174,239);\n"
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
"	font: 8px \"Futura\";\n"
"	color: white;\n"
"	border: 2px solid rgb(0, 174, 239);\n"
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
"	font: 8px \"Futura\";\n"
"	color: white;\n"
"	border: 2px solid rgb(0, 174, 239);\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background-color: rgb(0, 174, 239);\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 10pt \"Futura\";\n"
"	background: rgb(18, 18, 18);\n"
"	border: 2px solid rgb(0, 174, 239);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	pa"
                        "dding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	font: 10pt \"Futura\";\n"
"	background: rgb(18, 18, 18);\n"
"	border: 1px solid rgb(0, 174, 239);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"/*-------QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Futura\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	width: 22px;\n"
"}"));
        name = new QLineEdit(saveAsDialogForm);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(19, 44, 113, 22));
        cancel = new QToolButton(saveAsDialogForm);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(24, 80, 46, 22));
        save = new QToolButton(saveAsDialogForm);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(81, 80, 46, 22));
        label = new QLabel(saveAsDialogForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(19, 8, 113, 28));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(saveAsDialogForm);

        QMetaObject::connectSlotsByName(saveAsDialogForm);
    } // setupUi

    void retranslateUi(QWidget *saveAsDialogForm)
    {
        saveAsDialogForm->setWindowTitle(QCoreApplication::translate("saveAsDialogForm", "Save As...", nullptr));
#if QT_CONFIG(tooltip)
        name->setToolTip(QCoreApplication::translate("saveAsDialogForm", "You shall be called...", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cancel->setToolTip(QCoreApplication::translate("saveAsDialogForm", "I've changed my mind. <br>I don't want a new preset. Not yet...", nullptr));
#endif // QT_CONFIG(tooltip)
        cancel->setText(QCoreApplication::translate("saveAsDialogForm", "CANCEL", nullptr));
#if QT_CONFIG(tooltip)
        save->setToolTip(QCoreApplication::translate("saveAsDialogForm", "Saves a shiny, new preset.", nullptr));
#endif // QT_CONFIG(tooltip)
        save->setText(QCoreApplication::translate("saveAsDialogForm", "SAVE AS", nullptr));
        label->setText(QCoreApplication::translate("saveAsDialogForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Futura'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">What's my name?</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saveAsDialogForm: public Ui_saveAsDialogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEASFORM_H
