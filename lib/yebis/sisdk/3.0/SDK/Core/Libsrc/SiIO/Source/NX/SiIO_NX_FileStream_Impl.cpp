// Scope: common
// SiSDK3::SiIONXFileStream.
#define UNK_SIIO_NX_FILESTREAM_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/NX/SiIO_NX_FileStream_Impl.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>

// 0x710057cfb0: SiIO's kernel (leafgen's name), 0x710057d840: its archive
// manager (leafgen's name and types)
struct Unk_57d840;
Unk_57d840* Unk_57cfb0();
u64 Unk_57d840_get(const Unk_57d840* self);
// 0x7100583b70: the archive manager's file of a path, or null
SiSDK3::Unk_VFSEntryInterface* Unk_583b70(void* manager, const char* path);
// 0x7100582d60, 0x7100582d70: fopen and fclose
FILE* Unk_582d60(const char* path, const char* mode);
void Unk_582d70(FILE* file);
// 0x71004e4400: a path's directory or file name, 0x71004c8020: a string's assignment
SiSDK3::SiString<char> Unk_4e4400(SiSDK3::SiString<char>* path, bool);
void Unk_4c8020(SiSDK3::SiString<char>* self, const SiSDK3::SiString<char>* other);
// 0x71004c4c40: a wide string to a character buffer
void Unk_4c4c40(const wchar_t* s, char* dst, s32 size);

