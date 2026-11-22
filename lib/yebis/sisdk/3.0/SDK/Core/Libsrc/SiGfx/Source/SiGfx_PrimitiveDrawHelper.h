// SiSDK3::SiGfxPrimitiveDrawHelper: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/SiGfx_Kernel.h>

namespace SiSDK3 {

class SiGfxPrimitiveDrawHelper {
public:
    // what the helper gives the kernel (slots 5 and 6, 0x71005467d0 and
    // 0x71005468b0, aren't decompiled yet)
    class GfxEventHandler : public ISiGfxKernel::EventHandler {
    public:
        ~GfxEventHandler() override;  // 0x7100546770, 0x7100546790
        void vf5() override;
        void vf6() override;
    };

    virtual ~SiGfxPrimitiveDrawHelper();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace SiSDK3

// 0x710054d300 (vf2), 0x710054d320 (vf3)
#line 45
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxPrimitiveDrawHelper, field_8, field_10)
