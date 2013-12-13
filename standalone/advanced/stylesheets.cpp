// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "stylesheets.h"
#include <QDebug>

StyleSheets::StyleSheets()
{

    //////////////// MODLINE ENABLE CHECKBOXES ////////////////

    for(int i = 0; i < 6; i++)
    {
        //Set file path dynamically
        file = new QFile(QString(":/resources/modline_enable%1_stylesheet.qss").arg(i + 1));

        //If we successfully opened the file...
        if(file->open(QIODevice::ReadOnly))
        {
            //Append contents to out list of strings [QList<QString>]
            modlineEnableStyleSheet.append(QTextStream(file).readAll());
        }

        file->close();
    }

    //////////////// KEY BOX WINDOW OPEN BUTTONS ////////////////

    for(int i = 0; i < 10; i++)
    {
        //Set file path dynamically
        file = new QFile(QString(":/resources/keybox_openwindow%1_stylesheet.qss").arg(i + 1));

        //If we successfully opened the file...
        if(file->open(QIODevice::ReadOnly))
        {
            //Append contents to out list of strings [QList<QString>]
            keyBoxOpenButtonStyleSheet.append(QTextStream(file).readAll());
        }

        file->close();
    }

    ///////////////// KEY BOX SELECTION STYLESHEETS ////////////////
    file = new QFile(QString(":/resources/keybox_boxselected.qss"));
    if(file->open(QIODevice::ReadOnly))
    {
        //Append contents to out list of strings
        keyBoxSelectedStyleSheet = QTextStream(file).readAll();
    }
    file->close();
    file = new QFile(QString(":/resources/keybox_boxnotselected.qss"));
    if(file->open(QIODevice::ReadOnly))
    {
        keyBoxNotSelectedStyleSheet = QTextStream(file).readAll();
    }
    file->close();

    ///////////////// DEVICE LIST STYLESHEET //////////////////
    file = new QFile(QString(":/resources/devicestyle.qss"));
    if(file->open(QIODevice::ReadOnly))
    {
        deviceStyleSheet = QTextStream(file).readAll();
    }
    file->close();
}
