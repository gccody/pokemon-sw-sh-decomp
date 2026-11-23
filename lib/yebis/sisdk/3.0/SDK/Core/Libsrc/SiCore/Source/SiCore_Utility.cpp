// Scope: common
// SiCore's utilities: ids, the tick's period, noise, a string's formatting,
// names of numbers, the default allocator's callback. (The file's name is the
// callback's __FILE__, C:/workspace/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/
// SiCore_Utility.cpp; the report function and the languages aren't written.)
#include <nn/os.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringAssign.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c5630: compares two strings, with case or without
s64 Unk_4c5630(const char* a, const char* b, bool caseSensitive);

// 0x71004c8f70
SiSDK3::SI_GUID Unk_4c8f70() {
    SiSDK3::SI_GUID id = {};
    return id;
}

// 0x71004c8f80
bool Unk_4c8f80(const void* a, const void* b) {
    const SiSDK3::SI_GUID* pA = static_cast<const SiSDK3::SI_GUID*>(a);
    const SiSDK3::SI_GUID* pB = static_cast<const SiSDK3::SI_GUID*>(b);
    for (int i = 0; i < 16; i++) {
        if (pA->field_0[i] != pB->field_0[i]) {
            return false;
        }
    }
    return true;
}

// 0x710276ba98: how long a system tick is, in seconds
double Unk_276ba98 __attribute__((visibility("hidden")));

// 0x71004c9300
void Unk_4c9300() {
    nn::os::GetSystemTick();
    SiSDK3::Unk_SystemInfoInterface* pInfo = SiSDK3::Unk_GetKernel()->vf15();
    if (pInfo != nullptr && *pInfo->vf5() > 0) {
        Unk_276ba98 = 1.0 / static_cast<double>(*pInfo->vf5());
    }
}

// The noise's tables (Unk_4ca6a0.cpp): a permutation and the gradients' x
// and y
extern int Unk_276bc20[0x100];
extern float Unk_276c020[0x100];
extern float Unk_276c420[0x100];

// The noise's helpers (placeholder names): a number of the permutation, the
// dot product of a gradient and a point, the fade curve and the blend
static inline int Unk_NoisePerm(int i) { return Unk_276bc20[i & 0xff]; }
static inline float Unk_NoiseGrad(int h, float x, float y) { return x * Unk_276c020[h] + y * Unk_276c420[h]; }
static inline float Unk_NoiseFade(float t) { return t * (t * (t * (t * (t * 6.0f - 15.0f) + 10.0f))); }
static inline float Unk_NoiseLerp(float t, float a, float b) { return a + t * (b - a); }
// 0x71004c9110: the gradient noise of a point (the permutation's first number
// stands where a third coordinate's would)
// NON_MATCHING: the same instructions, scheduled in another order (the
// hashes of the second row are computed later in the original, between the
// first row's products) and with other registers.
float Unk_4c9110(float x, float y) {
    int ix = static_cast<int>(floorf(x));
    int iy = static_cast<int>(floorf(y));
    x -= static_cast<float>(ix);
    y -= static_cast<float>(iy);
    float n00 = Unk_NoiseGrad(Unk_NoisePerm(Unk_NoisePerm(Unk_NoisePerm(0) + iy) + ix), x, y);
    float n10 = Unk_NoiseGrad(Unk_NoisePerm(Unk_NoisePerm(Unk_NoisePerm(0) + iy) + (ix + 1)), x - 1.0f, y);
    float n01 = Unk_NoiseGrad(Unk_NoisePerm(Unk_NoisePerm(Unk_NoisePerm(0) + iy + 1) + ix), x, y - 1.0f);
    float n11 = Unk_NoiseGrad(Unk_NoisePerm(Unk_NoisePerm(Unk_NoisePerm(0) + iy + 1) + (ix + 1)), x - 1.0f, y - 1.0f);
    float u = Unk_NoiseFade(x);
    float v = Unk_NoiseFade(y);
    return Unk_NoiseLerp(v, Unk_NoiseLerp(u, n00, n10), Unk_NoiseLerp(u, n01, n11));
}

