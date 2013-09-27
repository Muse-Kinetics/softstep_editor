// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    presetInterface = new PresetInterface();

    //Mainwindow Ui
    this->setWindowTitle("SoftStep Advanced Editor");  //FIND OUT WHY THIS ISN'T WORKING!?
    ui->setupUi(this);
    this->setFixedSize(995,344);

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i] = new Key(this, i);
    }

    this->installEventFilter(this);

    slotConnectInterfaces();

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i]->slotConnectElements();
    }

    presetInterface->slotRecallPreset(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConnectInterfaces()
{
    //--------------------------------------- Preset Recall

    //Keys
    for(int k = 0; k < 10; k++)
    {
        connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));

        //Modlines
        for(int m = 0; m < 6; m++)
        {
            connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), key[k]->modline[m], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));
        }
    }

    //Nav Pad


    //--------------------------------------- Parameter Storage

    //Keys
    for(int k = 0; k < 10; k++)
    {
        connect(key[k], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));

        //Modlines
        for(int m = 0; m < 6; m++)
        {
            connect(key[k]->modline[m], SIGNAL(signalStoreValue(QString,QVariant,int)), presetInterface, SLOT(slotStoreValue(QString,QVariant,int)));
        }
    }

    //Nav Pad


    //Update Button
    connect(ui->update, SIGNAL(clicked()), presetInterface, SLOT(slotUpdateClicked()));

    //preset number box (this will be switched to a comboBox soon)
    connect(ui->presetNumber, SIGNAL(valueChanged(int)), presetInterface, SLOT(slotRecallPreset(int)));
}
