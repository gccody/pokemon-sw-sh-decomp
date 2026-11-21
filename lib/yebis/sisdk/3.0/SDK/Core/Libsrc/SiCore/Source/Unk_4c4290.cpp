// Scope: common
// SiCore's string functions (0x71004c4290 to 0x71004c5eb0): lengths, copies,
// conversions and SiString's out-of-line members, under the free-function
// names Unk_StringFuncs.h gives them. The file's name isn't in the
// executable; its static initialiser is lib/yebis/static/Unk_4c6010.cpp.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c4290
s64 Unk_4c4290(const char* s) {
    if (s == nullptr) {
        return 0;
    }
    s64 length = 0;
    for (; s[length] != '\0'; length++) {
    }
    return length;
}

// 0x71004c45a0
s64 Unk_4c45a0(const wchar_t* s) {
    if (s == nullptr) {
        return 0;
    }
    s64 length = 0;
    for (; s[length] != L'\0'; length++) {
    }
    return length;
}

// 0x71004c5480
s64 Unk_4c5480(const char* s) {
    if (s == nullptr) {
        return 0;
    }
    s64 length = 0;
    for (; s[length] != '\0'; length++) {
    }
    return length;
}

// 0x71004c5860
void Unk_4c5860(char* dst, size_t, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsprintf(dst, format, args);
    va_end(args);
}

// 0x71004c58e0
s64 Unk_4c58e0(const char* s) {
    if (s == nullptr) {
        return 0;
    }
    return atol(s);
}

// 0x71004c58f0
f32 Unk_4c58f0(const char* s) {
    if (s == nullptr) {
        return 0.0f;
    }
    return static_cast<f32>(atof(s));
}

// 0x71004c5920
f64 Unk_4c5920(const char* s) {
    if (s == nullptr) {
        return 0.0;
    }
    return atof(s);
}

// 0x71004c5a40: the three bases share one format
// NON_MATCHING: the original tests the bases in this order, 16, 10 and 8;
// clang makes a switch of any spelling tried, and tests 8 first.
bool Unk_4c5a40(char* dst, size_t, s64 value, int base) {
    if (base == 16) {
        sprintf(dst, "%llo", value);
        return true;
    }
    if (base == 10) {
        sprintf(dst, "%llo", value);
        return true;
    }
    if (base == 8) {
        sprintf(dst, "%llo", value);
        return true;
    }
    return false;
}

// the formatted print with its arguments in a list
static inline void Unk_VSprintf(char* dst, size_t, const char* format, va_list args) {
    vsprintf(dst, format, args);
}

// 0x71004c5a90
void Unk_4c5a90(char* dst, size_t, const char* format, ...) {
    va_list args;
    va_start(args, format);
    Unk_VSprintf(dst, 0, format, args);
    va_end(args);
}

// 0x71004c5d50
bool Unk_4c5d50(SiSDK3::SiString<char>* self, size_t capacity, bool keep) {
    return SiSDK3::Unk_StringSetCapacityImpl(self, capacity, keep);
}

// 0x71004c5eb0
bool Unk_4c5eb0(SiSDK3::SiString<wchar_t>* self, size_t capacity, bool keep) {
    return SiSDK3::Unk_StringSetCapacityImpl(self, capacity, keep);
}

// Copies a string into size characters (size under 1: as many as it has),
// cutting it short with a terminator: 0x71004c54a0, and inline elsewhere.
template <class D, class S>
static inline void Unk_Copy(D* dst, s64 size, const S* src) {
    if (size == 0) {
        return;
    }
    D* end = dst;
    if (src != nullptr) {
        s64 i = 0;
        for (; src[i] != 0; i++) {
            if (size >= 1 && i >= size) {
                end = dst + i - 1;
                goto terminate;
            }
            dst[i] = static_cast<D>(src[i]);
        }
        end = dst + i;
    }
terminate:
    *end = 0;
}

// 0x71004c54a0
void Unk_4c54a0(char* dst, size_t size, const char* src) {
    Unk_Copy(dst, static_cast<s64>(size), src);
}

// 0x71004c4c40: a wide string's characters, each cut to a byte
char* Unk_4c4c40(const wchar_t* src, char* dst, s64 size) {
    if (src != nullptr) {
        s64 length = 0;
        for (; src[length] != 0; length++) {
        }
        s64 limit = size - 1;
        if ((length < limit ? length : limit) != 0) {
            Unk_Copy(dst, limit, src);
            return dst;
        }
    }
    *dst = 0;
    return dst;
}

// 0x71004c4d10: a multibyte string's wide characters
wchar_t* Unk_4c4d10(const char* s, wchar_t* dst, size_t size) {
    if (s == nullptr) {
        *dst = 0;
        return dst;
    }
    if (*s == 0) {
        *dst = 0;
        return dst;
    }
    mbstowcs(dst, s, size);
    return dst;
}

// 0x71004c5b70: a string from a wide one, in the C locale's encoding
bool Unk_4c5b70(SiSDK3::SiString<char>* self, const wchar_t* s) {
    mbstate_t state;
    mbsinit(&state);
    const wchar_t* src = s;
    size_t length = wcsrtombs(nullptr, &src, 0, &state);
    if (length == static_cast<size_t>(-1)) {
        return false;
    }
    SiSDK3::Unk_StringReserve(self, length + 1);
    SiSDK3::Unk_StringResize(self, length);
    src = s;
    if (wcsrtombs(self->m_pBuffer, &src, length + 1, &state) == static_cast<size_t>(-1)) {
        return false;
    }
    self->m_pBuffer[length] = 0;
    return true;
}

// 0x71004c5c60: a wide string from one in the C locale's encoding
bool Unk_4c5c60(SiSDK3::SiString<wchar_t>* self, const char* s) {
    mbstate_t state;
    mbsinit(&state);
    const char* src = s;
    size_t length = mbsrtowcs(nullptr, &src, 0, &state);
    if (length == static_cast<size_t>(-1)) {
        return false;
    }
    SiSDK3::Unk_StringReserve(self, length + 1);
    SiSDK3::Unk_StringResize(self, length);
    src = s;
    if (mbsrtowcs(self->m_pBuffer, &src, length + 1, &state) == static_cast<size_t>(-1)) {
        return false;
    }
    self->m_pBuffer[length] = 0;
    return true;
}
