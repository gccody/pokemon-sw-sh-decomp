// Scope: common
// SiSDK3::SiGfxShaderEffectVariation: the destructors and what they call.
#include <string.h>

#define UNK_SIGFX_SHADEREFFECTVARIATION_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariation_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

// 0x7100582f10, 0x7100582f70: skip to, and fill up to, a multiple of alignment
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);

// 0x71004c9ba0: a key's bits, 0x71004c5860: a formatted string, 0x71004c4290:
// a string's length
s32 Unk_4c9ba0(s32 size, const u8* bytes, s32 offset, s32 count);
s32 Unk_4c5860(char* dst, size_t size, const char* format, ...);
s64 Unk_4c4290(const char* s);
// 0x71004ca0b0: replaces one string with another in a string
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, u64, u64, bool);

namespace SiSDK3 {

// 0x7100574710
SiGfxShaderEffectVariation::SiGfxShaderEffectVariation(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_48(pAllocator), field_98(pAllocator), field_c8(0),
      field_cc(0), field_d0(pAllocator), field_120(pAllocator), field_150(0), field_154(0) {}

// 0x7100574850 (D2), 0x7100574c30 (D0)
SiGfxShaderEffectVariation::~SiGfxShaderEffectVariation() {
    Unk_574a20();
}

// 0x7100574a20
void SiGfxShaderEffectVariation::Unk_574a20() {
    field_48.Unk_4e3050();
    field_98.Unk_Clear();
    field_d0.Unk_4e3050();
    field_120.Unk_Clear();
}

SiString<char> Unk_575240(const char* a, const SiString<char>& b);

// 0x7100574c90: a value that doesn't fit its place gets a placeholder ("@"
// and a character), which is replaced with "0x" and the value at the end.
// The array of those values is emptied right after its construction and
// before its destruction: the stores of its members come after the
// allocator's call, and the destructor's (its vtable's too) are dead. The
// indices are computed in statements of their own, before the buffer is read.
bool SiGfxShaderEffectVariation::vf8(SiString<char>* out, void*, void*, s32 size, const u8* bytes) {
    SiArray<SiString<char> > values;
    values.Unk_FreeAll();
    char text[0x100];
    char name[0x100];
    *out = field_98;
    for (s64 i = 0; i < static_cast<s32>(field_48.m_itemCount); i++) {
        VariationItem* item = &field_48.m_pData[i];
        s32 value = Unk_4c9ba0(size, bytes, item->field_4, item->field_8);
        switch (item->field_20) {
        case 0: {
            s32 position = item->field_18;
            if (value != 0) {
                memcpy(&out->m_pBuffer[position], " true", item->field_1c);
            } else {
                memcpy(&out->m_pBuffer[position], "false", item->field_1c);
            }
            break;
        }
        case 1:
            value = (item->field_14 > 1 ? item->field_14 : 1) * value + item->field_c;
            if (value >= item->field_10) {
                value = item->field_10;
            }
            // fall through
        default: {
            Unk_4c5860(text, sizeof(text), "%x", value);
            s32 length = Unk_4c4290(text);
            s32 position = item->field_18;
            out->m_pBuffer[position] = '0';
            out->m_pBuffer[position + 1] = 'x';
            s32 j = 0;
            for (; j < item->field_1c - 2 - length; j++) {
                s32 index = position + 2 + j;
                out->m_pBuffer[index] = ' ';
            }
            if (item->field_1c - 2 >= length) {
                s32 index = position + 2 + j;
                memcpy(&out->m_pBuffer[index], text, length);
            } else {
                Unk_4c5860(name, sizeof(name), "@%c", values.m_itemCount + 0x20);
                SiString<char> s(nullptr, name);
                while (Unk_4c4290(Unk_StringCStr(&s)) < item->field_1c) {
                    Unk_StringAppend(&s, ' ');
                }
                s32 index = position + j;
                memcpy(&out->m_pBuffer[index], Unk_StringCStr(&s), item->field_1c);
                Unk_StringAssign(&s, text);
                s = Unk_575240("0x", s);
                values.Unk_Add(s);
            }
            break;
        }
        }
    }
    for (s64 i = 0; i < static_cast<s32>(values.m_itemCount); i++) {
        Unk_4c5860(name, sizeof(name), "@%c", static_cast<s32>(i) + 0x20);
        SiString<char> s(nullptr, name);
        Unk_4ca0b0(out, s.m_pBuffer, values.m_pData[i].m_pBuffer, 0, 0, true);
    }
    values.Unk_FreeAll();
    return true;
}

// 0x7100575510
bool SiGfxShaderEffectVariation::vf14(ISiIOStream* stream) {
    Unk_582f70(stream, 0x10, 0);
    stream->vf58(Unk_StringCStr(&field_18), true);
    Unk_582f70(stream, 0x10, 0);
    stream->vf50(field_48.m_itemCount, true);
    stream->vf50(field_c8, true);
    stream->vf50(field_cc, true);
    stream->vf50(field_d0.m_itemCount, true);
    stream->vf50(field_150, true);
    stream->vf50(field_154, true);
    if (field_48.m_itemCount != 0) {
        for (s64 i = 0; i < static_cast<s32>(field_48.m_itemCount); i++) {
            VariationItem* item = &field_48.m_pData[i];
            stream->vf50(item->field_0, true);
            stream->vf50(item->field_4, true);
            stream->vf50(item->field_8, true);
            stream->vf50(item->field_c, true);
            stream->vf50(item->field_10, true);
            stream->vf50(item->field_14, true);
            stream->vf50(item->field_18, true);
            stream->vf50(item->field_1c, true);
            stream->vf50(item->field_20, true);
        }
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&field_98), true);
    }
    if (field_d0.m_itemCount != 0) {
        for (s64 i = 0; i < static_cast<s32>(field_d0.m_itemCount); i++) {
            VariationItem* item = &field_d0.m_pData[i];
            stream->vf50(item->field_0, true);
            stream->vf50(item->field_4, true);
            stream->vf50(item->field_8, true);
            stream->vf50(item->field_c, true);
            stream->vf50(item->field_10, true);
            stream->vf50(item->field_14, true);
            stream->vf50(item->field_18, true);
            stream->vf50(item->field_1c, true);
            stream->vf50(1, true);
        }
        Unk_582f70(stream, 0x10, 0);
        stream->vf58(Unk_StringCStr(&field_120), true);
    }
    return true;
}

