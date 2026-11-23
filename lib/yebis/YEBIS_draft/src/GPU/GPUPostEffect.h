// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp names
// the class and many of its functions in its log lines; the members are
// placeholders), as far as the functions written so far read it.
#pragma once

#include <list>
#include <map>
#include <utility>

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceResource.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_410f90.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_FixedHeapAllocator2.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

// 0x71024e09bc (placeholder; GPUPostEffect.cpp)
extern s32 Unk_24e09bc;
// 0x7100440c00 (lib/yebis/leaf/Unk_43dc00.cpp)
u32 Unk_440c00_get(u64 device, u32 arg);
// 0x71024e09b8 (placeholder; GPUPostEffect.cpp): EndPostEffectScene_Process
// ORs it into field_67b
extern bool Unk_24e09b8;

namespace PPFX {

class CRenderTexture;
class CRenderTextureArray;
class CTextureLuminanceManage;
struct Unk_49b230_Object;
struct Unk_GPUTexture;
// 0x710049da70 (GPURenderTexture.h)
s32 Unk_49da70(s32 count, CRenderTexture** targets, Unk_49b230_Object* depth, Unk_49b230_Object* arg3, s32 arg4,
               void* arg5, s32 arg6, s32 arg7, s32 arg8, f32 arg9);

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
    Unk_GPUTexture* field_60[2];  // its depth textures' device textures
    u8 pad_70[0x10];
    Unk_RenderTexture* field_80[2];  // its depth textures
    s32 field_90;  // the current one
    u32 field_94;
};
// the object field_1a0 points to, as this file reads it
struct Unk_4aa5a0_Self {
    u8 pad_0[0xd4];
    s32 field_d4;  // the format of its description
    u8 pad_d8[0x12d - 0xd8];
    bool field_12d;
    u8 pad_12e[0x178 - 0x12e];
    f32 field_178;
    s32 field_17c;
    u8 pad_180[0x1e0 - 0x180];
    bool field_1e0;
    u8 pad_1e1[0x3];
    f32 field_1e4;
    u8 pad_1e8[0x1f8 - 0x1e8];
    s64 field_1f8;
    u8 pad_200[0x240 - 0x200];
    bool field_240;
    u8 pad_241[0x251 - 0x241];
    bool field_251;
    u8 pad_252[0x2a8 - 0x252];
    s32 field_2a8;
    s32 field_2ac;
    f32 field_2b0;
    f32 field_2b4;
    f32 field_2b8;
    f32 field_2bc;
    u8 pad_2c0[0x3a8 - 0x2c0];
    bool field_3a8;
    u8 pad_3a9[0x3];
    f32 field_3ac;
    s32 field_3b0;
    u8 pad_3b4[0x4];
    f32 field_3b8;
    f32 field_3bc;
    f32 field_3c0;
    bool field_3c4;
    u8 pad_3c5[0x3];
    u64 field_3c8;
    u64 field_3d0;
    f32 field_3d8;
    f32 field_3dc;
    f32 field_3e0;
    u8 pad_3e4[0x4];
    f32 field_3e8;
    f32 field_3ec;
    bool field_3f0;
    u8 pad_3f1[0x3];
    f32 field_3f4;
};
// what 0x71004278c0 copies
// a glare's settings (0x7100427900 copies those of a glare definition,
// GPUGlareDef.h's Unk_4a0b00, into one)
struct Unk_4278c0_Data {
    // (CPostEffect's constructor zeroes its member: member by member, the
    // arrays value-initialised)
    Unk_4278c0_Data()
        : field_0(), field_10(), field_20(0.0f), field_24(0), field_28(), field_38(0.0f), field_3c(0.0f),
          field_40(false), field_44(), field_54(0), field_58(0.0f), field_5c(0.0f), field_60(false), field_64(0.0f),
          field_68(0.0f), field_6c(false), field_70(), field_80(0.0f) {}

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
    u8 pad_0[0xbc];
    u32 field_bc;  // its width
    u32 field_c0;  // its height
    u8 pad_c4[0x10];
    s32 field_d4;  // its format
    u8 pad_d8[0x30];
    bool field_108;
    u8 pad_109[0x3];
    s32 field_10c;  // how many light shafts it can draw
    bool field_110;
    u8 pad_111[0x3];
    s32 field_114;  // how many light ghosts it can draw
    u8 pad_118[0xc];
    f32 field_124;
    f32 field_128;
    u8 pad_12c[0xc];
    f32 field_138;
    u8 pad_13c[0xc];
    f32 field_148;
    f32 field_14c;
    f32 field_150;
    u8 pad_154[0x2c];
    bool field_180;  // whether there is a vignette
    u8 pad_181[0x7];
    f32 field_188;
    bool field_18c;
    u8 pad_18d[0x1f];
    bool field_1ac;
    u8 pad_1ad[0x37];
    s32 field_1e4;
    f32 field_1e8;
    s32 field_1ec;
    f32 field_1f0;
    s32 field_1f4;  // how many light shafts it draws
    u8 pad_1f8[0x8];
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
    f32 field_258;
    f32 field_25c;
    s32 field_260;
    f32 field_264;
    f32 field_268;
    bool field_26c;
    u8 pad_26d[0x7f];
    s32 field_2ec;
    u8 pad_2f0[0x120];
    bool field_410;
    u8 pad_411[0xf];
    Unk_RenderTexture* field_420;
};
PKMN_OFFSET_ASSERT(Unk_45eb90_Self, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_45eb90_Self, field_420, 0x420);
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
    Unk_Rect field_4c;
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
    f32 field_1c;
    f32 field_20;
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
    u8 pad_1[0x3];
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
    bool field_24;
    u8 pad_25[0x3];
    f32 field_28;
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
// 0x710043dc00 (lib/yebis/leaf/Unk_43dc00.cpp): a lazy draw command's release
// (placeholder type: GPUSiGfxLazyDrawCommand's layout)
struct Unk_43dc00;
u32 Unk_43dc00_get(Unk_43dc00* self);
// 0x71004bc760 (Unk_4bc640.cpp), 0x71004cbd40 and 0x71004cbdd0 (Unk_4cbd40.cpp:
// SiGfx's initialisation and its end)
// 0x710049eb10, 0x710049eb20 (lib/yebis/leaf/Unk_49eb10.cpp), 0x710049fdc0
// (lib/yebis/leaf/Unk_49fdc0.cpp: a render texture pool's release of a texture)
u32 Unk_49eb10_get();
u32 Unk_49eb20_get(u32 value);
void Unk_49fdc0_call(void* self, u64 value);
void Unk_4bc760(u64 value);
bool Unk_4cbd40(SiSDK3::ISiAllocator* pAllocator);
void Unk_4cbdd0();
// 0x71024e09c0, 0x71024e09c8: the memory pool storage buffer and its size;
// 0x71024e09d0, 0x71024e09d8: the NVN texture and sampler pools (GPUPostEffect.cpp)
extern u64 Unk_24e09c0;
extern s32 Unk_24e09c8;
extern void* Unk_24e09d0;
extern void* Unk_24e09d8;
// 0x710238c2e4, 0x710238c2e8: the first descriptor the post effect's texture
// and sampler pools keep for themselves (-1: the pool's last ones) and how
// many (placeholders)
extern s32 Unk_238c2e4;
extern s32 Unk_238c2e8;

