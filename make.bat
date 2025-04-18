@echo off

set wintrace=build\wintrace.exe

if [%1]==[]         goto :install
if "%1"=="clean"    goto :clean
if "%1"=="test"     goto :test
if "%1"=="all"      goto :all

goto :EOF

:install
    pushd build
        cl /W4 /MP /LD /Fe"wintrace.dll" ..\dll\*.c user32.lib kernel32.lib advapi32.lib
        cl /W4 /MP /Fe"wintrace.exe" ..\core\*.c kernel32.lib
    popd
goto :EOF

:clean
    pushd build
        del /Q *.*
		pushd tests
			del /Q *.*
		popd
    popd
goto :EOF

:test
    pushd build\tests
        cl /W4 /MD ..\..\tests\test_heapapi.c
    popd
goto :EOF

:all
    pushd build
        cl /W4 /MP /LD /Fe"wintrace.dll" ..\dll\*.c user32.lib kernel32.lib advapi32.lib
        cl /W4 /MP /Fe"wintrace.exe" ..\core\*.c kernel32.lib
        pushd tests
            cl /W4 /MD ..\..\tests\test_heapapi.c
        popd
    popd
goto :EOF
