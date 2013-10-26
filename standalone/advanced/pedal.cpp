// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "pedal.h"

Pedal::Pedal(QWidget *parent) :
    QWidget(parent)
{

    pixmap.load(QString::fromUtf8("resources/pedal_top.png"));

    QPainter painter(&pixmap);
    painter.rotate(90);
    painter.translate(22, 66);

}


void Pedal::slotSetLeverPointer(QLabel *lever)
{
    pedallever = lever;
    pedallever->setPixmap(pixmap);
    pedallever->setText("Chomsky");
    pedallever->show();
}

void Pedal::slotRotateLever(int degrees)
{

}
