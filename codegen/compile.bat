@echo off

hookgen wt_debugapi Wt
hookgen wt_fileapi Wt
hookgen wt_heapapi Wt
hookgen wt_memoryapi Wt
hookgen wt_processthreadsapi Wt
hookgen wt_profileapi Wt
hookgen wt_winuser Wt

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
