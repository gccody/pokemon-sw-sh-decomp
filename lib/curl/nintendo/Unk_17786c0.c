/*
 * Pokemon SwSh decomp: Nintendo's libc replacements for libcurl, not public.
 *
 * Nintendo's SDK build doesn't call the SDK's time(), stdio or
 * gethostbyname() from curl's code: curl_memory.h redirects those calls to
 * these functions (Sword 0x71017786c0 to 0x7101778ae0), reconstructed from
 * the binary. Time comes from nn::os ticks. The stream functions accept only
 * stdout and stderr, whose output a release build doesn't print (an NN_LOG
 * that compiles to nothing), and the file functions abort. Neither the
 * file's nor the functions' names are known.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#include "curl_setup.h"
#include "timeval.h"
#include "curl_memory.h"

#undef time
#undef fwrite
#undef fputs
#undef fflush
#undef fprintf
#undef vfprintf
#undef fclose
#undef fopen
#undef fread
#undef fseek
#undef fgets
#undef stat

/* The SDK's C APIs */
int64_t nnosGetSystemTick(void);
int64_t nnosGetSystemTickFrequency(void);
int64_t nnosConvertTickToNanoSeconds(int64_t tick);
struct hostent *nnsocketGetHostByNameWithOptions(const char *name,
                                                 const void *options,
                                                 size_t optionsCount);
void nndetailDiagAbortFormatImpl(const char *condition, const char *function,
                                 const char *file, int line,
                                 const char *format, ...)
  __attribute__((noreturn));

/* NN_ABORT() in a release build */
#define NN_ABORT() nndetailDiagAbortFormatImpl("", "", "", 0, "")

/* Sword 0x71017786c0: time() */
time_t Unk_17786c0(time_t *t)
{
  int64_t tick = nnosGetSystemTick();
  time_t now = tick / nnosGetSystemTickFrequency();
  if(t)
    *t = now;
  return now;
}

/* Sword 0x7101778700: the time for curlx_tvnow() */
struct curltime Unk_1778700(struct curltime *t)
{
  int64_t tick = nnosGetSystemTick();
  struct curltime now;
  now.tv_sec = tick / nnosGetSystemTickFrequency();
  now.tv_usec = (int)((nnosConvertTickToNanoSeconds(tick) / 1000) % 1000000);
  if(t)
    *t = now;
  return now;
}

/* Sword 0x7101778790: gethostbyname(), with the SDK's resolver options */
struct hostent *Unk_1778790(const char *name, const void *options,
                            size_t optionsCount)
{
  return nnsocketGetHostByNameWithOptions(name, options, optionsCount);
}

/* Sword 0x71017787a0: fwrite() */
size_t Unk_17787a0(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t len;
  char *buf;
  if(stream != stdout && stream != stderr)
    NN_ABORT();
  len = size * nmemb;
  if(!len)
    return 0;
  buf = malloc(len + 1);
  if(!buf)
    NN_ABORT();
  memset(buf, 0, len + 1);
  memcpy(buf, ptr, len);
  /* NN_LOG("%s", buf); */
  free(buf);
  return len;
}

/* Sword 0x7101778850: fputs() */
int Unk_1778850(const char *s, FILE *stream)
{
  if(stream != stdout && stream != stderr)
    NN_ABORT();
  if(!s)
    return -1;
  /* NN_LOG("%s", s); */
  return (int)strlen(s);
}

/* Sword 0x71017788c0: fflush() */
int Unk_17788c0(FILE *stream)
{
  if(stream != stdout && stream != stderr)
    NN_ABORT();
  return 0;
}

/* Sword 0x7101778910: fprintf() */
int Unk_1778910(FILE *stream, const char *format, ...)
{
  (void)format;
  if(stream != stdout && stream != stderr)
    NN_ABORT();
  /* NN_LOG(format, ...); */
  return -1;
}

/* Sword 0x71017789a0: vfprintf() */
int Unk_17789a0(FILE *stream, const char *format, va_list ap)
{
  (void)format;
  (void)ap;
  if(stream != stdout && stream != stderr)
    NN_ABORT();
  /* NN_VLOG(format, ap); */
  return -1;
}

/* Sword 0x71017789f0: fclose() */
int Unk_17789f0(FILE *stream)
{
  (void)stream;
  NN_ABORT();
}

/* Sword 0x7101778a20: fopen() */
FILE *Unk_1778a20(const char *path, const char *mode)
{
  (void)path;
  (void)mode;
  NN_ABORT();
}

/* Sword 0x7101778a50: fread() */
size_t Unk_1778a50(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  (void)ptr;
  (void)size;
  (void)nmemb;
  (void)stream;
  NN_ABORT();
}

/* Sword 0x7101778a80: fseek() */
int Unk_1778a80(FILE *stream, long offset, int whence)
{
  (void)stream;
  (void)offset;
  (void)whence;
  NN_ABORT();
}

/* Sword 0x7101778ab0: fgets() */
char *Unk_1778ab0(char *s, int size, FILE *stream)
{
  (void)s;
  (void)size;
  (void)stream;
  NN_ABORT();
}

/* Sword 0x7101778ae0: stat() */
int Unk_1778ae0(const char *path, struct stat *buf)
{
  (void)path;
  (void)buf;
  NN_ABORT();
}
