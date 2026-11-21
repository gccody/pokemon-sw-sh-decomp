// SiSDK3::SiGfxShaderEffectVariation (RTTI names the class): its strings and
// its two lists of items, as far as its destructor shows them. Placeholder
// members. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIGFX_SHADEREFFECTVARIATION_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiIOStream;

class SiGfxShaderEffectVariation {
public:
    // An item of its lists (RTTI: the arrays' element): 0x24 bytes, with no
    // destructor.
    struct VariationItem {
        u32 field_0[9];
    };

    // 0x7100574710
    explicit SiGfxShaderEffectVariation(ISiAllocator* pAllocator);
    virtual ~SiGfxShaderEffectVariation();
    UNK_REFCOUNT_DECLARE;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual bool vf14(ISiIOStream* stream);  // writes it
    virtual bool vf15(ISiIOStream* stream);  // reads it

    // 0x7100574a20: empties the lists and the strings after them
    void Unk_574a20();

    Unk_4bf660 field_8;
    SiString<char> field_18;
    SiArray<VariationItem> field_48;
    SiString<char> field_98;
    u64 field_c8;
    SiArray<VariationItem> field_d0;
    SiString<char> field_120;
    u64 field_150;
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectVariation, 0x158);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECTVARIATION_IMPL
// 0x7100575cb0 (vf2), 0x7100575cd0 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffectVariation, field_8.m_pAllocator, field_8.m_count)
#endif
