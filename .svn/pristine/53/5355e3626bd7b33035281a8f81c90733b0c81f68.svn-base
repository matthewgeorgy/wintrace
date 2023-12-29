# wintrace

`wintrace` is a simple tracing utility for Windows programs. \
It's essentially an `strace`/`ltrace` equivalent like on Linux, but for Windows.

It currently supports a wide range of Win32 functions, as well as some functions from the CRT. See \
below for a complete list of supported functions (COMING SOON...).

## Usage

`wintrace` is a CLI tool, so it's very simple to start using.

The following is an available list of options for use with `wintrace`, \
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
```

The full format `wintrace`'s output follows as:

`[Process ID] <Thread ID> (Call Cnt) FunctionName(Args...) = Return Value`.

## Limitations

The only current limitation with using `wintrace` is that it requires your program to be compiled with \
the DLL version of the CRT (C Runtime Library), `msvcrt.lib`. There are a few ways to do this with `cl`:

- Compiling your whole program with the `/MD` switch in MSVC  (`cl /MD ...`),
or `/MDd` \
for the debug version, `msvcrtd.lib`.

- Linking your program directly to `msvcrt.lib` (or `msvcrtd.lib` with `link` \
(`link ... msvcrt.lib ...`).

See the Microsoft Docs on `cl` and `link` for more details. To specify `msvcrt/d.lib` in Visual Studio, \
check either your Visual Studio Documentation, or the Microsoft Docs, to see how to specify \
this lib in your project's property pages (I won't detail it here since it changes between version releases \
of Visual Studio).

`wintrace` must also be built for the correct target platform of the program you wish to test. That is \
to say, if you must build `wintrace` for x64 if you want to test an x64 executable (same story for x86).

In addition, `wintrace`'s numerical output (like the numbers found in function parameters is only \
formatted correctly for x64. You can still build and run `wintrace` for x86, but note that some of the \
numerical values will be incorrect. This will be addressed soon.

## How does it work?

To understand how `wintrace` works internally, you must first understand (at a basic level) how DLL's \
work under Windows.

### DLL Injection

`wintrace` primarily works through a process called "DLL Injection".


### More coming soon...

'core' contains the executable
'dll' contains the dll with hooked functions that are injected

