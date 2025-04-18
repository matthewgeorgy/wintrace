@echo off

cl /W4 /MP /LD /Fe"wintrace.dll" w:\wintrace\dll\*.c user32.lib kernel32.lib

cl /W4 /MP /Fe"wintrace.exe" w:\wintrace\core\*.c kernel32.lib
