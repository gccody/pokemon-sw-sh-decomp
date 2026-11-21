// PPFX::TEXSHADERSET and CTextureUtil (../src/GPU/GPUTextureUtil.h is the
// __FILE__ of CTextureUtil's inline functions' asserts; the log lines of
// GPUTextureUtil.cpp name the classes). Placeholder members: field_<offset>.
#pragma once

// YEBIS keeps its asserts (the build defines NDEBUG for everything)
#undef NDEBUG
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTexturePool.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>

// 0x7100442c50 (lib/yebis/leaf has it with a u32 result; its callers here
// test bit 0 and lay their blocks out as for a bool)
bool Unk_442c50_get(u64 device);
// 0x7100446620: the device of an IGPUResource (with a reference)
void Unk_446620(void* resource, PPFX::IGPUDevice** device);

namespace PPFX {

// PPFX::IGPUTexture, as the DrawRectGPU functions call it (a
// CRenderTexture's field_a8 is one)
struct Unk_GPUTexture {
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
    virtual void vf15(s32 filter);  // sets what vf16 gives
    virtual s32 vf16();
    virtual void vf17(s32 arg);

    u8 pad_8[0x44];
    u32 field_4c;  // its size
    u32 field_50;
};

// PPFX::IGPUEffect, as this file calls it
struct Unk_463fd0_Effect {
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
    virtual s32 vf10();  // "OnResetDevice"
    virtual s32 vf11();
    virtual s32 vf12(u32 parent, const char* name);  // a parameter's handle
    virtual void vf13();
    virtual void vf14();
    virtual s32 vf15(const char* name);  // a technique's handle
    virtual void vf16();
    virtual void vf17();
    virtual void vf18(s32 parameter, f32 value);  // a float
    virtual void vf19();
    virtual void vf20(s32 parameter, const f32* value);
    virtual void vf21();
    virtual void vf22(s32 parameter, const Unk_Float4* values, s32 count);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26(s32 parameter, Unk_GPUTexture* texture);
    virtual s32 vf27(s32 technique);
    virtual s32 vf28(s32 technique);
    virtual void vf29(s32 technique);
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33(void* passes, u32 technique);  // begins a technique
    virtual s32 vf34();  // ends it
    virtual void vf35(s32 pass);  // begins a pass
    virtual void vf36();  // ends it
    // 0x710049a480: IGPUEffect's function, under IGPUEffect's symbol. This
    // struct is that class with the parameters this file's callers pass (the
    // class in GPUInterfaceEffect.h has the parameters its own functions
    // read), and the call has to take the member as it is: a cast to the
    // other class makes the member's address a second expression, and the
    // DrawRect functions then lose the pointer to the member they keep in a
    // register (GVN's PRE of that address needs one expression).
    s32 SetupGraphicsPipelineState() __asm__("_ZN4PPFX10IGPUEffect26SetupGraphicsPipelineStateEv");
    virtual void* vf37(s32 arg);
    virtual void vf38();
    virtual s32 vf39(s32 arg);
    virtual void vf40();
    virtual void vf41();
    virtual void vf42(IGPUInterface* layout, IGPUBuffer* vertices, u32 offset, s32 arg4, s32 arg5, s32 arg6);
};

// 0x710049a300: "IGPUEffect::CreateEffectFromFile()" in the log
s32 Unk_49a300(void* device, const void* data, s32 size, void* arg3, void* effect, char** errors,
               s32 arg6);

// the depth-of-field scatter techniques, cleared as one
struct Unk_1af6c {
    s32 field_0[32];
    s32 field_80[8];
    s32 field_a0[40][5];
};
PKMN_SIZE_ASSERT(Unk_1af6c, 0x3c0);

class TEXSHADERSET {
public:
    TEXSHADERSET() {
        memset(this, 0, __builtin_offsetof(TEXSHADERSET, field_299b4));
        for (s32 i = 0; i < 13; i++) {
            field_299b8[i] = nullptr;
        }
        field_29a20 = nullptr;
    }

    s32 CreateEffect(void* device);  // 0x7100463fd0
    s32 InitializeDevice(IGPUDevice* device, bool keepEffect);  // 0x710046d7e0
    s32 Unk_46d990(void* arg);       // 0x710046d990: releases the effect

