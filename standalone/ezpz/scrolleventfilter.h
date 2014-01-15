// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SCROLLEVENTFILTER_H
#define SCROLLEVENTFILTER_H

#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QWidget>

class ScrollEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit ScrollEventFilter(QObject *parent = 0);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    
signals:
    
public slots:
    
};

#endif // SCROLLEVENTFILTER_H
