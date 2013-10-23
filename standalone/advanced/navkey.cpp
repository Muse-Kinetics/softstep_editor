// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navkey.h"

//-------NAV PAD WINDOW SIZE CONSTANTS------------//
#define NAVWINDOW_LG_WIDTH 1118
#define NAVWINDOW_SM_WIDTH 935
#define NAVWINDOW_HEIGHT 410

//-------NAV BOX SIZE CONSTANTS-------//
#define NAVBOX_WIDTH 101
#define NAVBOX_HEIGHT 64
#define NAVBOX_STARTING_X_POS 579
#define NAVBOX_STARTING_Y_POS 228

//-------NAV PAD WINDOW LINE SEPARATOR WIDTHS-------//
#define LINE_SEPARATOR_LG 1098
#define LINE_SEPARATOR_SM 915

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
    navKeyWindowWidget->setFixedSize(NAVWINDOW_SM_WIDTH,NAVWINDOW_HEIGHT);
    navKeyWindowWidget->setGeometry(220, 600, NAVWINDOW_SM_WIDTH, NAVWINDOW_HEIGHT);
    navKeyWindowWidget->setWindowTitle(QString("Nav Pad Modulation"));

    //what's in the nav pad box?
    connect(navBoxForm->openNavWindow, SIGNAL(clicked()), this, SLOT(slotOpenWindow()));

    //what's in the nav pad window?
    for(int i = 0; i < 6; i++)
    {
        navModline[i] = new NavModline(navKeyWindowWidget, i); //construct modlines
        navModline[i]->slotConnectElements(); //connect modlines
        displayLinkedButtonGroup.addButton(navModline[i]->displayLinkButton, i);
    }
    connect(navKeyWindowForm->showLEDSettings, SIGNAL(toggled(bool)), this, SLOT(slotShowDisplaySettings(bool)));
    connect(navKeyWindowForm->addmodline, SIGNAL(clicked()), this, SLOT(slotAddSubtractModlines()));
    connect(navKeyWindowForm->deletemodline, SIGNAL(clicked()), this, SLOT(slotAddSubtractModlines()));
}

void NavKey::slotOpenWindow()
{
    navKeyWindowWidget->show();
}

