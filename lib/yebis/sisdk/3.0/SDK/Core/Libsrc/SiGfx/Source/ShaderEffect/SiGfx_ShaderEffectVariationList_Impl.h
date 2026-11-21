// SiSDK3::SiGfxShaderEffectVariationList (RTTI names the class): as far as the
// code that holds one shows it (a package has one as a member), with
// placeholder members. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_SHADEREFFECTVARIATIONLIST_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class SiGfxShaderEffectPackage;

class SiGfxShaderEffectVariationList {
public:
    // 0x7100570d10
    explicit SiGfxShaderEffectVariationList(ISiAllocator* pAllocator);
    // 0x7100570e40
    virtual ~SiGfxShaderEffectVariationList();
    UNK_REFCOUNT_DECLARE;

    Unk_4bf660 field_8;
    SiOSCriticalSection field_18;
    SiGfxShaderEffectPackage* field_48;  // the package it's in
    SiString<char> field_50;             // the package's name
    u8 field_80[0xf8];                   // its lists and arrays
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectVariationList, 0x178);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECTVARIATIONLIST_IMPL
// 0x71005736d0 (vf2), 0x71005736f0 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffectVariationList, field_8.m_pAllocator, field_8.m_count)
#endif
