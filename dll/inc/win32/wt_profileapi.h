#ifndef WT_PROFILEAPI_H
#define WT_PROFILEAPI_H

#include "common.h"

BOOL WtQueryPerformanceCounter(PLARGE_INTEGER lpPerformanceCount);
BOOL WtQueryPerformanceFrequency(PLARGE_INTEGER lpFrequency);

#endif // WT_PROFILEAPI_H
