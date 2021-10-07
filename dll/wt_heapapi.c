#include <stdio.h>
#include "inc/wt_heapapi.h"

extern T_WINTRACEOPTS      *pOpts;

HANDLE
WtGetProcessHeap()
{
    HANDLE              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnGetProcessHeap;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnGetProcessHeap = GetProcAddress(GetModuleHandle("Kernel32.dll"), "GetProcessHeap");
    printf("GetProcessHeap()");
    Ret = lpfnGetProcessHeap();
    printf(" = 0x%p\n", Ret);

    Cnt++;
    return Ret;
}

DWORD
WtGetProcessHeaps(DWORD NumberOfHeaps,
                  PHANDLE ProcessHeaps)
{
    DWORD               Ret;
    static DWORD        Cnt;
    FARPROC             lpfnGetProcessHeaps;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnGetProcessHeaps = GetProcAddress(GetModuleHandle("Kernel32.dll"), "GetProcessHeaps");
    printf("GetProcessHeaps(%u, 0x%p)", NumberOfHeaps, ProcessHeaps);
    Ret = lpfnGetProcessHeaps(NumberOfHeaps, ProcessHeaps);
    printf(" = %u\n", Ret);

    Cnt++;
    return Ret;
}

LPVOID
WtHeapAlloc(HANDLE hHeap,
            DWORD dwFlags,
            SIZE_T dwBytes)
{
    LPVOID              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapAlloc;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapAlloc = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapAlloc");
    printf("HeapAlloc(0x%p, %u, %llu)", hHeap, dwFlags, dwBytes);
    Ret = lpfnHeapAlloc(hHeap, dwFlags, dwBytes);
    printf(" = 0x%p\n", Ret);

    Cnt++;
    return Ret;
}

SIZE_T
WtHeapCompact(HANDLE hHeap,
              DWORD dwFlags)
{
    SIZE_T              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapCompact;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapCompact = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapCompact");
    printf("HeapCompact(0x%p, %u) = %ul\n", hHeap, dwFlags);
    Ret = lpfnHeapCompact(hHeap, dwFlags);
    printf(" = %u\n", Ret);

    Cnt++;
    return Ret;
}

HANDLE
WtHeapCreate(DWORD flOptions,
             SIZE_T dwInitialSize,
             SIZE_T dwMaximumSize)
{
    HANDLE              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapCreate;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapCreate = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapCreate");
    printf("HeapCreate(%u, %llu, %llu)", flOptions, dwInitialSize, dwMaximumSize);
    Ret = lpfnHeapCreate(flOptions, dwInitialSize, dwMaximumSize);
    printf(" = 0x%p\n", Ret);

    Cnt++;
    return Ret;
}

BOOL
WtHeapDestroy(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapDestroy;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapDestroy = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapDestroy");
    printf("HeapDestroy(0x%p)", hHeap);
    Ret = lpfnHeapDestroy(hHeap);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}

BOOL
WtHeapFree(HANDLE hHeap,
           DWORD dwFlags,
           LPVOID lpMem)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapFree;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapFree = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapFree");
    printf("HeapFree(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = lpfnHeapFree(hHeap, dwFlags, lpMem);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}

BOOL
WtHeapLock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapLock;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapLock = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapLock");
    printf("HeapLock(0x%p)", hHeap);
    Ret = lpfnHeapLock(hHeap);
    printf(" = %d\n", Ret);

    Cnt++;
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
    FARPROC             lpfnHeapQueryInformation;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapQueryInformation = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapQueryInformation");
    printf("HeapQueryInformation(0x%p, %d, 0x%p, %u, 0x%p)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    Ret = lpfnHeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    printf(" = %d\n", Ret);

    Cnt++;
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
    FARPROC             lpfnHeapReAlloc;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapReAlloc = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapReAlloc");
    printf("HeapReAlloc(0x%p, %u, 0x%p, %u)", hHeap, dwFlags, lpMem, dwBytes);
    Ret = lpfnHeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
    printf(" = 0x%p\n", Ret);

    Cnt++;
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
    FARPROC             lpfnHeapSetInformation;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapSetInformation = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapSetInformation");
    printf("HeapSetInformation(0x%p, %d, 0x%p, %u)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    Ret = lpfnHeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}

SIZE_T
WtHeapSize(HANDLE hHeap,
           DWORD dwFlags,
           LPCVOID lpMem)
{
    SIZE_T              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapSize;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapSize = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapSize");
    printf("HeapSize(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = lpfnHeapSize(hHeap, dwFlags, lpMem);
    printf(" = %u\n", Ret);

    Cnt++;
    return Ret;
}

BOOL
WtHeapUnlock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapUnlock;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapUnlock = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapUnlock");
    printf("HeapUnlock(0x%p)", hHeap);
    Ret = lpfnHeapUnlock(hHeap);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}

BOOL
WtHeapValidate(HANDLE hHeap,
               DWORD dwFlags,
               LPCVOID lpMem)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapValidate;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapValidate = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapValidate");
    printf("HeapValidate(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
    Ret = lpfnHeapValidate(hHeap, dwFlags, lpMem);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}

BOOL
WtHeapWalk(HANDLE hHeap,
           LPPROCESS_HEAP_ENTRY lpEntry)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapWalk;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    lpfnHeapWalk = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapWalk");
    printf("HeapWalk(0x%p, 0x%p)", hHeap, lpEntry);
    Ret = lpfnHeapWalk(hHeap, lpEntry);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}
