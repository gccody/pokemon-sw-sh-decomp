// SiSDK3::SiGfxNXVolume (RTTI names the class; like the other NX resources it
// is on ISiInterface and, at 8, ISiNamedObject): a volume texture's data.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit (UNK_SIGFX_NX_VOLUME_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the volume's slots 20 to 22.
UNK_NAMED_OBJECT(Unk_NXVolumeNamedObject, vf20, vf21, vf22);

class SiGfxNXVolume : public Unk_NXInterface, public Unk_NXVolumeNamedObject {
public:
    SiGfxNXVolume();                            // 0x71005656f0
    ~SiGfxNXVolume() override;                  // 0x7100565780, 0x71005658a0
    u32 vf2() override;                         // 0x7100565ec0
    u32 vf3() override;                         // 0x7100565ee0
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
    virtual u32 vf16();
    virtual const u8* vf17();
    virtual u64 vf18();
    virtual u64 vf19();
    bool vf20(const char* name) override;       // 0x71005659c0
    const SiString<char>* vf21() override;      // 0x7100565a40
    u32 vf22() override;                        // 0x7100565a60

    // 0x7100565ab0: the device it belongs to, whose allocator becomes its own
    // and its name's
    void Unk_565ab0(SiGfxNXDevice* pDevice);
    // 0x7100565c10: starts over with data
    bool Unk_565c10(void* data, u32 a2);

    Unk_538d70 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    // (placeholder name)
    struct Unk_78 {
        u64 field_0[8];
    };
    Unk_78 field_78;
    u32 field_b8;
    void* field_c0;  // the data
    u32 field_c8;
};
PKMN_OFFSET_ASSERT(SiGfxNXVolume, field_78, 0x78);
PKMN_OFFSET_ASSERT(SiGfxNXVolume, field_c0, 0xc0);
PKMN_SIZE_ASSERT(SiGfxNXVolume, 0xd0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_VOLUME_IMPL
// 0x7100565ec0 (vf2), 0x7100565ee0 (vf3)
#line 37
UNK_REFCOUNT_DEFERRED_DEFINE(SiSDK3::SiGfxNXVolume, field_10.m_pAllocator, field_10.m_count, field_10.field_c)
#endif
