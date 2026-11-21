// Scope: common
// SiSDK3::SiIOMemoryStream.
#define UNK_SIIO_MEMORYSTREAM_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_MemoryStream_Impl.h>

#include <stdio.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Endian.h>

namespace SiSDK3 {

// 0x7100580550
SiIOMemoryStream::SiIOMemoryStream(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_28(0), field_30(nullptr), field_38(0), field_3c(false), field_40(1), field_44(1) {
    field_18 = 0;
    field_20 = 0;
}

// 0x71005805a0 (D2), 0x7100580610 (D0)
SiIOMemoryStream::~SiIOMemoryStream() {
    SiIOMemoryStream::vf9();
}

// 0x7100580690
bool SiIOMemoryStream::vf6(const char* /*name*/, u32 mode, size_t size) {
    vf9();
    field_38 = mode;
    if (size == 0) {
        return false;
    }
#line 151
    field_30 = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (field_30 == nullptr) {
        return false;
    }
    field_18 = size;
    field_20 = size;
    field_28 = 0;
    return true;
}

// 0x7100580760
void SiIOMemoryStream::vf9() {
    if (field_30 != nullptr) {
        if (!field_3c) {
#line 221
            UNK_FREE(field_8.m_pAllocator, field_30);
        }
        field_30 = nullptr;
    }
    field_28 = 0;
    field_20 = 0;
    field_18 = 0;
}

// 0x71005807d0
bool SiIOMemoryStream::vf79(u64 length) {
    if (length > static_cast<u64>(field_18)) {
        return false;
    }
    field_20 = length;
    return true;
}

// 0x7100580870
bool SiIOMemoryStream::vf18(s64 pos, bool fromEnd) {
    if (field_30 == nullptr) {
        return false;
    }
    if (fromEnd) {
        pos = field_18 - pos;
        if (pos < 0) {
            return false;
        }
    } else {
        if (pos > field_18) {
            return false;
        }
    }
    field_28 = pos;
    Unk_UpdateLength();
    return true;
}

// 0x71005808e0
bool SiIOMemoryStream::vf19(s64 offset) {
    if (field_30 == nullptr) {
        return false;
    }
    s64 pos = field_28 + offset;
    if (pos < 0) {
        return false;
    }
    if (pos > field_18) {
        return false;
    }
    field_28 = pos;
    Unk_UpdateLength();
    return true;
}

// 0x7100580980
bool SiIOMemoryStream::vf21(void* p, s64 size, bool advance) {
    if (field_30 == nullptr) {
        return false;
    }
    if (field_28 + size > field_18) {
        return false;
    }
    if (advance) {
        memcpy(p, field_30 + field_28, size);
        field_28 += size;
    } else {
        s64 pos = vf17();
        memcpy(p, field_30 + field_28, size);
        field_28 += size;
        vf18(pos, false);
    }
    return true;
}

// 0x7100580a70
bool SiIOMemoryStream::vf22(bool advance) {
    if (field_30 == nullptr) {
        return false;
    }
    u8 value = field_30[field_28];
    if (advance) {
        field_28++;
    }
    return value != 0;
}

// 0x7100580aa0
s32 SiIOMemoryStream::vf23(bool advance) {
    if (field_30 == nullptr) {
        return 0;
    }
    u8 value = field_30[field_28];
    if (advance) {
        field_28++;
    }
    return value;
}

// 0x7100580ad0
wchar_t SiIOMemoryStream::vf24(bool advance) {
    if (field_30 == nullptr) {
        return 0;
    }
    wchar_t value = *reinterpret_cast<wchar_t*>(field_30 + field_28);
    if (advance) {
        field_28 += sizeof(wchar_t);
    }
    if (Unk_Swaps()) {
        value = Unk_Swap16(static_cast<u16>(value));
    }
    return value;
}

// 0x7100580b30
s16 SiIOMemoryStream::vf26(bool advance) {
    u16 value = *reinterpret_cast<u16*>(field_30 + field_28);
    if (advance) {
        field_28 += 2;
    }
    if (Unk_Swaps()) {
        value = Unk_Swap16(value);
    }
    return value;
}

// 0x7100580b60
s32 SiIOMemoryStream::vf27(bool advance) {
    u32 value = *reinterpret_cast<u32*>(field_30 + field_28);
    if (advance) {
        field_28 += 4;
    }
    if (Unk_Swaps()) {
        value = Unk_Swap32(value);
    }
    return value;
}

// 0x7100580ba0
s64 SiIOMemoryStream::vf28(bool advance) {
    u64 value = *reinterpret_cast<u64*>(field_30 + field_28);
    if (advance) {
        field_28 += 8;
    }
    if (Unk_Swaps()) {
        value = Unk_Swap64(value);
    }
    return value;
}

// 0x7100580c10
u8 SiIOMemoryStream::vf29(bool advance) {
    u8 value = field_30[field_28];
    if (advance) {
        field_28++;
    }
    return value;
}

// 0x7100580c30
u16 SiIOMemoryStream::vf30(bool advance) {
    u16 value = *reinterpret_cast<u16*>(field_30 + field_28);
    if (advance) {
        field_28 += 2;
    }
    if (Unk_Swaps()) {
        value = Unk_Swap16(value);
    }
    return value;
}

// 0x7100580c60
u32 SiIOMemoryStream::vf31(bool advance) {
    u32 value = *reinterpret_cast<u32*>(field_30 + field_28);
    if (advance) {
        field_28 += 4;
    }
    if (Unk_Swaps()) {
        value = Unk_Swap32(value);
    }
    return value;
}

// 0x7100580ca0
u64 SiIOMemoryStream::vf32(bool advance) {
    u64 value = *reinterpret_cast<u64*>(field_30 + field_28);
    if (advance) {
        field_28 += 8;
    }
    if (Unk_Swaps()) {
        value = Unk_Swap64(value);
    }
    return value;
}

// 0x7100580d10
float SiIOMemoryStream::vf33(bool advance) {
    float value = *reinterpret_cast<float*>(field_30 + field_28);
    if (advance) {
        field_28 += 4;
    }
    if (Unk_Swaps()) {
        value = Unk_SwapFloat(value);
    }
    return value;
}

// 0x7100580d50
double SiIOMemoryStream::vf34(bool advance) {
    double value = *reinterpret_cast<double*>(field_30 + field_28);
    if (advance) {
        field_28 += 8;
    }
    if (Unk_Swaps()) {
        value = Unk_SwapDouble(value);
    }
    return value;
}

// 0x7100580dc0
bool SiIOMemoryStream::vf35(SiString<char>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    if (length <= 0) {
        Unk_StringAssign(str, "");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, "");
        Unk_StringResize(str, length);
        vf21(str->m_pBuffer, length, true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100580f00
bool SiIOMemoryStream::vf36(SiString<wchar_t>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    if (length <= 0) {
        Unk_StringAssign(str, L"");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, L"");
        do {
            wchar_t c = vf23(true) & 0xff;
            if (c != 0) {
                Unk_StringAppend(str, c);
            }
        } while (--length != 0);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100581060
bool SiIOMemoryStream::vf37(SiString<char>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    if (length <= 0) {
        Unk_StringAssign(str, "");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, "");
        do {
            char c = static_cast<char>(vf30(true));
            if (c != 0) {
                Unk_StringAppend(str, c);
            }
        } while (--length != 0);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x71005811d0
bool SiIOMemoryStream::vf38(SiString<wchar_t>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    if (length <= 0) {
        Unk_StringAssign(str, L"");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, L"");
        Unk_StringResize(str, length);
        vf21(str->m_pBuffer, length * sizeof(wchar_t), true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100581310
bool SiIOMemoryStream::vf39(SiString<char>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    vf27(true);
    if (length <= 0) {
        Unk_StringAssign(str, "");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, "");
        Unk_StringResize(str, length);
        vf21(str->m_pBuffer, length, true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100581460
bool SiIOMemoryStream::vf40(SiString<wchar_t>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    vf27(true);
    if (length <= 0) {
        Unk_StringAssign(str, L"");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, L"");
#line 994
        char* p = static_cast<char*>(UNK_ALLOC(Unk_GetKernel()->vf12(), length + 1));
        vf21(p, length, true);
        p[length] = 0;
        Unk_4c4f60(p, str, -1);
        if (p != nullptr) {
#line 1007
            UNK_FREE(Unk_GetKernel()->vf12(), p);
        }
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100581600
bool SiIOMemoryStream::vf41(SiString<char>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    bool result;
    if (length <= 0) {
        Unk_StringAssign(str, "");
        result = true;
    } else {
        char* p = static_cast<char*>(__builtin_alloca(length + 1));
        vf21(p, length, true);
        p[length] = 0;
        Unk_StringAssign(str, "");
        result = Unk_4c5b50_call(str, p);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return result;
}

// 0x7100581710
bool SiIOMemoryStream::vf42(SiString<wchar_t>* str, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s32 length = vf27(true);
    bool result;
    if (length <= 0) {
        Unk_StringAssign(str, L"");
        result = true;
    } else {
        char* p = static_cast<char*>(__builtin_alloca(length + 1));
        vf21(p, length, true);
        p[length] = 0;
        Unk_StringAssign(str, L"");
        result = Unk_4c5c60(str, p);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return result;
}

// 0x7100581820
s32 SiIOMemoryStream::vf43(char* p, s32 size, bool advance) {
    s64 pos = vf17();
    s32 i = 0;
    char* q = p;
    while (i < size - 1) {
        char c = static_cast<char>(vf23(true));
        if (c == '\n') {
            break;
        }
        *q++ = c;
        i++;
    }
    p[i] = 0;
    if (!advance) {
        vf18(pos, false);
    }
    return i;
}

// 0x71005818e0
bool SiIOMemoryStream::vf44(const void* p, s64 size, bool advance) {
    if (field_30 == nullptr) {
        return false;
    }
    if (field_28 + size > field_18) {
        return false;
    }
    s64 pos = advance ? 0 : vf17();
    memcpy(field_30 + field_28, p, size);
    field_28 += size;
    Unk_UpdateLength();
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x71005819d0
bool SiIOMemoryStream::vf45(bool value, bool advance) {
    *reinterpret_cast<bool*>(field_30 + field_28) = value;
    if (advance) {
        field_28++;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581a30
bool SiIOMemoryStream::vf46(char value, bool advance) {
    *reinterpret_cast<char*>(field_30 + field_28) = value;
    if (advance) {
        field_28++;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581a80
bool SiIOMemoryStream::vf47(wchar_t value, bool advance) {
    if (Unk_Swaps()) {
        value = static_cast<s16>(Unk_Swap16(static_cast<u16>(value)));
    }
    *reinterpret_cast<wchar_t*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += sizeof(wchar_t);
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581b00
bool SiIOMemoryStream::vf49(s16 value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_Swap16(value);
    }
    *reinterpret_cast<s16*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 2;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581b70
bool SiIOMemoryStream::vf50(s32 value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_Swap32(value);
    }
    *reinterpret_cast<s32*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 4;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581be0
bool SiIOMemoryStream::vf51(s64 value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_Swap64(value);
    }
    *reinterpret_cast<s64*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 8;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581c70
bool SiIOMemoryStream::vf52(u8 value, bool advance) {
    field_30[field_28] = value;
    if (advance) {
        field_28++;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581cc0
bool SiIOMemoryStream::vf53(u16 value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_Swap16(value);
    }
    *reinterpret_cast<u16*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 2;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581d30
bool SiIOMemoryStream::vf54(u32 value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_Swap32(value);
    }
    *reinterpret_cast<u32*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 4;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581da0
bool SiIOMemoryStream::vf55(u64 value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_Swap64(value);
    }
    *reinterpret_cast<u64*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 8;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581e30
bool SiIOMemoryStream::vf56(float value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_SwapFloat(value);
    }
    *reinterpret_cast<float*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 4;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581eb0
bool SiIOMemoryStream::vf57(double value, bool advance) {
    if (Unk_Swaps()) {
        value = Unk_SwapDouble(value);
    }
    *reinterpret_cast<double*>(field_30 + field_28) = value;
    if (advance) {
        field_28 += 8;
    }
    Unk_UpdateLength();
    return true;
}

// 0x7100581f50
bool SiIOMemoryStream::vf58(const char* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s64 length = Unk_4c4290(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < length; i++) {
        vf46(s[i], true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100582010
bool SiIOMemoryStream::vf59(const wchar_t* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s64 length = Unk_4c45a0(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < length; i++) {
        vf46(static_cast<char>(s[i]), true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x71005820d0
bool SiIOMemoryStream::vf60(const char* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s64 length = Unk_4c4290(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < length; i++) {
        vf53(static_cast<u8>(s[i]), true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100582190
bool SiIOMemoryStream::vf61(const wchar_t* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s64 length = Unk_4c45a0(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < length; i++) {
        vf53(static_cast<u16>(s[i]), true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100582250
bool SiIOMemoryStream::vf62(const char* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s64 length = Unk_4c4290(s);
#line 1566
    char* p = static_cast<char*>(UNK_ALLOC(Unk_GetKernel()->vf12(), length * 4 + 4));
    Unk_4c51e0(s, p, length * 4 + 4);
    s64 size = Unk_4c5480(p);
    s64 count = Unk_4c5170(p);
    vf50(static_cast<s32>(size), true);
    vf50(static_cast<s32>(count), true);
    vf44(p, size, true);
    if (p != nullptr) {
#line 1583
        UNK_FREE(Unk_GetKernel()->vf12(), p);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x71005823d0
bool SiIOMemoryStream::vf63(const wchar_t* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    s64 length = Unk_4c45a0(s);
#line 1604
    char* p = static_cast<char*>(UNK_ALLOC(Unk_GetKernel()->vf12(), length * 4 + 4));
    Unk_4c4e80(s, p, length * 4 + 4);
    s64 size = Unk_4c5480(p);
    s64 count = Unk_4c5170(p);
    vf50(static_cast<s32>(size), true);
    vf50(static_cast<s32>(count), true);
    vf44(p, size, true);
    if (p != nullptr) {
#line 1621
        UNK_FREE(Unk_GetKernel()->vf12(), p);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100582550
bool SiIOMemoryStream::vf64(const wchar_t* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    bool result;
    {
        SiString<char> str(field_8.m_pAllocator);
        if (Unk_4c5b30_call(&str, const_cast<wchar_t*>(s))) {
            s32 length = static_cast<s32>(str.field_10);
            vf50(length, true);
            vf44(str.m_pBuffer, length, true);
            result = true;
        } else {
            result = false;
        }
    }
    if (!advance) {
        vf18(pos, false);
    }
    return result;
}

// 0x71005826a0
bool SiIOMemoryStream::vf65(const wchar_t* s, bool advance) {
    s64 pos = advance ? 0 : vf17();
    bool result;
    {
        SiString<char> str(field_8.m_pAllocator);
        if (Unk_4c5b70(&str, s)) {
            s32 length = static_cast<s32>(str.field_10);
            vf50(length, true);
            vf44(str.m_pBuffer, length, true);
            result = true;
        } else {
            result = false;
        }
    }
    if (!advance) {
        vf18(pos, false);
    }
    return result;
}

// 0x71005827f0
bool SiIOMemoryStream::vf66(const char* format, ...) {
    if (field_30 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    if (field_28 > field_18) {
        return false;
    }
    vsprintf(reinterpret_cast<char*>(field_30 + field_28), format, args);
    Unk_UpdateLength();
    return true;
}

// 0x71005828f0
bool SiIOMemoryStream::vf67(const wchar_t* format, ...) {
    if (field_30 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    if (field_28 > field_18) {
        return false;
    }
    vswprintf(reinterpret_cast<wchar_t*>(field_30 + field_28), field_18, format, args);
    Unk_UpdateLength();
    return true;
}

// 0x7100582a00
bool SiIOMemoryStream::vf68(const char* format, ...) {
    if (field_30 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    sscanf(reinterpret_cast<const char*>(field_30), format, args);
    va_end(args);
    return true;
}

// 0x7100582aa0
bool SiIOMemoryStream::vf69(const wchar_t* format, ...) {
    if (field_30 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    swscanf(reinterpret_cast<const wchar_t*>(field_30), format, args);
    va_end(args);
    return true;
}

}  // namespace SiSDK3
