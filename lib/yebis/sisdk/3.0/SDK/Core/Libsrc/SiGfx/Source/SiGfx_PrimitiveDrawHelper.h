// SiSDK3::SiGfxPrimitiveDrawHelper (RTTI names the class; it derives from
// ISiInterface): what draws the draw context's primitives (the context has
// one at 0x2c70). As far as the executable's functions show it, with
// placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit
// (UNK_SIGFX_PRIMITIVEDRAWHELPER_IMPL).
#pragma once

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/SiGfx_Kernel.h>

namespace SiSDK3 {

// A vertex format's elements as the helper compares them (placeholder
// names: SiGfxNXVertexFormat's elements and their count).
struct Unk_NXVertexLayout {
    struct Element {
        u32 field_0;  // the attribute's row
        s32 field_4;  // and column
        u32 field_8;  // its format
        u32 field_c;
        s32 field_10;  // its offset
        u32 field_14;
        u32 field_18;
    };
    Element field_0[32];
    s32 field_380;  // how many elements
};
PKMN_SIZE_ASSERT(Unk_NXVertexLayout, 0x384);

// What the draw context's slot 33 gives (placeholder names): the program
// bound, whose slot 10 has its vertex format at 0x168.
struct Unk_547360_Program {
    u8 field_0[0x168];
    Unk_NXVertexLayout field_168;
};
class Unk_547360_Shader {
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
    virtual Unk_547360_Program* vf10();
};
struct Unk_547360_Bound {
    Unk_547360_Shader* field_0;
};

// What the helper keeps a reference of at 0xae0 (placeholder name).
class Unk_546ae0_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};


// What the draw context's slot 85 gives the helper (placeholder name).
struct Unk_PrimitiveStates {
    u8 field_0[8];
    class Unk_PrimitiveFormat* field_8;  // the vertex format
    u8 field_10[0x15c];
    u32 field_16c;  // what is drawn
    u8 field_170[0x18];
    u32 field_188;  // what changed (4: what is drawn)
};

// Its vertex format (placeholder name): slot 32 gives its elements.
class Unk_PrimitiveFormat {
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
    virtual const Unk_NXVertexLayout* vf32();
};

// The draw context as the helper calls it (placeholder name and slots).
// The device as the helper's event handler calls it (placeholder name): its
// shaders (slot 39) and programs (slot 46).
// What the helper makes its sampler from (placeholder name and members).
struct Unk_546c60_Desc {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u64 field_10;
    f32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24[7];
};
PKMN_SIZE_ASSERT(Unk_546c60_Desc, 0x40);

class Unk_PrimitiveDevice {
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
    virtual void vf38();
    virtual void* vf39(u64 kind);
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void* vf46(u32 index);
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual class Unk_546ae0_Object* vf52(const Unk_546c60_Desc* desc, void* a2, u32 a3, void* a4);
};

class Unk_PrimitiveContext {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual class Unk_PrimitiveDevice* vf5();
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
    virtual u32 vf24(s32 count, s32 first, s32 instances, s32 baseInstance);
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual Unk_547360_Bound* vf33();
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
    virtual void* vf74(u32 a1, s32 count, s32 size);  // room for vertices
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual bool vf84();
    virtual Unk_PrimitiveStates* vf85();
};

// What slot 58 of the draw context draws a texture with (placeholder names):
// its matrix, colours, filter and the rectangle it is clipped to.
struct Unk_PrimitiveTextureDesc {
    f32 field_0[16];
    f32 field_40;   // the level (a whole number: that level's view)
    u32 field_44[4];
    bool field_54;
    u32 field_58;   // the layer
    u8 field_5c[8];
    s32 field_64;
    u8 field_68[8];
    bool field_70;
    u32 field_74;
    u32 field_78;
    u8 field_7c[4];
    u32 field_80;   // which of the helper's shaders
    bool field_84;
    bool field_85;  // whether it is clipped
    s32 field_88;   // the clip rectangle: left, right, top, bottom
    s32 field_8c;
    s32 field_90;
    s32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_PrimitiveTextureDesc, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_PrimitiveTextureDesc, field_94, 0x94);

// A rectangle as slot 58 takes it (placeholder name): left, right, top,
// bottom.
struct Unk_PrimitiveRect {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};

// The texture slot 58 draws (placeholder name): slot 19 is its description,
// slot 26 a view of a level and layer.
class Unk_PrimitiveTexture;

class SiGfxPrimitiveDrawHelper : public ISiInterface {
public:
    // what the helper gives the kernel: slots 5 and 6 (0x71005467d0 and
    // 0x71005468b0, not written yet) are the kernel's events
    class GfxEventHandler : public ISiGfxKernel::EventHandler {
    public:
        explicit GfxEventHandler(ISiAllocator* pAllocator) : EventHandler(pAllocator) {}
        ~GfxEventHandler() override;  // 0x7100546770, 0x7100546790
        void vf5() override;
        void vf6() override;

        SiGfxPrimitiveDrawHelper* field_18;  // its helper
    };

    explicit SiGfxPrimitiveDrawHelper(ISiAllocator* pAllocator);  // 0x7100546990
    ~SiGfxPrimitiveDrawHelper() override;                          // 0x7100546a40, 0x7100546b90
    u32 vf2() override;                                            // 0x710054d300
    u32 vf3() override;                                            // 0x710054d320
    u32 vf4() override;

