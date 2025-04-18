#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int
main(void)
{
	FILE *File;

    printf("\n|------------TEST: %s------------|\n", __FILE__);
	File = fopen("test_stdio.txt", "w");

	fclose(File);

    printf("|-----------------------------|\n\n");

	return 0;
}
