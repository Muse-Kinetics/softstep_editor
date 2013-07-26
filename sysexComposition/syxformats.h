// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef SoftstepSyxDemo_syxformats_h
#define SoftstepSyxDemo_syxformats_h

#include "softstep.h"


#define	LE_short(val) (((val & 0xFF) << 8) + ( ((val) >> 8) & 0xFF))
//#define	LE_int(val)  (LE_short(((int)val)>>16) | LE_short((int)val & 0xffff))
#define	LE_int(val)  ( LE_short((int) (val) & 0xffff)<<16 | LE_short((int)(val)>>16) )

enum {SX_PACKET_DISPLAY=2,SX_PACKET_LED,SX_PACKET_EL,SX_PACKET_PAD=8,SX_PACKET_STANDALONE,SX_PACKET_SEGMENT,SX_PACKET_PEDAL};
#define	MAX_SYSEX_SIZE	50000
#define	TAIL_LEN	4
#define	SX_PACKET_START	0x01
#define SX_ENCODE_LEN	0x07

enum {LED_OFF,LED_ON,LED_SLOW,LED_FAST,LED_BLINK};
enum {LED_GREEN,LED_RED,LED_BOTH};
enum {PAD_QUERY,PAD_LIMIT_LOW};
enum {PEDAL_ONOFF,PEDAL_FILTER_ONOFF,PEDAL_CALIBRATION_EDGES,PEDAL_FILTER_HYS_LENGTH};
enum {SA_TYPE_PRESET_IMAGE,SA_TYPE_PRESET_SET,SA_TYPE_SETTINGS,SA_TYPE_STANDALONE_ONOFF,SA_TYPE_TETHER_ONOFF,SA_TYPE_PIN,SA_TYPE_PORT,SA_TYPE_SCAN,SA_TYPE_NAVTETHER_ONOFF};

#ifdef _WIN32 || _WIN64
#define _WINDOWS
#endif

#ifdef	_WINDOWS
#pragma PACK(1)
#endif

typedef struct {
	unsigned short type;
	union {
		struct {unsigned char format,reserved[2],num_presets;} PACK_INLINE preset_info;
		struct {unsigned char read,num,val;} PACK_INLINE pin_info;
		struct {unsigned char read,num,io,analog,write;} PACK_INLINE port_info;
		unsigned char scan_onoff;
		unsigned char preset_num;
		struct {unsigned char state,save;} onoff;
		unsigned char settings_format;
	} u;
} PACK_INLINE STANDALONE_INFO;

typedef struct {
	unsigned char type;
	union {
		unsigned char pad;
		unsigned char limit;
	} u;
	
} PACK_INLINE PAD_INFO;

typedef struct {unsigned char hysteresis,length;} PACK_INLINE HL;

typedef struct {
	unsigned char type;
	union {
		unsigned char onoff;
		PEDAL_CALIBRATION pedal_calibration;
		HL hl;
	} u;
} PACK_INLINE PEDAL_INFO;


extern STANDALONE_INFO standalone_info;
extern PAD_INFO pad_info;
extern PEDAL_INFO pedal_info;

#endif