namespace SiSDK3 {

namespace {

inline void* Unk_GetVFSManager() {
    return reinterpret_cast<void*>(Unk_57d840_get(Unk_57cfb0()));
}

inline void Unk_SwapInPlace(s16* p) {
    *p = Unk_Swap16(*p);
}
inline void Unk_SwapInPlace(u16* p) {
    *p = Unk_Swap16(*p);
}
inline void Unk_SwapInPlace(s32* p) {
    *p = Unk_Swap32(*p);
}
inline void Unk_SwapInPlace(u32* p) {
    *p = Unk_Swap32(*p);
}
inline void Unk_SwapInPlace(s64* p) {
    *p = Unk_Swap64(*p);
}
inline void Unk_SwapInPlace(u64* p) {
    *p = Unk_Swap64(*p);
}
inline void Unk_SwapInPlace(float* p) {
    Unk_SwapInPlace(reinterpret_cast<u32*>(p));
}
inline void Unk_SwapInPlace(double* p) {
    Unk_SwapInPlace(reinterpret_cast<u64*>(p));
}

// A value of the file, in the machine's byte order (0 at the end of the file).
template <class T>
inline T Unk_Read(SiIONXFileStream* self, bool advance) {
    T value;
    if (self->Unk_588cc0(&value, sizeof(T), advance) != sizeof(T)) {
        return 0;
    }
    if (self->Unk_Swaps()) {
        Unk_SwapInPlace(&value);
    }
    return value;
}

template <class T>
inline T Unk_ReadByte(SiIONXFileStream* self, bool advance) {
    T value;
    if (self->Unk_588cc0(&value, sizeof(T), advance) != sizeof(T)) {
        return 0;
    }
    return value;
}

template <class T>
inline bool Unk_Write(SiIONXFileStream* self, T value, bool advance) {
    if (self->Unk_Swaps()) {
        Unk_SwapInPlace(&value);
    }
    return self->Unk_58a520(&value, sizeof(T), advance) == sizeof(T);
}

}  // namespace

// 0x7100588110
SiIONXFileStream::SiIONXFileStream(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(nullptr), field_20(0), field_24(1), field_28(1), field_30(nullptr),
      field_60(nullptr), field_90(nullptr), field_98(nullptr), field_a0(0), field_a8(0), field_b0(0), field_b8(false),
      field_b9(true), field_ba(), field_10100(0), field_10108(0), field_10110(nullptr), field_10118(0),
      field_10120(nullptr) {}

// 0x7100588200 (D2), 0x71005882c0 (D0)
SiIONXFileStream::~SiIONXFileStream() {
    SiIONXFileStream::vf9();
}

// 0x7100588370
bool SiIONXFileStream::vf6(const char* path, u32 mode, size_t /*size*/) {
    vf9();
    if (path == nullptr || path[0] == 0) {
        return false;
    }
    if ((mode & 0x18) == 8) {
        if (Unk_GetVFSManager() != nullptr) {
            field_90 = Unk_583b70(Unk_GetVFSManager(), path);
            if (field_90 != nullptr) {
                field_98 = field_90->vf19();
                if (field_98 == nullptr) {
                    return false;
                }
                Unk_StringAssign(&field_30, path);
                {
                    SiString<char> name = Unk_4e4400(&field_30, true);
                    Unk_4c8020(&field_60, &name);
                }
                field_98->vf18(0, false);
                return true;
            }
        }
    }
    char modeString[16];
    u32 n = 0;
    if (mode & 8) {
        modeString[n] = 'r';
        n++;
    }
    if (mode & 0x10) {
        modeString[n] = 'w';
        n++;
    }
    if (mode & 1) {
        modeString[n] = 'b';
        n++;
    }
    if (mode & 2) {
        modeString[n] = 't';
        n++;
    }
    modeString[n] = 0;
    field_20 = mode;
    field_18 = Unk_582d60(path, modeString);
    if (field_18 == nullptr) {
        return false;
    }
    Unk_StringAssign(&field_30, path);
    {
        SiString<char> name = Unk_4e4400(&field_30, true);
        Unk_4c8020(&field_60, &name);
    }
    field_a0 = 0;
    field_a8 = 0;
    if (!vf12()) {
        field_a8 = Unk_FileSize();
    }
    field_b0 = 0;
    if ((field_20 & 0x98) == 0x88) {
        field_10100 = field_a8;
        ISiAllocator* pAllocator = field_8.m_pAllocator;
#line 2341
        field_10120 = pAllocator != nullptr ? static_cast<u8*>(pAllocator->vf8(1, field_10100, 0x10, __FILE__, __LINE__)) : nullptr;
        field_10110 = field_10120;
        field_10108 = 0;
        field_10118 = 0;
        fread(field_10110, field_10100, 1, field_18);
    } else {
        field_10100 = 0x10000;
        field_10110 = reinterpret_cast<u8*>((reinterpret_cast<uintptr_t>(field_ba) + 0x1f) & ~static_cast<uintptr_t>(0x1f));
        field_10108 = 0;
        field_10120 = nullptr;
        field_10118 = 0;
    }
    return true;
}

// 0x71005886d0
bool SiIONXFileStream::vf8(const wchar_t* path, u32 mode, size_t size) {
    char buffer[0x404];
    Unk_4c4c40(path, buffer, 0x400);
    return vf6(buffer, mode, size);
}

// 0x7100588740
void SiIONXFileStream::vf9() {
    Unk_Flush();
    if (field_8.m_pAllocator != nullptr) {
#line 2370
        SI_DELETE_ARRAY(field_8.m_pAllocator, field_10120);
        field_10120 = nullptr;
    }
    if (field_10110 != nullptr) {
        field_10110 = nullptr;
    }
    field_10118 = 0;
    field_10108 = 0;
    field_10100 = 0;
    const bool attached = field_b8;
    field_a0 = 0;
    field_a8 = 0;
    if (attached) {
        field_b8 = false;
        field_18 = nullptr;
    }
    if (field_98 != nullptr) {
        field_98->vf3();
        field_98 = nullptr;
    }
    if (field_90 != nullptr) {
        field_90 = nullptr;
        field_18 = nullptr;
    } else if (field_18 != nullptr) {
        Unk_582d70(field_18);
        field_18 = nullptr;
    }
}

// 0x7100588870
s64 SiIONXFileStream::vf10() {
    if (field_98 != nullptr) {
        return field_98->vf10();
    }
    if (field_18 == nullptr) {
        return 0;
    }
    if (!vf12()) {
        return field_a8;
    }
    return Unk_FileSize();
}

// 0x7100588960
void SiIONXFileStream::vf13(u32 value) {
    if (field_98 != nullptr) {
        field_98->vf13(value);
        return;
    }
    field_28 = value;
}

// 0x7100588980
void SiIONXFileStream::vf14(u32 value) {
    if (field_98 != nullptr) {
        field_98->vf14(value);
        return;
    }
    field_24 = value;
}

// 0x71005889a0
u32 SiIONXFileStream::vf15() {
    if (field_98 != nullptr) {
        return field_98->vf15();
    }
    return field_28;
}

// 0x71005889c0
u32 SiIONXFileStream::vf16() {
    if (field_98 != nullptr) {
        return field_98->vf16();
    }
    return field_24;
}

// 0x71005889e0
s64 SiIONXFileStream::vf17() {
    if (field_98 != nullptr) {
        return field_98->vf17();
    }
    if (field_18 == nullptr) {
        return 0;
    }
    return field_b0;
}

// 0x7100588a10
bool SiIONXFileStream::vf18(s64 pos, bool fromEnd) {
    if (field_98 != nullptr) {
        return field_98->vf18(pos, fromEnd);
    }
    if (field_18 == nullptr) {
        return false;
    }
    s64 old = field_b0;
    if (fromEnd) {
        field_b0 = vf10() - pos;
    } else {
        field_b0 = field_a0 + pos;
    }
    field_10118 += field_b0 - old;
    if (field_10118 < 0 || field_10118 >= field_10108) {
        Unk_Flush();
        field_10118 = 0;
        field_10108 = 0;
        fseek(field_18, field_b0, SEEK_SET);
    }
    return true;
}

// 0x7100588b40
bool SiIONXFileStream::vf19(s64 offset) {
    if (field_98 != nullptr) {
        return field_98->vf19(offset);
    }
    if (field_18 == nullptr) {
        return false;
    }
    field_b0 += offset;
    field_10118 += offset;
    if (field_10118 < 0 || field_10118 >= field_10108) {
        field_10118 = 0;
        field_10108 = 0;
        fseek(field_18, field_b0, SEEK_SET);
    }
    return true;
}

// 0x7100588bd0
bool SiIONXFileStream::vf20() {
    if (field_98 != nullptr) {
        return field_98->vf20();
    }
    if (field_18 == nullptr) {
        return false;
    }
    return vf17() >= vf10();
}

// 0x7100588c50
bool SiIONXFileStream::vf21(void* p, s64 size, bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf21(p, size, advance);
    }
    if (field_18 == nullptr) {
        return false;
    }
    return Unk_588cc0(p, size, advance) == size;
}

// 0x7100588cc0
// NON_MATCHING: the same instructions, but the test for buffered bytes is `cmp x8, #1 ; b.lt`
// instead of `subs ; b.le`, and the blocks after the loop are laid out in another order.
s64 SiIONXFileStream::Unk_588cc0(void* p, s64 size, bool advance) {
    if (size < 1) {
        return 0;
    }
    s64 pos = field_b0;
    s64 left = field_a8 - pos < size ? field_a8 - pos : size;
    if (left < 1) {
        return 0;
    }
    s64 bufferPos = field_10118;
    u8* dst = static_cast<u8*>(p);
    s64 total = 0;
    s32 refills = 0;
    if (field_10108 - field_10118 > 0) {
        s64 n = left < field_10108 - field_10118 ? left : field_10108 - field_10118;
        memcpy(dst, field_10110 + field_10118, n);
        field_10118 += n;
        field_b0 += n;
        left -= n;
        dst += n;
        total = n;
    }
    if (left > 0 && field_10118 >= field_10108) {
        do {
            s64 fill = field_10100 < field_a8 - field_b0 ? field_10100 : field_a8 - field_b0;
            field_10108 = fill;
            field_10118 = 0;
            s64 n = left < fill ? left : fill;
            s32 read = static_cast<s32>(fread(field_10110, 1, fill, field_18));
            if (read != field_10108) {
                field_10110[read] = 0xff;
                field_10110[read + 1] = 0xff;
            }
            memcpy(dst, field_10110 + field_10118, n);
            refills++;
            field_10118 += n;
            field_b0 += n;
            left -= n;
            dst += n;
            total += n;
        } while (left > 0);
    }
    if (!advance) {
        field_b0 = pos;
        field_10118 = bufferPos;
        if (refills > 0) {
            fseek(field_18, field_a0 + pos, SEEK_SET);
            field_10118 = 0;
            field_10108 = 0;
        }
    }
    return total;
}

// 0x7100588ec0
bool SiIONXFileStream::vf22(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf22(advance);
    }
    if (field_18 == nullptr) {
        return false;
    }
    return Unk_ReadByte<u8>(this, advance) != 0;
}

