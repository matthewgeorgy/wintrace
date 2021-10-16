#include "inc/wt_fileapi.h"

extern T_WINTRACEOPTS *pOpts;

BOOL
WtCreateDirectoryA(
  LPCSTR                lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateDirectoryA(\"%s\", 0x%p)", lpPathName, lpSecurityAttributes);
    Ret = CreateDirectoryA(lpPathName, lpSecurityAttributes);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "CreateDirectoryW(\"%ws\", 0x%p)", lpPathName, lpSecurityAttributes);
    Ret = CreateDirectoryW(lpPathName, lpSecurityAttributes);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "CreateFileA(\"%s\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    Ret = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    fprintf(stderr, " = 0x%p\n", Ret);

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
    fprintf(stderr, "CreateFileW(\"%ws\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    Ret = CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    fprintf(stderr, " = 0x%p\n", Ret);

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
    fprintf(stderr, "DeleteFileA(\"%s\")", lpFileName);
    Ret = DeleteFileA(lpFileName);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "DeleteFileW(\"%ws\")", lpFileName);
    Ret = DeleteFileW(lpFileName);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "GetFileSize(0x%p, 0x%p)", hFile, lpFileSizeHigh);
    Ret = GetFileSize(hFile, lpFileSizeHigh);
    fprintf(stderr, " = %u\n", Ret);

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
    fprintf(stderr, "GetFileSizeEx(0x%p, 0x%p)", hFile, lpFileSize);
    Ret = GetFileSizeEx(hFile, lpFileSize);
    fprintf(stderr, " = %u\n", Ret);

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
    fprintf(stderr, "GetFileType(0x%p)", hFile);
    Ret = GetFileType(hFile);
    fprintf(stderr, " = %u\n", Ret);

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
    fprintf(stderr, "ReadFile(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    Ret = ReadFile(hFile, lpBuffer,
            nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "ReadFileEx(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
    Ret = ReadFileEx(hFile, lpBuffer,
            nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "SetEndOfFile(0x%p)", hFile);
    Ret = SetEndOfFile(hFile);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "SetFilePointer(0x%p, %d, 0x%p, %u)", hFile, lDistanceToMove,
            lpDistanceToMoveHigh, dwMoveMethod);
    Ret = SetFilePointer(hFile, lDistanceToMove,
            lpDistanceToMoveHigh, dwMoveMethod);
    fprintf(stderr, " = %u\n", Ret);

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
    fprintf(stderr, "SetFilePointerEx(0x%p, %d, 0x%p, %u)", hFile, liDistanceToMove,
            lpNewFilePointer, dwMoveMethod);
    Ret = SetFilePointerEx(hFile, liDistanceToMove,
            lpNewFilePointer, dwMoveMethod);
    fprintf(stderr, " = %u\n", Ret);

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
    fprintf(stderr, "WriteFile(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
    Ret = WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite,
            lpNumberOfBytesWritten, lpOverlapped);
    fprintf(stderr, " = %d\n", Ret);

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
    fprintf(stderr, "WriteFileEx(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
            nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);
    Ret = WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite,
            lpOverlapped, lpCompletionRoutine);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}

