#include <stdio.h>
#include "inc/wt_heapapi.h"

extern T_WINTRACE_OPTS      *pOpts;

HANDLE
WtGetProcessHeap()
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetProcessHeap()");
    Ret = GetProcessHeap();
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

DWORD
WtGetProcessHeaps(DWORD NumberOfHeaps,
                  PHANDLE ProcessHeaps)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetProcessHeaps(%u, 0x%p)", NumberOfHeaps, ProcessHeaps);
    Ret = GetProcessHeaps(NumberOfHeaps, ProcessHeaps);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

LPVOID
WtHeapAlloc(HANDLE hHeap,
            DWORD dwFlags,
            SIZE_T dwBytes)
{
    LPVOID              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapAlloc(0x%p, %u, %llu)", hHeap, dwFlags, dwBytes);
    Ret = HeapAlloc(hHeap, dwFlags, dwBytes);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

SIZE_T
WtHeapCompact(HANDLE hHeap,
              DWORD dwFlags)
{
    SIZE_T              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapCompact(0x%p, %u)", hHeap, dwFlags);
    Ret = HeapCompact(hHeap, dwFlags);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

HANDLE
WtHeapCreate(DWORD flOptions,
             SIZE_T dwInitialSize,
             SIZE_T dwMaximumSize)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapCreate(%u, %llu, %llu)", flOptions, dwInitialSize, dwMaximumSize);
    Ret = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtHeapDestroy(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapDestroy(0x%p)", hHeap);
    Ret = HeapDestroy(hHeap);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapFree(HANDLE hHeap,
           DWORD dwFlags,
           LPVOID lpMem)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapFree(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = HeapFree(hHeap, dwFlags, lpMem);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapLock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapLock(0x%p)", hHeap);
    Ret = HeapLock(hHeap);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

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
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapQueryInformation(0x%p, %d, 0x%p, %u, 0x%p)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    Ret = HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

LPVOID
WtHeapReAlloc(HANDLE hHeap,
              DWORD dwFlags,
              LPVOID lpMem,
              SIZE_T dwBytes)
{
    LPVOID              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapReAlloc(0x%p, %u, 0x%p, %u)", hHeap, dwFlags, lpMem, dwBytes);
    Ret = HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtHeapSetInformation(HANDLE HeapHandle,
                     HEAP_INFORMATION_CLASS HeapInformationClass,
                     PVOID  HeapInformation,
                     SIZE_T HeapInformationLength)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapSetInformation(0x%p, %d, 0x%p, %u)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    Ret = HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

SIZE_T
WtHeapSize(HANDLE hHeap,
           DWORD dwFlags,
           LPCVOID lpMem)
{
    SIZE_T              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapSize(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = HeapSize(hHeap, dwFlags, lpMem);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

BOOL
WtHeapUnlock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapUnlock(0x%p)", hHeap);
    Ret = HeapUnlock(hHeap);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapValidate(HANDLE hHeap,
               DWORD dwFlags,
               LPCVOID lpMem)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapValidate(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = HeapValidate(hHeap, dwFlags, lpMem);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapWalk(HANDLE hHeap,
           LPPROCESS_HEAP_ENTRY lpEntry)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "HeapWalk(0x%p, 0x%p)", hHeap, lpEntry);
    Ret = HeapWalk(hHeap, lpEntry);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}
