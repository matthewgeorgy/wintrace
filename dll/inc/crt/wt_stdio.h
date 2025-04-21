#ifndef WT_STDIO_H
#define WT_STDIO_H

#include "common.h"

LPFILE wt_fopen(LPCSTR filename, LPCSTR mode);
LPFILE wt__wfopen(LPCWSTR filename, LPCWSTR mode);
int wt_fclose(LPFILE stream);
int wt_feof(LPFILE stream);
int wt_ferror(LPFILE stream);
int wt_fflush(LPFILE stream);
size_t wt_fread(LPVOID ptr, size_t size, size_t nmemb, LPFILE stream);
size_t wt_fwrite(LPVOID ptr, size_t size, size_t nmemb, LPFILE stream);
int wt_fseek(LPFILE stream, long offset, int whence);
long wt_ftell(LPFILE stream);

#endif // WT_STDIO_H
