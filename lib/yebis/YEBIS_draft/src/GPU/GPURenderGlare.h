// PPFX::CRenderGlare (C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp names
// the class in its log lines; the members are placeholders, except the
// m_p... ones that 0x7100453540 (CreateSystemObjects) names in the strings it
// gives their objects), as far as the functions written so far read it.
#pragma once

#include <math.h>
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>

namespace PPFX {

class IGPUSurface;
class CRenderTextureArray;

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
    f32 field_14;  // each colour's fourth element
    Unk_Vector3 field_18;
    f32 field_24;
    u8 pad_28[0x8];
    Unk_Vector3 field_30;
    f32 field_3c;
    u8 pad_40[0xc];
    Unk_Vector3 field_4c;
    f32 field_58;
    u8 pad_5c[0xc];
    f32 field_68;
    Unk_Vector3 field_6c;
    f32 field_78;
    u8 pad_7c[0xc];
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
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    f32 field_30;
    Unk_GlareRect field_34;
    Unk_Float2 field_44;  // the shaft's centre
    f32 field_4c[4];
    f32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_453_1f8, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_453_1f8, field_44, 0x44);
PKMN_SIZE_ASSERT(Unk_453_1f8, 0x60);
// a light ghost (field_208's elements)
struct Unk_453_208 {
    bool field_0;
    u8 pad_1[0x3];
    f32 field_4[4];     // its colour
    Unk_Float2 field_14;
    Unk_Float2 field_1c;
    s32 field_24;  // its kind (2: field_29a70[4]'s texture)
    f32 field_28;
    f32 field_2c;
    u8 pad_30[0x4];
};
PKMN_SIZE_ASSERT(Unk_453_208, 0x34);
// a light ghost preset (Unk_24e5950's elements, GPUGlareDef.cpp)
struct Unk_GlareGhostDef {
    u8 field_0[0x1b00];
    s32 field_1b00;  // the number of its ghosts
};
PKMN_SIZE_ASSERT(Unk_GlareGhostDef, 0x1b04);
class Unk_4a0540;

// field_320's elements (placeholder): a texture at 0x18
struct Unk_45_320 {
    s32 field_0;  // the level's number from the first blurred one, plus 1 (0: not blurred)
    f32 field_4;  // its scale
    f32 field_8;
    u8 pad_c[0x4];
    CRenderTexture* field_10;
    CRenderTexture* field_18;
    CRenderTexture* field_20;
    CRenderTexture* field_28;
    CRenderTexture* field_30;