void NavKey::slotConnectElements()
{
    //nav name (from the nav box form)
    connect(navBoxForm->keyName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));
    connect(navBoxForm->keyName, SIGNAL(textEdited(QString)), navKeyWindowForm->keyname, SLOT(setText(QString)));
    connect(navKeyWindowForm->keyname, SIGNAL(textEdited(QString)), navBoxForm->keyName, SLOT(setText(QString)));

    //nav modulation window stuff
    connect(navKeyWindowForm->navpadmode_modline, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->navpadmode_programchange, SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //display stuff
    connect(navKeyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    connect(navKeyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
}

void NavKey::slotDisconnectElements()
{
    //nav name (from the nav box form)
    disconnect(navBoxForm->keyName, SIGNAL(textEdited(QString)), this, SLOT(slotValueChanged()));

    //nav modulation window stuff
    disconnect(navKeyWindowForm->navpadmode_modline, SIGNAL(clicked()),this,SLOT(slotValueChanged()));
    disconnect(navKeyWindowForm->navpadmode_programchange, SIGNAL(clicked()),this,SLOT(slotValueChanged()));

    //display stuff
    disconnect(navKeyWindowForm->displayprefix,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(navKeyWindowForm->keyname,SIGNAL(textChanged(QString)),this,SLOT(slotValueChanged()));
    disconnect(navKeyWindowForm->leddisplaymode,SIGNAL(currentIndexChanged(int)),this,SLOT(slotValueChanged()));
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
        //display stuff
        else if(sender == navKeyWindowForm->displayprefix)
        {
            jsonName = "prefix";
            value = navKeyWindowForm->displayprefix->text();
        }
        else if(sender == navKeyWindowForm->keyname)
        {
            jsonName = "name";
            value = navKeyWindowForm->keyname->text();
        }
        else if(sender == navKeyWindowForm->leddisplaymode)
        {
            jsonName = "displaymode";
            value = navKeyWindowForm->leddisplaymode->currentText();
        }

        emit signalStoreValue(QString("nav_%1").arg(jsonName), value, -1);
    }
    emit signalCheckSavedState();
}

void NavKey::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    slotDisconnectElements();

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

    //display stuff
    navKeyWindowForm->displayprefix->setText(preset.value(QString("nav_prefix")).toString());
    navKeyWindowForm->keyname->setText(preset.value(QString("nav_name")).toString());
    navKeyWindowForm->leddisplaymode->setCurrentIndex(navKeyWindowForm->leddisplaymode->findText(preset.value(QString("nav_displaymode")).toString()));

    slotConnectElements();
}

void NavKey::slotShowDisplaySettings(bool show)
{
    if(show == TRUE)
    {
        //show large window
        navKeyWindowWidget->setFixedWidth(NAVWINDOW_LG_WIDTH);
        //show large line separator
        navKeyWindowForm->label->setFixedWidth(LINE_SEPARATOR_LG);
    }
    else
    {
        //show small window
        navKeyWindowWidget->setFixedWidth(NAVWINDOW_SM_WIDTH);
        //show small line separator
        navKeyWindowForm->label->setFixedWidth(LINE_SEPARATOR_SM);
    }
}

void NavKey::slotWindowHeight(int modlinesShowing)
{
    if(modlinesShowing == 2)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-188);
        navKeyWindowForm->addmodline->setGeometry(9,192,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,192,22,22);
        navModline[2]->hide();
        navModline[3]->hide();
        navModline[4]->hide();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 3)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-141);
        navKeyWindowForm->addmodline->setGeometry(9,239,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,239,22,22);
        navModline[2]->show();
        navModline[3]->hide();
        navModline[4]->hide();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 4)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-94);
        navKeyWindowForm->addmodline->setGeometry(9,286,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,286,22,22);
        navModline[2]->show();
        navModline[3]->show();
        navModline[4]->hide();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 5)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT-47);
        navKeyWindowForm->addmodline->setGeometry(9,333,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,333,22,22);
        navModline[2]->show();
        navModline[3]->show();
        navModline[4]->show();
        navModline[5]->hide();
    }
    else if(modlinesShowing == 6)
    {
        navKeyWindowWidget->setFixedHeight(NAVWINDOW_HEIGHT);
        navKeyWindowForm->addmodline->setGeometry(9,380,22,22);
        navKeyWindowForm->deletemodline->setGeometry(35,380,22,22);
        navModline[2]->show();
        navModline[3]->show();
        navModline[4]->show();
        navModline[5]->show();
    }
}

void NavKey::slotRecallShowModlines(QVariantMap preset, QVariantMap)
{
    numModlines = 2;

    //first determine how many modlines should be showing based on which preset is recalled
    for(int i = 0; i < 6; i++)
    {
        bool modlineEnabled;

        modlineEnabled = preset.value(QString("nav_modline%1_enable").arg(i+1)).toBool();

        if(i>1 && modlineEnabled == TRUE)
        {
            numModlines = i+1;
        }
    }

    slotWindowHeight(numModlines);

    //qDebug() << QString("show %1 nav modlines").arg(numModlines);
}

void NavKey::slotAddSubtractModlines()
{
    //then add or subtract modlines when the buttons are clicked
    if(QObject::sender())
    {
        QObject *sender = QObject::sender();

        if(sender == navKeyWindowForm->addmodline)
        {
            numModlines++;
        }
        else if(sender == navKeyWindowForm->deletemodline)
        {
            numModlines--;
        }
    }
    if(numModlines > 6)
    {
        numModlines = 6;
        navKeyWindowForm->addmodline->setCheckable(FALSE);
    }
    else if(numModlines < 2)
    {
        numModlines = 2;
        navKeyWindowForm->deletemodline->setCheckable(FALSE);
    }
    else
    {
        navKeyWindowForm->addmodline->setCheckable(TRUE);
        navKeyWindowForm->deletemodline->setCheckable(TRUE);
    }

    slotWindowHeight(numModlines);
    //qDebug() << QString("show %1 nav modlines").arg(numModlines);
}
