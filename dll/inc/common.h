#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "func_records.h"

// Options structure that mirrors the core executable's
typedef struct _tag_WintraceOpts
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
    CHAR        OutputFilename[64];
    FILE        *OutputFile;
    CHAR        TraceList[32][32];
} T_WintraceOpts;

// See djb2 hash function online
DWORD Djb2(LPSTR String);

// Prints info about thread ID, proc ID, and call count
void ShowDetails(T_WintraceOpts *pOpts, DWORD Cnt);

// Begin the trace for a function; obtain the func record through the passed
// enum, then conditionally print info and return a bool to the hook that
// tells whether or not to trace the function (ie, print info)
BOOL BeginTrace(E_FuncEnum FunctionName);

// Initialize the function records array, specifically setting the conditional
// tracing flag (will add more later)
void InitFuncRecs();

// End the trace for a function
void EndTrace(E_FuncEnum FunctionName, BOOL bError);

#endif // COMMON_H

