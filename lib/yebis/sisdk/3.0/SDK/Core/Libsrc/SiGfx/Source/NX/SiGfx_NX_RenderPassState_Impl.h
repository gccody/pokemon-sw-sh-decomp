// SiSDK3::SiGfxNXRenderPassState (RTTI names the class; it derives from
// ISiGfxNXRenderPassState, ISiGfxRenderPassState and ISiInterface).
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit
// (UNK_SIGFX_NX_RENDERPASSSTATE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

class SiGfxNXRenderPassState : public Unk_NXInterface {
public:
    SiGfxNXRenderPassState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71005550c0
    ~SiGfxNXRenderPassState() override;                                        // 0x7100555100, 0x7100555120
    u32 vf2() override;                                                        // 0x7100555210
    u32 vf3() override;                                                        // 0x7100555230
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual bool vf9();  // 0x71005551c0: one less of field_24, if there are any
    virtual u64* vf10();
    virtual u64* vf11();
    virtual u32 vf12();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    s32 field_24;
    u64 field_28;
};
PKMN_SIZE_ASSERT(SiGfxNXRenderPassState, 0x30);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_RENDERPASSSTATE_IMPL
// 0x7100555210 (vf2), 0x7100555230 (vf3)
#line 39
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXRenderPassState, field_8.m_pAllocator, field_8.m_count)
#endif
