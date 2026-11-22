// SiSDK3::SiGfxTextureUtility: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
// The virtual functions declared and not defined here or in the .cpp are
// lib/yebis/class's or not decompiled yet (placeholder signatures).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxTextureUtility {
public:
    explicit SiGfxTextureUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxTextureUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u64 value, u64 arg2, u64 arg3, u64 arg4);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual u32 vf14();
    virtual u32 vf15();
    virtual u32 vf16();
    virtual void vf17();
    virtual void vf18();

    Unk_4bf660 field_8;
};

}  // namespace SiSDK3

// 0x71004ec870 (vf2), 0x71004ec890 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxTextureUtility, field_8.m_pAllocator, field_8.m_count)
