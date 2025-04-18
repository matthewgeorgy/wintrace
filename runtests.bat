@echo off

pushd build
wintrace.exe /c /t /p tests\test_heapapi.exe
popd
