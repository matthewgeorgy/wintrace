#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

int
main(void)
{
	BOOL		Status;
	HANDLE		File;
	DWORD		Written, Read, Offset;
	char		*MyStringBuffer = "Hello World!\r\n";
	char		MyBuffer[200];


    printf("\n|------------TEST: %s------------|\n", __FILE__);
	Status = CreateDirectoryA("Foo", NULL);
	File = CreateFileA("Foo\\bar.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	Status = WriteFile(File, MyStringBuffer, (DWORD)strlen(MyStringBuffer), &Written, NULL);
	Offset = SetFilePointer(File, 0, 0, FILE_BEGIN);
	Status = ReadFile(File, MyBuffer, sizeof(MyBuffer) - 1, &Read, NULL);
	Status = DeleteFileA("Foo\\bar.txt");
	Status = RemoveDirectoryA("Foo");
	CloseHandle(File);

	printf("\n");
	Status = CreateDirectoryW(L"Foo", NULL);
	File = CreateFileW(L"Foo\\bar.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	Status = WriteFile(File, MyStringBuffer, (DWORD)strlen(MyStringBuffer), &Written, NULL);
	Offset = SetFilePointer(File, 0, 0, FILE_BEGIN);
	Status = ReadFile(File, MyBuffer, sizeof(MyBuffer) - 1, &Read, NULL);
	Status = DeleteFileW(L"Foo\\bar.txt");
	Status = RemoveDirectoryW(L"Foo");
	CloseHandle(File);
    printf("|-----------------------------|\n\n");

	return 0;
}

