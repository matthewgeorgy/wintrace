#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define CRLF		"\r\n"

LPSTR Types[] =
{
	"BOOL",
	"BOOLEAN",

	"char",
	"short",
	"int",
	"long",
	"float",
	"double",
	"size_t",
	"INT",
	"INT8",
	"INT16",
	"INT32",
	"INT64",
	"UINT",
	"UINT8",
	"UINT16",
	"UINT32",
	"UINT64",
	"SHORT",
	"BYTE",
	"WORD",
	"DWORD",
	"QWORD",
	"SIZE_T",
	"LONG",
	"HEAP_INFORMATION_CLASS",

	"CHAR",
	"WCHAR",
	"LPSTR",
	"LPWSTR",
	"LPCSTR",
	"LPCWSTR",
	"ATOM",

	"LPOVERLAPPED",
	"LPOVERLAPPED_COMPLETION_ROUTINE",
	"PLARGE_INTEGER",
	"LARGE_INTEGER",
	"FLOAT",
	"LPFLOAT",
	"LPCVOID",
	"LPBYTE",
	"LPWORD",
	"PLONG",
	"LPLONG",
	"LPDWORD",
	"PDWORD",
	"LPPROCESS_HEAP_ENTRY",
	"LPCRITICAL_SECTION",
	"HWND",
	"HMODULE",
	"HANDLE",
	"PHANDLE",
	"LPVOID",
	"PVOID",
	"PSIZE_T",
	"void",
	"VOID",
	"LPSECURITY_ATTRIBUTES",
	"PMEMORY_BASIC_INFORMATION",
	"LPPROC_THREAD_ATTRIBUTE_LIST",
	"LPSTARTUPINFOA",
	"LPSTARTUPINFOW",
	"LPPROCESS_INFORMATION",
	"LPTHREAD_START_ROUTINE",
	"LPDEBUG_EVENT",
	"LPBOOL",
	"PBOOL",
	"LPRECT",
	"LRESULT",
	"PAINTSTRUCT",
	"LPPAINTSTRUCT",
	"HDC",
	"LPPOINT",
	"HMENU",
	"HINSTANCE",
	"WPARAM",
	"LPARAM",
	"LPMSG",
	"HBRUSH",
	"LPWNDCLASSEXA",
	"LPWNDCLASSEXW",
	"LPFILE"
};

DWORD
Djb2(LPSTR String)
{
    DWORD       Hash = 5381;
    INT         C = *String++;


    while (C)
    {
        Hash = ((Hash << 5) + Hash) + C;
        C = *String++;
    }

    return Hash;
}

int
main(void)
{
    HANDLE      HashFile;
    SIZE_T      TypesLen = sizeof(Types) / sizeof(Types[0]);
    INT         I;
    CHAR        Str[256];


    HashFile = CreateFile("type_hashes.h", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    for (I = 0; I < TypesLen; I++)
    {
        sprintf(Str, "#define TYPE_%s %u" CRLF, Types[I], Djb2(Types[I]));
        WriteFile(HashFile, Str, (DWORD)strlen(Str), NULL, NULL);
    }
    sprintf(Str, CRLF);
    WriteFile(HashFile, Str, (DWORD)strlen(Str), NULL, NULL);

    CloseHandle(HashFile);

    return 0;
}

