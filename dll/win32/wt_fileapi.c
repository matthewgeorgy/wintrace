#include <win32/wt_fileapi.h>

extern T_WintraceOpts		*pOpts;

BOOL
WtCreateDirectoryA(
	LPCSTR lpPathName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
	BOOL Ret;

	if (BeginTrace(E_CreateDirectoryA))
	{
		WriteFuncBuffer("(\"%s\", 0x%p)", lpPathName, lpSecurityAttributes);
		Ret = CreateDirectoryA(lpPathName, lpSecurityAttributes);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_CreateDirectoryA, FALSE);
	}
	else
	{
		Ret = CreateDirectoryA(lpPathName, lpSecurityAttributes);
	}

	return (Ret);
}

BOOL
WtCreateDirectoryW(
	LPCWSTR lpPathName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes
)
{
	BOOL Ret;

	if (BeginTrace(E_CreateDirectoryW))
	{
		WriteFuncBuffer("(\"%ws\", 0x%p)", lpPathName, lpSecurityAttributes);
		Ret = CreateDirectoryW(lpPathName, lpSecurityAttributes);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_CreateDirectoryW, FALSE);
	}
	else
	{
		Ret = CreateDirectoryW(lpPathName, lpSecurityAttributes);
	}

	return (Ret);
}

HANDLE
WtCreateFileA(
	LPCSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateFileA))
	{
		WriteFuncBuffer("(\"%s\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		Ret = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateFileA, FALSE);
	}
	else
	{
		Ret = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	}

	return (Ret);
}

HANDLE
WtCreateFileW(
	LPCWSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateFileW))
	{
		WriteFuncBuffer("(\"%ws\", %u, %u, 0x%p, %u, %u, 0x%p)", lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		Ret = CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateFileW, FALSE);
	}
	else
	{
		Ret = CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	}

	return (Ret);
}

BOOL
WtDeleteFileA(
	LPCSTR lpFileName
)
{
	BOOL Ret;

	if (BeginTrace(E_DeleteFileA))
	{
		WriteFuncBuffer("(\"%s\")", lpFileName);
		Ret = DeleteFileA(lpFileName);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_DeleteFileA, FALSE);
	}
	else
	{
		Ret = DeleteFileA(lpFileName);
	}

	return (Ret);
}

BOOL
WtDeleteFileW(
	LPCWSTR lpFileName
)
{
	BOOL Ret;

	if (BeginTrace(E_DeleteFileW))
	{
		WriteFuncBuffer("(\"%ws\")", lpFileName);
		Ret = DeleteFileW(lpFileName);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_DeleteFileW, FALSE);
	}
	else
	{
		Ret = DeleteFileW(lpFileName);
	}

	return (Ret);
}

DWORD
WtGetFileSize(
	HANDLE hFile,
	LPDWORD lpFileSizeHigh
)
{
	DWORD Ret;

	if (BeginTrace(E_GetFileSize))
	{
		WriteFuncBuffer("(0x%p, 0x%p)", hFile, lpFileSizeHigh);
		Ret = GetFileSize(hFile, lpFileSizeHigh);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_GetFileSize, FALSE);
	}
	else
	{
		Ret = GetFileSize(hFile, lpFileSizeHigh);
	}

	return (Ret);
}

BOOL
WtGetFileSizeEx(
	HANDLE hFile,
	PLARGE_INTEGER lpFileSize
)
{
	BOOL Ret;

	if (BeginTrace(E_GetFileSizeEx))
	{
		WriteFuncBuffer("(0x%p, 0x%p)", hFile, lpFileSize);
		Ret = GetFileSizeEx(hFile, lpFileSize);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_GetFileSizeEx, FALSE);
	}
	else
	{
		Ret = GetFileSizeEx(hFile, lpFileSize);
	}

	return (Ret);
}

DWORD
WtGetFileType(
	HANDLE hFile
)
{
	DWORD Ret;

	if (BeginTrace(E_GetFileType))
	{
		WriteFuncBuffer("(0x%p)", hFile);
		Ret = GetFileType(hFile);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_GetFileType, FALSE);
	}
	else
	{
		Ret = GetFileType(hFile);
	}

	return (Ret);
}

