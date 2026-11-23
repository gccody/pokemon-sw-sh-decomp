// SiSDK3::SiString's assignments as its out-of-line copies have them inline
// (the string TU's 0x71004c42b0 and 0x71004c4700, the copy constructor
// 0x71004c45c0, the string table TU's 0x71004c8020). Placeholder names.
#pragma once

#include "SiCore_String.h"
#include "Unk_StringFuncs.h"

namespace SiSDK3 {

// A string's length (null: 0).
template <class T>
inline size_t Unk_StringLength(const T* s) {
    if (s == nullptr) {
        return 0;
    }
    size_t length = 0;
    while (s[length] != 0) {
        length++;
    }
    return length;
}

// Copies count characters (under 0: all of them) and terminates them.
template <class T>
inline void Unk_StringCopyN(T* dst, const T* src, s64 count) {
    if (count < 0) {
        count = Unk_StringLength(src);
    }
    if (dst != nullptr && count > 0) {
        for (s64 i = 0; i < count; i++) {
            dst[i] = src[i];
        }
        dst[count] = 0;
    }
}

// No characters (the buffer stays).
template <class T>
inline void Unk_StringSetEmpty(SiString<T>* self) {
    if (self->m_pBuffer != nullptr) {
        self->m_pBuffer[0] = 0;
    }
    self->field_10 = 0;
}

// Makes room for capacity characters, without keeping the contents: by
// field_18 characters more, or twice the capacity.
template <class T>
inline void Unk_StringGrow(SiString<T>* self, size_t length) {
    size_t step = self->field_18;
    size_t capacity;
    if (step != 0) {
        capacity = step + length;
    } else {
        capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
    }
    Unk_StringSetCapacity(self, capacity, false);
}

// The first count characters of s.
template <class T>
inline void Unk_StringAssignN(SiString<T>* self, const T* s, s64 count) {
    if (count == 0) {
        Unk_StringSetEmpty(self);
        return;
    }
    if (self->field_20 <= static_cast<size_t>(count)) {
        Unk_StringGrow(self, count + 1);
    }
    Unk_StringCopyN(self->m_pBuffer, s, count);
    self->field_10 = count;
}

}  // namespace SiSDK3
