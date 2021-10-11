#include <stdio.h>
#include "inc/wt_heapapi.h"

extern T_WINTRACEOPTS      *pOpts;

HANDLE
WtGetProcessHeap()
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetProcessHeap()");
    Ret = GetProcessHeap();
    printf(" = 0x%p\n", Ret);

    return Ret;
}

DWORD
WtGetProcessHeaps(DWORD NumberOfHeaps,
                  PHANDLE ProcessHeaps)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetProcessHeaps(%u, 0x%p)", NumberOfHeaps, ProcessHeaps);
    Ret = GetProcessHeaps(NumberOfHeaps, ProcessHeaps);
    printf(" = %u\n", Ret);

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
    printf("HeapAlloc(0x%p, %u, %llu)", hHeap, dwFlags, dwBytes);
    Ret = HeapAlloc(hHeap, dwFlags, dwBytes);
    printf(" = 0x%p\n", Ret);

    return Ret;
}

SIZE_T
WtHeapCompact(HANDLE hHeap,
              DWORD dwFlags)
{
    SIZE_T              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("HeapCompact(0x%p, %u) = %ul\n", hHeap, dwFlags);
    Ret = HeapCompact(hHeap, dwFlags);
    printf(" = %u\n", Ret);

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
    printf("HeapCreate(%u, %llu, %llu)", flOptions, dwInitialSize, dwMaximumSize);
    Ret = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
    printf(" = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtHeapDestroy(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("HeapDestroy(0x%p)", hHeap);
    Ret = HeapDestroy(hHeap);
    printf(" = %d\n", Ret);

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
    printf("HeapFree(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = HeapFree(hHeap, dwFlags, lpMem);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapLock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("HeapLock(0x%p)", hHeap);
    Ret = HeapLock(hHeap);
    printf(" = %d\n", Ret);

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
    printf("HeapQueryInformation(0x%p, %d, 0x%p, %u, 0x%p)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    Ret = HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    printf(" = %d\n", Ret);

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
    printf("HeapReAlloc(0x%p, %u, 0x%p, %u)", hHeap, dwFlags, lpMem, dwBytes);
    Ret = HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
    printf(" = 0x%p\n", Ret);

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
    printf("HeapSetInformation(0x%p, %d, 0x%p, %u)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    Ret = HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    printf(" = %d\n", Ret);

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
    printf("HeapSize(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = HeapSize(hHeap, dwFlags, lpMem);
    printf(" = %u\n", Ret);

    return Ret;
}

BOOL
WtHeapUnlock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("HeapUnlock(0x%p)", hHeap);
    Ret = HeapUnlock(hHeap);
    printf(" = %d\n", Ret);

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
    printf("HeapValidate(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = HeapValidate(hHeap, dwFlags, lpMem);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapWalk(HANDLE hHeap,
           LPPROCESS_HEAP_ENTRY lpEntry)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("HeapWalk(0x%p, 0x%p)", hHeap, lpEntry);
    Ret = HeapWalk(hHeap, lpEntry);
    printf(" = %d\n", Ret);

    return Ret;
}
