// Scope: common
// SiSDK3::SiGfxNXDrawContext: the slots that pass their arguments on to its
// two helpers, its queries' and its command buffer's small functions, and
// the reference counts its header defines. (Its other small accessors are
// lib/yebis/class's; most of its functions aren't written yet.)
#define UNK_SIGFX_NX_DRAWCONTEXT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DrawContext_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandQueue_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_PipelineState_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/Unk_27703d8.h>

#include <math.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c9090: formats a string
void Unk_4c9090(SiSDK3::SiString<char>* self, const char* format, ...);
// 0x71004ed0c0: a format's bytes per pixel
s32 Unk_4ed0c0(u32 format);
// 0x710055d3b0 (leafgen's name and type: a surface's member at 0x108)
struct Unk_55d3b0;
u32 Unk_55d3b0_get(const Unk_55d3b0* self);

// nvn.h declares these two without their types
static inline void Unk_VertexStreamStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd140)(state);
}
static inline void Unk_CommandBufferSetShaderScratchMemory(void* commandBuffer, void* pool, u64 offset, s64 size) {
    reinterpret_cast<void (*)(void*, void*, u64, s64)>(Unk_27fd510)(commandBuffer, pool, offset, size);
}
static inline void Unk_VertexStreamStateSetStride(void* state, s64 stride) {
    reinterpret_cast<void (*)(void*, s64)>(Unk_27fd148)(state, stride);
}
static inline void Unk_VertexAttribStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd118)(state);
}
static inline void Unk_VertexAttribStateSetFormat(void* state, u32 format, s64 offset) {
    reinterpret_cast<void (*)(void*, u32, s64)>(Unk_27fd120)(state, format, offset);
}
static inline void Unk_VertexAttribStateSetStreamIndex(void* state, s32 index) {
    reinterpret_cast<void (*)(void*, s32)>(Unk_27fd128)(state, index);
}

// SiGfx's values as NVN's (Unk_562ee0.cpp)
u32 Unk_562ee0(u32 value);
u32 Unk_5630e0(u32 value, bool flag);
u32 Unk_563150(u32 value);
u32 Unk_563160(u32 value);
u32 Unk_563190(u32 value);
u32 Unk_5631d0(u32 value);
u32 Unk_5631f0(u32 value);
u32 Unk_563220(u32 value);
u32 Unk_563250(u32 value);

