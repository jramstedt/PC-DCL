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
#include <errno.h>
#include "platform.h"
#include "dcl.h"
#include "dbglog.h"

intptr_t Dcl_FindFirstFile(char *lpFileName, LPDCL_FIND_DATA lpFindFileData)
{
    intptr_t hFindFile;
    struct _finddata_t ff;

    if ((hFindFile = _findfirst(lpFileName, &ff)) != -1) {
        memset(lpFindFileData, 0, sizeof(DCL_FIND_DATA));
        lpFindFileData->dwFileAttributes = ff.attrib;
        lpFindFileData->nFileSize = ff.size;
        lpFindFileData->CreationTime = ff.time_create;
        lpFindFileData->AccessTime = ff.time_access;
        lpFindFileData->WriteTime = ff.time_write;
        memcpy(lpFindFileData->cFileName, ff.name, sizeof(lpFindFileData->cFileName));
        memset(lpFindFileData->cAlternateFileName, 0, sizeof(lpFindFileData->cAlternateFileName));
    } else {
        DebugLogV(DEBUGLOG_LEVEL_DEBUG, "<Dcl_FindFirstFile> _findfirst %s error %d.", lpFileName, errno);
    }

    return hFindFile;
}

BOOL Dcl_FindNextFile(intptr_t hFindFile, LPDCL_FIND_DATA lpFindFileData)
{
    struct _finddata_t ff;

    if (_findnext(hFindFile, &ff) == 0) {
        memset(lpFindFileData, 0, sizeof(DCL_FIND_DATA));
        lpFindFileData->dwFileAttributes = ff.attrib;
        lpFindFileData->nFileSize = ff.size;
        lpFindFileData->CreationTime = ff.time_create;
        lpFindFileData->AccessTime = ff.time_access;
        lpFindFileData->WriteTime = ff.time_write;
        memcpy(lpFindFileData->cFileName, ff.name, sizeof(lpFindFileData->cFileName));
        memset(lpFindFileData->cAlternateFileName, 0, sizeof(lpFindFileData->cAlternateFileName));
        return TRUE;
    } else {
        DebugLogV(DEBUGLOG_LEVEL_DEBUG, "<Dcl_FindNextFile> _findnext error %d.", errno);
        return FALSE;
    }
}

BOOL Dcl_FindClose(intptr_t hFindFile) 
{
    return _findclose(hFindFile) == 0 ? TRUE : FALSE;
}
