// Scope: common
// SiSDK3::SiGfxFontDrawHelper: its destruction, its event handler's slots,
// and the reference counts its header defines.
#define UNK_SIGFX_FONTDRAWHELPER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FontDrawHelper.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Font_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Sampler_Impl.h>

#include <math.h>
#include <string.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiMath/Unk_Matrix.h>

// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004ffbd0 (leafgen's name and type): SiGfxNXFont's face
struct Unk_4ffbd0;
const u8* Unk_4ffbd0_get(const Unk_4ffbd0* self);
// 0x71004ee020: a projection for a target of a width and a height
// (placeholder name)
Unk_Matrix44 Unk_4ee020(f32 width, f32 height, f32 a3, f32 a4);
// 0x71004c4d10, 0x71004c4d90: a string's characters, from Latin-1 and from
// UTF-8 (SiCore_String.cpp)
wchar_t* Unk_4c4d10(const char* s, wchar_t* dst, size_t size);
wchar_t* Unk_4c4d90(const char* s, wchar_t* dst, s64 size);

namespace SiSDK3 {

// The matrix set from rows (inline: placeholder name).
static inline void Unk_SetRows(SiGfxFontDrawHelper::Unk_Matrix* dst, float32x4_t a, float32x4_t b, float32x4_t c, float32x4_t d) {
    float32x4_t* rows = reinterpret_cast<float32x4_t*>(dst->field_0);
    rows[0] = a;
    rows[1] = b;
    rows[2] = c;
    rows[3] = d;
}

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

// 0x71005439a0
bool SiGfxFontDrawHelper::Unk_5439a0(Unk_544540_Context* pContext) {
    field_18 = pContext;
    Unk_5439a0_Device* pDevice = pContext->vf5();
    if (field_30.Unk_SetCount(0x1000)) {
        for (s64 i = 0; i < static_cast<s32>(field_30.m_itemCount); i++) {
            memset(&field_30.m_pData[i], 0, sizeof(GlyphRenderData));
        }
    }
    if (field_88.Unk_SetCount(0x400)) {
        for (s64 i = 0; i < static_cast<s32>(field_88.m_itemCount); i++) {
            memset(&field_88.m_pData[i], 0, sizeof(TextLineData));
        }
    }
    Unk_544090_Object* pFont = pDevice->vf56(1);
    if (pFont != nullptr) {
        pFont->vf2();
        if (field_20 != nullptr) {
            field_20->vf3();
        }
        field_20 = pFont;
    }
    field_120.Unk_SetCount(0x4000);
    field_170.Unk_SetCount(0x6000);
    memset(field_120.m_pData, 0, sizeof(FontVertex));
    for (s32 i = 0; i < 0x1000; i++) {
        field_170.m_pData[i * 6 + 0] = i * 4 + 0;
        field_170.m_pData[i * 6 + 1] = i * 4 + 1;
        field_170.m_pData[i * 6 + 2] = i * 4 + 2;
        field_170.m_pData[i * 6 + 3] = i * 4 + 2;
        field_170.m_pData[i * 6 + 4] = i * 4 + 1;
        field_170.m_pData[i * 6 + 5] = i * 4 + 3;
    }
    Unk_5439a0_VertexFormat* pFormat = pDevice->vf38(nullptr, 0, nullptr);
    pFormat->vf18();
    pFormat->vf19(0, 0, 2, 0, -1, 0, 0);
    pFormat->vf19(4, 0, 2, 0, -1, 0, 0);
    pFormat->vf19(5, 0, 16, 0, -1, 0, 0);
    pFormat->vf20();
    field_1c0 = pFormat;
    SiGfxNXSampler::Unk_Desc desc;
    desc.field_0 = 3;
    desc.field_4 = 1;
    desc.field_8 = 1;
    desc.field_c = 1;
    desc.field_10 = 0.0f;
    desc.field_14 = 0.0f;
    desc.field_18 = 100.0f;
    desc.field_1c = 1;
    desc.field_20 = 8;
    desc.field_24.field_0[0] = 0;
    desc.field_24.field_0[1] = 0;
    desc.field_24.field_0[2] = 0;
    desc.field_24.field_0[3] = 0;
    desc.field_34 = 0;
    desc.field_38 = 0;
    desc.field_3c = 0;
    field_228 = pDevice->vf52(&desc, 0, 0, nullptr);
    reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf33(&field_2b8);
    return true;
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

// The select of 3 or 0 that ends the visible glyphs' branch (compared with 3
// after it) is a cleanup destination: the font's pointer is a local of the
// loop's body, whose lifetime marker is a cleanup that the `break` (3, a
// `while` loop's end) and the fall-through (0) leave through; the glyph's is
// declared before the loop, or the `continue` (2) joins them. The loop is
// Unk_544610's (`c` read again at each step, a 32-bit index).
// NON_MATCHING: the glyph's advance is converted in each branch here (16
// bytes more); the original converts it once, before the test of the size.
// Tried: the advance in a local (before the test, in the loop's scope or
// before it: the empty glyphs' branch becomes selects), the sizes in locals,
// the test as `&`, the visible glyphs' branch first.
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
    u32 c = buffer[0];
    s32 i = 0;
    const Unk_544290_Glyph* glyph;
    while (true) {
        if (c == '\n') {
            if (!(flags & 0x20)) {
                if (width > 0.0f) {
                    pSize->field_0 = pSize->field_0 > width ? pSize->field_0 : width;
                    pSize->field_4 = lineHeight + pSize->field_4;
                    pending = false;
                }
                width = 0.0f;
            }
            c = buffer[++i];
            continue;
        }
        if (c == 0) {
            break;
        }
        Unk_544290_Font* font = static_cast<Unk_544290_Font*>(field_20);
        if (font == nullptr || font->vf5()->vf14() != 8) {
            return false;
        }
        glyph = static_cast<const Unk_544290_Glyph*>(reinterpret_cast<SiGfxNXFont*>(font)->Unk_4ffbe0(c));
        if (glyph == nullptr) {
            return false;
        }
        if (glyph->field_68 <= 0 && glyph->field_6c <= 0) {
            if (buffer[i + 1] == 0) {
                break;
            }
            width += static_cast<f32>(glyph->field_58);
            c = buffer[++i];
            continue;
        } else {
            pending = true;
            width += static_cast<f32>(glyph->field_58);
            i++;
            if (buffer[i] == 0) {
                break;
            }
            c = buffer[i];
        }
    }
    if (pending) {
        pSize->field_0 = pSize->field_0 > width ? pSize->field_0 : width;
        pSize->field_4 = lineHeight + pSize->field_4;
    }
    return true;
}

// (inline: placeholder name)
static inline void Unk_SetLine(SiGfxFontDrawHelper::TextLineData* line, const f32& width, f32 height, f32 x, f32 y, f32* total) {
    if (line != nullptr) {
        line->field_0 = width;
        line->field_4 = height;
        line->field_8 = x;
        line->field_c = y;
        *total += height;
    }
}

// The width of a line that is finished at the end goes through a reference
// (Unk_SetLine): the helper's copy of it is canonicalised to an integer load
// before it is inlined, so SROA gives the width an integer type and the loop
// keeps its bits in a register of their own (`fmov w28, s15`). A `continue`
// out of the branch of empty glyphs keeps the original's select of the
// cleanup destination (3 or 0) and its switch.
// NON_MATCHING: the exits are grouped differently (the original sends the
// break of a wrap to the block that tests whether a line is pending, here it
// joins the exits of the glyph branches, and the switch's break skips that
// test), the END's width is in w28 instead of a copy in w9, and the first
// floats are scheduled in another order.
// 0x7100544610
bool SiGfxFontDrawHelper::Unk_544610(const char* text, const Unk_Vec4* pRect, u32 flags, const Unk_TextColor* pColor,
                                     f32 scale) {
    if (text == nullptr) {
        return true;
    }
    if (field_28 <= 0) {
        return false;
    }
    wchar_t buffer[0x400];
    if (flags & 0x2000) {
        Unk_4c4d90(text, buffer, 0x400);
    } else {
        Unk_4c4d10(text, buffer, 0x400);
    }
    const Unk_544290_Metrics* metrics = static_cast<Unk_544290_Font*>(field_20)->vf20();
    s32 first = field_80;
    f32 ascender = static_cast<f32>(metrics->field_8);
    f32 descender = static_cast<f32>(metrics->field_c);
    f32 left = pRect->field_0;
    f32 right = pRect->field_4;
    f32 top = pRect->field_8;
    f32 bottom = pRect->field_c;
    u32 c = buffer[0];
    f32 width = right - left;
    f32 baseline = top + ascender;
    f32 height = bottom - top;
    f32 lineHeight = ceilf((ascender - descender) * scale);
    TextLineData* line = Unk_NewLine();
    if (line == nullptr) {
        return false;
    }
    f32 pen = 0.0f;
    f32 offset = 0.0f;
    f32 total = 0.0f;
    bool pending = false;
    s32 i = 0;
    while (true) {
        if (c == '\n') {
            if (!(flags & 0x20)) {
                if (pen > 0.0f) {
                    line->field_0 = pen;
                    line->field_4 = lineHeight;
                    line->field_8 = left;
                    line->field_c = baseline + offset;
                    line = Unk_NewLine();
                    pending = false;
                    if (line == nullptr) {
                        return false;
                    }
                }
                offset += lineHeight;
                total += lineHeight;
                pen = 0.0f;
                if (offset + lineHeight >= height) {
                    break;
                }
            }
            c = buffer[++i];
            continue;
        }
        if (c == 0) {
            break;
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
        if (!(flags & 0x20) && pen + static_cast<f32>(glyph->field_58) > width) {
            if (pen > 0.0f) {
                line->field_0 = pen;
                line->field_4 = lineHeight;
                line->field_8 = left;
                line->field_c = baseline + offset;
                line = Unk_NewLine();
                pending = false;
                if (line == nullptr) {
                    return false;
                }
            }
            offset += lineHeight;
            total += lineHeight;
            pen = 0.0f;
            if (offset + lineHeight >= height) {
                break;
            }
        }
        if (glyph->field_68 <= 0 && glyph->field_6c <= 0) {
            if (buffer[i + 1] == 0) {
                break;
            }
            pen += static_cast<f32>(glyph->field_58);
            c = buffer[++i];
            continue;
        } else {
            if (!Unk_AddGlyph(line, glyph, pColor, pen)) {
                break;
            }
            pending = true;
            pen += static_cast<f32>(glyph->field_58);
            i++;
            if (buffer[i] == 0) {
                break;
            }
            c = buffer[i];
        }
    }
    if (pending) {
        Unk_SetLine(line, pen, lineHeight, left, baseline + offset, &total);
    }
    f32 shift = (flags & 8) ? height - total : 0.0f;
    if (flags & 4) {
        shift = height * 0.5f - total * 0.5f;
    }
    for (s32 j = first; j < field_80; j++) {
        TextLineData* p = &field_88.m_pData[j];
        if (flags & 1) {
            p->field_8 = left + (width - p->field_0) * 0.5f;
        } else if (flags & 2) {
            p->field_8 = left + (width - p->field_0);
        } else {
            p->field_8 = left;
        }
        p->field_c = shift + p->field_c;
    }
    return true;
}

// The projection is a matrix of four NEON rows (Unk_Matrix44, returned in
// memory); its rows are read first and then stored (with -mno-implicit-float
// only explicit vectors give the 16-byte pairs `ldp q0, q1` / `stp q0, q1`).
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
    Unk_Matrix44 m = Unk_4ee020(static_cast<f32>(width), static_cast<f32>(height), 1.0f, 2.0f);
    Unk_SetRows(&field_e0, m.r[0], m.r[1], m.r[2], m.r[3]);
    return true;
}

// The width of the lines finished at the end through a reference, as
// Unk_544610 has it (inline: placeholder name).
static inline void Unk_SetLines(SiGfxFontDrawHelper::TextLineData* line, const f32& width, f32 height, f32 x, f32 y) {
    line->field_0 = width;
    line->field_4 = height;
    line->field_8 = x;
    line->field_c = y;
}

// NON_MATCHING: as Unk_544610's (it has the same loop, the lines and glyphs
// added for each copy), and the addresses of the glyph and colour arrays are
// hoisted out of the loop and spilled here (32 bytes more of frame).
// 0x7100544b00: Unk_544610 with copies of the text moved by a pixel each
// way the outline's flags ask for (0x10000, 0x20000, 0x8000, 0x4000), in the
// outline's colour, drawn first
bool SiGfxFontDrawHelper::Unk_544b00(const char* text, const Unk_Vec4* pRect, u32 flags, const Unk_TextColor* pColor,
                                     const Unk_TextColor* pOutlineColor, f32 scale, u32 outline) {
    if (text == nullptr) {
        return false;
    }
    if (field_28 <= 0) {
        return false;
    }
    Unk_Vec4 rects[5];
    Unk_TextColor colors[5] = {};
    TextLineData* lines[5];
    s32 first = field_80;
    s32 n = 0;
    if (outline & 0x10000) {
        rects[n] = Unk_Vec4(pRect->field_0 + 1.0f, pRect->field_4 + 1.0f, pRect->field_8 + 1.0f, pRect->field_c + 1.0f);
        colors[n] = *pOutlineColor;
        lines[n] = Unk_NewLine();
        n++;
    }
    if (outline & 0x20000) {
        rects[n] = Unk_Vec4(pRect->field_0 + 1.0f, pRect->field_4 + 1.0f, pRect->field_8 + -1.0f, pRect->field_c + -1.0f);
        colors[n] = *pOutlineColor;
        lines[n] = Unk_NewLine();
        n++;
    }
    if (outline & 0x8000) {
        rects[n] = Unk_Vec4(pRect->field_0 + -1.0f, pRect->field_4 + -1.0f, pRect->field_8 + -1.0f, pRect->field_c + -1.0f);
        colors[n] = *pOutlineColor;
        lines[n] = Unk_NewLine();
        n++;
    }
    if (outline & 0x4000) {
        rects[n] = Unk_Vec4(pRect->field_0 + -1.0f, pRect->field_4 + -1.0f, pRect->field_8 + 1.0f, pRect->field_c + 1.0f);
        colors[n] = *pOutlineColor;
        lines[n] = Unk_NewLine();
        n++;
    }
    rects[n] = *pRect;
    colors[n] = *pColor;
    lines[n] = Unk_NewLine();
    for (s32 k = 0; k <= n; k++) {
        if (lines[k] == nullptr) {
            return false;
        }
    }
    wchar_t buffer[0x400];
    if (flags & 0x2000) {
        Unk_4c4d90(text, buffer, 0x400);
    } else {
        Unk_4c4d10(text, buffer, 0x400);
    }
    const Unk_544290_Metrics* metrics = static_cast<Unk_544290_Font*>(field_20)->vf20();
    s32 count = n + 1;
    f32 ascender = static_cast<f32>(metrics->field_8);
    f32 descender = static_cast<f32>(metrics->field_c);
    f32 left = pRect->field_0;
    f32 right = pRect->field_4;
    f32 top = pRect->field_8;
    f32 bottom = pRect->field_c;
    u32 c = buffer[0];
    Unk_Vec2 origins[5];
    for (s32 k = 0; k <= n; k++) {
        origins[k].field_0 = rects[k].field_0;
        origins[k].field_4 = rects[k].field_8 + ascender;
    }
    f32 width = right - left;
    f32 height = bottom - top;
    f32 lineHeight = ceilf((ascender - descender) * scale);
    f32 pen = 0.0f;
    f32 offset = 0.0f;
    f32 total = 0.0f;
    bool pending = false;
    s32 i = 0;
    while (true) {
        if (c == '\n') {
            if (!(flags & 0x20)) {
                if (pen > 0.0f) {
                    for (s32 k = 0; k <= n; k++) {
                        lines[k]->field_0 = pen;
                        lines[k]->field_4 = lineHeight;
                        lines[k]->field_8 = origins[k].field_0;
                        lines[k]->field_c = origins[k].field_4 + offset;
                        lines[k] = Unk_NewLine();
                        if (lines[k] == nullptr) {
                            return false;
                        }
                    }
                    pending = false;
                }
                offset += lineHeight;
                total += lineHeight;
                pen = 0.0f;
                if (offset + lineHeight >= height) {
                    break;
                }
            }
            c = buffer[++i];
            continue;
        }
        if (c == 0) {
            break;
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
        if (!(flags & 0x20) && pen + static_cast<f32>(glyph->field_58) > width) {
            if (pen > 0.0f) {
                for (s32 k = 0; k <= n; k++) {
                    lines[k]->field_0 = pen;
                    lines[k]->field_4 = lineHeight;
                    lines[k]->field_8 = origins[k].field_0;
                    lines[k]->field_c = origins[k].field_4 + offset;
                    lines[k] = Unk_NewLine();
                    if (lines[k] == nullptr) {
                        return false;
                    }
                }
                pending = false;
            }
            offset += lineHeight;
            total += lineHeight;
            pen = 0.0f;
            if (offset + lineHeight >= height) {
                break;
            }
        }
        if (glyph->field_68 <= 0 && glyph->field_6c <= 0) {
            if (buffer[i + 1] == 0) {
                break;
            }
            pen += static_cast<f32>(glyph->field_58);
            c = buffer[++i];
            continue;
        } else {
            for (s32 k = 0; k <= n; k++) {
                if (!Unk_AddGlyph(lines[k], glyph, &colors[k], pen)) {
                    break;
                }
            }
            pending = true;
            pen += static_cast<f32>(glyph->field_58);
            i++;
            if (buffer[i] == 0) {
                break;
            }
            c = buffer[i];
        }
    }
    if (pending) {
        for (s32 k = 0; k <= n; k++) {
            Unk_SetLines(lines[k], pen, lineHeight, origins[k].field_0, origins[k].field_4 + offset);
        }
        total += lineHeight;
    }
    f32 shift = (flags & 8) ? height - total : 0.0f;
    if (flags & 4) {
        shift = height * 0.5f - total * 0.5f;
    }
    s32 m = 0;
    for (s32 j = first; j < field_80; j++) {
        TextLineData* p = &field_88.m_pData[j];
        if (flags & 1) {
            p->field_8 = origins[m].field_0 + (width - p->field_0) * 0.5f;
        } else if (flags & 2) {
            p->field_8 = origins[m].field_0 + (width - p->field_0);
        } else {
            p->field_8 = origins[m].field_0;
        }
        p->field_c = shift + p->field_c;
        m = (m + 1) % count;
    }
    return true;
}

// What the draw context's slots 18 and 14 take (placeholder names).
struct Unk_545910_State {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
};
struct Unk_545910_Viewport {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
};

// A corner transformed by the matrix of four NEON rows (inline: placeholder
// name).
static inline float32x4_t Unk_Transform(const SiGfxFontDrawHelper::Unk_Matrix* m, f32 x, f32 y, f32 z, f32 w) {
    const float32x4_t* rows = reinterpret_cast<const float32x4_t*>(m->field_0);
    return rows[0] * x + rows[1] * y + rows[2] * z + rows[3] * w;
}

// NON_MATCHING: the loop over a glyph's four corners schedules its loads and
// products in another order and addresses the texture coordinates from
// another base (the original's is &field_208[0].field_4, with the glyph's
// width folded into the post-increment of its first load); everything around
// it matches.
// 0x7100545910
bool SiGfxFontDrawHelper::Unk_545910() {
    if (field_28 <= 0) {
        return false;
    }
    field_28--;
    Unk_544290_Font* font = static_cast<Unk_544290_Font*>(field_20);
    font->vf5()->vf14();
    SiGfxFreeTypeFaceCache* cache =
        reinterpret_cast<const SiGfxFreeTypeFace*>(Unk_4ffbd0_get(reinterpret_cast<const Unk_4ffbd0*>(font)))
            ->field_1c0;
    Unk_544540_Context* pContext = field_18;
    cache->vf7(pContext);
    if (field_28 != 0) {
        return true;
    }
    if (field_20 == nullptr) {
        return false;
    }
    if (field_2c <= 0) {
        return true;
    }
    pContext->vf83(true);
    Unk_545910_State state;
    state.field_0 = 0;
    state.field_4 = 0x3f;
    state.field_10 = 0;
    state.field_14 = 0x3f;
    state.field_8 = 1;
    state.field_c = 2;
    state.field_18 = 1;
    state.field_1c = 2;
    pContext->vf18(1, &state);
    void* program = field_18->vf5()->vf46(0x44);
    if (program == nullptr) {
        return false;
    }
    ISiGfxTexture* texture = cache->field_30;
    pContext->vf92(1, 2, 0, texture);
    pContext->vf94(1, 2, 0, field_228);
    texture->vf32(field_228);
    s32 width = static_cast<s32>(field_18->vf33()->field_34);
    s32 height = static_cast<s32>(field_18->vf33()->field_38);
    Unk_545910_Viewport viewport;
    viewport.field_0 = 0.0f;
    viewport.field_4 = 0.0f;
    viewport.field_8 = static_cast<f32>(width);
    viewport.field_c = static_cast<f32>(height);
    viewport.field_10 = -1.0f;
    viewport.field_14 = 1.0f;
    pContext->vf14(1, &viewport);
    Unk_PrimitiveStates* states = pContext->vf85();
    states->field_0 = program;
    states->field_8 = reinterpret_cast<Unk_PrimitiveFormat*>(field_1c0);
    states->field_16c.field_0 = 4;
    states->field_10 = 1;
    states->field_14 = 3;
    states->field_34 = false;
    states->field_35 = false;
    states->field_60[0].field_0 = true;
    states->field_60[0].field_c = 1;
    states->field_60[0].field_10 = 5;
    states->field_60[0].field_4 = 5;
    states->field_60[0].field_8 = 6;
    states->field_60[0].field_14 = 6;
    states->field_60[0].field_18 = 1;
    states->field_188 |= 0x5f;
    FontVertex* vertices = field_120.m_pData;
    s32 count = 0;
    s32 i = 0;
    while (i < field_2c) {
        const GlyphRenderData* data = &field_30.m_pData[i];
        const TextLineData* line = data->field_0;
        FontVertex* vertex = &vertices[count * 4];
        for (s32 k = 0; k < 4; k++) {
            f32 x = (data->field_14 + line->field_8) + field_1c8[k].field_0 * data->field_1c;
            f32 y = (data->field_18 + line->field_c) + field_1c8[k].field_4 * data->field_20;
            float32x4_t position = Unk_Transform(&field_e0, x, y, field_1c8[k].field_8, field_1c8[k].field_c);
            f32 u = field_208[k].field_0 * data->field_24.field_8 + data->field_24.field_0;
            f32 v = field_208[k].field_4 * data->field_24.field_c + data->field_24.field_4;
            vertex[k].field_0 = position[0];
            vertex[k].field_4 = position[1];
            vertex[k].field_8 = position[2];
            vertex[k].field_c = position[3];
            vertex[k].field_20 = u;
            vertex[k].field_24 = v;
            vertex[k].field_10 = static_cast<f32>(data->field_10.field_0) / 255.0f;
            vertex[k].field_14 = static_cast<f32>(data->field_10.field_1) / 255.0f;
            vertex[k].field_18 = static_cast<f32>(data->field_10.field_2) / 255.0f;
            vertex[k].field_1c = static_cast<f32>(data->field_10.field_3) / 255.0f;
        }
        i++;
        count++;
        if (count * 4 >= static_cast<s32>(field_120.m_itemCount)) {
            memcpy(pContext->vf74(0, count * 4, sizeof(FontVertex)), field_120.m_pData, count * 4 * sizeof(FontVertex));
            pContext->vf75();
            memcpy(pContext->vf76(0x39, count * 6), field_170.m_pData, count * sizeof(unsigned short) * 6);
            pContext->vf77();
            count = 0;
        }
    }
    if (count >= 1) {
        memcpy(pContext->vf74(0, count * 4, sizeof(FontVertex)), field_120.m_pData, count * 4 * sizeof(FontVertex));
        pContext->vf75();
        memcpy(pContext->vf76(0x39, count * 6), field_170.m_pData, count * sizeof(unsigned short) * 6);
        pContext->vf77();
        pContext->vf25(count * 6, 0, 0, 1, 0);
    }
    field_2c = 0;
    pContext->vf83(false);
    return true;
}

}  // namespace SiSDK3
