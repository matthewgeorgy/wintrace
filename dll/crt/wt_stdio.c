#include <crt/wt_stdio.h>

extern T_WintraceOpts		*pOpts;

LPFILE
wt_fopen(
	LPCSTR filename,
	LPCSTR mode
)
{
	LPFILE Ret;

	if (BeginTrace(E_fopen))
	{
		WriteFuncBuffer("(\"%s\", \"%s\")", filename, mode);
		Ret = fopen(filename, mode);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_fopen, FALSE);
	}
	else
	{
		Ret = fopen(filename, mode);
	}

	return (Ret);
}

LPFILE
wt__wfopen(
	LPCWSTR filename,
	LPCWSTR mode
)
{
	LPFILE Ret;

	if (BeginTrace(E__wfopen))
	{
		WriteFuncBuffer("(\"%ws\", \"%ws\")", filename, mode);
		Ret = _wfopen(filename, mode);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E__wfopen, FALSE);
	}
	else
	{
		Ret = _wfopen(filename, mode);
	}

	return (Ret);
}

int
wt_fclose(
	LPFILE stream
)
{
	int Ret;

	if (BeginTrace(E_fclose))
	{
		WriteFuncBuffer("(0x%p)", stream);
		Ret = fclose(stream);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_fclose, FALSE);
	}
	else
	{
		Ret = fclose(stream);
	}

	return (Ret);
}

