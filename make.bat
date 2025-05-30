@echo off

if [%1]==[]         goto :install
if "%1"=="clean"    goto :clean
if "%1"=="test"     goto :test

:install
	pushd hookgen
		call make.bat
		call compile.bat
	popd
    pushd build
		cl /MP /W4 /c /nologo /I"..\dll\inc" ..\dll\crt\*.c ..\dll\win32\*.c ..\dll\*.c
		:: cl /W4 /c /I"..\dll\inc" ..\dll\win32\*.c
		:: cl /W4 /c /I"..\dll\inc" ..\dll\*.c
		link /DLL *.obj /nologo /OUT:wintrace.dll kernel32.lib user32.lib advapi32.lib
        cl /W4 /MP /nologo /Fe"wintrace.exe" ..\core\*.c kernel32.lib
    popd
if "%1"=="all"	goto :test
goto :EOF

:test
    pushd build\tests
        cl /W4 /MD /nologo ..\..\tests\test_heapapi.c
        cl /W4 /MD /nologo ..\..\tests\test_fileapi.c
        cl /W4 /MD /nologo ..\..\tests\test_winuser.c user32.lib
        cl /W4 /MD /nologo ..\..\tests\test_memoryapi.c
        cl /W4 /MD /nologo ..\..\tests\test_stdio.c
        cl /W4 /MD /nologo ..\..\tests\test_stdlib.c
        cl /W4 /MD /nologo ..\..\tests\test_threads.c
		del /Q *.obj
    popd
goto :EOF

:clean
    pushd build
        del /Q *.obj *.exe *.pdb *.ilk *.lib *.exp *.dll
		del /Q Foo\*
		rmdir Foo
		pushd tests
			del /Q *.exe
		popd
    popd
goto :EOF

