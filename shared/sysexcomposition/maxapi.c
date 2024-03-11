// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "maxapi.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include "device_includes.h"
#include "maxapi.h"
#include "syxformats.h"
#include "attribute.h"
#include "syxtx.h"
#include "utils.h"

struct t_obj_info;

struct t_obj_info {struct t_obj_info *next; t_symbol symbol;};

struct t_obj_info *toi_next = 0;


t_symbol *add_symbol(char *str)
{
    struct t_obj_info **next = &toi_next;

    while(*next)
    {
            if (!strcmp(str,(*next)->symbol.s_name))
            {

                return &(*next)->symbol;
            }

            next = &(*next)->next;
    }

    *next = (struct t_obj_info *) malloc(sizeof(struct t_obj_info));
    (*next)->symbol.s_name = (char *) malloc(strlen(str)+1);
    strcpy((*next)->symbol.s_name,str); // fixing this broke things, leaving as insecure

    (*next)->next = 0;
    return &(*next)->symbol;
}

void maxapi_init(void)
{
    
    
    
}

t_symbol *gensym(char *str)
{
    return add_symbol(str);
}

void *outlet_anything(void *o, t_symbol *s, short ac, t_atom *av)
{
    Q_UNUSED(o);
    Q_UNUSED(s);

    //printf("outlet_anything: %s",s->s_name);

    int i;
    for (i=0;i<ac;i++)
    {
        switch(av[i].a_type)
        {
        case A_LONG:
            printf(" %ld",av[i].a_w.w_long);
            break;
        case A_SYM:
            printf(" %s",av[i].a_w.w_sym->s_name);
            break;
        default:
            printf(" unknown type[%d]",av[i].a_type);
            break;
        }
    }
    printf("\n");
    return 0;
}


