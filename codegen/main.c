#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "hashes.h"

#define BUFF_SIZE		1024 * 1024 // 1 MB

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
void			GetFormat(CHAR *Format, CHAR *Type);
DWORD			Djb2(LPSTR String);

int
main(int argc,
	 char **argv)
{
	T_Function		*Functions;
	INT				Count,
					Len;
	T_Buffer		SourceBuffer,
					HeaderBuffer;
	HANDLE 			HeaderFile,
					SourceFile;
	CHAR			**File,
					*ListName,
					*HeaderName,
					*SourceName,
					*Prefix,
					*IncludeGuard;
	INT				Commas;


	if (argc < 3)
	{
		printf("No input file provided...!\r\n");
		printf("Usage: hookgen <file> <prefix>\r\n");
		return (-1);
	}

	ListName = argv[1];
	Prefix = argv[2];

	Len = (INT)strlen(ListName);
	HeaderName = (CHAR *)malloc(Len + 3);
	SourceName = (CHAR *)malloc(Len + 3);
	memcpy(HeaderName, ListName, Len);
	memcpy(SourceName, ListName, Len);

	HeaderName[Len] = '.';
	HeaderName[Len + 1] = 'h';
	HeaderName[Len + 2] = 0;
	SourceName[Len] = '.';
	SourceName[Len + 1] = 'c';
	SourceName[Len + 2] = 0;

	Functions = ParseFunctions(ListName, &Count);

	SourceBuffer.Buff = (CHAR *)malloc(BUFF_SIZE);
	SourceBuffer.Pos = 0;

	WriteBuffer(&SourceBuffer, "#include <win32/%s>\n\n", HeaderName);
	WriteBuffer(&SourceBuffer, "extern T_WintraceOpts\t\t*pOpts;\n\n");

	for (INT J = 0; J < Count; J++)
	{
		T_Function Func = Functions[J];

		WriteBuffer(&SourceBuffer, "%s\n%s%s", Func.ReturnType, Prefix, Func.Name);
		WriteBuffer(&SourceBuffer, "(");

		if (Func.ArgCount == 0)
		{
			WriteBuffer(&SourceBuffer, ")");
		}
		else
		{
			Commas = Func.ArgCount - 1;

			WriteBuffer(&SourceBuffer, "\n");

			for (INT I = 0; I < Func.ArgCount; I++)
			{
				WriteBuffer(&SourceBuffer, "\t %s %s", Func.ArgTypes[I], Func.ArgNames[I]);

				if (Commas > 0)
				{
					WriteBuffer(&SourceBuffer, ",");
					Commas--;
				}

				WriteBuffer(&SourceBuffer, "\n");
			}

			WriteBuffer(&SourceBuffer, ")");
		}

		WriteBuffer(&SourceBuffer, "\n{\n");

		// Create stack
		if (strcmp(Func.ReturnType, "void"))
		{
			WriteBuffer(&SourceBuffer, "\t%s Ret;\n\n", Func.ReturnType);
		}

		// BeginTrace
		WriteBuffer(&SourceBuffer, "\tif (BeginTrace(E_%s))\n\t{\n", Func.Name);
		WriteBuffer(&SourceBuffer, "\t\tWriteFuncBuffer(\"(");

		// Arguments in WriteFuncBuffer string
		Commas = Func.ArgCount - 1;
		for (INT K = 0; K < Func.ArgCount; K++)
		{
			CHAR Format[8];
			GetFormat(Format, Func.ArgTypes[K]);
			WriteBuffer(&SourceBuffer, "%s", Format);
			if (Commas)
			{
				WriteBuffer(&SourceBuffer, ", ");
				Commas--;
			}
		}
		WriteBuffer(&SourceBuffer, ")\"");

		// Arguments in WriteFuncBuffer varargs
		Commas = Func.ArgCount - 1;
		if (Func.ArgCount > 0)
		{
			WriteBuffer(&SourceBuffer, ",");
		}
		for (INT K = 0; K < Func.ArgCount; K++)
		{
			WriteBuffer(&SourceBuffer, " %s", Func.ArgNames[K]);
			if (Commas)
			{
				WriteBuffer(&SourceBuffer, ",");
				Commas--;
			}
		}
		WriteBuffer(&SourceBuffer, ");\n");

		// Call the real function
		// We call it inside the BeginTrace block if it's a non-void function.
		// Otherwise, it gets called outside the block
		if (strcmp(Func.ReturnType, "void"))
		{
			WriteBuffer(&SourceBuffer, "\t\tRet = %s(", Func.Name);
			Commas = Func.ArgCount - 1;
			for (INT K = 0; K < Func.ArgCount; K++)
			{
				WriteBuffer(&SourceBuffer, "%s", Func.ArgNames[K]);
				if (Commas)
				{
					WriteBuffer(&SourceBuffer, ", ");
					Commas--;
				}
			}
			WriteBuffer(&SourceBuffer, ");\n");
		}

		// WriteFuncBuffer hook function return value
		WriteBuffer(&SourceBuffer, "\t\tWriteFuncBuffer(\" = ");
		if (strcmp(Func.ReturnType, "void"))
		{
			CHAR Format[8];
			GetFormat(Format, Func.ReturnType);
			WriteBuffer(&SourceBuffer, "%s\", Ret", Format);
		}
		else
		{
			WriteBuffer(&SourceBuffer, "VOID");
		}
		WriteBuffer(&SourceBuffer, ");\n");

		// EndTrace
		WriteBuffer(&SourceBuffer, "\t\tEndTrace(E_%s, FALSE);\n", Func.Name);

		WriteBuffer(&SourceBuffer, "\t}\n");

		if (strcmp(Func.ReturnType, "void"))
		{
			WriteBuffer(&SourceBuffer, "\telse\n\t{\n");
			WriteBuffer(&SourceBuffer, "\t\tRet = ");
			WriteBuffer(&SourceBuffer, "%s(", Func.Name);

			Commas = Func.ArgCount - 1;
			for (INT K = 0; K < Func.ArgCount; K++)
			{
				WriteBuffer(&SourceBuffer, "%s", Func.ArgNames[K]);
				if (Commas)
				{
					WriteBuffer(&SourceBuffer, ", ");
					Commas--;
				}
			}

			WriteBuffer(&SourceBuffer, ");");
			WriteBuffer(&SourceBuffer, "\n\t}\n");
		}
		else
		{
			WriteBuffer(&SourceBuffer, "\n\t%s(", Func.Name);

			Commas = Func.ArgCount - 1;
			for (INT K = 0; K < Func.ArgCount; K++)
			{
				WriteBuffer(&SourceBuffer, "%s", Func.ArgNames[K]);
				if (Commas)
				{
					WriteBuffer(&SourceBuffer, ", ");
					Commas--;
				}
			}

			WriteBuffer(&SourceBuffer, ");");
		}

		// Return variable return
		if (strcmp(Func.ReturnType, "void"))
		{
			WriteBuffer(&SourceBuffer,
				"\n\treturn (Ret);"
			);
		}

		WriteBuffer(&SourceBuffer, "\n}\n\n");
	}

	SourceFile = CreateFile(SourceName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	WriteFile(SourceFile, SourceBuffer.Buff, (DWORD)SourceBuffer.Pos, 0, 0);
	CloseHandle(SourceFile);

	HeaderBuffer.Buff = (CHAR *)malloc(BUFF_SIZE);
	HeaderBuffer.Pos = 0;

	IncludeGuard = (CHAR *)malloc(Len + 1);
	strcpy(IncludeGuard, ListName);
	for (INT I = 0; I < strlen(IncludeGuard); I++)
	{
		IncludeGuard[I] = toupper(IncludeGuard[I]);
	}
	IncludeGuard[Len] = '_';
	IncludeGuard[Len + 1] = 'H';
	IncludeGuard[Len + 2] = 0;

	File = StringFile(ListName, &Len);

	WriteBuffer(&HeaderBuffer, "#ifndef %s\n", IncludeGuard);
	WriteBuffer(&HeaderBuffer, "#define %s\n\n", IncludeGuard);
	WriteBuffer(&HeaderBuffer, "#include \"common.h\"\n\n");

	for (INT I = 0; I < Len; I++)
	{
		T_Function Func = Functions[I];

		WriteBuffer(&HeaderBuffer, "%s %s%s(", Func.ReturnType, Prefix, Func.Name);
		Commas = Func.ArgCount - 1;

		for (INT J = 0; J < Func.ArgCount; J++)
		{
			WriteBuffer(&HeaderBuffer, "%s %s", Func.ArgTypes[J], Func.ArgNames[J]);
			if (Commas > 0)
			{
				WriteBuffer(&HeaderBuffer, ", ");
				Commas--;
			}
		}

		WriteBuffer(&HeaderBuffer, ");\n");
	}

	WriteBuffer(&HeaderBuffer, "\n#endif // %s\n", IncludeGuard);

	HeaderFile = CreateFile(HeaderName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	WriteFile(HeaderFile, HeaderBuffer.Buff, (DWORD)HeaderBuffer.Pos, 0, 0);
	CloseHandle(HeaderFile);

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

void
GetFormat(CHAR *Format,
		  CHAR *Type)
{
	DWORD		Hash;


	Hash = Djb2(Type);
	switch (Hash)
	{
		case TYPE_LPVOID:
		case TYPE_HANDLE:
		case TYPE_LPSECURITY_ATTRIBUTES:
		case TYPE_LPDWORD:
		case TYPE_PLARGE_INTEGER:
		case TYPE_LPOVERLAPPED:
		case TYPE_LPOVERLAPPED_COMPLETION_ROUTINE:
		case TYPE_PLONG:
		case TYPE_LPCVOID:
		{
			strcpy(Format, "0x%p");
		} break;

		case TYPE_LPSTR:
		case TYPE_LPCSTR:
		{
			strcpy(Format, "\\\"%s\\\"");
		} break;

		case TYPE_DWORD:
		{
			strcpy(Format, "%u");
		} break;

		case TYPE_SIZE_T:
		{
			strcpy(Format, "%llu");
		} break;

		case TYPE_INT:
		case TYPE_BOOL:
		case TYPE_LONG:
		case TYPE_LARGE_INTEGER:
		{
			strcpy(Format, "%d");
		} break;

		case TYPE_CHAR:
		{
			strcpy(Format, "%c");
		} break;

		case TYPE_LPWSTR:
		case TYPE_LPCWSTR:
		{
			strcpy(Format, "\\\"%ws\\\"");
		} break;

		default:
		{
			printf("CODEGEN ERR: NO FORMAT FOUND FOR %s\n", Type);
			exit(-1);
		} break;
	}
}

DWORD
Djb2(LPSTR String)
{
    DWORD       Hash = 5381;
    INT         C = *String++;


    while (C)
    {
        Hash = ((Hash << 5) + Hash) + C;
        C = *String++;
    }

    return Hash;
}

