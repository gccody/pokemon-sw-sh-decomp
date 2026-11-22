// SiSDK3::SiGfxNXManager (RTTI: SiGfxNXManager : ISiGfxNXManager :
// ISiInterface; written as one class): what makes SiGfx's NVN devices and
// keeps them. Placeholder members; the virtual functions are vf<slot>. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_MANAGER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxNXDevice;

class SiGfxNXManager {
public:
    explicit SiGfxNXManager(ISiAllocator* pAllocator);  // 0x71004f6920
    virtual ~SiGfxNXManager();                          // 0x71004f69a0, 0x71004f6af0
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5(u64 a1);  // 0x71004f6bd0
    virtual u64 vf6();
    virtual u32 vf7();

    // 0x71004f6c80: a new device
    SiGfxNXDevice* Unk_4f6c80();
    // 0x71004f6d80: forgets a device
    void Unk_4f6d80(SiGfxNXDevice* pDevice);

    Unk_4bf660 field_8;
    SiArray<SiGfxNXDevice*, 16> field_18;  // its devices
    s32 field_68;
    u64 field_70;
};
PKMN_SIZE_ASSERT(SiGfxNXManager, 0x78);
PKMN_OFFSET_ASSERT(SiGfxNXManager, field_68, 0x68);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_MANAGER_IMPL
// 0x71004f6e60 (vf2), 0x71004f6e80 (vf3)
#line 35
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXManager, field_8.m_pAllocator, field_8.m_count)
#endif
