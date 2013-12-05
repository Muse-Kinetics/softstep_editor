// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef PEDAL_H
#define PEDAL_H

#include <QWidget>
#include <QtGui>

class Pedal : public QWidget
{
    Q_OBJECT
public:
    explicit Pedal(QWidget *parent = 0);

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

    bool    calibrating;
    
signals:
    
public slots:

    void slotSetLeverPointer(QLabel *lever);
    void slotRotateLever(int degrees);

    //--------------------------------------- Midi Input Processing
    int slotWindowInput(int pedalInput); //Windowing takes place here
    
    //--------------------------------------- Calibration
    void slotStartCalibrate();
    void slotCalibrate(int pedalInput);
    void slotStopCalibrate();
    void slotResetCalibrate();
    void slotWritePedalTableFile();

};

#endif // PEDAL_H
