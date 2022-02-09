// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "sysexcomposer.h"

#include "QDebug"
#include "QApplication"
#include "sysexmessages.h"

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
    //x = softstep_init();
    //slotGetEmbeddedVersion();
    isSoftStep2 = false;
    //connectedBuildNum = -1;
    connected = false;
}

//void SysExComposer::slotGetEmbeddedVersion()
//{
//    t_softstep *x = softstep_init();

//    QString sysExPath = QCoreApplication::applicationDirPath(); //get bundle path

//#if defined(Q_OS_MAC) // && !defined(QT_DEBUG)
//    sysExPath.remove(sysExPath.length() - 5, sysExPath.length()); //Remove "MacOS" from path string
//    sysExPath.append("Resources/SoftStep.syx");

//#else
//    sysExPath = QString("./SoftStep.syx");
//#endif

//#ifdef Q_OS_MAC
//    FILE *fd = fopen(sysExPath.toUtf8(),"r");
//#else
//    FILE *fd = fopen(sysExPath.toUtf8(),"rb");
//#endif

//    qDebug() << "sysEx path: " << sysExPath;

//    if (fd)
//    {
//        int fchar;

//#ifdef Q_OS_MAC
//        fseek(fd, 0l, SEEK_END);
//        fwFileSize = ftell(fd);
//        rewind(fd);

//        fwFile = (unsigned char*)malloc(fwFileSize*sizeof(unsigned char));
//        fread(fwFile,1,fwFileSize, fd);

//        //qDebug() << fwFile[fwFileSize - 1];

//        rewind(fd);
//#else

//#endif
//        while ( (fchar = fgetc(fd)) != EOF)
//        {
//            QCoreApplication::processEvents();
//            softstep_midi_process(x,&x->version_embedded,fchar);
//        }

//        embeddedbuildNum = x->version_embedded.buildnum;
//        embeddedVersion = QString(x->version_embedded.version);
//    }
//    else
//    {
//        embeddedbuildNum = -1;
//        embeddedVersion = QString("Not Found");
//        qDebug() << "WARNING: SoftStep.syx not found.";
//    }

//    //qDebug() << "sysexpath" << sysExPath << "file size" << fwFileSize << "69078";
//}

