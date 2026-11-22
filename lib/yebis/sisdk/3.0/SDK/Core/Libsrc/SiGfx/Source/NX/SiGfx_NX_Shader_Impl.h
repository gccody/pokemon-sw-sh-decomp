// SiSDK3::SiGfxNXShader (RTTI names the class; it derives from
// ISiGfxNXShader, ISiGfxShader and ISiGfxResource, which is on ISiInterface
// and, at 8, ISiNamedObject): a shader's code in a memory heap of its own and
// its control data. Placeholder members; the virtual functions are vf<slot>.
// The reference counts, with deferred deletion, are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIGFX_NX_SHADER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the shader's slots 22 to 24.
UNK_NAMED_OBJECT(Unk_NXShaderNamedObject, vf22, vf23, vf24);

class SiGfxNXShader : public Unk_NXInterface, public Unk_NXShaderNamedObject {
public:
    // What slot 17 returns (placeholder name).
    struct Unk_Desc {
        u64 field_0;
        u64 field_8;
    };

    // A compiled shader (placeholder names): a header, then the stages it has
    // code for, each with its control data and its code.
    struct Unk_BinaryEntry {
        u32 field_0;
        u32 field_4;  // where its data is in the binary
        u32 field_8;  // 0: the one slot 18 takes
        u8 field_c[0x24];
        u32 field_30;  // the control data's offset in its data
        u32 field_34;  // the code's
        u32 field_38;  // the code's size
        u32 field_3c;  // the control data's
        u8 field_40[0x50];
    };
    struct Unk_Binary {
        u32 field_0;  // 0x19866891
        u8 field_4[0x48];
        u32 field_4c;  // how many entries it has
        u8 field_50[0x40];
    };

    SiGfxNXShader(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710055ade0
    ~SiGfxNXShader() override;                                        // 0x710055ae80, 0x710055afc0
    u32 vf2() override;                                               // 0x710055b580
    u32 vf3() override;                                               // 0x710055b5a0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual size_t vf7();  // its index in the pool
    virtual const Unk_NXResourceInfo* vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
    virtual const Unk_Desc* vf17();
    virtual bool vf18(const void* desc, const Unk_Binary* binary);  // 0x710055b280: takes a compiled shader
    virtual void vf19();                                    // 0x710055b4d0: releases it
    virtual bool vf20();
    virtual u64 vf21();
    bool vf22(const char* name) override;       // 0x710055b110
    const SiString<char>* vf23() override;      // 0x710055b190
    u32 vf24() override;                        // 0x710055b1b0

    Unk_538d70 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    Unk_Desc field_78;
    u32 field_88;
    u64 field_90;                 // the code's address for the GPU
    void* field_98;               // its control data, once it has code
    SiGfxNXMemoryHeap* field_a0;  // the heap
    void* field_a8;               // the control data
    s64 field_b0;                 // the code's room in the heap
};
PKMN_OFFSET_ASSERT(SiGfxNXShader, field_64, 0x64);
PKMN_OFFSET_ASSERT(SiGfxNXShader, field_90, 0x90);
PKMN_SIZE_ASSERT(SiGfxNXShader::Unk_BinaryEntry, 0x90);
PKMN_SIZE_ASSERT(SiGfxNXShader::Unk_Binary, 0x90);
PKMN_SIZE_ASSERT(SiGfxNXShader, 0xb8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_SHADER_IMPL
// 0x710055b580 (vf2), 0x710055b5a0 (vf3)
#line 37
UNK_REFCOUNT_DEFERRED_DEFINE(SiSDK3::SiGfxNXShader, field_10.m_pAllocator, field_10.m_count, field_10.field_c)
#endif
