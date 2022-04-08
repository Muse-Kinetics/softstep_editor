// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "scrolleventfilter.h"
#include <QToolTip>

ScrollEventFilter::ScrollEventFilter(QObject *parent) :
    QObject(parent)
{
    //qDebug() << "ScrollEventFilter called: " << parent->objectName();
    toolTipsOn = true;
}

bool ScrollEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    //qDebug() << "scroll::eventFilter called - name: " << obj->objectName() << " eventType: " << event->type();

    QWidget *widget = reinterpret_cast<QWidget *>(obj);

    //Scroll wheel, on combos, spinboxes
    if (event->type() == QEvent::Wheel)
    {
        if (!widget->underMouse() && obj->objectName() != "" && obj->objectName() != "qt_scrollarea_viewport")
        {
            //qDebug() << "scroll::eventFilter blocked underMouse() - name: " << obj->objectName() << " eventType: " << event->type();
            return true;
        }
        if (obj->objectName() == "presetmenu")
        {
            //qDebug() << "scroll::eventFilter blocked preset menu - name: " << obj->objectName() << " eventType: " << event->type();
            return true;
        }
        if (obj->objectName() == "" || obj->objectName() == "qt_scrollarea_viewport")
        {
            //qDebug() << "scroll::eventFilter wheel event allowed - name: " << obj->objectName() << " eventType: " << event->type();
            return QObject::eventFilter(obj, event);
        }
        // we want to block: "presetmenu"  eventType:  QEvent::Wheel
        //qDebug() << "scroll::eventFilter blocked - name: " << obj->objectName() << " eventType: " << event->type();

        return true;
    }

    //Tooltips
    else if(event->type() == QEvent::ToolTip && !toolTipsOn)
    {
        qDebug() << "tooltip";
        return true;
    }
    //ELSE
    else
    {
        //qDebug() << "scroll::eventFilter allowed - name: " << obj->objectName() << " eventType: " << event->type();

        //qDebug() << "other event";
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
    qDebug() << "Shouldn't go here!!";
}
