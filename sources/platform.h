#ifndef PLATFORM_H_
#define PLATFORM_H_
/*
 ***********
 *  WIN32  *
 ***********
 */
#ifdef _WIN32
#include <windows.h>

#define strncasecmp _strnicmp

#define SLASH_CHR      '\\'
#define SLASH_STR       "\\"
/*
 ***********
 *  UNIX   *
 ***********
 */
#else

#define SLASH_CHR      '/'
#define SLASH_STR       "/"

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned short      WORD;
//typedef int                 HANDLE;
typedef void                *LPVOID;

unsigned long filelength(int fh);
char *strupr(char *s);

#define INVALID_HANDLE_VALUE    -1

#define _mkdir(a)      	mkdir(a, 0777)
#define _rmdir(a)       rmdir(a)
#define _getcwd(a,b)    getcwd(a,b)
#define _sleep(a)		sleep(a)
#define MAX_PATH		PATH_MAX

/*
typedef unsigned char       BYTE;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL near           *PBOOL;
typedef BOOL far            *LPBOOL;
typedef BYTE near           *PBYTE;
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;
typedef int far             *LPINT;
typedef WORD near           *PWORD;
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;
typedef DWORD near          *PDWORD;
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;
typedef CONST void far      *LPCVOID;
*/

#include "findfile.h"
#include "splitpath.h"

#endif

#endif /*PLATFORM_H_*/