void SysExComposer::slotComposeSettings(QVariantMap settingsMapGlobal, QList<int> pedalTable)
{
    //qDebug() << "slotComposeSettings called";

    QVariantMap settingsMap = settingsMapGlobal.value("Global").toMap();

    t_softstep *x = softstep_init();

    //=========================================================================================================//
    //================================================= Settings ==============================================//
    //=========================================================================================================//

    //------------------------------------- Global -------------------------------------//
    //---- Sensitivity
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Response",A_LONG,settingsMap.value("sensorresponse_checkbox").toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"Global_Gain",A_FLOAT,settingsMap.value("global_gain").toFloat());

    //---- Key Safety
    //Adjacent Key Lockout - currently not implemented
    if(settingsMap.value("adjacentkeymode").toBool())
    {
        //attribute(x,3,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,0l);
    }

    //Single Key Lockout
    else if(settingsMap.value("keylockoutmode").toBool())
    {
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,0l);
    }

    //All Keys
    else if(settingsMap.value("multiplekeymode").toBool())
    {
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,1l);
    }

    //---- Pedal
    int max = 0;
    int min = 127;
    for(int i = 0; i < pedalTable.size(); i++)
    {
        //qDebug() << "pedal table " << pedalTable;
        //Min
        if(pedalTable.at(i) < min)
        {
            min = pedalTable.at(i);
        }

        //Max
        if(pedalTable.at(i) > max)
        {
            max = pedalTable.at(i);
        }
    }


    //attribute(x,0,A_SYM,"set",A_SYM,"Pedal_Table",A_GIMME,-1);
    attribute(x,4,A_SYM,"set",A_SYM,"pedalEdges",A_LONG,max, A_LONG,min);
    //attribute(x,3,A_SYM,"set",A_SYM,"pedalHysteresis",A_LONG,7);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalFilterLength",A_LONG,3);

    //---- EL
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!settingsMap.value("backlighting_enable").toLongLong());

    //---- Display offset 0-127, 1-128
    attribute(x,3,A_SYM,"set",A_SYM,"prog_change_display_offset",A_LONG,settingsMap.value("displaymode_checkbox").toLongLong());


    //qDebug() << " ---------------- el" << settingsMap.value("backlighting_enable").toLongLong();

    //---- Program Change Input Channel
    attribute(x,3,A_SYM,"set",A_SYM,"ProgramChangeInput",A_LONG,16);

    //--------------------------------------  Keys  ------------------------------------//
    for (long k=1;k<11;k++)
    {
        //Key Number
        attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,k);

        //Settings
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_X",A_LONG,settingsMap.value(QString("key%1_settings_xdead").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_X",A_LONG,settingsMap.value(QString("key%1_settings_xaccel").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_Y",A_LONG,settingsMap.value(QString("key%1_settings_ydead").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,settingsMap.value(QString("key%1_settings_yaccel").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"On_Sens",A_LONG,settingsMap.value(QString("key%1_settings_onthresh").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Off_Sens",A_LONG,settingsMap.value(QString("key%1_settings_offthresh").arg(k)).toLongLong());

        //qDebug() << k << "y aclle" << settingsMap.value(QString("key%1_settings_yaccel").arg(k)).toLongLong();
    }

    //------------------------------------- Nav Pad ------------------------------------//
    attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,11);

    //Nav Settings1
    attribute(x,3,A_SYM,"set",A_SYM,"North_On_Thresh",A_LONG,settingsMap.value(QString("nav_north_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"North_Off_Thresh",A_LONG,settingsMap.value(QString("nav_north_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"South_On_Thresh",A_LONG,settingsMap.value(QString("nav_south_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"South_Off_Thresh",A_LONG,settingsMap.value(QString("nav_south_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"East_On_Thresh",A_LONG,settingsMap.value(QString("nav_east_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"East_Off_Thresh",A_LONG,settingsMap.value(QString("nav_east_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"West_On_Thresh",A_LONG,settingsMap.value(QString("nav_west_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"West_Off_Thresh",A_LONG,settingsMap.value(QString("nav_west_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,settingsMap.value(QString("nav_settings_yaccel")).toLongLong());

    attribute(x,1,A_SYM,"download");

    //qDebug() << "settings" << settings << "settingsLength" << settingsLength;

    //Send Settings
    if (connected) emit signalSendSysEx(settings, settingsLength);

    //qDebug("freeing settings");
    //free(settings);

}

void SysExComposer::slotComposeAttributeListFromSetlist(QList<QVariantMap> setlist, QVariantMap settingsMapGlobal, QList<int> pedalTable)
{

    //For some reason there's an extra layer to get to the actual settings, the "Global" map within the settings json contains them
    //I think "Global" refers to the fact that it's for both modes, Standalone and Hosted

    QVariantMap settingsMap = settingsMapGlobal.value("Global").toMap();

    t_softstep *x = softstep_init();

    //=========================================================================================================//
    //================================================= Settings ==============================================//
    //=========================================================================================================//

    //------------------------------------- Global -------------------------------------//
    //---- Sensitivity
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Response",A_LONG,settingsMap.value("sensorresponse_checkbox").toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"Global_Gain",A_FLOAT,settingsMap.value("global_gain").toFloat());

    //---- Key Safety
    //Adjacent Key Lockout - currently not implemented
    if(settingsMap.value("adjacentkeymode").toBool())
    {
        //attribute(x,3,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,0l);
    }

    //Single Key Lockout
    else if(settingsMap.value("keylockoutmode").toBool())
    {
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,0l);
    }

    //All Keys
    else if(settingsMap.value("multiplekeymode").toBool())
    {
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,1l);
    }

    //---- Pedal
    int max = 0;
    int min = 127;
    for(int i = 0; i < pedalTable.size(); i++)
    {
        //qDebug() << "pedal table " << pedalTable;
        //Min
        if(pedalTable.at(i) < min)
        {
            min = pedalTable.at(i);
        }

        //Max
        if(pedalTable.at(i) > max)
        {
            max = pedalTable.at(i);
        }
    }


    //attribute(x,0,A_SYM,"set",A_SYM,"Pedal_Table",A_GIMME,-1);
    attribute(x,4,A_SYM,"set",A_SYM,"pedalEdges",A_LONG,max, A_LONG,min);
    //attribute(x,3,A_SYM,"set",A_SYM,"pedalHysteresis",A_LONG,7);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalFilterLength",A_LONG,3);

    //---- EL
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!settingsMap.value("backlighting_enable").toLongLong());

    //---- Display offset 0-127, 1-128
    attribute(x,3,A_SYM,"set",A_SYM,"prog_change_display_offset",A_LONG,settingsMap.value("displaymode_checkbox").toLongLong());


    //qDebug() << " ---------------- el" << settingsMap.value("backlighting_enable").toLongLong();

    //---- Program Change Input Channel
    attribute(x,3,A_SYM,"set",A_SYM,"ProgramChangeInput",A_LONG,16);

    //--------------------------------------  Keys  ------------------------------------//
    for (long k=1;k<11;k++)
    {
        //Key Number
        attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,k);

        //Settings
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_X",A_LONG,settingsMap.value(QString("key%1_settings_xdead").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_X",A_LONG,settingsMap.value(QString("key%1_settings_xaccel").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_Y",A_LONG,settingsMap.value(QString("key%1_settings_ydead").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,settingsMap.value(QString("key%1_settings_yaccel").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"On_Sens",A_LONG,settingsMap.value(QString("key%1_settings_onthresh").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Off_Sens",A_LONG,settingsMap.value(QString("key%1_settings_offthresh").arg(k)).toLongLong());

        //qDebug() << k << "y aclle" << settingsMap.value(QString("key%1_settings_yaccel").arg(k)).toLongLong();
    }

    //------------------------------------- Nav Pad ------------------------------------//
    attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,11);

    //Nav Settings1
    attribute(x,3,A_SYM,"set",A_SYM,"North_On_Thresh",A_LONG,settingsMap.value(QString("nav_north_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"North_Off_Thresh",A_LONG,settingsMap.value(QString("nav_north_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"South_On_Thresh",A_LONG,settingsMap.value(QString("nav_south_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"South_Off_Thresh",A_LONG,settingsMap.value(QString("nav_south_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"East_On_Thresh",A_LONG,settingsMap.value(QString("nav_east_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"East_Off_Thresh",A_LONG,settingsMap.value(QString("nav_east_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"West_On_Thresh",A_LONG,settingsMap.value(QString("nav_west_settings_onthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"West_Off_Thresh",A_LONG,settingsMap.value(QString("nav_west_settings_offthresh")).toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,settingsMap.value(QString("nav_settings_yaccel")).toLongLong());


    //=========================================================================================================//
    //================================================== Preset ===============================================//
    //=========================================================================================================//

    //Scroll setlist, enumerating presets
    for (long p=0; p<setlist.size(); p++)
    {
        QVariantMap preset = setlist.at(p);

        attribute(x,2,A_SYM,"preset",A_LONG,p);
        attribute(x,3,A_SYM, "set",A_SYM,"Scene_Name",A_SYM,preset.value("preset_displayname").toString().toUtf8().constData());

        //----------------------------------------------------------------------------------------//
        //----------------------------------------- Keys -----------------------------------------//
        //----------------------------------------------------------------------------------------//

        for(long k = 1; k < 11; k++)
        {
            attribute(x,2,A_SYM,"key",A_LONG,k);
            attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM, preset.value(QString("%1_key_name").arg(k)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,preset.value(QString("%1_key_prefix").arg(k)).toString().toUtf8().constData());

            //qDebug() << "Display_Mode" << preset.value(QString("%1_key_displaymode").arg(k)).toString();

            //---------------------------------------- Display Mode
            QString displayMode = preset.value(QString("%1_key_displaymode").arg(k)).toString();

            if(displayMode == "None")
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,0l);
            }
            else if(displayMode == "Always")
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,1l);
            }
            else if(displayMode == "Once")
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,2l);
            }
            else if(displayMode == "Initial/Return")
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,3l);
            }
            else if(displayMode == "Immed Param")
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
            }

            //---------------------------------------- Modlines
            for(long m = 1; m < 7; m++ )
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m);
                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,preset.value(QString("key%1_modline%2_enable").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("key%1_modline%2_source").arg(k).arg(m)).toString().toUtf8().constData());

                qDebug() << "key : " << k << "modline : " << m << preset.value(QString("key%1_modline%2_source").arg(k).arg(m)).toString();

                attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("key%1_modline%2_gain").arg(k).arg(m)).toFloat());
                attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,preset.value(QString("key%1_modline%2_offset").arg(k).arg(m)).toFloat());

                QString keyTable = preset.value(QString("key%1_modline%2_table").arg(k).arg(m)).toString();
                //qDebug() << "key tbale" << keyTable;

                //Toggle 127 table formatting
                if(keyTable.contains("Toggle"))
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "Toggle_127");
                }
                else if(keyTable.contains("Linear"))
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
                    //qDebug() << "------------ linear";
                }
                else if(keyTable.contains("Sine"))
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "2_Sin");
                    //qDebug() << "------------ key tbale sine";
                }
                else if(keyTable.contains("Cosine"))
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "3_Cos");
                    //qDebug() << "------------ key tbale cosine";
                }
                else if(keyTable.contains("Exponential"))
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "4_Exponential");
                    //qDebug() << "------------ key tbale exponential";
                }
                else if(keyTable.contains("Logarithmic"))
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "5_Logarithmic");
                    //qDebug() << "------------ key tbale log";
                }



                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("key%1_modline%2_min").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("key%1_modline%2_max").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("key%1_modline%2_slew").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("key%1_modline%2_destination").arg(k).arg(m)).toString().toUtf8().constData());

                //qDebug() << "TABLE" << preset.value(QString("key%1_modline%2_table").arg(k).arg(m)).toString();

                //------------------------------------- Destination Handling
                QString destination = preset.value(QString("key%1_modline%2_destination").arg(k).arg(m)).toString();

                //------------- Note Set
                if(destination == "Note Set" || destination == "Note Live")
                {
                    //Note
                    attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("key%1_modline%2_note").arg(k).arg(m)).toLongLong());

                    //Velocity
                    attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("key%1_modline%2_velocity").arg(k).arg(m)).toLongLong());

                    //Channel
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                }

                //------------- Note Live
                /*else if(destination == "Note Live")
                {
                    //Note
                    attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("key%1_modline%2_note").arg(k)).toLongLong());

                    //Velocity
                    attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("key%1_modline%2_velocity").arg(k)).toLongLong());

                    //Channel
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                }*/

                //------------- CC
                else if(destination == "CC")
                {
                    //CC#
                    attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("key%1_modline%2_cc").arg(k).arg(m)).toLongLong());

                    //Channel
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                }

                //------------- Bank
                else if(destination == "Bank")
                {
                    //MSB goes here in future.
                    attribute(x,3,A_SYM,"set",A_SYM,"bank_msb",A_LONG,preset.value(QString("key%1_modline%2_bankmsb").arg(k).arg(m)).toLongLong());

                    qDebug() <<  "bank msb" << preset.value(QString("key%1_modline%2_bankmsb").arg(k).arg(m)).toLongLong();

                    //Channel
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                }

                //------------- Program
                else if(destination == "Program")
                {

                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                }

                //------------- Pitch Bend
                else if(destination == "Pitch Bend")
                {

                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
                }

                //------------- MMC
                else if(destination == "MMC")
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"MMC_Device_ID",A_LONG,preset.value(QString("key%1_modline%2_mmcid").arg(k).arg(m)).toLongLong());
                    attribute(x,3,A_SYM,"set",A_SYM,"MMC_Function",A_SYM,preset.value(QString("key%1_modline%2_mmcfunction").arg(k).arg(m)).toString().toUtf8().constData());
                }

                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,preset.value(QString("key%1_modline%2_ledred").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,preset.value(QString("key%1_modline%2_ledgreen").arg(k).arg(m)).toString().toUtf8().constData());
                attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,preset.value(QString("key%1_modline%2_displaylinked").arg(k).arg(m)).toLongLong());

            } //Modline loop
        } //Key loop


        //----------------------------------------------------------------------------------------//
        //----------------------------------------- NavP. ----------------------------------------//
        //----------------------------------------------------------------------------------------//

        //Nav is Key 11
        attribute(x,2,A_SYM,"key",A_LONG,11l);

        //Modline or Program change mode
        attribute(x,3,A_SYM,"set",A_SYM,"Nav_Modline_Mode",A_LONG,1 - preset.value(QString("nav_modlinemode")).toLongLong());

        qDebug() << "nav modline mode" << preset.value(QString("nav_modlinemode")).toLongLong();

        //Name
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM,preset.value("nav_name").toString().toUtf8().constData());

        //---------------------------------------- Display Mode
        QString navDisplayMode = preset.value(QString("nav_displaymode")).toString();

        if(navDisplayMode == "None")
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,0l);
        }
        else if(navDisplayMode == "Always")
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,1l);
        }
        else if(navDisplayMode == "Once")
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,2l);
        }
        else if(navDisplayMode == "Initial/Return")
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,3l);
        }
        else if(navDisplayMode == "Immed Param")
        {
            //qDebug() << "Display mode Immed Param";
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
        }

        //Prefix Name
        attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,preset.value("nav_prefix").toString().toUtf8().constData());



        for(long m = 1l; m < 7l; m++)
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m);
            attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,preset.value(QString("nav_modline%1_enable").arg(m)).toLongLong());

            //---- Source
            QString navSource = preset.value(QString("nav_modline%1_source").arg(m)).toString();

            //qDebug() << "nav source" << navSource;

            //Account for underscores in name-- could be fixed in attribute settings...
            if(navSource == "Nav Y Inc-Dec")
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"Nav_Y_Inc-Dec");
            }
            else
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("nav_modline%1_source").arg(m)).toString().toUtf8().constData());
            }

            //qDebug() << "nav source" << preset.value(QString("nav_modline%1_source").arg(m)).toString().toUtf8().constData();

            attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("nav_modline%1_gain").arg(m)).toFloat());
            attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,preset.value(QString("nav_modline%1_offset").arg(m)).toFloat());

            //Toggle 127 table formatting
            QString navTable = preset.value(QString("nav_modline%1_table").arg(m)).toString();

            if(navTable.contains("Toggle"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "Toggle_127");
            }
            else if(navTable.contains("Linear"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
            }
            else if(navTable.contains("Sine"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "2_Sin");
            }
            else if(navTable.contains("Cosine"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "3_Cos");
            }
            else if(navTable.contains("Exponential"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "4_Exponential");
            }
            else if(navTable.contains("Logarithmic"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "5_Logarithmic");
            }

            //attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM,preset.value(QString("nav_modline%1_table").arg(m)).toString().toUtf8().constData());

            attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("nav_modline%1_min").arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("nav_modline%1_max").arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("nav_modline%1_slew").arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("nav_modline%1_destination").arg(m)).toString().toUtf8().constData());

            //------------------------------------- Destination Handling
            QString destination = preset.value(QString("nav_modline%1_destination").arg(m)).toString();

            //------------- Note Set / Note Live
            if(destination == "Note Set" || destination == "Note Live")
            {
                //Note
                attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("nav_modline%1_note").arg(m)).toLongLong());

                //Velocity
                attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("nav_modline%1_velocity").arg(m)).toLongLong());

                //Channel
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("nav_modline%1_channel").arg(m)).toLongLong());
            }

            //------------- Note Live
            /*else if(destination == "Note Live")
            {
                //Note
                attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("key%1_modline%2_note").arg(k)).toLongLong());

                //Velocity
                attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("key%1_modline%2_velocity").arg(k)).toLongLong());

                //Channel
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
            }*/

            //------------- CC
            else if(destination == "CC")
            {
                //CC#
                attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("nav_modline%1_cc").arg(m)).toLongLong());

                //Channel
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("nav_modline%2_channel").arg(m)).toLongLong());
            }

            //------------- Bank
            else if(destination == "Bank")
            {
                //MSB goes here in future.
                attribute(x,3,A_SYM,"set",A_SYM,"bank_msb",A_LONG,preset.value(QString("nav_modline%1_bankmsb").arg(m)).toLongLong());

                //Channel
                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("nav_modline%1_channel").arg(m)).toLongLong());
            }

            //------------- Program
            else if(destination == "Program")
            {

                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("nav_modline%1_channel").arg(m)).toLongLong());
            }

            //------------- Pitch Bend
            else if(destination == "Pitch Bend")
            {

                attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("nav_modline%1_channel").arg(m)).toLongLong());
            }

            //------------- MMC
            else if(destination == "MMC")
            {

            }

            //Device
            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,preset.value(QString("nav_modline%1_device").arg(m)).toString().toUtf8().constData());

            //Display Linkage
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,preset.value(QString("nav_modline%1_displaylinked").arg(m)).toLongLong());

        }
    }

    //=========================================================================================================//
    //================================================= Download ==============================================//
    //=========================================================================================================//
    attribute(x,1,A_SYM,"download");

    //qDebug() << "image" << image << "imageLength" << imageLength;
    //qDebug() << "settings" << settings << "settingsLength" << settingsLength;


    //emit signalSendSysEx(QString("settings image"), settings, settingsLength, QString("SoftStep Control Surface"));

    //Send Settings
    if (connected) emit signalSendSysEx(settings, settingsLength);
    slotSettingsSent();
}

