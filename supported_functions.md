# Supported function list

Below is a list of all the functions currently supported by `wintrace`, sorted by library / header file

## debugapi

<ul>
<li>CheckRemoteDebuggerPresent</li>
<li>ContinueDebugEvent</li>
<li>DebugActiveProcess</li>
<li>DebugActiveProcessStop</li>
<li>DebugBreak</li>
<li>IsDebuggerPresent</li>
<li>OutputDebugStringA</li>
<li>OutputDebugStringW</li>
<li>WaitForDebugEvent</li>
</ul>

## fileapi

<ul>
<li>CreateDirectoryA</li>
<li>CreateDirectoryW</li>
<li>CreateFileA</li>
<li>CreateFileW</li>
<li>DeleteFileA</li>
<li>DeleteFileW</li>
<li>GetFileSize</li>
<li>GetFileSizeEx</li>
<li>GetFileType</li>
<li>ReadFile</li>
<li>ReadFileEx</li>
<li>RemoveDirectoryA</li>
<li>RemoveDirectoryW</li>
<li>SetEndOfFile</li>
<li>SetFilePointer</li>
<li>SetFilePointerEx</li>
<li>WriteFile</li>
<li>WriteFileEx</li>
</ul>

## heapapi

<ul>
<li>GetProcessHeap</li>
<li>GetProcessHeaps</li>
<li>HeapAlloc</li>
<li>HeapCompact</li>
<li>HeapCreate</li>
<li>HeapDestroy</li>
<li>HeapFree</li>
<li>HeapLock</li>
<li>HeapQueryInformation</li>
<li>HeapReAlloc</li>
<li>HeapSetInformation</li>
<li>HeapSize</li>
<li>HeapUnlock</li>
<li>HeapValidate</li>
<li>HeapWalk</li>
</ul>

## memoryapi

<ul>
<li>CreateFileMappingA</li>
<li>CreateFileMappingW</li>
<li>FlushViewOfFile</li>
<li>MapViewOfFile</li>
<li>MapViewOfFileEx</li>
<li>OpenFileMappingA</li>
<li>OpenFileMappingW</li>
<li>UnmapViewOfFile</li>
<li>VirtualAlloc</li>
<li>VirtualAllocEx</li>
<li>VirtualFree</li>
<li>VirtualFreeEx</li>
<li>VirtualLock</li>
<li>VirtualProtect</li>
<li>VirtualProtectEx</li>
<li>VirtualQuery</li>
<li>VirtualQueryEx</li>
<li>VirtualUnlock</li>
</ul>

## processthreadsapi

<ul>
<li>CreateProcessA</li>
<li>CreateProcessW</li>
<li>CreateProcessAsUserA</li>
<li>CreateProcessAsUserW</li>
<li>CreateRemoteThread</li>
<li>CreateRemoteThreadEx</li>
<li>CreateThread</li>
<li>DeleteProcThreadAttributeList</li>
<li>ExitProcess</li>
<li>ExitThread</li>
<li>GetCurrentProcess</li>
<li>GetCurrentProcessId</li>
<li>ResumeThread</li>
<li>SuspendThread</li>
<li>TerminateProcess</li>
<li>TerminateThread</li>
</ul>

## profileapi

<ul>
<li>QueryPerformanceCounter</li>
<li>QueryPerformanceFrequency</li>
</ul>

## winuser

<ul>
<li>AdjustWindowRect</li>
<li>AdjustWindowRectEx</li>
<li>BeginPaint</li>
<li>ClientToScreen</li>
<li>ClipCursor</li>
<li>CloseWindow</li>
<li>CreateWindowA</li>
<li>CreateWindowW</li>
<li>CreateWindowExA</li>
<li>CreateWindowExW</li>
<li>DefWindowProcA</li>
<li>DefWindowProcW</li>
<li>DestroyWindow</li>
<li>DispatchMessageA</li>
<li>DispatchMessageW</li>
<li>EndPaint</li>
<li>FillRect</li>
<li>GetClientRect</li>
<li>GetCursorPos</li>
<li>GetDC</li>
<li>GetMessageA</li>
<li>GetMessageW</li>
<li>GetWindowRect</li>
<li>MessageBoxA</li>
<li>MessageBoxW</li>
<li>MessageBoxExA</li>
<li>MessageBoxExW</li>
<li>PeekMessageA</li>
<li>PeekMessageW</li>
<li>PostMessageA</li>
<li>PostMessageW</li>
<li>PostQuitMessage</li>
<li>RegisterClassExA</li>
<li>RegisterClassExW</li>
<li>ReleaseDC</li>
<li>ScreenToClient</li>
<li>ShowCursor</li>
<li>ShowWindow</li>
<li>TranslateMessage</li>
<li>UpdateWindow</li>
</ul>

## syncapi

<ul>
<li>CreateMutexA</li>
<li>CreateMutexW</li>
<li>CreateMutexExA</li>
<li>CreateMutexExW</li>
<li>ReleaseMutex</li>
<li>CreateSemaphoreExW</li>
<li>ReleaseSemaphore</li>
<li>CreateEventA</li>
<li>CreateEventW</li>
<li>CreateEventExA</li>
<li>CreateEventExW</li>
<li>SetEvent</li>
<li>ResetEvent</li>
<li>InitializeCriticalSection</li>
<li>EnterCriticalSection</li>
<li>LeaveCriticalSection</li>
<li>InitializeCriticalSectionAndSpinCount</li>
<li>InitializeCriticalSectionEx</li>
<li>SetCriticalSectionSpinCount</li>
<li>TryEnterCriticalSection</li>
<li>DeleteCriticalSection</li>
<li>WaitForSingleObject</li>
<li>WaitForSingleObjectEx</li>
<li>WaitForMultipleObjectsEx</li>
<li>SleepEx</li>
</ul>

## stdio

<ul>
<li>fopen</li>
<li>_wfopen</li>
<li>fclose</li>
<li>feof</li>
<li>ferror</li>
<li>fflush</li>
<li>fread</li>
<li>fwrite</li>
<li>fseek</li>
<li>ftell</li>
</ul>

## stdlib

<ul>
<li>atof</li>
<li>atoi</li>
<li>atol</li>
<li>malloc</li>
<li>calloc</li>
<li>realloc</li>
<li>free</li>
</ul>

