# wintrace

`wintrace` is a simple tracing utility for Windows programs.
It's essentially an `strace`/`ltrace` equivalent like on Linux, but for Windows.

It currently supports a wide range of Win32 functions, as well as some functions from the CRT. See
below for a complete list of supported functions (COMING SOON...).

## Usage

`wintrace` is a CLI tool, so it's very simple to start using.

The following is an available list of options for use with `wintrace`,
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

The only current limitation with using `wintrace` is that it requires your program to be compiled with
the DLL version of the CRT (C Runtime Library), `msvcrt.lib`. There are a few ways to do this with `cl`:

- Compiling your whole program with the `/MD` switch in MSVC  (`cl /MD ...`),
or `/MDd` for the debug version, `msvcrtd.lib`.

- Linking your program directly to `msvcrt.lib` (or `msvcrtd.lib` with `link`
(`link ... msvcrt.lib ...`).

See the Microsoft Docs on `cl` and `link` for more details. To specify `msvcrt/d.lib` in Visual Studio,
check either your Visual Studio Documentation, or the Microsoft Docs, to see how to specify
this lib in your project's property pages (I won't detail it here since it changes between version releases
of Visual Studio).

`wintrace` must also be built for the correct target platform of the program you wish to test. That is
to say, if you must build `wintrace` for x64 if you want to test an x64 executable (same story for x86).

In addition, `wintrace`'s numerical output (like the numbers found in function parameters is only
formatted correctly for x64. You can still build and run `wintrace` for x86, but note that some of the
numerical values will be incorrect. This will be addressed soon.

## How does it work?

To understand how `wintrace` works internally, you must first understand (at a basic level) how DLL's
work under Windows. I will not go into too much detail about how they work, as it is a well documented topic that you can
read about extensively online (namely MSDN). I will only focus on the parts that are relevant to wintrace and how it works.

### The Import Address Table (IAT)

One of the core components of the Windows PE (portable executable) file format is the "Import Address Table" (IAT for short).
The IAT is a table containing a list of all the functions that are to be dynamically linked to your program through a DLL. It contains
two pieces of information which we care about:
1) The function's name (as an ASCII string).
2) The function's address (function pointer).

When a PE is loaded into memory, one thing that needs to be done is that the function pointers for the dynamically-linked functions need
to be resolved. Say we need to use the Win32 function `HeapAlloc`, which comes from `kernel32.dll`. When we run our program, Windows first
needs to load `kernel32.dll` into memory (if it hasn't already). Once the DLL is loaded, Windows then needs to set the function pointer for
`HeapAlloc` in our program's IAT to point to the address of `HeapAlloc` loaded into memory in the DLL. That way, our program knows where the
function is in order to execute it (remember! `HeapAlloc` is DYNAMICALLY linked, not STATICALLY linked, so the function is not part of the .exe).

I've skipped over some of the details, but at its core this is how dynamic linking works under Windows, and it will suffice in order to understand
how wintrace works.

### DLL Injection

`wintrace` primarily works through a technique called "DLL Injection". It is a technique that allows you to run code inside of another process
by forcing it to load a DLL. This is because when you load a DLL, the `DllMain()` function of that DLL will then be invoked (if it exists). This is
where you put the code that you want to run. There are several ways of doing this, but the method I've chosen involves the use of a few Win32 functions
which I'll discuss below.

`CreateProcess` is a function that allows you to spawn a new process given an executable file name.

`LoadLibrary` is the function you use for loading a DLL into your program.

`CreateRemoteThread` is a function that allows you to create a new thread inside of an existing process. (You might be thinking "Wow, this sounds like a
huge security hole!", and you'd be right; except, you can only create a remote thread for a process that *your program created*, such as with `CreateProcess` :) ).

The process for doing DLL injection on a targeted .exe then looks something like this:
0. Get the program name and DLL name you wish to target.
1. Create a process with the program (.exe) name, with the `CREATE_SUSPENDED` flag so that the main thread does not immediately begin executing.
2. Create a remote thread in the process, setting the thread's entry function is `LoadLibrary`, and passing it the name of DLL you want.
3. Wait for the remote thread to finish executing (namely, it's `DllMain()`).
4. Resume the main thread of the target exe.

### Putting it all together

So we understand these two concepts now, but what are they good for? Well remember, wintrace is a tracing application - we want to be able to monitor the functions
that are being executed in real-time. How can this be done?

Simple! We simply define a function "hook" that essentially wraps a function we want to trace, and give it some additional behaviour. Here's a simple example:
```
LPVOID
HeapAlloc_Hooked(HANDLE hHeap,
		  		 DWORD dwFlags,
		  		 SIZE_T dwBytes)
{
	LPVOID		Result;

	printf("HeapAlloc(0x%p, 0x%u, 0x%u) = ", hHeap, dwFlags, dwBytes);
	Result = HeapAlloc(hHeap, dwFlags, dwBytes);
	printf("0x%p\n", Result);

	return Result;
}

```

As you can see, this hooked function gives us the information we want: it prints the call to `HeapAlloc()`, the parameters that were passed, and the return values!

Since we'll have many functions like this that we wish to hook, it would be a good idea to put them all into a `.dll` (not a `.lib` because we want to hook precompiled
binaries).

So now that we've got function hooks, how can we get our (already compiled) program to use them? Well we can just overwrite the IAT using some functions in Win32 from
the `DbgHelp` library. All we need to do is open our running program in memory, walk through all the functions in the IAT and overwrite their pointers. While this may sound
crazy, it's perfectly fine to do - if you do it correctly of course :). (While it should be obvious, I will also point out that we can only overwrite functions for which we
have hooks for).

### wintrace implementation

So how does wintrace do this? wintrace has two halves: `wintrace.exe` and `wintrace.dll`. `.exe` belongs to the `core\` folder; `.dll` belongs to the `dll\` folder.

`wintrace.dll` contains two things: the hooked function definitions and a `DllMain()` function. The hooked functions are exactly as I described above; Win32 hooks are
prefixed with `Wt`, CRT hooks are prefixed with `wt_`, and the hooks can be found in their respective folders under `dll\`. The `DllMain()` is where we actually
overwrite the IAT, which is done by calling the function `PatchIAT()`.

The purpose of `wintrace.exe` is to actually perform DLL injection into the target application
following the procedure outlined above. This can be seen in the main function of `core\main.c`.