void SysExComposer::slotSettingsSent()
{
    qDebug("freeing settings");
    free(settings);

    if (connected) emit signalSendSysEx(image, imageLength);
    slotPresetsSent();
}

void SysExComposer::slotPresetsSent()
{
    qDebug() << "SysEx Composer -- Presets Sent";
    qDebug("freeing image");
    free(image);

    //sysex message complete
    emit signalUpdateComplete();
}

//void SysExComposer::slotGetConnectedVersion(QByteArray msg)
//{
//    qDebug() << "signal was received" << msg.count();

//    t_softstep *x = softstep_init();

//    for(int i =0 ; i < msg.count(); i++)
//    {
//        softstep_midi_process(x,&x->version_connected, msg.at(i));
//    }

//    //If POST v76 firmware -- where SS2 differentiaion was introduced
//    if(msg.size() > 91)
//    {
//        if(msg.at(107))
//        {
//            qDebug() << "SS2";
//            isSoftStep2 = true;
//        }
//        else
//        {
//            qDebug() << "SS1";
//            isSoftStep2 = false;
//        }
//    }

//    //If for some reason we get a version number of 0, try sending the message again
//    if(x->version_connected.buildnum == 0)
//    {
//        /*
//        unsigned char _fw_query_syx_softstep_sysexcomposer[] =
//        {
//            0xF0,0x00,0x1B,0x48,0x7A,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x04,0x40,
//            0x00,0x30,0xF7
//        };
//        */



