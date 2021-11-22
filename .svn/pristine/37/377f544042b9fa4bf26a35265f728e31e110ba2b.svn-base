#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "func_records.h"

typedef struct _tag_WINTRACE_OPTS
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
    CHAR        OutputFilename[64];
    FILE        *OutputFile;
	CHAR		TraceList[32][32];
} T_WINTRACE_OPTS;

DWORD Djb2(LPSTR String);
void ShowDetails(T_WINTRACE_OPTS *pOpts, DWORD Cnt);
BOOL BeginTrace(E_FuncEnum FunctionName);
void InitFuncRecs();

#endif // COMMON_H