namespace SiSDK3 {

// The frames' arrays' release (0x7100542c80) is out of line in every caller
// of the original, the destructors and the reserve: it is instantiated once,
// at the end of this file (clang inlines it everywhere otherwise).
extern template void SiArray<SiGfxNXDrawContext::FrameDirectBufferArray, 16>::Unk_4e3050();

// 0x710053b200
SiGfxNXDrawContext::SiGfxNXDrawContext(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(reinterpret_cast<Unk_NXDrawDevice*>(pDevice)), field_20(0), field_28(nullptr),
      field_2c70(pAllocator), field_3780(pAllocator), field_3a60(nullptr), field_3a68(0), field_3e00(nullptr),
      field_3e08(8), field_3e0c(0) {
    Unk_55ba30(&field_30);
    field_3a70.Unk_53b3f0();
}

// The order of each colour target's assignments decides how their stores are
// merged (the fifth target's first word apart, the last's channels with
// field_160): it is SiGfxNXPipelineState's too (of the orders that keep the
// enable first and the channels last, the only one that gives both).
// 0x710053b3f0
void SiGfxNXDrawContext::Unk_DrawStates::Unk_53b3f0() {
    field_10 = 3;
    field_14 = 3;
    memset(&field_18, 0, sizeof(field_18));
    field_28 = false;
    for (s32 i = 0; i < 4; i++) {
        field_29[i] = 0;
    }
    field_2d = false;
    field_30 = 2;
    field_34 = false;
    field_35 = true;
    field_38 = 0;
    field_39 = 0xff;
    field_3a = 0xff;
    field_3b = 0;
    field_3c = 1;
    field_40 = 1;
    field_44 = 1;
    field_48 = 8;
    field_4c = 1;
    field_50 = 1;
    field_54 = 1;
    field_58 = 8;
    field_5c = false;
    field_5d = false;
    for (s32 i = 0; i < 8; i++) {
        field_60[i].field_0 = false;
        field_60[i].field_c = 1;
        field_60[i].field_4 = 2;
        field_60[i].field_8 = 1;
        field_60[i].field_18 = 1;
        field_60[i].field_10 = 2;
        field_60[i].field_14 = 1;
        field_60[i].field_1c[0] = 1;
        field_60[i].field_1c[1] = 1;
        field_60[i].field_1c[2] = 1;
        field_60[i].field_1c[3] = 1;
    }
    field_160 = 0;
    field_164 = 0;
    field_168 = -1;
    field_16c = 4;
    field_170 = 0;
    field_178[0] = 0;
    field_178[1] = 0;
    field_188_0 = 0xffff;
    field_0 = nullptr;
    field_8 = nullptr;
}

// (The frames' arrays are one member, an array of three: its destructor's
// loop computes the first one's address before it destroys the last.)
// 0x710053b550 (D2), 0x710053b650 (D0); 0x7100542950 is the buffers' delete
SiGfxNXDrawContext::~SiGfxNXDrawContext() {
    if (field_3e00 != nullptr) {
        field_3e00->vf3();
        field_3e00 = nullptr;
    }
    field_3780.Unk_5436d0();
    field_2c70.Unk_546b00();
    Unk_53ba70();
}

// 0x710053b680 (the helpers take the context as their own placeholder
// classes of it)
bool SiGfxNXDrawContext::Unk_53b680(u32 a1, const Unk_53b680_Desc* desc) {
    field_20 = a1;
    Unk_546c60_Desc sampler;
    sampler.field_0 = 0xb;
    sampler.field_4 = 3;
    sampler.field_8 = 3;
    sampler.field_c = 1;
    sampler.field_10 = 0;
    sampler.field_18 = 100.0f;
    sampler.field_1c = 1;
    sampler.field_20 = 8;
    for (int i = 0; i < 7; i++) {
        sampler.field_24[i] = 0;
    }
    field_3e00 = field_18->vf52(&sampler, nullptr, 0, nullptr);
    if (field_3e00 == nullptr) {
        return false;
    }
    if (desc->field_0) {
        field_3780.Unk_5439a0(reinterpret_cast<Unk_544540_Context*>(this));
    }
    if (desc->field_1) {
        field_2c70.Unk_546c60(reinterpret_cast<Unk_PrimitiveContext*>(this));
    }
    Unk_53b750();
    return true;
}

// 0x710053b750
bool SiGfxNXDrawContext::Unk_53b750() {
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    field_3e10[0].Unk_SetCount(field_3e08);
    for (s64 i = 0; i < field_3e08; i++) {
        FrameDirectBufferArray& frame = field_3e10[0].m_pData[i];
        frame.field_0 = pAllocator;
        frame.field_10.Unk_SetAllocator(pAllocator);
    }
    field_3e10[1].Unk_SetCount(field_3e08);
    for (s64 i = 0; i < field_3e08; i++) {
        FrameDirectBufferArray& frame = field_3e10[1].m_pData[i];
        frame.field_0 = pAllocator;
        frame.field_10.Unk_SetAllocator(pAllocator);
    }
    field_3e10[2].Unk_SetCount(field_3e08);
    for (s64 i = 0; i < field_3e08; i++) {
        FrameDirectBufferArray& frame = field_3e10[2].m_pData[i];
        frame.field_0 = pAllocator;
        frame.field_10.Unk_SetAllocator(pAllocator);
    }
    return true;
}

// 0x710053ba70
void SiGfxNXDrawContext::Unk_53ba70() {
    for (s64 i = 0; i < static_cast<s32>(field_3e10[0].m_itemCount); i++) {
        Unk_566a00(field_3e10[0].m_pData[i].field_0, &field_3e10[0].m_pData[i].field_10, false);
    }
    for (s64 i = 0; i < static_cast<s32>(field_3e10[1].m_itemCount); i++) {
        Unk_566a00(field_3e10[1].m_pData[i].field_0, &field_3e10[1].m_pData[i].field_10, false);
    }
    for (s64 i = 0; i < static_cast<s32>(field_3e10[2].m_itemCount); i++) {
        Unk_566a00(field_3e10[2].m_pData[i].field_0, &field_3e10[2].m_pData[i].field_10, false);
    }
}

// The command buffer and the device are reached through references taken
// before the test of the command list: with each branch's own member access,
// GVN's PRE joins the branches' addresses into phis (kept in callee-saved
// registers) where the original reloads both members after the join. The
// draw count is cleared before the frame's index is computed.
// 0x710053bb80
bool SiGfxNXDrawContext::vf8(SiGfxNXCommandList* pCommandList) {
    if (field_28 != nullptr) {
        return false;
    }
    if (pCommandList != nullptr) {
        pCommandList->vf2();
    }
    if (field_28 != nullptr) {
        field_28->vf3();
    }
    field_28 = pCommandList;
    if (pCommandList->field_14c == 0) {
        pCommandList->field_14c = 1;
    }
    void*& buffer = field_3a60;
    Unk_NXDrawDevice*& device = field_18;
    if (pCommandList->vf14()) {
        buffer = field_28->vf15();
    } else {
        field_28->vf17();
        buffer = field_28->vf15();
        nvnCommandBufferBeginRecording(buffer);
        SiGfxNXDevice* pDevice = reinterpret_cast<SiGfxNXDevice*>(device);
        s32 size = pDevice->field_7a8;
        if (size > 0) {
            Unk_CommandBufferSetShaderScratchMemory(buffer, pDevice->field_7a0->vf16(),
                                                    reinterpret_cast<SiGfxNXDevice*>(device)->field_7b0, size);
        }
    }
    Unk_55ba30(&field_30);
    Unk_4fb320_update(reinterpret_cast<const Unk_4fb320*>(device), reinterpret_cast<u64>(buffer));
    field_28->field_124 = SiGfxNXCommandList::Unk_Counts();
    field_3a68 = 0;
    s32 frame = field_3e0c + 1 >= field_3e08 ? 0 : field_3e0c + 1;
    field_3e0c = frame;
    for (s32 i = 0; i < 3; i++) {
        FrameDirectBufferArray& buffers = field_3e10[i][field_3e0c];
        buffers.field_8 = 0;
        if (buffers.field_10.m_itemCount != 0 && buffers.field_10.m_pData[0] != nullptr) {
            buffers.field_10.m_pData[0]->field_10 = 0;
        }
    }
    return true;
}

// 0x710053bda0
bool SiGfxNXDrawContext::vf9() {
    bool result = false;
    if (field_28 != nullptr && field_3a60 != nullptr) {
        if (!field_28->vf14()) {
            field_28->Unk_53a790();
        }
        result = true;
    }
    field_28->field_14c = 0;
    if (result) {
        if (field_28 != nullptr) {
            field_28->vf3();
            field_28 = nullptr;
        }
        field_3a60 = nullptr;
    }
    return result;
}

// NON_MATCHING: the address of the handles (sp + 0x58) is hoisted into a
// callee-saved register (x27) and rematerialised after each loop, where the
// original computes it in the texture loop; the registers of the stage loop
// differ with it (x26/x27), and the vertex buffers' test compares the highest
// slot with the lowest (`cmp w8, w1; b.ge`, the original `cmp w1, w8; b.le`).
// NON_MATCHING: the colours' loop compares the count of targets in 64 bits
// in the original (`ldrsw x8; cmp x8, #2; b.le`), here in 32 (`ldr w8; cmp
// w8, #3; b.lt`): s32, s64 and u32 counters, `!=` and the operands'
// order give the same. In the IR here GVN's PRE makes the original's i64
// phis of the reloaded count (the sign extension carried across the else
// paths) and InstCombine then folds them into i32 phis once the first
// compare is narrowed; the original keeps them, as if the loop had been
// unrolled only after the last GVN (with -unroll-threshold below 235 it isn't
// unrolled at all: no window where only the late unroll fires). Also tried:
// the count in a local, while, nested ifs, `continue`, the colour through a
// pointer or a loop. The stencil's mask is selected the other way round
// (`csel w3, w9, wzr, ne` for `csel w3, wzr, w9, eq`). The rest, the colour
// bit that only moves on for a target not cleared included, is the
// original's.
// 0x710053be40
void SiGfxNXDrawContext::vf11(Unk_NXDrawPass* pPass, const Unk_NXDrawClear* pClear) {
    if (pPass == nullptr || field_30.field_20.field_18 == pPass) {
        return;
    }
    field_30.field_20.field_18 = pPass;
    Unk_NXDrawRenderTarget* pTarget = pPass->field_28;
    if (pTarget == nullptr) {
        return;
    }
    if (field_30.field_20.field_20 != pTarget) {
        field_30.field_20.field_20 = pTarget;
        Unk_NXDrawState& state = field_30.field_508;
        state.field_550 = pTarget->vf36();
        state.field_558 = pTarget->vf37();
        state.field_560 = pTarget->vf38();
        state.field_568 = pTarget->vf39();
        u32 colors = *pTarget->vf35();
        field_30.field_20.field_28 = 1;
        state.field_0 = 1;
        state.field_8 = colors;
        s32 width = pTarget->vf17()->field_0;
        s32 height = pTarget->vf17()->field_4;
        Unk_Viewport& viewport = field_30.field_20.field_2c[0];
        viewport.field_0 = 0.0f;
        viewport.field_4 = 0.0f;
        viewport.field_8 = static_cast<f32>(width);
        viewport.field_c = static_cast<f32>(height);
        viewport.field_10 = 0.0f;
        viewport.field_14 = 1.0f;
        state.field_c[0].field_0 = 0.0f;
        state.field_c[0].field_4 = 0.0f;
        state.field_c[0].field_8 = static_cast<f32>(width);
        state.field_c[0].field_c = static_cast<f32>(height);
        state.field_10c[0].field_0 = 0.0f;
        state.field_10c[0].field_4 = 1.0f;
        field_30.field_20.field_1ac = 1;
        state.field_4 = 1;
        field_30.field_20.field_1b0[0].field_0 = 0;
        field_30.field_20.field_1b0[0].field_8 = 0;
        field_30.field_20.field_1b0[0].field_4 = width;
        field_30.field_20.field_1b0[0].field_c = height;
        state.field_18c[0].field_0 = 0;
        state.field_18c[0].field_4 = 0;
        state.field_18c[0].field_8 = width;
        state.field_18c[0].field_c = height;
        field_30.field_0 |= 7;
    }
    if (pClear == nullptr || pClear->field_88 == 0) {
        return;
    }
    Unk_53c340();
    u32 bit = 0x10;
    for (s64 i = 0; i < 8; i++) {
        f32 color[4];
        color[0] = pClear->field_0[i][0];
        color[1] = pClear->field_0[i][1];
        color[2] = pClear->field_0[i][2];
        color[3] = pClear->field_0[i][3];
        if (i < field_30.field_508.field_8 && (pClear->field_88 & bit)) {
            nvnCommandBufferClearColor(field_3a60, i, color, 0xf);
        } else {
            bit <<= 1;
        }
    }
    bool clear = false;
    u8 depthMask = 0;
    if (pClear->field_88 & 1) {
        depthMask = field_30.field_20.field_20->vf17()->field_18;
        clear = depthMask != 0;
    }
    s32 stencilMask = 0;
    if (pClear->field_88 & 2) {
        bool stencil = field_30.field_20.field_20->vf17()->field_19 != 0;
        stencilMask = stencil ? 0xf : 0;
        clear |= stencil;
    }
    if (clear) {
        nvnCommandBufferClearDepthStencil(field_3a60, pClear->field_80, depthMask, pClear->field_84, stencilMask);
    }
}

// (The storage buffers' slot is declared before its loop, and the vertex
// buffers' count is `last + 1 - first`: each decides the original's block
// order and compares.)
// 0x710053c340
void SiGfxNXDrawContext::Unk_53c340() {
    const void* device = field_18->vf85();
    if (field_3a68 != 0) {
        Unk_53f7d0();
    }
    bool changed = false;
    if (field_30.field_0 != 0) {
        Unk_NXDrawState& state = field_30.field_508;
        if (field_30.field_0 & 1) {
            nvnCommandBufferSetRenderTargets(field_3a60, state.field_8, reinterpret_cast<void* const*>(state.field_550),
                                             reinterpret_cast<void* const*>(state.field_558), state.field_560,
                                             state.field_568);
        }
        if (field_30.field_0 & 2) {
            nvnCommandBufferSetViewports(field_3a60, 0, state.field_0, &state.field_c[0].field_0);
            nvnCommandBufferSetDepthRange(field_3a60, state.field_10c[0].field_0, state.field_10c[0].field_4);
        }
        if (field_30.field_0 & 4) {
            nvnCommandBufferSetScissors(field_3a60, 0, state.field_4, &state.field_18c[0].field_0);
        }
        if (field_30.field_2760.field_4 <= field_30.field_2760.field_8) {
            nvnCommandBufferBindVertexBuffers(field_3a60, field_30.field_2760.field_4,
                                              field_30.field_2760.field_8 + 1 - field_30.field_2760.field_4,
                                              state.field_290);
            field_30.field_2760.Unk_Reset();
        }
        if (field_30.field_0 & 0x1000) {
            nvnCommandBufferBindVertexStreamState(field_3a60, state.field_4ac, state.field_4b0);
        }
        if (field_30.field_0 & 0x800) {
            nvnCommandBufferBindVertexAttribState(field_3a60, state.field_428, state.field_42c);
        }
        if (field_30.field_0 & 0x20) {
            nvnCommandBufferBindPolygonState(field_3a60, &state.field_3f8);
        }
        if (field_30.field_0 & 0x8000) {
            nvnCommandBufferSetPolygonOffsetClamp(field_3a60, state.field_534, state.field_530, state.field_538);
        }
        if (field_30.field_0 & 0x10000) {
            nvnCommandBufferSetDepthClamp(field_3a60, state.field_53c);
        }
        if (field_30.field_0 & 0x40) {
            nvnCommandBufferBindMultisampleState(field_3a60, state.field_408);
        }
        if (field_30.field_0 & 0x80) {
            nvnCommandBufferBindDepthStencilState(field_3a60, &state.field_400);
        }
        if (field_30.field_0 & 0x100) {
            nvnCommandBufferBindBlendState(field_3a60, state.field_3b8);
            nvnCommandBufferSetBlendColor(field_3a60, state.field_3a4);
        }
        if (field_30.field_0 & 0x200) {
            nvnCommandBufferBindColorState(field_3a60, &state.field_420);
        }
        if (field_30.field_0 & 0x400) {
            nvnCommandBufferBindChannelMaskState(field_3a60, &state.field_424);
        }
        if (field_30.field_0 & 0x2000) {
            if (state.field_548 != 0) {
                nvnCommandBufferBindProgram(field_3a60, state.field_540, state.field_548);
            }
            changed = true;
        }
    }
    u64 handles[64];
    Unk_SlotRange textures(64);
    for (s32 i = 0; i < field_30.field_4; i++) {
        u32 stage = field_30.field_8[i];
        Unk_SlotRange& uniforms = field_30.field_2778[stage];
        if (uniforms.field_4 <= uniforms.field_8) {
            for (s32 slot = uniforms.field_4; slot <= uniforms.field_8; slot++) {
                if (uniforms.field_10 & static_cast<u64>(1) << slot) {
                    nvnCommandBufferBindUniformBuffer(field_3a60, stage, slot, field_30.field_508.field_570[stage][slot],
                                                      field_30.field_508.field_810[stage][slot]);
                    changed = true;
                }
            }
            uniforms.Unk_Reset();
        }
        Unk_SlotRange& storages = field_30.field_2898[stage];
        if (storages.field_4 <= storages.field_8) {
            s32 slot;
            for (slot = storages.field_4; slot <= storages.field_8; slot++) {
                if (storages.field_10 & static_cast<u64>(1) << slot) {
                    nvnCommandBufferBindStorageBuffer(field_3a60, stage, slot, field_30.field_508.field_960[stage][slot],
                                                      field_30.field_508.field_c00[stage][slot]);
                }
            }
            storages.Unk_Reset();
        }
        Unk_53fe70(device, &field_30.field_2808[stage], &field_30.field_29b8, handles, &textures);
        if (textures.field_4 <= textures.field_8) {
            for (s32 slot = textures.field_4; slot <= textures.field_8; slot++) {
                if (textures.field_10 & static_cast<u64>(1) << slot) {
                    nvnCommandBufferBindTexture(field_3a60, stage, field_30.field_508.field_1c50[stage][slot], handles[slot]);
                }
            }
            textures.Unk_Reset();
        }
        Unk_SlotRange& images = field_30.field_2928[stage];
        if (images.field_4 <= images.field_8) {
            for (s32 slot = images.field_4; slot <= images.field_8; slot++) {
                if (images.field_10 & static_cast<u64>(1) << slot) {
                    nvnCommandBufferBindImage(field_3a60, stage, slot, field_30.field_508.field_1050[stage][slot]);
                }
            }
            images.Unk_Reset();
        }
    }
    u32 barriers = field_30.field_508.field_2250[0];
    u32 flags = field_30.field_0;
    if (changed) {
        flags |= 0x20000;
        barriers |= 0x20;
        field_30.field_0 = flags;
    }
    if (barriers != 0 && (flags & 0x20000)) {
        nvnCommandBufferBarrier(field_3a60, barriers);
        field_30.field_508.field_2250[0] = 0;
    }
    field_30.field_0 = 0;
}

// 0x710053c9c0
void SiGfxNXDrawContext::vf12() {
    Unk_53c340();
    field_30.field_20.field_18 = nullptr;
}

// 0x710053c9f0
void SiGfxNXDrawContext::vf14(s32 count, const Unk_Viewport* viewports) {
    if (count < 0 || count > 15) {
        return;
    }
    field_30.field_20.field_28 = count;
    field_30.field_508.field_0 = count;
    for (s32 i = 0; i < count; i++) {
        field_30.field_508.field_c[i].field_0 = viewports[i].field_0;
        field_30.field_508.field_c[i].field_4 = viewports[i].field_4;
        field_30.field_508.field_c[i].field_8 = viewports[i].field_8;
        field_30.field_508.field_c[i].field_c = viewports[i].field_c;
        field_30.field_508.field_10c[i].field_0 = viewports[i].field_10;
        field_30.field_508.field_10c[i].field_4 = viewports[i].field_14;
    }
    field_30.field_0 |= 2;
}

// NON_MATCHING: the same instructions with the loop's two pointers in each
// other's registers (the original has the scissors' in x10 and the
// rectangles' in x11). Tried: references to both in either order, pointers
// stepped by the loop, a local rectangle assigned, the sizes first, s64/u32
// counters, the rectangle's four stores or the whole loop in a static inline
// helper (either parameter order, references or pointers).
// 0x710053ca70
void SiGfxNXDrawContext::vf15(s32 count, const Unk_Scissor* scissors) {
    if (count < 0 || count > 15) {
        return;
    }
    field_30.field_20.field_1ac = count;
    field_30.field_508.field_4 = count;
    for (s32 i = 0; i < count; i++) {
        field_30.field_508.field_18c[i].field_0 = scissors[i].field_0;
        field_30.field_508.field_18c[i].field_4 = scissors[i].field_8;
        field_30.field_508.field_18c[i].field_8 = scissors[i].field_4 - scissors[i].field_0;
        field_30.field_508.field_18c[i].field_c = scissors[i].field_c - scissors[i].field_8;
    }
    field_30.field_0 |= 4;
}

// 0x710053cae0
void SiGfxNXDrawContext::vf16(SiGfxNXPipelineState* pState) {
    if (pState == nullptr) {
        return;
    }
    field_30.field_20.field_0 = pState;
    field_30.field_20.field_3bc = pState->field_28.field_160;
    Unk_NXDrawState& state = field_30.field_508;
    state.field_3a0 = pState->vf24();
    const Unk_NXDrawPipelineDesc* desc = reinterpret_cast<const Unk_NXDrawPipelineDesc*>(pState->vf10());
    if (memcmp(&state.field_3f8, &pState->field_598, sizeof(state.field_3f8)) != 0) {
        memcpy(&state.field_3f8, &pState->field_598, sizeof(state.field_3f8));
        field_30.field_0 |= 0x20;
    }
    if (state.field_530 != desc->field_18 || state.field_534 != desc->field_20 || state.field_538 != desc->field_1c) {
        state.field_530 = desc->field_18;
        state.field_534 = desc->field_20;
        state.field_538 = desc->field_1c;
        field_30.field_0 |= 0x8000;
    }
    if (memcmp(state.field_408, pState->field_5a8, sizeof(state.field_408)) != 0) {
        memcpy(state.field_408, pState->field_5a8, sizeof(state.field_408));
        field_30.field_0 |= 0x40;
    }
    if (state.field_53c != desc->field_2c) {
        state.field_53c = desc->field_2c;
        field_30.field_0 |= 0x10000;
    }
    if (memcmp(state.field_3b8, pState->field_558, sizeof(state.field_3b8)) != 0) {
        memcpy(state.field_3b8, pState->field_558, sizeof(state.field_3b8));
        field_30.field_0 |= 0x100;
    }
    if (memcmp(&state.field_420, &pState->field_5c0, sizeof(state.field_420)) != 0) {
        memcpy(&state.field_420, &pState->field_5c0, sizeof(state.field_420));
        field_30.field_0 |= 0x200;
    }
    if (memcmp(&state.field_424, &pState->field_5c4, sizeof(state.field_424)) != 0) {
        memcpy(&state.field_424, &pState->field_5c4, sizeof(state.field_424));
        field_30.field_0 |= 0x400;
    }
    if (memcmp(&state.field_400, &pState->field_5a0, sizeof(state.field_400)) != 0) {
        memcpy(&state.field_400, &pState->field_5a0, sizeof(state.field_400));
        field_30.field_0 |= 0x80;
    }
    if (state.field_428 != pState->field_6c8 ||
        memcmp(state.field_42c, pState->field_5c8, state.field_428 * sizeof(u32)) != 0) {
        state.field_428 = pState->field_6c8;
        memcpy(state.field_42c, pState->field_5c8, pState->field_6c8 * sizeof(u32));
        field_30.field_0 |= 0x800;
    }
    if (state.field_4ac != pState->field_6cc ||
        memcmp(state.field_4b0, pState->field_648, state.field_4ac * sizeof(u64)) != 0) {
        state.field_4ac = pState->field_6cc;
        memcpy(state.field_4b0, pState->field_648, pState->field_6cc * sizeof(u64));
        field_30.field_0 |= 0x1000;
    }
    // (the original calls slot 23 here, its result unused)
    pState->vf23();
    if (state.field_3a0 != pState->field_6d4) {
        state.field_3a0 = pState->field_6d4;
        field_30.field_0 |= 0x10;
    }
    Unk_NXDrawProgram* program = reinterpret_cast<const Unk_NXDrawPipelineDesc*>(pState->vf10())->field_8;
    void* nvnProgram = nullptr;
    s32 stages = 0;
    if (program != nullptr) {
        nvnProgram = program->field_b8;
        stages = program->field_178;
    }
    if (state.field_540 != nvnProgram) {
        state.field_540 = nvnProgram;
        state.field_548 = stages;
        if (nvnProgram != nullptr) {
            s32 count = program->field_17c;
            field_30.field_4 = count;
            memcpy(field_30.field_8, program->field_180, count * sizeof(u32));
        }
        field_30.field_0 |= 0x2000;
    }
}

// 0x7100540750
void SiGfxNXDrawContext::vf34() {
    Unk_55ba30(&field_30);
}

// 0x7100540630
bool SiGfxNXDrawContext::vf35(u32 mode) {
    return field_2c70.Unk_5472d0(mode);
}

// 0x7100540640
bool SiGfxNXDrawContext::vf36() {
    return field_2c70.Unk_5474b0();
}

// 0x7100540650
bool SiGfxNXDrawContext::vf37() {
    return field_2c70.Unk_547760();
}

// 0x7100540660
bool SiGfxNXDrawContext::vf38(s32 count, const u8* pVertices) {
    return field_2c70.Unk_547810(count, pVertices);
}

// 0x7100540670
bool SiGfxNXDrawContext::vf39(const void* pVertex) {
    return field_2c70.Unk_5478f0(pVertex);
}

// 0x7100540680
bool SiGfxNXDrawContext::vf40(u32 row, s32 column, f32 x, f32 y, f32 z, f32 w) {
    return field_2c70.Unk_547930(row, column, x, y, z, w);
}

// 0x7100540690
bool SiGfxNXDrawContext::vf41(u32 row, s32 column, const f32* pValues) {
    return field_2c70.Unk_547a40(row, column, pValues);
}

// 0x71005406a0
bool SiGfxNXDrawContext::vf42(u32 row, s32 column, const f32* pValues) {
    return field_2c70.Unk_547b60(row, column, pValues);
}

// 0x71005406b0
bool SiGfxNXDrawContext::vf43(u32 row, s32 column, const f32* pValues) {
    return field_2c70.Unk_547ca0(row, column, pValues);
}

// 0x71005406c0
bool SiGfxNXDrawContext::vf44(u32 row, s32 column, u8 r, u8 g, u8 b, u8 a) {
    return field_2c70.Unk_547df0(row, column, r, g, b, a);
}

// 0x71005406d0
bool SiGfxNXDrawContext::vf45(u32 row, s32 column, const u8* pValues) {
    return field_2c70.Unk_547f50(row, column, pValues);
}

// 0x71005406e0
bool SiGfxNXDrawContext::vf46(u32 row, s32 column, const u8* pValues) {
    return field_2c70.Unk_5480c0(row, column, pValues);
}

// 0x71005406f0
bool SiGfxNXDrawContext::vf47(u32 row, s32 column, const f32* pValues) {
    return field_2c70.Unk_548230(row, column, pValues);
}

// 0x7100540700
bool SiGfxNXDrawContext::vf48(u32 row, s32 column, const u8* pValues) {
    return field_2c70.Unk_548380(row, column, pValues);
}

// 0x7100540710
bool SiGfxNXDrawContext::vf49(u32 row, s32 column, const f32* pValues) {
    return field_2c70.Unk_5484f0(row, column, pValues);
}

// 0x710053ce30
void SiGfxNXDrawContext::vf17(SiGfxNXRootSignature* pSignature) {
    if (pSignature == nullptr) {
        return;
    }
    if (field_20 == 1) {
        field_30.field_20.field_8 = pSignature;
        for (s32 i = 0; i < static_cast<s32>(pSignature->vf17()); i++) {
            if (pSignature->vf21(i) != nullptr) {
                Unk_BindTexture(i, pSignature->vf21(i));
            }
        }
    } else if (field_20 == 2) {
        field_30.field_20.field_10 = pSignature;
    }
}

// NON_MATCHING: in the copy of the loop for given strides the induction
// pointers of the strides and of the NVN vertex buffers are created in the
// other order (x25/x26 exchanged), and the size and stride exchange w8/w9;
// the copy for the buffers' own strides is the original's but for the order
// of the flag's `orr` and the last store (37 lines). The slot computed at the
// loop's top and the buffer's range built before the test decided most of it.
// 0x710053cfc0
void SiGfxNXDrawContext::vf19(s32 first, s32 count, ISiGfxResource** ppBuffers, const s32* strides,
                              const s32* offsets) {
    if (first < 0 || first + count > 15) {
        return;
    }
    bool update = false;
    for (s32 i = 0; i < count; i++) {
        s32 slot = first + i;
        ISiGfxResource* pResource = ppBuffers[i];
        u64 address = 0;
        s32 size = 0;
        s32 stride = 0;
        if (pResource != nullptr) {
            Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pResource);
            address = pBuffer->vf27();
            size = pBuffer->vf17()->field_4;
            if (strides == nullptr) {
                stride = pBuffer->vf17()->field_8;
            }
        }
        if (strides != nullptr) {
            stride = strides[i];
        }
        s32 offset = offsets != nullptr ? offsets[i] : 0;
        Unk_VertexBuffer vb = {address + offset, static_cast<u64>(static_cast<s64>(size))};
        if (field_30.field_20.field_2b0[slot] == pResource && field_30.field_20.field_370[slot] == offset &&
            field_30.field_20.field_330[slot] == stride) {
            continue;
        }
        update = field_30.field_20.field_330[slot] != stride || (stride & 0x3f) != 0;
        field_30.field_20.field_2b0[slot] = pResource;
        field_30.field_20.field_370[slot] = offset;
        field_30.field_20.field_330[slot] = stride;
        field_30.field_508.field_290[slot] = vb;
        if (update) {
            Unk_VertexStreamStateSetDefaults(&field_30.field_508.field_4b0[slot]);
            Unk_VertexStreamStateSetStride(&field_30.field_508.field_4b0[slot], stride);
        }
        field_30.field_2760.Unk_MarkOr(slot);
    }
    if (!update) {
        return;
    }
    field_30.field_508.field_4ac = 0;
    for (s32 i = 0; i < 16; i++) {
        if (field_30.field_508.field_290[i].field_0 != 0) {
            field_30.field_508.field_4ac++;
        }
    }
    field_30.field_0 |= 0x1000;
}

// 0x710053d490
void SiGfxNXDrawContext::vf20(Unk_NXDrawIndirect* pBuffer, s32 offset) {
    s32 size = 0;
    s32 type = 0;
    u64 address = 0;
    if (pBuffer != nullptr) {
        address = pBuffer->vf27();
        type = pBuffer->vf28();
        switch (type) {
        case 0:
            size = 1;
            break;
        case 2:
            size = 4;
            break;
        case 1:
            size = 2;
            break;
        default:
            size = 0;
            break;
        }
    }
    address += offset;
    if (field_30.field_20.field_3b0 != pBuffer || field_30.field_508.field_398 != type || field_30.field_508.field_390 != address || field_30.field_508.field_39c != size) {
        field_30.field_20.field_3b0 = pBuffer;
        field_30.field_508.field_398 = type;
        field_30.field_508.field_390 = address;
        field_30.field_508.field_39c = size;
    }
    field_30.field_0 |= 8;
}

// 0x710053d5c0
void SiGfxNXDrawContext::vf21(const Unk_Color* color) {
    if (field_30.field_20.field_3c4.field_0 == color->field_0 && field_30.field_20.field_3c4.field_4 == color->field_4 &&
        field_30.field_20.field_3c4.field_8 == color->field_8 && field_30.field_20.field_3c4.field_c == color->field_c) {
        return;
    }
    field_30.field_20.field_3c4 = *color;
    field_30.field_508.field_3a4[0] = color->field_0;
    field_30.field_508.field_3a4[1] = color->field_4;
    field_30.field_508.field_3a4[2] = color->field_8;
    field_30.field_508.field_3a4[3] = color->field_c;
}

// 0x710053d660
void SiGfxNXDrawContext::vf23(SiGfxNXDescriptorSet* pSet) {
    if (pSet == nullptr) {
        return;
    }
    bool changed = field_30.field_20.field_3d8 != pSet || field_30.field_20.field_3e0 != pSet->vf18();
    if (!changed) {
        for (size_t i = 0; i < pSet->field_28.m_itemCount; i++) {
            SiGfxNXDescriptorSet::ParameterEntry& entry = pSet->field_28.m_pData[i];
            if (entry.field_0 == 4 && entry.field_20 != 0) {
                if (field_30.field_20.field_3e8[i] != reinterpret_cast<SiGfxNXDescriptorTable*>(entry.field_20)->vf31()) {
                    changed = true;
                    break;
                }
            }
        }
        if (!changed) {
            return;
        }
    }
    field_30.field_20.field_3d8 = pSet;
    field_30.field_20.field_3e0 = pSet->vf18();
    for (size_t i = 0; i < pSet->field_28.m_itemCount; i++) {
        if (pSet->field_28.m_pData[i].field_10) {
            continue;
        }
        SiGfxNXDescriptorSet::ParameterEntry& entry = pSet->field_28.m_pData[i];
        switch (entry.field_0) {
        case 1:
            Unk_53d8a0(entry.field_4, reinterpret_cast<ISiGfxResource*>(entry.field_18), entry.field_8, entry.field_c);
            break;
        case 2:
            Unk_53da20(entry.field_4, reinterpret_cast<ISiGfxResource*>(entry.field_18));
            break;
        case 3: {
            s32 index = entry.field_4;
            ISiGfxResource* pResource = reinterpret_cast<ISiGfxResource*>(entry.field_18);
            SiGfxNXRootSignature* pSignature;
            if (field_20 == 1) {
                pSignature = field_30.field_20.field_8;
            } else if (field_20 == 2) {
                pSignature = field_30.field_20.field_10;
            } else {
                break;
            }
            if (index < 0 || pSignature == nullptr || index >= static_cast<s32>(pSignature->field_28.m_itemCount)) {
                break;
            }
            SiGfxNXRootSignature::RootParameterEntry& parameter = pSignature->field_28.m_pData[index];
            if (parameter.field_0 != 3) {
                break;
            }
            s32 slot = parameter.field_8;
            if (static_cast<u32>(slot) > 13) {
                break;
            }
            Unk_53ee60(pResource, pSignature->field_300[slot].field_0, slot);
            break;
        }
        case 4:
            if (entry.field_20 != 0) {
                Unk_53e0c0(entry.field_4, reinterpret_cast<SiGfxNXDescriptorTable*>(entry.field_20));
                field_30.field_20.field_3e8[i] = reinterpret_cast<SiGfxNXDescriptorTable*>(entry.field_20)->vf31();
            }
            break;
        }
    }
    Unk_53ed20(pSet);
}

// The stages' bits, in the order of the states' tables (placeholder name):
// the last entries are zero.
static const u32 Unk_StageBits[33] = {1, 2, 4, 16, 8, 32};

// NON_MATCHING: the loop's invariants are hoisted in another order (the
// sizes' address before the bit in the original), so the registers of the
// loop's four pointers differ.
// 0x710053d8a0
void SiGfxNXDrawContext::Unk_53d8a0(s32 index, ISiGfxResource* pResource, s32 offset, s32 size) {
    SiGfxNXRootSignature* pSignature;
    if (field_20 == 1) {
        pSignature = field_30.field_20.field_8;
    } else if (field_20 == 2) {
        pSignature = field_30.field_20.field_10;
    } else {
        return;
    }
    if (index < 0 || pSignature == nullptr || index >= static_cast<s32>(pSignature->field_28.m_itemCount)) {
        return;
    }
    SiGfxNXRootSignature::RootParameterEntry& parameter = pSignature->field_28.m_pData[index];
    if (parameter.field_0 != 2) {
        return;
    }
    s32 slot = parameter.field_8;
    if (pResource == nullptr) {
        return;
    }
    if (static_cast<u32>(slot) > 13) {
        return;
    }
    if (pResource->vf8()->field_0 != 10) {
        return;
    }
    Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pResource);
    s32 bufferSize = pBuffer->field_bc;
    u64 base = pBuffer->field_100;
    s32 bytes = size < 1 ? bufferSize : size;
    if (base == 0) {
        return;
    }
    u64 address = base + (pBuffer->field_154 * bufferSize + offset);
    u32 stages = pSignature->field_2c8[slot].field_0;
    for (s32 i = 0; i < 33; i++) {
        if ((Unk_StageBits[i] & stages) == 0) {
            continue;
        }
        if (field_30.field_508.field_570[i][slot] == address) {
            continue;
        }
        field_30.field_508.field_570[i][slot] = address;
        field_30.field_508.field_810[i][slot] = bytes;
        field_30.field_2778[i].Unk_Mark(slot);
    }
}

