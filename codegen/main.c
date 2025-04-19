#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFF_SIZE		1024 * 1024

typedef struct _tag_Function
{
	CHAR		Name[64];
	CHAR		ReturnType[32];
	CHAR		ArgTypes[16][32];
	CHAR		ArgNames[16][32];
	INT			ArgCount;
} T_Function;

typedef struct _tag_Buffer
{
	CHAR		*Buff;
	SIZE_T		Pos;
} T_Buffer;

CHAR			**StringFile(char *filename, int *plen);
T_Function		*ParseFunctions(CHAR *Filename, INT *Count);
void			WriteBuffer(T_Buffer *Buffer, char *Format, ...);

int
main(void)
{
	T_Function		*Functions;
	INT				Count;
	T_Function		Func;
	T_Buffer		Buffer;
	INT				Ptr;


	Functions = ParseFunctions("in.txt", &Count);
	Buffer.Buff = (CHAR *)malloc(BUFF_SIZE);
	Buffer.Pos = 0;
	Func = Functions[0];

	WriteBuffer(&Buffer, "%s\nWt%s", Func.ReturnType, Func.Name);
	WriteBuffer(&Buffer, "(");

	if (Func.ArgCount == 0)
	{
		WriteBuffer(&Buffer, ")\n");
	}
	else
	{
		INT Commas = Func.ArgCount - 1;

		WriteBuffer(&Buffer, "\n");

		for (INT I = 0; I < Func.ArgCount; I++)
		{
			WriteBuffer(&Buffer, "\t %s %s", Func.ArgTypes[I], Func.ArgNames[I]);

			if (Commas > 0)
			{
				WriteBuffer(&Buffer, ",");
				Commas--;
			}

			WriteBuffer(&Buffer, "\n");
		}

		WriteBuffer(&Buffer, ")");
	}


	printf("%s\n", Buffer.Buff);

	return (0);
}

T_Function *
ParseFunctions(CHAR *Filename,
			   INT *Count)
{
	T_Function		*Functions;
	CHAR			**File,
					*Signature,
					*Temp;
	INT				Len;


	File = StringFile(Filename, &Len);
	Functions = (T_Function *)calloc(1, Len * sizeof(*Functions));
	*Count = Len;

	for (INT J = 0; J < Len; J++)
	{
		Signature = File[J];

		// Type
		Temp = strtok(Signature, " ,()");
		memcpy(Functions[J].ReturnType, Temp, strlen(Temp));

		// Name
		Temp = strtok(NULL, "(");
		memcpy(Functions[J].Name, Temp, strlen(Temp));

		// Arguments
		INT Arg = 0;
		while (Temp != NULL)
		{
			Temp = strtok(NULL, " ");
			if (!Temp)
				break;
			memcpy(Functions[J].ArgTypes[Arg], Temp, strlen(Temp));

			Temp = strtok(NULL, ",)");
			if (!Temp)
				break;
			memcpy(Functions[J].ArgNames[Arg], Temp, strlen(Temp));

			Arg++;
		}
		Functions[J].ArgCount = Arg;

		printf("\tType: %s\n", Functions[J].ReturnType);
		printf("\tName: %s\n", Functions[J].Name);
		printf("\tCount: %d\n", Functions[J].ArgCount);
		for (INT I = 0; I < Functions[J].ArgCount; I++)
		{
			printf("\t\tType %d: %s\n", I, Functions[J].ArgTypes[I]);
			printf("\t\tName %d: %s\n", I, Functions[J].ArgNames[I]);
		}
	}

	return (Functions);
}

CHAR **
StringFile(char *filename, int *plen)
{
	HANDLE				f;
	char				*buffer, **list = NULL, *s;
	size_t				len, count, i;
	LARGE_INTEGER		large_int;

	f = CreateFile(filename, GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!f) return NULL;
	GetFileSizeEx(f, &large_int);
	len = large_int.QuadPart;
	buffer = (char *)HeapAlloc(GetProcessHeap(), 0, len + 1);
	ReadFile(f, buffer, (DWORD)len, (LPDWORD)&len, NULL);
	buffer[len] = 0;
	CloseHandle(f);

   // two passes through: first time count lines, second time set them
   for (i=0; i < 2; ++i) {
      s = buffer;
      if (i == 1)
         list[0] = s;
      count = 1;
      while (*s) {
         if (*s == '\n' || *s == '\r') {
            // detect if both cr & lf are together
            int crlf = (s[0] + s[1]) == ('\n' + '\r');
            if (i == 1) *s = 0;
            if (crlf) ++s;
            if (s[1]) {  // it's not over yet
               if (i == 1) list[count] = s+1;
               ++count;
            }
         }
         ++s;
      }
      if (i == 0) {
         list = (char **)HeapAlloc(GetProcessHeap(), 0, sizeof(*list) * (count+1) + len+1);
         if (!list) return NULL;
         list[count] = 0;
         // recopy the file so there's just a single allocation to free
         memcpy(&list[count+1], buffer, len+1);
         HeapFree(GetProcessHeap(), 0, buffer);
         buffer = (char *) &list[count+1];
         if (plen) *plen = (int) count;
      }
   }
   return list;
}

void			
WriteBuffer(T_Buffer *Buffer, 
			char *Format,
			...)
{
	SIZE_T		Bytes;
	va_list		VarArgs;


	va_start(VarArgs, Format);

	Bytes = vsprintf(Buffer->Buff + Buffer->Pos, Format, VarArgs);
	Buffer->Pos += Bytes;

	va_end(VarArgs);
}

