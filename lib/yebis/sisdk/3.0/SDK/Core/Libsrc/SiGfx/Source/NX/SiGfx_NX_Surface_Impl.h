// SiSDK3::SiGfxNXSurface (RTTI names the class; like the other NX resources it
// is on ISiInterface and, at 8, ISiNamedObject): one level and layer of a
// texture, or a surface with memory of its own. Placeholder members; the
// virtual functions are vf<slot>. The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_NX_SURFACE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// What a texture's slot 19 returns (placeholder name): its description.
struct Unk_NXSurfaceTextureDesc {
    u32 field_0;   // its kind (4 and 6: cube maps)
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    s32 field_14;  // its width
    s32 field_18;  // and height
    u32 field_1c;
    u32 field_20;  // how many levels
};

// What a surface's other owner's slot 20 returns, and that owner (placeholder
// names).
struct Unk_NXSurfaceOwnerDesc {
    u8 field_0[0x20];
    u32 field_20;
};
class Unk_NXSurfaceOwner {
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
    virtual const Unk_NXSurfaceOwnerDesc* vf20();
};

// The texture a surface is part of, as the surface calls it (placeholder
// name): slot 19 is its description, slot 40 its NVN texture, slot 42 the NVN
// view of a level and layer.
class Unk_NXSurfaceTexture {
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
    virtual const Unk_NXSurfaceTextureDesc* vf19();
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
    virtual void* vf40();
    virtual void vf41();
    virtual void* vf42(u32 level, u32 layer);
};

// The named object's functions are the surface's slots 28 to 30.
UNK_NAMED_OBJECT(Unk_NXSurfaceNamedObject, vf28, vf29, vf30);

class SiGfxNXSurface : public Unk_NXInterface, public Unk_NXSurfaceNamedObject {
public:
    // What a surface is described by (placeholder name and members).
    struct Unk_Desc {
        u32 field_0;
        u32 field_4;   // the format
        u32 field_8;
        u32 field_c;
        u32 field_10;
        s32 field_14;  // the width
        s32 field_18;  // the height
        s32 field_1c;  // the samples
        u32 field_20;
        bool field_24;
        bool field_25;
        s32 field_28;  // a pixel's size
        bool field_2c;  // whether the format is one of blocks
        s32 field_30;   // the width and height in blocks
        s32 field_34;
        s32 field_38;   // a block's size
        u32 field_3c;
        u32 field_40;   // the cube map's face (4: none)
        u32 field_44;
        u32 field_48;   // the level
        u32 field_4c;
        Unk_NXSurfaceOwner* field_50;
    };

    SiGfxNXSurface();                                                  // 0x710055c660
    SiGfxNXSurface(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710055c5b0
    ~SiGfxNXSurface() override;                 // 0x710055c730, 0x710055c850
    u32 vf2() override;                         // 0x710055d460
    u32 vf3() override;                         // 0x710055d480
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual size_t vf7();  // its index in the pool
    virtual const Unk_NXResourceInfo* vf8();
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
    bool vf28(const char* name) override;       // 0x710055caa0
    const SiString<char>* vf29() override;      // 0x710055cb20
    u32 vf30() override;                        // 0x710055cb40

    // 0x710055c9a0: lets go of the texture or of its own memory
    void Unk_55c9a0();
    // 0x710055cb60: the device it belongs to, whose allocator becomes its own
    // and its name's
    void Unk_55cb60(SiGfxNXDevice* pDevice);
    // 0x710055cd70: its description, from its NVN texture and from the texture
    // it is a level and layer of
    void Unk_55cd70(u32 a1, u32 level, u32 layer);
    // 0x710055d300: becomes a level and layer of a texture
    bool Unk_55d300(Unk_NXSurfaceTexture* pTexture, u32 level, u32 layer);

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    Unk_Desc field_78;
    u32 field_d0;
    Unk_NXSurfaceTexture* field_d8;  // the texture it is part of
    void* field_e0;                  // its NVN texture
    void* field_e8;                  // its NVN texture view
    SiGfxNXMemoryHeap* field_f0;     // its own memory's heap
    s64 field_f8;                    // and where in it
    u64 field_100;
    u32 field_108;  // which of the texture's levels and layers it is
    bool field_10c;  // whether the NVN objects are its own
    u32 field_110;
};
PKMN_OFFSET_ASSERT(SiGfxNXSurface, field_78, 0x78);
PKMN_OFFSET_ASSERT(SiGfxNXSurface, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(SiGfxNXSurface, field_10c, 0x10c);
PKMN_SIZE_ASSERT(SiGfxNXSurface::Unk_Desc, 0x58);
PKMN_SIZE_ASSERT(SiGfxNXSurface, 0x118);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_SURFACE_IMPL
// 0x710055d460 (vf2), 0x710055d480 (vf3)
#line 39
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXSurface, field_10.m_pAllocator, field_10.m_count)
#endif
