// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <stdio.h>
#include "device_includes.h"
#include "syxrx.h"
#include "utils.h"
#include "string.h"
#include "syxformats.h"
#include "download.h"
#include "attribute.h"

typedef struct {int valid,buildNum,error;char version[30];} FW_STATUS;

unsigned char fw_query_syx_softstep[] = {
	0xF0,0x00,0x1B,0x48,0x7A,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x04,0x40,
	0x00,0x30,0xF7
};

unsigned char fw_query_syx_12step[] = {
    0xF0,0x00,0x1b,0x48,0x7A,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x04,0x40,
    0x00,0x30,0xF7
};
unsigned char fw_query_syx_qunexus[] = {
    0xF0,0x00,0x1b,0x48,0x7A,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x04,0x40,
    0x00,0x30,0xF7
};

struct {int valid,buildnum,error;char version[20];} fw_status = {0,0,0,{0}};

FW_STATUS fw_status_embedded = {0,0,0,{0}};
FW_STATUS fw_status_current = {0,0,0,{0}};
void fw_header_close(unsigned char success) {
    //	post("fw_header_close[%d]",success);
	if (success)
	{
		sysex_rx_completion_type = BLOCK_TYPE_FW_HEADER;
		fw_status.buildnum = LE_short(sysex_data.u.fw_header.fixed.buildnum);
		
		if (fw_status.buildnum == 4)	// version G
		{
			struct FW_HEADER_G *hg = (struct FW_HEADER_G *) &sysex_data.u.fw_header;
			
			snprintf(fw_status.version,sizeof(fw_status.version),"VG");
			
			if (hg->versionString[2] == 'B')
				fw_status.error = 1;
			else
				if (hg->versionString[3] == 'B')
					fw_status.error = 2;
                else
                    fw_status.error = 0;
		} else
		{
            // EB TODO: test this on MacOS, might need to use compiler condition for strncpy with 3 arguments
            strncpy(fw_status.version,sysex_data.u.fw_header.versionString,sizeof(fw_status.version)-1);
            //strncpy_s(fw_status.version, sizeof(fw_status.version)-1, sysex_data.u.fw_header.versionString, sizeof(fw_status.version)-1);

			if (sysex_data.u.fw_header.fixed.fw_status.part[0] == 'B')
				fw_status.error = 1;
			else
				if (sysex_data.u.fw_header.fixed.fw_status.part[1] == 'B')
					fw_status.error = 2;
				else
					if (sysex_data.u.fw_header.fixed.fw_status.part[2] == 'B')
						fw_status.error = 3;
					else
						if (sysex_data.u.fw_header.fixed.fw_status.part[3] == 'B')
							fw_status.error = 4;
						else
							fw_status.error = 0;
            
            //			post("found fw_header: build[%d] version[%s] fw_status[%d %d %d %d]",
            //				LE_short(fw_header.fixed.buildnum),fw_header.versionString,
            //				 fw_header.fixed.fw_status.part[0],
            //				 fw_header.fixed.fw_status.part[1],
            //				 fw_header.fixed.fw_status.part[2],
            //				 fw_header.fixed.fw_status.part[3]
            //				 );
		}
	}
}

int fw_status_get(int *buildNum,int *error,char *version)
{
	if (sysex_rx_completion_type)
	{
		*buildNum = fw_status.buildnum;
		*error = fw_status.error;
        strncpy(version, fw_status.version,sizeof(fw_status.version)-1);
        // EB TODO: potential need for compiler conditional MACOS
        //strncpy_s(version, sizeof(fw_status.version)-1, fw_status.version,sizeof(fw_status.version)-1);
	}
	
	return (sysex_rx_completion_type);
}

unsigned char *get_sysex_debug(void)
{
    //	char i,c;
	
    //	post("sysex data %p",&sysex_data);
	
    //	for (i=0;i<10;i++)
    //	{
    //		c = sysex_data.u.debug_msg[i];
    //		post("gsd %x %x",c,packet_data_info.header[i]);
    //	}
	
	return sysex_data.u.debug_msg;
}

void sysex_completion_flag_clear(void){
	sysex_rx_completion_type = 0;
}

