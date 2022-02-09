// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
//#define DEVELOPMENT


#include <stdlib.h>
#include <string.h>
#include "maxapi.h"
#include "softstep.h"
#include "utils.h"
#include "download.h"
#include "syxformats.h"
#include "attribute.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include "syxtx.h"

#include <qglobal.h>


char *garageband_function_list[] = {"None","Rewind_to_Start","Rewind","Play","Fast_Forward","Loop","Record"};
char *mmc_function_list[] = {"None","Stop","Play","Deferred_Play","Fast_Forward","Rewind","Punch_In","Punch_Out","Pause"};
char *hui_function_list[] = {"Play","Stop","Rewind","Fast_Forward","Rec_Enable","Solo","Mute","Next_Bank","Prev_Bank"};
char *destination_list[] = {"SSCOM_Port_1","SoftStep_Expander"};
char *dest_list[] = {"None","Note_Set","Note_Live","CC","Bank","Program","Pitch_Bend","MMC","GarageBand","HUI",0};
char *table_list[] = {"0_Off","1_Lin","2_Sin","3_Cos","4_Exponential","5_Logarithmic","Toggle","Toggle_127",0};
char *table_list2[] = {"Off","Lin","Sin","Cos","Exponential","Logarithmic","Toggle",0};
char *led_list[] = {"None","True","False","Flash True","Flash False","Flash_Fast_True","Flash_Fast_False","Blink_True","Blink_False","Off",0};



char *source_list[] = {
    "None","Knob","Pressure_Latch","X_Latch","Y_Latch","Pressure_Live","X_Live","Y_Live","X_Increment",SRC_Y_INCREMENT,
    "Foot_On","Foot_Off","Preset","Pedal","Wait_Trig","Fast_Trig","Dbl_Trig",SRC_LONG_TRIG,"Off_Trig",
    "Wait_Trig_Latch","Fast Trig Latch","Long Trig Latch",SRC_NAV_Y,"Nav Yx10 & Key",
    SRC_ANY_KEY_VALUE,"Prev Key Value","This Key Value",
    "Key 0 Pressed","Key 1 Pressed","Key 2 Pressed","Key 3 Pressed","Key 4 Pressed","Key 5 Pressed",
    "Key 6 Pressed","Key 7 Pressed","Key 8 Pressed","Key 9 Pressed",SRC_OTHER_KEY_PRESSED,
    MODLINE_1_OUTPUT,"Modline 2 Output","Modline 3 Output","Modline 4 Output","Modline 5 Output",MODLINE_6_OUTPUT,
    "Init",
    0};



char *source_xlate[] = {
    "Nav_Y_Inc-Dec",SRC_Y_INCREMENT,
    0,0
};

int xlate_key_num(int in)
{
	int out = in;
	
	if (in == 10)
		out = 0;
	if (in >= 11)
		out = 10;
	
    post("xlate key[%d] to key[%d]\n",in,out);
	
	return out;
}

