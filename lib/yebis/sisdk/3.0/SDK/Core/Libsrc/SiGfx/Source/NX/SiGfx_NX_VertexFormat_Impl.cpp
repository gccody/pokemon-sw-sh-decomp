// Scope: common
// SiSDK3::SiGfxNXVertexFormat: its construction and destruction, its name,
// its tables' accessors, and the reference counts its header defines. (Its
// other small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_VERTEXFORMAT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_VertexFormat_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c3410: a checksum
u32 Unk_4c3410(s64 size, const u8* data);
// 0x71004ed0c0: a format's size
s32 Unk_4ed0c0(u32 format);

namespace SiSDK3 {

// 0x7100564560
SiGfxNXVertexFormat::SiGfxNXVertexFormat(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator) {
    field_440 = 0;
    memset(field_7c, 0, sizeof(field_7c) + sizeof(field_3fc));
    field_78 = false;
    field_60 = 0;
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 6;
    memset(field_448, 0xff, sizeof(field_448) + sizeof(field_4e8));
    memset(field_628, 0, sizeof(field_628) + sizeof(field_6c8));
    for (s32 i = 0; i < 16; i++) {
        field_400[i] = 0x7fffffff;
        field_708[i] = 0;
    }
}

// 0x71005646c0 (D2), 0x7100564800 (D0); 0x7100564760 and 0x71005648a0 are
// their thunks for the second base
SiGfxNXVertexFormat::~SiGfxNXVertexFormat() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf21();
}

// 0x7100564960 (0x71005649a0: its thunk)
bool SiGfxNXVertexFormat::vf35(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    return true;
}

// 0x71005649e0 (0x71005649f0: its thunk)
const SiString<char>* SiGfxNXVertexFormat::vf36() {
    return &field_30;
}

// 0x7100564a00 (0x7100564a10: its thunk)
u32 SiGfxNXVertexFormat::vf37() {
    return field_60;
}

// 0x7100564cd0
void SiGfxNXVertexFormat::Unk_564cd0() {
    field_440 = 0;
    for (s32 i = 0; i < 16; i++) {
        field_6c8[i] = 0;
        field_400[i] = 0x7fffffff;
    }
    for (s32 i = 0; i < field_3fc && i < 32; i++) {
        const Unk_Element& element = field_7c[i];
        s64 stream = element.field_c;
        if (static_cast<u32>(stream) <= 15) {
            s32 offset = element.field_10;
            s32 end = Unk_4ed0c0(element.field_8) + offset;
            if (end > field_6c8[stream]) {
                field_6c8[stream] = end;
            }
            if (field_400[stream] == 0x7fffffff) {
                field_400[stream] = element.field_14;
            }
        }
    }
    for (s32 i = 0; i < 16; i++) {
        if (field_6c8[i] > 0) {
            if (field_708[i] > 0) {
                field_6c8[i] = (field_6c8[i] + field_708[i] - 1) & -field_708[i];
            }
            field_440++;
        }
    }
}

// The elements' offsets, after a change: what slots 17 and 20 start with. (A
// macro: the code is in both, and as an inline function, even a small one, it
// compiles to other code.)
#define UNK_VERTEXFORMAT_OFFSETS()                                                                                     \
    s32 offsets[16] = {};                                                                                              \
    for (s64 i = 0; i < field_3fc && i < 32; i++) {                                                                    \
        Unk_Element& element = field_7c[i];                                                                            \
        s64 stream = element.field_c;                                                                                  \
        if (static_cast<u32>(stream) <= 15) {                                                                          \
            s32 offset = element.field_10;                                                                             \
            if (offset < 0) {                                                                                          \
                offset = offsets[stream];                                                                              \
                element.field_10 = offset;                                                                             \
            } else {                                                                                                   \
                offsets[stream] = offset;                                                                              \
            }                                                                                                          \
            offsets[stream] = Unk_4ed0c0(element.field_8) + offset;                                                    \
        }                                                                                                              \
    }

