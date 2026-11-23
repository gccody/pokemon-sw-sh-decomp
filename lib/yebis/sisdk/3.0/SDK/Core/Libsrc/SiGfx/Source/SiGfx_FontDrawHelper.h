// SiSDK3::SiGfxFontDrawHelper (RTTI names the class; it derives from
// ISiInterface): what draws the draw context's text (the context has one at
// 0x3780). As far as the executable's functions show it, with placeholder
// members; the virtual functions are vf<slot>. The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// class's own translation unit (UNK_SIGFX_FONTDRAWHELPER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/SiGfx_Kernel.h>

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
struct Unk_544290_Glyph {
    u8 field_0[0x58];
    s32 field_58;  // its advance
    u8 field_5c[0xc];
    s32 field_68;  // its bitmap's size
    s32 field_6c;
};
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
    virtual void vf46();
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

// The draw context as the helper calls it (placeholder name).
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
    virtual Unk_544540_Target* vf33();
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
    struct GlyphRenderData {
        GlyphRenderData() : field_10(0), field_18(0), field_20(0), field_28(0), field_30(0) {}

        u64 field_0;
        u64 field_8;
        u64 field_10;
        u64 field_18;
        u64 field_20;
        u64 field_28;
        u32 field_30;
    };
    struct TextLineData {
        TextLineData() : field_0(0), field_4(0), field_8(0), field_c(0) {}

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
    };
    struct FontVertex {
        FontVertex() : field_0(0), field_8(0), field_10(0), field_18(0), field_20(0) {}

        u64 field_0;
        u64 field_8;
        u64 field_10;
        u64 field_18;
        u64 field_20;
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
    void Unk_544610();            // 0x7100544610
    void Unk_544b00();            // 0x7100544b00
    void Unk_545910();            // 0x7100545910

    Unk_4bf660 field_8;
    Unk_544540_Context* field_18;  // the draw context
    Unk_544090_Object* field_20;   // the font
    u32 field_28;                  // how many begins there are
    u32 field_2c;
    SiArray<GlyphRenderData, 16> field_30;
    u32 field_80;
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
