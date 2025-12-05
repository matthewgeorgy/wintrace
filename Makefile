CC = gcc
CFLAGS = -I. -Idll/inc -Idll/inc/win32 -Idll/inc/crt -Wall -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable
LDFLAGS = -shared

# Hookgen targets
HOOKGEN_DIR = hookgen
HOOKGEN_EXE = $(HOOKGEN_DIR)/hookgen.exe
TYPE_HASH_EXE = $(HOOKGEN_DIR)/type_hash.exe
TYPE_HASHES_H = $(HOOKGEN_DIR)/type_hashes.h

# DLL targets
DLL_SRCS = \
	dll/crt/wt_stdio.c dll/crt/wt_stdlib.c \
	dll/win32/wt_debugapi.c dll/win32/wt_fileapi.c \
	dll/win32/wt_heapapi.c dll/win32/wt_memoryapi.c \
	dll/win32/wt_processthreadsapi.c dll/win32/wt_profileapi.c \
	dll/win32/wt_winuser.c dll/win32/wt_syncapi.c \
	dll/common.c dll/dllmain.c dll/func_records.c dll/patch_function.c

DLL_OUT = build/wintrace.dll

# Core targets
CORE_SRCS = core/main.c
CORE_OUT = build/wintrace.exe

.PHONY: all clean generate_hooks

all: $(DLL_OUT) $(CORE_OUT)

$(TYPE_HASH_EXE): $(HOOKGEN_DIR)/type_hash.c
	$(CC) -o $@ $<

$(TYPE_HASHES_H): $(TYPE_HASH_EXE)
	cd $(HOOKGEN_DIR) && ./type_hash.exe

$(HOOKGEN_EXE): $(HOOKGEN_DIR)/main.c $(TYPE_HASHES_H)
	$(CC) -D"_countof(x)=(sizeof(x)/sizeof((x)[0]))" -o $@ $(HOOKGEN_DIR)/main.c -I$(HOOKGEN_DIR)

generate_hooks: $(HOOKGEN_EXE)
	cd $(HOOKGEN_DIR) && ./hookgen.exe
	mv $(HOOKGEN_DIR)/wt_debugapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_fileapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_heapapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_memoryapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_processthreadsapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_profileapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_winuser.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_syncapi.h dll/inc/win32/
	mv $(HOOKGEN_DIR)/wt_debugapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_fileapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_heapapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_memoryapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_processthreadsapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_profileapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_winuser.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_syncapi.c dll/win32/
	mv $(HOOKGEN_DIR)/wt_stdio.h dll/inc/crt/
	mv $(HOOKGEN_DIR)/wt_stdlib.h dll/inc/crt/
	mv $(HOOKGEN_DIR)/wt_stdio.c dll/crt/
	mv $(HOOKGEN_DIR)/wt_stdlib.c dll/crt/
	mv $(HOOKGEN_DIR)/func_records.h dll/inc/
	mv $(HOOKGEN_DIR)/func_records.c dll/
	mv $(HOOKGEN_DIR)/patch_function.c dll/
	mv $(HOOKGEN_DIR)/func_hashes.h dll/inc/
	mv $(HOOKGEN_DIR)/supported_functions.md ./

$(DLL_OUT): generate_hooks
	mkdir -p build
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(DLL_SRCS) -lkernel32 -luser32 -ladvapi32

$(CORE_OUT): $(CORE_SRCS)
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ $(CORE_SRCS) -lkernel32

clean:
	rm -f $(HOOKGEN_EXE) $(TYPE_HASH_EXE) $(TYPE_HASHES_H)
	rm -f $(DLL_OUT) $(CORE_OUT)
