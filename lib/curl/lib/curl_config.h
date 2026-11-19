/* lib/curl/lib/curl_config.h: the configuration of Nintendo's libcurl 7.55.1
   (NintendoSDK_libcurl-7_3_2-Release in Pokemon Sword/Shield's main), as far
   as the binary shows it. Nintendo's own curl_config.h isn't public; each
   choice below names its evidence. docs/compiler.md, section "libcurl 7.55.1",
   has the details and the sweep numbers.

   Not written by the curl project. The rest of lib/curl is upstream 7.55.1,
   unchanged. */
#ifndef HEADER_CURL_CONFIG_H
#define HEADER_CURL_CONFIG_H

/* curl_version_info()'s static data: host is "Nintendo". */
#define OS "Nintendo"

/* --- Protocols ---------------------------------------------------------- */
/* curl_version_info()'s protocol list is {"http", "https", NULL}, and the
   only Curl_handler tables (scheme pointers in .data.rel.ro) are HTTP and
   HTTPS. None of the other protocols' code or strings is in the binary. */
#define CURL_DISABLE_DICT 1
#define CURL_DISABLE_FILE 1
#define CURL_DISABLE_FTP 1
#define CURL_DISABLE_GOPHER 1
#define CURL_DISABLE_IMAP 1
#define CURL_DISABLE_LDAP 1
#define CURL_DISABLE_LDAPS 1
#define CURL_DISABLE_POP3 1
#define CURL_DISABLE_RTSP 1
#define CURL_DISABLE_SMB 1
#define CURL_DISABLE_SMTP 1
#define CURL_DISABLE_TELNET 1
#define CURL_DISABLE_TFTP 1
/* Cookies, proxies (HTTP CONNECT, SOCKS4/5), digest auth (crypto auth) and
   the verbose strings are all in the binary, so none of those is disabled. */

/* --- Features (curl_version_info()'s features: 0x8c) -------------------- */
/* 0x8c = CURL_VERSION_SSL | CURL_VERSION_LIBZ | CURL_VERSION_ASYNCHDNS.
   No CURL_VERSION_IPV6, CURL_VERSION_LARGEFILE or CURL_VERSION_UNIX_SOCKETS:
   ENABLE_IPV6, SIZEOF_OFF_T and USE_UNIX_SOCKETS stay undefined.
   CURL_VERSION_SSL: Nintendo's nn::ssl backend (vtls), which isn't public.
   USE_NINTENDO_SSL is this repository's: it selects lib/vtls/nnssl.h, the
   backend's API setup, and its fields in urldata.h, and so USE_SSL. */
#define USE_NINTENDO_SSL 1

/* LIBZ: curl_version() appends " zlib/%s", and content_encoding.c's inflate
   code calls inflateInit2_ with the SDK's ZLIB_VERSION. */
#define HAVE_LIBZ 1
#define HAVE_ZLIB_H 1

/* ASYNCHDNS without c-ares (curl_version() has no " c-ares/"): the threaded
   resolver, asyn-thread.c ("Could not resolve %s: %s"). Nintendo runs it on
   nn::os threads ("LibcurlResolver"), not through curl_threads.c. */
#define USE_THREADS_POSIX 1
#define HAVE_PTHREAD_H 1

/* --- Types ---------------------------------------------------------------- */
/* bool is one byte: Curl_open sets ssl.primary.verifypeer and verifyhost
   (adjacent bools) with one strh of 0x101.
   With curl's own enum bool (4 bytes) the struct offsets don't match. */
#define HAVE_STDBOOL_H 1
#define HAVE_BOOL_T 1
#define SIZEOF_INT 4
#define SIZEOF_SHORT 2
#define SIZEOF_LONG 8
#define SIZEOF_SIZE_T 8
/* SIZEOF_TIME_T is not defined (curl_setup.h then assumes 4): curlx_tvdiff
   has the "SIZEOF_TIME_T < 8" overflow check (returns 0x7fffffff when the
   difference is at least 0x7fffffff/1000 seconds). SIZEOF_OFF_T isn't
   defined either (no CURL_VERSION_LARGEFILE). */
#define HAVE_LONGLONG 1
#define HAVE_STRUCT_TIMEVAL 1
#define HAVE_VARIADIC_MACROS_C99 1
#define HAVE_VARIADIC_MACROS_GCC 1

/* --- Headers (the musl headers stand in for the SDK's) ------------------- */
#define STDC_HEADERS 1
#define HAVE_ASSERT_H 1
#define HAVE_ERRNO_H 1
#define HAVE_FCNTL_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H 1
#define HAVE_LOCALE_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_TIME_H 1
#define HAVE_UNISTD_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NETDB_H 1
#define HAVE_ARPA_INET_H 1
#define HAVE_POLL_H 1

/* --- Functions ------------------------------------------------------------ */
/* Sockets go through the SDK's nnsocket* C functions (Socket, Connect, Recv,
   Send, Poll, Fcntl, ...; imports of main). */
#define HAVE_SOCKET 1
#define HAVE_RECV 1
#define RECV_TYPE_ARG1 int
#define RECV_TYPE_ARG2 void *
#define RECV_TYPE_ARG3 size_t
#define RECV_TYPE_ARG4 int
#define RECV_TYPE_RETV ssize_t
#define HAVE_SEND 1
#define SEND_TYPE_ARG1 int
#define SEND_QUAL_ARG2 const
#define SEND_TYPE_ARG2 void *
#define SEND_TYPE_ARG3 size_t
#define SEND_TYPE_ARG4 int
#define SEND_TYPE_RETV ssize_t
/* nnsocketPoll is imported and select isn't. */
#define HAVE_POLL_FINE 1
/* curlx_nonblock: nnsocketFcntl is imported. */
#define HAVE_FCNTL_O_NONBLOCK 1
/* No HAVE_STRUCT_SOCKADDR_STORAGE: sizeof(struct Curl_sockaddr_storage) is
   0x100 (Curl_updateconninfo's getpeername length), curl's cbuf[256]. The
   socket headers are the SDK's, reconstructed in lib/curl/nnsocket. */
/* curl_global_init_mem's default strdup is the libc one (a GOT load of
   strdup). */
#define HAVE_STRDUP 1
/* Not defined, each with curl's own code in the binary instead of a libc
   import: HAVE_INET_PTON (Curl_inet_pton matches), HAVE_INET_NTOP
   (Curl_inet_ntop), HAVE_STRTOK_R (Curl_strtok_r), HAVE_MEMRCHR
   (Curl_memrchr). HAVE_GMTIME_R isn't defined either (gmtime is imported,
   gmtime_r isn't), nor HAVE_GETADDRINFO, HAVE_SIGNAL or HAVE_GETTIMEOFDAY
   (none of them is imported). */

#endif /* HEADER_CURL_CONFIG_H */
