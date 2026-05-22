// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "maxapi.h"
#include "utils.h"
#include "device_includes.h"
#include "query.h"
#include "attribute.h"


void prepare_presets(t_softstep *x)
{
    // create 5 presets
    int i;
    long key, m;
    for (i=0;i<1;i++)
    {
        attribute(x,2,A_SYM,"preset",A_LONG,i);
        
        // create 5 keys
        for (key=0;key<5;key++)
        {
            attribute(x,2,A_SYM,"key",A_LONG,key);
            
            // create 2 modlines
            for (m=0;m<2;m++)
            {
                attribute(x,3,A_SYM,"set",A_SYM,"Modline",A_LONG,m+1);
                
                // set some attibutes for this modline
                attribute(x,3,A_SYM,"set",A_SYM,"Min",A_LONG,12l);
                attribute(x,3,A_SYM,"set",A_SYM,"Garageband_Function",A_SYM,"Rewind_to_Start");
            }
        }
    }
}

void prepare_settings(t_softstep *x)
{
    long key;

    for (key=0;key<5;key++)
    {
        attribute(x,4,A_SYM,"set",A_SYM,"key",A_SYM,"keynum",A_LONG,key+1);

        attribute(x,3,A_SYM,"set",A_SYM,"Key_Response",A_LONG,22l);

    }

    
}

int mainsysex(int argc, const char * argv[])
{
    t_softstep *x = softstep_init();
    
    
    // check the version of the embedded firmware, which is a sysex file in the working directory
    
    if (argc==2)
    {
        FILE *fd = fopen(argv[1],"rb");
        if (fd)
        {
            int fchar;
            
            while ( (fchar = fgetc(fd)) != EOF)
                softstep_midi_process(x,&x->version_embedded,fchar);
            
            
        } else
            LOG_ERR("Unable to open %s", argv[1]);
        
        if (x->version_embedded.buildnum)
            LOG_INFO("Embedded version: %s build[%d]", x->version_embedded.version, x->version_embedded.buildnum);
    } else
        LOG_INFO("No embedded sysex file present");
    
    // query for the connected version
    send_fw_query(x);  // this sends the fw query sysex
    
    // process each response byte in midi handler with the softstep_midi_process(x,&x->version_connected,fchar);
    
    
    
    prepare_presets(x);
    prepare_settings(x);
    
    attribute(x,1,A_SYM,"download");  // download presets and settings
    
    return 0;
}
