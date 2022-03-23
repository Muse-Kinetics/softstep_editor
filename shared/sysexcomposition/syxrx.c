// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <stdlib.h>
#include <string.h>

#include <qglobal.h>

#include "softstep.h"
#include "syxformats.h"
#include "midi.h"
#include "utils.h"
#include "syxrx.h"
#include "attribute.h"


struct SYSEX_DATA sysex_data;

PACKET_DATA_INFO packet_data_info;
PACKET_DATA pd;

const SYSEX_HANDLER sysex_handlers[] = {
    {0,0,0,0,NULL},// 0 request_fw_version,
    {0,0,0,0,NULL},// 1 request_fw_update,
    {0,0,0,0,NULL},// 2 digit display
    {0,0,0,0,NULL},// 3 leds
    {0,0,0,0,NULL},// 4 EL
    {&sysex_data,sizeof(struct SYSEX_DATA),null_open,null_datum,fw_header_close},// 5
    {0,0,null_open,null_datum,null_close},// 6 EL
    {0,0,null_open,null_datum,null_close},// 7 EL
    {0,0,0,0,NULL},// 8 EL
    {0,0,0,0,NULL},// 9 EL
    {0,0,0,0,NULL},// 10 EL
    {0,0,0,0,NULL},// 11 EL
    {&sysex_data,sizeof(struct SYSEX_DATA),null_open,null_datum,debug_msg_close},// 12
    {&sysex_data,sizeof(struct SYSEX_DATA),null_open,null_datum,misc_info_close},// 13  ****** new entry *********
    
};

unsigned int packet_crc;
unsigned char sx_packet_opened;



union {
	SYSEX_STANDARD standard_header;
	unsigned char raw[sizeof(SYSEX_STANDARD)];
} core_sx;


unsigned long core_sx_count;
int sysex_rx_completion_type = 0;

unsigned char core_sx_state;
struct {unsigned char index_in,index_out,buf[SX_ENCODE_LEN+1];} core_sx_decode;

void misc_info_close(unsigned char success)
{
    if (success)
    {
        switch (sysex_data.u.misc_info.hardware_type)
        {
            case 0:     // softstep 1
            post("................... ss 1\n");
                break;
            case 1:     // softstep 2
            post("................... ss 2\n");
                break;
        }

    }
    else
    {
        post("success %i", success);
    }

    fflush(stdout);

}

