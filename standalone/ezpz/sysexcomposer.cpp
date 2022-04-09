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
//#include "utils.h"
//#include "softstep.h"
//#include "query.h"
#include "attribute.h"
}


SysExComposer::SysExComposer(QWidget *parent) :
    QWidget(parent)
{
    //slotGetEmbeddedVersion();
    isSoftStep2 = false;

    factoryPresets = new FactoryPresets();
}

SysExComposer::~SysExComposer()
{
    //free(fwFile);
}

void SysExComposer::slotComposeAttributeListFromPreset(QVariantMap presetSent, QVariantMap master, qlonglong presetNum)
{
    Q_UNUSED(presetNum)

    t_softstep *x = softstep_init();

    QMapIterator<QString, QVariant> i(presetSent);

    /*while (i.hasNext())
    {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }*/

    //=========================================================================================================//
    //================================================= Settings ==============================================//
    //=========================================================================================================//

    //------------------------------------- Global Settings
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Response",A_LONG,0l);
    attribute(x,3,A_SYM,"set",A_SYM,"Global_Gain",A_FLOAT,master.value("sensitivity").toFloat());   //-----
    //attribute(x,0,A_SYM,"set",A_SYM,"Pedal_Table",A_GIMME,-1);
    attribute(x,4,A_SYM,"set",A_SYM,"pedalEdges",A_LONG,127l, A_LONG,0l);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalHysteresis",A_LONG,7);
    attribute(x,3,A_SYM,"set",A_SYM,"pedalFilterLength",A_LONG,5);
    attribute(x,3,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,!master.value("backlight").toInt());     //-----
    attribute(x,3,A_SYM,"set",A_SYM,"ProgramChangeInput",A_LONG,12);


    //------------------------------------ Key Settings
    for (long k=1;k<11;k++)
    {
        //Key Number
        attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,k);

        //Settings
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_X",A_LONG,16l);
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_X",A_LONG,85l);
        attribute(x,3,A_SYM,"set",A_SYM,"Dead_Y",A_LONG,16l);
        //attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,preset.value(QString("%1_key_setting_yAccel").arg(k)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,85l);
        attribute(x,3,A_SYM,"set",A_SYM,"On_Sens",A_LONG,30l);
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
    for (long p=0;p<10;p++)
    {

        QVariantMap preset = master.value(QString("Preset_00%1").arg(p)).toMap();

        if(!preset.value("useFactory").toString().contains("No"))
        {
            qDebug() << "use factory" << preset.value("useFactory").toString();
            slotComposeFactoryPreset(p, preset.value("useFactory").toString(), x);
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////   NO Factory     /////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else
        {
            attribute(x,2,A_SYM,"preset",A_LONG,p);
            attribute(x,3,A_SYM, "set",A_SYM,"Scene_Name",A_SYM,preset.value("displayName").toString().toUtf8().constData());

            //qDebug() << preset.value("displayName").toString().toUtf8().constData();

            //----------------------------------------------------------------------------------------//
            //------------------------------------------ Keys ----------------------------------------//
            //----------------------------------------------------------------------------------------//
            for(long k = 1l; k < 11l; k++)
            {
                attribute(x,2,A_SYM,"key",A_LONG,k);
                attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM, preset.value(QString("%1_key_name").arg(k)).toString().toUtf8().constData());

                if(preset.value(QString("%1_key_source").arg(k)).toString() == "sourceYInc")
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"Y");
                }
                else if(preset.value(QString("%1_key_source").arg(k)).toString() == "sourceXY")
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"XY");
                }
                else
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,1l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"XY");
                }

                //--------------------------------------- Modlines ---------------------------------------//
                for(long m = 0l; m < 6l; m++)
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m+1);

                    //---------------------------- SSCOM
                    //First two lines are twins, except for their device output
                    if(m < 2l && !preset.value(QString("%1_key_modline_source").arg(k)).toString().contains("None"))
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                        attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,1l);
                        attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("%1_key_modline_source").arg(k)).toString().toUtf8().constData());
                        attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("%1_key_modline_gain").arg(k)).toFloat());
                        attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                        attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("%1_key_modline_table").arg(k)).toString().toUtf8().constData());
                        attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("%1_key_modline_min").arg(k)).toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("%1_key_modline_max").arg(k)).toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("%1_key_modline_slew").arg(k)).toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,(long)preset.value("midiChannel").toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("%1_key_modline_destination").arg(k)).toString().toUtf8().constData());

                        //Note Params
                        if(preset.value(QString("%1_key_modline_destination").arg(k)).toString().contains("Note"))
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("%1_key_noteNum").arg(k)).toLongLong());
                            attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("%1_key_noteVelocity").arg(k)).toLongLong());
                        }

                        //CC Params
                        else if(preset.value(QString("%1_key_modline_destination").arg(k)).toString().contains("CC"))
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("%1_key_modline_cc").arg(k)).toLongLong());
                        }

                        //Devices
                        if(m == 0l)
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_USB_MIDI");
                        }
                        else
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
                        }

                        //LEDs
                        //Handle LED States for sources using 2 modlines
                        if(preset.value(QString("%1_key_source").arg(k)).toString().contains("sourceXY") ||
                                preset.value(QString("%1_key_source").arg(k)).toString().contains("sourceProgram") ||
                                preset.value(QString("%1_key_source").arg(k)).toString().contains("sourceYInc"))
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                        }
                        else
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,preset.value(QString("%1_key_led_green").arg(k)).toString().toUtf8().constData());
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                        }
                    }

                    //--------------------- EXPANDER
                    //If source requires two modlines (XY, Program), then make twins on 3 and four for each output device
                    else if(m < 4l && !preset.value(QString("%1_key_modline2_source").arg(k)).toString().contains("None"))
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                        attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,1l);
                        attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("%1_key_modline2_source").arg(k)).toString().toUtf8().constData());
                        attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("%1_key_modline_gain").arg(k)).toFloat());
                        attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                        attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("%1_key_modline_table").arg(k)).toString().toUtf8().constData());
                        attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("%1_key_modline2_min").arg(k)).toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("%1_key_modline2_max").arg(k)).toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("%1_key_modline_slew").arg(k)).toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,(long)preset.value("midiChannel").toLongLong());
                        attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("%1_key_modline2_destination").arg(k)).toString().toUtf8().constData());

                        //CC Params (other possibility is program)
                        if(preset.value(QString("%1_key_modline2_destination").arg(k)).toString().contains("CC"))
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("%1_key_modline2_cc").arg(k)).toLongLong());
                        }

                        if(m == 2l)
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_USB_MIDI");
                        }
                        else
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
                        }

                        //LEDs
                        attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                        attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                    }

                    //Turn all other lines off, unless needed for LEDs
                    //####################################################### This should be cleaned up when I'm less tired #######################################
                    else
                    {

                        //Handle LED States for special sources on last modline, if SoftStep2
                        if(m == 5l && isSoftStep2)
                        {
                            //For XY, YInc, and Program Change, create an LED modline
                            if(preset.value(QString("%1_key_source").arg(k)).toString().contains("sourceXY") ||
                                    preset.value(QString("%1_key_source").arg(k)).toString().contains("sourceProgram") ||
                                    preset.value(QString("%1_key_source").arg(k)).toString().contains("sourceYInc"))
                            {
                                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"Foot_On");
                                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"True");
                            }

                            //If not mentioned above turn off
                            else
                            {
                                attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
                                attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"None");
                                attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                            }

                            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                            attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                            attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM,"1_Lin");
                            attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                            attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"None");
                        }

                        //If SS1, modline 4 or 5, don't use LEDs and set to off
                        else
                        {
                            attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"None");
                            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                            attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                            attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM,"1_Lin");
                            attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                            attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,"None");
                            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,"None");
                            attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"None");
                        }
                    }
                }
            }

            //----------------------------------------------------------------------------------------//
            //----------------------------------------- NavP. ----------------------------------------//
            //----------------------------------------------------------------------------------------//
            attribute(x,2,A_SYM,"key",A_LONG,11l);
            attribute(x,3,A_SYM,"set",A_SYM,"Nav_Modline_Mode",A_LONG,1l);

            //set nav pad key name to scene name and display to always so that then scene name will display when the nav pad is pressed.
            attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM,preset.value("displayName").toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,4l);
            attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,"Y");

            for(long m = 0l; m < 6l; m++)
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m+1);

                //Y Inc-dec
                if(m < 2l)
                {

                    if(preset.value("navPadCC").toLongLong() != -1l)
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                    }
                    else
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
                    }

                    if(m == 0)
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,1l);
                    }
                    else
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                    }

                    attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"Nav_Y_Inc-Dec");
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                    attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
                    attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value("midiChannel").toLongLong());
                    attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value("navPadCC").toLongLong());

                    if(m == 0l)
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_USB_MIDI");
                    }
                    else
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
                    }
                }

                //Pedal
                else if(m < 4l)
                {
                    if(preset.value("pedalCC").toLongLong() != -1l)
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
                    }
                    else
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
                    }

                    attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"Pedal");
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                    attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, "1_Lin");
                    attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value("midiChannel").toLongLong());
                    attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value("pedalCC").toLongLong());

                    if(m == 2l)
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_USB_MIDI");
                    }
                    else
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
                    }
                }

                //All other lines off
                else
                {
                    attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m+1);
                    attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,"None");
                    attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,1.0000);
                    attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0000);
                    attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM,"1_Lin");
                    attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,127l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,0l);
                    attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"None");
                }
            }
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



    //Send Settings
    emit signalSendSysEx(settings, settingsLength);
    slotSettingsSent();

}

