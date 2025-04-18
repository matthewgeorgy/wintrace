@echo off

if [%1]==[]         goto :install
if "%1"=="clean"    goto :clean
if "%1"=="test"     goto :test

:install
    pushd build
		cl /W4 /c /I"..\dll\inc" ..\dll\win32\*.c
		cl /W4 /c /I"..\dll\inc" ..\dll\*.c
		link /DLL *.obj /OUT:wintrace.dll kernel32.lib user32.lib advapi32.lib
        cl /W4 /MP /Fe"wintrace.exe" ..\core\*.c kernel32.lib
    popd
if "%1"=="all"	goto :test
goto :EOF

:test
    pushd build\tests
        cl /W4 /MD ..\..\tests\test_heapapi.c
        cl /W4 /MD ..\..\tests\test_fileapi.c
        cl /W4 /MD ..\..\tests\test_winuser.c user32.lib
        cl /W4 /MD ..\..\tests\test_memoryapi.c
    popd
goto :EOF

:clean
    pushd build
        del /Q *.*
		del /Q Foo\*
		rmdir Foo
		pushd tests
			del /Q *.*
		popd
    popd
goto :EOF