// 0x71004c9270: the noise's octaves, each at twice the frequency and half the
// weight of the one before
float Unk_4c9270(float x, float y, int octaves) {
    float sum = 0.0f;
    float scale = 1.0f;
    for (int i = 0; i < octaves; i++) {
        sum += scale * Unk_4c9110(x, y);
        scale *= 0.5f;
        x *= 2.0f;
        y *= 2.0f;
    }
    return sum;
}

// 0x71004c9fe0: replaces a string by a formatted one (at most 4096
// characters)
void Unk_4c9fe0(SiSDK3::SiString<char>* self, const char* format, va_list args) {
    SiSDK3::ISiAllocator* pAllocator = Unk_4bc690() != nullptr ? Unk_4bc690() : Unk_4bc640();
    static_cast<void>(pAllocator);
    char buffer[0x1000];
    s64 length = vsprintf(buffer, format, args);
    size_t needed = length + self->field_10 + 1;
    if (needed > self->field_20) {
        Unk_4c5d50(self, needed, true);
    }
    memcpy(self->m_pBuffer, buffer, length);
    self->m_pBuffer[length] = 0;
    const char* s = self->m_pBuffer;
    size_t count = 0;
    if (s != nullptr) {
        while (s[count] != 0) {
            count++;
        }
    }
    self->field_10 = count;
}

// 0x71004c9390: a language's codes (its language and its country)
bool Unk_4c9390(const Unk_4ca820_arg0& language, SiSDK3::SiString<char>* lang, SiSDK3::SiString<char>* country) {
    SiSDK3::Unk_StringAssign(lang, "");
    SiSDK3::Unk_StringAssign(country, "");
    switch (language.field_0) {
    case 1:
        SiSDK3::Unk_StringAssign(lang, "en");
        switch (language.field_4) {
        case 1:
            SiSDK3::Unk_StringAssign(country, "us");
            break;
        case 2:
            SiSDK3::Unk_StringAssign(country, "uk");
            break;
        case 3:
            SiSDK3::Unk_StringAssign(country, "au");
            break;
        case 4:
            SiSDK3::Unk_StringAssign(country, "ca");
            break;
        case 5:
            SiSDK3::Unk_StringAssign(country, "nz");
            break;
        }
        break;
    case 2:
        SiSDK3::Unk_StringAssign(lang, "ja");
        break;
    case 3:
        SiSDK3::Unk_StringAssign(lang, "zh");
        switch (language.field_4) {
        case 6:
            SiSDK3::Unk_StringAssign(country, "tw");
            break;
        case 7:
            SiSDK3::Unk_StringAssign(country, "cn");
            break;
        }
        break;
    }
    return true;
}

// 0x71004c9ba0: bits of a block of bytes, as a number (none for more than 32
// or past the block's end)
u32 Unk_4c9ba0(s32 size, const u8* data, s32 offset, s32 count) {
    if (count > 32) {
        return 0;
    }
    if (offset + count > size * 8) {
        return 0;
    }
    s32 i;
    u32 result = 0;
    for (i = 0; i < count; i++) {
        s32 bit = offset + i;
        result += ((data[bit / 8] & (1 << (bit & 7))) != 0) << i;
    }
    return result;
}

// 0x71004c9c20: sets bits of a block of bytes to a number's (none for more
// than 32 or past the block's end)
bool Unk_4c9c20(s32 size, u8* data, s32 offset, s32 count, u32 value) {
    if (count > 32) {
        return false;
    }
    if (count + offset > size * 8) {
        return false;
    }
    for (s32 i = 0; i < count; i++) {
        s32 bit = offset + i;
        s32 index = bit / 8;
        s32 shift = bit & 7;
        bool set = (value & (1 << i)) != 0;
        data[index] = (set << shift) | (data[index] & ~(1 << shift));
    }
    return true;
}

// 0x71004c9090
void Unk_4c9090(SiSDK3::SiString<char>* self, const char* format, ...) {
    va_list args;
    va_start(args, format);
    Unk_4c9fe0(self, format, args);
    va_end(args);
}

// 0x71004c9380
void* Unk_4c9380(void* dst, const void* src, size_t size) {
    return memcpy(dst, src, size);
}

