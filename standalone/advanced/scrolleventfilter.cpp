// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "scrolleventfilter.h"

ScrollEventFilter::ScrollEventFilter(QObject *parent) :
    QObject(parent)
{
}

bool ScrollEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    //qDebug() << "scroll event filter called";

    QWidget *widget = reinterpret_cast<QWidget *>(obj);

    if (!widget->underMouse() && event->type() == QEvent::Wheel)
    {
        return true;
    }
     else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
