/*
 * Pokemon SwSh decomp: Nintendo's nn::ssl TLS backend for libcurl (not
 * public), Sword 0x71017775a0 to 0x7101778130 (see nnssl.h), reconstructed
 * from the binary. Neither the file's nor the functions' names are known.
 */

#include "curl_setup.h"

#ifdef USE_NINTENDO_SSL

#include <stdint.h>
#include <stdio.h>

#include "urldata.h"
#include "vtls.h"
#include "connect.h" /* Pokemon SwSh decomp: Curl_timeleft */

#include <fcntl.h>
#include <string.h>

/* The SDK's C API (nnResult: curl_nnos.h) */
#include "curl_nnos.h"

bool nnResultIsSuccess(nnResult result);
int nnResultGetModule(nnResult result);
int nnResultGetDescription(nnResult result);
nnResult nnsslInitialize(void);
nnResult nnsslFinalize(void);
nnResult nnsslConnectionPending(void *connection, int *pending);
nnResult nnsslConnectionGetConnectionId(void *connection, uint64_t *id);
nnResult nnsslConnectionDestroy(void *connection);
nnResult nnsslConnectionRead(void *connection, char *buffer, int *count,
                             size_t length);
nnResult nnsslConnectionWrite(void *connection, const void *buffer,
                              int *count, size_t length);
nnResult nnsslContextGetContextId(void *context, uint64_t *id);
nnResult nnsslContextDestroy(void *context);
nnResult nnsslConnectionCreate(void *connection, void *context);
nnResult nnsslConnectionSetOption(void *connection, int option, bool enable);
nnResult nnsslConnectionSetSocketDescriptor(void *connection, int socket);
nnResult nnsslConnectionSetHostName(void *connection, const char *name,
                                    size_t length);
nnResult nnsslConnectionSetVerifyOption(void *connection, int options);
nnResult nnsslConnectionSetSessionCacheMode(void *connection, int mode);
nnResult nnsslConnectionSetIoMode(void *connection, int mode);
nnResult nnsslConnectionDoHandshakeWithCertBuffer(void *connection,
                                                  uint32_t *certSize,
                                                  uint32_t *certCount);
nnResult nnsslConnectionGetVerifyCertError(void *connection,
                                           nnResult *error);
int nnsocketFcntl(int s, int cmd, ...);

/* The result a non-blocking read or write fails with when it would block
   (by its value). */
#define UNK_RESULT_WOULD_BLOCK 0x1987b

/* Sword 0x71017775a0: curlssl_init(). A failure with the result 0x1927b (the
   library already initialised, by its value) is a success. */
int Unk_17775a0(void)
{
  nnResult result = nnsslInitialize();
  if(nnResultIsFailure(result)) {
    nnResult initialized = {0x1927b};
    if(nnResultGetModule(result) != nnResultGetModule(initialized))
      return 0;
    if(nnResultGetDescription(result) != nnResultGetDescription(initialized))
      return 0;
  }
  return 1;
}

/* Sword 0x7101777640: curlssl_cleanup() */
void Unk_1777640(void)
{
  nnsslFinalize();
}

static ssize_t Unk_1777fa0(struct connectdata *conn, int sockindex,
                           char *buf, size_t len, CURLcode *curlcode);
static ssize_t Unk_1778060(struct connectdata *conn, int sockindex,
                           const void *mem, size_t len, CURLcode *curlcode);

/* Two results are the same failure: their modules and descriptions are. */
static bool result_is(nnResult result, uint32_t value)
{
  nnResult other = {value};
  return nnResultGetModule(result) == nnResultGetModule(other) &&
         nnResultGetDescription(result) == nnResultGetDescription(other);
}

/* What field_30's callback gets after a handshake: whether it succeeded and
   the server certificates' size and count from
   nnsslConnectionDoHandshakeWithCertBuffer. field_1 is copied from 7 bytes
   of the handshake's that nothing sets. */
struct Unk_1777650_Handshake {
  bool field_0;
  unsigned char field_1[7];
  uint64_t field_8;
  uint64_t field_10;
};
_Static_assert(sizeof(struct Unk_1777650_Handshake) == 0x18, "Handshake");

