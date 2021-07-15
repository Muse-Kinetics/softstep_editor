// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'keyBoxForm.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOXFORM_H
#define UI_KEYBOXFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyBoxForm
{
public:
    QFrame *keyBoxFrame;
    QToolButton *keyBackground;
    QToolButton *openWindow;
    QLineEdit *keyName;

    void setupUi(QWidget *keyBoxForm)
    {
        if (keyBoxForm->objectName().isEmpty())
            keyBoxForm->setObjectName(QString::fromUtf8("keyBoxForm"));
        keyBoxForm->resize(101, 64);
        keyBoxForm->setAutoFillBackground(false);
        keyBoxForm->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background:		rgb(60, 60, 60);\n"
"	border: 3px solid rgb(0,174,239);\n"
"}\n"
"\n"
"/* ---------- QLabels ------------*/\n"
"QLabel\n"
"{\n"
"	background:		none;\n"
"	color: 				white;\n"
"	font: 				10pt \"Futura\";\n"
"	border:				none;\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	border:				none;\n"
"}\n"
"\n"
"/*---------- QPushButton ---------*/\n"
"QToolButton\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/openkeywindow1_inactive.png);\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/openkeywindow1_active.png);\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 12pt \"Droid Sans Mono\";\n"
"	background: rgb(40, 40, 40);\n"
"	border: 2px solid rgb(0,174,239);\n"
"	border-radius: 0px;\n"
"	color: white;\n"
"	padding-left: 2px;\n"
"	padding-bottom: 2px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border: 2px solid white;\n"
"	outline: none;\n"
"}\n"
"\n"
"/*-------QToolTip-"
                        "------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Futura\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"	width: 22px;\n"
"}"));
        keyBoxFrame = new QFrame(keyBoxForm);
        keyBoxFrame->setObjectName(QString::fromUtf8("keyBoxFrame"));
        keyBoxFrame->setGeometry(QRect(0, 0, 101, 64));
        keyBoxFrame->setFrameShape(QFrame::StyledPanel);
        keyBoxFrame->setFrameShadow(QFrame::Raised);
        keyBackground = new QToolButton(keyBoxFrame);
        keyBackground->setObjectName(QString::fromUtf8("keyBackground"));
        keyBackground->setGeometry(QRect(0, 0, 101, 64));
        keyBackground->setStyleSheet(QString::fromUtf8("image: none;"));
        openWindow = new QToolButton(keyBoxFrame);
        openWindow->setObjectName(QString::fromUtf8("openWindow"));
        openWindow->setGeometry(QRect(7, 13, 40, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura")});
        font.setPointSize(10);
        openWindow->setFont(font);
        keyName = new QLineEdit(keyBoxFrame);
        keyName->setObjectName(QString::fromUtf8("keyName"));
        keyName->setGeometry(QRect(52, 21, 40, 26));
#if QT_CONFIG(tooltip)
        keyName->setToolTip(QString::fromUtf8("<b>Key Name</b><p>Set the name of this key."));
#endif // QT_CONFIG(tooltip)
        keyName->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	padding-top: 1px;\n"
"}"));
        keyName->setInputMethodHints(Qt::ImhNone);
        keyName->setMaxLength(4);
        keyName->setAlignment(Qt::AlignCenter);

        retranslateUi(keyBoxForm);

        QMetaObject::connectSlotsByName(keyBoxForm);
    } // setupUi

    void retranslateUi(QWidget *keyBoxForm)
    {
        keyBoxForm->setWindowTitle(QCoreApplication::translate("keyBoxForm", "Form", nullptr));
#if QT_CONFIG(tooltip)
        keyBackground->setToolTip(QCoreApplication::translate("keyBoxForm", "Click this key box to<br> select it for copy/paste functionality", nullptr));
#endif // QT_CONFIG(tooltip)
        keyBackground->setText(QString());
#if QT_CONFIG(tooltip)
        openWindow->setToolTip(QCoreApplication::translate("keyBoxForm", "Open this key's modulation window.", nullptr));
#endif // QT_CONFIG(tooltip)
        openWindow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class keyBoxForm: public Ui_keyBoxForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOXFORM_H
