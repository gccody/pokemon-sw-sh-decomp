// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: texture, color target and depth stencil
// views. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

int Unk_178d540(int format);
int Unk_178d620(u32 value);

// A view: a state, flags, the NVN texture and its NVN texture view (in
// field_18).
struct Unk_1790ca0_View {
    u8 field_0;
    Unk_1787ac0_Flags field_1;
    u8 _2[0x6];
    void* field_8;
    void* field_10;
    u8 field_18[0x28];
};
PKMN_OFFSET_ASSERT(Unk_1790ca0_View, field_18, 0x18);

// A texture: its NVN texture.
struct Unk_1790ca0_Texture {
    u8 _0[0x8];
    void* field_8;
};

// A texture view's info: image dimension, depth stencil mode, image format,
// channel mapping, mip levels, array range and the texture.
struct Unk_1790ca0_Info {
    u8 field_0;
    u8 field_1;
    u8 _2[0x2];
    s32 field_4;
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 field_b;
    u8 _c[0x4];
    u16 field_10;
    u16 field_12;
    u8 _14[0xc];
    s32 field_20;
    s32 field_24;
    u8 _28[0x8];
    const Unk_1790ca0_Texture* field_30;
};
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_30, 0x30);

// The channel mapping to NVN's swizzles.
static const int Unk_1f48f84[] = {0, 1, 2, 3, 4, 5};

void Unk_17911b0(void* view, int format, const void* texture);

// 0x7101790ca0
void Unk_1790ca0(Unk_1790ca0_View* self, const Unk_1791080_Device* device,
                 const Unk_1790ca0_Info& info) {
    self->field_8 = info.field_30->field_8;
    self->field_10 = self->field_18;
    nvnTextureViewSetDefaults(self->field_10);
    nvnTextureViewSetLevels(self->field_10, info.field_10, info.field_12);
    if (info.field_0 != 2) {
        nvnTextureViewSetLayers(self->field_10, info.field_20, info.field_24);
    }
    Unk_17911b0(self->field_10, Unk_178d540(info.field_4), self->field_8);
    nvnTextureViewSetSwizzle(self->field_10, Unk_1f48f84[info.field_8], Unk_1f48f84[info.field_9],
                             Unk_1f48f84[info.field_a], Unk_1f48f84[info.field_b]);
    nvnTextureViewSetDepthStencilMode(self->field_10, info.field_1 != 0);
    nvnTextureViewSetTarget(self->field_10, Unk_178d620(info.field_0));
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// A color target or depth stencil view's info: image dimension, mip level,
// image format, array range and the texture.
struct Unk_1790e20_Info {
    u8 field_0;
    u8 _1;
    u16 field_2;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    u8 _10[0x8];
    const Unk_1790ca0_Texture* field_18;
};
PKMN_OFFSET_ASSERT(Unk_1790e20_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1790e20_Info, field_18, 0x18);

// 0x7101790e20
void Unk_1790e20(Unk_1790ca0_View* self, const Unk_1791080_Device* device,
                 const Unk_1790e20_Info& info) {
    self->field_8 = info.field_18->field_8;
    self->field_10 = self->field_18;
    nvnTextureViewSetDefaults(self->field_10);
    nvnTextureViewSetLevels(self->field_10, info.field_2, 1);
    nvnTextureViewSetLayers(self->field_10, info.field_8, info.field_c);
    nvnTextureViewSetFormat(self->field_10, Unk_178d540(info.field_4));
    nvnTextureViewSetTarget(self->field_10, Unk_178d620(info.field_0));
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// 0x7101790f40
void Unk_1790f40(Unk_1790ca0_View* self, const Unk_1791080_Device* device,
                 const Unk_1790e20_Info& info) {
    self->field_8 = info.field_18->field_8;
    self->field_10 = self->field_18;
    nvnTextureViewSetDefaults(self->field_10);
    nvnTextureViewSetLevels(self->field_10, info.field_2, 1);
    nvnTextureViewSetLayers(self->field_10, info.field_8, info.field_c);
    nvnTextureViewSetTarget(self->field_10, Unk_178d620(info.field_0));
    self->field_1.Set(1, false);
    self->field_0 = 1;
}

// 0x7101790f00
void Unk_1790f00(Unk_1790ca0_View* self, const Unk_1791080_Device* device) {
    self->field_0 = 0;
    self->field_8 = nullptr;
    self->field_10 = nullptr;
}
