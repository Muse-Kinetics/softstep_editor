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
#include "midi.h"

SysExComposer::SysExComposer(QWidget *parent) :
    QWidget(parent)
{
    //x = softstep_init();
    //slotGetEmbeddedVersion();
    isSoftStep2 = false;
    //connectedBuildNum = -1;
    connected = false;

    composeSettingsTimeout = new QElapsedTimer();
    composeSettingsTimeout->start();
}


void SysExComposer::slotComposeSettings(QVariantMap settingsMapGlobal, QList<int> pedalTable)
{
    Q_UNUSED(pedalTable);
    //qDebug() << "slotComposeSettings called";

    if (composeSettingsTimeout->elapsed() < 500) // limit update to twice a second
    {
        return;
    }
    else
    {
        composeSettingsTimeout->restart(); // otherwise restart timer
    }


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


    // PEDAL CALIBRATION
    unsigned char min = settingsMap.value("pedal_calibration_min").toInt();
    unsigned char max = settingsMap.value("pedal_calibration_max").toInt();
    unsigned char table = settingsMap.value("pedal_calibration_table").toInt();

    x->settings.pedal_calibration.heel = min;
    x->settings.pedal_calibration.toe = max;
    x->settings.pedal_calibration.table = table;

    //attribute(x,5,A_SYM,"set",A_SYM,"pedalCalibration",A_LONG,min, A_LONG,max, A_LONG,table);

    // backlight
    unsigned char brightness = settingsMap.value("backlight_slider").toInt();
    attribute(x,3,A_SYM,"set",A_SYM,"keyL_brightness",A_LONG,brightness);

    //---- EL - for SS1 only
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!settingsMap.value("backlighting_enable").toLongLong());

    //---- Display offset 0-127, 1-128
    attribute(x,3,A_SYM,"set",A_SYM,"prog_change_display_offset",A_LONG,settingsMap.value("displaymode_checkbox").toLongLong());


    //qDebug() << " ---------------- el" << settingsMap.value("backlighting_enable").toLongLong();

    //---- Program Change Input Channel
    int channel = settingsMap.value("progChgCh").toInt();
    attribute(x,3,A_SYM,"set",A_SYM,"progchg_rx_channel",A_LONG, channel);

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
// Compose all of the attributes for each preset in the setlist, and then transmit it to the device
void SysExComposer::slotComposeAttributeListFromSetlist(QList<QVariantMap> setlist, QVariantMap settingsMapGlobal, QList<int> pedalTable)
{
    Q_UNUSED(pedalTable);
    qDebug() << "slotComposeAttributeListFromSetlist";

    int p_size = sizeof(PRESET_IMAGE);
    int nm_size = sizeof(NM);

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

    // PEDAL CALIBRATION
    unsigned char min = settingsMap.value("pedal_calibration_min").toInt();
    unsigned char max = settingsMap.value("pedal_calibration_max").toInt();
    unsigned char table = settingsMap.value("pedal_calibration_table").toInt();

    x->settings.pedal_calibration.heel = min;
    x->settings.pedal_calibration.toe = max;
    x->settings.pedal_calibration.table = table;

    // backlight
    unsigned char brightness = settingsMap.value("backlight_slider").toInt();
    attribute(x,4,A_SYM,"set",A_SYM,"keyL_brightness",A_LONG,brightness);

    //---- EL - for SS1 only
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!settingsMap.value("backlighting_enable").toLongLong());

    //---- Display offset 0-127, 1-128
    attribute(x,3,A_SYM,"set",A_SYM,"prog_change_display_offset",A_LONG,settingsMap.value("displaymode_checkbox").toLongLong());


    //qDebug() << " ---------------- el" << settingsMap.value("backlighting_enable").toLongLong();

    //---- Program Change Input Channel


    int channel = settingsMap.value("progChgCh").toInt();
    attribute(x,3,A_SYM,"set",A_SYM,"progchg_rx_channel",A_LONG, channel);

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
        //----------------------------------------- CVs  -----------------------------------------//
        //----------------------------------------------------------------------------------------//

        QMap<QString, unsigned char> cvUSBMap;

        cvUSBMap["Gate"] = 0;
        cvUSBMap["Pitch"] = 1;
        cvUSBMap["Velocity"] = 2;

        cvUSBMap["Pitch Bend"] = 0;
        cvUSBMap["Mod Wheel"] = 1;
        cvUSBMap["Aftertouch"] = 2;

        cvUSBMap["Keys/USB"] = 0;
        cvUSBMap["Keys"] = 1;
        cvUSBMap["USB"] = 2;

        cvUSBMap["Disabled"] = 4;

        cvUSBMap["Ch. 1"] = 0;
        cvUSBMap["Ch. 2"] = 1;
        cvUSBMap["Ch. 3"] = 3;
        cvUSBMap["Ch. 4"] = 4;
        cvUSBMap["Ch. 5"] = 5;
        cvUSBMap["Ch. 6"] = 6;
        cvUSBMap["Ch. 7"] = 7;
        cvUSBMap["Ch. 8"] = 8;
        cvUSBMap["Ch. 9"] = 9;
        cvUSBMap["Ch. 10"] = 10;
        cvUSBMap["Ch. 11"] = 11;
        cvUSBMap["Ch. 12"] = 12;
        cvUSBMap["Ch. 13"] = 13;
        cvUSBMap["Ch. 14"] = 14;
        cvUSBMap["Ch. 15"] = 15;
        cvUSBMap["Ch. 16"] = 16;

        unsigned char cv1_sources = cvUSBMap.value(preset.value("cv1_sources", "Keys/USB").toString());
        unsigned char cv2_sources = cvUSBMap.value(preset.value("cv2_sources", "Keys/USB").toString());

        unsigned char cv1_control = cvUSBMap.value(preset.value("cv1_control", "Pitch Bend").toString());
        unsigned char cv1_ch = cvUSBMap.value(preset.value("cv1_ch", "Ch. 1").toString());
        unsigned char cv1_notes = cvUSBMap.value(preset.value("cv1_notes", "Gate").toString());

        unsigned char cv2_control = cvUSBMap.value(preset.value("cv2_control", "Mod Wheel").toString());
        unsigned char cv2_ch = cvUSBMap.value(preset.value("cv2_ch", "Ch. 1").toString());
        unsigned char cv2_notes = cvUSBMap.value(preset.value("cv2_notes", "Pitch").toString());

        x->current_image->nm.cv1Sources = cv1_sources;
        x->current_image->nm.cv1Notes = cv1_notes;
        x->current_image->nm.cv1Control = cv1_control;
        x->current_image->nm.cv1Channel = cv1_ch;
        x->current_image->nm.cv2Sources = cv2_sources;
        x->current_image->nm.cv2Notes = cv2_notes;
        x->current_image->nm.cv2Control = cv2_control;
        x->current_image->nm.cv2Channel = cv2_ch;

