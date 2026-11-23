// SiSDK3::SiGfxFontDrawHelper (RTTI names the class; it derives from
// ISiInterface): what draws the draw context's text (the context has one at
// 0x3780). As far as the executable's functions show it, with placeholder
// members; the virtual functions are vf<slot>. The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// class's own translation unit (UNK_SIGFX_FONTDRAWHELPER_IMPL).
#pragma once

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/SiGfx_Kernel.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_FaceCache.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_PrimitiveDrawHelper.h>

namespace SiSDK3 {

// What the helper keeps references of (placeholder name).
class Unk_544090_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

// The helper's font as Unk_544290 calls it (placeholder names: SiGfxNXFont's
// slots). Slot 5's slot 14 is the graphics interface (8: NX), slot 20 the
// face's metrics; Unk_4ffbe0 is SiGfxNXFont's glyph of a character.
class Unk_544290_Interface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual s32 vf14();
};
struct Unk_544290_Metrics {
    u8 field_0[8];
    s32 field_8;  // the ascender
    s32 field_c;  // and descender
};
// A glyph's place in the texture of glyphs (placeholder name): its
// coordinates and their size.
struct Unk_GlyphUV {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};
// A colour, a byte each (placeholder name).
struct Unk_TextColor {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
};
struct Unk_544290_Glyph {
    u8 field_0[0x58];
    s32 field_58;  // its advance
    u8 field_5c[4];
    s32 field_60;  // where its bitmap begins
    s32 field_64;
    s32 field_68;  // its bitmap's size
    s32 field_6c;
    u8 field_70[0x10];
    Unk_GlyphUV field_80;
    s32 field_90;  // its size on the screen
    s32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_544290_Glyph, field_80, 0x80);
PKMN_SIZE_ASSERT(Unk_544290_Glyph, 0x98);
class Unk_544290_Font : public Unk_544090_Object {
public:
    virtual void vf4();
    virtual Unk_544290_Interface* vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual const Unk_544290_Metrics* vf20();
};

// What slot 33 of the helper's draw context gives (placeholder name): the
// target's size.
struct Unk_544540_Target {
    u8 field_0[0x34];
    f32 field_34;  // its width
    f32 field_38;  // and height
};

// The vertex format the helper makes (placeholder name: SiGfxNXVertexFormat's
// slots 18 to 20 begin, add an element and end its description).
class Unk_5439a0_VertexFormat : public Unk_544090_Object {
public:
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u32 vf18();
    virtual bool vf19(u32 a1, s32 a2, u32 a3, s32 a4, s32 a5, u32 a6, u32 a7);
    virtual bool vf20();
};

// The device as the helper calls it (placeholder name: SiGfxNXDevice's
// slots 38, 52 and 56 make a vertex format and a sampler and give a font).
class Unk_5439a0_Device {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual Unk_5439a0_VertexFormat* vf38(const void* desc, u32 a2, ISiAllocator* pAllocator);
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void* vf46(u32 index);  // a program of SiGfx's own
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual Unk_544090_Object* vf52(const void* desc, u64 a2, u32 a3, ISiAllocator* pAllocator);
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual Unk_544090_Object* vf56(s32 index);
};

// The draw context as the helper calls it (placeholder name): the draw
// context's slots (14 the viewports, 18 the samplers' states, 25 draws
// indexed, 74 to 77 map and unmap the vertices and indices, 83 saves or
// restores the states, 85 gives them, 92 and 94 bind a texture and a
// sampler).
class Unk_544540_Context {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual Unk_5439a0_Device* vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(s32 count, const void* viewports);
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18(s32 count, const void* states);
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual bool vf25(s32 count, s32 first, s32 baseVertex, s32 instances, s32 baseInstance);
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual Unk_544540_Target* vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void* vf74(s32 slot, s32 count, s32 stride);
    virtual void vf75();
    virtual void* vf76(u32 format, s32 count);
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83(bool more);
    virtual void vf84();
    virtual Unk_PrimitiveStates* vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92(u32 a1, u32 stages, s32 slot, ISiGfxTexture* pTexture);
    virtual void vf93();
    virtual void vf94(u32 a1, u32 stages, s32 slot, Unk_544090_Object* pSampler);
};

