#ifndef HEADER_CURL_MEMORY_H
#define HEADER_CURL_MEMORY_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2017, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

/*
 * Nasty internal details ahead...
 *
 * File curl_memory.h must be included by _all_ *.c source files
 * that use memory related functions strdup, malloc, calloc, realloc
 * or free, and given source file is used to build libcurl library.
 * It should be included immediately before memdebug.h as the last files
 * included to avoid undesired interaction with other memory function
 * headers in dependent libraries.
 *
 * There is nearly no exception to above rule. All libcurl source
 * files in 'lib' subdirectory as well as those living deep inside
 * 'packages' subdirectories and linked together in order to build
 * libcurl library shall follow it.
 *
 * File lib/strdup.c is an exception, given that it provides a strdup
 * clone implementation while using malloc. Extra care needed inside
 * this one. TODO: revisit this paragraph and related code.
 *
 * The need for curl_memory.h inclusion is due to libcurl's feature
 * of allowing library user to provide memory replacement functions,
 * memory callbacks, at runtime with curl_global_init_mem()
 *
 * Any *.c source file used to build libcurl library that does not
 * include curl_memory.h and uses any memory function of the five
 * mentioned above will compile without any indication, but it will
 * trigger weird memory related issues at runtime.
 *
 * OTOH some source files from 'lib' subdirectory may additionally be
 * used directly as source code when using some curlx_ functions by
 * third party programs that don't even use libcurl at all. When using
 * these source files in this way it is necessary these are compiled
 * with CURLX_NO_MEMORY_CALLBACKS defined, in order to ensure that no
 * attempt of calling libcurl's memory callbacks is done from code
 * which can not use this machinery.
 *
 * Notice that libcurl's 'memory tracking' system works chaining into
 * the memory callback machinery. This implies that when compiling
 * 'lib' source files with CURLX_NO_MEMORY_CALLBACKS defined this file
 * disengages usage of libcurl's 'memory tracking' system, defining
 * MEMDEBUG_NODEFINES and overriding CURLDEBUG purpose.
 *
 * CURLX_NO_MEMORY_CALLBACKS takes precedence over CURLDEBUG. This is
 * done in order to allow building a 'memory tracking' enabled libcurl
 * and at the same time allow building programs which do not use it.
 *
 * Programs and libraries in 'tests' subdirectories have specific
 * purposes and needs, and as such each one will use whatever fits
 * best, depending additionally whether it links with libcurl or not.
 *
 * Caveat emptor. Proper curlx_* separation is a work in progress
 * the same as CURLX_NO_MEMORY_CALLBACKS usage, some adjustments may
 * still be required. IOW don't use them yet, there are sharp edges.
 */

#ifdef HEADER_CURL_MEMDEBUG_H
#error "Header memdebug.h shall not be included before curl_memory.h"
#endif

#ifndef CURLX_NO_MEMORY_CALLBACKS

#ifndef CURL_DID_MEMORY_FUNC_TYPEDEFS /* only if not already done */
/*
 * The following memory function replacement typedef's are COPIED from
 * curl/curl.h and MUST match the originals. We copy them to avoid having to
 * include curl/curl.h here. We avoid that include since it includes stdio.h
 * and other headers that may get messed up with defines done here.
 */
typedef void *(*curl_malloc_callback)(size_t size);
typedef void (*curl_free_callback)(void *ptr);
typedef void *(*curl_realloc_callback)(void *ptr, size_t size);
typedef char *(*curl_strdup_callback)(const char *str);
typedef void *(*curl_calloc_callback)(size_t nmemb, size_t size);
#define CURL_DID_MEMORY_FUNC_TYPEDEFS
#endif

#if 0 /* not in Nintendo's SDK build: see below */
extern curl_malloc_callback Curl_cmalloc;
extern curl_free_callback Curl_cfree;
extern curl_realloc_callback Curl_crealloc;
extern curl_strdup_callback Curl_cstrdup;
extern curl_calloc_callback Curl_ccalloc;
#endif /* not in Nintendo's SDK build */

/*
 * Pokemon SwSh decomp: Nintendo's SDK build (NintendoSDK_libcurl-7_3_2)
 * calls functions of its own, not the Curl_c* pointers: every malloc(),
 * free(), realloc(), strdup() and calloc() in curl's code is a direct call
 * to one of five wrappers (Sword 0x7101778330 ... 0x7101778370), each a tail
 * call through a table of the five callbacks that curl_global_init_mem()
 * fills. Their names aren't known. lib/curl/nintendo/Unk_17782a0.c has them.
 */
