@echo off

:: Win32 hooks
hookgen wt_debugapi Wt win32
hookgen wt_fileapi Wt win32
hookgen wt_heapapi Wt win32
hookgen wt_memoryapi Wt win32
hookgen wt_processthreadsapi Wt win32
hookgen wt_profileapi Wt win32
hookgen wt_winuser Wt win32

cp wt_debugapi.h W:\wintrace\dll\inc\win32
cp wt_fileapi.h W:\wintrace\dll\inc\win32
cp wt_heapapi.h W:\wintrace\dll\inc\win32
cp wt_memoryapi.h W:\wintrace\dll\inc\win32
cp wt_processthreadsapi.h W:\wintrace\dll\inc\win32
cp wt_profileapi.h W:\wintrace\dll\inc\win32
cp wt_winuser.h W:\wintrace\dll\inc\win32

cp wt_debugapi.c W:\wintrace\dll\win32
cp wt_fileapi.c W:\wintrace\dll\win32
cp wt_heapapi.c W:\wintrace\dll\win32
cp wt_memoryapi.c W:\wintrace\dll\win32
cp wt_processthreadsapi.c W:\wintrace\dll\win32
cp wt_profileapi.c W:\wintrace\dll\win32
cp wt_winuser.c W:\wintrace\dll\win32

:: CRT hooks
hookgen wt_stdio wt_ crt
hookgen wt_stdlib wt_ crt

cp wt_stdio.h W:\wintrace\dll\inc\crt
cp wt_stdlib.h W:\wintrace\dll\inc\crt

cp wt_stdio.c W:\wintrace\dll\crt
cp wt_stdlib.c W:\wintrace\dll\crt