// Whether a starts with b, with case or without (placeholder name).
static inline bool Unk_MatchRest(const char* a, const char* b, bool caseSensitive) {
    for (;;) {
        u8 cb = *b;
        if (!caseSensitive) {
            cb = toupper(cb);
        }
        if (cb == 0) {
            return true;
        }
        u8 ca = *a;
        if (!caseSensitive) {
            ca = toupper(ca);
        }
        if (ca != cb) {
            return false;
        }
        a++;
        b++;
    }
}

// 0x71004c99a0: where sub is in a string from start on, with case or without
// (-1: nowhere)
// NON_MATCHING: three instructions. Before the case-sensitive comparison's
// loop the original copies its two pointers ahead of the test for the end of
// sub, in the same block; here they're in a preheader of their own after it.
s64 Unk_4c99a0(const SiSDK3::SiString<char>* self, const char* sub, size_t start, bool caseSensitive) {
    s64 result = -1;
    size_t length = self->field_10;
    if (sub == nullptr || length == 0) {
        return result;
    }
    if (SiSDK3::Unk_StringLength(sub) + 1 == 1) {
        return result;
    }
    u8 first = sub[0];
    if (!caseSensitive) {
        first = toupper(first);
    }
    if (start >= length) {
        return result;
    }
    const char* buffer = self->m_pBuffer;
    for (size_t i = start; i < length; i++) {
        u8 c = buffer[i];
        if (!caseSensitive) {
            c = toupper(c);
        }
        if (c == first && Unk_MatchRest(buffer + i + 1, sub + 1, caseSensitive)) {
            result = i;
            break;
        }
    }
    return result;
}

// 0x71004c9b30, 0x71004c9b60: a number's name (the same code twice)
const char* Unk_4c9b30(u32 value) {
    switch (value) {
    case 1:
        return "Mswin";
    case 2:
        return "Mac";
    case 3:
        return "Linux";
    case 4:
        return "iOS";
    case 5:
        return "Android";
    case 6:
        return "PS4";
    case 7:
        return "NX";
    case 8:
        return "PVRwin";
    default:
        return "Unknown";
    }
}

const char* Unk_4c9b60(u32 value) {
    switch (value) {
    case 1:
        return "Mswin";
    case 2:
        return "Mac";
    case 3:
        return "Linux";
    case 4:
        return "iOS";
    case 5:
        return "Android";
    case 6:
        return "PS4";
    case 7:
        return "NX";
    case 8:
        return "PVRwin";
    default:
        return "Unknown";
    }
}

// 0x71004c9cb0: another number's name
const char* Unk_4c9cb0(u32 value) {
    switch (value) {
    case 1:
        return "BOOL";
    case 2:
        return "CHAR";
    case 3:
        return "BYTE";
    case 4:
        return "INT16";
    case 5:
        return "WORD";
    case 6:
        return "INT32";
    case 7:
        return "UINT32";
    case 8:
        return "DWORD";
    case 9:
        return "INT64";
    case 10:
        return "QWORD";
    case 11:
        return "FLOAT";
    case 12:
        return "DOUBLE";
    case 13:
        return "GUID";
    default:
        return "Unknown";
    }
}

// 0x71004c9ce0: the number of a name (the other way round, without case;
// UINT32 and QWORD aren't there)
u32 Unk_4c9ce0(const char* name) {
    if (Unk_4c5630(name, "BOOL", false) == 0) {
        return 1;
    }
    if (Unk_4c5630(name, "CHAR", false) == 0) {
        return 2;
    }
    if (Unk_4c5630(name, "BYTE", false) == 0) {
        return 3;
    }
    if (Unk_4c5630(name, "INT16", false) == 0) {
        return 4;
    }
    if (Unk_4c5630(name, "WORD", false) == 0) {
        return 5;
    }
    if (Unk_4c5630(name, "INT32", false) == 0) {
        return 6;
    }
    if (Unk_4c5630(name, "DWORD", false) == 0) {
        return 8;
    }
    if (Unk_4c5630(name, "INT64", false) == 0) {
        return 9;
    }
    if (Unk_4c5630(name, "FLOAT", false) == 0) {
        return 11;
    }
    if (Unk_4c5630(name, "DOUBLE", false) == 0) {
        return 12;
    }
    if (Unk_4c5630(name, "GUID", false) == 0) {
        return 13;
    }
    return 0;
}

// 0x71004ca0b0
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, size_t start, size_t end,
                bool caseSensitive);