extern void *Unk_1778330(size_t size);
extern void Unk_1778340(void *ptr);
extern void *Unk_1778350(void *ptr, size_t size);
extern char *Unk_1778360(const char *str);
extern void *Unk_1778370(size_t nmemb, size_t size);
#if defined(WIN32) && defined(UNICODE)
extern curl_wcsdup_callback Curl_cwcsdup;
#endif

#ifndef CURLDEBUG

/*
 * libcurl's 'memory tracking' system defines strdup, malloc, calloc,
 * realloc and free, along with others, in memdebug.h in a different
 * way although still using memory callbacks forward declared above.
 * When using the 'memory tracking' system (CURLDEBUG defined) we do
 * not define here the five memory functions given that definitions
 * from memdebug.h are the ones that shall be used.
 */

#undef strdup
#define strdup(ptr) Unk_1778360(ptr)  /* Nintendo: Curl_cstrdup(ptr) */
#undef malloc
#define malloc(size) Unk_1778330(size)  /* Nintendo: Curl_cmalloc(size) */
#undef calloc
#define calloc(nbelem,size) Unk_1778370(nbelem, size)  /* Nintendo: Curl_ccalloc */
#undef realloc
#define realloc(ptr,size) Unk_1778350(ptr, size)  /* Nintendo: Curl_crealloc */
#undef free
#define free(ptr) Unk_1778340(ptr)  /* Nintendo: Curl_cfree(ptr) */

#ifdef WIN32
#  ifdef UNICODE
#    undef wcsdup
#    define wcsdup(ptr) Curl_cwcsdup(ptr)
#    undef _wcsdup
#    define _wcsdup(ptr) Curl_cwcsdup(ptr)
#    undef _tcsdup
#    define _tcsdup(ptr) Curl_cwcsdup(ptr)
#  else
#    undef _tcsdup
#    define _tcsdup(ptr) Curl_cstrdup(ptr)
#  endif
#endif

#endif /* CURLDEBUG */

/*
 * Pokemon SwSh decomp: Nintendo's SDK build doesn't call the SDK's time(),
 * stdio or gethostbyname() from curl's code either, but functions of its own
 * (Sword 0x71017786c0 ... 0x7101778ae0, lib/curl/nintendo/Unk_17786c0.c).
 * They are redirected here, after curl_printf.h's fprintf: progress.c and
 * cookie.c call Nintendo's fprintf, not curl_mfprintf. fread and fwrite are
 * also callback values (Curl_init_userdefined, Curl_readrewind).
 */
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
struct hostent;
extern time_t Unk_17786c0(time_t *t);
extern struct hostent *Unk_1778790(const char *name, const void *options,
                                   size_t optionsCount);
extern size_t Unk_17787a0(const void *ptr, size_t size, size_t nmemb,
                          FILE *stream);
extern int Unk_1778850(const char *s, FILE *stream);
extern int Unk_17788c0(FILE *stream);
extern int Unk_1778910(FILE *stream, const char *format, ...);
extern int Unk_17789a0(FILE *stream, const char *format, va_list ap);
extern int Unk_17789f0(FILE *stream);
extern FILE *Unk_1778a20(const char *path, const char *mode);
extern size_t Unk_1778a50(void *ptr, size_t size, size_t nmemb, FILE *stream);
extern int Unk_1778a80(FILE *stream, long offset, int whence);
extern char *Unk_1778ab0(char *s, int size, FILE *stream);
extern int Unk_1778ae0(const char *path, struct stat *buf);
#undef time
#define time(t) Unk_17786c0(t)
#undef fwrite
#define fwrite Unk_17787a0
#undef fputs
#define fputs(s, stream) Unk_1778850(s, stream)
#undef fflush
#define fflush(stream) Unk_17788c0(stream)
#undef fprintf
#define fprintf Unk_1778910
#undef vfprintf
#define vfprintf(stream, format, ap) Unk_17789a0(stream, format, ap)
#undef fclose
#define fclose(stream) Unk_17789f0(stream)
#undef fopen
#define fopen(path, mode) Unk_1778a20(path, mode)
#undef fread
#define fread Unk_1778a50
#undef fseek
#define fseek(stream, offset, whence) Unk_1778a80(stream, offset, whence)
#undef fgets
#define fgets(s, size, stream) Unk_1778ab0(s, size, stream)
#undef stat
#define stat(path, buf) Unk_1778ae0(path, buf)
#undef gethostbyname
#define gethostbyname(name, options, count) Unk_1778790(name, options, count)

#else /* CURLX_NO_MEMORY_CALLBACKS */

#ifndef MEMDEBUG_NODEFINES
#define MEMDEBUG_NODEFINES
#endif

#endif /* CURLX_NO_MEMORY_CALLBACKS */

#endif /* HEADER_CURL_MEMORY_H */
