// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef PEDAL_H
#define PEDAL_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QSlider>

class Pedal : public QWidget
{
    Q_OBJECT
public:
    explicit Pedal(QWidget *parent = 0, int keyInstance = -1);

    //Graphics
    QLabel* pedallever;
    QPixmap pixmap;

    //Calibrate
    QList<unsigned char> pedalValueList;
    QList<int>  pedalBucket;
    int         pedalSampleCount;
    int         pedalSampleSum;

    int     pedalValueListMin;
    int     pedalValueListMax;
    int     pedalValueListLength;

    int pedalAverage;

    bool    calibrating;

    QSlider* testValueSlider;
    QLabel *rockYourPedalLabel;
    QLabel *calibrationArrowsLabel;
    QLabel *calibrationCompleteLabel;

    int parentKeyInstance;
    
signals:
    void signalDrawTable(QList<unsigned char>);
    void signalLivePedalVal(int);
    void signalWriteTableToDisk(QByteArray);
    void signalResetOnZeroInput();

public slots:

    void slotSetLeverPointer(QLabel *lever);

    //--------------------------------------- Midi Input Processing
    int slotWindowInput(int pedalInput); //Windowing takes place here
    int slotTableInput(int pedalInput);
    
    //--------------------------------------- Calibration
    void slotStartCalibrate();
    void slotCalibrate(int pedalInput);
    void slotStopCalibrate();
    void slotResetCalibrate();
    void slotSetMinMaxLength();
    void slotWritePedalTableFile();
    void slotSetLivePedalValue(int val);
    void slotInitPedalTable(QByteArray table);
};

#endif // PEDAL_H
