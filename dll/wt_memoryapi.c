#include "inc/wt_memoryapi.h"

extern T_WintraceOpts      *pOpts;

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
    HANDLE      Ret;


    if (BeginTrace(E_CreateFileMappingA))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %u, %u, %u, \"%s\")",
                hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
        Ret = CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateFileMappingA, Ret == NULL);
    }
    else
        Ret = CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);

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
    HANDLE      Ret;


    if (BeginTrace(E_CreateFileMappingW))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %u, %u, %u, \"%ws\")",
                hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
        Ret = CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateFileMappingW, Ret == NULL);
    }
    else
        Ret = CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);

    return Ret;
}

BOOL
WtFlushViewOfFile(
  LPCVOID lpBaseAddress,
  SIZE_T  dwNumberOfBytesToFlush
)
{
    BOOL        Ret;


    if (BeginTrace(E_FlushViewOfFile))
    {
        WriteFuncBuffer("(0x%p, %llu)",
                lpBaseAddress, dwNumberOfBytesToFlush);
        Ret = FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_FlushViewOfFile, Ret == FALSE);
    }
    else
        Ret = FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush);

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
    LPVOID      Ret;


    if (BeginTrace(E_MapViewOfFile))
    {
        WriteFuncBuffer("(0x%p, %u, %u, %u, %llu)",
                hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap);
        Ret = MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_MapViewOfFile, Ret == NULL);
    }
    else
        Ret = MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap);

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
    LPVOID      Ret;


    if (BeginTrace(E_MapViewOfFileEx))
    {
        WriteFuncBuffer("(0x%p, %u, %u, %u, %llu, 0x%p)",
                hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);
        Ret = MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_MapViewOfFileEx, Ret == NULL);
    }
    else
        Ret = MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);

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
    HANDLE      Ret;


    if (BeginTrace(E_OpenFileMappingA))
    {
        WriteFuncBuffer("(%u, %d, \"%s\")",
                dwDesiredAccess, bInheritHandle, lpName);
        Ret = OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_OpenFileMappingA, Ret == NULL);
    }
    else
        Ret = OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName);

    return Ret;
}

HANDLE
WtOpenFileMappingW(
  DWORD   dwDesiredAccess,
  BOOL    bInheritHandle,
  LPCWSTR lpName
)
{
    HANDLE          Ret;


    if (BeginTrace(E_OpenFileMappingW))
    {
        WriteFuncBuffer("(%u, %d, \"%ws\")",
                dwDesiredAccess, bInheritHandle, lpName);
        Ret = OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_OpenFileMappingW, Ret == NULL);
    }
    else
        Ret = OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName);

    return Ret;
}

BOOL
WtUnmapViewOfFile(
  LPCVOID lpBaseAddress
)
{
    BOOL        Ret;


    if (BeginTrace(E_UnmapViewOfFile))
    {
        WriteFuncBuffer("(0x%p)",
            lpBaseAddress);
        Ret = UnmapViewOfFile(lpBaseAddress);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_UnmapViewOfFile, Ret == FALSE);
    }
    else
        Ret = UnmapViewOfFile(lpBaseAddress);

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
/*     WriteFuncBuffer("UnmapViewOfFileEx(0x%p, %u)", */
/*         BaseAddress, UnmapFlags); */
/*     Ret = UnmapViewOfFileEx(BaseAddress, UnmapFlags); */
/*     WriteFuncBuffer(" = %d", Ret); */

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
    LPVOID      Ret;


    if (BeginTrace(E_VirtualAlloc))
    {
        WriteFuncBuffer("(0x%p, %llu, %u, %u)",
                lpAddress, dwSize, flAllocationType, flProtect);
        Ret = VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_VirtualAlloc, Ret == NULL);
    }
    else
        Ret = VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);

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
    LPVOID      Ret;


    if (BeginTrace(E_VirtualAllocEx))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %llu, %u, %u)",
                hProcess, lpAddress, dwSize, flAllocationType, flProtect);
        Ret = VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_VirtualAllocEx, Ret == NULL);
    }
    else
        Ret = VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect);

    return Ret;
}

