// Scope: common
// SiSDK3::SiGfxFontDrawHelper: its destruction, its event handler's slots,
// and the reference counts its header defines.
#define UNK_SIGFX_FONTDRAWHELPER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FontDrawHelper.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Font_Impl.h>

#include <math.h>

// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004ee020: a projection for a target of a width and a height
// (placeholder name)
SiSDK3::SiGfxFontDrawHelper::Unk_Matrix Unk_4ee020(f32 width, f32 height, f32 a3, f32 a4);
// 0x71004c4d10, 0x71004c4d90: a string's characters, from Latin-1 and from
// UTF-8 (SiCore_String.cpp)
wchar_t* Unk_4c4d10(const char* s, wchar_t* dst, size_t size);
wchar_t* Unk_4c4d90(const char* s, wchar_t* dst, s64 size);

namespace SiSDK3 {

// 0x7100543200, 0x7100543220 (deleting): defined here, so it is a function
// of its own (with the base's inline)
SiGfxFontDrawHelper::GfxEventHandler::~GfxEventHandler() {}

// 0x7100543260
void SiGfxFontDrawHelper::GfxEventHandler::vf5() {}

// 0x7100543270
void SiGfxFontDrawHelper::GfxEventHandler::vf6() {}

// 0x7100543280
SiGfxFontDrawHelper::SiGfxFontDrawHelper(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(nullptr), field_20(nullptr), field_28(0), field_2c(0), field_30(pAllocator), field_80(0),
      field_88(pAllocator), field_120(pAllocator), field_170(pAllocator), field_1c0(nullptr), field_228(nullptr),
      field_2b8(pAllocator) {
    field_e0.Unk_SetIdentity();
    field_208[0].field_0 = 0.0f;
    field_208[0].field_4 = 0.0f;
    field_208[1].field_0 = 0.0f;
    field_208[1].field_4 = 1.0f;
    field_208[2].field_0 = 1.0f;
    field_208[2].field_4 = 0.0f;
    field_208[3].field_0 = 1.0f;
    field_208[3].field_4 = 1.0f;
    for (int i = 0; i < 16; i++) {
        field_230[i] = nullptr;
    }
    field_2b0 = 0;
    field_2b8.field_18 = this;
    field_1c8[0].field_0 = 0.0f;
    field_1c8[0].field_4 = 0.0f;
    field_1c8[0].field_8 = 0.0f;
    field_1c8[0].field_c = 1.0f;
    field_1c8[1].field_0 = 0.0f;
    field_1c8[1].field_4 = 1.0f;
    field_1c8[1].field_8 = 0.0f;
    field_1c8[1].field_c = 1.0f;
    field_1c8[2].field_0 = 1.0f;
    field_1c8[2].field_4 = 0.0f;
    field_1c8[2].field_8 = 0.0f;
    field_1c8[2].field_c = 1.0f;
    field_1c8[3].field_0 = 1.0f;
    field_1c8[3].field_4 = 1.0f;
    field_1c8[3].field_8 = 0.0f;
    field_1c8[3].field_c = 1.0f;
}

// 0x71005434b0 (D2), 0x7100543970 (D0)
SiGfxFontDrawHelper::~SiGfxFontDrawHelper() {
    Unk_5436d0();
}

// 0x71005436d0
void SiGfxFontDrawHelper::Unk_5436d0() {
    reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf34(&field_2b8);
    Unk_544090();
}

// 0x7100544090
void SiGfxFontDrawHelper::Unk_544090() {
    if (field_228 != nullptr) {
        field_228->vf3();
        field_228 = nullptr;
    }
    if (field_1c0 != nullptr) {
        field_1c0->vf3();
        field_1c0 = nullptr;
    }
    if (field_20 != nullptr) {
        field_20->vf3();
        field_20 = nullptr;
    }
    for (int i = 0; i < 16; i++) {
        if (field_230[i] != nullptr) {
            field_230[i]->vf3();
            field_230[i] = nullptr;
        }
    }
}

// 0x7100544010
bool SiGfxFontDrawHelper::Unk_544010(void* font) {
    Unk_544090_Object* pFont = static_cast<Unk_544090_Object*>(font);
    if (pFont != nullptr) {
        pFont->vf2();
        if (field_20 != nullptr) {
            field_20->vf3();
        }
        field_20 = pFont;
    } else if (field_20 != nullptr) {
        field_20->vf3();
        field_20 = nullptr;
    }
    return true;
}

// NON_MATCHING: the original's loop keeps the index in a 32-bit register
// (`ldr w21, [x25, w24, sxtw #2]`) and ends the visible glyphs' branch with a
// select of 3 or 0 that is then compared with 3: a cleanup destination, so
// the loop's body has a scope with a destructor (0x7100544610 has the same,
// with a `continue` as 2). Which object it is isn't known; here the loop
// walks a pointer and the branches come out in another order.
// 0x7100544290
bool SiGfxFontDrawHelper::Unk_544290(const char* text, Unk_Vec2* pSize, u32 flags, f32 scale) {
    *pSize = Unk_Vec2();
    if (text == nullptr) {
        return true;
    }
    if (field_20 == nullptr || field_18 == nullptr) {
        return false;
    }
    wchar_t buffer[0x400];
    if (flags & 0x2000) {
        Unk_4c4d90(text, buffer, 0x400);
    } else {
        Unk_4c4d10(text, buffer, 0x400);
    }
    const Unk_544290_Metrics* metrics = static_cast<Unk_544290_Font*>(field_20)->vf20();
    f32 lineHeight = ceilf(static_cast<f32>(metrics->field_8 - metrics->field_c) * scale);
    bool pending = false;
    f32 width = 0.0f;
    for (s32 i = 0; buffer[i] != 0; i++) {
        u32 c = buffer[i];
        if (c == '\n') {
            if (!(flags & 0x20)) {
                if (width > 0.0f) {
                    pSize->field_0 = pSize->field_0 > width ? pSize->field_0 : width;
                    pSize->field_4 = lineHeight + pSize->field_4;
                    pending = false;
                }
                width = 0.0f;
            }
            continue;
        }
        Unk_544290_Font* font = static_cast<Unk_544290_Font*>(field_20);
        if (font == nullptr || font->vf5()->vf14() != 8) {
            return false;
        }
        const Unk_544290_Glyph* glyph =
            static_cast<const Unk_544290_Glyph*>(reinterpret_cast<SiGfxNXFont*>(font)->Unk_4ffbe0(c));
        if (glyph == nullptr) {
            return false;
        }
        if (glyph->field_68 > 0 || glyph->field_6c > 0) {
            pending = true;
            width += static_cast<f32>(glyph->field_58);
            if (buffer[i + 1] == 0) {
                break;
            }
        } else {
            if (buffer[i + 1] == 0) {
                break;
            }
            width += static_cast<f32>(glyph->field_58);
        }
    }
    if (pending) {
        pSize->field_0 = pSize->field_0 > width ? pSize->field_0 : width;
        pSize->field_4 = lineHeight + pSize->field_4;
    }
    return true;
}

// NON_MATCHING: the original copies the projection with four 16-byte loads
// and stores (`ldp q0, q1`) and puts the return for a second begin before
// the setup; here the copy is eight 8-byte pairs and the setup comes first.
// The matrix's real type decides both (with four `vector_size(16)` rows,
// returned in registers, the branches come out right). Tried: Unk_Matrix.h's
// Unk_Matrix44 as the return, with field_e0 as four float32x4_t rows (the
// copy is then 16-byte stores, not pairs, and the constructor 0x7100543280
// stops matching) or assigned with a 64-byte memcpy (8-byte pairs).
// 0x7100544540
bool SiGfxFontDrawHelper::Unk_544540() {
    if (field_20 == nullptr) {
        return false;
    }
    if (field_28++ != 0) {
        return true;
    }
    field_2c = 0;
    field_80 = 0;
    s32 width = static_cast<s32>(field_18->vf33()->field_34);
    s32 height = static_cast<s32>(field_18->vf33()->field_38);
    field_e0 = Unk_4ee020(static_cast<f32>(width), static_cast<f32>(height), 1.0f, 2.0f);
    return true;
}

}  // namespace SiSDK3