// 0x7100588f30
char SiIONXFileStream::vf23(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf23(advance);
    }
    if (field_18 == nullptr) {
        return 0;
    }
    return Unk_ReadByte<u8>(this, advance);
}

// 0x7100588f90
wchar_t SiIONXFileStream::vf24(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf24(advance);
    }
    if (field_18 == nullptr) {
        return 0;
    }
    wchar_t value;
    if (Unk_588cc0(&value, sizeof(value), advance) != sizeof(value)) {
        return 0;
    }
    if (Unk_Swaps()) {
        value = static_cast<s16>(Unk_Swap16(static_cast<u16>(value)));
    }
    return value;
}

// 0x7100589040
s16 SiIONXFileStream::vf26(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf26(advance);
    }
    return Unk_Read<s16>(this, advance);
}

// 0x71005890c0
s32 SiIONXFileStream::vf27(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf27(advance);
    }
    return Unk_Read<s32>(this, advance);
}

// 0x7100589150
s64 SiIONXFileStream::vf28(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf28(advance);
    }
    return Unk_Read<s64>(this, advance);
}

// 0x7100589200
u8 SiIONXFileStream::vf29(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf29(advance);
    }
    return Unk_ReadByte<u8>(this, advance);
}

// 0x7100589250
u16 SiIONXFileStream::vf30(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf30(advance);
    }
    return Unk_Read<u16>(this, advance);
}