class SiGfxFontDrawHelper : public ISiInterface {
public:
    // what the helper gives the kernel: it does nothing with the events
    class GfxEventHandler : public ISiGfxKernel::EventHandler {
    public:
        explicit GfxEventHandler(ISiAllocator* pAllocator) : EventHandler(pAllocator) {}
        ~GfxEventHandler() override;  // 0x7100543200, 0x7100543220
        void vf5() override;            // 0x7100543260
        void vf6() override;            // 0x7100543270

        SiGfxFontDrawHelper* field_18;  // its helper
    };

    // The arrays' elements (RTTI names them), as far as their sizes.
    // (Their constructors are what the arrays' reserves construct the new
    // elements with.)
    struct TextLineData {
        TextLineData() : field_0(0.0f), field_4(0.0f), field_8(0.0f), field_c(0.0f) {}

        f32 field_0;  // its width
        f32 field_4;  // and height
        f32 field_8;  // where it is
        f32 field_c;
        u32 field_10;
    };
    struct GlyphRenderData {
        GlyphRenderData()
            : field_10(), field_14(0.0f), field_18(0.0f), field_1c(0.0f), field_20(0.0f), field_24() {}

        TextLineData* field_0;            // its line
        const Unk_544290_Glyph* field_8;  // the glyph
        Unk_TextColor field_10;
        f32 field_14;  // where it is on its line
        f32 field_18;
        f32 field_1c;  // its size
        f32 field_20;
        Unk_GlyphUV field_24;  // its place in the texture of glyphs
    };
    struct FontVertex {
        FontVertex()
            : field_0(0.0f), field_4(0.0f), field_8(0.0f), field_c(0.0f), field_10(0.0f), field_14(0.0f),
              field_18(0.0f), field_1c(0.0f), field_20(0.0f), field_24(0.0f) {}

        f32 field_0;  // where it is
        f32 field_4;
        f32 field_8;
        f32 field_c;
        f32 field_10;  // its colour
        f32 field_14;
        f32 field_18;
        f32 field_1c;
        f32 field_20;  // its texture coordinates
        f32 field_24;
    };

