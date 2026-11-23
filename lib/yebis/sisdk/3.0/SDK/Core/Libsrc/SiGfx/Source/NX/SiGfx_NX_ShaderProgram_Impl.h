// SiSDK3::SiGfxNXShaderProgram (RTTI names the class; it derives from
// ISiGfxNXShaderProgram, ISiGfxShaderProgram and ISiGfxResource, which is on
// ISiInterface and, at 8, ISiNamedObject): an NVN program, its six shaders
// and its input. Placeholder members; the virtual functions are vf<slot>. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_SHADERPROGRAM_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the shader program's slots 40 to 42.
UNK_NAMED_OBJECT(Unk_NXShaderProgramNamedObject, vf40, vf41, vf42);

// A shader's code as NVN takes it (NVNshaderData: its address and its
// control section).
struct Unk_NXShaderData {
    u64 field_0;
    const void* field_8;
};

// A shader or the shader input, as the program releases it (placeholder
// name).
class Unk_NXProgramPart {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
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
    virtual bool vf20();  // a shader: whether it has its code
    virtual const Unk_NXShaderData* vf21();  // and the code (NVNshaderData)
};

class SiGfxNXShaderProgram : public Unk_NXInterface, public Unk_NXShaderProgramNamedObject {
public:
    // What slot 17 returns (placeholder name).
    struct Unk_Desc {
        Unk_Desc() : field_0(0), field_4(false) {}

        u32 field_0;
        bool field_4;  // whether the program is linked
    };

    SiGfxNXShaderProgram(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100559dc0
    ~SiGfxNXShaderProgram() override;                                        // 0x7100559e70, 0x7100559fb0
    u32 vf2() override;                                                      // 0x710055a9c0
    u32 vf3() override;                                                      // 0x710055a9e0
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
    // 0x710055a2d0: links the program from five shaders
    virtual bool vf18(Unk_NXProgramPart* a1, Unk_NXProgramPart* a2, Unk_NXProgramPart* a3, Unk_NXProgramPart* a4,
                      Unk_NXProgramPart* a5);
    virtual u32 vf19();
    virtual bool vf20(Unk_NXProgramPart* a1);  // 0x710055a760: from the sixth alone
    virtual u32 vf21();
    virtual void vf22();  // 0x710055a7a0: releases the program and its shaders
    virtual bool vf23();
    virtual Unk_NXProgramPart* vf24();
    virtual Unk_NXProgramPart* vf25();
    virtual Unk_NXProgramPart* vf26();
    virtual Unk_NXProgramPart* vf27();
    virtual Unk_NXProgramPart* vf28();
    virtual Unk_NXProgramPart* vf29();
    virtual Unk_NXProgramPart* vf30();
    virtual Unk_NXProgramPart* vf31();
    virtual Unk_NXProgramPart* vf32();
    virtual Unk_NXProgramPart* vf33();
    virtual Unk_NXProgramPart* vf34();
    virtual Unk_NXProgramPart* vf35();
    virtual Unk_NXProgramPart* vf36();
    virtual bool vf37();  // 0x710055aa70
    virtual void* vf38();
    virtual u64 vf39();
    bool vf40(const char* name) override;       // 0x710055a100
    const SiString<char>* vf41() override;      // 0x710055a1e0
    u32 vf42() override;                        // 0x710055a200

    // 0x710055a2e0: links the program
    bool Unk_55a2e0(Unk_NXProgramPart* a1, Unk_NXProgramPart* a2, Unk_NXProgramPart* a3, Unk_NXProgramPart* a4,
                    Unk_NXProgramPart* a5, Unk_NXProgramPart* a6);

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    Unk_Desc field_78;
    Unk_NXProgramPart* field_80;  // the shaders
    Unk_NXProgramPart* field_88;
    Unk_NXProgramPart* field_90;
    Unk_NXProgramPart* field_98;
    Unk_NXProgramPart* field_a0;
    Unk_NXProgramPart* field_a8;
    Unk_NXProgramPart* field_b0;  // the input
    u64 field_b8[0x18];           // NVNprogram
    u32 field_178;                // the stages it has
    s32 field_17c;                // how many
    u32 field_180[6];             // and which

    bool field_198;  // whether the NVN program is made
};
PKMN_OFFSET_ASSERT(SiGfxNXShaderProgram, field_b8, 0xb8);
PKMN_SIZE_ASSERT(SiGfxNXShaderProgram, 0x1a0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_SHADERPROGRAM_IMPL
// 0x710055a9c0 (vf2), 0x710055a9e0 (vf3)
#line 38
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXShaderProgram, field_10.m_pAllocator, field_10.m_count)
#endif
