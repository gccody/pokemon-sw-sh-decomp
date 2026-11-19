/*
 * Pokemon SwSh decomp: in place of musl's <netdb.h> for Nintendo's SDK
 * libcurl (see sys/socket.h here). struct hostent has the usual layout
 * (Curl_he2ai reads h_length at +0x14 and h_addr_list at +0x18). curl's
 * gethostbyname() is Nintendo's (curl_memory.h).
 */
#ifndef PKMN_NNSOCKET_NETDB_H
#define PKMN_NNSOCKET_NETDB_H

#include <netinet/in.h>

struct hostent {
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
};

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* An option of the SDK's resolver, 0x18 bytes: Nintendo's resolver thread
   passes three to nnsocketGetHostByNameWithOptions (asyn-thread.c). Each is
   a key, a type (0x64 for a bool, 0x65 for an int, as used), the value's
   size and the value. */
struct Unk_ResolverOption {
  uint32_t key;
  uint32_t type;
  size_t size;
  union {
    bool b;
    int i;
  } value;
};
_Static_assert(sizeof(struct Unk_ResolverOption) == 0x18, "ResolverOption");

int nnsocketResolverGetOption(struct Unk_ResolverOption *option,
                              uint32_t key);
int nnsocketResolverSetOption(const struct Unk_ResolverOption *option);

#endif /* PKMN_NNSOCKET_NETDB_H */
