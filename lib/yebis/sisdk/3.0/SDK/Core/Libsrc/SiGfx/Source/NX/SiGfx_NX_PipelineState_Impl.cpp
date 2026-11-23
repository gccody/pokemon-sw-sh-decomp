// Scope: common
// SiSDK3::SiGfxNXPipelineState: its construction and destruction, the NVN
// states it makes from its description and the reference counts its header
// defines. (Its small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_PIPELINESTATE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_PipelineState_Impl.h>

#include <nx_middleware/gfx/nvn.h>

// SiGfx's values as NVN's (SiGfx_NX_Utility's, placeholder names: the
// formats, the blend factors and equations, the comparisons, the stencil
// operations, the faces culled, the polygon modes, the vertex formats'
// semantics and sizes, the primitives)
u32 Unk_562ee0(u32 format);              // 0x7100562ee0
u32 Unk_5630e0(u32 factor, bool alpha);  // 0x71005630e0
u32 Unk_563150(u32 equation);            // 0x7100563150
u32 Unk_563160(u32 primitive);           // 0x7100563160
u32 Unk_563190(u32 function);            // 0x7100563190
u32 Unk_5631d0(u32 face);                // 0x71005631d0
u32 Unk_5631f0(u32 function);            // 0x71005631f0
u32 Unk_563220(u32 op);                  // 0x7100563220
u32 Unk_563250(u32 mode);                // 0x7100563250
s32 Unk_563600(u32 semantic);            // 0x7100563600
s32 Unk_4ed0c0(u32 format);              // 0x71004ed0c0

namespace {

// nvn.h declares these without their types
inline void Unk_VertexAttribStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd118)(state);
}
inline void Unk_VertexAttribStateSetFormat(void* state, s32 format, s64 offset) {
    reinterpret_cast<void (*)(void*, s32, s64)>(Unk_27fd120)(state, format, offset);
}
inline void Unk_VertexAttribStateSetStreamIndex(void* state, s32 index) {
    reinterpret_cast<void (*)(void*, s32)>(Unk_27fd128)(state, index);
}
inline void Unk_VertexStreamStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd140)(state);
}
inline void Unk_VertexStreamStateSetStride(void* state, s64 stride) {
    reinterpret_cast<void (*)(void*, s64)>(Unk_27fd148)(state, stride);
}

}  // namespace

