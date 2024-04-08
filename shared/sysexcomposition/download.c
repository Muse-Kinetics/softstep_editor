// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <stdlib.h>
#include <string.h>
#include "device_includes.h"
#include "syxformats.h"
#include "syxtx.h"
#include "midi_ss.h"
#include "maxapi.h"
#include "attribute.h"
#include "utils.h"

void free_presets(t_softstep *x);
int modline_is_output_reference(MODLINE *modline,int *index);
void send_standalone_settings(t_softstep *x);
void send_standalone_image(t_softstep *x);

#if defined(_WIN32) || defined(_WIN64)
#define _WINDOWS
#endif

//#ifdef	_WINDOWS
//#pragma pack(8) // default for x86
//#endif

STANDALONE_INFO standalone_info;
PAD_INFO pad_info;
PEDAL_INFO pedal_info;

int numTabs = 0;

char *source_list_d[] = {
    "None","Knob","Pressure_Latch","X_Latch","Y_Latch","Pressure_Live","X_Live","Y_Live","X_Increment",SRC_Y_INCREMENT,
    "Foot_On","Foot_Off","Preset","Pedal","Wait_Trig","Fast_Trig","Dbl_Trig",SRC_LONG_TRIG,"Off_Trig",
    "Wait_Trig_Latch","Fast Trig Latch","Long Trig Latch",SRC_NAV_Y,"Nav Yx10 & Key",
    SRC_ANY_KEY_VALUE,"Prev Key Value","This Key Value",
    "Key 0 Pressed","Key 1 Pressed","Key 2 Pressed","Key 3 Pressed","Key 4 Pressed","Key 5 Pressed",
    "Key 6 Pressed","Key 7 Pressed","Key 8 Pressed","Key 9 Pressed",SRC_OTHER_KEY_PRESSED,
    MODLINE_1_OUTPUT,"Modline 2 Output","Modline 3 Output","Modline 4 Output","Modline 5 Output",MODLINE_6_OUTPUT,
    "Init",
    0};

int firmware_compatable(int build_num)
{
	// VK, VK1 55
	// VK2 56
    //post("checking firmware compatable against %d\n",build_num);
	switch(build_num)
	{
            //		case 55: // VK, VK1
            //		case 56: // VK2
            //		case 57: // VK1f
            //		case 58: // VK1I
            //		case 59: // VK1L
            //		case 60: // VK1M
            //		case 61: // VK2
        case 67: // VK2
		case 68: // VK2 for firmware Program Change no running status
			return 1;
	}
	return 0;
}

void download_start(t_softstep *x)
{
	if (!firmware_compatable(x->build_num))
	{
        //post("not compatable with build num %d\n",x->build_num);
		return;
	}
	

    send_standalone_image(x);
    send_standalone_settings(x);

}