    // 0x7100546b00: lets go of what it has
    void Unk_546b00();
    // 0x7100546e80: the programs and vertex formats of each kind of primitive
    bool Unk_546e80();
    // 0x7100546c60: sets the helper up for a draw context
    bool Unk_546c60(Unk_PrimitiveContext* pContext);
    // The vertices' buffer's free (inline, in the .cpp, whose __FILE__ it has:
    // placeholder name)
    inline void Unk_FreeBuffer();
    // The event handler's slots 5 and 6 (inline: placeholder name)
    void Unk_Reset() {
        memset(&field_820, 0, sizeof(field_820));
        Unk_Setup();
    }
    void Unk_Setup() {
        Unk_546e80();
        Unk_PrimitiveDevice* pDevice = field_490->vf5();
        Unk_SetShader(0, pDevice->vf46(0x4c), field_490->vf5()->vf39(5));
        Unk_SetShader(1, pDevice->vf46(0x4d), field_490->vf5()->vf39(5));
    }
    void Unk_SetShader(s32 index, void* pProgram, void* pShader) {
        field_820.field_2a0[index] = pProgram;
        field_820.field_2b0[index] = pShader;
    }
    // The draw context's slots 35 to 49, 58 and 59 (what they take is passed
    // on as it comes: the functions not written yet are declared without it).
    bool Unk_5472d0(u32 mode);  // begins
    // 0x71005474b0: ends
    bool Unk_5474b0();
    // 0x7100547360: the attributes' offsets and formats from the vertex format
    void Unk_547360();
    // 0x7100547500: draws the vertices there are (or those of pData)
    bool Unk_547500(bool last, const u8* pData);
    bool Unk_547760();                     // adds the vertex being made
    bool Unk_547810(s32 count, const u8* pVertices);  // adds vertices
    bool Unk_5478f0(const void* pVertex);  // sets the vertex being made
    // set an attribute of the vertex being made
    bool Unk_547930(u32 row, s32 column, f32 x, f32 y, f32 z, f32 w);
    bool Unk_547a40(u32 row, s32 column, const f32* pValues);
    bool Unk_547b60(u32 row, s32 column, const f32* pValues);
    bool Unk_547ca0(u32 row, s32 column, const f32* pValues);
    bool Unk_547df0(u32 row, s32 column, u8 r, u8 g, u8 b, u8 a);
    bool Unk_547f50(u32 row, s32 column, const u8* pValues);
    bool Unk_5480c0(u32 row, s32 column, const u8* pValues);
    bool Unk_548230(u32 row, s32 column, const f32* pValues);
    bool Unk_548380(u32 row, s32 column, const u8* pValues);
    bool Unk_5484f0(u32 row, s32 column, const f32* pValues);
    // 0x7100548640: draws a texture in a rectangle (of a part of it)
    bool Unk_548640(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc, const Unk_PrimitiveRect* dest,
                    const Unk_PrimitiveRect* source);
    void Unk_54cab0();

    Unk_4bf660 field_8;
    u8 field_18[8];
    u8 field_20[10][16];  // each attribute's offset in a vertex
    u8 field_c0[10][16];  // and its format (0: none)
    // the vertices' buffer and what tells about it
    u8* field_160;
    u8* field_168;  // where the next vertex goes
    s32 field_170;  // the buffer's size
    s32 field_174;  // a vertex's size
    s32 field_178;  // how many vertices there are
    s32 field_17c;  // how many fit
    u32 field_180;  // what is drawn (1: points, 2 and 3: lines, 4 and 5: triangles)
    bool field_184;  // between a begin and its end
    u8 field_185[0xb];
    // The vertex being made and the vertices a strip keeps (placeholder
    // name), zeroed as a whole.
    struct Unk_Vertices {
        u8 field_0[0x100];
        u8 field_100[0x200];
    };
    Unk_Vertices field_190;
    Unk_PrimitiveContext* field_490;  // the draw context
    Unk_NXVertexLayout field_498;     // the vertex format the attributes are of
    u8 field_81c[4];
    // What the helper draws with (placeholder name), zeroed as a whole.
    struct Unk_Shaders {
        void* field_0[6][7];    // each kind's programs, by Unk_4ecf40's index
        void* field_150[6][7];  // and their vertex formats
        void* field_2a0[2];  // the programs
        void* field_2b0[2];  // and their shaders
    };
    Unk_Shaders field_820;
    Unk_546ae0_Object* field_ae0;
    GfxEventHandler field_ae8;
    u8 field_b08[8];
};
PKMN_OFFSET_ASSERT(SiGfxPrimitiveDrawHelper, field_160, 0x160);
PKMN_OFFSET_ASSERT(SiGfxPrimitiveDrawHelper, field_490, 0x490);
PKMN_OFFSET_ASSERT(SiGfxPrimitiveDrawHelper, field_ae8, 0xae8);
PKMN_SIZE_ASSERT(SiGfxPrimitiveDrawHelper, 0xb10);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_PRIMITIVEDRAWHELPER_IMPL
// 0x710054d300 (vf2), 0x710054d320 (vf3)
#line 45
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxPrimitiveDrawHelper, field_8.m_pAllocator, field_8.m_count)
#endif
