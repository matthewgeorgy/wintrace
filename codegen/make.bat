@echo off

cl hash.c
hash.exe
cl /W4 /Zi /MP /Fe"hookgen" main.c user32.lib kernel32.lib