namespace SiSDK3 {

// 0x7100553180
// The colour targets' defaults are set twice: by their constructor, as the
// description is constructed (those stores die in the memset, but their
// addresses, computed before it, are what the later stores use: the ten
// `add x21, x19, #0x10c` before the memset), and in this loop, in the same
// order, which decides how their stores are merged.
SiGfxNXPipelineState::SiGfxNXPipelineState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_24(0), field_6c8(0), field_6cc(0), field_6d0(0) {
    memset(&field_28, 0, sizeof(field_28));
    field_28.field_10 = 3;
    field_28.field_14 = 3;
    field_28.field_28 = false;
    field_28.field_2d = false;
    field_28.field_34 = false;
    field_28.field_35 = true;
    field_28.field_30 = 2;
    field_28.field_39 = 0xff;
    field_28.field_3a = 0xff;
    field_28.field_3c = 1;
    field_28.field_40 = 1;
    field_28.field_44 = 1;
    field_28.field_48 = 8;
    field_28.field_4c = 1;
    field_28.field_50 = 1;
    field_28.field_54 = 1;
    field_28.field_58 = 8;
    field_28.field_5c = false;
    field_28.field_5d = false;
    for (s32 i = 0; i < 8; i++) {
        field_28.field_60[i].field_0 = false;
        field_28.field_60[i].field_c = 1;
        field_28.field_60[i].field_4 = 2;
        field_28.field_60[i].field_8 = 1;
        field_28.field_60[i].field_18 = 1;
        field_28.field_60[i].field_10 = 2;
        field_28.field_60[i].field_14 = 1;
        field_28.field_60[i].field_1c[0] = 1;
        field_28.field_60[i].field_1c[1] = 1;
        field_28.field_60[i].field_1c[2] = 1;
        field_28.field_60[i].field_1c[3] = 1;
    }
}

// (The loop over the vertex attributes counts in 32 bits: IndVarSimplify
// widens it, which leaves the copy without the semantic flag no test against
// -1 and a 64-bit compare of the count.)
// NON_MATCHING: two instructions: before the blend loop the original zeroes
// the 32-bit index (`mov w23, wzr`) before the 64-bit offset, this the other
// way round. Tried: the blend loop's index as s32/u32/u64, the blend state
// through a pointer, the colour state's pointer after the channel mask's
// defaults, every single-line move of the function.
// 0x71005536e0
bool SiGfxNXPipelineState::vf9() {
    if (field_24 < 1) {
        return false;
    }
    for (s32 i = 0; i < 8; i++) {
        nvnBlendStateSetDefaults(&field_558[i]);
    }
    for (s32 i = 0; i < 32; i++) {
        Unk_VertexAttribStateSetDefaults(&field_5c8[i]);
    }
    for (s32 i = 0; i < 16; i++) {
        Unk_VertexStreamStateSetDefaults(&field_648[i]);
    }
    nvnPolygonStateSetDefaults(&field_598);
    nvnPolygonStateSetCullFace(&field_598, Unk_5631d0(field_28.field_10));
    nvnPolygonStateSetFrontFace(&field_598, field_28.field_28);
    nvnPolygonStateSetPolygonMode(&field_598, Unk_563250(field_28.field_14));
    nvnPolygonStateSetPolygonOffsetEnables(&field_598, 4);
    nvnMultisampleStateSetDefaults(field_5a8);
    nvnMultisampleStateSetMultisampleEnable(field_5a8, field_28.field_29);
    nvnMultisampleStateSetSamples(field_5a8, field_28.field_24);
    nvnDepthStencilStateSetDefaults(&field_5a0);
    nvnDepthStencilStateSetDepthTestEnable(&field_5a0, field_28.field_34);
    nvnDepthStencilStateSetDepthWriteEnable(&field_5a0, field_28.field_35);
    nvnDepthStencilStateSetDepthFunc(&field_5a0, Unk_563190(field_28.field_30));
    nvnDepthStencilStateSetStencilTestEnable(&field_5a0, field_28.field_38);
    nvnDepthStencilStateSetStencilFunc(&field_5a0, 2, Unk_5631f0(field_28.field_58));
    nvnDepthStencilStateSetStencilOp(&field_5a0, 2, Unk_563220(field_28.field_4c), Unk_563220(field_28.field_50),
                                     Unk_563220(field_28.field_54));
    nvnDepthStencilStateSetStencilFunc(&field_5a0, 1, Unk_5631f0(field_28.field_48));
    nvnDepthStencilStateSetStencilOp(&field_5a0, 1, Unk_563220(field_28.field_3c), Unk_563220(field_28.field_40),
                                     Unk_563220(field_28.field_44));
    u32* color = &field_5c0;
    nvnChannelMaskStateSetDefaults(&field_5c4);
    nvnColorStateSetDefaults(color);
    for (s64 i = 0; i < 8; i++) {
        const Unk_Blend& blend = field_28.field_60[i];
        nvnColorStateSetBlendEnable(color, i, blend.field_0);
        nvnBlendStateSetDefaults(&field_558[i]);
        nvnBlendStateSetBlendTarget(&field_558[i], i);
        nvnBlendStateSetBlendFunc(&field_558[i], Unk_5630e0(blend.field_4, false), Unk_5630e0(blend.field_8, false),
                                  Unk_5630e0(blend.field_10, true), Unk_5630e0(blend.field_14, true));
        nvnBlendStateSetBlendEquation(&field_558[i], Unk_563150(blend.field_c), Unk_563150(blend.field_18));
        nvnChannelMaskStateSetChannelMask(&field_5c4, i, blend.field_1c[0], blend.field_1c[1], blend.field_1c[2],
                                          blend.field_1c[3]);
    }
    s64 strides[16] = {};
    bool bySemantic = field_28.field_52c;
    s32 attributes = 0;
    for (s32 i = 0; i < field_28.field_4e8; i++) {
        const Unk_VertexElement& element = field_28.field_168[i];
        u32 format = Unk_562ee0(element.field_8);
        s32 location;
        if (bySemantic) {
            location = Unk_563600(element.field_0);
            if (location != -1) {
                location += element.field_4;
            }
        } else {
            location = i;
        }
        if (location != -1) {
            attributes = attributes > location + 1 ? attributes : location + 1;
            Unk_VertexAttribStateSetDefaults(&field_5c8[location]);
            Unk_VertexAttribStateSetStreamIndex(&field_5c8[location], element.field_c);
            Unk_VertexAttribStateSetFormat(&field_5c8[location], format, element.field_10);
        }
        strides[element.field_c] += Unk_4ed0c0(element.field_8);
    }
    s32 streams = 0;
    for (s32 i = 0; i < 16; i++) {
        if (strides[i] > 0) {
            if (bySemantic) {
                strides[i] = (strides[i] + 0x3f) & ~static_cast<s64>(0x3f);
            }
            streams++;
        }
    }
    for (s32 i = 0; i < streams; i++) {
        Unk_VertexStreamStateSetDefaults(&field_648[i]);
        Unk_VertexStreamStateSetStride(&field_648[i], strides[i]);
    }
    if (!bySemantic) {
        attributes = field_28.field_4e8;
    }
    u32 primitive = field_28.field_160;
    field_6c8 = attributes;
    field_6cc = streams;
    field_6d0 = primitive - 0x21 < 0x20 ? primitive - 0x20 : 0;
    field_6d4 = Unk_563160(primitive);
    return true;
}

// 0x7100553330 (D2), 0x7100553640 (D0)
SiGfxNXPipelineState::~SiGfxNXPipelineState() {
    Unk_553370(reinterpret_cast<Unk_553370_States*>(this));
}

}  // namespace SiSDK3
