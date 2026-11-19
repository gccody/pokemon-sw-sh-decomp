/*
 * Pokemon SwSh decomp: Nintendo's nn::ssl TLS backend for libcurl (not
 * public), the functions of it reconstructed so far (see nnssl.h). The rest
 * (connect, close, recv, send) is in the binary at Sword 0x7101777650,
 * 0x7101777df0, 0x7101777fa0 and 0x7101778060. Neither the file's nor the
 * functions' names are known.
 */

#include "curl_setup.h"

#ifdef USE_NINTENDO_SSL

#include <stdint.h>
#include <stdio.h>

#include "urldata.h"
#include "vtls.h"

/* The SDK's C API: nn::Result is a 32-bit value. */
typedef struct nnResult {
  uint32_t value;
} nnResult;

bool nnResultIsSuccess(nnResult result);
bool nnResultIsFailure(nnResult result);
int nnResultGetModule(nnResult result);
int nnResultGetDescription(nnResult result);
nnResult nnsslInitialize(void);
nnResult nnsslFinalize(void);
nnResult nnsslConnectionPending(void *connection, int *pending);

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
int Unk_1777f50(const struct connectdata *conn, int sockindex)
{
  int pending = 0;
  nnResult result = nnsslConnectionPending(
    (void *)conn->ssl[sockindex].field_10, &pending);
  return nnResultIsSuccess(result) & (pending > 0);
}

#endif /* USE_NINTENDO_SSL */
