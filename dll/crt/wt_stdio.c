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

int
wt_feof(
	LPFILE stream
)
{
	int Ret;

	if (BeginTrace(E_feof))
	{
		WriteFuncBuffer("(0x%p)", stream);
		Ret = feof(stream);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_feof, FALSE);
	}
	else
	{
		Ret = feof(stream);
	}

	return (Ret);
}

int
wt_ferror(
	LPFILE stream
)
{
	int Ret;

	if (BeginTrace(E_ferror))
	{
		WriteFuncBuffer("(0x%p)", stream);
		Ret = ferror(stream);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ferror, FALSE);
	}
	else
	{
		Ret = ferror(stream);
	}

	return (Ret);
}

int
wt_fflush(
	LPFILE stream
)
{
	int Ret;

	if (BeginTrace(E_fflush))
	{
		WriteFuncBuffer("(0x%p)", stream);
		Ret = fflush(stream);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_fflush, FALSE);
	}
	else
	{
		Ret = fflush(stream);
	}

	return (Ret);
}

size_t
wt_fread(
	LPVOID ptr,
	size_t size,
	size_t nmemb,
	LPFILE stream
)
{
	size_t Ret;

	if (BeginTrace(E_fread))
	{
		WriteFuncBuffer("(0x%p, %llu, %llu, 0x%p)", ptr, size, nmemb, stream);
		Ret = fread(ptr, size, nmemb, stream);
		WriteFuncBuffer(" = %llu", Ret);
		EndTrace(E_fread, FALSE);
	}
	else
	{
		Ret = fread(ptr, size, nmemb, stream);
	}

	return (Ret);
}

size_t
wt_fwrite(
	LPVOID ptr,
	size_t size,
	size_t nmemb,
	LPFILE stream
)
{
	size_t Ret;

	if (BeginTrace(E_fwrite))
	{
		WriteFuncBuffer("(0x%p, %llu, %llu, 0x%p)", ptr, size, nmemb, stream);
		Ret = fwrite(ptr, size, nmemb, stream);
		WriteFuncBuffer(" = %llu", Ret);
		EndTrace(E_fwrite, FALSE);
	}
	else
	{
		Ret = fwrite(ptr, size, nmemb, stream);
	}

	return (Ret);
}

int
wt_fseek(
	LPFILE stream,
	long offset,
	int whence
)
{
	int Ret;

	if (BeginTrace(E_fseek))
	{
		WriteFuncBuffer("(0x%p, %d, %d)", stream, offset, whence);
		Ret = fseek(stream, offset, whence);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_fseek, FALSE);
	}
	else
	{
		Ret = fseek(stream, offset, whence);
	}

	return (Ret);
}

long
wt_ftell(
	LPFILE stream
)
{
	long Ret;

	if (BeginTrace(E_ftell))
	{
		WriteFuncBuffer("(0x%p)", stream);
		Ret = ftell(stream);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ftell, FALSE);
	}
	else
	{
		Ret = ftell(stream);
	}

	return (Ret);
}

