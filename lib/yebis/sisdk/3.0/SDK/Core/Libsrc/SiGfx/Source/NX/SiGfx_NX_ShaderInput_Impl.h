// SiSDK3::SiGfxNXShaderInput (RTTI names the class; it derives from
// ISiGfxNXShaderInput, ISiGfxShaderInput and ISiInterface): what a shader
// program takes as input, up to 32 entries. Placeholder members; the virtual
// functions are vf<slot>. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIGFX_NX_SHADERINPUT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

class SiGfxNXShaderInput : public Unk_NXInterface {
public:
    // One input (placeholder name). Its constructor clears it: the class's
    // constructor has the 32 of them and the members around them as one
    // memset that isn't a tail call, which is what merged stores give.
    struct Unk_Entry {
        Unk_Entry() : field_0(0), field_4(0), field_8(0), field_c(0) {}

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
    };

    SiGfxNXShaderInput(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710055abb0
    ~SiGfxNXShaderInput() override;                                        // 0x710055ac00, 0x710055ac20
    u32 vf2() override;                                                    // 0x710055acb0
    u32 vf3() override;                                                    // 0x710055acd0
    u32 vf4() override;
    virtual u32 vf5();
    virtual const Unk_Entry* vf6();
    virtual const Unk_Entry* vf7(s32 index);  // 0x710055ac90: an entry (the first one for a wrong index)

    // 0x710055ac60: whether it was given a program
    bool Unk_55ac60(const void* program);

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;  // how many entries there are
    Unk_Entry field_24[32];
    u32 field_224;
    u32 field_228;
    u32 field_22c;
    u32 field_230;
};
PKMN_OFFSET_ASSERT(SiGfxNXShaderInput, field_224, 0x224);
PKMN_SIZE_ASSERT(SiGfxNXShaderInput, 0x238);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_SHADERINPUT_IMPL
// 0x710055acb0 (vf2), 0x710055acd0 (vf3)
#line 37
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXShaderInput, field_8.m_pAllocator, field_8.m_count)
#endif