// what SiSDK3::SiGfxKernel's slot 37 (Unk_4cbf40_get()->vf37()) gives, as
// CreateInternalResource_SiGfx calls it (placeholder)
struct Unk_4cbf40_Object {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(SiSDK3::ISiAllocator* pAllocator);  // sets the allocator
};

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

// PFX_INITPARAM (the log names it and three of its members): what
// Initialize is given, beside its flags; the other members are placeholders
struct PFX_INITPARAM {
    // (assigned in this order: the sizes and aspect ratios, the -1 block,
    // the rest in member order, field_c last; it decides which of the
    // constructors' stores LLVM merges)
    PFX_INITPARAM() {
        field_10 = 0;
        field_14 = 0;
        field_18 = 0;
        field_1c = 0;
        field_20 = 0.0f;
        field_24 = 0.0f;
        field_28 = 0.0f;
        field_2c = 0.0f;
        field_90 = -1;
        field_94 = -1;
        field_98 = -1;
        field_9c = -1;
        field_a0 = -1;
        field_a4 = -1;
        field_a8 = -1;
        field_ac = -1;
        field_b0 = -1;
        field_b4 = -1;
        field_b8 = -1;
        field_bc = -1;
        field_c0 = -1;
        field_c4 = -1;
        field_0 = 1;
        field_4 = 0;
        field_8 = 0;
        field_30 = true;
        field_34 = -1;
        field_38 = 1;
        field_3c = 0;
        field_40 = 0;
        field_44 = 0;
        field_48 = 0;
        field_4c = 0.0f;
        field_50 = 0;
        field_54 = 0;
        field_58 = 0;
        field_5c = 0;
        field_60 = 0.25f;
        field_64 = 0;
        field_68 = true;
        field_69 = true;
        field_6c = 8;
        field_70 = 0.25f;
        field_74 = 0;
        field_78 = 1;
        field_7c = 0.0f;
        field_80 = 0;
        field_84 = 0;
        field_88 = -1;
        field_8c = -1;
        field_c8 = 0;
        field_cc = -1;
        field_d0 = 0.85f;
        field_d4 = 0.75f;
        field_d8 = 0.0f;
        field_dc = 1.0f;
        field_e0 = 1.0f;
        field_e4 = 0;
        field_e8 = 0.0f;
        field_ec = false;
        field_f0 = 0.0f;
        field_f4 = 0;
        field_f8 = 0;
        field_fc = 0.0f;
        field_100 = 0;
        field_104 = INT32_MIN;
        field_108 = 0.0f;
        field_10c = 0;
        field_110 = 0;
        field_114 = 0;
        field_118 = 0;
        field_11c = 0x100;
        field_120 = 0x40;
        field_124 = 0;
        field_128 = 0;
        field_12c = 0;
        field_130 = 0;
        field_134 = 0;
        field_138 = 0;
        field_13c = false;
        field_140 = 0;
        field_144 = 0x80000000u;
        field_c = 0;
    }

