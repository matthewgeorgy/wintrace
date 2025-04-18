@echo off

cl /Zi /W4 /MD /MP /Fe"testfile" test.c user32.lib kernel32.lib
cls

wintrace.exe testfile.exe
