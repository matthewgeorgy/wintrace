/*
	Version History

		0.1.5	Added counters for hooked function calls
		0.1.4	Fully add wt_heapapi.h/c; BUG ON x86!
		0.1.3	Added dummy macro to easily patch individual IAT entries
		0.1.2	Added dllmain.h and moved #includes around
		0.1.1	Added wt_winuser.h/c and wt_processthreadsapi.c/h
		0.1.0	Initial creation
*/

#ifndef DLLMAIN_H
#define DLLMAIN_H

#include <windows.h>
#include <Dbghelp.h>

#include "wt_winuser.h"
#include "wt_heapapi.h"
#include "wt_processthreadsapi.h"

void PatchIAT(void);

#define PatchEntry(__Func) \
	do \
	{ \
		VirtualProtect((LPVOID)(&FirstThunk->u1.Function), 8, PAGE_READWRITE, &OldProtect); \
		FirstThunk->u1.Function = (DWORD_PTR)(__Func); \
	} while (0);

#endif // DLLMAIN_H
