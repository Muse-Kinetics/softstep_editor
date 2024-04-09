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

//--------------------------------------------

enum
{
    TETHER_OFF,
    TETHER_HOSTED,
    TETHER_LIVE,
    TETHER_PEAK,
    TETHER_MIN
};

// message category/types stored in the sysex preamble
enum SYX_MSG_CATEGORY
{
    MSG_CAT_LEGACY,         // 0x00 = older softstep messaging where type was an int with MSB = 0, LSB = LEGACY_SYX_MSG_TYPES
    MSG_CAT_CALIBRATION,    // new message categories start here
    MSG_CAT_PRESET,         // to request/send preset data
    NUM_MSG_CATEGORIES
};

enum LEGACY_SYX_MSG_TYPES
{
    REQUEST_FW_VERSION,		// 0 - sends the current firmware version
    REQUEST_FW_UPDATE,  	// 1 - sends entire 8051 code memory as sysex
    LED_PACKET_CLOSE,   	// 2 - led packet digits
    LED_PACKET_LED_CLOSE, 	// 3 - led packet
    EL_PACKET_CLOSE,		// 4 - el packet
    FW_HEADER_CLOSE,		// 5 - fw header, used to update firmware - now sends to bootloader
    FW_BANK_INFO_CLOSE,		// 6 - fw block header
    FW_BANK_DATA_CLOSE,		// 7 - fw data
    PAD_PACKET_CLOSE,		// 8 - pad packet
    STANDALONE_CLOSE,		// 9 - standalone packet (preset?)
    SEGMENT_PACKET_CLOSE,	// A - segment
    PEDAL_PACKET_CLOSE,		// B - pedal
    ERASE_SERIAL,           // C - new but still legacy category
    NUM_LEGACY_SYX_MSG_TYPES

};

enum SYX_CALIBRATION_MSGS
{
    REQUEST_PEDAL_CAL,
    PEDAL_CAL_PAYLOAD,
    REQUEST_KEYS_CAL,
    KEYS_CAL_PAYLOAD,
    REQUEST_CV_CAL,
    CV_CAL_PAYLOAD,
    RESET_CV_CAL_TO_FACTORY,
    NUM_CALIBRATION_MSG_TYPES
};

enum SYX_PRESET_MSGS
{
    REQUEST_PRESET,
    PRESET_PAYLOAD,
    NUM_PRESET_MSG_TYPES
};

// standalone sysex packet message types
enum
{
    SA_TYPE_PRESET_IMAGE,           // 0
    SA_TYPE_PRESET_SET,             // 1
    SA_TYPE_SETTINGS,               // 2
    SA_TYPE_STANDALONE_ONOFF,       // 3
    SA_TYPE_TETHER_ONOFF,           // 4
    SA_TYPE_PIN,                    // 5
    SA_TYPE_PORT,                   // 6
    SA_TYPE_SCAN,                   // 7
    SA_TYPE_SCENECHANGE_ONOFF,      // 8
    SA_TYPE_NAVSTANDALONE_ONOFF     // 9
};


//--------------------------------------------


#define CURRENT_CV_CAL_VERSION 1
#define NUM_CV_OUTS 2
#define NUM_CV_OCTAVES 6 // 0v counts
#define NUM_CV_NOTES 61 // 0-5v is

#define	NUM_KEYS	11
#define	NUM_MODLINES_PER_KEY	6
#define	NUM_TOTAL_MODLINES	(NUM_KEYS * NUM_MODLINES_PER_KEY)
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

typedef struct
{
    unsigned char heel, toe;
    unsigned char table, reserved1;
} PEDAL_CALIBRATION;

typedef struct {unsigned char hysteresis,length;} PACK_INLINE PEDAL_FILTER;
typedef struct {unsigned char standalone,tether;} PACK_INLINE CONNECT_MODE;

typedef union MIDI_SHARED {
	struct {unsigned char velocity,number;} PACK_INLINE note;
    struct {unsigned char velocity; char transpose;} PACK_INLINE noteLive;
	unsigned char controller;
	unsigned char garageband_function;
	struct {unsigned char function,device_id;} PACK_INLINE mmc;
	struct {unsigned char function,track;} PACK_INLINE hui;
    unsigned char bank_msb;  // xxxnew
} PACK_INLINE MIDI_SHARED;

typedef struct KEY {unsigned char modline_count,display_mode : 4,nav_y_mode : 4;short key_name_index,prefix_index;} PACK_INLINE KEY;
typedef struct MODLINE {unsigned char source,table,dest,led_green,led_red,max,min;short slew;FIXED_PT gain,offset; unsigned char channel;MIDI_SHARED ms;unsigned char port : 4,display_linked : 4;} PACK_INLINE MODLINE;

typedef	struct NM
{
    unsigned char format;
    unsigned char reserved1[2];
    short   name_index, other_key_index, pedal_index,
            string_index, end_index;
    unsigned char cv1Sources, cv1Notes, cv1Control, cv1Channel;
    unsigned char cv2Sources, cv2Notes, cv2Control, cv2Channel;
    KEY key[NUM_KEYS];
} PACK_INLINE NM;	 // nm = not modline

typedef struct PRESET_IMAGE
{
    NM nm;
    MODLINE modlines[NUM_KEYS][NUM_MODLINES_PER_KEY];
} PACK_INLINE PRESET_IMAGE;

typedef struct STRINGS {int size; char data[500];} STRINGS;
struct PRESET_LIST;

typedef struct PRESET_LIST {struct PRESET_LIST *next;PRESET_IMAGE preset_image;STRINGS strings;unsigned char enables[NUM_KEYS][NUM_MODLINES_PER_KEY];} PRESET_LIST;

typedef	struct KEY_SETTINGS
{
    unsigned char Rot_Slew,dead_x,accel_x,dead_y,accel_y; // rot_slew is unused
    unsigned char on_sense,off_sense,delta; // delta is unused, on/off are per key
} KEY_SETTINGS;

typedef	struct SETTINGS
{
    FIXED_PT Global_Gain;
    unsigned char   north_on_thresh,north_off_thresh,
                    east_on_thresh,east_off_thresh,
                    south_on_thresh,south_off_thresh,
                    west_on_thresh,west_off_thresh,     // all of the above are global to all sensors
                    key_mode,key_response,
                    el_offon:1,prog_change_display_offset:1,reserved:6;
    char progchg_rx_channel; // this is already set up for program change rx channel, so use this
    PEDAL_CALIBRATION pedal_calibration; // this was unused prior to SS3
    unsigned char keyL_brightness, reserved1; // was PEDAL_FILTER pedal_filter;
    CONNECT_MODE connect_mode;
    KEY_SETTINGS key[NUM_KEYS]; // 8 bytes * 11 keys
} SETTINGS;

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
