/*
    Version History

		0.5.4	Naming Opts, Pipe, and Fence with the target PID
        0.5.3   Tidying up some DLL stuff
        0.5.2   Added a switch /P to use named pipes to print debug output through the EXE instead of the DLL (WIP)
        0.5.1   CRT function hooks are now generated using hookgen
        0.5.0   Win32 function hooks are now generated using hookgen
        0.4.10  Added function for getting wintrace.dll version
        0.4.9   Added ~ specifier to the /T switch to specify functions that
                are not to be traced
                Needs a bit of bulletproofing
        0.4.8   Added wt_stdlib.h with a few function hooks
        0.4.7   Beginning to add CRT support; currently a few stdio.h functions
        0.4.6   Tested printing with new system; still needs a slight fix
                Fixed hooks for DefWindowProcA/W
        0.4.5   Added basic printing with Write/PrintFuncBuffer();
                Need to test it with actual nested calls next
        0.4.4   Implemented EndTrace() in hooks; fixed misc bugs
        0.4.3   Added EndTrace(), g_CallLvl, WriteFuncBuffer(), PrintFuncBuffer()
                Need to actually implement/integrate these into the hooks
        0.4.2   Misc cleanups/fixes + added some comments/documentation
        0.4.1   Added specific tracing
        0.4.0   Fixed GetMessage
        0.3.9   Cleaned up warnings
        0.3.8   Added WtRemoveDirectoryA/W
        0.3.7   Added wt_memoryapi.c/h
        0.3.6   Added wt_profileapi.c/h
        0.3.5   Added wt_debugapi.c/h + filled functions + updated hashes
        0.3.4   General cleanup + fixes after testing with ppmview
                Removed _WIN64 requirement for Heap functions
        0.3.3   Added custom output file parsing
        0.3.2   Output now goes to stderr instead of stdout
        0.3.1   Small print fix in WtHeapCompact
        0.3.0   Added wt_fileapi.h/c + functions + added to patch list
        0.2.9   PatchIAT now uses switch+case table with Djb2 hashes
        0.2.8   Added more winuser functions + added them to the patch list
        0.2.7   Removed FARPROC + lpfn function loading in hooks
        0.2.6   Added more winuser functions
        0.2.5   Added processthreadsapi functions to the patch list
        0.2.4   Added more functions to wt_processthreadsapi
        0.2.3   Added common.c and ShowDetails() to display trace opts
        0.2.2   Added procID/threadID tracing
        0.2.1   Function call counts starts at 1 and enclosed in ()
        0.2.0   Function call counts print conditionally according to options
        0.1.9   Added common.h to contain common defs we'll need across files
        0.1.8   Added basic file mapping to retrieve options from core process
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
// TODO: Check functions with 64bit params and see what format specifier to
// use (ie, %u vs %lu vs %llu).
// TODO: Create our own printf that does fprintf(pOpts->...) internally?

#ifndef DLLMAIN_H
#define DLLMAIN_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Dbghelp.h>
#include <stdio.h>

#include <common.h>

#include <win32/wt_winuser.h>
#include <win32/wt_heapapi.h>
#include <win32/wt_processthreadsapi.h>
#include <win32/wt_fileapi.h>
#include <win32/wt_debugapi.h>
#include <win32/wt_profileapi.h>
#include <win32/wt_memoryapi.h>
#include <crt/wt_stdio.h>
#include <crt/wt_stdlib.h>

#define WINTRACE_DLL_VERSION "0.5.4"

// Goes through the IAT and patches the function addresses
void PatchIAT(void);

// 'Dummy' function for printing the IAT (function names + addresses)
void ReadIAT(void);

__declspec(dllexport) LPSTR __stdcall GetWintraceDllVersion(void);

// Simpe macro for patching a functions address in the IAT
#define PatchEntry(__Func) \
    do \
    { \
        VirtualProtect((LPVOID)(&FirstThunk->u1.Function), sizeof(DWORD_PTR), PAGE_READWRITE, &OldProtect); \
        FirstThunk->u1.Function = (DWORD_PTR)(__Func); \
    } while (0);

#endif // DLLMAIN_H