//        attribute(x, 3, A_SYM, "set", A_SYM, "cv1_modline", A_LONG, cv1_modline);
//        attribute(x, 3, A_SYM, "set", A_SYM, "cv1_usb", A_LONG, cv1_usb);
//        attribute(x, 3, A_SYM, "set", A_SYM, "cv1_ch", A_LONG, cv1_ch);
//        attribute(x, 3, A_SYM, "set", A_SYM, "cv2_modline", A_LONG, cv2_modline);
//        attribute(x, 3, A_SYM, "set", A_SYM, "cv2_usb", A_LONG, cv2_usb);
//        attribute(x, 3, A_SYM, "set", A_SYM, "cv2_ch", A_LONG, cv2_ch);

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

                //QString keyTable = preset.value(QString("key%1_modline%2_table").arg(k).arg(m)).toString();
                //qDebug() << "key tbale" << keyTable;

                QMap<QString, int> tableMap;

                // Standard tables
                tableMap["Off"] = 0; // holdover from someone not realizing that none = linear
                tableMap["Linear"] = 1;
                tableMap["Sine"] = 2;
                tableMap["Cosine"] = 3;
                tableMap["Exponential"] = 4;
                tableMap["Logarithmic"] = 5;
                tableMap["Toggle1"] = 6; // not used
                tableMap["Toggle"] = 7; // toggle_127
                tableMap["Random"] = 8;

                // scales
                tableMap["Major"] = 9;
                tableMap["Natural Minor"] = 10;
                tableMap["Harmonic Minor"] = 11;
                tableMap["Dorian"] = 12;
                tableMap["Phrygian"] = 13;
                tableMap["Lydian"] = 14;
                tableMap["Mixolydian"] = 15;
                tableMap["Locrian"] = 16;

                int keyTableIndex = tableMap.value(preset.value(QString("key%1_modline%2_table").arg(k).arg(m)).toString(), 1);
                x->current_modline->table = keyTableIndex;

