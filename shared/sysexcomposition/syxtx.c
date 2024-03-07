// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "syxformats.h"
#include "midi_ss.h"
#include "utils.h"
#include "attribute.h"



int midi_hi_bits,midi_hi_count,message_len;

unsigned char message[MAX_SYSEX_SIZE];

void midi_chunk_init(void) {
	midi_hi_bits = midi_hi_count = 0;
}

void midi_buffer_put_core(unsigned char val){
	message[message_len] = val;
	if (message_len < (MAX_SYSEX_SIZE-1))
		message_len++;
}


void midi_buffer_put_nulls(int count) {
	while(count--)
		midi_buffer_put_core(0);
}

void midi_sx_header(int device_softstep,int device_12step,int device_qunexus) {
	message_len = 0;
	midi_buffer_put_core(MIDI_SX_START);
	midi_buffer_put_core(0x00);
    if (device_softstep)
    {
        midi_buffer_put_core(0x01);
        midi_buffer_put_core(0x5F);
        midi_buffer_put_core(0x7a);
        midi_buffer_put_core(1); // product id
    }
    if (device_12step)
    {
        midi_buffer_put_core(0x01);
        midi_buffer_put_core(0x5F);
        midi_buffer_put_core(0x7a);
        midi_buffer_put_core(20); // product id
    }
    if (device_qunexus)
    {
        midi_buffer_put_core(0x01);
        midi_buffer_put_core(0x5F);
        midi_buffer_put_core(0x7a);
        midi_buffer_put_core(25); // product id
    }
	midi_buffer_put_core(0x00); // format
	midi_buffer_put_nulls(10);
}
void midi_sx_encode_char(unsigned char val) {
	midi_hi_bits |= (val & 0x80);
	midi_hi_bits >>= 1;
	midi_buffer_put_core(val & 0x7f);
    //	post("mbpc %02x",val & 0x7f);
	if (++midi_hi_count == SX_ENCODE_LEN) {
		midi_hi_count = 0;
		midi_buffer_put_core(midi_hi_bits);
        //	post("mbpc %02x (hi_bits)",midi_hi_bits);
	}
}
void midi_sx_encode_int(unsigned short val) {
	midi_sx_encode_char(val>>8);
    midi_sx_encode_char((unsigned char)val);
}

void midi_sx_encode_crc_char(unsigned char val) {
	crc_byte(val);
	midi_sx_encode_char(val);
}
void midi_sx_encode_crc_int(unsigned short val) {
	midi_sx_encode_crc_char(val>>8);
    midi_sx_encode_crc_char((unsigned char)val);
}
void midi_sx_flush(void) {
	while(midi_hi_count)
		midi_sx_encode_char(0);
}

int midi_sx_data_addr = 0;
void midi_sx_data_crc(void *data,unsigned short length) {
	int i;
    //	post("midi_sx_data_crc: length[%d] data[%02x,%02x,%02x,%02x,%02x,%02x]",length,
    //		 length > 0 ? ((unsigned char *) data)[0]:0xff,
    //		 length > 1 ? ((unsigned char *) data)[1]:0xff,
    //		 length > 2 ? ((unsigned char *) data)[2]:0xff,
    //		 length > 3 ? ((unsigned char *) data)[3]:0xff,
    //		 length > 4 ? ((unsigned char *) data)[4]:0xff,
    //		 length > 5 ? ((unsigned char *) data)[5]:0xff
    //		 );
    //	post("midi_sx_data_crc length[%d]",length);
    //	post("midi_sx_data_addr[%d]",midi_sx_data_addr);
	for(i=0;i<length;i++)
	{
        //		post("%3d: %02x %c",midi_sx_data_addr,((unsigned char *) data)[i],isprint(((unsigned char *) data)[i]) ? ((unsigned char *) data)[i] : '.');
		midi_sx_data_addr++;
		midi_sx_encode_crc_char( ((unsigned char *) data)[i]);
        //		post("0x%04x, // %4d %02x",crc,i,((unsigned char *) data)[i]);
	}
}
void midi_sx_packet_preamble(unsigned short packet_type,unsigned short length) {
	crc = 0xffff;
    
	midi_buffer_put_core(0x01);
	midi_chunk_init();
	midi_sx_encode_crc_int(packet_type);
	midi_sx_encode_crc_int(length + TAIL_LEN);
	midi_sx_encode_int(crc);
    
}
void midi_sx_packet_data(void *source,unsigned short length) {
	crc = 0xffff;
	midi_sx_data_crc(source,length);
}

void midi_sx_packet_data_close(unsigned short length) {
	midi_sx_encode_crc_int(length ? length + TAIL_LEN : 0);
	midi_sx_encode_int(crc);
}
void midi_sx_packet(unsigned short packet_type,void *source,unsigned short length) {
	midi_sx_packet_preamble(packet_type,length);
	midi_sx_packet_data(source,length);
	midi_sx_packet_data_close(0);    // length 0 to indicate no more data packets
	midi_sx_flush();
}
void midi_sx_close(void) {
	midi_buffer_put_core(MIDI_SX_STOP);
}

long midi_sx_length(void) {
	return message_len;
}

long midi_sx_byte(int index) {
	return message[index];
}
unsigned char *midi_sx_buffer(void) {
	return message;
}