/* Sword 0x7101777650: curlssl_connect_nonblocking(). The CURLcodes 0x5d,
   0x5e, 0x5f and 0x61 are Nintendo's (curl 7.55.1's end at 92). */
/* NON_MATCHING: the same calls and tests, laid out differently: this
   jumps from the would-block handshake straight to the CURLE_OK return,
   where the original goes through the error dispatch, and spills more (a
   0xa0-byte frame, the original's is 0x90). */
CURLcode Unk_1777650(struct connectdata *conn, int sockindex, bool *done)
{
  CURLcode result = (CURLcode)0x61;
  struct ssl_connect_data *connssl;
  struct Curl_easy *data;
  nnResult nnresult;
  uint32_t certCount;
  uint32_t certSize;
  unsigned char unknown[7];

  if(!conn || !done)
    return result;
  connssl = &conn->ssl[sockindex];
  if(connssl->state == ssl_connection_complete) {
    *done = TRUE;
    return CURLE_OK;
  }

  if(connssl->connecting_state == ssl_connect_1) {
    uint64_t id;
    int verify;
    data = conn->data;
    id = 0;
    if(data->set.ssl.primary.field_18) {
      connssl->field_110 = data->set.ssl.primary.field_18;
      connssl->field_118 = TRUE;
    }
    else {
      connssl->field_118 = FALSE;
      connssl->field_110 = connssl->field_90;
      nnresult = nnsslContextGetContextId(connssl->field_110, &id);
      if(nnResultIsFailure(nnresult)) {
        result = (CURLcode)0x5f;
        goto fail;
      }
      if(id) {
        nnresult = nnsslContextDestroy(connssl->field_110);
        if(nnResultIsFailure(nnresult)) {
          result = (CURLcode)0x5f;
          goto fail;
        }
      }
      if(!data->set.ssl.fsslctx && !data->set.ssl.primary.field_18) {
        result = (CURLcode)0x5d;
        goto fail;
      }
      if((*data->set.ssl.fsslctx)(conn->data, connssl->field_110,
                                  conn->data->set.ssl.fsslctxp)) {
        result = CURLE_ABORTED_BY_CALLBACK;
        goto fail;
      }
    }
    nnresult = nnsslContextGetContextId(connssl->field_110, &id);
    if(nnResultIsFailure(nnresult)) {
      result = (CURLcode)0x5f;
      goto fail;
    }
    if(!id) {
      result = (CURLcode)0x5e;
      goto fail;
    }
    if(nnResultIsFailure(nnsslConnectionCreate(connssl->field_10,
                                               connssl->field_110)))
      goto connect_error;
    nnsocketFcntl(conn->sock[sockindex], F_SETFL, 0);
    if(nnResultIsFailure(nnsslConnectionSetOption(connssl->field_10, 0,
                                                  TRUE)))
      goto connect_error;
    if(nnResultIsFailure(nnsslConnectionSetSocketDescriptor(
         connssl->field_10, conn->sock[sockindex])))
      goto connect_error;
    if(nnResultIsFailure(nnsslConnectionSetHostName(
         connssl->field_10, conn->host.name, strlen(conn->host.name))))
      goto connect_error;
    if(nnResultIsFailure(nnsslConnectionSetOption(
         connssl->field_10, 2, conn->data->set.ssl.primary.field_40)))
      goto connect_error;
    verify = conn->data->set.ssl.primary.verifypeer;
    if(conn->data->set.ssl.primary.verifyhost)
      verify |= 2;
    if(conn->data->set.ssl.primary.field_13)
      verify |= 4;
    if(nnResultIsFailure(nnsslConnectionSetVerifyOption(connssl->field_10,
                                                        verify)))
      goto connect_error;
    if(nnResultIsFailure(nnsslConnectionSetSessionCacheMode(
         connssl->field_10, conn->data->set.ssl.primary.sessionid)))
      goto connect_error;
    if(conn->data->set.ssl.primary.field_28 &&
       ((int (*)(struct Curl_easy *, void *, void *))
        conn->data->set.ssl.primary.field_28)(
         conn->data, connssl->field_10, conn->data->set.ssl.primary.field_38)) {
      result = CURLE_ABORTED_BY_CALLBACK;
      goto fail;
    }
    if(nnResultIsFailure(nnsslConnectionSetIoMode(connssl->field_10, 2))) {
      result = CURLE_SSL_CONNECT_ERROR;
      goto close;
    }
    connssl->connecting_state = ssl_connect_2;
  }

  data = conn->data;
  if(Curl_timeleft(data, NULL, TRUE) < 0) {
    result = CURLE_OPERATION_TIMEDOUT;
    goto close;
  }
  data->set.ssl.primary.field_20 = NULL;
  data->set.ssl.certverifyresult = 0;
  certCount = 0;
  certSize = 0;
  memset(unknown, 0, sizeof(unknown));
  nnresult = nnsslConnectionDoHandshakeWithCertBuffer(connssl->field_10,
                                                      &certSize, &certCount);
  result = CURLE_OK;
  if(nnResultIsFailure(nnresult)) {
    if(result_is(nnresult, UNK_RESULT_WOULD_BLOCK))
      result = CURLE_AGAIN;
    else {
      data->set.ssl.primary.field_20 = (void *)(uintptr_t)nnresult.value;
      result = result_is(nnresult, UNK_RESULT_WOULD_BLOCK + 0x600) ?
               CURLE_PEER_FAILED_VERIFICATION : CURLE_SSL_CONNECT_ERROR;
    }
  }
  if(result != CURLE_AGAIN && data->set.ssl.primary.field_30) {
    struct Unk_1777650_Handshake handshake;
    handshake.field_0 = result == CURLE_OK;
    memcpy(handshake.field_1, unknown, sizeof(unknown));
    handshake.field_8 = certSize;
    handshake.field_10 = certCount;
    if(((int (*)(struct Curl_easy *, void *, void *,
                 struct Unk_1777650_Handshake *))
        data->set.ssl.primary.field_30)(
         conn->data, connssl->field_10, conn->data->set.ssl.primary.field_38,
         &handshake))
      result = CURLE_ABORTED_BY_CALLBACK;
  }
  if(!result) {
    *done = TRUE;
    conn->recv[sockindex] = Unk_1777fa0;
    conn->send[sockindex] = Unk_1778060;
    connssl->state = ssl_connection_complete;
    connssl->connecting_state = ssl_connect_1;
    return CURLE_OK;
  }
  goto fail;

connect_error:
  result = CURLE_SSL_CONNECT_ERROR;
fail:
  if(result == CURLE_AGAIN)
    return CURLE_OK;
  if(result == CURLE_PEER_FAILED_VERIFICATION) {
    nnResult error;
    if(!nnResultIsFailure(nnsslConnectionGetVerifyCertError(connssl->field_10,
                                                            &error))) {
      conn->data->set.ssl.certverifyresult = error.value;
      if(result_is(error, 0x25a7b) || result_is(error, 0x2607b) ||
         result_is(error, 0x25e7b))
        result = CURLE_PEER_FAILED_VERIFICATION;
      else if(result_is(error, 0x2867b))
        result = CURLE_SSL_CERTPROBLEM;
      else if(result_is(error, 0x2947b))
        result = CURLE_SSL_CACERT;
      else if(result_is(error, 0xbca7b) || result_is(error, 0xbd07b) ||
              result_is(error, 0xbce7b))
        result = CURLE_SSL_CERTPROBLEM;
      else
        result = CURLE_PEER_FAILED_VERIFICATION;
    }
  }
close:
  Unk_1777df0(conn, sockindex);
  return result;
}

