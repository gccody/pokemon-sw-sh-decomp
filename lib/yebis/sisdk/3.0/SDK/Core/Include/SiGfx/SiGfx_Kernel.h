// SiSDK3::ISiGfxKernel::EventHandler: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the one translation unit that asks for them
// (UNK_SIGFX_KERNEL_EVENTHANDLER_DEFINE: SiGfx_Kernel.cpp).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiGfxKernel {
public:
    // What the kernel tells of its events: an abstract class (its deleting
    // destructor is a trap, 0x7100545fb0).
    class EventHandler {
    public:
        virtual ~EventHandler() {}  // 0x7100545f90
        UNK_REFCOUNT_DECLARE;
        virtual u32 vf4() { return field_8.m_count; }  // 0x7100545ed0
        virtual void vf5() = 0;
        virtual void vf6() = 0;

        Unk_4bf660 field_8;
    };
};

}  // namespace SiSDK3

#ifdef UNK_SIGFX_KERNEL_EVENTHANDLER_DEFINE
// 0x7100545e30 (vf2), 0x7100545e50 (vf3)
#line 93
UNK_REFCOUNT_DEFINE(SiSDK3::ISiGfxKernel::EventHandler, field_8.m_pAllocator, field_8.m_count)
#endif
