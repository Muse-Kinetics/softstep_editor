// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#ifndef MIDI_INCLUDED
#define	MIDI_INCLUDED

//typedef struct {unsigned char manufacturer_id1,manufacturer_id2,manufacturer_id3,manufacturer_id4,product,format;} SYSEX_STANDARD;
typedef struct {unsigned char manufacturer_id,model_number,sysex_type,sub_model,res2,res[9],unit_id;} SYSEX_FIRMWARE;
typedef struct {unsigned char manufacturer_id,model_number,sysex_type,format,dest,res[9],unit_id;} SYSEX_PRESET;
typedef struct {unsigned char manufacturer_id,model_number,sysex_type,format,res2,res[9],unit_id;} SYSEX_BULK;
typedef struct {unsigned char manufacturer_id,model_number,sysex_type,cmd,preset_num,res[9],unit_id;} SYSEX_REMOTE;
typedef struct {unsigned char manufacturer_id,sysex_channel,sub_id_1,sub_id_2;} SYSEX_UNIVERSAL;


#ifdef UNUSED
typedef struct {unsigned char status;
	union {
		struct { unsigned char note,velocity; } note_on;
		struct { unsigned char note,after_touch; } note_off;
		struct { unsigned char lsb,msb; } pitch_wheel;
		struct { unsigned char program; } program_change;
		struct { unsigned char cnum,val; } controller;
		SYSEX_STANDARD standard_header;
		SYSEX_FIRMWARE firmware_header;
		SYSEX_PRESET preset_header;
		SYSEX_BULK bulk_header;
		SYSEX_REMOTE remote_header;
		SYSEX_UNIVERSAL universal_header;
		unsigned char raw[1];
	} u;
} MIDI_MESSAGE;
#endif

#define	MIDI_NOTE_OFF			0x80
#define	MIDI_NOTE_ON			0x90
#define	MIDI_NOTE_AFTERTOUCH	0xA0
#define	MIDI_CONTROL_CHANGE		0xB0
#define	MIDI_PROG_CHANGE		0xC0
#define	MIDI_CHANNEL_PRESSURE	0xD0
#define	MIDI_PITCH_BEND			0xE0
#define	MIDI_SX_START			0xF0
#define	MIDI_MTC				0xF1
#define	MIDI_SONG_POSITION		0xF2
#define	MIDI_SONG_SELECT		0xF3
#define	MIDI_TUNE_REQUEST		0xF6
#define MIDI_BANK_CHANGE_LSB	0x20
#define MIDI_BANK_CHANGE_MSB	0x00

#define	MIDI_SX_STOP			0xF7

#define MIDI_RT_CLOCK			0xF8
#define	MIDI_RT_UNDEF1			0xF9
#define MIDI_RT_START			0xFA
#define	MIDI_RT_CONTINUE		0xFB
#define	MIDI_RT_STOP			0xFC
#define	MIDI_RT_UNDEF2			0xFD
#define	MIDI_RT_ACTIVE_SENSE	0xFE
#define	MIDI_RT_RESET			0xFF

#define	MIDI_SYSTEM			0xF0

#define	MANUFACTURER_MOOG	4
#define	MODEL_MP			47
#define	SUB_MODEL			0
#define	UNIT_ID				0

//#define	MAX_DEST	2

#define	NOTE_VELOCITY_DEFAULT	0x40

struct MIDI_SOURCE;
struct MIDI_BUFFER;

typedef struct 	{
	unsigned char CableCode;
	union
	{
		unsigned char datums[3];
		struct
		{
			unsigned char status;
			union
			{
				struct { unsigned char note,velocity; } note_on;
				struct { unsigned char note,after_touch; } note_off;
				struct { unsigned char lsb,msb; } pitch_wheel;
				struct { unsigned char program; } program_change;
				struct { unsigned char cnum,val; } controller;
			} d;
		} s;
	} u;
} MIDI_USB_MESSAGE;

//typedef	void (*PUT_ROUTINE)(MIDI_USB_MESSAGE pdata *msg,struct MIDI_BUFFER xdata *this,unsigned char CableCode) ;

typedef struct MIDI_STREAM_STATE {unsigned char mss_status,mss_expected,mss_index;} MIDI_STREAM_STATE;

#define	MIDI_BUFFER_SIZE	40
//extern pdata unsigned char usb_in[MIDI_BUFFER_SIZE];


#define	MIDI_SERVE_NO		0		// don't call midi serve
#define	MIDI_SERVE_WAIT		1		// call and wait till rooom
#define	MIDI_SERVE_NOWAIT	2		// call but discard if full



//extern data unsigned long rtc_count;
extern unsigned long rtc_elapsed,rtc_last;
//extern bit rtc_pending,rtc_state;
//extern bit controller_tx_disable;
extern unsigned char usb_tx_timeout;

void MidiServe(void);
void midi_serial_in_put(unsigned char midi_char);
void midi_init(void);
void midi_setup_paths(void);
unsigned char midi_serial_out_empty(void);
//MIDI_USB_MESSAGE pdata *midi_serial_out_get(void);
void usb_midi_stall_check(void);
void midi_triple(unsigned char status,unsigned char val1,unsigned char val2);
void midi_double(unsigned char status,unsigned char val1);
unsigned char midi_triple_room_check(void);
void midi_put_chunk(unsigned char *source,unsigned int len);
void midi_send_nulls(unsigned int count);
void midi_buffer_put_core(unsigned char val);
void rtc_serve(void);
//extern data unsigned char rtc_char;
void midi_rtc_rx(void);
void midi_serve_serial(void);
void midi_serve_usb(void);
//void advance_midi_source( MIDI_SOURCE xdata *midi_source);
void midi_clear_paths(void);
void midi_path_usb_in(void);
void midi_path_usb_out(void);
void midi_path_serial_in(void);
//void midi_buffer_put_raw(unsigned char val,MIDI_BUFFER xdata *this,unsigned char serve_flag) reentrant;
void midi_buffer_put_raw_core(unsigned char val);
void midi_note_on(unsigned char note,unsigned char velocity,unsigned char channel);
void midi_note_off(unsigned char note,unsigned char velocity,unsigned char channel);
void midi_controller(unsigned char val,unsigned char cc,unsigned char channel);
void midi_bank(unsigned char bank,unsigned char channel);
void midi_program(unsigned char program,unsigned char channel);
void midi_buffer_init(void);


//unsigned char midi_buffer_usb_out_room(MIDI_BUFFER xdata *this);

void sx_send_setup(void);
void sx_send_cleanup(void);

#endif //MIDI_INCLUDED

