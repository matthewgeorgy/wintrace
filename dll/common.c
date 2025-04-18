#include "inc/common.h"
#include <stdio.h>

extern T_FuncRec g_FuncRecs[];
extern T_WINTRACE_OPTS *pOpts;

void
ShowDetails(T_WINTRACE_OPTS *Opts,
            DWORD Cnt)
{
    if (Opts->ShowProcessID)
        fprintf(Opts->OutputFile, "[%u] ", GetCurrentProcessId());
    if (Opts->ShowThreadID)
        fprintf(Opts->OutputFile, "<%u> ", GetCurrentThreadId());
    if (Opts->ShowFuncCount)
        fprintf(Opts->OutputFile, "(%u) ", Cnt);
}

// See djb2 hash function online
DWORD
Djb2(LPSTR String)
{
    DWORD       Hash = 5381;
    INT         C = *String++;


    while (C)
    {
        Hash = ((Hash << 5) + Hash) + C;
        C = *String++;
    }

    return Hash;
}

BOOL 
BeginTrace(E_FuncEnum FunctionName)
{
	T_FuncRec		Func = g_FuncRecs[FunctionName];


	if (!Func.bTrace)
	{
		ShowDetails(pOpts, ++(Func.Cnt));
		fprintf(pOpts->OutputFile, "%s", Func.Name);
		return TRUE;
	}

	return FALSE;
}

