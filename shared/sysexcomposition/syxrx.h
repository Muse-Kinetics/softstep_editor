// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
//
//  syxrx.h
//  SoftstepSyxDemo
//
//

#ifndef SoftstepSyxDemo_syxrx_h
#define SoftstepSyxDemo_syxrx_h

extern int sysex_rx_completion_type;

enum {
	BLOCK_TYPE_REQUEST_FW_VERSION,
	BLOCK_TYPE_REQUEST_FW,
	BLOCK_TYPE_ALPHANUMERIC,
	BLOCK_TYPE_LED,
	BLOCK_TYPE_EL,
	BLOCK_TYPE_FW_HEADER,
	BLOCK_TYPE_FW_BLOCK_HEADER,
	BLOCK_TYPE_FW_DATA,
	BLOCK_TYPE_PAD,
	BLOCK_TYPE_STANDALONE,
	BLOCK_TYPE_SEGMENT_MASK,
	BLOCK_TYPE_PEDAL,
	BLOCK_TYPE_DEBUG_MESSAGE,
	PACKET_TYPE_COUNT
};
enum {CORE_SX_START,CORE_SX_HEADER,CORE_SX_PACKET_START_SEARCH,CORE_SX_PACKET_PREAMBLE,CORE_SX_PACKET_DATA};
typedef union {
	unsigned char raw[1];
	struct {unsigned short length,crc;} PACK_INLINE fmt;
} PACK_INLINE TAIL;


typedef struct {unsigned short type;TAIL tail;} PACK_INLINE PACKET_PREAMBLE;
union {
	PACKET_PREAMBLE s;
	unsigned char raw[sizeof(PACKET_PREAMBLE)];
} PACK_INLINE packet_preamble;

union FW_STATUS {unsigned char part[4]; unsigned int whole;} PACK_INLINE;


struct FW_BLOCK_HEADER {unsigned char block_num;unsigned short length;} PACK_INLINE;
struct FW_HEADER {
	struct {unsigned char bank,block_num_last;unsigned short buildnum,length,crc;union FW_STATUS fw_status;} PACK_INLINE fixed;
	char versionString[20];
};
struct SYSEX_DATA {
	union {
		struct FW_HEADER fw_header;
		char debug_msg[200];
	} u;
};


typedef struct {unsigned char manufacturer_id1,manufacturer_id2,manufacturer_id3,manufacturer_id4,product,format;} SYSEX_STANDARD;

typedef struct {
	void *data_header_ptr;
	unsigned char data_header_len,(*open)(void);
	void (*datum)(unsigned char schar);
	void (*close)(unsigned char success);} SYSEX_HANDLER;


typedef struct {unsigned char index;
	unsigned char *header;
	unsigned char packet_count;
    //	MIDI_SOURCE xdata *source;
	//	struct {void *dest;unsigned int count,index;} datums;
	const SYSEX_HANDLER *sysex_handler;
	TAIL tail;
} PACKET_DATA_INFO;
typedef union {
	struct FW_BLOCK_HEADER fw_block_header;
    //	struct PAD_PACKET_FORM pad_packet;
} PACKET_DATA;

struct FW_HEADER_G {
	struct {unsigned char bank,block_num_last;unsigned short buildnum,length,crc;} PACK_INLINE fixed;
	char versionString[20];
} PACK_INLINE;

extern struct SYSEX_DATA sysex_data;
void sx_process(t_softstep *x,unsigned char sx_char);

void null_datum(unsigned char val);
unsigned char null_open(void);
void null_close(unsigned char success);
void fw_header_close(unsigned char success);
void debug_msg_close(unsigned char success);
#endif
