#include <crt/wt_stdlib.h>

extern T_WintraceOpts		*pOpts;

LPVOID
wt_malloc(
	size_t size
)
{
	LPVOID Ret;

	if (BeginTrace(E_malloc))
	{
		WriteFuncBuffer("(%llu)", size);
		Ret = malloc(size);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_malloc, FALSE);
	}
	else
	{
		Ret = malloc(size);
	}

	return (Ret);
}

void
wt_free(
	LPVOID memblock
)
{
	if (BeginTrace(E_free))
	{
		WriteFuncBuffer("(0x%p)", memblock);
		WriteFuncBuffer(" = VOID");
		EndTrace(E_free, FALSE);
	}

	free(memblock);
}

