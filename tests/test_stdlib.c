#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int *Ptr;

    printf("\n|------------TEST: %s------------|\n", __FILE__);

	Ptr = (int *)malloc(20);
	free(Ptr);

    printf("|-----------------------------|\n\n");

	return 0;
}