    s32 field_0;  // m_nEffectViews (the log names it)
    s32 field_4;
    s32 field_8;
    s32 field_c;
    u32 field_10;  // the scene size (0: the device's)
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    f32 field_20;  // the aspect ratio (0: from the size)
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    bool field_30;
    u8 pad_31[0x3];
    s32 field_34;
    s32 field_38;
    s32 field_3c;
    s32 field_40;
    s32 field_44;
    s32 field_48;
    f32 field_4c;
    s32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5c;
    f32 field_60;
    s32 field_64;
    bool field_68;
    bool field_69;
    u8 pad_6a[0x2];
    s32 field_6c;
    f32 field_70;
    s32 field_74;
    u32 field_78;  // how many light shafts
    f32 field_7c;
    s32 field_80;
    s32 field_84;
    s32 field_88;
    s32 field_8c;
    s32 field_90;
    s32 field_94;
    s32 field_98;
    s32 field_9c;
    s32 field_a0;
    s32 field_a4;
    s32 field_a8;
    s32 field_ac;
    s32 field_b0;
    s32 field_b4;
    s32 field_b8;
    s32 field_bc;
    s32 field_c0;
    s32 field_c4;
    s32 field_c8;
    s32 field_cc;
    f32 field_d0;
    f32 field_d4;
    f32 field_d8;
    f32 field_dc;
    f32 field_e0;
    s32 field_e4;
    f32 field_e8;
    bool field_ec;
    u8 pad_ed[0x3];
    f32 field_f0;
    s32 field_f4;
    s32 field_f8;
    f32 field_fc;
    s32 field_100;
    s32 field_104;
    f32 field_108;
    s32 field_10c;
    s32 field_110;
    s32 field_114;
    s32 field_118;  // m_eFeedbackFormat (the log names it)
    s32 field_11c;
    s32 field_120;
    s32 field_124;  // how many light ghosts
    s32 field_128;
    s32 field_12c;
    s32 field_130;
    s32 field_134;
    s32 field_138;
    bool field_13c;
    u8 pad_13d[0x3];
    s32 field_140;
    u32 field_144;  // m_uiAntialiasFlags (the log names it)
};
PKMN_SIZE_ASSERT(PFX_INITPARAM, 0x148);

// what IPfxBaseContext::Initialize hands CPostEffect::Initialize (placeholder)
struct Unk_417b30_Desc {
    void* field_0;  // what IGPUDevice::CreateDevice is given (null: made here)
    u64 field_8;  // the frame buffer
    u32 field_10;
    u32 field_14;
    void* field_18;  // the NVN device
    // the callbacks that register and release the texture and sampler
    // descriptors, and what each is given (null: the post effect's own)
    void* field_20;
    void* field_28;
    void* field_30;
    void* field_38;
    void* field_40;
    void* field_48;
    void* field_50;
    void* field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
};

// four numbers that 0x71004320b0 hands on by address, copied (placeholder)
struct Unk_4320b0_Vector {
    f32 field_0[4];
};
PKMN_SIZE_ASSERT(Unk_4320b0_Vector, 0x10);

// what 0x71004306b0 hands 0x7100430250 and 0x710042f540 (placeholder)
struct Unk_42f540_Params {
    void* field_0;  // the target surface (its size at 0x4c)
    f32 field_8;
    f32 field_c;
    f32 field_10;
    s32 field_14;
    Unk_Float4 field_18;
    s32 field_28;
    s32 field_2c;
    MATRIXT44 field_30;
    MATRIXT44 field_70;
    f32 field_b0;
    f32 field_b4;
    f32 field_b8;
    f32 field_bc;
    f32 field_c0;
    f32 field_c4;
    bool field_c8;
    u8 pad_c9[0x3];
    f32 field_cc;
    f32 field_d0;
    f32 field_d4;
    f32 field_d8;
    f32 field_dc;
};
PKMN_SIZE_ASSERT(Unk_42f540_Params, 0xe0);

// a depth cast type kept if it is one of the four (-1 otherwise; inline: the
// callers of GPUPostEffect.cpp's Unk_DepthCastType that check its result)
inline s32 Unk_CheckDepthCastType(s32 type) {
    switch (type) {
    case 0:
    case 1:
    case 2:
    case 3:
        return type;
    default:
        return -1;
    }
}

