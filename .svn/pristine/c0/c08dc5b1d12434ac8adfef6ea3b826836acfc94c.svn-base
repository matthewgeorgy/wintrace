#include <stdio.h>
#include "wt_heapapi.h"

HANDLE
WtGetProcessHeap()
{
    HANDLE              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnGetProcessHeap;


    lpfnGetProcessHeap = GetProcAddress(GetModuleHandle("Kernel32.dll"), "GetProcessHeap");
    printf("[%u] GetProcessHeap()", Cnt++);
    Ret = lpfnGetProcessHeap();
    printf(" = 0x%p\n", Ret);

    return Ret;
}

DWORD
WtGetProcessHeaps(DWORD NumberOfHeaps,
                  PHANDLE ProcessHeaps)
{
    DWORD               Ret;
    static DWORD        Cnt;
    FARPROC             lpfnGetProcessHeaps;


    lpfnGetProcessHeaps = GetProcAddress(GetModuleHandle("Kernel32.dll"), "GetProcessHeaps");
    printf("[%u] GetProcessHeaps(%u, 0x%p)", Cnt++, NumberOfHeaps, ProcessHeaps);
    Ret = lpfnGetProcessHeaps(NumberOfHeaps, ProcessHeaps);
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
    FARPROC             lpfnHeapAlloc;


    lpfnHeapAlloc = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapAlloc");
    printf("[%u] HeapAlloc(0x%p, %u, %llu)", Cnt++, hHeap, dwFlags, dwBytes);
    Ret = lpfnHeapAlloc(hHeap, dwFlags, dwBytes);
    printf(" = 0x%p\n", Ret);

    return Ret;
}

SIZE_T
WtHeapCompact(HANDLE hHeap,
              DWORD dwFlags)
{
    SIZE_T              Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapCompact;


    lpfnHeapCompact = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapCompact");
    printf("[%u] HeapCompact(0x%p, %u) = %ul\n", Cnt++, hHeap, dwFlags);
    Ret = lpfnHeapCompact(hHeap, dwFlags);
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
    FARPROC             lpfnHeapCreate;


    lpfnHeapCreate = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapCreate");
    printf("[%u] HeapCreate(%u, %llu, %llu)", Cnt++, flOptions, dwInitialSize, dwMaximumSize);
    Ret = lpfnHeapCreate(flOptions, dwInitialSize, dwMaximumSize);
    printf(" = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtHeapDestroy(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapDestroy;


    lpfnHeapDestroy = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapDestroy");
    printf("[%u] HeapDestroy(0x%p)", Cnt++, hHeap);
    Ret = lpfnHeapDestroy(hHeap);
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
    FARPROC             lpfnHeapFree;


    lpfnHeapFree = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapFree");
    printf("[%u] HeapFree(0x%p, %u, 0x%p)", Cnt++, hHeap, dwFlags, lpMem);
    Ret = lpfnHeapFree(hHeap, dwFlags, lpMem);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapLock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapLock;


    lpfnHeapLock = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapLock");
    printf("[%u] HeapLock(0x%p)", Cnt++, hHeap);
    Ret = lpfnHeapLock(hHeap);
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
    FARPROC             lpfnHeapQueryInformation;


    lpfnHeapQueryInformation = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapQueryInformation");
    printf("[%u] HeapQueryInformation(0x%p, %d, 0x%p, %u, 0x%p)", Cnt++, HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
    Ret = lpfnHeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength);
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
    FARPROC             lpfnHeapReAlloc;


    lpfnHeapReAlloc = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapReAlloc");
    printf("[%u] HeapReAlloc(0x%p, %u, 0x%p, %u)", Cnt++, hHeap, dwFlags, lpMem, dwBytes);
    Ret = lpfnHeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
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
    FARPROC             lpfnHeapSetInformation;


    lpfnHeapSetInformation = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapSetInformation");
    printf("[%u] HeapSetInformation(0x%p, %d, 0x%p, %u)", Cnt++, HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
    Ret = lpfnHeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
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
    FARPROC             lpfnHeapSize;


    lpfnHeapSize = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapSize");
    printf("[%u] HeapSize(0x%p, %u, 0x%p)", Cnt++, hHeap, dwFlags, lpMem);
    Ret = lpfnHeapSize(hHeap, dwFlags, lpMem);
    printf(" = %u\n", Ret);

    return Ret;
}

BOOL
WtHeapUnlock(HANDLE hHeap)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapUnlock;


    lpfnHeapUnlock = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapUnlock");
    printf("[%u] HeapUnlock(0x%p)", Cnt++, hHeap);
    Ret = lpfnHeapUnlock(hHeap);
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
    FARPROC             lpfnHeapValidate;


    lpfnHeapValidate = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapValidate");
    printf("[%u] HeapValidate(0x%p, %u, 0x%p)", Cnt++, hHeap, dwFlags, lpMem);
    Ret = lpfnHeapValidate(hHeap, dwFlags, lpMem);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtHeapWalk(HANDLE hHeap,
           LPPROCESS_HEAP_ENTRY lpEntry)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnHeapWalk;


    lpfnHeapWalk = GetProcAddress(GetModuleHandle("Kernel32.dll"), "HeapWalk");
    printf("[%u] HeapWalk(0x%p, 0x%p)", Cnt++, hHeap, lpEntry);
    Ret = lpfnHeapWalk(hHeap, lpEntry);
    printf(" = %d\n", Ret);

    return Ret;
}