// 0x71005758a0
bool SiGfxShaderEffectVariation::vf15(ISiIOStream* stream) {
    Unk_582f10(stream, 0x10);
    stream->vf35(&field_18, true);
    Unk_582f10(stream, 0x10);
    s32 count48 = stream->vf27(true);
    field_c8 = stream->vf27(true);
    field_cc = stream->vf27(true);
    s32 countD0 = stream->vf27(true);
    field_150 = stream->vf27(true);
    field_154 = stream->vf27(true);
    if (count48 <= 0 && countD0 < 1) {
        return false;
    }
    if (count48 >= 1) {
        field_48.Unk_SetCount(count48);
        for (s64 i = 0; i < static_cast<s32>(field_48.m_itemCount); i++) {
            VariationItem* item = &field_48.m_pData[i];
            item->field_0 = stream->vf27(true);
            item->field_4 = stream->vf27(true);
            item->field_8 = stream->vf27(true);
            item->field_c = stream->vf27(true);
            item->field_10 = stream->vf27(true);
            item->field_14 = stream->vf27(true);
            item->field_18 = stream->vf27(true);
            item->field_1c = stream->vf27(true);
            item->field_20 = stream->vf27(true);
        }
        Unk_582f10(stream, 0x10);
        stream->vf35(&field_98, true);
    }
    if (countD0 >= 1) {
        field_d0.Unk_SetCount(countD0);
        for (s64 i = 0; i < static_cast<s32>(field_d0.m_itemCount); i++) {
            VariationItem* item = &field_d0.m_pData[i];
            item->field_0 = stream->vf27(true);
            item->field_4 = stream->vf27(true);
            item->field_8 = stream->vf27(true);
            item->field_c = stream->vf27(true);
            item->field_10 = stream->vf27(true);
            item->field_14 = stream->vf27(true);
            item->field_18 = stream->vf27(true);
            item->field_1c = stream->vf27(true);
            item->field_20 = stream->vf27(true);
        }
        Unk_582f10(stream, 0x10);
        stream->vf35(&field_120, true);
    }
    return true;
}

// 0x7100575390
// NON_MATCHING: scheduling: before the zeros' loop, this loads the buffer
// first (into x12) and computes the count and the position after "0x" after
// it; the original loads it after them (into x8). The loop itself is the
// original's with an `s32` counter and the copy's `&buffer[...]` (with an
// `s64` counter or `buffer + ...`, the index is added to the reloaded buffer
// each time). Tried: the position as s64, the stores as pointers, the count
// in a local (vectorised), a guarded do-while, the length as u32/s64, the
// order of the terms (~70 variants).
bool SiGfxShaderEffectVariation::vf12(SiString<char>* out, void*, void*, s32 size, const u8* bytes) {
    *out = field_120;
    for (s64 i = 0; i < static_cast<s32>(field_d0.m_itemCount); i++) {
        VariationItem* item = &field_d0.m_pData[i];
        s32 value = Unk_4c9ba0(size, bytes, item->field_4, item->field_8);
        value = (item->field_14 > 1 ? item->field_14 : 1) * value + item->field_c;
        if (value >= item->field_10) {
            value = item->field_10;
        }
        char text[0x100];
        Unk_4c5860(text, sizeof(text), "%x", value);
        s32 length = Unk_4c4290(text);
        s32 position = item->field_18;
        out->m_pBuffer[position] = '0';
        out->m_pBuffer[position + 1] = 'x';
        s32 j = 0;
        for (; j < item->field_1c - 2 - length; j++) {
            out->m_pBuffer[position + 2 + j] = '0';
        }
        memcpy(&out->m_pBuffer[position + 2 + j], text, length);
    }
    return true;
}

// 0x7100575240: characters and a string after them (placeholder name)
SiString<char> Unk_575240(const char* a, const SiString<char>& b) {
    SiString<char> result;
    result.Unk_SetExternal(a);
    Unk_StringAppendString(&result, &b);
    return result;
}

}  // namespace SiSDK3

// The items' array's reserve, which this translation unit instantiates.
// 0x7100575df0 = _ZN6SiSDK37SiArrayINS_26SiGfxShaderEffectVariation13VariationItemELi16EE10Unk_4bf190Emb
