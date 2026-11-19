#ifndef HEADER_CURL_NNSTDIO_H
#define HEADER_CURL_NNSTDIO_H
/*
 * Pokemon SwSh decomp: Nintendo's SDK build doesn't call the SDK's time(),
 * stdio or gethostbyname() from curl's code either, but functions of its own
 * (Sword 0x71017786c0 ... 0x7101778ae0, lib/curl/nintendo/Unk_17786c0.c).
 * curl_printf.h and curl_memory.h include this header, after
 * curl_printf.h's fprintf: progress.c and cookie.c call Nintendo's fprintf,
 * not curl_mfprintf (progress.c includes only curl_printf.h). fread and fwrite are
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

#endif /* HEADER_CURL_NNSTDIO_H */
