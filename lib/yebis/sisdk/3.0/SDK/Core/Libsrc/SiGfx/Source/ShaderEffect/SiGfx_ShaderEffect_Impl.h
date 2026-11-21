// SiSDK3::SiGfxShaderEffect, SiSDK3::SiGfxShaderEffect::CompileRequestCallback, SiSDK3::SiGfxShaderEffect::ShaderProgramMap: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines,
// for the classes' own translation unit (UNK_SIGFX_SHADEREFFECT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxShaderEffect {
public:
    class CompileRequestCallback {
    public:
        virtual ~CompileRequestCallback();
        UNK_REFCOUNT_DECLARE;

        SiSDK3::ISiAllocator* field_8;
        u32 field_10;
    };

    class ShaderProgramMap {
    public:
        virtual ~ShaderProgramMap();
        UNK_REFCOUNT_DECLARE;

        SiSDK3::ISiAllocator* field_8;
        u32 field_10;
    };

    virtual ~SiGfxShaderEffect();
    UNK_REFCOUNT_DECLARE;
    // (the slots up to the one its package calls)
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
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
};

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECT_IMPL
// 0x710056db50 (vf2), 0x710056db70 (vf3)
#line 531
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffect::ShaderProgramMap, field_8, field_10)

// 0x7100579220 (vf2), 0x7100579240 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffect, field_8, field_10)

// 0x7100579330 (vf2), 0x7100579350 (vf3)
#line 626
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffect::CompileRequestCallback, field_8, field_10)
#endif
