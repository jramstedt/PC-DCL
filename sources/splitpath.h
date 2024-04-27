#ifndef SPLITPATH_H_
#define SPLITPATH_H_


// unix emulation code for the win32 _splitpath function
// Warning: don't use this function in your own code, you're asking for security
// problems (buffer overflow)

#ifndef WIN32

void _splitpath(const char* const path, char *drive, char *dir, char *fname, char *ext);

void _makepath(char* path, const  char *drive, const  char *dir, const  char *fname, const  char *ext);

#endif

#endif /*SPLITPATH_H_*/
