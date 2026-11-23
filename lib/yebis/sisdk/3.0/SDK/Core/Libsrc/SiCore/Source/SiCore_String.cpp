// Scope: common
// SiCore's string functions (0x71004c4290 to 0x71004c5eb0): lengths, copies,
// conversions and SiString's out-of-line members, under the free-function
// names Unk_StringFuncs.h gives them. The file's name is the __FILE__ of
// 0x71004c49f0's allocation; its static initialiser is
// lib/yebis/static/Unk_4c6010.cpp.
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define UNK_SICORE_STRING_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringAssign.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>

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

// 0x71004c5a40: the three bases share one format. Three separate tests
// setting a result (8, 10, 16): the compares come out as 16, 10, 8.
bool Unk_4c5a40(char* dst, size_t, s64 value, int base) {
    bool result = false;
    if (base == 8) {
        sprintf(dst, "%llo", value);
        result = true;
    }
    if (base == 10) {
        sprintf(dst, "%llo", value);
        result = true;
    }
    if (base == 16) {
        sprintf(dst, "%llo", value);
        result = true;
    }
    return result;
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

// 0x71004c4e80: wide characters to UTF-8 (those over 0xfffe are skipped)
char* Unk_4c4e80(const wchar_t* s, char* dst, s64 size) {
    char* end = dst;
    if (s != nullptr) {
        s64 count = 0;
        for (; *s != 0; s++) {
            wchar_t c = *s;
            if (c <= 0x7f) {
                if (count >= size) {
                    break;
                }
                dst[count] = static_cast<char>(c);
                count += 1;
            } else if (c <= 0x7ff) {
                if (count + 1 >= size) {
                    break;
                }
                dst[count] = static_cast<char>(0xc0 | (c >> 6));
                dst[count + 1] = static_cast<char>(0x80 | (c & 0x3f));
                count += 2;
            } else if (c <= 0xfffe) {
                if (count + 2 >= size) {
                    break;
                }
                dst[count] = static_cast<char>(0xe0 | (c >> 12));
                dst[count + 1] = static_cast<char>(0x80 | ((c >> 6) & 0x3f));
                dst[count + 2] = static_cast<char>(0x80 | (c & 0x3f));
                count += 3;
            }
        }
        end = dst + count;
    }
    *end = 0;
    return dst;
}

// 0x71004c51e0: Latin-1 to UTF-8
char* Unk_4c51e0(const char* s, char* dst, s64 size) {
    char* end = dst;
    if (s != nullptr) {
        s64 count = 0;
        for (; *s != 0; s++) {
            u8 c = *s;
            if (static_cast<s8>(c) >= 0) {
                if (count >= size) {
                    break;
                }
                dst[count] = c;
                count += 1;
            } else {
                if (count + 1 >= size) {
                    break;
                }
                dst[count] = 0xc0 | (c >> 6);
                dst[count + 1] = 0x80 | (c & 0x3f);
                count += 2;
            }
        }
        end = dst + count;
    }
    *end = 0;
    return dst;
}

// 0x71004c4d90: UTF-8 to wide characters, at most size of them (a four-byte
// sequence makes none)
// The load-free size test is written last (it still comes first): that
// clears the count's register once, before both tests.
wchar_t* Unk_4c4d90(const char* s, wchar_t* dst, s64 size) {
    wchar_t* end = dst;
    if (s != nullptr) {
        s64 count = 0;
        if (s[0] != 0 && size >= 1) {
            s64 i = 0;
            do {
                wchar_t c = static_cast<u8>(s[i]);
                if (c < 0x80) {
                    dst[count] = c;
                    i += 1;
                } else if (c <= 0xdf) {
                    dst[count] = ((c & 0x1f) << 6) | (s[i + 1] & 0x3f);
                    i += 2;
                } else if (c <= 0xef) {
                    dst[count] = ((c & 0xf) << 12) | ((s[i + 1] & 0x3f) << 6) | (s[i + 2] & 0x3f);
                    i += 3;
                } else {
                    count--;
                    i += 4;
                }
                count++;
                if (count >= size) {
                    break;
                }
            } while (s[i] != 0);
        }
        end = dst + count;
    }
    *end = 0;
    return dst;
}

// 0x71004c4f60: UTF-8 to a wide string of count characters (under 0: as many
// as s has; a four-byte sequence makes none)
bool Unk_4c4f60(const char* s, SiSDK3::SiString<wchar_t>* dst, s64 count) {
    if (s == nullptr) {
        dst->Unk_Clear();
        return false;
    }
    if (count < 0) {
        count = Unk_4c5170(s);
    }
    SiSDK3::Unk_StringReserve(dst, count + 1);
    SiSDK3::Unk_StringResize(dst, count);
    wchar_t* out = dst->m_pBuffer;
    int n = 0;
    s64 i = 0;
    if (*s != 0) {
        do {
            wchar_t c = static_cast<u8>(s[i]);
            if (static_cast<s8>(s[i]) >= 0) {
                *out++ = c;
                n++;
                i += 1;
            } else if (c <= 0xdf) {
                *out++ = ((c & 0x1f) << 6) | (s[i + 1] & 0x3f);
                n++;
                i += 2;
            } else if (c <= 0xef) {
                *out++ = ((c & 0xf) << 12) | ((s[i + 1] & 0x3f) << 6) | (s[i + 2] & 0x3f);
                n++;
                i += 3;
            } else {
                i += 4;
            }
            if (n >= count) {
                break;
            }
        } while (s[i] != 0);
    }
    return true;
}

// The characters of s (not null). It tests s for null only where it's called:
// with the test here, call-site splitting (before the inliner) gives the
// copy's call a second copy for the path that grows the buffer.
template <class T>
static inline void Unk_StringAssignCStr(SiSDK3::SiString<T>* self, const T* s) {
    if (*s == 0) {
        SiSDK3::Unk_StringSetEmpty(self);
        return;
    }
    size_t capacity = self->field_20;
    size_t count = SiSDK3::Unk_StringLength(s);
    if (capacity <= count) {
        SiSDK3::Unk_StringGrow(self, count + 1);
    }
    SiSDK3::Unk_StringCopyN(self->m_pBuffer, s, count);
    self->field_10 = SiSDK3::Unk_StringLength(self->m_pBuffer);
}


// The characters of s, with room for them made first (0x71004c42b0 and
// 0x71004c4700). The empty string's path is the one that tests the flags
// (the original loads them there and nothing uses them).
template <class T>
static inline SiSDK3::SiString<T>* Unk_StringAssignReserved(SiSDK3::SiString<T>* self, const T* s) {
    if (s == nullptr || *s == 0) {
        SiSDK3::Unk_StringSetEmptyAny(self);
        return self;
    }
    s64 length = SiSDK3::Unk_StringLength(s);
    if (static_cast<s64>(self->field_20) < length + 1) {
        SiSDK3::Unk_StringReserve(self, length + 1);
    }
    Unk_StringAssignCStr(self, s);
    self->field_10 = length;
    return self;
}

// 0x71004c42b0
SiSDK3::SiString<wchar_t>* Unk_4c42b0(SiSDK3::SiString<wchar_t>* self, const wchar_t* s) {
    return Unk_StringAssignReserved(self, s);
}

// 0x71004c4700
SiSDK3::SiString<char>* Unk_4c4700(void* self, void* s) {
    return Unk_StringAssignReserved(static_cast<SiSDK3::SiString<char>*>(self), static_cast<const char*>(s));
}

namespace SiSDK3 {

// 0x71004c45c0
template <>
SiString<char>::SiString(const SiString<char>& other, ISiAllocator* pAllocator)
    : m_pAllocator(pAllocator), m_pBuffer(nullptr), field_10(0), field_18(0), field_20(0), field_28(0) {
    if (m_pAllocator == nullptr) {
        if (other.m_pAllocator != nullptr) {
            m_pAllocator = other.m_pAllocator;
        } else {
            m_pAllocator = Unk_4bc690() != nullptr ? Unk_4bc690() : Unk_4bc640();
        }
    }
    size_t length = other.field_10;
    if (length != 0) {
        Unk_StringSetCapacity(this, length + 1, false);
        Unk_StringCopyN(m_pBuffer, Unk_StringCStr(&other), length);
        field_10 = length;
        field_20 = length;
        field_28 = 0;
    }
}

}  // namespace SiSDK3

void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);

