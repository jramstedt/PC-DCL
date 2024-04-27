#ifndef _DCL_FIND_DATA_H_
#define _DCL_FIND_DATA_H_

#ifdef __cplusplus
extern "C"
{
#endif
intptr_t Dcl_FindFirstFile(char *lpFileName, LPDCL_FIND_DATA lpFindFileData);
BOOL     Dcl_FindNextFile(intptr_t hFindFile, LPDCL_FIND_DATA lpFindFileData);
BOOL     Dcl_FindClose(intptr_t hFindFile);
#ifdef __cplusplus
}
#endif

#endif
