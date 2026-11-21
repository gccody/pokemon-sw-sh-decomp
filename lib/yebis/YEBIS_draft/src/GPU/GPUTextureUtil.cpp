// Scope: common
// PPFX::TEXSHADERSET, the shader set of YEBIS's texture utilities
// (C:/workspace/YEBIS_draft/src/GPU/GPUTextureUtil.cpp, the __FILE__ of its log
// lines and allocations). The class and CreateEffect are named by the log
// lines ("TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() ..."),
// which leave the namespace out as they do for PPFX::IGPUEffect; everything
// else is a placeholder. CreateEffect's body is the list of the effect's
// parameters and techniques: field_<offset> is where each handle goes.
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <miniz/miniz_yebis.h>
#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/GPUTextureUtil.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

extern "C" int mz_uncompress(unsigned char* pDest, unsigned long* pDest_len, const unsigned char* pSource,
                             unsigned long source_len);

// log switches: all messages, PPFX_ERROR's and PPFX_LOG's
extern s32 Unk_238c1e0;
extern s32 Unk_238c1e8;
extern s32 Unk_24e0008;
// the effect file, compressed: its size, then miniz's stream
extern const u8 Unk_1b61595[];

// 0x7101b3516c: "CTextureUtil"
extern const char Unk_1b3516c[];

// 0x7100417a30: printf to the log
void Unk_417a30(const char* format, ...);
// 0x7100446df0: an error code's name
const char* Unk_446df0(s32 result);

#define PPFX_LOG(...)                                                                                 \
    do {                                                                                              \
        if (Unk_238c1e0 != 0 && Unk_24e0008 != 0) {                                                   \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPUTextureUtil.cpp(%d) : PPFX: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                  \
        }                                                                                             \
    } while (0)
#define PPFX_ERROR(...)                                                                                     \
    do {                                                                                                    \
        if (Unk_238c1e0 != 0 && Unk_238c1e8 != 0) {                                                         \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPUTextureUtil.cpp(%d) : PPFX ERROR: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                        \
        }                                                                                                   \
    } while (0)

// 0x71024e4a18 and 0x71024e4c18: this file's scratch vectors (statics: the
// code takes their addresses directly), written just before the effect reads
// them. The sizes matter: the compiler only folds an element's offset into the
// address it materialises when the offset is inside the object.
extern PPFX::Unk_Float4 Unk_24e4a18[32] __attribute__((visibility("hidden")));
extern PPFX::Unk_Float4 Unk_24e4c18[32] __attribute__((visibility("hidden")));

namespace PPFX {

// the bokeh kernels' sample counts
static const s32 Unk_1b35158[5] = {7, 19, 37, 61, 91};

// The static variables of YEBIS's src/GPU code (each helper's suffix table and
// the flag that says it is filled in), where the executable has them. LLVM
// merged the internal globals of that TU (every src/GPU file, by the functions
// that use this block: 0x7100462fe0 to 0x7100499b70) into one object, so the
// code addresses them from one base, and it shrank each flag, a static bool
// only ever set to true, to one bit: the code tests bit 0 of its byte. Until
// the whole TU is here they can't be defined, so they are declared as the
// block they became.
struct Unk_24e45d0_Statics {
    u8 field_0;  // Unk_462fe0's
    u8 field_1;  // Unk_463500's
    u8 field_2;  // Unk_463750's
    u8 field_3;  // Unk_463980's
    u8 field_4;  // Unk_463a70's
    u8 _5[0x160 - 0x5];
    const char* field_160[7];  // Unk_463750's
    const char* field_198[2];  // Unk_463980's
    const char* field_1a8[7];  // Unk_463a70's
    u8 _1e0[0x318 - 0x1e0];
    const char* field_318[16];  // Unk_463500's
    const char* field_398[22];  // Unk_462fe0's
};
PKMN_OFFSET_ASSERT(Unk_24e45d0_Statics, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_24e45d0_Statics, field_398, 0x398);
extern Unk_24e45d0_Statics Unk_24e45d0 __attribute__((visibility("hidden")));

// 0x7100462fe0: the technique `name` for each pair of HDR formats
s32 TEXSHADERSET::Unk_462fe0(s32* techniques, const char* name) {
    if (!(Unk_24e45d0.field_0 & 1)) {
        Unk_24e45d0.field_0 = 1;
        Unk_24e45d0.field_398[0] = "";
        Unk_24e45d0.field_398[1] = "_REINHARDRGB_RGB";
        Unk_24e45d0.field_398[2] = "_REINHARDRGB_RGBFAST";
        Unk_24e45d0.field_398[3] = "_RGB_REINHARDRGB";
        Unk_24e45d0.field_398[4] = "_REINHARDRGBLUM_RGB";
        Unk_24e45d0.field_398[5] = "_REINHARDRGBLUM_RGBFAST";
        Unk_24e45d0.field_398[6] = "_RGB_REINHARDRGBLUM";
        Unk_24e45d0.field_398[7] = "_LOGRGB_RGB";
        Unk_24e45d0.field_398[8] = "_LOGRGB_RGBFAST";
        Unk_24e45d0.field_398[9] = "_RGB_LOGRGB";
        Unk_24e45d0.field_398[10] = "_LOGRGBLUM_RGB";
        Unk_24e45d0.field_398[11] = "_LOGRGBLUM_RGBFAST";
        Unk_24e45d0.field_398[12] = "_RGB_LOGRGBLUM";
        Unk_24e45d0.field_398[13] = "_RGBALUM_RGB";
        Unk_24e45d0.field_398[14] = "_RGBALUM_RGBFAST";
        Unk_24e45d0.field_398[15] = "_RGB_RGBALUM";
        Unk_24e45d0.field_398[16] = "_REINHARDRGB_REINHARDRGB";
        Unk_24e45d0.field_398[17] = "_REINHARDRGBLUM_REINHARDRGBLUM";
        Unk_24e45d0.field_398[18] = "_LOGRGB_LOGRGB";
        Unk_24e45d0.field_398[19] = "_LOGRGBLUM_LOGRGBLUM";
        Unk_24e45d0.field_398[20] = "_RGBALUM_RGBALUM";
        Unk_24e45d0.field_398[21] = "_ALPHA_RGB";
    }
    Unk_TFXString text(name);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 22; i++) {
        text.Unk_451530(length);
        text += Unk_24e45d0.field_398[i];
        techniques[i] = field_0->vf15(text.field_8);
        if (techniques[i] == 0)
            result = -1;
        if (techniques[i] != 0 && field_0->vf28(techniques[i]) < 0)
            techniques[i] = 0;
        if (techniques[i] != 0) {
            s32 error = field_0->vf27(techniques[i]);
            if (error < 0)
                result = error;
        }
    }
    return result;
}

// 0x7100463220: the techniques `name` with its last character replaced by 1, 2, ...
s32 TEXSHADERSET::Unk_463220(s32* techniques, const char* name, s32 count) {
    Unk_TFXString prefix(name);
    prefix.Unk_451530(prefix.field_0 - 1);
    s32 result = 0;
    char buffer[1024];
    for (s32 i = 0; i < count; i++) {
        sprintf(buffer, "%s%d", prefix.field_8, i + 1);
        techniques[i] = field_0->vf15(buffer);
        if (techniques[i] != 0 && field_0->vf28(techniques[i]) < 0)
            techniques[i] = 0;
        if (techniques[i] != 0) {
            s32 error = field_0->vf27(techniques[i]);
            if (error < 0)
                result = error;
        }
    }
    return result;
}

// 0x7100463340: the techniques `name` with its last three characters replaced by 0_0 to 7_7
s32 TEXSHADERSET::Unk_463340(s32 (*techniques)[8][22], const char* name) {
    Unk_TFXString prefix(name);
    prefix.Unk_451530(prefix.field_0 - 3);
    char buffer[1024];
    for (s32 i = 0; i < 8; i++) {
        for (s32 j = 0; j < 8; j++) {
            sprintf(buffer, "%s%d_%d", prefix.field_8, i, j);
            Unk_462fe0(techniques[i][j], buffer);
        }
    }
    return 0;
}

// 0x7100463500: the technique `name` for each tone map
s32 TEXSHADERSET::Unk_463500(s32* techniques, const char* name) {
    if (!(Unk_24e45d0.field_1 & 1)) {
        Unk_24e45d0.field_1 = 1;
        Unk_24e45d0.field_318[0] = "_LINEAR";
        Unk_24e45d0.field_318[2] = "_REINHARD";
        Unk_24e45d0.field_318[3] = "_REINHARD_PREMAP";
        Unk_24e45d0.field_318[4] = "_REINHARDLUM";
        Unk_24e45d0.field_318[5] = "_REINHARDLUM_PREMAP";
        Unk_24e45d0.field_318[6] = "_LOG";
        Unk_24e45d0.field_318[7] = "_LOG_PREMAP";
        Unk_24e45d0.field_318[8] = "_LOGLUM";
        Unk_24e45d0.field_318[9] = "_LOGLUM_PREMAP";
        Unk_24e45d0.field_318[10] = "";
        Unk_24e45d0.field_318[11] = "_SENSITOMETRIC_PREMAP";
        Unk_24e45d0.field_318[12] = "_REINHARD_LINEARSAT_PREMAP";
        Unk_24e45d0.field_318[13] = "_REINHARD_SENSITOMETRIC_PREMAP";
        Unk_24e45d0.field_318[14] = "_LINEARSAT";
        Unk_24e45d0.field_318[15] = "_ALPHALUM_PREMAP";
        Unk_24e45d0.field_318[1] = "_LINEARSAT";
    }
    Unk_TFXString prefix(name);
    Unk_TFXString text(prefix);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 16; i++) {
        text.Unk_451530(length);
        text += Unk_24e45d0.field_318[i];
        techniques[i] = field_0->vf15(text.field_8);
        if (techniques[i] == 0)
            result = -1;
        if (techniques[i] != 0 && field_0->vf28(techniques[i]) < 0)
            techniques[i] = 0;
        if (techniques[i] != 0) {
            s32 error = field_0->vf27(techniques[i]);
            if (error < 0)
                result = error;
        }
    }
    return result;
}

// 0x7100463750: Unk_462fe0 for each value format
s32 TEXSHADERSET::Unk_463750(s32 (*techniques)[22], const char* name) {
    if (!(Unk_24e45d0.field_2 & 1)) {
        Unk_24e45d0.field_2 = 1;
        Unk_24e45d0.field_160[0] = "_RVALUE";
        Unk_24e45d0.field_160[1] = "_GVALUE";
        Unk_24e45d0.field_160[2] = "_BVALUE";
        Unk_24e45d0.field_160[3] = "_AVALUE";
        Unk_24e45d0.field_160[4] = "_RGBA8";
        Unk_24e45d0.field_160[5] = "_ARGB8";
        Unk_24e45d0.field_160[6] = "_ABGR8";
    }
    Unk_TFXString prefix(name);
    s32 result = 0;
    for (s32 i = 0; i < 7; i++) {
        Unk_TFXString full = prefix + Unk_24e45d0.field_160[i];
        s32 error = Unk_462fe0(techniques[i], full.field_8);
        if (error < 0)
            result = error;
    }
    return result;
}

