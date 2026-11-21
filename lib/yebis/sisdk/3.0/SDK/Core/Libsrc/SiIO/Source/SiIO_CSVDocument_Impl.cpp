// Scope: common
// SiSDK3::SiIOCSVDocument.
#define UNK_SIIO_CSVDOCUMENT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_CSVDocument_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x710057d030: SiIO's kernel as a number (leafgen's name and type)
u64 Unk_57d030_get();
// 0x7100583340: skips a byte order mark
bool Unk_583340(SiSDK3::ISiIOStream* stream);
// 0x71004c58e0, 0x71004c58f0, 0x71004c5920: a string as numbers (null: 0)
long Unk_4c58e0(const char* s);
f32 Unk_4c58f0(const char* s);
f64 Unk_4c5920(const char* s);
// 0x71004c5a40: a number as a string in a base, 0x71004c5a90: a formatted
// string
bool Unk_4c5a40(char* dst, size_t size, s64 value, s32 base);
void Unk_4c5a90(char* dst, size_t size, const char* format, ...);

// 0x71024e9360: the empty string a string without a buffer reads as
extern char Unk_24e9360[];

// 0x710057e080
void* Unk_57e080(SiSDK3::ISiAllocator* pAllocator) {
#line 34
    return UNK_NEW(pAllocator, 0x10) SiSDK3::SiIOCSVDocument(pAllocator);
}

namespace SiSDK3 {

namespace {

inline const char* Unk_CStr(const SiString<char>* s) {
    return s->m_pBuffer != nullptr ? s->m_pBuffer : Unk_24e9360;
}

}  // namespace

// 0x710057e0d0
// NON_MATCHING: four bytes longer. The three reserves are inlined like the original's, but this
// keeps the addresses of the arrays' counts in two more callee-saved registers (a 0x50-byte frame
// instead of 0x40).
SiIOCSVDocument::SiIOCSVDocument(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(false), field_20(pAllocator), field_70(pAllocator), field_c0(pAllocator),
      field_110(pAllocator) {
    if (field_70.m_reservedCount < 0x1000) {
        field_70.Unk_Reserve(0x1000);
    }
    if (field_c0.m_reservedCount < 0x400) {
        field_c0.Unk_Reserve(0x400);
    }
    if (field_110.m_reservedCount < 0x400) {
        field_110.Unk_Reserve(0x400);
    }
}

// 0x710057e5f0 (D2), 0x710057e9b0 (D0)
SiIOCSVDocument::~SiIOCSVDocument() {}

// 0x710057e9e0
bool SiIOCSVDocument::vf5(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x28, nullptr);
    if (stream == nullptr) {
        return false;
    }
    bool result = vf6(stream);
    stream->vf3();
    return result;
}

// 0x710057ea50
bool SiIOCSVDocument::vf6(ISiIOStream* stream) {
    if (stream == nullptr) {
        return false;
    }
    if (!stream->vf11()) {
        return false;
    }
    Unk_583340(stream);
    SiString<char> line(field_8.m_pAllocator);
    while (!stream->vf20()) {
        Unk_57eb50(stream, &line);
        if (!Unk_57edd0(&line)) {
            return false;
        }
    }
    return true;
}

// 0x710057f560
bool SiIOCSVDocument::vf7(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x14, nullptr);
    if (stream == nullptr) {
        return false;
    }
    vf8(stream);
    stream->vf3();
    return true;
}

// 0x710057f9a0
u32 SiIOCSVDocument::vf10(s32 row) {
    return field_20.m_pData[row].m_itemCount;
}

// 0x710057f9c0
SiString<char>* SiIOCSVDocument::vf11(s32 column, s32 row) {
    return &field_20.m_pData[row].m_pData[column];
}

// 0x710057f9e0
s32 SiIOCSVDocument::vf12(s32 column, s32 row) {
    return Unk_4c58e0(Unk_CStr(&field_20.m_pData[row].m_pData[column]));
}

// 0x710057fa20
f32 SiIOCSVDocument::vf13(s32 column, s32 row) {
    return Unk_4c58f0(Unk_CStr(&field_20.m_pData[row].m_pData[column]));
}

// 0x710057fa50
f64 SiIOCSVDocument::vf14(s32 column, s32 row) {
    return Unk_4c5920(Unk_CStr(&field_20.m_pData[row].m_pData[column]));
}

// 0x710057fa80
// NON_MATCHING: the same instructions, but the original returns in place where the count is
// already right (its own copy of the epilogue after the first test); this branches to the
// return it shares with the other paths, as the original's vf16 does.
bool SiIOCSVDocument::vf15(s32 count) {
    return field_20.Unk_SetCount(count);
}

// 0x710057fb30
bool SiIOCSVDocument::vf16(s32 row, s32 count) {
    return field_20.m_pData[row].Unk_SetCount(count);
}

// 0x710057fbf0
// NON_MATCHING: four bytes longer. The original keeps the row's address in x0 from the test of
// its cell count to the call that grows it; this computes it again before the call.
bool SiIOCSVDocument::vf17(s32 column, s32 row, const char* value) {
    if (static_cast<s32>(field_20.m_itemCount) <= row) {
        if (!field_20.Unk_SetCount(row + 1)) {
            return false;
        }
    }
    SiArray<SiString<char> >* cells = &field_20.m_pData[row];
    if (static_cast<s32>(cells->m_itemCount) <= column) {
        if (!cells->Unk_SetCount(column + 1)) {
            return false;
        }
    }
    Unk_StringAssign(&field_20.m_pData[row].m_pData[column], value);
    return true;
}

// 0x710057fd60
bool SiIOCSVDocument::vf18(s32 column, s32 row, s32 value) {
    char text[0x100];
    Unk_4c5a40(text, sizeof(text), value, 10);
    return vf17(column, row, text);
}

// 0x710057fdd0
bool SiIOCSVDocument::vf19(s32 column, s32 row, f32 value) {
    char text[0x100];
    Unk_4c5a90(text, sizeof(text), "%f", value);
    return vf17(column, row, text);
}

// 0x710057fe40
bool SiIOCSVDocument::vf20(s32 column, s32 row, f64 value) {
    char text[0x100];
    Unk_4c5a90(text, sizeof(text), "%e", value);
    return vf17(column, row, text);
}

}  // namespace SiSDK3
