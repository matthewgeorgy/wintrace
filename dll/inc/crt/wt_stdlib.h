#ifndef WT_STDLIB_H
#define WT_STDLIB_H

#include "common.h"

LPVOID wt_malloc(size_t size);
void wt_free(LPVOID memblock);

#endif // WT_STDLIB_H
