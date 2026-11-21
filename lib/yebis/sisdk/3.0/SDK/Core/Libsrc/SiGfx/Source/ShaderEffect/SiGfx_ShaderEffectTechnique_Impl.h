// SiSDK3::SiGfxShaderEffectTechnique (RTTI names the class): a technique's
// name and its data, read from and written to a stream. Placeholder members;
// the virtual functions are vf<slot>. The reference counts are defined in
// this header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_SHADEREFFECTTECHNIQUE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiIOStream;

class SiGfxShaderEffectTechnique {
public:
    explicit SiGfxShaderEffectTechnique(ISiAllocator* pAllocator);
    virtual ~SiGfxShaderEffectTechnique();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual const u8* vf5();
    virtual u32 vf6();  // field_48

    // The allocator that made it (inline in every caller: placeholder name).
    // The destructor reads it through this: read as `field_8.m_pAllocator`
    // there, the address would be the one field_8's destructor is called
    // with, kept in a register across the body's calls, which the original
    // doesn't do.
    ISiAllocator* Unk_Allocator() const { return field_8.m_pAllocator; }

    // 0x71005709e0: writes it, 0x7100570aa0: reads it
    bool Unk_5709e0(ISiIOStream* stream);
    bool Unk_570aa0(ISiIOStream* stream);

    Unk_4bf660 field_8;
    SiString<char> field_18;  // the name
    u32 field_48;             // what the definition sorts its techniques by
    u32 field_4c;             // its index in the definition
    s32 field_50;             // the number of bytes at field_58
    void* field_58;
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectTechnique, 0x60);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECTTECHNIQUE_IMPL
// 0x7100570b80 (vf2), 0x7100570ba0 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffectTechnique, field_8.m_pAllocator, field_8.m_count)
#endif