// 0x7100463980: Unk_463750 with and without _USNORM
s32 TEXSHADERSET::Unk_463980(s32 (*techniques)[7][22], const char* name) {
    if (!(Unk_24e45d0.field_3 & 1)) {
        Unk_24e45d0.field_3 = 1;
        Unk_24e45d0.field_198[0] = "";
        Unk_24e45d0.field_198[1] = "_USNORM";
    }
    Unk_TFXString prefix(name);
    s32 result = 0;
    for (s32 i = 0; i < 2; i++) {
        Unk_TFXString full = prefix + Unk_24e45d0.field_198[i];
        s32 error = Unk_463750(techniques[i], full.field_8);
        if (error < 0)
            result = error;
    }
    return result;
}

// 0x7100463a70: Unk_463500 for each set of the tone map's seven options
s32 TEXSHADERSET::Unk_463a70(s32 (*techniques)[16], const char* name) {
    if (!(Unk_24e45d0.field_4 & 1)) {
        Unk_24e45d0.field_4 = 1;
        Unk_24e45d0.field_1a8[0] = "_PreMatrix";
        Unk_24e45d0.field_1a8[1] = "_Dither";
        Unk_24e45d0.field_1a8[2] = "_Vignette";
        Unk_24e45d0.field_1a8[3] = "_VignetteSim";
        Unk_24e45d0.field_1a8[4] = "_Exposure";
        Unk_24e45d0.field_1a8[5] = "_Matrix";
        Unk_24e45d0.field_1a8[6] = "_Gamma";
    }
    Unk_TFXString prefix(name);
    Unk_TFXString text(prefix);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 128; i++) {
        text.Unk_451530(length);
        for (s32 j = 0; j < 7; j++)
            if (i & (1 << j))
                text += Unk_24e45d0.field_1a8[j];
        s32 error = Unk_463500(techniques[i], text.field_8);
        if (error < 0)
            result = error;
    }
    // a set with the simulated vignette but not the vignette falls back on ...
    for (u32 i = 0; i < 128; i++) {
        if ((i & 0xc) == 8) {
            for (s32 j = 0; j < 16; j++)
                if (techniques[i][j] != 0)
                    techniques[i | 4][j] = techniques[i][j];
        }
    }
    return result;
}

// 0x7100463d90: the parameters `name`, an array's, with each index in its brackets
s32 TEXSHADERSET::Unk_463d90(s32* parameters, s32 count, const char* name) {
    Unk_TFXString text(name);
    s32 bracket = text.Unk_452400("[]", 0, -1);
    Unk_TFXString head;
    Unk_TFXString tail;
    bool split = false;
    if (bracket >= 1) {
        head = text;
        head.Unk_451530(bracket);
        tail = text.field_8 + bracket;
        split = true;
    }
    s32 result = 0;
    for (s32 i = 0; i < count; i++) {
        char number[16];
        sprintf(number, "%d", i);
        Unk_TFXString index(number);
        Unk_TFXString full;
        if (split)
            full = head + index + tail;
        else
            full = text + index;
        parameters[i] = field_0->vf12(0, full.field_8);
        if (parameters[i] == 0)
            result = -1;
    }
    return result;
}

// 0x7100463fd0
s32 TEXSHADERSET::CreateEffect(void* device) {
#line 2849
    PPFX_LOG("==== TEXSHADERSET::CreateEffect() ====\n");
    if (field_0 != nullptr)
        return 0;

    char* errors = nullptr;
    s32 size = *reinterpret_cast<const s32*>(Unk_1b61595);
    if (field_29a20 != nullptr)
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_29a20) - 1);
    u64* block = static_cast<u64*>(Unk_4b99a0(Unk_238d5f8, size + sizeof(u64), __FILE__, 2925, nullptr));
    if (block != nullptr)
        *block++ = size;
    field_29a20 = reinterpret_cast<u8*>(block);
    {
        unsigned long length = size;
        mz_uncompress(field_29a20, &length, Unk_1b61595 + 4, 0x318b62);
    }
    s32 result = Unk_49a300(device, field_29a20, size, nullptr, &field_0, &errors, 1);
    if (result < 0) {
#line 2967
        PPFX_ERROR("TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() failed (0x%x: %s).\n", result, Unk_446df0(result));
        if (errors != nullptr) {
#line 2972
            PPFX_ERROR("%s\n", errors);
        }
        return result;
    }
#line 2976
    PPFX_LOG("TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() succeeded.\n");
