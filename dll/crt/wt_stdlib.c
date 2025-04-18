#include <crt/wt_stdlib.h>

extern T_WintraceOpts      *pOpts;

void *
wt_malloc(
   size_t size
)
{
	void		*ret;


	if (BeginTrace(E_malloc))
	{
		WriteFuncBuffer("(%u)", size);
		ret = malloc(size);
		WriteFuncBuffer(" = 0x%p", ret);
		EndTrace(E_malloc, ret == NULL);
	}
	else
		ret = malloc(size);

	return ret;
}

void
wt_free(
   void *memblock
)
{
	if (BeginTrace(E_free))
	{
		WriteFuncBuffer("(0x%p)", memblock);
		free(memblock);
		WriteFuncBuffer(" = VOID");
		EndTrace(E_free, FALSE);
	}
	else
		free(memblock);
}

