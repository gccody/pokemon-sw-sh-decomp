#ifndef	_ERRNO_H
#define _ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <bits/errno.h>

/* NX: no __attribute__((const)). The SDK's libc doesn't declare
 * __errno_location const: protobuf's FloatToBuffer (Sword 0x71006fee00) calls
 * it again to read errno after strtof. See include/libc/README.md. */
int *__errno_location(void);
#define errno (*__errno_location())

#ifdef _GNU_SOURCE
extern char *program_invocation_short_name, *program_invocation_name;
#endif

#ifdef __cplusplus
}
#endif

#endif