// 0x71004c49f0: a string of s's characters, copied through a buffer on the
// stack (or one allocated for a longer string) with the file's copies
SiSDK3::SiString<char> Unk_4c49f0(const char* s) {
    if (s == nullptr) {
        return SiSDK3::SiString<char>();
    }
    s64 size = Unk_4c4290(s) + 1;
    SiSDK3::SiString<char> result(SiSDK3::Unk_GetKernel()->vf12());
    if (size != 1) {
        if (size - 1 < 0x400) {
            char buffer[0x400];
            Unk_4c54a0(buffer, sizeof(buffer) - 1, s);
            Unk_4c4700(&result, buffer);
        } else {
#line 265
            char* buffer = static_cast<char*>(UNK_ALLOC(SiSDK3::Unk_GetKernel()->vf12(), size + 1));
            Unk_4c5520(buffer, size, s, -1);
            Unk_4c4700(&result, buffer);
#line 268
            UNK_FREE(SiSDK3::Unk_GetKernel()->vf12(), buffer);
        }
    }
    return SiSDK3::SiString<char>(result, nullptr);
}

// 0x71004c5170: a UTF-8 string's character count (by the lead bytes). Each
// branch counts the character itself: with the count after the chain,
// InstCombine merges the selects of the two two-byte ranges.
s64 Unk_4c5170(const char* s) {
    if (s == nullptr) {
        return 0;
    }
    s64 i = 0;
    s64 count = 0;
    while (s[i] != 0) {
        u8 c = s[i];
        if (static_cast<s8>(c) >= 0) {
            count++;
            i += 1;
        } else if (c < 0xc4) {
            count++;
            i += 2;
        } else if (c < 0xe0) {
            count++;
            i += 2;
        } else if (c < 0xf0) {
            count++;
            i += 3;
        } else {
            count++;
            i += 4;
        }
    }
    return count;
}