// NON_MATCHING: the slot and its sign-extended copy (w22, x23) are used the
// other way round in some of the ranges' compares, and one merged block (the
// stages 3 and 4 of the images) schedules its loads differently. (The
// buffers' ranges are marked with `Unk_MarkOr`, which took it from 72 lines
// to 48; a search over the six mark helpers at every call finds nothing
// better.)
// 0x710053da20
void SiGfxNXDrawContext::Unk_53da20(s32 index, ISiGfxResource* pResource) {
    SiGfxNXRootSignature* pSignature;
    if (field_20 == 1) {
        pSignature = field_30.field_20.field_8;
    } else if (field_20 == 2) {
        pSignature = field_30.field_20.field_10;
    } else {
        return;
    }
    if (index < 0 || pSignature == nullptr || index >= static_cast<s32>(pSignature->field_28.m_itemCount)) {
        return;
    }
    SiGfxNXRootSignature::RootParameterEntry& parameter = pSignature->field_28.m_pData[index];
    if (parameter.field_0 != 1) {
        return;
    }
    s32 slot = parameter.field_8;
    if (static_cast<u32>(slot) > 63) {
        return;
    }
    u32 stages = parameter.field_4;
    if (pResource == nullptr) {
        return;
    }
    if (pResource->vf8()->field_0 == 1) {
        Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pResource);
        u32 number = pTexture->vf43();
        Unk_NXRootSampler* pSampler = pTexture->vf33();
        s32 sampler = pSampler != nullptr ? static_cast<s32>(pSampler->vf19()) : -1;
        if (number != field_30.field_508.field_d50[slot]) {
            field_30.field_508.field_d50[slot] = number;
            if (sampler != -1) {
                field_30.field_508.field_e50[slot] = sampler;
                field_30.field_29b8.Unk_MarkRead(slot);
            }
            if (stages & 1) {
                field_30.field_2808[0].Unk_MarkRead(slot);
            }
            if (stages & 2) {
                field_30.field_2808[1].Unk_MarkRead(slot);
            }
            if (stages & 4) {
                field_30.field_2808[2].Unk_MarkRead(slot);
            }
            if (stages & 16) {
                field_30.field_2808[3].Unk_MarkRead(slot);
            }
            if (stages & 16) {
                field_30.field_2808[4].Unk_MarkRead(slot);
            }
            if (stages & 32) {
                field_30.field_2808[5].Unk_MarkRead(slot);
            }
        }
    }
    if (pResource->vf8()->field_0 == 10) {
        Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pResource);
        if ((pResource->vf8()->field_8 & 0x10000) == 0) {
            u64 base = pBuffer->field_100;
            s64 bytes = pBuffer->field_bc;
            u64 address = base + pBuffer->field_154 * bytes;
            if (stages & 1) {
                field_30.field_2898[0].Unk_MarkOr(slot);
                field_30.field_508.field_960[0][slot] = address;
                field_30.field_508.field_c00[0][slot] = bytes;
            }
            if (stages & 2) {
                field_30.field_2898[1].Unk_MarkOr(slot);
                field_30.field_508.field_960[1][slot] = address;
                field_30.field_508.field_c00[1][slot] = bytes;
            }
            if (stages & 4) {
                field_30.field_2898[2].Unk_MarkOr(slot);
                field_30.field_508.field_960[2][slot] = address;
                field_30.field_508.field_c00[2][slot] = bytes;
            }
            if (stages & 16) {
                field_30.field_2898[3].Unk_MarkOr(slot);
                field_30.field_508.field_960[3][slot] = address;
                field_30.field_508.field_c00[3][slot] = bytes;
            }
            if (stages & 8) {
                field_30.field_2898[4].Unk_MarkOr(slot);
                field_30.field_508.field_960[4][slot] = address;
                field_30.field_508.field_c00[4][slot] = bytes;
            }
            if (stages & 32) {
                field_30.field_2898[5].Unk_MarkOr(slot);
                field_30.field_508.field_960[5][slot] = address;
                field_30.field_508.field_c00[5][slot] = bytes;
            }
        } else {
            u64 handle = pBuffer->vf29();
            if (stages & 1) {
                field_30.field_2928[0].Unk_MarkRead(slot);
                field_30.field_508.field_1050[0][slot] = handle;
            }
            if (stages & 2) {
                field_30.field_2928[1].Unk_MarkRead(slot);
                field_30.field_508.field_1050[1][slot] = handle;
            }
            if (stages & 4) {
                field_30.field_2928[2].Unk_MarkRead(slot);
                field_30.field_508.field_1050[2][slot] = handle;
            }
            if (stages & 16) {
                field_30.field_2928[3].Unk_MarkRead(slot);
                field_30.field_508.field_1050[3][slot] = handle;
            }
            if (stages & 8) {
                field_30.field_2928[4].Unk_MarkRead(slot);
                field_30.field_508.field_1050[4][slot] = handle;
            }
            if (stages & 32) {
                field_30.field_2928[5].Unk_MarkRead(slot);
                field_30.field_508.field_1050[5][slot] = handle;
            }
        }
    }
}

