#ifndef WT_HEAPAPI_H
#define WT_HEAPAPI_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

HANDLE WtGetProcessHeap();

DWORD WtGetProcessHeaps(
  DWORD   NumberOfHeaps,
  PHANDLE ProcessHeaps
);

LPVOID WtHeapAlloc(
  HANDLE hHeap,
  DWORD  dwFlags,
  SIZE_T dwBytes
);

SIZE_T WtHeapCompact(
  HANDLE hHeap,
  DWORD  dwFlags
);

HANDLE WtHeapCreate(
  DWORD  flOptions,
  SIZE_T dwInitialSize,
  SIZE_T dwMaximumSize
);

BOOL WtHeapDestroy(
  HANDLE hHeap
);

BOOL WtHeapFree(
  HANDLE hHeap,
  DWORD  dwFlags,
  LPVOID lpMem
);

BOOL WtHeapLock(
  HANDLE hHeap
);

BOOL WtHeapQueryInformation(
  HANDLE                 HeapHandle,
  HEAP_INFORMATION_CLASS HeapInformationClass,
  PVOID                  HeapInformation,
  SIZE_T                 HeapInformationLength,
  PSIZE_T                ReturnLength
);

LPVOID WtHeapReAlloc(
  HANDLE  hHeap,
  DWORD  dwFlags,
  LPVOID lpMem,
  SIZE_T dwBytes
);

BOOL WtHeapSetInformation(
  HANDLE                 HeapHandle,
  HEAP_INFORMATION_CLASS HeapInformationClass,
  PVOID                  HeapInformation,
  SIZE_T                 HeapInformationLength
);

SIZE_T WtHeapSize(
  HANDLE  hHeap,
  DWORD   dwFlags,
  LPCVOID lpMem
);

BOOL WtHeapUnlock(
  HANDLE hHeap
);

BOOL WtHeapValidate(
  HANDLE  hHeap,
  DWORD   dwFlags,
  LPCVOID lpMem
);

BOOL WtHeapWalk(
  HANDLE               hHeap,
  LPPROCESS_HEAP_ENTRY lpEntry
);

#endif // WT_HEAPAPI_H