void download_file_open(t_softstep *x,char *name)
{
	const char *homeDir = getenv("HOME");
	char fname[200];
	
	snprintf(fname,sizeof(fname),"%s/%s.c",homeDir,name);
	x->fd_c = fopen(fname,"w+");
	post("download_file_open[%s] [%p]\n",fname,x->fd_c);
	snprintf(fname,sizeof(fname),"%s/%s.syx",homeDir,name);
	x->fd_syx = fopen(fname,"w+");
	post("download_file_open[%s] [%p]\n",fname,x->fd_syx);
	
}
void download_file_close(t_softstep *x)
{
	if (x->fd_c)
		fclose(x->fd_c);
	if (x->fd_syx)
		fclose(x->fd_syx);
	x->fd_c = x->fd_syx = 0;
}
void free_presets(t_softstep *x)
{
    //	return;
    
	while(x->first) {
		PRESET_LIST *next = x->first->next;
		free(x->first);
		x->first = next;
	}
}
int modline_source_reference_low(void)
{
    return get_index_str(source_list_d,MODLINE_1_OUTPUT);
}
int modline_source_reference_high(void)
{
    return get_index_str(source_list_d,MODLINE_6_OUTPUT);
}
int modline_is_output_reference(MODLINE *modline,int *index)
{
	int low = modline_source_reference_low();
	int high= modline_source_reference_high();
	if (modline->source >= low && modline->source <= high)
	{
		*index = modline->source - low;
		return 1;
	}
	return 0;
}
void modline_fix_reference(int key,PRESET_IMAGE *pi,int modnum_old,int modnum_new)
{
	int m,r;
	for (m=0;m < NUM_MODLINES_PER_KEY;m++)
	{
		if (modline_is_output_reference(&pi->modlines[key][m],&r))
		{
			if (r == modnum_old)
				pi->modlines[key][m].source = modnum_new + modline_source_reference_low();
			
		}
	}
}
int other_key_modline(MODLINE *ml)
{
    int nav_y = get_index_str(source_list_d,SRC_NAV_Y);
    //	int long_trig = get_index_str(source_list_d,SOURCE_LONG_TRIG);
    int first = get_index_str(source_list_d,SRC_ANY_KEY_VALUE);
    int last = get_index_str(source_list_d,SRC_OTHER_KEY_PRESSED);
	
	return (	ml->source == nav_y ||
            //				ml->source == long_trig ||
            (ml->source>=first && ml->source<= last));
}
int modline_reaarange(int key,PRESET_IMAGE *pi)
{
	int m,modnum,swap=false;
	MODLINE temp;
	for (m = 0;m < NUM_MODLINES_PER_KEY;m++)
	{
		if (modline_is_output_reference(&pi->modlines[key][m],&modnum))
		{
			if (modnum > m)
			{
				temp = pi->modlines[key][m];
				pi->modlines[key][m] = pi->modlines[key][modnum];
				pi->modlines[key][modnum] = temp;
				modline_fix_reference(key,pi,m,modnum);
				modline_fix_reference(key,pi,modnum,m);
				swap = true;
			}
		}
	}
	return swap;
}
void send_standalone_settings(t_softstep *x)
{
	//	post("settings.key.dead_x[%x]",x->d.settings.key[0].dead_x);
	standalone_info.u.settings_format = 0;
	
	standalone_info.type = LE_short(SA_TYPE_SETTINGS);
	
	midi_sx_header(x->device_softstep,x->device_12step,x->device_qunexus);
    //	xlate(x);
	midi_sx_packet_preamble(SX_PACKET_STANDALONE,sizeof(standalone_info));
	midi_sx_packet_data(&standalone_info,sizeof(standalone_info));
	
	midi_sx_packet_data_close(sizeof(x->settings));
	
    write_settings_to_file(&x->settings, x->fd_c);
    //write_c("standalone_settings",&x->settings,sizeof(x->settings),x);
	write_c_close(x);
	
	midi_sx_packet_data(&x->settings,sizeof(x->settings));
	
	midi_sx_packet_data_close(0);    // length 0 to indicate no more data packets
	
	midi_sx_flush();
	
	midi_sx_close();
	sx_send_list(x,SX_TYPE_NORMAL,"send_standalone_settings");
}
void send_standalone_image(t_softstep *x)
{
	PRESET_LIST *list = x->first;
	int count = 0,scene = 0;
	
	while(list){
		count++;
		list = list->next;
	}
	
	
    //post("modline length is %ld bytes\n",sizeof(MODLINE));
	//	post("send_sa_image: found %d presets",count);
	
	midi_sx_header(x->device_softstep,x->device_12step,x->device_qunexus);
	
	memset(&standalone_info.u.preset_info,0,sizeof(standalone_info.u.preset_info));
	standalone_info.type = LE_short(SA_TYPE_PRESET_IMAGE);
	standalone_info.u.preset_info.num_presets = count;
	
	midi_sx_packet_preamble(SX_PACKET_STANDALONE,sizeof(standalone_info));
	
    fprintf(x->fd_c, "#include \"scenes.h\"\n\n");
	write_c("standalone_info",&standalone_info.u.preset_info,sizeof(standalone_info.u.preset_info),x);
	
	midi_sx_packet_data(&standalone_info,sizeof(standalone_info));
	
	list = x->first;
	
	//	post("found image = %d",list!=0);
	
	write_c_title("scenes",x);
	
    int preset_index = 0;



	while(list) {

        numTabs = 1;
        char *display_name = &list->strings.data[1];
        fprintf(x->fd_c, "\n// ********************************************************************");
        fprintf(x->fd_c, "\n// \tPRESET %d: %s\n", preset_index++, display_name);
        fprintf(x->fd_c, "\n// ********************************************************************");

		//	if (list) { // limit to the first preset only
		
		int key,m,num_modlines = 0,num_modlines_exceeded = 0,other_key_count=0,pedal_count=0;
		//		int	other_key_modlines = 0;
		struct OTHER_KEY_INFO {unsigned char key,index;} PACK_INLINE;
		struct OTHER_KEY_INFO other_key_info[100],pedal_info[100];
		
		for (key=0;key<NUM_KEYS;key++)
		{
			// rearange modlines so reference are to modlines in front
			// if there is some arrangment(impossible?) so swapping is endless then stop;
			int t;
			for (t=0;t<100;t++)
				if (!modline_reaarange(key,&list->preset_image))
					break;
			if (t==100)
				post("******bizarre: can't rearange modlines for key[%d]",key);
			
			
			list->preset_image.nm.key[key].modline_count = 0;
			for (m=0;m<NUM_MODLINES_PER_KEY;m++)
			{
				if (list->enables[key][m])
				{
					if (num_modlines < NUM_MODLINES_LIMIT)
					{
						int modnum;
						// adjust the modline references if not enabled modlines in between
						if (modline_is_output_reference(&list->preset_image.modlines[key][m],&modnum))
						{
							if (list->enables[key][modnum])
							{
								int j;
								for (j=0;j<modnum;j++)
									if (!list->enables[key][j])
										list->preset_image.modlines[key][m].source--;
							} else
							{
								list->enables[key][m] = 0;// disable modline since it refers to a disabled one
								continue;
							}
						} else
							if (other_key_modline(&list->preset_image.modlines[key][m]))
							{
								other_key_info[other_key_count].key = key;
								other_key_info[other_key_count++].index = num_modlines;
							}
						
							else
                                if (list->preset_image.modlines[key][m].source == get_index_str(source_list_d,"Pedal"))
								{
                                    //post("---------------- Found a pedal on key[%d] Modline[%d]\n",key,num_modlines);
									{
										pedal_info[pedal_count].key = key;
										pedal_info[pedal_count++].index = num_modlines;
									}
								}
						
						list->preset_image.nm.key[key].modline_count++;
						num_modlines++;
					} else
						num_modlines_exceeded++;
				}
			}
		}
		
		//		post("num_modlines [%d] other_key[%d][%d]",num_modlines,other_key_modlines,other_key_modlines * sizeof(struct OTHER_KEY_INFO));
		
		
		//		{
		//			char *ptr = (char *) &other_key_info;
		//			int i;
		//			for (i=0;i<20;i++)
		//				post("%d %x",i,ptr[i]);
		//		}
		
		
		if (num_modlines_exceeded)
		{
			t_atom limits[2];
			limits[0].a_type = A_LONG;	limits[0].a_w.w_long = scene;
			limits[1].a_type = A_LONG;	limits[1].a_w.w_long = num_modlines_exceeded;
			outlet_anything(x->outlet_msg, gensym("modlineLimitExceeded"),2, limits);
		}
		
#ifdef FAKE_DATA
		midi_sx_packet_data_close(sizeof(fake_data));
		
		int f;
		for (f=0;f<sizeof(fake_data);f++) {
			fake_data[f] = f & 0xff;
		}
		midi_sx_packet_data(fake_data,sizeof(fake_data));
#else
		{
			int preset_size = sizeof(NM) + num_modlines * sizeof(MODLINE);
			
			short other_key_index,pedal_index,string_index,end_index;
			other_key_index = preset_size;
			pedal_index = other_key_index + other_key_count * sizeof(struct OTHER_KEY_INFO);
			string_index = pedal_index + pedal_count * sizeof(struct OTHER_KEY_INFO);
			end_index = string_index + list->strings.size;
			
            //			post("preset_size[%d]",preset_size);
            //			post("pedal_index[%d]",pedal_index);
            //			post("string_index[%d]",string_index);
            //			post("end_index[%d]",end_index);
			
			list->preset_image.nm.other_key_index = LE_short(other_key_index);
			list->preset_image.nm.pedal_index = LE_short(pedal_index);
			list->preset_image.nm.string_index = LE_short(string_index);
			list->preset_image.nm.end_index = LE_short(end_index);
			
			midi_sx_packet_data_close(end_index);
			
            numTabs = 2;
            fprintf(x->fd_c, "\n// \t\tNOT MODLINE:\n");

            write_nm_to_file(&list->preset_image.nm, x);
            //write_c_data(&list->preset_image.nm,sizeof(NM),x);
			
			midi_sx_packet_data(&list->preset_image.nm,sizeof(NM));
			midi_sx_data_addr = 0;
			
			for (key=0;key<NUM_KEYS;key++){
                numTabs = 3;
                fprintf(x->fd_c, "\n// \t\t\tKEY: %d\n", key);

				for (m=0;m<NUM_MODLINES_PER_KEY;m++)
				{
                    //printf("key[%d][%d] source[%d]\n",key,m,list->preset_image.modlines[key][m].source);
                    fflush(stdout);
                    if (list->enables[key][m])
					{
                    //post("enabled\n");
						if (num_modlines)
						{
                            numTabs = 4;
                            fprintf(x->fd_c, "\n// \t\t\t\tMODLINE: %d\n", m);

                            write_modline_to_file(&list->preset_image.modlines[key][m], x);
                            //write_c_data(&list->preset_image.modlines[key][m],sizeof(MODLINE),x);
							midi_sx_data_crc(&list->preset_image.modlines[key][m],sizeof(MODLINE));
							num_modlines--;
						}
					}
				}
			}
            //					post("other_key_info");
            numTabs = 2;
            fprintf(x->fd_c, "\n// \t\tOTHER KEY INFO (triggers, key/modline_index pairs) - other_key_count: %d\n", other_key_count);

			write_c_data(&other_key_info,other_key_count * sizeof(struct OTHER_KEY_INFO),x);
			midi_sx_data_crc(&other_key_info,other_key_count * sizeof(struct OTHER_KEY_INFO));
            //					post("pedal_info");

            fprintf(x->fd_c, "\n// \t\tPEDAL INFO (expression pedal modlines, key/modline_index pairs) - pedal_count: %d\n", pedal_count);

			write_c_data(&pedal_info,pedal_count * sizeof(struct OTHER_KEY_INFO),x);
			midi_sx_data_crc(&pedal_info,pedal_count * sizeof(struct OTHER_KEY_INFO));
            //					post("strings");

            fprintf(x->fd_c, "\n// \t\tSTRINGS:\n");

            write_strings_to_file(list->strings.data, list->strings.size, x);
            //write_c_data(list->strings.data,list->strings.size,x);
			midi_sx_data_crc(list->strings.data,list->strings.size);
		}
#endif
		
		list = list->next;
		scene++;
	}
	
	write_c_end(x);
	
	midi_sx_packet_data_close(0);    // length 0 to indicate no more data packets
	
	midi_sx_flush();
	
	midi_sx_close();
	
	sx_send_list(x,SX_TYPE_DOWNLOAD,"send_standalone_image");
	
	free_presets(x);
	
}