// A sampler as a descriptor table holds it (placeholder name: a
// SiGfxNXSampler, of kind 12): slot 19 is its hash.
class Unk_NXTableSampler : public ISiGfxResource {
public:
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
    virtual u32 vf19();
};

// NON_MATCHING: the cases, their loops (the 32-bit slot widened by
// IndVarSimplify into the ranges' 64-bit compares) and the ranges' repeat
// count are the original's; the table's null test is hoisted above the
// signature's count here, and the registers differ (the original keeps the
// ranges and both a range's base and count in callee-saved registers, here
// they are spilled).
// 0x710053e0c0
void SiGfxNXDrawContext::Unk_53e0c0(s32 index, SiGfxNXDescriptorTable* pTable) {
    SiGfxNXRootSignature* pSignature;
    if (field_20 == 1) {
        pSignature = field_30.field_20.field_8;
    } else if (field_20 == 2) {
        pSignature = field_30.field_20.field_10;
    } else {
        return;
    }
    if (index < 0 || pSignature == nullptr || index >= static_cast<s32>(pSignature->field_28.m_itemCount) ||
        pTable == nullptr) {
        return;
    }
    SiGfxNXRootSignature::RootParameterEntry& parameter = pSignature->field_28.m_pData[index];
    if (parameter.field_0 != 5) {
        return;
    }
    SiGfxNXRootSignature::Unk_Ranges* pRanges = parameter.field_20;
    s32 textures = 0;
    s32 buffers = 0;
    s32 images = 0;
    s32 samplers = 0;
    for (s32 i = 0; i < static_cast<s32>(pRanges->field_8.m_itemCount); i++) {
        SiGfxNXRootSignature::DescriptorRangeEntry& range = pRanges->field_8.m_pData[i];
        s32 base = range.field_4;
        s32 count = range.field_c;
        switch (range.field_0) {
        case 1:
            if (base < 0 || count + base > 63) {
                return;
            }
            for (s32 j = 0; j < count; j++) {
                if (textures + j >= static_cast<s32>(pTable->field_88.field_8.m_itemCount)) {
                    break;
                }
                Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pTable->field_88.field_8.m_pData[textures + j]);
                if (pTexture == nullptr) {
                    continue;
                }
                u32 stages = parameter.field_4;
                s32 slot = base + j;
                if (pTexture->vf8()->field_0 == 1) {
                    u32 number = pTexture->vf43();
                    Unk_NXRootSampler* pSampler = pTexture->vf33();
                    s32 sampler = pSampler != nullptr ? static_cast<s32>(pSampler->vf19()) : -1;
                    if (number != field_30.field_508.field_d50[slot]) {
                        field_30.field_2a08[slot] = stages;
                        field_30.field_508.field_d50[slot] = number;
                        if (sampler != -1) {
                            field_30.field_508.field_e50[slot] = sampler;
                            field_30.field_29b8.Unk_MarkRead(slot);
                        }
                        if (stages & 1) {
                            field_30.field_2808[0].Unk_MarkRead(slot);
                        }
                        if (stages & 2) {
                            field_30.field_2808[1].Unk_MarkRead(slot);
                        }
                        if (stages & 4) {
                            field_30.field_2808[2].Unk_MarkRead(slot);
                        }
                        if (stages & 16) {
                            field_30.field_2808[3].Unk_MarkRead(slot);
                        }
                        if (stages & 16) {
                            field_30.field_2808[4].Unk_MarkRead(slot);
                        }
                        if (stages & 32) {
                            field_30.field_2808[5].Unk_MarkRead(slot);
                        }
                    }
                }
                if (pTexture->vf8()->field_0 == 10) {
                    u64 address = pTexture->field_100 + pTexture->field_154 * static_cast<s64>(pTexture->field_bc);
                    s32 bytes = pTexture->field_bc;
                    if (stages & 1) {
                        field_30.field_2898[0].Unk_MarkRead(slot);
                        field_30.field_508.field_960[0][slot] = address;
                        field_30.field_508.field_c00[0][slot] = bytes;
                    }
                    if (stages & 2) {
                        field_30.field_2898[1].Unk_MarkRead(slot);
                        field_30.field_508.field_960[1][slot] = address;
                        field_30.field_508.field_c00[1][slot] = bytes;
                    }
                    if (stages & 4) {
                        field_30.field_2898[2].Unk_MarkRead(slot);
                        field_30.field_508.field_960[2][slot] = address;
                        field_30.field_508.field_c00[2][slot] = bytes;
                    }
                    if (stages & 16) {
                        field_30.field_2898[3].Unk_MarkRead(slot);
                        field_30.field_508.field_960[3][slot] = address;
                        field_30.field_508.field_c00[3][slot] = bytes;
                    }
                    if (stages & 16) {
                        field_30.field_2898[4].Unk_MarkRead(slot);
                        field_30.field_508.field_960[4][slot] = address;
                        field_30.field_508.field_c00[4][slot] = bytes;
                    }
                    if (stages & 32) {
                        field_30.field_2898[5].Unk_MarkRead(slot);
                        field_30.field_508.field_960[5][slot] = address;
                        field_30.field_508.field_c00[5][slot] = bytes;
                    }
                }
            }
            textures += count;
            break;
        case 2:
            if (base < 0 || count + base > 13) {
                return;
            }
            for (s32 j = 0; j < count; j++) {
                if (buffers + j >= static_cast<s32>(pTable->field_30.field_8.m_itemCount)) {
                    break;
                }
                Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pTable->field_30.field_8.m_pData[buffers + j]);
                if (pBuffer == nullptr) {
                    continue;
                }
                u32 stages = parameter.field_4;
                s32 slot = base + j;
                if (pBuffer->vf8()->field_0 != 10) {
                    continue;
                }
                u64 address = pBuffer->field_100 + pBuffer->field_154 * static_cast<s64>(pBuffer->field_bc);
                s32 bytes = pBuffer->field_bc;
                if (stages & 1) {
                    field_30.field_2778[0].Unk_MarkRead(slot);
                    field_30.field_508.field_570[0][slot] = address;
                    field_30.field_508.field_810[0][slot] = bytes;
                }
                if (stages & 2) {
                    field_30.field_2778[1].Unk_MarkRead(slot);
                    field_30.field_508.field_570[1][slot] = address;
                    field_30.field_508.field_810[1][slot] = bytes;
                }
                if (stages & 4) {
                    field_30.field_2778[2].Unk_MarkRead(slot);
                    field_30.field_508.field_570[2][slot] = address;
                    field_30.field_508.field_810[2][slot] = bytes;
                }
                if (stages & 16) {
                    field_30.field_2778[3].Unk_MarkRead(slot);
                    field_30.field_508.field_570[3][slot] = address;
                    field_30.field_508.field_810[3][slot] = bytes;
                }
                if (stages & 16) {
                    field_30.field_2778[4].Unk_MarkRead(slot);
                    field_30.field_508.field_570[4][slot] = address;
                    field_30.field_508.field_810[4][slot] = bytes;
                }
                if (stages & 32) {
                    field_30.field_2778[5].Unk_MarkRead(slot);
                    field_30.field_508.field_570[5][slot] = address;
                    field_30.field_508.field_810[5][slot] = bytes;
                }
            }
            buffers += count;
            break;
        case 3:
            if (base < 0 || count + base > 13) {
                return;
            }
            for (s32 j = 0; j < count; j++) {
                if (images + j >= static_cast<s32>(pTable->field_e0.field_8.m_itemCount)) {
                    break;
                }
                Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pTable->field_e0.field_8.m_pData[images + j]);
                if (pTexture == nullptr) {
                    continue;
                }
                u32 stages = parameter.field_4;
                s32 slot = base + j;
                u64 handle = pTexture->field_340;
                if (stages & 1) {
                    field_30.field_2928[0].Unk_MarkRead(slot);
                    field_30.field_508.field_1050[0][slot] = handle;
                }
                if (stages & 2) {
                    field_30.field_2928[1].Unk_MarkRead(slot);
                    field_30.field_508.field_1050[1][slot] = handle;
                }
                if (stages & 4) {
                    field_30.field_2928[2].Unk_MarkRead(slot);
                    field_30.field_508.field_1050[2][slot] = handle;
                }
                if (stages & 16) {
                    field_30.field_2928[3].Unk_MarkRead(slot);
                    field_30.field_508.field_1050[3][slot] = handle;
                }
                if (stages & 16) {
                    field_30.field_2928[4].Unk_MarkRead(slot);
                    field_30.field_508.field_1050[4][slot] = handle;
                }
                if (stages & 32) {
                    field_30.field_2928[5].Unk_MarkRead(slot);
                    field_30.field_508.field_1050[5][slot] = handle;
                }
            }
            images += count;
            break;
        case 4:
            for (s32 j = 0; j < count; j++) {
                if (samplers + j >= static_cast<s32>(pTable->field_138.field_8.m_itemCount)) {
                    break;
                }
                Unk_NXTableSampler* pSampler = static_cast<Unk_NXTableSampler*>(pTable->field_138.field_8.m_pData[samplers + j]);
                if (pSampler == nullptr) {
                    continue;
                }
                u32 stages = parameter.field_4;
                s32 slot = base + j;
                if (pSampler->vf8()->field_0 != 12) {
                    continue;
                }
                u32 bound = pSampler->vf19();
                if (bound == field_30.field_508.field_e50[slot]) {
                    continue;
                }
                field_30.field_2b40[slot] = stages;
                field_30.field_508.field_e50[slot] = bound;
                field_30.field_29b8.Unk_MarkRead(slot);
            }
            samplers += count;
            break;
        }
        s32 repeat = pRanges->field_8.m_pData[i].field_8;
        i += repeat > 1 ? repeat - 1 : 0;
    }
}

