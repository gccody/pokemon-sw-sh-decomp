// Pokemon SwSh decomp: Nintendo's nn::nsd and nn::nifm glue for libcurl, not
// public, reconstructed from the binary (Sword 0x7101778430 and
// 0x71017785c0, right after the libcurl tag function). Curl_setopt's
// CURLOPT_URL calls the first, create_conn the second (lib/curl/lib/url.c).
// Both report a failure with curl's curl_mfprintf to stderr. Neither the
// file's nor the functions' names are known (lib/curl/lib/curl_nnnet.h).

#include <stdio.h>
#include <string.h>

#include <nn/os.h>

#include <curl/curl.h>
#include <curl/mprintf.h>

#include "curl_nnnet.h"

// curl's malloc() and free() (lib/curl/lib/curl_memory.h).
extern "C" void *Unk_1778330(size_t size);
extern "C" void Unk_1778340(void *ptr);

namespace nn {

namespace nsd {

// 0x100 bytes: Unk_1778430 allocates two and copies 255 characters into
// them.
struct Fqdn {
    char field_0[0x100];
};
static_assert(sizeof(Fqdn) == 0x100, "Fqdn");

// _ZN2nn3nsd9ResolveExEPNS0_4FqdnERKS1_
Result ResolveEx(Fqdn* out, const Fqdn& in) noexcept;

}  // namespace nsd

namespace nifm {

// 0xaa bytes (Unk_17785c0 zeroes it on the stack); the offsets are where
// Unk_17785c0 reads it.
struct ProxySetting {
    bool field_0;
    uint16_t field_2;
    char field_4[100];
    bool field_68;
    char field_69[32];
    char field_89[32];
};
static_assert(sizeof(ProxySetting) == 0xaa, "ProxySetting");

// _ZN2nn4nifm22GetCurrentProxySettingEPNS0_12ProxySettingE
Result GetCurrentProxySetting(ProxySetting* setting) noexcept;

}  // namespace nifm

}  // namespace nn

// A failure's description: bits 9 to 21 of the result (ubfx #9, #13).
static int Unk_GetDescription(nn::Result result) {
    return (result.field_0 >> 9) & 0x1fff;
}

// Sword 0x7101778430
extern "C" int Unk_1778430(char** out, const char* host) {
    int ret = 0;
    nn::nsd::Fqdn* in = static_cast<nn::nsd::Fqdn*>(Unk_1778330(sizeof(nn::nsd::Fqdn)));
    memset(in, 0, sizeof(nn::nsd::Fqdn));
    nn::nsd::Fqdn* resolved = static_cast<nn::nsd::Fqdn*>(Unk_1778330(sizeof(nn::nsd::Fqdn)));
    memset(resolved, 0, sizeof(nn::nsd::Fqdn));
    if (in == NULL || resolved == NULL) {
        curl_mfprintf(stderr, "\nError: Failed to allocate memory for nn::nsd::ResolveEx().\n\n", ret);
        ret = -1;
    } else {
        strncpy(in->field_0, host, sizeof(in->field_0) - 1);
        in->field_0[sizeof(in->field_0) - 1] = '\0';
        nn::Result result = nn::nsd::ResolveEx(resolved, *in);
        if (!result.IsSuccess()) {
            ret = Unk_GetDescription(result);
            curl_mfprintf(stderr, "\nError: nn::nsd::ResolveEx() failed. Err Desc: %d\n\n", ret);
        } else if (out != NULL && *out != NULL) {
            strncpy(*out, resolved->field_0, sizeof(resolved->field_0) - 1);
            (*out)[sizeof(resolved->field_0) - 1] = '\0';
        }
    }
    if (resolved != NULL)
        Unk_1778340(resolved);
    if (in != NULL)
        Unk_1778340(in);
    return ret;
}

// Sword 0x71017785c0
extern "C" int Unk_17785c0(struct Unk_17785c0_Setting* setting) {
    nn::nifm::ProxySetting proxy = {};
    nn::Result result = nn::nifm::GetCurrentProxySetting(&proxy);
    if (!result.IsSuccess()) {
        int desc = Unk_GetDescription(result);
        curl_mfprintf(stderr, "\nError: nn::nifm::GetCurrentProxySetting() failed. Err Desc: %d\n\n",
                      desc);
        return desc;
    }
    setting->field_4 = proxy.field_0;
    if (setting->field_4) {
        setting->field_6 = proxy.field_2;
        strncpy(setting->field_8, proxy.field_4, sizeof(setting->field_8) - 1);
        setting->field_8[sizeof(setting->field_8) - 1] = '\0';
        setting->field_70 = proxy.field_68;
        if (setting->field_70) {
            strncpy(setting->field_71, proxy.field_69, sizeof(setting->field_71) - 1);
            setting->field_71[sizeof(setting->field_71) - 1] = '\0';
            strncpy(setting->field_91, proxy.field_89, sizeof(setting->field_91) - 1);
            setting->field_91[sizeof(setting->field_91) - 1] = '\0';
        }
    }
    return 0;
}
