#include <windows.h>
#include <stdio.h>

int
main(void)
{
	LPCSTR					DllPath = "lib.dll";
	LPCSTR					ProgramName = "main.exe";
	HANDLE					Process;
	STARTUPINFO				si = {0};
	PROCESS_INFORMATION		pi = {0};
	LPVOID					pDllPath;
	HANDLE					LoadThread;
	SIZE_T					Len = strlen(DllPath) + 1;
	BOOL					Status;
	PTHREAD_START_ROUTINE	pfnThreadRtn;


	si.cb = sizeof(STARTUPINFO);
	Status = CreateProcess(NULL, ProgramName, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);
	if (!Status)
	{
		printf("failed to create process!\n");
		return -1;
	}

	pfnThreadRtn = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("Kernel32.dll"), "LoadLibraryA");
	if (!pfnThreadRtn)
	{
		printf("could no locate loadliba\n");
		return -1;
	}

	Process = pi.hProcess;

	pDllPath = VirtualAllocEx(Process, 0, Len, MEM_COMMIT, PAGE_READWRITE);
	if (!pDllPath)
	{
		printf("failed to allocate!\n");
		return -1;
	}

	Status = WriteProcessMemory(Process, pDllPath, (LPVOID)DllPath, Len, 0);
	if (!Status)
	{
		printf("failed to write memory!\n");
		return -1;
	}

	LoadThread = CreateRemoteThread(Process, NULL, 0, pfnThreadRtn, pDllPath, 0, NULL);
	if (!LoadThread)
	{
		printf("failed to load thread\n");
		return -1;
	}

	WaitForSingleObject(LoadThread, INFINITE);

	if (ResumeThread(pi.hThread) == -1)
	{
		printf("resume thread failed\n");
	}

	VirtualFreeEx(Process, pDllPath, Len, MEM_RELEASE);

	return 0;
}