BOOL
WtReadFile(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberOfBytesToRead,
	LPDWORD lpNumberOfBytesRead,
	LPOVERLAPPED lpOverlapped
)
{
	BOOL Ret;

	if (BeginTrace(E_ReadFile))
	{
		WriteFuncBuffer("(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
		Ret = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ReadFile, FALSE);
	}
	else
	{
		Ret = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
	}

	return (Ret);
}

BOOL
WtReadFileEx(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberOfBytesToRead,
	LPOVERLAPPED lpOverlapped,
	LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
	BOOL Ret;

	if (BeginTrace(E_ReadFileEx))
	{
		WriteFuncBuffer("(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
		Ret = ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ReadFileEx, FALSE);
	}
	else
	{
		Ret = ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
	}

	return (Ret);
}

BOOL
WtRemoveDirectoryA(
	LPCSTR lpPathName
)
{
	BOOL Ret;

	if (BeginTrace(E_RemoveDirectoryA))
	{
		WriteFuncBuffer("(\"%s\")", lpPathName);
		Ret = RemoveDirectoryA(lpPathName);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_RemoveDirectoryA, FALSE);
	}
	else
	{
		Ret = RemoveDirectoryA(lpPathName);
	}

	return (Ret);
}

BOOL
WtRemoveDirectoryW(
	LPCWSTR lpPathName
)
{
	BOOL Ret;

	if (BeginTrace(E_RemoveDirectoryW))
	{
		WriteFuncBuffer("(\"%ws\")", lpPathName);
		Ret = RemoveDirectoryW(lpPathName);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_RemoveDirectoryW, FALSE);
	}
	else
	{
		Ret = RemoveDirectoryW(lpPathName);
	}

	return (Ret);
}

BOOL
WtSetEndOfFile(
	HANDLE hFile
)
{
	BOOL Ret;

	if (BeginTrace(E_SetEndOfFile))
	{
		WriteFuncBuffer("(0x%p)", hFile);
		Ret = SetEndOfFile(hFile);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_SetEndOfFile, FALSE);
	}
	else
	{
		Ret = SetEndOfFile(hFile);
	}

	return (Ret);
}

DWORD
WtSetFilePointer(
	HANDLE hFile,
	LONG lDistanceToMove,
	PLONG lpDistanceToMoveHigh,
	DWORD dwMoveMethod
)
{
	DWORD Ret;

	if (BeginTrace(E_SetFilePointer))
	{
		WriteFuncBuffer("(0x%p, %d, 0x%p, %u)", hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);
		Ret = SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_SetFilePointer, FALSE);
	}
	else
	{
		Ret = SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);
	}

	return (Ret);
}

BOOL
WtSetFilePointerEx(
	HANDLE hFile,
	LARGE_INTEGER liDistanceToMove,
	PLARGE_INTEGER lpNewFilePointer,
	DWORD dwMoveMethod
)
{
	BOOL Ret;

	if (BeginTrace(E_SetFilePointerEx))
	{
		WriteFuncBuffer("(0x%p, %d, 0x%p, %u)", hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);
		Ret = SetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_SetFilePointerEx, FALSE);
	}
	else
	{
		Ret = SetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);
	}

	return (Ret);
}

BOOL
WtWriteFile(
	HANDLE hFile,
	LPCVOID lpBuffer,
	DWORD nNumberOfBytesToWrite,
	LPDWORD lpNumberOfBytesWritten,
	LPOVERLAPPED lpOverlapped
)
{
	BOOL Ret;

	if (BeginTrace(E_WriteFile))
	{
		WriteFuncBuffer("(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
		Ret = WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_WriteFile, FALSE);
	}
	else
	{
		Ret = WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
	}

	return (Ret);
}

BOOL
WtWriteFileEx(
	HANDLE hFile,
	LPCVOID lpBuffer,
	DWORD nNumberOfBytesToWrite,
	LPOVERLAPPED lpOverlapped,
	LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
	BOOL Ret;

	if (BeginTrace(E_WriteFileEx))
	{
		WriteFuncBuffer("(0x%p, 0x%p, %u, 0x%p, 0x%p)", hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);
		Ret = WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_WriteFileEx, FALSE);
	}
	else
	{
		Ret = WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine);
	}

	return (Ret);
}

