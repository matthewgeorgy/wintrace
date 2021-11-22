#include "inc/wt_fileapi.h"

extern T_WINTRACE_OPTS *pOpts;

BOOL
WtCreateDirectoryA(
  LPCSTR                lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
    BOOL		Ret;


	if (BeginTrace(E_CreateDirectoryA))
	{
		fprintf(pOpts->OutputFile, "(\"%s\", 0x%p)", lpPathName, lpSecurityAttributes);
		Ret = CreateDirectoryA(lpPathName, lpSecurityAttributes);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = CreateDirectoryA(lpPathName, lpSecurityAttributes);

    return Ret;
}

BOOL
WtCreateDirectoryW(
  LPCWSTR               lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
    BOOL		Ret;


	if (BeginTrace(E_CreateDirectoryW))
	{
		fprintf(pOpts->OutputFile, "(\"%ws\", 0x%p)", lpPathName, lpSecurityAttributes);
		Ret = CreateDirectoryW(lpPathName, lpSecurityAttributes);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = CreateDirectoryW(lpPathName, lpSecurityAttributes);

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
    HANDLE		Ret;


	if (BeginTrace(E_CreateFileA))
	{
		fprintf(pOpts->OutputFile, "(\"%s\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		Ret = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
	}
	else
		Ret = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

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
    HANDLE 		Ret;


	if (BeginTrace(E_CreateFileW))
	{
		fprintf(pOpts->OutputFile, "(\"%ws\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		Ret = CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
	}
	else
		Ret = CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

    return Ret;
}

BOOL
WtDeleteFileA(
  LPCSTR lpFileName
)
{
    BOOL		Ret;


	if (BeginTrace(E_DeleteFileA))
	{
		fprintf(pOpts->OutputFile, "(\"%s\")", lpFileName);
		Ret = DeleteFileA(lpFileName);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = DeleteFileA(lpFileName);

    return Ret;
}

BOOL
WtDeleteFileW(
  LPCWSTR lpFileName
)
{
    BOOL 		Ret;


	if (BeginTrace(E_DeleteFileW))
	{
		fprintf(pOpts->OutputFile, "(\"%ws\")", lpFileName);
		Ret = DeleteFileW(lpFileName);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = DeleteFileW(lpFileName);

    return Ret;
}

DWORD
WtGetFileSize(
  HANDLE  hFile,
  LPDWORD lpFileSizeHigh
)
{
    DWORD 		Ret;


	if (BeginTrace(E_GetFileSize))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hFile, lpFileSizeHigh);
		Ret = GetFileSize(hFile, lpFileSizeHigh);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
	}
	else
		Ret = GetFileSize(hFile, lpFileSizeHigh);

    return Ret;
}

BOOL
WtGetFileSizeEx(
  HANDLE         hFile,
  PLARGE_INTEGER lpFileSize
)
{
    BOOL 		Ret;


	if (BeginTrace(E_GetFileSizeEx))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hFile, lpFileSize);
		Ret = GetFileSizeEx(hFile, lpFileSize);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
	}
	else
		Ret = GetFileSizeEx(hFile, lpFileSize);

    return Ret;
}

DWORD
WtGetFileType(
  HANDLE hFile
)
{
    DWORD 		Ret;


	if (BeginTrace(E_GetFileType))
	{
		fprintf(pOpts->OutputFile, "(0x%p)", hFile);
		Ret = GetFileType(hFile);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
	}
	else
		Ret = GetFileType(hFile);

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
    BOOL 		Ret;


	if (BeginTrace(E_ReadFile))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
				nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
		Ret = ReadFile(hFile, lpBuffer,
				nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);

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
    BOOL 		Ret;


	if (BeginTrace(E_ReadFileEx))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
				nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
		Ret = ReadFileEx(hFile, lpBuffer,
				nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);

    return Ret;
}

BOOL
WtRemoveDirectoryA(
  LPCSTR lpPathName
)
{
    BOOL 		Ret;


	if (BeginTrace(E_RemoveDirectoryA))
	{
		fprintf(pOpts->OutputFile, "(\"%s\")",
				lpPathName);
		Ret = RemoveDirectoryA(lpPathName);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = RemoveDirectoryA(lpPathName);

    return Ret;
}

BOOL
WtRemoveDirectoryW(
  LPCWSTR lpPathName
)
{
    BOOL 		Ret;


	if (BeginTrace(E_RemoveDirectoryW))
	{
		fprintf(pOpts->OutputFile, "(\"%ws\")",
				lpPathName);
		Ret = RemoveDirectoryW(lpPathName);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = RemoveDirectoryW(lpPathName);

    return Ret;
}

BOOL
WtSetEndOfFile(
  HANDLE hFile
)
{
    BOOL 		Ret;


	if (BeginTrace(E_SetEndOfFile))
	{
		fprintf(pOpts->OutputFile, "(0x%p)", hFile);
		Ret = SetEndOfFile(hFile);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = SetEndOfFile(hFile);

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
    DWORD 		Ret;


	if (BeginTrace(E_SetFilePointer))
	{
		fprintf(pOpts->OutputFile, "(0x%p, %d, 0x%p, %u)", hFile, lDistanceToMove,
				lpDistanceToMoveHigh, dwMoveMethod);
		Ret = SetFilePointer(hFile, lDistanceToMove,
				lpDistanceToMoveHigh, dwMoveMethod);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
	}
	else
		Ret = SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);

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
    DWORD		Ret;


	if (BeginTrace(E_SetFilePointerEx))
	{
		fprintf(pOpts->OutputFile, "(0x%p, %d, 0x%p, %u)", hFile, liDistanceToMove,
				lpNewFilePointer, dwMoveMethod);
		Ret = SetFilePointerEx(hFile, liDistanceToMove,
				lpNewFilePointer, dwMoveMethod);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
	}
	else
		Ret = SetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);

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
    BOOL		Ret;


	if (BeginTrace(E_WriteFile))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
				nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
		Ret = WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite,
				lpNumberOfBytesWritten, lpOverlapped);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);

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
    BOOL		Ret;


	if (BeginTrace(E_WriteFileEx))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer,
				nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);
		Ret = WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite,
				lpOverlapped, lpCompletionRoutine);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);

    return Ret;
}

