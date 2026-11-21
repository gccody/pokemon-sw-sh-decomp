// SiSDK3::SiGfxShaderEffectDefinition (RTTI names the class): an effect's
// names and its techniques, read from and written to a stream. Placeholder
// members; the virtual functions are vf<slot>. The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// class's own translation unit (UNK_SIGFX_SHADEREFFECTDEFINITION_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectTechnique_Impl.h>

namespace SiSDK3 {

class ISiIOStream;

// What vf12 and vf13 fill in (placeholder name): a value and a buffer they
// clear first.
struct Unk_570150 {
    u64 field_0;
    u32 field_8;
    s32 field_c;     // the buffer's size
    void* field_10;  // the buffer
};

// What field_c0 is: an object with a reference count (placeholder name).
class Unk_570680 {
public:
    virtual ~Unk_570680();
    virtual u32 vf2();
    virtual u32 vf3();
};

class SiGfxShaderEffectDefinition {
public:
    // 0x710056fd60
    explicit SiGfxShaderEffectDefinition(ISiAllocator* pAllocator);
    virtual ~SiGfxShaderEffectDefinition();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual const u8* vf5();
    virtual const u8* vf6();
    virtual const u8* vf7();
    virtual u32 vf8();
    virtual u32 vf9();                                          // the number of techniques
    virtual SiGfxShaderEffectTechnique* vf10(s32 index);        // a technique
    virtual SiGfxShaderEffectTechnique* vf11(const char* name);  // the technique of a name
    virtual bool vf12(Unk_570150* out, const char* name);
    virtual bool vf13(Unk_570150* out, u32 value);
    virtual bool vf14(ISiIOStream* stream);  // writes it
    virtual bool vf15(ISiIOStream* stream);  // reads it
    virtual void vf16(Unk_570680* object);   // sets field_c0
    virtual u64 vf17();
    virtual u64 vf18();

    // the allocator that made it (inline in every caller: placeholder name;
    // see SiGfxShaderEffectTechnique's)
    ISiAllocator* Unk_Allocator() const { return field_8.m_pAllocator; }

    // 0x7100570530: makes and reads count techniques
    bool Unk_570530(ISiIOStream* stream, s32 count);
    // releases field_c0 and the techniques (inline in its callers:
    // placeholder name)
    void Unk_Release();

    Unk_4bf660 field_8;
    SiString<char> field_18;
    SiString<char> field_48;
    SiString<char> field_78;
    s32 field_a8;
    s32 field_ac;                           // the number of techniques
    SiGfxShaderEffectTechnique* field_b0;   // the techniques
    SiGfxShaderEffectTechnique** field_b8;  // the techniques in the order of their field_48
    Unk_570680* field_c0;
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectDefinition, 0xc8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECTDEFINITION_IMPL
// 0x71005706f0 (vf2), 0x7100570710 (vf3)
#line 35
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffectDefinition, field_8.m_pAllocator, field_8.m_count)
#endif
