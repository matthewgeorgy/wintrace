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
			PatchIAT();
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

				if (lstrcmpiA(FunctionName->Name, "MessageBoxA") == 0)
				{
					VirtualProtect((LPVOID)(&FirstThunk->u1.Function), 8, PAGE_READWRITE, &OldProtect);
					FirstThunk->u1.Function = (DWORD_PTR)(WtMessageBoxA);
				}
				if (lstrcmpiA(FunctionName->Name, "GetCurrentProcess") == 0)
				{
					VirtualProtect((LPVOID)(&FirstThunk->u1.Function), 8, PAGE_READWRITE, &OldProtect);
					FirstThunk->u1.Function = (DWORD_PTR)(WtGetCurrentProcess);
				}
				if (lstrcmpiA(FunctionName->Name, "GetCurrentProcessId") == 0)
				{
					VirtualProtect((LPVOID)(&FirstThunk->u1.Function), 8, PAGE_READWRITE, &OldProtect);
					FirstThunk->u1.Function = (DWORD_PTR)(WtGetCurrentProcessId);
				}

				OriginalFirstThunk++;
				FirstThunk++;
			}
		}

		ImportDesc++;
	}
}
