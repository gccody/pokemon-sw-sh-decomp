#pragma once

// nn::err, the parts that Pia calls. As in nn/os.h, every function is an
// import of `main` and its name and parameter types come from the import's
// mangled name (_ZN2nn3err18ErrorResultVariantC1Ev,
// _ZN2nn3err18ErrorResultVariantaSERKNS_6ResultE,
// _ZNK2nn3err18ErrorResultVariantcvNS0_9ErrorCodeEEv,
// _ZNK2nn3err18ErrorResultVariantcvNS_6ResultEEv,
// _ZNK2nn3err18ErrorResultVariant8GetStateEv,
// _ZN2nn3err18ErrorResultVariantaSERKNS0_9ErrorCodeE). The layout is what the
// callers show: Pia copies an ErrorResultVariant as 12 bytes, and the
// ErrorCode conversion returns 8 bytes in x0.

#include <nn/os.h>

namespace nn {
namespace err {

struct ErrorCode {
    uint32_t field_0;
    uint32_t field_4;
};
static_assert(sizeof(ErrorCode) == 0x8, "ErrorCode");

class ErrorResultVariant {
public:
    ErrorResultVariant() noexcept;
    ErrorResultVariant& operator=(const Result& result) noexcept;
    ErrorResultVariant& operator=(const ErrorCode& code) noexcept;
    int GetState() const noexcept;
    operator ErrorCode() const noexcept;
    operator Result() const noexcept;

    uint32_t field_0;
    uint32_t field_4;
    uint32_t field_8;
};
static_assert(sizeof(ErrorResultVariant) == 0xc, "ErrorResultVariant");

}  // namespace err
}  // namespace nn
