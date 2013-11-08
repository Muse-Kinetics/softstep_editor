// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef TABLES_H
#define TABLES_H

#include <QWidget>
#include <QMap>

class Tables : public QWidget
{
    Q_OBJECT
public:
    explicit Tables(QWidget *parent = 0);

    QMap<QString, unsigned char *> tableMap;

    signals:
    
public slots:
    
};

#endif // TABLES_H