// 0x71005892d0
u32 SiIONXFileStream::vf31(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf31(advance);
    }
    return Unk_Read<u32>(this, advance);
}

// 0x7100589360
u64 SiIONXFileStream::vf32(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf32(advance);
    }
    return Unk_Read<u64>(this, advance);
}

// 0x7100589410
float SiIONXFileStream::vf33(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf33(advance);
    }
    return Unk_Read<float>(this, advance);
}

// 0x71005894c0
double SiIONXFileStream::vf34(bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf34(advance);
    }
    return Unk_Read<double>(this, advance);
}

// 0x7100589580
// NON_MATCHING: the position and the string swap their registers (x21 and x22): the two live
// ranges are within four instructions of each other in size, and the allocator takes the longer first.
bool SiIONXFileStream::vf35(SiString<char>* str, bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf35(str, advance);
    }
    s64 pos = vf17();
    s32 length = 0;
    if (Unk_588cc0(&length, sizeof(length), true) != sizeof(length)) {
        return false;
    }
    if (Unk_Swaps()) {
        Unk_SwapInPlace(&length);
    }
    if (length <= 0) {
        Unk_StringAssign(str, "");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, "");
        s32 count = length;
        do {
            char c;
            Unk_588cc0(&c, 1, true);
            if (c != 0) {
                Unk_StringAppend(str, c);
            }
        } while (--count != 0);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100589750
