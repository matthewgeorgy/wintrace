#include <crt/wt_stdlib.h>

extern T_WintraceOpts		*pOpts;

double
wt_atof(
	LPCSTR str
)
{
	double Ret;

	if (BeginTrace(E_atof))
	{
		WriteFuncBuffer("(\"%s\")", str);
		Ret = atof(str);
		WriteFuncBuffer(" = %lf", Ret);
		EndTrace(E_atof, FALSE);
	}
	else
	{
		Ret = atof(str);
	}

	return (Ret);
}

int
wt_atoi(
	LPCSTR str
)
{
	int Ret;

	if (BeginTrace(E_atoi))
	{
		WriteFuncBuffer("(\"%s\")", str);
		Ret = atoi(str);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_atoi, FALSE);
	}
	else
	{
		Ret = atoi(str);
	}

	return (Ret);
}

long
wt_atol(
	LPCSTR str
)
{
	long Ret;

	if (BeginTrace(E_atol))
	{
		WriteFuncBuffer("(\"%s\")", str);
		Ret = atol(str);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_atol, FALSE);
	}
	else
	{
		Ret = atol(str);
	}

	return (Ret);
}

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

LPVOID
wt_calloc(
	size_t nitems,
	size_t size
)
{
	LPVOID Ret;

	if (BeginTrace(E_calloc))
	{
		WriteFuncBuffer("(%llu, %llu)", nitems, size);
		Ret = calloc(nitems, size);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_calloc, FALSE);
	}
	else
	{
		Ret = calloc(nitems, size);
	}

	return (Ret);
}

LPVOID
wt_realloc(
	LPVOID ptr,
	size_t size
)
{
	LPVOID Ret;

	if (BeginTrace(E_realloc))
	{
		WriteFuncBuffer("(0x%p, %llu)", ptr, size);
		Ret = realloc(ptr, size);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_realloc, FALSE);
	}
	else
	{
		Ret = realloc(ptr, size);
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

