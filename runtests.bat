@echo off

pushd build
wintrace.exe /c /t /p tests\test_heapapi.exe
wintrace.exe /c /t /p tests\test_fileapi.exe
wintrace.exe /c /t /p tests\test_winuser.exe
popd
