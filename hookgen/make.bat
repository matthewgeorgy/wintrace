@echo off

cl type_hash.c
type_hash.exe
cl /W4 /Zi /MP /Fe"hookgen" main.c user32.lib kernel32.lib
