// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: the render state objects (rasterizer, blend
// and depth stencil states). Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

int Unk_178d630(u32 value);
int Unk_178d640(u32 value);
int Unk_178d650(u32 value);
int Unk_178d660(u32 value);
int Unk_178d670(u32 value);
int Unk_178d680(u32 value);
int Unk_178d690(u32 value);
int Unk_178d6a0(u32 value);
int Unk_178d720(u32 value);

// A rasterizer state's info.
struct Unk_178f700_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 _3;
    u16 field_4;
    u8 field_6;
    u8 _7;
    f32 field_8;
    s32 field_c;
    f32 field_10;
    u8 _14[0x4];
    u8 field_18;
    u8 _19;
    u8 field_1a;
    u8 _1b;
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_178f700_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_178f700_Info, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_178f700_Info, field_1c, 0x1c);

// 0x710178f700
// NON_MATCHING: the original tests the polygon offset values with one
// `fcmp; fccmp; ccmp` chain (clamp, slope, then the integer bias); clang makes
// a separate select of the bias test here. The rest matches.
void Unk_178f700(Unk_1788210_State* self, const Unk_1791080_Device* device,
                 const Unk_178f700_Info& info) {
    u8* multisample = self->field_4;
    nvnPolygonStateSetDefaults(self);
    nvnPolygonStateSetCullFace(self, Unk_178d720(info.field_2));
    nvnPolygonStateSetFrontFace(self, Unk_178d690(info.field_1));
    nvnPolygonStateSetPolygonMode(self, Unk_178d6a0(info.field_0));
    int depthBias = info.field_c;
    self->field_20 = depthBias;
    self->field_24 = info.field_10;
    self->field_28 = info.field_8;
    nvnPolygonStateSetPolygonOffsetEnables(
        self, self->field_28 != 0.0f || self->field_24 != 0.0f || depthBias != 0 ? 7 : 0);
    self->field_1c = info.field_1c;
    nvnMultisampleStateSetDefaults(multisample);
    nvnMultisampleStateSetMultisampleEnable(multisample, (info.field_4 >> 1) & 1);
    nvnMultisampleStateSetSamples(multisample, info.field_18 > 1 ? info.field_18 : 0);
    nvnMultisampleStateSetAlphaToCoverageEnable(multisample, info.field_1a & 1);
    self->field_2d.Set(1, (info.field_4 & 2) != 0);
    self->field_2d.Set(2, (info.field_4 & 4) == 0);
    self->field_2d.Set(4, (info.field_4 & 1) == 0);
    self->field_2d.Set(8, info.field_6 == 1);
    self->field_2c = 1;
}

// A blend target's info: enable, factors, equations and channel mask.
struct Unk_178f930_Target {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 _8[0x18];
};
PKMN_SIZE_ASSERT(Unk_178f930_Target, 0x20);

// A blend state's info: the number of targets, the logic op, flags (bit 2:
// independent blending, bit 3: logic op), the blend color and the targets.
struct Unk_178f930_Info {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    u8 _14[0x4];
    const Unk_178f930_Target* field_18;
};
PKMN_OFFSET_ASSERT(Unk_178f930_Info, field_18, 0x18);

// 0x710178f8e0
size_t Unk_178f8e0(const Unk_178f930_Info& info) {
    return info.field_0 * sizeof(u64);
}

// 0x710178f930
void Unk_178f930(Unk_1788310_State* self, const Unk_1791080_Device* device,
                 const Unk_178f930_Info& info) {
    u32* colorState = &self->field_8;
    u32* channelMask = &self->field_c;
    u64* blendStates = self->field_0;
    const Unk_178f930_Target* targets = info.field_18;
    self->field_10[0] = info.field_4;
    self->field_10[1] = info.field_8;
    self->field_10[2] = info.field_c;
    self->field_10[3] = info.field_10;
    nvnColorStateSetDefaults(colorState);
    nvnChannelMaskStateSetDefaults(channelMask);
    self->field_25 = info.field_0;
    for (int i = 0; i < info.field_0; ++i) {
        const Unk_178f930_Target& target = targets[(info.field_2 & 4) ? i : 0];
        nvnColorStateSetBlendEnable(colorState, i, target.field_0 & 1);
        nvnBlendStateSetDefaults(&blendStates[i]);
        nvnBlendStateSetBlendTarget(&blendStates[i], i);
        nvnBlendStateSetBlendFunc(&blendStates[i], Unk_178d670(target.field_1),
                                  Unk_178d670(target.field_2), Unk_178d670(target.field_4),
                                  Unk_178d670(target.field_5));
        nvnBlendStateSetBlendEquation(&blendStates[i], Unk_178d660(target.field_3),
                                      Unk_178d660(target.field_6));
        nvnChannelMaskStateSetChannelMask(channelMask, i, target.field_7 & 1,
                                          (target.field_7 >> 1) & 1, (target.field_7 >> 2) & 1,
                                          (target.field_7 >> 3) & 1);
    }
    if (info.field_2 & 8) {
        nvnColorStateSetLogicOp(colorState, Unk_178d680(info.field_1));
    }
    self->field_24 = 1;
}

// One face's stencil info.
struct Unk_178fb70_Stencil {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 _5[0xb];
};
PKMN_SIZE_ASSERT(Unk_178fb70_Stencil, 0x10);

// A depth stencil state's info: the depth function, stencil masks, flags
// (bit 0: depth test, 1: depth write, 2: stencil test, 3: depth bounds) and
// the front and back stencil.
struct Unk_178fb70_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 _3;
    u16 field_4;
    u8 _6[0x2];
    Unk_178fb70_Stencil field_8;
    Unk_178fb70_Stencil field_18;
};
PKMN_OFFSET_ASSERT(Unk_178fb70_Info, field_18, 0x18);

// 0x710178fb70
void Unk_178fb70(Unk_17883c0_State* self, const Unk_1791080_Device* device,
                 const Unk_178fb70_Info& info) {
    self->field_1a = info.field_4;
    nvnDepthStencilStateSetDefaults(self);
    nvnDepthStencilStateSetDepthTestEnable(self, info.field_4 & 1);
    nvnDepthStencilStateSetDepthWriteEnable(self, (info.field_4 >> 1) & 1);
    nvnDepthStencilStateSetStencilTestEnable(self, (info.field_4 >> 2) & 1);
    nvnDepthStencilStateSetDepthFunc(self, Unk_178d630(info.field_0));
    nvnDepthStencilStateSetStencilFunc(self, 2, Unk_178d650(info.field_18.field_3));
    nvnDepthStencilStateSetStencilOp(self, 2, Unk_178d640(info.field_18.field_0),
                                     Unk_178d640(info.field_18.field_1),
                                     Unk_178d640(info.field_18.field_2));
    nvnDepthStencilStateSetStencilFunc(self, 1, Unk_178d650(info.field_8.field_3));
    nvnDepthStencilStateSetStencilOp(self, 1, Unk_178d640(info.field_8.field_0),
                                     Unk_178d640(info.field_8.field_1),
                                     Unk_178d640(info.field_8.field_2));
    self->field_10 = info.field_18.field_4;
    self->field_14 = info.field_8.field_4;
    self->field_8 = info.field_1;
    self->field_c = info.field_2;
    self->field_18 = 1;
}
