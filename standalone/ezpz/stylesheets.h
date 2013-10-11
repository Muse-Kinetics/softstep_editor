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

    QString sendButtonDirtyStyleSheet;
    QString sendButtonCleanStyleSheet;
    QString sendButtonDirtyStyleSheet_windows;
    QString sendButtonCleanStyleSheet_windows;
};

#endif // STYLESHEETS_H
