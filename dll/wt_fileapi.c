#include "inc/wt_fileapi.h"

extern T_WINTRACE_OPTS *pOpts;

BOOL
WtCreateDirectoryA(
  LPCSTR                lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateDirectoryA(\"%s\", 0x%p)", lpPathName, lpSecurityAttributes);
    Ret = CreateDirectoryA(lpPathName, lpSecurityAttributes);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtCreateDirectoryW(
  LPCWSTR               lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateDirectoryW(\"%ws\", 0x%p)", lpPathName, lpSecurityAttributes);
    Ret = CreateDirectoryW(lpPathName, lpSecurityAttributes);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

HANDLE
WtCreateFileA(LPCSTR lpFileName,
              DWORD dwDesiredAccess,
              DWORD dwShareMode,
              LPSECURITY_ATTRIBUTES lpSecurityAttributes,
              DWORD dwCreationDisposition,
              DWORD dwFlagsAndAttributes,
              HANDLE hTemplateFile)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateFileA(\"%s\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    Ret = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

HANDLE
WtCreateFileW(LPCWSTR lpFileName,
              DWORD dwDesiredAccess,
              DWORD dwShareMode,
              LPSECURITY_ATTRIBUTES lpSecurityAttributes,
              DWORD dwCreationDisposition,
              DWORD dwFlagsAndAttributes,
              HANDLE hTemplateFile)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateFileW(\"%ws\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    Ret = CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtDeleteFileA(
  LPCSTR lpFileName
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DeleteFileA(\"%s\")", lpFileName);
    Ret = DeleteFileA(lpFileName);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtDeleteFileW(
  LPCWSTR lpFileName
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DeleteFileW(\"%ws\")", lpFileName);
    Ret = DeleteFileW(lpFileName);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

DWORD
WtGetFileSize(
  HANDLE  hFile,
  LPDWORD lpFileSizeHigh
)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetFileSize(0x%p, 0x%p)", hFile, lpFileSizeHigh);
    Ret = GetFileSize(hFile, lpFileSizeHigh);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

BOOL
WtGetFileSizeEx(
  HANDLE         hFile,
  PLARGE_INTEGER lpFileSize
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetFileSizeEx(0x%p, 0x%p)", hFile, lpFileSize);
    Ret = GetFileSizeEx(hFile, lpFileSize);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

DWORD
WtGetFileType(
  HANDLE hFile
)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetFileType(0x%p)", hFile);
    Ret = GetFileType(hFile);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

BOOL
WtReadFile(
  HANDLE       hFile,
  LPVOID       lpBuffer,
  DWORD        nNumberOfBytesToRead,
  LPDWORD      lpNumberOfBytesRead,
  LPOVERLAPPED lpOverlapped
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ReadFile(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    Ret = ReadFile(hFile, lpBuffer,
            nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtReadFileEx(
  HANDLE                          hFile,
  LPVOID                          lpBuffer,
  DWORD                           nNumberOfBytesToRead,
  LPOVERLAPPED                    lpOverlapped,
  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ReadFileEx(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
    Ret = ReadFileEx(hFile, lpBuffer,
            nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtSetEndOfFile(
  HANDLE hFile
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "SetEndOfFile(0x%p)", hFile);
    Ret = SetEndOfFile(hFile);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

DWORD
WtSetFilePointer(
  HANDLE hFile,
  LONG   lDistanceToMove,
  PLONG  lpDistanceToMoveHigh,
  DWORD  dwMoveMethod
)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "SetFilePointer(0x%p, %d, 0x%p, %u)", hFile, lDistanceToMove,
            lpDistanceToMoveHigh, dwMoveMethod);
    Ret = SetFilePointer(hFile, lDistanceToMove,
            lpDistanceToMoveHigh, dwMoveMethod);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

BOOL
WtSetFilePointerEx(
  HANDLE         hFile,
  LARGE_INTEGER  liDistanceToMove,
  PLARGE_INTEGER lpNewFilePointer,
  DWORD          dwMoveMethod
)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "SetFilePointerEx(0x%p, %d, 0x%p, %u)", hFile, liDistanceToMove,
            lpNewFilePointer, dwMoveMethod);
    Ret = SetFilePointerEx(hFile, liDistanceToMove,
            lpNewFilePointer, dwMoveMethod);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

BOOL
WtWriteFile(
  HANDLE       hFile,
  LPCVOID      lpBuffer,
  DWORD        nNumberOfBytesToWrite,
  LPDWORD      lpNumberOfBytesWritten,
  LPOVERLAPPED lpOverlapped
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "WriteFile(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
    Ret = WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite,
            lpNumberOfBytesWritten, lpOverlapped);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtWriteFileEx(
  HANDLE                          hFile,
  LPCVOID                         lpBuffer,
  DWORD                           nNumberOfBytesToWrite,
  LPOVERLAPPED                    lpOverlapped,
  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "WriteFileEx(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);
    Ret = WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite,
            lpOverlapped, lpCompletionRoutine);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

