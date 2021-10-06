@echo off

cl /Zi /W4 /MP /LD lib.c user32.lib kernel32.lib

cl /Zi /W4 /MP main.c user32.lib

cl /Zi /W4 /MP inject.c user32.lib dbghelp.lib
