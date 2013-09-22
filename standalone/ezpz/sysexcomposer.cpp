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

    factoryPresets = new FactoryPresets();
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

void SysExComposer::slotComposeAttributeListFromPreset(QVariantMap presetSent, QVariantMap master, qlonglong presetNum)
{
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
    for (long p=0;p<10;p++)
    {

        QVariantMap preset = master.value(QString("Preset_00%1").arg(p)).toMap();

        if(!preset.value("useFactory").toString().contains("No"))
        {
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
                            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SSCOM_Port_1");
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
                            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SSCOM_Port_1");
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
                    attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,1l);
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
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SSCOM_Port_1");
                    }
                    else
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SoftStep_Expander");
                    }
                }

                //Pedal
                else if(m < 4l)
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
                    attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,"CC");
                    attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value("midiChannel").toLongLong());
                    attribute(x,3,A_SYM,"set",A_SYM,"Control_Number",A_LONG,preset.value("navPadCC").toLongLong());

                    if(m == 2l)
                    {
                        attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,"SSCOM_Port_1");
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

    emit signalSendSysEx(QString("standalone image"), image, imageLength, QString("SSCOM Port 1"));
    qDebug("freeing image");
    free(image);

    emit signalSendSysEx(QString("standalone image"), settings, settingsLength, QString("SSCOM Port 1"));
    qDebug("freeing settings");
    free(settings);

    //sysex message complete
    emit signalUpdateComplete();
}

void SysExComposer::slotComposeFactoryPreset(long p, QString factoryPresetName, t_softstep* x)
{
    QVariantMap preset = factoryPresets->programChangeMap;

    attribute(x,2,A_SYM,"preset",A_LONG,p);
    attribute(x,3,A_SYM, "set",A_SYM,"Scene_Name",A_SYM,preset.value("displayName").toString().toUtf8().constData());

    for(long k = 1; k < 11; k++)
    {
        attribute(x,2,A_SYM,"key",A_LONG,k);
        attribute(x,3,A_SYM,"set",A_SYM,"Key_Name",A_SYM, preset.value(QString("%1_key_name").arg(k)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,preset.value(QString("%1_key_prefix").arg(k)).toString().toUtf8().constData());
        attribute(x,3,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,preset.value(QString("%1_key_displayMode").arg(k)).toLongLong());

        for(long m = 1; m < 7; m++ )
        {
            attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m);
            attribute(x,3,A_SYM,"set",A_SYM,"On",A_LONG,preset.value(QString("%1_key_modline%2_on").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Source",A_SYM,preset.value(QString("%1_key_modline%2_source").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Gain",A_FLOAT,preset.value(QString("%1_key_modline%2_gain").arg(k).arg(m)).toFloat());
            attribute(x,3,A_SYM,"set",A_SYM,"Offset",A_FLOAT,preset.value(QString("%1_key_modline%2_offset").arg(k).arg(m)).toFloat());
            attribute(x,3,A_SYM,"set",A_SYM,"Table",A_SYM, preset.value(QString("%1_key_modline%2_table").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,preset.value(QString("%1_key_modline%2_min").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Max",A_LONG,preset.value(QString("%1_key_modline%2_max").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Slew",A_LONG,preset.value(QString("%1_key_modline%2_slew").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Destination",A_SYM,preset.value(QString("%1_key_modline%2_destination").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Channel",A_LONG,preset.value(QString("%1_key_modline%2_channel").arg(k).arg(m)).toLongLong());
            attribute(x,3,A_SYM,"set",A_SYM,"Device",A_SYM,preset.value(QString("%1_key_modline%2_device").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,preset.value(QString("%1_key_modline%2_led_red").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,preset.value(QString("%1_key_modline%2_led_green").arg(k).arg(m)).toString().toUtf8().constData());
            attribute(x,3,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,preset.value(QString("%1_key_modline%2_displayLinked").arg(k).arg(m)).toString().toUtf8().constData());

        }   //modline loop
    }       //key loop


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
