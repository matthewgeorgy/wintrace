@echo off

hookgen

:: Win32 hooks
move wt_debugapi.h W:\wintrace\dll\inc\win32
move wt_fileapi.h W:\wintrace\dll\inc\win32
move wt_heapapi.h W:\wintrace\dll\inc\win32
move wt_memoryapi.h W:\wintrace\dll\inc\win32
move wt_processthreadsapi.h W:\wintrace\dll\inc\win32
move wt_profileapi.h W:\wintrace\dll\inc\win32
move wt_winuser.h W:\wintrace\dll\inc\win32

move wt_debugapi.c W:\wintrace\dll\win32
move wt_fileapi.c W:\wintrace\dll\win32
move wt_heapapi.c W:\wintrace\dll\win32
move wt_memoryapi.c W:\wintrace\dll\win32
move wt_processthreadsapi.c W:\wintrace\dll\win32
move wt_profileapi.c W:\wintrace\dll\win32
move wt_winuser.c W:\wintrace\dll\win32

:: CRT hooks
move wt_stdio.h W:\wintrace\dll\inc\crt
move wt_stdlib.h W:\wintrace\dll\inc\crt

move wt_stdio.c W:\wintrace\dll\crt
move wt_stdlib.c W:\wintrace\dll\crt

:: Func records
move func_records.h W:\wintrace\dll\inc
move func_records.c W:\wintrace\dll

:: PatchFunction
move patch_function.c W:\wintrace\dll

:: Function hashes
move func_hashes.h W:\wintrace\dll\inc