class CPostEffect {
public:
    CPostEffect();               // 0x71004190f0
    ~CPostEffect();              // 0x7100419550
    // 0x710041afb0 (its log lines name it)
    s32 Initialize(const Unk_417b30_Desc* desc, u32 arg2, u32 arg3, u32 arg4, void* arg5);
    s32 Uninitialize(void* arg);   // 0x7100419690: its uninitialisation
    // 0x71004229e0 (its log lines name it): makes what the description
    // doesn't give (Initialize's first step)
    s32 CreateInternalResource_SiGfx(void** device, const Unk_417b30_Desc* desc);
    s32 Unk_425750();  // 0x7100425750
    s32 UpdateParameters_Base();  // 0x710042a7e0 (its log lines name it)
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
    // 0x7100435180 (EndPostEffectScene_Process's log line names it)
    s32 EndPostEffectScene_PreProcess(u32 flags, s32 samples);
    s32 Unk_438510();  // 0x7100438510: the end of the scene (EndPostEffectScene_Process)
    // 0x710042cc90
    s32 Unk_42cc90(s32 view, bool clear, void* source, void* target, bool keep, void* mask, u32 maskSpace,
                   u32 depthSpace, u32 flags, f32 offset);
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
    // 0x7100435ed0: CPostEffect::EndPostEffectScene_InternalProcess (its log
    // lines name it)
    s32 Unk_435ed0();
    // 0x710042c300 (its log line names it)
    s32 ApplyEffects_GenerateNormalAndLinearDepth();
    // 0x71004320b0: Unk_48cc30 from `source` (`target`: its texture, else
    // the one field_5f8 names) when field_10de or `force` says so
    s32 Unk_4320b0(Unk_RenderTexture* source, Unk_RenderTexture* target, bool flag, bool force);
    s32 Unk_432570();  // 0x7100432570 (not written yet)
    s32 Unk_433450();  // 0x7100433450 (not written yet)
    s32 Unk_42d490(Unk_RenderTexture* source);  // 0x710042d490 (not written yet)
    s32 Unk_434000(Unk_RenderTexture* source);  // 0x7100434000
    s32 Unk_433d00(Unk_RenderTexture* source);  // 0x7100433d00
    // 0x7100431b40: the colour chart's look-up textures, drawn again when
    // the colour spaces or field_bc4 and field_bc8 changed (1: none drawn)
    s32 Unk_431b40();
    // 0x71004306b0: the colour chart (0x7100430250) drawn into `surface`,
    // once more for the second output when there is one
    s32 Unk_4306b0(void* surface, f32 a, f32 b, f32 c, s32 arg4, const Unk_Float4* color, s32 arg6,
                   const MATRIXT44* matrix, f32 d, f32 e, f32 f, f32 g);
    // 0x710042f540: part `kind` of the colour chart in the `w` by `h`
    // rectangle at `x`, `y` of the `width` by `height` area
    s32 Unk_42f540(s32 kind, bool second, bool hdr, const Unk_42f540_Params* params, f32 width, f32 height, f32 x,
                   f32 y, f32 w, f32 h, f32 a, f32 b, f32 c, f32 d);
    // 0x7100430250: its parts (0x710042f540) laid out in a `width` by
    // `height` area from `x`, `y`
    s32 Unk_430250(bool second, bool hdr, bool pq, bool flag, const Unk_42f540_Params* params, f32 x, f32 y,
                   f32 width, f32 height);
    // 0x7100430a10 (not written yet; placeholder signature, from the call)
    s32 Unk_430a10(Unk_RenderTexture* source, void* arg2, void* surface, bool arg4);
    void DrawDebugBuffers();  // 0x71004386d0 (not written yet)
    // 0x7100428220
    s32 Unk_428220();
    bool Unk_4291c0();  // 0x71004291c0
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
    // its four numbers as one (inline: its array takes the caller's highest
    // stack slot)
    Unk_Rect Unk_DepthFactors(s32 from, s32 to, f32 a, f32 b) {
        f32 factors[4];
        Unk_428cc0(factors, from, to, a, b);
        Unk_Rect result = {factors[0], factors[1], factors[2], factors[3]};
        return result;
    }
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
    s32 EndCommandList_SiGfx();  // 0x7100426210
    // 0x7100426070: a view's (0x7fffffff: every view's) exposure history set
    // to `value` (when not positive, from field_6c4 and field_6c8)
    s32 Unk_426070(s32 view, f32 value);
    // 0x7100425dd0: CPostEffect::InitializeAutoExposure (its log line names it)
    s32 InitializeAutoExposure(s32 view, f32 luminance, f32 adjusted);
    // 0x7100426700 (its log line names it)
    s32 BeginPostEffectScene(u32 clearFlags, const void* clearColor, f32 clearDepth, u32 clearStencil, s32 aux);
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

    // whether the output is an HDR one (inline)
    bool Unk_IsHdrOutput() const { return field_96c || Unk_24e09bc != 0; }
    // whether it is one in field_970's way (inline)
    bool Unk_IsHdrDirect() const { return field_96c && field_970 != 0; }
    // `target` as the device's only target (inline: its array takes the
    // caller's highest stack slot)
    static s32 Unk_SetTarget(CRenderTexture* target) {
        CRenderTexture* targets[8] = {target};
        return Unk_49da70(8, targets, nullptr, nullptr, 0, nullptr, 0, 0, 0, 1.0f);
    }

    // per-view records (inline: the callers read the index before the array)
    s32 Unk_Frame(s32 view) const { return field_290[view]; }
    Unk_423990_Item& Unk_LightShaft(s32 view) { return field_858[view]; }
    Unk_423ba0_Item& Unk_LightGhost(s32 view) { return field_868[view]; }
    // what field_e04 holds from 0xe88 on, as 0x71004320b0 reads it (a
    // number, a render texture and four numbers; inline)
    s32 Unk_E88() const { return *reinterpret_cast<const s32*>(&field_e04[(0xe88 - 0xe04) / 4]); }
    // the same of 0xe04 (a mode) and 0xe48 (a matrix), as 0x710042c300 reads them
    s32 Unk_E04() const { return *reinterpret_cast<const s32*>(&field_e04[0]); }
    const MATRIXT44& Unk_E48() const {
        return *reinterpret_cast<const MATRIXT44*>(&field_e04[(0xe48 - 0xe04) / 4]);
    }
    CRenderTexture* Unk_E90() const {
        return *reinterpret_cast<CRenderTexture* const*>(&field_e04[(0xe90 - 0xe04) / 4]);
    }
    const Unk_4320b0_Vector& Unk_E98() const {
        return *reinterpret_cast<const Unk_4320b0_Vector*>(&field_e04[(0xe98 - 0xe04) / 4]);
    }

