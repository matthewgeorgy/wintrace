#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "type_hashes.h"

#define BUFF_SIZE       1024 * 1024 // 1 MB

typedef struct _tag_Function
{
    CHAR        Name[64];
    CHAR        ReturnType[32];
    CHAR        ArgTypes[16][32];
    CHAR        ArgNames[16][32];
    INT         ArgCount;
} T_Function;

typedef struct _tag_Buffer
{
    CHAR        *Buff;
    SIZE_T      Pos;
} T_Buffer;

CHAR *HookList[] =
{
    "wt_debugapi Wt win32",
    "wt_fileapi Wt win32",
    "wt_heapapi Wt win32",
    "wt_memoryapi Wt win32",
    "wt_processthreadsapi Wt win32",
    "wt_profileapi Wt win32",
    "wt_winuser Wt win32",
    "wt_stdio wt_ crt",
    "wt_stdlib wt_ crt"
};

CHAR            **StringFile(char *filename, int *plen);
T_Function      *ParseFunctions(CHAR *Filename, INT *Count);
SIZE_T          WriteBuffer(T_Buffer *Buffer, char *Format, ...);
void            GetFormat(CHAR *Format, CHAR *Type);
DWORD           Djb2(LPSTR String);
void            GenerateHooks(T_Function *Functions, INT Count, CHAR *ListName, CHAR *Prefix, CHAR *Folder);
void            GenerateFuncRecords(T_Function *Functions[], INT Count[], CHAR *LibNames[], SIZE_T HookListSize);
void            GeneratePatchFunction(T_Function *Functions[], INT Count[], CHAR *LibNames[], SIZE_T HookListSize);
void            GenerateFunctionHashes(T_Function *Functions[], INT Count[], CHAR *LibNames[], SIZE_T HookListSize);

int
main(void)
{
    T_Function      *Functions[9];
    INT             Count[9];
    CHAR            *LibNames[9];
    INT             I;
    CHAR            ListName[32],
                    Prefix[32],
                    Folder[32];


    assert(_countof(Functions) == _countof(HookList));
    assert(_countof(Count) == _countof(HookList));
    assert(_countof(LibNames) == _countof(HookList));

    for (I = 0; I < _countof(HookList); I++)
    {
        sscanf(HookList[I], "%s %s %s", ListName, Prefix, Folder);

        Functions[I] = ParseFunctions(ListName, &Count[I]);
        GenerateHooks(Functions[I], Count[I], ListName, Prefix, Folder);

        LibNames[I] = (CHAR *)malloc(strlen(ListName) - 3);
        strcpy(LibNames[I], &ListName[3]);
    }

    GenerateFuncRecords(Functions, Count, LibNames, _countof(HookList));
    GeneratePatchFunction(Functions, Count, LibNames, _countof(HookList));
    GenerateFunctionHashes(Functions, Count, LibNames, _countof(HookList));

    return (0);
}

