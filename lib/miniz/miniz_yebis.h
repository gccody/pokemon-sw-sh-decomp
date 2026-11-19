/* Not part of miniz: the YEBIS allocator that YEBIS's copy of miniz.c
   (C:/workspace/YEBIS_draft/src/GPU/miniz.c) calls for MZ_MALLOC and MZ_FREE
   (lib/miniz/README.md). Placeholder names, from the executable; the
   functions are in lib/yebis/leaf/Unk_4b99a0.cpp. */
#ifndef MINIZ_YEBIS_H
#define MINIZ_YEBIS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct Unk_4b99a0_arg0;

/* 0x710238d5f8: the allocator every YEBIS allocation goes through */
extern struct Unk_4b99a0_arg0* Unk_238d5f8;

/* 0x71004b99a0: allocate size bytes, with the caller's __FILE__ and __LINE__ */
void* Unk_4b99a0(struct Unk_4b99a0_arg0* self, size_t size, const char* file, int line, void* arg4);

/* 0x71004b9a60: free what Unk_4b99a0 returned */
void Unk_4b9a60(struct Unk_4b99a0_arg0* self, void* p);

#ifdef __cplusplus
}
#endif

#endif