// 0x710053ed20
void SiGfxNXDrawContext::Unk_53ed20(SiGfxNXDescriptorSet* pSet) {
    for (SiGfxNXDescriptorSet::ParameterEntry *entry = pSet->field_28.field_30, *end = pSet->field_28.field_38; entry != end;
         entry++) {
        if (entry->field_10) {
            continue;
        }
        if (entry->field_0 == 2) {
            Unk_NXDrawTexture* pTexture = reinterpret_cast<Unk_NXDrawTexture*>(entry->field_18);
            if (pTexture == nullptr) {
                continue;
            }
            s32 index = entry->field_4;
            if (pTexture->vf8()->field_0 != 1) {
                continue;
            }
            SiGfxNXRootSignature* pSignature;
            if (field_20 == 1) {
                pSignature = field_30.field_20.field_8;
            } else if (field_20 == 2) {
                pSignature = field_30.field_20.field_10;
            } else {
                continue;
            }
            if (index < 0 || pSignature == nullptr || index >= static_cast<s32>(pSignature->field_28.m_itemCount)) {
                continue;
            }
            SiGfxNXRootSignature::RootParameterEntry& parameter = pSignature->field_28.m_pData[index];
            if (parameter.field_0 != 1) {
                continue;
            }
            s32 slot = parameter.field_8;
            if (static_cast<u32>(slot) > 63) {
                continue;
            }
            field_30.field_508.field_f50[slot] = Unk_53f490(pTexture, pSignature);
        } else if (entry->field_0 == 4) {
            Unk_53f2f0(entry->field_4, reinterpret_cast<SiGfxNXDescriptorTable*>(entry->field_20));
        }
    }
}

// 0x710053ee60 (the buffer's texture marks its slot with `Unk_MarkOr`)
void SiGfxNXDrawContext::Unk_53ee60(ISiGfxResource* pResource, u32 stages, s32 slot) {
    if (pResource == nullptr) {
        return;
    }
    Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pResource);
    if (pResource->vf8()->field_0 == 1) {
        u64 handle = pTexture->field_340;
        if (stages & 1) {
            field_30.field_2928[0].Unk_MarkRead(slot);
            field_30.field_508.field_1050[0][slot] = handle;
        }
        if (stages & 2) {
            field_30.field_2928[1].Unk_MarkRead(slot);
            field_30.field_508.field_1050[1][slot] = handle;
        }
        if (stages & 4) {
            field_30.field_2928[2].Unk_MarkRead(slot);
            field_30.field_508.field_1050[2][slot] = handle;
        }
        if (stages & 16) {
            field_30.field_2928[3].Unk_MarkRead(slot);
            field_30.field_508.field_1050[3][slot] = handle;
        }
        if (stages & 16) {
            field_30.field_2928[4].Unk_Mark(slot);
            field_30.field_508.field_1050[4][slot] = handle;
        }
        if (stages & 32) {
            field_30.field_2928[5].Unk_MarkRead(slot);
            field_30.field_508.field_1050[5][slot] = handle;
        }
    }
    if (pResource->vf8()->field_0 != 10) {
        return;
    }
    if (pResource->vf8()->field_8 & 0x8000) {
        u64 base = pTexture->field_100;
        s64 bytes = pTexture->field_bc;
        u64 address = base + pTexture->field_154 * bytes;
        if (stages & 1) {
            field_30.field_2898[0].Unk_MarkRead(slot);
            field_30.field_508.field_960[0][slot] = address;
            field_30.field_508.field_c00[0][slot] = bytes;
        }
        if (stages & 2) {
            field_30.field_2898[1].Unk_MarkRead(slot);
            field_30.field_508.field_960[1][slot] = address;
            field_30.field_508.field_c00[1][slot] = bytes;
        }
        if (stages & 4) {
            field_30.field_2898[2].Unk_MarkRead(slot);
            field_30.field_508.field_960[2][slot] = address;
            field_30.field_508.field_c00[2][slot] = bytes;
        }
        if (stages & 16) {
            field_30.field_2898[3].Unk_Mark(slot);
            field_30.field_508.field_960[3][slot] = address;
            field_30.field_508.field_c00[3][slot] = bytes;
        }
        if (stages & 16) {
            field_30.field_2898[4].Unk_Mark(slot);
            field_30.field_508.field_960[4][slot] = address;
            field_30.field_508.field_c00[4][slot] = bytes;
        }
        if (stages & 32) {
            field_30.field_2898[5].Unk_MarkRead(slot);
            field_30.field_508.field_960[5][slot] = address;
            field_30.field_508.field_c00[5][slot] = bytes;
        }
    } else if (pResource->vf8()->field_8 & 0x10000) {
        u64 handle = pTexture->vf29();
        if (stages & 32) {
            field_30.field_2928[5].Unk_MarkOr(slot);
            field_30.field_508.field_1050[5][slot] = handle;
        }
    }
}

// NON_MATCHING: three instructions: the original steps a pointer to the
// sampler slot (`str w0, [x25] ; add x25, x25, #4`) where this indexes it by
// the inner counter. Tried: the slot through a pointer stepped by the loop or
// indexed, the counters and the range's fields as s64/u32.
// 0x710053f2f0
void SiGfxNXDrawContext::Unk_53f2f0(s32 index, SiGfxNXDescriptorTable* pTable) {
    if (pTable == nullptr) {
        return;
    }
    SiGfxNXRootSignature* pSignature;
    if (field_20 == 1) {
        pSignature = field_30.field_20.field_8;
    } else if (field_20 == 2) {
        pSignature = field_30.field_20.field_10;
    } else {
        return;
    }
    if (index < 0 || pSignature == nullptr || index >= static_cast<s32>(pSignature->field_28.m_itemCount)) {
        return;
    }
    SiGfxNXRootSignature::RootParameterEntry& parameter = pSignature->field_28.m_pData[index];
    if (parameter.field_0 != 5) {
        return;
    }
    SiGfxNXRootSignature::Unk_Ranges* pRanges = parameter.field_20;
    s32 first = 0;
    for (s32 i = 0; i < static_cast<s32>(pRanges->field_8.m_itemCount); i++) {
        SiGfxNXRootSignature::DescriptorRangeEntry& range = pRanges->field_8.m_pData[i];
        s32 base = range.field_4;
        s32 count = range.field_c;
        if (range.field_0 != 1) {
            continue;
        }
        if (base < 0) {
            return;
        }
        if (count + base > 63) {
            return;
        }
        for (s32 j = 0; j < count; j++) {
            if (first + j >= static_cast<s32>(pTable->field_88.field_8.m_itemCount)) {
                break;
            }
            Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pTable->field_88.field_8.m_pData[first + j]);
            if (pTexture == nullptr) {
                continue;
            }
            if (pTexture->vf8()->field_0 == 1) {
                field_30.field_508.field_f50[base + j] = Unk_53f490(pTexture, pSignature);
            }
        }
        first += count;
    }
}

// NON_MATCHING: the original duplicates the final `mvn` into the block of
// a missing signature or no samplers (with the dead `mov w23, wzr` left in
// it); here that block branches to it. Tried: `~result`, `-(result + 1)`, an
// early return for a missing signature, the result declared first, s32
// indices, returning from the loop instead of the break.
// 0x710053f490
s32 SiGfxNXDrawContext::Unk_53f490(Unk_NXDrawTexture* pTexture, SiGfxNXRootSignature* pSignature) {
    Unk_NXRootSampler* pSampler = pTexture->vf33();
    if (pSampler != nullptr) {
        u32 hash = pSampler->vf19();
        for (s64 i = 0; i < 64; i++) {
            if (hash == field_30.field_508.field_e50[i]) {
                return i;
            }
        }
    }
    s32 result = 0;
    if (pSignature != nullptr) {
        const SiGfxNXSampler::Unk_Desc* desc = pSampler != nullptr ? pSampler->vf17() : nullptr;
        for (s64 i = 0; i < static_cast<s32>(pSignature->field_78.m_itemCount); i++) {
            const SiGfxNXSampler::Unk_Desc* other = pSignature->field_78.m_pData[i].field_50->vf17();
            if (desc != nullptr && Unk_53f630(desc, other)) {
                result = i;
                break;
            }
            if (Unk_53f630(other, reinterpret_cast<const SiGfxNXSampler::Unk_Desc*>(Unk_27703d8))) {
                result = i;
            }
        }
    }
    return -1 - result;
}

// Two numbers that are equal to 1e-7 (inline: placeholder name).
static inline bool Unk_NearlyEqual(f64 a, f64 b) {
    return fabs(a - b) < 1e-7f;
}

// 0x710053f630
bool Unk_53f630(const SiGfxNXSampler::Unk_Desc* a, const SiGfxNXSampler::Unk_Desc* b) {
    if (a->field_0 != b->field_0) {
        return false;
    }
    if (a->field_0 == 0xc && a->field_1c != b->field_1c) {
        return false;
    }
    if (a->field_4 != b->field_4) {
        return false;
    }
    if (a->field_8 != b->field_8) {
        return false;
    }
    if (a->field_c != b->field_c) {
        return false;
    }
    if (!Unk_NearlyEqual(a->field_10, b->field_10)) {
        return false;
    }
    if (!Unk_NearlyEqual(a->field_14, b->field_14)) {
        return false;
    }
    if (!Unk_NearlyEqual(a->field_18, b->field_18)) {
        return false;
    }
    if (a->field_20 != b->field_20) {
        return false;
    }
    if (!Unk_NearlyEqual(a->field_24.field_0[0], b->field_24.field_0[0])) {
        return false;
    }
    if (!Unk_NearlyEqual(a->field_24.field_0[1], b->field_24.field_0[1])) {
        return false;
    }
    if (!Unk_NearlyEqual(a->field_24.field_0[2], b->field_24.field_0[2])) {
        return false;
    }
    return Unk_NearlyEqual(a->field_24.field_0[3], b->field_24.field_0[3]);
}

// NON_MATCHING: when a stage has no samplers that changed, the original
// doesn't load the program's count of stages again (it keeps it in w8 through
// the loop, so the other registers are one up); here it is reloaded
// (`ldrsw`). Two spill slots are exchanged in the blending's part (1680
// bytes for 1688). The rest is the original's.
// 0x710053f7d0
void SiGfxNXDrawContext::Unk_53f7d0() {
    if (field_3a68 < 1) {
        return;
    }
    Unk_NXDrawProgram* program = field_3a70.field_0;
    for (s32 i = 0; i < program->field_17c; i++) {
        Unk_SlotRange& range = field_30.field_2808[program->field_180[i]];
        for (s64 slot = range.field_4; slot <= range.field_8; slot++) {
            if ((static_cast<u64>(1) << slot) & range.field_10) {
                s32 index;
                if (field_30.field_29b8.field_4 == field_30.field_29b8.field_8 && field_30.field_29b8.field_10 != 0) {
                    index = field_30.field_29b8.field_4;
                } else {
                    Unk_NXRootSampler* pSampler = static_cast<Unk_NXDrawTexture*>(field_3a70.field_190[slot])->vf33();
                    index = -1;
                    if (pSampler != nullptr) {
                        u32 id = pSampler->vf19();
                        for (s32 j = 0; j < 64; j++) {
                            if (id == field_30.field_508.field_e50[j]) {
                                index = j;
                                break;
                            }
                        }
                    }
                }
                field_30.field_508.field_f50[slot] = index;
            }
        }
    }
    if (field_3a70.field_188 == 0) {
        return;
    }
    Unk_NXDrawState& state = field_30.field_508;
    if (field_3a70.field_188 & 0x88) {
        nvnPolygonStateSetDefaults(&state.field_3f8);
        nvnPolygonStateSetCullFace(&state.field_3f8, Unk_5631d0(field_3a70.field_10));
        nvnPolygonStateSetFrontFace(&state.field_3f8, field_3a70.field_28);
        nvnPolygonStateSetPolygonMode(&state.field_3f8, Unk_563250(field_3a70.field_14));
        nvnPolygonStateSetPolygonOffsetEnables(&state.field_3f8, 4);
        nvnMultisampleStateSetDefaults(state.field_408);
        nvnMultisampleStateSetMultisampleEnable(state.field_408, field_3a70.field_29[0]);
        nvnMultisampleStateSetSamples(state.field_408, field_3a70.field_18.field_c);
        state.field_53c = field_3a70.field_29[3];
        field_30.field_0 |= 0x18060;
    }
    if (field_3a70.field_188 & 0x40) {
        nvnChannelMaskStateSetDefaults(&state.field_424);
        nvnColorStateSetDefaults(&state.field_420);
        for (s32 i = 0; i < 8; i++) {
            const Unk_DrawStates::Unk_Blend& blend = field_3a70.field_60[i];
            nvnColorStateSetBlendEnable(&state.field_420, i, blend.field_0);
            nvnBlendStateSetDefaults(&state.field_3b8[i]);
            nvnBlendStateSetBlendTarget(&state.field_3b8[i], i);
            nvnBlendStateSetBlendFunc(&state.field_3b8[i], Unk_5630e0(blend.field_4, false), Unk_5630e0(blend.field_8, false),
                                      Unk_5630e0(blend.field_10, true), Unk_5630e0(blend.field_14, true));
            nvnBlendStateSetBlendEquation(&state.field_3b8[i], Unk_563150(blend.field_c), Unk_563150(blend.field_18));
            nvnChannelMaskStateSetChannelMask(&state.field_424, i, blend.field_1c[0], blend.field_1c[1], blend.field_1c[2],
                                              blend.field_1c[3]);
        }
        field_30.field_0 |= 0x700;
    }
    if (field_3a70.field_188 & 0x10) {
        nvnDepthStencilStateSetDefaults(&state.field_400);
        nvnDepthStencilStateSetDepthTestEnable(&state.field_400, field_3a70.field_34);
        nvnDepthStencilStateSetDepthWriteEnable(&state.field_400, field_3a70.field_35);
        nvnDepthStencilStateSetDepthFunc(&state.field_400, Unk_563190(field_3a70.field_30));
        nvnDepthStencilStateSetStencilTestEnable(&state.field_400, field_3a70.field_38);
        nvnDepthStencilStateSetStencilFunc(&state.field_400, 2, Unk_5631f0(field_3a70.field_58));
        nvnDepthStencilStateSetStencilOp(&state.field_400, 2, Unk_563220(field_3a70.field_4c), Unk_563220(field_3a70.field_50),
                                         Unk_563220(field_3a70.field_54));
        nvnDepthStencilStateSetStencilFunc(&state.field_400, 1, Unk_5631f0(field_3a70.field_48));
        nvnDepthStencilStateSetStencilOp(&state.field_400, 1, Unk_563220(field_3a70.field_3c), Unk_563220(field_3a70.field_40),
                                         Unk_563220(field_3a70.field_44));
        field_30.field_0 |= 0x80;
    }
    if (field_3a70.field_188 & 1) {
        Unk_NXDrawProgram* pProgram = field_3a70.field_0;
        if (pProgram == nullptr) {
            return;
        }
        state.field_540 = pProgram->field_b8;
        state.field_548 = pProgram->field_178;
        s32 count = pProgram->field_17c;
        field_30.field_4 = count;
        memcpy(field_30.field_8, pProgram->field_180, count * sizeof(u32));
        field_30.field_0 |= 0x2000;
    }
    if (field_3a70.field_188 & 2) {
        Unk_NXDrawVertexFormat* pFormat = field_3a70.field_8;
        if (pFormat != nullptr) {
            for (s32 i = 0; i < pFormat->field_3fc; i++) {
                const Unk_NXDrawVertexFormat::Attribute& attribute = pFormat->field_7c[i];
                u32 format = Unk_562ee0(attribute.field_8);
                Unk_VertexAttribStateSetDefaults(&state.field_42c[i]);
                Unk_VertexAttribStateSetStreamIndex(&state.field_42c[i], attribute.field_c);
                Unk_VertexAttribStateSetFormat(&state.field_42c[i], format, attribute.field_10);
            }
            state.field_428 = pFormat->field_3fc;
            field_30.field_0 |= 0x800;
        }
    }
    if (field_3a70.field_188 & 4) {
        u32 kind = field_3a70.field_16c;
        field_30.field_20.field_3bc = kind;
        state.field_3a0 = Unk_563160(kind);
        field_30.field_0 |= 0x10;
    }
    field_3a70.field_188 = 0;
}

