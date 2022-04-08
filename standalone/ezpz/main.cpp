// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include <QApplication>
#include "mainwindow.h"

#include<stdio.h>

int main(int argc, char *argv[])
{
    // set highdpi scale factor rounding
    //QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    //double scale = width / minWidth;
    //qDebug() << "scale: " << scale;
#ifdef Q_OS_WIN
    double scale = 1.5;
#else
    double scale = 1;
#endif
    std::string scaleAsString = std::to_string(scale);
    QByteArray scaleAsQByteArray(scaleAsString.c_str(), scaleAsString.length());
    qputenv("QT_SCALE_FACTOR", scaleAsQByteArray);
    qputenv("QT_SCALE_FACTOR_ROUNDING_POLICY", "Round");

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SoftStep Basic Editor");
    w.setFixedSize(w.size());
    w.show();
    return a.exec();
}
