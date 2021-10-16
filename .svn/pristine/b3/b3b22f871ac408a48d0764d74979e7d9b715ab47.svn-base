#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

typedef struct _tag_WINTRACE_OPTS
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
	CHAR		OutputFilename[64];
	FILE		*OutputFile;
} T_WINTRACE_OPTS;

typedef HANDLE	T_HFILEMAP;

void ShowDetails(T_WINTRACE_OPTS *pOpts, DWORD Cnt);

#endif // COMMON_H