// 0x710053fe70
void SiGfxNXDrawContext::Unk_53fe70(const void* device, Unk_SlotRange* textures, Unk_SlotRange* samplers, u64* handles,
                                    Unk_SlotRange* changed) {
    s32 texturesLowest = textures->field_4;
    s32 texturesHighest = textures->field_8;
    s32 samplersLowest = samplers->field_4;
    s32 samplersHighest = samplers->field_8;
    if (texturesLowest > texturesHighest && samplersLowest > samplersHighest) {
        return;
    }
    if (texturesLowest <= texturesHighest) {
        for (s32 i = texturesLowest; i <= textures->field_8; i++) {
            if ((textures->field_10 & static_cast<u64>(1) << i) != 0) {
                s32 texture = field_30.field_508.field_d50[i];
                s32 slot = field_30.field_508.field_f50[i];
                s32 sampler = field_30.field_508.field_e50[slot < 0 ? 0 : slot];
                handles[i] = nvnDeviceGetTextureHandle(device, texture, sampler < 0 ? 0 : sampler);
                changed->Unk_Mark(i);
            }
        }
        textures->Unk_Reset();
    }
    if (samplersLowest <= samplersHighest) {
        for (s32 i = samplers->field_4; i <= samplers->field_8; i++) {
            if ((samplers->field_10 & static_cast<u64>(1) << i) != 0) {
                for (s32 j = 0; j < 64; j++) {
                    if (static_cast<s32>(field_30.field_508.field_f50[j]) == i) {
                        s32 texture = field_30.field_508.field_d50[j];
                        if (texture > 0) {
                            handles[j] = nvnDeviceGetTextureHandle(device, texture, field_30.field_508.field_e50[i]);
                            changed->Unk_MarkRead(j);
                        }
                    }
                }
            }
        }
        samplers->Unk_Reset();
    }
}

// 0x7100540080
bool SiGfxNXDrawContext::vf24(s32 count, s32 first, s32 instances, s32 baseInstance) {
    Unk_53c340();
    if (instances <= 1) {
        nvnCommandBufferDrawArrays(field_3a60, field_30.field_508.field_3a0, first, count);
    } else {
        nvnCommandBufferDrawArraysInstanced(field_3a60, field_30.field_508.field_3a0, first, count, baseInstance, instances);
    }
    SiGfxNXCommandList* pList = field_28;
    pList->field_124.field_0[1]++;
    s32 n = instances > 1 ? instances : 1;
    pList->field_124.field_0[8] += n * count;
    Unk_CountPrimitives(pList, count, n);
    return true;
}

// 0x71005401c0
bool SiGfxNXDrawContext::vf25(s32 count, s32 first, s32 baseVertex, s32 instances, s32 baseInstance) {
    Unk_53c340();
    u64 indexBuffer = static_cast<s64>(field_30.field_508.field_39c) * first + field_30.field_508.field_390;
    if (instances <= 1) {
        nvnCommandBufferDrawElementsBaseVertex(field_3a60, field_30.field_508.field_3a0, field_30.field_508.field_398, count, indexBuffer, baseVertex);
    } else {
        nvnCommandBufferDrawElementsInstanced(field_3a60, field_30.field_508.field_3a0, field_30.field_508.field_398, count, indexBuffer, baseVertex,
                                              baseInstance, instances);
    }
    SiGfxNXCommandList* pList = field_28;
    pList->field_124.field_0[1]++;
    s32 n = instances > 1 ? instances : 1;
    pList->field_124.field_0[8] += n * count;
    pList->field_124.field_0[9] += n * count;
    Unk_CountPrimitives(pList, count, n);
    return true;
}

// 0x7100540320
u32 SiGfxNXDrawContext::vf26(Unk_NXDrawIndirect* pBuffer) {
    Unk_53c340();
    nvnCommandBufferBarrier(field_3a60, 8);
    nvnCommandBufferDrawElementsIndirect(field_3a60, field_30.field_508.field_3a0, field_30.field_508.field_398, field_30.field_508.field_390, pBuffer->vf27());
    return 0;
}

// 0x71005403c0
u32 SiGfxNXDrawContext::vf28(s32 x, s32 y, s32 z) {
    Unk_53c340();
    nvnCommandBufferDispatchCompute(field_3a60, x, y, z);
    field_28->field_124.field_0[4]++;
    return 0;
}

// NON_MATCHING: the barriers' bits are combined in another order (the 720
// orders of the first six tests were tried: 22 instructions differ at best).
// 0x7100540440
bool SiGfxNXDrawContext::vf30(ISiGfxResource* pResource, u32 from, u32 to) {
    if (from == to) {
        return true;
    }
    u32 kind = pResource->vf8()->field_0;
    u32 barriers = 0;
    u32 tracked = 0;
    if (kind == 1 || kind == 3 || kind == 11) {
        tracked = static_cast<Unk_NXDrawTexture*>(pResource)->vf16();
    } else {
        if (from & 0x2c) {
            barriers |= 1;
        }
        if ((from & 0xf0d0) || (to & 0x50d0)) {
            barriers |= 2;
        }
        if (to & 0x2c) {
            barriers |= 1;
        }
        if (from & 0x800) {
            barriers |= 8;
        }
        if (to & 0x800) {
            barriers |= 8;
        }
        if (to & 2) {
            barriers |= 0x20;
        }
        if (to & 0x300) {
            barriers |= 0x11;
        }
        if (to & 0xa000) {
            barriers |= 0x10;
        }
    }
    if (tracked & from) {
        static_cast<Unk_NXDrawTexture*>(pResource)->vf15(to);
        if ((to | from) & 0x50) {
            if (to & 0x200) {
                barriers |= 2;
            }
            if (to & 0x1c0) {
                barriers |= 1;
            }
        }
        if (to & 0x300) {
            barriers |= 0x10;
        }
    }
    if (barriers != 0) {
        field_30.field_508.field_2250[0] |= barriers;
        field_30.field_0 |= 0x20000;
    }
    return true;
}

// 0x71005405c0
void SiGfxNXDrawContext::vf31(const char* description) {
    if (field_3a60 != nullptr) {
        char buffer[0x100];
        Unk_4c4cf0_update(reinterpret_cast<u64>(description), reinterpret_cast<u64>(buffer), sizeof(buffer));
        nvnCommandBufferInsertDebugMarker(field_3a60, buffer);
    }
}

// 0x7100540760
void SiGfxNXDrawContext::vf50(u32 index) {
    void* font = field_18->vf56(index);
    field_3780.Unk_544010(font);
}

// 0x71005407a0
void SiGfxNXDrawContext::vf51(void* font) {
    field_3780.Unk_544010(font);
}

// 0x71005407b0
void SiGfxNXDrawContext::vf52() {
    Unk_544280_get(reinterpret_cast<const Unk_544280*>(&field_3780));
}

// 0x71005407c0
bool SiGfxNXDrawContext::vf53(const char* text, SiGfxFontDrawHelper::Unk_Vec2* pSize, u32 flags, f32 scale) {
    return field_3780.Unk_544290(text, pSize, flags, scale);
}

// 0x71005407d0
void SiGfxNXDrawContext::vf54() {
    field_3780.Unk_544540();
}

// 0x71005407e0
bool SiGfxNXDrawContext::vf55(const char* text, const SiGfxFontDrawHelper::Unk_Vec4* pRect, u32 flags,
                              const Unk_TextColor* pColor, f32 scale) {
    return field_3780.Unk_544610(text, pRect, flags, pColor, scale);
}

// 0x71005407f0
bool SiGfxNXDrawContext::vf56(const char* text, const SiGfxFontDrawHelper::Unk_Vec4* pRect, u32 flags,
                              const Unk_TextColor* pColor, const Unk_TextColor* pOutlineColor, f32 scale, u32 outline) {
    return field_3780.Unk_544b00(text, pRect, flags, pColor, pOutlineColor, scale, outline);
}

// 0x7100540800
bool SiGfxNXDrawContext::vf57() {
    return field_3780.Unk_545910();
}

// 0x7100540810
bool SiGfxNXDrawContext::vf58(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc,
                              const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    return field_2c70.Unk_548640(pTexture, desc, dest, source);
}

// 0x7100540820
bool SiGfxNXDrawContext::vf59(Unk_PrimitiveTexture* pPlane0, Unk_PrimitiveTexture* pPlane1, Unk_PrimitiveTexture* pPlane2,
                              Unk_PrimitiveTexture* pPlane3, const Unk_PrimitiveTextureDesc* desc,
                              const Unk_PrimitiveRect* dest, const Unk_PrimitiveRect* source) {
    return field_2c70.Unk_54cab0(pPlane0, pPlane1, pPlane2, pPlane3, desc, dest, source);
}

// 0x7100540840
bool SiGfxNXDrawContext::vf61(Unk_NXDrawQuery* query) {
    void* commandBuffer = field_3a60;
    if (query->field_78 == 1) {
        nvnCommandBufferResetCounter(commandBuffer, 1);
    } else {
        nvnCommandBufferResetCounter(commandBuffer, 0);
    }
    return true;
}

// 0x7100540890
bool SiGfxNXDrawContext::vf62(Unk_NXDrawQuery* query) {
    nvnCommandBufferReportCounter(field_3a60, query->field_78 == 1, query->field_b8);
    return true;
}

// 0x71005408e0
bool SiGfxNXDrawContext::vf64(Unk_NXDrawQuery* query) {
    void* result = nvnBufferMap(query->field_88);
    nvnBufferInvalidateMappedRange(query->field_88, 0, query->field_80);
    memcpy(query->field_d8, result, query->field_80);
    return true;
}


