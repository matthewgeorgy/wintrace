#include "inc/wt_memoryapi.h"

extern T_WINTRACE_OPTS      *pOpts;

// Actually belongs in winbase.h but this location is more appropriate
HANDLE
WtCreateFileMappingA(
  HANDLE                hFile,
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  DWORD                 flProtect,
  DWORD                 dwMaximumSizeHigh,
  DWORD                 dwMaximumSizeLow,
  LPCSTR                lpName
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateFileMappingA(0x%p, 0x%p, %u, %u, %u, \"%s\")",
            hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
    Ret = CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

HANDLE
WtCreateFileMappingW(
  HANDLE                hFile,
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  DWORD                 flProtect,
  DWORD                 dwMaximumSizeHigh,
  DWORD                 dwMaximumSizeLow,
  LPCWSTR               lpName
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateFileMappingW(0x%p, 0x%p, %u, %u, %u, \"%ws\")",
            hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
    Ret = CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtFlushViewOfFile(
  LPCVOID lpBaseAddress,
  SIZE_T  dwNumberOfBytesToFlush
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "FlushViewOfFile(0x%p, %llu)",
            lpBaseAddress, dwNumberOfBytesToFlush);
    Ret = FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

LPVOID
WtMapViewOfFile(
  HANDLE hFileMappingObject,
  DWORD  dwDesiredAccess,
  DWORD  dwFileOffsetHigh,
  DWORD  dwFileOffsetLow,
  SIZE_T dwNumberOfBytesToMap
)
{
    LPVOID              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "MapViewOfFile(0x%p, %u, %u, %u, %llu)",
            hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap);
    Ret = MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

LPVOID
WtMapViewOfFileEx(
  HANDLE hFileMappingObject,
  DWORD  dwDesiredAccess,
  DWORD  dwFileOffsetHigh,
  DWORD  dwFileOffsetLow,
  SIZE_T dwNumberOfBytesToMap,
  LPVOID lpBaseAddress
)
{
    LPVOID              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "MapViewOfFileEx(0x%p, %u, %u, %u, %llu, 0x%p)",
            hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);
    Ret = MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

// Same story this is a better location IMO
HANDLE
WtOpenFileMappingA(
  DWORD   dwDesiredAccess,
  BOOL    bInheritHandle,
  LPCSTR lpName
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "OpenFileMappingA(%u, %d, \"%s\")",
            dwDesiredAccess, bInheritHandle, lpName);
    Ret = OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

HANDLE
WtOpenFileMappingW(
  DWORD   dwDesiredAccess,
  BOOL    bInheritHandle,
  LPCWSTR lpName
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "OpenFileMappingW(%u, %d, \"%ws\")",
            dwDesiredAccess, bInheritHandle, lpName);
    Ret = OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);


    return Ret;
}

BOOL
WtUnmapViewOfFile(
  LPCVOID lpBaseAddress
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "UnmapViewOfFile(0x%p)",
        lpBaseAddress);
    Ret = UnmapViewOfFile(lpBaseAddress);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

// Win8
/* BOOL */
/* WtUnmapViewOfFileEx( */
/*   PVOID BaseAddress, */
/*   ULONG UnmapFlags */
/* ) */
/* { */
/*     BOOL                Ret; */
/*     static DWORD        Cnt; */


/*     ShowDetails(pOpts, ++Cnt); */
/*     fprintf(pOpts->OutputFile, "UnmapViewOfFileEx(0x%p, %u)", */
/*         BaseAddress, UnmapFlags); */
/*     Ret = UnmapViewOfFileEx(BaseAddress, UnmapFlags); */
/*     fprintf(pOpts->OutputFile, " = %d\n", Ret); */

/*     return Ret; */
/* } */

LPVOID
WtVirtualAlloc(
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  flAllocationType,
  DWORD  flProtect
)
{
    LPVOID              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualAlloc(0x%p, %llu, %u, %u)",
            lpAddress, dwSize, flAllocationType, flProtect);
    Ret = VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

LPVOID
WtVirtualAllocEx(
  HANDLE hProcess,
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  flAllocationType,
  DWORD  flProtect
)
{
    LPVOID              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualAllocEx(0x%p, 0x%p, %llu, %u, %u)",
            hProcess, lpAddress, dwSize, flAllocationType, flProtect);
    Ret = VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtVirtualFree(
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  dwFreeType
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualFree(0x%p, %llu, %u)",
            lpAddress, dwSize, dwFreeType);
    Ret = VirtualFree(lpAddress, dwSize, dwFreeType);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtVirtualFreeEx(
  HANDLE hProcess,
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  dwFreeType
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualFreeEx(0x%p, 0x%p, %llu, %u)",
            hProcess, lpAddress, dwSize, dwFreeType);
    Ret = VirtualFreeEx(hProcess, lpAddress, dwSize, dwFreeType);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtVirtualLock(
  LPVOID lpAddress,
  SIZE_T dwSize
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualLock(0x%p, %llu)",
            lpAddress, dwSize);
    Ret = VirtualLock(lpAddress, dwSize);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtVirtualProtect(
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  flNewProtect,
  PDWORD lpflOldProtect
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualProtect(0x%p, %llu, %u, 0x%p)",
            lpAddress, dwSize, flNewProtect, lpflOldProtect);
    Ret = VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtVirtualProtectEx(
  HANDLE hProcess,
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  flNewProtect,
  PDWORD lpflOldProtect
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualProtectEx(0x%p, 0x%p, %llu, %u, 0x%p)",
            hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect);
    Ret = VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

SIZE_T
WtVirtualQuery(
  LPCVOID                   lpAddress,
  PMEMORY_BASIC_INFORMATION lpBuffer,
  SIZE_T                    dwLength
)
{
    SIZE_T              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualQuery(0x%p, 0x%p, %llu)",
            lpAddress, lpBuffer, dwLength);
    Ret = VirtualQuery(lpAddress, lpBuffer, dwLength);
    fprintf(pOpts->OutputFile, " = %llu", Ret);

    return Ret;
}

SIZE_T
WtVirtualQueryEx(
  HANDLE                    hProcess,
  LPCVOID                   lpAddress,
  PMEMORY_BASIC_INFORMATION lpBuffer,
  SIZE_T                    dwLength
)
{
    SIZE_T              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualQueryEx(0x%p, 0x%p, 0x%p, %llu)",
            hProcess, lpAddress, lpBuffer, dwLength);
    Ret = VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength);
    fprintf(pOpts->OutputFile, " = %llu", Ret);

    return Ret;
}

BOOL
WtVirtualUnlock(
  LPVOID lpAddress,
  SIZE_T dwSize
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "VirtualUnlock(0x%p, %llu)",
            lpAddress, dwSize);
    Ret = VirtualUnlock(lpAddress, dwSize);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

