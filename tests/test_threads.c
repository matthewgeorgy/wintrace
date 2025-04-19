#include <stdio.h>
#include <process.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define LOOP_COUNT	1

void	TaskLocked(void *);
void 	TaskUnlocked(void *);

HANDLE Threads[5];
HANDLE Mutex;
HANDLE File;

int
main(void)
{
	CHAR ClearLine[16] = "\r\n\r\n";

	Mutex = CreateMutex(NULL, FALSE, NULL);
	if (!Mutex)
	{
		printf("failed to create mutex! %d\r\n", GetLastError());
		return 1;
	}

	File = CreateFileA("blah.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!File)
	{
		printf("failed to create file!...%d\r\n", GetLastError());
		return -1;
	}

	printf("-----------LOCKED------------\r\n\r\n");

	Threads[0] = (HANDLE)_beginthread(&TaskLocked, 0, "First\r\n");
	Threads[1] = (HANDLE)_beginthread(&TaskLocked, 0, "Second\r\n");
	Threads[2] = (HANDLE)_beginthread(&TaskLocked, 0, "Third\r\n");
	Threads[3] = (HANDLE)_beginthread(&TaskLocked, 0, "Fourth\r\n");
	Threads[4] = (HANDLE)_beginthread(&TaskLocked, 0, "Fifth\r\n");

	WaitForMultipleObjects(5, Threads, TRUE, INFINITE);
	WriteFile(File, ClearLine, strlen(ClearLine), NULL, NULL);

	printf("-----------UNLOCKED------------\r\n\r\n");

	Threads[0] = (HANDLE)_beginthread(&TaskUnlocked, 0, "First\r\n");
	Threads[1] = (HANDLE)_beginthread(&TaskUnlocked, 0, "Second\r\n");
	Threads[2] = (HANDLE)_beginthread(&TaskUnlocked, 0, "Third\r\n");
	Threads[3] = (HANDLE)_beginthread(&TaskUnlocked, 0, "Fourth\r\n");
	Threads[4] = (HANDLE)_beginthread(&TaskUnlocked, 0, "Fifth\r\n");

	WaitForMultipleObjects(5, Threads, TRUE, INFINITE);

	CloseHandle(File);

	return 0;
}

void 
TaskLocked(void *String)
{
	INT 		i;
	CHAR 		*Ch;
	DWORD 		WaitResult;


	for (i = 0; i < LOOP_COUNT; i++)
	{
		WaitResult = WaitForSingleObject(Mutex, INFINITE);

		switch (WaitResult)
		{
			case WAIT_OBJECT_0:
			{
				for (Ch = (char *)String; *Ch; ++Ch)
				{
					WriteFile(File, Ch, 1, NULL, NULL);
				}
				ReleaseMutex(Mutex);
			} break;
		}
	}
}

void 
TaskUnlocked(void *String)
{
	INT 		i;
	CHAR 		*Ch;


	for (i = 0; i < LOOP_COUNT; i++)
	{
		for (Ch = (CHAR *)String; *Ch; ++Ch)
		{
			WriteFile(File, Ch, 1, NULL, NULL);
		}
	}
}


