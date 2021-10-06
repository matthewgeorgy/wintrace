#include "wt_processthreadsapi.h"

HANDLE
WtGetCurrentProcess(void)
{
	HANDLE 		Ret;
	
	Ret = GetCurrentProcess();
	printf("GetCurrentProcess() = 0x%p\n", Ret);

	return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
	DWORD Ret;

	Ret = GetCurrentProcessId();
	printf("GetCurrentProcessId() = %u\n", Ret);

	return Ret;
}
	
