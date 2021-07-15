// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
/********************************************************************************
** Form generated from reading UI file 'pedalLiveTableForm.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDALLIVETABLEFORM_H
#define UI_PEDALLIVETABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PedalLiveTableForm
{
public:

    void setupUi(QWidget *PedalLiveTableForm)
    {
        if (PedalLiveTableForm->objectName().isEmpty())
            PedalLiveTableForm->setObjectName(QString::fromUtf8("PedalLiveTableForm"));
        PedalLiveTableForm->resize(400, 300);

        retranslateUi(PedalLiveTableForm);

        QMetaObject::connectSlotsByName(PedalLiveTableForm);
    } // setupUi

    void retranslateUi(QWidget *PedalLiveTableForm)
    {
        PedalLiveTableForm->setWindowTitle(QCoreApplication::translate("PedalLiveTableForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PedalLiveTableForm: public Ui_PedalLiveTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDALLIVETABLEFORM_H
