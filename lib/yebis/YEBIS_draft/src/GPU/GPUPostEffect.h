// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp names
// the class and many of its functions in its log lines; the members are
// placeholders), as far as the functions written so far read it.
#pragma once

#include <types.h>

namespace PPFX {

// CRenderTexture (0x7100481000 and on), as this file reads it
struct Unk_RenderTexture {
    u8 pad_0[0x30];
    u32 field_30;  // width
    u32 field_34;  // height
};

// a viewport as fractions of a render target: the size, then the origin
struct Unk_Rect {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};
PKMN_SIZE_ASSERT(Unk_Rect, 0x10);

struct Unk_4a5d10_Self;
struct Unk_45eb90_Self;
struct Unk_4aa5a0_Self;

}  // namespace PPFX

// 0x710049ad30: a render texture's viewport
s32 Unk_49ad30(PPFX::Unk_RenderTexture* texture, s32 width, s32 height, s32 x, s32 y);
// 0x71004a5d10, 0x710045eb90, 0x71004aa5a0: the same for the objects that own render textures
s32 Unk_4a5d10(PPFX::Unk_4a5d10_Self* self, s32 arg1, f32 width, f32 height, f32 x, f32 y);
s32 Unk_45eb90(PPFX::Unk_45eb90_Self* self, f32 width, f32 height, f32 x, f32 y);
s32 Unk_4aa5a0(PPFX::Unk_4aa5a0_Self* self, f32 width, f32 height, f32 x, f32 y);
// 0x71004a6160
s32 Unk_4a6160(PPFX::Unk_4a5d10_Self* self, void* arg1, s32 arg2, f32 arg3);

namespace PPFX {

// a render texture's viewport from the fractions (at least one pixel)
inline s32 Unk_SetViewport(Unk_RenderTexture* texture, f32 width, f32 height, f32 x, f32 y) {
    s32 w = static_cast<s32>(width * static_cast<f32>(texture->field_30));
    s32 h = static_cast<s32>(height * static_cast<f32>(texture->field_34));
    s32 ix = static_cast<s32>(x * static_cast<f32>(texture->field_30));
    s32 iy = static_cast<s32>(y * static_cast<f32>(texture->field_34));
    if (width > 0.0f) { w = w > 1 ? w : 1; }
    if (height > 0.0f) { h = h > 1 ? h : 1; }
    return Unk_49ad30(texture, w, h, ix, iy);
}

class CPostEffect {
public:
    s32 Unk_426a50();  // 0x7100426a50

    // field_190's viewport (inline, and by reference: the function takes the
    // fractions' addresses before it reads field_190, and reads them after)
    s32 Unk_SetViewport190(const f32& width, const f32& height, const f32& x, const f32& y) {
        return Unk_4a5d10(field_190, 0x7fffffff, width, height, x, y);
    }

    // UNK_FIELDS_BEGIN
    bool field_0;  // between BeginPostEffectScene() and EndPostEffectScene()
    u8 pad_1[0x4f];
    Unk_RenderTexture* field_50;
    u8 pad_58[0x18];
    Unk_RenderTexture* field_70;
    u8 pad_78[0x28];
    Unk_RenderTexture* field_a0;
    Unk_RenderTexture* field_a8;
    Unk_RenderTexture* field_b0;
    Unk_RenderTexture* field_b8;
    u8 pad_c0[0xd0];
    Unk_4a5d10_Self* field_190;
    Unk_45eb90_Self* field_198;
    Unk_4aa5a0_Self* field_1a0;
    u8 pad_1a8[0x30];
    Unk_RenderTexture* field_1d8;
    Unk_4a5d10_Self* field_1e0;
    Unk_4a5d10_Self* field_1e8;
    Unk_RenderTexture* field_1f0;
    Unk_RenderTexture* field_1f8;
    Unk_RenderTexture* field_200;
    Unk_RenderTexture* field_208;
    Unk_RenderTexture* field_210;
    Unk_RenderTexture* field_218;
    Unk_RenderTexture* field_220;
    Unk_RenderTexture* field_228;
    Unk_RenderTexture* field_230;
    Unk_RenderTexture** field_238;  // one per view
    u8 pad_240[0x40];
    s32 field_280;
    u8 pad_284[0x4];
    Unk_RenderTexture** field_288;
    u8 pad_290[0x8];
    s32 field_298;  // the active view
    u8 pad_29c[0x2b4];
    Unk_RenderTexture** field_550;
    s32 field_558;
    u8 pad_55c[0x5c];
    Unk_RenderTexture* field_5b8;
    Unk_RenderTexture* field_5c0;
    u8 pad_5c8[0x238];
    Unk_Rect field_800;  // the viewport's scale
    bool field_810;
    u8 pad_811[0x3];
    Unk_Rect field_814;
    Unk_Rect field_824;
    Unk_Rect field_834;
    u8 pad_844[0x4f4];
    Unk_RenderTexture* field_d38;
    u8 pad_d40[0xb0];
    Unk_RenderTexture* field_df0;
    // UNK_FIELDS_END
};

}  // namespace PPFX