// Where c is in a string from pos on (-1: nowhere) (inline: placeholder name)
static inline s64 Unk_StringFindChar(const SiSDK3::SiString<char>* self, char c, size_t pos) {
    size_t length = self->field_10;
    if (pos >= length) {
        return -1;
    }
    for (size_t i = pos; i < length; i++) {
        if (self->m_pBuffer[i] == c) {
            return i;
        }
    }
    return -1;
}

// count characters of another string from pos on (0: all of them) (inline:
// placeholder name)
static inline void Unk_StringAssignSub(SiSDK3::SiString<char>* self, const SiSDK3::SiString<char>* other, size_t pos,
                                       size_t count) {
    if (count == 0) {
        count = other->field_10 - pos;
    }
    if (self->field_20 <= count) {
        size_t step = self->field_18;
        size_t length = count + 1;
        size_t capacity;
        if (step != 0) {
            capacity = step + length;
        } else {
            capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
        }
        SiSDK3::Unk_StringSetCapacity(self, capacity, false);
    }
    SiSDK3::Unk_StringCopyN(self->m_pBuffer, other->m_pBuffer + pos, count);
    self->field_10 = count;
}

// Puts a character in front of a string (inline: placeholder name)
static inline void Unk_StringPrepend(SiSDK3::SiString<char>* self, char c) {
    if (self->field_20 < self->field_10 + 2) {
        size_t step = self->field_18;
        size_t length = self->field_10 + 2;
        size_t capacity;
        if (step != 0) {
            capacity = step + length;
        } else {
            capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
        }
        SiSDK3::Unk_StringSetCapacity(self, capacity, true);
    }
    size_t length = self->field_10;
    for (size_t i = 0; i < length; i++) {
        self->m_pBuffer[length - i] = self->m_pBuffer[length - i - 1];
    }
    self->m_pBuffer[0] = c;
    self->field_10++;
    self->m_pBuffer[self->field_10] = 0;
}

// 0x71004c94d0 (leafgen's name and type): replaces each %name% in a string by
// the kernel's value of name
void Unk_4c94d0(void* p) {
    SiSDK3::SiString<char>* self = static_cast<SiSDK3::SiString<char>*>(p);
    SiSDK3::SiString<char> name(SiSDK3::Unk_GetKernel()->vf12());
    SiSDK3::SiString<char> value(SiSDK3::Unk_GetKernel()->vf12());
    size_t pos = 0;
    while (self->field_10 != 0) {
        s64 start = Unk_StringFindChar(self, '%', pos);
        if (start < 0) {
            break;
        }
        s64 end = Unk_StringFindChar(self, '%', start + 1);
        if (end < 0) {
            break;
        }
        if (end > start + 1) {
            Unk_StringAssignSub(&name, self, start + 1, end - start - 1);
            SiSDK3::Unk_GetKernel()->vf16(SiSDK3::Unk_StringCStr(&name), &value);
            if (value.field_10 != 0) {
                Unk_StringPrepend(&name, '%');
                SiSDK3::Unk_StringAppend(&name, '%');
                Unk_4ca0b0(self, name.m_pBuffer, value.m_pBuffer, start, end, true);
                end += value.field_10 - name.field_10;
            }
        }
        pos = end + 1;
    }
}

// Moves count characters of a string from src to dst (the ranges may
// overlap), terminating it after them if they were its end (inline in the
// replacement: placeholder name)
static inline void Unk_StringMove(SiSDK3::SiString<char>* self, size_t dst, size_t src, size_t count) {
    if (src == dst || count == 0) {
        return;
    }
    size_t length = self->field_10;
    size_t end = src + count < length ? 0 : dst + count;
    if (src < dst) {
        for (s64 i = static_cast<s64>(count) - 1; i >= 0; i--) {
            self->m_pBuffer[dst + i] = self->m_pBuffer[src + i];
        }
    } else {
        memcpy(self->m_pBuffer + dst, self->m_pBuffer + src, count);
    }
    if (src + count >= length) {
        self->m_pBuffer[end] = 0;
    }
}

