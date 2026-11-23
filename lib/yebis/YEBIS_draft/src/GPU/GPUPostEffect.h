// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp names
// the class and many of its functions in its log lines; the members are
// placeholders), as far as the functions written so far read it.
#pragma once

#include <list>
#include <map>
#include <utility>

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_410f90.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>

namespace PPFX {

// CRenderTexture (0x7100481000 and on), as this file reads it
struct Unk_RenderTexture {
    u8 pad_0[0x2c];
    s32 field_2c;
    u32 field_30;  // width
    u32 field_34;  // height
    s32 field_38;  // the format
    u8 pad_3c[0x18];
    u32 field_54;
    u32 field_58;
};

// two render textures (what field_560 holds)
struct Unk_RenderTexturePair {
    Unk_RenderTexture* field_0;
    Unk_RenderTexture* field_8;
};

// a viewport as fractions of a render target: the size, then the origin
struct Unk_Rect {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};
PKMN_SIZE_ASSERT(Unk_Rect, 0x10);

// the object field_190 points to, as this file reads it: render textures
// and the current one
struct Unk_4a5d10_Self {
    u8 pad_0[0x30];
    s32 field_30;  // how many
    u8 pad_34[0x4];
    Unk_RenderTexture** field_38;
    u8 pad_40[0x10];
    Unk_RenderTexture* field_50;
    void* field_58;
    u8 pad_60[0x20];
    Unk_RenderTexture* field_80[2];  // its depth textures
    s32 field_90;  // the current one
    u32 field_94;
};
// the object field_1a0 points to, as this file reads it
struct Unk_4aa5a0_Self {
    u8 pad_0[0xd4];
    s32 field_d4;  // the format of its description
    u8 pad_d8[0x1e0 - 0xd8];
    bool field_1e0;
    u8 pad_1e1[0x3];
    f32 field_1e4;
    u8 pad_1e8[0x3a8 - 0x1e8];
    bool field_3a8;
    u8 pad_3a9[0x3];
    f32 field_3ac;
};
// what 0x71004278c0 copies
// a glare's settings (0x7100427900 copies those of a glare definition,
// GPUGlareDef.h's Unk_4a0b00, into one)
struct Unk_4278c0_Data {
    f32 field_0[4];  // a colour (its luminance tells whether there is a glare)
    f32 field_10[4];
    f32 field_20;
    s32 field_24;
    f32 field_28[4];
    f32 field_38;
    f32 field_3c;
    bool field_40;
    f32 field_44[4];
    s32 field_54;  // the star's lines
    f32 field_58;
    f32 field_5c;
    bool field_60;
    f32 field_64;
    f32 field_68;
    bool field_6c;
    f32 field_70[4];
    f32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_4278c0_Data, field_44, 0x44);
PKMN_OFFSET_ASSERT(Unk_4278c0_Data, field_70, 0x70);
PKMN_SIZE_ASSERT(Unk_4278c0_Data, 0x84);
// CRenderGlare, as this file reads it
struct Unk_45eb90_Self {
    u8 pad_0[0x108];
    bool field_108;
    u8 pad_109[0x7];
    bool field_110;
    u8 pad_111[0x3];
    s32 field_114;  // how many light ghosts it can draw
    u8 pad_118[0xcc];
    s32 field_1e4;
    u8 pad_1e8[0x4];
    s32 field_1ec;
    f32 field_1f0;
    u8 pad_1f4[0xc];
    s32 field_200;  // how many light ghosts it draws
    u8 pad_204[0x4];
    struct Unk_423ba0_Item* field_208;  // the light ghosts
    u8 pad_210[0x14];
    Unk_Rect field_224;  // a colour
    u8 pad_234[0x14];
    f32 field_248;  // the depth of field's numbers for it
    f32 field_24c;
    f32 field_250;
    Unk_Float field_254;
    u8 pad_258[0xc];
    f32 field_264;
    f32 field_268;
    u8 pad_26c[0x80];
    s32 field_2ec;
};
PKMN_OFFSET_ASSERT(Unk_45eb90_Self, field_248, 0x248);
PKMN_OFFSET_ASSERT(Unk_45eb90_Self, field_2ec, 0x2ec);
// a view's light shaft and light ghost settings
struct Unk_423990_Item {
    Unk_Rect field_0;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    f32 field_30;
    Unk_Rect field_34;
    Unk_Float2 field_44;
    u8 pad_4c[0x10];
    f32 field_5c;
    bool field_60;
    u8 pad_61[0x3];
    u32 field_64;
};
PKMN_SIZE_ASSERT(Unk_423990_Item, 0x68);
struct Unk_423ba0_Item {
    u8 field_0;  // on
    u8 pad_1[0x3];
    Unk_Rect field_4;
    Unk_Float2 field_14;
    Unk_Float2 field_1c;
    u32 field_24;
    f32 field_28;
    f32 field_2c;
    u32 field_30;
};
// a view's settings of two more kinds, as 0x7100429da0 and 0x7100429e60 read them
struct Unk_429da0_Item {
    bool field_0;  // auto exposure is on
    u8 pad_1[0x3];
    f32 field_4;  // the middle grey
    f32 field_8;
    f32 field_c;  // the metering area: its size, then its offset
    f32 field_10;
    f32 field_14;
    f32 field_18;
    u8 pad_1c[0x8];
    f32 field_24;
    u32 field_28;  // the delay mode
    f32 field_2c;  // the delay
    f32 field_30;  // the exposure range
    f32 field_34;
    f32 field_38;  // the light and dark exposure border
    f32 field_3c;  // the adaptation's sensitivity, scale and speed limit
    f32 field_40;
    f32 field_44;
    f32 field_48;  // the dark adaptation's
    f32 field_4c;
    f32 field_50;
    s32 field_54;
    s32 field_58;
    f32 field_5c;
    f32 field_60;
    bool field_64;
    u8 pad_65[0x3];
    s32 field_68;
    u8 pad_6c[0x4];
    void* field_70;  // a CTextureLuminanceManage
};
PKMN_SIZE_ASSERT(Unk_429da0_Item, 0x78);
struct Unk_429e60_Item {
    bool field_0;
    u8 pad_1[0x1b];
    f32 field_1c;
    u8 pad_20[0xc];
    s32 field_2c;
    s32 field_30;
    f32 field_34;
    f32 field_38;
    bool field_3c;
    u8 pad_3d[0x3];
    s32 field_40;
    u8 pad_44[0x4];
    void* field_48;  // a CTextureLuminanceManage
};
PKMN_SIZE_ASSERT(Unk_429e60_Item, 0x50);
PKMN_SIZE_ASSERT(Unk_423ba0_Item, 0x34);

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

// PPFX's maps of objects by the device's object (an address); the pointees
// whose class isn't known are placeholders named after their map's
// destroy function, which each map type has its own copy of
template <class T>
using Unk_TextureMap = std::map<u64, T*, std::less<u64>, Unk_StlAllocator<std::pair<const u64, T*>>>;
// the object of `key`, or null (inline: its find compares with the key as a
// value, not through a reference)
template <class T>
T* Unk_MapFind(const Unk_TextureMap<T>& map, u64 key) {
    auto it = map.find(key);
    return it != map.end() ? it->second : nullptr;
}
template <class T>
using Unk_PairMap = std::map<std::pair<u64, u64>, T, std::less<std::pair<u64, u64>>,
                             Unk_StlAllocator<std::pair<const std::pair<u64, u64>, T>>>;
class IGPUDevice;
// what field_1198 and field_11a0 are, as the command list's begin calls them
// (placeholders)
struct Unk_CommandList {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
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
    virtual void vf18(void* commandBuffer);  // records to an NVN command buffer
};
struct Unk_CommandListMaker {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
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
    virtual void vf20();
    virtual void vf21();
    virtual void* vf22(u32 arg1, u32 arg2, void* arg3);  // makes a command list
};
struct Unk_43c490;
struct Unk_43c4e0;

// what IPfxBaseContext::Initialize hands CPostEffect::Initialize (placeholder)
struct Unk_417b30_Desc {
    u8 pad_0[0x70];
    u64 field_70;
};

class CPostEffect {
public:
    CPostEffect();               // 0x71004190f0
    ~CPostEffect();              // 0x7100419550
    // 0x710041afb0 (its log lines name it)
    s32 Initialize(const Unk_417b30_Desc* desc, u32 arg2, u32 arg3, u32 arg4, void* arg5);
    s32 Unk_419690(void* arg);   // 0x7100419690: its uninitialisation
    s32 Unk_426a50();  // 0x7100426a50
    // 0x7100423160: the object of two device objects (key) made or found
    u64 Unk_423160(u64 arg1, u64 arg2, void* device);
    // 0x7100427c10: the render texture of a device texture, made and added
    // to field_108
    s32 Unk_427c10(u64 key, u32 arg2, u32 arg3, u32 format, void* arg5, Unk_RenderTexture** out);
    // 0x71004397e0: the same for field_d8
    s32 Unk_4397e0(u64 key, u32 arg2, u32 arg3, u32 format, u32 arg5, u32 arg6, Unk_43c4e0** out);
    // 0x71004399e0, 0x7100439c10: release what field_11e8's and field_11d0's
    // objects hold
    s32 Unk_4399e0(SiSDK3::ISiInterface* object, void* arg2);
    s32 Unk_439c10(SiSDK3::ISiInterface* object, void* arg2);
    // 0x710043b150
    s32 Unk_43b150(u32 arg1, u64 key, u32 arg3, u32 arg4, u32 format, u32 arg6, f32 a, f32 b);
    // 0x710041af70: field_190's texture field_5d8 (-1: its current one)
    Unk_RenderTexture* Unk_41af70();
    // 0x71004346f0, 0x71004347e0 (their log lines name them)
    s32 EndPostEffectScene(u32 flags, s32 samples);
    s32 EndPostEffectScene_Process(u32 flags, s32 samples);
    s32 Unk_438510();  // 0x7100438510: the end of the scene (EndPostEffectScene_Process)
    // 0x710042cc90
    s32 Unk_42cc90(s32 view, s32 arg2, void* arg3, void* arg4, bool arg5, void* arg6, u32 arg7, u32 arg8, u32 arg9,
                   f32 arg10);
    s32 Unk_42cba0(bool arg);  // 0x710042cba0
    // 0x710042df80
    s32 Unk_42df80(s32* outFormat, f32* outScale, f32* outScale2, f32* outDither, bool* outHasGamma, f32* outGamma,
                   MATRIXT44** outMatrix, MATRIXT44** outMatrix2, bool linear, bool keep);
    Unk_RenderTexture* Unk_42bbe0(Unk_RenderTexture* source);  // 0x710042bbe0
    Unk_RenderTexture* Unk_428f00();  // 0x7100428f00
    s32 ApplyEffects_DepthOfField();  // 0x710042f070 (its log line names it)
    void Unk_42e560();                // 0x710042e560 (not written yet)
    // field_190's texture `index` (-1: its current one), if it has one (inline)
    Unk_RenderTexture* Unk_TextureAt(s32 index) {
        Unk_4a5d10_Self* textures = field_190;
        if (index == -1) {
            index = textures->field_90;
        }
        if (index < textures->field_30) {
            return textures->field_38[index];
        }
        return nullptr;
    }
    Unk_RenderTexture* Unk_FeedbackTexture();
    Unk_RenderTexture* Unk_428f00_Copy();
    Unk_RenderTexture* Unk_428f00_Previous(Unk_4a5d10_Self* textures);
    // 0x7100429f20: the depth of field's flag and the fewest bits per channel
    // of the three formats
    s32 Unk_429f20(bool set, bool enable);
    // 0x710042b8a0: the ranges field_8f4 and field_904 follow field_6c4
    s32 Unk_42b8a0();
    // 0x710042b9f0: the depth of field's numbers handed to the glare
    s32 Unk_42b9f0();
    // 0x7100429460: the light ghosts handed to the glare (whether there are any)
    bool Unk_429460();
    // 0x710042a0f0: the tone map's output format and shader numbers
    s32 Unk_42a0f0();
    // 0x710042be10: the velocity of the scene's depth (once a frame)
    s32 Unk_42be10();
    // 0x7100428220
    void Unk_428220();
    // 0x710042a590: what changed since the last frame's view (placeholder)
    s32 Unk_42a590(bool* far, bool* moved, bool* projection, bool* rotation, bool* any);
    // field_895 set: what 0x7100428220 brings up to date is out of date
    // (inline)
    void Unk_Refresh() {
        if (field_895) {
            Unk_428220();
        }
    }
    // 0x7100428cc0: the scale and offset (then their inverses) from depth
    // space `from` to `to` (6: field_5c's), for depths scaled by `a` and moved
    // by `b`
    s32 Unk_428cc0(f32* out, s32 from, s32 to, f32 a, f32 b);
    f32 Unk_4280e0();  // 0x71004280e0
    bool Unk_427ad0();  // 0x7100427ad0
    MATRIXT44 Unk_429c50(bool arg);  // 0x7100429c50
    s32 Unk_4299a0();  // 0x71004299a0
    bool Unk_4297b0();  // 0x71004297b0
    s32 Unk_433270();   // 0x7100433270
    f32 Unk_42f320(f32 value, const MATRIXT44* m, s32 mode);  // 0x710042f320
    // 0x7100432ca0: draws with CTextureUtil from three textures (the second
    // optional) to the fourth, their filters set to `filter` for it
    s32 Unk_432ca0(f32 scale, Unk_RenderTexture* arg1, Unk_RenderTexture* arg2, Unk_RenderTexture* arg3,
                   Unk_RenderTexture* arg4, const Unk_Float4* color, s32 filter, bool list, bool negate);
    bool Unk_434570();  // 0x7100434570
    s32 Unk_426210();  // 0x7100426210
    // 0x7100426070: a view's (0x7fffffff: every view's) exposure history set
    // to `value` (when not positive, from field_6c4 and field_6c8)
    s32 Unk_426070(s32 view, f32 value);
    // 0x7100425dd0: CPostEffect::InitializeAutoExposure (its log line names it)
    s32 InitializeAutoExposure(s32 view, f32 luminance, f32 adjusted);
    s32 Unk_426700(s32 arg1, void* arg2, s32 arg3, s32 arg4, f32 arg5);  // 0x7100426700
    s32 BeginCommandList_SiGfx();  // 0x7100425c50 (its log lines name it)
    s32 Unk_423630(bool enable);        // 0x7100423630
    s32 SetAntialiasType(s32 type);     // 0x7100423850
    s32 SetLightShaftEnable(bool enable);  // inline in Unk_423990
    s32 SetLightGhostEnable(bool enable);  // inline in Unk_423ba0

