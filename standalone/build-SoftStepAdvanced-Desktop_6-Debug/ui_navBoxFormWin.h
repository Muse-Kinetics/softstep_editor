// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'navBoxFormWin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVBOXFORMWIN_H
#define UI_NAVBOXFORMWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_navBoxForm
{
public:
    QPushButton *openNavWindow;
    QLineEdit *keyName;

    void setupUi(QWidget *navBoxForm)
    {
        if (navBoxForm->objectName().isEmpty())
            navBoxForm->setObjectName(QString::fromUtf8("navBoxForm"));
        navBoxForm->resize(101, 64);
        navBoxForm->setStyleSheet(QString::fromUtf8("QWidget\n"
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
"	font: 				10pt \"Futura-Normal\";\n"
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
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/openkeywindowNav_inactive.png)\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"	image: url(:/resources/openkeywindowNav_active.png);\n"
"}\n"
"\n"
"/* ---------- QLineEdit ------------*/\n"
"QLineEdit\n"
"{\n"
"	font: 10pt \"Droid Sans Mono\";\n"
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
"/*------"
                        "-QToolTip-------*/\n"
"QToolTip\n"
"{\n"
"	font: 10px \"Corbel\";\n"
"	color: rgb(255, 255, 255);\n"
"	background: rgba(40, 40, 40, 140);\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	padding: 2px;\n"
"}"));
        openNavWindow = new QPushButton(navBoxForm);
        openNavWindow->setObjectName(QString::fromUtf8("openNavWindow"));
        openNavWindow->setGeometry(QRect(7, 13, 38, 38));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura")});
        font.setPointSize(10);
        openNavWindow->setFont(font);
        keyName = new QLineEdit(navBoxForm);
        keyName->setObjectName(QString::fromUtf8("keyName"));
        keyName->setGeometry(QRect(52, 21, 40, 26));
        keyName->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	padding-bottom: -1px;\n"
"}"));
        keyName->setMaxLength(4);
        keyName->setAlignment(Qt::AlignCenter);

        retranslateUi(navBoxForm);

        QMetaObject::connectSlotsByName(navBoxForm);
    } // setupUi

    void retranslateUi(QWidget *navBoxForm)
    {
        navBoxForm->setWindowTitle(QCoreApplication::translate("navBoxForm", "Form", nullptr));
#if QT_CONFIG(tooltip)
        openNavWindow->setToolTip(QCoreApplication::translate("navBoxForm", "Open this key's modulation window.", nullptr));
#endif // QT_CONFIG(tooltip)
        openNavWindow->setText(QString());
#if QT_CONFIG(tooltip)
        keyName->setToolTip(QCoreApplication::translate("navBoxForm", "Key Name<p>Set the name of this key.", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class navBoxForm: public Ui_navBoxForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVBOXFORMWIN_H
