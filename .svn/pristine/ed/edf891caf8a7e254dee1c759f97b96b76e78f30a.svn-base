#include <crt/wt_stdio.h>

extern T_WintraceOpts      *pOpts;

FILE *wt_fopen(
   const char *filename,
   const char *mode
)
{
    FILE        *ret;


    if (BeginTrace(E_fopen))
    {
        WriteFuncBuffer("(\"%s\", \"%s\")", filename, mode);
        ret = fopen(filename, mode);
        WriteFuncBuffer(" = 0x%p", ret);
        EndTrace(E_fopen, ret == NULL);
    }
    else
        ret = fopen(filename, mode);

    return ret;
}

FILE *wt__wfopen(
   const wchar_t *filename,
   const wchar_t *mode
)
{
    FILE        *ret;


    if (BeginTrace(E__wfopen))
    {
        WriteFuncBuffer("(\"%ws\", \"%ws\")", filename, mode);
        ret = _wfopen(filename, mode);
        WriteFuncBuffer(" = 0x%p", ret);
        EndTrace(E__wfopen, ret == NULL);
    }
    else
        ret = _wfopen(filename, mode);

    return ret;
}

int wt_fclose(
   FILE *stream
)
{
    int     ret;


    if (BeginTrace(E_fclose))
    {
        WriteFuncBuffer("(0x%p)", stream);
        ret = fclose(stream);
        WriteFuncBuffer(" = %d", ret);
        EndTrace(E_fclose, ret == EOF);
    }
    else
        ret = fclose(stream);

    return ret;
}

