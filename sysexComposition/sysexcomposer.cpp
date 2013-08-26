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
#include "softstep.h"
#include "query.h"
#include "attribute.h"
}

SysExComposer::SysExComposer(QWidget *parent) :
    QWidget(parent)
{

    slotGetEmbeddedVersion();

}

SysExComposer::~SysExComposer()
{
    //free(fwFile);
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

void SysExComposer::slotConstructDefaultAttributeList()
{

    QList<int> pedalTable;
    QList<int> pedalEdges;
    pedalEdges.append(127);
    pedalEdges.append(0);

    for(int i =0; i < 128; i++)
    {
        pedalTable.append(i);
    }

    defaultAttributeList.clear();

    //=========================================================================================================//
    //================================================= Settings ==============================================//
    //=========================================================================================================//

    //-------------------------------- Global Settings
    defaultAttributeList.insert("settings global", 0);
    defaultAttributeList.insert("attribute set Key_Response", 0);
    defaultAttributeList.insert("attribute set Global_Gain", 1.4961);
    //defaultAttributeList.insert("attribute set Pedal_Table", pedalTable);
    //defaultAttributeList.insert("attribute set pedalEdges", pedalEdges);
    defaultAttributeList.insert("pedalHysteresis", 7);
    defaultAttributeList.insert("attribute set pedalFilterLength", 5);
    defaultAttributeList.insert("attribute set EL_Mode", 0);
    defaultAttributeList.insert("attribute set ProgramChangeInput", 12);

    //------------------------------- Key Settings

    for(int i =0 ; i < 10; i++)
    {
        defaultAttributeList.insert("settings key", i + 1);
        defaultAttributeList.insert("attribute set Dead_X", 16);
        defaultAttributeList.insert("attribute set Accel_X", 85);
        defaultAttributeList.insert("attribute set Dead_Y", 16);
        defaultAttributeList.insert("attribute set Accel_Y", 85);
        defaultAttributeList.insert("attribute set On_Sens", 20);
        defaultAttributeList.insert("attribute set Off_Sens", 10);
    }

    //------------------------------ Nav Settings
    defaultAttributeList.insert("settings key nav", 0);
    defaultAttributeList.insert("attribute set West_Off_Thresh" ,10);
    defaultAttributeList.insert("attribute set West_On_Thresh", 20);
    defaultAttributeList.insert("attribute set East_Off_Thresh" ,10);
    defaultAttributeList.insert("attribute set East_On_Thresh", 20);
    defaultAttributeList.insert("attribute set South_Off_Thresh", 10);
    defaultAttributeList.insert("attribute set South_On_Thresh", 20);
    defaultAttributeList.insert("attribute set North_Off_Thresh", 10);
    defaultAttributeList.insert("attribute set North_On_Thresh", 20);
    defaultAttributeList.insert("attribute set Accel_Y", 85);

    //=========================================================================================================//
    //================================================== Preset ===============================================//
    //=========================================================================================================//

    defaultAttributeList.insert("attribute preset", 0);
    defaultAttributeList.insert("attribute set Scene_Name", "INIT");

    for(int i = 0; i < 10; i++)
    {
        defaultAttributeList.insert("attribute key", i + 1);
        defaultAttributeList.insert("attribute set Key_Name", "____");
        defaultAttributeList.insert("attribute set Display_Mode", 0);
        defaultAttributeList.insert("attribute set Prefix_Name", "__");

        for(int i = 0; i < 6; i++)
        {
            defaultAttributeList.insert("attribute set Modline", i + 1);
            defaultAttributeList.insert("attribute set On", 0);
            defaultAttributeList.insert("attribute set Display_Linked", 1);
            defaultAttributeList.insert("attribute set Source", "None");
            defaultAttributeList.insert("attribute set Gain", 1.0000);
            defaultAttributeList.insert("attribute set Offset", 0.0000);
            defaultAttributeList.insert("attribute set Table", "1_Lin");
            defaultAttributeList.insert("attribute set Min", 0);
            defaultAttributeList.insert("attribute set Max", 127);
            defaultAttributeList.insert("attribute set Slew", 0);
            defaultAttributeList.insert("attribute set LED_Menu_Green", "None");
            defaultAttributeList.insert("attribute set LED_Menu_Red", "None");
            defaultAttributeList.insert("attribute set Destination", "None");
        }
    }

    //=========================================================================================================//
    //================================================= Download ==============================================//
    //=========================================================================================================//

    defaultAttributeList.insert("attribute download", 0);

}

void SysExComposer::slotComposeAttributeListFromPreset(QVariantMap preset)
{


    t_softstep *x = softstep_init();

    QMapIterator<QString, QVariant> i(preset);

    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }

    //=========================================================================================================//
    //================================================= Settings ==============================================//
    //=========================================================================================================//

    //------------------------------------- Global Settings
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Response",A_LONG,0l);
    attribute(x,3,A_SYM,"set",A_SYM,"Global_Gain",A_FLOAT,preset.value("Global_Gain").toFloat());   //-----
    //attribute(x,0,A_SYM,"set",A_SYM,"Pedal_Table",A_GIMME,-1);
    attribute(x,4,A_SYM,"set",A_SYM,"pedalEdges",A_LONG,127l, A_LONG,0l);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalHysteresis",A_LONG,7);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalFilterLength",A_LONG,5);
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!preset.value("Global_Backlight").toInt());     //-----
    attribute(x,3,A_SYM,"set",A_SYM,"ProgramChangeInput",A_LONG,12);


    //------------------------------------ Key Settings
    for (long k=0;k<10;k++)
    {
        //Key Number
        attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,k+1);

        //Settings
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_X",A_LONG,16l);
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_X",A_LONG,85l);
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_Y",A_LONG,16l);
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,85l);
        attribute(x,3,A_SYM,"set",A_SYM,"On_Sens",A_LONG,20l);
        attribute(x,3,A_SYM,"set",A_SYM,"Off_Sens",A_LONG,10l);
    }
  //----------------------------------- Nav Settings

    //Nav Key
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

    //Preset/Scene Number and Name
    attribute(x,2,A_SYM,"preset",A_LONG,0);
    attribute(x,3,A_SYM, "set",A_SYM,"Scene_Name",A_SYM,preset.value("Global_Scene_Name").toString().toUtf8().constData());

    //Keys
    for(long k = 0l; k < 10l; k++)
    {
        attribute(x,2,A_SYM,"key",A_LONG,k+1);
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM, preset.value(QString("%1_Key_Key_Name").arg(k)).toString().toUtf8().constData());

        if(preset.value(QString("%1_Key_Source").arg(k)).toString() == "Y_Increment")
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
            attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"Y");
        }
        else if(preset.value(QString("%1_Key_Source").arg(k)).toString() == "X_Live")
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
            attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"X");
        }
        else
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,1l);
            attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"X");
        }

        //Modlines
        for(long m = 0l; m < 6l; m++)
        {
            //Will need more logic here with full editor
            attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m+1);
            if(m == 0l)
            {
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,1l);
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("%1_Key_Source").arg(k)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("%1_Key_Table").arg(k)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("%1_Key_Smooth").arg(k)).toInt());

                // Set gain to 127 for foot on source so that it goes from 0 to 127 instead of 0 to 1.
                if(preset.value(QString("%1_Key_Source").arg(k)).toString() == "Foot_On"){
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,127.0000);
                }
                else{
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                }

                // Led menu conditionals
                if(preset.value(QString("%1_Key_Source").arg(k)).toString() == "Foot_On" && preset.value(QString("%1_Key_Table").arg(k)).toString() == "Toggle_127")
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"True");
                }
                else
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                }

                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");

                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,(long)preset.value("Global_Midi_Channel").toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("%1_Key_CC").arg(k)).toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SSCOM_Port_1");
            }
            else if(k == 0 && m == 1l)
            {
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,1l);
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"Pedal");
                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value("Global_Midi_Channel").toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value("Global_Pedal_CC").toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SSCOM_Port_1");
            }
            else
            {
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM,"1_Lin");
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"None");
            }
            //repeat all the settings in modline 0 for modline 2 (modline 1 key 0 = pedal)
            //except turn off Display_Linked (only one modline needed for display since they are the same)
            //and set device to expander so that output is repeated there.
            if(m == 2l)
            {
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("%1_Key_Source").arg(k)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("%1_Key_Table").arg(k)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("%1_Key_Smooth").arg(k)).toInt());

                // Set gain to 127 for foot on source so that it goes from 0 to 127 instead of 0 to 1.
                if(preset.value(QString("%1_Key_Source").arg(k)).toString() == "Foot_On"){
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,127.0000);
                }
                else{
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                }

                // Led menu conditionals
                if(preset.value(QString("%1_Key_Source").arg(k)).toString() == "Foot_On" && preset.value(QString("%1_Key_Table").arg(k)).toString() == "Toggle_127")
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"True");
                }
                else
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                }

                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");

                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,(long)preset.value("Global_Midi_Channel").toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("%1_Key_CC").arg(k)).toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
            }
            //then repeat the pedal output on key 0 modline 3 and send it to the expander too turning off display_linked.
            else if(k == 0 && m == 3l)
            {
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"Pedal");
                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value("Global_Midi_Channel").toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value("Global_Pedal_CC").toInt());
                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
            }
        }
    }

    //set nav pad to modline mode instead of program change mode.
    attribute(x,2,A_SYM,"key",A_LONG,11l);
    attribute(x,3,A_SYM,"set",A_SYM,"Nav_Modline_Mode",A_LONG,1l);

    //set nav pad key name to scene name and display to always so that the scene name will display when the nav pad is pressed.
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM,preset.value("Global_Scene_Name").toString().toUtf8().constData());
    attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,1l);

    for(long m = 0l; m < 6l; m++){

            //set all modlines to default parameters.
            attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m+1);
            attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"None");
            attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
            attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
            attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM,"1_Lin");
            attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
            attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
            attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
            attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"None");

            //turn on modline 1 only and link it to the display
        if(m == 0l){
            attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,1l);
        }
        else{
            attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
        }
    }

    //=========================================================================================================//
    //================================================= Download ==============================================//
    //=========================================================================================================//
    attribute(x,1,A_SYM,"download");

    qDebug() << "image" << image << "imageLength" << imageLength;
    qDebug() << "settings" << settings << "settingsLength" << settingsLength;

    for(int i =0; i < imageLength; i++)
    {
        //qDebug() << "byte" << image[i];
    }

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
