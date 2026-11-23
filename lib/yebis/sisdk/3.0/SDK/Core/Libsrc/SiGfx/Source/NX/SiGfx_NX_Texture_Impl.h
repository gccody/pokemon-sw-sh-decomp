// SiSDK3::SiGfxNXTexture (RTTI names the class; it is on ISiInterface, at 8
// on ISiNamedObject, and at 0x10 on an interface that has a GUID): an NVN
// texture, its surfaces and its volumes. Placeholder members; the virtual
// functions are vf<slot>. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIGFX_NX_TEXTURE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Surface_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Volume_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

class NVNtextureView;

namespace SiSDK3 {

// The named object's functions are the texture's slots 45 to 47.
UNK_NAMED_OBJECT(Unk_NXTextureNamedObject, vf45, vf46, vf47);

// The third base (placeholder name): whether the object is of a class, by
// the class's GUID, and its own class's GUID. They are the texture's slots
// 17 and 18.
class Unk_NXTextureTypedObject {
public:
    virtual ~Unk_NXTextureTypedObject() {}
    virtual bool vf17(const void* guid) = 0;
    virtual const void* vf18() = 0;
};

// What the texture's slot 31 fills (placeholder name): a render target's
// description.
class Unk_NXTextureTarget {
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
    virtual void vf10(u32 a1, u32 a2, u32 a3, u32 a4);
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(u32 a1, u32 a2, u32 a3, s32 a4);
};

// What the texture's slot 32 keeps a reference of (placeholder name).
class Unk_NXTextureOwner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// The draw context as slot 30 is given it (placeholder name): slot 102 is
// its NVN command buffer.
class Unk_NXTextureDrawContext {
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
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void* vf102();
};

class SiGfxNXTexture : public Unk_NXInterface, public Unk_NXTextureNamedObject, public Unk_NXTextureTypedObject {
public:
    // What a texture is made from (placeholder name and members): 0x110
    // bytes, two strings among them.
    struct Unk_Desc {
        // the first members given (placeholder parameters) or zero. The
        // level data and their count are parameters too: with all of 0x50 to
        // 0x78 constant, the constructor's own zero stores there become a
        // memset before it is inlined, and every user's zero stores at 0x38
        // to 0x48 then come out after those at 0x50 (the original has them
        // first: the NX texture's constructor, the face cache's slot 5, the
        // texture chunk's data)
        inline explicit Unk_Desc(u32 format = 0, u32 width = 0, u32 height = 0, u32 a18 = 0, u32 a1c = 0, u32 a20 = 0,
                          u32 a30 = 0, u32 a38 = 0, u32 a54 = 0, const void* a60 = nullptr)
            : field_0(format), field_4(0), field_8(0), field_10(width), field_14(height), field_18(a18),
              field_1c(a1c), field_20(a20), field_24(0), field_28(0), field_2c(0), field_30(a30), field_34(8), field_38(a38), field_3c(0),
              field_40(0), field_44(0), field_50(0), field_54(a54), field_58(0), field_60(a60),
              field_68(0), field_70(0), field_78(1.0f), field_7c(0), field_80(0), field_84(0), field_e8(0),
              field_ec(-1), field_f0(-1) {
            field_f4 = Unk_Pair();
            field_fe = false;
            field_fc = false;
            field_fd = false;
            field_48 = 0;
            field_100 = -1;
            field_108 = -1;
        }

        // 0x710055ffd0: back to the defaults
        void Unk_55ffd0();

        // two numbers copied one by one (placeholder): slot 23's copy of a
        // description copies them member by member between the two blocks
        // it copies whole, so their copy constructor isn't trivial
        struct Unk_Pair2 {
            Unk_Pair2(u32 a0 = 0, u32 a4 = 0) : field_0(a0), field_4(a4) {}
            Unk_Pair2(const Unk_Pair2& other) : field_0(other.field_0), field_4(other.field_4) {}
            Unk_Pair2& operator=(const Unk_Pair2& other) = default;
            u32 field_0;
            u32 field_4;
        };

