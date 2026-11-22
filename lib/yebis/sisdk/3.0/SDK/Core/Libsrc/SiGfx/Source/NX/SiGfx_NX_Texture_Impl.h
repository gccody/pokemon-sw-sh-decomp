// SiSDK3::SiGfxNXTexture (RTTI names the class; it is on ISiInterface, at 8
// on ISiNamedObject, and at 0x10 on an interface that has a GUID): an NVN
// texture, its surfaces and its volumes. Placeholder members; the virtual
// functions are vf<slot>. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIGFX_NX_TEXTURE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Surface_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Volume_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

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

class SiGfxNXTexture : public Unk_NXInterface, public Unk_NXTextureNamedObject, public Unk_NXTextureTypedObject {
public:
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
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual SiGfxNXSurface* vf25(s32 level);                            // 0x7100561040
    virtual SiGfxNXSurface* vf26(s32 layer, s32 level);                 // 0x7100561080
    virtual SiGfxNXSurface* vf27(s32 layer, s32 level);                 // 0x71005610c0
    virtual SiGfxNXSurface* vf28(s32 layer, s32 face, s32 level);       // 0x7100561120
    virtual SiGfxNXVolume* vf29(s32 level);                             // 0x7100561190
    virtual void vf30();
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
    virtual void vf44();
    bool vf45(const char* name) override;       // 0x710055f1e0
    const SiString<char>* vf46() override;      // 0x710055f2c0
    u32 vf47() override;                        // 0x710055f2e0

    // 0x7100561e10: maps its memory pool; 0x7100561e50: tells NVN that its
    // memory was written
    void* Unk_561e10();
    void Unk_561e50();

    Unk_538d70 field_18;
    SiGfxNXDevice* field_28;
    size_t field_30;              // its index in the pool (0: it isn't in one)
    Unk_NXString<0x40> field_38;  // the name
    u32 field_a8;                 // its hash
    u8 field_ac[0x128];
    u32 field_1d4;  // its kind (2: 2D, 3: 3D, 4: cube, 5: 2D array, 6: cube array)
    u32 field_1d8;
    u8 field_1dc[0xc];
    u32 field_1e8;
    u32 field_1ec;
    u32 field_1f0;
    u32 field_1f4;
    u8 field_1f8[0x34];
    s32 field_22c;  // how many levels
    s32 field_230;  // how many layers
    u32 field_234;
    SiArray<SiGfxNXSurface, 16> field_238;
    SiArray<SiGfxNXVolume, 16> field_288;
    u8 field_2d8[0x40];
    Unk_NXTextureOwner* field_318;
    u64 field_320;
    void* field_328;  // NVNtexture
    u8 field_330[0x18];
    SiArray<void*, 16> field_348;  // the levels' and layers' NVN views
};
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_1d4, 0x1d4);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_238, 0x238);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_328, 0x328);
PKMN_OFFSET_ASSERT(SiGfxNXTexture, field_348, 0x348);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_TEXTURE_IMPL
// 0x71005623c0 (vf2), 0x71005623e0 (vf3)
#line 40
UNK_REFCOUNT_DEFERRED_DEFINE(SiSDK3::SiGfxNXTexture, field_18.m_pAllocator, field_18.m_count, field_18.field_c)
#endif
