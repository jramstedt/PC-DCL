/****************************************************************************/
/*                                                                          */
/*   PC-DCL -  DCL command line interpreter for Windows.                    */
/*   Copyright (C) 1991-2007 by Michel Valentin                             */
/*                                                                          */
/*   This program is free software; you can redistribute it and/or modify   */
/*   it under the terms of the enclosed   license.                          */
/*                                                                          */
/*   This program is distributed in the hope that it will be useful,        */
/*   but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   */
/*                                                                          */
/****************************************************************************/
#include <string.h>
#include <strings.h>

#include "platform.h"
#include "dcl.h"

// Gosub -----------------------------------------------------
RPARAM_T GOSUB_PARAM[] = {
    {1,"Label",0},
    {0,"",0}
    };

int dcl_gosub(PARAM_T *p,PARAM_T *q)
{
    char    label[MAX_TOKEN];
    CMD_LABEL LABEL;
    int     l = 0;
    int     i = 0;
    int     found = 0;
    int     retcod = DCL_OK;

    if (cmd[C].subr) {
        NEXT_LINE();
        return(DCL_OK);
        }
    if (!dcl[D].cc[dcl[D].ccl]) {
        NEXT_LINE();
        return(DCL_OK);
        }

    *label = 0;
    if (C <= 1) {
        (void) dcl_printf(dcl[D].SYS_OUTPUT,"Invalid use of GOSUB command.\n");
        _SEVERITY = 2;
        retcod = DCL_ERROR;
        goto exit_label;
        }

    if (p == NULL || q == NULL) return(DCL_ERROR);

    retcod = cmd_parse_line(dcl_line,GOSUB_PARAM,DUMMY_QUAL,p,q);
    if (retcod == DCL_OK) {
        dcl_string(p[0].value,label,MAX_TOKEN);

        if (*label) {
            strcat(label,":");
            while (!found && i <= (int) nempty(cmd[C].label)) {
                if (rcld(cmd[C].label,&LABEL,(unsigned int)i)) {
                    if (strcasecmp(label,LABEL.name) == 0) {
                        l = LABEL.line;
                        found = 1;
                        }
                    }
                i++;
                }
            }
        if (!found) {
            NEXT_LINE();
            (void) dcl_printf(dcl[D].SYS_OUTPUT,"GOSUB target not found.\n");
            _SEVERITY = 2;
            retcod = DCL_ERROR;
            goto exit_label;
            }
        else {
            i = cmd[C].ln + 1;
            (void) pushdptr(cmd[C].stack,&i);
            cmd[C].ln = l;
            }
        }
exit_label:
    return(retcod);
}
