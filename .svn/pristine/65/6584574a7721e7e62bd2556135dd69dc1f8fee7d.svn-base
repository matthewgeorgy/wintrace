#include "inc/wt_heapapi.h"

extern T_WintraceOpts      *pOpts;

HANDLE
WtGetProcessHeap()
{
    HANDLE              Ret;


    if (BeginTrace(E_GetProcessHeap))
    {
        fprintf(pOpts->OutputFile, "()");
        Ret = GetProcessHeap();
        fprintf(pOpts->OutputFile, " = 0x%p", Ret);
        EndTrace(E_GetProcessHeap, Ret == NULL);
    }
    else
        Ret = GetProcessHeap();

    return Ret;
}

DWORD
WtGetProcessHeaps(DWORD NumberOfHeaps,
                  PHANDLE ProcessHeaps)
{
    DWORD               Ret;


    if (BeginTrace(E_GetProcessHeaps))
    {
        fprintf(pOpts->OutputFile, "(%u, 0x%p)", NumberOfHeaps, ProcessHeaps);
        Ret = GetProcessHeaps(NumberOfHeaps, ProcessHeaps);
        fprintf(pOpts->OutputFile, " = %u", Ret);
        EndTrace(E_GetProcessHeaps, Ret == 0);
    }
    else
        Ret = GetProcessHeaps(NumberOfHeaps, ProcessHeaps);

    return Ret;
}

LPVOID
WtHeapAlloc(HANDLE hHeap,
            DWORD dwFlags,
            SIZE_T dwBytes)
{
    LPVOID              Ret;


    if (BeginTrace(E_HeapAlloc))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, %llu)", hHeap, dwFlags, dwBytes);
        Ret = HeapAlloc(hHeap, dwFlags, dwBytes);
        fprintf(pOpts->OutputFile, " = 0x%p", Ret);
        EndTrace(E_HeapAlloc, Ret == NULL);
    }
    else
        Ret = HeapAlloc(hHeap, dwFlags, dwBytes);

    return Ret;
}

SIZE_T
WtHeapCompact(HANDLE hHeap,
              DWORD dwFlags)
{
    SIZE_T              Ret;


    if (BeginTrace(E_HeapCompact))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u)", hHeap, dwFlags);
        Ret = HeapCompact(hHeap, dwFlags);
        fprintf(pOpts->OutputFile, " = %u", Ret);
        EndTrace(E_HeapCompact, Ret == 0);
    }
    else
        Ret = HeapCompact(hHeap, dwFlags);

    return Ret;
}

HANDLE
WtHeapCreate(DWORD flOptions,
             SIZE_T dwInitialSize,
             SIZE_T dwMaximumSize)
{
    HANDLE              Ret;


    if (BeginTrace(E_HeapCreate))
    {
        fprintf(pOpts->OutputFile, "(%u, %llu, %llu)", flOptions, dwInitialSize, dwMaximumSize);
        Ret = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
        fprintf(pOpts->OutputFile, " = 0x%p", Ret);
        EndTrace(E_HeapCreate, Ret == NULL);
    }
    else
        Ret = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);

    return Ret;
}

BOOL
WtHeapDestroy(HANDLE hHeap)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapDestroy))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hHeap);
        Ret = HeapDestroy(hHeap);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapDestroy, Ret == FALSE);
    }
    else
        Ret = HeapDestroy(hHeap);

    return Ret;
}

BOOL
WtHeapFree(HANDLE hHeap,
           DWORD dwFlags,
           LPVOID lpMem)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapFree))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
        Ret = HeapFree(hHeap, dwFlags, lpMem);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapFree, Ret == FALSE);
    }
    else
        Ret = HeapFree(hHeap, dwFlags, lpMem);

    return Ret;
}

BOOL
WtHeapLock(HANDLE hHeap)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapLock))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hHeap);
        Ret = HeapLock(hHeap);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapLock, Ret == FALSE);
    }
    else
        Ret = HeapLock(hHeap);

    return Ret;
}

BOOL
WtHeapQueryInformation(HANDLE HeapHandle,
                       HEAP_INFORMATION_CLASS HeapInformationClass,
                       PVOID HeapInformation,
                       SIZE_T HeapInformationLength,
                       PSIZE_T ReturnLength)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapQueryInformation))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %d, 0x%p, %u, 0x%p)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
        Ret = HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapQueryInformation, Ret == FALSE);
    }
    else
        Ret = HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);

    return Ret;
}

LPVOID
WtHeapReAlloc(HANDLE hHeap,
              DWORD dwFlags,
              LPVOID lpMem,
              SIZE_T dwBytes)
{
    LPVOID              Ret;


    if (BeginTrace(E_HeapReAlloc))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, 0x%p, %u)", hHeap, dwFlags, lpMem, dwBytes);
        Ret = HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
        fprintf(pOpts->OutputFile, " = 0x%p", Ret);
        EndTrace(E_HeapReAlloc, Ret == NULL);
    }
    else
        Ret = HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);

    return Ret;
}

BOOL
WtHeapSetInformation(HANDLE HeapHandle,
                     HEAP_INFORMATION_CLASS HeapInformationClass,
                     PVOID  HeapInformation,
                     SIZE_T HeapInformationLength)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapSetInformation))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %d, 0x%p, %u)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
        Ret = HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapSetInformation, Ret == FALSE);
    }
    else
        Ret = HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);

    return Ret;
}

SIZE_T
WtHeapSize(HANDLE hHeap,
           DWORD dwFlags,
           LPCVOID lpMem)
{
    SIZE_T              Ret;


    if (BeginTrace(E_HeapSize))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
        Ret = HeapSize(hHeap, dwFlags, lpMem);
        fprintf(pOpts->OutputFile, " = %u", Ret);
        EndTrace(E_HeapSize, Ret == (SIZE_T)-1);
    }
    else
        Ret = HeapSize(hHeap, dwFlags, lpMem);

    return Ret;
}

BOOL
WtHeapUnlock(HANDLE hHeap)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapUnlock))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hHeap);
        Ret = HeapUnlock(hHeap);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapUnlock, Ret == FALSE);
    }
    else
        Ret = HeapUnlock(hHeap);

    return Ret;
}

BOOL
WtHeapValidate(HANDLE hHeap,
               DWORD dwFlags,
               LPCVOID lpMem)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapValidate))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
        Ret = HeapValidate(hHeap, dwFlags, lpMem);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapValidate, Ret == FALSE);
    }
    else
        Ret = HeapValidate(hHeap, dwFlags, lpMem);

    return Ret;
}

BOOL
WtHeapWalk(HANDLE hHeap,
           LPPROCESS_HEAP_ENTRY lpEntry)
{
    BOOL                Ret;


    if (BeginTrace(E_HeapWalk))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hHeap, lpEntry);
        Ret = HeapWalk(hHeap, lpEntry);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_HeapWalk, Ret == FALSE);
    }
    else
        Ret = HeapWalk(hHeap, lpEntry);

    return Ret;
}

