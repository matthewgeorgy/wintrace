#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int
main(void)
{
	HANDLE		Heap;
	INT			*Arr1;
	INT			*Arr2;
	INT			I;


	Heap = GetProcessHeap();
	Arr1 = (INT *)HeapAlloc(Heap, 0, 10 * sizeof(INT));
	for (I = 0; I < 10; I++)
		Arr1[I] = I;
	HeapCompact(Heap, 0);
	
	Heap = HeapCreate(0, 4096, 4096);
	Arr2 = (INT *)HeapAlloc(Heap, 0, 10 * sizeof(INT));
	for (I = 0; I < 10; I++)
		Arr2[I] = 5;
	HeapCompact(Heap, 0);
	HeapReAlloc(Heap, 0, Arr2, 20 * sizeof(INT));
	HeapSize(Heap, 0, Arr2);

	HeapFree(GetProcessHeap(), 0, Arr1);
	HeapFree(Heap, 0, Arr2);
	HeapDestroy(Heap);

	return 0;
}
