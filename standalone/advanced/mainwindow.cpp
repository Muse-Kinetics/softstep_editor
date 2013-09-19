// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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

    //slotConnectInterfaces();

    //Construct Key Windows
    for(int i = 0; i < 10; i++)
    {
        key[i]->slotConnectElements();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::slotConnectInterfaces()
{
    for(init i = 0; i < 6; i++)
    {
        //connect(presetInterface, SIGNAL(signalRecallPreset(QVariantMap,QVariantMap)), modline[i], SLOT(slotRecallPreset(QVariantMap, QVariantMap)));
    }
}
*/