    // the layout of a position alone (inline in the DrawRect functions)
    void Unk_Layout1() {
        if (field_0 == nullptr) {
            return;
        }
        IGPUDevice* device;
        Unk_InputElement elements[1] = {
            Unk_InputElement(0, 0, 0x10),
        };
        if (field_299b8[0] != nullptr) {
            return;
        }
        Unk_446620(field_0, &device);
        device->vf1();
        void* arg3 = field_0->vf37(0);
        s32 arg4 = field_0->vf39(0);
        device->vf70(elements, 1, arg3, arg4, &field_299b8[0]);
    }
    // 0x710046cfe0 to 0x710046d6f0: the vertex layouts (a position and 1 to 6
    // texture coordinates; 5 of another format; 2 with another position)
    s32 Unk_46cfe0();
    s32 Unk_46d0c0();
    s32 Unk_46d1b0();
    s32 Unk_46d2a0();
    s32 Unk_46d3a0();
    s32 Unk_46d4b0();
    s32 Unk_46d5e0();
    s32 Unk_46d6f0();

    // a technique's handles: one per HDR format pair, per tone map, ...
    s32 Unk_462fe0(s32* techniques, const char* name);
    s32 Unk_463220(s32* techniques, const char* name, s32 count);
    s32 Unk_463340(s32 (*techniques)[8][22], const char* name);
    s32 Unk_463500(s32* techniques, const char* name);
    s32 Unk_463750(s32 (*techniques)[22], const char* name);
    s32 Unk_463980(s32 (*techniques)[7][22], const char* name);
    s32 Unk_463a70(s32 (*techniques)[16], const char* name);
    s32 Unk_463d90(s32* parameters, s32 count, const char* name);

    // the techniques `name` with its last character replaced by 1, 2, ...
    // (inline in CreateEffect: placeholder name)
    void Unk_GetTechs(s32 (*techniques)[22], const char* name, s32 count) {
        Unk_TFXString prefix(name);
        prefix.Unk_451530(prefix.field_0 - 1);
        char buffer[1024];
        for (s32 i = 0; i < count; i++) {
            sprintf(buffer, "%s%d", prefix.field_8, i + 1);
            Unk_462fe0(techniques[i], buffer);
        }
    }
    void Unk_GetTechs(s32 (*techniques)[2][7][22], const char* name, s32 count) {
        Unk_TFXString prefix(name);
        prefix.Unk_451530(prefix.field_0 - 1);
        char buffer[1024];
        for (s32 i = 0; i < count; i++) {
            sprintf(buffer, "%s%d", prefix.field_8, i + 1);
            Unk_463980(techniques[i], buffer);
        }
    }