// 0x71004c5280: UTF-8 to a string of count bytes (under 0: as many as s has
// characters), each character cut to its low byte (a four-byte sequence
// makes none)
bool Unk_4c5280(const u8* s, SiSDK3::SiString<char>* dst, s64 count) {
    if (s == nullptr) {
        dst->Unk_Clear();
        return false;
    }
    if (count < 0) {
        count = Unk_4c5170(reinterpret_cast<const char*>(s));
    }
    SiSDK3::Unk_StringReserve(dst, count);
    SiSDK3::Unk_StringResize(dst, count);
    char* out = dst->m_pBuffer;
    int n = 0;
    s64 i = 0;
    if (*s != 0) {
        do {
            u8 c = s[i];
            if (static_cast<s8>(c) >= 0) {
                *out++ = c;
                n++;
                i += 1;
            } else if (c < 0xe0) {
                *out++ = (c << 6) | (s[i + 1] & 0x3f);
                n++;
                i += 2;
            } else if (c <= 0xef) {
                *out++ = (s[i + 1] << 6) | (s[i + 2] & 0x3f);
                n++;
                i += 3;
            } else {
                i += 4;
            }
            if (n >= count) {
                break;
            }
        } while (s[i] != 0);
    }
    return true;
}

// 0x71004c5520: copies at most count characters (-1: all of them) into size
// (under 1: as many as there are), cutting the string short with a
// terminator
// The counted loop comes first (`count != -1`): with the test the other way
// round the empty source's path gets the terminator store duplicated into it.
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count) {
    if (size == 0) {
        return;
    }
    if (src == nullptr) {
        if (dst != nullptr) {
            *dst = 0;
        }
        return;
    }
    s64 i = 0;
    char c = *src;
    if (count != -1) {
        while (count >= 1 && c != 0) {
            if (static_cast<s64>(size) >= 1 && i >= static_cast<s64>(size)) {
                dst[i - 1] = 0;
                return;
            }
            dst[i] = c;
            count--;
            i++;
            c = src[i];
        }
    } else {
        while (c != 0) {
            if (static_cast<s64>(size) >= 1 && i >= static_cast<s64>(size)) {
                dst[i - 1] = 0;
                return;
            }
            dst[i] = c;
            i++;
            c = src[i];
        }
    }
    dst[i] = 0;
}

