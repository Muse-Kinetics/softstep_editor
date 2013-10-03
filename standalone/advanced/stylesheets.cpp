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



    /*//Modline 2
    file = new QFile(":/resources/modline_enable2_stylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        modlineEnable2StyleSheet = QTextStream(file).readAll();
        qDebug() << modlineEnable2StyleSheet;
    }

    file->close();

    //Modline 3
    file = new QFile(":/resources/modline_enable3_stylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        modlineEnable3StyleSheet = QTextStream(file).readAll();
        qDebug() << modlineEnable3StyleSheet;
    }

    file->close();

    //Modline 4
    file = new QFile(":/resources/modline_enable4_stylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        modlineEnable4StyleSheet = QTextStream(file).readAll();
        qDebug() << modlineEnable4StyleSheet;
    }

    file->close();

    //Modline 5
    file = new QFile(":/resources/modline_enable5_stylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        modlineEnable5StyleSheet = QTextStream(file).readAll();
        qDebug() << modlineEnable5StyleSheet;
    }

    file->close();

    //Modline 6
    file = new QFile(":/resources/modline_enable6_stylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        modlineEnable6StyleSheet = QTextStream(file).readAll();
        qDebug() << modlineEnable6StyleSheet;
    }

    file->close();*/
}