T_Function *
ParseFunctions(CHAR *Filename,
               INT *Count)
{
    T_Function      *Functions;
    CHAR            **File,
                    *Signature,
                    *Temp;
    INT             Len;


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

// stb_stringfile, thank you Sean Barrett
CHAR **
StringFile(char *filename, int *plen)
{
    HANDLE              f;
    char                *buffer, **list = NULL, *s;
    size_t              len, count, i;
    LARGE_INTEGER       large_int;

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

SIZE_T
WriteBuffer(T_Buffer *Buffer,
            char *Format,
            ...)
{
    SIZE_T      Bytes;
    va_list     VarArgs;


    va_start(VarArgs, Format);

    Bytes = vsprintf(Buffer->Buff + Buffer->Pos, Format, VarArgs);
    Buffer->Pos += Bytes;

    va_end(VarArgs);

    return (Bytes);
}

void
GetFormat(CHAR *Format,
          CHAR *Type)
{
    DWORD       Hash;


    Hash = Djb2(Type);
    switch (Hash)
    {
        // Pointers
        case TYPE_PVOID:
        case TYPE_PSIZE_T:
        case TYPE_LPVOID:
        case TYPE_HANDLE:
        case TYPE_LPSECURITY_ATTRIBUTES:
        case TYPE_LPDWORD:
        case TYPE_PDWORD:
        case TYPE_PMEMORY_BASIC_INFORMATION:
        case TYPE_PLARGE_INTEGER:
        case TYPE_LPOVERLAPPED:
        case TYPE_LPOVERLAPPED_COMPLETION_ROUTINE:
        case TYPE_PLONG:
        case TYPE_LPCVOID:
        case TYPE_PHANDLE:
        case TYPE_LPPROCESS_HEAP_ENTRY:
        case TYPE_LPPROC_THREAD_ATTRIBUTE_LIST:
        case TYPE_LPSTARTUPINFOA:
        case TYPE_LPSTARTUPINFOW:
        case TYPE_LPPROCESS_INFORMATION:
        case TYPE_LPTHREAD_START_ROUTINE:
        case TYPE_LPDEBUG_EVENT:
        case TYPE_PBOOL:
        case TYPE_LPBOOL:
        case TYPE_LPRECT:
        case TYPE_HWND:
        case TYPE_LPPAINTSTRUCT:
        case TYPE_HDC:
        case TYPE_LPPOINT:
        case TYPE_HMENU:
        case TYPE_HINSTANCE:
        case TYPE_LPMSG:
        case TYPE_HBRUSH:
        case TYPE_LPFILE:
        {
            strcpy(Format, "0x%p");
        } break;

        // Strings
        case TYPE_LPSTR:
        case TYPE_LPCSTR:
        {
            strcpy(Format, "\\\"%s\\\"");
        } break;

        // Unsigned
        case TYPE_WORD:
        case TYPE_ATOM:
        case TYPE_DWORD:
        case TYPE_UINT:
        case TYPE_LRESULT:
        case TYPE_WPARAM:
        case TYPE_LPARAM:
        case TYPE_LPWNDCLASSEXA:
        case TYPE_LPWNDCLASSEXW:
        {
            strcpy(Format, "%u");
        } break;

        // Long unsigned
        case TYPE_size_t:
        case TYPE_SIZE_T:
        {
            strcpy(Format, "%llu");
        } break;

        // Int
        case TYPE_int:
        case TYPE_INT:
        case TYPE_BOOL:
        case TYPE_LONG:
        case TYPE_LARGE_INTEGER:
        case TYPE_HEAP_INFORMATION_CLASS:
        case TYPE_short:
        {
            strcpy(Format, "%d");
        } break;

        // Char
        case TYPE_CHAR:
        {
            strcpy(Format, "%c");
        } break;

        // Wide string
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

void
GenerateHooks(T_Function *Functions,
              INT Count,
              CHAR *ListName,
              CHAR *Prefix,
              CHAR *Folder)
{
    INT             Len;
    T_Buffer        SourceBuffer,
                    HeaderBuffer;
    HANDLE          HeaderFile,
                    SourceFile;
    CHAR            *HeaderName,
                    *SourceName,
                    *IncludeGuard;
    INT             Commas;


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

    /* Functions = ParseFunctions(ListName, &Count); */

    //////////////////////////////////////////////////////////////////////////
    // Source file generation

    SourceBuffer.Buff = (CHAR *)malloc(BUFF_SIZE);
    SourceBuffer.Pos = 0;

    // Header and extern global pOpts
    WriteBuffer(&SourceBuffer, "#include <%s/%s>\n\n", Folder, HeaderName);
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
                WriteBuffer(&SourceBuffer, "\t%s %s", Func.ArgTypes[I], Func.ArgNames[I]);

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
            WriteBuffer(&SourceBuffer, "VOID\"");
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
            WriteBuffer(&SourceBuffer, "\n\treturn (Ret);");
        }

        WriteBuffer(&SourceBuffer, "\n}\n\n");
    }

    SourceFile = CreateFile(SourceName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    WriteFile(SourceFile, SourceBuffer.Buff, (DWORD)SourceBuffer.Pos, 0, 0);
    CloseHandle(SourceFile);

    //////////////////////////////////////////////////////////////////////////
    // Header file generation

    HeaderBuffer.Buff = (CHAR *)malloc(BUFF_SIZE);
    HeaderBuffer.Pos = 0;

    IncludeGuard = (CHAR *)malloc(Len + 1);
    strcpy(IncludeGuard, ListName);
    for (INT I = 0; I < strlen(IncludeGuard); I++)
    {
        IncludeGuard[I] = (CHAR)toupper(IncludeGuard[I]);
    }
    IncludeGuard[Len] = '_';
    IncludeGuard[Len + 1] = 'H';
    IncludeGuard[Len + 2] = 0;

    WriteBuffer(&HeaderBuffer, "#ifndef %s\n", IncludeGuard);
    WriteBuffer(&HeaderBuffer, "#define %s\n\n", IncludeGuard);
    WriteBuffer(&HeaderBuffer, "#include \"common.h\"\n\n");

    for (INT I = 0; I < Count; I++)
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

}

void
GenerateFuncRecords(T_Function *Functions[],
                    INT Count[],
                    CHAR *LibNames[],
                    SIZE_T HookListSize)
{
    T_Buffer        HeaderBuffer,
                    SourceBuffer;
    HANDLE          HeaderFile,
                    SourceFile;


    //////////////////////////////////////////////////////////////////////////
    // Source file generation

    SourceBuffer.Buff = (CHAR *)malloc(BUFF_SIZE);
    SourceBuffer.Pos = 0;

    // Header and extern global pOpts
    WriteBuffer(&SourceBuffer, "#include <common.h>\n\n");
    WriteBuffer(&SourceBuffer, "extern T_WintraceOpts *pOpts;\n\n");

    // Function record array
    WriteBuffer(&SourceBuffer, "// Full list of supported function records\n");
    WriteBuffer(&SourceBuffer, "T_FuncRec  g_FuncRecs[] =\n{\n");

    for (INT I = 0; I < HookListSize; I++)
    {
        WriteBuffer(&SourceBuffer, "    // %s.h\n", LibNames[I]);

        for (INT J = 0; J < Count[I]; J++)
        {
            WriteBuffer(&SourceBuffer, "    { \"%s\", 0, FALSE },\n", Functions[I][J].Name);
        }
    }
    WriteBuffer(&SourceBuffer, "};\n\n");


    // SetTrace function
    WriteBuffer(&SourceBuffer, "void\nSetTrace(DWORD Hash,\n         BOOL bTrace)\n{\n");
    WriteBuffer(&SourceBuffer, "    switch (Hash)\n    {\n");

    for (INT I = 0; I < HookListSize; I++)
    {
        WriteBuffer(&SourceBuffer, "        // %s.h\n", LibNames[I]);

        for (INT J = 0; J < Count[I]; J++)
        {
            SIZE_T Written = WriteBuffer(&SourceBuffer, "        case FUNC_%s:", Functions[I][J].Name);
            Written = 52 - Written;
            WriteBuffer(&SourceBuffer, "%*c", Written, ' ');
            WriteBuffer(&SourceBuffer, "{ g_FuncRecs[E_%s].bTrace = bTrace; } break;\n", Functions[I][J].Name);
        }
    }
    WriteBuffer(&SourceBuffer, "    }\n");
    WriteBuffer(&SourceBuffer, "}\n");

    SourceFile = CreateFile("func_records.c", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(SourceFile, SourceBuffer.Buff, (DWORD)SourceBuffer.Pos, 0, 0);
    CloseHandle(SourceFile);

    //////////////////////////////////////////////////////////////////////////
    // Header file generation

    HeaderBuffer.Buff = (CHAR *)malloc(BUFF_SIZE);
    HeaderBuffer.Pos = 0;

    // Include guards
    WriteBuffer(&HeaderBuffer, "#ifndef FUNC_RECORDS_H\n");
    WriteBuffer(&HeaderBuffer, "#define FUNC_RECORDS_H\n\n");

    // Includes
    WriteBuffer(&HeaderBuffer, "#define WIN32_LEAN_AND_MEAN\n");
    WriteBuffer(&HeaderBuffer, "#include <windows.h>\n\n");

    // T_FuncRec
    WriteBuffer(&HeaderBuffer, "typedef struct _tag_FuncRec\n"
                               "{\n"
                               "    CHAR        *Name;\n"
                               "    DWORD       Cnt;\n"
                               "    BOOL        bTrace;\n"
                               "} T_FuncRec;\n\n");


    // E_FuncEnum
    WriteBuffer(&HeaderBuffer, "typedef enum _tag_FuncEnum\n{\n");
    for (INT I = 0; I < HookListSize; I++)
    {
        WriteBuffer(&HeaderBuffer, "    // %s.h\n", LibNames[I]);

        for (INT J = 0; J < Count[I]; J++)
        {
            WriteBuffer(&HeaderBuffer, "    E_%s,\n", Functions[I][J].Name);
        }
    }
    WriteBuffer(&HeaderBuffer, "    E_Count,\n");
    WriteBuffer(&HeaderBuffer, "} E_FuncEnum;\n\n");

    WriteBuffer(&HeaderBuffer, "#endif // FUNC_RECORDS_H");

    HeaderFile = CreateFile("func_records.h", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(HeaderFile, HeaderBuffer.Buff, (DWORD)HeaderBuffer.Pos, 0, 0);
    CloseHandle(HeaderFile);
}

void
GeneratePatchFunction(T_Function *Functions[],
                      INT Count[],
                      CHAR *LibNames[],
                      SIZE_T HookListSize)
{
    T_Buffer        Buffer;
    HANDLE          File;


    Buffer.Buff = (CHAR *)malloc(BUFF_SIZE);
    Buffer.Pos = 0;

    WriteBuffer(&Buffer, "#include <dllmain.h>\n\n");

    WriteBuffer(&Buffer,
        "void\n"
        "PatchFunction(DWORD FuncHash,\n"
        "             PIMAGE_THUNK_DATA FirstThunk)\n"
        "{\n"
        "   DWORD       OldProtect;\n"
        "\n\n"
        "   switch (FuncHash)\n"
        "   {\n"
        "#pragma warning(disable: 4127)\n");

    for (INT I = 0; I < HookListSize; I++)
    {
        WriteBuffer(&Buffer, "        // %s.h\n", LibNames[I]);

        for (INT J = 0; J < Count[I]; J++)
        {
            SIZE_T Written = WriteBuffer(&Buffer, "        case FUNC_%s:", Functions[I][J].Name);
            Written = 52 - Written;
            WriteBuffer(&Buffer, "%*c", Written, ' ');
            WriteBuffer(&Buffer, "{ PatchEntry(");

            // Choose the correct prefix:
            // wt_ for CRT
            // Wt for Win32
            if (!strcmp(LibNames[I], "stdio") || !strcmp(LibNames[I], "stdlib"))
            {
                WriteBuffer(&Buffer, "wt_");
            }
            else
            {
                WriteBuffer(&Buffer, "Wt");
            }

            WriteBuffer(&Buffer, "%s); } break;\n", Functions[I][J].Name);
        }
    }
    WriteBuffer(&Buffer, "#pragma warning(default: 4127)\n");
    WriteBuffer(&Buffer, "    }\n");
    WriteBuffer(&Buffer, "}\n");

    File = CreateFile("patch_function.c", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(File, Buffer.Buff, (DWORD)Buffer.Pos, 0, 0);
    CloseHandle(File);
}

void            
GenerateFunctionHashes(T_Function *Functions[],
               		   INT Count[],
					   CHAR *LibNames[],
               		   SIZE_T HookListSize)
{
    T_Buffer        Buffer;
    HANDLE          File;


    Buffer.Buff = (CHAR *)malloc(BUFF_SIZE);
    Buffer.Pos = 0;

	WriteBuffer(&Buffer, "#ifndef FUNC_HASHES_H\n");
	WriteBuffer(&Buffer, "#define FUNC_HASHES_H\n\n");

    for (INT I = 0; I < HookListSize; I++)
    {
        WriteBuffer(&Buffer, "// %s.h\n", LibNames[I]);
        for (INT J = 0; J < Count[I]; J++)
        {
			DWORD Hash = Djb2(Functions[I][J].Name);

			WriteBuffer(&Buffer, "#define FUNC_%s %u\n", Functions[I][J].Name, Hash);
		}
	}

	WriteBuffer(&Buffer, "\n#endif // FUNC_HASHES_H\n");

    File = CreateFile("func_hashes.h", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(File, Buffer.Buff, (DWORD)Buffer.Pos, 0, 0);
    CloseHandle(File);
}