#line 2986
    PPFX_LOG("TEXSHADERSET::CreateEffect(): get parameter handles ...\n");

    field_a0 = field_0->vf12(0, "fParam_ScreenSpaceScale");
    field_a4 = field_0->vf12(0, "fParam_PerspectiveFactor");
    field_a8 = field_0->vf12(0, "fParam_DepthOfFieldConvertDepthFactor");
    field_ac = field_0->vf12(0, "fParam_FocusDistance");
    field_b0 = field_0->vf12(0, "fParam_DepthOfFieldFactorScaleOffset");
    field_b4 = field_0->vf12(0, "afXY_DepthOfFieldLevelBlendFactor16");
    field_b8 = field_0->vf12(0, "fParam_DepthOfFieldLayerMaskThreshold");
    field_bc = field_0->vf12(0, "fParam_DepthOfFieldFactorThreshold");
    field_c0 = field_0->vf12(0, "fParam_DepthCastScaleOffset");
    field_c4 = field_0->vf12(0, "afUV_TexCoordOffsetV16");
    field_c8 = field_0->vf12(0, "afUV_TexCoordOffsetP32");
    field_cc = field_0->vf12(0, "afParam_TexCoordScaler8");
    field_d0 = field_0->vf12(0, "afRGBA_Modulate");
    field_d4 = field_0->vf12(0, "afRGBA_Offset");
    field_d8 = field_0->vf12(0, "fRGBA_Constant");
    field_dc = field_0->vf12(0, "afRGBA_Constant");
    field_e0 = field_0->vf12(0, "afUVWQ_TexCoordScaleOffset");
    field_e4 = field_0->vf12(0, "fParam_VignetteSimulate");
    field_e8 = field_0->vf12(0, "fParam_VignettePowerOfCosine");
    field_ec = field_0->vf12(0, "fParam_HDRFormatFactor_LOGRGB");
    field_f0 = field_0->vf12(0, "fParam_HDRFormatFactor_RGBALUM");
    field_f4 = field_0->vf12(0, "fParam_HDRFormatFactor_REINHARDRGB");
    field_f8 = field_0->vf12(0, "fParam_BrightPass_LensDistortion");
    field_fc = field_0->vf12(0, "fParam_GammaCorrection");
    field_100 = field_0->vf12(0, "fParam_DitherOffsetScale");
    field_104 = field_0->vf12(0, "fParam_TonemapMaxMappingLuminance");
    field_108 = field_0->vf12(0, "m44_ColorTransformMatrix");
    field_10c = field_0->vf12(0, "m44_PreTonemapColorTransformMatrix");
    field_110 = field_0->vf12(0, "m44_PreTonemapGlareColorTransformMatrix");
    field_114 = field_0->vf12(0, "am44_TransformMatrix");
    Unk_GetTechs(field_118, "tech_MadT1_Sn", 32);
    Unk_GetTechs(field_c18, "tech_MadScalarWeightT1_Sn", 32);
    Unk_GetTechs(field_1718, "tech_MadAlphaT1_Sn", 32);
    Unk_GetTechs(field_2218, "tech_MadT2_Sn", 32);
    Unk_GetTechs(field_74a8, "tech_MadColorGradingLutT1_Sn", 4);
    Unk_GetTechs(field_2d18, "tech_MadAlphaColorT2_R_Sn", 1);
    Unk_GetTechs(field_3298, "tech_MadAlphaColorT2_G_Sn", 1);
    Unk_GetTechs(field_3818, "tech_MadAlphaColorT2_B_Sn", 1);
    Unk_GetTechs(field_3d98, "tech_MadAlphaColorT2_A_Sn", 1);
    field_4318 = field_0->vf15("tech_Alpha_R");
    field_431c = field_0->vf15("tech_Alpha_G");
    field_4320 = field_0->vf15("tech_Alpha_B");
    field_4324 = field_0->vf15("tech_Alpha_A");
    Unk_GetTechs(field_4328, "tech_TexCoordOffsetMadTn", 16);
    Unk_GetTechs(field_48a8, "tech_MadTn", 16);
    Unk_GetTechs(field_4e28, "tech_MadLumGammaTn", 16);
    Unk_GetTechs(field_53a8, "tech_MadLumGammaWithLensDirtTn", 16);
    Unk_GetTechs(field_5928, "tech_MadOffsetTn", 16);
    Unk_GetTechs(field_69a8, "tech_MaxColorTn", 16);
    Unk_GetTechs(field_6f28, "tech_MaxColorLumGammaTn", 16);
    Unk_GetTechs(field_5ea8, "tech_MadOffsetVignetteTn", 1);
    Unk_GetTechs(field_6428, "tech_MadOffsetVignetteSimulateTn", 1);
    Unk_463220(field_1b3f4, "tech_TransformMadT1_Sn", 8);
    Unk_463220(field_1b414, "tech_TexCoordMadT1_Sn", 4);
    Unk_GetTechs(field_7710, "tech_BrightPassT1_THRESHOLD_Sn", 1);
    Unk_GetTechs(field_7818, "tech_BrightPassT1_THRESHOLD_LUMINANCE_Sn", 1);
    Unk_GetTechs(field_7920, "tech_BrightPassT1_THRESHOLD_LUMINANCE_REMAP_Sn", 1);
    Unk_GetTechs(field_7768, "tech_BrightPassT1_Vignette_THRESHOLD_Sn", 1);
    Unk_GetTechs(field_7870, "tech_BrightPassT1_Vignette_THRESHOLD_LUMINANCE_Sn", 1);
    Unk_GetTechs(field_7978, "tech_BrightPassT1_Vignette_THRESHOLD_LUMINANCE_REMAP_Sn", 1);
    Unk_GetTechs(field_77c0, "tech_BrightPassT1_VignetteSimulate_THRESHOLD_Sn", 1);
    Unk_GetTechs(field_78c8, "tech_BrightPassT1_VignetteSimulate_THRESHOLD_LUMINANCE_Sn", 1);
    Unk_GetTechs(field_79d0, "tech_BrightPassT1_VignetteSimulate_THRESHOLD_LUMINANCE_REMAP_Sn", 1);
    field_7a28 = field_0->vf15("tech_LightShaftMask");
    field_7a2c = field_0->vf15("tech_LightShaftMask_SM3");
    field_7a30 = field_0->vf15("tech_Corona");
    Unk_462fe0(field_7a34, "tech_GlareGhost_PointSymmetryT4_S8_TrimT1_S8");
    Unk_462fe0(field_7a8c, "tech_GlareGhost_PointSymmetryDistScaleT4_S8_TrimT1_S8");
    Unk_462fe0(field_7ae4, "tech_GlareGhost_PointSymmetryT3_S8");
    Unk_462fe0(field_7b3c, "tech_LightGhostLuminance");
    Unk_462fe0(field_7b94, "tech_LightGhostLuminance_Depth");
    Unk_462fe0(field_7bec, "tech_LightGhost_N5");
    Unk_462fe0(field_7c44, "tech_LightGhost_N6");
    Unk_462fe0(field_7c9c, "tech_LightGhost_N7");
    Unk_462fe0(field_7cf4, "tech_LightGhost_N8");
    Unk_GetTechs(field_7eac, "tech_DepthOfField_CompositeBlurredLevels_Tn", 8);
    Unk_GetTechs(field_816c, "tech_DepthOfField_CompositeBlurredLevels_USNORM_Tn", 8);
    Unk_GetTechs(field_842c, "tech_DepthOfField_CompositeBlurredLevelsFrontBlur_Tn", 8);
    Unk_GetTechs(field_86ec, "tech_DepthOfField_CompositeBlurredLevelsFrontBlur_USNORM_Tn", 8);
    Unk_463340(field_89ac, "tech_DepthOfField_CompositeBlurLevelsFrontBlur_TSn_n");
    Unk_463340(field_9fac, "tech_DepthOfField_CompositeBlurLevelsFrontBlur_USNORM_TSn_n");
    Unk_463340(field_b5ac, "tech_DepthOfField_CompositeMaskedBlurLevels_TSn_n");
    Unk_463340(field_cbac, "tech_DepthOfField_CompositeMaskedBlurLevels_USNORM_TSn_n");
    Unk_GetTechs(field_e1ac, "tech_DepthOfField_BackgroundLayerMaskT1_Sn", 25);
    Unk_GetTechs(field_ea44, "tech_DepthOfField_BackgroundLayerMaskT1_USNORM_Sn", 25);
    Unk_GetTechs(field_f2dc, "tech_DepthOfField_ForegroundLayerMaskT1_Sn", 25);
    Unk_GetTechs(field_fb74, "tech_DepthOfField_ForegroundLayerMaskT1_USNORM_Sn", 25);
    Unk_463220(field_1040c, "tech_DepthOfField_BackgroundLayerMaskMakeColorT1_Sn", 17);
    Unk_463220(field_10490, "tech_DepthOfField_BackgroundLayerMaskMakeColorT1_USNORM_Sn", 17);
    Unk_463220(field_1061c, "tech_DepthOfField_ForegroundLayerMaskMakeColorT1_Sn", 17);
    Unk_463220(field_106a0, "tech_DepthOfField_ForegroundLayerMaskMakeColorT1_USNORM_Sn", 17);
    Unk_463220(field_1082c, "tech_DepthOfField_BackgroundLayerMaskMakeColorMaskT1_Sn", 17);
    Unk_463220(field_108b0, "tech_DepthOfField_BackgroundLayerMaskMakeColorMaskT1_USNORM_Sn", 17);
    Unk_463220(field_10a3c, "tech_DepthOfField_ForegroundLayerMaskMakeColorMaskT1_Sn", 17);
    Unk_463220(field_10ac0, "tech_DepthOfField_ForegroundLayerMaskMakeColorMaskT1_USNORM_Sn", 17);
    Unk_463220(field_10514, "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseT1_Sn", 33);
    Unk_463220(field_10598, "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseT1_USNORM_Sn", 33);
    Unk_463220(field_10724, "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseT1_Sn", 33);
    Unk_463220(field_107a8, "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseT1_USNORM_Sn", 33);
    Unk_463220(field_10934, "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseMaskT1_Sn", 33);
    Unk_463220(field_109b8, "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseMaskT1_USNORM_Sn", 33);
    Unk_463220(field_10b44, "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseMaskT1_Sn", 33);
    Unk_463220(field_10bc8, "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseMaskT1_USNORM_Sn", 33);
    field_7da4 = field_0->vf15("tech_ValidatePixel");
    field_7da8 = field_0->vf15("tech_ValidatePixelEx");
    field_7dac = field_0->vf15("tech_MedianFilter_Separablex3x3");
    field_7dc0 = field_0->vf15("tech_GenerateNormalDepth_NormRGB");
    field_7db0 = field_0->vf15("tech_GenerateNormalDepth_NormGen2D");
    field_7db4 = field_0->vf15("tech_GenerateNormalDepth_NormGen2DMan");
    field_7db8 = field_0->vf15("tech_GenerateNormalDepth_NormGen3D");
    field_7dbc = field_0->vf15("tech_GenerateNormalDepth_NormGen3DMan");
    field_7dc4 = field_0->vf15("tech_DownsampleNormalDepth");
    {
        char name[1024];
        for (s32 i = 0; i < 6; i++) {
            s32 size = (i + 3) * (i + 3);
            sprintf(name, "tech_AlchemySsao_T1_S%d", size);
            field_7dc8[i] = field_0->vf15(name);
            sprintf(name, "tech_AlchemySsao_Falloff_T1_S%d", size);
            field_7de0[i] = field_0->vf15(name);
            sprintf(name, "tech_AlchemySsaoIgn_T1_S%d", size);
            field_7df8[i] = field_0->vf15(name);
            sprintf(name, "tech_AlchemySsaoIgn_Falloff_T1_S%d", size);
            field_7e10[i] = field_0->vf15(name);
        }
        for (s32 i = 0; i < 7; i++) {
            sprintf(name, "tech_CrossBilateralForSsao_S%d", 5 + i * 2);
            field_7e28[i] = field_0->vf15(name);
        }
    }
    field_7e48 = field_0->vf15("tech_UpsampleSsao_IM");
    field_7e4c = field_0->vf15("tech_UpsampleSsao");
    field_7e50 = field_0->vf15("tech_UpsampleSsao_MC");
    field_7e54 = field_0->vf15("tech_UpsampleSsao_MC_Mask");
    field_7e58 = field_0->vf15("tech_UpsampleSsao_LN");
    field_7e5c = field_0->vf15("tech_UpsampleSsao_LN_MC");
    field_7e60 = field_0->vf15("tech_UpsampleSsao_LN_MC_Mask");
    field_7e64 = field_0->vf15("tech_TemporalAntialias");
    field_7e68 = field_0->vf15("tech_TemporalAntialias_DynamicPixel");
    field_7e6c = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthR");
    field_7e70 = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthG");
    field_7e74 = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthB");
    field_7e78 = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthA");
    field_7e7c = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthRGBA8");
    field_7e88 = field_0->vf15("tech_TemporalAntialias_Tonemap");
    field_7e8c = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel");
    field_7e90 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthR");
    field_7e94 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthG");
    field_7e98 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthB");
    field_7e9c = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthA");
    field_7ea0 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthRGBA8");
    field_10c4c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_RVALUE");
    field_10c54 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_GVALUE");
    field_10c5c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_BVALUE");
    field_10c64 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_AVALUE");
    field_10c6c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_RGBA8");
    field_15984 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_RVALUE");
    field_1598c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_GVALUE");
    field_15994 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_BVALUE");
    field_1599c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_AVALUE");
    field_159a4 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_RGBA8");
    field_1a6bc = field_0->vf15("tech_DepthOfField_NormalizeBackgroundBlurFactor");
    field_1a6c0 = field_0->vf15("tech_DepthOfField_NormalizeBackgroundBlurFactor_USNORM");
    field_1a6c4 = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactor");
    field_1a6cc = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactorMask");
    field_1a6c8 = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactorDilation");
    field_1a6d0 = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactorDilationMask");
    Unk_GetTechs(field_1a6d4, "tech_MadCocT2_Sn", 25);
    memset(&field_1af6c, 0, sizeof(field_1af6c));
    field_1af6c.field_0[0] = field_0->vf15("tech_ScatterCoc");
    field_1af6c.field_0[4] = field_0->vf15("tech_ScatterCoc_Rad");
    field_1af6c.field_0[2] = field_0->vf15("tech_ScatterCoc_Eclipse");
    field_1af6c.field_0[6] = field_0->vf15("tech_ScatterCoc_RadEclipse");
    field_1af6c.field_0[1] = field_0->vf15("tech_ScatterCoc_SeparateXY");
    field_1af6c.field_0[5] = field_0->vf15("tech_ScatterCoc_RadSeparateXY");
    field_1af6c.field_0[3] = field_0->vf15("tech_ScatterCoc_EclipseSeparateXY");
    field_1af6c.field_0[7] = field_0->vf15("tech_ScatterCoc_RadEclipseSeparateXY");
    field_1af6c.field_0[8] = field_0->vf15("tech_ScatterCocLevel");
    field_1af6c.field_0[12] = field_0->vf15("tech_ScatterCocLevel_Rad");
    field_1af6c.field_0[10] = field_0->vf15("tech_ScatterCocLevel_Eclipse");
    field_1af6c.field_0[14] = field_0->vf15("tech_ScatterCocLevel_RadEclipse");
    field_1af6c.field_0[9] = field_0->vf15("tech_ScatterCocLevel_SeparateXY");
    field_1af6c.field_0[13] = field_0->vf15("tech_ScatterCocLevel_RadSeparateXY");
    field_1af6c.field_0[11] = field_0->vf15("tech_ScatterCocLevel_EclipseSeparateXY");
    field_1af6c.field_0[15] = field_0->vf15("tech_ScatterCocLevel_RadEclipseSeparateXY");
    field_1af6c.field_0[16] = field_0->vf15("tech_ScatterCocLevelClamp");
    field_1af6c.field_0[20] = field_0->vf15("tech_ScatterCocLevelClamp_Rad");
    field_1af6c.field_0[18] = field_0->vf15("tech_ScatterCocLevelClamp_Eclipse");
    field_1af6c.field_0[22] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipse");
    field_1af6c.field_0[17] = field_0->vf15("tech_ScatterCocLevelClamp_SeparateXY");
    field_1af6c.field_0[21] = field_0->vf15("tech_ScatterCocLevelClamp_RadSeparateXY");
    field_1af6c.field_0[19] = field_0->vf15("tech_ScatterCocLevelClamp_EclipseSeparateXY");
    field_1af6c.field_0[23] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipseSeparateXY");
    field_1af6c.field_0[24] = field_0->vf15("tech_ScatterCocLevel_Rad_Lerp");
    field_1af6c.field_0[26] = field_0->vf15("tech_ScatterCocLevel_RadEclipse_Lerp");
    field_1af6c.field_0[25] = field_0->vf15("tech_ScatterCocLevel_RadSeparateXY_Lerp");
    field_1af6c.field_0[27] = field_0->vf15("tech_ScatterCocLevel_RadEclipseSeparateXY_Lerp");
    field_1af6c.field_0[28] = field_0->vf15("tech_ScatterCocLevelClamp_Rad_Lerp");
    field_1af6c.field_0[30] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipse_Lerp");
    field_1af6c.field_0[29] = field_0->vf15("tech_ScatterCocLevelClamp_RadSeparateXY_Lerp");
    field_1af6c.field_0[31] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipseSeparateXY_Lerp");
    field_1af6c.field_80[0] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels");
    field_1af6c.field_80[1] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_Eclipse");
    field_1af6c.field_80[4] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_Blur");
    field_1af6c.field_80[5] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_BlurEclipse");
    field_1af6c.field_80[6] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_BlurRad");
    field_1af6c.field_80[7] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_BlurRadEclipse");
    field_1b330 = field_0->vf15("tech_DilateScatteredColorT1_S37");
    {
        Unk_TFXString str0("tech_BokehBlur_S");
        Unk_TFXString str1("tech_BokehBlur_Rad_S");
        Unk_TFXString str2("tech_BokehBlur_Eclipse_S");
        Unk_TFXString str3("tech_BokehBlur_RadEclipse_S");
        Unk_TFXString str4("tech_BokehBlur_SeparateXY_S");
        Unk_TFXString str5("tech_BokehBlur_RadSeparateXY_S");
        Unk_TFXString str6("tech_BokehBlur_EclipseSeparateXY_S");
        Unk_TFXString str7("tech_BokehBlur_RadEclipseSeparateXY_S");
        Unk_TFXString str8("tech_BokehBlurConditional_S");
        Unk_TFXString str9("tech_BokehBlurConditional_Rad_S");
        Unk_TFXString str10("tech_BokehBlurConditional_Eclipse_S");
        Unk_TFXString str11("tech_BokehBlurConditional_RadEclipse_S");
        Unk_TFXString str12("tech_BokehBlurConditional_SeparateXY_S");
        Unk_TFXString str13("tech_BokehBlurConditional_RadSeparateXY_S");
        Unk_TFXString str14("tech_BokehBlurConditional_EclipseSeparateXY_S");
        Unk_TFXString str15("tech_BokehBlurConditional_RadEclipseSeparateXY_S");
        Unk_TFXString str16("tech_BokehBlurSmallAlpha_S");
        Unk_TFXString str17("tech_BokehBlurSmallAlpha_Rad_S");
        Unk_TFXString str18("tech_BokehBlurSmallAlpha_Eclipse_S");
        Unk_TFXString str19("tech_BokehBlurSmallAlpha_RadEclipse_S");
        Unk_TFXString str20("tech_BokehBlurSmallAlpha_SeparateXY_S");
        Unk_TFXString str21("tech_BokehBlurSmallAlpha_RadSeparateXY_S");
        Unk_TFXString str22("tech_BokehBlurSmallAlpha_EclipseSeparateXY_S");
        Unk_TFXString str23("tech_BokehBlurSmallAlpha_RadEclipseSeparateXY_S");
        Unk_TFXString str24("tech_BokehBlurSmallAlphaConditional_S");
        Unk_TFXString str25("tech_BokehBlurSmallAlphaConditional_Rad_S");
        Unk_TFXString str26("tech_BokehBlurSmallAlphaConditional_Eclipse_S");
        Unk_TFXString str27("tech_BokehBlurSmallAlphaConditional_RadEclipse_S");
        Unk_TFXString str28("tech_BokehBlurSmallAlphaConditional_SeparateXY_S");
        Unk_TFXString str29("tech_BokehBlurSmallAlphaConditional_RadSeparateXY_S");
        Unk_TFXString str30("tech_BokehBlurSmallAlphaConditional_EclipseSeparateXY_S");
        Unk_TFXString str31("tech_BokehBlurSmallAlphaConditional_RadEclipseSeparateXY_S");
        Unk_TFXString str32("tech_BokehBlurCenterAlpha_S");
        Unk_TFXString str33("tech_BokehBlurCenterAlpha_Rad_S");
        Unk_TFXString str34("tech_BokehBlurCenterAlpha_Eclipse_S");
        Unk_TFXString str35("tech_BokehBlurCenterAlpha_RadEclipse_S");
        Unk_TFXString str36("tech_BokehBlurCenterAlpha_SeparateXY_S");
        Unk_TFXString str37("tech_BokehBlurCenterAlpha_RadSeparateXY_S");
        Unk_TFXString str38("tech_BokehBlurCenterAlpha_EclipseSeparateXY_S");
        Unk_TFXString str39("tech_BokehBlurCenterAlpha_RadEclipseSeparateXY_S");
        Unk_TFXString full;
        for (s32 i = 0; i < 5; i++) {
            s32 size = Unk_1b35158[i];
            Unk_TFXString num = Unk_4525a0(size);
            full = str0 + num;
            field_1af6c.field_a0[0][i] = field_0->vf15(full.field_8);
            full = str1 + num;
            field_1af6c.field_a0[4][i] = field_0->vf15(full.field_8);
            full = str2 + num;
            field_1af6c.field_a0[2][i] = field_0->vf15(full.field_8);
            full = str3 + num;
            field_1af6c.field_a0[6][i] = field_0->vf15(full.field_8);
            full = str8 + num;
            field_1af6c.field_a0[8][i] = field_0->vf15(full.field_8);
            full = str9 + num;
            field_1af6c.field_a0[12][i] = field_0->vf15(full.field_8);
            full = str10 + num;
            field_1af6c.field_a0[10][i] = field_0->vf15(full.field_8);
            full = str11 + num;
            field_1af6c.field_a0[14][i] = field_0->vf15(full.field_8);
            full = str16 + num;
            field_1af6c.field_a0[16][i] = field_0->vf15(full.field_8);
            full = str17 + num;
            field_1af6c.field_a0[20][i] = field_0->vf15(full.field_8);
            full = str18 + num;
            field_1af6c.field_a0[18][i] = field_0->vf15(full.field_8);
            full = str19 + num;
            field_1af6c.field_a0[22][i] = field_0->vf15(full.field_8);
            full = str24 + num;
            field_1af6c.field_a0[24][i] = field_0->vf15(full.field_8);
            full = str25 + num;
            field_1af6c.field_a0[28][i] = field_0->vf15(full.field_8);
            full = str26 + num;
            field_1af6c.field_a0[26][i] = field_0->vf15(full.field_8);
            full = str27 + num;
            field_1af6c.field_a0[30][i] = field_0->vf15(full.field_8);
            {
                Unk_TFXString num2 = Unk_4525a0(size);
                full = str4 + num2;
                field_1af6c.field_a0[1][i] = field_0->vf15(full.field_8);
                full = str5 + num2;
                field_1af6c.field_a0[5][i] = field_0->vf15(full.field_8);
                full = str6 + num2;
                field_1af6c.field_a0[3][i] = field_0->vf15(full.field_8);
                full = str7 + num2;
                field_1af6c.field_a0[7][i] = field_0->vf15(full.field_8);
                full = str12 + num2;
                field_1af6c.field_a0[9][i] = field_0->vf15(full.field_8);
                full = str13 + num2;
                field_1af6c.field_a0[13][i] = field_0->vf15(full.field_8);
                full = str14 + num2;
                field_1af6c.field_a0[11][i] = field_0->vf15(full.field_8);
                full = str15 + num2;
                field_1af6c.field_a0[15][i] = field_0->vf15(full.field_8);
                full = str20 + num2;
                field_1af6c.field_a0[17][i] = field_0->vf15(full.field_8);
                full = str21 + num2;
                field_1af6c.field_a0[21][i] = field_0->vf15(full.field_8);
                full = str22 + num2;
                field_1af6c.field_a0[19][i] = field_0->vf15(full.field_8);
                full = str23 + num2;
                field_1af6c.field_a0[23][i] = field_0->vf15(full.field_8);
                full = str28 + num2;
                field_1af6c.field_a0[25][i] = field_0->vf15(full.field_8);
                full = str29 + num2;
                field_1af6c.field_a0[29][i] = field_0->vf15(full.field_8);
                full = str30 + num2;
                field_1af6c.field_a0[27][i] = field_0->vf15(full.field_8);
                full = str31 + num2;
                field_1af6c.field_a0[31][i] = field_0->vf15(full.field_8);
            }
            if (i < 3) {
                full = str32 + num;
                field_1af6c.field_a0[32][i] = field_0->vf15(full.field_8);
                full = str33 + num;
                field_1af6c.field_a0[36][i] = field_0->vf15(full.field_8);
                full = str34 + num;
                field_1af6c.field_a0[34][i] = field_0->vf15(full.field_8);
                full = str35 + num;
                field_1af6c.field_a0[38][i] = field_0->vf15(full.field_8);
                full = str36 + num;
                field_1af6c.field_a0[33][i] = field_0->vf15(full.field_8);
                full = str37 + num;
                field_1af6c.field_a0[37][i] = field_0->vf15(full.field_8);
                full = str38 + num;
                field_1af6c.field_a0[35][i] = field_0->vf15(full.field_8);
                full = str39 + num;
                field_1af6c.field_a0[39][i] = field_0->vf15(full.field_8);
            }
        }
    }
    field_1b32c = field_0->vf15("tech_GradientMaskT1_S4");
    Unk_GetTechs(field_10c84, "tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastT1_Sn", 1);
    Unk_GetTechs(field_159bc, "tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLutT1_Sn", 1);
    field_1b334 = field_0->vf15("tech_DepthEncode_RVALUE");
    field_1b344 = field_0->vf15("tech_DepthEncode_RGBA8");
    field_1b350 = field_0->vf15("tech_DepthFromDofFactor_R");
    field_1b354 = field_0->vf15("tech_DepthFromDofFactor_G");
    field_1b358 = field_0->vf15("tech_DepthFromDofFactor_B");
    field_1b35c = field_0->vf15("tech_DepthFromDofFactor_A");
    field_1b360 = field_0->vf15("tech_DepthFromDofFactor_USNORM_R");
    field_1b364 = field_0->vf15("tech_DepthFromDofFactor_USNORM_G");
    field_1b368 = field_0->vf15("tech_DepthFromDofFactor_USNORM_B");
    field_1b36c = field_0->vf15("tech_DepthFromDofFactor_USNORM_A");
    field_10c80 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_USNORM_ABGR8");
    field_1b370 = field_0->vf15("tech_LensDistortion");
    field_1b374 = field_0->vf15("tech_LensDistortionConv");
    field_1b378 = field_0->vf15("tech_LensDistortionFalloff");
    field_1b37c = field_0->vf15("tech_LensDistortion_Noise");
    field_1b380 = field_0->vf15("tech_LensDistortionConv_Noise");
    field_1b384 = field_0->vf15("tech_LensDistortion_Noise_Additive");
    field_1b388 = field_0->vf15("tech_LensDistortionConv_Noise_Additive");
    field_1b38c = field_0->vf15("tech_ImageSensorNoise");
    field_1b390 = field_0->vf15("tech_ImageSensorNoise_Additive");
    Unk_463220(field_1b394, "tech_LateralChromaticAberration_Sn", 8);
    Unk_463220(field_1b3b4, "tech_ChromaticAberrationWithMask_Sn", 8);
    Unk_463220(field_1b3d4, "tech_ChromaticAberrationWithMask_Noise_Sn", 8);
    field_1b424 = field_0->vf15("tech_Feedback");
    field_1b428 = field_0->vf15("tech_Feedback_Matrix");
    field_1b42c = field_0->vf15("tech_Feedback_Blend");
    field_1b430 = field_0->vf15("tech_Feedback_Blend_Matrix");
    Unk_GetTechs(field_1b434, "tech_MotionBlurCameraRotatePerspectiveT1_Sn", 8);
    Unk_GetTechs(field_1b9b4, "tech_MotionBlurCameraRotatePerspective_SM3_T1_Sn", 8);
    Unk_GetTechs(field_1b6f4, "tech_MotionBlurCameraRotatePerspectiveFalloffT1_Sn", 8);
    Unk_GetTechs(field_1bc74, "tech_MotionBlurCameraRotatePerspectiveFalloff_SM3_T1_Sn", 8);
    Unk_GetTechs(field_1bf34, "tech_MotionBlurCameraRotatePerspectiveFalloffBiLinearT1_Sn", 8);
    Unk_GetTechs(field_1c1f4, "tech_MotionBlurCameraRotatePerspectiveFalloffBiLinear_SM3_T1_Sn", 8);
    field_1c4b4 = field_0->vf15("tech_MotionBlurMakeCameraVelocity_R");
    field_1c4b8 = field_0->vf15("tech_MotionBlurMakeCameraVelocity_G");
    field_1c4bc = field_0->vf15("tech_MotionBlurMakeCameraVelocity_B");
    field_1c4c0 = field_0->vf15("tech_MotionBlurMakeCameraVelocity_A");
    field_1c4c4 = field_0->vf15("tech_MotionBlurMakeCameraVelocity_RGBA8");
    field_1c4d0 = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_R");
    field_1c4d4 = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_G");
    field_1c4d8 = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_B");
    field_1c4dc = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_A");
    field_1c4e0 = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_RGBA8");
    field_1c4ec = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_R");
    field_1c4f0 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_G");
    field_1c4f4 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_B");
    field_1c4f8 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_A");
    field_1c4fc = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_RGBA8");
    field_1c508 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_R");
    field_1c50c = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_G");
    field_1c510 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_B");
    field_1c514 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_A");
    field_1c518 = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_RGBA8");
    Unk_GetTechs(field_1c524, "tech_MotionBlurVelocityT2_Sn", 8);
    Unk_GetTechs(field_1d5a4, "tech_MotionBlurVelocity_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1c7e4, "tech_MotionBlurVelocityInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1d864, "tech_MotionBlurVelocityInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1e624, "tech_MotionBlurVelocityClampT2_Sn", 8);
    Unk_GetTechs(field_1f6a4, "tech_MotionBlurVelocityClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1e8e4, "tech_MotionBlurVelocityInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_1f964, "tech_MotionBlurVelocityInnerscreenClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1caa4, "tech_MotionBlurVelocityDirT2_Sn", 8);
    Unk_GetTechs(field_1db24, "tech_MotionBlurVelocityDir_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1cd64, "tech_MotionBlurVelocityDirInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1dde4, "tech_MotionBlurVelocityDirInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1eba4, "tech_MotionBlurVelocityDirClampT2_Sn", 8);
    Unk_GetTechs(field_1fc24, "tech_MotionBlurVelocityDirClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1ee64, "tech_MotionBlurVelocityDirInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_1fee4, "tech_MotionBlurVelocityDirInnerscreenClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1d024, "tech_MotionBlurVelocityDirDepthT2_Sn", 8);
    Unk_GetTechs(field_1e0a4, "tech_MotionBlurVelocityDirDepth_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1d2e4, "tech_MotionBlurVelocityDirDepthInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1e364, "tech_MotionBlurVelocityDirDepthInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1f124, "tech_MotionBlurVelocityDirDepthClampT2_Sn", 8);
    Unk_GetTechs(field_201a4, "tech_MotionBlurVelocityDirDepthClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1f3e4, "tech_MotionBlurVelocityDirDepthInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_20464, "tech_MotionBlurVelocityDirDepthInnerscreenClamp_SM3_T2_Sn", 8);
    field_20724 = field_0->vf15("tech_MotionBlurVelocityUpsample");
    field_20728 = field_0->vf15("tech_MotionBlurVelocityDecode");
    field_2072c = field_0->vf15("tech_TonemapToAnalyzeSceneLuminance");
    Unk_463a70(field_20730, "tech_TonemapHDR");
    field_8 = field_0->vf12(0, "asamp2D_Texture[0]");
    field_c = field_0->vf12(0, "asamp2D_Texture[1]");
    Unk_463d90(field_10, 16, "asamp2D_Texture[]");
    Unk_463d90(field_50, 16, "asamp3D_Texture[]");
    Unk_463d90(field_90, 4, "asamp2D_VertexTexture[]");
    field_22730 = field_0->vf15("tech_UpdateWaterHeight");
    field_22734 = field_0->vf15("tech_GenerateNormalMap");
    field_22738 = field_0->vf15("tech_ConstantColor");
    Unk_463220(field_2273c, "tech_ConstantColorO4", 4);
    field_2273c[0] = field_22738;
    field_2274c = field_0->vf15("tech_AnalyzeIntensity");
    field_22750 = field_0->vf15("tech_AnalyzeIntensityTest");
    field_22754 = field_0->vf15("tech_Fxaa2");
    field_22758 = field_0->vf15("tech_Fxaa2_Falloff");
    field_2275c = field_0->vf15("tech_Fxaa2_Tonemap");
    field_22760 = field_0->vf15("tech_Fxaa2_Tonemap_Falloff");
    field_22764 = field_0->vf15("tech_Smaa_EdgeDetection");
    field_2276c = field_0->vf15("tech_Smaa_BlendingWeightCalculation");
    field_22774 = field_0->vf15("tech_Smaa_BlendingWeightCalculation_Diag");
    field_22770 = field_0->vf15("tech_Smaa_BlendingWeightCalculation_Corner");
    field_22778 = field_0->vf15("tech_Smaa_BlendingWeightCalculation_Diag_Corner");
    field_2277c = field_0->vf15("tech_Smaa_NeighborhoodBlending");
    field_22780 = field_0->vf15("tech_Smaa_NeighborhoodBlending_Falloff");
    field_22788 = field_0->vf15("tech_ColorModulateByChannel_R");
    field_2278c = field_0->vf15("tech_ColorModulateByChannel_G");
    field_22790 = field_0->vf15("tech_ColorModulateByChannel_B");
    field_22794 = field_0->vf15("tech_ColorModulateByChannel_A");
    field_22798 = field_0->vf15("tech_ColorModulateByChannel_RGB");
    field_227b0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R");
    field_227c4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G");
    field_227d8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B");
    field_227ec = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A");
    field_227b4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_R");
    field_227b8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_G");
    field_227bc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_B");
    field_227c0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_A");
    field_227c8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_R");
    field_227cc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_G");
    field_227d0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_B");
    field_227d4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_A");
    field_227dc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_R");
    field_227e0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_G");
    field_227e4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_B");
    field_227e8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_A");
    field_227f0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_R");
    field_227f4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_G");
    field_227f8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_B");
    field_227fc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_A");
    field_22800 = field_0->vf15("tech_RenderSceneRect");
    field_22804 = field_0->vf15("tech_RenderSceneRect_OutReinhard");
    field_22808 = field_0->vf15("tech_RenderSceneRect_InLinearDepth");
    field_2280c = field_0->vf15("tech_RenderSceneRect_InLinearDepth_OutReinhard");
    Unk_463220(field_22810, "tech_HeatShimmerParticle_Sn", 4);
    Unk_463220(field_22820, "tech_HeatShimmerParticle_SM3_Sn", 4);
    Unk_463220(field_22830, "tech_HeatShimmerParticle_BlendAlpha_Sn", 4);
    Unk_463220(field_22840, "tech_HeatShimmerParticle_SM3_BlendAlpha_Sn", 4);
    Unk_463220(field_22850, "tech_MinMaxAverageOfMaxChannelT1_Sn", 16);
    Unk_463220(field_22890, "tech_MinMaxAverageT1_Sn", 16);
    Unk_463220(field_228d0, "tech_MinMaxAverageEncodeT1_Sn", 16);
    Unk_463500(field_22910, "tech_OptoElectronicTransferT2_S1_PQ");
    Unk_463500(field_22d50, "tech_OptoElectronicTransferT2_S1_PQSCRGB");
    Unk_463500(field_22950, "tech_OptoElectronicTransferT2_S1_HLG");
    Unk_463500(field_22990, "tech_OptoElectronicTransferT2_S1_SLOG");
    Unk_463500(field_22a50, "tech_OptoElectronicTransferT2_S1_CLAMP");
    Unk_463500(field_22c50, "tech_OptoElectronicTransferT2_S1_GAMMA");
    Unk_463500(field_22d10, "tech_OptoElectronicTransferT2_S1_GAMMASCRGB");
    Unk_463500(field_22cd0, "tech_OptoElectronicTransferT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23210, "tech_OptoElectronicTransferGamutT2_S1_PQ");
    Unk_463500(field_23650, "tech_OptoElectronicTransferGamutT2_S1_PQSCRGB");
    Unk_463500(field_23250, "tech_OptoElectronicTransferGamutT2_S1_HLG");
    Unk_463500(field_23290, "tech_OptoElectronicTransferGamutT2_S1_SLOG");
    Unk_463500(field_23350, "tech_OptoElectronicTransferGamutT2_S1_CLAMP");
    Unk_463500(field_23550, "tech_OptoElectronicTransferGamutT2_S1_GAMMA");
    Unk_463500(field_23610, "tech_OptoElectronicTransferGamutT2_S1_GAMMASCRGB");
    Unk_463500(field_235d0, "tech_OptoElectronicTransferGamutT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23b10, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQ");
    Unk_463500(field_23f50, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQSCRGB");
    Unk_463500(field_23b50, "tech_OptoElectronicTransferGamutPostColorT2_S1_HLG");
    Unk_463500(field_23b90, "tech_OptoElectronicTransferGamutPostColorT2_S1_SLOG");
    Unk_463500(field_23c50, "tech_OptoElectronicTransferGamutPostColorT2_S1_CLAMP");
    Unk_463500(field_23e50, "tech_OptoElectronicTransferGamutPostColorT2_S1_GAMMA");
    Unk_463500(field_23f10, "tech_OptoElectronicTransferGamutPostColorT2_S1_GAMMASCRGB");
    Unk_463500(field_23ed0, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_22d90, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQ");
    Unk_463500(field_231d0, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQSCRGB");
    Unk_463500(field_22dd0, "tech_OptoElectronicTransferAdjustGammaT2_S1_HLG");
    Unk_463500(field_22e10, "tech_OptoElectronicTransferAdjustGammaT2_S1_SLOG");
    Unk_463500(field_22ed0, "tech_OptoElectronicTransferAdjustGammaT2_S1_CLAMP");
    Unk_463500(field_23150, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23690, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQ");
    Unk_463500(field_23ad0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQSCRGB");
    Unk_463500(field_236d0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_HLG");
    Unk_463500(field_23710, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_SLOG");
    Unk_463500(field_237d0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_CLAMP");
    Unk_463500(field_23a50, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23f90, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQ");
    Unk_463500(field_243d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQSCRGB");
    Unk_463500(field_23fd0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_HLG");
    Unk_463500(field_24010, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_SLOG");
    Unk_463500(field_240d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_CLAMP");
    Unk_463500(field_24350, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_25f10, "tech_OptoElectronicTransferT2_S4_PQ");
    Unk_463500(field_26350, "tech_OptoElectronicTransferT2_S4_PQSCRGB");
    Unk_463500(field_25f50, "tech_OptoElectronicTransferT2_S4_HLG");
    Unk_463500(field_25f90, "tech_OptoElectronicTransferT2_S4_SLOG");
    Unk_463500(field_26050, "tech_OptoElectronicTransferT2_S4_CLAMP");
    Unk_463500(field_26250, "tech_OptoElectronicTransferT2_S4_GAMMA");
    Unk_463500(field_26310, "tech_OptoElectronicTransferT2_S4_GAMMASCRGB");
    Unk_463500(field_262d0, "tech_OptoElectronicTransferT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_26810, "tech_OptoElectronicTransferGamutT2_S4_PQ");
    Unk_463500(field_26c50, "tech_OptoElectronicTransferGamutT2_S4_PQSCRGB");
    Unk_463500(field_26850, "tech_OptoElectronicTransferGamutT2_S4_HLG");
    Unk_463500(field_26890, "tech_OptoElectronicTransferGamutT2_S4_SLOG");
    Unk_463500(field_26950, "tech_OptoElectronicTransferGamutT2_S4_CLAMP");
    Unk_463500(field_26b50, "tech_OptoElectronicTransferGamutT2_S4_GAMMA");
    Unk_463500(field_26c10, "tech_OptoElectronicTransferGamutT2_S4_GAMMASCRGB");
    Unk_463500(field_26bd0, "tech_OptoElectronicTransferGamutT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_27110, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQ");
    Unk_463500(field_27550, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQSCRGB");
    Unk_463500(field_27150, "tech_OptoElectronicTransferGamutPostColorT2_S4_HLG");
    Unk_463500(field_27190, "tech_OptoElectronicTransferGamutPostColorT2_S4_SLOG");
    Unk_463500(field_27250, "tech_OptoElectronicTransferGamutPostColorT2_S4_CLAMP");
    Unk_463500(field_27450, "tech_OptoElectronicTransferGamutPostColorT2_S4_GAMMA");
    Unk_463500(field_27510, "tech_OptoElectronicTransferGamutPostColorT2_S4_GAMMASCRGB");
    Unk_463500(field_274d0, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_26390, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQ");
    Unk_463500(field_267d0, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQSCRGB");
    Unk_463500(field_263d0, "tech_OptoElectronicTransferAdjustGammaT2_S4_HLG");
    Unk_463500(field_26410, "tech_OptoElectronicTransferAdjustGammaT2_S4_SLOG");
    Unk_463500(field_264d0, "tech_OptoElectronicTransferAdjustGammaT2_S4_CLAMP");
    Unk_463500(field_26750, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_26c90, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQ");
    Unk_463500(field_270d0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQSCRGB");
    Unk_463500(field_26cd0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_HLG");
    Unk_463500(field_26d10, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_SLOG");
    Unk_463500(field_26dd0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_CLAMP");
    Unk_463500(field_27050, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_27590, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQ");
    Unk_463500(field_279d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQSCRGB");
    Unk_463500(field_275d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_HLG");
    Unk_463500(field_27610, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_SLOG");
    Unk_463500(field_276d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_CLAMP");
    Unk_463500(field_27950, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_247d0, "tech_OptoElectronicTransferT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_27dd0, "tech_OptoElectronicTransferT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_250d0, "tech_OptoElectronicTransferGamutT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_286d0, "tech_OptoElectronicTransferGamutT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_259d0, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_28fd0, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_24c50, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_28250, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_25550, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_28b50, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_25e50, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_29450, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_29510, "tech_OptoElectronicTransferTonemapGraph_PQ");
    Unk_463500(field_29950, "tech_OptoElectronicTransferTonemapGraph_PQSCRGB");
    Unk_463500(field_29550, "tech_OptoElectronicTransferTonemapGraph_HLG");
    Unk_463500(field_29590, "tech_OptoElectronicTransferTonemapGraph_SLOG");
    Unk_463500(field_29650, "tech_OptoElectronicTransferTonemapGraph_CLAMP");
    Unk_463500(field_29850, "tech_OptoElectronicTransferTonemapGraph_GAMMA");
    Unk_463500(field_29910, "tech_OptoElectronicTransferTonemapGraph_GAMMA");
    return 0;
}


// 0x710046cfe0
s32 TEXSHADERSET::Unk_46cfe0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[2] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
    };
    if (field_299b8[1] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 2, arg3, arg4, &field_299b8[1]);
}

// 0x710046d0c0
s32 TEXSHADERSET::Unk_46d0c0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[3] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
    };
    if (field_299b8[2] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 3, arg3, arg4, &field_299b8[2]);
}

// 0x710046d1b0
s32 TEXSHADERSET::Unk_46d1b0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[4] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
    };
    if (field_299b8[3] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 4, arg3, arg4, &field_299b8[3]);
}

// 0x710046d2a0
s32 TEXSHADERSET::Unk_46d2a0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    if (field_299b8[4] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    Unk_InputElement elements[5] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
        Unk_InputElement(2, 3, 0x10),
    };
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 5, arg3, arg4, &field_299b8[4]);
}

// 0x710046d3a0
s32 TEXSHADERSET::Unk_46d3a0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    if (field_299b8[5] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    Unk_InputElement elements[6] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
        Unk_InputElement(2, 3, 0x10),
        Unk_InputElement(2, 4, 0x10),
    };
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 6, arg3, arg4, &field_299b8[5]);
}

// 0x710046d4b0
s32 TEXSHADERSET::Unk_46d4b0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    if (field_299b8[6] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    Unk_InputElement elements[7] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
        Unk_InputElement(2, 3, 0x10),
        Unk_InputElement(2, 4, 0x10),
        Unk_InputElement(2, 5, 0x10),
    };
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 7, arg3, arg4, &field_299b8[6]);
}

// 0x710046d5e0
s32 TEXSHADERSET::Unk_46d5e0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[6] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x2),
        Unk_InputElement(2, 1, 0x2),
        Unk_InputElement(2, 2, 0x2),
        Unk_InputElement(2, 3, 0x2),
        Unk_InputElement(2, 4, 0x2),
    };
    if (field_299b8[11] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 6, arg3, arg4, &field_299b8[11]);
}

// 0x710046d6f0
s32 TEXSHADERSET::Unk_46d6f0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[3] = {
        Unk_InputElement(0, 0, 0x6),
        Unk_InputElement(2, 0, 0x2),
        Unk_InputElement(2, 1, 0x2),
    };
    if (field_299b8[12] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 3, arg3, arg4, &field_299b8[12]);
}

// 0x710046d7e0
s32 TEXSHADERSET::InitializeDevice(IGPUDevice* device, bool keepEffect) {
#line 4908
    PPFX_LOG("==== TEXSHADERSET::InitializeDevice() ====\n");
    if (!keepEffect) {
        s32 result = CreateEffect(device);
        if (result < 0) {
#line 4924
            PPFX_ERROR("TEXSHADERSET::InitializeDevice(): CreateEffect() failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
    }
    if (field_0 != nullptr) {
        s32 result = field_0->vf10();
        if (result < 0) {
#line 4940
            PPFX_ERROR("TEXSHADERSET::InitializeDevice(): m_pEffect->OnResetDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
        f32 value[4] = {};
        bool flag = device->field_58;
        value[0] = 1.0f;
        value[1] = flag ? 1.0f : -1.0f;
        field_0->vf20(field_a0, value);
    }
#line 5367
    PPFX_LOG("==== TEXSHADERSET::InitializeDevice() succeeded. ====\n");
    return 0;
}

// 0x710046db60
CTextureUtil::CTextureUtil(const char* name) : CGPUResourceManage(nullptr) {
    Unk_46dc60(name);
}

// A member object named after its owner: the name is made first, and the
// object from its text (one line each in the original, by their __LINE__s).
#define UNK_NEW_NAMED(member, T, suffix)                   do {                                                       Unk_TFXString name_ = field_10 + suffix;               const char* text_ = name_.field_8;                     member = UNK_NEW(T)(text_);                        } while (0)

// 0x710046dc60: names the object, makes its texture pool and its measurement
// texture, and fills the sample points
s32 CTextureUtil::Unk_46dc60(const char* name) {
    if (name != nullptr && name[0] != '\0') {
        field_10 = Unk_TFXString(Unk_1b3516c) + " " + name;
    } else {
        field_10 = Unk_1b3516c;
    }
#line 5530
    UNK_NEW_NAMED(field_29a58, CRenderTexturePool, "::m_pTexturePool");
    Unk_24e2d50[0] = Unk_SamplePoint(0.12545430660247803f, -0.6233202219009399f);
    Unk_24e2d50[1] = Unk_SamplePoint(-0.012919187545776367f, 0.2008380889892578f);
    Unk_24e2d50[2] = Unk_SamplePoint(-0.013421475887298584f, -0.9243490695953369f);
    Unk_24e2d50[3] = Unk_SamplePoint(0.391507625579834f, -0.02421402931213379f);
    Unk_24e2d50[4] = Unk_SamplePoint(-0.47500234842300415f, 0.5201195478439331f);
    Unk_24e2d50[5] = Unk_SamplePoint(0.185394287109375f, -0.7468999624252319f);
    Unk_24e2d50[6] = Unk_SamplePoint(-0.9652976989746094f, -0.2772960662841797f);
    Unk_24e2d50[7] = Unk_SamplePoint(0.7774732112884521f, -0.8726856708526611f);
    Unk_Clear();
#line 5694
    UNK_NEW_NAMED(field_29a98, CRenderTexture, "::m_pTextureMeasurement");
    s32 result = field_29a98->Unk_Create(0, 0x10, 0x10, 0x1c);
    return result < 0 ? result : 0;
}

// 0x710046e360: the colour chart's bars (the members' names are in the strings)
s32 CTextureUtil::Unk_46e360(s32 width, s32 height, s32 format) {
    s32 result;
    if (field_29b00 != nullptr) {
        if (field_29b00->field_a8 != nullptr && field_29b00->field_b8 != nullptr) {
            return 1;
        }
        if (field_20 == nullptr) {
            return 0;
        }
        field_29b00->vf0(field_20);
        field_29b08[1]->vf0(field_20);
        field_29b08[0]->vf0(field_20);
        field_29b08[2]->vf0(field_20);
        return field_29b08[3]->vf0(field_20);
    }
#line 5893
    UNK_NEW_NAMED(field_29b00, CRenderTexture, "::m_pRenderTextureColorChart_ColorBar");
    UNK_NEW_NAMED(field_29b08[0], CRenderTexture, "::m_pRenderTextureColorChart_ColorBarGraded");
    UNK_NEW_NAMED(field_29b08[1], CRenderTexture, "::m_pRenderTextureColorChart_ColorBar_Small");
    UNK_NEW_NAMED(field_29b08[2], CRenderTexture, "::m_pRenderTextureColorChart_ColorBarGraded_Small");
    UNK_NEW_NAMED(field_29b08[3], CRenderTexture, "::m_pRenderTextureColorChart_ColorBarLuminance");
    field_29b00->Unk_Create(0, width, height, format);
    field_29b08[0]->Unk_Create(0, width, height, format);
    field_29b08[1]->Unk_Create(0, width, height, format);
    field_29b08[2]->Unk_Create(0, width, height, format);
    result = field_29b08[3]->Unk_Create(0, width, 4, format);
    if (field_20 != nullptr) {
        field_29b00->vf0(field_20);
        field_29b08[0]->vf0(field_20);
        field_29b08[1]->vf0(field_20);
        field_29b08[2]->vf0(field_20);
        result = field_29b08[3]->vf0(field_20);
    }
    return result;
}

// 0x710046e740: the colour chart's chromaticity diagrams
s32 CTextureUtil::Unk_46e740(s32 width, s32 height, s32 format) {
    s32 result;
    if (field_29b08[4] != nullptr) {
        if (field_29b08[4]->field_a8 != nullptr && field_29b08[4]->field_b8 != nullptr) {
            return 1;
        }
        if (field_20 == nullptr) {
            return 0;
        }
        field_29b08[4]->vf0(field_20);
        field_29b08[5]->vf0(field_20);
        field_29b08[6]->vf0(field_20);
        return field_29b08[7]->vf0(field_20);
    }
#line 5973
    UNK_NEW_NAMED(field_29b08[4], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagram");
    UNK_NEW_NAMED(field_29b08[5], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagramLegacy");
    UNK_NEW_NAMED(field_29b08[6], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagramUV");
    UNK_NEW_NAMED(field_29b08[7], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagramLegacyUV");
    field_29b08[4]->Unk_Create(0, width, height, format);
    field_29b08[5]->Unk_Create(0, width, height, format);
    field_29b08[6]->Unk_Create(0, width, height, format);
    result = field_29b08[7]->Unk_Create(0, width, height, format);
    if (field_20 != nullptr) {
        field_29b08[4]->vf0(field_20);
        field_29b08[5]->vf0(field_20);
        field_29b08[6]->vf0(field_20);
        result = field_29b08[7]->vf0(field_20);
    }
    return result;
}

// 0x710046ea80: the colour chart's waveform monitor and its source
s32 CTextureUtil::Unk_46ea80(s32 width, s32 height) {
    s32 result;
    if (field_29b08[8] != nullptr) {
        if (field_29b08[8]->field_a8 != nullptr && field_29b08[8]->field_b8 != nullptr) {
            return 1;
        }
        if (field_20 == nullptr) {
            return 0;
        }
        field_29b08[8]->vf0(field_20);
        return field_29b08[9]->vf0(field_20);
    }
#line 6026
    UNK_NEW_NAMED(field_29b08[8], CRenderTexture, "::m_pRenderTextureColorChart_WaveformMonitor");
    field_29b08[8]->Unk_Create(0, width, height, 0x1c);
#line 6039
    UNK_NEW_NAMED(field_29b08[9], CRenderTexture, "::m_pRenderTextureColorChart_WaveformSource");
    result = field_29b08[9]->Unk_Create(0, width, height, 0xa);
    if (field_20 != nullptr) {
        field_29b08[8]->vf0(field_20);
        result = field_29b08[9]->vf0(field_20);
    }
    return result;
}

// the power of two that isn't less than `value`
static inline f64 Unk_PowerOfTwo(s32 value) {
    f64 exponent = log(static_cast<f64>(value)) / log(2.0);
    s32 whole = static_cast<s32>(exponent);
    if (exponent != static_cast<f64>(whole)) {
        whole = static_cast<s32>(exponent + 1.0);
    }
    return ldexp(1.0, whole);
}

// 0x710046ec80: the colour chart's textures for a target of that size
s32 CTextureUtil::Unk_46ec80(u32 width, u32 height) {
    s32 barWidth = static_cast<s32>(Unk_PowerOfTwo(width >> 1));
    u32 barHeight = static_cast<u32>(barWidth) >> 3;
    barHeight = barHeight > 0x80 ? barHeight : 0x80;
    f64 diagram = Unk_PowerOfTwo(height >> 1);
    f64 waveform = Unk_PowerOfTwo(width >> 1);
    s32 result = Unk_46e360(barWidth, barHeight, 0xa);
    if (result < 0) {
        return result;
    }
    result = Unk_46e740(static_cast<s32>(diagram), static_cast<s32>(diagram), 0xa);
    if (result < 0) {
        return result;
    }
    return Unk_46ea80(static_cast<s32>(waveform), static_cast<s32>(waveform));
}

// 0x710046d990: releases the effect's objects, and with no argument the
// effect and its file too
s32 TEXSHADERSET::Unk_46d990(void* arg) {
    if (field_0 != nullptr) {
        s32 result = field_0->vf11();
        if (result < 0) {
            return result;
        }
    }
    if (arg == nullptr) {
        PPFX_SAFE_RELEASE_INTERFACE(field_0);
        // an array of bytes: nothing to destroy (the count is still before it)
        if (field_29a20 != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_29a20) - 1);
            field_29a20 = nullptr;
        }
    }
    for (s32 i = 0; i < 13; i++) {
        PPFX_SAFE_RELEASE_INTERFACE(field_299b8[i]);
    }
    return 0;
}

}  // namespace PPFX

// 0x710046e270: CTextureUtil::InitializeDeviceSharedTexturePoolWithCheck (its
// log lines), under the placeholder name its caller gave it
s32 Unk_46e270(void* self_, u32) {
    PPFX::CTextureUtil* self = static_cast<PPFX::CTextureUtil*>(self_);
    s32 result = self->field_29a58->vf0(self->field_20);
    if (result < 0) {
#line 5837
        PPFX_ERROR("CTextureUtil::InitializeDeviceSharedTexturePoolWithCheck(): m_pTexturePool->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
#line 5841
    PPFX_LOG("CTextureUtil::InitializeDeviceSharedTexturePoolWithCheck(): m_pTexturePool->InitializeDevice() succeeded.\n");
    return result;
}

namespace PPFX {

// 0x7100470860
s32 CTextureUtil::Unk_470860(s32 value) {
    field_29a64 = value;
    return 0;
}

// 0x7100470880
s32 CTextureUtil::Unk_470880() {
    field_29a6c = false;
    return 0;
}

// 0x71004708a0
s32 CTextureUtil::Unk_4708a0(void* arg) {
    return field_29a58->Unk_49fed0(arg);
}

// 0x7100471410
void CTextureUtil::Unk_471410() {
    field_20->vf39();
    field_20->vf40(-1);
    field_20->vf42(0);
}

// 0x7100471960
// NON_MATCHING: the same instructions, but the corners' temporaries are in
// other floating-point registers (the height's half and scale in s3 and s5
// in the original, s2 and s5 here): no order of these eight statements gave
// the original's allocation.
s32 CTextureUtil::Unk_471960(f32 x, f32 y, f32 width, f32 height, u32 flags) {
    if (!(flags & 0x40000)) {
        field_20->vf41(-1, 1);
    }
    if (!(flags & 0x20000)) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    f32 targetWidth;
    f32 targetHeight;
    {
        Unk_Viewport viewport;
        field_20->vf17(&viewport);
        targetWidth = static_cast<f32>(viewport.field_8);
        targetHeight = static_cast<f32>(viewport.field_c);
    }
    f32 halfWidth = targetWidth * 0.5f;
    f32 halfHeight = targetHeight * 0.5f;
    f32 scaleX = 2.0f / targetWidth;
    f32 scaleY = 2.0f / targetHeight;
    f32 x0 = x - halfWidth;
    f32 x1 = x0 + width;
    f32 y0 = y - halfHeight;
    f32 y1 = y0 + height;
    s32 count;
    if (flags & 0x10000) {
        count = 4;
    } else {
        x1 = x0 + (x1 - x0) * 2.0f;
        y0 = y1 + (y0 - y1) * 2.0f;
        count = 3;
    }
    const f32 offset = 0.0f;
    f32 vertices[4][2];
    vertices[0][0] = scaleX * (x0 + offset);
    vertices[0][1] = scaleY * (y1 + offset);
    vertices[1][0] = scaleX * (x0 + offset);
    vertices[1][1] = scaleY * (y0 + offset);
    vertices[2][0] = scaleX * (x1 + offset);
    vertices[2][1] = scaleY * (y1 + offset);
    vertices[3][0] = scaleX * (x1 + offset);
    vertices[3][1] = scaleY * (y0 + offset);
    field_30.Unk_Layout1();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 0);
    if (!(flags & 0x20000)) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100471c50 to 0x7100472cd0: a rectangle with 1 to 6 rectangles of
// texture coordinates (`from` and `to` are their opposite corners). The
// result is the last call's, and the flags are the last parameter.
// 0x7100471c50
s32 CTextureUtil::Unk_471c50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[1] = {Unk_Float2(u0, v0)};
    Unk_Float2 to[1] = {Unk_Float2(s0, t0)};
    Unk_Float2 coords[1][4];
    Unk_471470(1, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<1> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<1>(positions[i], coords, i);
    }
    field_30.Unk_46cfe0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 1);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100471f60
s32 CTextureUtil::Unk_471f60(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[2] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1)};
    Unk_Float2 to[2] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1)};
    Unk_Float2 coords[2][4];
    Unk_471470(2, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<2> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<2>(positions[i], coords, i);
    }
    field_30.Unk_46d0c0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 2);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472250
s32 CTextureUtil::Unk_472250(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[3] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2)};
    Unk_Float2 to[3] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2)};
    Unk_Float2 coords[3][4];
    Unk_471470(3, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<3> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<3>(positions[i], coords, i);
    }
    field_30.Unk_46d1b0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 3);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472590
s32 CTextureUtil::Unk_472590(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[4] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2), Unk_Float2(u3, v3)};
    Unk_Float2 to[4] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2), Unk_Float2(s3, t3)};
    Unk_Float2 coords[4][4];
    Unk_471470(4, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<4> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<4>(positions[i], coords, i);
    }
    field_30.Unk_46d2a0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 4);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472900
s32 CTextureUtil::Unk_472900(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, f32 u4, f32 v4, f32 s4, f32 t4, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[5] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2), Unk_Float2(u3, v3), Unk_Float2(u4, v4)};
    Unk_Float2 to[5] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2), Unk_Float2(s3, t3), Unk_Float2(s4, t4)};
    Unk_Float2 coords[5][4];
    Unk_471470(5, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<5> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<5>(positions[i], coords, i);
    }
    field_30.Unk_46d3a0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 5);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472cd0
s32 CTextureUtil::Unk_472cd0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, f32 u4, f32 v4, f32 s4, f32 t4, f32 u5, f32 v5, f32 s5, f32 t5, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[6] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2), Unk_Float2(u3, v3), Unk_Float2(u4, v4), Unk_Float2(u5, v5)};
    Unk_Float2 to[6] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2), Unk_Float2(s3, t3), Unk_Float2(s4, t4), Unk_Float2(s5, t5)};
    Unk_Float2 coords[6][4];
    Unk_471470(6, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<6> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<6>(positions[i], coords, i);
    }
    field_30.Unk_46d4b0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 6);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// DRAWRECTGPU_BEGIN
// 0x7100473d90
s32 CTextureUtil::Unk_473d90(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg9, f32 arg10,
                             f32 arg11, f32 arg12, f32 arg13, const Unk_Float4* arg1, const Unk_Float4* arg2,
                             const Unk_Float4* matrix, Unk_GPUTexture* texture, u32 flags) {
    field_30.field_0->vf29(field_30.field_1b32c);
    if (matrix != nullptr) {
        for (s32 i = 0; i < 4; i++) {
            Unk_24e4c18[i] = matrix[i];
        }
    } else {
        memset(Unk_24e4c18, 0, sizeof(Unk_Float4) * 4);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 4);
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 0);
    Unk_24e4c18[0] = Unk_Float4(arg9, 1.0f / arg9, arg10, arg11);
    Unk_24e4c18[1] = *arg1;
    Unk_24e4c18[2] = *arg2;
    Unk_24e4c18[3].field_0[0] = arg12;
    Unk_24e4c18[3].field_0[1] = arg13;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 4);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
        s32 filter = texture->vf16();
        texture->vf17(1);
        s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
        texture->vf15(filter);
        return result;
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100475150
s32 CTextureUtil::Unk_475150(CRenderTexture* source, CRenderTexture* target, bool clear) {
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result >= 0) {
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        field_30.field_0->vf29(field_30.field_7dac);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        Unk_24e4c18[0].field_0[0] = source->field_88;
        Unk_24e4c18[0].field_0[1] = source->field_8c;
        Unk_24e4c18[0].field_0[2] = 0.0f;
        Unk_24e4c18[0].field_0[3] = 0.0f;
        field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 1);
        s32 filter = texture->vf16();
        texture->vf15(5);
        result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0);
        texture->vf15(filter);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100475320
