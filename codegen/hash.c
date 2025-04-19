#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

LPSTR Types[] =
{
	"BOOL",
	"BOOLEAN",

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
	"LPDWORD",
	"HWND",
	"HMODULE",
	"HANDLE",
	"LPVOID",
	"void",
	"LPSECURITY_ATTRIBUTES"
};


DWORD
Djb2(LPSTR String)
{
    DWORD       Hash = 5381;
    INT         C;


    while (C = *String++)
        Hash = ((Hash << 5) + Hash) + C;

    return Hash;
}

int
main(void)
{
    HANDLE      HashFile;
    SIZE_T      TypesLen = sizeof(Types) / sizeof(Types[0]);
    INT         I;
    CHAR        Str[256];


    HashFile = CreateFile("w:\\wintrace\\codegen\\hashes.h", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    for (I = 0; I < TypesLen; I++)
    {
        sprintf(Str, "#define TYPE_%s %u\r\n", Types[I], Djb2(Types[I]));
        WriteFile(HashFile, Str, strlen(Str), NULL, NULL);
    }
    sprintf(Str, "\r\n");
    WriteFile(HashFile, Str, strlen(Str), NULL, NULL);

    CloseHandle(HashFile);

    return 0;
}

