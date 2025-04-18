#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

typedef struct _tag_WINTRACEOPTS
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
} T_WINTRACEOPTS;

typedef HANDLE	T_HFILEMAP;

void ShowDetails(T_WINTRACEOPTS *pOpts, DWORD Cnt);

#endif // COMMON_H
