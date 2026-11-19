// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: command buffers. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// 0x7101787e40
static void Unk_1787e40(void* commandBuffer, int event, size_t minSize, void* data) {
    Unk_1787d90_CommandBuffer* self = static_cast<Unk_1787d90_CommandBuffer*>(data);
    Unk_1787d90_Event arg;
    arg.field_0 = minSize;
    switch (event) {
    case 0:
        self->field_d0(self, &arg);
        break;
    case 1:
        self->field_d8(self, &arg);
        break;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

// 0x7101787d90
void Unk_1787d90(Unk_1787d90_CommandBuffer* self, Unk_1791080_Device* device) {
    self->field_8 = device;
    void* nvnDevice = device->field_0;
    self->field_b8 = self->field_18;
    nvnCommandBufferInitialize(self->field_b8, nvnDevice);
    self->field_d0 = nullptr;
    self->field_d8 = nullptr;
    nvnCommandBufferSetMemoryCallback(self->field_b8, Unk_1787e40);
    nvnCommandBufferSetMemoryCallbackData(self->field_b8, self);
    self->field_c0 = 0;
    self->field_1.Set(2, (device->field_300c & 8) != 0);
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// 0x7101787ea0
void Unk_1787ea0(Unk_1787d90_CommandBuffer* self) {
    if (self->field_c0 != 0) {
        nvnDeviceFinalizeCommandHandle(self->field_8->field_0, self->field_c0);
        self->field_c0 = 0;
    }
    nvnCommandBufferFinalize(self->field_b8);
    self->field_0 = 0;
}

// 0x7101787f00
void Unk_1787f00(Unk_1787d90_CommandBuffer* self, const Unk_1787ac0_Pool* pool, s64 offset, size_t size) {
    nvnCommandBufferAddCommandMemory(self->field_b8, pool->field_0, offset, size);
}

// 0x7101787f20
void Unk_1787f20(Unk_1787d90_CommandBuffer* self, void* memory, size_t size) {
    nvnCommandBufferAddControlMemory(self->field_b8, memory, size);
}

// 0x7101787f70
void Unk_1787f70(Unk_1787d90_CommandBuffer* self) {
    if (self->field_c0 != 0) {
        nvnDeviceFinalizeCommandHandle(self->field_8->field_0, self->field_c0);
        self->field_c0 = 0;
    }
    nvnCommandBufferBeginRecording(self->field_b8);
    self->field_0 = 2;
}

// 0x7101787fd0
void Unk_1787fd0(Unk_1787d90_CommandBuffer* self) {
    self->field_c0 = nvnCommandBufferEndRecording(self->field_b8);
    self->field_0 = 1;
}

// 0x7101788010
void Unk_1788010(Unk_1787d90_CommandBuffer* self, int x, int y, int z) {
    nvnCommandBufferDispatchCompute(self->field_b8, x, y, z);
}

// 0x7101788030
void Unk_1788030(Unk_1787d90_CommandBuffer* self, int topology, int vertexCount, int vertexOffset) {
    nvnCommandBufferDrawArrays(self->field_b8, Unk_178d6b0(topology), vertexOffset, vertexCount);
}

// 0x7101788080
void Unk_1788080(Unk_1787d90_CommandBuffer* self, int topology, int vertexCount, int vertexOffset,
                 int instanceCount, int baseInstance) {
    nvnCommandBufferDrawArraysInstanced(self->field_b8, Unk_178d6b0(topology), vertexOffset, vertexCount, baseInstance,
                instanceCount);
}

// 0x71017880f0
void Unk_17880f0(void* self, u32 topology, u32 indexFormat, void* indexBuffer, u32 indexCount,
                 u32 baseVertex) {
    void* commandBuffer = static_cast<Unk_1787d90_CommandBuffer*>(self)->field_b8;
    int mode = Unk_178d6b0(topology);
    int type = Unk_178d710(indexFormat);
    nvnCommandBufferDrawElementsBaseVertex(commandBuffer, mode, type, indexCount,
                Unk_178d730(*static_cast<Unk_178d730_Address*>(indexBuffer)), baseVertex);
}

// 0x7101788170
void Unk_1788170(Unk_1787d90_CommandBuffer* self, int topology, int indexFormat,
                 const Unk_178d730_Address* indexBuffer, int indexCount, int baseVertex,
                 int instanceCount, int baseInstance) {
    void* commandBuffer = self->field_b8;
    int mode = Unk_178d6b0(topology);
    int type = Unk_178d710(indexFormat);
    nvnCommandBufferDrawElementsInstanced(commandBuffer, mode, type, indexCount, Unk_178d730(*indexBuffer), baseVertex,
                baseInstance, instanceCount);
}

// 0x7101788210
void Unk_1788210(Unk_1787d90_CommandBuffer* self, const Unk_1788210_State* state) {
    nvnCommandBufferBindPolygonState(self->field_b8, state);
    nvnCommandBufferSetPolygonOffsetClamp(self->field_b8, state->field_28, state->field_20,
                                          state->field_24);
    nvnCommandBufferBindMultisampleState(self->field_b8, state->field_4);
    if (state->field_2d.Test(1)) {
        nvnCommandBufferSetSampleMask(self->field_b8, state->field_1c);
    }
    nvnCommandBufferSetDepthClamp(self->field_b8, !state->field_2d.GetBit(1));
    nvnCommandBufferSetRasterizerDiscard(self->field_b8, !state->field_2d.GetBit(2));
    if (self->field_1.Test(2)) {
        nvnCommandBufferSetConservativeRasterEnable(self->field_b8, state->field_2d.GetBit(3));
    }
}

// 0x7101788310
void Unk_1788310(Unk_1787d90_CommandBuffer* self, const Unk_1788310_State* state) {
    int count = state->field_25;
    const u64* blendStates = state->field_0;
    for (int i = 0; i < count; ++i) {
        nvnCommandBufferBindBlendState(self->field_b8, &blendStates[i]);
    }
    nvnCommandBufferBindChannelMaskState(self->field_b8, &state->field_c);
    nvnCommandBufferBindColorState(self->field_b8, &state->field_8);
    nvnCommandBufferSetBlendColor(self->field_b8, state->field_10);
}

// 0x71017883c0
void Unk_17883c0(Unk_1787d90_CommandBuffer* self, const Unk_17883c0_State* state) {
    nvnCommandBufferBindDepthStencilState(self->field_b8, state);
    nvnCommandBufferSetStencilValueMask(self->field_b8, 3, state->field_8);
    nvnCommandBufferSetStencilMask(self->field_b8, 3, state->field_c);
    nvnCommandBufferSetStencilRef(self->field_b8, 2, state->field_10);
    nvnCommandBufferSetStencilRef(self->field_b8, 1, state->field_14);
    if (!(state->field_1a & 8)) {
        nvnCommandBufferSetDepthBounds(self->field_b8, false, 0.0f, 1.0f);
    }
}

struct Unk_17884a0_State {
    u32 _0;
    u32 field_4;
    u32 field_8;
    u8 _c[0x4];
    const void* field_10;
    const void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_17884a0_State, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_17884a0_State, field_18, 0x18);

// 0x71017884a0
void Unk_17884a0(Unk_1787d90_CommandBuffer* self, const Unk_17884a0_State* state) {
    nvnCommandBufferBindVertexAttribState(self->field_b8, state->field_8, state->field_18);
    nvnCommandBufferBindVertexStreamState(self->field_b8, state->field_4, state->field_10);
}

// A shader: flags (bit 0: the stages come from the caller), its stages and
// its NVN program.
struct Unk_1788500_Shader {
    u8 _0;
    Unk_1787ac0_Flags field_1;
    u8 _2[0x2];
    u32 field_4;
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1788500_Shader, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1788500_Shader, field_8, 0x8);

// 0x7101788500
void Unk_1788500(Unk_1787d90_CommandBuffer* self, const Unk_1788500_Shader* shader, int stages) {
    void* program = nullptr;
    int nvnStages;
    if (shader != nullptr) {
        program = shader->field_8;
    }
    if (shader != nullptr && !shader->field_1.Test(1)) {
        nvnStages = shader->field_4;
    } else {
        nvnStages = Unk_178d6d0(stages);
    }
    nvnCommandBufferBindProgram(self->field_b8, program, nvnStages);
}

// A color target or depth stencil view: its NVN texture and texture view.
struct Unk_1788560_View {
    u8 _0[0x8];
    void* field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1788560_View, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1788560_View, field_10, 0x10);

// 0x7101788560
void Unk_1788560(Unk_1787d90_CommandBuffer* self, int count, const Unk_1788560_View* const* colors,
                 const Unk_1788560_View* depthStencil) {
    void* textures[8] = {};
    void* views[8] = {};
    for (int i = 0; i < count; ++i) {
        if (colors[i] != nullptr) {
            textures[i] = colors[i]->field_8;
            views[i] = colors[i]->field_10;
        }
    }
    void* depthTexture;
    void* depthView;
    if (depthStencil != nullptr) {
        depthTexture = depthStencil->field_8;
        depthView = depthStencil->field_10;
    } else {
        depthTexture = nullptr;
        depthView = nullptr;
    }
    nvnCommandBufferSetRenderTargets(self->field_b8, count, textures, views, depthTexture, depthView);
}

// 0x7101788610
void Unk_1788610(Unk_1787d90_CommandBuffer* self, int index, const Unk_178d730_Address* address,
                 s64 stride, size_t size) {
    nvnCommandBufferBindVertexBuffer(self->field_b8, index, Unk_178d730(*address), size);
}

// A viewport scissor state: the first viewport, depth range and scissor, and
// the others (viewports, then depth ranges, then scissors) in one array.
struct Unk_1788660_Viewport {
    f32 field_0[4];
};
struct Unk_1788660_DepthRange {
    f32 field_0[2];
};
struct Unk_1788660_Scissor {
    s32 field_0[4];
};
struct Unk_1788660_State {
    const Unk_1788660_Viewport* field_0;
    s32 field_8;
    u8 _c[0x4];
    f32 field_10[4];
    f64 field_20;
    f64 field_28;
    s32 field_30[4];
};
PKMN_OFFSET_ASSERT(Unk_1788660_State, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1788660_State, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1788660_State, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1788660_State, field_30, 0x30);

// 0x7101788660
void Unk_1788660(Unk_1787d90_CommandBuffer* self, const Unk_1788660_State* state) {
    nvnCommandBufferSetDepthRange(self->field_b8, static_cast<f32>(state->field_20),
                                  static_cast<f32>(state->field_28));
    nvnCommandBufferSetViewports(self->field_b8, 0, 1, state->field_10);
    nvnCommandBufferSetScissors(self->field_b8, 0, 1, state->field_30);
    if (state->field_8 > 1) {
        int extraCount = state->field_8 - 1;
        const Unk_1788660_Viewport* viewports = state->field_0;
        const Unk_1788660_DepthRange* depthRanges =
            reinterpret_cast<const Unk_1788660_DepthRange*>(viewports + extraCount);
        const Unk_1788660_Scissor* scissors =
            reinterpret_cast<const Unk_1788660_Scissor*>(depthRanges + extraCount);
        nvnCommandBufferSetViewports(self->field_b8, 1, extraCount, viewports->field_0);
        nvnCommandBufferSetDepthRanges(self->field_b8, 1, extraCount, depthRanges->field_0);
        nvnCommandBufferSetScissors(self->field_b8, 1, extraCount, scissors->field_0);
    }
}

// 0x7101788770
void Unk_1788770(Unk_1787d90_CommandBuffer* self, const Unk_1787ac0_Buffer* dst, s64 dstOffset,
                 const Unk_1787ac0_Buffer* src, s64 srcOffset, size_t size) {
    u64 srcAddress = nvnBufferGetAddress(src->field_8) + srcOffset;
    u64 dstAddress = nvnBufferGetAddress(dst->field_8) + dstOffset;
    nvnCommandBufferCopyBufferToBuffer(self->field_b8, srcAddress, dstAddress, size, 0);
}

// A texture: its NVN texture.
struct Unk_17887f0_Texture {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_17887f0_Texture, field_8, 0x8);

// A subresource: mip level and array index.
struct Unk_17887f0_Subresource {
    u16 field_0;
    u8 _2[0x2];
    s32 field_4;
};
PKMN_SIZE_ASSERT(Unk_17887f0_Subresource, 0x8);

// A texture copy region: offsets, size, subresource and array length.
struct Unk_17887f0_Region {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
    Unk_17887f0_Subresource field_18;
    s32 field_20;
};
PKMN_SIZE_ASSERT(Unk_17887f0_Region, 0x24);

// NVN's copy region.
struct Unk_17887f0_NvnRegion {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
};
PKMN_SIZE_ASSERT(Unk_17887f0_NvnRegion, 0x18);

static inline int Unk_17887f0_Max(int a, int b) {
    return a < b ? b : a;
}

// Array textures keep their layers in y (1D arrays) or z (2D arrays).
// NON_MATCHING: the functions that inline this test the array targets with
// `cmp #6; ccmp #4` (the second copy in Unk_1788d40 with two `cmp; b.eq`);
// clang folds `target == 6 || target == 4` to `(target | 2) == 6`, and a
// switch with the two cases gives two branches that aren't made a ccmp. The
// rest of the four functions matches.
static inline void Unk_17887f0_ToNvn(Unk_17887f0_NvnRegion* out, const Unk_17887f0_Region& in,
                                     int target) {
    int y = in.field_4;
    int height = in.field_10;
    int z;
    int depth;
    if (target == 6 || target == 4) {
        z = in.field_18.field_4;
        depth = Unk_17887f0_Max(1, in.field_20);
    } else {
        z = in.field_8;
        depth = in.field_14;
        if (target == 3) {
            y = in.field_18.field_4;
            height = Unk_17887f0_Max(1, in.field_20);
        }
    }
    out->field_0 = in.field_0;
    out->field_4 = y;
    out->field_8 = z;
    out->field_c = in.field_c;
    out->field_10 = height;
    out->field_14 = depth;
}

// 0x71017887f0
void Unk_17887f0(Unk_1787d90_CommandBuffer* self, const Unk_17887f0_Texture* dst,
                 const Unk_17887f0_Subresource* dstSubresource, int dstU, int dstV, int dstW,
                 const Unk_17887f0_Texture* src, const Unk_17887f0_Region* srcRegion) {
    Unk_17887f0_NvnRegion nvnSrcRegion;
    Unk_17887f0_NvnRegion nvnDstRegion;
    u8 srcView[0x28];
    u8 dstView[0x28];
    int srcTarget = nvnTextureGetTarget(src->field_8);
    int dstTarget = nvnTextureGetTarget(dst->field_8);
    Unk_17887f0_ToNvn(&nvnSrcRegion, *srcRegion, srcTarget);
    nvnDstRegion.field_0 = dstU;
    nvnDstRegion.field_4 = dstTarget == 3 ? dstSubresource->field_4 : dstV;
    nvnDstRegion.field_8 = dstTarget == 4 || dstTarget == 6 ? dstSubresource->field_4 : dstW;
    nvnDstRegion.field_c = nvnSrcRegion.field_c;
    nvnDstRegion.field_10 = nvnSrcRegion.field_10;
    nvnDstRegion.field_14 = nvnSrcRegion.field_14;
    nvnTextureViewSetDefaults(srcView);
    nvnTextureViewSetLevels(srcView, srcRegion->field_18.field_0, 1);
    nvnTextureViewSetDefaults(dstView);
    nvnTextureViewSetLevels(dstView, dstSubresource->field_0, 1);
    nvnCommandBufferCopyTextureToTexture(self->field_b8, src->field_8, srcView, &nvnSrcRegion,
                                         dst->field_8, dstView, &nvnDstRegion, 0);
}

// A buffer texture copy region: the buffer offset and image size, then the
// texture's region.
struct Unk_1788980_Region {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    Unk_17887f0_Region field_c;
};
PKMN_SIZE_ASSERT(Unk_1788980_Region, 0x30);

int Unk_178da40(u32 format);

// The row stride of a buffer image: its width (the region's if it has none) in
// bytes, or in blocks of a compressed format.
static inline int Unk_1788980_RowStride(const Unk_1788980_Region* region, const void* texture) {
    if (region->field_4 == 0 && region->field_8 == 0) {
        return 0;
    }
    int format = Unk_178da40(nvnTextureGetFormat(texture)) >> 8;
    int imageWidth = region->field_4;
    int copyWidth = region->field_c.field_c;
    int rowStride = (imageWidth != 0 ? imageWidth : copyWidth) * Unk_17877c0(format);
    if (Unk_17877b0(format)) {
        rowStride /= Unk_1787750(format) * Unk_1787780(format);
    }
    return rowStride;
}

// 0x7101788980
void Unk_1788980(Unk_1787d90_CommandBuffer* self, const Unk_17887f0_Texture* dst,
                 const Unk_1787ac0_Buffer* src, const Unk_1788980_Region* region) {
    Unk_17887f0_NvnRegion nvnRegion;
    u8 view[0x28];
    int target = nvnTextureGetTarget(dst->field_8);
    Unk_17887f0_ToNvn(&nvnRegion, region->field_c, target);
    nvnTextureViewSetDefaults(view);
    nvnTextureViewSetLevels(view, region->field_c.field_18.field_0, 1);
    u64 address = nvnBufferGetAddress(src->field_8) + region->field_0;
    int rowStride = Unk_1788980_RowStride(region, dst->field_8);
    int imageStride = region->field_8 != 0 ? region->field_8 * rowStride : 0;
    nvnCommandBufferSetCopyRowStride(self->field_b8, rowStride);
    nvnCommandBufferSetCopyImageStride(self->field_b8, imageStride);
    nvnCommandBufferCopyBufferToTexture(self->field_b8, address, dst->field_8, view, &nvnRegion, 0);
}

// 0x7101788b60
void Unk_1788b60(Unk_1787d90_CommandBuffer* self, const Unk_1787ac0_Buffer* dst,
                 const Unk_17887f0_Texture* src, const Unk_1788980_Region* region) {
    Unk_17887f0_NvnRegion nvnRegion;
    u8 view[0x28];
    int target = nvnTextureGetTarget(src->field_8);
    Unk_17887f0_ToNvn(&nvnRegion, region->field_c, target);
    nvnTextureViewSetDefaults(view);
    nvnTextureViewSetLevels(view, region->field_c.field_18.field_0, 1);
    u64 address = nvnBufferGetAddress(dst->field_8) + region->field_0;
    int rowStride = Unk_1788980_RowStride(region, src->field_8);
    int imageStride = region->field_8 != 0 ? region->field_8 * rowStride : 0;
    nvnCommandBufferSetCopyRowStride(self->field_b8, rowStride);
    nvnCommandBufferSetCopyImageStride(self->field_b8, imageStride);
    nvnCommandBufferCopyTextureToBuffer(self->field_b8, src->field_8, view, &nvnRegion, address, 0);
}

// 0x7101788d40
void Unk_1788d40(Unk_1787d90_CommandBuffer* self, const Unk_17887f0_Texture* dst,
                 const Unk_17887f0_Region* dstRegion, const Unk_17887f0_Texture* src,
                 const Unk_17887f0_Region* srcRegion, int copyFlags) {
    Unk_17887f0_NvnRegion nvnDstRegion;
    Unk_17887f0_NvnRegion nvnSrcRegion;
    u8 dstView[0x28];
    u8 srcView[0x28];
    Unk_17887f0_ToNvn(&nvnDstRegion, *dstRegion, nvnTextureGetTarget(dst->field_8));
    Unk_17887f0_ToNvn(&nvnSrcRegion, *srcRegion, nvnTextureGetTarget(src->field_8));
    nvnTextureViewSetDefaults(dstView);
    nvnTextureViewSetLevels(dstView, dstRegion->field_18.field_0, 1);
    nvnTextureViewSetDefaults(srcView);
    nvnTextureViewSetLevels(srcView, srcRegion->field_18.field_0, 1);
    nvnCommandBufferCopyTextureToTexture(self->field_b8, src->field_8, srcView, &nvnSrcRegion,
                                         dst->field_8, dstView, &nvnDstRegion, copyFlags & 1);
}

void Unk_1788f20(Unk_1787d90_CommandBuffer* self, const Unk_1788560_View* view, const f32* color,
                 const s32* range);

// 0x7101788ef0
void Unk_1788ef0(Unk_1787d90_CommandBuffer* self, const Unk_1788560_View* view, f32 red,
                 f32 green, f32 blue, f32 alpha, const s32* range) {
    f32 color[4] = {red, green, blue, alpha};
    Unk_1788f20(self, view, color, range);
}

// 0x7101788f20
void Unk_1788f20(Unk_1787d90_CommandBuffer* self, const Unk_1788560_View* view, const f32* color,
                 const s32* range) {
    void* texture = view->field_8;
    void* textureView = view->field_10;
    Unk_17887f0_NvnRegion region = {};
    int baseLevel = 0;
    int target;
    int numLayers = 0;
    int numLevels;
    int minLayer;
    bool hasLayers;
    if (textureView != nullptr) {
        nvnTextureViewGetLevels(textureView, &baseLevel, &numLevels);
        nvnTextureViewGetTarget(textureView, &target);
        hasLayers = nvnTextureViewGetLayers(textureView, &minLayer, &numLayers) == 1;
    } else {
        target = nvnTextureGetTarget(texture);
        hasLayers = false;
    }
    region.field_c = nvnTextureGetWidth(texture);
    region.field_10 = nvnTextureGetHeight(texture);
    region.field_14 = nvnTextureGetDepth(texture);
    region.field_c = Unk_17887f0_Max(1, region.field_c >> baseLevel);
    if (target != 0 && target != 3) {
        region.field_10 = Unk_17887f0_Max(1, region.field_10 >> baseLevel);
        if (target == 2) {
            region.field_14 = Unk_17887f0_Max(1, region.field_14 >> baseLevel);
            if (hasLayers) {
                region.field_14 = numLayers;
            }
        }
    }
    if (range != nullptr) {
        if (target == 3) {
            region.field_4 = range[0];
            region.field_10 = range[1];
        } else if (target == 4 || target == 6) {
            region.field_8 = range[0];
            region.field_14 = range[1];
        }
    } else if (hasLayers) {
        if (target == 3) {
            region.field_10 = numLayers;
        } else if (target == 4 || target == 6) {
            region.field_14 = numLayers;
        }
    }
    nvnCommandBufferClearTexture(self->field_b8, texture, textureView, &region, color, 0xf);
}

// 0x7101789130
void Unk_1789130(Unk_1787d90_CommandBuffer* self, const Unk_1788560_View* view, f32 depth,
                 int stencil, int mode) {
    void* texture = view->field_8;
    void* textureView = view->field_10;
    nvnCommandBufferSetScissor(self->field_b8, 0, 0, 0x7fffffff, 0x7fffffff);
    nvnCommandBufferSetRenderTargets(self->field_b8, 0, nullptr, nullptr, texture, textureView);
    switch (mode) {
    case 1:
        nvnCommandBufferClearDepthStencil(self->field_b8, depth, true, stencil, 0);
        break;
    case 2:
        nvnCommandBufferClearDepthStencil(self->field_b8, depth, false, stencil, -1);
        break;
    case 3:
        nvnCommandBufferClearDepthStencil(self->field_b8, depth, true, stencil, -1);
        break;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

// 0x7101789250
void Unk_1789250(Unk_1787d90_CommandBuffer* self, const Unk_17887f0_Texture* dst, int dstArrayIndex,
                 const void* dstRegion, const Unk_17887f0_Texture* src) {
    void* srcTexture = src->field_8;
    nvnCommandBufferDownsample(self->field_b8, srcTexture, dst->field_8);
}

// 0x7101789270
void Unk_1789270(Unk_1787d90_CommandBuffer* self, int gpuAccess) {
    if (gpuAccess & 0x49c0) {
        nvnCommandBufferBarrier(self->field_b8, 1);
    }
}

// 0x71017892a0
void Unk_17892a0(Unk_1787d90_CommandBuffer* self, int gpuAccess) {
    int barrier = ((gpuAccess & 0x4020) ? 0x10 : 0) | ((gpuAccess & 0x200) ? 0x8 : 0) |
                  ((gpuAccess & 0x1000) ? 0x40 : 0) | ((gpuAccess & 0x2050) ? 0x20 : 0);
    if (barrier != 0) {
        nvnCommandBufferBarrier(self->field_b8, barrier);
    }
}

// 0x71017892f0
void Unk_17892f0(Unk_1787d90_CommandBuffer* self, const Unk_1787d90_CommandBuffer* commands) {
    u64 handle = commands->field_c0;
    nvnCommandBufferCallCommands(self->field_b8, 1, &handle);
}

// A descriptor pool: its type (1: textures, 2: samplers) and its NVN pool.
struct Unk_1789330_Pool {
    u8 _0;
    u8 field_1;
    u8 _2[0xe];
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1789330_Pool, field_10, 0x10);

// 0x7101789330
void Unk_1789330(Unk_1787d90_CommandBuffer* self, const Unk_1789330_Pool* pool) {
    switch (pool->field_1) {
    case 1:
        nvnCommandBufferSetTexturePool(self->field_b8, pool->field_10);
        break;
    case 2:
        nvnCommandBufferSetSamplerPool(self->field_b8, pool->field_10);
        break;
    }
}

// 0x7101789380
void Unk_1789380(Unk_1787d90_CommandBuffer* self, const Unk_178d730_Address* address) {
    nvnCommandBufferReportCounter(self->field_b8, 0, Unk_178d730(*address));
}

// 0x71017893c0
void Unk_17893c0(Unk_1787d90_CommandBuffer* self, f32 width) {
    nvnCommandBufferSetLineWidth(self->field_b8, width);
}

// A viewport: origin, size and depth range.
struct Unk_17893e0_Viewport {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    u8 _18[0x18];
};
PKMN_SIZE_ASSERT(Unk_17893e0_Viewport, 0x30);

// 0x71017893e0
void Unk_17893e0(Unk_1787d90_CommandBuffer* self, int first, int count,
                 const Unk_17893e0_Viewport* viewports) {
    f32 nvnViewports[16 * 4];
    f32 nvnDepthRanges[16 * 2];
    f32* viewport = nvnViewports;
    f32* depthRange = nvnDepthRanges;
    for (int i = 0; i < count; ++i) {
        *viewport++ = viewports[i].field_0;
        *viewport++ = viewports[i].field_4;
        *viewport++ = viewports[i].field_8;
        *viewport++ = viewports[i].field_c;
        *depthRange++ = viewports[i].field_10;
        *depthRange++ = viewports[i].field_14;
    }
    nvnCommandBufferSetViewports(self->field_b8, first, count, nvnViewports);
    nvnCommandBufferSetDepthRanges(self->field_b8, first, count, nvnDepthRanges);
}

// A scissor: origin and size.
struct Unk_17894b0_Scissor {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    u8 _10[0x10];
};
PKMN_SIZE_ASSERT(Unk_17894b0_Scissor, 0x20);

// 0x71017894b0
void Unk_17894b0(Unk_1787d90_CommandBuffer* self, int first, int count,
                 const Unk_17894b0_Scissor* scissors) {    s32 nvnScissors[16 * 4];
    s32* rect = nvnScissors;
    for (int i = 0; i < count; ++i) {
        *rect++ = scissors[i].field_0;
        *rect++ = scissors[i].field_4;
        *rect++ = scissors[i].field_8;
        *rect++ = scissors[i].field_c;
    }
    nvnCommandBufferSetScissors(self->field_b8, first, count, nvnScissors);
}

// A buffer descriptor: its GPU address and size.
struct Unk_1789530_BufferDescriptor {
    u64 field_0;
    u64 field_8;
};

// A descriptor slot: a pointer (buffers) or an NVN descriptor id.
struct Unk_1789530_Slot {
    u64 field_0;
};

int Unk_178d6c0(u32 stage);

// 0x7101789530
void Unk_1789530(Unk_1787d90_CommandBuffer* self, int index, int stage,
                 const Unk_1789530_Slot* slot) {
    const Unk_1789530_BufferDescriptor* descriptor =
        reinterpret_cast<const Unk_1789530_BufferDescriptor*>(slot->field_0);
    u64 address = descriptor->field_0;
    u64 size = descriptor->field_8;
    nvnCommandBufferBindUniformBuffer(self->field_b8, Unk_178d6c0(stage), index, address, size);
}

// 0x7101789590
void Unk_1789590(Unk_1787d90_CommandBuffer* self, int index, int stage,
                 const Unk_1789530_Slot* texture, const Unk_1789530_Slot* sampler) {
    u64 handle = nvnDeviceGetTextureHandle(self->field_8->field_0, texture->field_0,
                                           sampler->field_0);
    nvnCommandBufferBindTexture(self->field_b8, Unk_178d6c0(stage), index, handle);
}

// 0x7101789610
void Unk_1789610(Unk_1787d90_CommandBuffer* self, int index, int stage,
                 const Unk_1789530_Slot* texture) {
    u64 handle = nvnDeviceGetTexelFetchHandle(self->field_8->field_0, texture->field_0);
    nvnCommandBufferBindTexture(self->field_b8, Unk_178d6c0(stage), index, handle);
}

// 0x7101789690
void Unk_1789690(Unk_1787d90_CommandBuffer* self, int index, int stage,
                 const Unk_178d730_Address* address, size_t size) {
    nvnCommandBufferBindUniformBuffer(self->field_b8, Unk_178d6c0(stage), index,
                                      Unk_178d730(*address), size);
}

// 0x7101789700
void Unk_1789700(Unk_1787d90_CommandBuffer* self, int index, int stage,
                 const Unk_178d730_Address* address, size_t size) {
    nvnCommandBufferBindStorageBuffer(self->field_b8, Unk_178d6c0(stage), index,
                                      Unk_178d730(*address), size);
}
