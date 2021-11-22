#ifndef WT_STDIO_H
#define WT_STDIO_H

// already includes <stdio.h>
#include <common.h>

FILE *wt_fopen(
   const char *filename,
   const char *mode
);
FILE *wt__wfopen(
   const wchar_t *filename,
   const wchar_t *mode
);

int wt_fclose(
   FILE *stream
);

#endif // WT_STDIO_H