BOOL
WtVirtualFree(
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD  dwFreeType
)
{
    BOOL        Ret;


    if (BeginTrace(E_VirtualFree))
    {
        WriteFuncBuffer("(0x%p, %llu, %u)",
                lpAddress, dwSize, dwFreeType);
        Ret = VirtualFree(lpAddress, dwSize, dwFreeType);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_VirtualFree, Ret == FALSE);
    }
    else
        Ret = VirtualFree(lpAddress, dwSize, dwFreeType);

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
    BOOL        Ret;


    if (BeginTrace(E_VirtualFreeEx))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %llu, %u)",
                hProcess, lpAddress, dwSize, dwFreeType);
        Ret = VirtualFreeEx(hProcess, lpAddress, dwSize, dwFreeType);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_VirtualFreeEx, Ret == FALSE);
    }
    else
        Ret = VirtualFreeEx(hProcess, lpAddress, dwSize, dwFreeType);

    return Ret;
}

BOOL
WtVirtualLock(
  LPVOID lpAddress,
  SIZE_T dwSize
)
{
    BOOL        Ret;


    if (BeginTrace(E_VirtualLock))
    {
        WriteFuncBuffer("(0x%p, %llu)",
                lpAddress, dwSize);
        Ret = VirtualLock(lpAddress, dwSize);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_VirtualLock, Ret == FALSE);
    }
    else
        Ret = VirtualLock(lpAddress, dwSize);

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
    BOOL        Ret;


    if (BeginTrace(E_VirtualProtect))
    {
        WriteFuncBuffer("(0x%p, %llu, %u, 0x%p)",
                lpAddress, dwSize, flNewProtect, lpflOldProtect);
        Ret = VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_VirtualProtect, Ret == FALSE);
    }
    else
        Ret = VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);

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
    BOOL        Ret;


    if (BeginTrace(E_VirtualProtectEx))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %llu, %u, 0x%p)",
                hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect);
        Ret = VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_VirtualProtectEx, Ret == FALSE);
    }
    else
        Ret = VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect);

    return Ret;
}

SIZE_T
WtVirtualQuery(
  LPCVOID                   lpAddress,
  PMEMORY_BASIC_INFORMATION lpBuffer,
  SIZE_T                    dwLength
)
{
    SIZE_T      Ret;


    if (BeginTrace(E_VirtualQuery))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %llu)",
                lpAddress, lpBuffer, dwLength);
        Ret = VirtualQuery(lpAddress, lpBuffer, dwLength);
        WriteFuncBuffer(" = %llu", Ret);
        EndTrace(E_VirtualQuery, Ret == 0);
    }
    else
        Ret = VirtualQuery(lpAddress, lpBuffer, dwLength);

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
    SIZE_T      Ret;


    if (BeginTrace(E_VirtualQueryEx))
    {
        WriteFuncBuffer("(0x%p, 0x%p, 0x%p, %llu)",
                hProcess, lpAddress, lpBuffer, dwLength);
        Ret = VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength);
        WriteFuncBuffer(" = %llu", Ret);
        EndTrace(E_VirtualQueryEx, Ret == 0);
    }
    else
        Ret = VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength);

    return Ret;
}

BOOL
WtVirtualUnlock(
  LPVOID lpAddress,
  SIZE_T dwSize
)
{
    BOOL        Ret;


    if (BeginTrace(E_VirtualUnlock))
    {
        WriteFuncBuffer("(0x%p, %llu)",
                lpAddress, dwSize);
        Ret = VirtualUnlock(lpAddress, dwSize);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_VirtualUnlock, Ret == FALSE);
    }
    else
        Ret = VirtualUnlock(lpAddress, dwSize);

    return Ret;
}

