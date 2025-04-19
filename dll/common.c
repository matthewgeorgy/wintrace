#include <common.h>
#include <stdio.h>

// Globals
extern      		T_FuncRec g_FuncRecs[];
extern      		T_WintraceOpts *pOpts;
BOOL        		g_TraceAll = TRUE;
INT         		g_CallLvl = 0;
T_FuncList  		g_FuncList;
extern HANDLE		g_Pipe;
extern HANDLE		g_Fence;

void
ShowDetails(T_WintraceOpts *Opts,
            DWORD Cnt)
{
    if (Opts->ShowProcessID)
        WriteFuncBuffer("[%u] ", GetCurrentProcessId());
    if (Opts->ShowThreadID)
        WriteFuncBuffer("<%u> ", GetCurrentThreadId());
    if (Opts->ShowFuncCount)
        WriteFuncBuffer("(%u) ", Cnt);
}

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
    T_FuncRec       *Func = &g_FuncRecs[FunctionName];


    if (Func->bTrace)
    {
        g_CallLvl++;
        ShowDetails(pOpts, ++(Func->Cnt));
        WriteFuncBuffer("%*c%s", g_CallLvl, ' ', Func->Name);
        return TRUE;
    }

    return FALSE;
}

// *could use this param to check for if a function can report GetLastError()
void
EndTrace(E_FuncEnum FunctionName, // reserved for now*
         BOOL bError)
{
    if (bError)
        WriteFuncBuffer(" (ERROR: %u) ", GetLastError());
    WriteFuncBuffer("\r\n");
    PrintFuncBuffer(&g_FuncList.Buffers[g_CallLvl--]);
}

void
WriteFuncBuffer(char *Format,
                ...)
{
    T_FuncBuffer        *Buffer = &g_FuncList.Buffers[g_CallLvl];
    SIZE_T              Bytes;
    va_list             VarArgs;

    va_start(VarArgs, Format);

    Bytes = vsprintf(Buffer->Buff + Buffer->Pos, Format, VarArgs);
    Buffer->Pos += Bytes;

    va_end(VarArgs);
}

void
PrintFuncBuffer(T_FuncBuffer *Buffer)
{
	if (pOpts->UsePipes)
	{
		BOOL Status;
		DWORD NumRead;

		Status = WriteFile(g_Pipe, Buffer->Buff, 512, &NumRead, NULL);
		if (!Status)
		{
			printf("failed to write to pipe %d...!\r\n", GetLastError());
		}
		WaitForSingleObject(g_Fence, INFINITE);
	}
	else
	{
    	fprintf(pOpts->OutputFile, "%s", Buffer->Buff);
	}

    Buffer->Pos = 0;
}

void
InitFuncRecs()
{
    DWORD       Hash;
    INT         I;


	// Only tracing specific functions, set just these to TRUE
	if (pOpts->TraceList[0][0])
	{
		for (I = 0; I < 32 && pOpts->TraceList[I]; I++)
		{
			Hash = Djb2(pOpts->TraceList[I]);

			SetTrace(Hash, TRUE);
		}
	}

	// Blocking specific functions
	else if (pOpts->BlockList[0][0])
    {
        for (I = 0; I < E_Count; I++)
        {
            g_FuncRecs[I].bTrace = TRUE;
        }

		for (I = 0; I < 32 && pOpts->BlockList[I]; I++)
		{
			Hash = Djb2(pOpts->BlockList[I]);

			SetTrace(Hash, FALSE);
		}
    }

	// Tracing all functions
    else
    {
        for (I = 0; I < E_Count; I++)
        {
            g_FuncRecs[I].bTrace = TRUE;
        }
    }
}