void debug_msg_close(unsigned char success) {
    Q_UNUSED(success);

    //	int i;
    //	for(i=0;i<10;i++)
    //		post("debug_msg: [%p] [%02x] [%c]",&sysex_data,sysex_data.u.debug_msg[i],sysex_data.u.debug_msg[i]);
	sysex_rx_completion_type = BLOCK_TYPE_DEBUG_MESSAGE;
}
void midi_sx_decode_put(unsigned char val) {
	core_sx_decode.buf[core_sx_decode.index_in++] = val;
}
void sx_decode_init(void) {
	core_sx_decode.index_in = core_sx_decode.index_out = 0;
}
unsigned char midi_sx_decode_get(unsigned char *val) {
	if (core_sx_decode.index_in==SX_ENCODE_LEN+1) {
		*val = core_sx_decode.buf[core_sx_decode.index_out++];
		if (core_sx_decode.buf[SX_ENCODE_LEN] & 1)
			*val |= 0x80;
		core_sx_decode.buf[SX_ENCODE_LEN] >>=1;
		if (core_sx_decode.index_out==SX_ENCODE_LEN) {
			sx_decode_init();
		}
		return 1;
	}
	
	return 0;
}
void null_datum(unsigned char val) {
    Q_UNUSED(val);
}
unsigned char null_open(void) {
	return 1;
}
void null_close(unsigned char success) {
    Q_UNUSED(success);
}
void sx_init(void) {
	core_sx_state = CORE_SX_START;
}
void core_sx_init(void) {
	core_sx_count = 0;// not one of ours or we would have processed it by now
	core_sx_state = CORE_SX_HEADER;
}
void core_sx_packet_init(void) {
	sx_decode_init();
	core_sx_count = 0;
	core_sx_state = CORE_SX_PACKET_PREAMBLE;
	crc_init();
}
void core_sx_set_packet_search(void) {
	core_sx_state = CORE_SX_PACKET_START_SEARCH;
    //	post("CORE_SX_PACKET_START_SEARCH");
}
void core_sx_set_ignore(void) {
	sx_decode_init();
	core_sx_state = CORE_SX_HEADER;
	core_sx_count=sizeof(SYSEX_STANDARD)+1;
}
void packet_data_handler(const SYSEX_HANDLER *handler){
	packet_data_info.sysex_handler = handler;
}
void packet_data_init(TAIL *tail) {
	core_sx_state = CORE_SX_PACKET_DATA;
	packet_data_info.index = 0;
    
	packet_preamble.s.tail.fmt.length = LE_short(tail->fmt.length);
    //	post("pdi expecting %d chars",packet_preamble.s.tail.fmt.length);
	crc_init();
	
	packet_data_info.header = packet_data_info.sysex_handler->data_header_ptr;
	
    //	post("pdi header address %p",packet_data_info.header);
    
	packet_data_info.packet_count = 0;
	if (packet_data_info.sysex_handler->data_header_len) {
		sx_packet_opened = 1;// open to read in data header before calling .open()
	}
	else
		if (packet_data_info.sysex_handler->open)
			sx_packet_opened = (*packet_data_info.sysex_handler->open)();
		else
			(*packet_data_info.sysex_handler->close)(1);
	
	if (!packet_preamble.s.tail.fmt.length)
		core_sx_set_packet_search();
}
void packet_data_process(void) {
	unsigned char sx_char;
	
	while(midi_sx_decode_get(&sx_char)) {
        //		post("pdp[%d][%02x]",packet_preamble.s.tail.fmt.length,sx_char);
        //		continue;
		
		if (packet_preamble.s.tail.fmt.length-- > sizeof(short))
			crc_byte(sx_char);
		
		if (packet_preamble.s.tail.fmt.length < sizeof(TAIL))
		{
			packet_data_info.tail.raw[sizeof(TAIL)-1-packet_preamble.s.tail.fmt.length] = sx_char;
			if (!packet_preamble.s.tail.fmt.length)
			{
                //				post("pdp crc[%04x] crc[%04x]",crc,LE_short(packet_data_info.tail.fmt.crc));
                
				if (crc==LE_short(packet_data_info.tail.fmt.crc))
				{
					if (packet_data_info.sysex_handler->close)
					{
                        //					post("calling close");
						(*packet_data_info.sysex_handler->close)(1);//FUNCTIONCALL
					}
					
					if (LE_short(packet_data_info.tail.fmt.length))
						packet_data_init(&packet_data_info.tail);
					else
					{
						core_sx_set_packet_search();
						return;
					}
				} else
				{
					core_sx_set_ignore();
					if (packet_data_info.sysex_handler->close)
                        (*packet_data_info.sysex_handler->close)(1);//FUNCTIONCALL -- force succes of 1 on close, fixes found version of 0, need better solution.
				}
				packet_data_info.packet_count++;
			}
		} else{
			if (packet_data_info.sysex_handler->data_header_len)
			{
                //post("pdi[%d][%d][%p] [%x]",packet_data_info.index,packet_preamble.s.tail.fmt.length,packet_data_info.header,sx_char);
				packet_data_info.header[packet_data_info.index++] = sx_char;
                //				post("pdi after[%x]",packet_data_info.header[packet_data_info.index-1]);
				
                //				if (packet_data_info.index == sysex_handlers[LE_short(packet_preamble.s.type)].data_header_len)
				if (packet_data_info.index == packet_preamble.s.tail.fmt.length)
				{
					if (packet_data_info.sysex_handler->open)
						sx_packet_opened = (*packet_data_info.sysex_handler->open)();
				}
			}
			else
				if (packet_data_info.sysex_handler->datum)
					(*packet_data_info.sysex_handler->datum)(sx_char);//FUNCTIONCALL
		}
	}
}
//int debug_sx_process_count = 0;
void sx_process(t_softstep *x,unsigned char sx_char) {
	
    //if (debug_sx_process_count>260)
    //	return;
	
    //	post("%5d: sx_process[%x] state[%x]",debug_sx_process_count++,sx_char,core_sx_state);
	
    
    //	post("%02x: %d",sx_char,core_sx_state);
	
    if (sx_char & 0x80)
        sx_init();
	
    if (sx_char==MIDI_SX_START) {
        //			second_stage = 0;
        core_sx_init();
    } else
        if (sx_char==MIDI_SX_STOP) {
            sx_init();
            return;
        }
        else {
            switch (core_sx_state) {
                case CORE_SX_PACKET_START_SEARCH:
                    if (sx_char==SX_PACKET_START) {
                        core_sx_packet_init();
                        //							post("CORE_SX_PACKET_PREAMBLE");
                        
                    }
                    break;
                case CORE_SX_PACKET_PREAMBLE:
                    //EA = 0;
                    //						post("crc[%04x]",crc);
                    midi_sx_decode_put(sx_char);
                    while(midi_sx_decode_get(&sx_char)) {
                        if (core_sx_count<4)
                            crc_byte(sx_char);
                        //							post("core_sx_count[%d] sx_char[%02x] crc[%04x]",core_sx_count,sx_char,crc);
                        packet_preamble.raw[core_sx_count++] = sx_char;
                        if (core_sx_count==sizeof(PACKET_PREAMBLE)) {
                            //								post("rx packet");
                            if (LE_short(crc)==packet_preamble.s.tail.fmt.crc) {
                                //									post("good crc: type[%d] limit[%d]",LE_short(packet_preamble.s.type),PACKET_TYPE_COUNT);
                                if (LE_short(packet_preamble.s.type)<PACKET_TYPE_COUNT) {
                                    //										packet_data_info.source = source;
                                    //		post("packet_data_handler %d",LE_short(packet_preamble.s.type));
                                    //										if (debug_sx_process_count>252)
                                    //											return;
                                    
                                    packet_data_handler(&sysex_handlers[LE_short(packet_preamble.s.type)]);
                                    packet_data_init(&packet_preamble.s.tail);
                                    
                                    
                                    if (core_sx_state == CORE_SX_PACKET_DATA)
                                        packet_data_process();
                                    
                                }
                                else
                                    core_sx_set_ignore();
                                //lcd_putchar(packet_preamble.s.num+'0');
                            } else {
                                post("bad crc");
                                // set state so rest of sx will not be processed
                                core_sx_set_ignore();
                            }
                            break;
                        }
                    }
                    //EA = 1;
                    break;
                case CORE_SX_PACKET_DATA:
                    midi_sx_decode_put(sx_char);
                    packet_data_process();
                    break;
                case CORE_SX_HEADER:
                    if (core_sx_count<=sizeof(SYSEX_STANDARD)) {
                        core_sx.raw[core_sx_count] = sx_char;
                        if (++core_sx_count==sizeof(SYSEX_STANDARD)) {
                            //								post("CORE_SX_HEADER received");
                            
                            if (core_sx.standard_header.manufacturer_id1==0x00 &&
                                
                                ((x->device_softstep &&
                                  core_sx.standard_header.manufacturer_id2==0x1b  &&
                                  core_sx.standard_header.manufacturer_id3==0x48  &&
                                  core_sx.standard_header.product == 1)  ||
                                 
                                 (!x->device_softstep &&
                                  core_sx.standard_header.manufacturer_id2==0x01 &&
                                  core_sx.standard_header.manufacturer_id3==0x5F &&
                                  core_sx.standard_header.product == 20 )) &&
                                
                                core_sx.standard_header.manufacturer_id4==0x7A &&
                                core_sx.standard_header.format == 0
                                ) {
                                core_sx_set_packet_search();
                            }
                        }
                    }
                    break;
            }
        }
    
}


