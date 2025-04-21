#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int *Ptr;
	double d;
	int i;
	long l;

    printf("\n|------------TEST: %s------------|\n", __FILE__);

	Ptr = (int *)malloc(20);
	Ptr = (int *)calloc(20, 4);
	Ptr = (int *)realloc(Ptr, 100);

	d = atof("100.23422");
	i = atoi("-12400");
	l = atol("20");

	free(Ptr);

    printf("|-----------------------------|\n\n");

	return 0;
}
