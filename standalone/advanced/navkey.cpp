// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navkey.h"

//-------NAV PAD WINDOW SIZE CONSTANTS------------//
#define NAVWINDOW_WIDTH 1118
#define NAVWINDOW_HEIGHT 400

//-------NAV BOX SIZE CONSTANTS-------//
#define NAVBOX_WIDTH 101
#define NAVBOX_HEIGHT 64
#define NAVBOX_STARTING_X_POS 10
#define NAVBOX_STARTING_Y_POS 228

NavKey::NavKey(QWidget *parent) :
    QWidget(parent)
{
    //set up the nav pad box
    navBoxWidget = new QWidget(this);
    navBoxForm->setupUi(navBoxWidget);
    navBoxWidget->setFixedSize(NAVBOX_WIDTH,NAVBOX_HEIGHT);

    this->setGeometry(NAVBOX_STARTING_X_POS, NAVBOX_STARTING_Y_POS, NAVBOX_WIDTH, NAVBOX_HEIGHT);

    //set ub the nav pad window
    navKeyWindowWidget = new QWidget();
    navKeyWindowForm->setupUi(navKeyWindowWidget);
    navKeyWindowWidget->setFixedSize(NAVWINDOW_WIDTH,NAVWINDOW_HEIGHT);
    navKeyWindowWidget->setWindowTitle(QString("Nav Pad Modulation"));

    //what's in the nav pad box?
    //connect(navBoxForm->openWindow, SIGNAL(clicked()), this, SLOT(slotOpenWindow()));

    //what's in the nav pad window?
    for(int i = 0; i < 6; i++)
    {
        navModline[i] = new NavModline(navKeyWindowWidget, i); //construct modlines
        navModline[i]->slotConnectElements(); //connect modlines
    }
}

void NavKey::slotOpenWindow()
{
    navKeyWindowWidget->show();
}

void NavKey::slotConnectElements()
{
    //nav name (from the nav box form)

    //nav counter stuff?
}

void NavKey::slotValueChanged()
{
    //nav name stuff
}

void NavKey::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    //recalling stuff for nav name
}
