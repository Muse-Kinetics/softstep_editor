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
#define NAVBOX_STARTING_X_POS 579
#define NAVBOX_STARTING_Y_POS 228

NavKey::NavKey(QWidget *parent) :
    QWidget(parent),
    navBoxForm(new Ui::navBoxForm),
    navKeyWindowForm(new Ui::navKeyWindowForm),
    navBoxWidget(new QWidget(this)),
    navKeyWindowWidget(new QWidget())
{
    //set up the nav pad box
    navBoxForm->setupUi(navBoxWidget);
    navBoxWidget->setFixedSize(NAVBOX_WIDTH,NAVBOX_HEIGHT);

    this->setGeometry(NAVBOX_STARTING_X_POS, NAVBOX_STARTING_Y_POS, NAVBOX_WIDTH, NAVBOX_HEIGHT);

    //set ub the nav pad window
    navKeyWindowForm->setupUi(navKeyWindowWidget);
    navKeyWindowWidget->setFixedSize(NAVWINDOW_WIDTH,NAVWINDOW_HEIGHT);
    navKeyWindowWidget->setWindowTitle(QString("Nav Pad Modulation"));

    //what's in the nav pad box?
    connect(navBoxForm->openNavWindow, SIGNAL(clicked()), this, SLOT(slotOpenWindow()));

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
    connect(navBoxForm->keyName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));

    //nav modulation window stuff
    connect(navKeyWindowForm->navpadmode_modline, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->navpadmode_programchange, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
}

void NavKey::slotValueChanged()
{
    if(QObject::sender())
    {
        QString jsonName;
        QObject *sender = QObject::sender();
        QVariant value;

        //nav name
        if(sender == navBoxForm->keyName)
        {
            jsonName = "name";
            value = navBoxForm->keyName->text();
        }
        else if(sender == navKeyWindowForm->navpadmode_modline)
        {
            jsonName = "modlinemode";
            value = 0;
        }
        else if(sender == navKeyWindowForm->navpadmode_programchange)
        {
            jsonName = "modlinemode";
            value = 1;
        }

        emit signalStoreValue(QString("nav_%1").arg(jsonName), value, -1);
    }
    emit signalCheckSavedState();
}

void NavKey::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    navBoxForm->keyName->setText(preset.value(QString("nav_name")).toString());

    //this stuff is to determine the modlinemode (0 is for modline, 1 is for programchange... this can be changed)
    int modlinemode = preset.value(QString("nav_modlinemode")).toInt();

    if(modlinemode == 0)
    {
        navKeyWindowForm->navpadmode_modline->setChecked(TRUE);
        navKeyWindowForm->navpadmode_programchange->setChecked(FALSE);
    }
    else if(modlinemode == 1)
    {
        navKeyWindowForm->navpadmode_modline->setChecked(FALSE);
        navKeyWindowForm->navpadmode_programchange->setChecked(TRUE);
    }
}
