/*
 * Pokemon SwSh decomp: in place of musl's <arpa/inet.h> for Nintendo's SDK
 * libcurl (see sys/socket.h here). curl uses its own inet_pton/inet_ntop.
 */
#ifndef PKMN_NNSOCKET_ARPA_INET_H
#define PKMN_NNSOCKET_ARPA_INET_H

#include <netinet/in.h>

#endif /* PKMN_NNSOCKET_ARPA_INET_H */