    // field_28 or field_30, else field_18 (inline)
    CRenderTexture* Unk_Texture28() const {
        CRenderTexture* texture = field_18;
        if (field_28 != nullptr) {
            texture = field_28;
        }
        return texture;
    }
    CRenderTexture* Unk_Texture30() const {
        CRenderTexture* texture = field_18;
        if (field_30 != nullptr) {
            texture = field_30;
        }
        return texture;
    }
};
PKMN_SIZE_ASSERT(Unk_45_320, 0x38);

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
    union {
        u64 field_60;
        struct {
            bool field_60_b;  // whether there are light ghosts
            s32 field_64;     // how many
        };
    };
    union {
        u64 field_68;
        const s32* field_68_p;  // the same as a pointer (the glare definitions' seeds)
    };
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
    s32 CreateSystemObjects();  // 0x7100453540 (its log lines name it)
    s32 Unk_45e980(void* arg);  // 0x710045e980: hands `arg` to every resource
    s32 Unk_45ca70(CRenderTexture* target, s32 index);  // 0x710045ca70: the light shaft of a view
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
        m_pGlareSource = nullptr;
        m_pGhostGeneration = nullptr;
        m_pAnamorphicFlareResult = nullptr;
        m_pStarResult = nullptr;
        m_pStarGeneration = nullptr;
        field_320 = nullptr;
        m_pBloomResult = nullptr;
        m_ppBloomGeneration = nullptr;
        field_358 = nullptr;
        m_ppAfterimageGeneration = nullptr;
        m_pLightShaftResult = nullptr;
        m_pLightShaftGeneration = nullptr;
        m_pLightShaftBlurSource = nullptr;
        m_pGlareResultUpsample = nullptr;
        m_pGlareResultAntialias = nullptr;
        m_pGlareResultLensDistortionFalloff = nullptr;
        m_pGlareResultChromaticAberration = nullptr;
        m_pGlareResult = nullptr;
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
        m_pLightGhostLuminance = nullptr;
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
    s32 Unk_458720();          // 0x7100458720
    s32 Unk_458e20();          // 0x7100458e20: the ghosts' levels added up into m_pBloomResult
    // field_3d8, at most field_b0.field_18[6] (inline)
    s32 Unk_LevelCount() const {
        s32 count = field_3d8;
        s32 limit = field_b0.field_18[6];
        return limit < count ? limit : count;
    }
    s32 Unk_4593f0(bool flag);  // 0x71004593f0: the glare's star (`flag`: the sixth star definition)
    // 0x7100459730 (not written yet; placeholder signature, from its caller)
    s32 Unk_459730(const Unk_4a0540* star, CRenderTexture* target, CGPUResourceManage* texture,
                   CRenderTexture** textures, CRenderTexture** pair, s32 count, bool flag);
    s32 Unk_45a820();          // 0x710045a820 (not written yet)
    s32 GenerateGlare_Afterimage();  // 0x710045c1e0 (its log line names it)
    s32 GenerateGlare_Composite();  // 0x710045d3b0 (its log lines name it)
    // 0x710045ee80: the glare of a frame
    s32 Unk_45ee80(CRenderTexture* source, f32 f0, f32 f1, f32 f2, f32 f3, s32 arg2, f32 f4, u32 index,
                   const Unk_45_170* color, f32 f5, f32 f6, bool flag, s32 arg6, CRenderTexture* arg7);
    f32 Unk_458580();   // 0x7100458580
    s32 Unk_457f00(CRenderTexture* source, s32 arg2, CRenderTexture* arg3);  // 0x7100457f00
    s32 Unk_457760(CRenderTexture* source, CRenderTexture* target);  // 0x7100457760
    // 0x710045f1c0 (its caller's log line names it): `source` and the glare
    // tone mapped into `surface` (`format` -1: copied, `frames` 1: filtered)
    s32 TonemapToSurface(IGPUSurface* surface, bool hasSurface, CRenderTexture* source, bool hasGamma, s32 format,
                         const Unk_Float4* color, const MATRIXT44* matrix, f32 width, f32 height, f32 x, f32 y,
                         f32 intensity, f32 gamma, f32 exposure, f32 white, f32 step, const MATRIXT44* matrix2,
                         f32 luminance, const Unk_Float4* arg17, f32 arg18, f32 arg19, f32 arg20, f32 arg21,
                         f32 arg22, f32 arg23, f32 aspect, bool arg25, const Unk_Float4* rect, s32 space, s32 blend,
                         s32 frames, f32 arg30, void* arg31);

    // UNK_FIELDS_BEGIN
    Unk_453_30 field_30;
    Unk_453_30 field_b0;
    bool field_130;
    u8 pad_131[0x3];
    f32 field_134;
    f32 field_138;
    f32 field_13c;
    s32 field_140;
    f32 field_144;
    s32 field_148;  // the lens dirt
    f32 field_14c;
    f32 field_150;
    f32 field_154;
    f32 field_158;
    f32 field_15c;
    f32 field_160;
    f32 field_164;
    f32 field_168;
    u8 pad_16c[0x4];
    const Unk_45_170* field_170;
    f32 field_178;
    f32 field_17c;
    bool field_180;
    u8 pad_181[0x3];
    f32 field_184;
    f32 field_188;
    bool field_18c;
    u8 pad_18d[0x3];
    f32 field_190;
    f32 field_194;
    f32 field_198;
    Unk_Float4 field_19c;
    bool field_1ac;
    u8 pad_1ad[0x3];
    f32 field_1b0;
    f32 field_1b4;
    f32 field_1b8;
    f32 field_1bc;
    f32 field_1c0;
    f32 field_1c4;
    f32 field_1c8;
    f32 field_1cc;
    f32 field_1d0;
    f32 field_1d4;
    f32 field_1d8;
    f32 field_1dc;
    f32 field_1e0;
    f32 field_1e4;
    f32 field_1e8;
    f32 field_1ec;
    f32 field_1f0;
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
    union {
        u64 field_248;
        struct {
            f32 field_248_f;
            f32 field_24c;
        };
    };
    union {
        u64 field_250;
        struct {
            f32 field_250_f;
            f32 field_254;
        };
    };
    s32 field_258;
    f32 field_25c;
    s32 field_260;
    s32 field_264;
    f32 field_268;
    bool field_26c;  // the lens distortion
    u8 pad_26d[0x3];
    f32 field_270[8];
    f32 field_290;
    s32 field_294;
    f32 field_298;
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
    CGPUResourceManage* m_pGlareSource;
    void* field_2f8;
    CRenderTexture** field_300;  // field_308 of them
    s32 field_308;
    u8 pad_30c[0x4];
    CGPUResourceManage** m_ppBloomGeneration;
    CGPUResourceManage* m_pBloomResult;
    Unk_45_320* field_320;
    CGPUResourceManage* m_pStarGeneration;
    CGPUResourceManage* m_pStarResult;
    CGPUResourceManage* m_pAnamorphicFlareResult;
    CGPUResourceManage* m_pGhostGeneration;
    IGPUInterface* field_348;
    CRenderTextureArray** m_ppAfterimageGeneration;  // one per view
    f32* field_358;
    u64 field_360;
    bool field_368;
    u8 pad_369[0x3];
    Unk_GlareRect field_36c;
    Unk_GlarePair field_37c;
    Unk_GlarePair field_384;
    u8 pad_38c[0x4];
    CGPUResourceManage* m_pLightGhostLuminance;
    CGPUResourceManage* m_pGlareResult;
    CGPUResourceManage* m_pGlareResultChromaticAberration;
    CGPUResourceManage* m_pGlareResultLensDistortionFalloff;
    CGPUResourceManage* m_pGlareResultAntialias;
    CGPUResourceManage* m_pGlareResultUpsample;
    CGPUResourceManage* m_pLightShaftBlurSource;
    CGPUResourceManage* m_pLightShaftGeneration;
    CGPUResourceManage* m_pLightShaftResult;
    s32 field_3d8;
    f32 field_3dc;
    f32 field_3e0;
    f32 field_3e4;
    f32 field_3e8;
    f32 field_3ec;
    f32 field_3f0;
    f32 field_3f4;
    f32 field_3f8;
    f32 field_3fc;
    f32 field_400;
    f32 field_404;
    Unk_Float field_408;  // copied as an object
    f32 field_40c;
    bool field_410;
    bool field_411;
    u8 pad_412[0x2];
    s32 field_414;
    f32 field_418;
    bool field_41c;
    u8 pad_41d[0x3];
    CRenderTexture* field_420;  // the glare's result
    bool field_428;
    // UNK_FIELDS_END
};
PKMN_OFFSET_ASSERT(CRenderGlare, field_190, 0x190);
PKMN_OFFSET_ASSERT(CRenderGlare, field_19c, 0x19c);
PKMN_OFFSET_ASSERT(CRenderGlare, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(CRenderGlare, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(CRenderGlare, field_148, 0x148);
PKMN_OFFSET_ASSERT(CRenderGlare, field_254, 0x254);
PKMN_OFFSET_ASSERT(CRenderGlare, field_270, 0x270);
PKMN_OFFSET_ASSERT(CRenderGlare, field_298, 0x298);
PKMN_OFFSET_ASSERT(CRenderGlare, field_3fc, 0x3fc);
PKMN_OFFSET_ASSERT(CRenderGlare, field_411, 0x411);
PKMN_OFFSET_ASSERT(CRenderGlare, field_428, 0x428);

}  // namespace PPFX