//                //Toggle 127 table formatting
//                if(keyTable.contains("Toggle"))
//                {
//                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "Toggle_127");
//                }
//                else if(keyTable.contains("Linear"))
//                {
//                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
//                    //qDebug() << "------------ linear";
//                }
//                else if(keyTable.contains("Sine"))
//                {
//                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "2_Sin");
//                    //qDebug() << "------------ key tbale sine";
//                }
//                else if(keyTable.contains("Cosine"))
//                {
//                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "3_Cos");
//                    //qDebug() << "------------ key tbale cosine";
//                }
//                else if(keyTable.contains("Exponential"))
//                {
//                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "4_Exponential");
//                    //qDebug() << "------------ key tbale exponential";
//                }
//                else if(keyTable.contains("Logarithmic"))
//                {
//                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "5_Logarithmic");
//                    //qDebug() << "------------ key tbale log";
//                }



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

                // string and then the index of the combobox, whose items are updated by mainWindow
                QMap<QString, QString> portMap;

                // USB
                portMap["SSCOM Port 1"] = "SoftStep USB MIDI";
                portMap["SoftStep USB MIDI"] = "SoftStep USB MIDI";
                portMap["SoftStep Control Surface"] = "SoftStep USB MIDI";

                // MIDI
                portMap["SSCOM Port 2"] = "SoftStep Expander";
                portMap["SoftStep Expander"] = "SoftStep Expander";
                portMap["SoftStep TRS MIDI Out"] = "SoftStep Expander";

                // CV
                portMap["SoftStep CV Out"] = "SoftStep CV Out";

                QString thisDest = preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString();
                thisDest = portMap.value(thisDest);

                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM, thisDest.toUtf8().constData());
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


            QMap<QString, int> tableMap;

            // Standard tables
            tableMap["Off"] = 0; // holdover from someone not realizing that none = linear
            tableMap["Linear"] = 1;
            tableMap["Sine"] = 2;
            tableMap["Cosine"] = 3;
            tableMap["Exponential"] = 4;
            tableMap["Logarithmic"] = 5;
            tableMap["Toggle1"] = 6; // not used
            tableMap["Toggle"] = 7; // toggle_127
            tableMap["Random"] = 8;

            // scales
            tableMap["Major"] = 9;
            tableMap["Natural Minor"] = 10;
            tableMap["Harmonic Minor"] = 11;
            tableMap["Dorian"] = 12;
            tableMap["Phrygian"] = 13;
            tableMap["Lydian"] = 14;
            tableMap["Mixolydian"] = 15;
            tableMap["Locrian"] = 16;

            int keyTableIndex = tableMap.value(preset.value(QString("nav_modline%1_table").arg(m)).toString(), 1);
            x->current_modline->table = keyTableIndex;

            //Toggle 127 table formatting
            //QString navTable = preset.value(QString("nav_modline%1_table").arg(m)).toString();

//            if(navTable.contains("Toggle"))
//            {
//                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "Toggle_127");
//            }
//            else if(navTable.contains("Linear"))
//            {
//                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
//            }
//            else if(navTable.contains("Sine"))
//            {
//                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "2_Sin");
//            }
//            else if(navTable.contains("Cosine"))
//            {
//                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "3_Cos");
//            }
//            else if(navTable.contains("Exponential"))
//            {
//                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "4_Exponential");
//            }
//            else if(navTable.contains("Logarithmic"))
//            {
//                attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "5_Logarithmic");
//            }

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
    attribute(x,1,A_SYM,"download"); // this command sends the image

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

void SysExComposer::slotTetherOnOffInStandalone(bool onOff) // 2nd
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

void SysExComposer::slotRequestPedalCalibration()
{
    qDebug() << "slotRequestPedalCalibration called - connected: " << connected;

    if (!connected) return; // don't send when not connected

    //emit signalSendSysEx(_request_pedal_cal, sizeof(_request_pedal_cal));
}