    // field_190's viewport (inline, and by reference: the function takes the
    // fractions' addresses before it reads field_190, and reads them after)
    s32 Unk_SetViewport190(const f32& width, const f32& height, const f32& x, const f32& y) {
        return Unk_4a5d10(field_190, 0x7fffffff, width, height, x, y);
    }

    // per-view records (inline: the callers read the index before the array)
    s32 Unk_Frame(s32 view) const { return field_290[view]; }
    Unk_423990_Item& Unk_LightShaft(s32 view) { return field_858[view]; }
    Unk_423ba0_Item& Unk_LightGhost(s32 view) { return field_868[view]; }

    // UNK_FIELDS_BEGIN
    bool field_0;  // between BeginPostEffectScene() and EndPostEffectScene()
    bool field_1;
    u8 pad_2[0x16];
    IGPUDevice* field_18;
    u64 field_20;
    void* field_28;
    u8 pad_30[0x20];
    Unk_RenderTexture* field_50;  // the depth factor source's texture
    u32 field_58;                 // its source
    u32 field_5c;
    f32 field_60;  // its scale and bias, and their inverse
    f32 field_64;
    f32 field_68;
    f32 field_6c;
    Unk_RenderTexture* field_70;
    u32 field_78;
    u8 pad_7c[0x4];
    void* field_80;
    u8 pad_88[0x4];
    u32 field_8c;
    u32 field_90;
    u32 field_94;
    f32 field_98;
    u8 pad_9c[0x4];
    Unk_RenderTexture* field_a0;
    Unk_RenderTexture* field_a8;
    Unk_RenderTexture* field_b0;
    Unk_RenderTexture* field_b8;
    u32 field_c0;
    u8 pad_c4[0x14];
    Unk_TextureMap<Unk_43c4e0> field_d8;
    Unk_TextureMap<Unk_43c490> field_f0;
    Unk_TextureMap<Unk_RenderTexture> field_108;  // CRenderTexture::m_mapDeviceTextureRenderTexture
    Unk_43c4e0* field_120;
    u64 field_128;
    u64 field_130;
    u8 pad_138[0x58];
    Unk_4a5d10_Self* field_190;
    Unk_45eb90_Self* field_198;
    Unk_4aa5a0_Self* field_1a0;
    u8 pad_1a8[0x10];
    bool field_1b8;
    bool field_1b9;
    bool field_1ba;
    u8 pad_1bb[0x1];
    bool field_1bc;
    u8 pad_1bd[0x3];
    bool field_1c0;
    u8 pad_1c1[0x5];
    bool field_1c6;
    u8 pad_1c7[0x1];
    bool field_1c8;
    u8 pad_1c9[0x1];
    bool field_1ca;
    u8 pad_1cb[0x1];
    bool field_1cc;
    bool field_1cd;
    u8 pad_1ce[0x5];
    bool field_1d3;  // the scene is external (PFXINIT_RENDERSCENE_EXTERNAL)
    u8 pad_1d4[0x4];
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
    u8 pad_240[0x20];
    Unk_4a5d10_Self** field_260;  // one per view: the feedback textures
    u8 pad_268[0x10];
    Unk_RenderTexture* field_278;
    s32 field_280;
    u8 pad_284[0x4];
    Unk_RenderTexture** field_288;
    s32* field_290;  // each view's frame number
    s32 field_298;  // the active view
    u8 pad_29c[0x4];
    Unk_429da0_Item* field_2a0;  // one per view
    Unk_429e60_Item* field_2a8;  // one per view
    u8 pad_2b0[0x150];
    s32 field_400;
    u8 pad_404[0x1c];
    f32 field_420;
    u8 pad_424[0xf4];
    s32 field_518;  // the feedback format
    u8 pad_51c[0x8];
    s32 field_524;  // how many light ghosts
    u8 pad_528[0x1c];
    u32 field_544;
    bool field_548;
    u8 pad_549[0x7];
    Unk_RenderTexture** field_550;
    s32 field_558;
    u8 pad_55c[0x4];
    Unk_RenderTexturePair* field_560;  // field_568 pairs
    s32 field_568;
    u8 pad_56c[0x28];
    bool field_594;
    u8 pad_595[0x3];
    bool field_598;
    bool field_599;
    bool field_59a;
    u8 pad_59b[0x1];
    bool field_59c;
    bool field_59d;
    bool field_59e;
    u8 pad_59f[0x5];
    f32 field_5a4;
    f32 field_5a8;
    f32 field_5ac;
    f32 field_5b0;
    u8 pad_5b4[0x4];
    Unk_RenderTexture* field_5b8;
    Unk_RenderTexture* field_5c0;
    u32 field_5c8;
    u8 pad_5cc[0xc];
    s32 field_5d8;
    u8 pad_5dc[0x4];
    s32 field_5e0;
    u8 pad_5e4[0x20];
    s32 field_604;
    s32 field_608;
    s32 field_60c;
    u8 pad_610[0x20];
    s32 field_630;
    s32 field_634;
    s32 field_638;
    u8 pad_63c[0x30];
    s32 field_66c;
    s32 field_670;
    u8 pad_674[0x6];
    bool field_67a;
    u8 pad_67b[0x5];
    s32 field_680;  // the tone map's shader numbers
    s32 field_684;
    s32 field_688;
    s32 field_68c;
    s32 field_690;
    s32 field_694;
    s32 field_698;
    s32 field_69c;
    s32 field_6a0;
    s32 field_6a4;  // the output format (Unk_42df80)
    s32 field_6a8;  // the format when there is no texture field_5d8
    u8 pad_6ac[0x4];
    u32 field_6b0;
    u32 field_6b4;
    u8 pad_6b8[0xc];
    f32 field_6c4;
    f32 field_6c8;
    f32 field_6cc;
    f32 field_6d0;
    f32 field_6d4;
    f32 field_6d8;
    f32 field_6dc;
    f32 field_6e0;
    f32 field_6e4;
    f32 field_6e8;
    f32 field_6ec;
    f32 field_6f0;
    MATRIXT44 field_6f4;  // compared with field_774 by Unk_42a590
    MATRIXT44 field_734;
    MATRIXT44 field_774;
    MATRIXT44 field_7b4;
    f32 field_7f4;
    f32 field_7f8;  // the scene's luminance scale
    f32 field_7fc;
    Unk_Rect field_800;  // the viewport's scale
    bool field_810;
    u8 pad_811[0x3];
    Unk_Rect field_814;
    Unk_Rect field_824;
    Unk_Rect field_834;
    f32 field_844;
    f32 field_848;
    u8 pad_84c[0xc];
    Unk_423990_Item* field_858;
    s32 field_860;
    u8 pad_864[0x4];
    Unk_423ba0_Item* field_868;
    s32 field_870;
    s32 field_874;  // the light ghost's kind
    u64 field_878;
    s32 field_880;
    f32 field_884;  // the depth of field's camera
    f32 field_888;
    f32 field_88c;
    f32 field_890;
    u8 pad_894[0x1];
    bool field_895;
    u8 pad_896[0x2];
    f32 field_898;
    f32 field_89c;
    u32 field_8a0;
    f32 field_8a4;
    Unk_Float2 field_8a8;
    f32 field_8b0;
    u8 pad_8b4[0x2];
    bool field_8b6;
    u8 pad_8b7[0x1];
    Unk_Float2 field_8b8;
    Unk_Float field_8c0;  // the tone map's exposure
    Unk_Float field_8c4;  // its gamma
    u32 field_8c8;        // the tone map
    f32 field_8cc;
    f32 field_8d0;
    u8 pad_8d4[0x18];
    f32 field_8ec;  // the last frame's field_8f4 and field_8f8
    f32 field_8f0;
    f32 field_8f4;
    f32 field_8f8;
    f32 field_8fc;  // the last frame's field_904 and field_908
    f32 field_900;
    f32 field_904;
    f32 field_908;
    f32 field_90c;
    f32 field_910;
    u8 field_914;
    u8 pad_915[0x3];
    u32 field_918;
    f32 field_91c;
    f32 field_920;
    f32 field_924;
    Unk_Rect field_928;
    f32 field_938;
    u8 pad_93c[0x11];
    bool field_94d;
    u8 pad_94e[0x2];
    f32 field_950;
    f32 field_954;
    f32 field_958;
    u8 pad_95c[0xc];
    f32 field_968;  // the dither's offset scale
    bool field_96c;
    u8 pad_96d[0x3];
    u32 field_970;
    u8 pad_974[0x4];
    s32 field_978;
    u32 field_97c;
    u8 pad_980[0x2c];
    s32 field_9ac;
    u8 pad_9b0[0x4];
    MATRIXT44 field_9b4[6];  // the colour matrices
    bool field_b34[6];  // which of them changed
    u8 pad_b3a[0x2];
    MATRIXT44 field_b3c;
    s32 field_b7c;  // colour space numbers for field_b84 and field_ba4 (-1: none)
    s32 field_b80;
    Unk_410f90 field_b84;  // colour spaces
    Unk_410f90 field_ba4;
    u8 pad_bc4[0x9];
    bool field_bcd;
    bool field_bce;
    u8 pad_bcf[0x15];
    bool field_be4;
    u8 pad_be5[0x89];
    bool field_c6e;  // there are light ghosts to draw
    bool field_c6f;
    u8 pad_c70[0x8];
    bool field_c78;
    u8 pad_c79[0x1];
    bool field_c7a;
    u8 pad_c7b[0x1];
    Unk_Rect field_c7c;
    f32 field_c8c;
    bool field_c90;
    bool field_c91;
    u8 pad_c92[0x2];
    s32 field_c94;
    u8 pad_c98[0x4d];
    bool field_ce5;
    u8 pad_ce6[0x2];
    s32 field_ce8;
    u8 pad_cec[0x4];
    Unk_Float field_cf0;
    Unk_Float field_cf4;
    s32 field_cf8;
    u32 field_cfc;
    Unk_Float field_d00;
    u8 pad_d04[0x4];
    f32 field_d08;
    u8 pad_d0c[0x4];
    f32 field_d10;
    f32 field_d14;
    u8 pad_d18[0x14];
    s32 field_d2c;
    s32 field_d30;
    u8 pad_d34[0x4];
    Unk_RenderTexture* field_d38;
    u8 pad_d40[0x24];
    Unk_Float2 field_d64;
    s32 field_d6c;
    Unk_RenderTexture* field_d70;
    Unk_RenderTexture* field_d78;
    bool field_d80;
    u8 pad_d81[0x3];
    s32 field_d84;
    void* field_d88;
    bool field_d90;
    u8 pad_d91[0x3];
    f32 field_d94;
    u8 pad_d98[0x4];
    Unk_Float4 field_d9c;
    u8 pad_dac[0x34];
    f32 field_de0;
    f32 field_de4;
    u8 pad_de8[0x8];
    Unk_RenderTexture* field_df0;
    u8 pad_df8[0xf4];
    f32 field_eec;
    f32 field_ef0;
    u8 pad_ef4[0x38];
    s32 field_f2c;
    s32 field_f30;
    u8 pad_f34[0x4];
    bool field_f38;
    u8 pad_f39[0xb];
    s32 field_f44;
    u8 pad_f48[0x24];
    f32 field_f6c;
    f32 field_f70;
    u8 pad_f74[0x4];
    u32 field_f78;
    Unk_Float field_f7c;
    s32 field_f80;
    Unk_4278c0_Data field_f84;
    s32 field_1008;
    f32 field_100c;
    f32 field_1010;
    bool field_1014;
    u8 pad_1015[0x38];
    bool field_104d;
    u8 pad_104e[0x1];
    bool field_104f;
    bool field_1050;
    bool field_1051;
    u8 pad_1052[0x1];
    bool field_1053;
    f32 field_1054;
    f32 field_1058;
    f32 field_105c;
    f32 field_1060;
    f32 field_1064;
    u8 pad_1068[0x2];
    bool field_106a;
    bool field_106b;
    bool field_106c;
    u8 pad_106d[0x1];
    bool field_106e;
    u8 pad_106f[0x1];
    f32 field_1070;
    u8 pad_1074[0x10];
    Unk_Float2 field_1084;
    f32 field_108c;
    bool field_1090;
    bool field_1091;
    u8 pad_1092[0x2];
    MATRIXT44 field_1094;
    u8 pad_10d4[0x2];
    bool field_10d6;
    u8 pad_10d7[0x3];
    bool field_10da;
    bool field_10db;
    u8 pad_10dc[0x8c];
    u64 field_1168;
    u8 pad_1170[0x8];
    SiYebisAllocator field_1178;
    Unk_CommandList* field_1198;  // the NVN command list's
    Unk_CommandListMaker* field_11a0;
    u8 pad_11a8[0x8];
    void* field_11b0;  // the command list in use
    bool field_11b8;  // it is field_11c0
    u8 pad_11b9[0x7];
    void* field_11c0;  // the one made for SiGfx's own buffers
    bool field_11c8;
    u8 pad_11c9[0x3];
    u32 field_11cc;  // how many begins
    // UNK_FIELDS_END
    // by two device objects: an object and an allocation, and two objects
    Unk_PairMap<std::pair<SiSDK3::ISiInterface*, void*>> field_11d0;
    Unk_PairMap<std::pair<SiSDK3::ISiInterface*, SiSDK3::ISiInterface*>> field_11e8;
    void* field_1200;  // the current NVN command buffer (SetCurrentCommandBuffer_Nvn)
    u8 pad_1208[0x8];
    // the free indices of the NVN texture and sampler pools that the default
    // callbacks hand out
    std::list<s32, Unk_StlAllocator<s32>> field_1210;
    std::list<s32, Unk_StlAllocator<s32>> field_1228;