// The streams' tables and the elements' checksum, after a change: what slots
// 17 and 20 end with (inlined in both; the checksum's size shares the
// sign-extended count with the loop's test only when this is a function of its
// own)
inline void SiGfxNXVertexFormat::Unk_UpdateTables() {
    memset(field_448, 0xff, sizeof(field_448) + sizeof(field_4e8));
    memset(field_628, 0, sizeof(field_628));
    for (s32 i = 0; i < field_3fc; i++) {
        const Unk_Element& element = field_7c[i];
        if (element.field_c <= 15) {
            u32 format = element.field_8;
            if (format != 0 && element.field_4 <= 15) {
                s32 offset = element.field_10;
                field_448[element.field_0][element.field_4] = element.field_c;
                field_4e8[element.field_0][element.field_4] = offset;
                field_628[element.field_0][element.field_4] = format;
            }
        }
    }
    field_444 = field_3fc < 1 ? 0 : Unk_4c3410(field_3fc * sizeof(Unk_Element), reinterpret_cast<const u8*>(field_7c));
}

// NON_MATCHING (and slot 20, which has the same code): 1 instruction: the
// first of the three stores' row index is sign-extended by a `sxtw` of its
// own in the original (`ldr w13, [x9, #4]` for the test, `sxtw x13, w13`
// where the address is computed); here CodeGenPrepare moves the extension to
// the test's load and it becomes `ldrsw`. The extension's operand is the load
// in the IR here, so it moves whatever the source order; the original's was
// something else (a phi?). Tried: the test as `< 16`, as a 64-bit compare, the
// index in an s32 or s64 local, the row through a pointer.
// (Round 3: with `(format != 0) & (element.field_4 <= 15)` the extension
// stays at the address (a `sxtw` of its own), but the stream's load is then
// scheduled after it: 6 instructions instead of 1, in every order of the
// stores and with the stream or the row in locals.)
// 0x7100564ac0
bool SiGfxNXVertexFormat::vf17(s32 count, const Unk_Element* elements) {
    vf21();
    SiGfxNXDevice* device = field_20;
    if (static_cast<u32>(count - 1) > 31 || device == nullptr) {
        return false;
    }
    field_3fc = count;
    memcpy(field_7c, elements, count * sizeof(Unk_Element));
    UNK_VERTEXFORMAT_OFFSETS();
    Unk_564cd0();
    Unk_UpdateTables();
    return true;
}

// 0x7100564e50
bool SiGfxNXVertexFormat::vf19(u32 a1, s32 a2, u32 a3, s32 a4, s32 a5, u32 a6, u32 a7) {
    if (!field_78) {
        return false;
    }
    if (field_3fc > 15) {
        return false;
    }
    field_7c[field_3fc].field_0 = a1;
    field_7c[field_3fc].field_4 = a2;
    field_7c[field_3fc].field_8 = a3;
    field_7c[field_3fc].field_c = a4;
    field_7c[field_3fc].field_10 = a5;
    field_7c[field_3fc].field_14 = a6;
    field_7c[field_3fc].field_18 = a7;
    field_3fc++;
    return true;
}

// NON_MATCHING: see slot 17 (1 instruction)
// 0x7100564ee0
bool SiGfxNXVertexFormat::vf20() {
    field_78 = false;
    UNK_VERTEXFORMAT_OFFSETS();
    Unk_564cd0();
    Unk_UpdateTables();
    return true;
}

// 0x71005650e0
const SiGfxNXVertexFormat::Unk_Element* SiGfxNXVertexFormat::vf24(s32 index) {
    s64 i = index < 0 ? 0 : ((static_cast<s32>(field_3fc) <= index || index > 31) ? 0 : index);
    return &field_7c[i];
}

// 0x7100565130
u32 SiGfxNXVertexFormat::vf26(s32 index) {
    if (static_cast<u32>(index) > 15) {
        return 0;
    }
    return field_6c8[index];
}

// 0x7100565150
s32 SiGfxNXVertexFormat::vf27(u32 stream, s32 index) {
    return field_448[stream][index];
}

// 0x7100565160
s32 SiGfxNXVertexFormat::vf28(u32 stream, s32 index) {
    return field_4e8[stream][index];
}

// 0x7100565180
u32 SiGfxNXVertexFormat::vf29(u32 stream, s32 index) {
    return field_628[stream][index];
}

// 0x71005651c0
s32 SiGfxNXVertexFormat::vf31(u32 stream) {
    s32 n = 0;
    for (s32 i = 0; i < 16; i++) {
        n += vf30(stream, i);
    }
    return n;
}

// 0x71005653f0
void SiGfxNXVertexFormat::vf33(s32 index, s32 value) {
    field_708[index] = value;
}

// 0x7100565400
s32 SiGfxNXVertexFormat::vf34(s32 index) {
    return field_708[index];
}

}  // namespace SiSDK3
