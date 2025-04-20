@echo off

cl /nologo /W4 type_hash.c
type_hash.exe
cl /W4 /Zi /nologo /Fe"hookgen" main.c user32.lib kernel32.lib