    // A 4x4 matrix, an identity one at first (placeholder name).
    struct Unk_Matrix {
        Unk_Matrix() { Unk_SetIdentity(); }
        void Unk_SetIdentity() {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    field_0[i][j] = i == j ? 1.0f : 0.0f;
                }
            }
        }

        f32 field_0[4][4];
    };
    // Four and two floats, zero at first (placeholder names).
    struct Unk_Vec4 {
        Unk_Vec4() : field_0(0.0f), field_4(0.0f), field_8(0.0f), field_c(0.0f) {}
        Unk_Vec4(f32 a0, f32 a4, f32 a8, f32 ac) : field_0(a0), field_4(a4), field_8(a8), field_c(ac) {}

        f32 field_0;
        f32 field_4;
        f32 field_8;
        f32 field_c;
    };
    struct Unk_Vec2 {
        Unk_Vec2() : field_0(0.0f), field_4(0.0f) {}

        f32 field_0;
        f32 field_4;
    };

    explicit SiGfxFontDrawHelper(ISiAllocator* pAllocator);  // 0x7100543280
    ~SiGfxFontDrawHelper() override;  // 0x71005434b0, 0x7100543970
    u32 vf2() override;               // 0x7100545ee0
    u32 vf3() override;               // 0x7100545f00
    u32 vf4() override;

    // 0x71005436d0: leaves the kernel's handlers and lets go of what it has
    void Unk_5436d0();
    // 0x7100544090: lets go of what it has
    void Unk_544090();
    // 0x71005439a0: sets the helper up for a draw context
    bool Unk_5439a0(Unk_544540_Context* pContext);
    // The draw context's slots 51 to 57 (what they take is passed on as it
    // comes: the functions not written yet are declared without it).
    bool Unk_544010(void* font);  // 0x7100544010: sets the font
    // 0x7100544290: the size of a text (its flags: 0x20, newlines don't
    // count; 0x2000, it is UTF-8)
    bool Unk_544290(const char* text, Unk_Vec2* pSize, u32 flags, f32 scale);
    bool Unk_544540();            // 0x7100544540: begins
    // 0x7100544610: lays out a text in a rectangle (its flags: 1, 2 centred
    // or right-aligned; 4, 8 centred or at the bottom; 0x20, no wrapping or
    // newlines; 0x2000, UTF-8)
    bool Unk_544610(const char* text, const Unk_Vec4* pRect, u32 flags, const Unk_TextColor* pColor, f32 scale);
    bool Unk_544b00(const char* text, const Unk_Vec4* pRect, u32 flags, const Unk_TextColor* pColor,
                    const Unk_TextColor* pOutlineColor, f32 scale, u32 outline);  // 0x7100544b00

    // The next line, cleared, and a glyph added (inline: placeholder names).
    TextLineData* Unk_NewLine() {
        if (field_80 >= static_cast<s32>(field_88.m_itemCount)) {
            return nullptr;
        }
        TextLineData* p = &field_88.m_pData[field_80];
        memset(p, 0, sizeof(TextLineData));
        field_80++;
        return p;
    }
    GlyphRenderData* Unk_NewGlyph() {
        if (field_2c >= static_cast<s32>(field_30.m_itemCount)) {
            return nullptr;
        }
        return &field_30.m_pData[field_2c];
    }
    bool Unk_AddGlyph(TextLineData* line, const Unk_544290_Glyph* glyph, const Unk_TextColor* pColor, f32 x) {
        if (field_2c >= static_cast<s32>(field_30.m_itemCount)) {
            return false;
        }
        GlyphRenderData* data = &field_30.m_pData[field_2c];
        data->field_0 = line;
        data->field_8 = glyph;
        data->field_10 = *pColor;
        data->field_14 = x + static_cast<f32>(glyph->field_60);
        data->field_18 = static_cast<f32>(-glyph->field_64);
        data->field_1c = static_cast<f32>(glyph->field_90);
        data->field_20 = static_cast<f32>(glyph->field_94);
        data->field_24 = glyph->field_80;
        field_2c++;
        return true;
    }
    bool Unk_545910();            // 0x7100545910: ends, and draws what there is

    Unk_4bf660 field_8;
    Unk_544540_Context* field_18;  // the draw context
    Unk_544090_Object* field_20;   // the font
    s32 field_28;                  // how many begins there are
    s32 field_2c;                  // how many glyphs there are
    SiArray<GlyphRenderData, 16> field_30;
    s32 field_80;  // how many lines there are
    SiArray<TextLineData, 16> field_88;
    u8 field_d8[8];
    Unk_Matrix field_e0;
    SiArray<FontVertex, 16> field_120;
    SiArray<unsigned short, 16> field_170;
    Unk_5439a0_VertexFormat* field_1c0;
    Unk_Vec4 field_1c8[4];  // a quad's corners
    Unk_Vec2 field_208[4];  // and their texture coordinates
    Unk_544090_Object* field_228;
    Unk_544090_Object* field_230[16];
    u32 field_2b0;
    GfxEventHandler field_2b8;
    u8 field_2d8[8];
};
PKMN_OFFSET_ASSERT(SiGfxFontDrawHelper, field_30, 0x30);
PKMN_OFFSET_ASSERT(SiGfxFontDrawHelper, field_120, 0x120);
PKMN_OFFSET_ASSERT(SiGfxFontDrawHelper, field_1c0, 0x1c0);
PKMN_OFFSET_ASSERT(SiGfxFontDrawHelper, field_2b8, 0x2b8);
PKMN_SIZE_ASSERT(SiGfxFontDrawHelper, 0x2e0);
PKMN_SIZE_ASSERT(SiGfxFontDrawHelper::GlyphRenderData, 0x38);
PKMN_SIZE_ASSERT(SiGfxFontDrawHelper::TextLineData, 0x14);
PKMN_SIZE_ASSERT(SiGfxFontDrawHelper::FontVertex, 0x28);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_FONTDRAWHELPER_IMPL
// 0x7100545ee0 (vf2), 0x7100545f00 (vf3)
#line 46
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxFontDrawHelper, field_8.m_pAllocator, field_8.m_count)
#endif
