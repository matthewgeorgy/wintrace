#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	FILE *File;
	int *Ptr;

    printf("\n|------------TEST: %s------------|\n", __FILE__);
	File = fopen("test_stdio.txt", "w");
	Ptr = (int *)malloc(20);

	fclose(File);
	free(Ptr);

    printf("|-----------------------------|\n\n");

	return 0;
}
