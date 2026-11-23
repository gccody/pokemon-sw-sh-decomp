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
struct Unk_GlareRect {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};
struct Unk_GlarePair {
    f32 field_0;
    f32 field_4;
};
// what field_170 points to (set outside this file): a colour at 8
struct Unk_45_170 {
    u8 pad_0[0x8];
    Unk_Vector3 field_8;
    u8 pad_14[0x4];
    Unk_Vector3 field_18;
    u8 pad_24[0xc];
    Unk_Vector3 field_30;
    u8 pad_3c[0x10];
    Unk_Vector3 field_4c;
    u8 pad_58[0x10];
    f32 field_68;
    Unk_Vector3 field_6c;
    u8 pad_78[0x10];
    s32 field_88;
    u8 pad_8c[0x4];
    f32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_45_170, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_45_170, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_45_170, field_90, 0x90);
struct Unk_453_1f8 {
    Unk_GlareRect field_0;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
    u8 pad_24[0x38];
    f32 field_5c;
};
PKMN_SIZE_ASSERT(Unk_453_1f8, 0x60);
struct Unk_453_208 {
    u8 field_0[0x34];
};
struct Unk_29af8;

struct Unk_453_30 {
    Unk_453_30() { Unk_Reset(); }
    void Unk_Reset() {
        memset(field_bytes, 0, sizeof(field_bytes));
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

    // the first 0x15 bytes, which the reset clears as one
    union {
        u8 field_bytes[0x15];
        struct {
            u32 field_0;
            u32 field_4;
            u32 field_8;
            u32 field_c;
            u32 field_10;
            bool field_14;
        };
    };
    union {
        s32 field_18[12];
        f32 field_18_f[12];  // the same words where they are floats
    };
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
    f32 field_74;
    f32 field_78;
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
    // 0x71004555a0 (its log line names it)
    s32 Initialize(const Unk_453_30* desc);
    s32 Unk_453540();  // 0x7100453540 (not written yet)
    s32 Unk_45e980(void* arg);  // 0x710045e980: hands `arg` to every resource
    s32 Unk_45ca70(CRenderTexture* texture, s32 index);  // 0x710045ca70 (not written yet)
    s32 Unk_45c880();  // 0x710045c880
    bool Unk_455850();                 // 0x7100455850
    // 0x71004534f0: the field of view (tan(22.5 degrees) for none) and two more numbers
    s32 Unk_4534f0(f32 fov, f32 a, f32 b);
    // 0x7100453440: three numbers (-1: field_b0's)
    s32 Unk_453440(s32 a, s32 b, s32 c);
    f32 Unk_45ed80();  // 0x710045ed80
    f32 Unk_45ee20();  // 0x710045ee20
    // 0x710045e940
    s32 Unk_45e940(const Unk_GlareRect* a, const Unk_GlarePair* b, const Unk_GlarePair* c);
    // 0x71004552e0: the light shaft of a view
    s32 Unk_4552e0(s32 view, const Unk_GlareRect* rect, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
    f32 Unk_45d350();  // 0x710045d350
    // 0x710045e8a0
    s32 Unk_45e8a0(bool a, s32 b, bool c, const u64* d, const u64* e, const u64* f, const u64* g, const u64* h,
                   bool i, f32 j, f32 k, f32 l);
    s32 CreateDeviceResources();       // 0x7100455b50

    // the members as a new object has them (inline in Unk_4531d0 and vf3: it
    // has the keyword, without which LLVM finds it too large)
    inline void Unk_Clear() {
        field_30.Unk_Reset();
        field_b0.Unk_Reset();
        field_23c = 0.5f;
        field_2e8 = 0;
        field_2ec = 0;
        field_2e0 = 0;
        field_2e4 = 0;
        field_224.field_0 = 1.0f;
        field_224.field_4 = 1.0f;
        field_224.field_8 = 1.0f;
        field_224.field_c = 1.0f;
        field_234 = 1.0f;
        field_238 = 1.0f;
        field_240 = 1.0f;
        field_244 = 0.0f;
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
        field_36c.field_0 = 1.0f;
        field_36c.field_4 = 1.0f;
        field_36c.field_8 = 1.0f;
        field_36c.field_c = 1.0f;
        field_37c.field_0 = 1.0f;
        field_37c.field_4 = 1.0f;
        field_384.field_0 = 0.0f;
        field_384.field_4 = 0.0f;
        field_390 = nullptr;
        field_348 = nullptr;
    }

    // 0x7100456bf0, 0x7100456f30, 0x71004570b0, 0x7100457370: whether
    // parts of the glare changed
    bool Unk_456bf0();
    bool Unk_456f30();
    bool Unk_4570b0();
    bool Unk_457370();
    bool Unk_457650();  // 0x7100457650: whether nothing is to be drawn again
    f32 Unk_458420();   // 0x7100458420: the glare's luminance
    f32 Unk_458250();   // 0x7100458250
    f32 Unk_458580();   // 0x7100458580
    s32 Unk_457f00(CRenderTexture* source, s32 arg2, CRenderTexture* arg3);  // 0x7100457f00
    void Unk_457760(CRenderTexture* source, CRenderTexture* target);  // 0x7100457760 (not written yet)

    // UNK_FIELDS_BEGIN
    Unk_453_30 field_30;
    Unk_453_30 field_b0;
    u8 pad_130[0x4];
    f32 field_134;
    f32 field_138;
    f32 field_13c;
    u8 pad_140[0x14];
    f32 field_154;
    f32 field_158;
    f32 field_15c;
    f32 field_160;
    f32 field_164;
    f32 field_168;
    u8 pad_16c[0x4];
    const Unk_45_170* field_170;
    u8 pad_178[0x8];
    bool field_180;
    u8 pad_181[0x3];
    f32 field_184;
    f32 field_188;
    bool field_18c;
    u8 pad_18d[0x1f];
    bool field_1ac;
    u8 pad_1ad[0x37];
    f32 field_1e4;
    u8 pad_1e8[0xc];
    s32 field_1f4;
    Unk_453_1f8* field_1f8;
    s32 field_200;
    u8 pad_204[0x4];
    Unk_453_208* field_208;
    s32 field_210;
    u8 pad_214[0x4];
    u64 field_218;
    s32 field_220;
    Unk_GlareRect field_224;
    f32 field_234;
    f32 field_238;
    f32 field_23c;
    f32 field_240;
    f32 field_244;
    u64 field_248;
    u64 field_250;
    s32 field_258;
    f32 field_25c;
    s32 field_260;
    s32 field_264;
    s32 field_268;
    bool field_26c;
    u8 pad_26d[0x2f];
    bool field_29c;
    u8 pad_29d[0x3];
    s32 field_2a0;
    bool field_2a4;
    u8 pad_2a5[0x3];
    u64 field_2a8;
    u64 field_2b0;
    u64 field_2b8;
    u64 field_2c0;
    u64 field_2c8;
    f32 field_2d0;
    f32 field_2d4;
    f32 field_2d8;
    bool field_2dc;
    u8 pad_2dd[0x3];
    s32 field_2e0;
    s32 field_2e4;
    s32 field_2e8;
    s32 field_2ec;  // the active view
    CGPUResourceManage* field_2f0;
    void* field_2f8;
    CRenderTexture** field_300;  // field_308 of them
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
    Unk_GlareRect field_36c;
    Unk_GlarePair field_37c;
    Unk_GlarePair field_384;
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
    s32 field_3d8;
    f32 field_3dc;
    f32 field_3e0;
    f32 field_3e4;
    f32 field_3e8;
    f32 field_3ec;
    f32 field_3f0;
    f32 field_3f4;
    f32 field_3f8;
    u8 pad_3fc[0x14];
    bool field_410;
    u8 pad_411[0x7];
    f32 field_418;
    u8 pad_41c[0x4];
    u64 field_420;
    // UNK_FIELDS_END
};

}  // namespace PPFX
