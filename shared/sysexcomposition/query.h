// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
//
//  query.h
//  SoftstepSyxDemo
//
//

#ifndef SoftstepSyxDemo_query_h
#define SoftstepSyxDemo_query_h

int fw_process_midi(int midiVal,int *buildNum,int *error,char *version);
void softstep_midi_process(t_softstep *x, VERSION *version,long n);
void send_fw_query(t_softstep *x);

#endif
