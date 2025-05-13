# wintrace

wintrace is a simple tracing utility for Windows programs.
It's essentially an strace/ltrace equivalent like on Linux, but for Windows.

It currently supports a wide range of Win32 functions, as well as some functions from the CRT. See [supported_functions.md](supported_functions.md) for a list of supported functions.

## Build instructions

**NOTE: Currently, only building for x64 is supported.**

### 1. Requirements

To work with the codebase, you'll need Visual Studio 2015 (or later) and the Windows SDK.

### 2. Build environment setup

Building the codebase must be done in a terminal that can call MSVC. This is generally done by calling `vcvarsall.bat x64` in the Visual Studio install directory. 

Alternatively, you can use the developer command prompt that is provided with the Visual Studio install. It is typically called something like `x64 Native Tools Command Prompt for VS <year>`.

You can ensure that the MSVC compiler is accessible from your command line by running:
```
cl
```

If everything is set up correctly, you should have output similar to the following:
```
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

### 3. Building

Start by cloning the repo:


```
git clone https://github.com/matthewgeorgy/wintrace/
cd wintrace
```

Building wintrace is done by using the `make.bat` script in the root of the directory. You have multiple options:

```
make            (builds the core executable wintrace.exe and DLL wintrace.dll)
make install    (same as above)
make test       (builds the tests)
make all        (builds everything)
make clean      (cleans the build\ directory)
```

## Usage

wintrace is a CLI tool, so it's very simple to start using.

The following is an available list of options you can specify,
which can be obtained by running `wintrace /?`.

```
Usage: wintrace [options...] <exe> [args...]

Options:
  /c            Show function call count
  /p            Show process ID
  /t            Show thread ID
  /T:fns        Trace only fns, a comma separated list of function names
  /o:file       Output to file
  /?            Show available options
```

Here is some sample output, taken from running the `test_fileapi` test:
```
> wintrace /c /t /p tests\test_fileapi.exe
[CORE] Initialized successfully:
  PID: 7008
  Opts: WintraceOpts_7008
  Pipe: \\.\pipe\WintracePipe_7008
  Fence: WintraceFence_7008
[CORE] Created pipe...
[DLL] Connected pipe...
[DLL] Opened the fence...
[CORE] Connected pipe...
|------------TEST: ..\..\tests\test_fileapi.c------------|
[7008] <3484> (1)  CreateDirectoryA("Foo", 0x0000000000000000) = 1
[7008] <3484> (1)  CreateFileA("Foo\bar.txt", 3221225472, 0, 0x0000000000000000, 2, 128, 0x0000000000000000) = 0x00000000000000A0
[7008] <3484> (1)  WriteFile(0x00000000000000A0, 0x00007FF6A3FE3000, 14, 0x0000000000FEFC60, 0x0000000000000000) = 1
[7008] <3484> (1)  SetFilePointer(0x00000000000000A0, 0, 0x0000000000000000, 0) = 0
[7008] <3484> (1)  ReadFile(0x00000000000000A0, 0x0000000000FEFC70, 199, 0x0000000000FEFC54, 0x0000000000000000) = 1
[7008] <3484> (1)  DeleteFileA("Foo\bar.txt") = 1
[7008] <3484> (1)  RemoveDirectoryA("Foo") = 1

[7008] <3484> (1)  CreateDirectoryW("Foo", 0x0000000000000000) = 1
[7008] <3484> (1)  CreateFileW("Foo\bar.txt", 3221225472, 0, 0x0000000000000000, 2, 128, 0x0000000000000000) = 0x0000000000000058
[7008] <3484> (2)  WriteFile(0x0000000000000058, 0x00007FF6A3FE3000, 14, 0x0000000000FEFC60, 0x0000000000000000) = 1
[7008] <3484> (2)  SetFilePointer(0x0000000000000058, 0, 0x0000000000000000, 0) = 0
[7008] <3484> (2)  ReadFile(0x0000000000000058, 0x0000000000FEFC70, 199, 0x0000000000FEFC54, 0x0000000000000000) = 1
[7008] <3484> (1)  DeleteFileW("Foo\bar.txt") = 0 (ERROR: 32)
[7008] <3484> (1)  RemoveDirectoryW("Foo") = 0 (ERROR: 145)
|-----------------------------|
```

The full format of wintrace's output is as follows:

`[Process ID] <Thread ID> (Call count) FunctionName(Args...) = Return Value`

## Limitations

The only current "limitation" with using wintrace actually has to do with the CRT. If your target program statically links to the CRT, then the output from wintrace will be polluted with a lot of extra function calls that come from the CRT internally. This is especially noticeable at program startup/exit where the CRT initializes/deinitializes.

As an example, consider `malloc` and `free`. Commonly, in CRT implementations, these are actually just stubs that call into the Win32 functions `HeapAlloc` and `HeapFree`, respectively. If the CRT is statically linked, then these heap function calls will go directly in your executable, and you'll see them in the output where you call `malloc` and `free`. Furthermore, the heap functions require a heap handle (such as from `GetProcessHeap`). Many CRT implementations actually create a separate, private heap that is specfically for use by CRT functions like `malloc` and `free`. So, if you see a call to `HeapCreate` in the startup of your program, then that's probabaly what that is.

There are only two ways (that I know of) to get around this problem:

1. Dynamically link to the CRT, which can be done in several ways. The simplest is with the `/MD` switch.

2. Don't link to the CRT at all: https://gist.github.com/mmozeiko/81e9c0253cc724638947a53b826888e9.

## How does it work?

Coming soon.

