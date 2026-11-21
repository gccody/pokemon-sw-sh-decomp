// SiSDK3::SiSystemInfo (RTTI): what the kernel tells about the machine.
// Placeholder members. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the file that asks with
// UNK_SISYSTEMINFO_DEFINE (SiCore_SystemInfo_Impl.cpp).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiSystemInfo {
public:
    // what vf5 returns (0x60 bytes)
    struct Unk_Info {
        u64 field_0;  // the system tick's frequency
        u64 field_8;
        s32 field_10[4];
        char field_20[0x10];
        char field_30[0x20];
        bool field_50[4];
        bool field_54[2];
        bool field_56;
        bool field_57;
        bool field_58;
        bool field_59;
        u8 field_5a[6];
    };

    explicit SiSystemInfo(ISiAllocator* pAllocator);  // 0x71004c88c0
    virtual ~SiSystemInfo();                          // 0x71004c89e0, 0x71004c8aa0
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual const u8* vf5();
    virtual void vf6();  // 0x71004c8d40
    virtual void vf7();  // 0x71004c8db0
    virtual u64 vf8();
    virtual u64 vf9();
    virtual const u8* vf10();
    virtual const u8* vf11();

    Unk_4bf660 field_8;
    char field_18[0x80];
    char field_98[0x80];
    SiString<char> field_118;  // in field_18
    SiString<char> field_148;  // in field_98
    Unk_Info field_178;
};
PKMN_SIZE_ASSERT(SiSystemInfo::Unk_Info, 0x60);
PKMN_SIZE_ASSERT(SiSystemInfo, 0x1d8);

}  // namespace SiSDK3

#ifdef UNK_SISYSTEMINFO_DEFINE
// 0x71004c8e40 (vf2), 0x71004c8e60 (vf3)
#line 24
UNK_REFCOUNT_DEFINE(SiSDK3::SiSystemInfo, field_8.m_pAllocator, field_8.m_count)
#endif
