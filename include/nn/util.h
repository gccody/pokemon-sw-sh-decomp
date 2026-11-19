#pragma once

// nn::util functions that NintendoWare calls, beyond nn/os.h's ReferSymbol.
// As in nn/os.h, every one is an import of `main`: the names and parameter
// types come from the imports' mangled names, the return types from how the
// callers use the results, and the classes are opaque.

#include <nn/os.h>

namespace nn {
namespace util {

// _ZN2nn4util30PickOutCharacterFromUtf8StringEPcPPKc: copies the UTF-8
// sequence at *str into the 4-byte buffer and advances *str past it.
int PickOutCharacterFromUtf8String(char* out, const char** str) noexcept;
// _ZN2nn4util27ConvertCharacterUtf8ToUtf32EPjPKc
int ConvertCharacterUtf8ToUtf32(uint32_t* out, const char* utf8) noexcept;

// _ZN2nn4util8SNPrintfEPcmPKcz
int SNPrintf(char* buffer, size_t size, const char* format, ...) noexcept;

namespace detail {
// The math constants and the sin/cos sample table of the SDK's inline math
// functions, imports of `main` (_ZN2nn4util6detail7FloatPiE, ...).
extern const float FloatPi;
extern const float FloatDegree180;
extern const uint32_t AngleIndexHalfRound;
// 256 samples of a full turn: cos, sin and the differences to the next.
struct Unk_SinCosSample {
    float field_0;
    float field_4;
    float field_8;
    float field_c;
};
extern const Unk_SinCosSample SinCosSampleTable[];
}  // namespace detail

class BinaryFileHeader {
public:
    // _ZNK2nn4util16BinaryFileHeader12GetAlignmentEv
    size_t GetAlignment() const noexcept;
};

}  // namespace util
}  // namespace nn
