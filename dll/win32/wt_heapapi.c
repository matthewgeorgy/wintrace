#include <win32/wt_heapapi.h>

extern T_WintraceOpts		*pOpts;

HANDLE
WtGetProcessHeap()
{
	HANDLE Ret;

	if (BeginTrace(E_GetProcessHeap))
	{
		WriteFuncBuffer("()");
		Ret = GetProcessHeap();
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_GetProcessHeap, FALSE);
	}
	else
	{
		Ret = GetProcessHeap();
	}

	return (Ret);
}

DWORD
WtGetProcessHeaps(
	DWORD NumberOfHeaps,
	PHANDLE ProcessHeaps
)
{
	DWORD Ret;

	if (BeginTrace(E_GetProcessHeaps))
	{
		WriteFuncBuffer("(%u, 0x%p)", NumberOfHeaps, ProcessHeaps);
		Ret = GetProcessHeaps(NumberOfHeaps, ProcessHeaps);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_GetProcessHeaps, FALSE);
	}
	else
	{
		Ret = GetProcessHeaps(NumberOfHeaps, ProcessHeaps);
	}

	return (Ret);
}

LPVOID
WtHeapAlloc(
	HANDLE hHeap,
	DWORD dwFlags,
	SIZE_T dwBytes
)
{
	LPVOID Ret;

	if (BeginTrace(E_HeapAlloc))
	{
		WriteFuncBuffer("(0x%p, %u, %llu)", hHeap, dwFlags, dwBytes);
		Ret = HeapAlloc(hHeap, dwFlags, dwBytes);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_HeapAlloc, FALSE);
	}
	else
	{
		Ret = HeapAlloc(hHeap, dwFlags, dwBytes);
	}

	return (Ret);
}

SIZE_T
WtHeapCompact(
	HANDLE hHeap,
	DWORD dwFlags
)
{
	SIZE_T Ret;

	if (BeginTrace(E_HeapCompact))
	{
		WriteFuncBuffer("(0x%p, %u)", hHeap, dwFlags);
		Ret = HeapCompact(hHeap, dwFlags);
		WriteFuncBuffer(" = %llu", Ret);
		EndTrace(E_HeapCompact, FALSE);
	}
	else
	{
		Ret = HeapCompact(hHeap, dwFlags);
	}

	return (Ret);
}

HANDLE
WtHeapCreate(
	DWORD flOptions,
	SIZE_T dwInitialSize,
	SIZE_T dwMaximumSize
)
{
	HANDLE Ret;

	if (BeginTrace(E_HeapCreate))
	{
		WriteFuncBuffer("(%u, %llu, %llu)", flOptions, dwInitialSize, dwMaximumSize);
		Ret = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_HeapCreate, FALSE);
	}
	else
	{
		Ret = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
	}

	return (Ret);
}

BOOL
WtHeapDestroy(
	HANDLE hHeap
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapDestroy))
	{
		WriteFuncBuffer("(0x%p)", hHeap);
		Ret = HeapDestroy(hHeap);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapDestroy, FALSE);
	}
	else
	{
		Ret = HeapDestroy(hHeap);
	}

	return (Ret);
}

BOOL
WtHeapFree(
	HANDLE hHeap,
	DWORD dwFlags,
	LPVOID lpMem
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapFree))
	{
		WriteFuncBuffer("(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
		Ret = HeapFree(hHeap, dwFlags, lpMem);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapFree, FALSE);
	}
	else
	{
		Ret = HeapFree(hHeap, dwFlags, lpMem);
	}

	return (Ret);
}

BOOL
WtHeapLock(
	HANDLE hHeap
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapLock))
	{
		WriteFuncBuffer("(0x%p)", hHeap);
		Ret = HeapLock(hHeap);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapLock, FALSE);
	}
	else
	{
		Ret = HeapLock(hHeap);
	}

	return (Ret);
}

BOOL
WtHeapQueryInformation(
	HANDLE HeapHandle,
	HEAP_INFORMATION_CLASS HeapInformationClass,
	PVOID HeapInformation,
	SIZE_T HeapInformationLength,
	PSIZE_T  ReturnLength
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapQueryInformation))
	{
		WriteFuncBuffer("(0x%p, %d, 0x%p, %llu, 0x%p)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength,  ReturnLength);
		Ret = HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength,  ReturnLength);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapQueryInformation, FALSE);
	}
	else
	{
		Ret = HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength,  ReturnLength);
	}

	return (Ret);
}

LPVOID
WtHeapReAlloc(
	HANDLE hHeap,
	DWORD dwFlags,
	LPVOID lpMem,
	SIZE_T dwBytes
)
{
	LPVOID Ret;

	if (BeginTrace(E_HeapReAlloc))
	{
		WriteFuncBuffer("(0x%p, %u, 0x%p, %llu)", hHeap, dwFlags, lpMem, dwBytes);
		Ret = HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_HeapReAlloc, FALSE);
	}
	else
	{
		Ret = HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
	}

	return (Ret);
}

BOOL
WtHeapSetInformation(
	HANDLE HeapHandle,
	HEAP_INFORMATION_CLASS HeapInformationClass,
	PVOID HeapInformation,
	SIZE_T HeapInformationLength
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapSetInformation))
	{
		WriteFuncBuffer("(0x%p, %d, 0x%p, %llu)", HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
		Ret = HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapSetInformation, FALSE);
	}
	else
	{
		Ret = HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength);
	}

	return (Ret);
}

SIZE_T
WtHeapSize(
	HANDLE hHeap,
	DWORD dwFlags,
	LPCVOID lpMem
)
{
	SIZE_T Ret;

	if (BeginTrace(E_HeapSize))
	{
		WriteFuncBuffer("(0x%p, %u, 0x%p)", hHeap, dwFlags, lpMem);
		Ret = HeapSize(hHeap, dwFlags, lpMem);
		WriteFuncBuffer(" = %llu", Ret);
		EndTrace(E_HeapSize, FALSE);
	}
	else
	{
		Ret = HeapSize(hHeap, dwFlags, lpMem);
	}

	return (Ret);
}

BOOL
WtHeapUnlock(
	HANDLE hHeap
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapUnlock))
	{
		WriteFuncBuffer("(0x%p)", hHeap);
		Ret = HeapUnlock(hHeap);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapUnlock, FALSE);
	}
	else
	{
		Ret = HeapUnlock(hHeap);
	}

	return (Ret);
}

BOOL
WtHeapValidate(
	HANDLE  hHeap,
	DWORD dwFlags,
	LPCVOID lpMem
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapValidate))
	{
		WriteFuncBuffer("(0x%p, %u, 0x%p)",  hHeap, dwFlags, lpMem);
		Ret = HeapValidate( hHeap, dwFlags, lpMem);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapValidate, FALSE);
	}
	else
	{
		Ret = HeapValidate( hHeap, dwFlags, lpMem);
	}

	return (Ret);
}

BOOL
WtHeapWalk(
	HANDLE hHeap,
	LPPROCESS_HEAP_ENTRY lpEntry
)
{
	BOOL Ret;

	if (BeginTrace(E_HeapWalk))
	{
		WriteFuncBuffer("(0x%p, 0x%p)", hHeap, lpEntry);
		Ret = HeapWalk(hHeap, lpEntry);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_HeapWalk, FALSE);
	}
	else
	{
		Ret = HeapWalk(hHeap, lpEntry);
	}

	return (Ret);
}