/* Sword 0x7101777ed0: curlssl_version() */
size_t Unk_1777ed0(char *buffer, size_t size)
{
  if(!buffer)
    return 0;
  return snprintf(buffer, size, "nn::ssl");
}

/* Sword 0x7101777f00: curlssl_random(). It fills the buffer with zeros. */
CURLcode Unk_1777f00(struct Curl_easy *data, unsigned char *entropy,
                     size_t length)
{
  unsigned int i;
  if(!entropy)
    return CURLE_OK;
  if(!data)
    return CURLE_OK;
  for(i = 0; i < length; i++)
    entropy[i] = 0;
  return CURLE_OK;
}

/* Sword 0x7101777f30: curlssl_cert_status_request() */
bool Unk_1777f30(void)
{
  return FALSE;
}

/* Sword 0x7101777f40: curlssl_false_start() */
bool Unk_1777f40(void)
{
  return FALSE;
}

/* Sword 0x7101777f50: curlssl_data_pending() */
bool Unk_1777f50(const struct connectdata *conn, int sockindex)
{
  int pending = 0;
  nnResult result = nnsslConnectionPending(
    (void *)conn->ssl[sockindex].field_10, &pending);
  return nnResultIsSuccess(result) & (pending > 0);
}

/* Sword 0x7101777df0: curlssl_close(). It destroys the connection, and the
   context unless field_118 says it isn't the backend's. */
