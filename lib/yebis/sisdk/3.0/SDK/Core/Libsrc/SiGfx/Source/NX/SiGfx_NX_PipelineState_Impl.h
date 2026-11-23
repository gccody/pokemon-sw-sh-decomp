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
    // A colour target's blending in the description (placeholder name and
    // members). Its constructor's order of assignments is the one the
    // pipeline's constructor stores the defaults in again.
    struct Unk_Blend {
        Unk_Blend() {
            field_0 = false;
            field_c = 1;
            field_4 = 2;
            field_8 = 1;
            field_18 = 1;
            field_10 = 2;
            field_14 = 1;
            field_1c[0] = 1;
            field_1c[1] = 1;
            field_1c[2] = 1;
            field_1c[3] = 1;
        }

        bool field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        u32 field_18;
        u8 field_1c[4];  // the channels written
    };
    // A vertex attribute in the description (placeholder name and members).
    struct Unk_VertexElement {
        u32 field_0;  // its semantic
        s32 field_4;  // and its index
        u32 field_8;  // its format
        s32 field_c;  // the stream it is read from
        s32 field_10;  // its offset there
        u8 field_14[8];
    };
    PKMN_SIZE_ASSERT(Unk_VertexElement, 0x1c);
    // What a pipeline is described by (placeholder name and members): 0x530
    // bytes, which the constructor zeroes before it sets the defaults.
    struct Unk_Desc {
        u8 field_0[0x10];
        u32 field_10;  // the faces culled
        u32 field_14;  // the polygon mode
        u8 field_18[0xc];
        u32 field_24;  // the samples
        bool field_28;  // the front face
        bool field_29;  // multisampling
        u8 field_2a[3];
        bool field_2d;
        u32 field_30;   // the depth function
        bool field_34;  // the depth test
        bool field_35;  // the depth writes
        u8 field_36[2];
        bool field_38;  // the stencil test
        u8 field_39;
        u8 field_3a;
        u32 field_3c;
        u32 field_40;
        u32 field_44;
        u32 field_48;
        u32 field_4c;
        u32 field_50;
        u32 field_54;
        u32 field_58;
        bool field_5c;
        bool field_5d;
        Unk_Blend field_60[8];
        u32 field_160;  // what is drawn (as the draw context counts it)
        u8 field_164[4];
        Unk_VertexElement field_168[32];  // the vertex attributes
        s32 field_4e8;                    // how many there are
        u8 field_4ec[0x40];
        bool field_52c;  // the attributes are placed by their semantics
        u8 field_52d[3];
    };
    PKMN_OFFSET_ASSERT(Unk_Desc, field_60, 0x60);
    PKMN_OFFSET_ASSERT(Unk_Desc, field_4e8, 0x4e8);
    PKMN_SIZE_ASSERT(Unk_Desc, 0x530);

    SiGfxNXPipelineState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100553180
    ~SiGfxNXPipelineState() override;                                        // 0x7100553330, 0x7100553640
    u32 vf2() override;                                                      // 0x71005542f0
    u32 vf3() override;                                                      // 0x7100554310
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual bool vf9();  // 0x71005536e0: makes the NVN states
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
    s32 field_24;  // how many descriptions it was given (slot 8)
    Unk_Desc field_28;  // its description
    u64 field_558[8];    // NVNblendState
    u32 field_598;       // NVNpolygonState
    u8 field_59c[4];
    u64 field_5a0;       // NVNdepthStencilState
    u8 field_5a8[0x18];  // NVNmultisampleState
    u32 field_5c0;       // NVNcolorState
    u32 field_5c4;       // NVNchannelMaskState
    u32 field_5c8[32];   // NVNvertexAttribState
    u64 field_648[16];   // NVNvertexStreamState
    s32 field_6c8;  // how many vertex attributes and streams there are
    s32 field_6cc;
    u32 field_6d0;
    u32 field_6d4;
};
PKMN_OFFSET_ASSERT(SiGfxNXPipelineState, field_558, 0x558);
PKMN_OFFSET_ASSERT(SiGfxNXPipelineState, field_5c0, 0x5c0);
PKMN_OFFSET_ASSERT(SiGfxNXPipelineState, field_648, 0x648);
PKMN_SIZE_ASSERT(SiGfxNXPipelineState, 0x6d8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_PIPELINESTATE_IMPL
// 0x71005542f0 (vf2), 0x7100554310 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXPipelineState, field_8.m_pAllocator, field_8.m_count)
#endif
