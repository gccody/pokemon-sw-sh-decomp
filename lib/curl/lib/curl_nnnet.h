#ifndef HEADER_CURL_NNNET_H
#define HEADER_CURL_NNNET_H
/*
 * Pokemon SwSh decomp: not upstream's. Nintendo's SDK build asks the SDK
 * for the host name to use (nn::nsd::ResolveEx, from Curl_setopt's
 * CURLOPT_URL) and for the system's proxy (nn::nifm::GetCurrentProxySetting,
 * from create_conn). These are the functions it calls for that, Sword
 * 0x7101778430 and 0x71017785c0 (lib/curl/nintendo/Unk_1778430.cpp). Their
 * names and the header's aren't known.
 */
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The proxy setting Unk_17785c0 copies out of nn::nifm::ProxySetting
   (create_conn zeroes it on the stack, 0xb4 bytes). Only what the two
   functions touch is known: field_4 says whether a proxy is set (create_conn
   then uses field_6 as the port and field_8 as the host), field_70 whether
   the proxy needs a user name (field_71) and password (field_91). */
struct Unk_17785c0_Setting {
  int field_0;
  bool field_4;
  unsigned short field_6;
  char field_8[100];
  int field_6c;
  bool field_70;
  char field_71[32];
  char field_91[32];
};

/* Sword 0x7101778430: copies the host name that nn::nsd::ResolveEx returns
   for `host` into *out (255 characters at most, when out and *out aren't
   NULL) and returns 0, or the failure's description (or -1 when it can't
   allocate). */
int Unk_1778430(char **out, const char *host);

/* Sword 0x71017785c0: the system's proxy setting into *setting; returns 0,
   or the failure's description. */
int Unk_17785c0(struct Unk_17785c0_Setting *setting);

#ifdef __cplusplus
}
#endif

#endif /* HEADER_CURL_NNNET_H */
