#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

int
main(void)
{
    int *a = NULL;
    HANDLE Heap;
    HANDLE File;

    printf("----------------\n");

    Heap = GetProcessHeap();
    File = CreateFileA("t.t", GENERIC_READ, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    a = (int *)HeapAlloc(Heap, 0, 40);
    GetCurrentProcess();
    GetCurrentProcessId();

    MessageBoxA(NULL, L"Hello", L"window", 0);
    HeapFree(Heap, 0, a);

    printf("----------------\n");

    return 0;
}