// A surface's rows are mapped in place in both cases: each branch multiplies
// the row's bytes (read first, so the load is hoisted above the test) by its
// count of rows; a helper would be simplified on its own first and its loads
// sunk into a select of addresses. The kinds are a switch: the original's
// blocks are in the cases' order (10, 1, 3) and its comparisons in their
// values' (if-else chains are compared in the reverse of the source's order).
// NON_MATCHING: for a texture whose size isn't given, the original keeps the
// size in 32 bits through the join and sign-extends it after (`ldr w24`, `mov
// w24, w0`, then `sxtw x2, w24`); an s64 size (as here) extends it at the load
// and keeps the call's 64 bits, and an s32 one duplicates the invalidation's
// call into both paths (the size from nvnTextureGetStorageSize is a truncated
// size_t, its sign extension a shift pair that differs from the loaded
// size's: 752 bytes). The texture's two rows' multiplications aren't merged
// into one as the original's are (740 bytes for 736). Tried: the mapping as
// helpers (either case), rows in a local, the empty surface's branch first.
// 0x7100540990
bool SiGfxNXDrawContext::vf69(ISiGfxResource* pResource, Unk_NXDrawFlush* pMap) {
    if (pResource == nullptr) {
        return false;
    }
    u32 kind = pResource->vf8()->field_0;
    switch (kind) {
    case 10: {
            Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pResource);
            const Unk_NXDrawUsage* usage = pBuffer->vf19();
            pMap->field_20 = nvnBufferMap(pBuffer->field_d0);
            if (usage->field_74 & 1) {
                return false;
            }
            if (usage->field_74 & 4) {
                nvnBufferInvalidateMappedRange(pBuffer->field_d0, 0, pBuffer->field_bc);
            }
            return true;
    }
    case 1: {
            Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pResource);
            const Unk_NXDrawUsage* usage = pTexture->vf20();
            if (usage->field_74 & 1) {
                return false;
            }
            if (usage->field_74 & 4) {
                if (pTexture->field_328 == nullptr) {
                    return false;
                }
                void* pool = nvnTextureGetMemoryPool(pTexture->field_328);
                if (pool == nullptr) {
                    return false;
                }
                s64 offset = nvnTextureGetMemoryOffset(pTexture->field_328);
                s64 size = pMap->field_8;
                if (size < 0) {
                    size = nvnTextureGetStorageSize(pTexture->field_328);
                }
                nvnMemoryPoolInvalidateMappedRange(pool, offset, size);
                pMap->field_4 = offset;
                pMap->field_8 = size;
            }
            pMap->field_20 = usage->field_450;
            if (pTexture->vf19()->field_0 == 2 || pTexture->vf19()->field_0 == 5 || pTexture->vf19()->field_0 == 4 ||
                pTexture->vf19()->field_0 == 6) {
                if (pTexture->field_248 != 0) {
                    const Unk_NXDrawSurface* pSurface = pTexture->field_260;
                    pMap->field_28 = pSurface->field_110;
                    if (pSurface->field_a4) {
                        pMap->field_2c = pSurface->field_110 * pSurface->field_ac;
                    } else {
                        pMap->field_2c = pSurface->field_110 * pSurface->field_90;
                    }
                } else {
                    // (the original calls it again here, its result unused)
                    pTexture->vf19();
                }
            }
            return true;
    }
    case 3: {
            Unk_NXDrawSurface* pSurface = static_cast<Unk_NXDrawSurface*>(pResource);
            const Unk_NXDrawUsage* usage = pSurface->vf18();
            if (usage->field_74 & 1) {
                return false;
            }
            if (usage->field_74 & 4) {
                if (pSurface->field_e0 == nullptr) {
                    return false;
                }
                void* pool = nvnTextureGetMemoryPool(pSurface->field_e0);
                if (pool == nullptr) {
                    return false;
                }
                s64 offset = nvnTextureGetMemoryOffset(pSurface->field_e0);
                s32 size = pMap->field_8;
                if (size < 0) {
                    size = nvnTextureGetStorageSize(pSurface->field_e0);
                }
                nvnMemoryPoolInvalidateMappedRange(pool, offset, size);
            }
            pMap->field_20 = usage->field_450;
            pMap->field_28 = pSurface->field_110;
            if (pSurface->field_a4) {
                pMap->field_2c = pSurface->field_110 * pSurface->field_ac;
            } else {
                pMap->field_2c = pSurface->field_110 * pSurface->field_90;
            }
            return true;
    }
    }
    return false;
}

// NON_MATCHING: the return for a kind it doesn't flush is a copy of its own
// at the end, where the original shares the null resource's (20 bytes more).
// Written as a switch, the rest is the original's: its blocks are in the
// cases' order (10, 1, 3), its comparisons in their values' (an if-else chain
// compares 10 first). Tried: a null resource as kind 0, a default case, the
// result in a variable. The IR has one return block; the copy is block
// placement's tail duplication (-tail-dup-placement=0 gives 384 bytes), so
// the edges' frequencies differ. Also tried: the textures' flush as a static
// inline helper, if-else chains and switches in all six orders, an s32 kind,
// the kind not in a local.
// 0x7100540c70
bool SiGfxNXDrawContext::vf70(ISiGfxResource* pResource, const Unk_NXDrawFlush* pFlush) {
    if (pResource == nullptr) {
        return false;
    }
    u32 kind = pResource->vf8()->field_0;
    switch (kind) {
    case 10: {
            Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pResource);
            if ((pBuffer->vf19()->field_74 & 4) == 0) {
                return true;
            }
            nvnBufferFlushMappedRange(pBuffer->field_d0, 0, pBuffer->field_bc);
            return true;
    }
    case 1: {
            Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pResource);
            if ((pTexture->vf20()->field_74 & 4) == 0) {
                return true;
            }
            if (pTexture->field_328 == nullptr) {
                return false;
            }
            void* pool = nvnTextureGetMemoryPool(pTexture->field_328);
            if (pool == nullptr) {
                return false;
            }
            s64 offset = nvnTextureGetMemoryOffset(pTexture->field_328);
            s32 size = pFlush->field_8;
            if (size < 0) {
                size = nvnTextureGetStorageSize(pTexture->field_328);
            }
            nvnMemoryPoolFlushMappedRange(pool, offset, size);
            return true;
    }
    case 3: {
            Unk_NXDrawSurface* pSurface = static_cast<Unk_NXDrawSurface*>(pResource);
            if ((pSurface->vf18()->field_74 & 4) == 0) {
                return true;
            }
            if (pSurface->field_e0 == nullptr) {
                return false;
            }
            void* pool = nvnTextureGetMemoryPool(pSurface->field_e0);
            if (pool == nullptr) {
                return false;
            }
            s64 offset = nvnTextureGetMemoryOffset(pSurface->field_e0);
            s32 size = pFlush->field_8;
            if (size < 0) {
                size = nvnTextureGetStorageSize(pSurface->field_e0);
            }
            nvnMemoryPoolFlushMappedRange(pool, offset, size);
            return true;
    }
    }
    return false;
}

// NON_MATCHING: the original keeps the buffer found and the one made in two
// registers (x20 and x21, `mov x20, xzr` for no buffer, `mov x20, x21` once
// it is made); here they are one, which shifts the registers (1252 bytes for
// 1236).
// NON_MATCHING: the null texture and view of a buffer are set before the
// kind's second comparison (`mov x22, xzr` hoisted into the compare block),
// where the original has a block of its own for them, tail-duplicated with
// what follows (1020 bytes for 1040); `this` and the bit test's 1 are in
// each other's registers (x21/x20). The cases' order (3, then 1) is the
// original's. Tried: the nulls as initial values, a case 10 for them.
// 0x7100540e00
bool SiGfxNXDrawContext::vf71(ISiGfxResource* pDst, ISiGfxResource* pSrc) {
    u32 dstKind = pDst->vf8()->field_0;
    if (dstKind != 1 && dstKind != 3 && dstKind != 10) {
        return false;
    }
    u32 srcKind = pSrc->vf8()->field_0;
    if (srcKind != 1 && srcKind != 3 && srcKind != 10) {
        return false;
    }
    Unk_NXCopyRegion dstRegion;
    void* dstTexture;
    void* dstView;
    switch (dstKind) {
    case 3: {
            Unk_NXDrawSurface* pSurface = static_cast<Unk_NXDrawSurface*>(pDst);
            const Unk_NXDrawUsage* info = pSurface->vf17();
            s32 width = info->field_14;
            s32 height = info->field_18;
            dstRegion.field_c = width;
            dstRegion.field_10 = height;
            dstTexture = pSurface->vf25();
            dstView = pSurface->vf26();
            Unk_55d3b0_get(reinterpret_cast<const Unk_55d3b0*>(pSurface));
        break;
    }
    case 1: {
            Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pDst);
            const Unk_NXDrawUsage* info = pTexture->vf19();
            s32 width = info->field_14;
            s32 height = info->field_18;
            dstRegion.field_c = width;
            dstRegion.field_10 = height;
            dstTexture = pTexture->vf40();
            dstView = pTexture->vf41();
        break;
    }
    default:
            dstTexture = nullptr;
            dstView = nullptr;
        break;
    }
    SiGfxNXCommandList* pList = field_28;
    bool own = false;
    if (pList == nullptr) {
        pList = field_18->vf92();
        own = true;
    }
    void* commandBuffer = pList->vf15();
    SiGfxNXCommandQueue* pQueue = field_18->vf91();
    if (own) {
        pList->vf17();
        pQueue->vf8();
        nvnCommandBufferBeginRecording(commandBuffer);
    }
    if (dstKind == 10 && srcKind == 10) {
        u64 src = static_cast<Unk_NXDrawTexture*>(pSrc)->vf27();
        u64 dst = static_cast<Unk_NXDrawTexture*>(pDst)->vf27();
        nvnCommandBufferCopyBufferToBuffer(commandBuffer, src, dst, static_cast<Unk_NXDrawTexture*>(pDst)->vf17()->field_4, 0);
    } else if (srcKind == 10) {
        reinterpret_cast<SiGfxNXBuffer*>(pSrc)->Unk_538910();
        nvnCommandBufferCopyBufferToTexture(commandBuffer, static_cast<Unk_NXDrawTexture*>(pSrc)->vf27(), dstTexture, dstView,
                                            &dstRegion, 0);
    } else {
        Unk_NXCopyRegion srcRegion;
        void* srcTexture;
        void* srcView;
        switch (srcKind) {
        case 3: {
                Unk_NXDrawSurface* pSurface = static_cast<Unk_NXDrawSurface*>(pSrc);
                const Unk_NXDrawUsage* info = pSurface->vf17();
                s32 width = info->field_14;
                s32 height = info->field_18;
                srcRegion.field_c = width;
                srcRegion.field_10 = height;
                srcTexture = pSurface->vf25();
                srcView = pSurface->vf26();
                Unk_55d3b0_get(reinterpret_cast<const Unk_55d3b0*>(pSurface));
            break;
        }
        case 1: {
                Unk_NXDrawTexture* pTexture = static_cast<Unk_NXDrawTexture*>(pSrc);
                const Unk_NXDrawUsage* info = pTexture->vf19();
                s32 width = info->field_14;
                s32 height = info->field_18;
                srcRegion.field_c = width;
                srcRegion.field_10 = height;
                srcTexture = pTexture->vf40();
                srcView = pTexture->vf41();
            break;
        }
        default:
                srcTexture = nullptr;
                srcView = nullptr;
            break;
        }
        nvnCommandBufferCopyTextureToTexture(commandBuffer, srcTexture, srcView, &srcRegion, dstTexture, dstView, &dstRegion, 0);
    }
    if (own) {
        pList->Unk_53a790();
        pQueue->vf10(1, &pList);
        bool result = pQueue->vf13(pQueue->vf12());
        pQueue->vf9();
        return result;
    }
    return true;
}

// 0x7100541210
SiGfxNXDrawContext::DirectBuffer* SiGfxNXDrawContext::Unk_541210(u32 kind, s32 a2, s32 size, u32 format,
                                                                 Unk_3f00<4>* pMemory) {
    s32 current = field_3e0c;
    FrameDirectBufferArray& frame = field_3e10[kind].m_pData[current];
    DirectBuffer* pBuffer;
    bool found = false;
    if (frame.field_8 >= 0 && frame.field_8 < static_cast<s32>(frame.field_10.m_itemCount)) {
        pBuffer = frame.field_10.m_pData[frame.field_8];
        if (pBuffer != nullptr) {
            if (static_cast<s32>(pBuffer->field_0->vf19()->vf7()->field_0) - pBuffer->field_10 >= size) {
                found = true;
            } else {
                frame.field_8++;
                if (frame.field_8 < static_cast<s32>(frame.field_10.m_itemCount)) {
                    pBuffer = frame.field_10.m_pData[frame.field_8];
                    pBuffer->field_10 = 0;
                    found = true;
                }
            }
        }
    } else {
        pBuffer = nullptr;
    }
    if (!found) {
#line 4247
        DirectBuffer* pNew = UNK_SI_NEW(field_8.m_pAllocator, 0x10) DirectBuffer();
        pNew->field_8 = field_18->vf30(0, nullptr);
        Unk_NXMemoryHeapDesc heapDesc(0x100000, 1);
        switch (kind) {
        case 0:
            heapDesc.field_18 = 4;
            break;
        case 1:
            heapDesc.field_18 = 1;
            break;
        case 2:
            heapDesc.field_18 = 2;
            break;
        }
        heapDesc.field_10 = 2;
        heapDesc.field_1c = 0x10000;
        heapDesc.field_30 = (Unk_563620(10, heapDesc.field_10, heapDesc.field_18, heapDesc.field_1c) & ~7) | 2;
        heapDesc.field_24 = 0x400;
        if (!pNew->field_8->vf8(&heapDesc)) {
            if (pNew->field_8 != nullptr) {
                pNew->field_8->vf3();
                pNew->field_8 = nullptr;
            }
            return nullptr;
        }
        pNew->field_0 = field_18->vf59(nullptr, 0, nullptr);
        SiGfxNXBuffer::Unk_MakeDesc makeDesc(0, 0, 0, 1, 1, 0);
        makeDesc.field_4 = 0x100000;
        makeDesc.field_1c = heapDesc.field_18;
        makeDesc.field_20 = heapDesc.field_1c;
        makeDesc.field_18 = heapDesc.field_10;
        makeDesc.field_0 = format;
        makeDesc.field_38 = pNew->field_8;
        bool failed;
        {
            Unk_NXString<0x400> name(field_8.m_pAllocator);
            if (kind == 1) {
                Unk_4c9090(&name, "DirectMapBuffer::VB_%d_%d", field_3e0c, frame.field_10.m_itemCount);
            } else if (kind == 2) {
                Unk_4c9090(&name, "DirectMapBuffer::IB_%d_%d", field_3e0c, frame.field_10.m_itemCount);
            } else if (kind == 0) {
                Unk_4c9090(&name, "DirectMapBuffer::CB_%d_%d", field_3e0c, frame.field_10.m_itemCount);
            }
            static_cast<Unk_NXBufferNamedObject&>(*pNew->field_0).vf30(Unk_StringCStr(&name));
            if (pNew->field_0->vf21(&makeDesc)) {
                frame.field_8 = frame.field_10.m_itemCount;
                frame.field_10.Unk_Add(pNew);
                failed = false;
            } else {
                if (pNew->field_0 != nullptr) {
                    pNew->field_0->vf3();
                    pNew->field_0 = nullptr;
                }
                if (pNew->field_8 != nullptr) {
                    pNew->field_8->vf3();
                    pNew->field_8 = nullptr;
                }
                failed = true;
            }
        }
        if (failed) {
            return nullptr;
        }
        pBuffer = pNew;
    }
    pMemory->field_20[0] = static_cast<u8*>(nvnBufferMap(pBuffer->field_0->field_d0));
    return pBuffer;
}