void send_debug_msg(t_softstep *x)
{
    Q_UNUSED(x);

    sysex_completion_flag_clear();
	LOG_DBG("hw debug: %s", get_sysex_debug());
}

int fw_process_midi(int midiVal,int *buildNum,int *error,char *version)
{
    Q_UNUSED(midiVal);

    if ((fw_status_current.valid = fw_status_get(
                                                &fw_status_current.buildNum,
                                                &fw_status_current.error,
                                                fw_status_current.version)))
	{
        //		post("connected buildNum[%d] error[%d], version[%s]",
        //			 fw_status_current.buildNum,
        //			 fw_status_current.error,
        //			 fw_status_current.version);
		sysex_completion_flag_clear();
		*buildNum = fw_status_current.buildNum;
		*error = fw_status_current.error;
        strncpy(version,fw_status_current.version,sizeof(fw_status_current.version)-1);
        // EB TODO - test on MacOS, might need compilier conditional
        //strncpy_s(version, sizeof(fw_status.version)-1, fw_status_current.version,sizeof(fw_status_current.version)-1);
		return 1;
	}
	return 0;
}

void send_fw_status_msg(t_softstep *x,char *type,int buildNum,int error,char *version,int compatable)
{
	
	t_atom vb[5];
    
	LOG_INFO("%s version[%s] build[%d] error[%d] compatable[%d]", type, version, buildNum, error, compatable);
    
    
	vb[0].a_type = A_SYM;
	vb[0].a_w.w_sym = gensym(type);
	vb[1].a_type = A_SYM;
	vb[1].a_w.w_sym = gensym(version);
	vb[2].a_type = A_LONG;
	vb[2].a_w.w_long = buildNum;
	vb[3].a_type = A_LONG;
	vb[3].a_w.w_long = error;
	vb[4].a_type = A_LONG;
	vb[4].a_w.w_long = compatable;
	
	outlet_anything(x->outlet_msg, gensym("fw"), 5, vb);
}

extern int fw_debug;
int fw_embedded_status(int *buildNum,int *error,char **version)
{
	if (fw_status_embedded.valid)
	{
		*buildNum = fw_status_embedded.buildNum;
		*error = fw_status_embedded.error;
		*version = fw_status_embedded.version;
		return true;
	} else
		return false;
}

void send_fw_query(t_softstep *x)
{
    //	int i;
	int buildNum,error;
	char *version;
	
	LOG_DBG("send_fw_query");
	
	
	if (fw_embedded_status(&buildNum,&error, &version))
		send_fw_status_msg(x,"embedded",buildNum,error,version,firmware_compatable(buildNum));
	
	sysex_rx_completion_type = 0; // kludgy
    
    if (x->device_softstep)
        sendSysex(fw_query_syx_softstep,sizeof(fw_query_syx_softstep), -1);
    if (x->device_12step)
        sendSysex(fw_query_syx_12step,sizeof(fw_query_syx_12step), -1);
    if (x->device_qunexus)
        sendSysex(fw_query_syx_qunexus,sizeof(fw_query_syx_qunexus), -1);
	
	//	for (i=0;i<sizeof(fw_query_syx);i++)
	//		outlet_int(x->outlet,fw_query_syx[i]);
}

void softstep_midi_process(t_softstep *x, VERSION *version,long n)
{	
    //			post("sx[%02x]",n);
    //			if (n==MIDI_SX_STOP)
    //				post("end of sysex");
	
    //	post("softstep_midi_process[%02x]",n);
	
	sx_process(x,(unsigned char) n);
	
	switch(sysex_rx_completion_type)
	{
		case BLOCK_TYPE_FW_HEADER:
            //						post("BLOCK_TYPE_FW_HEADER");
			if (fw_process_midi((int)n,&version->buildnum,&version->firmware_status,version->version))
			{
                //				clock_unset(x->d.fw_query_timer);
                				
				//post("SoftStep: found build[%d] error[%d] version[%s]",buildNum,error,version);
			}
			break;
		case BLOCK_TYPE_DEBUG_MESSAGE:
			send_debug_msg(x);
			
			break;
	}
	sysex_completion_flag_clear();
}
