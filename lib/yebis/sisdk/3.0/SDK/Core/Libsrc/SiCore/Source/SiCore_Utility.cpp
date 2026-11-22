// Scope: common
// SiCore's utilities: ids, the tick's period, noise, a string's formatting,
// names of numbers, the default allocator's callback. (The file's name is the
// callback's __FILE__, C:/workspace/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/
// SiCore_Utility.cpp; the report function and the languages aren't written.)
#include <nn/os.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

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

// 0x71004c9110: the noise of a point (not written: 344 bytes of float code)
float Unk_4c9110(float x, float y);

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
