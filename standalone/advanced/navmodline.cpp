// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "navmodline.h"

//constants for various modline arrangement parameters
#define MODLINE_WINDOW_WIDTH 1100
#define MODLINE_WINDOW_HEIGHT 42
#define MODLINE_SPACING 5
#define MODLINE_STARTING_X_POS 9
#define MODLINE_STARTING_Y_POS 98

NavModline::NavModline(QWidget *parent, int navInstanceNum) :
    QWidget(parent)
{
    navInstance = navInstanceNum;

    //-------------------------------- Set Up Ui
    QWidget *formWidget = new QWidget(this);

    navModlineForm.setupUi(formWidget);
    this->setFixedSize(MODLINE_WINDOW_WIDTH,MODLINE_WINDOW_HEIGHT);

    //navModlineForm.instanceLabel->setText(QString("%1").arg((navInstance +1)%10));
    //navModlineForm.deviceViews->setCurrentIndex(0);
    //navModlineForm.deviceViewLabels->setCurrentIndex(0);

    //connect and initialize the raw value to the result (not for presets)
    //connect(navModlineForm.raw,SIGNAL(valueChanged(int)),this,SLOT(slotRawResult()));
    //connect(navModlineForm.gain,SIGNAL(valueChanged(double)),this,SLOT(slotRawResult()));
    //connect(navModlineForm.offset,SIGNAL(valueChanged(int)),this,SLOT(slotRawResult()));
    //navModlineForm.raw->setValue(0);

    this->setGeometry(MODLINE_STARTING_X_POS, MODLINE_STARTING_Y_POS + ((navInstance)*(MODLINE_WINDOW_HEIGHT + MODLINE_SPACING)), MODLINE_WINDOW_WIDTH, MODLINE_WINDOW_HEIGHT);

    //dynamically set the stylesheet for the "enable" checkbox
    //navModlineForm.enable->setStyleSheet(stylesheets.modlineEnableStyleSheet.at(navInstance));
}

void NavModline::slotConnectElements()
{
    //enable checkbox
}

void NavModline::slotValueChanged()
{
    //enable checkbox
}

void NavModline::slotRecallPreset(QVariantMap preset, QVariantMap)
{
    //basic modline parameters
}

void NavModline::slotRawResult()
{
    //qDebug() << "initialize result value";
}
