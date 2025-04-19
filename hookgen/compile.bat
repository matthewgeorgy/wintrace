@echo off

hookgen

:: Win32 hooks
mv wt_debugapi.h W:\wintrace\dll\inc\win32
mv wt_fileapi.h W:\wintrace\dll\inc\win32
mv wt_heapapi.h W:\wintrace\dll\inc\win32
mv wt_memoryapi.h W:\wintrace\dll\inc\win32
mv wt_processthreadsapi.h W:\wintrace\dll\inc\win32
mv wt_profileapi.h W:\wintrace\dll\inc\win32
mv wt_winuser.h W:\wintrace\dll\inc\win32

mv wt_debugapi.c W:\wintrace\dll\win32
mv wt_fileapi.c W:\wintrace\dll\win32
mv wt_heapapi.c W:\wintrace\dll\win32
mv wt_memoryapi.c W:\wintrace\dll\win32
mv wt_processthreadsapi.c W:\wintrace\dll\win32
mv wt_profileapi.c W:\wintrace\dll\win32
mv wt_winuser.c W:\wintrace\dll\win32

:: CRT hooks
mv wt_stdio.h W:\wintrace\dll\inc\crt
mv wt_stdlib.h W:\wintrace\dll\inc\crt

mv wt_stdio.c W:\wintrace\dll\crt
mv wt_stdlib.c W:\wintrace\dll\crt
