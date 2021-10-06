#include "dllmain.h"

BOOL APIENTRY
DllMain(HMODULE hModule,
		DWORD fdwReason,
		LPVOID lpReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			ReadIAT();
			PatchIAT();
		} break;
		case DLL_PROCESS_DETACH:
		{
		} break;
	}

	return TRUE;
}

void
PatchIAT(void)
{
	LPVOID							ImageBase;
	PIMAGE_DOS_HEADER 				DosHeader;
	PIMAGE_NT_HEADERS				NtHeader;
	PIMAGE_IMPORT_DESCRIPTOR		ImportDesc;
	IMAGE_DATA_DIRECTORY			ImportDir;
	LPCSTR							LibraryName;
	HMODULE							Library;
	PIMAGE_IMPORT_BY_NAME			FunctionName;
	DWORD							OldProtect;
	PIMAGE_THUNK_DATA				OriginalFirstThunk,
									FirstThunk;


	ImageBase = GetModuleHandle(NULL);
	DosHeader = (PIMAGE_DOS_HEADER)ImageBase;
	NtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ImageBase + DosHeader->e_lfanew);

	ImportDir = NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	ImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(ImportDir.VirtualAddress + (DWORD_PTR)ImageBase);

	while (ImportDesc->Name != 0)
	{
		LibraryName = (LPCSTR)ImportDesc->Name + (DWORD_PTR)ImageBase;
		Library = LoadLibraryA(LibraryName);

		if (Library)
		{
			OriginalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->OriginalFirstThunk);
			FirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->FirstThunk);

			while (OriginalFirstThunk->u1.AddressOfData != 0)
			{
				FunctionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)ImageBase + OriginalFirstThunk->u1.AddressOfData);

				if (lstrcmpiA(FunctionName->Name, "MessageBoxA") == 0) PatchEntry(WtMessageBoxA);
				if (lstrcmpiA(FunctionName->Name, "GetCurrentProcess") == 0) PatchEntry(WtGetCurrentProcess);
				if (lstrcmpiA(FunctionName->Name, "GetCurrentProcessId") == 0) PatchEntry(WtGetCurrentProcessId);
				// heapapi.h
				if (lstrcmpiA(FunctionName->Name, "GetProcessHeap") == 0) 		PatchEntry(WtGetProcessHeap);
				if (lstrcmpiA(FunctionName->Name, "GetProcessHeaps") == 0) 		PatchEntry(WtGetProcessHeaps);
				if (lstrcmpiA(FunctionName->Name, "HeapAlloc") == 0) 			PatchEntry(WtHeapAlloc);
				if (lstrcmpiA(FunctionName->Name, "HeapCompact") == 0)			PatchEntry(WtHeapCompact);
				if (lstrcmpiA(FunctionName->Name, "HeapCreate") == 0)			PatchEntry(WtHeapCreate);
				if (lstrcmpiA(FunctionName->Name, "HeapDestroy") == 0)			PatchEntry(WtHeapDestroy);
				if (lstrcmpiA(FunctionName->Name, "HeapFree") == 0)				PatchEntry(WtHeapFree);
				if (lstrcmpiA(FunctionName->Name, "HeapLock") == 0) 			PatchEntry(WtHeapLock);
				if (lstrcmpiA(FunctionName->Name, "HeapQueryInformation") == 0)	PatchEntry(WtHeapQueryInformation);
				if (lstrcmpiA(FunctionName->Name, "HeapReAlloc") == 0) 			PatchEntry(WtHeapReAlloc);
				if (lstrcmpiA(FunctionName->Name, "HeapSetInformation") == 0) 	PatchEntry(WtHeapSetInformation);
				if (lstrcmpiA(FunctionName->Name, "HeapSize") == 0)				PatchEntry(WtHeapSize);
				if (lstrcmpiA(FunctionName->Name, "HeapUnlock") == 0)			PatchEntry(WtHeapUnlock);
				if (lstrcmpiA(FunctionName->Name, "HeapValidate") == 0)			PatchEntry(WtHeapValidate);
				if (lstrcmpiA(FunctionName->Name, "HeapWalk") == 0)				PatchEntry(WtHeapWalk);

				OriginalFirstThunk++;
				FirstThunk++;
			}
		}

		ImportDesc++;
	}
}

void
ReadIAT(void)
{
	LPVOID							ImageBase;
	PIMAGE_DOS_HEADER 				DosHeader;
	PIMAGE_NT_HEADERS				NtHeader;
	PIMAGE_IMPORT_DESCRIPTOR		ImportDesc;
	IMAGE_DATA_DIRECTORY			ImportDir;
	LPCSTR							LibraryName;
	HMODULE							Library;
	PIMAGE_IMPORT_BY_NAME			FunctionName;
	DWORD							OldProtect;
	PIMAGE_THUNK_DATA				OriginalFirstThunk,
									FirstThunk;


	printf("\n");
	ImageBase = GetModuleHandle(NULL);
	DosHeader = (PIMAGE_DOS_HEADER)ImageBase;
	NtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ImageBase + DosHeader->e_lfanew);

	ImportDir = NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	ImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(ImportDir.VirtualAddress + (DWORD_PTR)ImageBase);

	while (ImportDesc->Name != 0)
	{
		LibraryName = (LPCSTR)ImportDesc->Name + (DWORD_PTR)ImageBase;
		Library = LoadLibraryA(LibraryName);
		printf("%s\n", LibraryName);

		if (Library)
		{
			OriginalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->OriginalFirstThunk);
			FirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->FirstThunk);

			while (OriginalFirstThunk->u1.AddressOfData != 0)
			{
				FunctionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)ImageBase + OriginalFirstThunk->u1.AddressOfData);

				printf("%s\n", FunctionName->Name);

				OriginalFirstThunk++;
				FirstThunk++;
			}
		}

		ImportDesc++;
	}
}
