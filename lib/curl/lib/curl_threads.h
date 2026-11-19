#ifndef HEADER_CURL_THREADS_H
#define HEADER_CURL_THREADS_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
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
#include "curl_setup.h"

#if defined(USE_THREADS_POSIX) && 1 /* Pokemon SwSh decomp */
/* Nintendo's SDK build runs the resolver on nn::os threads and locks nn::os
   mutexes (asyn-thread.c's code in the binary calls nnosLockMutex, ...).
   The thread functions are Nintendo's (lib/curl/nintendo/Unk_1778b10.c). */
#  include "curl_nnos.h"
struct Unk_1778b10_Thread;
#  define CURL_STDCALL
#  define curl_mutex_t           nnosMutexType
#  define curl_thread_t          struct Unk_1778b10_Thread *
#  define curl_thread_t_null     (struct Unk_1778b10_Thread *)0
#  define Curl_mutex_init(m)     nnosInitializeMutex(m, false, 1)
#  define Curl_mutex_acquire(m)  nnosLockMutex(m)
#  define Curl_mutex_release(m)  nnosUnlockMutex(m)
#  define Curl_mutex_destroy(m)  nnosFinalizeMutex(m)
#elif defined(USE_THREADS_POSIX)
#  define CURL_STDCALL
#  define curl_mutex_t           pthread_mutex_t
#  define curl_thread_t          pthread_t *
#  define curl_thread_t_null     (pthread_t *)0
#  define Curl_mutex_init(m)     pthread_mutex_init(m, NULL)
#  define Curl_mutex_acquire(m)  pthread_mutex_lock(m)
#  define Curl_mutex_release(m)  pthread_mutex_unlock(m)
#  define Curl_mutex_destroy(m)  pthread_mutex_destroy(m)
#elif defined(USE_THREADS_WIN32)
#  define CURL_STDCALL           __stdcall
#  define curl_mutex_t           CRITICAL_SECTION
#  define curl_thread_t          HANDLE
#  define curl_thread_t_null     (HANDLE)0
#  if !defined(_WIN32_WINNT) || !defined(_WIN32_WINNT_VISTA) || \
      (_WIN32_WINNT < _WIN32_WINNT_VISTA)
#    define Curl_mutex_init(m)   InitializeCriticalSection(m)
#  else
#    define Curl_mutex_init(m)   InitializeCriticalSectionEx(m, 0, 1)
#  endif
#  define Curl_mutex_acquire(m)  EnterCriticalSection(m)
#  define Curl_mutex_release(m)  LeaveCriticalSection(m)
#  define Curl_mutex_destroy(m)  DeleteCriticalSection(m)
#endif

#if defined(USE_THREADS_POSIX) || defined(USE_THREADS_WIN32)

/* !checksrc! disable SPACEBEFOREPAREN 1 */
curl_thread_t Curl_thread_create(unsigned int (CURL_STDCALL *func) (void *),
                                 void *arg);

void Curl_thread_destroy(curl_thread_t hnd);

int Curl_thread_join(curl_thread_t *hnd);

#endif /* USE_THREADS_POSIX || USE_THREADS_WIN32 */

#endif /* HEADER_CURL_THREADS_H */