//        //emit signalSendSysEx("deviceQuery", _fw_query_syx_softstep_sysexcomposer, 67, "SoftStep Control Surface");
//        //return;
//    }

//    qDebug() << "___________ connected version number indexed" << (int)msg.at(68);

//#ifdef Q_OS_MAC
//    //connectedBuildNum = x->version_connected.buildnum;
//    connectedBuildNum = (int)msg.at(68);
//    connectedVersion = QString(x->version_connected.version);
//#else
//    connectedBuildNum = x->version_connected.buildnum;
//#endif
//    qDebug() << "_____ Connected:" << connectedBuildNum;
//    qDebug() << "______ Embedded:" << embeddedbuildNum;

//    emit signalSendBuildNums(connectedBuildNum, connectedVersion, embeddedbuildNum, embeddedVersion, (uint)isSoftStep2);
//}

//void SysExComposer::slotUpdateFirmware()
//{
//    //qDebug() << "update firmware called" << fwFileSize;
//    //QApplication::processEvents();
//    emit signalSendSysEx(QString("update firmware"), (unsigned char*)fwFile, fwFileSize, QString("SoftStep Control Surface"));
//}

void SysExComposer::slotHostedOnOff(bool onOff)
{
    qDebug() << "slotHostedOnOff called - connected: " << connected;

    if (!connected) return; // don't send when not connected

    //EB old comment: FIFO necessary because firmware requires delay between messages
    if(!onOff)
    {
        //mode = "standalone";

        emit signalSendSysEx(_fw_tether_off, sizeof(_fw_tether_off));
        emit signalSendSysEx(_fw_standalone_on, sizeof(_fw_standalone_on));
        //emit signalSendSysEx(_fw_scenechange_on_persist, sizeof(_fw_scenechange_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on_persist, sizeof(_fw_nav_standalone_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on, sizeof(_fw_nav_standalone_on));
    }
    else
    {
        //mode = "hosted";

        emit signalSendSysEx(_fw_scenechange_on_persist, sizeof(_fw_scenechange_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on_persist, sizeof(_fw_nav_standalone_on_persist));
        emit signalSendSysEx(_fw_tether_on, sizeof(_fw_tether_on));
        emit signalSendSysEx(_fw_standalone_off, sizeof(_fw_standalone_off));
        emit signalSendSysEx(_fw_nav_standalone_off, sizeof(_fw_nav_standalone_off));
    }
}

void SysExComposer::slotSceneChangeOnOff(bool onOff)
{
    qDebug() << "scene change on/off - connected: " << connected;

    if (!connected) return; // don't send when not connected

    if(onOff)
    {
        emit signalSendSysEx(_fw_tether_off, sizeof(_fw_tether_off));
        emit signalSendSysEx(_fw_standalone_on, sizeof(_fw_standalone_on));
        emit signalSendSysEx(_fw_scenechange_on_persist, sizeof(_fw_scenechange_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on_persist, sizeof(_fw_nav_standalone_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on, sizeof(_fw_nav_standalone_on));
    }
    else
    {
        emit signalSendSysEx(_fw_tether_off, sizeof(_fw_tether_off));
        emit signalSendSysEx(_fw_standalone_on, sizeof(_fw_standalone_on));
        emit signalSendSysEx(_fw_scenechange_off_persist, sizeof(_fw_scenechange_off_persist));
        emit signalSendSysEx(_fw_nav_standalone_on_persist, sizeof(_fw_nav_standalone_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on, sizeof(_fw_nav_standalone_on));
    }
}

void SysExComposer::slotBackLightOnOff(bool onOff)
{
    qDebug() << "slotBackLightOnOff called - connected: " << connected;

    if (!connected) return; // don't send when not connected

    if(onOff)
    {
        emit signalSendSysEx(_backlight_on, sizeof(_backlight_on));
    }
    else
    {
        emit signalSendSysEx(_backlight_off, sizeof(_backlight_off));
    }

}

void SysExComposer::slotTetherOnOffInStandalone(bool onOff)
{
    qDebug() << "slotTetherOnOffInStandalone called";
    //---- !!!! This function only used for pedal calibration !!! ----//

    //Turn tether on during calibration
    if(onOff)
    {
        calibrationPhase = "start"; // see the original mididevicemanager, which would emit start/stop calibration signals when FIFO would empty

        if (!connected) return; // don't send when not connected - EB TODO - this might need to move up so as to not modify calibrationPhase

        emit signalSendSysEx(_fw_scenechange_on_persist, sizeof(_fw_scenechange_on_persist));
        emit signalSendSysEx(_fw_tether_on, sizeof(_fw_tether_on));
        emit signalSendSysEx(_fw_standalone_off, sizeof(_fw_standalone_off));
        emit signalSendSysEx(_fw_nav_standalone_off, sizeof(_fw_nav_standalone_off));

        //Cue calibration start
        emit signalStartStandaloneCalibration();
    }

    //Turn thether off at end of calibration
    else
    {
        calibrationPhase = "stop";

        if (!connected) return; // don't send when not connected

        emit signalSendSysEx(_fw_tether_off, sizeof(_fw_tether_off));
        emit signalSendSysEx(_fw_standalone_on, sizeof(_fw_standalone_on));
        emit signalSendSysEx(_fw_nav_standalone_on_persist, sizeof(_fw_nav_standalone_on_persist));
        emit signalSendSysEx(_fw_nav_standalone_on, sizeof(_fw_nav_standalone_on));

    }
}

// EB TODO - lots of re-writes here
// this is handled in MainWindow::slotProcessInputToHostedMode
//------------------------------------------------------ Hosted
//void SysExComposer::hosted_slotParsePacket(QByteArray packet)
//{
//    //Sends raw packet to be parsed from SoftStep Control Surface
//    emit hosted_signalParsePacket(&packet);
//}

// EB - not integrated yet, explore how this works
//void SysExComposer::hosted_slotSendPacket(QString port, QByteArray packet)
//{
//    //Semds Packet to external dest
//    //qDebug() << "hosted_slotSendPacketCalled - data:" << packet.data[0] << packet.data[1] << packet.data[2] << "length, time : " << packet.length << packet.timeStamp << "\n";

//    //Packet Size max size
//    Byte packetListSize[256];

    //Allocates bytes, sets size of total packetlist
//    MIDIPacketList* packetList = (MIDIPacketList*)packetListSize;

    //Initialize packet
//    MIDIPacket* pkt = MIDIPacketListInit(packetList); //Init midi packet

    //Add new packet to list
//    MIDIPacketListAdd(packetList, 256, pkt, 0, packet.length, packet.data);

    //---------------------------- Send packet to virtual source

//    if(port == "SoftStep Hosted Virtual Port")
//    {
//        MIDIReceived(appVirtualSourceRef, packetList);
//    }
//    else if(port.contains("SoftStep Control Surface"))
//    {
//        //qDebug() << "send message to SSCOM1";
////        MIDISend(appOutPortRef, sscomPort1DestRef, packetList);
//    }
//    else
//    {
////        MIDISend(appOutPortRef, externalDests.value(port), packetList);
//    }

//}

// EB - this has been integrated into MainWindow::slotMIDIPortChange
//void SysExComposer::hosted_slotRepopulateMidiSourceDests()
//{
    //Called when midi system changes, automaticall called on hosted to standlaone/switch because of "SoftStep Share"

    //----------------------- Get non SSCOM sources
    //midiInputSources.clear();

    // EB TODO - this needs an entire re-write

//    for(unsigned int i=0; i<MIDIGetNumberOfSources(); i++)
//    {
//        //Allocate new array of endpoint pointers for passing as refcon
//        midiInputSourcePointers = new MIDIEndpointRef[MIDIGetNumberOfSources()];

//        //Expander
//        if(getDisplayName(MIDIGetSource(i)).contains("SoftStep Expander"))
//        {
//            midiInputSources.insert("SoftStep Expander", MIDIGetSource(i));

//            //Insert MIDIEndpointRef into array
//            //midiInputSourcePointers[i] = MIDIGetSource(i);
//        }

//        if(!getDisplayName(MIDIGetSource(i)).contains("SoftStep"))
//        {
//            //qDebug() << "Non-SoftStep Source: " << getDisplayName(MIDIGetSource(i));

//            //Store name of midi input source and it's endpoint ref
//            midiInputSources.insert(getDisplayName(MIDIGetSource(i)), MIDIGetSource(i));

//            //Insert MIDIEndpointRef into array
//            //midiInputSourcePointers[i] = MIDIGetSource(i);
//        }
//    }

//    //Sends sources to midi input in settings page, connected in mainwindow
//    emit hosted_signalMidiInputSourceMenus(midiInputSources);

//    //----------------------- Get non SSCOM destinations
//    externalDests.clear();

//    //Make sure SoftStep Share is in there but points to nothing
//    externalDests.insert("SoftStep Share", 0);

//    for(unsigned int i=0; i<MIDIGetNumberOfDestinations(); i++)
//    {
//        ///qDebug() << "Destinations: " << getDisplayName(MIDIGetSource(i));

//        if(!getDisplayName(MIDIGetDestination(i)).contains("SoftStep Control Surface") && !getDisplayName(MIDIGetDestination(i)).contains("SoftStep Hosted Virtual Port"))
//        {
//            if(getDisplayName(MIDIGetDestination(i)).contains("SoftStep Expander"))
//            {
//                //We would like port 2 to be named SoftStep Expander
//                externalDests.insert("SoftStep Expander", MIDIGetDestination(i));
//            }
//            else
//            {
//                //Store name of dest and it's endpoint ref
//                externalDests.insert(getDisplayName(MIDIGetDestination(i)), MIDIGetDestination(i));
//            }
//            //qDebug() << "Non-SoftStep Destination: " << getDisplayName(MIDIGetDestination(i));
//        }
//    }

//    //qDebug() << "Modline Device Menus:" << externalDests.keys();

//    //Sneds destinations to device menus in modlines
//    emit hosted_signalPopulateDeviceMenus(externalDests);
//}

// this may not be necessary anymore
//void SysExComposer::hosted_slotParseMidiInputPacket(QByteArray, QString deviceName)
//{
//    //Sends raw packet to be parsed from SoftStep Control Surface
//    //emit hosted_signalParseMidiInputPacket(packet, deviceName);
//}

// EB not integrated yet, but may not be necessary
//void SysExComposer::hosted_slotConnectExternalMidiInputSources()
//{
    //er = midiInputSources.value(getDisplayName(MIDIGetSource(0)));

    // EB TODO - this needs an entire re-write
//    for(unsigned int i=0; i<MIDIGetNumberOfSources(); i++)
//    {
//        if(getDisplayName(MIDIGetSource(i)).contains("SoftStep Control Surface"))
//        {
//            //Filter out SoftStep Control Surface and
//        }
//        else
//        {
//            //midiInputSources.value(getDisplayName(MIDIGetSource(i)));

//            //MIDIEndpointRef* epr = &midiInputSourcePointers[i];

//            midiInputSourcePointers[i] = MIDIGetSource(i);

//            //qDebug() << "----------------------------" << "slot connect external midi sources" << getDisplayName(MIDIGetSource(i)) << midiInputSourcePointers[i];

//            MIDIPortConnectSource(midiInputPort, MIDIGetSource(i), (void*)&midiInputSourcePointers[i]);
//        }
//    }
//}