        // two numbers stored together (placeholder)
        struct Unk_Pair {
            Unk_Pair() : field_0(-1), field_4(0) {}
            s32 field_0;
            u32 field_4;
        };

        u32 field_0;  // the format
        u32 field_4;
        u64 field_8;
        u32 field_10;  // the width
        u32 field_14;  // the height
        u32 field_18;
        u32 field_1c;
        u32 field_20;
        u32 field_24;
        u32 field_28;  // (a 32-bit member: the texture utility's slot 18 zeroes it alone)
        u32 field_2c;
        u32 field_30;
        u32 field_34;
        u32 field_38;
        u32 field_3c;  // (0x34 to 0x3c: what the texture chunk's reader adds its flags to)
        u32 field_40;
        u32 field_44;
        u64 field_48;
        u32 field_50;
        u32 field_54;
        u64 field_58;
        const void* field_60;
        Unk_Pair2 field_68;
        Unk_Pair2 field_70;
        f32 field_78;
        u32 field_7c;
        u32 field_80;
        u32 field_84;
        SiString<char> field_88;
        SiString<char> field_b8;
        u32 field_e8;
        s32 field_ec;
        s32 field_f0;
        Unk_Pair field_f4;
        bool field_fc;
        bool field_fd;
        bool field_fe;
        s64 field_100;
        s64 field_108;
    };
    PKMN_SIZE_ASSERT(Unk_Desc, 0x110);

    // The pixels of a level, face or layer a description points to
    // (placeholder name and members).
    struct Unk_LevelData {
        const void* field_0;
        u64 field_8;   // how many bytes
        u32 field_10;  // how many bytes a row is
        u32 field_14;
    };
    PKMN_SIZE_ASSERT(Unk_LevelData, 0x18);

    // 0x710055e7c0: a texture of a kind (2: 2D, ...)
    SiGfxNXTexture(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, u32 kind);
    ~SiGfxNXTexture() override;                 // 0x710055eb20, 0x710055f130
    u32 vf2() override;                         // 0x71005623c0
    u32 vf3() override;                         // 0x71005623e0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
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
    bool vf17(const void* guid) override;       // 0x71005624f0
    const void* vf18() override;                // 0x7100562510
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    // 0x710055f3d0: makes the texture from a description
    virtual bool vf22(const Unk_Desc* desc);
    // 0x71005604c0: makes the texture from an image (its pixels, levels and
    // layers) and a description of the rest
    virtual bool vf23(const Unk_Desc* desc, SiGfxImage* image);
    virtual void vf24();  // 0x7100560e10: releases what it was made with
    virtual SiGfxNXSurface* vf25(s32 level);                            // 0x7100561040
    virtual SiGfxNXSurface* vf26(s32 layer, s32 level);                 // 0x7100561080
    virtual SiGfxNXSurface* vf27(s32 layer, s32 level);                 // 0x71005610c0
    virtual SiGfxNXSurface* vf28(s32 layer, s32 face, s32 level);       // 0x7100561120
    virtual SiGfxNXVolume* vf29(s32 level);                             // 0x7100561190
    // 0x71005611d0: makes its levels from the first (with the device's
    // program 0x4b), in the context's command buffer or in a command list of
    // the device's
    virtual bool vf30(Unk_NXTextureDrawContext* pContext);
    virtual bool vf31(Unk_NXTextureTarget* pTarget);                    // 0x7100561630
    virtual bool vf32(Unk_NXTextureOwner* pOwner);                      // 0x71005616b0
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual bool vf37();
    virtual void vf38();
    virtual bool vf39(u32 kind);                                        // 0x7100562370
    virtual void vf40();
    virtual void vf41();
    virtual void* vf42(s32 level, s32 layer);                           // 0x7100561dc0
    virtual void vf43();
    virtual bool vf44(void* texture, void* view);  // 0x7100561ef0: takes an NVN texture and its view
    bool vf45(const char* name) override;       // 0x710055f1e0
    const SiString<char>* vf46() override;      // 0x710055f2c0
    u32 vf47() override;                        // 0x710055f2e0

