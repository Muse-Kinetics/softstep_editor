// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
//
//  attribute.h
//  SoftstepSyxDemo
//
//

#ifndef SoftstepSyxDemo_attribute_h
#define SoftstepSyxDemo_attribute_h

#include "device_includes.h"
//#include "maxapi.h"

#define	MODLINE_1_OUTPUT	"Modline 1 Output"
#define	MODLINE_6_OUTPUT	"Modline 6 Output"

#define	SRC_NAV_Y				"Nav Y"
#define	SRC_ANY_KEY_VALUE		"Any Key Value"
#define	SRC_OTHER_KEY_PRESSED	"Other Key Pressed"
#define	SRC_LONG_TRIG			"Long_Trig"
#define	SRC_Y_INCREMENT			"Y_Increment"

//char *source_list[];
void attribute_process(t_softstep *x, short argc, t_atom *argv);

//----------------------------------------------- uutils.h
extern unsigned short crc;
void crc_byte(char val);
void post_par_list(short argc,t_atom *argv, char *fmt,...);
int par_match(short argc,t_atom *argv,...);

void write_c_close(t_softstep *x);
void write_c(char *title,void *data,int length,t_softstep *x);
void write_c_title(char *title,t_softstep *x);
void write_c_data(void *data,int length,t_softstep *x);
void write_c_end(t_softstep *x);
void attribute(t_softstep *x,int count,...);
void write_c_close(t_softstep *x);
void write_c(char *title,void *data,int length,t_softstep *x);
void sx_send_list(t_softstep *x,int type,char *description);
int get_index_str(char *list[],char *str);
int get_index(char *list[],char *listXlate[],t_atom *argv);
void float_fix(FIXED_PT *val,float fval);
void par_error(t_softstep *x,short argc,t_atom *argv,char *msg);
void crc_init(void);
t_softstep *softstep_init(void);
void sendSysex(unsigned char *src,int len, int type);

unsigned char *image; int imageLength;
unsigned char *settings; int settingsLength;


#endif
