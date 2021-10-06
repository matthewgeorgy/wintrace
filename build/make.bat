@echo off

cl /Zi /W4 /MP /LD ..\dll\*.c user32.lib kernel32.lib /Fe"wintrace.dll"

cl /Zi /W4 /MP ..\core\*.c user32.lib dbghelp.lib /Fe"wintrace.exe"