// NON_MATCHING: the flags' mask (`and w, w, #1`) is before the loop that finds
// the source's texture here and after it in the original, and the registers
// of the parameters follow from that.
s32 CTextureUtil::Unk_475320(f32 arg8, f32 arg9, CRenderTexture* source, CRenderTexture* target,
                             const Unk_Float4* arg3, const Unk_Float4* arg4, const Unk_Float4* arg5,
                             const Unk_Float4* arg6, u32 flags) {
    if (flags & 1) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result >= 0) {
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        field_30.field_0->vf29(field_30.field_7da8);
        Unk_24e4a18[0] = *arg3;
        Unk_24e4a18[1] = *arg4;
        Unk_24e4a18[2] = *arg5;
        Unk_24e4a18[3] = *arg6;
        field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 4);
        Unk_Float4 value(arg8, arg9, 0.0f, 0.0f);
        field_30.field_0->vf20(field_30.field_f8, &value.field_0[0].field_0);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        s32 filter = texture->vf16();
        texture->vf15(5);
        result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, flags & 1);
        texture->vf15(filter);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100473150: a rectangle with `count` (1 to 4) rectangles of texture
// coordinates, given as four arrays
s32 CTextureUtil::Unk_473150(f32 x, f32 y, f32 width, f32 height, const f32* u0, const f32* v0, const f32* u1,
                             const f32* v1, s32 count, u32 flags) {
    if (count < 1 || count > 4) {
        return -4;
    }
    switch (count) {
    case 1:
        return Unk_471c50(x, y, width, height, u0[0], v0[0], u1[0], v1[0], flags);
    case 2:
        return Unk_471f60(x, y, width, height, u0[0], v0[0], u1[0], v1[0], u0[1], v0[1], u1[1], v1[1], flags);
    case 3:
        return Unk_472250(x, y, width, height, u0[0], v0[0], u1[0], v1[0], u0[1], v0[1], u1[1], v1[1], u0[2], v0[2],
                          u1[2], v1[2], flags);
    case 4:
        return Unk_472590(x, y, width, height, u0[0], v0[0], u1[0], v1[0], u0[1], v0[1], u1[1], v1[1], u0[2], v0[2],
                          u1[2], v1[2], u0[3], v0[3], u1[3], v1[3], flags);
    }
    return 0;
}

