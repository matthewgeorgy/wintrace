#ifndef COMMON_H
#define COMMON_H

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <func_records.h>

typedef FILE *LPFILE; 

// Options structure that mirrors the core executable's
typedef struct _tag_WintraceOpts
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
	BOOL		UsePipes;
    CHAR        OutputFilename[64];
    FILE        *OutputFile;
    CHAR        TraceList[32][32];
    CHAR        *ProgramName,
                CmdArgs[128];
} T_WintraceOpts;

// Function string trace buffer
typedef struct _tag_FuncBuffer
{
    CHAR        Buff[1024];
    SIZE_T      Pos;
} T_FuncBuffer;

typedef struct _tag_FuncList
{
    T_FuncBuffer        Buffers[64];
    SIZE_T              Index;
} T_FuncList;

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

// Write to the current global function buffer
void WriteFuncBuffer(char *Format, ...);

// Print the specified function buffer
void PrintFuncBuffer(T_FuncBuffer *Buffer);

#endif // COMMON_H

