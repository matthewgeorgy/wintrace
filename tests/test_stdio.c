#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
	FILE *File;
	char *String = "Hello there...";
	char Buffer[200];
	int FileSize;

    printf("\n|------------TEST: %s------------|\n", __FILE__);

	File = fopen("test_stdio.txt", "w+");

	fwrite(String, strlen(String), 1, File);

	fseek(File, 0, SEEK_END);
	FileSize = ftell(File);
	fseek(File, 0, SEEK_SET);

	fread(Buffer, 200, 1, File);

	fclose(File);

    printf("|-----------------------------|\n\n");

	return 0;
}
