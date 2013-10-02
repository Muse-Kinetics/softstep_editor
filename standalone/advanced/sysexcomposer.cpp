// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "sysexcomposer.h"

#include "QDebug"
#include "QApplication"

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maxapi.h"
#include "utils.h"
//#include "softstep.h"
#include "query.h"
#include "attribute.h"
}

SysExComposer::SysExComposer(QWidget *parent) :
    QWidget(parent)
{
    slotGetEmbeddedVersion();
    isSoftStep2 = false;
}

void SysExComposer::slotGetEmbeddedVersion()
{
    t_softstep *x = softstep_init();

    QString sysExPath = QCoreApplication::applicationDirPath(); //get bundle path

#if defined(Q_OS_MAC) && !defined(QT_DEBUG)
    sysExPath.remove(sysExPath.length() - 5, sysExPath.length()); //Remove "MacOS" from path string
    sysExPath.append("Resources/SoftStep.syx");

#else
    sysExPath = QString("./SoftStep.syx");
#endif

#ifdef Q_OS_MAC
    FILE *fd = fopen(sysExPath.toUtf8(),"r");
#else
    FILE *fd = fopen(sysExPath.toUtf8(),"rb");
#endif

    if (fd)
    {
        int fchar;

        fseek(fd, 0l, SEEK_END);
        fwFileSize = ftell(fd);
        rewind(fd);

        fwFile = (unsigned char*)malloc(fwFileSize*sizeof(unsigned char));
        qDebug() << fread(fwFile,1,fwFileSize, fd);

        qDebug() << fwFile[fwFileSize - 1];

        rewind(fd);

        while ( (fchar = fgetc(fd)) != EOF)
        {
            softstep_midi_process(x,&x->version_embedded,fchar);
        }

        embeddedbuildNum = x->version_embedded.buildnum;
        embeddedVersion = QString(x->version_embedded.version);
    }
    else
    {
        embeddedbuildNum = -1;
        embeddedVersion = QString("Not Found");
        qDebug() << "______ SoftStep.syx not found. ______";
    }
}