/* NON_MATCHING: the original computes &conn->ssl[sockindex] again for
   field_118 after storing state (two madds), where this reuses it. */
void Unk_1777df0(struct connectdata *conn, int sockindex)
{
  struct ssl_connect_data *connssl;
  uint64_t id;
  nnResult result;
  if(!conn)
    return;
  connssl = &conn->ssl[sockindex];
  id = 0;
  result = nnsslConnectionGetConnectionId((void *)connssl->field_10, &id);
  if(!nnResultIsFailure(result) && id) {
    result = nnsslConnectionDestroy((void *)connssl->field_10);
    if(nnResultIsFailure(result)) {
      /* nothing in a release build */
    }
  }
  connssl->state = ssl_connection_none;
  if(!connssl->field_118) {
    void *context = connssl->field_110;
    id = 0;
    if(context) {
      bool failed;
      result = nnsslContextGetContextId(context, &id);
      failed = nnResultIsFailure(result);
      if(id && !failed) {
        result = nnsslContextDestroy(connssl->field_110);
        if(nnResultIsFailure(result)) {
          /* nothing in a release build */
        }
      }
    }
  }
}

/* Sword 0x7101777fa0: conn->recv[] (Unk_1777650 sets it) */
static ssize_t Unk_1777fa0(struct connectdata *conn, int sockindex,
                           char *buf, size_t len, CURLcode *curlcode)
{
  int count = 0;
  nnResult result = nnsslConnectionRead((void *)conn->ssl[sockindex].field_10,
                                        buf, &count, len);
  if(nnResultIsFailure(result)) {
    nnResult wouldblock = {UNK_RESULT_WOULD_BLOCK};
    CURLcode code = CURLE_RECV_ERROR;
    if(nnResultGetModule(result) == nnResultGetModule(wouldblock) &&
       nnResultGetDescription(result) == nnResultGetDescription(wouldblock))
      code = CURLE_AGAIN;
    *curlcode = code;
    return -1;
  }
  return count;
}

/* Sword 0x7101778060: conn->send[] (Unk_1777650 sets it). Without a
   connection, data or error pointer it returns 0x61. */
static ssize_t Unk_1778060(struct connectdata *conn, int sockindex,
                           const void *mem, size_t len, CURLcode *curlcode)
{
  int count = 0;
  nnResult result;
  if(!conn || !mem || !curlcode)
    return 0x61;
  result = nnsslConnectionWrite((void *)conn->ssl[sockindex].field_10, mem,
                                &count, len);
  if(nnResultIsFailure(result)) {
    nnResult wouldblock = {UNK_RESULT_WOULD_BLOCK};
    CURLcode code = CURLE_WRITE_ERROR;
    if(nnResultGetModule(result) == nnResultGetModule(wouldblock) &&
       nnResultGetDescription(result) == nnResultGetDescription(wouldblock))
      code = CURLE_AGAIN;
    *curlcode = code;
    return -1;
  }
  return count;
}

#endif /* USE_NINTENDO_SSL */
