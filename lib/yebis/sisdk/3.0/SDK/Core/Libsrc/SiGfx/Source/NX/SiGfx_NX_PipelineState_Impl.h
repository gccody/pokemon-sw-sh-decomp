// SiSDK3::SiGfxNXPipelineState (RTTI names the class; it derives from
// ISiGfxNXPipelineState, ISiGfxPipelineState and ISiInterface): a pipeline's
// description and the NVN states made from it. Placeholder members; the
// virtual functions are vf<slot>. The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_NX_PIPELINESTATE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

// 0x7100553370 (Unk_553370.cpp, under the name and type it was written with):
// sets the pipeline state's NVN blend, vertex attribute and vertex stream
// states to their defaults
struct Unk_553370_States;
void Unk_553370(Unk_553370_States* self);

namespace SiSDK3 {

class SiGfxNXPipelineState : public Unk_NXInterface {
public:
    SiGfxNXPipelineState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100553180 (not written yet)
    ~SiGfxNXPipelineState() override;                                        // 0x7100553330, 0x7100553640
    u32 vf2() override;                                                      // 0x71005542f0
    u32 vf3() override;                                                      // 0x7100554310
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual bool vf9(const void* desc);  // 0x71005536e0: makes the NVN states (not written yet)
    virtual const u8* vf10();
    virtual const u8* vf11();
    virtual u32 vf12();
    virtual const u8* vf13();
    virtual const u8* vf14();
    virtual const u8* vf15();
    virtual const u8* vf16();
    virtual const u8* vf17();
    virtual const u8* vf18();
    virtual const u8* vf19();
    virtual const u8* vf20();
    virtual u32 vf21();
    virtual u32 vf22();
    virtual u32 vf23();
    virtual u32 vf24();

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    u8 field_28[0x530];  // its description
    u64 field_558[8];    // NVNblendState
    u8 field_598[0x30];
    u32 field_5c8[32];   // NVNvertexAttribState
    u64 field_648[16];   // NVNvertexStreamState
    u32 field_6c8;
    u32 field_6cc;
    u32 field_6d0;
    u32 field_6d4;
};
PKMN_OFFSET_ASSERT(SiGfxNXPipelineState, field_558, 0x558);
PKMN_OFFSET_ASSERT(SiGfxNXPipelineState, field_648, 0x648);
PKMN_SIZE_ASSERT(SiGfxNXPipelineState, 0x6d8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_PIPELINESTATE_IMPL
// 0x71005542f0 (vf2), 0x7100554310 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXPipelineState, field_8.m_pAllocator, field_8.m_count)
#endif