// 0x71004c5750: appends at most count characters of src (-1: all of them) to
// dst, which has size characters (under 1: as many as it needs). The limit
// the original tests is the size plus the length dst had; without a count it
// stops there with no terminator.
void Unk_4c5750(char* dst, s64 size, const char* src, s64 count) {
    if (size == 0) {
        return;
    }
    s64 length = 0;
    while (*dst != 0) {
        dst++;
        length++;
    }
    s64 i = 0;
    char c = *src;
    if (count == -1) {
        while (c != 0) {
            if (size >= 1 && i >= length + size) {
                return;
            }
            *dst++ = c;
            i++;
            c = src[i];
        }
    } else {
        while (count >= 1 && c != 0) {
            if (size >= 1 && i >= length + size) {
                break;
            }
            *dst++ = c;
            count--;
            i++;
            c = src[i];
        }
    }
    *dst = 0;
}

// which of two ends (null or zero) comes first: -1, 0 or 1 (both ends'
// test is computed before a's: `orr ; csetm`, then `csinc`)
template <class T>
static inline s64 Unk_EndOrder(T a, T b) {
    s64 r = (a == 0 && b == 0) ? 0 : -1;
    return a == 0 ? r : 1;
}

// 0x71004c5630: compares two strings (with or without case): -1, 0 or 1; a
// null string is before any other
// One loop for each case: their first iterations' identical reads and tests
// are hoisted above the case's branch, as in the original. The end's result
// is computed with the end's test before it (an `orr` of both tests that the
// loops branch on).
s64 Unk_4c5630(const char* a, const char* b, bool caseSensitive) {
    s64 result = Unk_EndOrder(a, b);
    if (a == nullptr || b == nullptr) {
        return result;
    }
    if (caseSensitive) {
        for (;;) {
            char c1 = *a;
            char c2 = *b;
            bool end = c1 == 0 || c2 == 0;
            result = Unk_EndOrder(c1, c2);
            if (end) {
                return result;
            }
            if (static_cast<u8>(c1) < static_cast<u8>(c2)) {
                return -1;
            }
            if (static_cast<u8>(c1) > static_cast<u8>(c2)) {
                return 1;
            }
            a++;
            b++;
        }
    } else {
        for (;;) {
            char c1 = *a;
            char c2 = *b;
            bool end = c1 == 0 || c2 == 0;
            result = Unk_EndOrder(c1, c2);
            if (end) {
                return result;
            }
            u8 u1 = toupper(static_cast<u8>(c1));
            u8 u2 = toupper(static_cast<u8>(c2));
            if (u1 < u2) {
                return -1;
            }
            if (u1 > u2) {
                return 1;
            }
            a++;
            b++;
        }
    }
}

// 0x71004c5930: a number's digits, in groups of three (false for more than
// 255 digits)
// The count is 64-bit while the digits are taken and kept in a 32-bit one
// after (assigned in each branch): the pointer to the last digit sign-extends
// it and the loop's limit zero-extends it (`sxtw #2`, `mov w10, w8`).
bool Unk_4c5930(char* dst, size_t size, u64 value) {
    u32 digits[0x100];
    u32 n;
    if (static_cast<s64>(value) < 1) {
        digits[0] = 0;
        n = 1;
    } else {
        s64 count = 0;
        do {
            digits[count] = value % 10;
            count++;
            if (value < 10) {
                break;
            }
            value /= 10;
        } while (count < 0x100);
        n = count;
        if (n > 0xff) {
            return false;
        }
    }
    int left = n;
    const u32* digit = digits + left - 1;
    size_t i = 0;
    int pos = 0;
    do {
        dst[pos] = static_cast<char>(*digit + '0');
        if (static_cast<s64>(pos) + 1 >= static_cast<s64>(size)) {
            pos++;
            break;
        }
        pos++;
        left--;
        if (left >= 1 && left % 3 == 0) {
            dst[pos] = ',';
            pos++;
        }
        i++;
        digit--;
    } while (i < n);
    dst[pos] = 0;
    return true;
}