// 0x71004ca0b0: replaces every from in a string by to, between start and end
// (0: the string's end)
// NON_MATCHING: the backward loop and registers. The original loads each node
// through a phi of addresses (&m_pTail at the entry, the decrement's select
// in the latch), which late SimplifyCFG makes by sinking the two loads into
// the header; here LICM hoists &m_pBuffer into the preheader after the tail's
// load, so the loads aren't sunk (with any m_pBuffer access before the loop
// they are). toLength and the difference also swap callee-saved registers.
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, size_t start, size_t end,
                bool caseSensitive) {
    if (end == 0) {
        end = self->field_10;
    }
    SiSDK3::SiLinkedList<size_t> found(self->m_pAllocator);
    size_t fromLength = SiSDK3::Unk_StringLength(from);
    size_t pos = start;
    do {
        size_t index = Unk_4c99a0(self, from, pos, caseSensitive);
        if (index == static_cast<size_t>(-1)) {
            break;
        }
        found.AddTail(index);
        pos = index + fromLength;
    } while (pos < end);
    size_t count = found.m_count;
    if (count == 0) {
        return;
    }
    size_t toLength = SiSDK3::Unk_StringLength(to);
    size_t length = self->field_10;
    s64 diff = toLength - fromLength;
    size_t newLength = diff * count + length;
    if (newLength >= self->field_20) {
        SiSDK3::Unk_StringReserve(self, newLength + 1);
    }
    if (toLength < fromLength) {
        s64 offset = 0;
        for (SiSDK3::SiLinkedList<size_t>::Node* node = found.m_pHead; node != nullptr; node = node->m_pNext) {
            size_t at = node->m_value + offset;
            size_t src = at + fromLength;
            size_t dst = at + toLength;
            size_t rest = self->field_10 - src;
            Unk_StringMove(self, dst, src, rest);
            if (rest == 0) {
                self->m_pBuffer[dst] = 0;
                self->field_10 = dst;
            }
            memcpy(self->m_pBuffer + at, to, toLength);
            offset += diff;
        }
        self->m_pBuffer[newLength] = 0;
    } else {
        size_t last = self->field_10;
        s64 offset = diff * (count - 1);
        SiSDK3::SiLinkedList<size_t>::Node* node = found.m_pTail;
        for (;;) {
            size_t at = node->m_value;
            size_t src = at + fromLength;
            size_t dst = at + offset;
            Unk_StringMove(self, dst + toLength, src, last - src);
            memcpy(self->m_pBuffer + dst, to, toLength);
            if (dst + toLength >= length) {
                self->m_pBuffer[newLength] = 0;
            }
            last = at;
            offset -= diff;
            if (node == found.m_pHead) {
                break;
            }
            node = node != nullptr ? node->m_pPrev : found.m_pTail;
        }
    }
    self->field_10 = newLength;
}

// 0x71004ca610 (leafgen's name and type): the static allocator
u8* Unk_4ca610_get();

namespace SiSDK3 {

// SiSDK3::DefaultAllocatorCallback (RTTI names the class): what the default
// allocator reports through. Placeholder members; slots 4 and 5 are
// lib/yebis/class's.
class DefaultAllocatorCallback {
public:
    // with the static allocator (0x71004ca610 is its getter, under leafgen's
    // name and type)
    DefaultAllocatorCallback() : field_8(reinterpret_cast<ISiAllocator*>(Unk_4ca610_get())) {}
    virtual ~DefaultAllocatorCallback();  // 0x71004c9ec0, 0x71004c9ee0
    UNK_REFCOUNT_DECLARE;                 // 0x71004c9f20, 0x71004c9f40
    virtual u32 vf4();
    virtual void vf5();

    Unk_4bf660 field_8;
};

// 0x71004c9ec0 (D2), 0x71004c9ee0 (D0)
DefaultAllocatorCallback::~DefaultAllocatorCallback() {}

}  // namespace SiSDK3

// 0x71004c9f20 (vf2), 0x71004c9f40 (vf3)
#line 1799
UNK_REFCOUNT_DEFINE(SiSDK3::DefaultAllocatorCallback, field_8.m_pAllocator, field_8.m_count)

// 0x710276bab8
static SiSDK3::SiReflectionPropertyHandle Unk_276bab8;

// 0x710276baa0: the callback, which nothing else in the executable refers to
static SiSDK3::DefaultAllocatorCallback Unk_276baa0;

// 0x71004ca550: _GLOBAL__sub_I_SiCore_Utility.cpp
