/*
 * Pokemon SwSh decomp: Nintendo's memory functions for libcurl, not public.
 *
 * Nintendo's SDK build (NintendoSDK_libcurl-7_3_2) replaces curl_memory.h's
 * Curl_cmalloc, ... pointers with a table of the five callbacks and one
 * wrapper function per callback, which curl's malloc(), free(), ... call
 * (see curl_memory.h). These are the functions of the binary's TU between
 * wildcard.c's code and the libcurl tag function (Sword 0x71017782a0 to
 * 0x7101778420), reconstructed from it. Neither the file's nor the
 * functions' names are known.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

/* The SDK's abort (an NN_ABORT_UNLESS whose strings a release build
   empties). */
void nndetailDiagAbortFormatImpl(const char *condition, const char *function,
                                 const char *file, int line,
                                 const char *format, ...)
  __attribute__((noreturn));

/* Sword 0x71027fc480: the callbacks, in curl_global_init_mem()'s order. */
struct {
  curl_malloc_callback cmalloc;
  curl_free_callback cfree;
  curl_realloc_callback crealloc;
  curl_strdup_callback cstrdup;
  curl_calloc_callback ccalloc;
} Unk_27fc480;

/* Sword 0x71017782a0: the defaults, which global_init() sets for
   curl_global_init() and curl_easy_init(). */
int Unk_17782a0(void)
{
  Unk_27fc480.cmalloc = malloc;
  Unk_27fc480.cfree = free;
  Unk_27fc480.crealloc = realloc;
  Unk_27fc480.cstrdup = strdup;
  Unk_27fc480.ccalloc = calloc;
  return 1;
}

/* Sword 0x71017782f0: curl_global_init_mem()'s callbacks. */
int Unk_17782f0(curl_malloc_callback m, curl_free_callback f,
                curl_realloc_callback r, curl_strdup_callback s,
                curl_calloc_callback c)
{
  if(!m || !f || !r || !s || !c)
    return 0;
  Unk_27fc480.cmalloc = m;
  Unk_27fc480.cfree = f;
  Unk_27fc480.crealloc = r;
  Unk_27fc480.cstrdup = s;
  Unk_27fc480.ccalloc = c;
  return 1;
}

/* Sword 0x7101778330: malloc() */
void *Unk_1778330(size_t size)
{
  return Unk_27fc480.cmalloc(size);
}

/* Sword 0x7101778340: free() */
void Unk_1778340(void *ptr)
{
  Unk_27fc480.cfree(ptr);
}

/* Sword 0x7101778350: realloc() */
void *Unk_1778350(void *ptr, size_t size)
{
  return Unk_27fc480.crealloc(ptr, size);
}

/* Sword 0x7101778360: strdup() */
char *Unk_1778360(const char *str)
{
  return Unk_27fc480.cstrdup(str);
}

/* Sword 0x7101778370: calloc() */
void *Unk_1778370(size_t nmemb, size_t size)
{
  return Unk_27fc480.ccalloc(nmemb, size);
}

/* Sword 0x7101778380: an aligned allocation (the resolver thread's stack,
   Sword 0x7101778b60). The pointer that malloc() returned is kept just
   before the aligned block. */
void *Unk_1778380(size_t alignment, size_t size)
{
  void *block;
  void *aligned;
  if(!Unk_27fc480.cmalloc)
    return NULL;
  block = Unk_27fc480.cmalloc(size + alignment + 7);
  if(!block)
    return NULL;
  aligned = (void *)(((uintptr_t)block + alignment + 7) & -alignment);
  ((void **)aligned)[-1] = block;
  return aligned;
}

/* Sword 0x71017783e0: frees a block of Unk_1778380(). */
void Unk_17783e0(void *ptr)
{
  if(!Unk_27fc480.cfree)
    nndetailDiagAbortFormatImpl("", "", "", 0, "");
  Unk_27fc480.cfree(((void **)ptr)[-1]);
}
