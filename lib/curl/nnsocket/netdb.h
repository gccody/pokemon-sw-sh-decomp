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

#endif /* PKMN_NNSOCKET_NETDB_H */
