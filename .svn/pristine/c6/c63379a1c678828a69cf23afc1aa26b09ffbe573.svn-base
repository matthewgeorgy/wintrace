#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "func_records.h"

typedef struct _tag_WintraceOpts
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
    CHAR        OutputFilename[64];
    FILE        *OutputFile;
	CHAR		TraceList[32][32];
} T_WintraceOpts;

DWORD Djb2(LPSTR String);
void ShowDetails(T_WintraceOpts *pOpts, DWORD Cnt);
BOOL BeginTrace(E_FuncEnum FunctionName);
void InitFuncRecs();

#endif // COMMON_H

