#ifndef WT_STDLIB_H
#define WT_STDLIB_H

#include "common.h"

double wt_atof(LPCSTR str);
int wt_atoi(LPCSTR str);
long wt_atol(LPCSTR str);
LPVOID wt_malloc(size_t size);
LPVOID wt_calloc(size_t nitems, size_t size);
LPVOID wt_realloc(LPVOID ptr, size_t size);
void wt_free(LPVOID memblock);

#endif // WT_STDLIB_H
