#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

void		TestVirtualFunctions(void);
void		TestMapFunctions(void);

int
main(void)
{
    printf("\n|------------TEST: %s------------|\n", __FILE__);

	TestVirtualFunctions();

	TestMapFunctions();

    printf("|-----------------------------|\n\n");
	return 0;
}

void
TestVirtualFunctions(void)
{
	LPVOID							Ptr;
	SIZE_T							MemSize = 4096,
									RetSize;
	BOOL							Status;
	MEMORY_BASIC_INFORMATION		MemoryInfo;
	DWORD							OldProtect;


	Ptr = VirtualAlloc(NULL, MemSize, MEM_COMMIT, PAGE_READWRITE);
	RetSize = VirtualQuery(Ptr, &MemoryInfo, MemSize);
	Status = VirtualLock(Ptr, MemSize);
	Status = VirtualUnlock(Ptr, MemSize);
	Status = VirtualProtect(Ptr, MemSize, PAGE_EXECUTE, &OldProtect);
	Status = VirtualFree(Ptr, MemSize, MEM_DECOMMIT);
}

void
TestMapFunctions(void)
{
	HANDLE		FileMap;
	HANDLE		View;
	DWORD		Data,
				*pData;


	FileMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(Data), "test_memoryapi");
	if (!FileMap)
	{
		printf("Could not create file map (%d)\n", GetLastError());
		return;
	}

	pData = (DWORD *)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Data));
	if (!pData)
	{
		printf("Could not create map view (%d)\n", GetLastError());
		CloseHandle(FileMap);
		return;
	}

	CopyMemory((LPVOID)pData, &Data, sizeof(Data));

	View = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "test_memoryapi");

	UnmapViewOfFile(FileMap);
	CloseHandle(FileMap);

	UnmapViewOfFile(View);
	CloseHandle(View);
}