// 0x71005416f0
u8* SiGfxNXDrawContext::vf72(u32 a1, u32 stages, s32 slot, s32 size) {
    s32 alignment;
    nvnDeviceGetInteger(field_18->vf85(), 4, &alignment);
    s32 bytes = (alignment + size) / alignment * alignment;
    DirectBuffer* pBuffer = Unk_541210(0, stages, bytes, 0, &field_3f00[0]);
    if (pBuffer == nullptr) {
        return nullptr;
    }
    Unk_DirectBlock& block = Unk_Blocks()[0];
    block.field_0 = pBuffer;
    block.field_8 = pBuffer->field_10;
    block.field_c = bytes;
    u8* memory = field_3f00[0].field_20[0];
    s32 offset = pBuffer->field_10;
    u64 address = pBuffer->field_0->vf27() + pBuffer->field_10;
    u8* result = memory + offset;
    if (stages & 1) {
        field_30.field_508.field_570[0][slot] = address;
        field_30.field_508.field_810[0][slot] = bytes;
        field_30.field_2778[0].Unk_MarkRead(slot);
    }
    if (stages & 2) {
        field_30.field_508.field_570[1][slot] = address;
        field_30.field_508.field_810[1][slot] = bytes;
        field_30.field_2778[1].Unk_MarkRead(slot);
    }
    if (stages & 4) {
        field_30.field_508.field_570[2][slot] = address;
        field_30.field_508.field_810[2][slot] = bytes;
        field_30.field_2778[2].Unk_MarkRead(slot);
    }
    if (stages & 16) {
        field_30.field_508.field_570[3][slot] = address;
        field_30.field_508.field_810[3][slot] = bytes;
        field_30.field_2778[3].Unk_MarkRead(slot);
    }
    if (stages & 8) {
        field_30.field_508.field_570[4][slot] = address;
        field_30.field_508.field_810[4][slot] = bytes;
        field_30.field_2778[4].Unk_MarkRead(slot);
    }
    if (stages & 32) {
        field_30.field_508.field_570[5][slot] = address;
        field_30.field_508.field_810[5][slot] = bytes;
        field_30.field_2778[5].Unk_MarkRead(slot);
    }
    pBuffer->field_10 += bytes;
    return result;
}

// 0x71005419f0
u8* SiGfxNXDrawContext::vf74(s32 slot, s32 count, s32 stride) {
    s32 total = stride * count;
    if (total < 1) {
        return nullptr;
    }
    s32 bytes = (stride + total - 1) / stride * stride;
    DirectBuffer* pBuffer = Unk_541210(1, count, bytes, 0, &field_3f00[1]);
    if (pBuffer == nullptr) {
        return nullptr;
    }
    Unk_DirectBlock& block = Unk_Blocks()[1];
    block.field_0 = pBuffer;
    block.field_8 = pBuffer->field_10;
    block.field_c = bytes;
    u8* memory = field_3f00[1].field_20[0];
    s32 offset = pBuffer->field_10;
    u64 address = pBuffer->field_0->vf27() + pBuffer->field_10;
    field_30.field_20.field_2b0[slot] = 0;
    field_30.field_20.field_370[slot] = 0;
    field_30.field_20.field_330[slot] = stride;
    field_30.field_508.field_290[slot].field_0 = address;
    field_30.field_508.field_290[slot].field_8 = bytes;
    Unk_VertexStreamStateSetDefaults(&field_30.field_508.field_4b0[slot]);
    Unk_VertexStreamStateSetStride(&field_30.field_508.field_4b0[slot], stride);
    field_30.field_508.field_4ac = 0;
    for (s32 i = 0; i < 16; i++) {
        if (field_30.field_508.field_290[i].field_0 != 0) {
            field_30.field_508.field_4ac++;
        }
    }
    field_30.field_2760.Unk_MarkOr(slot);
    field_30.field_0 |= 0x1000;
    u8* result = memory + offset;
    pBuffer->field_10 += bytes;
    return result;
}

// 0x7100541c80
u8* SiGfxNXDrawContext::vf76(u32 format, s32 count) {
    u32 type = format == 0x2a ? 2 : 1;
    s32 elementSize = Unk_4ed0c0(format);
    if (elementSize < 0) {
        return nullptr;
    }
    s32 total = elementSize * count;
    if (total < 1) {
        return nullptr;
    }
    s32 alignment = format == 0x2a ? 4 : (format == 0x39 ? 2 : 0);
    s32 bytes = (total + alignment) / alignment * alignment;
    DirectBuffer* pBuffer = Unk_541210(2, count, bytes, format, reinterpret_cast<Unk_3f00<4>*>(&field_3f80));
    if (pBuffer == nullptr) {
        return nullptr;
    }
    Unk_DirectBlock& block = Unk_Blocks()[2];
    block.field_0 = pBuffer;
    block.field_8 = pBuffer->field_10;
    block.field_c = bytes;
    u8* result = field_3f80.field_20[0] + pBuffer->field_10;
    u64 address = pBuffer->field_0->vf27() + pBuffer->field_10;
    field_30.field_20.field_3b0 = nullptr;
    field_30.field_20.field_3b8 = 0;
    field_30.field_508.field_39c = elementSize;
    field_30.field_508.field_390 = address;
    field_30.field_508.field_398 = type;
    field_30.field_0 |= 8;
    pBuffer->field_10 += bytes;
    return result;
}

// 0x7100541db0
void SiGfxNXDrawContext::vf98(SiGfxNXCommandList* pCommandList) {
    if (pCommandList != nullptr) {
        field_28 = pCommandList;
        field_3a60 = pCommandList->vf15();
    } else {
        field_28 = nullptr;
        field_3a60 = nullptr;
    }
}

// 0x7100541e00
void SiGfxNXDrawContext::vf99(const void* pool) {
    nvnCommandBufferSetTexturePool(field_3a60, pool);
}

// 0x7100541e20
void SiGfxNXDrawContext::vf100(const void* pool) {
    nvnCommandBufferSetSamplerPool(field_3a60, pool);
}

// 0x7100541e40
void SiGfxNXDrawContext::vf101() {
    Unk_4fb320_update(reinterpret_cast<const Unk_4fb320*>(field_18), reinterpret_cast<u64>(field_3a60));
}

// The handles slot 78 binds: none.
// 0x710276eeb0
static u64 Unk_276eeb0[32];

inline void SiGfxNXDrawContext::Unk_UnbindTextures(void* commandBuffer, s32 stage, s32 first, s32 count) {
    nvnCommandBufferBindTextures(commandBuffer, stage, first, count, Unk_276eeb0);
    memset(&field_30.field_508.field_d50[first], 0, count * sizeof(u32));
    field_30.field_2808[stage].Unk_MarkRange(first, first + count - 1);
}

// 0x7100541e60
void SiGfxNXDrawContext::vf78(u32 stages, s32 first, s32 count) {
    if (count == 0) {
        return;
    }
    s32 n = first + count > 32 || count < 0 ? 32 - first : count;
    if (static_cast<u32>(first) >= 32) {
        return;
    }
    void* commandBuffer = field_3a60;
    if (stages & 1) {
        Unk_UnbindTextures(commandBuffer, 0, first, n);
    }
    if (stages & 2) {
        Unk_UnbindTextures(commandBuffer, 1, first, n);
    }
    if (stages & 4) {
        Unk_UnbindTextures(commandBuffer, 2, first, n);
    }
    if (stages & 0x10) {
        Unk_UnbindTextures(commandBuffer, 3, first, n);
    }
    if (stages & 8) {
        Unk_UnbindTextures(commandBuffer, 4, first, n);
    }
    if (stages & 0x20) {
        Unk_UnbindTextures(commandBuffer, 5, first, n);
    }
}

// 0x7100542260
void SiGfxNXDrawContext::vf83(bool more) {
    if (more) {
        field_3a68++;
    } else if (field_3a68 > 0) {
        field_3a68--;
    }
}

// 0x7100542300
void SiGfxNXDrawContext::vf91(u32 a1, u32 stages, s32 slot, ISiGfxResource* pResource, s32 offset, s32 size) {
    if (pResource == nullptr) {
        return;
    }
    if (pResource->vf8()->field_0 != 10) {
        return;
    }
    Unk_NXDrawTexture* pBuffer = static_cast<Unk_NXDrawTexture*>(pResource);
    u64 base = pBuffer->field_100;
    s32 bufferSize = pBuffer->field_bc;
    s32 bytes = size < 1 ? bufferSize : size;
    if (base == 0) {
        return;
    }
    u64 address = base + (pBuffer->field_154 * bufferSize + offset);
    field_30.field_29d0[slot] = stages;
    if (stages & 1) {
        field_30.field_508.field_570[0][slot] = address;
        field_30.field_508.field_810[0][slot] = bytes;
        field_30.field_2778[0].Unk_MarkRead(slot);
    }
    if (stages & 2) {
        field_30.field_508.field_570[1][slot] = address;
        field_30.field_508.field_810[1][slot] = bytes;
        field_30.field_2778[1].Unk_MarkRead(slot);
    }
    if (stages & 4) {
        field_30.field_508.field_570[2][slot] = address;
        field_30.field_508.field_810[2][slot] = bytes;
        field_30.field_2778[2].Unk_MarkRead(slot);
    }
    if (stages & 16) {
        field_30.field_508.field_570[3][slot] = address;
        field_30.field_508.field_810[3][slot] = bytes;
        field_30.field_2778[3].Unk_MarkRead(slot);
    }
    if (stages & 16) {
        field_30.field_508.field_570[4][slot] = address;
        field_30.field_508.field_810[4][slot] = bytes;
        field_30.field_2778[4].Unk_Mark(slot);
    }
    if (stages & 32) {
        field_30.field_508.field_570[5][slot] = address;
        field_30.field_508.field_810[5][slot] = bytes;
        field_30.field_2778[5].Unk_MarkRead(slot);
    }
}

// NON_MATCHING: the last call of slot 8 (its result unused) is a tail call
// here; the original calls it and returns. Tried: slot 8 returning a
// reference (the README's dereferenceable case): still a tail call. (Codegen
// only keeps the call if the IR has a load or another unspeculatable
// instruction between it and the return, or the call isn't marked `tail`,
// which an escaping local at TailCallElim would do.)
// 0x7100542570
void SiGfxNXDrawContext::vf92(u32 a1, u32 stages, s32 slot, ISiGfxResource* pResource) {
    if (pResource == nullptr) {
        return;
    }
    field_30.field_2a08[slot] = stages;
    if (pResource->vf8()->field_0 == 1) {
        field_30.field_508.field_d50[slot] = static_cast<Unk_NXDrawTexture*>(pResource)->vf43();
        field_3a70.field_190[slot] = pResource;
        if (stages & 1) {
            field_30.field_2808[0].Unk_MarkRead(slot);
        }
        if (stages & 2) {
            field_30.field_2808[1].Unk_MarkRead(slot);
        }
        if (stages & 4) {
            field_30.field_2808[2].Unk_MarkRead(slot);
        }
        if (stages & 16) {
            field_30.field_2808[3].Unk_MarkRead(slot);
        }
        if (stages & 8) {
            field_30.field_2808[4].Unk_MarkRead(slot);
        }
        if (stages & 32) {
            field_30.field_2808[5].Unk_MarkRead(slot);
        }
    }
    // (what it does with a buffer isn't in the executable)
    if (pResource->vf8()->field_0 == 10) {
    }
}

// 0x71005427a0
void SiGfxNXDrawContext::vf94(u32 a1, u32 value, s32 slot, Unk_5427a0_Object* pObject) {
    u32 bound = pObject->vf19();
    if (bound == field_30.field_508.field_e50[slot]) {
        return;
    }
    field_30.field_2b40[slot] = value;
    field_30.field_508.field_e50[slot] = bound;
    field_30.Unk_MarkSlot(slot);
}

// Where a kind's values are in field_30.field_508.field_1c50 (inline in slot 95: placeholder
// name).
static inline size_t Unk_ValuesIndex(u32 kind) {
    switch (kind) {
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 4;
    case 5:
        return 3;
    case 6:
        return 5;
    default:
        return 0;
    }
}

// 0x7100542840
void SiGfxNXDrawContext::vf95(u32 kind, s32 index, s32 count, const u32* values) {
    memcpy(&field_30.field_508.field_1c50[Unk_ValuesIndex(kind)][index], values, count * sizeof(u32));
}

}  // namespace SiSDK3

// 0x7100542c80 (see the top of the file); 0x7100542e80, the arrays' reserve,
// is instantiated by Unk_53b750 (it calls this release, out of line here).
template void SiSDK3::SiArray<SiSDK3::SiGfxNXDrawContext::FrameDirectBufferArray, 16>::Unk_4e3050();