void SysExComposer::slotSettingsSent()
{
    qDebug("freeing settings");
    free(settings);

    emit signalSendSysEx(image, imageLength);
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

void SysExComposer::slotComposeFactoryPreset(long p, QString factoryPresetName, t_softstep* x)
{
    QVariantMap preset;

    if(factoryPresetName == "Program Change")
    {
        preset = factoryPresets->programChangeMap;
    }
    else if(factoryPresetName == "ElevenRack Control")
    {
        preset = factoryPresets->factoryElevenRackMap;
    }
    else if(factoryPresetName == "Line6 Pod Control")
    {
        preset = factoryPresets->factoryPodMap;
    }
    else if(factoryPresetName == "Ableton Live Control")
    {
        preset = factoryPresets->factoryLiveMap;
    }

    attribute(x,2,A_SYM,"preset",A_LONG,p);
    attribute(x,3,A_SYM, "set",A_SYM,"Scene_Name",A_SYM,preset.value("displayname").toString().toUtf8().constData());

    //----------------------------------------------------------------------------------------//
    //------------------------------------------ Keys ----------------------------------------//
    //----------------------------------------------------------------------------------------//
    for(long k = 1; k < 11; k++)
    {
        attribute(x,2,A_SYM,"key",A_LONG,k);
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM, preset.value(QString("key%1_name").arg(k)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,preset.value(QString("key%1_prefix").arg(k)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,preset.value(QString("key%1_displaymode").arg(k)).toLongLong());

        for(long m = 1; m < 7; m++ )
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m);
            attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,preset.value(QString("key%1_modline%2_enable").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("key%1_modline%2_source").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("key%1_modline%2_gain").arg(k).arg(m)).toFloat());
            attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,preset.value(QString("key%1_modline%2_offset").arg(k).arg(m)).toFloat());
            attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("key%1_modline%2_table").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("key%1_modline%2_min").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("key%1_modline%2_max").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("key%1_modline%2_slew").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("key%1_modline%2_destination").arg(k).arg(m)).toString().toUtf8().constData());

            //Set destination dependent params
            QString dest = preset.value(QString("key%1_modline%2_destination").arg(k).arg(m)).toString();

            if(dest.contains("Note"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("key%1_modline%2_note").arg(k).arg(m)).toLongLong());
                attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("key%1_modline%2_velocity").arg(k).arg(m)).toLongLong());
            }
            else if(dest.contains("CC"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("key%1_modline%2_cc").arg(k).arg(m)).toLongLong());
            }

            attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("key%1_modline%2_channel").arg(k).arg(m)).toLongLong());
            //qDebug() << "------------------ " << preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString().toUtf8().constData();
            QString deviceTest = preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString();
            if(deviceTest.contains("SoftStep_USB_MIDI") || deviceTest.contains("SoftStep_Expander"))
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString().toUtf8().constData());
            }

            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,preset.value(QString("key%1_modline%2_ledred").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,preset.value(QString("key%1_modline%2_ledgreen").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,preset.value(QString("key%1_modline%2_displaylinked").arg(k).arg(m)).toString().toUtf8().constData());

        }   //modline loop
    }       //key loop

    //----------------------------------------------------------------------------------------//
    //----------------------------------------- NavP. ----------------------------------------//
    //----------------------------------------------------------------------------------------//
    attribute(x,2,A_SYM,"key",A_LONG,11l);
    attribute(x,3,A_SYM,"set",A_SYM,"Nav_Modline_Mode",A_LONG,preset.value("nav_modlinemode").toLongLong());



    //set nav pad key name to scene name and display to always so that then scene name will display when the nav pad is pressed.
    attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM,preset.value("nav_name").toString().toUtf8().constData());
    attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,preset.value("nav_displaymode").toLongLong());
    attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,preset.value("nav_prefix").toString().toUtf8().constData());

    for(long m = 1; m < 7; m++ )
    {
        QString k = "nav";

        attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m);

        attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,preset.value(QString("%1_modline%2_enable").arg(k).arg(m)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("%1_modline%2_source").arg(k).arg(m)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("%1_modline%2_gain").arg(k).arg(m)).toFloat());
        attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,preset.value(QString("%1_modline%2_offset").arg(k).arg(m)).toFloat());
        attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("%1_modline%2_table").arg(k).arg(m)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("%1_modline%2_min").arg(k).arg(m)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("%1_modline%2_max").arg(k).arg(m)).toLongLong());
        attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("%1_modline%2_slew").arg(k).arg(m)).toLongLong());

        //Set destination dependent params
        QString dest = preset.value(QString("%1_modline%2_destination").arg(k).arg(m)).toString();

        if(dest.contains("Note"))
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Note_Number",A_LONG,preset.value(QString("%1_modline%2_note").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,preset.value(QString("%1_modline%2_velocity").arg(k).arg(m)).toLongLong());
        }
        else if(dest.contains("CC"))
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value(QString("%1_modline%2_cc").arg(k).arg(m)).toLongLong());

            qDebug() << "\n\n------------cc num for nav" << preset.value(QString("%1_modline%2_cc").arg(k).arg(m)).toLongLong();
        }

        attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("%1_modline%2_destination").arg(k).arg(m)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("%1_modline%2_channel").arg(k).arg(m)).toLongLong());

        QString deviceTest = preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString();
        if(deviceTest.contains("SoftStep_USB_MIDI") || deviceTest.contains("SoftStep_Expander"))
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,preset.value(QString("key%1_modline%2_device").arg(k).arg(m)).toString().toUtf8().constData());
        }

        attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,preset.value(QString("%1_modline%2_displaylinked").arg(k).arg(m)).toString().toUtf8().constData());
    }


}

void SysExComposer::slotStandaloneOn()
{
    qDebug() << "slotStandaloneOn called";
    emit signalSendSysEx(_fw_tether_off, sizeof(_fw_tether_off));
    emit signalSendSysEx(_fw_standalone_on, sizeof(_fw_standalone_on));
    emit signalSendSysEx(_fw_scenechange_on_persist, sizeof(_fw_scenechange_on_persist));
    emit signalSendSysEx(_fw_nav_standalone_on_persist, sizeof(_fw_nav_standalone_on_persist));
    emit signalSendSysEx(_fw_nav_standalone_on, sizeof(_fw_nav_standalone_on));

}

