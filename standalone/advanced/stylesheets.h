// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef STYLESHEETS_H
#define STYLESHEETS_H

#include <QString>
#include <QFile>
#include <QTextStream>

class StyleSheets
{

    public:
        StyleSheets();

        QFile* file;

        /*QString modlineEnable1StyleSheet;
        QString modlineEnable2StyleSheet;
        QString modlineEnable3StyleSheet;
        QString modlineEnable4StyleSheet;
        QString modlineEnable5StyleSheet;
        QString modlineEnable6StyleSheet;*/

        QList<QString> modlineEnableStyleSheet;

};

#endif // STYLESHEETS_H
