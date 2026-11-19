#ifndef HEADER_CURL_NNSSL_H
#define HEADER_CURL_NNSSL_H
/*
 * Pokemon SwSh decomp: the API setup of Nintendo's nn::ssl TLS backend, which
 * upstream curl doesn't have. Not Nintendo's header (it isn't public): the
 * curlssl_* mapping that vtls.c's functions in the binary show. The backend's
 * functions are Sword 0x71017775a0 to 0x7101778060 (between vtls.c's code and
 * wildcard.c's; the "nn::ssl" version string is referenced from
 * 0x7101777ed0). Their names aren't known.
 */
#include "curl_setup.h"

#ifdef USE_NINTENDO_SSL

int Unk_17775a0(void);                          /* Sword 0x71017775a0 */
void Unk_1777640(void);                         /* Sword 0x7101777640 */
CURLcode Unk_1777650(struct connectdata *conn, int sockindex,
                     bool *done);               /* Sword 0x7101777650 */
void Unk_1777df0(struct connectdata *conn, int sockindex); /* 0x7101777df0 */
size_t Unk_1777ed0(char *buffer, size_t size);  /* Sword 0x7101777ed0 */
CURLcode Unk_1777f00(struct Curl_easy *data, unsigned char *entropy,
                     size_t length);            /* Sword 0x7101777f00 */
bool Unk_1777f30(void);                         /* Sword 0x7101777f30 */
bool Unk_1777f40(void);                         /* Sword 0x7101777f40 */
bool Unk_1777f50(const struct connectdata *conn,
                 int sockindex);                 /* Sword 0x7101777f50 */

/* Curl_ssl_backend() returns 30 (Sword 0x71017771a0): not one of curl.h's
   CURLSSLBACKEND_* values. */
#define CURL_SSL_BACKEND ((curl_sslbackend)30)

#define curlssl_init() Unk_17775a0()
#define curlssl_cleanup() Unk_1777640()
/* Curl_ssl_connect() isn't in the binary, so what its curlssl_connect was
   isn't known. */
#define curlssl_connect(x,y) ((void)(x), (void)(y), CURLE_NOT_BUILT_IN)
#define curlssl_connect_nonblocking Unk_1777650
/* Curl_ssl_kill_session() and Curl_ssl_close_all() call nothing of the
   backend's. */
#define curlssl_session_free(x) ((void)(x))
#define curlssl_close_all(x) ((void)(x))
#define curlssl_close Unk_1777df0
#define curlssl_shutdown(x,y) 0
#define curlssl_set_engine(x,y) (x=x, y=y, CURLE_NOT_BUILT_IN)
#define curlssl_set_engine_default(x) (x=x, CURLE_NOT_BUILT_IN)
#define curlssl_engines_list(x) (x=x, (struct curl_slist *)NULL)
#define curlssl_version Unk_1777ed0
#define curlssl_check_cxn(x) (x=x, -1)
#define curlssl_data_pending(x,y) Unk_1777f50(x, y)
#define curlssl_random(x,y,z) Unk_1777f00(x, y, z)
#define curlssl_cert_status_request() Unk_1777f30()
#define curlssl_false_start() Unk_1777f40()

#endif /* USE_NINTENDO_SSL */
#endif /* HEADER_CURL_NNSSL_H */