// NON_MATCHING: x21 and x22 are swapped, as in vf35.
bool SiIONXFileStream::vf36(SiString<wchar_t>* str, bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf36(str, advance);
    }
    s64 pos = vf17();
    s32 length = 0;
    if (Unk_588cc0(&length, sizeof(length), true) != sizeof(length)) {
        return false;
    }
    if (Unk_Swaps()) {
        Unk_SwapInPlace(&length);
    }
    if (length <= 0) {
        Unk_StringAssign(str, L"");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, L"");
        s32 count = length;
        do {
            u8 c;
            Unk_588cc0(&c, 1, true);
            if (c != 0) {
                Unk_StringAppend(str, static_cast<wchar_t>(c));
            }
        } while (--count != 0);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100589920
// NON_MATCHING: x21 and x22 are swapped, as in vf35.
bool SiIONXFileStream::vf37(SiString<char>* str, bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf37(str, advance);
    }
    s64 pos = vf17();
    s32 length = 0;
    if (Unk_588cc0(&length, sizeof(length), true) != sizeof(length)) {
        return false;
    }
    if (Unk_Swaps()) {
        Unk_SwapInPlace(&length);
    }
    if (length <= 0) {
        Unk_StringAssign(str, "");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, "");
        s32 count = length;
        do {
            wchar_t c = 0;
            Unk_588cc0(&c, 2, true);
            if (Unk_Swaps()) {
                c = Unk_Swap16(static_cast<u16>(c));
            }
            if (static_cast<char>(c) != 0) {
                Unk_StringAppend(str, static_cast<char>(c));
            }
        } while (--count != 0);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x7100589b10
