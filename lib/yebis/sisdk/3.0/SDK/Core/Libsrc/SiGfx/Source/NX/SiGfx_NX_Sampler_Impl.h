// SiSDK3::SiGfxNXSampler (RTTI names the class; it derives from
// ISiGfxNXSampler, ISiGfxSampler and ISiGfxResource, which is on ISiInterface
// and, at 8, ISiNamedObject): an NVN sampler and its number in the device's
// sampler pool. Placeholder members; the virtual functions are vf<slot>. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_SAMPLER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the sampler's slots 20 to 22.
UNK_NAMED_OBJECT(Unk_NXSamplerNamedObject, vf20, vf21, vf22);

class SiGfxNXSampler : public Unk_NXInterface, public Unk_NXSamplerNamedObject {
public:
    // A sampler's description (placeholder name): what its constructor takes
    // and slot 17 returns. Its copy is the implicit one: two blocks of plain
    // members around the border colour, which copies itself.
    struct Unk_Desc {
        u32 field_0;   // the filter
        u32 field_4;   // the wrap modes
        u32 field_8;
        u32 field_c;
        f32 field_10;  // the level of detail's bias
        f32 field_14;  // its range
        f32 field_18;
        s32 field_1c;  // the largest anisotropy
        u32 field_20;  // the comparison
        Unk_NXColor field_24;  // the border
        u32 field_34;
        u32 field_38;
        u32 field_3c;
    };

    SiGfxNXSampler(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, const Unk_Desc& desc);  // 0x7100558c60
    ~SiGfxNXSampler() override;                 // 0x7100558d40, 0x7100558e30
    u32 vf2() override;                         // 0x71005592a0
    u32 vf3() override;                         // 0x71005592c0
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
    virtual const Unk_Desc* vf17();
    virtual u32 vf18();
    virtual u32 vf19();
    bool vf20(const char* name) override;       // 0x71005590b0
    const SiString<char>* vf21() override;      // 0x7100559190
    u32 vf22() override;                        // 0x71005591b0

    // 0x7100558e90: makes the NVN sampler, for the pool that made the object
    bool Unk_558e90(size_t index);

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    Unk_Desc field_78;
    u32 field_b8;
    u64 field_c0[12];  // NVNsampler
    s32 field_120;     // its number in the device's sampler pool
    bool field_124;    // whether the NVN sampler is made
};
PKMN_OFFSET_ASSERT(SiGfxNXSampler, field_78, 0x78);
PKMN_OFFSET_ASSERT(SiGfxNXSampler, field_c0, 0xc0);
PKMN_SIZE_ASSERT(SiGfxNXSampler, 0x128);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_SAMPLER_IMPL
// 0x71005592a0 (vf2), 0x71005592c0 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXSampler, field_10.m_pAllocator, field_10.m_count)
#endif