void SysExComposer::slotComposeAttributeListFromPreset(QVariantMap presetSent, QVariantMap master, qlonglong presetNum)
{
    t_softstep *x = softstep_init();

    QMapIterator<QString, QVariant> i(presetSent);

    QVariantMap preset;

    /*while (i.hasNext())
    {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }*/

    //=========================================================================================================//
    //================================================= Settings ==============================================//
    //=========================================================================================================//

    //------------------------------------- Global -------------------------------------//
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Response",A_LONG,0l);
    attribute(x,3,A_SYM,"set",A_SYM,"Global_Gain",A_FLOAT,master.value("sensitivity").toFloat());   //-----
    //attribute(x,0,A_SYM,"set",A_SYM,"Pedal_Table",A_GIMME,-1);
    attribute(x,4,A_SYM,"set",A_SYM,"pedalEdges",A_LONG,127l, A_LONG,0l);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalHysteresis",A_LONG,7);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalFilterLength",A_LONG,5);
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!master.value("backlight").toInt());     //-----
    attribute(x,3,A_SYM,"set",A_SYM,"ProgramChangeInput",A_LONG,12);

    //--------------------------------------  Keys  ------------------------------------//
    for (long k=1;k<11;k++)
    {
        //Key Number
        attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,k);

        //Settings
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_X",A_LONG,16l);
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_X",A_LONG,85l);
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_Y",A_LONG,16l);
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,preset.value(QString("%1_key_setting_yAccel").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,85l);
        attribute(x,3,A_SYM,"set",A_SYM,"On_Sens",A_LONG,20l);
        attribute(x,3,A_SYM,"set",A_SYM,"Off_Sens",A_LONG,10l);
    }

    //------------------------------------- Nav Pad ------------------------------------//
    attribute(x,3,A_SYM,"set",A_SYM,"key",A_SYM,"nav");

    //Nav Settings
    attribute(x,3,A_SYM,"set",A_SYM,"North_On_Thresh",A_LONG,20l);
    attribute(x,3,A_SYM,"set",A_SYM,"North_Off_Thresh",A_LONG,10l);
    attribute(x,3,A_SYM,"set",A_SYM,"South_On_Thresh",A_LONG,20l);
    attribute(x,3,A_SYM,"set",A_SYM,"South_Off_Thresh",A_LONG,10l);
    attribute(x,3,A_SYM,"set",A_SYM,"East_On_Thresh",A_LONG,20l);
    attribute(x,3,A_SYM,"set",A_SYM,"East_Off_Thresh",A_LONG,10l);
    attribute(x,3,A_SYM,"set",A_SYM,"West_On_Thresh",A_LONG,20l);
    attribute(x,3,A_SYM,"set",A_SYM,"West_Off_Thresh",A_LONG,10l);
    attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,85l);

    //=========================================================================================================//
    //================================================== Preset ===============================================//
    //=========================================================================================================//


    //Scroll setlist, enumerating presets
    for (long p=0; p<setlist.size(); p++)
    {
        QVariantMap preset = setlist.at(p);

        attribute(x,2,A_SYM,"preset",A_LONG,p);
        attribute(x,3,A_SYM, "set",A_SYM,"Scene_Name",A_SYM,preset.value("displayname").toString().toUtf8().constData());

        for(long k = 1; k < 11; k++)
        {
            attribute(x,2,A_SYM,"key",A_LONG,k);
            attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM, preset.value(QString("key%1_name").arg(k)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,preset.value(QString("key%1_prefix").arg(k)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,preset.value(QString("key%1_displaymode").arg(k)).toLongLong());

            for(long m = 1; m < 7; m++ )
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m);
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,preset.value(QString("key%1_modline%2_on").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("key%1_modline%2_source").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("key%1_modline%2_gain").arg(k).arg(m)).toFloat());
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,preset.value(QString("key%1_modline%2_offset").arg(k).arg(m)).toFloat());
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("key%1_modline%2_table").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("key%1_modline%2_min").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("key%1_modline%2_max").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("key%1_modline%2_slew").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("key%1_modline%2_destination").arg(k).arg(m)).toString().toUtf8().constData());



                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,preset.value(QString("key%1_modline%2_ledred").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,preset.value(QString("key%1_modline%2_ledgreen").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,preset.value(QString("key%1_modline%2_displaylinked").arg(k).arg(m)).toString().toUtf8().constData());

            } //Modline loop
         } //Key loop
    }

    //=========================================================================================================//
    //================================================= Download ==============================================//
    //=========================================================================================================//
    attribute(x,1,A_SYM,"download");

    //qDebug() << "image" << image << "imageLength" << imageLength;
    //qDebug() << "settings" << settings << "settingsLength" << settingsLength;

    emit signalSendSysEx(QString("standalone image"), image, imageLength, QString("SSCOM Port 1"));
    qDebug("freeing image");
    free(image);

    emit signalSendSysEx(QString("standalone image"), settings, settingsLength, QString("SSCOM Port 1"));
    qDebug("freeing settings");
    free(settings);

    //sysex message complete
    emit signalUpdateComplete();
}

void SysExComposer::slotGetConnectedVersion(QByteArray msg)
{

    t_softstep *x = softstep_init();

    for(int i =0 ; i < msg.count(); i++)
    {
        softstep_midi_process(x,&x->version_connected, msg.at(i));
    }

    connectedBuildNum = x->version_connected.buildnum;
    connectedVersion = QString(x->version_connected.version);

    qDebug() << "_____ Connected:" << connectedBuildNum;
    qDebug() << "______ Embedded:" << embeddedbuildNum;

    emit signalSendBuildNums(connectedBuildNum, connectedVersion, embeddedbuildNum, embeddedVersion);
}

void SysExComposer::slotUpdateFirmware()
{
    qDebug() << "update firmware called" << fwFileSize;
    //QApplication::processEvents();
    emit signalSendSysEx(QString("update firmware"), (unsigned char*)fwFile, fwFileSize, QString("SSCOM Port 1"));
}
