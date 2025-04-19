#ifndef WT_STDIO_H
#define WT_STDIO_H

#include "common.h"

LPFILE wt_fopen(LPCSTR filename, LPCSTR mode);
LPFILE wt__wfopen(LPCWSTR filename, LPCWSTR mode);
int wt_fclose(LPFILE stream);

#endif // WT_STDIO_H
