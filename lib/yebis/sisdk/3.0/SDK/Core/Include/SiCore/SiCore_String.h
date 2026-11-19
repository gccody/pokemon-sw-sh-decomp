// SiSDK3's string (RTTI: SiSDK3::SiString<char>), as far as its destructor:
// the implementation is SiCore_String.inl (its __FILE__). Placeholder members.
#pragma once

#include "SiCore_Memory.h"

namespace SiSDK3 {

template <class T>
class SiString {
public:
    ~SiString() { Unk_Release(); }

    // frees the buffer unless it isn't the string's own (inline in every
    // caller: placeholder name)
    void Unk_Release();

    ISiAllocator* m_pAllocator;
    T* m_pBuffer;
    size_t field_10;
    size_t field_18;
    size_t field_20;
    u64 field_28;  // bit 0: m_pBuffer isn't the string's own
};

}  // namespace SiSDK3

#include "SiCore_String.inl"

PKMN_SIZE_ASSERT(SiSDK3::SiString<char>, 0x30);
