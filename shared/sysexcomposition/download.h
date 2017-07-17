// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef SoftstepSyxDemo_download_h
#define SoftstepSyxDemo_download_h

#include "softstep.h"

int firmware_compatable(int build_num);

void download_start(t_softstep *x);
void download_file_open(t_softstep *x,char *name);
void download_file_close(t_softstep *x);

#endif
