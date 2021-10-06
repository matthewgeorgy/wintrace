/*
    Version History

        0.1.7   Cleanup + retab; forcing x64 DLLCRT
        0.1.6   Fixed wt_heapapi bug*, added ReadIAT()
        0.1.5   Added counters for hooked function calls
        0.1.4   Fully added wt_heapapi.h/c; wt_heapapi BUG ON x86!
        0.1.3   Added dummy macro to easily patch individual IAT entries
        0.1.2   Added dllmain.h and moved #includes around
        0.1.1   Added wt_winuser.h/c and wt_processthreadsapi.c/h
        0.1.0   Initial creation
*/

// TODO: Fix bug that requires test programs to be compiled with msvcrt.lib:
// If I don't compile the test program with msvcrt.lib, then WtHeapAlloc()
// causes a stack overflow. This is because the printf() calls to malloc(),
// which calls HeapAlloc(). However, because the original HeapAlloc was
// overwritten, it actually calls WtHeapAlloc(), causing an infinite recursion
// until eventual stack overflow. Although not tested, I would expect a
// similar issue with WtHeapFree(). On x86, this causes an almost immediate
// crash; on x64, this doesn't crash, but the recursed HeapAlloc calls can be
// seen in the output.
// However, if I DO compile the test program with msvcrt.lib, then this issue
// somehow disappears.
// NOTE: For now, I am ignoring this issue; target programs MUST be built for
// x64 and linked to the CRT DLL (/MD or link ... msvcrt.lib). I'll
// investigate this later.

#ifndef DLLMAIN_H
#define DLLMAIN_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Dbghelp.h>
#include <stdio.h>

#include "wt_winuser.h"
#include "wt_heapapi.h"
#include "wt_processthreadsapi.h"
#include "wt_fileapi.h"

void PatchIAT(void);
void ReadIAT(void);

#define PatchEntry(__Func) \
    do \
    { \
        VirtualProtect((LPVOID)(&FirstThunk->u1.Function), sizeof(DWORD_PTR), PAGE_READWRITE, &OldProtect); \
        FirstThunk->u1.Function = (DWORD_PTR)(__Func); \
    } while (0);

#endif // DLLMAIN_H