void attribute_process(t_softstep *x, short argc, t_atom *argv)
{

    //printf("\n");
    //fflush(stdout);
    //post_par_list(argc, argv, "");

    if (argc==3 && argv[1].a_type==A_SYM && argv[2].a_type==A_SYM)
    {
        //post("comparing %s %s\n",argv[1].a_w.w_sym->s_name,argv[2].a_w.w_sym->s_name);
    }

    if ( par_match(argc,argv,A_SYM,"download",A_SYM,0,-1))
    {
        //post("download file %s\n",argv[1].a_w.w_sym->s_name);
        download_file_open(x,argv[1].a_w.w_sym->s_name);

        download_start(x);

    } else if ( par_match(argc,argv,A_SYM,"download",-1))
    {
#ifdef DEVELOPMENT
        download_file_open(x,"scenes");
#endif

        post("download\n");

        download_start(x);
        return;

    }
    if ( par_match(argc,argv,A_SYM,"preset",A_LONG,0l,-1) )
    {
        PRESET_LIST **list = &x->first;
        int i=0,just_created = false,count = (int) argv[1].a_w.w_long;

        post("********************************** download preset[%d]************************************\n",count);

        for(;;) {
            if (*list) {
                if (i++==count)
                {
                    if (!just_created)
                        post("--------------------  Error: Duplicate scene[%d] -------------------\n",count);
                    break;
                }
                else
                {
                    list = &(*list)->next;
                    just_created = false;
                }
            }
            else
            {


                *list = (PRESET_LIST *) malloc(sizeof(PRESET_LIST));
                if (*list)
                {
                    memset(*list,0,sizeof(PRESET_LIST));
                    //post("create preset_list size[%d] at[%p]\n",sizeof(PRESET_LIST),*list);
                    (*list)->strings.size = 1; // so a zero pointer points to null string
                    //post("create preset_image size[%d] at[%p]\n",sizeof(PRESET_IMAGE),(*list)->preset_image);
                    (*list)->next = NULL;
                    just_created = true;
                }
            }
        }
        x->current_image = &(*list)->preset_image;
        x->current_list = *list;
        memset(x->current_image,0,sizeof(PRESET_IMAGE));
        x->settings.programChangeInput = 16;
        return;

    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Modline",A_LONG,0l,-1) )
    {
        //post("Modline matched");
        x->mod_num_current = (int) argv[2].a_w.w_long - 1;


        x->current_modline = &x->current_image->modlines[x->key_num][x->mod_num_current];

        //post("--- %s key[%d] modline[%d]",x->current_list->strings.data + LE_short(x->current_image->nm.name_index),x->key_num,x->mod_num_current);
        return;
    }


    if (par_match(argc,argv,A_SYM,"key",A_SYM,"nav",-1))
    {
        //post("************************************ found key nav *********************************");
        x->key_num = NUM_KEYS - 1;
        //post("key settings index [%d]\n", x->key_settings_index);
        return;
    }

    if (par_match(argc,argv,A_SYM,"key",A_LONG,0l,-1))
    {
        x->key_num = (int) xlate_key_num((int)argv[1].a_w.w_long);
        return;
    }

    if (par_match(argc,argv,A_SYM,"set",A_SYM,"On",A_LONG,0l,-1))
    {
        x->current_list->enables[x->key_num][x->mod_num_current] = argv[2].a_w.w_long;
        //post("************* set On key[%d][%d]=%d",x->key_num,x->mod_num_current,x->current_list->enables[x->key_num][x->mod_num_current]);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Display_Mode",A_LONG,0l,-1))
    {
        x->current_image->nm.key[x->key_num].display_mode = LIMIT_255(argv[2].a_w.w_long);
        //post("Display Mode[%d]",x->current_image->nm.key[x->key_num].display_mode);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Nav_Modline_Mode",A_LONG,0l,-1))
    {
        x->current_image->nm.key[x->key_num].nav_y_mode = argv[2].a_w.w_long;
        //post("Nav Modline Mode [%d]", x->current_image->nm.key[x->key_num].nav_y_mode);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Key_Name",A_SYM,0,-1)){
        x->current_image->nm.key[x->key_num].key_name_index = LE_short(x->current_list->strings.size);
        strcpy(x->current_list->strings.data+x->current_list->strings.size,argv[2].a_w.w_sym->s_name);
        x->current_list->strings.size += strlen(argv[2].a_w.w_sym->s_name) + 1;
        //post("Key_Name[%s] key[%d] index[%d]",argv[2].a_w.w_sym->s_name,x->key_num,LE_short(x->current_image->nm.key[x->key_num].key_name_index));
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Prefix_Name",A_SYM,0,-1)){
        char *str = argv[2].a_w.w_sym->s_name;
        int len;
        //		int i;

        if (*str == '"')
            str++;

        len = (int) strlen(str);

        //		post("len[%d]",len);
        //		for (i=0;i<len;i++)
        //			post("%d = %d",i,str[i]);

        if (len) {
            x->current_image->nm.key[x->key_num].prefix_index = LE_short(x->current_list->strings.size);
            strcpy(x->current_list->strings.data+x->current_list->strings.size,str);
            x->current_list->strings.size += len + 1;
        } else {
            //    x->current_image->nm.key[x->key_num].prefix_index;
        }

        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Dead_X",A_LONG,0l,-1)){

        x->settings.key[x->key_settings_index].dead_x = LIMIT_255(argv[2].a_w.w_long);
        //post("Dead X [%d]\n", x->settings.key[x->key_settings_index].dead_x);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Accel_X",A_LONG,0l,-1))
    {
        x->settings.key[x->key_settings_index].accel_x = LIMIT_255(argv[2].a_w.w_long);
        //post("Accel_X [%d]\n", x->settings.key[x->key_settings_index].accel_x);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Dead_Y",A_LONG,0l,-1))
    {
        x->settings.key[x->key_settings_index].dead_y = LIMIT_255(argv[2].a_w.w_long);
        //post("Dead Y [%d]\n",  x->settings.key[x->key_settings_index].dead_y);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Accel_Y",A_LONG,0l,-1))
    {
        x->settings.key[x->key_settings_index].accel_y = LIMIT_255(argv[2].a_w.w_long);
        //post("Accel Y [%d]\n", x->settings.key[x->key_settings_index].accel_y);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"On_Sens",A_LONG,0l,-1))
    {
        x->settings.key[x->key_settings_index].on_sense=argv[2].a_w.w_long;
        //post("On_Sens [%d]\n", x->settings.key[x->key_settings_index].on_sense);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Off_Sens",A_LONG,0l,-1)){
        x->settings.key[x->key_settings_index].off_sense=argv[2].a_w.w_long;
        //post("Off_Sense [%d]\n", x->settings.key[x->key_settings_index].off_sense);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Delta",A_LONG,0l,-1))
    {
        x->settings.key[x->key_settings_index].delta=argv[2].a_w.w_long;
        //post("Delta [%d]\n", x->settings.key[x->key_settings_index].delta);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"North_On_Thresh",A_LONG,0l,-1))
    {
        x->settings.north_on_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"North_Off_Thresh",A_LONG,0l,-1))
    {
        x->settings.north_off_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"East_On_Thresh",A_LONG,0l,-1))
    {
        x->settings.east_on_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"East_Off_Thresh",A_LONG,0l,-1))
    {
        x->settings.east_off_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"South_On_Thresh",A_LONG,0l,-1))
    {
        x->settings.south_on_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"South_Off_Thresh",A_LONG,0l,-1))
    {
        x->settings.south_off_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"West_On_Thresh",A_LONG,0l,-1))
    {
        x->settings.west_on_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"West_Off_Thresh",A_LONG,0l,-1))
    {
        x->settings.west_off_thresh=argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,0l,-1))
    {
        x->key_settings_index = (int) argv[3].a_w.w_long-1;
        //post("key settings index [%d]\n", x->key_settings_index);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Key_Mode",A_LONG,0l,-1))
    {
        x->settings.key_mode = argv[2].a_w.w_long;
        //post("key mode [%d]\n",  x->settings.key_mode);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Key_Response",A_LONG,0l,-1))
    {
        x->settings.key_response = argv[2].a_w.w_long;
        //post("key response [%d]\n", x->settings.key_response);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"EL_Mode",A_LONG,0l,-1))
    {
        x->settings.el_offon = argv[2].a_w.w_long;
        //post("el mode", x->settings.el_offon);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"prog_change_display_offset",A_LONG,0l,-1))
    {
        x->settings.prog_change_display_offset = argv[2].a_w.w_long;
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Pedal_Table",A_GIMME,-1))
    {
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"pedalEdges",A_LONG,0l,A_LONG,0l,-1))
    {
        //post_par_list(argc,argv,"pedal");
        x->settings.pedal_calibration.heal = argv[3].a_w.w_long+3;
        x->settings.pedal_calibration.toe = argv[2].a_w.w_long-3;
        x->settings.pedal_calibration.mpx = LE_short((128 * 256) / (x->settings.pedal_calibration.toe - x->settings.pedal_calibration.heal));
        //post("mpx[%x]",x->settings.pedal_calibration.mpx);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"pedalHysteresis",A_LONG,0l,-1))
    {
        x->settings.pedal_filter.hysteresis = argv[2].a_w.w_long;
        //post("setting hysteresis[%d]",x->settings.pedal_filter.hysteresis);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"pedalFilterLength",A_LONG,0l,-1))
    {
        int length = (int) argv[2].a_w.w_long;
        if (length>=0x100)
            length = LE_short(length);
        x->settings.pedal_filter.length = argv[2].a_w.w_long > 5 ? 5 : argv[2].a_w.w_long;
        //		post("setting length[%d]",x->settings.pedal_filter.length);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Rot_Slew",A_LONG,0l,-1))
    {
        x->settings.key[x->key_settings_index].Rot_Slew = LIMIT_255(argv[2].a_w.w_long);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Global_Gain",A_FLOAT,0.0,-1))
    {
        float_fix(&x->settings.Global_Gain,argv[2].a_w.w_float);
        //post("$ global gain [%f]\n", argv[2].a_w.w_float);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"ProgramChangeInput",A_LONG,0l,-1))
    {
        x->settings.programChangeInput = (int)argv[2].a_w.w_long;
        //post("*************** here is ProgramChangeInput channel[%d]",(int)argv[2].a_w.w_long);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"ProgramChangeChannelDIN",A_LONG,0l,-1))
    {
        x->settings.programChangeInput = argv[2].a_w.w_long;
        //post("*************** here is ProgramChangeChannelDIN[%d]",(int) argv[2].a_w.w_long);
        return;
    }


    //********************Â±***********************************************************
    //	if (x->ignore_modline)  // modline break.  Don't allow ignored modlines
    //	{
    //		post("ignoring modline");
    //		return;
    //	} else
    //********************************************************************************
    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Note_Channel",A_LONG,0l,-1) )
    {
        x->current_modline->channel = argv[2].a_w.w_long-1;
        //post("Note Channel\n", x->current_modline->channel);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Note_Velocity",A_LONG,0l,-1) ||
         par_match(argc,argv,A_SYM,"set",A_SYM,"Note_Live_Velocity",A_LONG,0l,-1) ||
         par_match(argc,argv,A_SYM,"set",A_SYM,"Velocity",A_LONG,0l,-1)	)
    {
        x->current_modline->ms.note.velocity = argv[2].a_w.w_long;
        //post("setting velocity[%d]\n",argv[2].a_w.w_long);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Note_Number",A_LONG,0l,-1) )
    {
        x->current_modline->ms.note.number = argv[2].a_w.w_long;
        //post("Note Number [%d]\n", x->current_modline->ms.note.number);
        return;
    }

    if (	par_match(argc,argv,A_SYM,"set",A_SYM,"Channel",A_LONG,0l,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Control_Channel",A_LONG,0l,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Bank_Channel",A_LONG,0l,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Bend_Channel",A_LONG,0l,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Program_Channel",A_LONG,0l,-1) )
    {
        x->current_modline->channel = argv[2].a_w.w_long-1;
        //post("channel [%d]\n", x->current_modline->channel);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Control_Number",A_LONG,0l,-1) )
    {
        x->current_modline->ms.controller = argv[2].a_w.w_long;
        //post("control number [%d]\n", x->current_modline->ms.controller);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"MMC_Device_ID",A_LONG,0l,-1) )
    {
        x->current_modline->ms.mmc.device_id = argv[2].a_w.w_long;
        //post("MMC device Id [%d]\n", x->current_modline->ms.mmc.device_id);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"MMC_Function",A_SYM,0,-1))
    {
        x->current_modline->ms.mmc.function = get_index(mmc_function_list,NULL,argv+2);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Garageband_Function",A_SYM,0l,-1))
    {
        x->current_modline->ms.garageband_function = get_index(garageband_function_list,NULL,argv+2);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"HUI_Function",A_SYM,0,-1))
    {
        x->current_modline->ms.hui.function = get_index(hui_function_list,NULL,argv+2);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"HUI_Track",A_LONG,0l,-1))
    {
        x->current_modline->ms.hui.track = argv[2].a_w.w_long-1;
        return;
    }

    //Bank MSB
    if (    par_match(argc,argv,A_SYM,"set",A_SYM,"bank_msb",A_LONG,0l,-1))  // xxxnew
    {
        x->current_modline->ms.bank_msb = argv[2].a_w.w_long;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Min",A_LONG,0l,-1) )
    {
        x->current_modline->min = argv[2].a_w.w_long;
        //post("mind [%d]\n", x->current_modline->min);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Max",A_LONG,0l,-1) )
    {
        x->current_modline->max = argv[2].a_w.w_long;
        //post("Max [%d]\n", x->current_modline->max);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Slew",A_LONG,0l,-1) )
    {
        //		x->current_modline->slew = 10;

        if (argv[2].a_w.w_long)
            x->current_modline->slew = LE_short(argv[2].a_w.w_long / 10 + 1) ;
        else
            x->current_modline->slew = 0;

        //post("Slew [%d]\n", x->current_modline->max);

        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Source",A_SYM,0,-1))
    {
        if (argc==3)
        {
            //			extern int get_index_verbose;
            //			get_index_verbose = 1;
            //			post("searching for %s",argv[2].a_w.w_sym->s_name);
            x->current_modline->source = get_index(source_list,source_xlate,argv + 2);
            //			get_index_verbose = 0;
        }
        //post("source: %d *******\n",x->current_modline->source);
        return;
    }
    if (par_match(argc,argv,A_SYM,"set",A_SYM,"Device",A_SYM,0,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Control_Device",A_SYM,0,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Note_Live_Device",A_SYM,0,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Bank_Device",A_SYM,0,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Program_Device",A_SYM,0,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Bend_Device_ID",A_SYM,0,-1) ||
            par_match(argc,argv,A_SYM,"set",A_SYM,"Bend_Device",A_SYM,0,-1)	)
    {
        x->current_modline->port = get_index(destination_list,NULL,argv + 2);   
        //post("Device [%s]",argv[2].a_w.w_sym->s_name);
        return;
    }
    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Destination",A_SYM,0,-1))
    {
        x->current_modline->dest = get_index(dest_list,NULL,argv + 2);
        //post("destination [%d]\n", x->current_modline->dest);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Table",A_SYM,0,-1))
    {
        //		post("*************** set Table %d %d",argv[2].a_type,A_SYM);
        x->current_modline->table = get_index(table_list,NULL,argv + 2);
        //post("table [%d]\n", x->current_modline->table);
        return;
    }

    //	if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Table",A_LONG,0l,A_SYM,0,-1))// needed because the '1 Lin' got split up to number and string
    //	{
    //		x->current_modline->table = get_index(table_list2,argv + 3);
    //	}
    //	else
    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Gain",A_FLOAT,0.0,-1))
    {
        float oval,fval;

        oval = fval = argv[2].a_w.w_float;

        float_fix(&x->current_modline->gain,fval);

                //post("set fixed point %f: %x:%x",oval,x->current_modline->gain.u.upper,x->current_modline->gain.u.lower);

                //set_fixed_point(&x->current_image->gain,argv + 2);
        //post("gain [%f]\n", argv[2].a_w.w_float);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Offset",A_FLOAT,0.0,-1))
    {
        float oval,fval;

        oval = fval = argv[2].a_w.w_float;

        float_fix(&x->current_modline->offset,fval);

        //post("set fixed point %f: %x:%x",oval,x->current_image->offset.u.upper,x->current_image->offset.u.lower);

        //		set_fixed_point(&x->current_image->offset,argv + 2);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"LED_Menu_Green",A_SYM,0,-1))
    {
        x->current_modline->led_green = get_index(led_list,NULL,argv + 2);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"LED_Menu_Red",A_SYM,0,-1))
    {
        x->current_modline->led_red = get_index(led_list,NULL,argv + 2);
        //		post("led_menu_red %s",argv[2].a_w.w_sym->s_name);
        return;
    }

    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Display_Linked",A_LONG,0l,-1))
    {
        x->current_modline->display_linked = LIMIT_255(argv[2].a_w.w_long);
        return;
    }

    //	post("comparing Scene Name");


    if ( par_match(argc,argv,A_SYM,"set",A_SYM,"Scene_Name",A_SYM,0,-1))
    {
        //post("setting scene name[%s] at name_index[%d]\n",argv[2].a_w.w_sym->s_name,x->current_list->strings.size);
        x->current_image->nm.name_index = LE_short(x->current_list->strings.size);
        strcpy(x->current_list->strings.data+x->current_list->strings.size,argv[2].a_w.w_sym->s_name);
        x->current_list->strings.size += strlen(argv[2].a_w.w_sym->s_name) + 1;
        //		post("new index[%d]",x->current_list->strings.size);
        return;
    }

    //par_error(x,argc,argv,"attribute");

}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//utils.c

#define MAX_ARGV 4

void attribute(t_softstep *x,int count,...)
{
    int argc = count;
    int i;

    t_atom argv[MAX_ARGV];
    va_list arguments;

    va_start ( arguments, count );

    for (i = 0; i < count; i++ )        // Loop until all numbers are added
    {
        int type = va_arg(arguments,int);
        argv[i].a_type = type;

        switch(type)
        {
        case A_LONG:
            argv[i].a_w.w_long = va_arg(arguments,long);
            break;
        case A_FLOAT:
            argv[i].a_w.w_float = va_arg(arguments,double);
            break;
        case A_SYM:
            argv[i].a_w.w_sym = gensym(va_arg(arguments,char *));
            break;
        default:
            printf("attribute: unknown type %d",type);
            fflush(stdout);
            va_end ( arguments );                  // Cleans up the list
            return;

        }
    }
    attribute_process(x,argc,argv);

    va_end ( arguments );                  // Cleans up the list
}

unsigned short crc;
void crc_init(void) {
    crc = 0xffff;
}
void crc_byte(char val)   {
    unsigned short temp;
    unsigned short quick;

    temp = (crc >> 8) ^ val;
    crc <<= 8;
    quick = temp ^ (temp >> 4);
    crc ^= quick;
    quick <<= 5;
    crc ^= quick;
    quick <<= 7;
    crc ^= quick;
}
int str_space_cmp(char *str1,char *str2)
{
    do{
        if (*str1==' ' || *str1=='_')
        {
            if (*str2 != ' ' && *str2!= '_')
                return 1;
        } else
            if (toupper(*str1) != toupper(*str2))
                return 1;
    }
    while(*str1++ && *str2++);
    return 0;
}
void par_list_str(short argc,t_atom *argv, char *str,int len) {
    int i;
    for (i=0;i<argc;i++) {
        switch(argv[i].a_type)
        {
        case A_LONG:
            snprintf(str+strlen(str),len," %ldL",argv[i].a_w.w_long);
            break;
        case A_FLOAT:
            snprintf(str+strlen(str),len," %fF",argv[i].a_w.w_float);
            break;
        case A_SYM:
            snprintf(str+strlen(str),len," %s",argv[i].a_w.w_sym->s_name);
            break;
        default:
            snprintf(str+strlen(str),len," unknown");
            break;
        }
    }

}
void vpost_par_list(short argc,t_atom *argv, char *fmt,va_list a_list) {

    char emsg[2000];

    vsnprintf(emsg,sizeof(emsg),fmt,a_list);

    par_list_str(argc,argv,emsg+strlen(emsg),(int) (sizeof(emsg)-strlen(emsg)));
    post("%s", emsg);
    printf("\n");

}
void post_par_list(short argc,t_atom *argv, char *fmt,...) {
    va_list a_list;


    va_start( a_list, fmt);

    vpost_par_list(argc,argv,fmt,a_list);
    printf("\n");

    va_end(a_list);
}
int par_match(short argc,t_atom *argv,...) {
    int i,type;
    va_list a_list;
    va_start( a_list, argv);

    for (i=0;i<argc;i++) {
        type = va_arg(a_list,int);
        switch (type)
        {
        case A_SYM:
        {
            char *sym;
            if (argv[i].a_type != A_SYM)
                return 0;

            sym = va_arg(a_list,char *);

            if (sym && str_space_cmp(sym,argv[i].a_w.w_sym->s_name))
                return 0;
            //post("found %s",argv[i].a_w.w_sym->s_name);
        }
            break;
        case A_LONG:
            if (argv[i].a_type != A_LONG)
                return 0;
            va_arg(a_list,long);
            break;
        case A_FLOAT:
            //post("need a float[%d][%d]",argc,argv[i].a_type);
            if (argv[i].a_type != A_FLOAT)
                return 0;

#ifdef _WINDOWS
            //va_arg(a_list,float);
            va_arg(a_list,double);
#else
            va_arg(a_list,double);
#endif
            break;
        case A_GIMME:
            va_end ( a_list );                  // Cleans up the list
            return 1;
            break;
        case -1:
            if (i != (argc-1) )
                return 0;
            break;
        default:
            post("unknown type %d",type);
            return 0;
            break;
        }
    }

    type = va_arg(a_list,int);

    va_end ( a_list );                  // Cleans up the list

    if (type != -1 && type != A_GIMME)
        return 0;

    //	post_par_list(argc,argv,"match with: ");


    return 1;
}
void float_fix(FIXED_PT *val,float fval)
{
    val->whole = 0;

    if (fval <= -32768){
        val->u.upper = 0x8000;
        val->u.lower = 0x0000;
    }
    else
        if (fval >= 32768){
            val->u.upper = 0x7fff;
            val->u.lower = 0xffff;
        }
        else {
            fval *= 65536;
            val->whole = LE_int(fval);
        }
}
int first,data_index;

void write_c_title(char *title,t_softstep *x)
{
    if (!x->fd_c)
        return;

    fprintf(x->fd_c,"\ncode const unsigned char %s[]={",title);
    first = 1;
    data_index = 0;
}
void write_c_data(void *data,int length,t_softstep *x)
{
    int i;

    if (!x->fd_c)
        return;

    for (i=0;i<length;i++)
    {
        if (i || !first)
            fputc(',',x->fd_c);

        first = 0;
        if (!(i%16)) {
            fprintf(x->fd_c,"\n/*%04x*/\t",data_index);
        }
        fprintf(x->fd_c,"0x%02x",((unsigned char *) data)[i]);
        data_index++;
    }
}
void write_c_end(t_softstep *x)
{
    if (!x->fd_c)
        return;

    fprintf(x->fd_c,"\n\t};");
}
void write_c_close(t_softstep *x)
{
    if (!x->fd_c)
        return;

    fclose(x->fd_c);

    x->fd_c = 0;
}
void write_c(char *title,void *data,int length,t_softstep *x)
{
    if (!x->fd_c)
        return;

    write_c_title(title,x);
    write_c_data(data,length,x);
    write_c_end(x);
}

void par_error(t_softstep *x,short argc,t_atom *argv,char *msg)
{
#if 1
    Q_UNUSED(x);
    Q_UNUSED(argc);
    Q_UNUSED(argv);
    Q_UNUSED(msg);
#else
    post_par_list(argc,argv,"**************  No match for %s: key[%d] ************",msg,x->key_num);
#endif
}

int get_index_verbose = 0;

int get_index(char *list[],char *listXlate[],t_atom *argv)
{
    char source[200];
    int i,index;

    STRNCPY(source,argv->a_w.w_sym->s_name,sizeof(source))

            if (listXlate)
    {
        for(i=0;;i+=2)
        {
            if (!listXlate[i])
                break;
            //			post("xlate[%s][%s][%s]",source,listXlate[i],listXlate[i+1]);
            if (!strcmp(source,listXlate[i]))
                STRNCPY(source,listXlate[i+1],sizeof(source));
        }
    }



    index = 0;
    while (*list) {
        if (get_index_verbose)
            post("cmp [%s] [%s]\n",source,*list);
        if ( !str_space_cmp(*list,source) ) {
            //			post("matched %s",source);
            return index;
        }
        list++;
        index++;
    }
    //post("error trying to match: %s ******************************\n",source);
    return 0;
}
int get_index_str(char *list[],char *str)
{
    int index = 0;
    while (*list) {
        //	post("cmp [%s] [%s]",argv->a_w.w_sym->s_name,*list);
        if ( !str_space_cmp(*list,str) ) {
            //			post("matched %s",argv->a_w.w_sym->s_name);
            return index;
        }
        list++;
        index++;
    }
    //post("error trying to match: %s ******************************\n",str);
    return 0;
}
void sx_send_list(t_softstep *x,int type,char *description) {
    Q_UNUSED(description);

    //printf("sx_send_list[%s] -- len[%i] -- type[%i]\n",description, midi_sx_length(), type);
    //fflush(stdout);

    int i;
    //Set current sysex message pointer (this points to either settings or image)
    unsigned char* message = (unsigned char *) midi_sx_buffer();

    if(type == SX_TYPE_NORMAL) //Settings
    {

        //Allocate a unique buffer to store settings sysex message
        settings = (unsigned char*)malloc(midi_sx_length());



        //Set each each byte to its unique settings storage space for later use (because the pointers are changing)
        for(i =0; i < (int)midi_sx_length(); i++)
        {
            settings[i] = message[i];
            settingsLength = (int)midi_sx_length();
        }
    }
    else if(type == SX_TYPE_DOWNLOAD) //Standalone Image
    {
        //Allocate a unique buffer to store image sysex message
        image = (unsigned char*)malloc((int)midi_sx_length());

        //Set each each byte to its unique image storage space for later use (because the pointers are changing)
        for(i =0; i < (int)midi_sx_length(); i++)
        {
            image[i] = message[i];
            imageLength = (int)midi_sx_length();
        }
    }


    if (x->fd_syx)
    {
        fwrite(midi_sx_buffer(),midi_sx_length(),1,x->fd_syx);
        fclose(x->fd_syx);
        x->fd_syx = 0;
    }

    //sendSysex((unsigned char *) midi_sx_buffer(),(int) midi_sx_length(),0);
}

void sendSysex(unsigned char *src,int len, int type)
{

    image = src; imageLength = len;
    //0 == standalone image
    //1 == standalone settings

    if(type == 0)
    {
        int i;


        //printf("^^^^ %x -- %x \n", image, imageLength);
        //fflush(stdout);

        for(i = 0; i < imageLength; i++)
        {

            //printf("--------- %x --\n", (char*)image[i]);
            //fflush(stdout);

        }


    }
    else if(type == 1)
    {
        //settings = src; settingsLength = len;
    }


}

t_softstep *softstep_init(void)
{
    t_softstep *x = (t_softstep *) malloc(sizeof(t_softstep));
    memset(x,0,sizeof(t_softstep));

    x->device_softstep = true;
    x->build_num = 67;  // xxx This is the build num of the firmware you are replacing, not the new firmware.  You need to get this number from the device.

    return x;
}


