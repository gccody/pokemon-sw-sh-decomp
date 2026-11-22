// SiSDK3::SiGfxFontDrawHelper: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/SiGfx_Kernel.h>

namespace SiSDK3 {

class SiGfxFontDrawHelper {
public:
    // what the helper gives the kernel: it does nothing with the events
    class GfxEventHandler : public ISiGfxKernel::EventHandler {
    public:
        ~GfxEventHandler() override;  // 0x7100543200, 0x7100543220
        void vf5() override;            // 0x7100543260
        void vf6() override;            // 0x7100543270
    };

    virtual ~SiGfxFontDrawHelper();
    UNK_REFCOUNT_DECLARE;

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace SiSDK3

// 0x7100545ee0 (vf2), 0x7100545f00 (vf3)
#line 46
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxFontDrawHelper, field_8, field_10)