    static s32 DefaultRegisterTextureHandleCallback_Nvn(const void* texture, const void* view);  // 0x710043b290
    static void Unk_43b370(s32 index);                                                         // 0x710043b370
    static s32 DefaultRegisterSamplerHandleCallback_Nvn(const void* sampler);                   // 0x710043b3f0
    static void Unk_43b500(s32 index);                                                         // 0x710043b500
};
PKMN_OFFSET_ASSERT(CPostEffect, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(CPostEffect, field_6f4, 0x6f4);
PKMN_OFFSET_ASSERT(CPostEffect, field_7b4, 0x7b4);
PKMN_OFFSET_ASSERT(CPostEffect, field_d08, 0xd08);
PKMN_OFFSET_ASSERT(CPostEffect, field_560, 0x560);
PKMN_OFFSET_ASSERT(CPostEffect, field_c94, 0xc94);
PKMN_OFFSET_ASSERT(CPostEffect, field_120, 0x120);
PKMN_OFFSET_ASSERT(CPostEffect, field_190, 0x190);
PKMN_OFFSET_ASSERT(CPostEffect, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(CPostEffect, field_6a8, 0x6a8);
PKMN_OFFSET_ASSERT(CPostEffect, field_599, 0x599);
PKMN_OFFSET_ASSERT(CPostEffect, field_59d, 0x59d);
PKMN_OFFSET_ASSERT(CPostEffect, field_6a4, 0x6a4);
PKMN_OFFSET_ASSERT(CPostEffect, field_9ac, 0x9ac);
PKMN_OFFSET_ASSERT(CPostEffect, field_9b4, 0x9b4);
PKMN_OFFSET_ASSERT(CPostEffect, field_106b, 0x106b);
PKMN_OFFSET_ASSERT(CPostEffect, field_106e, 0x106e);
PKMN_OFFSET_ASSERT(CPostEffect, field_8ec, 0x8ec);
PKMN_OFFSET_ASSERT(CPostEffect, field_904, 0x904);
PKMN_OFFSET_ASSERT(CPostEffect, field_914, 0x914);
PKMN_OFFSET_ASSERT(CPostEffect, field_918, 0x918);
PKMN_OFFSET_ASSERT(Unk_4aa5a0_Self, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_4aa5a0_Self, field_3a8, 0x3a8);
PKMN_OFFSET_ASSERT(Unk_RenderTexture, field_54, 0x54);
PKMN_OFFSET_ASSERT(CPostEffect, field_1178, 0x1178);
PKMN_OFFSET_ASSERT(CPostEffect, field_11c8, 0x11c8);
PKMN_OFFSET_ASSERT(CPostEffect, field_11e8, 0x11e8);
PKMN_OFFSET_ASSERT(CPostEffect, field_1210, 0x1210);
PKMN_OFFSET_ASSERT(CPostEffect, field_1228, 0x1228);

}  // namespace PPFX
