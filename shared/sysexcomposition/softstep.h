// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef SoftstepSyxDemo_softstep_h
#define SoftstepSyxDemo_softstep_h

#include "stdio.h"

#ifndef Q_UNUSED
#define Q_UNUSED(x) (void)x;
#endif

#if defined(_WIN32) || defined(WIN64)
#define _WINDOWS
#endif

#define	LIMIT_255(val) (val>255?255:val)
#ifdef	_WINDOWS
#include <windows.h>
#define	PACK_INLINE
#define	stricmp	_stricmp
#define CASE_CMP(v1,v2) stricmp(v1,v2)
#define	snprintf	sprintf_s
#define vsnprintf	vsprintf_s
#pragma pack(1)
#else
#define	PACK_INLINE __attribute__ ((packed))
#define CASE_CMP(v1,v2) strcasecmp(v1,v2)
#endif


#define	NUM_KEYS	11
#define	NUM_MODLINES_PER_KEY	6
#define	NUM_TOTAL_MODLINES	(NUM_KEYS*NUM_MODLINES_PER_KEY)
#define	NUM_MODLINES_LIMIT		50

#define	SEND_SX_DIRECT		// send directly to device instead of outlet
#define	LED_USE_CONTROLLER  // use controllers instead of sysex for led messages
#define	DISPLAY_USE_CONTROLLER

#ifdef	_WINDOWS
//#pragma pack(8) // default for x86
#endif
#ifdef _WINDOWS
#define	STRNCPY(dest,source,len) strcpy_s(dest,len,source);
#else
#define STRNCPY(dest,source,len)	strncpy(dest,source,len);
#endif

#define CSTR(val) CFStringGetCStringPtr(val,CFStringGetSystemEncoding())
typedef unsigned char Byte;

#ifndef false
#define false   0
#endif

#define FALSE   0

#ifndef true
#define true    1
#endif

#define TRUE    1


typedef struct {int buildnum,firmware_status;char version[50];} VERSION;

#ifdef VARIABLE_FIXED
typedef struct FIXED_PT { unsigned short val; unsigned char point;}PACK_INLINE FIXED_PT;
#else
typedef union FIXED_PT {
	int whole;
	struct { unsigned short upper; unsigned short lower;} PACK_INLINE u;
} PACK_INLINE FIXED_PT;
#endif
typedef struct {unsigned char heel,toe;unsigned short mpx;} PACK_INLINE PEDAL_CALIBRATION;
typedef struct {unsigned char hysteresis,length;} PACK_INLINE PEDAL_FILTER;
typedef struct {unsigned char standalone,tether;} PACK_INLINE CONNECT_MODE;

typedef union MIDI_SHARED {
	struct {unsigned char velocity,number;} PACK_INLINE note;
	unsigned char controller;
	unsigned char garageband_function;
	struct {unsigned char function,device_id;} PACK_INLINE mmc;
	struct {unsigned char function,track;} PACK_INLINE hui;
    unsigned char bank_msb;  // xxxnew
} PACK_INLINE MIDI_SHARED;
typedef struct KEY {unsigned char modline_count,display_mode : 4,nav_y_mode : 4;short key_name_index,prefix_index;} PACK_INLINE KEY;
typedef struct MODLINE {unsigned char source,table,dest,led_green,led_red,max,min;short slew;FIXED_PT gain,offset; unsigned char channel;MIDI_SHARED ms;unsigned char port : 4,display_linked : 4;} PACK_INLINE MODLINE;
typedef struct NM {unsigned char format,reserved1[2];short name_index,other_key_index,pedal_index,string_index,end_index,reserved2[4];KEY key[NUM_KEYS];} PACK_INLINE NM;
typedef struct PRESET_IMAGE {NM nm;MODLINE modlines[NUM_KEYS][NUM_MODLINES_PER_KEY];} PACK_INLINE PRESET_IMAGE;
typedef struct STRINGS {int size; char data[500];} STRINGS;
struct PRESET_LIST;

typedef struct PRESET_LIST {struct PRESET_LIST *next;PRESET_IMAGE preset_image;STRINGS strings;unsigned char enables[NUM_KEYS][NUM_MODLINES_PER_KEY];} PRESET_LIST;

typedef	struct KEY_SETTINGS {unsigned char Rot_Slew,dead_x,accel_x,dead_y,accel_y;unsigned char on_sense,off_sense,delta;} PACK_INLINE KEY_SETTINGS;
typedef	struct SETTINGS		{FIXED_PT Global_Gain;unsigned char north_on_thresh,north_off_thresh,east_on_thresh,east_off_thresh,south_on_thresh,south_off_thresh,west_on_thresh,west_off_thresh,key_mode,key_response,el_offon:1,prog_change_display_offset:1,reserved:6,programChangeInput;PEDAL_CALIBRATION pedal_calibration;PEDAL_FILTER pedal_filter;CONNECT_MODE connect_mode;KEY_SETTINGS key[NUM_KEYS];} PACK_INLINE SETTINGS;

enum {SX_TYPE_NORMAL,SX_TYPE_FWUPDATE,SX_TYPE_DOWNLOAD};
enum {TYPE_NONE,TYPE_DEVICE,TYPE_MIDIINFO,TYPE_MIDIOUT,TYPE_MIDIIN,TYPE_CTL,TYPE_END_OF_LIST};
typedef struct {
	PRESET_LIST *first,*current_list;
	int preset_count,key_settings_index;
	PRESET_IMAGE *current_image;
	MODLINE		*current_modline;
	SETTINGS	settings;
	FILE		*fd_c;
	FILE		*fd_syx;
	Byte		*fw_image;
	int			key_num;
	int			mod_num_current;
    int			build_num;
	int			firmware_status;
    
    int device_softstep;
    int device_12step;
    int device_qunexus;
	void *outlet_msg;
    
    VERSION version_connected;
    VERSION version_embedded;


} t_softstep;

#ifdef	_WINDOWS
#pragma pack(8) // default for x86
#endif

#endif
