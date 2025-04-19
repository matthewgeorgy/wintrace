#ifndef FUNC_HASHES_H
#define FUNC_HASHES_H

// debugapi.h
#define FUNC_CheckRemoteDebuggerPresent 107187221
#define FUNC_ContinueDebugEvent 2549675251
#define FUNC_DebugActiveProcess 3798885479
#define FUNC_DebugActiveProcessStop 2188885901
#define FUNC_DebugBreak 3528731537
#define FUNC_IsDebuggerPresent 3869395015
#define FUNC_OutputDebugStringA 2037555093
#define FUNC_OutputDebugStringW 2037555115
#define FUNC_WaitForDebugEvent 3195682730
// fileapi.h
#define FUNC_CreateDirectoryA 1106952175
#define FUNC_CreateDirectoryW 1106952197
#define FUNC_CreateFileA 3952526842
#define FUNC_CreateFileW 3952526864
#define FUNC_DeleteFileA 483952409
#define FUNC_DeleteFileW 483952431
#define FUNC_GetFileSize 2022819104
#define FUNC_GetFileSizeEx 3826751101
#define FUNC_GetFileType 2022872135
#define FUNC_ReadFile 1895930145
#define FUNC_ReadFileEx 3083628222
#define FUNC_RemoveDirectoryA 1100116521
#define FUNC_RemoveDirectoryW 1100116543
#define FUNC_SetEndOfFile 1696626301
#define FUNC_SetFilePointer 1408199666
#define FUNC_SetFilePointerEx 226113999
#define FUNC_WriteFile 1715268784
#define FUNC_WriteFileEx 3911901709
// heapapi.h
#define FUNC_GetProcessHeap 3327659266
#define FUNC_GetProcessHeaps 2438573493
#define FUNC_HeapAlloc 536700686
#define FUNC_HeapCompact 3053059978
#define FUNC_HeapCreate 616373623
#define FUNC_HeapDestroy 3960452205
#define FUNC_HeapFree 927503301
#define FUNC_HeapLock 927715596
#define FUNC_HeapQueryInformation 2411812863
#define FUNC_HeapReAlloc 506577189
#define FUNC_HeapSetInformation 4089094677
#define FUNC_HeapSize 927961374
#define FUNC_HeapUnlock 1316333263
#define FUNC_HeapValidate 3315282893
#define FUNC_HeapWalk 928095954
// memoryapi.h
#define FUNC_CreateFileMappingA 4081056902
#define FUNC_CreateFileMappingW 4081056924
#define FUNC_FlushViewOfFile 2411283351
#define FUNC_MapViewOfFile 299806899
#define FUNC_MapViewOfFileEx 72200912
#define FUNC_OpenFileMappingA 1942271556
#define FUNC_OpenFileMappingW 1942271578
#define FUNC_UnmapViewOfFile 3594121814
#define FUNC_VirtualAlloc 942411671
#define FUNC_VirtualAllocEx 4084095668
#define FUNC_VirtualFree 1720700718
#define FUNC_VirtualFreeEx 1237343243
#define FUNC_VirtualLock 1720913013
#define FUNC_VirtualProtect 2219831693
#define FUNC_VirtualProtectEx 3625095722
#define FUNC_VirtualQuery 961702338
#define FUNC_VirtualQueryEx 3616795551
#define FUNC_VirtualUnlock 1819893880
// processthreadsapi.h
#define FUNC_CreateProcessA 2931109401
#define FUNC_CreateProcessW 2931109423
#define FUNC_CreateProcessAsUserA 2958281772
#define FUNC_CreateProcessAsUserW 2958281794
#define FUNC_CreateRemoteThread 2855303005
#define FUNC_CreateRemoteThreadEx 4163619834
#define FUNC_CreateThread 2131293265
#define FUNC_DeleteProcThreadAttributeList 672166644
#define FUNC_ExitProcess 3077125022
#define FUNC_ExitThread 2060145751
#define FUNC_GetCurrentProcess 3398268199
#define FUNC_GetCurrentProcessId 2747229364
#define FUNC_ResumeThread 1947609710
#define FUNC_SuspendThread 2348241503
#define FUNC_TerminateProcess 1622083437
#define FUNC_TerminateThread 2276354630
// profileapi.h
#define FUNC_QueryPerformanceCounter 3679327501
#define FUNC_QueryPerformanceFrequency 1087381631
// winuser.h
#define FUNC_AdjustWindowRect 2713507990
#define FUNC_AdjustWindowRectEx 72703859
#define FUNC_BeginPaint 3709176934
#define FUNC_ClientToScreen 4019554119
#define FUNC_ClipCursor 2721823819
#define FUNC_CloseWindow 1543434227
#define FUNC_CreateWindowA 1227009330
#define FUNC_CreateWindowW 1227009352
#define FUNC_CreateWindowExA 478339695
#define FUNC_CreateWindowExW 478339717
#define FUNC_DefWindowProcA 1760583233
#define FUNC_DefWindowProcW 1760583255
#define FUNC_DestroyWindow 344202887
#define FUNC_DispatchMessageA 2879414363
#define FUNC_DispatchMessageW 2879414385
#define FUNC_EndPaint 739920600
#define FUNC_FillRect 2887030522
#define FUNC_GetClientRect 2958303922
#define FUNC_GetCursorPos 821011093
#define FUNC_GetDC 222110892
#define FUNC_GetMessageA 3419322795
#define FUNC_GetMessageW 3419322817
#define FUNC_GetWindowRect 4136403979
#define FUNC_MessageBoxA 944706740
#define FUNC_MessageBoxW 944706762
#define FUNC_MessageBoxExA 2288464497
#define FUNC_MessageBoxExW 2288464519
#define FUNC_PeekMessageA 227682608
#define FUNC_PeekMessageW 227682630
#define FUNC_PostMessageA 2485462673
#define FUNC_PostMessageW 2485462695
#define FUNC_PostQuitMessage 563058387
#define FUNC_RegisterClassExA 2469310590
#define FUNC_RegisterClassExW 2469310612
#define FUNC_ReleaseDC 3828904397
#define FUNC_ScreenToClient 2379331655
#define FUNC_ShowCursor 3042291940
#define FUNC_ShowWindow 3810608670
#define FUNC_TranslateMessage 3846330968
#define FUNC_UpdateWindow 3899713536
// stdio.h
#define FUNC_fopen 259230589
#define FUNC__wfopen 2980484915
#define FUNC_fclose 4245278497
// stdlib.h
#define FUNC_malloc 221883709
#define FUNC_free 2090266759

#endif // FUNC_HASHES_H
