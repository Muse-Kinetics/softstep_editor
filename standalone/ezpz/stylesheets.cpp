// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "stylesheets.h"
#include <QDebug>

StyleSheets::StyleSheets()
{


    //------ Send Button
    //Dirty
    file = new QFile(":/resources/sendbuttondirtystylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        sendButtonDirtyStyleSheet = QTextStream(file).readAll();
        //qDebug() << sendButtonDirtyStyleSheet;
    }

    file->close();

    //Clean
    file = new QFile(":/resources/sendbuttoncleanstylesheet.qss");
    if(file->open(QIODevice::ReadOnly))
    {
        sendButtonCleanStyleSheet = QTextStream(file).readAll();
        qDebug() << sendButtonCleanStyleSheet;
    }

    file->close();
}