    // UNK_FIELDS_BEGIN
    bool field_0;  // between BeginPostEffectScene() and EndPostEffectScene()
    bool field_1;
    bool field_2;
    u8 pad_3[0x5];
    bool field_8;
    bool field_9;
    bool field_a;
    u8 pad_b[0x5];
    u64 field_10;
    IGPUDevice* field_18;
    u64 field_20;
    void* field_28;
    IGPUPixelContainer::Unk_Desc* field_30;  // the targets' descriptions
    IGPUPixelContainer::Unk_Desc* field_38;
    IGPUDevice* field_40;
    u64 field_48;
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
    bool field_88;
    u8 pad_89[0x3];
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
    u8 pad_c4[0x4];
    u64 field_c8;
    Unk_RenderTexture* field_d0;
    Unk_TextureMap<Unk_43c4e0> field_d8;
    Unk_TextureMap<Unk_43c490> field_f0;
    Unk_TextureMap<Unk_RenderTexture> field_108;  // CRenderTexture::m_mapDeviceTextureRenderTexture
    Unk_43c4e0* field_120;
    u64 field_128;
    u64 field_130;
    u64 field_138;
    u64 field_140;
    u64 field_148;
    u64 field_150;
    u64 field_158;
    u64 field_160;
    u64 field_168;
    u64 field_170;
    void* field_178;
    bool field_180;
    u8 pad_181[0x7];
    u64 field_188;
    Unk_4a5d10_Self* field_190;
    Unk_45eb90_Self* field_198;
    Unk_4aa5a0_Self* field_1a0;
    CRenderTextureArray* field_1a8;
    Unk_4a5d10_Self* field_1b0;
    bool field_1b8;
    bool field_1b9;
    bool field_1ba;
    bool field_1bb;
    bool field_1bc;
    bool field_1bd;
    bool field_1be;
    bool field_1bf;
    bool field_1c0;
    bool field_1c1;
    bool field_1c2;
    bool field_1c3;
    bool field_1c4;
    bool field_1c5;
    bool field_1c6;
    bool field_1c7;
    bool field_1c8;
    bool field_1c9;
    bool field_1ca;
    bool field_1cb;
    bool field_1cc;
    bool field_1cd;
    bool field_1ce;
    bool field_1cf;
    bool field_1d0;
    bool field_1d1;
    bool field_1d2;
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
    f32* field_240;  // one per view
    f32* field_248;
    f32* field_250;
    Unk_Rect* field_258;
    Unk_4a5d10_Self** field_260;  // one per view: the feedback textures
    Unk_RenderTexture* field_268;  // the feedback's tone map texture
    bool field_270;
    bool field_271;
    u8 pad_272[0x6];
    Unk_RenderTexture* field_278;
    s32 field_280;
    u8 pad_284[0x4];
    Unk_RenderTexture** field_288;
    s32* field_290;  // each view's frame number
    s32 field_298;  // the active view
    u8 pad_29c[0x4];
    Unk_429da0_Item* field_2a0;  // one per view
    Unk_429e60_Item* field_2a8;  // one per view
    u32 field_2b0;  // the flags Initialize was given (PFXINIT_*)
    u32 field_2b4;  // the flags in use
    PFX_INITPARAM field_2b8;  // the parameters Initialize was given
    // the parameters in use: a copy of field_2b8 that Initialize adjusts,
    // also read member by member
    union {
        PFX_INITPARAM field_400_param;
        struct {
            s32 field_400;  // m_nEffectViews (the log names it)
            s32 field_404;
            s32 field_408;
            s32 field_40c;
            u32 field_410;  // the scene size (0: the device's)
            u32 field_414;
            u32 field_418;
            u32 field_41c;
            f32 field_420;  // the aspect ratio (0: from the size)
            f32 field_424;
            f32 field_428;
            f32 field_42c;
            bool field_430;
            u8 pad_431[0x3];
            s32 field_434;
            s32 field_438;
            s32 field_43c;
            s32 field_440;
            s32 field_444;
            s32 field_448;
            f32 field_44c;
            s32 field_450;
            s32 field_454;
            s32 field_458;
            s32 field_45c;
            f32 field_460;
            s32 field_464;
            bool field_468;
            bool field_469;
            u8 pad_46a[0x2];
            s32 field_46c;
            f32 field_470;
            s32 field_474;
            u32 field_478;  // how many light shafts
            f32 field_47c;
            s32 field_480;
            s32 field_484;
            s32 field_488;
            s32 field_48c;
            s32 field_490;
            s32 field_494;
            s32 field_498;
            s32 field_49c;
            s32 field_4a0;
            s32 field_4a4;
            s32 field_4a8;
            s32 field_4ac;
            s32 field_4b0;
            s32 field_4b4;
            s32 field_4b8;
            s32 field_4bc;
            s32 field_4c0;
            s32 field_4c4;
            s32 field_4c8;
            s32 field_4cc;
            f32 field_4d0;
            f32 field_4d4;
            f32 field_4d8;
            f32 field_4dc;
            f32 field_4e0;
            s32 field_4e4;
            f32 field_4e8;
            bool field_4ec;
            u8 pad_4ed[0x3];
            f32 field_4f0;
            s32 field_4f4;
            s32 field_4f8;
            f32 field_4fc;
            s32 field_500;
            s32 field_504;
            f32 field_508;
            s32 field_50c;
            s32 field_510;
            s32 field_514;
            s32 field_518;  // m_eFeedbackFormat (the log names it)
            s32 field_51c;
            s32 field_520;
            s32 field_524;  // how many light ghosts
            s32 field_528;
            s32 field_52c;
            s32 field_530;
            s32 field_534;
            s32 field_538;
            bool field_53c;
            u8 pad_53d[0x3];
            s32 field_540;
            u32 field_544;  // m_uiAntialiasFlags (the log names it)
        };
    };
    bool field_548;
    u8 pad_549[0x7];
    Unk_RenderTexture** field_550;
    s32 field_558;
    u8 pad_55c[0x4];
    Unk_RenderTexturePair* field_560;  // field_568 pairs
    s32 field_568;
    u8 pad_56c[0x4];
    CRenderTexture** field_570;  // the OETF luminance's base work, one per view
    CRenderTexture** field_578;  // and its resize work, field_580 of them
    s32 field_580;
    u8 pad_584[0x4];
    CTextureLuminanceManage** field_588;  // one per view
    s32 field_590;
    bool field_594;
    bool field_595;
    bool field_596;
    bool field_597;
    bool field_598;
    bool field_599;
    bool field_59a;
    bool field_59b;
    bool field_59c;
    bool field_59d;
    bool field_59e;
    bool field_59f;
    bool field_5a0;
    bool field_5a1;
    bool field_5a2;
    u8 pad_5a3[0x1];
    f32 field_5a4;
    f32 field_5a8;
    f32 field_5ac;
    f32 field_5b0;
    u8 pad_5b4[0x4];
    Unk_RenderTexture* field_5b8;
    Unk_RenderTexture* field_5c0;
    u32 field_5c8;
    u32 field_5cc;
    s32 field_5d0;
    f32 field_5d4;
    s32 field_5d8;
    u32 field_5dc;  // whether the render buffer has mip textures
    s32 field_5e0;
    u32 field_5e4;
    s32 field_5e8;  // the render buffer's texture in use
    s32 field_5ec;
    s32 field_5f0;
    s32 field_5f4;
    s32 field_5f8;
    s32 field_5fc;
    s32 field_600;
    s32 field_604;
    s32 field_608;
    s32 field_60c;
    s32 field_610;
    s32 field_614;
    u8 pad_618[0x10];
    s32 field_628;
    s32 field_62c;
    s32 field_630;
    s32 field_634;
    s32 field_638;
    s32 field_63c;
    s32 field_640;
    s32 field_644;
    s32 field_648;
    s32 field_64c;
    s32 field_650;
    s32 field_654;
    s32 field_658;
    s32 field_65c;
    s32 field_660;
    s32 field_664;
    s32 field_668;
    s32 field_66c;
    s32 field_670;
    u8 pad_674[0x4];
    bool field_678;
    bool field_679;
    bool field_67a;
    bool field_67b;
    bool field_67c;
    u8 pad_67d[0x3];
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
    s32 field_6ac;
    u32 field_6b0;
    u32 field_6b4;
    u32 field_6b8;  // the scene's clear flags, depth and stencil
    f32 field_6bc;
    u32 field_6c0;
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
    bool field_84c;
    u8 pad_84d[0x3];
    s32 field_850;
    u8 pad_854[0x4];
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
    bool field_894;
    bool field_895;
    u8 pad_896[0x2];
    f32 field_898;
    f32 field_89c;
    u32 field_8a0;
    f32 field_8a4;
    Unk_Float2 field_8a8;
    f32 field_8b0;
    bool field_8b4;
    bool field_8b5;
    bool field_8b6;
    u8 pad_8b7[0x1];
    Unk_Float2 field_8b8;
    Unk_Float field_8c0;  // the tone map's exposure
    Unk_Float field_8c4;  // its gamma
    u32 field_8c8;        // the tone map
    f32 field_8cc;
    f32 field_8d0;
    Unk_Float4 field_8d4;
    f32 field_8e4;
    f32 field_8e8;
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
    f32 field_93c;
    f32 field_940;
    f32 field_944;
    f32 field_948;
    bool field_94c;  // whether field_93c and field_944 are scaled by field_89c
    bool field_94d;
    u8 pad_94e[0x2];
    f32 field_950;
    f32 field_954;
    f32 field_958;
    f32 field_95c;
    f32 field_960;
    bool field_964;  // field_960's side is the far one
    u8 pad_965[0x3];
    f32 field_968;  // the dither's offset scale
    bool field_96c;
    u8 pad_96d[0x3];
    u32 field_970;
    s32 field_974;
    s32 field_978;
    u32 field_97c;
    f32 field_980;
    f32 field_984;
    f32 field_988;
    f32 field_98c;
    f32 field_990;
    f32 field_994;
    bool field_998;
    bool field_999;
    u8 pad_99a[0x2];
    s32 field_99c;
    f32 field_9a0;
    f32 field_9a4;
    f32 field_9a8;
    s32 field_9ac;
    u32 field_9b0;
    MATRIXT44 field_9b4[6];  // the colour matrices
    bool field_b34[6];  // which of them changed
    u8 pad_b3a[0x2];
    MATRIXT44 field_b3c;
    s32 field_b7c;  // colour space numbers for field_b84 and field_ba4 (-1: none)
    s32 field_b80;
    Unk_410f90 field_b84;  // colour spaces
    Unk_410f90 field_ba4;
    f32 field_bc4;
    f32 field_bc8;
    bool field_bcc;
    bool field_bcd;
    bool field_bce;
    u8 pad_bcf[0x1];
    f32 field_bd0;
    f32 field_bd4;
    union {
        u64 field_bd8;  // (the constructor zeroes it as one)
        struct {
            f32 field_bd8_f;  // the feedback's numbers (0x7100434000)
            f32 field_bdc;
        };
    };
    u32 field_be0;
    bool field_be4;
    u8 pad_be5[0x3];
    f32 field_be8;
    bool field_bec;
    u8 pad_bed[0x3];
    f32 field_bf0;
    f32 field_bf4;
    f32 field_bf8;
    f32 field_bfc;
    f32 field_c00;
    u32 field_c04;
    f32 field_c08;
    f32 field_c0c;
    f32 field_c10;
    s32 field_c14;
    f32 field_c18;
    f32 field_c1c;
    f32 field_c20;
    f32 field_c24;
    f32 field_c28;
    bool field_c2c;
    bool field_c2d;
    u8 pad_c2e[0x2];
    s32 field_c30;
    bool field_c34;
    bool field_c35;
    bool field_c36;
    u8 pad_c37[0x1];
    Unk_Float2 field_c38;
    Unk_Float2 field_c40;
    Unk_Float2 field_c48;
    Unk_Float2 field_c50;
    Unk_Float2 field_c58;
    f32 field_c60;
    f32 field_c64;
    f32 field_c68;
    bool field_c6c;
    bool field_c6d;  // there are light shafts to draw
    bool field_c6e;  // there are light ghosts to draw
    bool field_c6f;
    bool field_c70;
    u8 pad_c71[0x3];
    f32 field_c74;
    bool field_c78;
    bool field_c79;
    bool field_c7a;
    u8 pad_c7b[0x1];
    Unk_Rect field_c7c;
    f32 field_c8c;
    bool field_c90;
    bool field_c91;
    u8 pad_c92[0x2];
    s32 field_c94;
    bool field_c98;
    u8 pad_c99[0x3];
    f32 field_c9c;
    f32 field_ca0;
    Unk_Float4 field_ca4[4];
    u8 pad_ce4[0x1];
    bool field_ce5;
    u8 pad_ce6[0x2];
    s32 field_ce8;
    bool field_cec;
    u8 pad_ced[0x3];
    Unk_Float field_cf0;
    Unk_Float field_cf4;
    s32 field_cf8;
    u32 field_cfc;
    Unk_Float field_d00;
    f32 field_d04;
    f32 field_d08;
    bool field_d0c;
    u8 pad_d0d[0x3];
    f32 field_d10;
    f32 field_d14;
    f32 field_d18;
    f32 field_d1c;
    f32 field_d20;
    f32 field_d24;
    s32 field_d28;
    s32 field_d2c;
    s32 field_d30;
    u8 pad_d34[0x4];
    Unk_RenderTexture* field_d38;
    bool field_d40;
    u8 pad_d41[0x7];
    u64 field_d48;
    f32 field_d50;
    f32 field_d54;
    f32 field_d58;
    f32 field_d5c;
    s32 field_d60;
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
    f32 field_d98;
    Unk_Float4 field_d9c;
    Unk_Float2 field_dac;
    Unk_Vector3 field_db4;
    s32 field_dc0;
    f32 field_dc4;
    f32 field_dc8;
    bool field_dcc;
    u8 pad_dcd[0x3];
    Unk_Float4 field_dd0;
    f32 field_de0;
    f32 field_de4;
    bool field_de8;
    u8 pad_de9[0x7];
    Unk_RenderTexture* field_df0;
    union {
        u64 field_df8;  // (the constructor zeroes it as one)
        struct {
            s32 field_df8_i;  // the normal's mode (0x710042c300)
            s32 field_dfc;
        };
    };
    bool field_e00;
    u8 pad_e01[0x3];
    f32 field_e04[41];
    union {
        struct {
            u64 field_ea8;
            u64 field_eb0;
        };
        Unk_4320b0_Vector field_ea8_v;
    };
    bool field_eb8;
    u8 pad_eb9[0x3];
    s32 field_ebc;
    f32 field_ec0;
    f32 field_ec4;
    f32 field_ec8;
    f32 field_ecc;
    f32 field_ed0;
    f32 field_ed4;
    f32 field_ed8;
    union {
        struct {
            f32 field_edc;
            f32 field_ee0;
            f32 field_ee4;
            f32 field_ee8;
        };
        Unk_4320b0_Vector field_edc_v;
    };
    f32 field_eec;
    f32 field_ef0;
    s32 field_ef4;
    f32 field_ef8;
    f32 field_efc;
    f32 field_f00;
    s32 field_f04;
    bool field_f08;
    u8 pad_f09[0x3];
    s32 field_f0c;
    bool field_f10;
    u8 pad_f11[0x3];
    f32 field_f14;
    f32 field_f18;
    f32 field_f1c;
    f32 field_f20;
    f32 field_f24;
    f32 field_f28;
    s32 field_f2c;
    s32 field_f30;
    f32 field_f34;
    bool field_f38;
    bool field_f39;
    u8 pad_f3a[0x2];
    f32 field_f3c;
    f32 field_f40;
    s32 field_f44;
    f32 field_f48;
    s32 field_f4c;
    s32 field_f50;
    s32 field_f54;
    bool field_f58;
    u8 pad_f59[0x3];
    f32 field_f5c;
    f32 field_f60;
    f32 field_f64;
    f32 field_f68;
    f32 field_f6c;
    f32 field_f70;
    s32 field_f74;
    u32 field_f78;
    Unk_Float field_f7c;
    s32 field_f80;
    Unk_4278c0_Data field_f84;
    s32 field_1008;
    f32 field_100c;
    f32 field_1010;
    bool field_1014;
    u8 pad_1015[0x3];
    f32 field_1018;
    f32 field_101c;
    s32 field_1020;
    s32 field_1024;
    u8 pad_1028[0x1];
    bool field_1029;
    u8 pad_102a[0x2];
    f32 field_102c[6];
    s32 field_1044;
    s32 field_1048;
    bool field_104c;
    bool field_104d;
    bool field_104e;
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
    bool field_106d;
    bool field_106e;
    u8 pad_106f[0x1];
    f32 field_1070;
    bool field_1074;
    bool field_1075;
    u8 pad_1076[0x2];
    s32 field_1078;  // the depth of field's mode this frame (-1: none)
    u8 pad_107c[0x4];
    bool field_1080;
    u8 pad_1081[0x3];
    Unk_Float2 field_1084;
    f32 field_108c;
    bool field_1090;
    bool field_1091;
    u8 pad_1092[0x2];
    MATRIXT44 field_1094;
    u8 pad_10d4[0x1];
    bool field_10d5;
    bool field_10d6;
    bool field_10d7;
    bool field_10d8;
    bool field_10d9;
    bool field_10da;
    bool field_10db;
    bool field_10dc;
    bool field_10dd;  // the normal and linear depth are drawn
    bool field_10de;
    bool field_10df;
    u8 pad_10e0[0x1];
    bool field_10e1;
    u8 pad_10e2[0x2];
    u32 field_10e4[18];
    u32 field_112c;
    union {
        u64 field_1130[6];  // (the constructor zeroes them as these)
        struct {
            f32 field_1130_0;  // the colour chart's numbers (0x7100430a10)
            f32 field_1134;
            f32 field_1138;
            f32 field_113c;
            f32 field_1140;
            f32 field_1144;
            f32 field_1148;
            f32 field_114c;
            f32 field_1150;
            f32 field_1154;
            f32 field_1158;
            f32 field_115c;
        };
    };
    u32 field_1160;
    u8 pad_1164[0x4];
    u64 field_1168;
    bool field_1170;
    u8 pad_1171[0x7];
    SiYebisAllocator field_1178;
    Unk_CommandList* field_1198;  // the NVN command list's
    Unk_CommandListMaker* field_11a0;
    void* field_11a8;
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
    u64 field_1208;
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
PKMN_OFFSET_ASSERT(CPostEffect, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(CPostEffect, field_178, 0x178);
PKMN_OFFSET_ASSERT(CPostEffect, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(CPostEffect, field_668, 0x668);
PKMN_OFFSET_ASSERT(CPostEffect, field_850, 0x850);
PKMN_OFFSET_ASSERT(CPostEffect, field_8e8, 0x8e8);
PKMN_OFFSET_ASSERT(CPostEffect, field_be0, 0xbe0);
PKMN_OFFSET_ASSERT(CPostEffect, field_c6c, 0xc6c);
PKMN_OFFSET_ASSERT(CPostEffect, field_ca4, 0xca4);
PKMN_OFFSET_ASSERT(CPostEffect, field_dd0, 0xdd0);
PKMN_OFFSET_ASSERT(CPostEffect, field_f64, 0xf64);
PKMN_OFFSET_ASSERT(CPostEffect, field_1024, 0x1024);
PKMN_OFFSET_ASSERT(CPostEffect, field_1080, 0x1080);
PKMN_OFFSET_ASSERT(CPostEffect, field_10e1, 0x10e1);
PKMN_OFFSET_ASSERT(CPostEffect, field_bdc, 0xbdc);
PKMN_OFFSET_ASSERT(CPostEffect, field_ea8_v, 0xea8);
PKMN_OFFSET_ASSERT(CPostEffect, field_edc_v, 0xedc);
PKMN_OFFSET_ASSERT(CPostEffect, field_f00, 0xf00);
PKMN_OFFSET_ASSERT(CPostEffect, field_115c, 0x115c);
PKMN_OFFSET_ASSERT(CPostEffect, field_94c, 0x94c);
PKMN_OFFSET_ASSERT(CPostEffect, field_964, 0x964);
PKMN_OFFSET_ASSERT(CPostEffect, field_f18, 0xf18);
PKMN_OFFSET_ASSERT(CPostEffect, field_1078, 0x1078);
PKMN_OFFSET_ASSERT(Unk_45eb90_Self, field_410, 0x410);
PKMN_OFFSET_ASSERT(Unk_4a5d10_Self, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_4a5d10_Self, field_80, 0x80);

}  // namespace PPFX
