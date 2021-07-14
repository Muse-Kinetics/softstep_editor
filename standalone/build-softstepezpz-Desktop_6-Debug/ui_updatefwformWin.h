// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'updatefwformWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEFWFORMWIN_H
#define UI_UPDATEFWFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateFirmwareForm
{
public:
    QFrame *warningFrame;
    QFrame *warningSubFrame;
    QPushButton *update;
    QLabel *label_3;
    QPushButton *cancel;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *UpdateFirmwareForm)
    {
        if (UpdateFirmwareForm->objectName().isEmpty())
            UpdateFirmwareForm->setObjectName(QString::fromUtf8("UpdateFirmwareForm"));
        UpdateFirmwareForm->resize(241, 129);
        UpdateFirmwareForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"	font: 7pt \"Corbel\";\n"
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
"	font: 7pt \"Corbel\";\n"
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
"	font: 7pt \"Corbel\";\n"
"	background: rgba(0,174,239,0);\n"
"	border: 2px solid rgba(0,174,239,255);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focu"
                        "s\n"
"{\n"
"	font: 7pt \"Corbel\";\n"
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
"	font: 7pt \"Corbel\";\n"
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
"	font: 7pt \"Corbel\";\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border: 2px solid white;\n"
"	font: 7pt \"Corbel\";\n"
"	background: rgba(0,174,239,255);\n"
"	color: white;\n"
"}\n"
""));
        warningFrame = new QFrame(UpdateFirmwareForm);
        warningFrame->setObjectName(QString::fromUtf8("warningFrame"));
        warningFrame->setGeometry(QRect(0, 0, 241, 129));
        QFont font;
        font.setPointSize(7);
        warningFrame->setFont(font);
        warningFrame->setFocusPolicy(Qt::NoFocus);
        warningFrame->setStyleSheet(QString::fromUtf8(""));
        warningFrame->setFrameShape(QFrame::StyledPanel);
        warningFrame->setFrameShadow(QFrame::Raised);
        warningSubFrame = new QFrame(warningFrame);
        warningSubFrame->setObjectName(QString::fromUtf8("warningSubFrame"));
        warningSubFrame->setGeometry(QRect(8, 8, 224, 113));
        warningSubFrame->setFont(font);
        warningSubFrame->setFocusPolicy(Qt::NoFocus);
        warningSubFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background:rgba(200, 200, 200, 0);\n"
"	border-bottom-left-radius:4.0;\n"
"	border-bottom-right-radius:4.0;\n"
"	border-top-left-radius:4.0;\n"
"	border-top-right-radius:4.0;\n"
"	border:none;\n"
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
        update->setGeometry(QRect(115, 80, 51, 20));
        update->setFocusPolicy(Qt::NoFocus);
        update->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(warningSubFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 224, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Corbel")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        label_3->setFont(font1);
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt;"));
        label_3->setAlignment(Qt::AlignCenter);
        cancel = new QPushButton(warningSubFrame);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(55, 80, 51, 20));
        cancel->setFocusPolicy(Qt::NoFocus);
        cancel->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(warningSubFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 35, 224, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Corbel")});
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        label_4->setFont(font2);
        label_4->setFocusPolicy(Qt::NoFocus);
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(warningSubFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 49, 224, 21));
        label_5->setFont(font2);
        label_5->setFocusPolicy(Qt::NoFocus);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignCenter);
        update->raise();
        label_3->raise();
        cancel->raise();
        label_5->raise();
        label_4->raise();

        retranslateUi(UpdateFirmwareForm);

        QMetaObject::connectSlotsByName(UpdateFirmwareForm);
    } // setupUi

    void retranslateUi(QWidget *UpdateFirmwareForm)
    {
        UpdateFirmwareForm->setWindowTitle(QCoreApplication::translate("UpdateFirmwareForm", "Form", nullptr));
        update->setText(QCoreApplication::translate("UpdateFirmwareForm", "UPDATE", nullptr));
        label_3->setText(QCoreApplication::translate("UpdateFirmwareForm", "Update/Reload firmware?", nullptr));
        cancel->setText(QCoreApplication::translate("UpdateFirmwareForm", "CANCEL", nullptr));
        label_4->setText(QCoreApplication::translate("UpdateFirmwareForm", "This will reload the factory presets", nullptr));
        label_5->setText(QCoreApplication::translate("UpdateFirmwareForm", "to the connected SoftStep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateFirmwareForm: public Ui_UpdateFirmwareForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEFWFORMWIN_H
