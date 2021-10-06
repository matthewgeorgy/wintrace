/*
	Version History

		0.1.2	Added dllmain.h and moved #includes around
		0.1.1	Added wt_winuser.h/c and wt_processthreadsapi.c/h
		0.1.0	Initial creation
*/

#ifndef DLLMAIN_H
#define DLLMAIN_H

#include <windows.h>
#include <Dbghelp.h>

#include "wt_winuser.h"
#include "wt_processthreadsapi.h"

void PatchIAT(void);

#endif // DLLMAIN_H