// NON_MATCHING: x21 and x22 are swapped, as in vf35.
bool SiIONXFileStream::vf38(SiString<wchar_t>* str, bool advance) {
    if (field_98 != nullptr) {
        return field_98->vf38(str, advance);
    }
    s64 pos = vf17();
    s32 length = 0;
    if (Unk_588cc0(&length, sizeof(length), true) != sizeof(length)) {
        return false;
    }
    if (Unk_Swaps()) {
        Unk_SwapInPlace(&length);
    }
    if (length <= 0) {
        Unk_StringAssign(str, L"");
    } else {
        Unk_StringReserve(str, length + 1);
        Unk_StringAssign(str, L"");
        s32 count = length;
        do {
            wchar_t c = 0;
            Unk_588cc0(&c, 2, true);
            if (Unk_Swaps()) {
                c = Unk_Swap16(static_cast<u16>(c));
            }
            if (c != 0) {
                Unk_StringAppend(str, c);
            }
        } while (--count != 0);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x710058a400
s32 SiIONXFileStream::vf43(char* p, s32 size, bool advance) {
    s64 pos = vf17();
    s32 i = 0;
    char* q = p;
    while (i < size - 1) {
        char c = vf23(true);
        if (c == '\r') {
            c = vf23(true);
        }
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

// 0x710058a4e0
bool SiIONXFileStream::vf44(const void* p, s64 size, bool advance) {
    if (field_18 == nullptr) {
        return false;
    }
    return Unk_58a520(p, size, advance) == size;
}

// 0x710058a520
// NON_MATCHING: the same instructions, but the test for room in the buffer is `cmp x8, #1 ; b.lt`
// instead of `subs ; b.le`, and the blocks after the loop are laid out in another order.
s64 SiIONXFileStream::Unk_58a520(const void* p, s64 size, bool advance) {
    if (size < 1) {
        return 0;
    }
    s64 bufferPos = field_10118;
    s64 pos = field_b0;
    const u8* src = static_cast<const u8*>(p);
    s64 total = 0;
    s32 flushes = 0;
    s64 n = field_10100 - bufferPos;
    if (n > 0) {
        if (n > size) {
            n = size;
        }
        memcpy(field_10110 + bufferPos, src, n);
        field_10118 += n;
        field_b0 += n;
        size -= n;
        src += n;
        total = n;
    }
    if (size > 0 && field_10118 >= field_10100) {
        do {
            field_10108 = field_10108 > field_10118 ? field_10108 : field_10118;
            if (field_10108 > 0) {
                if (static_cast<s32>(fwrite(field_10110, field_10108, 1, field_18)) == 1) {
                    field_10118 = 0;
                    field_10108 = 0;
                }
            }
            n = size < field_10100 ? size : field_10100;
            flushes++;
            field_10118 = 0;
            memcpy(field_10110, src, n);
            field_10118 += n;
            field_b0 += n;
            size -= n;
            src += n;
            total += n;
        } while (size > 0);
    }
    if (!advance) {
        field_b0 = pos;
        field_10118 = bufferPos;
        if (flushes > 0) {
            fseek(field_18, field_a0 + pos, SEEK_SET);
            field_10118 = 0;
            field_10108 = 0;
        }
    }
    field_10108 = field_10108 > field_10118 ? field_10108 : field_10118;
    field_a8 = field_a8 > field_b0 ? field_a8 : field_b0;
    return total;
}

// 0x710058a710
bool SiIONXFileStream::vf45(bool value, bool advance) {
    return Unk_58a520(&value, 1, advance) == 1;
}

// 0x710058a750
bool SiIONXFileStream::vf46(char value, bool advance) {
    return Unk_58a520(&value, 1, advance) == 1;
}

// 0x710058a790
bool SiIONXFileStream::vf47(wchar_t value, bool advance) {
    if (Unk_Swaps()) {
        value = static_cast<s16>(Unk_Swap16(static_cast<u16>(value)));
    }
    return Unk_58a520(&value, sizeof(value), advance) == sizeof(value);
}

// 0x710058a7f0
bool SiIONXFileStream::vf49(s16 value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058a840
bool SiIONXFileStream::vf50(s32 value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058a8a0
bool SiIONXFileStream::vf51(s64 value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058a920
bool SiIONXFileStream::vf52(u8 value, bool advance) {
    return Unk_58a520(&value, 1, advance) == 1;
}

// 0x710058a960
bool SiIONXFileStream::vf53(u16 value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058a9b0
bool SiIONXFileStream::vf54(u32 value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058aa10
bool SiIONXFileStream::vf55(u64 value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058aa90
bool SiIONXFileStream::vf56(float value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058aaf0
bool SiIONXFileStream::vf57(double value, bool advance) {
    return Unk_Write(this, value, advance);
}

// 0x710058ab70
bool SiIONXFileStream::vf58(const char* s, bool advance) {
    s64 pos = vf17();
    s32 length = static_cast<s32>(Unk_4c4290(s));
    vf50(length, true);
    for (s32 i = 0; i < length; i++) {
        char c = s[i];
        Unk_58a520(&c, 1, true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x710058ac30
bool SiIONXFileStream::vf59(const wchar_t* s, bool advance) {
    s64 pos = vf17();
    s64 length = Unk_4c45a0(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < static_cast<s32>(length); i++) {
        char c = static_cast<char>(s[i]);
        Unk_58a520(&c, 1, true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x710058ad00
bool SiIONXFileStream::vf60(const char* s, bool advance) {
    s64 pos = vf17();
    s64 length = Unk_4c4290(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < length; i++) {
        u16 c = static_cast<u8>(s[i]);
        if (field_28 != field_24) {
            c = Unk_Swap16(c);
        }
        Unk_58a520(&c, sizeof(c), true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x710058add0
bool SiIONXFileStream::vf61(const wchar_t* s, bool advance) {
    s64 pos = vf17();
    s64 length = Unk_4c45a0(s);
    vf50(static_cast<s32>(length), true);
    for (s64 i = 0; i < length; i++) {
        u16 c = static_cast<u16>(s[i]);
        if (field_28 != field_24) {
            c = Unk_Swap16(c);
        }
        Unk_58a520(&c, sizeof(c), true);
    }
    if (!advance) {
        vf18(pos, false);
    }
    return true;
}

// 0x710058aea0
bool SiIONXFileStream::vf62(const char* s, bool advance) {
    s64 pos = vf17();
    s64 length = Unk_4c4290(s);
#line 1923
    char* p = static_cast<char*>(UNK_ALLOC(Unk_GetKernel()->vf12(), length * 4 + 4));
    Unk_4c51e0(s, p, length * 4 + 4);
    s64 size = Unk_4c5480(p);
    s64 count = Unk_4c5170(p);
    vf50(static_cast<s32>(size), true);
    vf50(static_cast<s32>(count), true);
    vf44(p, size, true);
    if (!advance) {
        vf18(pos, false);
    }
    if (p != nullptr) {
#line 1945
        UNK_FREE(Unk_GetKernel()->vf12(), p);
    }
    return true;
}

// 0x710058b010
bool SiIONXFileStream::vf63(const wchar_t* s, bool advance) {
    s64 pos = vf17();
    s64 length = Unk_4c45a0(s);
#line 1966
    char* p = static_cast<char*>(UNK_ALLOC(Unk_GetKernel()->vf12(), length * 4 + 4));
    Unk_4c4e80(s, p, length * 4 + 4);
    s64 size = Unk_4c5480(p);
    s64 count = Unk_4c5170(p);
    vf50(static_cast<s32>(size), true);
    vf50(static_cast<s32>(count), true);
    vf44(p, size, true);
    if (!advance) {
        vf18(pos, false);
    }
    if (p != nullptr) {
#line 1988
        UNK_FREE(Unk_GetKernel()->vf12(), p);
    }
    return true;
}

// 0x710058b180
bool SiIONXFileStream::vf64(const wchar_t* s, bool advance) {
    s64 pos = vf17();
    bool result;
    {
        SiString<char> str(field_8.m_pAllocator);
        if (Unk_4c5b30_call(&str, const_cast<wchar_t*>(s))) {
            s32 length = static_cast<s32>(str.field_10);
            vf50(length, true);
            vf44(str.m_pBuffer, length, true);
            if (!advance) {
                vf18(pos, false);
            }
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

// 0x710058b2c0
bool SiIONXFileStream::vf65(const wchar_t* s, bool advance) {
    s64 pos = vf17();
    bool result;
    {
        SiString<char> str(field_8.m_pAllocator);
        if (Unk_4c5b70(&str, s)) {
            s32 length = static_cast<s32>(str.field_10);
            vf50(length, true);
            vf44(str.m_pBuffer, length, true);
            if (!advance) {
                vf18(pos, false);
            }
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

// 0x710058b400
bool SiIONXFileStream::vf66(const char* format, ...) {
    if (field_18 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    vfprintf(field_18, format, args);
    va_end(args);
    return true;
}

// 0x710058b4a0
bool SiIONXFileStream::vf67(const wchar_t* /*format*/, ...) {
    if (field_18 == nullptr) {
        return false;
    }
    return true;
}

// 0x710058b4e0
bool SiIONXFileStream::vf68(const char* format, ...) {
    if (field_18 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    int result = fscanf(field_18, format, args);
    va_end(args);
    return result != -1;
}

// 0x710058b580
bool SiIONXFileStream::vf69(const wchar_t* format, ...) {
    if (field_18 == nullptr) {
        return false;
    }
    va_list args;
    va_start(args, format);
    fwscanf(field_18, format, args);
    va_end(args);
    return true;
}

// 0x710058b620
void SiIONXFileStream::vf70() {
    if (field_18 != nullptr) {
        fflush(field_18);
    }
}

// 0x710058b670
bool SiIONXFileStream::vf72() {
    if (field_18 == nullptr) {
        return false;
    }
    s64 pos = vf17();
    s64 size = vf10();
    for (s64 i = pos; i < size; i += 0x1000) {
        vf18(i, false);
        vf29(true);
    }
    vf18(pos, false);
    return true;
}

// 0x710058b770
u8* SiIONXFileStream::vf79() {
    return field_10120;
}

}  // namespace SiSDK3
