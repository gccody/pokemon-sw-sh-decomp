/*
 * Pokemon SwSh decomp: the SDK's BSD-style struct sockaddr_in, for Nintendo's
 * SDK libcurl, in place of musl's <netinet/in.h>. See sys/socket.h here.
 * htons and ntohs are the SDK's nnsocketInetHtons and nnsocketInetNtohs
 * (Curl_he2ai, Curl_updateconninfo).
 */
#ifndef PKMN_NNSOCKET_NETINET_IN_H
#define PKMN_NNSOCKET_NETINET_IN_H

#include <sys/socket.h>

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

struct in_addr {
  in_addr_t s_addr;
};

struct sockaddr_in {
  uint8_t sin_len;
  sa_family_t sin_family;
  in_port_t sin_port;
  struct in_addr sin_addr;
  char sin_zero[8];
};

#define IPPROTO_TCP 6
#define IPPROTO_UDP 17

#define INADDR_ANY ((in_addr_t)0x00000000)
#define INADDR_NONE ((in_addr_t)0xffffffff)
#define INET_ADDRSTRLEN 16

uint16_t nnsocketInetHtons(uint16_t hostshort);
uint16_t nnsocketInetNtohs(uint16_t netshort);

#define htons(x) nnsocketInetHtons(x)
#define ntohs(x) nnsocketInetNtohs(x)

#endif /* PKMN_NNSOCKET_NETINET_IN_H */
