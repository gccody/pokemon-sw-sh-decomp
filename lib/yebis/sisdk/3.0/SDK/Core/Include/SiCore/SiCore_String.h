// SiSDK3's string (RTTI: SiSDK3::SiString<char>), as far as its destructor:
// the implementation is SiCore_String.inl (its __FILE__). Placeholder members.
#pragma once

#include <string.h>

#include "SiCore_Memory.h"

// 0x71004bc690: the kernel's allocator, or null without a kernel
SiSDK3::ISiAllocator* Unk_4bc690();

namespace SiSDK3 {
template <class T>
class SiString;
}  // namespace SiSDK3

// 0x71004c8020: a string's assignment
void Unk_4c8020(SiSDK3::SiString<char>* self, const SiSDK3::SiString<char>* other);

namespace SiSDK3 {

template <class T>
class SiString {
public:
    // the kernel's allocator for a null one (inline in every caller)
    explicit SiString(ISiAllocator* pAllocator = nullptr)
        : m_pAllocator(pAllocator), m_pBuffer(nullptr), field_10(0), field_18(0), field_20(0), field_28(0) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc690() != nullptr ? Unk_4bc690() : Unk_4bc640();
        }
    }
    // in a buffer that isn't the string's own (inline in every caller)
    SiString(ISiAllocator* pAllocator, T* pBuffer, size_t capacity)
        : m_pAllocator(pAllocator), m_pBuffer(pBuffer), field_10(0), field_18(0), field_20(capacity), field_28(1) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc690() != nullptr ? Unk_4bc690() : Unk_4bc640();
        }
        m_pBuffer[0] = 0;
    }
    ~SiString() { Unk_Release(); }

    // 0x71004c8020 (char): out of line
    SiString& operator=(const SiString& other) {
        Unk_4c8020(this, &other);
        return *this;
    }

    // frees the buffer unless it isn't the string's own (inline in every
    // caller: placeholder name)
    void Unk_Release();
    // frees the buffer, unless it isn't the string's own; that and no
    // characters; that and no capacity (inline: placeholder names). The last
    // is Unk_Clear in three steps, which is how the capacity setters have it.
    void Unk_FreeBuffer();
    void Unk_Empty();
    void Unk_EmptyAll();
    // frees the buffer and empties the string (inline in every caller:
    // placeholder name)
    void Unk_Clear();
    // makes the string a view of s, which isn't copied (inline in its
    // caller: placeholder name)
    void Unk_SetExternal(const T* s) {
        if (s != nullptr && *s != 0) {
            m_pBuffer = const_cast<T*>(s);
            size_t length = 0;
            while (s[length] != 0) {
                length++;
            }
            field_10 = length;
            field_20 = 0;
            field_28 |= 1;
        }
    }

    ISiAllocator* m_pAllocator;
    T* m_pBuffer;
    size_t field_10;  // length
    size_t field_18;  // what a full string grows by (0: it doubles)
    size_t field_20;  // capacity
    u64 field_28;     // bit 0: m_pBuffer isn't the string's own
};

}  // namespace SiSDK3

#include "SiCore_String.inl"

PKMN_SIZE_ASSERT(SiSDK3::SiString<char>, 0x30);
