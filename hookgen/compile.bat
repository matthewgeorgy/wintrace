@echo off

hookgen

:: Win32 hooks
move wt_debugapi.h ..\dll\inc\win32
move wt_fileapi.h ..\dll\inc\win32
move wt_heapapi.h ..\dll\inc\win32
move wt_memoryapi.h ..\dll\inc\win32
move wt_processthreadsapi.h ..\dll\inc\win32
move wt_profileapi.h ..\dll\inc\win32
move wt_winuser.h ..\dll\inc\win32
move wt_syncapi.h ..\dll\inc\win32

move wt_debugapi.c ..\dll\win32
move wt_fileapi.c ..\dll\win32
move wt_heapapi.c ..\dll\win32
move wt_memoryapi.c ..\dll\win32
move wt_processthreadsapi.c ..\dll\win32
move wt_profileapi.c ..\dll\win32
move wt_winuser.c ..\dll\win32
move wt_syncapi.c ..\dll\win32

:: CRT hooks
move wt_stdio.h ..\dll\inc\crt
move wt_stdlib.h ..\dll\inc\crt

move wt_stdio.c ..\dll\crt
move wt_stdlib.c ..\dll\crt

:: Func records
move func_records.h ..\dll\inc
move func_records.c ..\dll

:: PatchFunction
move patch_function.c ..\dll

:: Function hashes
move func_hashes.h ..\dll\inc

