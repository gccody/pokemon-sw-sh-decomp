/*
 * Pokemon SwSh decomp: the socket API that Nintendo's SDK libcurl is built
 * against, in place of musl's <sys/socket.h> (lib/curl/README.md).
 *
 * Not the SDK's header, which isn't public: a reconstruction of what curl's
 * code in the binary shows. The SDK's sockets are BSD-style: struct sockaddr
 * starts with a length byte and a family byte (Curl_he2ai, Sword
 * 0x7101755800, stores sin_family with strb at +1), and SOL_SOCKET and the
 * SO_* options have BSD values (getsockopt(SOL_SOCKET = 0xffff,
 * SO_ERROR = 0x1007) in Curl_is_connected, setsockopt(SO_NOSIGPIPE = 0x800)
 * and (SO_KEEPALIVE = 8) in singleipconnect). The functions are the SDK's
 * nnsocket* C functions, which take the BSD functions' arguments.
 * sizeof(struct Curl_sockaddr_storage) is 0x100 (Curl_updateconninfo), so
 * there's no struct sockaddr_storage (curl_config.h).
 */
#ifndef PKMN_NNSOCKET_SYS_SOCKET_H
#define PKMN_NNSOCKET_SYS_SOCKET_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint32_t socklen_t;
typedef uint8_t sa_family_t;

struct sockaddr {
  uint8_t sa_len;
  sa_family_t sa_family;
  char sa_data[14];
};

#define AF_UNSPEC 0
#define AF_INET 2
#define PF_UNSPEC AF_UNSPEC
#define PF_INET AF_INET

#define SOCK_STREAM 1
#define SOCK_DGRAM 2

#define SOL_SOCKET 0xffff
#define SO_KEEPALIVE 0x0008
#define SO_NOSIGPIPE 0x0800
#define SO_ERROR 0x1007

#define MSG_PEEK 0x2

int nnsocketSocket(int domain, int type, int protocol);
int nnsocketBind(int s, const struct sockaddr *addr, socklen_t addrlen);
int nnsocketConnect(int s, const struct sockaddr *addr, socklen_t addrlen);
ssize_t nnsocketRecv(int s, void *buf, size_t len, int flags);
ssize_t nnsocketSend(int s, const void *buf, size_t len, int flags);
int nnsocketGetSockName(int s, struct sockaddr *addr, socklen_t *addrlen);
int nnsocketGetPeerName(int s, struct sockaddr *addr, socklen_t *addrlen);
int nnsocketGetSockOpt(int s, int level, int optname, void *optval,
                       socklen_t *optlen);
int nnsocketSetSockOpt(int s, int level, int optname, const void *optval,
                       socklen_t optlen);
int nnsocketClose(int s);
int nnsocketFcntl(int s, int cmd, ...);
int nnsocketGetLastErrno(void);
void nnsocketSetLastErrno(int error);

#define socket(d, t, p) nnsocketSocket(d, t, p)
#define bind(s, a, l) nnsocketBind(s, a, l)
#define connect(s, a, l) nnsocketConnect(s, a, l)
#define recv(s, b, l, f) nnsocketRecv(s, b, l, f)
#define send(s, b, l, f) nnsocketSend(s, b, l, f)
#define getsockname(s, a, l) nnsocketGetSockName(s, a, l)
#define getpeername(s, a, l) nnsocketGetPeerName(s, a, l)
#define getsockopt(s, lv, n, v, l) nnsocketGetSockOpt(s, lv, n, v, l)
#define setsockopt(s, lv, n, v, l) nnsocketSetSockOpt(s, lv, n, v, l)

#endif /* PKMN_NNSOCKET_SYS_SOCKET_H */