// 0x71004732b0: draws indexed triangles from the caller's buffers
s32 CTextureUtil::Unk_4732b0(s32 count, s32 arg2, s32 arg3, IGPUBuffer* vertices, void* indices, u32 offset, s32 arg7,
                             u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u32 passes;
        field_30.field_0->vf33(&passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    field_30.Unk_46d6f0();
    field_30.field_0->vf42(field_30.field_299b8[12], vertices, offset, 0, 0, 1);
    field_20->vf9(indices, arg7);
    field_30.field_0->SetupGraphicsPipelineState();
    s32 result = field_20->vf58(4, count, 0, arg2, arg3);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100474ae0: four taps, half a texel around each corner
s32 CTextureUtil::Unk_474ae0(CRenderTexture* target, CRenderTexture* source, bool clear) {
    if (clear) {
        Unk_471410();
    }
    f32 width0 = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 height0 = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 sx = source->field_88;
    f32 sy = source->field_8c;
    f32 ox = source->field_90;
    f32 oy = source->field_94;
    f32 a = sx * 0.5f + ox;
    f32 b = sy * 0.5f + oy;
    f32 u1 = sx * width0 + ox;
    f32 v1 = sy * height0 + oy;
    Unk_Float4 rects[4];
    rects[0] = Unk_Float4(-a, -b, u1 - a, v1 - b);
    rects[1] = Unk_Float4(a, -b, u1 + a, v1 - b);
    rects[2] = Unk_Float4(-a, b, u1 - a, v1 + b);
    rects[3] = Unk_Float4(a, b, u1 + a, v1 + b);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    target->Unk_49d250(0, 0, 1, 0, 0);
    s32 result = CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (result >= 0) {
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        field_30.field_0->vf29(field_30.field_7dc4);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        s32 filter = texture->vf16();
        texture->vf15(5);
        result = Unk_472590(0.0f, 0.0f, width, height, rects[0].field_0[0].field_0, rects[0].field_0[1].field_0,
                            rects[0].field_0[2].field_0, rects[0].field_0[3].field_0, rects[1].field_0[0].field_0,
                            rects[1].field_0[1].field_0, rects[1].field_0[2].field_0, rects[1].field_0[3].field_0,
                            rects[2].field_0[0].field_0, rects[2].field_0[1].field_0, rects[2].field_0[2].field_0,
                            rects[2].field_0[3].field_0, rects[3].field_0[0].field_0, rects[3].field_0[1].field_0,
                            rects[3].field_0[2].field_0, rects[3].field_0[3].field_0, 0);
        texture->vf15(filter);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100473fd0: one direction of a Gaussian blur with up to 8 pairs of taps
// (the offsets step by 1, by 1.5 around the limit and by 2 beyond it)
s32 CTextureUtil::Unk_473fd0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 sigma,
                             f32 arg10, f32 arg11, const Unk_Float2* direction, Unk_GPUTexture* texture, s32 taps,
                             u32 flags) {
    s32 n = taps;
    if (taps < 1) {
        n = static_cast<s32>(sigma + 0.9999f);
    }
    n = n < 8 ? n : 8;
    n = n > 2 ? n : 2;
    s32 count = n * 2 + 1;
    field_30.field_0->vf29(field_30.field_7e28[n - 2]);
    f32 scale = -1.0f / (2.0f * sigma * sigma);
    f32 limit = sigma * 1.4823039f;
    Unk_24e4c18[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    bool nearest = limit <= static_cast<f32>(n);
    f32 offset = 0.0f;
    for (s32 i = 0; i < n; i++) {
        f32 next = offset + 1.0f;
        if (offset > limit) {
            next = offset + 2.0f;
        } else if (next > limit) {
            next = offset + 1.5f;
        }
        offset = next;
        f32 dx = offset * direction->field_0[0].field_0;
        f32 dy = offset * direction->field_0[1].field_0;
        f32 weight = offset * (scale * offset);
        Unk_24e4c18[1 + i * 2] = Unk_Float4(dx, dy, weight, 0.0f);
        Unk_24e4c18[2 + i * 2] = Unk_Float4(-dx, -dy, weight, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, count);
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, count < 8 ? count : 8);
    Unk_24e4c18[0] = Unk_Float4(0.0f, -1.0f / (2.0f * arg10 * arg10), -1.0f / (2.0f * arg11 * arg11), 0.0f);
    field_30.field_0->vf22(field_30.field_cc, Unk_24e4c18, 1);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    if (static_cast<f32>(texture->field_4c) != width || static_cast<f32>(texture->field_50) != height) {
        nearest = true;
    }
    s32 filter = texture->vf16();
    texture->vf15(nearest ? 8 : 9);
    s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture->vf15(filter);
    return result;
}

// 0x7100474d00: the same from one render texture into another, along x or y
s32 CTextureUtil::Unk_474d00(f32 sigma, f32 arg2, f32 arg3, CRenderTexture* source, CRenderTexture* target,
                             bool horizontal, s32 taps, bool clear) {
    if (clear) {
        Unk_471410();
    }
    Unk_Float2 direction = *reinterpret_cast<const Unk_Float2*>(&source->field_88);
    if (horizontal) {
        direction.field_0[1] = 0.0f;
    } else {
        direction.field_0[0] = 0.0f;
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    target->Unk_49d250(0, 0, 1, 0, 0);
    s32 result = CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (result >= 0) {
        result = Unk_473fd0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, sigma, arg2, arg3, &direction,
                            Unk_GetTexture(source), taps, 0);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x71004768b0: `count` textures (1 to 16), each times a colour, with the
// technique for that many textures or the nearest one that exists
s32 CTextureUtil::Unk_4768b0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             Unk_GPUTexture** textures, const Unk_Float4* colors, s32 index, u32 flags) {
    if (count < 1 || count > 16) {
        return -4;
    }
    s32 technique;
    s32 used;
    if (Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        used = count - 1;
        do {
            technique = field_30.field_48a8[used][index];
            used++;
        } while (used < 16 && technique == 0);
    } else {
        used = count + 1;
        do {
            technique = field_30.field_48a8[used - 2][index];
            used--;
        } while (used > 0 && technique == 0);
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 values[16];
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            values[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i < used; i++) {
        values[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, values, used);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    for (s32 i = count; i < used; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// DRAWRECTGPU_END

// 0x71004708b0: releases what the device made
s32 CTextureUtil::Unk_4708b0(void* arg) {
    field_29bb0 = arg;
    field_30.Unk_46d990(arg);
    field_29a58->vf1();
    field_29a98->vf1();
    PPFX_SAFE_RELEASE(field_29b00);
    for (s32 i = 0; i < 10; i++) {
        PPFX_SAFE_RELEASE(field_29b08[i]);
    }
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[1]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[2]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[3]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[4]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29aa0[1]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29aa0[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ab8[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ab8[1]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ab8[2]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ad8[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ad8[1]);
    for (s32 i = 0; i < 7; i++) {
        PPFX_SAFE_RELEASE_INTERFACE(field_29bc8[i]);
    }
    UNK_DELETE_ARRAY(field_29af8);
    field_29af0 = 0;
    return CGPUResourceManage::vf1();
}

// 0x7100470e40
s32 CTextureUtil::vf1() {
    Unk_4708b0(nullptr);
    return CGPUResourceManage::vf1();
}

// 0x7100470e70
s32 CTextureUtil::vf2() {
    s32 result = CGPUResourceManage::vf2();
    return result < 0 ? result : 0;
}

// 0x7100470e90: releases the rest, and puts the members back as the
// constructor left them
s32 CTextureUtil::vf3() {
    PPFX_SAFE_RELEASE(field_29a98);
    PPFX_SAFE_RELEASE(field_29b00);
    for (s32 i = 0; i < 10; i++) {
        PPFX_SAFE_RELEASE(field_29b08[i]);
    }
    Unk_Clear();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x710046e110, 0x710046e1c0 (deleting)
CTextureUtil::~CTextureUtil() {
    if (field_29bb0 != nullptr) {
        CTextureUtil::vf1();
    }
    Unk_49ec80();
    UNK_DELETE(field_29a58);
}

}  // namespace PPFX
