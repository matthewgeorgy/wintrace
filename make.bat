@echo off

set wintrace=build\wintrace.exe

if [%1]==[]			goto :install
if "%1"=="clean"	goto :clean
if "%1"=="test"		goto :test

goto :EOF

:install
	pushd build
	cl /W4 /MP /LD /Fe"wintrace.dll" w:\wintrace\dll\*.c user32.lib kernel32.lib advapi32.lib
	cl /W4 /MP /Fe"wintrace.exe" w:\wintrace\core\*.c kernel32.lib
	popd
goto :EOF

:clean
	pushd build
	del *.exe *.obj *.lib *.dll *.exp *.ilk *.pdb
	popd
goto :EOF

:test
	pushd build
	cl /W4 /MD w:\wintrace\tests\test_heapapi.c
	popd
goto :EOF