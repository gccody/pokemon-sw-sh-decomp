// PPFX::CRenderGlare (C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp names
// the class in its log lines; the members are placeholders), as far as the
// functions written so far read it.
#pragma once

#include <math.h>
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>

namespace PPFX {

// 0x80 bytes that CRenderGlare has twice: the constructor's stores give the
// members' sizes
struct Unk_453_1f8 {
    u8 field_0[0x60];
};
struct Unk_453_208 {
    u8 field_0[0x34];
};
struct Unk_29af8;

struct Unk_453_30 {
    Unk_453_30() { Unk_Reset(); }
    void Unk_Reset() {
        memset(field_0, 0, sizeof(field_0));
        memset(field_18, 0, sizeof(field_18));
        field_48 = true;
        field_49 = true;
        field_4a = false;
        field_4c = 1;
        field_50 = false;
        field_54 = 2;
        field_58 = false;
        field_5c = 1;
        field_70 = false;
        field_71 = false;
        field_68 = 0;
        field_74 = 0;
        field_78 = 0;
        field_7c = false;
    }

    u8 field_0[0x15];
    s32 field_18[12];
    bool field_48;
    bool field_49;
    bool field_4a;
    u32 field_4c;
    bool field_50;
    s32 field_54;
    bool field_58;
    s32 field_5c;
    u64 field_60;
    u64 field_68;
    bool field_70;
    bool field_71;
    s32 field_74;
    s32 field_78;
    bool field_7c;
};
PKMN_SIZE_ASSERT(Unk_453_30, 0x80);

class CRenderGlare : public CGPUResourceManage {
public:
    CRenderGlare(const char* name);  // 0x71004530b0
    s32 vf0(IGPUDevice* device) override;     // 0x7100455b00
    s32 vf1() override;              // 0x7100456190
    s32 vf2() override;              // 0x7100456380
    s32 vf3() override;              // 0x71004563c0
    ~CRenderGlare() override;        // 0x7100455750, 0x71004557d0

    s32 Unk_4531d0(const char* name);  // 0x71004531d0
    bool Unk_455850();                 // 0x7100455850
    s32 CreateDeviceResources();       // 0x7100455b50

    // the members as a new object has them (inline in Unk_4531d0 and vf3: it
    // has the keyword, without which LLVM finds it too large)
    inline void Unk_Clear() {
        field_30.Unk_Reset();
        field_b0.Unk_Reset();
        field_23c = 0.5f;
        field_2e8 = 0;
        field_2e0 = 0;
        field_224[0] = 1.0f;
        field_224[1] = 1.0f;
        field_224[2] = 1.0f;
        field_224[3] = 1.0f;
        field_224[4] = 1.0f;
        field_224[5] = 1.0f;
        field_240 = 1.0f;
        field_244 = 0;
        field_220 = 0;
        field_218 = 0;
        field_210 = 2;
        field_250 = 0;
        field_248 = 0;
        field_25c = 0.5f;
        field_260 = 6;
        field_258 = 0;
        field_264 = 0;
        field_268 = 0;
        field_1f8 = nullptr;
        field_208 = nullptr;
        field_420 = 0;
        field_308 = 0;
        field_300 = nullptr;
        field_2f8 = nullptr;
        field_2f0 = nullptr;
        field_340 = nullptr;
        field_338 = nullptr;
        field_330 = nullptr;
        field_328 = nullptr;
        field_320 = nullptr;
        field_318 = nullptr;
        field_310 = nullptr;
        field_358 = nullptr;
        field_350 = nullptr;
        field_3d0 = nullptr;
        field_3c8 = nullptr;
        field_3c0 = nullptr;
        field_3b8 = nullptr;
        field_3b0 = nullptr;
        field_3a8 = nullptr;
        field_3a0 = nullptr;
        field_398 = nullptr;
        field_158 = 0.41421357f;
        field_15c = 0;
        field_160 = 0;
        field_154 = atanf(field_158) * 2.0f;
        field_164 = 1.0f;
        field_168 = 1.0f;
        field_134 = 64.0f;
        field_13c = 1.0f;
        field_360 = 0;
        field_368 = false;
        field_36c[0] = 1.0f;
        field_36c[1] = 1.0f;
        field_36c[2] = 1.0f;
        field_36c[3] = 1.0f;
        field_36c[4] = 1.0f;
        field_36c[5] = 1.0f;
        field_384[0] = 0.0f;
        field_384[1] = 0.0f;
        field_390 = nullptr;
        field_348 = nullptr;
    }

    // UNK_FIELDS_BEGIN
    Unk_453_30 field_30;
    Unk_453_30 field_b0;
    u8 pad_130[0x4];
    f32 field_134;
    u8 pad_138[0x4];
    f32 field_13c;
    u8 pad_140[0x14];
    f32 field_154;
    f32 field_158;
    s32 field_15c;
    s32 field_160;
    f32 field_164;
    f32 field_168;
    u8 pad_16c[0x8c];
    Unk_453_1f8* field_1f8;
    u8 pad_200[0x8];
    Unk_453_208* field_208;
    s32 field_210;
    u8 pad_214[0x4];
    u64 field_218;
    s32 field_220;
    f32 field_224[6];
    f32 field_23c;
    f32 field_240;
    s32 field_244;
    u64 field_248;
    u64 field_250;
    s32 field_258;
    f32 field_25c;
    s32 field_260;
    s32 field_264;
    s32 field_268;
    u8 pad_26c[0x74];
    u64 field_2e0;
    u64 field_2e8;
    CGPUResourceManage* field_2f0;
    void* field_2f8;
    void** field_300;
    s32 field_308;
    u8 pad_30c[0x4];
    CGPUResourceManage** field_310;
    CGPUResourceManage* field_318;
    Unk_29af8* field_320;
    CGPUResourceManage* field_328;
    CGPUResourceManage* field_330;
    CGPUResourceManage* field_338;
    CGPUResourceManage* field_340;
    IGPUInterface* field_348;
    CGPUResourceManage** field_350;
    u32* field_358;
    u64 field_360;
    bool field_368;
    u8 pad_369[0x3];
    f32 field_36c[6];
    f32 field_384[2];
    u8 pad_38c[0x4];
    CGPUResourceManage* field_390;
    CGPUResourceManage* field_398;
    CGPUResourceManage* field_3a0;
    CGPUResourceManage* field_3a8;
    CGPUResourceManage* field_3b0;
    CGPUResourceManage* field_3b8;
    CGPUResourceManage* field_3c0;
    CGPUResourceManage* field_3c8;
    CGPUResourceManage* field_3d0;
    u8 pad_3d8[0x48];
    u64 field_420;
    // UNK_FIELDS_END
};

}  // namespace PPFX
