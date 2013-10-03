// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "stylesheets.h"
#include <QDebug>

StyleSheets::StyleSheets()
{


    //////////////// MODLINE ENABLE CHECKBOXES ////////////////

    //Modline 1
    file = new QFile(":/resources/modline_enable1_stylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        modlineEnable1StyleSheet = QTextStream(file).readAll();
        qDebug() << modlineEnable1StyleSheet;
    }

    file->close();

    //Modline 2
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

    file->close();
}