    // 0x71005601b0: makes its surfaces or volumes for its kind (0x7100561730
    // and 0x7100561aa0 make a cube's and a cube array's, not written yet)
    bool Unk_5601b0();
    bool Unk_561730();
    // 0x7100561970: makes a surface of each level of each layer
    bool Unk_561970();
    bool Unk_561aa0();
    // 0x7100561e10: maps its memory pool; 0x7100561e50: tells NVN that its
    // memory was written
    void* Unk_561e10();
    void Unk_561e50();

    Unk_538d70 field_18;
    SiGfxNXDevice* field_28;
    size_t field_30;              // its index in the pool (0: it isn't in one)
    Unk_NXString<0x40> field_38;  // the name
    u32 field_a8;                 // its hash
    u32 field_ac;
    Unk_Desc field_b0;            // what it was made from
    // 0x1c0 to 0x22c: what it is (the constructor zeroes it, then sets the
    // first member and the kind)
    u32 field_1c0;
    u32 field_1c4;
    u32 field_1c8;
    u32 field_1cc;
    u32 field_1d0;
    u32 field_1d4;  // its kind (1: 1D, 2: 2D, 3: 3D, 4: cube, 5: 2D array, 6: cube array)
    u32 field_1d8;  // the format
    u32 field_1dc;  // the view's format, or
    u32 field_1e0;  // the view's format with a depth and stencil mode
    u32 field_1e4;
    s32 field_1e8;  // the width
    s32 field_1ec;  // the height
    s32 field_1f0;  // the depth (3D)
    s32 field_1f4;  // how many levels
    s32 field_1f8;  // how many layers (arrays)
    s32 field_1fc;  // levels times layers
    s32 field_200;
    s32 field_204;  // the samples
    u32 field_208;
    bool field_20c;
    bool field_20d;
    bool field_20e;  // whether the format is one of blocks
    bool field_20f;
    s32 field_210;  // the width and height in blocks
    s32 field_214;
    s32 field_218;  // a block's size
    u32 field_21c;
    u8 field_220[0xc];
    s32 field_22c;  // how many levels
    s32 field_230;  // how many layers
    u32 field_234;
    SiArray<SiGfxNXSurface, 16> field_238;
    SiArray<SiGfxNXVolume, 16> field_288;
    u32 field_2d8;
    u32 field_2dc;
    u32 field_2e0;
    u32 field_2e4;
    u64 field_2e8;
    f32 field_2f0;
    u32 field_2f4;
    u32 field_2f8;
    u8 field_2fc[0x1c];
    Unk_NXTextureOwner* field_318;
    u32 field_320;
    u32 field_324;
    void* field_328;  // NVNtexture
    u64 field_330;
    s32 field_338;
    u32 field_33c;
    u64 field_340;
    SiArray<NVNtextureView*, 16> field_348;  // the levels' and layers' NVN views
    SiArray<int, 16> field_398;
    SiArray<unsigned long, 16> field_3e8;
    // Three words and a flag, which the constructor zeroes. The flag being
    // the last member (0x450, the class's size minus 8) decides the thunks:
    // clang's -8 adjustment of `this` becomes an index of the member there,
    // and only for a scalar the thunk of slot 45 keeps `sub x8, x19, #8`.
    SiGfxNXMemoryHeap* field_438;  // the heap of its memory, its offset there and size
    s64 field_440;
    u64 field_448;
    bool field_450;
    bool field_451;
};
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_1d4, 0x1d4);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_20c, 0x20c);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_22c, 0x22c);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_238, 0x238);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_328, 0x328);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_348, 0x348);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_b0, 0xb0);
PKMN_SIZE_ASSERT(SiGfxNXTexture, 0x458);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_TEXTURE_IMPL
// 0x71005623c0 (vf2), 0x71005623e0 (vf3)
#line 40
UNK_REFCOUNT_DEFERRED_DEFINE(SiSDK3::SiGfxNXTexture, field_18.m_pAllocator, field_18.m_count, field_18.field_c)
#endif