    Unk_463fd0_Effect* field_0;
    s32 field_8;
    s32 field_c;
    s32 field_10[16];
    s32 field_50[16];
    s32 field_90[4];
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
    s32 field_d0;
    s32 field_d4;
    s32 field_d8;
    s32 field_dc;
    s32 field_e0;
    s32 field_e4;
    s32 field_e8;
    s32 field_ec;
    s32 field_f0;
    s32 field_f4;
    s32 field_f8;
    s32 field_fc;
    s32 field_100;
    s32 field_104;
    s32 field_108;
    s32 field_10c;
    s32 field_110;
    s32 field_114;
    s32 field_118[32][22];
    s32 field_c18[32][22];
    s32 field_1718[32][22];
    s32 field_2218[32][22];
    s32 field_2d18[1][22];
    u8 pad_2d70[0x528];
    s32 field_3298[1][22];
    u8 pad_32f0[0x528];
    s32 field_3818[1][22];
    u8 pad_3870[0x528];
    s32 field_3d98[1][22];
    u8 pad_3df0[0x528];
    s32 field_4318;
    s32 field_431c;
    s32 field_4320;
    s32 field_4324;
    s32 field_4328[16][22];
    s32 field_48a8[16][22];
    s32 field_4e28[16][22];
    s32 field_53a8[16][22];
    s32 field_5928[16][22];
    s32 field_5ea8[1][22];
    u8 pad_5f00[0x528];
    s32 field_6428[1][22];
    u8 pad_6480[0x528];
    s32 field_69a8[16][22];
    s32 field_6f28[16][22];
    s32 field_74a8[4][22];
    u8 pad_7608[0x108];
    s32 field_7710[1][22];
    s32 field_7768[1][22];
    s32 field_77c0[1][22];
    s32 field_7818[1][22];
    s32 field_7870[1][22];
    s32 field_78c8[1][22];
    s32 field_7920[1][22];
    s32 field_7978[1][22];
    s32 field_79d0[1][22];
    s32 field_7a28;
    s32 field_7a2c;
    s32 field_7a30;
    s32 field_7a34[22];
    s32 field_7a8c[22];
    s32 field_7ae4[22];
    s32 field_7b3c[22];
    s32 field_7b94[22];
    s32 field_7bec[22];
    s32 field_7c44[22];
    s32 field_7c9c[22];
    s32 field_7cf4[22];
    u8 pad_7d4c[0x58];
    s32 field_7da4;
    s32 field_7da8;
    s32 field_7dac;
    s32 field_7db0;
    s32 field_7db4;
    s32 field_7db8;
    s32 field_7dbc;
    s32 field_7dc0;
    s32 field_7dc4;
    s32 field_7dc8[6];
    s32 field_7de0[6];
    s32 field_7df8[6];
    s32 field_7e10[6];
    s32 field_7e28[7];
    u8 pad_7e44[0x4];
    s32 field_7e48;
    s32 field_7e4c;
    s32 field_7e50;
    s32 field_7e54;
    s32 field_7e58;
    s32 field_7e5c;
    s32 field_7e60;
    s32 field_7e64;
    s32 field_7e68;
    s32 field_7e6c;
    s32 field_7e70;
    s32 field_7e74;
    s32 field_7e78;
    s32 field_7e7c;
    u8 pad_7e80[0x8];
    s32 field_7e88;
    s32 field_7e8c;
    s32 field_7e90;
    s32 field_7e94;
    s32 field_7e98;
    s32 field_7e9c;
    s32 field_7ea0;
    u8 pad_7ea4[0x8];
    s32 field_7eac[2][8][22];  // tech_DepthOfField_CompositeBlurredLevels(_USNORM)_Tn: [USNORM][textures - 1]
    s32 field_842c[2][8][22];  // ...CompositeBlurredLevelsFrontBlur(_USNORM)_Tn
    s32 field_89ac[8][8][22];
    s32 field_9fac[8][8][22];
    s32 field_b5ac[8][8][22];
    s32 field_cbac[8][8][22];
    s32 field_e1ac[25][22];
    s32 field_ea44[25][22];
    s32 field_f2dc[25][22];
    s32 field_fb74[25][22];
    s32 field_1040c[17];
    u8 pad_10450[0x40];
    s32 field_10490[17];
    u8 pad_104d4[0x40];
    s32 field_10514[33];
    s32 field_10598[33];
    s32 field_1061c[17];
    u8 pad_10660[0x40];
    s32 field_106a0[17];
    u8 pad_106e4[0x40];
    s32 field_10724[33];
    s32 field_107a8[33];
    s32 field_1082c[17];
    u8 pad_10870[0x40];
    s32 field_108b0[17];
    u8 pad_108f4[0x40];
    s32 field_10934[33];
    s32 field_109b8[33];
    s32 field_10a3c[17];
    u8 pad_10a80[0x40];
    s32 field_10ac0[17];
    u8 pad_10b04[0x40];
    s32 field_10b44[33];
    s32 field_10bc8[33];
    s32 field_10c4c;
    u8 pad_10c50[0x4];
    s32 field_10c54;
    u8 pad_10c58[0x4];
    s32 field_10c5c;
    u8 pad_10c60[0x4];
    s32 field_10c64;
    u8 pad_10c68[0x4];
    s32 field_10c6c;
    u8 pad_10c70[0x10];
    s32 field_10c80;
    s32 field_10c84[1][2][7][22];
    u8 pad_11154[0x4830];
    s32 field_15984;
    u8 pad_15988[0x4];
    s32 field_1598c;
    u8 pad_15990[0x4];
    s32 field_15994;
    u8 pad_15998[0x4];
    s32 field_1599c;
    u8 pad_159a0[0x4];
    s32 field_159a4;
    u8 pad_159a8[0x14];
    s32 field_159bc[1][2][7][22];
    u8 pad_15e8c[0x4830];
    s32 field_1a6bc;
    s32 field_1a6c0;
    s32 field_1a6c4;
    s32 field_1a6c8;
    s32 field_1a6cc;
    s32 field_1a6d0;
    s32 field_1a6d4[25][22];
    Unk_1af6c field_1af6c;
    s32 field_1b32c;
    s32 field_1b330;
    s32 field_1b334;
    u8 pad_1b338[0xc];
    s32 field_1b344;
    u8 pad_1b348[0x8];
    s32 field_1b350;
    s32 field_1b354;
    s32 field_1b358;
    s32 field_1b35c;
    s32 field_1b360;
    s32 field_1b364;
    s32 field_1b368;
    s32 field_1b36c;
    s32 field_1b370;
    s32 field_1b374;
    s32 field_1b378;
    s32 field_1b37c;
    s32 field_1b380;
    s32 field_1b384;
    s32 field_1b388;
    s32 field_1b38c;
    s32 field_1b390;
    s32 field_1b394[8];
    s32 field_1b3b4[8];
    s32 field_1b3d4[8];
    s32 field_1b3f4[8];
    s32 field_1b414[4];
    s32 field_1b424;
    s32 field_1b428;
    s32 field_1b42c;
    s32 field_1b430;
    s32 field_1b434[8][22];
    s32 field_1b6f4[8][22];
    s32 field_1b9b4[8][22];
    s32 field_1bc74[8][22];
    s32 field_1bf34[8][22];
    s32 field_1c1f4[8][22];
    s32 field_1c4b4;
    s32 field_1c4b8;
    s32 field_1c4bc;
    s32 field_1c4c0;
    s32 field_1c4c4;
    u8 pad_1c4c8[0x8];
    s32 field_1c4d0;
    s32 field_1c4d4;
    s32 field_1c4d8;
    s32 field_1c4dc;
    s32 field_1c4e0;
    u8 pad_1c4e4[0x8];
    s32 field_1c4ec;
    s32 field_1c4f0;
    s32 field_1c4f4;
    s32 field_1c4f8;
    s32 field_1c4fc;
    u8 pad_1c500[0x8];
    s32 field_1c508;
    s32 field_1c50c;
    s32 field_1c510;
    s32 field_1c514;
    s32 field_1c518;
    u8 pad_1c51c[0x8];
    s32 field_1c524[8][22];
    s32 field_1c7e4[8][22];
    s32 field_1caa4[8][22];
    s32 field_1cd64[8][22];
    s32 field_1d024[8][22];
    s32 field_1d2e4[8][22];
    s32 field_1d5a4[8][22];
    s32 field_1d864[8][22];
    s32 field_1db24[8][22];
    s32 field_1dde4[8][22];
    s32 field_1e0a4[8][22];
    s32 field_1e364[8][22];
    s32 field_1e624[8][22];
    s32 field_1e8e4[8][22];
    s32 field_1eba4[8][22];
    s32 field_1ee64[8][22];
    s32 field_1f124[8][22];
    s32 field_1f3e4[8][22];
    s32 field_1f6a4[8][22];
    s32 field_1f964[8][22];
    s32 field_1fc24[8][22];
    s32 field_1fee4[8][22];
    s32 field_201a4[8][22];
    s32 field_20464[8][22];
    s32 field_20724;
    s32 field_20728;
    s32 field_2072c;
    s32 field_20730[128][16];
    s32 field_22730;
    s32 field_22734;
    s32 field_22738;
    s32 field_2273c[4];
    s32 field_2274c;
    s32 field_22750;
    s32 field_22754;
    s32 field_22758;
    s32 field_2275c;
    s32 field_22760;
    s32 field_22764;
    u8 pad_22768[0x4];
    s32 field_2276c;
    s32 field_22770;
    s32 field_22774;
    s32 field_22778;
    s32 field_2277c;
    s32 field_22780;
    u8 pad_22784[0x4];
    s32 field_22788;
    s32 field_2278c;
    s32 field_22790;
    s32 field_22794;
    s32 field_22798;
    u8 pad_2279c[0x14];
    s32 field_227b0;
    s32 field_227b4;
    s32 field_227b8;
    s32 field_227bc;
    s32 field_227c0;
    s32 field_227c4;
    s32 field_227c8;
    s32 field_227cc;
    s32 field_227d0;
    s32 field_227d4;
    s32 field_227d8;
    s32 field_227dc;
    s32 field_227e0;
    s32 field_227e4;
    s32 field_227e8;
    s32 field_227ec;
    s32 field_227f0;
    s32 field_227f4;
    s32 field_227f8;
    s32 field_227fc;
    s32 field_22800;
    s32 field_22804;
    s32 field_22808;
    s32 field_2280c;
    s32 field_22810[4];
    s32 field_22820[4];
    s32 field_22830[4];
    s32 field_22840[4];
    s32 field_22850[16];
    s32 field_22890[16];
    s32 field_228d0[16];
    s32 field_22910[16];
    s32 field_22950[16];
    s32 field_22990[16];
    u8 pad_229d0[0x80];
    s32 field_22a50[16];
    u8 pad_22a90[0x1c0];
    s32 field_22c50[16];
    u8 pad_22c90[0x40];
    s32 field_22cd0[16];
    s32 field_22d10[16];
    s32 field_22d50[16];
    s32 field_22d90[16];
    s32 field_22dd0[16];
    s32 field_22e10[16];
    u8 pad_22e50[0x80];
    s32 field_22ed0[16];
    u8 pad_22f10[0x240];
    s32 field_23150[16];
    u8 pad_23190[0x40];
    s32 field_231d0[16];
    s32 field_23210[16];
    s32 field_23250[16];
    s32 field_23290[16];
    u8 pad_232d0[0x80];
    s32 field_23350[16];
    u8 pad_23390[0x1c0];
    s32 field_23550[16];
    u8 pad_23590[0x40];
    s32 field_235d0[16];
    s32 field_23610[16];
    s32 field_23650[16];
    s32 field_23690[16];
    s32 field_236d0[16];
    s32 field_23710[16];
    u8 pad_23750[0x80];
    s32 field_237d0[16];
    u8 pad_23810[0x240];
    s32 field_23a50[16];
    u8 pad_23a90[0x40];
    s32 field_23ad0[16];
    s32 field_23b10[16];
    s32 field_23b50[16];
    s32 field_23b90[16];
    u8 pad_23bd0[0x80];
    s32 field_23c50[16];
    u8 pad_23c90[0x1c0];
    s32 field_23e50[16];
    u8 pad_23e90[0x40];
    s32 field_23ed0[16];
    s32 field_23f10[16];
    s32 field_23f50[16];
    s32 field_23f90[16];
    s32 field_23fd0[16];
    s32 field_24010[16];
    u8 pad_24050[0x80];
    s32 field_240d0[16];
    u8 pad_24110[0x240];
    s32 field_24350[16];
    u8 pad_24390[0x40];
    s32 field_243d0[16];
    u8 pad_24410[0x3c0];
    s32 field_247d0[16];
    u8 pad_24810[0x440];
    s32 field_24c50[16];
    u8 pad_24c90[0x440];
    s32 field_250d0[16];
    u8 pad_25110[0x440];
    s32 field_25550[16];
    u8 pad_25590[0x440];
    s32 field_259d0[16];
    u8 pad_25a10[0x440];
    s32 field_25e50[16];
    u8 pad_25e90[0x80];
    s32 field_25f10[16];
    s32 field_25f50[16];
    s32 field_25f90[16];
    u8 pad_25fd0[0x80];
    s32 field_26050[16];
    u8 pad_26090[0x1c0];
    s32 field_26250[16];
    u8 pad_26290[0x40];
    s32 field_262d0[16];
    s32 field_26310[16];
    s32 field_26350[16];
    s32 field_26390[16];
    s32 field_263d0[16];
    s32 field_26410[16];
    u8 pad_26450[0x80];
    s32 field_264d0[16];
    u8 pad_26510[0x240];
    s32 field_26750[16];
    u8 pad_26790[0x40];
    s32 field_267d0[16];
    s32 field_26810[16];
    s32 field_26850[16];
    s32 field_26890[16];
    u8 pad_268d0[0x80];
    s32 field_26950[16];
    u8 pad_26990[0x1c0];
    s32 field_26b50[16];
    u8 pad_26b90[0x40];
    s32 field_26bd0[16];
    s32 field_26c10[16];
    s32 field_26c50[16];
    s32 field_26c90[16];
    s32 field_26cd0[16];
    s32 field_26d10[16];
    u8 pad_26d50[0x80];
    s32 field_26dd0[16];
    u8 pad_26e10[0x240];
    s32 field_27050[16];
    u8 pad_27090[0x40];
    s32 field_270d0[16];
    s32 field_27110[16];
    s32 field_27150[16];
    s32 field_27190[16];
    u8 pad_271d0[0x80];
    s32 field_27250[16];
    u8 pad_27290[0x1c0];
    s32 field_27450[16];
    u8 pad_27490[0x40];
    s32 field_274d0[16];
    s32 field_27510[16];
    s32 field_27550[16];
    s32 field_27590[16];
    s32 field_275d0[16];
    s32 field_27610[16];
    u8 pad_27650[0x80];
    s32 field_276d0[16];
    u8 pad_27710[0x240];
    s32 field_27950[16];
    u8 pad_27990[0x40];
    s32 field_279d0[16];
    u8 pad_27a10[0x3c0];
    s32 field_27dd0[16];
    u8 pad_27e10[0x440];
    s32 field_28250[16];
    u8 pad_28290[0x440];
    s32 field_286d0[16];
    u8 pad_28710[0x440];
    s32 field_28b50[16];
    u8 pad_28b90[0x440];
    s32 field_28fd0[16];
    u8 pad_29010[0x440];
    s32 field_29450[16];
    u8 pad_29490[0x80];
    s32 field_29510[16];
    s32 field_29550[16];
    s32 field_29590[16];
    u8 pad_295d0[0x80];
    s32 field_29650[16];
    u8 pad_29690[0x1c0];
    s32 field_29850[16];
    u8 pad_29890[0x80];
    s32 field_29910[16];
    s32 field_29950[16];
    u8 pad_29990[0x24];
    s32 field_299b4;  // the constructor clears what's before it at once
    IGPUInterface* field_299b8[13];
    u8* field_29a20;  // the effect file
};
PKMN_OFFSET_ASSERT(TEXSHADERSET, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(TEXSHADERSET, field_1af6c, 0x1af6c);
PKMN_OFFSET_ASSERT(TEXSHADERSET, field_29a20, 0x29a20);

// PPFX::CTextureUtil (its log lines name it and its DrawRectGPU functions;
// RTTI its base, CGPUResourceManage): the texture utilities' shaders, vertex
// buffers and shared textures.
struct Unk_29af8 {
    u8 field_0[0x38];
};

// a sample point: two coordinates, and two zeros
struct Unk_SamplePoint {
    Unk_SamplePoint(f32 x, f32 y) : field_0(x), field_4(y), field_8(0.0f), field_c(0.0f) {}

    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};
// 0x71024e2d50: eight of them, set by CTextureUtil::Unk_46dc60
extern Unk_SamplePoint Unk_24e2d50[8];

// a corner of the rectangle CTextureUtil draws, as Unk_471470 gives it: x, y and 0
struct Unk_RectPosition {
    Unk_RectPosition() {}

    Unk_Float field_0[3];
};
PKMN_SIZE_ASSERT(Unk_RectPosition, 0xc);

// The vertex of a rectangle with N rectangles of texture coordinates. The
// DrawRect functions make each one as a temporary and copy it into their
// array: they read all of a corner's elements before they write any.
template <s32 N>
struct Unk_RectVertex {
    Unk_RectVertex() {}
    // corner `i`
    Unk_RectVertex(const Unk_RectPosition& position, const Unk_Float2 (*coords)[4], s32 i) {
        field_0.field_0[0] = position.field_0[0];
        field_0.field_0[1] = position.field_0[1];
        for (s32 j = 0; j < N; j++) {
            field_8[j].field_0[0] = coords[j][i].field_0[0];
            field_8[j].field_0[1] = coords[j][i].field_0[1];
        }
    }

    Unk_Float2 field_0;
    Unk_Float2 field_8[N];
};

// A render texture's device texture: its outermost parent's (inline in the
// DrawRectGPU functions).
inline Unk_GPUTexture* Unk_GetTexture(CRenderTexture* texture) {
    while (texture->field_120 != nullptr) {
        texture = texture->field_120;
    }
    return reinterpret_cast<Unk_GPUTexture*>(texture->field_a8);
}

// The texture coordinates of the far corner of a render texture's viewport
// (inline in the DrawRectGPU functions).
inline void Unk_GetCoords(const CRenderTexture* texture, f32* u, f32* v) {
    f32 width = static_cast<f32>(static_cast<u32>(texture->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(texture->field_58));
    *u = texture->field_88 * width + texture->field_90;
    *v = texture->field_8c * height + texture->field_94;
}

class CTextureUtil : public CGPUResourceManage {
public:
    CTextureUtil(const char* name);  // 0x710046db60
    s32 Unk_46dc60(const char* name);  // 0x710046dc60
    s32 Unk_46e360(s32 width, s32 height, s32 format);  // 0x710046e360: the colour bars
    s32 Unk_46e740(s32 width, s32 height, s32 format);  // 0x710046e740: the chromaticity diagrams
    s32 Unk_46ea80(s32 width, s32 height);              // 0x710046ea80: the waveform monitor
    s32 Unk_46ec80(u32 width, u32 height);              // 0x710046ec80: all of the colour chart's
    void Unk_471410();                                  // 0x7100471410

    // the members as the constructor leaves them (inline in Unk_46dc60 and vf3)
    inline void Unk_Clear() {
        field_29a98 = nullptr;
        for (s32 i = 0; i < 8; i++) {
            field_29b68[i] = nullptr;
        }
        field_29b00 = nullptr;
        for (s32 i = 0; i < 10; i++) {
            field_29b08[i] = nullptr;
        }
        field_29ba8 = 1.0f;
        field_29a60 = true;
        field_29ab0 = true;
        field_29ad0 = true;
        field_29ae8 = 0x20;
        field_29aec = 1;
        field_29c00 = 0x40;
        field_29c04 = 1;
        field_29bb0 = nullptr;
        field_29af0 = 0;
        field_29af8 = nullptr;
        for (s32 i = 0; i < 5; i++) {
            field_29a70[i] = nullptr;
        }
        for (s32 i = 0; i < 2; i++) {
            field_29aa0[i] = nullptr;
        }
        for (s32 i = 0; i < 3; i++) {
            field_29ab8[i] = nullptr;
        }
        for (s32 i = 0; i < 2; i++) {
            field_29ad8[i] = nullptr;
        }
        for (s32 i = 0; i < 7; i++) {
            field_29bc8[i] = nullptr;
        }
        for (s32 i = 0; i < 2; i++) {
            field_29b58[i] = nullptr;
        }
    }
    s32 vf0(IGPUDevice* device) override;  // 0x710046edd0
    s32 vf1() override;           // 0x7100470e40
    s32 vf2() override;           // 0x7100470e70
    s32 vf3() override;           // 0x7100470e90
    ~CTextureUtil() override;     // 0x710046e110, 0x710046e1c0

    s32 Unk_4708b0(void* arg);  // 0x71004708b0
    // 0x7100471960: draws a rectangle (or the triangle that covers it) in the current target
    s32 Unk_471960(f32 x, f32 y, f32 width, f32 height, u32 flags);
    // 0x7100471470: the corners of a rectangle (or of the triangle that
    // covers it) and of `sets` rectangles of texture coordinates
    s32 Unk_471470(s32 sets, const Unk_Float2* from, const Unk_Float2* to, u32 flags, s32* count,
                   Unk_RectPosition* positions, Unk_Float2 (*coords)[4], f32 x, f32 y, f32 width, f32 height);
    // 0x7100471c50 to 0x7100472cd0: the same with 1 to 6 rectangles of
    // texture coordinates. The flags are the last parameter: the callers set
    // w1 after the floating-point registers.
    s32 Unk_471c50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, u32 flags);
    s32 Unk_471f60(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, u32 flags);
    s32 Unk_472250(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, u32 flags);
    s32 Unk_472590(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, u32 flags);
    s32 Unk_472900(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, f32 u4, f32 v4, f32 s4, f32 t4, u32 flags);
    s32 Unk_472cd0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, f32 u4, f32 v4, f32 s4, f32 t4, f32 u5, f32 v5, f32 s5, f32 t5, u32 flags);
    // The end of the DrawRect functions (inline; its result is the draw call's): the vertices go through
    // the vertex buffer, which is written as a ring, and are drawn as a strip.
    // (`inline` is spelled out: the hint is what gets a function this long inlined.)
    inline s32 Unk_DrawVertices(const void* vertices, s32 count, u32 stride, s32 layout) {
        u32 size = count * stride;
        u32 start = field_29bb8;
        bool wrap = start + size >= field_29bbc;
        if (wrap) {
            start = 0;
            field_29bb8 = 0;
        }
        field_29bb8 = start + size;
        IGPUBuffer* buffer = static_cast<IGPUBuffer*>(field_29bc8[0]);
        memcpy(buffer->Map(wrap ? 6 : 2, start, size), vertices, size);
        static_cast<IGPUBuffer*>(field_29bc8[0])->Unmap();
        field_30.field_0->vf42(field_30.field_299b8[layout], static_cast<IGPUBuffer*>(field_29bc8[0]), start, 0, 0, 1);
        field_20->vf9(field_29bc8[1], 0);
        field_30.field_0->SetupGraphicsPipelineState();
        return field_20->vf58(5, count, 0, 0, count - 1);
    }
    // 0x7100473d90 and on: the DrawRectGPU functions. Each sets a technique
    // and its parameters, and draws one of the rectangles above. Their
    // floating-point parameters come first and the flags last (the order the
    // callers fill the registers in, and the order of the entry's copies).
    s32 Unk_473d90(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg9, f32 arg10, f32 arg11,
                   f32 arg12, f32 arg13, const Unk_Float4* arg1, const Unk_Float4* arg2, const Unk_Float4* matrix,
                   Unk_GPUTexture* texture, u32 flags);
    s32 Unk_475150(CRenderTexture* source, CRenderTexture* target, bool clear);
    s32 Unk_475320(f32 arg8, f32 arg9, CRenderTexture* source, CRenderTexture* target, const Unk_Float4* arg3,
                   const Unk_Float4* arg4, const Unk_Float4* arg5, const Unk_Float4* arg6, u32 flags);
    s32 Unk_473150(f32 x, f32 y, f32 width, f32 height, const f32* u0, const f32* v0, const f32* u1, const f32* v1,
                   s32 count, u32 flags);
    s32 Unk_4732b0(s32 count, s32 arg2, s32 arg3, IGPUBuffer* vertices, void* indices, u32 offset, s32 arg7,
                   u32 flags);
    s32 Unk_474ae0(CRenderTexture* target, CRenderTexture* source, bool clear);
    s32 Unk_473fd0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 sigma, f32 arg10,
                   f32 arg11, const Unk_Float2* direction, Unk_GPUTexture* texture, s32 taps, u32 flags);
    s32 Unk_474d00(f32 sigma, f32 arg2, f32 arg3, CRenderTexture* source, CRenderTexture* target, bool horizontal,
                   s32 taps, bool clear);
    s32 Unk_4768b0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                   Unk_GPUTexture** textures, const Unk_Float4* colors, s32 index, u32 flags);
    s32 Unk_476bc0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power, s32 count,
                   Unk_GPUTexture** textures, const Unk_Float4* colors, s32 index, u32 flags);
    s32 Unk_4772f0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power, s32 count,
                   CRenderTexture** sources, const Unk_Float4* colors, s32 index, u32 flags);
    s32 Unk_47aa60(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, const Unk_Float4* value,
                   Unk_GPUTexture* texture, void* arg3, u32 flags);
    void Unk_47abf0(f32 value);
    s32 Unk_47ac50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2, f32 u3,
                   f32 v3, s32 count, Unk_GPUTexture** textures, const Unk_Float2* weights, bool arg4, s32 arg5,
                   s32 index, u32 flags);
    s32 Unk_47ae50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2, f32 u3,
                   f32 v3, s32 arg1, s32 arg2, Unk_GPUTexture** textures, const Unk_Float2* weights, s32 arg5,
                   s32 index, u32 flags);
    // The handle of a texture stage (inline; its name and line are its assert's)
    s32 GetHandle_tex2D_aTexture(s32 stage) {
#line 3059
        assert(stage >= 0 && stage < 16);
        return field_30.field_10[stage];
    }
    s32 Unk_470860(s32 value);  // 0x7100470860
    s32 Unk_470880();           // 0x7100470880
    s32 Unk_4708a0(void* arg);  // 0x71004708a0

    // UNK_FIELDS_BEGIN
    TEXSHADERSET field_30;
    CRenderTexturePool* field_29a58;
    bool field_29a60;
    u8 pad_29a61[0x3];
    s32 field_29a64;
    u8 pad_29a68[0x4];
    bool field_29a6c;
    u8 pad_29a6d[0x3];
    IGPUInterface* field_29a70[5];
    CRenderTexture* field_29a98;
    IGPUInterface* field_29aa0[2];
    bool field_29ab0;
    u8 pad_29ab1[0x7];
    IGPUInterface* field_29ab8[3];
    bool field_29ad0;
    u8 pad_29ad1[0x7];
    IGPUInterface* field_29ad8[2];
    s32 field_29ae8;
    s32 field_29aec;
    s32 field_29af0;
    u8 pad_29af4[0x4];
    Unk_29af8* field_29af8;
    CRenderTexture* field_29b00;
    CRenderTexture* field_29b08[10];
    void* field_29b58[2];
    void* field_29b68[8];
    f32 field_29ba8;
    u8 pad_29bac[0x4];
    void* field_29bb0;
    u32 field_29bb8;
    u32 field_29bbc;
    u8 pad_29bc0[0x8];
    IGPUInterface* field_29bc8[7];  // the vertex buffer the rectangles go through, the index buffer, ...
    s32 field_29c00;
    s32 field_29c04;
    // UNK_FIELDS_END
};
PKMN_OFFSET_ASSERT(CTextureUtil, field_29a58, 0x29a58);
PKMN_SIZE_ASSERT(CTextureUtil, 0x29c08);

}  // namespace PPFX
