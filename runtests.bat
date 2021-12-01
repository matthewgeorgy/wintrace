@echo off

pushd build
wintrace.exe /c /t /p tests\test_heapapi.exe
wintrace.exe /c /t /p tests\test_fileapi.exe
wintrace.exe /c /t /p tests\test_winuser.exe
wintrace.exe /c /t /p tests\test_memoryapi.exe
wintrace.exe /c /t /p tests\test_stdio.exe
wintrace.exe /c /t /p tests\test_stdlib.exe
popd
