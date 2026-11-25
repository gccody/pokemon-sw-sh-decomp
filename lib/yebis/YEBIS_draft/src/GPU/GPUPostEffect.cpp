// Scope: common
// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp, the
// __FILE__ of its log lines).
#include <float.h>
#include <math.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUPostEffect.h>
#include <nx_middleware/gfx/nvn.h>
#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h>
#include <yebis/YEBIS_draft/src/GPU/GPUGlareDef.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderGlare.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Luminance.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.h>
#include <yebis/YEBIS_draft/src/GPU/GPUTextureLuminance.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

// 0x7100418e20: the post effect
u64 Unk_418e20_get();

// The TU's merged statics (0x71024e0c38 to 0x71024e14f8, sorted by size,
// module order for ties): the flags of GetEffectDofEdgeQualityType...
// (0xc38, table 0xd58), Unk_DofQualityLevel (0xc39, 0xdac) and
// Unk_DofEdgeBlurType (0xc3b, 0xd28), which Initialize (0x710041afb0) uses
// first, then the angle at 0xc44, the white points from 0xc48,
// 0x710042df80's two guards and matrices (0xd08/0xd10, 0xea8/0xee8),
// 0x7100435ed0's guarded glare definition (0xd18, 0xff0), Unk_Static_Object0
// and 1 (0xd6c, 0xd8c), the reflection handle (0xf78) and the tables named
// Unk_24e.... Every function indexing the block from its start (the static
// initialiser 0x710043d330, 0x7100427900, 0x710042b9f0, ...) depends on all
// of them being there.

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

// a scale and a number (0x710041afb0's tables of them)
struct Unk_ScaleLevel {
    Unk_ScaleLevel(f32 scale, s32 level) : field_0(scale), field_4(level) {}

    Unk_Float field_0;
    s32 field_4;
};
PKMN_SIZE_ASSERT(Unk_ScaleLevel, 0x8);

// 0x71024e0e28, 0x71024e0e68: two tables of eight (0x710041afb0 picks one by
// the byte at 0x71024e09e0)
static Unk_ScaleLevel Unk_24e0e28[8] = {
    Unk_ScaleLevel(0.125f, 4), Unk_ScaleLevel(0.15f, 5), Unk_ScaleLevel(0.2f, 6),  Unk_ScaleLevel(0.25f, 7),
    Unk_ScaleLevel(0.375f, 8), Unk_ScaleLevel(0.5f, 9),  Unk_ScaleLevel(0.75f, 10), Unk_ScaleLevel(1.0f, 11),
};
static Unk_ScaleLevel Unk_24e0e68[8] = {
    Unk_ScaleLevel(0.125f, 2), Unk_ScaleLevel(0.15f, 3), Unk_ScaleLevel(0.2f, 4),  Unk_ScaleLevel(0.25f, 5),
    Unk_ScaleLevel(0.375f, 6), Unk_ScaleLevel(0.5f, 7),  Unk_ScaleLevel(0.75f, 8), Unk_ScaleLevel(1.0f, 9),
};

// the depth of field's settings of a quality (0x710041afb0's table)
struct Unk_DofQuality {
    Unk_DofQuality(f32 scale, s32 a, s32 b, s32 c, s32 d, s32 size, f32 e)
        : field_0(scale), field_4(a), field_8(b), field_c(c), field_10(d), field_14(size), field_18(e) {}

    Unk_Float field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
    Unk_Float field_18;
};
PKMN_SIZE_ASSERT(Unk_DofQuality, 0x1c);

// 0x71024e1098: the depth of field's settings of each of 20 qualities
static Unk_DofQuality Unk_24e1098[20] = {
    Unk_DofQuality(0.25f, 1, 1, 1, 1, 0x80, 0.125f),  Unk_DofQuality(0.25f, 2, 1, 1, 3, 0xa0, 0.125f),
    Unk_DofQuality(0.375f, 2, 2, 0, 3, 0xa0, 0.125f), Unk_DofQuality(0.5f, 3, 2, 0, 2, 0xa0, 0.125f),
    Unk_DofQuality(0.5f, 3, 2, 0, 3, 0x140, 0.25f),   Unk_DofQuality(0.5f, 3, 3, 0, 2, 0x140, 0.25f),
    Unk_DofQuality(0.5f, 3, 3, 0, 3, 0x140, 0.25f),   Unk_DofQuality(0.5f, 4, 3, 0, 4, 0x140, 0.25f),
    Unk_DofQuality(0.5f, 5, 3, 0, 4, 0x140, 0.4f),    Unk_DofQuality(0.75f, 6, 4, 0, 4, 0x180, 0.4f),
    Unk_DofQuality(1.0f, 7, 4, 0, 4, 0x180, 0.4f),    Unk_DofQuality(0.5f, 7, 4, 6, 5, 0x180, 0.4f),
    Unk_DofQuality(0.5f, 7, 4, 7, 5, 0x180, 0.4f),    Unk_DofQuality(0.5f, 7, 4, 5, 5, 0x180, 0.4f),
    Unk_DofQuality(0.75f, 7, 4, 6, 5, 0x180, 0.4f),   Unk_DofQuality(0.75f, 7, 4, 7, 5, 0x180, 0.4f),
    Unk_DofQuality(0.75f, 7, 4, 5, 5, 0x180, 0.5f),   Unk_DofQuality(1.0f, 7, 4, 6, 5, 0x180, 0.5f),
    Unk_DofQuality(1.0f, 7, 4, 7, 5, 0x180, 0.5f),    Unk_DofQuality(1.0f, 7, 4, 5, 5, 0x180, 0.5f),
};

// two levels (0x710041afb0's table of them)
struct Unk_LevelPair {
    Unk_LevelPair(s32 a, s32 b) : field_0(a), field_4(b) {}

    s32 field_0;
    s32 field_4;
};

// 0x71024e12c8: the depth of field's level pairs of each of 10 qualities
// (-1: none)
static Unk_LevelPair Unk_24e12c8[10][7] = {
    {Unk_LevelPair(0, 0), Unk_LevelPair(1, 1), Unk_LevelPair(2, 1), Unk_LevelPair(2, 2),
     Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(1, 1), Unk_LevelPair(1, 2), Unk_LevelPair(2, 2),
     Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(1, 1), Unk_LevelPair(1, 2),
     Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 2), Unk_LevelPair(1, 2), Unk_LevelPair(2, 2),
     Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(0, 2), Unk_LevelPair(1, 2),
     Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(1, 1), Unk_LevelPair(1, 2),
     Unk_LevelPair(2, 2), Unk_LevelPair(3, 2), Unk_LevelPair(3, 3)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(0, 2), Unk_LevelPair(1, 2),
     Unk_LevelPair(2, 2), Unk_LevelPair(3, 2), Unk_LevelPair(3, 3)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(0, 2), Unk_LevelPair(1, 2),
     Unk_LevelPair(2, 2), Unk_LevelPair(2, 3), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(0, 2), Unk_LevelPair(1, 2),
     Unk_LevelPair(1, 3), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
    {Unk_LevelPair(0, 0), Unk_LevelPair(0, 1), Unk_LevelPair(0, 2), Unk_LevelPair(0, 3),
     Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1), Unk_LevelPair(-1, -1)},
};

// The tables below are filled the first time their (inline) functions run.
// Each one's flag and table are statics of that function, so they are made
// in the order the functions are first used: the flags at 0x71024e0c38 to
// 0x71024e0c40 follow it, which is why Unk_DofEdgeBlurType is only declared
// here and defined after 0x7100427900 (whose table is the third), and why
// the first users of the later ones (0x7100429460, 0x710042b9f0,
// 0x710042be10, 0x710042a0f0, 0x7100435ed0) are in that order at the end.

// GetEffectDofEdgeQualityTypeFromEdgeQualityType (its log line names it)
static inline s32 GetEffectDofEdgeQualityTypeFromEdgeQualityType(s32 quality) {
    static bool initialised = false;
    static s32 types[5];
    if (!initialised) {
        initialised = true;
        types[0] = 0;
        types[1] = 0;
        types[2] = 2;
        types[3] = 6;
        types[4] = 6;
    }
    if (static_cast<u32>(quality) >= 5) {
        if (quality == -1) {
            return 0x10000000;
        }
#line 1008
        PPFX_WARNING("GetEffectDofEdgeQualityTypeFromEdgeQualityType(): Unsupported EPFX_DOFEDGEQUALITY: %d is specified.\n",
                     quality);
    }
    return types[quality];
}

// the depth of field's level of a quality (a table set up the first time)
static inline s32 Unk_DofQualityLevel(s32 quality) {
    static bool initialised = false;
    static s32 levels[8];
    if (!initialised) {
        initialised = true;
        levels[0] = 0;
        levels[1] = 1;
        levels[2] = 2;
        levels[3] = 3;
        levels[4] = 4;
        levels[5] = 5;
        levels[6] = 5;
        levels[7] = 5;
    }
    return levels[quality];
}

// below 0x7100427900
static inline s32 Unk_DofEdgeBlurType(s32 type);

}  // namespace PPFX

// 0x71024e09e0: a flag (placeholder)
extern u8 Unk_24e09e0;
// 0x71024e09e8, 0x71024e09f0, 0x71024e09f8: a callback Initialize calls (with
// 1, then 2) when the flags' bit for the call is set, and its argument
// (placeholders)
extern void (*Unk_24e09e8)(s32 step, void* arg);
extern u8 Unk_24e09f0;
extern void* Unk_24e09f8;
// 0x7101b35154 (GPUDepthOfField.cpp): a flag in .rodata
extern const bool Unk_1b35154;
// 0x710238d258: whether new render textures are cleared (ppfxRenderToTexture.cpp)
extern u8 Unk_238d258;
// 0x71004b72b0 (lib/yebis/leaf/Unk_4afa90.cpp)
u32 Unk_4b72b0_get();
// 0x7100442c50 (GPUTextureUtil.h)
bool Unk_442c50_get(u64 device);
// 0x710046e350 (lib/yebis/leaf/Unk_46e350.cpp): the texture util's
// InitializeDeviceSharedTexturePool (the log line names what it does)
s32 Unk_46e350_call(void* util);
// 0x7100446df0 (Unk_447050.cpp): a result's name
const char* Unk_446df0(s32 result);
// 0x710238d250 (placeholder)
extern s64 Unk_238d250;
// below (GPUPostEffect.cpp's CPostEffect setters, called with the object's address)
s32 Unk_424240(u64 self, u32 flag, f32 width, f32 height, f32 x, f32 y);
s32 Unk_427760(u64 self, f32 a, f32 b, f32 c, f32 d, f32 e);
s32 Unk_424100(PPFX::CPostEffect* self, f32 nearZ, f32 farZ, f32 fov, f32 elapsed, f32 scale);
s32 Unk_424670(PPFX::CPostEffect* self, f32 elapsed);
s32 Unk_424740(u64 self, s32 view, bool enable);
s32 Unk_4248b0(f32 sensitivity, PPFX::Unk_Float scale, PPFX::Unk_Float speed, f32 darkSensitivity, f32 darkScale,
               f32 darkSpeed, f32 border, u64 self, s32 view);
s32 Unk_424b20(u64 self, s32 view, f32 minExposure, f32 maxExposure);
s32 Unk_424c90(u64 self, s32 view, f32 middleGray, f32 glare);
s32 Unk_424de0(u64 self, s32 view, u32 mode, f32 delay);
s32 Unk_424f40(f32 width, f32 height, f32 x, f32 y, u64 self, s32 view);
s32 Unk_4244a0(u64 self, u32 tonemap, f32 exposure, f32 gamma, f32 factor, f32 dither);
s32 Unk_425240(u64 self, u32 mode);
s32 Unk_4255b0(u64 self, u32 index);
static inline void Unk_Identity(PPFX::MATRIXT44* out);
// 0x7100455510, 0x7100455530 (lib/yebis/leaf: the glare's, placeholder types)
struct Unk_455510;
struct Unk_455350;
struct Unk_455350_Float4 {
    f32 field_0[4];
};
u32 Unk_455510_update(Unk_455510* self, f32 fvalue, f32 farg1, f32 farg2);
u32 Unk_455530_set(Unk_455350* self, const Unk_455350_Float4* a, const Unk_455350_Float4* b);
// 0x710049c8d0 (lib/yebis/leaf)
void Unk_49c8d0_call(void* self, void* arg);
// 0x71004234f0: CPostEffect::SetActiveView (below)
s32 Unk_4234f0(u64 self, u32 view);
// 0x71004534a0 (GPURenderGlare.cpp)
s32 Unk_4534a0(void* self, const PPFX::Unk_GlareRect* rect, f32 a, f32 b, f32 c, f32 d, f32 e);
// 0x7100423480 (below)
bool Unk_423480(s32 format);

namespace PPFX {

// 0x7100446ae0, 0x7100446eb0 (Unk_447050.cpp): a format's bits per pixel, and
// the multisample type and quality of a sample count
u32 Unk_446ae0(s32 format);
// 0x7100442bc0 (GPUInterfaceDevice.cpp): the first of `count` formats the
// device supports for a use (`fallback` if none)
s32 Unk_442bc0(IGPUDevice* self, s32 usage, s32 type, const s32* formats, s32 count, s32 fallback);
s32 Unk_446eb0(s32 count, s32 quality, u32* outType, s32* outQuality);

// Unk_453_30's eight bytes at 0x60 as Initialize fills them: whether there
// are light ghosts, and how many (placeholder)
struct Unk_GlareGhosts {
    bool field_0;
    s32 field_4;
};

// whether the depth of field can be drawn in a format (placeholder: the
// formats Initialize accepts when the flags' bit 2 is set)
static inline bool Unk_IsDofFormat(s32 format) {
    switch (format) {
    case 2:
    case 6:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 20:
    case 21:
    case 0x1a:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 40:
    case 41:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 67:
        return true;
    default:
        return false;
    }
}

// CPostEffect::SetMotionBlurVelocityDilationType (its log line names it; inline)
static inline s32 Unk_SetMotionBlurVelocityDilationType(CPostEffect* self, u32 type) {
    u64 dilation = type & 1;
    if (dilation != 0 && self->field_1e0 == nullptr) {
#line 14355
        PPFX_WARNING("CPostEffect::SetMotionBlurVelocityDilationType(): Initialize with PFX_INITPARAM::m_uiVelocityDilationType |= PFXMBVD_GAUSSIAN.\n");
        return 1;
    }
    self->field_d48 = dilation;
    return 0;
}

// CPostEffect::SetMotionBlurVelocitySource (its log lines name it; inline)
static inline s32 Unk_SetMotionBlurVelocitySource(CPostEffect* self, s32 source) {
    if (source == 0) {
        if (self->field_1bd) {
            if (self->field_1d8 == nullptr) {
#line 14420
                PPFX_ERROR("CPostEffect::SetMotionBlurVelocitySource(): Initialize() with PFXINIT_MOTIONBLUR_INTERNALVELOCITYTEXTURE flag to use PFXVS_AUTOGEN.\n");
                return -6;
            }
        } else {
            if (self->field_ce5) {
#line 14465
                PPFX_ERROR("CPostEffect::SetMotionBlurVelocitySource(): Effective velocity source must be set with PFXVS_APPGEN.\n");
                return -6;
            }
            source = 2;
        }
    }
    self->field_d2c = source;
    self->field_d30 = -2;
    self->field_d38 = nullptr;
    self->field_d40 = false;
    self->field_d18 = 1.0f;
    self->field_d1c = 1.0f;
    return 0;
}

// CPostEffect::SetTonemapBackendColorSpaceMode and its Sdr version (their log
// lines name them; inline)
static inline s32 Unk_SetTonemapBackendColorSpaceMode(CPostEffect* self, s32 mode) {
#line 17876
    PPFX_FN("Frame: %d, View: %d, SetTonemapBackendColorSpaceMode(eBackendColorSpaceMode: %d);\n", self->Unk_Frame(self->field_298), self->field_298, mode);
    self->field_9ac = mode;
    return 0;
}
static inline s32 Unk_SetTonemapBackendColorSpaceModeSdr(CPostEffect* self, s32 mode) {
#line 17889
    PPFX_FN("Frame: %d, View: %d, SetTonemapBackendColorSpaceModeSdr(eBackendColorSpaceMode: %d);\n", self->Unk_Frame(self->field_298), self->field_298, mode);
    self->field_9b0 = mode;
    return 0;
}

// CPostEffect::SetGlareModulatorSourceViewportScale,
// SetEffectMaskColorSourceViewportScale and
// SetEffectMaskAlphaSourceViewportScale (their log lines name them; inline)
static inline s32 Unk_SetGlareModulatorSourceViewportScale(CPostEffect* self, f32 width, f32 height, f32 x, f32 y) {
    if (self->field_0) {
#line 38328
        PPFX_ERROR("CPostEffect::SetGlareModulatorSourceViewportScale(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    self->field_814.field_0 = width;
    self->field_814.field_4 = height;
    self->field_814.field_8 = x;
    self->field_814.field_c = y;
    return 0;
}
static inline s32 Unk_SetEffectMaskColorSourceViewportScale(CPostEffect* self, f32 width, f32 height, f32 x, f32 y) {
    if (self->field_0) {
#line 38353
        PPFX_ERROR("CPostEffect::SetEffectMaskColorSourceViewportScale(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    self->field_824.field_0 = width;
    self->field_824.field_4 = height;
    self->field_824.field_8 = x;
    self->field_824.field_c = y;
    return 0;
}
static inline s32 Unk_SetEffectMaskAlphaSourceViewportScale(CPostEffect* self, f32 width, f32 height, f32 x, f32 y) {
    if (self->field_0) {
#line 38378
        PPFX_ERROR("CPostEffect::SetEffectMaskAlphaSourceViewportScale(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    self->field_834.field_0 = width;
    self->field_834.field_4 = height;
    self->field_834.field_8 = x;
    self->field_834.field_c = y;
    return 0;
}

// CPostEffect::SetAutoExposureMeteringResult, SetAutoExposureMeteringLuminanceRange
// and SetAutoExposureMeteringColorSpace (their log lines name them; inline)
static inline s32 Unk_SetAutoExposureMeteringResult(CPostEffect* self, s32 view, f32 luminance) {
#line 19381
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMeteringResult(iEffectViewIndex: %d, fSceneLuminance: %f);\n", self->Unk_Frame(self->field_298), self->field_298, view, luminance);
    for (s32 i = 0; i < self->field_400; i++) {
        self->field_2a0[i].field_24 = luminance;
    }
    return 0;
}
static inline s32 Unk_SetAutoExposureMeteringLuminanceRange(CPostEffect* self, s32 view, f32 minLuminance, f32 maxLuminance) {
#line 19073
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMeteringLuminanceRange(iEffectViewIndex: %d, fMinLuminance: %f, fMaxLuminance: %f);\n", self->Unk_Frame(self->field_298), self->field_298, view, minLuminance, maxLuminance);
    for (s32 i = 0; i < self->field_400; i++) {
        self->field_2a0[i].field_1c = minLuminance;
        self->field_2a0[i].field_20 = maxLuminance;
    }
    return 0;
}
static inline s32 Unk_SetAutoExposureMeteringColorSpace(CPostEffect* self, s32 space) {
#line 19443
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMeteringColorSpace(eDynamicRangeSpace: %s);\n", self->Unk_Frame(self->field_298), self->field_298, space);
    self->field_f74 = space;
    return 0;
}

// CPostEffect::SetRenderSceneHeightReverse_Gcm (its log line names it; inline)
static inline s32 Unk_SetRenderSceneHeightReverse_Gcm(CPostEffect* self, bool reverse) {
    if (self->field_0) {
#line 40843
        PPFX_ERROR("CPostEffect::SetRenderSceneHeightReverse_Gcm(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    self->field_a = reverse;
    return 0;
}

// 0x71004190f0
// NON_MATCHING: the instruction schedule (the stores are the original's,
// merged the same way; their order isn't)
CPostEffect::CPostEffect()
    : field_0(false), field_10(0), field_18(nullptr), field_20(0), field_28(nullptr), field_30(nullptr),
      field_38(nullptr), field_40(nullptr), field_48(0), field_50(nullptr), field_70(nullptr), field_80(nullptr),
      field_b8(nullptr), field_c8(0), field_178(nullptr), field_190(nullptr), field_198(nullptr), field_1a0(nullptr),
      field_1a8(nullptr), field_1b0(nullptr), field_1d8(nullptr), field_1e0(nullptr), field_1e8(nullptr),
      field_1f0(nullptr), field_1f8(nullptr), field_200(nullptr), field_208(nullptr), field_210(nullptr),
      field_218(nullptr), field_220(nullptr), field_228(nullptr), field_230(nullptr), field_238(nullptr),
      field_240(nullptr), field_248(nullptr), field_250(nullptr), field_258(nullptr), field_260(nullptr),
      field_268(nullptr), field_278(nullptr), field_288(nullptr), field_290(nullptr), field_2a0(nullptr),
      field_2a8(nullptr), field_400_param(), field_550(nullptr), field_558(0), field_560(nullptr), field_568(0),
      field_570(nullptr), field_578(nullptr), field_580(0), field_588(nullptr), field_590(0), field_5b8(nullptr),
      field_5c0(nullptr), field_858(nullptr), field_868(nullptr), field_f84(), field_1170(false), field_1198(nullptr),
      field_11a0(nullptr), field_11a8(nullptr), field_11b0(nullptr), field_11b8(false), field_11c0(nullptr),
      field_11c8(false), field_11cc(0), field_1200(nullptr), field_1208(0) {}

// 0x710041afb0
// NON_MATCHING: 31048 of 31268 bytes. Written section by section from the
// original's order of events and log lines; not compared in detail (the
// frame is 0x300 bytes smaller and the block layout differs). The read of
// the edge blur table (see Unk_DofEdgeBlurType's call) is kept by a test of
// its value that the original doesn't have: it reads the table there and
// nothing of what it does with the value is left, but its table and stores
// are (here they are removed with an unused read).
s32 CPostEffect::Initialize(const Unk_417b30_Desc* desc, u32 glareQuality, u32 dofQuality, u32 flags, void* param) {
#line 4219
    PPFX_LOG("==== CPostEffect::Initialize() ====\n");
    if (field_0) {
#line 4246
        PPFX_ERROR("CPostEffect::Initialize(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    field_0 = false;
    field_2 = false;
    IGPUDevice* previous = field_40 != nullptr ? field_40 : field_18;
    bool reuse = false;
    if (previous != nullptr && field_18 != nullptr) {
        reuse = field_18->vf4(previous) >= 0;
    }
    if (field_40 == nullptr) {
        Uninitialize(previous);
    }
    u64 framebuffer;
    void* deviceArg = desc->field_0;
    if (deviceArg == nullptr) {
        if (CreateInternalResource_SiGfx(&deviceArg, desc) < 0) {
            return 1;
        }
        framebuffer = Unk_423160(desc->field_60, desc->field_68, field_11a8);
#line 4295
        PPFX_LOG("CPostEffect::Initialize(): Create initGpuDeviceFramebuffer succeeded.\n");
    } else {
        framebuffer = desc->field_8;
    }
    field_40 = nullptr;
    if (param != nullptr) {
        field_2b8 = *static_cast<const PFX_INITPARAM*>(param);
    } else {
        field_2b8 = PFX_INITPARAM();
    }
    field_d8.clear();
    field_f0.clear();
    field_108.clear();
    field_400_param = field_2b8;
    field_2b0 = flags;
    field_2b4 = flags;
    field_6a8 = 0;
    field_6ac = 0;
    Unk_SetRenderSceneHeightReverse_Gcm(this, false);
    if (static_cast<s32>(glareQuality) < 0) {
#line 4384
        PPFX_ERROR("CPostEffect::Initialize(): Argment iGlareQuality must be greater than or equal to 0.\n");
        return -6;
    }
    if (field_540 == 1 || field_540 == 2) {
        field_53c = true;
    }

    // one of bits 0 to 3 (all of them when none is given: the lowest)
    if ((field_2b4 & 0xf) == 0) {
        field_2b4 |= 0xf;
    }
    if (field_2b4 & 1) {
        field_2b4 = (field_2b4 & ~0xfu) | 1;
    } else if (field_2b4 & 2) {
        field_2b4 = (field_2b4 & ~0xfu) | 2;
    } else if (field_2b4 & 4) {
        field_2b4 = (field_2b4 & ~0xfu) | 4;
    } else if (field_2b4 & 8) {
        field_2b4 = (field_2b4 & ~0xfu) | 8;
    }
    // and one of bits 4 to 6
    bool given = (field_2b4 & 0x70) != 0;
    if (!given) {
        field_2b4 |= 0x70;
    }
    switch (field_2b4 & 0xf) {
    case 1:
        if (field_2b4 & 0x10) {
            field_2b4 = (field_2b4 & ~0x70u) | 0x10;
        } else if (field_2b4 & 0x20) {
            field_2b4 = (field_2b4 & ~0x70u) | 0x20;
        } else if (field_2b4 & 0x40) {
            field_2b4 = (field_2b4 & ~0x70u) | 0x40;
        }
        break;
    case 2:
    case 4:
    case 8:
        if (field_2b4 & 0x40) {
            field_2b4 = (field_2b4 & ~0x70u) | 0x40;
        } else if (field_2b4 & 0x20) {
            field_2b4 = (field_2b4 & ~0x70u) | 0x20;
        } else if (field_2b4 & 0x10) {
            field_2b4 = (field_2b4 & ~0x70u) | 0x10;
        }
        break;
    }
    if (!given && (field_2b4 & 0x40)) {
        field_2b4 |= 0x80;
    }
    if (!(field_2b4 & 0x40)) {
        field_2b4 &= ~0x80u;
    }
    if (field_540 == 2) {
        field_2b4 |= 0x400;
    }
    if (field_400 < 1) {
#line 4592
        PPFX_ERROR("CPostEffect::Initialize(): PFX_INITPARAM::m_nEffectViews must be greater than or equal to 0.\n");
        return -6;
    }
    field_440 = std::max(std::min(field_2b8.field_40, 16), 0);
    if (field_2b4 & 0x40000) {
        field_444 = std::max(field_444, 1);
    }
    if (field_2b4 & 0x80000) {
        field_444 = std::max(field_444, 2);
    }
    if (field_1c7) {
        field_444 = std::max(field_444, 1);
    }
    field_1bf = (field_2b4 >> 18) & 1;
    field_1bc = false;
    field_1bd = false;
    field_d40 = false;
    field_d70 = nullptr;
    if (field_2b4 & 0x40000) {
        field_1bc = true;
        if ((field_2b4 & 0x200000) || field_504 != 0) {
            field_1bd = true;
        }
    }
    field_1c3 = (field_2b4 >> 26) & 1;
    field_1c2 = (field_2b4 >> 26) & 1;
    field_1c1 = true;
    field_1c4 = (field_2b4 >> 18) & 1;
    field_1c5 = (field_2b4 >> 18) & 1;
    field_1b9 = (field_2b4 >> 18) & 1;
    field_1ba = (field_2b4 >> 18) & 1;
    field_1d1 = (field_2b4 >> 18) & 1;
    field_1d2 = (field_2b4 >> 13) & 1;
    field_1ca = false;
    field_1c8 = false;
    field_1c9 = false;
    if (field_2b4 & 0x8000000) {
        field_1c8 = true;
        if (static_cast<s32>(field_544) < 0) {
            field_544 = 1;
        }
        if (field_544 & 2) {
            field_1ca = true;
        }
        field_1c9 = true;
    }
    field_1bb = (field_2b4 >> 18) & 1;
    field_1c0 = (field_2b4 >> 18) & 1;
    field_1cb = (field_2b4 >> 18) & 1;
    field_1d0 = (field_2b4 >> 18) & 1;
    field_1cc = (field_2b4 >> 15) & 1;
    field_1cd = (field_2b4 >> 10) & 1;
    field_1cf = (field_2b4 >> 10) & 1;
    field_1d3 = false;
    if (field_2b4 & 0x800) {
        field_1d3 = true;
        if (field_2b4 & 0x10000) {
#line 4916
            PPFX_WARNING("CPostEffect::Initialize(): PFXINIT_DEPTHTEXTURE cannot be set with PFXINIT_RENDERSCENE_EXTERNAL\n");
            return -6;
        }
    }

    // the device
    Unk_DeviceSettings settings;
    settings.field_20 = desc->field_10;
    settings.field_24 = desc->field_14;
    settings.field_28 = framebuffer;
    settings.field_18 = field_10;
    if (!reuse) {
        field_18 = IGPUDevice::CreateDevice(&settings, deviceArg);
        if (field_18 == nullptr) {
#line 4993
            PPFX_ERROR("CPostEffect::Initialize(): IGPUDevice::CreateDevice() failed.\n");
            return -2;
        }
    } else {
        s32 result = field_18->vf6(&settings);
        if (result < 0) {
#line 5006
            PPFX_ERROR("CPostEffect::Initialize(): m_pGPUDevice->Reset() failed.\n");
            Uninitialize(nullptr);
            return result;
        }
    }
    field_18->vf12(reinterpret_cast<IGPUInterface**>(&field_20));
    field_18->vf11(reinterpret_cast<IGPUInterface**>(&field_28));
#line 5044
    field_30 = UNK_NEW(IGPUPixelContainer::Unk_Desc);
    field_38 = UNK_NEW(IGPUPixelContainer::Unk_Desc);
    reinterpret_cast<IGPUPixelContainer*>(field_20)->vf8(field_30);
    if (field_28 != nullptr) {
        static_cast<IGPUPixelContainer*>(field_28)->vf8(field_38);
    } else {
        *field_38 = *field_30;
        field_38->field_0 = 0;
    }
    field_1be = false;
    if (!field_18->field_14efb && (field_2b4 & 0x100000)) {
        field_1be = true;
    }
    if (Unk_24e09e8 != nullptr && (Unk_24e09f0 & 1)) {
        Unk_24e09e8(1, Unk_24e09f8);
    }

    u32 initFlags = field_2b4;
    field_598 = (initFlags >> 1) & 1;
    field_597 = (initFlags >> 2) & 1;
    field_599 = (initFlags >> 3) & 1;
    field_59a = false;
    bool shared = false;
    if ((initFlags & 0x100) && ((initFlags & 2) || (initFlags & 4))) {
        shared = true;
        initFlags |= 0x4000;
        field_59a = true;
        field_2b4 = initFlags;
    }
    u32 width = field_2b8.field_10 != 0 ? field_2b8.field_10 : field_30->field_8;
    u32 height = field_2b8.field_14 != 0 ? field_2b8.field_14 : field_30->field_c;
    u32 width2 = field_2b8.field_18 != 0 ? field_2b8.field_18 : width;
    u32 height2 = field_2b8.field_1c != 0 ? field_2b8.field_1c : height;
    u32 x74 = (initFlags & 0x200) ? 0x500 : width;
    if (field_2b8.field_48 != 0) {
        x74 = field_448;
    }
    s32 p450 = field_450;
    s32 p480 = field_480;
    s32 p4f4 = field_4f4;
    s32 p500 = field_500;
    s32 p50c = field_50c;
    s32 p454 = field_454;
    s32 p484 = field_484;
    s32 p48c = field_48c;
    s32 p4e4 = field_4e4;
    f32 p44c = field_44c;
    f32 p47c = field_47c;
    f32 p4f0 = field_4f0;
    f32 p4fc = field_4fc;
    f32 p508 = field_508;
    f32 p4e8 = field_4e8;
    f32 aspect = field_420 > 0.0f ? field_420 : static_cast<f32>(width) / static_cast<f32>(height);
    field_420 = aspect;

    s32 sceneFormat = field_2b8.field_4;
    s32 depthFormat = field_2b8.field_8;
    s32 p2c4 = field_2b8.field_c;
    s32 p310 = field_2b8.field_58;
    s32 p314 = field_2b8.field_5c;
    s32 p3b0 = field_2b8.field_f8;
    s32 p3c8 = field_2b8.field_110;
    s32 p3cc = field_2b8.field_114;
    if (depthFormat == 0) {
        depthFormat = shared ? 0 : sceneFormat;
    }
    if (sceneFormat == 0) {
        sceneFormat = shared ? 0 : depthFormat;
    }
    u32 glareLevel = static_cast<s32>(glareQuality) < 7 ? glareQuality : 7;
    s32 dofLevel = std::min(static_cast<s32>(dofQuality), Unk_1b35154 ? 19 : 10);
    field_1b8 = dofLevel >= 0;
    field_548 = field_18->field_14ef4 && (initFlags & 0x10000);
    field_594 = (initFlags >> 17) & 1;
    bool lightShafts = (initFlags & 0x10000000) != 0;
    if (field_1c2 || field_1bc || field_1b8 || lightShafts || field_1c4 || field_1c9) {
        field_595 = field_594 || field_548;
    } else {
        field_595 = false;
    }
    field_59c = (initFlags & 2) || (initFlags & 4) || (initFlags & 8);
    field_568 = (initFlags & 0x400000) ? -1 : 0;
    field_59b = false;
    s32 aaFormat = 0x1c;
    if ((initFlags & 0x4000) && field_59c) {
        field_59b = true;
        aaFormat = 0x1d;
    }
    if (field_59c) {
        field_59d = !(initFlags & 4);
        field_59e = !(initFlags & 2);
    } else {
        field_59d = false;
        field_59e = false;
    }
    field_596 = field_53c;
    field_59f = false;
    if (initFlags & 4) {
        field_596 = true;
        field_59f = true;
    }
    bool external = field_53c || field_1d3 || shared;
    if (field_1d3 || shared) {
        field_596 = true;
    }
    s32 bufferFormat = sceneFormat;
    if (depthFormat != 0 && sceneFormat == 0) {
        bufferFormat = 0;
        if (!shared && !(initFlags & 4)) {
            bufferFormat = depthFormat;
            if (field_595) {
                s32 bits = static_cast<s32>(Unk_446ae0(depthFormat));
                if (static_cast<u32>(depthFormat - 0x18) < 3 || bits < 4 || !Unk_423480(depthFormat)) {
                    bufferFormat = 0;
                }
            }
        }
    }
    s32 dofA = field_488 >= 0 ? field_488 : Unk_24e1098[dofLevel].field_8;
    s32 dofB = field_4cc >= 0 ? field_4cc : Unk_24e1098[dofLevel].field_c;
    if (!Unk_1b35154) {
        dofB = 0;
    }
    field_4cc = dofB;
    if (field_2b4 & 0x20000000) {
        if (!(field_428 > 0.0f)) {
            field_428 = 1.5f;
        }
        if (!(field_424 > 0.0f)) {
            field_424 = 4.0f / 3.0f;
        }
    }
    if (field_2b4 & 0x40000000) {
        if (!(field_42c > 0.0f)) {
            field_42c = 2.0f / 3.0f;
        }
    }
    if (!(field_428 > 0.0f)) {
        field_428 = 1.0f;
    }
    if (!(field_424 > 0.0f)) {
        field_424 = 1.0f;
    }
    if (!(field_42c > 0.0f)) {
        field_42c = 1.0f;
    }
    field_478 = field_478 == 0 ? 1 : std::min(field_478, 16u);
    if (lightShafts) {
#line 5830
        field_858 = UNK_NEW_ARRAY(Unk_423990_Item, field_478);
    } else {
        field_478 = 0;
    }
    bool lightGhosts = field_524 != 0;
    field_524 = std::min(static_cast<u32>(field_524), 16u);
    if (lightGhosts) {
#line 5841
        field_868 = UNK_NEW_ARRAY(Unk_423ba0_Item, field_524);
    }
    u32 msaaType;
    s32 msaaQuality;
    Unk_446eb0(field_2b8.field_38, field_2b8.field_3c, &msaaType, &msaaQuality);
    field_1168 = 0;
    field_128 = 0;
    field_130 = 0;
    field_120 = nullptr;
    if (!reuse) {
        Unk_GetTextureUtil();
    }
#line 5875
    field_190 = reinterpret_cast<Unk_4a5d10_Self*>(UNK_NEW(CRenderTextureArray)("CPostEffect::m_pRenderBuffer"));
#line 5876
    field_198 = reinterpret_cast<Unk_45eb90_Self*>(UNK_NEW(CRenderGlare)("CPostEffect::m_pRenderGlare"));
    if (field_1cc) {
#line 5880
        field_1b0 = reinterpret_cast<Unk_4a5d10_Self*>(UNK_NEW(CRenderTextureArray)("CPostEffect::m_pGlareModulatorWork"));
    }
    if (field_1cf) {
#line 5885
        field_1a8 = UNK_NEW(CRenderTextureArray)("CPostEffect::m_pEffectColorAlphaDestinationWork");
    }
#line 5892
    field_1a0 = reinterpret_cast<Unk_4aa5a0_Self*>(UNK_NEW(CDepthOfField)("CPostEffect::m_pDepthOfField"));
    UNK_DELETE_ARRAY(field_2a0);
    UNK_DELETE_ARRAY(field_2a8);
#line 5900
    field_2a0 = UNK_NEW_ARRAY(Unk_429da0_Item, field_400);
#line 5901
    field_2a8 = UNK_NEW_ARRAY(Unk_429e60_Item, field_400);
    for (s32 i = 0; i < field_400; i++) {
#line 5905
        field_2a0[i].field_70 = UNK_NEW(CTextureLuminanceManage)(
            (Unk_4529a0("CPostEffect::m_pAutoExposureParam[", Unk_4525a0(i)) + "].m_pQuerySceneLuminance").field_8);
#line 5908
        field_2a8[i].field_48 = UNK_NEW(CTextureLuminanceManage)(
            (Unk_4529a0("CPostEffect::m_pAutoFocusParam[", Unk_4525a0(i)) + "].m_pQuerySceneDepth").field_8);
    }
#line 5928
    field_290 = UNK_NEW_ARRAY(s32, field_400);
    for (s32 i = 0; i < field_400; i++) {
        field_290[i] = 0;
    }
    Unk_238d258 = 0;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->field_29a60 = false;
    util->field_29ab0 = field_1c1;
    util->field_29ad0 = field_1ca;
    util->field_29ae8 = field_51c;
    util->field_29aec = field_400;
    util->field_29c00 = field_524 != 0 ? field_520 : 0;
    util->field_29c04 = field_524 != 0 ? field_400 : 0;
    s32 result = Unk_24e0c30->vf0(field_18);
    if (result < 0) {
#line 5983
        PPFX_ERROR("CPostEffect::Initialize(): CSingleTextureUtil::InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        field_18->vf7(0, reinterpret_cast<void*>(field_20), 0);
        field_18->vf8(field_28);
        return result;
    }
#line 5989
    PPFX_LOG("CPostEffect::Initialize(): CSingleTextureUtil::InitializeDevice() succeeded.\n");
    if (Unk_24e09e8 != nullptr && (Unk_24e09f0 & 2)) {
        Unk_24e09e8(2, Unk_24e09f8);
    }

    // the render buffer's formats
    u32 textureFlags = field_548 ? 0x30000 : 0x10000;
    if (field_59d) {
        if (bufferFormat == 0) {
            bufferFormat = aaFormat;
        }
    } else if (bufferFormat == 0) {
        const s32 formats[6] = {0xa, 0xa, 0x2, 0xb, 0x18, 0x1c};
        bufferFormat = Unk_442bc0(field_18, (field_2b4 & 0x1000) ? 0x80001 : 1, 3, formats, 6, 0xa);
    }
    if (p310 == 0) {
        p310 = (initFlags & 0x60) == 0x40 ? 0x18 : 0x1a;
        if (p310 != 0x18 || static_cast<s32>(Unk_446ae0(p310)) <= 4) {
            field_18->vf75(0x20001, 3, p310);
        }
    }
    if (p314 == 0 && (initFlags & 0x20)) {
        const s32 formats[1] = {0x18};
        p314 = Unk_442bc0(field_18, 0x20001, 3, formats, 1, 0x18);
    }
    if (p314 == 0) {
        switch (p310) {
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
        case 0x20:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x57:
        case 0x58:
        case 0x5b:
        case 0x5d:
            p314 = field_59b ? 0x1d : 0;
            break;
        }
    }
    if (depthFormat != bufferFormat && depthFormat != 0 && bufferFormat != 0) {
        field_596 = true;
    }
    bool sameSize = width2 == width && height2 == height;
    s32 depthTarget = p2c4 == 0 ? 0x7fffffff : p2c4;
    if (!sameSize) {
        external = true;
        field_596 = true;
    } else if (!field_596) {
        u32 tileWidth = width;
        u32 tileHeight = height;
        s32 tileFormats[4] = {bufferFormat, 0, 0, 0};
        if (Unk_446e20(&tileWidth, &tileHeight, width, height, 1, tileFormats, p2c4, msaaType, 0) >= 2) {
            field_596 = true;
        }
    }
    if (field_595) {
        if (field_18->vf75(0x80001, 3, depthFormat != 0 ? depthFormat : bufferFormat) < 0 &&
            !field_18->field_14ef0) {
            external = true;
            field_596 = true;
        }
    }
    if (field_1cc && field_18->field_14efa) {
        field_596 = true;
    }
    field_5a0 = false;
    // whether the scene is drawn to the render buffer itself (direct), and
    // whether its copy is the first texture (alias)
    bool direct;
    bool alias;
    if (!field_596) {
        direct = true;
        alias = false;
    } else if (field_1c2 || field_1b8 || field_1b9 || field_1bb || field_1bc || field_1bf || field_1c0 || field_1c4 ||
               field_1c6 || field_1c8) {
        direct = false;
        alias = false;
    } else if (width2 > width || field_1cb) {
        direct = true;
        alias = true;
    } else if (height2 > height || field_1d3 || field_59f) {
        direct = false;
        alias = false;
    } else {
        field_5a0 = true;
        direct = false;
        alias = true;
    }
    field_5d8 = 0;
    field_5dc = field_440 != 0;
    s32 index = direct || alias ? 0 : field_440 + 1;
    s32 count = field_440 + 1;
    field_5e0 = index;
    field_680 = 0;
    field_684 = 0;
    field_688 = 0;
    field_68c = 0;
    field_694 = 0;
    field_5e4 = index;
    if (!direct && !alias) {
        count = field_440 + 2;
    }
    field_5a1 = false;
    if (field_1b8) {
        field_5a1 = field_18->field_14ef0;
        if (static_cast<u32>(dofB - 5) <= 2 && Unk_4b72b0_get()) {
            field_5a1 = false;
        }
        s32 levels = field_5a1 ? 0 : 1;
        if (static_cast<u32>(dofB - 5) <= 2 && Unk_4b72b0_get()) {
            levels++;
        }
        field_444 = std::max(field_444, levels);
    }
    if (field_444 >= 1) {
        count += field_444;
        u32 last = field_5e0;
        if (field_440 != 0) {
            last = std::max(last, field_440 + field_5dc - 1);
        }
        field_5e4 = last + 1;
    }
    s32 copyFormat = 0;
    s32 altFormat = 0;
    bool sameTarget = false;
    if (field_596) {
        bool antialiased = false;
        if (field_599) {
            if (depthFormat == 0) {
                depthFormat = aaFormat;
            }
            antialiased = true;
        } else if (depthFormat == 0) {
            if (field_59a) {
                const s32 formats[6] = {0xa, 0xa, 0x2, 0xb, 0x18, 0x1c};
                depthFormat = Unk_442bc0(field_18, (field_2b4 & 0x1000) ? 0x80001 : 1, 3, formats, 6, 0xa);
            } else {
                depthFormat = bufferFormat;
            }
        }
        if (field_596) {
            copyFormat = depthFormat;
            if (!external) {
                sameTarget = sameSize && depthFormat == bufferFormat && !antialiased;
            }
        }
    } else {
        altFormat = depthFormat;
    }

    // the render buffer's textures
    Unk_49ab20_Desc descs[20];
    if (!field_5a0) {
        Unk_49ab20_Desc& desc = descs[static_cast<u32>(field_5e0)];
        desc.field_0 = field_596 ? 0x40000 : 0x100;
        desc.field_4 = width;
        desc.field_8 = height;
        desc.field_c = bufferFormat;
        desc.field_10 = 1;
        desc.field_14 = field_596 ? 0 : msaaType;
        desc.field_18 = field_596 ? 0 : msaaQuality;
        desc.field_1c = altFormat;
        desc.field_20 = false;
    }
    if (field_596) {
        Unk_49ab20_Desc& desc = descs[static_cast<u32>(field_5d8)];
        desc.field_0 = 0x100;
        desc.field_4 = width2;
        desc.field_8 = height2;
        desc.field_c = copyFormat;
        desc.field_10 = 1;
        desc.field_14 = msaaType;
        desc.field_18 = msaaQuality;
        desc.field_1c = depthFormat;
        desc.field_20 = false;
        if (field_1d3) {
            desc.field_0 = 0x80000100;
        }
    }
    for (s32 i = 0; i < field_440; i++) {
        descs[field_5dc + i] = descs[static_cast<u32>(field_5d8)];
    }
    if (field_5e4 != field_5e0) {
        for (u32 i = field_5e4; i < static_cast<u32>(count); i++) {
            descs[i] = descs[static_cast<u32>(field_5e0)];
            descs[i].field_0 = (descs[i].field_0 & ~0x100u) | 0x40000;
            descs[i].field_14 = 0;
            descs[i].field_18 = 0;
        }
    }
    // the sample counts the device supports for each
    for (s32 i = 0; i < count; i++) {
        Unk_49ab20_Desc& desc = descs[i];
        if (desc.field_0 & 0x80000000) {
            continue;
        }
        s32 format = desc.field_1c != 0 ? desc.field_1c : desc.field_c;
        s32 depth = depthTarget;
        if (depth == 0x7fffffff) {
            depth = field_38->field_0 != 0 ? field_38->field_0 : 0x2d;
        }
        while (desc.field_14 != 0) {
            if (field_18->vf74(format, desc.field_14, desc.field_18) >= 0 &&
                field_18->vf74(depth, desc.field_14, desc.field_18) >= 0) {
                break;
            }
            if (desc.field_18 != 0) {
                desc.field_18--;
            } else {
                desc.field_14--;
            }
        }
        if (desc.field_14 == 0) {
            desc.field_18 = 0;
        }
    }
    field_6a8 = descs[static_cast<u32>(field_5d8)].field_c;
    field_6ac = descs[static_cast<u32>(field_5d8)].field_1c != 0 ? descs[static_cast<u32>(field_5d8)].field_1c
                                                                  : descs[static_cast<u32>(field_5d8)].field_c;
    result = reinterpret_cast<CRenderTextureArray*>(field_190)->Initialize(count, descs, depthTarget, false, textureFlags);
    if (result < 0) {
#line 7085
        PPFX_ERROR("CPostEffect::Initialize(): m_pRenderBuffer->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
        Uninitialize(nullptr);
        return result;
    }
#line 7093
    PPFX_LOG("CPostEffect::Initialize(): m_pRenderBuffer->Initialize() succeeded.\n");
    CRenderTextureArray* renderBuffer = reinterpret_cast<CRenderTextureArray*>(field_190);
    if (sameTarget) {
        CRenderTexture* scene = renderBuffer->Unk_Texture(field_5e0);
        CRenderTexture* copy = renderBuffer->Unk_Texture(field_5d8);
        scene->field_100 = reinterpret_cast<u64>(copy);
        scene->field_108.push_back(copy);
        copy->field_100 = reinterpret_cast<u64>(scene);
        copy->field_108.push_back(scene);
    }
    // the temporal antialias's history, one per view
    if (field_1be) {
#line 7149
        field_238 = reinterpret_cast<Unk_RenderTexture**>(UNK_NEW_ARRAY(CRenderTexture*, field_400));
        memset(field_238, 0, field_400 * sizeof(CRenderTexture*));
#line 7151
        field_240 = UNK_NEW_ARRAY(f32, field_400);
#line 7152
        field_248 = UNK_NEW_ARRAY(f32, field_400);
#line 7153
        field_250 = UNK_NEW_ARRAY(f32, field_400);
#line 7154
        field_258 = UNK_NEW_ARRAY(Unk_Rect, field_400);
        for (s32 i = 0; i < field_400; i++) {
            Unk_TFXString name = Unk_TFXString("CPostEffect::m_ppTemporalAntialias_History") + '[' + Unk_4525a0(i) + ']';
#line 7168
            field_238[i] = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)(name.field_8));
            reinterpret_cast<CRenderTexture*>(field_238[i])->Unk_Create(0x400, width, height, bufferFormat);
        }
    }
    // the render buffer's reductions
    field_558 = 0;
    if (field_5d8 == field_5e0) {
        field_550 = nullptr;
    } else {
        CRenderTexture* source = renderBuffer->Unk_Texture(field_5d8);
        CRenderTexture* scene = renderBuffer->field_38[field_5e0 == -1 ? renderBuffer->field_90 : field_5e0];
        f32 scaleX = static_cast<f32>(static_cast<u32>(scene->field_54 + 1)) / static_cast<f32>(static_cast<u32>(source->field_54));
        f32 scaleY = static_cast<f32>(static_cast<u32>(scene->field_58 + 1)) / static_cast<f32>(static_cast<u32>(source->field_58));
        s32 levels = static_cast<s32>(ceilf(logf(scaleX > scaleY ? scaleX : scaleY) / logf(0.5f)));
        field_558 = std::max(levels - 1, 0);
        field_550 = nullptr;
        if (levels >= 2) {
            CTextureUtil* pool = Unk_GetTextureUtil();
            Unk_ReleaseTextureUtil();
#line 7216
            field_550 = reinterpret_cast<Unk_RenderTexture**>(UNK_NEW_ARRAY(CRenderTexture*, field_558));
            memset(field_550, 0, field_558 * sizeof(CRenderTexture*));
            CRenderTexture* texture = renderBuffer->Unk_Texture(field_5d8);
            u32 w = texture->field_54;
            u32 h = texture->field_58;
            for (s32 i = 0; i < field_558; i++) {
                w = static_cast<u32>(static_cast<f32>(w) * 0.5f + 0.99f);
                h = static_cast<u32>(static_cast<f32>(h) * 0.5f + 0.99f);
                pool->field_29a58->Unk_49fc10(reinterpret_cast<CRenderTexture**>(&field_550[i]), w, h,
                                             texture->field_2c.field_c, false, 0, 0);
            }
        }
    }
    if (field_568 < 0) {
        CRenderTexture* scene = renderBuffer->field_38[field_5e0 == -1 ? renderBuffer->field_90 : field_5e0];
        field_568 = std::max(static_cast<s32>(ceilf(logf(16.0f / static_cast<f32>(static_cast<u32>(scene->field_54))) / logf(0.5f))) - 1, 0);
    }
    field_560 = nullptr;
    if (field_568 != 0) {
        CTextureUtil* pool = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
#line 7281
        field_560 = UNK_NEW_ARRAY(Unk_RenderTexturePair, field_568);
        memset(field_560, 0, field_568 * sizeof(Unk_RenderTexturePair));
        CRenderTexture* texture = renderBuffer->Unk_Texture(field_5e0);
        u32 w = texture->field_54;
        u32 h = texture->field_58;
        for (s32 i = 0; i < field_568; i++) {
            w = static_cast<u32>(static_cast<f32>(w) * 0.5f + 0.99f);
            h = static_cast<u32>(static_cast<f32>(h) * 0.5f + 0.99f);
            pool->field_29a58->AllocateTextures(2, reinterpret_cast<CRenderTexture**>(&field_560[i]), w, h,
                                                texture->field_2c.field_c, true, 0, 0);
        }
    }
    // the OETF's scene luminance
    field_580 = 0;
    if (field_1d2) {
        s32 shorter = std::min(width, height);
        u32 size = static_cast<s32>(ldexp(1.0, static_cast<s32>(log(shorter) / log(2.0))));
        size = size == 0 ? 1 : std::min(size, 0x400u);
        f32 fsize = static_cast<f32>(size);
        field_580 = static_cast<s32>(logf(fsize) / logf(2.0f) + -2.0f + 0.99f);
        s32 steps = static_cast<s32>(logf(fsize) / logf(4.0f));
        field_570 = nullptr;
        field_578 = nullptr;
        field_580 = std::max(field_580 - std::min(steps - 1, 3), 1);
        if (field_580 != 0) {
#line 7375
            field_570 = UNK_NEW_ARRAY(CRenderTexture*, field_400);
#line 7379
            field_588 = UNK_NEW_ARRAY(CTextureLuminanceManage*, field_400);
            for (s32 i = 0; i < field_400; i++) {
#line 7388
                field_570[i] = UNK_NEW(CRenderTexture)(
                    (Unk_4529a0("CPostEffect::m_ppOetfSceneLuminanceBaseWork[", Unk_4525a0(i)) + ']').field_8);
                field_570[i]->Unk_Create(0x400, size, size, 0x1a);
#line 7397
                field_588[i] = UNK_NEW(CTextureLuminanceManage)(
                    (Unk_4529a0("CPostEffect::m_ppOetfQuerySceneLuminance[", Unk_4525a0(i)) + ']').field_8);
                CTextureLuminanceManage::Unk_Desc desc;
                desc.field_0 = 4;
                desc.field_4 = 1;
                desc.field_8 = 1;
                desc.field_c = 0;
                field_588[i]->Unk_4b87d0(&desc);
            }
#line 7409
            field_578 = UNK_NEW_ARRAY(CRenderTexture*, field_580);
            u32 w = size;
            u32 h = size;
            for (s32 i = 0; i < field_580; i++) {
                u32 half = w >> 1;
                if (half == 8 || half == 0x80 || half == 0x20) {
                    w >>= 2;
                    h >>= 2;
                } else {
                    w = half;
                    h >>= 1;
                }
                w = w > 1 ? w : 1;
                h = h > 1 ? h : 1;
                util->field_29a58->Unk_49fc10(&field_578[i], w, h, 0x1a, true, 0, 0);
            }
        }
    } else {
        field_578 = nullptr;
        field_570 = nullptr;
    }

    // the glare
    const Unk_ScaleLevel* glareLevels = Unk_24e09e0 ? Unk_24e0e68 : Unk_24e0e28;
    f32 glareScale = p44c > 0.0f ? p44c : glareLevels[glareLevel].field_0.field_0;
    f32 sceneAspect = field_420 / field_428;
    if (sceneAspect < aspect) {
        glareScale *= sceneAspect / aspect;
    }
    u32 glareWidth = static_cast<u32>(glareScale * static_cast<f32>(x74) + 0.99f);
    glareWidth = x74 > glareWidth ? glareWidth : x74;
    glareWidth = glareWidth < width ? glareWidth : width;
    if (p450 != 0) {
        glareWidth = p450;
    }
    s32 glareLines = p454 != 0 ? p454 : glareLevels[glareLevel].field_4;
    u32 glareHeight = static_cast<u32>(static_cast<f32>(glareWidth) / sceneAspect + 0.499999f);
    if (glareWidth < 16 || glareHeight < 16) {
        if (glareWidth < glareHeight) {
            glareWidth = 16;
            glareHeight = static_cast<u32>(16.0f / sceneAspect + 0.499999f);
        } else {
            glareHeight = 16;
            glareWidth = static_cast<u32>(sceneAspect * 16.0f + 0.499999f);
        }
    }
    Unk_453_30 glare;
    glare.field_0 = 0;
    glare.field_4 = width;
    glare.field_8 = height;
    glare.field_c = glareWidth;
    glare.field_10 = glareHeight;
    glare.field_18_f[0] = field_460;
    glare.field_18[1] = field_464 != 0 ? field_464 : width >> 1;
    glare.field_18[2] = p310;
    glare.field_18[3] = p314;
    glare.field_18[4] = bufferFormat;
    glare.field_18[5] = glareLines;
    glare.field_18[10] = field_46c;
    glare.field_18_f[11] = field_470;
    glare.field_48 = field_468;
    glare.field_49 = field_469;
    glare.field_4a = (field_2b4 >> 7) & 1;
    glare.field_4c = field_400;
    glare.field_50 = true;
    glare.field_54 = 2;
    glare.field_58 = lightShafts;
    glare.field_5c = field_478;
    Unk_GlareGhosts* ghosts = reinterpret_cast<Unk_GlareGhosts*>(&glare.field_60);
    ghosts->field_0 = lightGhosts;
    ghosts->field_4 = field_524;
    glare.field_68 = reinterpret_cast<u64>(&field_528);
    glare.field_70 = field_1b9;
    glare.field_71 = field_1cc;
    glare.field_74 = field_420 / field_424;
    glare.field_78 = field_42c / field_424;
    glare.field_7c = (field_2b4 >> 18) & 1;
    result = reinterpret_cast<CRenderGlare*>(field_198)->Initialize(&glare);
    if (result < 0) {
#line 7675
        PPFX_ERROR("CPostEffect::Initialize(): m_pRenderGlare->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
        Uninitialize(nullptr);
        return result;
    }
#line 7682
    PPFX_LOG("CPostEffect::Initialize(): m_pRenderGlare->Initialize() succeeded.\n");
    if (field_1cc) {
        Unk_49ab20_Desc workDescs[20];
        s32 sourceFormat;
        s32 format;
        if (field_474 != 0) {
            sourceFormat = field_474;
            format = field_474;
        } else {
            CRenderTexture* copy = renderBuffer->Unk_Texture(field_5d8);
            sourceFormat = copy != nullptr ? copy->field_2c.field_c : field_6a8;
            format = renderBuffer->field_38[field_5e0 == -1 ? renderBuffer->field_90 : field_5e0]->field_2c.field_c;
        }
        u32 workWidth = renderBuffer->field_38[field_5e0 == -1 ? renderBuffer->field_90 : field_5e0]->field_54 >> 1;
        u32 workHeight = renderBuffer->field_38[field_5e0 == -1 ? renderBuffer->field_90 : field_5e0]->field_58 >> 1;
        workDescs[0].field_1c = sourceFormat;
        workDescs[0].field_c = format;
        workDescs[0].field_4 = std::max(workWidth, field_198->field_bc);
        workDescs[0].field_8 = std::max(workHeight, field_198->field_c0);
        result = reinterpret_cast<CRenderTextureArray*>(field_1b0)->Initialize(1, workDescs, 0, false, 0);
        if (result < 0) {
#line 7744
            PPFX_ERROR("CPostEffect::Initialize(): m_pGlareModulatorWork->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 7752
        PPFX_LOG("CPostEffect::Initialize(): m_pGlareModulatorWork->Initialize() succeeded.\n");
    }
    if (field_1cf) {
        Unk_49ab20_Desc workDesc(0, field_30->field_8, field_30->field_c, field_30->field_0);
        result = field_1a8->Initialize(field_540 == 2 ? 2 : 1, &workDesc, 0, true, 0);
        if (result < 0) {
#line 7781
            PPFX_ERROR("CPostEffect::Initialize(): m_pEffectColorAlphaDestinationWork->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 7789
        PPFX_LOG("CPostEffect::Initialize(): m_pEffectColorAlphaDestinationWork->Initialize() succeeded.\n");
    }

    // the depth of field
    if (field_1b8) {
        const Unk_DofQuality& quality = Unk_24e1098[dofLevel];
        f32 dofScale = p47c > 0.0f ? p47c : quality.field_0.field_0;
        f32 dofAspect = field_420 / field_42c;
        if (field_430) {
            if (dofAspect > aspect) {
                dofScale *= dofAspect / aspect;
            }
        } else {
            dofScale *= sqrtf(dofAspect / aspect);
        }
        u32 dofWidth = static_cast<u32>(dofScale * static_cast<f32>(x74) + 0.99f);
        dofWidth = x74 > dofWidth ? dofWidth : x74;
        dofWidth = dofWidth < width ? dofWidth : width;
        if (p480 != 0) {
            dofWidth = p480;
        }
        s32 dofLevels = p484 != 0 ? p484 : quality.field_4;
        s32 pairs = quality.field_10 < 0 ? 9 : quality.field_10;
        if (p48c >= 0) {
            pairs = p48c;
        }
        if (field_490 >= 0) {
            pairs = -2;
        }
        if (pairs == 8 && static_cast<u32>(dofB - 5) < 3) {
            pairs = 7;
        }
        f32 dofFactor = p4e8 > 0.0f ? p4e8 : quality.field_18.field_0;
        bool p4ec = field_4ec;
        s32 dofSize = p4e4 != 0 ? p4e4 : quality.field_14;
        u32 dofHeight = static_cast<u32>(static_cast<f32>(dofWidth) / dofAspect + 0.499999f);
        if (dofWidth < 16 || dofHeight < 16) {
            if (dofWidth < dofHeight) {
                dofWidth = 16;
                dofHeight = static_cast<u32>(16.0f / dofAspect + 0.499999f);
            } else {
                dofHeight = 16;
                dofWidth = static_cast<u32>(dofAspect * 16.0f + 0.499999f);
            }
        }
        s32 format = field_4c8 != 0 ? field_4c8 : bufferFormat;
        s32 dofFormat = 0;
        if ((!field_597 || Unk_IsDofFormat(format)) && format != 0) {
            dofFormat = field_18->vf75(0x20001, 3, format) < 0 ? 0 : format;
        }
        if (field_4cc == 0) {
            Unk_442c50_get(reinterpret_cast<u64>(field_18));
        }
        CDepthOfField::Unk_Desc desc;
        desc.field_0[0] = 0;
        desc.field_0[1] = dofWidth;
        desc.field_0[2] = dofHeight;
        desc.field_0[3] = GetEffectDofEdgeQualityTypeFromEdgeQualityType(dofA);
        desc.field_10 = dofLevels;
        desc.field_14 = dofFormat;
        desc.field_18 = Unk_DofQualityLevel(dofB);
        desc.field_1c = pairs;
        if (pairs >= 0) {
            desc.field_1c = -1;
            for (s32 i = 0; i < 7; i++) {
                desc.field_20[i * 2] = Unk_24e12c8[pairs][i].field_0;
                desc.field_20[i * 2 + 1] = Unk_24e12c8[pairs][i].field_4;
            }
        } else {
            for (s32 i = 0; i < 14; i++) {
                desc.field_20[i] = (&field_490)[i];
            }
        }
        desc.field_58 = -1;
        desc.field_5c = dofSize;
        desc.field_60 = dofFactor;
        desc.field_64 = p4ec;
        desc.field_65 = true;
        desc.field_68 = 2;
        desc.field_6c = field_18->field_14ef0;
        if (static_cast<u32>(dofB - 5) <= 2) {
            desc.field_6d = true;
            desc.field_70 = 2;
            if (dofB == 7) {
                desc.field_70 = 1;
            } else if (dofB == 6) {
                desc.field_70 = 0;
            }
        }
        desc.field_74 = field_420 / field_424;
        desc.field_78 = field_42c / field_424;
        desc.field_7c = field_4d0;
        desc.field_80 = field_4d4;
        desc.field_84 = false;
        desc.field_88 = field_4d8;
        desc.field_8c = field_4dc;
        desc.field_90 = field_4e0;
        result = reinterpret_cast<CDepthOfField*>(field_1a0)->Initialize(renderBuffer->Unk_Texture(field_5e0), &desc);
        if (result < 0) {
#line 8186
            PPFX_ERROR("CPostEffect::Initialize(): m_pDepthOfField->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 8193
        PPFX_LOG("CPostEffect::Initialize(): m_pDepthOfField->Initialize() succeeded.\n");
    }

    // the motion blur
    f32 fx74 = static_cast<f32>(x74);
    u32 blurWidth = static_cast<u32>((p4fc > 0.0f ? p4fc : 0.5f) * fx74 + 0.99f);
    if (p500 != 0) {
        blurWidth = p500;
    }
    if (blurWidth < x74) {
        u32 blurHeight = static_cast<u32>(static_cast<f32>(blurWidth) / aspect + 0.499999f);
#line 8214
        field_1e8 = reinterpret_cast<Unk_4a5d10_Self*>(UNK_NEW(CRenderTextureArray)("CPostEffect::m_pMotionBlurReducedWork"));
        Unk_49ab20_Desc desc;
        desc.field_4 = blurWidth;
        desc.field_8 = height > blurHeight ? blurHeight : height;
        CRenderTexture* copy = renderBuffer->Unk_Texture(field_5d8);
        desc.field_1c = copy != nullptr ? copy->field_2c.field_c : field_6a8;
        desc.field_c = renderBuffer->field_38[field_5e0 == -1 ? renderBuffer->field_90 : field_5e0]->field_2c.field_c;
        result = reinterpret_cast<CRenderTextureArray*>(field_1e8)->Initialize(2, &desc, 0, true, 0);
        if (result < 0) {
#line 8231
            PPFX_ERROR("CPostEffect::Initialize(): m_pMotionBlurReducedWork->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 8239
        PPFX_LOG("CPostEffect::Initialize(): m_pMotionBlurReducedWork->Initialize() succeeded.\n");
    }
    if (static_cast<s32>(field_504) < 0) {
        if (field_1bd) {
            field_504 |= 1;
        } else {
            field_504 = 0;
        }
    } else if (!field_1bd && field_504 != 0) {
        field_504 = 0;
#line 8271
        PPFX_WARNING("CPostEffect::Initialize():\n\tFor using m_effectParam.m_uiVelocityDilationType,\n\tPFXINIT_MOTIONBLUR_INTERNALVELOCITYTEXTURE must be set at Initialize().\n");
    }
    field_d48 = field_504 & 1;
    if (field_1bd) {
        u32 velocityWidth = static_cast<u32>((p4f0 > 0.0f ? p4f0 : 0.5f) * fx74 + 0.99f);
        velocityWidth = x74 > velocityWidth ? velocityWidth : x74;
        if (p4f4 != 0) {
            velocityWidth = p4f4;
        }
        u32 velocityHeight = static_cast<u32>(static_cast<f32>(velocityWidth) / aspect + 0.499999f);
        velocityHeight = height > velocityHeight ? velocityHeight : height;
        s32 velocityFormat = p3b0 != 0 ? p3b0 : 0x18;
#line 8325
        field_1d8 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pMotionBlurInternalVelocityTexture"));
        result = reinterpret_cast<CRenderTexture*>(field_1d8)->Unk_Create(0, velocityWidth, velocityHeight, velocityFormat);
        if (result < 0) {
#line 8341
            PPFX_ERROR("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityTexture->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
        bool reduced = false;
        if (field_1e8 != nullptr) {
            CRenderTexture* work = reinterpret_cast<CRenderTexture*>(field_1e8->field_38[field_1e8->field_90]);
            if (velocityWidth > static_cast<u32>(work->field_54)) {
                velocityWidth = work->field_54;
                velocityHeight = work->field_58;
                reduced = true;
            }
        }
        if (reduced || field_d48 == 1) {
#line 8371
            field_1e0 = reinterpret_cast<Unk_4a5d10_Self*>(UNK_NEW(CRenderTextureArray)("CPostEffect::m_pMotionBlurInternalVelocityReducedWork"));
            Unk_49ab20_Desc desc(0, velocityWidth, velocityHeight, velocityFormat);
            desc.field_1c = velocityFormat;
            result = reinterpret_cast<CRenderTextureArray*>(field_1e0)->Initialize(2, &desc, 0, true, 0);
            if (result < 0) {
#line 8387
                PPFX_ERROR("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityReducedWork->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 8395
            PPFX_LOG("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityReducedWork->Initialize() succeeded.\n");
        }
    }

    // the ambient occlusion
    s32 aoFormat = 0;
    if (field_1c3) {
#line 8409
        field_1f0 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pAmbientOcclusion_NormalDepthTexture"));
        aoFormat = p3c8 != 0 ? p3c8 : 0x1c;
        result = reinterpret_cast<CRenderTexture*>(field_1f0)->Unk_Create(0, width, height, aoFormat);
        if (result < 0) {
#line 8426
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
    }
    if (field_1c2) {
        u32 aoWidth = static_cast<u32>((p508 > 0.0f ? p508 : 0.5f) * fx74 + 0.99f);
        aoWidth = x74 > aoWidth ? aoWidth : x74;
        if (p50c != 0) {
            aoWidth = p50c;
        }
        u32 aoHeight = static_cast<u32>(static_cast<f32>(aoWidth) / aspect + 0.499999f);
        aoHeight = height > aoHeight ? aoHeight : height;
        f32 aoScale = static_cast<f32>(aoWidth) / static_cast<f32>(width);
#line 8525
        field_1f8 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pAmbientOcclusion_NormalDepthTexture_Reduced"));
#line 8526
        field_208 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pAmbientOcclusion_Result_Reduced"));
#line 8527
        field_210 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pAmbientOcclusion_Result_Reduced2"));
        if (aoScale < 0.375f) {
#line 8530
            field_200 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pAmbientOcclusion_NormalDepthTexture_Reduced2"));
#line 8531
            field_218 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pAmbientOcclusion_Result_Reduced3"));
        }
        result = reinterpret_cast<CRenderTexture*>(field_1f8)->Unk_Create(0, aoWidth, aoHeight, aoFormat);
        if (result < 0) {
#line 8541
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture_Reduced->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
        s32 resultFormat = p3cc != 0 ? p3cc : 0xa;
        result = reinterpret_cast<CRenderTexture*>(field_208)->Unk_Create(0, aoWidth, aoHeight, resultFormat);
        if (result < 0) {
#line 8558
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
        result = reinterpret_cast<CRenderTexture*>(field_210)->Unk_Create(0, aoWidth, aoHeight, resultFormat);
        if (result < 0) {
#line 8571
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced2->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
        if (aoScale < 0.375f) {
            u32 aoWidth2 = static_cast<u32>(static_cast<f32>(width) * 0.5f + 0.99f);
            aoWidth2 = width > aoWidth2 ? aoWidth2 : width;
            u32 aoHeight2 = static_cast<u32>(static_cast<f32>(aoWidth2) / aspect + 0.499999f);
            aoHeight2 = height > aoHeight2 ? aoHeight2 : height;
            result = reinterpret_cast<CRenderTexture*>(field_200)->Unk_Create(0, aoWidth2, aoHeight2, aoFormat);
            if (result < 0) {
#line 8595
                PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture_Reduced2->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
            result = reinterpret_cast<CRenderTexture*>(field_218)->Unk_Create(0, aoWidth2, aoHeight2, resultFormat);
            if (result < 0) {
#line 8608
                PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced3->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
        }
        field_220 = nullptr;
    }
    // SMAA
    if (field_1ca) {
#line 8627
        field_228 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pSmaaEdgeTexture"));
#line 8628
        field_230 = reinterpret_cast<Unk_RenderTexture*>(UNK_NEW(CRenderTexture)("CPostEffect::m_pSmaaBlendTexture"));
        result = reinterpret_cast<CRenderTexture*>(field_228)->Unk_Create(0, width, height, 0x1c);
        if (result < 0) {
#line 8638
            PPFX_ERROR("CPostEffect::Initialize(): m_pSmaaEdgeTexture->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
        result = reinterpret_cast<CRenderTexture*>(field_230)->Unk_Create(0, width, height, 0x1c);
        if (result < 0) {
#line 8649
            PPFX_ERROR("CPostEffect::Initialize(): m_pSmaaBlendTexture->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
    }
    // the auto exposure's and auto focus's luminance
    {
        CRenderTexture* scene = renderBuffer->Unk_Texture(field_5e0);
        u32 meterWidth = static_cast<s32>(ldexp(1.0, static_cast<s32>(log(static_cast<s32>(static_cast<u32>(scene->field_54) >> 3)) / log(2.0))));
        u32 meterHeight = static_cast<s32>(ldexp(1.0, static_cast<s32>(log(static_cast<s32>(static_cast<u32>(scene->field_58) >> 3)) / log(2.0))));
        if (meterWidth > 0x80) {
            meterWidth = 0x80;
            meterHeight = static_cast<u32>(128.0f / field_420 + 0.49999f);
        }
        for (s32 i = 0; i < field_400; i++) {
            Unk_429da0_Item& aeparam = field_2a0[i];
            Unk_429e60_Item& afaram = field_2a8[i];
            CTextureLuminanceManage::Unk_Desc desc;
            desc.field_0 = 5;
            desc.field_4 = meterWidth;
            desc.field_8 = meterHeight;
            desc.field_c = 0;
            result = static_cast<CTextureLuminanceManage*>(aeparam.field_70)->Unk_4b87d0(&desc);
            if (result < 0) {
#line 8688
                PPFX_ERROR("CPostEffect::Initialize(): aeparam.m_pQuerySceneLuminance->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
            desc.field_0 = 1;
            desc.field_4 = 1;
            desc.field_8 = 1;
            desc.field_c = 0;
            result = static_cast<CTextureLuminanceManage*>(afaram.field_48)->Unk_4b87d0(&desc);
            if (result < 0) {
#line 8704
                PPFX_ERROR("CPostEffect::Initialize(): afaram.m_pQuerySceneDepth->Initialize() failed (0x%x: %s).\n", result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
        }
    }
    // the feedback
    field_1c6 = false;
    field_270 = false;
    field_271 = false;
    if (field_2b4 & 0x800000) {
        field_1c6 = true;
#line 8750
        field_260 = reinterpret_cast<Unk_4a5d10_Self**>(UNK_NEW_ARRAY(CRenderTextureArray*, field_400));
        memset(field_260, 0, field_400 * sizeof(CRenderTextureArray*));
        s32 feedbackFormat = field_2b8.field_118 != 0 ? field_2b8.field_118 : field_30->field_0;
        field_518 = feedbackFormat;
        for (s32 i = 0; i < field_400; i++) {
            Unk_TFXString name = Unk_TFXString("CPostEffect::m_ppFeedbackBuffer") + '[' + Unk_4525a0(i) + ']';
#line 8773
            field_260[i] = reinterpret_cast<Unk_4a5d10_Self*>(UNK_NEW(CRenderTextureArray)(name.field_8));
            Unk_49ab20_Desc desc(0x400, width, height, feedbackFormat);
            result = reinterpret_cast<CRenderTextureArray*>(field_260[i])->Initialize(2, &desc, 0, true, 0);
            if (result < 0) {
#line 8786
                PPFX_ERROR("CPostEffect::Initialize(): m_ppFeedbackBuffer[%d]->Initialize() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
        }
        field_270 = (field_2b4 >> 24) & 1;
        if (!(field_2b4 & 0x1000000)) {
            if (field_18->field_14ef0) {
                field_271 = true;
            } else {
                util->field_29a58->Unk_49fc10(reinterpret_cast<CRenderTexture**>(&field_268), width, height, feedbackFormat, true, 0, 0);
                if (field_268 == nullptr) {
#line 8824
                    PPFX_ERROR("CPostEffect::Initialize(): pTexUtil->GetTexturePool()->AllocateTexture(&m_pFeedbackTonemapTexture) failed.\n");
                    Uninitialize(nullptr);
                    return result;
                }
            }
        }
    }
    // the tone map's convolution
    field_1c7 = false;
    field_f2c = 0;
    bool sizeMatches = width == field_30->field_8 && height == field_30->field_c;
    s32 convolution = field_434;
    if (convolution == -1) {
        convolution = sizeMatches ? 0 : 1;
    }
    field_f2c = convolution;
    bool convolve = convolution >= 1;
    if (convolve) {
        field_1c7 = true;
    }
    field_1ce = false;
    bool allocate;
    if (field_2b4 & 0x80000000) {
        field_1ce = true;
        field_1c7 = true;
        allocate = true;
    } else {
        allocate = convolve &&
                   (!field_1c6 || reinterpret_cast<CRenderTextureArray*>(field_260[0])->field_38[field_260[0]->field_90]->field_2c.field_c != field_30->field_0);
    }
    if (allocate) {
        util->field_29a58->Unk_49fc10(reinterpret_cast<CRenderTexture**>(&field_278), width, height, field_30->field_0, true, 0, 0);
        if (field_278 == nullptr) {
#line 8933
            PPFX_ERROR("CPostEffect::Initialize(): pTexUtil->GetTexturePool()->AllocateTexture(&m_pTonemapConvolutionTexture) failed.\n");
            Uninitialize(nullptr);
            return result;
        }
    }
    field_280 = field_1c8;
    if (field_1c6) {
        if (!field_270 && !field_271) {
            field_280 = 1;
        }
    } else if (field_1c7) {
        field_280++;
    }
    field_280 = 0;
    field_420 = aspect;
    if (Unk_24e09e8 != nullptr && (Unk_24e09f0 & 4)) {
        Unk_24e09e8(4, Unk_24e09f8);
    }
    // the device objects
    result = reinterpret_cast<CRenderTextureArray*>(field_190)->vf0(field_18);
    if (result < 0) {
#line 9150
        PPFX_ERROR("CPostEffect::Initialize(): m_pRenderBuffer->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        Uninitialize(nullptr);
        return result;
    }
#line 9159
    PPFX_LOG("CPostEffect::Initialize(): m_pRenderBuffer->InitializeDevice() succeeded.\n");
    if (field_1b0 != nullptr) {
        result = reinterpret_cast<CRenderTextureArray*>(field_1b0)->vf0(field_18);
        if (result < 0) {
#line 9172
            PPFX_ERROR("CPostEffect::Initialize(): m_pGlareModulatorWork->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9179
        PPFX_LOG("CPostEffect::Initialize(): m_pGlareModulatorWork->InitializeDevice() succeeded.\n");
    }
    if (field_1a8 != nullptr) {
        result = field_1a8->vf0(field_18);
        if (result < 0) {
#line 9188
            PPFX_ERROR("CPostEffect::Initialize(): m_pEffectColorAlphaDestinationWork->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9195
        PPFX_LOG("CPostEffect::Initialize(): m_pEffectColorAlphaDestinationWork->InitializeDevice() succeeded.\n");
    }
    result = reinterpret_cast<CRenderGlare*>(field_198)->vf0(field_18);
    if (result < 0) {
#line 9206
        PPFX_ERROR("CPostEffect::Initialize(): m_pRenderGlare->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        Uninitialize(nullptr);
        return result;
    }
#line 9216
    PPFX_LOG("CPostEffect::Initialize(): m_pRenderGlare->InitializeDevice() succeeded.\n");
    if (field_1b8) {
        result = reinterpret_cast<CDepthOfField*>(field_1a0)->vf0(field_18);
        if (result < 0) {
#line 9229
            PPFX_ERROR("CPostEffect::Initialize(): m_pDepthOfField->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9238
        PPFX_LOG("CPostEffect::Initialize(): m_pDepthOfField->InitializeDevice() succeeded.\n");
    }
    if (field_1d8 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_1d8)->vf0(field_18);
        if (result < 0) {
#line 9258
            PPFX_ERROR("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityTexture->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9267
        PPFX_LOG("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityTexture->InitializeDevice() succeeded.\n");
    }
    if (field_1e0 != nullptr) {
        result = reinterpret_cast<CRenderTextureArray*>(field_1e0)->vf0(field_18);
        if (result < 0) {
#line 9278
            PPFX_ERROR("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityReducedWork->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9285
        PPFX_LOG("CPostEffect::Initialize(): m_pMotionBlurInternalVelocityReducedWork->InitializeDevice() succeeded.\n");
    }
    if (field_1e8 != nullptr) {
        result = reinterpret_cast<CRenderTextureArray*>(field_1e8)->vf0(field_18);
        if (result < 0) {
#line 9295
            PPFX_ERROR("CPostEffect::Initialize(): m_pMotionBlurReducedWork->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9302
        PPFX_LOG("CPostEffect::Initialize(): m_pMotionBlurReducedWork->InitializeDevice() succeeded.\n");
    }
    if (field_1f0 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_1f0)->vf0(field_18);
        if (result < 0) {
#line 9313
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9320
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture->InitializeDevice() succeeded.\n");
    }
    if (field_1f8 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_1f8)->vf0(field_18);
        if (result < 0) {
#line 9328
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture_Reduced->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9335
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture_Reduced->InitializeDevice() succeeded.\n");
    }
    if (field_200 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_200)->vf0(field_18);
        if (result < 0) {
#line 9343
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture_Reduced2->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9350
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_NormalDepthTexture_Reduced2->InitializeDevice() succeeded.\n");
    }
    if (field_208 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_208)->vf0(field_18);
        if (result < 0) {
#line 9358
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9365
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced->InitializeDevice() succeeded.\n");
    }
    if (field_210 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_210)->vf0(field_18);
        if (result < 0) {
#line 9373
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced2->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9380
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced2->InitializeDevice() succeeded.\n");
    }
    if (field_218 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_218)->vf0(field_18);
        if (result < 0) {
#line 9389
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced3->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9396
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_Result_Reduced3->InitializeDevice() succeeded.\n");
    }
    if (field_220 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_220)->vf0(field_18);
        if (result < 0) {
#line 9404
            PPFX_ERROR("CPostEffect::Initialize(): m_pAmbientOcclusion_Result->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9411
        PPFX_LOG("CPostEffect::Initialize(): m_pAmbientOcclusion_Result->InitializeDevice() succeeded.\n");
    }
    if (field_260 != nullptr) {
        for (s32 i = 0; i < field_400; i++) {
            CRenderTextureArray* feedback = reinterpret_cast<CRenderTextureArray*>(field_260[i]);
            if (feedback == nullptr) {
                continue;
            }
            result = feedback->vf0(field_18);
            if (result < 0) {
#line 9425
                PPFX_ERROR("CPostEffect::Initialize(): m_ppFeedbackBuffer[%d]->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
            for (s32 j = 0; j < reinterpret_cast<CRenderTextureArray*>(field_260[i])->field_30; j++) {
                CRenderTexture* texture = reinterpret_cast<CRenderTextureArray*>(field_260[i])->field_38[j];
                while (texture->field_120 != nullptr) {
                    texture = texture->field_120;
                }
                reinterpret_cast<IGPUTexture*>(texture->field_a8)->vf18(1);
            }
#line 9442
            PPFX_LOG("CPostEffect::Initialize(): m_ppFeedbackBuffer[%d]->InitializeDevice() succeeded.\n", i);
        }
    }
    for (s32 i = 0; i < field_400; i++) {
        CTextureLuminanceManage* luminance = static_cast<CTextureLuminanceManage*>(field_2a0[i].field_70);
        if (luminance != nullptr) {
            result = luminance->vf0(field_18);
            if (result < 0) {
#line 9459
                PPFX_ERROR("CPostEffect::Initialize(): m_pAutoExposureParam[%d].m_pQuerySceneLuminance->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 9468
            PPFX_LOG("CPostEffect::Initialize(): m_pAutoExposureParam[%d].m_pQuerySceneLuminance->InitializeDevice() succeeded.\n", i);
        }
        CTextureLuminanceManage* depth = static_cast<CTextureLuminanceManage*>(field_2a8[i].field_48);
        if (depth != nullptr) {
            result = depth->vf0(field_18);
            if (result < 0) {
#line 9479
                PPFX_ERROR("CPostEffect::Initialize(): m_pAutoFocusParam[%d].m_pQuerySceneDepth->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 9488
            PPFX_LOG("CPostEffect::Initialize(): m_pAutoFocusParam[%d].m_pQuerySceneLuminance->InitializeDevice() succeeded.\n", i);
        }
    }
    if (field_228 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_228)->vf0(field_18);
        if (result < 0) {
#line 9499
            PPFX_ERROR("CPostEffect::Initialize(): m_pSmaaEdgeTexture->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9506
        PPFX_LOG("CPostEffect::Initialize(): m_pSmaaEdgeTexture->InitializeDevice() succeeded.\n");
    }
    if (field_230 != nullptr) {
        result = reinterpret_cast<CRenderTexture*>(field_230)->vf0(field_18);
        if (result < 0) {
#line 9514
            PPFX_ERROR("CPostEffect::Initialize(): m_pSmaaBlendTexture->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            Uninitialize(nullptr);
            return result;
        }
#line 9521
        PPFX_LOG("CPostEffect::Initialize(): m_pSmaaBlendTexture->InitializeDevice() succeeded.\n");
    }
    if (field_238 != nullptr) {
        for (s32 i = 0; i < field_400; i++) {
            result = reinterpret_cast<CRenderTexture*>(field_238[i])->vf0(field_18);
            if (result < 0) {
#line 9536
                PPFX_ERROR("CPostEffect::Initialize(): m_ppTemporalAntialias_History[%d]->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 9543
            PPFX_LOG("CPostEffect::Initialize(): m_ppTemporalAntialias_History[%d]->InitializeDevice() succeeded.\n", i);
        }
    }
    if (field_580 != 0) {
        for (s32 i = 0; i < field_400; i++) {
            result = field_570[i]->vf0(field_18);
            if (result < 0) {
#line 9562
                PPFX_ERROR("CPostEffect::Initialize(): m_ppOetfSceneLuminanceBaseWork[%d]->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 9569
            PPFX_LOG("CPostEffect::Initialize(): m_ppOetfSceneLuminanceBaseWork[%d]->InitializeDevice() succeeded.\n", i);
            result = field_588[i]->vf0(field_18);
            if (result < 0) {
#line 9576
                PPFX_ERROR("CPostEffect::Initialize(): m_ppOetfQuerySceneLuminance[%d]->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 9583
            PPFX_LOG("CPostEffect::Initialize(): m_ppOetfQuerySceneLuminance[%d]->InitializeDevice() succeeded.\n", i);
        }
        for (s32 i = 0; i < field_580; i++) {
            result = field_578[i]->vf0(field_18);
            if (result < 0) {
#line 9616
                PPFX_ERROR("CPostEffect::Initialize(): m_pppOetfSceneLuminanceResizeWork[%d]->InitializeDevice() failed (0x%x: %s).\n", i, result, Unk_446df0(result));
                Uninitialize(nullptr);
                return result;
            }
#line 9623
            PPFX_LOG("CPostEffect::Initialize(): m_pppOetfSceneLuminanceResizeWork[%d]->InitializeDevice() succeeded.\n", i);
        }
    }
    result = Unk_46e350_call(util);
    if (result < 0) {
#line 9637
        PPFX_ERROR("CPostEffect::Initialize(): pTexUtil->InitializeDeviceSharedTexturePool() failed (0x%x: %s).\n", result, Unk_446df0(result));
        Uninitialize(nullptr);
        return result;
    }
#line 9643
    PPFX_LOG("CPostEffect::Initialize(): pTexUtil->InitializeDeviceSharedTexturePool() succeeded.\n");
    util->field_29a60 = true;

    // the effects' parameters, all reset
    for (s32 i = 0; i < 18; i++) {
        field_10e4[i] = 0;
    }
    field_112c = 0;
    field_1050 = false;
    field_0 = false;
    field_1 = false;
    field_8 = false;
    field_9 = false;
    Unk_4234f0(reinterpret_cast<u64>(this), 0);
    field_bcd = field_1b8;
    field_c20 = 0.0f;
    field_c24 = 3.14159274f;
    field_c28 = 0.34906585f;
    field_c08 = 1.0f;
    field_c0c = 0.05f;
    field_c18 = 0.785398185f;
    field_c1c = 0.34906585f;
    field_be8 = 1.0f;
    field_c04 = 1;
    field_bec = false;
    field_bf0 = 1.0f;
    field_bf4 = 1.0f;
    field_bf8 = 0.0f;
    field_c10 = 1.0f;
    field_c14 = 1;
    field_8b6 = false;
    field_895 = true;
    field_8b4 = false;
    field_8b5 = false;
    field_be4 = false;
    field_bfc = 0.5f;
    field_c00 = 0.5f;
    field_c74 = 5.87e-07f;
    field_c70 = false;
    field_c78 = true;
    field_c79 = true;
    field_f08 = false;
    field_f14 = 0.05f;
    field_f18 = 0;
    field_f24 = 0.001f;
    field_f28 = 0;
    field_f1c = 0.1f;
    field_f20 = 0.1f;
    field_f0c = 2;
    field_f10 = false;
    field_eb8 = false;
    field_ebc = 16;
    field_ec0 = 1.0f;
    field_ecc = 1.0f;
    field_ed0 = 1.0f;
    field_ed4 = 0;
    field_ed8 = 0.0001f;
    field_edc = 0.5f;
    field_ee0 = 0.5f;
    field_ee4 = 0.5f;
    field_ee8 = 0.5f;
    field_ef4 = -2;
    field_ec4 = 0;
    field_ec8 = 0;
    field_ef8 = 1.0f;
    field_efc = 1.0f;
    field_f00 = 0;
    field_f04 = 0;
    field_c7a = false;
    field_c7c.field_8 = 0.0f;
    field_c7c.field_c = 0.0f;
    field_c7c.field_0 = 0.0f;
    field_c7c.field_4 = 0.0f;
    field_c90 = true;
    field_c91 = true;
    field_c94 = 2;
    field_c8c = 0.005f;
    field_c98 = false;
    field_c9c = 0.0f;
    field_ca0 = 64512.0f;
    for (s32 i = 0; i < 4; i++) {
        field_ca4[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_f38 = field_1c8;
    field_895 = true;
    field_f3c = 0.0f;
    field_f40 = 0.0f;
    SetAntialiasType(INT32_MIN);
    field_f48 = 0.1f;
    field_f4c = 8;
    field_f58 = false;
    field_f50 = 0;
    field_f54 = 0;
    field_f5c = 1.0f;
    field_f60 = 1.0f;
    field_c2c = field_1cb;
    field_c30 = 5;
    field_f64 = 1.0f;
    field_c34 = false;
    field_c36 = false;
    field_c58 = Unk_Float2(0.0f, 0.0f);
    field_c50 = Unk_Float2(0.0f, 0.0f);
    field_c48 = Unk_Float2(0.0f, 0.0f);
    field_c40 = Unk_Float2(0.0f, 0.0f);
    field_c38 = Unk_Float2(0.0f, 0.0f);
    field_c60 = 1.0f;
    field_c64 = 0.0f;
    field_c68 = 0.25f;
    field_c6c = true;
    // the light shafts
    for (s32 i = 0; i < static_cast<s32>(field_478); i++) {
        if (i <= static_cast<s32>(field_478)) {
            field_860 = i;
        }
        if (field_198->field_108) {
            field_858[field_860].field_60 = false;
        }
        field_858[field_860].field_0 = {1.0f, 1.0f, 1.0f, 1.0f};
        field_858[field_860].field_1c = 1.0f;
        field_858[field_860].field_10 = 0.25f;
        field_858[field_860].field_5c = 0.99999f;
        field_858[field_860].field_64 = 0;
        field_858[field_860].field_20 = 1.0f;
        field_858[field_860].field_14 = 1.0f;
        field_858[field_860].field_18 = 1.0f;
        field_858[field_860].field_24 = 0.5f;
        field_858[field_860].field_30 = 0.261799395f;
        field_858[field_860].field_28 = 0.5f;
        field_858[field_860].field_2c = 1.0f;
        field_858[field_860].field_34 = {1.0f, 1.0f, 1.0f, 1.0f};
        field_858[field_860].field_44 = Unk_Float2(0.5f, 0.5f);
        field_858[field_860].field_4c = {1.0f, 1.0f, 1.0f, 1.0f};
    }
    if (static_cast<s32>(field_478) >= 0) {
        field_860 = 0;
    }
    {
        Unk_GlareRect color = {1.0f, 1.0f, 1.0f, 1.0f};
        Unk_4534a0(field_198, &color, 1.0f, 1.0f, 0.5f, 1.0f, 0.0f);
    }
    field_874 = 2;
    field_878 = 0;
    field_880 = 0;
    // the light ghosts
    for (s32 i = 0; i < field_524; i++) {
        if (i <= field_524) {
            field_870 = i;
        }
        if (field_198->field_110) {
            field_868[field_870].field_0 = 0;
        }
        field_868[field_870].field_4 = {1.0f, 1.0f, 1.0f, 1.0f};
        field_868[field_870].field_24 = 0;
        field_868[field_870].field_28 = 0.001f;
        field_868[field_870].field_2c = 0.99999f;
        field_868[field_870].field_30 = 0;
        field_868[field_870].field_14 = Unk_Float2(0.5f, 0.5f);
        field_868[field_870].field_1c = Unk_Float2(0.5f, 0.5f);
    }
    if (field_524 >= 0) {
        field_870 = 0;
    }
    field_884 = 1.0f;
    field_888 = 0.785398185f;
    field_88c = 0.0f;
    field_890 = 0.0f;
    field_8ec = 0.0f;
    field_8f0 = 0.0f;
    field_914 = 0;
    field_895 = true;
    if (field_1b8) {
        field_8fc = 0.0f;
        field_900 = 0.0f;
        field_1a0->field_1f8 = -1;
    }
    field_895 = true;
    field_d90 = true;
    field_d80 = false;
    field_d84 = 0;
    field_d88 = nullptr;
    field_d94 = 1.0f;
    field_d98 = 1.0f;
    field_d9c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
    field_dac = Unk_Float2(1.0f, 1.0f);
    field_db4.field_0[0] = 0.0f;
    field_db4.field_0[1] = 0.0f;
    field_db4.field_0[2] = 0.0f;
    field_dc0 = 3;
    field_dc4 = 2.7f;
    field_dc8 = 0.28f;
    field_de0 = 0.0f;
    field_de4 = 0.0f;
    if (field_de8) {
        field_895 = true;
    }
    field_dd0 = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
    field_cf0 = 1.0f;
    field_cf4 = 0.1f;
    field_d00 = 1.0f;
    field_de8 = false;
    field_dcc = false;
    field_ce5 = false;
    field_cec = true;
    field_ce8 = 1;
    field_cf8 = -1;
    field_cfc = 0xffffffff;
    field_d04 = 0.0f;
    field_d08 = 0.0f;
    field_895 = true;
    field_d20 = 0.15f;
    field_d24 = -0.01f;
    field_d0c = false;
    field_d10 = 0.0f;
    field_d14 = 0.0f;
    field_d28 = 0;
    Unk_SetMotionBlurVelocityDilationType(this, field_504);
    field_d50 = 0.93f;
    field_d54 = 0.93f;
    field_d58 = 0.93f;
    field_d5c = 0.93f;
    field_d60 = 1;
    Unk_SetMotionBlurVelocitySource(this, field_1bc ? 0 : -1);
    field_d18 = 1.0f;
    field_d1c = 1.0f;
    field_e04[0] = 0.0f;
    field_e04[1] = 1.0f;
    field_df8 = 0;
    field_df0 = nullptr;
    field_e00 = false;
    for (s32 i = 2; i < 41; i++) {
        field_e04[i] = 0.0f;
    }
    field_e04[(0xe44 - 0xe04) / 4] = 1.0f;
    field_e04[(0xe30 - 0xe04) / 4] = 1.0f;
    field_e04[(0xe1c - 0xe04) / 4] = 1.0f;
    field_e04[(0xe84 - 0xe04) / 4] = 1.0f;
    field_e04[(0xe70 - 0xe04) / 4] = 1.0f;
    field_e04[(0xe5c - 0xe04) / 4] = 1.0f;
    field_e04[(0xe48 - 0xe04) / 4] = 1.0f;
    field_e04[(0xe98 - 0xe04) / 4] = 1.0f;
    field_e04[(0xe9c - 0xe04) / 4] = 1.0f;
    field_e04[(0xea0 - 0xe04) / 4] = 1.0f;
    field_e04[(0xea4 - 0xe04) / 4] = 1.0f;
    field_f34 = 1.0f;
    field_980 = 1.0f;
    field_9a4 = 1.0f;
    field_bd4 = -FLT_MAX;
    field_990 = -FLT_MAX;
    field_994 = -FLT_MAX;
    field_998 = true;
    field_999 = true;
    field_9a8 = 80.0f;
    field_99c = 13;
    field_eec = 0.0f;
    field_ef0 = 0.0f;
    field_90c = 0.0f;
    field_910 = 0.0f;
    field_bce = false;
    field_bd0 = 0;
    field_eb0 = 0;
    field_ea8 = 0;
    field_bd8 = 0;
    field_f30 = -1;
    field_978 = 0;
    field_984 = 0;
    field_988 = 0;
    field_98c = 0.9f;
    field_9a0 = 2.4f;
    field_96c = false;
    field_970 = 0;
    if (field_1d1) {
        field_970 = 0;
    } else {
        field_96c = false;
    }
    field_974 = 0;
    field_97c = 0xffffffff;
    field_1160 = 0;
    for (s32 i = 5; i >= 0; i--) {
        field_1130[i] = 0;
    }
    Unk_SetTonemapBackendColorSpaceMode(this, 0);
    Unk_SetTonemapBackendColorSpaceModeSdr(this, 0);
    field_590 = 0;
    field_70 = nullptr;
    field_78 = 0;
    field_1168 = 0;
    field_128 = 0;
    field_130 = 0;
    field_180 = field_1ce;
    field_b0 = nullptr;
    field_b8 = nullptr;
    field_8c = 0;
    field_90 = 2;
    field_898 = 0.0f;
    field_89c = 0.024f;
    field_895 = true;
    field_a0 = nullptr;
    field_a8 = nullptr;
    field_8a0 = 1;
    field_8a4 = 0.029f;
    field_168 = 0;
    field_170 = 0;
    field_8a8 = Unk_Float2(0.0f, 0.785398185f);
    field_5d0 = field_540;
    field_120 = nullptr;
    field_c0 = 0;
    field_5c8 = 0;
    field_5cc = 0;
    field_5c0 = nullptr;
    field_5b8 = nullptr;
    field_5d4 = 1.0f;
    field_178 = nullptr;
    field_88 = false;
    field_80 = nullptr;
    field_94 = 0;
    field_98 = 0.0f;
    field_8b8 = Unk_Float2(0.0f, 0.0f);
    field_158 = 0;
    field_160 = 0;
    field_148 = 0;
    field_150 = 0;
    field_138 = 0;
    field_140 = 0;
    if (field_1b8) {
        field_1a0->field_178 = 0.1f;
        field_1a0->field_17c = 0;
    }
    field_8b0 = 1.0f;
    if (field_1a0 != nullptr) {
        field_1a0->field_251 = true;
        field_1a0->field_2a8 = 1;
    }
    if (field_198 != nullptr) {
        field_198->field_260 = 6;
    }
    if (field_1a0 != nullptr) {
        field_1a0->field_3e8 = 0.0f;
        field_1a0->field_3ec = 0.5f;
    }
    if (field_198 != nullptr) {
        field_198->field_258 = 0.0f;
        field_198->field_25c = 0.5f;
    }
    if (field_1a0 != nullptr) {
        field_1a0->field_2ac = 4;
        field_1a0->field_2b0 = 1.0f;
        field_1a0->field_2b4 = 0.5f;
        field_1a0->field_2b8 = 1.0f;
        field_1a0->field_2bc = 1.0f;
    }
    if (field_1a0 != nullptr) {
        field_1a0->field_3e0 = 4.0f;
        field_1a0->field_3d8 = 0.1f;
        field_1a0->field_3dc = 16.0f;
    }
    if (field_1a0 != nullptr && field_1a0->field_12d) {
        field_1a0->field_3f0 = false;
    }
    if (field_1a0 != nullptr) {
        field_1a0->field_3f4 = 1.0f;
    }
    if (field_1a0 != nullptr) {
        field_1a0->field_3a8 = false;
    }
    field_895 = true;
    if (field_1a0 != nullptr) {
        field_1a0->field_3b8 = 0.75f;
        field_1a0->field_3bc = 1.0f;
        field_1a0->field_3c0 = 0.785398185f;
        field_1a0->field_3c4 = false;
        field_1a0->field_3d0 = 0;
        field_1a0->field_3c8 = 0;
    }
    field_895 = true;
    if (field_1a0 != nullptr) {
        field_1a0->field_3b0 = 0;
    }
    field_188 = 0;
    Unk_424100(this, 0.0f, 0.0f, 0.0f, 1.0f / 60.0f, 1.0f);
    Unk_427760(reinterpret_cast<u64>(this), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Unk_Identity(&field_6f4);
    Unk_Identity(&field_774);
    Unk_424240(reinterpret_cast<u64>(this), false, 1.0f, 1.0f, 0.0f, 0.0f);
    Unk_SetGlareModulatorSourceViewportScale(this, 0.0f, 0.0f, 0.0f, 0.0f);
    Unk_SetEffectMaskColorSourceViewportScale(this, 0.0f, 0.0f, 0.0f, 0.0f);
    Unk_SetEffectMaskAlphaSourceViewportScale(this, 0.0f, 0.0f, 0.0f, 0.0f);
    field_7fc = 1.0f;
    field_844 = 0.0f;
    field_848 = 1.0f;
    field_f78 = 1;
    field_f7c = 1.0f;
    field_f80 = 1;
    field_198->field_1ac = false;
    Unk_455510_update(reinterpret_cast<Unk_455510*>(field_198), 1.0f, 1.0f, 1.0f);
    {
        Unk_455350_Float4 a = {{0.2f, 0.2f, 1.0f, 0.0f}};
        Unk_455350_Float4 b = {{0.2f, 0.7f, 0.5f, 0.0f}};
        Unk_455530_set(reinterpret_cast<Unk_455350*>(field_198), &a, &b);
    }
    field_1029 = false;
    for (s32 i = 0; i < 6; i++) {
        field_102c[i] = 1.0f;
    }
    field_1044 = 0;
    field_1048 = 0;
    field_c8 = 0;
    field_1008 = 1;
    field_100c = 1.0f;
    field_1010 = 0.0f;
    Unk_4244a0(reinterpret_cast<u64>(this), 0xffffffff, 1.0f, 1.0f, 32.0f, -FLT_MAX);
    field_be0 = 0;
    field_8d4 = Unk_Float4(0.0f, 0.0f, 0.0f, 1.0f);
    field_8e4 = 0.0f;
    field_8e8 = 0.5f;
    Unk_Identity(&field_b3c);
    field_b7c = 25;
    field_b84 = Unk_410f90();
    field_ba4 = Unk_410f90();
    field_b80 = 25;
    field_bc4 = 0.5f;
    field_bc8 = 0.5f;
    field_bcc = false;
    Unk_424670(this, 1.0f / 60.0f);
    if (field_1a0 != nullptr) {
        field_1a0->field_3a8 = false;
    }
    field_918 = 0;
    // every view's auto exposure and auto focus
    Unk_424740(reinterpret_cast<u64>(this), 0x7fffffff, false);
    Unk_4248b0(0.5f, 0.85f, 8.0f, -1.0f, -1.0f, -1.0f, 1.0f, reinterpret_cast<u64>(this), 0x7fffffff);
    Unk_424b20(reinterpret_cast<u64>(this), 0x7fffffff, FLT_MIN, FLT_MAX);
    Unk_424c90(reinterpret_cast<u64>(this), 0x7fffffff, 0.18f, 0.0f);
    Unk_424de0(reinterpret_cast<u64>(this), 0x7fffffff, 0, -1.0f);
    Unk_424f40(1.0f, 1.0f, 0.0f, 0.0f, reinterpret_cast<u64>(this), 0x7fffffff);
    Unk_SetAutoExposureMeteringResult(this, 0x7fffffff, 0.0f);
    Unk_SetAutoExposureMeteringLuminanceRange(this, 0x7fffffff, FLT_MIN, FLT_MAX);
    Unk_SetAutoExposureMeteringColorSpace(this, -1);
    for (s32 i = 0; i < field_400; i++) {
        field_2a8[i].field_0 = false;
    }
    field_f68 = 1.0f;
    for (s32 i = 0; i < field_400; i++) {
        field_2a8[i].field_24 = false;
        field_2a8[i].field_20 = 0.5f;
        field_2a8[i].field_28 = 1.0f;
    }
    for (s32 i = 0; i < field_400; i++) {
        field_2a8[i].field_c = FLT_MIN;
        field_2a8[i].field_10 = FLT_MAX;
    }
    for (s32 i = 0; i < field_400; i++) {
        field_2a8[i].field_14.field_0 = 0.5f;
        field_2a8[i].field_18.field_0 = 0.5f;
    }
    for (s32 i = 0; i < field_400; i++) {
        field_2a8[i].field_4 = 0;
        field_2a8[i].field_8 = -1.0f;
    }
    for (s32 i = 0; i < field_400; i++) {
        field_2a8[i].field_1c = 0.0f;
    }
    field_198->field_1e8 = 0.5f;
    field_84c = !field_59c;
    field_1018 = 0.0f;
    field_101c = 1.0f;
    // 1.0f's bits (placeholder types: the members are copied as integers)
    field_1020 = 0x3f800000;
    field_1024 = 0x3f800000;
    field_850 = 1;
    Unk_425240(reinterpret_cast<u64>(this), 0);
    // (the edge blur table is set up here, and what is read from it isn't
    // used: the argument is a placeholder)
    s32 edgeBlur = Unk_DofEdgeBlurType(dofA);
    Unk_238d250 = -1;
    field_894 = !field_59c || field_59e;
    Unk_424240(reinterpret_cast<u64>(this), false, 0.0f / static_cast<f32>(field_30->field_8),
               0.0f / static_cast<f32>(field_30->field_c), 0.0f / static_cast<f32>(field_30->field_8),
               0.0f / static_cast<f32>(field_30->field_c));
    field_5a4 = 1.0f;
    field_5a8 = 1.0f;
    field_5ac = 0.0f;
    field_5b0 = 0.0f;
    Unk_SetRenderSceneHeightReverse_Gcm(this, false);
    field_1014 = false;
    if (field_1b8) {
        field_1a0->field_240 = false;
    }
    bool dofScene = field_1b8 && field_1014;
    if (edgeBlur != 0) {
        field_895 = true;
    }
    renderBuffer->Unk_4a5f50(0x7fffffff, dofScene ? 1.0f : 0.0f, dofScene ? 0.0f : 1.0f);
    field_895 = true;
    field_50 = nullptr;
    field_58 = field_548 ? 3 : 8;
    field_5c = field_548 ? 0 : 2;
    field_60 = 1.0f;
    field_64 = 0.0f;
    field_68 = 1.0f;
    field_6c = -0.0f;
    Unk_442c50_get(reinterpret_cast<u64>(field_18));
    field_104c = false;
    field_104d = false;
    for (u32 i = 0; i < 6; i++) {
        Unk_4255b0(reinterpret_cast<u64>(this), i);
    }
    Unk_425750();
    if (Unk_24e09e8 != nullptr && (Unk_24e09f0 & 8)) {
        Unk_24e09e8(8, Unk_24e09f8);
    }
    BeginCommandList_SiGfx();
    util->Unk_4708a0(nullptr);
    Unk_4a6160(field_190, nullptr, 0, 1.0f);
    reinterpret_cast<CRenderGlare*>(field_198)->Unk_45e980(nullptr);
    if (field_1b8) {
        reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aa290(nullptr);
    }
    if (field_260 != nullptr) {
        for (s32 i = 0; i < field_400; i++) {
            if (field_260[i] != nullptr) {
                Unk_4a6160(field_260[i], nullptr, 0, 1.0f);
            }
        }
    }
    if (field_238 != nullptr) {
        for (s32 i = 0; i < field_400; i++) {
            Unk_49c8d0_call(field_238[i], nullptr);
        }
    }
    for (s32 i = 0; i < field_558; i++) {
        Unk_49c8d0_call(field_550[i], nullptr);
    }
    for (s32 i = 0; i < field_568; i++) {
        Unk_49c8d0_call(field_560[i].field_0, nullptr);
        Unk_49c8d0_call(field_560[i].field_8, nullptr);
    }
    InitializeAutoExposure(0x7fffffff, 0.18f, 1.0f);
    Unk_426070(0x7fffffff, 0.0f);
    if (field_1be) {
        for (s32 i = 0; i < field_400; i++) {
            field_240[i] = 1.0f;
            field_248[i] = 1.0f;
            field_250[i] = field_7f8;
            field_258[i] = {0.0f, 0.0f, 0.0f, 0.0f};
        }
    }
    field_18->vf7(0, reinterpret_cast<void*>(field_20), 0);
    field_18->vf8(field_28);
    if (field_10 != 0) {
        Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
    }
    EndCommandList_SiGfx();
#line 10269
    PPFX_LOG("==== CPostEffect::Initialize() succeeded. ====\n");
    return 0;
}

// 0x7100419550
CPostEffect::~CPostEffect() {
    Uninitialize(nullptr);
}

// 0x71024e53e0 (GPURenderTexture.cpp)
extern void* Unk_24e53e0;

// 0x7100426700: CPostEffect::BeginPostEffectScene (its log line names it)
// (the texture util's release is given the pointer its acquire read: the
// original reads it before the user count's store)
s32 CPostEffect::BeginPostEffectScene(u32 clearFlags, const void* clearColor, f32 clearDepth, u32 clearStencil,
                                      s32 aux) {
#line 11315
    PPFX_FN("Frame: %d, View: %d, BeginPostEffectScene(uiClearFlags: %08x, pClearColor: %p, fClearDepth: %f, uiClearStencil: %d, iAuxiliaryRenderBufferIndex: %d);\n",
            Unk_Frame(field_298), field_298, clearFlags, clearColor, clearDepth, clearStencil, aux);
    BeginCommandList_SiGfx();
    s32 result = field_18->vf56();
    if (aux < 1) {
        result = Unk_426a50();
    }
    field_6b8 = clearFlags;
    field_6bc = clearDepth;
    field_6c0 = clearStencil;
    if (clearDepth < 0.0f) {
        clearDepth = field_1014 ? 0.0f : 1.0f;
    }
    // (the texture util is made, if no one has it, and released again)
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil(util);
    field_5e8 = field_5d8;
    if (aux >= 0) {
        Unk_24e53e0 = nullptr;
        result = Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        field_5e8 = field_5dc + aux;
    }
    field_190->field_90 = field_5e8;
    reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(field_6b4, 0x7fffffff);
    if (field_1d3) {
        if (field_70 == nullptr) {
#line 11397
            PPFX_ERROR("CPostEffect::BeginPostEffectScene(): At least SetEffectSource() must be called if Initialize() was called with PFXINIT_RENDERSCENE_EXTERNAL flag.\n");
            return -1;
        }
    } else {
        result = reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a6070(
            field_5e8, true, clearFlags, const_cast<void*>(clearColor), clearStencil, 0, 0,
            (clearFlags & 0xff0) ? 0x30000 : 0x10000, clearDepth);
    }
    if (result < 0) {
#line 11416
        PPFX_ERROR("CPostEffect::BeginPostEffectScene(): m_pRenderBuffer->SetRenderTarget() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        return result;
    }
    field_0 = true;
    return 0;
}

// 0x7100426a50: every render texture's viewport from the viewport's scale
s32 CPostEffect::Unk_426a50() {
    s32 result = Unk_SetViewport190(field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    if (field_70 != nullptr) {
        result = Unk_SetViewport(field_70, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_50 != nullptr) {
        result = Unk_SetViewport(field_50, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_a0 != nullptr) {
        result = Unk_SetViewport(field_a0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_a8 != nullptr) {
        result = Unk_SetViewport(field_a8, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_b0 != nullptr) {
        result = Unk_SetViewport(field_b0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_b8 != nullptr) {
        f32 width;
        f32 height;
        f32 x;
        f32 y;
        if (field_814.field_0 > 0.0f && field_814.field_4 > 0.0f) {
            width = field_814.field_0;
            height = field_814.field_4;
            x = field_814.field_8;
            y = field_814.field_c;
        } else {
            width = field_800.field_0;
            height = field_800.field_4;
            x = field_800.field_8;
            y = field_800.field_c;
        }
        result = Unk_SetViewport(field_b8, width, height, x, y);
    }
    if (field_df0 != nullptr) {
        result = Unk_SetViewport(field_df0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1f0 != nullptr) {
        result = Unk_SetViewport(field_1f0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1f8 != nullptr) {
        result = Unk_SetViewport(field_1f8, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_200 != nullptr) {
        result = Unk_SetViewport(field_200, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_208 != nullptr) {
        result = Unk_SetViewport(field_208, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_210 != nullptr) {
        result = Unk_SetViewport(field_210, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_218 != nullptr) {
        result = Unk_SetViewport(field_218, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_220 != nullptr) {
        result = Unk_SetViewport(field_220, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_228 != nullptr) {
        result = Unk_SetViewport(field_228, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_230 != nullptr) {
        result = Unk_SetViewport(field_230, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_238 != nullptr && field_238[field_298] != nullptr) {
        result = Unk_SetViewport(field_238[field_298], field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    for (s32 i = 0; i < field_280; i++) {
        result = Unk_SetViewport(field_288[i], field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    for (s32 i = 0; i < field_558; i++) {
        result = Unk_SetViewport(field_550[i], field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_5b8 != nullptr) {
        f32 width;
        f32 height;
        f32 x;
        f32 y;
        if (field_824.field_0 > 0.0f && field_824.field_4 > 0.0f) {
            width = field_824.field_0;
            height = field_824.field_4;
            x = field_824.field_8;
            y = field_824.field_c;
        } else {
            width = field_800.field_0;
            height = field_800.field_4;
            x = field_800.field_8;
            y = field_800.field_c;
        }
        result = Unk_SetViewport(field_5b8, width, height, x, y);
    }
    if (field_5c0 != nullptr) {
        f32 width;
        f32 height;
        f32 x;
        f32 y;
        if (field_834.field_0 > 0.0f && field_834.field_4 > 0.0f) {
            width = field_834.field_0;
            height = field_834.field_4;
            x = field_834.field_8;
            y = field_834.field_c;
        } else {
            width = field_800.field_0;
            height = field_800.field_4;
            x = field_800.field_8;
            y = field_800.field_c;
        }
        result = Unk_SetViewport(field_5c0, width, height, x, y);
    }
    if (field_d38 != nullptr) {
        result = Unk_SetViewport(field_d38, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1d8 != nullptr) {
        result = Unk_SetViewport(field_1d8, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1e0 != nullptr) {
        result = Unk_4a5d10(field_1e0, 0x7fffffff, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1e8 != nullptr) {
        result = Unk_4a5d10(field_1e8, 0x7fffffff, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_810) {
        Unk_4a6160(field_190, nullptr, 0, 1.0f);
    }
    if (field_198 != nullptr) {
        Unk_45eb90(field_198, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1a0 != nullptr) {
        Unk_4aa5a0(field_1a0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    return result;
}

// what the SiGfx device's slot 69 makes: a texture that wraps a device
// texture and its memory (placeholder)
struct Unk_SiGfxWrappedTexture {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // releases a reference
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
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual bool vf27(u64 arg1, u64 arg2);  // wraps the two device objects
};

// what the SiGfx device's slot 72 makes, as 0x7100423160 sets it up
// (placeholder)
struct Unk_SiGfxWrappedTarget {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // releases a reference
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
    virtual bool vf18();  // begins setting it up
    virtual void vf19();
    virtual void vf20(u32 index, Unk_SiGfxWrappedTexture* texture);
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();  // ends it
};

// 0x71004229e0: CPostEffect::CreateInternalResource_SiGfx (its log lines name
// it): SiGfx, its device, draw context and command list, made the first time
// NON_MATCHING: the calls, tests and cleanup are the original's; the device
// description's stores are merged and ordered differently (the original
// doesn't seem to start from SiGfx's default constructor), and the frame
// has 16 bytes less below the description (one stack slot is 4 bytes off).
s32 CPostEffect::CreateInternalResource_SiGfx(void** device, const Unk_417b30_Desc* desc) {
    if (!field_1170) {
        Unk_4bc760(Unk_24e0008 == 0 ? ~0ul : (Unk_24e0008 == 1 ? 0 : 3));
        SiSDK3::ISiAllocator* allocator = reinterpret_cast<SiSDK3::ISiAllocator*>(&field_1178);
        Unk_4cbd40(allocator);
        SiSDK3::Unk_4ecbc0 settings(reinterpret_cast<SiSDK3::ISiAllocator*>(reinterpret_cast<SiSDK3::SiGfxKernel*>(Unk_4cbf40_get())->vf6()));
        settings.field_60 = false;
        settings.field_61 = false;
        reinterpret_cast<SiSDK3::SiGfxKernel*>(Unk_4cbf40_get())->vf26(&settings);
#line 41776
        PPFX_LOG("IPfxBaseContext::CreateInternalResource_SiGfx(): SiGfxInit() succeeded.\n");
        field_1208 = 0;
        if (Unk_24e09c0 != 0) {
#line 41783
            SiSDK3::SiFixedHeapAllocator2* heap = UNK_SI_NEW(allocator, 0x10) SiSDK3::SiFixedHeapAllocator2(nullptr);
            field_1208 = reinterpret_cast<u64>(heap);
            if (!heap->vf21(allocator, 0x200, reinterpret_cast<u8*>(Unk_24e09c0), Unk_24e09c8)) {
                Unk_4cbdd0();
#line 41792
                PPFX_ERROR("CPostEffect::CreateInternalResource_SiGfx(): m_nvnMemoryPoolStorageAllocator.InitHeap()==false\n");
                return 1;
            }
        }
        reinterpret_cast<Unk_4cbf40_Object*>(reinterpret_cast<SiSDK3::SiGfxKernel*>(Unk_4cbf40_get())->vf37())
            ->vf5(reinterpret_cast<SiSDK3::ISiAllocator*>(field_1208));
        if (field_11a0 != nullptr) {
            reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)->vf3();
            field_11a0 = nullptr;
        }
        SiSDK3::SiGfxNXDevice* sigfx = reinterpret_cast<SiSDK3::SiGfxNXDevice*>(reinterpret_cast<SiSDK3::SiGfxKernel*>(Unk_4cbf40_get())->vf8(8, 0));
        field_11a0 = reinterpret_cast<Unk_CommandListMaker*>(sigfx);
        if (sigfx == nullptr) {
            Unk_4cbdd0();
            return 1;
        }
        sigfx->vf80(false);
        s32 (*registerTexture)(u64, u64, u64) = reinterpret_cast<s32 (*)(u64, u64, u64)>(desc->field_20);
        u64 (*registerSampler)(u64, u64) = reinterpret_cast<u64 (*)(u64, u64)>(desc->field_28);
        u64 (*releaseTexture)(u32, u64) = reinterpret_cast<u64 (*)(u32, u64)>(desc->field_30);
        u64 (*releaseSampler)(u32, u64) = reinterpret_cast<u64 (*)(u32, u64)>(desc->field_38);
        void* registerTextureArg = desc->field_40;
        void* registerSamplerArg = desc->field_48;
        void* releaseTextureArg = desc->field_50;
        void* releaseSamplerArg = desc->field_58;
        if (registerTexture == nullptr && releaseTexture == nullptr) {
            s32 first = Unk_238c2e4;
            s32 count = Unk_238c2e8;
            if (first < 0) {
                first = reinterpret_cast<s32 (*)(void*)>(Unk_27fca10)(Unk_24e09d0) - count;
            }
            int reserved;
            nvnDeviceGetInteger(desc->field_18, 0x11, &reserved);
            int size;
            nvnDeviceGetInteger(desc->field_18, 0x24, &size);
            field_1210.clear();
            for (s32 i = 0; i < count; i++) {
                field_1210.push_back(first + i);
            }
            registerTexture = reinterpret_cast<s32 (*)(u64, u64, u64)>(&CPostEffect::DefaultRegisterTextureHandleCallback_Nvn);
            releaseTexture = reinterpret_cast<u64 (*)(u32, u64)>(&CPostEffect::Unk_43b370);
            registerTextureArg = nullptr;
            releaseTextureArg = nullptr;
        }
        if (registerSampler == nullptr && releaseSampler == nullptr) {
            s32 first = Unk_238c2e4;
            s32 count = Unk_238c2e8;
            if (first < 0) {
                first = reinterpret_cast<s32 (*)(void*)>(Unk_27fca50)(Unk_24e09d8) - count;
            }
            int reserved;
            nvnDeviceGetInteger(desc->field_18, 0x12, &reserved);
            int size;
            nvnDeviceGetInteger(desc->field_18, 0x25, &size);
            field_1228.clear();
            for (s32 i = 0; i < count; i++) {
                field_1228.push_back(first + i);
            }
            registerSampler = reinterpret_cast<u64 (*)(u64, u64)>(&CPostEffect::DefaultRegisterSamplerHandleCallback_Nvn);
            releaseSampler = reinterpret_cast<u64 (*)(u32, u64)>(&CPostEffect::Unk_43b500);
            registerSamplerArg = nullptr;
            releaseSamplerArg = nullptr;
        }
        SiSDK3::Unk_4f96c0_Desc deviceDesc;
        deviceDesc.field_51 = 0;
        deviceDesc.field_52 = 0;
        deviceDesc.field_53 = 0;
        deviceDesc.field_5c = 0;
        deviceDesc.field_64 = 0;
        deviceDesc.field_68 = 0;
        deviceDesc.field_6c = 0x20;
        deviceDesc.field_70 = 0x400;
        deviceDesc.field_7c = 0;
        deviceDesc.field_80 = 0x100;
        deviceDesc.field_84 = 0;
        deviceDesc.field_8c = 0;
        deviceDesc.field_94 = 0;
        deviceDesc.field_a4 = 0x80000;
        deviceDesc.field_b5 = 0;
        if (!reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)
                 ->vf88(&deviceDesc, desc->field_18, 0, registerTexture, registerSampler, releaseTexture,
                         releaseSampler, reinterpret_cast<u64>(registerTextureArg),
                         reinterpret_cast<u64>(registerSamplerArg), reinterpret_cast<u64>(releaseTextureArg),
                         reinterpret_cast<u64>(releaseSamplerArg))) {
            if (field_11a0 != nullptr) {
                reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)->vf3();
                field_11a0 = nullptr;
            }
            Unk_4cbdd0();
            return 1;
        }
#line 41929
        PPFX_LOG("CPostEffect::CreateInternalResource_SiGfx(): SiGfxGetKernel()->CreateDevice() succeeded.\n");
        if (field_11a8 != nullptr) {
            reinterpret_cast<SiSDK3::ISiInterface*>(field_11a8)->vf3();
            field_11a8 = nullptr;
        }
        {
            u16 contextDesc = 0;
            field_11a8 = reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)->vf21(1, 0, &contextDesc, nullptr);
        }
        if (field_11a8 == nullptr) {
            if (field_11a0 != nullptr) {
                reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)->vf3();
                field_11a0 = nullptr;
            }
            Unk_4cbdd0();
            return 1;
        }
        *device = field_11a8;
#line 41946
        PPFX_LOG("CPostEffect::CreateInternalResource_SiGfx(): ISiGfxDrawContext::CreateDrawContext() succeeded.\n");
        if (field_1198 != nullptr) {
            reinterpret_cast<SiSDK3::ISiInterface*>(field_1198)->vf3();
            field_1198 = nullptr;
        }
        field_1198 =
            reinterpret_cast<Unk_CommandList*>(reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)->vf22(1, 0, nullptr));
        if (field_1198 == nullptr) {
            if (field_11a0 != nullptr) {
                reinterpret_cast<SiSDK3::SiGfxNXDevice*>(field_11a0)->vf3();
                field_11a0 = nullptr;
            }
            Unk_4cbdd0();
            return 1;
        }
        if (field_11c0 != nullptr) {
            reinterpret_cast<SiSDK3::ISiInterface*>(field_11c0)->vf3();
            field_11c0 = nullptr;
        }
#line 41960
        PPFX_LOG("CPostEffect::CreateInternalResource_SiGfx(): ISiGfxDevice::CreateCommandList() succeeded.\n");
        field_1170 = true;
    }
    return 0;
}

// 0x7100423160: the render pass of two device objects (made the first time:
// a texture wrapping them, a render target with it and a render pass with
// the target)
// NON_MATCHING: only the emplace's search loop is laid out differently
// (the same difference as 0x710043b590's)
u64 CPostEffect::Unk_423160(u64 arg1, u64 arg2, void* context_) {
    if (arg1 == 0) {
        return 0;
    }
    auto it = field_11e8.find(std::make_pair(arg1, arg2));
    if (it != field_11e8.end()) {
        return reinterpret_cast<u64>(it->second.first);
    }
    Unk_SiGfxDrawContext* context = static_cast<Unk_SiGfxDrawContext*>(context_);
    if (context == nullptr) {
        context = field_18->field_30;
    }
    Unk_SiGfxDevice* device = context->vf5();
    Unk_SiGfxWrappedTexture* texture = device->vf69(nullptr, 0, nullptr);
    if (texture->vf27(arg1, arg2)) {
        Unk_SiGfxWrappedTarget* target =
            reinterpret_cast<Unk_SiGfxWrappedTarget*>(device->vf72(nullptr, 0, nullptr));
        if (target != nullptr) {
            target->vf18();
            target->vf20(0, texture);
            target->vf25();
            if (texture != nullptr) {
                texture->vf3();
            }
            Unk_SiGfxRenderTarget* pass = device->vf29(1, 0, nullptr);
            if (pass == nullptr) {
                target->vf3();
                return 0;
            }
            pass->vf8();
            *pass->vf10() = target;
            pass->vf9();
            field_11e8.emplace(std::make_pair(arg1, arg2),
                               std::make_pair(reinterpret_cast<SiSDK3::ISiInterface*>(pass),
                                              reinterpret_cast<SiSDK3::ISiInterface*>(target)));
            return reinterpret_cast<u64>(pass);
        }
    }
    if (texture != nullptr) {
        texture->vf3();
    }
    return 0;
}

// 0x7100423630
s32 CPostEffect::Unk_423630(bool enable) {
    field_895 = true;
    s32 result = 0;
    if (!field_1b8) {
        enable = false;
        result = 1;
    }
    field_bcd = enable;
    return result;
}

// 0x7100423850
s32 CPostEffect::SetAntialiasType(s32 type) {
    if (type < 0) {
        if (field_544 & 1) {
            type = 1;
        } else {
            type = (field_544 & 2) ? 2 : 1;
        }
    }
    if (type < 1 || type > 2) {
#line 13852
        PPFX_WARNING("CPostEffect::SetAntialiasType(): invalid argument.\n");
        field_f44 = 1;
        return 1;
    }
    if (!field_1ca && field_f44 == 2) {
#line 13862
        PPFX_WARNING("CPostEffect::SetAntialiasType(): Initialize with PFX_INITPARAM::m_uiAntialiasFlags |= PFXAA_SMAA.\n");
        field_f44 = 1;
        return 1;
    }
    field_f44 = type;
    return 0;
}

// The bodies of Unk_423990 and Unk_423ba0, which the game's code named as
// functions of (u64, u32).
// NON_MATCHING: the first two branches are swapped. The original tests the
// object's flag before the parameter, the order a bool parameter gives (an
// Argument is the second operand of the merged condition); the value computed
// from a u32 parameter comes first.
inline s32 CPostEffect::SetLightShaftEnable(bool enable) {
    bool available = field_198->field_108;
    if (available || enable) {
        if (available) {
            Unk_LightShaft(field_860).field_60 = false;
        }
        if (enable) {
            if (available) {
                Unk_LightShaft(field_860).field_60 = true;
            } else {
#line 12760
                PPFX_WARNING("CPostEffect::SetLightShaftEnable(): Initialize() with PFXINIT_LIGHTSHAFT flag for light shafts.\n");
                return 1;
            }
        }
    }
    return 0;
}

inline s32 CPostEffect::SetLightGhostEnable(bool enable) {
    bool available = field_198->field_110;
    if (available || enable) {
        if (available) {
            Unk_LightGhost(field_870).field_0 = false;
        }
        if (enable) {
            if (available) {
                Unk_LightGhost(field_870).field_0 = true;
            } else {
#line 12679
                PPFX_WARNING("CPostEffect::SetLightGhostEnable()\n");
                return 1;
            }
        }
    }
    return 0;
}

}  // namespace PPFX

// CPostEffect's functions that the game calls keep the placeholder names its
// code gave them (the object is their first argument); their log lines name them.

// the kinds of formats 0x7100423480 tells apart (inline)
static inline bool Unk_423480_B(s32 format) {
    return (format >= 1 && format <= 4) || (format >= 9 && format <= 12);
}
static inline bool Unk_423480_C(s32 format) {
    switch (format) {
    case 13:
    case 14:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 65:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 82:
    case 83:
    case 86:
    case 87:
        return true;
    default:
        return false;
    }
}

// 0x7100423480: whether a format is one of three kinds (placeholder). The
// first kind's switch is written here with the result assigned in its cases:
// the default edge then reaches the join directly, so the result's 0 is set
// at the entry (as an inline returning true or false, the cases' edge is the
// direct one and the second kind's test is duplicated).
bool Unk_423480(s32 format) {
    bool result = false;
    switch (format) {
    case 0:
        return false;
    case 2:
    case 10:
    case 24:
    case 28:
        result = true;
        break;
    }
    if (Unk_423480_B(format)) {
        return true;
    }
    if (Unk_423480_C(format)) {
        return true;
    }
    return result;
}

// 0x71004234f0: CPostEffect::SetActiveView
s32 Unk_4234f0(u64 self_, u32 index_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 index = index_;
#line 11029
    PPFX_FN("Frame: %d, View: %d, SetActiveView(iEffectViewIndex: %d);\n", self->Unk_Frame(self->field_298), self->field_298, index);
    if (self->field_0) {
#line 11037
        PPFX_ERROR("CPostEffect::SetActiveView(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    if (index < 0) {
        return -6;
    }
    if (self->field_400 < index) {
        return -6;
    }
    self->field_298 = index;
    if (self->field_198 != nullptr) {
        self->field_198->field_2ec = index;
    }
    return 0;
}

// 0x7100423660: CPostEffect::SetLensDistortionEnable
s32 Unk_423660(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    s32 result = 0;
    if (!self->field_1b9) {
        if (enable) {
#line 13283
            PPFX_WARNING("CPostEffect::SetLensDistortionEnable(): Initialize() with PFXINIT_LENSDISTORTION flag for lens distortion.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_be4 = enable;
    return result;
}

// 0x71004236f0: CPostEffect::SetGaussianBlurEnable
s32 Unk_4236f0(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    s32 result = 0;
    if (!self->field_1c0) {
        if (enable) {
#line 13636
            PPFX_WARNING("CPostEffect::SetGaussianBlurEnable(): Initialize() with PFXINIT_GAUSSIANBLUR flag for feedback.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_c7a = enable;
    return result;
}

// 0x71004237b0: CPostEffect::SetAntialiasEnable
s32 Unk_4237b0(u64 self_, u32 enable_, u32 quiet_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    bool quiet = quiet_ & 1;
    s32 result = 0;
    if (!self->field_1c8) {
        if (enable && !quiet) {
#line 13786
            PPFX_WARNING("CPostEffect::SetAntialiasEnable(): Initialize() with PFXINIT_ANTIALIAS flag for post-process antialias.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_f38 = enable;
    return result;
}

// 0x7100423990: CPostEffect::SetLightShaftEnable
s32 Unk_423990(u64 self_, bool enable_) {
    return reinterpret_cast<PPFX::CPostEffect*>(self_)->SetLightShaftEnable(enable_);
}

// 0x7100423ba0: CPostEffect::SetLightGhostEnable
s32 Unk_423ba0(u64 self_, bool enable_) {
    return reinterpret_cast<PPFX::CPostEffect*>(self_)->SetLightGhostEnable(enable_);
}

// 0x7100423d00: CPostEffect::SetMotionBlurEnable
s32 Unk_423d00(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    self->field_895 = true;
    s32 result = 0;
    if (!self->field_1bc) {
        if (enable) {
#line 13999
            PPFX_WARNING("CPostEffect::SetMotionBlurEnable(): Initialize() with PFXINIT_MOTIONBLUR flag for motion blur.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_ce5 = enable;
    return result;
}

// 0x7100423e20: CPostEffect::SetFeedbackEnable
s32 Unk_423e20(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    s32 result = 0;
    if (!self->field_1c6) {
        if (enable) {
#line 16798
            PPFX_WARNING("CPostEffect::SetFeedbackEnable(): Initialize() with PFXINIT_FEEDBACK flag for feedback.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_bce = enable;
    return result;
}

// 0x7100423780
s32 Unk_423780(u64 self_, const PPFX::Unk_Rect* value, bool a, bool b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_c7c = *value;
    self->field_c8c = c;
    self->field_c90 = a;
    self->field_c91 = b;
    return 0;
}

// 0x7100423b50: two numbers of the light shaft that is being set
s32 Unk_423b50(u64 self_, f32 a, f32 b) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::Unk_Float2 value(a, b);
    s32 view = self->field_860;
    self->field_858[view].field_44 = value;
    return 0;
}

// 0x7100423cd0: the same of the light ghost
s32 Unk_423cd0(u64 self_, f32 a, f32 b) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::Unk_Float2 value(a, b);
    s32 view = self->field_870;
    self->field_868[view].field_14 = value;
    return 0;
}

// 0x71004253e0: two scales (1 for none) and two more numbers
s32 Unk_4253e0(u64 self_, f32 a, f32 b, f32 c, f32 d) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_5a4 = a == 0.0f ? 1.0f : a;
    self->field_5a8 = b == 0.0f ? 1.0f : b;
    self->field_5ac = c;
    self->field_5b0 = d;
    return 0;
}

// 0x7100429da0: a number of a view's settings (-1: the active view)
f32 Unk_429da0(u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    return self->field_2a0[view].field_60;
}

// 0x7100429e60
f32 Unk_429e60(u64 self_, u32 view_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 view = view_;
    if (view == -1) {
        view = self->field_298;
    }
    return self->field_2a8[view].field_38;
}

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

// 0x71004346f0
s32 PPFX::CPostEffect::EndPostEffectScene(u32 flags, s32 samples) {
#line 29992
    PPFX_FN("Frame: %d, View: %d, EndPostEffectScene(uiEffectFlags: %08x, nManualMultisamples: %d);\n",
            Unk_Frame(field_298), field_298, flags, samples);
    s32 result = EndPostEffectScene_Process(flags, samples);
    if (result < 0) {
#line 30002
        PPFX_ERROR("CPostEffect::EndPostEffectScene(): EndPostEffectScene_Process() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
    }
    result = EndCommandList_SiGfx();
    return result < 0 ? result : 0;
}

// 0x7100425240: CPostEffect::SetMultisampleMode
s32 Unk_425240(u64 self_, u32 mode) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (self->field_0) {
#line 12316
        PPFX_ERROR("CPostEffect::SetMultisampleMode(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    self->field_6b0 = mode;
    if (self->field_1d3) {
        self->field_6b4 = 0;
        return 1;
    }
    PPFX::Unk_4a5d10_Self* textures = self->field_190;
    PPFX::Unk_RenderTexture* texture = textures->field_50;
    void* multisampled = textures->field_58;
    bool single = texture->field_54 == 0 && texture->field_58 == 0;
    bool multi = multisampled != nullptr;
    if (!multi) {
        if (mode == 3) {
            mode = 0;
        } else if (mode == 1) {
#line 12368
        PPFX_ERROR("CPostEffect::SetMultisampleMode(): Cannot set multisample mode to PFXMSM_SINGLESAMPLE.\n");
        return -6;
        }
    }
    if (single && mode == 2) {
#line 12380
        PPFX_ERROR("CPostEffect::SetMultisampleMode(): Cannot set multisample mode to PFXMSM_MULTISAMPLE.\n");
        return -6;
    }
    u32 value = mode == 3 ? 1 : (mode == 2 ? 0 : mode);
    self->field_6b4 = value;
    textures->field_94 = value;
    return 0;
}

// 0x7100425c50
s32 PPFX::CPostEffect::BeginCommandList_SiGfx() {
    if (field_11a0 != nullptr) {
        Unk_SiGfxDrawContext* context = field_18->field_30;
        void* current = context->vf10();
        if (current != nullptr) {
            if (current != field_11b0) {
                return -1;
            }
        } else {
            field_11b8 = field_11c8;
            if (field_11c8) {
                if (field_11c0 == nullptr) {
                    field_11c0 = field_11a0->vf22(1, 0, nullptr);
                }
                field_11b0 = field_11c0;
            } else {
                field_11b0 = field_1198;
                if (field_1200 == nullptr) {
#line 42012
                    PPFX_ERROR("CPostEffect::BeginCommandList_SiGfx(): m_pCurrentNVNcommandBuffer==NULL. Please call SetCurrentCommandBuffer_Nvn().\n");
                    return -1;
                }
                field_1198->vf18(field_1200);
            }
            if (!context->vf8(field_11b0)) {
#line 42025
                PPFX_ERROR("CPostEffect::BeginCommandList_SiGfx(): Failed pSiGfxDrawContext->BeginCommandList(m_pCurrentUsedSiGfxCommandList).\n");
                return -1;
            }
        }
    }
    field_11cc++;
    return 0;
}

namespace PPFX {

// what field_d8 maps a device surface to, as the post effect releases it
// (placeholder)
struct Unk_43c4e0 {
    virtual void vf0();
    virtual void vf1();  // releases a reference
};

}  // namespace PPFX

namespace PPFX {
// 0x7100446e60: the sample count of a number of samples (Unk_447050.cpp)
u32 Unk_446e60(s32 count);
}  // namespace PPFX

// 0x71004397e0
s32 PPFX::CPostEffect::Unk_4397e0(u64 key, u32 arg2, u32 arg3, u32 format, u32 arg5, u32 arg6, Unk_43c4e0** out) {
    if (field_18 == nullptr) {
        return -1;
    }
    Unk_43c4e0* object = nullptr;
    auto it = field_d8.find(key);
    u32 samples = Unk_446e60(arg5);
    if (it != field_d8.end()) {
        object = it->second;
    } else {
        s32 result = field_18->vf67(arg2, arg3, format, samples, arg6, reinterpret_cast<void*>(key),
                                    reinterpret_cast<IGPUInterface**>(&object));
        if (result < 0) {
            return result;
        }
        field_d8.insert(std::pair<const u64, Unk_43c4e0*>(key, object));
    }
    if (out != nullptr) {
        *out = object;
    }
    return 0;
}

// 0x71004399e0: CPostEffect::UnregisterDeviceSurface (its log lines name it)
s32 PPFX::CPostEffect::Unk_4399e0(SiSDK3::ISiInterface* object, void* arg2) {
    if (field_0) {
#line 36463
        PPFX_ERROR("CPostEffect::UnregisterDeviceSurface(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    auto it = field_d8.find(reinterpret_cast<u64>(object));
    if (it == field_d8.end()) {
        return -6;
    }
    if (arg2 != nullptr) {
#line 36497
        PPFX_ERROR("CPostEffect::UnregisterDeviceSurface(): Unable to replace the resource.\nThe specified resources are not compatible with each other.");
        return -6;
    }
    Unk_43c4e0* surface = it->second;
    if (surface == field_120) {
#line 36511
        PPFX_ERROR("CPostEffect::UnregisterDeviceSurface(): The resource is currently bound for SetTonemapDestination().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    field_d8.erase(it);
    if (surface != nullptr) {
        surface->vf1();
    }
    return 0;
}

namespace PPFX {

// what field_f0 maps a device texture to, as the post effect releases it
// (placeholder)
struct Unk_43c490 {
    virtual void vf0();
    virtual void vf1();  // releases a reference
};

}  // namespace PPFX

// 0x7100439c10: CPostEffect::UnregisterDeviceTexture (its log lines name it)
s32 PPFX::CPostEffect::Unk_439c10(SiSDK3::ISiInterface* object, void* arg2) {
    if (object == nullptr) {
        return -6;
    }
    if (object == arg2) {
#line 36550
        PPFX_WARNING("CPostEffect::UnregisterDeviceTexture(): Specified resources gpuTexture and gpuNewTexture are the same.\n");
        return 1;
    }
    if (field_0) {
#line 36557
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    auto it = field_f0.find(reinterpret_cast<u64>(object));
    if (it == field_f0.end()) {
        return -6;
    }
    if (arg2 != nullptr) {
#line 36590
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): Unable to replace the resource.\nThe specified resources are not compatible with each other.");
        return -6;
    }
    Unk_43c490* texture = it->second;
    if (field_50 != nullptr &&
        texture == reinterpret_cast<Unk_43c490*>(reinterpret_cast<CRenderTexture*>(field_50)->Unk_Root()->field_a8)) {
#line 36606
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): The resource is currently bound for SetDepthFactorSource().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    if (field_70 != nullptr &&
        texture == reinterpret_cast<Unk_43c490*>(reinterpret_cast<CRenderTexture*>(field_70)->Unk_Root()->field_a8)) {
#line 36618
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): The resource is currently bound for SetEffectSource().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    if (field_80 != nullptr &&
        texture == reinterpret_cast<Unk_43c490*>(reinterpret_cast<CRenderTexture*>(field_80)->Unk_Root()->field_a8)) {
#line 36630
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): The resource is currently bound for SetDepthOfFieldDepthRemapLutSource().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    if (field_b8 != nullptr &&
        texture == reinterpret_cast<Unk_43c490*>(reinterpret_cast<CRenderTexture*>(field_b8)->Unk_Root()->field_a8)) {
#line 36642
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): The resource is currently bound for SetGlareModulatorSource().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    if (field_178 == texture) {
#line 36653
        PPFX_ERROR("CPostEffect::UnregisterDeviceTexture(): The resource is currently bound for SetColorGradingLutSource().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    auto found = field_108.find(reinterpret_cast<u64>(object));
    Unk_RenderTexture* renderTexture = found != field_108.end() ? found->second : nullptr;
    bool release = renderTexture != nullptr;
    field_f0.erase(it);
    if (texture != nullptr) {
        texture->vf1();
    }
    if (release) {
        field_108.erase(found);
        reinterpret_cast<CRenderTexture*>(renderTexture)->Unk_Release();
    }
    return 0;
}

// 0x7100439630: CPostEffect::ApplyEffects
s32 Unk_439630(u64 self_, u32 flags) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 34180
    PPFX_FN("Frame: %d, View: %d, ApplyEffects(uiEffectFlags: %08x);\n", self->Unk_Frame(self->field_298),
            self->field_298, flags);
    if (self->field_0) {
#line 34189
        PPFX_ERROR("CPostEffect::ApplyEffects(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    u32 mode;
    if (self->field_1d3) {
        if (self->field_70 == nullptr) {
#line 34214
            PPFX_ERROR("CPostEffect::ApplyEffects(): At least SetEffectSource() must be called if initialized with PFXINIT_RENDERSCENE_EXTERNAL flag.\n");
            return -1;
        }
        mode = self->field_6b0;
        self->field_6b0 = 3;
        self->field_6b4 = 0;
    } else {
        mode = self->field_6b0;
        self->field_6b0 = 3;
        u32 has = self->field_190->field_58 != nullptr;
        self->field_6b4 = has;
        self->field_190->field_94 = has;
    }
    self->BeginPostEffectScene(0, nullptr, -3.40282347e+38f, 0, -1);
    s32 result = self->EndPostEffectScene(flags, 0);
    Unk_425240(self_, mode);
    return result < 0 ? result : 0;
}

// 0x710043b580
void Unk_43b580(u64 self_, bool value) {
    reinterpret_cast<PPFX::CPostEffect*>(self_)->field_11c8 = value;
}

// the larger of two numbers (inline)
static inline const PPFX::Unk_Float& Unk_Max(const PPFX::Unk_Float& a, const PPFX::Unk_Float& b) {
    return a.field_0 < b.field_0 ? b : a;
}

// 0x71004248b0: CPostEffect::SetAutoExposureAdjustment (its log line names it)
// NON_MATCHING: the original moves the adaptation scale and speed limit into
// w21 and w22 at the entry (before the log line) and selects them as integers
// there; here their integer copies are made after the call, and the
// registers and the order of the clamps differ from there on
s32 Unk_4248b0(f32 sensitivity, PPFX::Unk_Float scale, PPFX::Unk_Float speed, f32 darkSensitivity, f32 darkScale,
               f32 darkSpeed, f32 border, u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 19192
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureAdjustment(iEffectViewIndex: %d, fAdaptationSensitivity: %f, fAdaptationScale: %f, fAdaptationSpeedLimit: %f, fDarkAdaptationSensitivity: %f, fDarkAdaptationScale: %f, fDarkAdaptationSpeedLimit: %f, fLightDarkExposureBorder: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, sensitivity, scale.field_0, speed.field_0,
            darkSensitivity, darkScale, darkSpeed, border);
    sensitivity = sensitivity < 0.0f ? 0.0f : (sensitivity > 1.0f ? 1.0f : sensitivity);
    PPFX::Unk_Float speedLimit = speed.field_0 > 0.0f ? speed : PPFX::Unk_Float(0.0f);
    PPFX::Unk_Float scaleLimit = scale.field_0 > 0.0f ? scale : PPFX::Unk_Float(0.0f);
    if (darkSensitivity < 0.0f) {
        darkSensitivity = sensitivity;
    }
    if (darkScale < 0.0f) {
        darkScale = scaleLimit.field_0;
    }
    if (darkSpeed < 0.0f) {
        darkSpeed = speedLimit.field_0;
    }
    PPFX::Unk_Float darkSpeedLimit = darkSpeed > 0.0f ? PPFX::Unk_Float(darkSpeed) : PPFX::Unk_Float(0.0f);
    PPFX::Unk_Float darkScaleLimit = darkScale > 0.0f ? PPFX::Unk_Float(darkScale) : PPFX::Unk_Float(0.0f);
    f32 dark = darkSensitivity * darkSensitivity * (3.0f - (darkSensitivity + darkSensitivity));
    if (darkScaleLimit.field_0 < 0.0f || scaleLimit.field_0 < 0.0f || darkSpeedLimit.field_0 < 0.0f ||
        speedLimit.field_0 < 0.0f || dark < 0.0f || sensitivity < 0.0f || dark > 1.0f) {
        return -6;
    }
    self->field_f6c = 1.0f;
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    for (s32 i = 0; i < self->field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            PPFX::Unk_429da0_Item* item = &self->field_2a0[i];
            if (item->field_70 == nullptr) {
                result = 1;
            }
            item->field_38 = border;
            item->field_3c = sensitivity;
            item->field_40 = scaleLimit.field_0;
            item->field_44 = speedLimit.field_0;
            item->field_48 = dark;
            item->field_4c = darkScaleLimit.field_0;
            item->field_50 = darkSpeedLimit.field_0;
        }
    }
    return result;
}

// 0x7100424f40: CPostEffect::SetAutoExposureMeteringArea (its log line names
// it): the area made positive and moved and cut into the unit square;
// returns 1 if a view has no luminance to meter
s32 Unk_424f40(f32 width, f32 height, f32 x, f32 y, u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18979
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMeteringArea(iEffectViewIndex: %d, fWidth: %f, fHeight: %f, fOffsetX: %f, fOffsetY: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, width, height, x, y);
    if (width < 0.0f) {
        x = x + width;
        width = -width;
    }
    if (height < 0.0f) {
        y = y + height;
        height = -height;
    }
    if (x + width < 0.0f) {
        x = x - (x + width);
    }
    if (y + height < 0.0f) {
        y = y - (y + height);
    }
    if (x < 0.0f) {
        width = width + x;
        x = 0.0f;
    }
    if (y < 0.0f) {
        height = height + y;
        y = 0.0f;
    }
    PPFX::Unk_Float left = x < 1.0f ? PPFX::Unk_Float(x) : PPFX::Unk_Float(1.0f);
    PPFX::Unk_Float top = y < 1.0f ? PPFX::Unk_Float(y) : PPFX::Unk_Float(1.0f);
    if (left.field_0 + width > 1.0f) {
        width = width - (left.field_0 + width - 1.0f);
    }
    if (top.field_0 + height > 1.0f) {
        height = height - (top.field_0 + height - 1.0f);
    }
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    for (s32 i = 0; i < self->field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            PPFX::Unk_429da0_Item* item = &self->field_2a0[i];
            if (item->field_70 == nullptr) {
                result = 1;
            }
            item->field_c = width;
            item->field_10 = height;
            item->field_14 = left.field_0;
            item->field_18 = top.field_0;
        }
    }
    return result;
}

// 0x7100423a50: the light shaft that is being set
s32 Unk_423a50(u64 self_, const PPFX::Unk_Rect* rect, u32 mode, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->Unk_LightShaft(self->field_860).field_0 = *rect;
    self->Unk_LightShaft(self->field_860).field_1c = a;
    self->Unk_LightShaft(self->field_860).field_10 = b;
    self->Unk_LightShaft(self->field_860).field_5c = c;
    self->Unk_LightShaft(self->field_860).field_64 = mode;
    self->Unk_LightShaft(self->field_860).field_20 = d;
    self->Unk_LightShaft(self->field_860).field_14 = e;
    self->Unk_LightShaft(self->field_860).field_18 = f;
    return 0;
}

// 0x7100423ae0: more of the light shaft
s32 Unk_423ae0(u64 self_, const PPFX::Unk_Rect* rect, f32 a, f32 b, f32 c, f32 d) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->Unk_LightShaft(self->field_860).field_24 = a;
    self->Unk_LightShaft(self->field_860).field_30 = b;
    self->Unk_LightShaft(self->field_860).field_28 = c;
    self->Unk_LightShaft(self->field_860).field_2c = d;
    self->Unk_LightShaft(self->field_860).field_34 = *rect;
    return 0;
}

// 0x7100423c60: the light ghost that is being set
s32 Unk_423c60(u64 self_, const PPFX::Unk_Rect* rect, u32 arg2, u32 arg3, f32 a, f32 b) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->Unk_LightGhost(self->field_870).field_4 = *rect;
    self->Unk_LightGhost(self->field_870).field_24 = arg2;
    self->Unk_LightGhost(self->field_870).field_28 = a;
    self->Unk_LightGhost(self->field_870).field_2c = b;
    self->Unk_LightGhost(self->field_870).field_30 = arg3;
    return 0;
}

// 0x7100423db0
s32 Unk_423db0(u64 self_, s32 count, u32 arg2, PPFX::Unk_Float a, PPFX::Unk_Float b, PPFX::Unk_Float c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::Unk_Float x = a.field_0 > 0.0f ? a : PPFX::Unk_Float(0.0f);
    PPFX::Unk_Float y = b.field_0 > 0.0f ? b : PPFX::Unk_Float(0.0f);
    if (count >= 0) {
        count = count < 3 ? 3 : std::min(count, 8);
    }
    PPFX::Unk_Float z = c.field_0 > 1.0f ? c : PPFX::Unk_Float(1.0f);
    self->field_cf0 = x;
    self->field_cf4 = y;
    self->field_cf8 = count;
    self->field_cfc = arg2;
    self->field_d00 = z;
    return 0;
}

// 0x71004243c0: CPostEffect::SetGlareParameters
s32 Unk_4243c0(u64 self_, u32 mode, f32 a, f32 b, PPFX::Unk_Float remap) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (remap.field_0 <= 0.0f) {
#line 12183
        PPFX_ERROR("CPostEffect::SetGlareParameters(): GlareRemapFactor must be greater than 0.0.\n");
        return -1;
    }
    self->field_848 = a;
    self->field_844 = b;
    self->field_f78 = mode;
    self->field_f7c = Unk_Max(0.001f, remap);
    return 0;
}

// 0x7100424670: CPostEffect::SetDeltaTime
s32 Unk_424670(PPFX::CPostEffect* self, f32 elapsed) {
#line 11492
    PPFX_FN("Frame: %d, View: %d, SetDeltaTime(fElapsedTimeInSeconds: %f);\n", self->Unk_Frame(self->field_298), self->field_298, elapsed);
    self->field_7f4 = elapsed;
    return 0;
}

// CPostEffect::SetTonemapExposure, SetTonemapFunction and SetTonemapBackend
// (inline: they have no code of their own)
static inline s32 Unk_SetTonemapExposure(PPFX::CPostEffect* self, f32 exposure) {
#line 17619
    PPFX_FN("Frame: %d, View: %d, SetTonemapExposure(fExposure: %f);\n", self->Unk_Frame(self->field_298), self->field_298,
            exposure);
    PPFX::Unk_Float value = Unk_Max(1.17549435e-38f, exposure);
    if (value.field_0 < 0.0f) {
        return -6;
    }
    self->field_8c0 = value;
    return 0;
}
static inline s32 Unk_SetTonemapFunction(PPFX::CPostEffect* self, u32 tonemap, f32 factor) {
#line 17671
    PPFX_FN("Frame: %d, View: %d, SetTonemapFunction(eTonemap: %d, fMappingFactor: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, tonemap, factor);
    self->field_8c8 = tonemap;
    if (self->field_59c) {
        self->field_8cc = 1.0f;
        self->field_8d0 = 1.0f / factor;
    } else {
        self->field_8cc = factor;
        self->field_8d0 = 1.0f;
    }
    return 0;
}
static inline s32 Unk_SetTonemapBackend(PPFX::CPostEffect* self, f32 gamma, f32 dither) {
#line 17843
    PPFX_FN("Frame: %d, View: %d, SetTonemapBackend(fGamma: %f, fDitherOffsetScale: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, gamma, dither);
    PPFX::Unk_Float value = Unk_Max(0.0f, gamma);
    if (value.field_0 < 0.0f) {
        return -6;
    }
    self->field_8c4 = value;
    self->field_968 = dither == 3.40282347e+38f ? 1.70141173e+38f : dither;
    return 0;
}

// 0x71004244a0: the tone map
// NON_MATCHING: the original selects the clamped exposure and gamma as
// integers (`fmov w23, s11` at the entry, `csel w8, w23, w8, gt`, the store a
// `str w8`) and compares the selected bits as a float; here they are
// `fmaxnm`s. Unk_Float parameters, by-value and by-reference maxima and
// two reads of the maximum were tried (as with Unk_423db0); also the
// helper taking an Unk_Float (by value or reference), the maximum bound to a
// reference of named locals (so that the member's store copies through the
// selected pointer) and the arguments swapped: all give the float select.
// The callers
// (lib/yebis/leaf's Unk_418470_call and its game caller) don't pass the
// floats yet.
s32 Unk_4244a0(u64 self_, u32 tonemap, f32 exposure, f32 gamma, f32 factor, f32 dither) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    Unk_SetTonemapExposure(self, exposure);
    Unk_SetTonemapFunction(self, tonemap, factor);
    return Unk_SetTonemapBackend(self, gamma, dither);
}

// 0x71004246f0
s32 Unk_4246f0(u64 self_, const PPFX::Unk_Rect* rect, f32 a, f32 b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (self->field_1a0 != nullptr) {
        self->field_1a0->field_3a8 = false;
    }
    if (a == 0.0f) {
        self->field_918 = 0;
        return 0;
    }
    self->field_918 = 1;
    self->field_91c = a;
    self->field_920 = b;
    self->field_924 = c;
    self->field_928 = *rect;
    return 0;
}

// 0x71004276e0: a camera's numbers (1, 1000 and tan(22.5 degrees) for none)
s32 Unk_4276e0(u64 self_, f32 a, f32 b, f32 c, f32 d, f32 e) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_895 = true;
    if (a <= 0.0f) {
        a = 1.0f;
    }
    if (b <= 0.0f) {
        b = 1000.0f;
    }
    if (c <= 0.0f) {
        c = 0.41421356f;
    }
    self->field_6d4 = d;
    self->field_6d8 = e;
    self->field_6c4 = a;
    self->field_6c8 = b;
    self->field_6d0 = c;
    self->field_6cc = atanf(c) * 2.0f;
    return 0;
}

// 0x71004275e0: CPostEffect::SetRenderScenePerspective
s32 Unk_4275e0(PPFX::CPostEffect* self, f32 nearZ, f32 farZ, f32 fov) {
#line 11507
    PPFX_FN("Frame: %d, View: %d, SetRenderScenePerspective(fNear: %f, fFar: %f, fVerticalFov: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, nearZ, farZ, fov);
    f32 tangent = tanf(fov * 0.5f);
    self->field_895 = true;
    if (nearZ <= 0.0f) {
        nearZ = 1.0f;
    }
    if (farZ <= 0.0f) {
        farZ = 1000.0f;
    }
    if (tangent <= 0.0f) {
        tangent = 0.41421356f;
    }
    self->field_6c4 = nearZ;
    self->field_6c8 = farZ;
    self->field_6d0 = tangent;
    self->field_6d4 = 0.0f;
    self->field_6d8 = 0.0f;
    self->field_6cc = atanf(tangent) * 2.0f;
    return 0;
}

// CPostEffect::SetRenderSceneLuminanceScale (inline: it has no code of its own)
static inline s32 Unk_SetRenderSceneLuminanceScale(PPFX::CPostEffect* self, f32 scale) {
#line 11845
    PPFX_FN("Frame: %d, View: %d, SetRenderSceneLuminanceScale(fSceneLuminanceScale: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, scale);
    if (scale <= 0.0f) {
#line 11854
        PPFX_ERROR("CPostEffect::SetRenderSceneLuminanceScale(): SceneLuminanceScale mest be greater than zero.\n");
        return -6;
    }
    self->field_7f8 = scale;
    return 0;
}

// 0x7100424100: the scene's camera, time step and luminance scale
s32 Unk_424100(PPFX::CPostEffect* self, f32 nearZ, f32 farZ, f32 fov, f32 elapsed, f32 scale) {
    Unk_4275e0(self, nearZ, farZ, fov);
    Unk_424670(self, elapsed);
    return Unk_SetRenderSceneLuminanceScale(self, scale);
}

// 0x7100427760: the same of another camera
s32 Unk_427760(u64 self_, f32 a, f32 b, f32 c, f32 d, f32 e) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_895 = true;
    if (a <= 0.0f) {
        a = 1.0f;
    }
    if (b <= 0.0f) {
        b = 1000.0f;
    }
    if (c <= 0.0f) {
        c = 0.41421356f;
    }
    self->field_6ec = d;
    self->field_6f0 = e;
    self->field_6dc = a;
    self->field_6e0 = b;
    self->field_6e8 = c;
    self->field_6e4 = atanf(c) * 2.0f;
    return 0;
}

// 0x71004278c0
s32 Unk_4278c0(u64 self_, void* data) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (data == nullptr) {
        return -6;
    }
    self->field_f80 = -1;
    self->field_f84 = *static_cast<const PPFX::Unk_4278c0_Data*>(data);
    return 0;
}

// 0x71024e5948 (GPUGlareDef.cpp): the glare definitions
extern PPFX::Unk_4a0b00* Unk_24e5948;

namespace PPFX {

// the glare definition of a glare kind (a table set up the first time)
static inline u32 Unk_GlareDefinition(s32 kind) {
    static bool initialised = false;
    static u32 definitions[14];
    if (!initialised) {
        initialised = true;
        for (u32 i = 0; i < 14; i++) {
            definitions[i] = i;
        }
    }
    if (kind == -1) {
        return 0xffffffff;
    }
    return definitions[kind];
}

}  // namespace PPFX

// 0x7100427900: the settings of glare definition `index` (0 to 13)
// NON_MATCHING: only the merged statics: it matches once 0x710041afb0's
// statics exist (checked with a stand-in Initialize in a scratch copy)
PPFX::Unk_4278c0_Data* Unk_427900(u64 self_, void* data, u32 index) {
    if (data == nullptr || index > 13) {
        return nullptr;
    }
    u32 definition = PPFX::Unk_GlareDefinition(index);
    PPFX::Unk_4278c0_Data* out = static_cast<PPFX::Unk_4278c0_Data*>(data);
    const PPFX::Unk_4a0b00& glare = Unk_24e5948[definition];
    memcpy(out->field_0, &glare.field_8[0], sizeof(out->field_0));
    memcpy(out->field_10, &glare.field_8[4], sizeof(out->field_10));
    out->field_20 = glare.field_28;
    out->field_24 = glare.field_2c;
    memcpy(out->field_28, glare.field_30, sizeof(out->field_28));
    out->field_38 = glare.field_40;
    out->field_3c = glare.field_44;
    out->field_40 = glare.field_48;
    memcpy(out->field_44, glare.field_4c, sizeof(out->field_44));
    out->field_54 = glare.field_80.field_8;
    out->field_58 = glare.field_80.field_10;
    out->field_5c = glare.field_80.field_14;
    out->field_60 = glare.field_80.field_18;
    out->field_64 = glare.field_5c;
    out->field_68 = glare.field_60;
    out->field_6c = glare.field_64;
    memcpy(out->field_70, glare.field_6c, sizeof(out->field_70));
    out->field_80 = glare.field_68;
    return out;
}

namespace PPFX {

// the depth of field's edge blur of an edge quality type (a table set up the
// first time)
static inline s32 Unk_DofEdgeBlurType(s32 type) {
    static bool initialised = false;
    static s32 types[4];
    if (!initialised) {
        initialised = true;
        types[0] = 0;
        types[1] = 0;
        types[2] = 1;
        types[3] = 0;
    }
    return types[type];
}

}  // namespace PPFX

namespace PPFX {
// 0x7100446b20 (Unk_447050.cpp): a format's name
const char* Unk_446b20(s32 format, char* buffer);
}  // namespace PPFX

// 0x7100427c10: the device texture and render texture of a device texture
// (made the first time)
s32 PPFX::CPostEffect::Unk_427c10(u64 key, u32 arg2, u32 arg3, u32 format, void* arg5, Unk_RenderTexture** out) {
    if (field_18 == nullptr) {
        return -1;
    }
    Unk_43c490* texture = nullptr;
    auto it = field_f0.find(key);
    if (it != field_f0.end()) {
        texture = it->second;
    } else {
        s32 result = field_18->vf62(arg2, arg3, 0, 0, format, reinterpret_cast<void*>(key),
                                    reinterpret_cast<IGPUInterface**>(&texture));
        if (result < 0) {
            return result;
        }
        field_f0.insert(std::pair<const u64, Unk_43c490*>(key, texture));
    }
    Unk_RenderTexture* renderTexture;
    auto found = field_108.find(key);
    if (found != field_108.end()) {
        renderTexture = found->second;
    } else {
        Unk_TFXString name = Unk_TFXString("CRenderTexture::m_mapDeviceTextureRenderTexture[") +
                             Unk_4525a0(static_cast<s32>(key)) + ":" + Unk_446b20(format, nullptr) + "]";
        const char* text = name.field_8;
#line 36257
        CRenderTexture* made = UNK_NEW(CRenderTexture)(text);
        s32 result = made->vf6(field_18, reinterpret_cast<Unk_49b230_Object*>(texture));
        if (result < 0) {
            return result;
        }
        renderTexture = reinterpret_cast<Unk_RenderTexture*>(made);
        field_108.insert(std::pair<const u64, Unk_RenderTexture*>(key, renderTexture));
    }
    if (arg5 != nullptr) {
        *static_cast<Unk_43c490**>(arg5) = texture;
    }
    if (out != nullptr) {
        *out = renderTexture;
    }
    return 0;
}

// 0x7100428ec0
s32 Unk_428ec0(u64 self_, f32 a, f32 b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_895 = true;
    self->field_8b8 = PPFX::Unk_Float2(0.0f, 0.0f);
    self->field_898 = a;
    if (c >= 0.0f) {
        self->field_89c = c;
    }
    self->field_895 = true;
    self->field_8a4 = b;
    self->field_8a0 = 0;
    self->field_8a8 = PPFX::Unk_Float2(1.0f, 0.78539819f);
    return 0;
}

// 0x7100429dc0: CPostEffect::GetAutoExposureAdjustedApi
f32 Unk_429dc0(u64 self_, u32 view_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 view = view_;
    s32 index = view == -1 ? self->field_298 : view;
    f32 value = self->field_2a0[index].field_60;
#line 18580
    PPFX_FN("Frame: %d, View: %d, %f GetAutoExposureAdjustedApi(iEffectViewIndex: %d);\n", self->Unk_Frame(self->field_298), self->field_298, value, view);
    return value;
}

// The colour matrices' functions: each multiplies one of them by a matrix.
namespace PPFX {

// 0x710040fb30, 0x7100410130, 0x7100410200, 0x71004102a0 (Unk_415f40.cpp)
MATRIXT44* Unk_40fb30(MATRIXT44* out, bool luminance, f32 angle);
void Unk_410130(MATRIXT44* out, bool arg1, f32 r, f32 g, f32 b);
void Unk_410200(MATRIXT44* out, f32 x, f32 y, f32 z, f32 w);
void Unk_4102a0(MATRIXT44* out, f32 x, f32 y, f32 z);

}  // namespace PPFX

// a scale (inline)
static inline void Unk_Scale(PPFX::MATRIXT44* out, f32 x, f32 y, f32 z) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
            out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[0][0] = x;
    out->field_0[1][1] = y;
    out->field_0[2][2] = z;
    out->field_0[3][3] = 1.0f;
}

// A rotation about a unit axis (inline)
static inline void Unk_RotationAxis(PPFX::MATRIXT44* out, f32 x, f32 y, f32 z, f32 angle) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);
    out->field_0[0][0] = x * x + (1.0f - x * x) * c;
    out->field_0[0][1] = x * y * (1.0f - c) + z * s;
    out->field_0[0][2] = x * z * (1.0f - c) - y * s;
    out->field_0[1][0] = x * y * (1.0f - c) - z * s;
    out->field_0[1][1] = y * y + (1.0f - y * y) * c;
    out->field_0[1][2] = y * z * (1.0f - c) + x * s;
    out->field_0[2][0] = x * z * (1.0f - c) + y * s;
    out->field_0[2][1] = y * z * (1.0f - c) - x * s;
    out->field_0[2][2] = z * z + (1.0f - z * z) * c;
    out->field_0[0][3] = out->field_0[1][3] = out->field_0[2][3] = 0.0f;
    out->field_0[3][0] = out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[3][3] = 1.0f;
}

// the identity's element (inline)
static inline f32 Unk_Identity(s32 i, s32 j) {
    return i == j ? 1.0f : 0.0f;
}

// the sepia tone's matrix (placeholder name)
static const f32 Unk_SepiaTone[4][4] = {
    {0.941f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.784f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.569f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f},
};

// colour matrix `index` times `m`
static inline void Unk_Apply(PPFX::CPostEffect* self, s32 index, const PPFX::MATRIXT44* m) {
    PPFX::MATRIXT44_MatrixMultiply(&self->field_9b4[index], &self->field_9b4[index], m);
    self->field_b34[index] = true;
}

// 0x710043a400
s32 Unk_43a400(u64 self_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_4102a0(&m, -1.0f, -1.0f, -1.0f);
    Unk_Apply(self, 0, &m);
    return 0;
}

// 0x710043a460
s32 Unk_43a460(u64 self_, u32 index, f32 angle) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_RotationAxis(&m, 0.0f, 0.0f, 1.0f, angle);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a530
s32 Unk_43a530(u64 self_, u32 index, f32 scale) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_Scale(&m, scale, scale, scale);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a5b0
s32 Unk_43a5b0(u64 self_, u32 index, bool luminance, f32 angle) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_40fb30(&m, luminance, angle);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a610
s32 Unk_43a610(u64 self_, u32 index, f32 scale) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_4102a0(&m, scale, scale, scale);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a670
s32 Unk_43a670(u64 self_, u32 index, f32 saturation) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_410130(&m, false, saturation, saturation, saturation);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a6e0
s32 Unk_43a6e0(u64 self_, u32 index, f32 x, f32 y, f32 z) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_Scale(&m, x, y, z);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a760
s32 Unk_43a760(u64 self_, u32 index, f32 scale) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_Scale(&m, scale, scale, scale);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a7e0
s32 Unk_43a7e0(u64 self_, u32 index, f32 x, f32 y, f32 z, f32 w) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_410200(&m, x, y, z, w);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a840: `amount` of a sepia tone (the matrix between the identity
// and the tone's), then the saturation 1 - `amount`
// NON_MATCHING: the same arithmetic, but the tone's sixteen stores pair up at
// other offsets (here m[0][0] is stored alone first and the pairs are odd; the
// original pairs every row's elements 0-1 and 2-3). Element order, a loop by
// columns and a lerp of two matrices were tried; also every direction of
// both loops, `s64`/`u32` indices, a row pointer, a flat loop and the
// sixteen stores written out in the original's store order (with `j`
// counted down the pairs are the original's, their order isn't).
s32 Unk_43a840(u64 self_, u32 index, f32 amount) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 tone;
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 4; j++) {
            tone.field_0[i][j] = Unk_Identity(i, j) + amount * (Unk_SepiaTone[i][j] - Unk_Identity(i, j));
        }
    }
    PPFX::MATRIXT44 saturation;
    PPFX::Unk_410130(&saturation, false, 1.0f - amount, 1.0f - amount, 1.0f - amount);
    PPFX::MATRIXT44 m;
    PPFX::MATRIXT44_MatrixMultiply(&m, &saturation, &tone);
    PPFX::MATRIXT44 copy = m;
    Unk_Apply(self, index, &copy);
    return 0;
}

namespace PPFX {
// 0x710043c690 (below)
Unk_Float4 Unk_43c690(const f32* temperature, const Unk_410f90* space, const f32* tint, const f32* luminance,
                      const f32* alpha, bool invert, bool planck);
// 0x71004155f0 (Unk_415f40.cpp): the inverse of a matrix
void Unk_4155f0(MATRIXT44* out, const MATRIXT44* m);
}  // namespace PPFX

// a colour space copied unless it is itself (inline)
static inline void Unk_CopyColorSpace(Unk_410f90* out, const Unk_410f90* space) {
    if (space != out) {
        out->field_0 = space->field_0;
        out->field_8 = space->field_8;
        out->field_10 = space->field_10;
        out->field_18 = space->field_18;
    }
}

// the XYZ to RGB matrix of a colour space (inline: Unk_4114f0 with the space
// given)
static inline PPFX::MATRIXT44* Unk_XyzToRgb(PPFX::MATRIXT44* out, const Unk_410f90* space) {
    PPFX::MATRIXT44 toXyz;
    PPFX::Unk_411b00(&toXyz, &space->field_0, &space->field_8, &space->field_10, &space->field_18);
    PPFX::MATRIXT44 inverse;
    PPFX::Unk_4155f0(&inverse, &toXyz);
    *out = inverse;
    return out;
}

// 0x710043a970: the white balance of a colour temperature on the daylight
// locus as a matrix in colour space `from`, scaled in colour space `to`
// (the static colour space 0xffffffff: `from`)
PPFX::MATRIXT44* Unk_43a970(PPFX::MATRIXT44* out, const Unk_410f90* from, bool invert, const Unk_410f90* to,
                            f32 temperature, f32 tint, f32 luminance) {
    Unk_410f90 space;
    Unk_CopyColorSpace(&space, to);
    if (Unk_SameColorSpace(*to, PPFX::Unk_Static_Object0)) {
        space = *from;
    }
    PPFX::Unk_Float4 c;
    {
        f32 alpha = 0.0f;
        c = PPFX::Unk_43c690(&temperature, &space, &tint, &luminance, &alpha, invert, true);
    }
    Unk_Scale(out, c.field_0[0].field_0, c.field_0[1].field_0, c.field_0[2].field_0);
    if (!Unk_SameColorSpace(*to, PPFX::Unk_Static_Object0)) {
        PPFX::MATRIXT44 fromXyz;
        PPFX::Unk_411b00(&fromXyz, &from->field_0, &from->field_8, &from->field_10, &from->field_18);
        PPFX::MATRIXT44 spaceRgb;
        Unk_XyzToRgb(&spaceRgb, &space);
        PPFX::MATRIXT44 spaceXyz;
        PPFX::Unk_411b00(&spaceXyz, &space.field_0, &space.field_8, &space.field_10, &space.field_18);
        PPFX::MATRIXT44 fromRgb;
        Unk_XyzToRgb(&fromRgb, from);
        PPFX::MATRIXT44 m4;
        PPFX::MATRIXT44 m3;
        PPFX::MATRIXT44 m2;
        PPFX::MATRIXT44 m1;
        PPFX::MATRIXT44_MatrixMultiply(&m1, &fromXyz, &spaceRgb);
        PPFX::MATRIXT44_MatrixMultiply(&m2, &m1, out);
        PPFX::MATRIXT44_MatrixMultiply(&m3, &m2, &spaceXyz);
        PPFX::MATRIXT44_MatrixMultiply(&m4, &m3, &fromRgb);
        *out = m4;
    }
    return out;
}

// 0x710043ad10: colour matrix `index` times the white balance of a colour
// temperature, on the Planckian locus (`planck`) or the daylight one, in
// colour space field_b84 (a member of the colour space type: through a cast
// of a float array InstCombine puts the stack copy's address first in the
// copy's `space != out` test)
s32 Unk_43ad10(u64 self_, s32 index, bool planck, const Unk_410f90* space, f32 temperature, f32 luminance) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    f32 t;
    f32 tint;
    f32 l;
    f32 alpha;
    Unk_410f90 to;
    Unk_CopyColorSpace(&to, space);
    self->Unk_4299a0();
    Unk_410f90 from;
    Unk_CopyColorSpace(&from, &self->field_b84);
    PPFX::MATRIXT44 m;
    if (planck) {
        t = temperature;
        tint = 1.0f;
        l = luminance;
        alpha = 0.0f;
        PPFX::Unk_Float4 c = PPFX::Unk_43c690(&t, &from, &tint, &l, &alpha, false, false);
        Unk_Scale(&m, c.field_0[0].field_0, c.field_0[1].field_0, c.field_0[2].field_0);
    } else {
        if (Unk_SameColorSpace(*space, PPFX::Unk_Static_Object0)) {
            to = PPFX::Unk_410f90_Object(0x15);
        }
        Unk_43a970(&m, &from, false, &to, temperature, 1.0f, luminance);
    }
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043af30: the same inverted (the original repeats the code)
s32 Unk_43af30(u64 self_, s32 index, bool planck, const Unk_410f90* space, f32 temperature, f32 luminance) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    f32 t;
    f32 tint;
    f32 l;
    f32 alpha;
    Unk_410f90 to;
    Unk_CopyColorSpace(&to, space);
    self->Unk_4299a0();
    Unk_410f90 from;
    Unk_CopyColorSpace(&from, &self->field_b84);
    PPFX::MATRIXT44 m;
    if (planck) {
        t = temperature;
        tint = 1.0f;
        l = luminance;
        alpha = 0.0f;
        PPFX::Unk_Float4 c = PPFX::Unk_43c690(&t, &from, &tint, &l, &alpha, true, false);
        Unk_Scale(&m, c.field_0[0].field_0, c.field_0[1].field_0, c.field_0[2].field_0);
    } else {
        if (Unk_SameColorSpace(*space, PPFX::Unk_Static_Object0)) {
            to = PPFX::Unk_410f90_Object(0x15);
        }
        Unk_43a970(&m, &from, true, &to, temperature, 1.0f, luminance);
    }
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x7100429e80: a number of a view's settings (-1: the active view), or
// another one when it isn't set
f32 Unk_429e80(u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    if (self->field_2a0[view].field_24 > 0.0f) {
        return self->field_2a0[view].field_24;
    }
    if (self->field_2a0[view].field_70 != nullptr) {
        return self->field_2a0[view].field_5c;
    }
    return 0.0f;
}

// 0x7100429ed0: the same of the other kind
f32 Unk_429ed0(u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    if (self->field_2a8[view].field_1c > 0.0f) {
        return self->field_2a8[view].field_1c;
    }
    if (self->field_2a8[view].field_48 != nullptr) {
        return self->field_2a8[view].field_34;
    }
    return 0.0f;
}

// 0x7100424240: CPostEffect::SetRenderSceneViewportScale
s32 Unk_424240(u64 self_, u32 flag_, f32 width, f32 height, f32 x, f32 y) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool flag = flag_ & 1;
    if (self->field_0) {
#line 38261
        PPFX_ERROR("CPostEffect::SetRenderSceneViewportScale(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    if (x != 0.0f || y != 0.0f) {
#line 38269
        PPFX_ERROR("CPostEffect::SetRenderSceneViewportScale(): Not supported. Both of fOffsetX and fOffsetY must be zero.\n");
        return -4;
    }
    if (width >= 0.0f) {
        self->field_800.field_0 = width;
    }
    if (height >= 0.0f) {
        self->field_800.field_4 = height;
    }
    if (x >= 0.0f) {
        self->field_800.field_8 = x;
    }
    if (y >= 0.0f) {
        self->field_800.field_c = y;
    }
    if (self->field_800.field_0 == 0.0f) {
        self->field_800.field_0 = 1.0f;
    }
    if (self->field_800.field_4 == 0.0f) {
        self->field_800.field_4 = 1.0f;
    }
    self->field_810 = flag;
    return 0;
}

// 0x71004277e0: CPostEffect::SetVignetteByOpticsImageCircle
s32 Unk_4277e0(u64 self_, u32 a_, u32 b_, f32 c, f32 d, f32 e, f32 f, f32 g) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool a = a_ & 1;
    bool b = b_ & 1;
    self->field_918 = 0;
    self->field_1a0->field_3a8 = false;
    self->field_938 = c;
    self->field_950 = d;
    self->field_954 = e;
    self->field_920 = f;
    self->field_958 = g;
    self->field_94d = a;
    if (c <= 0.0f && d <= 0.0f) {
        return 0;
    }
    if (!self->field_1ba) {
        if (c > 0.0f || !(d <= 0.0f)) {
#line 12109
            PPFX_WARNING("CPostEffect::SetVignetteByOpticsImageCircle(): Initialize() with PFXINIT_OPTICALVIGNETTING flag for optical vignetting.\n");
        }
        return 1;
    }
    if (self->field_1a0 != nullptr) {
        self->field_1a0->field_3a8 = b;
    }
    self->field_918 = 3;
    return 0;
}

// 0x7100425170: which views' settings of the second kind are on (0x7fffffff:
// all of them, -1: the active one); 1 if one of them can't be
s32 Unk_425170(u64 self_, s32 view, bool enable) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    for (s32 i = 0; i < self->field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            if (self->field_2a8[i].field_48 == nullptr) {
                result = 1;
                self->field_2a8[i].field_0 = false;
            } else {
                self->field_2a8[i].field_0 = enable;
            }
        }
    }
    return result;
}

namespace PPFX {

// 0x710041af70
Unk_RenderTexture* CPostEffect::Unk_41af70() {
    Unk_4a5d10_Self* textures = field_190;
    s32 index = field_5d8;
    if (index == -1) {
        index = textures->field_90;
    }
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

}  // namespace PPFX

// 0x7100423ee0: CPostEffect::SetGlareModulatorSource
s32 Unk_423ee0(PPFX::CPostEffect* self, u32 source, u64 object) {
    if (source >= 6) {
#line 39137
        PPFX_ERROR("CPostEffect::SetGlareModulatorSource(): Argument eGlareModulatorSource is invalid.\n");
        return -6;
    }
    self->field_c0 = source;
    if (source == 0) {
        self->field_b8 = nullptr;
        return 0;
    }
    if (!self->field_1cc) {
#line 39161
        PPFX_WARNING("CPostEffect::SetGlareModulatorSource(): Initialize() with PFXINIT_GLAREMODULATOR flag for glare modulation.\n");
        self->field_c0 = 0;
        self->field_b8 = nullptr;
        return 1;
    }
    self->field_b8 = reinterpret_cast<PPFX::Unk_RenderTexture*>(object);
    return 0;
}

// 0x7100423ff0: CPostEffect::SetEffectMaskColorSource
s32 Unk_423ff0(PPFX::CPostEffect* self, u32 source, u64 object) {
    if (source >= 5) {
#line 39306
        PPFX_ERROR("CPostEffect::SetEffectMaskColorSource(): Argument eEffectMaskColorSource is invalid.\n");
        return -6;
    }
    self->field_5c8 = source;
    if (source == 0) {
        self->field_5b8 = nullptr;
        return 0;
    }
    if (!self->field_1cd) {
#line 39329
        PPFX_WARNING("CPostEffect::SetEffectMaskColorSource(): Initialize() with PFXINIT_EFFECTMASK flag for effect mask.\n");
        self->field_5c8 = 0;
        self->field_5b8 = nullptr;
        return 1;
    }
    self->field_5b8 = reinterpret_cast<PPFX::Unk_RenderTexture*>(object);
    return 0;
}

// 0x710043a100, 0x710043a280: the same with a device texture (its render
// texture, made if there is none)
s32 Unk_43a100(PPFX::CPostEffect* self, u32 source, u64 key, u32 arg3, u32 arg4, u32 format) {
    if (source == 0) {
        return Unk_423ee0(self, 0, 0);
    }
    PPFX::Unk_RenderTexture* texture = PPFX::Unk_MapFind(self->field_108, key);
    if (texture == nullptr) {
        s32 result = self->Unk_427c10(key, arg3, arg4, format, nullptr, &texture);
        if (result < 0) {
            return result;
        }
    }
    return Unk_423ee0(self, source, reinterpret_cast<u64>(texture));
}

s32 Unk_43a280(PPFX::CPostEffect* self, u32 source, u64 key, u32 arg3, u32 arg4, u32 format) {
    if (source == 0) {
        return Unk_423ff0(self, 0, 0);
    }
    PPFX::Unk_RenderTexture* texture = PPFX::Unk_MapFind(self->field_108, key);
    if (texture == nullptr) {
        s32 result = self->Unk_427c10(key, arg3, arg4, format, nullptr, &texture);
        if (result < 0) {
            return result;
        }
    }
    return Unk_423ff0(self, source, reinterpret_cast<u64>(texture));
}

// 0x7100424b20: CPostEffect::SetAutoExposureRange
s32 Unk_424b20(u64 self_, s32 view, f32 minExposure, f32 maxExposure) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18870
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureRange(iEffectViewIndex: %d, fMinExposure: %f, fMaxExposure: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, minExposure, maxExposure);
    if (minExposure > maxExposure) {
        return -6;
    }
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            if (item.field_70 == nullptr) {
                result = 1;
            }
            item.field_30 = minExposure;
            item.field_34 = maxExposure;
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                if (item.field_70 == nullptr) {
                    result = 1;
                }
                item.field_30 = minExposure;
                item.field_34 = maxExposure;
            }
        }
    }
    return result;
}

// 0x7100424740: CPostEffect::SetAutoExposureEnable
s32 Unk_424740(u64 self_, s32 view, bool enable) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18677
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureEnable(iEffectViewIndex: %d, bAutoExposureEnable: %s);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, enable ? "true" : "false");
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    for (s32 i = 0; i < self->field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            if (self->field_2a0[i].field_70 == nullptr) {
                result = 1;
                self->field_2a0[i].field_0 = false;
            } else {
                self->field_2a0[i].field_0 = enable;
            }
        }
    }
    return result;
}

// 0x7100424c90: CPostEffect::SetAutoExposureMiddleGray
s32 Unk_424c90(u64 self_, s32 view, f32 middleGray, f32 glare) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18932
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMiddleGray(iEffectViewIndex: %d, fMiddleGray: %f, fInfluencedByGlare: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, middleGray, glare);
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            if (item.field_70 == nullptr) {
                result = 1;
            }
            item.field_4 = middleGray;
            item.field_8 = glare;
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                if (item.field_70 == nullptr) {
                    result = 1;
                }
                item.field_4 = middleGray;
                item.field_8 = glare;
            }
        }
    }
    return result;
}

// 0x7100424de0: CPostEffect::SetAutoExposureMiddleGray (its log line's name),
// the delay
s32 Unk_424de0(u64 self_, s32 view, u32 mode, f32 delay) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 19112
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMiddleGray(iEffectViewIndex: %d, eDelayMode: %d, fDelayTime: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, mode, delay);
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            if (item.field_70 == nullptr) {
                result = 1;
            }
            item.field_28 = mode;
            item.field_2c = delay;
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                if (item.field_70 == nullptr) {
                    result = 1;
                }
                item.field_28 = mode;
                item.field_2c = delay;
            }
        }
    }
    return result;
}

// the identity (inline)
static inline void Unk_Identity(PPFX::MATRIXT44* out) {
    out->field_0[3][2] = out->field_0[3][1] = out->field_0[3][0] = out->field_0[2][3] = out->field_0[2][1] =
        out->field_0[2][0] = out->field_0[1][3] = out->field_0[1][2] = out->field_0[1][0] = out->field_0[0][3] =
            out->field_0[0][2] = out->field_0[0][1] = 0.0f;
    out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
}

// 0x71004255b0: resets colour matrix `index` (-2: all of them)
s32 Unk_4255b0(u64 self_, u32 index_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 index = index_;
    if (index == -2) {
        for (s32 i = 0; i < 6; i++) {
            Unk_Identity(&self->field_9b4[i]);
            self->field_b34[i] = false;
        }
    } else {
        Unk_Identity(&self->field_9b4[index]);
        self->field_b34[index] = false;
    }
    return 0;
}

// 0x71004554c0, 0x71004554f0 (lib/yebis/leaf: the glare's vignette, placeholder
// types)
u32 Unk_4554c0_set(Unk_455350* self, const Unk_455350_Float4* value, f32 a, f32 b);
struct Unk_4554f0;
u32 Unk_4554f0_update(Unk_4554f0* self, f32 fvalue, f32 farg1, f32 farg2);

namespace PPFX {

// 0x7100425750: the vignette handed to the glare, and the target surface
// (CTextureUtil::Unk_470880 is given field_a: a bool its body doesn't use)
// NON_MATCHING: case 4's field_960 (a phi of the two loads in the original)
// and the first select: the original selects on `uge` and keeps field_59c's
// test a branch of its own, reusing the select's compare; here the two tests
// are one `ccmp`. `has` set by `if`s from false gives the original's blocks.
// Tried for the select: `x < 0 ? 1 : x`, an `if` from field_91c, a shared
// `negative` flag, the field_59c test outside (nested `if`s), an if/else
// with the default in the else, the scale test outside.
s32 CPostEffect::Unk_425750() {
    Unk_42a0f0();
    Unk_428220();
    UpdateParameters_Base();
    f32 scale = field_91c >= 0.0f ? field_91c : 1.0f;
    f32 falloff = field_920;
    if (field_59c && field_91c < 0.0f) {
        scale = (field_8c8 & 0xffff) == 8 ? 0.0f : 0.85f;
    }
    reinterpret_cast<CRenderGlare*>(field_198)->Unk_4534f0(field_6d0, field_6d4, field_6d8);
    field_198->field_180 = field_918 != 0;
    field_5a2 = false;
    switch (field_918) {
    case 1: {
        field_198->field_18c = false;
        Unk_4554c0_set(reinterpret_cast<Unk_455350*>(field_198), reinterpret_cast<const Unk_455350_Float4*>(&field_928),
                       scale, falloff);
        f32 amount = field_198->field_180 ? field_198->field_188 : 0.0f;
        f32 k = amount * (0.41421357f / field_6d0 - 1.0f) + 1.0f;
        f32 size = field_924 * reinterpret_cast<CRenderGlare*>(field_198)->Unk_45d350() * k;
        Unk_4554f0_update(reinterpret_cast<Unk_4554f0*>(field_198), 1.0f, size, 0.0f);
        break;
    }
    case 2:
    case 3: {
        if (!field_1050) {
#line 22652
            PPFX_WARNING("SetVignetteByOptics() requires proper SetDepthOfFieldParameters() and SetRenderScenePerspective() settings.\n");
            field_198->field_180 = false;
            break;
        }
        field_198->field_18c = true;
        bool has = false;
        if (field_918 == 2) {
            if (!(field_93c <= 0.0f) && field_948 != 0.0f && ((field_940 != 0.0f) | (field_944 != 0.0f))) {
                has = true;
            }
        } else if (!(field_950 <= 0.0f)) {
            has = true;
        }
        if (field_104f && field_1a0->field_3a8) {
            reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4b5ae0();
        }
        f32 near = 0.0f;
        f32 far = -1.0f;
        if (has) {
            field_5a2 = true;
            reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4afae0(&near, &far);
            if (!field_5a2 && field_106e && far < 0.0f) {
                far -= field_1070;
            }
            far = fabsf(far);
            if (!field_94d && !field_104f) {
                far = 0.0f;
            }
            if (field_5a2) {
                near = 0.0f;
                far = -1.0f;
            }
        }
        Unk_4554f0_update(reinterpret_cast<Unk_4554f0*>(field_198), field_938, near, far);
        break;
    }
    case 4: {
        field_198->field_18c = true;
        f32 radius = field_960;
        if (field_104f && field_1a0->field_3a8) {
            reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4b5ae0();
        }
        f32 near;
        f32 far;
        if (radius < 0.0f) {
            near = 0.0f;
            far = -1.0f;
        } else {
            f32 k = 0.41421357f / ((field_6d0 - 0.41421357f) * field_920 + 0.41421357f);
            f32 inner = field_95c * k;
            f32 outer = field_960 * k;
            near = (inner + outer) * 0.5f;
            far = (outer - inner) * 0.5f;
        }
        Unk_4554f0_update(reinterpret_cast<Unk_4554f0*>(field_198), field_938, near, far);
        break;
    }
    }
    s32 result = 0;
    if (field_120 != nullptr) {
        field_1168 = reinterpret_cast<u64>(field_120);
    } else if (field_128 != 0) {
        result = reinterpret_cast<IGPUTexture*>(field_128)->vf23(0, reinterpret_cast<IGPUSurface**>(&field_1168));
        if (result >= 0) {
            reinterpret_cast<IGPUSurface*>(field_1168)->vf1();
            result = 0;
        }
    } else if (field_130 != 0) {
        CRenderTexture* texture = reinterpret_cast<CRenderTexture*>(field_130);
        field_1168 = reinterpret_cast<u64>(*texture->field_d0[texture->field_a0]);
    } else {
        field_1168 = field_20;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->Unk_470880(field_a);
    return result;
}

}  // namespace PPFX

// 0x71024e09bc (placeholder)
extern s32 Unk_24e09bc;
// 0x71024e09c0, 0x71024e09c8: the memory pool storage buffer and its size
extern u64 Unk_24e09c0;
extern s32 Unk_24e09c8;

// 0x710043b590: the SiGfx texture of an NVN texture and a view of it (made
// the first time, with a view of the whole texture when there is none)
// (placeholder signature)
// NON_MATCHING: register allocation (x22/x23 and x24/x25 swapped) and the
// emplace's search: the original computes the end node's address again for
// it (0x7100423160 does that here too) and lays its loop out differently
u64 Unk_43b590(void* self_, u64 texture_, u64 view_, u64 context_) {
    PPFX::CPostEffect* self = static_cast<PPFX::CPostEffect*>(self_);
    if (texture_ == 0) {
        return 0;
    }
    auto it = self->field_11d0.find(std::make_pair(texture_, view_));
    if (it != self->field_11d0.end()) {
        return reinterpret_cast<u64>(it->second.first);
    }
    PPFX::Unk_SiGfxDrawContext* context = reinterpret_cast<PPFX::Unk_SiGfxDrawContext*>(context_);
    if (context == nullptr) {
        context = self->field_18->field_30;
    }
    const void* texture = reinterpret_cast<const void*>(texture_);
    const void* view = reinterpret_cast<const void*>(view_);
    void* allocation = nullptr;
    if (view == nullptr) {
        SiSDK3::ISiAllocator* allocator = SiSDK3::Unk_NXKernel()->vf6();
#line 42296
        void* made = allocator->vf7(0x28, -1, __FILE__, __LINE__);
        if (made == nullptr) {
            return 0;
        }
        nvnTextureViewSetDefaults(made);
        nvnTextureViewSetLevels(made, 0, nvnTextureGetLevels(texture));
        nvnTextureViewSetFormat(made, nvnTextureGetFormat(texture));
        nvnTextureViewSetTarget(made, nvnTextureGetTarget(texture));
        nvnTextureViewSetDepthStencilMode(made, nvnTextureGetDepthStencilMode(texture));
        nvnTextureViewSetLayers(made, 0, nvnTextureGetDepth(texture));
        allocation = made;
        view = made;
    }
    PPFX::Unk_SiGfxTexture* siTexture = context->vf5()->vf49(2, nullptr, 0, nullptr);
    if (siTexture->vf44(texture, view)) {
        self->field_11d0.emplace(std::make_pair(texture_, view_),
                             std::make_pair(reinterpret_cast<SiSDK3::ISiInterface*>(siTexture), allocation));
        return reinterpret_cast<u64>(siTexture);
    }
    if (siTexture != nullptr) {
        siTexture->vf3();
    }
    return 0;
}

// 0x710043f080
namespace PPFX {
s32 Unk_43f080(IGPUDevice* self);
}

// 0x710043b9d0
s32 Unk_43b9d0(u64 self_, u64 arg1, u64 arg2, u64, u64) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    auto it = self->field_11e8.find(std::make_pair(arg1, arg2));
    if (it == self->field_11e8.end()) {
        return -6;
    }
    s32 result = self->Unk_4399e0(it->second.first, nullptr);
    if (result == 0) {
        if (it->second.first != nullptr) {
            it->second.first->vf3();
            it->second.first = nullptr;
        }
        if (it->second.second != nullptr) {
            it->second.second->vf3();
            it->second.second = nullptr;
        }
        self->field_11e8.erase(it);
    }
    PPFX::Unk_43f080(self->field_18);
    return result;
}

// 0x710043bb50
s32 Unk_43bb50(u64 self_, u64 arg1, u64 arg2, u64, u64) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    auto it = self->field_11d0.find(std::make_pair(arg1, arg2));
    if (it == self->field_11d0.end()) {
        return -6;
    }
    s32 result = self->Unk_439c10(it->second.first, nullptr);
    if (result != 0) {
        return result;
    }
    PPFX::CTextureUtil* util = PPFX::Unk_GetTextureUtil();
    PPFX::Unk_ReleaseTextureUtil();
    if (util != nullptr && util->field_30.field_0 != nullptr && util->field_30.field_0->field_78 != nullptr) {
        util->field_30.field_0->field_78->Unk_44def0();
    }
    if (it->second.first != nullptr) {
        it->second.first->vf3();
        it->second.first = nullptr;
    }
    if (it->second.second != nullptr) {
        SiSDK3::ISiAllocator* allocator = SiSDK3::Unk_NXKernel()->vf6();
        if (allocator != nullptr && it->second.second != nullptr) {
#line 42359
            allocator->vf9(it->second.second, __FILE__, __LINE__);
        }
        it->second.second = nullptr;
    }
    self->field_11d0.erase(it);
    return 0;
}

// 0x710043bde0
s32 Unk_43bde0(PPFX::CPostEffect* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format, u32 arg6, u32 arg7) {
    u64 key = self->Unk_423160(arg1, arg2, nullptr);
    PPFX::Unk_43c4e0* object = PPFX::Unk_MapFind(self->field_d8, key);
    if (object == nullptr) {
        s32 result = self->Unk_4397e0(key, arg3, arg4, format, arg6, arg7, &object);
        if (result < 0) {
            return result;
        }
    }
    self->field_120 = object;
    self->field_128 = 0;
    self->field_130 = 0;
    self->field_1168 = 0;
    return 0;
}

// 0x710043bec0
s32 Unk_43bec0(PPFX::CPostEffect* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format) {
    u64 key = Unk_43b590(self, arg1, arg2, 0);
    PPFX::Unk_RenderTexture* texture = PPFX::Unk_MapFind(self->field_108, key);
    if (texture == nullptr) {
        s32 result = self->Unk_427c10(key, arg3, arg4, format, nullptr, &texture);
        if (result < 0) {
            return result;
        }
    }
    self->field_70 = texture;
    self->field_78 = 0;
    return 0;
}

// the formats 0x7100425410 and 0x7100428030 single out (inline)
static inline bool Unk_425410_Format(s32 format) {
    switch (format) {
    case 20:
    case 40:
    case 45:
    case 55:
        return true;
    default:
        return false;
    }
}

// what 0x7100425410 reads of its second kind of object (placeholder)
struct Unk_425410_Other {
    u8 pad_0[0x44];
    s32 field_44;  // the format
};

// the format of one of the two objects (inline)
static inline s32 Unk_425410_GetFormat(u64 object, u64 other) {
    if (object != 0) {
        return reinterpret_cast<PPFX::Unk_RenderTexture*>(object)->field_38;
    }
    return reinterpret_cast<Unk_425410_Other*>(other)->field_44;
}

// 0x7100425410: CPostEffect::SetDepthFactorSource (its log line names it)
// NON_MATCHING: the original keeps `has` a flag in w9 (cset, then tbz at
// each test) and sets the source to 3 before a branchy test of the format;
// here the tests use the pointers' `orr` again and the format's two
// conditions are merged with `ccmp`, and the stores of field_58 to field_6c
// come in another order. The scale and bias are selected as integers in both
// (Unk_Float). Tried: `has` as `(object | other) != 0` or with `|`, the
// sources set before an `if` of the format, `use` with `&`.
s32 Unk_425410(PPFX::CPostEffect* self, u32 source, u64 object, u64 other, u32 mode, f32 scale, f32 bias) {
    self->field_895 = true;
    bool has = object != 0 || other != 0;
    if (source == 9) {
        if (has) {
            source = Unk_425410_Format(Unk_425410_GetFormat(object, other)) ? 0 : 3;
        } else {
            source = self->field_548 ? 8 : 3;
        }
    }
    if (mode == 5) {
        if (has) {
            mode = Unk_425410_Format(Unk_425410_GetFormat(object, other)) ? 0 : 2;
        } else {
            mode = source == 8 ? 0 : 2;
        }
    }
    if (has && !self->field_594) {
#line 40973
        PPFX_ERROR("CPostEffect::SetDepthFactorSource(): Initialize() with PFXINIT_DEPTHFACTORSOURCETEXTURE flag for user depth factor texture.\n");
        return -4;
    }
    bool use = has && source != 8;
    self->field_58 = source;
    self->field_5c = mode;
    self->field_50 = use ? reinterpret_cast<PPFX::Unk_RenderTexture*>(object) : nullptr;
    PPFX::Unk_Float s = use ? PPFX::Unk_Float(scale) : PPFX::Unk_Float(1.0f);
    PPFX::Unk_Float t = use ? PPFX::Unk_Float(bias) : PPFX::Unk_Float(0.0f);
    self->field_60 = s.field_0;
    self->field_64 = t.field_0;
    self->field_68 = 1.0f / s.field_0;
    self->field_6c = -t.field_0 / s.field_0;
    return 0;
}

// 0x710043b150: the same with a device texture (its render texture, made if
// it is neither one nor a device surface)
s32 PPFX::CPostEffect::Unk_43b150(u32 arg1, u64 key, u32 arg3, u32 arg4, u32 format, u32 arg6, f32 a, f32 b) {
    field_895 = true;
    Unk_RenderTexture* texture = Unk_MapFind(field_108, key);
    Unk_RenderTexture* object = texture;
    if (texture == nullptr) {
        Unk_43c490* surface = Unk_MapFind(field_f0, key);
        if (surface == nullptr) {
            s32 result = Unk_427c10(key, arg3, arg4, format, &surface, &texture);
            if (result < 0) {
                return result;
            }
        }
        object = texture;
    }
    return Unk_425410(this, arg1, reinterpret_cast<u64>(object), 0, arg6, a, b);
}

// 0x710043bf90
s32 Unk_43bf90(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format, u32 arg7, f32 a,
               f32 b) {
    u64 key = Unk_43b590(self, arg2, arg3, 0);
    return self->Unk_43b150(arg1, key, arg4, arg5, format, arg7, a, b);
}

// 0x710043c020
s32 Unk_43c020(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    u64 key = Unk_43b590(self, arg2, arg3, 0);
    return Unk_43a100(self, arg1, key, arg4, arg5, format);
}

// 0x710043c090
s32 Unk_43c090(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    u64 key = Unk_43b590(self, arg2, arg3, 0);
    return Unk_43a280(self, arg1, key, arg4, arg5, format);
}

// 0x71024e09d0, 0x71024e09d8: the NVN texture and sampler pools the default
// callbacks register in
extern void* Unk_24e09d0;
extern void* Unk_24e09d8;

namespace PPFX {

// 0x710043b290
s32 CPostEffect::DefaultRegisterTextureHandleCallback_Nvn(const void* texture, const void* view) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    if (self == nullptr) {
        return -1;
    }
    if (self->field_1210.empty()) {
#line 42451
        PPFX_ERROR("CPostEffect::DefaultRegisterTextureHandleCallback_Nvn : reserved numIndices is empty.");
        return -1;
    }
    s32 index = self->field_1210.front();
    self->field_1210.pop_front();
    nvnTexturePoolRegisterTexture(Unk_24e09d0, index, texture, view);
    return index;
}

// 0x710043b370: gives an index back
void CPostEffect::Unk_43b370(s32 index) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    self->field_1210.push_back(index);
}

// 0x710043b3f0
s32 CPostEffect::DefaultRegisterSamplerHandleCallback_Nvn(const void* sampler) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    if (self == nullptr) {
        return -1;
    }
    if (self->field_1228.empty()) {
#line 42475
        PPFX_ERROR("CPostEffect::DefaultRegisterSamplerHandleCallback_Nvn : reserved numIndices is empty.");
        return -1;
    }
    s32 index = self->field_1228.front();
    self->field_1228.pop_front();
    nvnSamplerPoolRegisterSampler(Unk_24e09d8, index, sampler);
    return index;
}

// 0x710043b500: gives an index back
void CPostEffect::Unk_43b500(s32 index) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    self->field_1228.push_back(index);
}

}  // namespace PPFX

// 0x710043b920: CPostEffect::SetResourceMemoryAllocate_Nvn
s32 Unk_43b920(u64 buffer, u32 size_) {
    s32 size = size_;
    if (buffer != 0 && size < 0) {
#line 42394
        PPFX_ERROR("CPostEffect::SetResourceMemoryAllocate_Nvn() : (iMemoryPoolStorageBufferSizeInBytes < 0)&&(pMemoryPoolStorageBuffer!=NULL)\n");
        return 1;
    }
    Unk_24e09c0 = buffer;
    Unk_24e09c8 = size;
    return 0;
}

namespace PPFX {
class CRenderTexture;
}  // namespace PPFX

// 0x710043c530: the growth of a render texture's field_108 (0x710041afb0's,
// which isn't written yet)
template void std::vector<PPFX::CRenderTexture*, PPFX::Unk_StlAllocator<PPFX::CRenderTexture*>>::
    __push_back_slow_path<PPFX::CRenderTexture* const&>(PPFX::CRenderTexture* const&);

// 0x710049e3a0 (GPURenderTexture.cpp)
s32 Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);
// 0x710043fc30 (GPUInterfaceDevice.cpp)
s32 Unk_43fc30(void* device);
// 0x71004afa90, 0x71004afa70 (GPUDepthOfField.cpp, lib/yebis/leaf)
struct Unk_4afa90;
struct Unk_4afa70;
f32 Unk_4afa90_get(const Unk_4afa90* self);
f32 Unk_4afa70_get(const Unk_4afa70* self);

namespace PPFX {

// one reference less, and the pointer cleared (UNK_RELEASE_COUNTED: a counted
// resource, the last reference deletes it)
#define UNK_RELEASE(object)        \
    do {                           \
        if ((object) != nullptr) { \
            (object)->vf1();       \
            (object) = nullptr;    \
        }                          \
    } while (0)
#define UNK_RELEASE_COUNTED(object)                                               \
    do {                                                                          \
        if ((object) != nullptr) {                                                \
            reinterpret_cast<CGPUResourceManage*>(object)->Unk_Release();         \
            (object) = nullptr;                                                   \
        }                                                                         \
    } while (0)
#define UNK_RELEASE_SI(object)                                              \
    do {                                                                    \
        if ((object) != nullptr) {                                          \
            reinterpret_cast<SiSDK3::ISiInterface*>(object)->vf3();         \
            (object) = nullptr;                                             \
        }                                                                   \
    } while (0)

// 0x7100419690: CPostEffect::Uninitialize (its log lines name it); `device`:
// a device to keep using (the device objects stay then)
// NON_MATCHING: the same calls and releases in the same order; the register
// allocation differs (the original keeps the reuse flag on the stack and
// &field_18 in x26, and rematerialises the texture util's size each time:
// here constant hoisting keeps it in x23) and so the scheduling of the first
// block. The original also lays the vf4 test (field_40 null) out after the
// first texture util block and stores field_40 once on each path (`mov x20,
// xzr` and a store of x20); tried: the reuse test nested the other way, the
// stores in the branches, `reuse ? keep : nullptr` (a csel), an `s32` flag.
s32 CPostEffect::Uninitialize(void* device) {
    IGPUDevice* keep = static_cast<IGPUDevice*>(device);
#line 10387
    PPFX_LOG("==== CPostEffect::Uninitialize() ====\n");
    if (field_0) {
#line 10396
        PPFX_ERROR("CPostEffect::Uninitialize(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    bool reuse = false;
    if (field_40 != nullptr) {
        if (field_40 == keep) {
            return 0;
        }
    } else if (keep != nullptr && field_18 != nullptr && field_18->vf4(keep) >= 0) {
        reuse = true;
    }
    field_40 = nullptr;
    if (reuse) {
        field_40 = keep;
    }
    if (field_18 != nullptr) {
        field_18->vf9(nullptr, 0);
    }
    if (field_18 != nullptr) {
        field_18->vf44(0);
        field_18->vf41(-1, true);
        Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    }
    for (auto it = field_d8.begin(); it != field_d8.end(); ++it) {
        UNK_RELEASE(it->second);
    }
    field_d8.clear();
    for (auto it = field_f0.begin(); it != field_f0.end(); ++it) {
        UNK_RELEASE(it->second);
    }
    field_f0.clear();
    for (auto it = field_108.begin(); it != field_108.end(); ++it) {
        UNK_RELEASE_COUNTED(it->second);
    }
    field_108.clear();
    if (field_48 != 0) {
        reinterpret_cast<IGPUInterface*>(field_48)->vf1();
        field_48 = 0;
    }
    UNK_RELEASE_COUNTED(field_198);
    UNK_RELEASE_COUNTED(field_1a0);
    UNK_RELEASE_COUNTED(field_190);
    UNK_RELEASE_COUNTED(field_1b0);
    UNK_RELEASE_COUNTED(field_1a8);
    UNK_RELEASE_COUNTED(field_1d8);
    UNK_RELEASE_COUNTED(field_1e0);
    UNK_RELEASE_COUNTED(field_1e8);
    UNK_RELEASE_COUNTED(field_1f0);
    UNK_RELEASE_COUNTED(field_1f8);
    UNK_RELEASE_COUNTED(field_200);
    UNK_RELEASE_COUNTED(field_208);
    UNK_RELEASE_COUNTED(field_210);
    UNK_RELEASE_COUNTED(field_218);
    for (s32 i = 0; i < field_400; i++) {
        if (field_260 != nullptr) {
            UNK_RELEASE_COUNTED(field_260[i]);
        }
    }
    UNK_DELETE_ARRAY(field_260);
    UNK_RELEASE_COUNTED(field_228);
    UNK_RELEASE_COUNTED(field_230);
    for (s32 i = 0; i < field_400; i++) {
        if (field_238 != nullptr) {
            UNK_RELEASE_COUNTED(field_238[i]);
        }
    }
    UNK_DELETE_ARRAY(field_238);
    UNK_DELETE_ARRAY(field_240);
    UNK_DELETE_ARRAY(field_248);
    UNK_DELETE_ARRAY(field_250);
    UNK_DELETE_ARRAY(field_258);
    if (field_268 != nullptr) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        Unk_49fdc0_call(util->field_29a58, reinterpret_cast<u64>(field_268));
        field_268 = nullptr;
    }
    if (field_278 != nullptr) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        Unk_49fdc0_call(util->field_29a58, reinterpret_cast<u64>(field_278));
        field_278 = nullptr;
    }
    if (field_288 != nullptr) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        Unk_49fc60(util->field_29a58, field_280, field_288);
        UNK_DELETE_ARRAY(field_288);
    }
    for (s32 i = 0; i < field_400; i++) {
        if (field_2a0 != nullptr) {
            UNK_RELEASE_COUNTED(field_2a0[i].field_70);
        }
        if (field_2a8 != nullptr) {
            UNK_RELEASE_COUNTED(field_2a8[i].field_48);
        }
    }
    if (!reuse) {
        UNK_DELETE_ARRAY(field_2a0);
        UNK_DELETE_ARRAY(field_2a8);
    }
    if (field_580 != 0) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        for (s32 i = 0; i < field_400; i++) {
            UNK_RELEASE_COUNTED(field_570[i]);
            UNK_RELEASE_COUNTED(field_588[i]);
        }
        for (s32 i = 0; i < field_580; i++) {
            Unk_49fdc0_call(util->field_29a58, reinterpret_cast<u64>(field_578[i]));
        }
        UNK_DELETE_ARRAY(field_570);
        UNK_DELETE_ARRAY(field_578);
        field_580 = 0;
        UNK_DELETE_ARRAY(field_588);
    }
    UNK_DELETE_ARRAY(field_858);
    UNK_DELETE_ARRAY(field_868);
    if (field_290 != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_290) - 1);
        field_290 = nullptr;
    }
    if (Unk_24e0c28 != 0) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        if (field_550 != nullptr) {
            Unk_49fc60(util->field_29a58, field_558, field_550);
            UNK_DELETE_ARRAY(field_550);
            field_558 = 0;
        }
    }
    if (Unk_24e0c28 != 0) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        if (field_560 != nullptr) {
            Unk_49fc60(util->field_29a58, field_568 * 2, field_560);
            if (field_560 != nullptr) {
                Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_560) - 1);
                field_560 = nullptr;
            }
            field_568 = 0;
        }
    }
    if (reuse) {
        if (Unk_24e0c28 != 0) {
            Unk_24e0c30->Unk_4708b0(field_18);
        }
    } else if (Unk_24e0c28 != 0) {
        Unk_ReleaseTextureUtil();
    }
    if (field_18 != nullptr) {
        if (field_20 != 0) {
            field_18->vf7(0, reinterpret_cast<void*>(field_20), 0);
        }
        if (field_28 != nullptr) {
            field_18->vf8(field_28);
        }
    }
    field_1168 = 0;
    field_120 = nullptr;
    field_128 = 0;
    field_130 = 0;
    UNK_DELETE(field_30);
    UNK_DELETE(field_38);
    if (field_28 != nullptr) {
        reinterpret_cast<IGPUInterface*>(field_28)->vf1();
        field_28 = nullptr;
    }
    if (field_20 != 0) {
        reinterpret_cast<IGPUInterface*>(field_20)->vf1();
        field_20 = 0;
    }
    if (field_18 != nullptr && Unk_49eb10_get() != 0) {
        Unk_49eb20_get(2);
    }
    if (reuse) {
        if (field_18 != nullptr) {
            Unk_43e2b0(field_18);
        }
    } else {
        UNK_RELEASE(field_18);
    }
    for (auto it = field_11d0.begin(); it != field_11d0.end(); ++it) {
        UNK_RELEASE_SI(it->second.first);
        if (it->second.second != nullptr) {
            SiSDK3::ISiAllocator* allocator = reinterpret_cast<SiSDK3::ISiAllocator*>(reinterpret_cast<SiSDK3::SiGfxKernel*>(Unk_4cbf40_get())->vf6());
            void* p = it->second.second;
            if (allocator != nullptr && p != nullptr) {
#line 42359
                allocator->vf9(p, __FILE__, __LINE__);
            }
            it->second.second = nullptr;
        }
    }
    field_11d0.clear();
    for (auto it = field_11e8.begin(); it != field_11e8.end(); ++it) {
        UNK_RELEASE_SI(it->second.first);
        UNK_RELEASE_SI(it->second.second);
    }
    field_11e8.clear();
    if (!reuse && field_1170) {
        UNK_RELEASE_SI(field_1198);
        UNK_RELEASE_SI(field_11c0);
        UNK_RELEASE_SI(field_11a8);
        UNK_RELEASE_SI(field_11a0);
        field_1210.clear();
        field_1228.clear();
        Unk_4cbdd0();
        if (field_1208 != 0) {
            reinterpret_cast<SiSDK3::SiFixedHeapAllocator2*>(field_1208)->vf23();
#line 11008
            SI_DELETE(reinterpret_cast<SiSDK3::ISiAllocator*>(&field_1178),
                      reinterpret_cast<SiSDK3::SiFixedHeapAllocator2*>(field_1208));
            field_1208 = 0;
        }
#line 11013
        PPFX_LOG("CPostEffect::~CPostEffect(): SiGfxDeinit succeeded.\n");
        field_1170 = false;
    }
#line 11020
    PPFX_LOG("==== CPostEffect::Uninitialize() succeeded. ====\n");
    return 0;
}

#undef UNK_RELEASE
#undef UNK_RELEASE_COUNTED
#undef UNK_RELEASE_SI

// 0x7100438510: CPostEffect::EndPostEffectScene_PostProcess (0x71004347e0 logs
// its name): the end of the scene, the targets set back
s32 CPostEffect::EndPostEffectScene_PostProcess() {
    if (field_1168 == field_20) {
        field_18->vf8(field_28);
    }
    field_18->vf44(0);
    field_18->vf41(-1, true);
    Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    if (field_1) {
        field_1 = false;
        field_18->vf7(0, reinterpret_cast<void*>(field_1168), 0);
    }
    s32 result = Unk_43fc30(field_18);
    return result < 0 ? result : 0;
}

// (inline: DrawDebugBuffers)
inline CTextureUtil* CPostEffect::Unk_TextureUtil() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil(util);
    return util;
}

// 0x71004386d0: CPostEffect::DrawDebugBuffers (its log line names it): 61
// intermediate textures drawn into the target as tiles a sixteenth of its size,
// 16 to a row, then again into its texture 21 four rows lower (debug code, off
// unless Unk_24e09b9 is set). The parts are reached through ppfx.cpp's getters
// every time, as in the original (one call per helper below). The rectangle is
// a POD of four floats (Unk_Rect): with Unk_Float4's constructor its constant
// half isn't stored as one 8-byte constant.
s32 CPostEffect::DrawDebugBuffers() {
    // a texture to draw, or a device texture if there is none, and its scale
    struct Unk_DebugBuffer {
        // the first texture of a render texture array (none without one)
        static CRenderTexture* Unk_First(CGPUResourceManage* textures) {
            return textures != nullptr ? static_cast<CRenderTextureArray*>(textures)->Unk_Texture(0) : nullptr;
        }
        // the glare's afterimage of its active view
        static CRenderTexture* Unk_Afterimage(CRenderGlare* glare) {
            if (glare->m_ppAfterimageGeneration == nullptr) {
                return nullptr;
            }
            return glare->m_ppAfterimageGeneration[static_cast<u32>(glare->field_2ec)]->Unk_Texture(-1);
        }
        // a depth of field level's result
        static CRenderTexture* Unk_Level(const CDepthOfField::Unk_Level* level, bool second) {
            if (second) {
                return level->field_b0 != nullptr ? level->field_b0 : level->field_a0;
            }
            return level->field_b8 != nullptr ? level->field_b8 : level->field_a8;
        }

        // the tile of the target a buffer is drawn into (an inline function:
        // the tile's own inline level decides the loops' registers)
        static Unk_Rect Unk_Tile(f32 x, f32 y) {
            Unk_Rect rect = {1.0f / 16, 1.0f / 16, x / 16, y / 16};
            return rect;
        }

        Unk_DebugBuffer(CRenderTexture* texture, Unk_GPUTexture* deviceTexture, f32 scale)
            : field_0(texture), field_8(deviceTexture), field_10(scale) {}

        CRenderTexture* field_0;
        Unk_GPUTexture* field_8;
        f32 field_10;
    };
#define UNK_POSTEFFECT() reinterpret_cast<CPostEffect*>(Unk_418e20_get())
#define UNK_TEXTURES() static_cast<CRenderTextureArray*>(Unk_418e30())
#define UNK_GLARE() static_cast<CRenderGlare*>(Unk_418e40())
#define UNK_DOF() static_cast<CDepthOfField*>(Unk_418e50())
    if (!Unk_24e09b9) {
        return 0;
    }
    static s32 frame = 0;
    frame++;
    if (frame % 100 == 25) {
#line 35160
        PPFX_WARNING("Debug code: CPostEffect::DrawDebugBuffers().\n");
    }
    f32 scale = field_7f8;
    f32 exposure = field_8c0.field_0;
    f32 luminance = exposure / (field_59a ? exposure * field_7fc : scale);
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil(util);
    Unk_DebugBuffer buffers[] = {
        {UNK_TEXTURES()->Unk_Texture(0), nullptr, luminance},
        {UNK_TEXTURES()->Unk_Texture(1), nullptr, luminance},
        {UNK_TEXTURES()->Unk_Texture(2), nullptr, luminance},
        {util->field_29b08[3], nullptr, 1.0f},
        {util->field_29b08[4], nullptr, 1.0f},
        {util->field_29b08[6], nullptr, 1.0f},
        {util->field_29b08[9], nullptr, 1.0f},
        {util->field_29b08[8], nullptr, 1.0f},
        {reinterpret_cast<CRenderTexture*>(UNK_POSTEFFECT()->field_1f8), nullptr, 1.0f},
        {reinterpret_cast<CRenderTexture*>(UNK_POSTEFFECT()->field_208), nullptr, 1.0f},
        {UNK_POSTEFFECT()->field_d70 != nullptr ? reinterpret_cast<CRenderTexture*>(UNK_POSTEFFECT()->field_d70)
                                                : nullptr,
         nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_ViewLuminance()->field_48, nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_ViewLuminance()->field_40->field_88, nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_ViewLuminance()->field_40->field_30, nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_ViewLuminance2()->field_48, nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_ViewLuminance2()->field_40->field_88, nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_ViewLuminance2()->field_40->field_30, nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_OetfBase(), nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_OetfResize(0), nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_OetfResize(1), nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_OetfResize(2), nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_OetfLastResize(), nullptr, 1.0f},
        {UNK_POSTEFFECT()->Unk_Luminance588() != nullptr ? UNK_POSTEFFECT()->Unk_ViewLuminance588()->field_48 : nullptr,
         nullptr, 1.0f},
        {static_cast<CRenderTextureArray*>(UNK_GLARE()->m_pGlareSource)->Unk_Texture(0), nullptr, luminance},
        {static_cast<CRenderTextureArray*>(UNK_GLARE()->m_pGlareSource)->Unk_Texture(1), nullptr, 4.0f},
        {static_cast<CRenderTextureArray*>(UNK_GLARE()->m_pGlareSource)->Unk_Texture(2), nullptr, 4.0f},
        {static_cast<CRenderTexture*>(UNK_GLARE()->m_pLightShaftBlurSource), nullptr, scale * 200.0f},
        {static_cast<CRenderTexture*>(UNK_GLARE()->m_pLightShaftResult), nullptr, scale * 10.0f},
        {static_cast<CRenderTexture*>(UNK_GLARE()->m_pBloomResult), nullptr, scale * 10.0f},
        {static_cast<CRenderTexture*>(UNK_GLARE()->m_pStarResult), nullptr, scale * 10.0f},
        {static_cast<CRenderTexture*>(UNK_GLARE()->m_pAnamorphicFlareResult), nullptr, scale * 10.0f},
        {Unk_DebugBuffer::Unk_First(UNK_GLARE()->m_pGhostGeneration), nullptr, scale * 10.0f},
        {Unk_DebugBuffer::Unk_Afterimage(UNK_GLARE()), nullptr, scale * 10.0f},
        {static_cast<CRenderTexture*>(UNK_GLARE()->m_pGlareResult), nullptr, scale * 10.0f},
        {UNK_GLARE()->field_420, nullptr, scale * 10.0f},
        {nullptr, reinterpret_cast<Unk_GPUTexture*>(UNK_POSTEFFECT()->Unk_TextureUtil()->field_29a70[0]), 1.0f},
        {nullptr, reinterpret_cast<Unk_GPUTexture*>(UNK_POSTEFFECT()->Unk_TextureUtil()->field_29ab8[0]), 1.0f},
        {nullptr, reinterpret_cast<Unk_GPUTexture*>(UNK_GLARE()->field_348), 1.0f},
        {nullptr, reinterpret_cast<Unk_GPUTexture*>(UNK_POSTEFFECT()->Unk_TextureUtil()->field_29ab8[2]), 1.0f},
        {nullptr, reinterpret_cast<Unk_GPUTexture*>(UNK_POSTEFFECT()->Unk_TextureUtil()->field_29ab8[1]), 1.0f},
        {UNK_DOF()->field_3f8 > 0 ? UNK_DOF()->field_438[0] : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 1 ? UNK_DOF()->field_438[1] : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 2 ? UNK_DOF()->field_438[2] : nullptr, nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 2 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[2], false) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 3 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[3], false) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 4 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[4], false) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 5 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[5], false) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 6 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[6], false) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 2 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[2], true) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 3 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[3], true) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 4 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[4], true) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 5 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[5], true) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_c0.field_10 > 6 ? Unk_DebugBuffer::Unk_Level(&UNK_DOF()->field_4a8[6], true) : nullptr,
         nullptr, luminance},
        {UNK_DOF()->field_3f8 > 0 ? UNK_DOF()->Unk_4b35a0(false, 0) : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 1 ? UNK_DOF()->Unk_4b35a0(false, 1) : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 2 ? UNK_DOF()->Unk_4b35a0(false, 2) : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 0 ? UNK_DOF()->Unk_4b35a0(true, 0) : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 1 ? UNK_DOF()->Unk_4b35a0(true, 1) : nullptr, nullptr, luminance},
        {UNK_DOF()->field_3f8 > 2 ? UNK_DOF()->Unk_4b35a0(true, 2) : nullptr, nullptr, luminance},
        {reinterpret_cast<CRenderTexture*>(field_228), nullptr, 1.0f},
        {reinterpret_cast<CRenderTexture*>(field_230), nullptr, 1.0f},
    };
#undef UNK_POSTEFFECT
#undef UNK_TEXTURES
#undef UNK_GLARE
#undef UNK_DOF
    const s32 count = sizeof(buffers) / sizeof(buffers[0]);
    for (s32 i = 0; i < count; i++) {
        f32 x = i % 16;
        f32 y = i / 16;
        if (buffers[i].field_0 != nullptr) {
            f32 factor = buffers[i].field_10 * Unk_238c2d8;
            Unk_49b230_Object* target = reinterpret_cast<Unk_49b230_Object*>(field_1168);
            Unk_Rect rect = Unk_DebugBuffer::Unk_Tile(x, y);
            CRenderTextureArray::Unk_4a6a50(target, buffers[i].field_0, 0, reinterpret_cast<const Unk_Float4*>(&rect),
                                            false, 3, factor);
        } else if (buffers[i].field_8 != nullptr) {
            f32 factor = buffers[i].field_10 * Unk_238c2d8;
            Unk_49b230_Object* target = reinterpret_cast<Unk_49b230_Object*>(field_1168);
            Unk_Rect rect = Unk_DebugBuffer::Unk_Tile(x, y);
            CRenderTextureArray::CopyToSurface(target, buffers[i].field_8, 0, factor,
                                               reinterpret_cast<const Unk_Float4*>(&rect), 1.0f, false, 1.0f, 3);
        }
    }
    for (s32 i = 0; i < count; i++) {
        f32 x = i % 16;
        f32 y = i / 16 + 4.0f;
        if (buffers[i].field_0 != nullptr) {
            f32 factor = Unk_238c2dc;
            Unk_49b230_Object* target = reinterpret_cast<Unk_49b230_Object*>(field_1168);
            Unk_Rect rect = Unk_DebugBuffer::Unk_Tile(x, y);
            CRenderTextureArray::Unk_4a6a50(target, buffers[i].field_0, 0x15,
                                            reinterpret_cast<const Unk_Float4*>(&rect), false, 3, factor);
        } else if (buffers[i].field_8 != nullptr) {
            f32 factor = Unk_238c2dc;
            Unk_49b230_Object* target = reinterpret_cast<Unk_49b230_Object*>(field_1168);
            Unk_Rect rect = Unk_DebugBuffer::Unk_Tile(x, y);
            CRenderTextureArray::CopyToSurface(target, buffers[i].field_8, 0x15, factor,
                                               reinterpret_cast<const Unk_Float4*>(&rect), 1.0f, false, 1.0f, 3);
        }
    }
    return 0;
}

// (an inline function: callers in other files call this copy, and as a
// linkonce function it isn't known not to write memory, so Unk_429f20 reloads
// field_1a0 after calling it)
inline bool Unk_4385e0(s32 format);

// a render texture's format (inline: in a branch it keeps the null test of
// the texture a branch that is threaded into Unk_41af70's)
static inline s32 Unk_FormatOf(const Unk_RenderTexture* texture) {
    return texture->field_38;
}

// 0x7100429f20
s32 CPostEffect::Unk_429f20(bool set, bool enable) {
    Unk_4aa5a0_Self* dof = field_1a0;
    if (dof == nullptr) {
        return 0;
    }
    if (!set) {
        enable = field_914 != 0;
    }
    dof->field_1e0 = enable;
    Unk_RenderTexture* texture = Unk_41af70();
    s32 format0 = texture != nullptr ? Unk_FormatOf(texture) : field_6a8;
    s32 index = field_5e0;
    if (index == -1) {
        index = field_190->field_90;
    }
    s32 format1 = field_190->field_38[index]->field_38;
    s32 format2 = field_1a0->field_d4;
    // the fewest bits per channel of the three formats (~0: none known)
    s32 formats[3] = {format0, format1, format2};
    u32 bits = 0xffffffff;
    for (s32 i = 0; i < 3; i++) {
        switch (formats[i]) {
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 49:
        case 50:
        case 51:
        case 52:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 87:
        case 88:
        case 91:
        case 93:
            bits = bits < 8 ? bits : 8;
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 35:
        case 36:
        case 37:
        case 38:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
            bits = bits < 16 ? bits : 16;
            break;
        default:
            if (formats[i] != 0 && Unk_4385e0(formats[i])) {
                bits = bits < 24 ? bits : 24;
            }
            break;
        }
    }
    reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aa030(bits == 0xffffffff ? 0 : bits);
    return 0;
}

// the greater of two values, by reference, the first one when they're equal
// (inline)
template <class T>
inline const T& Unk_Greater(const T& a, const T& b) {
    return a > b ? a : b;
}

// 0x710042b8a0: field_8f4 to field_8f8 follows field_6c4 to field_6c8 from
// last frame's range, and field_904 to field_908 follows that
// (field_904's value read into a local before field_908's bound gives the
// original's order of the last select and the store)
s32 CPostEffect::Unk_42b8a0() {
    field_8f4 = field_8ec;
    field_8f8 = field_8f0;
    field_8f4 = std::max(field_6c4, field_8f4);
    field_8f4 = std::min(field_6c8 * 0.99f, field_8f4);
    f32 high = std::min(field_6c8, field_8f8);
    high = high <= 0.0f ? field_6c8 : high;
    if (high <= field_8f4) {
        high = (field_6c8 - field_8f4) * 0.01f + field_8f4;
    }
    field_8f8 = high;
    field_904 = field_8fc;
    field_908 = field_900;
    field_904 = Unk_Greater(field_904, field_8f4);
    field_904 = std::min(field_8f8 * 0.99f, field_904);
    f32 high2 = std::min(field_8f8, field_908);
    f32 low = field_904;
    field_908 = high2 <= 0.0f ? field_8f8 : high2;
    if (field_908 <= low) {
        field_908 = (field_8f8 - field_904) * 0.01f + field_904;
        field_908 = std::min(field_8f8, field_908);
    }
    return 0;
}

// whether a format's channels are 32-bit floats (inline)
static inline bool Unk_IsFloat32Format(s32 format) {
    bool result = false;
    switch (format) {
    case 2:
    case 6:
    case 16:
    case 20:
    case 21:
    case 40:
    case 41:
        result = true;
        break;
    }
    return result;
}
// whether they are 16-bit floats or shared-exponent ones (inline)
static inline bool Unk_IsFloat16Format(s32 format) {
    switch (format) {
    case 10:
    case 34:
    case 54:
    case 67:
        return true;
    default:
        return false;
    }
}
// the linear format of an sRGB one (inline)
static inline s32 Unk_LinearFormat(s32 format) {
    switch (format) {
    case 0:
        return 0;
    case 29:
        return 28;
    case 72:
        return 71;
    case 75:
        return 74;
    case 78:
        return 77;
    case 91:
        return 87;
    case 93:
        return 88;
    case 99:
        return 98;
    default:
        return format;
    }
}

// what render target the frame's feedback is in (inline)
inline Unk_RenderTexture* CPostEffect::Unk_FeedbackTexture() {
    if (field_260 == nullptr) {
        return nullptr;
    }
    s32 view = field_298;
    Unk_4a5d10_Self* textures = field_260[view];
    s32 index = field_290[view] & 1;
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

// field_278, else the feedback texture (inline)
inline Unk_RenderTexture* CPostEffect::Unk_428f00_Copy() {
    if (field_278 != nullptr) {
        return field_278;
    }
    return Unk_FeedbackTexture();
}

// texture field_670 (-1: the current one) of `textures` (inline)
inline Unk_RenderTexture* CPostEffect::Unk_428f00_Previous(Unk_4a5d10_Self* textures) {
    s32 index = field_670;
    if (index == -1) {
        index = textures->field_90;
    }
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

// what 0x7100428f00 reads of field_1168 (placeholder)
struct Unk_428f00_Target {
    u8 pad_0[0x4c];
    u32 field_4c;
    u32 field_50;
};

// 0x7100428cc0: the scale and offset (and their inverse) that take depths of
// one kind (`from`) to another (`to`), through the stages between them
s32 CPostEffect::Unk_428cc0(f32* out, s32 from, s32 to, f32 a, f32 b) {
    if (from == 6) {
        from = field_5c;
    }
    if (to == 6) {
        to = field_5c;
    }
    Unk_Refresh();
    f32 offset = 0.0f;
    f32 scale = 1.0f;
    if (from != to) {
        f32 near = field_6c4;
        f32 far = field_6c8;
        s32 low = from < to ? from : to;
        s32 high = from > to ? from : to;
        Unk_Refresh();
        if (low < 1 && high >= 1) {
            f32 f = field_1064;
            f32 k = (far - near) * f / (near * far);
            offset = (1.0f - f / near) + offset * k;
            scale = scale * k;
        }
        if (low < 2 && high >= 2) {
            f32 k = field_1054;
            f32 m = field_1058;
            scale = scale * k;
            offset = offset * k + m;
        }
        if (low < 3 && high >= 3) {
            f32 c = field_105c;
            f32 o = offset * c;
            f32 d = field_1060;
            Unk_Refresh();
            scale = scale * c;
            o = o + d;
            f32 e = field_1050 ? field_1a0->field_1e4 : 0.0f;
            scale = scale * e;
            offset = o * e + 0.0f;
        }
        if (from >= to) {
            f32 inverse = 1.0f / scale;
            offset = -offset / scale;
            scale = inverse;
        }
    }
    if (a != 1.0f || b != 0.0f) {
        f32 inverse = 1.0f / a;
        offset = offset - b / a * scale;
        scale = inverse * scale;
    }
    f32 inverse = 1.0f / scale;
    f32 inverseOffset = -offset / scale;
    out[0] = scale;
    out[1] = offset;
    out[2] = inverse;
    out[3] = inverseOffset;
    return 0;
}

// 0x7100428f00: the render target the feedback is read from. The original
// has one block for each of field_278's and field_670's paths, so each
// helper is called once (the second tests field_970 again when it is entered
// from the size branch); the target's width is converted before it is
// multiplied (`(f32)w * scale`, the registers of the product).
Unk_RenderTexture* CPostEffect::Unk_428f00() {
    // CPostEffect::GetEffectiveFeedbackEnable(), its log line says
    bool feedback = field_bce;
    if (field_96c && field_970 != 0 && feedback) {
        s32 format = field_518;
        bool f32 = Unk_IsFloat32Format(format);
        if (!(Unk_IsFloat16Format(format) || ((format == 26) | f32))) {
#line 16846
            PPFX_WARNING("CPostEffect::GetEffectiveFeedbackEnable(): The feedback result will be clamped because the feedback buffer format is not floating point. Use PFXOETA_IMMEDIATE_IMPLICIT oetf or set floating point format to PFX_INITPARAM::m_eFeedbackFormat.\n");
        }
    }
    if (feedback) {
        return Unk_FeedbackTexture();
    }
    s32 count = field_f30;
    if (count == -1) {
        count = field_f2c;
    }
    s32 index = field_66c;
    Unk_4a5d10_Self* textures = field_190;
    if (index == -1) {
        index = textures->field_90;
    }
    Unk_RenderTexture* texture = textures->field_38[index];
    const Unk_428f00_Target* target = reinterpret_cast<const Unk_428f00_Target*>(field_1168);
    u32 width = static_cast<u32>(static_cast<f32>(target->field_4c) * field_5a4);
    bool resize = (texture->field_54 != width ||
                   texture->field_58 != static_cast<u32>(field_5a8 * static_cast<f32>(target->field_50))) &&
                  count >= 1;
    if (!resize || field_96c || Unk_24e09bc != 0) {
        if (!(resize && field_96c && field_970 != 0) && !field_10d6) {
            return nullptr;
        }
        if (field_96c && field_970 != 0) {
            return Unk_428f00_Previous(textures);
        }
    }
    return Unk_428f00_Copy();
}

// 0x710042f070 (its log line names it)
s32 CPostEffect::ApplyEffects_DepthOfField() {
    if (!field_104f) {
        return 0;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_4a5d10_Self* textures = field_190;
    textures->field_90 = field_60c;
    Unk_42e560();
    f32 scale = field_8b0;
    f32 a = field_8cc;
    f32 b = field_8d0;
    s32 mode = field_69c;
    if (scale != 1.0f) {
        if (mode == 0) {
            mode = 11;
            a = 1.0f;
            b = a / scale;
        } else {
            b = b / scale;
        }
    }
    reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aeed0(mode, -1, -1);
    util->Unk_470610(a, b);
    f32 exposure = field_8c0.field_0;
    Unk_4aa5a0_Self* dof = field_1a0;
    dof->field_3ac = exposure / (field_59a ? exposure * field_7fc : field_7f8);
    s32 result = reinterpret_cast<CDepthOfField*>(field_1a0)
                     ->ApplyDepthOfField(reinterpret_cast<CRenderTexture*>(Unk_TextureAt(field_604)),
                                         Unk_TextureAt(field_608),
                                         reinterpret_cast<CRenderTexture*>(Unk_TextureAt(field_60c)), true);
    if (result < 0) {
#line 25785
        PPFX_ERROR("CPostEffect::ApplyEffects_DepthOfField(): m_pDepthOfField->ApplyDepthOfField() failed (0x%x: %s).\n",
                   result, Unk_446df0(result));
    }
    field_67a = true;
    return result;
}

// 0x710042bbe0: `source` (null: Unk_41af70's) drawn into each of
// field_550's textures that is narrower than the last one drawn; the last of
// them, if anything was drawn
Unk_RenderTexture* CPostEffect::Unk_42bbe0(Unk_RenderTexture* source) {
    if (source == nullptr) {
        source = Unk_41af70();
    }
    if (field_558 == 0) {
        return source;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    bool drawn = false;
    Unk_RenderTexture* current = source;
    Unk_RenderTexture* target;
    for (s32 i = 0; i < field_558; i++) {
        target = field_550[i];
        if (target->field_54 < current->field_54) {
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
            drawn = true;
            util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, reinterpret_cast<CRenderTexture*>(target), 0, &color, 0,
                             false, false, 1, &offset, nullptr, -1);
            current = target;
        }
    }
    return drawn ? target : source;
}

// 0x710042cba0
s32 CPostEffect::Unk_42cba0(bool arg) {
    if ((field_1051 || field_50 != nullptr) && !field_1053) {
        bool flag = true;
        if (!field_18->field_14efa) {
            Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
            flag = false;
        }
        void* a6 = nullptr;
        u32 a7 = 0;
        u32 a8 = 2;
        u32 a9 = 0;
        f32 a10 = 0.0f;
        if (arg) {
            a6 = field_80;
            a7 = field_8c;
            a8 = field_90;
            a9 = field_94;
            a10 = field_98;
        }
        Unk_42cc90(-1, 0, nullptr, nullptr, flag, a6, a7, a8, a9, a10);
    }
    return 0;
}

// the sRGB format of a linear one (inline: placeholder name)
static inline s32 Unk_SrgbFormat(s32 format) {
    switch (format) {
    case 2:
        return 3;
    case 4:
        return 5;
    case 6:
        return 7;
    case 8:
        return 9;
    case 10:
        return 11;
    case 14:
        return 15;
    default:
        return format;
    }
}

// whether a matrix is the identity (inline)
static inline bool Unk_IsIdentity(const MATRIXT44& m) {
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 4; j++) {
            if (m.field_0[i][j] != (i == j ? 1.0f : 0.0f)) {
                return false;
            }
        }
    }
    return true;
}

// a function-local matrix (its constructor does nothing, so a static one has
// a guard without an initialisation)
struct Unk_StaticMatrix : MATRIXT44 {
    Unk_StaticMatrix() {}
    using MATRIXT44::operator=;
};

// 0x710042df80: what the final pass draws with: the output format, two
// scales, the dither's amount, the gamma (and whether there is one), and the
// two colour matrices (null: none; the colour space's conversion and
// field_1094's are folded into function-local copies)
// NON_MATCHING: 58 instructions (was 161): the tests, the calls and the block
// order are the original's; what is left is register allocation (x19/x21 of
// the first tests, gamma in s12/s13 where the original keeps it in s10 and
// the final one in s0, x4 to x7 spilled in another pairing) and the
// `csel ..., eq` of `matrix`. What decided the rest: the space as an `if`
// with its own -1 test, the HDR test as `!(field_96c == 0 && Unk_24e09bc ==
// 0)` (as `||` it becomes an `orr`), `hasMatrix` read just before `matrix`,
// the identity test as one `&&` chain and `hasGamma` computed before the
// stores.
s32 CPostEffect::Unk_42df80(s32* outFormat, f32* outScale, f32* outScale2, f32* outDither, bool* outHasGamma,
                            f32* outGamma, MATRIXT44** outMatrix, MATRIXT44** outMatrix2, bool linear, bool keep) {
    s32 format = field_6a4;
    u32 toneMap = field_8c8;
    if (field_106c && field_59c && field_599) {
        format = Unk_SrgbFormat(format);
    }
    if (field_106b) {
        format = Unk_SrgbFormat(format);
    }
    f32 gamma = field_8c4.field_0;
    f32 dither = Unk_434570() ? 1.0f : 0.0f;
    f32 divisor = field_8d0;
    f32 scale = field_8cc;
    f32 scale2 = 1.0f;
    if (!field_59d || field_106b) {
        scale2 = divisor;
    } else {
        if ((toneMap & 0xffff0000) == 0x70000 && field_106c) {
            format = 15;
        }
        scale = scale / divisor;
    }
    bool hasMatrix = field_b34[0];
    MATRIXT44* matrix = hasMatrix ? &field_9b4[0] : nullptr;
    bool hasMatrix2 = field_b34[1];
    MATRIXT44* matrix2 = hasMatrix2 ? &field_9b4[1] : nullptr;
    static Unk_StaticMatrix converted2;
    MATRIXT44 conversion = Unk_429c50(true);
    if (!(conversion.field_0[0][0] == 1.0f &&
          conversion.field_0[0][1] == 0.0f &&
          conversion.field_0[0][2] == 0.0f &&
          conversion.field_0[0][3] == 0.0f &&
          conversion.field_0[1][0] == 0.0f &&
          conversion.field_0[1][1] == 1.0f &&
          conversion.field_0[1][2] == 0.0f &&
          conversion.field_0[1][3] == 0.0f &&
          conversion.field_0[2][0] == 0.0f &&
          conversion.field_0[2][1] == 0.0f &&
          conversion.field_0[2][2] == 1.0f &&
          conversion.field_0[2][3] == 0.0f &&
          conversion.field_0[3][0] == 0.0f &&
          conversion.field_0[3][1] == 0.0f &&
          conversion.field_0[3][2] == 0.0f &&
          conversion.field_0[3][3] == 1.0f)) {
        converted2 = conversion;
        if (hasMatrix2) {
            MATRIXT44 m;
            MATRIXT44_MatrixMultiply(&m, matrix2, &converted2);
            converted2 = m;
        }
        matrix2 = &converted2;
    }
    static Unk_StaticMatrix converted;
    f32 scale3 = scale2;
    if (!(field_96c == 0 && Unk_24e09bc == 0) && !linear) {
        s32 space = 1;
        if (field_96c) {
            space = field_97c;
            if (space == -1) {
                space = 1;
            }
        }
        if (keep) {
            if (space != 1 || field_8c4.field_0 <= 0.0f) {
                gamma = 1.0f;
            } else {
                gamma = gamma / 2.2f;
            }
        } else {
            scale3 = 1.0f;
            f32 value = 1.0f;
            if (space != 1) {
                value = field_8c4.field_0 <= 0.0f ? 1.0f : gamma / 2.2f;
            }
            format = 0;
            gamma = value;
            scale = scale / scale2;
        }
        if (!Unk_SameColorSpace(field_b84, field_ba4)) {
            if (hasMatrix) {
                if (matrix != &converted) {
                    converted = *matrix;
                }
            } else {
                Unk_Identity(&converted);
            }
            MATRIXT44 inverse;
            MATRIXT44 m = field_1094;
            Unk_4155f0(&inverse, &m);
            MATRIXT44_MatrixMultiply(&converted, &converted, &inverse);
            matrix = &converted;
        }
    }
    if (!field_59c && !field_96c && Unk_24e09bc == 0 && !linear && field_9ac == 1) {
        if (gamma != 0.0f) {
            gamma = gamma / 2.2f;
        } else {
            gamma = 1.0f;
        }
    }
    bool hasGamma = gamma != 1.0f;
    if (outFormat != nullptr) {
        *outFormat = format;
    }
    if (outScale != nullptr) {
        *outScale = scale;
    }
    if (outScale2 != nullptr) {
        *outScale2 = scale3;
    }
    if (outDither != nullptr) {
        *outDither = dither;
    }
    if (outHasGamma != nullptr) {
        *outHasGamma = hasGamma;
    }
    if (outGamma != nullptr) {
        *outGamma = gamma;
    }
    if (outMatrix != nullptr) {
        *outMatrix = matrix;
    }
    if (outMatrix2 != nullptr) {
        *outMatrix2 = matrix2;
    }
    return 0;
}

// 0x71004280e0: a number by field_1008's mode (tan of half of field_6cc)
// The product is selected by the mode (`mode == 3 ? value : value * scale`),
// which gives the default case its own `field_100c * 0.0` block; case 2 adds
// its constant in a second statement (in one expression the product is put
// in s3).
f32 CPostEffect::Unk_4280e0() {
    f32 value;
    switch (field_1008) {
    case 0:
        value = 1.1996114f - tanf(field_6cc * 0.5f);
        break;
    case 1:
        value = -0.09597635f - logf(tanf(field_6cc * 0.5f));
        break;
    case 2:
        value = 1.0f / tanf(field_6cc * 0.5f) * 0.2f;
        value += 0.30255502f;
        break;
    case 3:
        value = field_100c;
        break;
    default:
        value = 0.0f;
        break;
    }
    f32 result = field_1008 == 3 ? value : value * field_100c;
    result += field_1010;
    if (field_1008 == 3) {
        return result;
    }
    if (field_1a0 != nullptr && Unk_4afa90_get(reinterpret_cast<const Unk_4afa90*>(field_1a0)) > 0.0f) {
        result += Unk_4afa70_get(reinterpret_cast<const Unk_4afa70*>(field_1a0)) * -0.5f;
    }
    return result;
}

// 0x71004622e0 (GPUTextureUtil.cpp)
bool Unk_4622e0(f32 low, f32 high, f32 current, f32 previous);

// the smaller and the larger of two numbers (inline)
static inline const f32& Unk_Less(const f32& a, const f32& b) {
    return a < b ? a : b;
}
static inline const f32& Unk_Greater(const f32& a, const f32& b) {
    return a > b ? a : b;
}

// 0x7100427ad0: whether field_6c4 or field_6c8 is to change (each limited by
// field_8f4 to field_8f8 and by field_90c and field_910)
// The last test is a `&` of the two comparisons (with `&&` GVN knows
// `now < before` where `next` is compared and compares `before` instead).
bool CPostEffect::Unk_427ad0() {
    f32 low = field_8f4;
    f32 x = field_90c;
    if (x > 0.0f) {
        f32 high = field_8f8;
        low = x < low ? low : (x > high ? high : x);
        f32 y = field_910;
        if (y > 0.0f) {
            low = Unk_Less(low, y);
        }
    }
    f32 current = field_6c4;
    f32 before = field_ef0;
    f32 now = field_eec;
    if (Unk_4622e0(current, field_6c8, now, before)) {
        f32 next = now > before ? before : current;
        current = next > current ? next : current;
    }
    if ((low > current ? low : current) != field_6c4) {
        return true;
    }
    f32 high = field_8f8;
    f32 y = field_910;
    if (y > 0.0f) {
        f32 low2 = field_8f4;
        high = y < low2 ? low2 : (y > high ? high : y);
        f32 x2 = field_90c;
        if (x2 > 0.0f) {
            high = Unk_Greater(high, x2);
        }
    }
    current = field_6c8;
    before = field_ef0;
    now = field_eec;
    if (Unk_4622e0(field_6c4, current, now, before)) {
        f32 next = now < before ? before : current;
        if ((now < before) & (next < current)) {
            current = before;
        }
    }
    return (high < current ? high : current) != field_6c8;
}

// 0x7100429c50: field_b3c after field_1094 if field_b84 and field_ba4 differ
// (and `arg`)
MATRIXT44 CPostEffect::Unk_429c50(bool arg) {
    MATRIXT44 result;
    Unk_Identity(&result);
    if (arg) {
        for (s32 i = 0; i < 8; i++) {
            if (reinterpret_cast<const f32*>(&field_b84)[i] != reinterpret_cast<const f32*>(&field_ba4)[i]) {
                MATRIXT44 m = field_1094;
                MATRIXT44_MatrixMultiply(&result, &result, &m);
                break;
            }
        }
    }
    MATRIXT44_MatrixMultiply(&result, &result, &field_b3c);
    return result;
}

// 0x7100410400
s32 Unk_410400(s32 type);

// 0x710040f8d0
void Unk_40f8d0(MATRIXT44* out, bool arg1, bool arg2, f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);

// 0x71004297b0: CTextureUtil::Unk_488380 with field_d84 and field_d88 and the
// view's off-centre frustum; whether it or an earlier call set field_1090
bool CPostEffect::Unk_4297b0() {
    field_1090 = false;
    field_1091 = false;
    if (!field_d80 || field_8b6) {
        return false;
    }
    if (field_d84 < 0 || field_d88 == nullptr) {
        return false;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    f32 near = field_6c4;
    f32 height = field_6d0;
    f32 width = height * field_420;
    f32 halfHeight = near * height;
    f32 halfWidth = near * width;
    f32 x = field_6d4 * halfWidth;
    f32 y = halfHeight * field_6d8;
    f32 far = field_6c8;
    f32 right = halfWidth + x;
    f32 bottom = y - halfHeight;
    f32 top = halfHeight + y;
    f32 left = x - halfWidth;
    s32 index = field_d84;
    void* data = field_d88;
    const MATRIXT44* view = &field_734;
    MATRIXT44 projection;
    Unk_40f8d0(&projection, false, true, left, right, bottom, top, near, far);
    s32 result =
        util->Unk_488380(field_de4, field_de0, field_d94, index, data, view, &projection, field_d90, &field_d9c);
    field_1091 = true;
    if (result != 0) {
        field_1090 = true;
        return true;
    }
    return field_1090;
}

// the smaller of two numbers (std::min's order)
static inline const Unk_Float& Unk_Min(const Unk_Float& a, const Unk_Float& b) {
    return a.field_0 < b.field_0 ? a : b;
}

// a device texture as Unk_432ca0 sets its filter (PPFX::IGPUTexture's slots
// 18 and 20)
struct Unk_FilteredTexture {
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
    virtual s32 vf18(u32 filter);
    virtual void vf19();
    virtual u32 vf20();
};

// a render texture's device texture (inline)
static inline Unk_FilteredTexture* Unk_FilterOf(Unk_RenderTexture* texture) {
    return reinterpret_cast<Unk_FilteredTexture*>(Unk_GetTexture(reinterpret_cast<CRenderTexture*>(texture)));
}

// the larger of two numbers (inline)
static inline const Unk_Float& Unk_Max(const Unk_Float& a, const Unk_Float& b) {
    return a.field_0 > b.field_0 ? a : b;
}

// 0x7100432ca0: draws with CTextureUtil (Unk_499250 with field_560's pairs,
// their filters set too, else Unk_497b20) with the textures' filters set to
// `filter` (negative: the one of field_c94), the colour's magnitudes (at
// least 1e-5, the first negated with `negate`) and `scale` (negative:
// field_c8c), then sets the filters back
// NON_MATCHING: the same instructions but for the callee-saved registers of
// `filter`, `list`, `negate`, the count and the first texture's filter (a
// rotation of w25 to w28: here `filter` takes w25, the original w28; tried
// the scale test first and the texture utility fetched later, `s64` and
// `u32` indices and counts, the list test's spellings, the colour's loop
// index, the third filter by `if`, a helper for the filters' calls; the
// restore loop's first saved filter read into a local before the call loads
// it before the parent loop, the original between the loop and the virtual
// call). Each element
// of the colour read where its magnitude is taken (not all four first) gives
// the original's loads and order.
s32 CPostEffect::Unk_432ca0(f32 scale, Unk_RenderTexture* arg1, Unk_RenderTexture* arg2, Unk_RenderTexture* arg3,
                            Unk_RenderTexture* arg4, const Unk_Float4* color, s32 filter, bool list, bool negate) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (filter < 0) {
        switch (field_c94) {
        case 0:
            filter = 1;
            break;
        case 1:
            filter = 3;
            break;
        case 2:
            filter = 2;
            break;
        case 3:
            filter = 0;
            break;
        default:
            filter = 0x7fffffff;
            break;
        }
    }
    if (scale < 0.0f) {
        scale = field_c8c;
    }
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
    u32 filter1 = Unk_FilterOf(arg1)->vf20();
    u32 filter2 = Unk_FilterOf(arg2)->vf20();
    u32 filter3 = arg3 != nullptr ? Unk_FilterOf(arg3)->vf20() : 0x7fffffff;
    Unk_FilterOf(arg1)->vf18(filter);
    Unk_FilterOf(arg2)->vf18(filter);
    if (arg3 != nullptr) {
        Unk_FilterOf(arg3)->vf18(filter);
    }
    Unk_Float4 c(color->field_0[0].field_0 > 0.0f ? color->field_0[0].field_0 : -color->field_0[0].field_0,
                 color->field_0[1].field_0 > 0.0f ? color->field_0[1].field_0 : -color->field_0[1].field_0,
                 color->field_0[2].field_0 > 0.0f ? color->field_0[2].field_0 : -color->field_0[2].field_0,
                 color->field_0[3].field_0 > 0.0f ? color->field_0[3].field_0 : -color->field_0[3].field_0);
    Unk_Float least = 1e-05f;
    for (s32 i = 0; i < 4; i++) {
        c.field_0[i] = Unk_Max(c.field_0[i], least);
    }
    if (negate) {
        c.field_0[0].field_0 = -c.field_0[0].field_0;
    }
    s32 count = field_568;
    s32 result;
    if (count != 0 && list) {
        u32 saved[16][2];
        for (s32 i = 0; i < count; i++) {
            saved[i][0] = Unk_FilterOf(field_560[i].field_0)->vf20();
            Unk_FilterOf(field_560[i].field_0)->vf18(filter);
            saved[i][1] = Unk_FilterOf(field_560[i].field_8)->vf20();
            Unk_FilterOf(field_560[i].field_8)->vf18(filter);
        }
        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
        result = util->Unk_499250(1.0f, scale, 4.0f, reinterpret_cast<CRenderTexture*>(arg1),
                                  reinterpret_cast<CRenderTexture*>(arg2), reinterpret_cast<CRenderTexture*>(arg3),
                                  reinterpret_cast<CRenderTexture*>(arg4), &c, 0, &ones, count, field_560, 2, false,
                                  false, false, 0, 0);
        for (s32 i = 0; i < count; i++) {
            Unk_FilterOf(field_560[i].field_0)->vf18(saved[i][0]);
            Unk_FilterOf(field_560[i].field_8)->vf18(saved[i][1]);
        }
    } else {
        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
        result = util->Unk_497b20(1.0f, scale, reinterpret_cast<CRenderTexture*>(arg1),
                                  reinterpret_cast<CRenderTexture*>(arg2), reinterpret_cast<CRenderTexture*>(arg4), &c,
                                  0, &ones, 0, false, false, 0, 0);
    }
    Unk_FilterOf(arg1)->vf18(filter1);
    Unk_FilterOf(arg2)->vf18(filter2);
    if (arg3 != nullptr) {
        Unk_FilterOf(arg3)->vf18(filter3);
    }
    return result;
}

// 0x7100433270: Unk_432ca0 with the textures field_630, field_634 and
// field_638 name and a colour from field_1070 and the first's height
s32 CPostEffect::Unk_433270() {
    if (!field_106e) {
        return 0;
    }
    Unk_RenderTexture* first = Unk_TextureAt(field_630);
    Unk_RenderTexture* second = Unk_TextureAt(field_634);
    Unk_RenderTexture* third = Unk_TextureAt(field_638);
    f32 scale = first->field_58 * field_1070;
    Unk_Float size = scale * 0.344375193f;
    Unk_Float limit = 5.0f;
    Unk_Float4 color;
    if (field_c78) {
        size = field_568 == 0 ? Unk_Min(size, Unk_Float(4.77691078f)) : size;
        color.field_0[0].field_0 = size.field_0 * 1.04670167f;
        color.field_0[1].field_0 = size.field_0 * 0.919055104f;
        color.field_0[2].field_0 = size.field_0 * 0.791408539f;
        color.field_0[3].field_0 = size.field_0;
    } else {
        size = field_568 != 0 || size.field_0 < limit.field_0 ? size : limit;
        color = Unk_Float4(size, size, size, size);
    }
    color.field_0[0].field_0 = -color.field_0[0].field_0;
    s32 result = Unk_432ca0(0.005f, first, second, nullptr, third, &color, 2, 1, true);
    return result < 0 ? result : 0;
}

// 0x7100410070
void Unk_410070(Unk_Vector3* out, const Unk_Vector3* v, const MATRIXT44* m);

// the luminance weights of a colour space: Rec. 709's for the default one,
// else the Y row of its RGB to XYZ matrix (inline)
static inline Unk_Vector3 Unk_LuminanceWeights(const Unk_410f90& space) {
    if (Unk_SameColorSpace(space, Unk_410f90_Object(0))) {
        Unk_Vector3 weights = {{0.2126f, 0.7152f, 0.0722f}};
        return weights;
    }
    MATRIXT44 m;
    Unk_411b00(&m, &space.field_0, &space.field_8, &space.field_10, &space.field_18);
    Unk_Vector3 y = {{m.field_0[0][1], m.field_0[1][1], m.field_0[2][1]}};
    return y;
}

// the output's gamma (inline)
static inline f32 Unk_OutputGamma(const CPostEffect* self) {
    return self->field_8c4.field_0;
}

// 0x710042f320: `value` scaled by what `m` makes of white (its luminance for
// modes 4 and 8, else its largest component), then through the output gamma
// when it isn't 2.2
f32 CPostEffect::Unk_42f320(f32 value, const MATRIXT44* m, s32 mode) {
    bool gamma;
    if (field_96c && field_97c == 0) {
        gamma = field_8c4.field_0 <= 0.0f || Unk_OutputGamma(this) != 2.2f;
    } else {
        gamma = false;
    }
    if (m == nullptr && !gamma) {
        return value;
    }
    bool luminance = mode == 4 || mode == 8;
    Unk_Vector3 v;
    {
        Unk_Vector3 transformed;
        Unk_Vector3 white;
        white.field_0[0] = 1.0f;
        white.field_0[1] = 1.0f;
        white.field_0[2] = 1.0f;
        Unk_410070(&transformed, &white, m);
        v = transformed;
    }
    f32 max = v.field_0[0] > v.field_0[1] ? v.field_0[0] : v.field_0[1];
    max = max > v.field_0[2] ? max : v.field_0[2];
    f32 y = Unk_Dot(v, Unk_LuminanceWeights(Unk_410f90_Object(0)));
    value = (luminance ? y : max) * value;
    if (gamma) {
        value = powf(value, field_8c4.field_0 <= 0.0f ? 1.0f : 1.0f / (field_8c4.field_0 / 2.2f));
    }
    return value;
}

// the colour space field_b80 or the default one gives (0 or the one of
// field_978, for HDR output)
static inline u32 Unk_DefaultSpace(const CPostEffect* self) {
    if (self->field_96c || Unk_24e09bc != 0) {
        return Unk_410400(self->field_96c ? self->field_978 : 13);
    }
    return 0;
}

// 0x71004299a0: field_b84 and field_ba4 from the colour spaces field_b7c and
// field_b80 name, or, without one, the static colour space 0x19 replaced
s32 CPostEffect::Unk_4299a0() {
    if (field_b7c != -1) {
        field_b84 = Unk_410f90_Object(field_b7c == 0x19 ? 0 : field_b7c);
    } else if (Unk_SameColorSpace(field_b84, Unk_Static_Object1)) {
        field_b84 = Unk_410f90_Object(0);
    }
    if (field_b80 != -1) {
        u32 space = field_b80;
        if (space == 0x19) {
            space = Unk_DefaultSpace(this);
        }
        field_ba4 = Unk_410f90_Object(space);
    } else if (Unk_SameColorSpace(field_ba4, Unk_Static_Object1)) {
        field_ba4 = Unk_410f90_Object(Unk_DefaultSpace(this));
    }
    return 0;
}

// 0x71004385e0: whether a format is a fixed-point one (inline, see above)
// The 32-bit floats' and the sRGB formats' switches become one table (case 0
// on its own: Unk_LinearFormat's `case 0`), the 16-bit test a bit test after
// it; the 32-bit flag is a local of its helper (with `return true` in the
// cases the switch becomes a bit mask before it can be merged).
inline bool Unk_4385e0(s32 format) {
    s32 linear = Unk_LinearFormat(format);
    bool f32 = Unk_IsFloat32Format(format);
    bool f16 = Unk_IsFloat16Format(linear);
    if (f32) {
        return false;
    }
    return !(f16 || linear == 26);
}

// a colour's luminance in colour space 0 (inline: its test stays a branch, so
// field_848's comparison is kept as a flag across the calls)
static inline f32 Unk_Space0Luminance(const Unk_4278c0_Data& color) {
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    return Unk_Luminance(space, reinterpret_cast<const Unk_Vector3&>(color.field_0));
}

// 0x7100434570: whether field_848 and the colour of field_f84 are positive
bool CPostEffect::Unk_434570() {
    bool result = field_848 > 0.0f;
    if (field_f80 == -1 && Unk_Space0Luminance(field_f84) <= 0.0f) {
        result = false;
    }
    return result & (field_f80 != 0);
}

}  // namespace PPFX

// the formats 0x7100428030 takes at once (inline)
static inline bool Unk_428030_A(s32 format) {
    switch (format) {
    case 4:
    case 8:
    case 13:
    case 14:
    case 18:
    case 31:
    case 37:
    case 38:
    case 43:
    case 51:
    case 52:
    case 58:
    case 59:
    case 63:
    case 64:
    case 81:
    case 84:
        return true;
    default:
        return false;
    }
}

// 0x7100428030: whether a format is one of a kind (placeholder)
// NON_MATCHING: the jump table is the original's (Unk_428030_A's cases, the
// 32-bit floats' flag set in it, case 0 straight to the return of false: the
// zero test first), but the 16-bit test comes out as a bitmap lookup whose
// true case returns true at once (`format != 26` folded); the original keeps
// a switch bit test (`lsl; tst`) and its `format != 26` compare, and combines
// the 32-bit flag with `bic`. Tried: the 16-bit test nested around the last
// two tests (one shared return), its helper with a result local, the tests
// in other orders and spellings, the linear format (its sRGB cases would get
// their own table entries, which the original's table doesn't have).
bool Unk_428030(s32 format) {
    if (format == 0) {
        return false;
    }
    if (Unk_428030_A(format)) {
        return true;
    }
    bool f32 = PPFX::Unk_IsFloat32Format(format);
    bool f16 = PPFX::Unk_IsFloat16Format(format);
    if (!(f16 || ((format == 26) | f32))) {
        return false;
    }
    if (Unk_425410_Format(format)) {
        return false;
    }
    return format != 26;
}

namespace PPFX {

// 0x7100425dd0
s32 CPostEffect::InitializeAutoExposure(s32 view, f32 luminance, f32 adjusted) {
#line 18381
    PPFX_FN("Frame: %d, View: %d, InitializeAutoExposure(iEffectViewIndex: %d, fSceneLuminance: %f, fCurrentAutoExposureAdjusted: %f);\n",
            Unk_Frame(field_298), field_298, view, luminance, adjusted);
    if (view == -1) {
        view = field_298;
    }
    BeginCommandList_SiGfx();
    for (s32 i = 0; i < field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            Unk_429da0_Item* item = &field_2a0[i];
            if (item->field_70 != nullptr) {
                f32 range = item->field_38 > adjusted ? item->field_40 : item->field_4c;
                f32 target = logf(adjusted) / 0.6931472f;
                f32 current = logf(item->field_38) / 0.6931472f;
                f32 exposure = exp2f(current + (target - current) / fmaxf(range, 0.001f));
                CTextureLuminanceManage* manage = static_cast<CTextureLuminanceManage*>(item->field_70);
                CTextureLuminanceManage::Unk_Value v;
                v.field_0[2] = luminance;
                v.field_0[3] = luminance;
                v.field_0[0] = luminance;
                v.field_0[1] = luminance;
                manage->Unk_4b9140(&v, true, luminance, exposure, 1.0f, field_6c4, field_6c8);
            }
            item->field_5c = luminance;
            item->field_60 = adjusted;
            item->field_54 = 0;
            item->field_58 = 0;
            item->field_64 = false;
            item->field_68 = 5;
        }
    }
    return EndCommandList_SiGfx();
}

// 0x7100426070: the exposure history reset to `value` (when not positive, the
// mean of field_6c4 and field_6c8's arithmetic and harmonic means)
s32 CPostEffect::Unk_426070(s32 view, f32 value) {
    if (value <= 0.0f) {
        f32 inv = (1.0f / field_6c4 + 1.0f / field_6c8) * 0.5f;
        f32 mean = (field_6c4 + field_6c8) * 0.5f;
        value = (mean + 1.0f / inv) * 0.5f;
    }
    if (view == -1) {
        view = field_298;
    }
    BeginCommandList_SiGfx();
    for (s32 i = 0; i < field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            Unk_429e60_Item* item = &field_2a8[i];
            CTextureLuminanceManage* luminance = static_cast<CTextureLuminanceManage*>(item->field_48);
            if (luminance != nullptr) {
                // the original stores the second half first
                CTextureLuminanceManage::Unk_Value v;
                v.field_0[2] = value;
                v.field_0[3] = value;
                v.field_0[0] = value;
                v.field_0[1] = value;
                luminance->Unk_4b9140(&v, true, value, field_8c0.field_0, 1.0f, field_6c4, field_6c8);
            }
            item->field_34 = value;
            item->field_38 = value;
            item->field_2c = 0;
            item->field_30 = 0;
            item->field_3c = false;
            item->field_40 = 5;
        }
    }
    return EndCommandList_SiGfx();
}

// 0x7100426210: CPostEffect::EndCommandList_SiGfx (its log line names it; the
// lazy draw commands' lines name CPostEffect::ExecuteLazyDrawCommand)
// Each branch has its own `list` (the -1 return leaves its scope: the
// original's own block for `mov w0, #-1`, and one return block, so the frame
// isn't shrink-wrapped).
s32 CPostEffect::EndCommandList_SiGfx() {
    if (--field_11cc != 0) {
        return 0;
    }
    IGPUDevice* device = field_18;
    Unk_SiGfxDrawContext* context = device->field_30;
    Unk_SiGfxDevice* sigfx = device->field_38;
    Unk_CommandListMaker* maker = field_11a0;
    if (maker != nullptr) {
        context->vf10();
        Unk_43fc30(field_18);
        if (field_11b8) {
            for (auto it = device->field_40.begin(); it != device->field_40.end(); ++it) {
                if (it->Execute(context) < 0) {
#line 42082
                    PPFX_ERROR("CPostEffect::ExecuteLazyDrawCommand(): Failed GPUSiGfxLazyDrawCommand::Execute().\n");
                }
            }
        }
        context->vf9();
        if (field_11b8) {
            field_11b8 = false;
            Unk_SiGfxQueue* queue = sigfx->vf19();
            queue->vf10(1, &field_11b0);
            queue->vf13(queue->vf12());
            for (auto it = device->field_40.begin(); it != device->field_40.end();) {
                Unk_43dc00_get(reinterpret_cast<Unk_43dc00*>(&*it));
                it = device->field_40.erase(it);
            }
        }
    }
    if (!device->field_40.empty()) {
        if (maker != nullptr) {
            if (field_11c0 == nullptr) {
                field_11c0 = sigfx->vf22(1, 0, nullptr);
            }
            void* list = field_11c0;
            if (!context->vf8(list)) {
#line 42123
                PPFX_ERROR("CPostEffect::EndCommandList_SiGfx(): Failed pSiGfxDrawContext->BeginCommandList(pTempCommandList).\n");
                return -1;
            }
            for (auto it = device->field_40.begin(); it != device->field_40.end(); ++it) {
                if (it->Execute(context) < 0) {
#line 42133
                    PPFX_ERROR("CPostEffect::ExecuteLazyDrawCommand(): Failed GPUSiGfxLazyDrawCommand::Execute().\n");
                }
            }
            context->vf9();
            Unk_SiGfxQueue* queue = sigfx->vf19();
            queue->vf10(1, &list);
            queue->vf13(queue->vf12());
            for (auto it = device->field_40.begin(); it != device->field_40.end();) {
                Unk_43dc00_get(reinterpret_cast<Unk_43dc00*>(&*it));
                it = device->field_40.erase(it);
            }
        } else {
            for (auto it = device->field_40.begin(); it != device->field_40.end(); ++it) {
                if (it->Execute(context) < 0) {
#line 42164
                    PPFX_ERROR("CPostEffect::ExecuteLazyDrawCommand(): Failed GPUSiGfxLazyDrawCommand::Execute().\n");
                }
            }
            void* list = context->vf10();
            context->vf9();
            Unk_SiGfxQueue* queue = sigfx->vf19();
            queue->vf10(1, &list);
            queue->vf13(queue->vf12());
            for (auto it = device->field_40.begin(); it != device->field_40.end();) {
                Unk_43dc00_get(reinterpret_cast<Unk_43dc00*>(&*it));
                it = device->field_40.erase(it);
            }
            context->vf8(list);
        }
    }
    field_11b0 = nullptr;
    if (field_11c0 != nullptr) {
        reinterpret_cast<Unk_CommandList*>(field_11c0)->vf3();
        field_11c0 = nullptr;
    }
    return 0;
}

// 0x710043cd40: the Planckian locus in CIE 1960 u and v at a reciprocal
// colour temperature (in mireds: 0 to 640, every 10 tabulated). Its statics
// are reached through the GOT: an inline function's.
// The division is computed before the clamp's test (CodeGenPrepare makes the
// select of it a branch only after Reassociate has ranked the fraction above
// the table's loads; written inside the ternary, the fraction is a phi ranked
// below them and the second product's operands are swapped).
inline Unk_Float2 Unk_43cd40(const f32* mired) {
    static const Unk_Float2 table[65] = {
        Unk_Float2(0.180046f, 0.263577f),
        Unk_Float2(0.180638f, 0.265948f),
        Unk_Float2(0.181309f, 0.268506f),
        Unk_Float2(0.182067f, 0.271236f),
        Unk_Float2(0.182919f, 0.274118f),
        Unk_Float2(0.183872f, 0.277131f),
        Unk_Float2(0.184932f, 0.280251f),
        Unk_Float2(0.186103f, 0.283452f),
        Unk_Float2(0.187389f, 0.286709f),
        Unk_Float2(0.188792f, 0.289997f),
        Unk_Float2(0.190312f, 0.293293f),
        Unk_Float2(0.191949f, 0.296575f),
        Unk_Float2(0.193701f, 0.299825f),
        Unk_Float2(0.195566f, 0.303025f),
        Unk_Float2(0.19754f, 0.306162f),
        Unk_Float2(0.199619f, 0.309223f),
        Unk_Float2(0.201799f, 0.312199f),
        Unk_Float2(0.204074f, 0.315083f),
        Unk_Float2(0.20644f, 0.317868f),
        Unk_Float2(0.208891f, 0.32055f),
        Unk_Float2(0.211423f, 0.323126f),
        Unk_Float2(0.21403f, 0.325595f),
        Unk_Float2(0.216706f, 0.327956f),
        Unk_Float2(0.219449f, 0.330208f),
        Unk_Float2(0.222251f, 0.332354f),
        Unk_Float2(0.22511f, 0.334393f),
        Unk_Float2(0.22802f, 0.336329f),
        Unk_Float2(0.230978f, 0.338163f),
        Unk_Float2(0.233979f, 0.339897f),
        Unk_Float2(0.23702f, 0.341536f),
        Unk_Float2(0.240097f, 0.34308f),
        Unk_Float2(0.243206f, 0.344534f),
        Unk_Float2(0.246345f, 0.345901f),
        Unk_Float2(0.249511f, 0.347183f),
        Unk_Float2(0.252699f, 0.348384f),
        Unk_Float2(0.255909f, 0.349508f),
        Unk_Float2(0.259136f, 0.350557f),
        Unk_Float2(0.262379f, 0.351534f),
        Unk_Float2(0.265635f, 0.352443f),
        Unk_Float2(0.268902f, 0.353287f),
        Unk_Float2(0.272179f, 0.354069f),
        Unk_Float2(0.275462f, 0.354791f),
        Unk_Float2(0.27875f, 0.355457f),
        Unk_Float2(0.282042f, 0.35607f),
        Unk_Float2(0.285335f, 0.356631f),
        Unk_Float2(0.288629f, 0.357144f),
        Unk_Float2(0.291922f, 0.357611f),
        Unk_Float2(0.295211f, 0.358034f),
        Unk_Float2(0.298497f, 0.358417f),
        Unk_Float2(0.301778f, 0.35876f),
        Unk_Float2(0.305053f, 0.359066f),
        Unk_Float2(0.30832f, 0.359338f),
        Unk_Float2(0.311579f, 0.359577f),
        Unk_Float2(0.314829f, 0.359785f),
        Unk_Float2(0.318068f, 0.359964f),
        Unk_Float2(0.321297f, 0.360115f),
        Unk_Float2(0.324514f, 0.36024f),
        Unk_Float2(0.327718f, 0.360342f),
        Unk_Float2(0.330909f, 0.36042f),
        Unk_Float2(0.334087f, 0.360477f),
        Unk_Float2(0.33725f, 0.360513f),
        Unk_Float2(0.340397f, 0.360531f),
        Unk_Float2(0.34353f, 0.360531f),
        Unk_Float2(0.346646f, 0.360515f),
        Unk_Float2(0.349746f, 0.360483f)
    };
    f32 scaled = (*mired > 640.0f ? 640.0f : *mired) / 10.0f;
    f32 t = *mired < 0.0f ? 0.0f : scaled;
    s32 i = static_cast<s32>(floorf(t));
    s32 next = i + 1 < 64 ? i + 1 : 64;
    f32 f = t - static_cast<f32>(i);
    Unk_Float2 hi = table[next];
    Unk_Float2 lo = table[i];
    Unk_Float2 d(hi.field_0[0].field_0 - lo.field_0[0].field_0, hi.field_0[1].field_0 - lo.field_0[1].field_0);
    Unk_Float2 s(d.field_0[0].field_0 * f, d.field_0[1].field_0 * f);
    return Unk_Float2(lo.field_0[0].field_0 + s.field_0[0].field_0, lo.field_0[1].field_0 + s.field_0[1].field_0);
}

// 0x710043cae0: a colour (its negative parts cut) scaled to a luminance:
// positive, the luminance in the colour space; negative, its largest
// component (set to it). An inline function: its static is reached through
// the GOT.
inline Unk_Float3 Unk_43cae0(const Unk_Vector3& color, const f32* luminance, const Unk_410f90* space) {
    Unk_Float3 c(fmaxf(color.field_0[0], 0.0f), fmaxf(color.field_0[1], 0.0f), fmaxf(color.field_0[2], 0.0f));
    if (*luminance > 0.0f) {
        Unk_Vector3 v = {{c.field_0[0].field_0, c.field_0[1].field_0, c.field_0[2].field_0}};
        f32 y = Unk_Dot(v, Unk_LuminanceWeights(*space));
        if (y != 0.0f) {
            f32 scale = *luminance / y;
            c.field_0[0].field_0 = v.field_0[0] * scale;
            c.field_0[1].field_0 = v.field_0[1] * scale;
            c.field_0[2].field_0 = v.field_0[2] * scale;
        }
    } else if (*luminance < 0.0f) {
        static const Unk_Float lowest(-3.40282347e+38f);
        f32 max = lowest.field_0;
        s32 index = -1;
        for (s32 i = 0; i < 3; i++) {
            if (c.v(i).field_0 > max) {
                max = c.v(i).field_0;
                index = i;
            }
        }
        if (max != 0.0f) {
            f32 scale = -(*luminance / max);
            c.field_0[0].field_0 *= scale;
            c.field_0[1].field_0 *= scale;
            c.field_0[2].field_0 *= scale;
            c.v(index).field_0 = -*luminance;
        }
    }
    return c;
}

// XYZ from x, y and the luminance: Y itself, or (negative) Y over y
// (inline)
static inline Unk_Vector3 Unk_XYZ(f32 x, f32 y, const f32* luminance) {
    f32 z = 1.0f - x;
    f32 Y = *luminance;
    if (Y < 0.0f) {
        Y = -(Y * y);
    }
    f32 scale = Y / y;
    Unk_Vector3 result = {{x * scale, Y, (z - y) * scale}};
    return result;
}

// the XYZ of white light of a colour temperature (K) and a luminance: on the
// Planckian locus, or the CIE daylight locus between 2000 and 25000 K
// (inline)
static inline Unk_Vector3 Unk_WhiteXYZ(f32 temperature, bool planck, const f32* luminance) {
    if (planck) {
        f32 mired = temperature < 1562.5f ? 640.0f
                                          : 1000000.0f / (temperature > 3.40282347e+38f ? 3.40282347e+38f : temperature);
        Unk_Float2 uv = Unk_43cd40(&mired);
        f32 u = uv.field_0[0].field_0;
        f32 v = uv.field_0[1].field_0;
        f32 d = 2.0f * u - 8.0f * v + 4.0f;
        return Unk_XYZ(3.0f * u / d, 2.0f * v / d, luminance);
    }
    if (temperature < 2000.0f) {
        temperature = 2000.0f;
    } else if (temperature > 25000.0f) {
        temperature = 25000.0f;
    }
    f64 t = temperature;
    f64 x;
    if (temperature < 4000.0f) {
        f64 l = log(t);
        x = -0.012 * (l * l) + 1.208;
    } else if (temperature <= 7000.0f) {
        x = -4.6070 * 1e9 / (t * t * t) + 2.9678 * 1e6 / (t * t) + 0.09911 * 1e3 / t + 0.244063;
    } else {
        x = -2.0064 * 1e9 / (t * t * t) + 1.9018 * 1e6 / (t * t) + 0.24748 * 1e3 / t + 0.237040;
    }
    f64 y = -3.0 * (x * x) + 2.87 * x - 0.275;
    return Unk_XYZ(static_cast<f32>(x), static_cast<f32>(y), luminance);
}

// the RGB of white light of a colour temperature (inline)
static inline Unk_Vector3 Unk_WhiteRGB(f32 temperature, bool planck, const f32* luminance, const MATRIXT44* toRgb) {
    Unk_Vector3 xyz = Unk_WhiteXYZ(temperature, planck, luminance);
    Unk_Vector3 rgb;
    Unk_410070(&rgb, &xyz, toRgb);
    return rgb;
}

// NON_MATCHING (0x710043c690 below): the same size, layout and calls; only
// Unk_XYZ's scheduling in its three copies differs (the original computes
// 1 - x before the luminance's select and subtracts y after the division).
// `1 - x` in a local before Y (kept: 25 differing instructions against 27)
// gives the first two copies the original's order but for registers (the
// first copy's 1.0 is materialised later); the third converts y before 1 - x.
// Tried: z first, the scale inline, `scale * x`, an if for the select, the
// select as a ternary, x or y converted to float in other places,
// non-static `inline`, `const f32&` parameters, `1 - x - y` in a local first
// or by `-=`, the result by elements.
// 0x710043c690: the RGB colour, in a colour space, of white light of a
// colour temperature (relative to 6500 K's) at a luminance (see Unk_43cae0),
// optionally inverted, and an alpha (an out-of-line function: unlike
// Unk_43cd40 and Unk_43cae0 nothing shows it inline; its callers are
// 0x710043a970, 0x710043ad10 and 0x710043af30)
Unk_Float4 Unk_43c690(const f32* temperature, const Unk_410f90* space, const f32* tint, const f32* luminance,
                      const f32* alpha, bool invert, bool planck) {
    if (*temperature == 6500.0f) {
        f32 l = *luminance;
        f32 value = l == 0.0f ? 1.0f : (l > 0.0f ? l : -l);
        return Unk_Float4(value, value, value, *alpha);
    }
    MATRIXT44 toRgb;
    Unk_XyzToRgb(&toRgb, space);
    Unk_Vector3 white = Unk_WhiteRGB(6500.0f, planck, tint, &toRgb);
    f32 r = 1.0f / white.field_0[0];
    f32 g = 1.0f / white.field_0[1];
    f32 b = 1.0f / white.field_0[2];
    Unk_Vector3 rgb = Unk_WhiteRGB(*temperature, planck, tint, &toRgb);
    rgb.field_0[0] *= r;
    rgb.field_0[1] *= g;
    rgb.field_0[2] *= b;
    if (invert) {
        rgb.field_0[0] = 1.0f / rgb.field_0[0];
        rgb.field_0[1] = 1.0f / rgb.field_0[1];
        rgb.field_0[2] = 1.0f / rgb.field_0[2];
    }
    if (*luminance >= 0.0f) {
        rgb.field_0[0] *= *luminance;
        rgb.field_0[1] *= *luminance;
        rgb.field_0[2] *= *luminance;
    } else {
        Unk_Float3 c = Unk_43cae0(rgb, luminance, space);
        rgb.field_0[0] = c.field_0[0].field_0;
        rgb.field_0[1] = c.field_0[1].field_0;
        rgb.field_0[2] = c.field_0[2].field_0;
    }
    return Unk_Float4(rgb.field_0[0], rgb.field_0[1], rgb.field_0[2], *alpha);
}

// a view's frustum at unit distance: its bottom, left, right and top
struct Unk_Frustum {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};

// the square root, without the call for 0 and 1 (inline)
static inline f32 Unk_Sqrt(f32 x) {
    if (x == 0.0f || x == 1.0f) {
        return x;
    }
    return sqrtf(x);
}

// 0x710042a590: what changed since the last frame's view: whether the eye
// moved further than field_d08, whether it moved, whether the projection and
// the rotation changed, and whether anything did
// NON_MATCHING: 16 instructions, the entry block's schedule (the frustums'
// arithmetic and the order of the three fccmps) and the registers after it.
// What gave the original's shape: the bottoms, lefts and rights compared with
// `|` (one fccmp chain), `||` the tops' comparison `|` the two NaN tests (a
// block of its own, where the tops are computed); the second frustum computed
// after the first one is stored; the rotation as `||`s of `!=` (the last
// test's block at the end); `any` computed before the stores.
s32 CPostEffect::Unk_42a590(bool* far, bool* moved, bool* projection, bool* rotation, bool* any) {
    f32 scale = field_6c4;
    f32 w = scale * (field_6d0 * field_420);
    f32 xw = field_6d4 * w;
    f32 h = scale * field_6d0;
    f32 yh = h * field_6d8;
    Unk_Frustum current;
    current.field_8 = w + xw;
    current.field_4 = xw - w;
    current.field_0 = yh - h;
    current.field_c = h + yh;
    f32 w2 = scale * (field_420 * field_6e8);
    f32 xw2 = field_6ec * w2;
    f32 h2 = scale * field_6e8;
    f32 yh2 = h2 * field_6f0;
    Unk_Frustum previous = {yh2 - h2, xw2 - w2, w2 + xw2, h2 + yh2};
    bool projectionChanged = ((current.field_0 != previous.field_0) | (current.field_4 != previous.field_4) |
                              (current.field_8 != previous.field_8)) ||
                             ((current.field_c != previous.field_c) | (field_6c4 != field_6c4) |
                              (field_6c8 != field_6c8));
    f32 dx = field_6f4.field_0[3][0] - field_774.field_0[3][0];
    f32 dy = field_6f4.field_0[3][1] - field_774.field_0[3][1];
    f32 dz = field_6f4.field_0[3][2] - field_774.field_0[3][2];
    f32 distance = Unk_Sqrt(dx * dx + dy * dy + dz * dz);
    bool isFar = distance > field_d08;
    bool hasMoved = distance > 0.0f;
    bool rotationChanged = field_6f4.field_0[0][0] != field_774.field_0[0][0] ||
                           field_6f4.field_0[0][1] != field_774.field_0[0][1] ||
                           field_6f4.field_0[0][2] != field_774.field_0[0][2] ||
                           field_6f4.field_0[1][0] != field_774.field_0[1][0] ||
                           field_6f4.field_0[1][1] != field_774.field_0[1][1] ||
                           field_6f4.field_0[1][2] != field_774.field_0[1][2] ||
                           field_6f4.field_0[2][0] != field_774.field_0[2][0] ||
                           field_6f4.field_0[2][1] != field_774.field_0[2][1] ||
                           field_6f4.field_0[2][2] != field_774.field_0[2][2];
    bool anyChanged = (distance > 0.0f) || projectionChanged || rotationChanged;
    if (far != nullptr) {
        *far = isFar;
    }
    if (moved != nullptr) {
        *moved = hasMoved;
    }
    if (projection != nullptr) {
        *projection = projectionChanged;
    }
    if (rotation != nullptr) {
        *rotation = rotationChanged;
    }
    if (any != nullptr) {
        *any = anyChanged;
    }
    return 0;
}

// CPostEffect::GetMaxMotionBlurCameraRecurrences (its log line names it): how
// many camera recurrences the motion blur can have (0, 2 or any number; one
// view less without an internal velocity texture where the velocity is made)
// (inline: UpdateParameters_Base, 0x7100433450)
inline u32 CPostEffect::GetMaxMotionBlurCameraRecurrences() {
    bool internal = false;
    if (field_ce8 == 2 && field_d38 == nullptr) {
        if (!field_1bd) {
#line 14639
            PPFX_ERROR("CPostEffect::GetMaxMotionBlurCameraRecurrences():\n\tFor using PFXMB_VELOCITYBASE at SetMotionBlurMode() and\n\tPFXVS_AUTOGEN or PFXVS_AUTOGEN_APPOVERWRITE at SetMotionBlurVelocitySource(),\n\tPFXINIT_MOTIONBLUR_INTERNALVELOCITYTEXTURE must be set at Initialize().\n");
        }
        internal = field_1d8 == nullptr;
    }
    s32 views = field_444 - internal;
    if (views < 1) {
        return 0;
    }
    if (views == 1) {
        return 2;
    }
    return 0xffffffff;
}

// a perspective projection from a field of view's tangent, an aspect ratio and
// a lens shift (inline)
static inline void Unk_Perspective(MATRIXT44* out, f32 n, f32 f, f32 tangent, f32 aspect, f32 shiftX, f32 shiftY) {
    f32 w = n * (tangent * aspect);
    f32 h = n * tangent;
    f32 xw = shiftX * w;
    f32 yh = h * shiftY;
    f32 right = w + xw;
    f32 bottom = yh - h;
    f32 top = h + yh;
    f32 left = xw - w;
    Unk_40f8d0(out, false, true, left, right, bottom, top, n, f);
}

// 0x710042a7e0: CPostEffect::UpdateParameters_Base (its log line names it):
// which effects run this frame, from the parameters set (Unk_411190 is
// declared here as GPUTextureUtil.cpp does)
// NON_MATCHING: a draft (4100 of 4276 bytes): the tests, calls and their
// arguments are the original's. The original computes !field_8b6 before the
// float tests it ends (field_1074, field_c2d) and tests field_eb8 twice for
// field_10de; the block layout, registers and stack slots differ.
s32 CPostEffect::UpdateParameters_Base() {
    void Unk_411190(MATRIXT44* out, const Unk_410f90* from, const Unk_410f90* to, bool arg3);
    field_106d = field_c98;
    bool bright = false;
    if (field_c70 && !field_8b6 && field_1050 && (field_c79 || field_104f)) {
        s32 index = field_5e0;
        Unk_4a5d10_Self* textures = field_190;
        if (index == -1) {
            index = textures->field_90;
        }
        f32 value = field_1070 * static_cast<f32>(textures->field_38[index]->field_58);
        if (field_c78) {
            value = value * 7e-07f / 5.8756e-07f;
        }
        bright = !(value <= 0.7259524f);
    }
    field_106e = bright;
    field_10de = !(field_ec0 <= 0.0f || field_ecc <= 0.0f || field_ed0 <= 0.0f) && field_eb8 && !field_8b6;
    bool scatter = (field_f14 < 1.0f || field_f18 != 1.0f) && field_f08;
    field_10df = scatter && !field_8b6;
    field_10e0 = field_10df && scatter && field_f0c == 2;
    field_1074 = field_c7a && (field_c7c.field_0 != 0.0f || field_c7c.field_4 != 0.0f || field_c7c.field_8 != 0.0f) &&
                 !field_8b6;
    bool shafts = false;
    if (field_c2c) {
        field_c2d = (field_c38.field_0[0].field_0 != 0.0f || field_c38.field_0[1].field_0 != 0.0f ||
                     field_c40.field_0[0].field_0 != 0.0f || field_c40.field_0[1].field_0 != 0.0f) &&
                    !field_8b6;
        field_c35 = field_c34;
        shafts = field_c2d && field_c36;
    } else {
        field_c2d = false;
        field_c35 = false;
    }
    reinterpret_cast<CRenderGlare*>(field_198)->Unk_45e8a0(
        shafts, field_c30, false, reinterpret_cast<const u64*>(&field_c38), reinterpret_cast<const u64*>(&field_c40),
        reinterpret_cast<const u64*>(&field_c48), reinterpret_cast<const u64*>(&field_c50),
        reinterpret_cast<const u64*>(&field_c58), field_c6c, field_c60, field_c64, field_c68);
    field_c37 = shafts;
    Unk_4291c0();
    Unk_429460();
    field_f39 = field_f38 && !field_8b6;
    Unk_4297b0();
    field_10d5 = field_be4 && !field_8b6;
    field_10d4 = (field_10d5 || field_bec) && !field_8b6;
    field_10d6 = field_180 && field_178 != nullptr && !field_8b6 && !(Unk_IsHdrOutput() && Unk_IsHdrDirect());
    field_10d7 = (field_58 == 8 || field_50 != nullptr) && field_88 && field_104f && field_80 != nullptr;
    field_1028 = false;
    bool glow =
        field_1029 && field_c8 != 0 && (field_102c[0] != 0.0f || field_102c[1] != 0.0f || field_102c[2] != 0.0f);
    field_1028 = glow;
    Unk_45e930_update(reinterpret_cast<Unk_45e930*>(field_198), glow);
    if (glow) {
        Unk_45e920_update(reinterpret_cast<Unk_45e920*>(field_198), field_c8);
        reinterpret_cast<CRenderGlare*>(field_198)->Unk_45e940(reinterpret_cast<const Unk_GlareRect*>(&field_102c[0]),
                                                               reinterpret_cast<const Unk_GlarePair*>(&field_102c[4]),
                                                               reinterpret_cast<const Unk_GlarePair*>(&field_1044));
    }
    Unk_4299a0();
    Unk_411190(&field_1094, &field_b84, &field_ba4, field_bcc);
    field_1075 = false;
    s32 mode = field_1078;
    field_1078 = -1;
    field_107c = 0;
    field_108c = 0.0f;
    if (field_cf0.field_0 > 0.0f && field_cf4.field_0 > 0.0f && field_ce5 && !field_8b6) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil(util);
        util->Unk_470860(field_cf8);
        util->field_29a68 = field_cec ? 1 : 2;
        MATRIXT44 projection;
        {
            Unk_Perspective(&projection, field_6c4, field_6c8, field_6d0, field_420, field_6d4, field_6d8);
        }
        MATRIXT44 previous;
        {
            Unk_Perspective(&previous, field_6c4, field_6c8, field_6e8, field_420, field_6ec, field_6f0);
        }
        bool far;
        bool moved;
        bool projected;
        bool rotated;
        bool any;
        Unk_42a590(&far, &moved, &projected, &rotated, &any);
        if (mode != 2) {
            far = false;
        }
        f32 scale = field_cf0.field_0;
        f32 limit = field_cf4.field_0;
        u32 levels = field_cfc;
        u32 recurrences = GetMaxMotionBlurCameraRecurrences();
        if (levels > recurrences) {
            levels = recurrences;
        }
        f32 ratio = field_d00.field_0;
        CRenderTexture* source = reinterpret_cast<CRenderTexture*>(Unk_TextureAt(field_5e0));
        s32 count = 0;
        s32 used = 0;
        s32 first = 0;
        field_1084.field_0[0] = 0.0f;
        field_1084.field_0[1] = 0.0f;
        const f32* range = nullptr;
        if (field_ce5 && static_cast<u32>(field_ce8 - 1) < 2 &&
            Unk_4622e0(field_6c4, field_6c8, field_d10, field_d14)) {
            f32 near = field_6c4;
            f32 farPlane = field_6c8;
            f32 c = field_105c;
            f32 offset = 0.0f * c + field_1060;
            f32 f = field_1064;
            f32 k = (farPlane - near) * f / (near * farPlane);
            f32 inverse = 1.0f / k;
            f32 s = c * inverse;
            offset = offset * inverse - (1.0f - f / near) / k;
            f32 a = farPlane * (field_d14 - near) / (farPlane - near) / field_d14;
            f32 b = farPlane * (field_d10 - near) / (farPlane - near) / field_d10;
            f32 span = 1.0f / (b - a);
            field_1084.field_0[1] = offset * span + (0.0f - a * span);
            field_1084.field_0[0] = s * span;
            range = &field_1084.field_0[0].field_0;
        }
        Unk_Float2 unit(1.0f, 1.0f);
        f32 length;
        f32 motion;
        f32 lengthRatio;
        Unk_484f50_View view;
        Unk_484f50_View lerped;
        f32 amount;
        f32 blur = 0.0f;
        bool always = true;
        switch (mode) {
            case 0: {
                if (!rotated) {
                    goto done;
                }
                Unk_Float2 offset;
                Unk_Float2 direction;
                util->Unk_482d70(scale, limit, source, &field_6f4, &field_774, &projection, levels, ratio, &unit, 0,
                                 &count, &used, &first, &offset, &direction);
                offset.field_0[0].field_0 = field_420 * offset.field_0[0].field_0;
                if (used > 0) {
                    f32 x = offset.field_0[0].field_0;
                    f32 y = offset.field_0[1].field_0;
                    f32 squared = x * x + y * y;
                    amount = squared == 0.0f || squared == 1.0f ? squared : sqrtf(squared);
                } else {
                    amount = 0.0f;
                }
                break;
            }
            case 1:
                if (!rotated && !projected) {
                    goto done;
                }
                util->Unk_482fd0(scale, limit, ratio, source, &field_6f4, &field_774, &projection, &previous, range,
                                 levels, &unit, 0, &count, &used, &first, &length, &lengthRatio, &view, &lerped);
                amount = used > 0 ? length : 0.0f;
                break;
            case 2: {
                if (!any && field_d2c == 0) {
                    goto done;
                }
                bool flag = field_d2c >= 2 ? field_d40 : false;
                CRenderTexture* target = source;
                if (field_1e8 != nullptr) {
                    target = reinterpret_cast<CRenderTextureArray*>(field_1e8)->Unk_Texture(0);
                }
                util->Unk_483e50(scale, limit, ratio, target, &field_6f4, &field_774, &projection, &previous, flag,
                                 levels, &unit, 0, &count, &used, &first, &length, &motion, &lengthRatio, &view,
                                 &lerped);
                amount = used > 0 ? motion : 0.0f;
                if (used > 0) {
                    blur = length / static_cast<f32>(reinterpret_cast<Unk_RenderTexture*>(target)->field_58);
                }
                always = field_d0c || field_d2c == 0;
                break;
            }
            default:
                amount = 0.0f;
                break;
        }
        if (used != 0) {
            if (always) {
                amount = amount / static_cast<f32>(reinterpret_cast<Unk_RenderTexture*>(source)->field_58);
                if (!(amount > field_d04) && !far) {
                    goto done;
                }
            }
            field_1075 = true;
            field_1078 = mode;
            field_107c = used;
            field_108c = blur;
        }
    done:
        field_1080 = false;
        field_1081 = false;
        if (field_1075) {
            if (field_1078 >= 2) {
                field_1081 = true;
                field_1080 = true;
            }
            if (field_ce5 && static_cast<u32>(field_ce8 - 1) < 2 &&
                Unk_4622e0(field_6c4, field_6c8, field_d10, field_d14)) {
                field_1080 = true;
            }
        }
    } else {
        field_1080 = false;
        field_1081 = false;
    }
    if (field_10df && static_cast<u32>(field_f0c - 1) < 2) {
        field_108c = field_108c > field_f1c ? field_108c : field_f1c;
    }
    if (field_59d && (field_8c8 & 0xffff0000) == 0x70000) {
        field_104f = false;
    }
    bool other = field_50 != nullptr || field_548;
    field_10d8 = field_1080 || field_1090 || field_c6d || (field_c6e && field_c6f) ||
                 (field_f38 && Unk_4622e0(field_6c4, field_6c8, field_f3c, field_f40)) || (field_10de && !other) ||
                 (field_10e0 && !other);
    field_10d9 = field_10d8 || field_104f;
    field_10dc = field_10de;
    field_10da = field_1081 || (field_10df && static_cast<u32>(field_f0c - 1) < 2);
    field_10db = false;
    field_d64 = *reinterpret_cast<const Unk_Float2*>(&field_d18);
    field_d6c = -1;
    if (field_d2c == 2) {
        if (field_d38 != nullptr) {
            field_10db = true;
            field_d6c = field_d30;
        }
    } else if (field_d2c == 0 && field_108c > 0.0f) {
        field_d64.field_0[0] = field_108c;
        field_d64.field_0[1] = field_108c;
    }
    field_d78 = nullptr;
    field_d70 = nullptr;
    if (field_10da) {
        if (field_d38 != nullptr) {
            switch (field_d2c) {
                case 1:
                    field_d78 = field_d38;
                    // fall through
                case 0:
                    field_d70 = field_1d8;
                    break;
                default:
                    field_d70 = field_d38;
                    break;
            }
        } else if (field_1d8 != nullptr) {
            field_d70 = field_1d8;
        } else {
            field_d70 = Unk_TextureAt(field_624);
        }
    }
    field_d0 = nullptr;
    field_1051 = field_10d9;
    if (field_1051) {
        if (field_58 != 8) {
            field_1051 = false;
        }
        if (field_50 != nullptr) {
            field_1051 = false;
        }
    }
    if (!field_9 && field_1051 && field_70 != nullptr && field_58 == 8) {
#line 21214
        PPFX_ERROR("CPostEffect::UpdateParameters_Base(): If SetEffectSource() is called, depth texture cannot be used as dpeth factor source.\n");
        return -1;
    }
    field_10dd = false;
    field_1052 = false;
    field_1053 = false;
    if (field_10d9 && !field_1051 && field_50 == nullptr) {
        field_1052 = true;
        field_1053 = true;
    }
    field_1068 = field_104f || field_10de || field_f39 || field_10df || field_c2d || field_c35 || field_10d5 ||
                 field_106e || field_1074 || field_1075 || field_1090;
    field_1069 = field_1051 || field_104c || (field_10de && field_50 == nullptr && field_548) ||
                 (field_10e0 && field_50 == nullptr && field_548);
    return 0;
}

}  // namespace PPFX

// 0x7100455350, 0x71004553a0, 0x710045e900 (lib/yebis/leaf: the glare's,
// placeholder types)
struct Unk_455350_Float2 {
    f32 field_0[2];
};
u32 Unk_455350_set(Unk_455350* self, s32 index, const Unk_455350_Float4* value, f32 a, f32 b, f32 c, f32 d);
u32 Unk_4553a0_set(Unk_455350* self, s32 index, const Unk_455350_Float2* value);
u32 Unk_45e900_set(Unk_455350* self, s32 index, const Unk_455350_Float4* value);

namespace PPFX {

// 0x71004786d0 (GPUTextureUtil.cpp): where a position of the target is read from
Unk_Float2 Unk_4786d0(bool flag, const Unk_Float2* position, s32 mode, f32 angle, f32 aspect, f32 value, f32 arg3,
                      f32 arg4, f32 arg5, f32 arg6, f32 arg7);

// where a light shaft is seen from (inline)
inline Unk_Float2 Unk_ShaftPosition(const CPostEffect* self, const Unk_Float2* source) {
    if (!self->field_10d5) {
        return *source;
    }
    f32 distance = self->field_6cc;
    f32 shift;
    switch (self->field_c14) {
    case 0:
        distance = self->field_c18;
        shift = 0.0f;
        break;
    case 2:
        shift = self->field_c1c;
        break;
    default:
        shift = 0.0f;
        break;
    }
    return Unk_4786d0(false, source, self->field_c04, distance, self->field_420, self->field_be8, shift,
                      self->field_c20, self->field_c24, self->field_c28, self->field_c08);
}

// 0x71004291c0: the light shafts handed to the glare (whether there are any)
// NON_MATCHING: the loop's induction variable is based at field_64 (the
// original's at the item: with a `u32` index LSR picks the item, but the loop
// is then counted up), and case 0 and the default of the shaft position's
// switch each get the `shift = 0` copy (the original: one block that case 0
// falls into). `at` is declared where it is set and `color` isn't in a scope
// of its own: that gives the original's stack slots. Tried: the item by
// reference or pointer (or Unk_LightShaft), `s64` indices, the shaft
// position's switch with `shift` set before it, the tests' spellings; a `u32`
// index (the item-based IV, counted up) with the factors read offset first
// is the closest (18 differing instructions against 33), but the original
// tests a signed count (so does `i != count`, also 18). Kept: `offset`
// assigned before `scale` from the factors (their registers, as in
// 0x7100429460). 0x7100429460's fix for the same IV (the skip test as
// `!on || x`) doesn't apply: the loop's skips have no stores and the item
// isn't held in a reference across the calls.
bool CPostEffect::Unk_4291c0() {
    Unk_45eb90_Self* glare = field_198;
    field_c6d = false;
    if (glare->field_10c >= 0) {
        glare->field_1f4 = 0;
    }
    if (field_8b6) {
        return false;
    }
    s32 count = field_478;
    s32 drawn = 0;
    for (s32 i = 0; i < count; i++) {
        if (!field_858[i].field_60 || field_848 <= 0.0f) {
            continue;
        }
        if (field_858[i].field_0.field_0 <= 0.0f && field_858[i].field_0.field_4 <= 0.0f &&
            field_858[i].field_0.field_8 <= 0.0f) {
            continue;
        }
        f32 offset;
        f32 scale;
        f32 depth;
        if (field_858[i].field_64 == 7) {
            Unk_Refresh();
            f32 near = field_1064;
            Unk_Refresh();
            depth = (field_858[i].field_5c - near) / field_858[i].field_5c;
            scale = field_1054;
            offset = field_1058;
        } else {
            f32 factors[4];
            Unk_428cc0(factors, field_858[i].field_64, 2, 1.0f, 0.0f);
            offset = factors[1];
            scale = factors[0];
            depth = field_858[i].field_5c;
        }
        f32 position = offset + scale * depth;
        Unk_Rect color = field_858[i].field_0;
        if (field_59c) {
            color.field_0 = field_8d0 * color.field_0;
            color.field_4 = field_8d0 * color.field_4;
            color.field_8 = field_8d0 * color.field_8;
        }
        reinterpret_cast<CRenderGlare*>(field_198)->Unk_4552e0(
            drawn, reinterpret_cast<const Unk_GlareRect*>(&color), field_858[i].field_1c, field_858[i].field_10,
            position, field_858[i].field_20, field_858[i].field_14, field_858[i].field_18);
        Unk_455350_set(reinterpret_cast<Unk_455350*>(field_198), drawn,
                       reinterpret_cast<const Unk_455350_Float4*>(&field_858[i].field_34), field_858[i].field_24,
                       field_858[i].field_30, field_858[i].field_28, field_858[i].field_2c);
        Unk_45e900_set(reinterpret_cast<Unk_455350*>(field_198), drawn,
                       reinterpret_cast<const Unk_455350_Float4*>(&field_858[i].field_4c));
        Unk_Float2 at = Unk_ShaftPosition(this, &field_858[i].field_44);
        Unk_4553a0_set(reinterpret_cast<Unk_455350*>(field_198), drawn, reinterpret_cast<const Unk_455350_Float2*>(&at));
        drawn++;
    }
    if (field_198->field_10c >= drawn) {
        field_198->field_1f4 = drawn;
    }
    field_c6d = drawn > 0;
    return field_c6d;
}

}  // namespace PPFX

// 0x71004534e0, 0x71004534d0 (lib/yebis/leaf/Unk_4534d0.cpp): the glare's
// light ghost kind, and its custom one
struct Unk_4534e0;
struct Unk_4534d0;
u32 Unk_4534e0_update(Unk_4534e0* self, u32 value);
u32 Unk_4534d0_update(Unk_4534d0* self, u32 value, u64 arg2);

namespace PPFX {

// the glare's kind of a light ghost kind (-1: a custom one; a table set up
// the first time)
static inline s32 Unk_LightGhostKind(s32 kind) {
    static bool initialised = false;
    static s32 kinds[20];
    if (!initialised) {
        initialised = true;
        for (s32 i = 0; i < 20; i++) {
            kinds[i] = i;
        }
    }
    if (kind == -1) {
        return -1;
    }
    return kinds[kind];
}

// whether a colour has no red, green or blue (inline)
static inline bool Unk_IsBlack(const Unk_Rect& color) {
    return (color.field_0 <= 0.0f) & (color.field_4 <= 0.0f) & (color.field_8 <= 0.0f);
}

// 0x7100429460: the light ghosts handed to the glare (whether there are any)
// NON_MATCHING: 11 instructions: the original's `and`s of the four tests of
// `none` take their operands the other way round (the later test first) and
// its loads come in another order, and it tests `none | (on == 0)` where this
// tests `(on != 0) & !none` (bic). What decided the rest: the two skips as
// two `if`s with their own store and `continue` (one test would make the loop
// small enough for LoopUnswitch to split it on `none`), `scale` assigned
// after `offset` from the factors (their registers), and field_2c stored last.
bool CPostEffect::Unk_429460() {
    Unk_45eb90_Self* glare = field_198;
    field_c6e = false;
    field_c6f = false;
    if (glare->field_114 >= 0) {
        glare->field_200 = 0;
    }
    bool none = (field_848 <= 0.0f) & Unk_IsBlack(field_198->field_224);
    s32 count = field_524;
    s32 drawn = 0;
    for (s32 i = 0; i < count; i++) {
        const Unk_423ba0_Item& ghost = field_868[i];
        if (!ghost.field_0 || none) {
            field_198->field_208[i].field_0 = false;
            continue;
        }
        if (ghost.field_4.field_0 <= 0.0f && ghost.field_4.field_4 <= 0.0f && ghost.field_4.field_8 <= 0.0f) {
            field_198->field_208[i].field_0 = false;
            continue;
        }
        f32 offset;
        f32 scale;
        f32 depth;
        if (ghost.field_30 == 7) {
            Unk_Refresh();
            f32 near = field_1064;
            Unk_Refresh();
            depth = (ghost.field_2c - near) / ghost.field_2c;
            scale = field_1054;
            offset = field_1058;
        } else {
            f32 factors[4];
            Unk_428cc0(factors, ghost.field_30, 2, 1.0f, 0.0f);
            offset = factors[1];
            scale = factors[0];
            depth = ghost.field_2c;
        }
        Unk_423ba0_Item& out = field_198->field_208[i];
        out.field_0 = true;
        out.field_14 = ghost.field_14;
        out.field_1c = ghost.field_1c;
        out.field_4 = ghost.field_4;
        out.field_24 = ghost.field_24;
        out.field_28 = ghost.field_28;
        out.field_2c = offset + scale * depth;
        if (out.field_24 == 1) {
            field_c6f = true;
        }
        drawn++;
    }
    if (field_198->field_114 >= drawn) {
        field_198->field_200 = drawn;
    }
    s32 kind = Unk_LightGhostKind(field_874);
    Unk_4534e0_update(reinterpret_cast<Unk_4534e0*>(field_198), kind);
    bool known = static_cast<u32>(kind) < 20;
    if (kind == -1) {
        Unk_4534d0_update(reinterpret_cast<Unk_4534d0*>(field_198), field_880, field_878);
        known = field_880 > 0;
    }
    field_c6e = drawn > 0 && known;
    return field_c6e;
}


// the depth of field's kind of a camera mode (a table set up the first time)
static inline s32 Unk_DofCameraMode(u32 mode) {
    static bool initialised = false;
    static s32 modes[4];
    if (!initialised) {
        initialised = true;
        modes[0] = 0;
        modes[1] = 1;
        modes[2] = 2;
        modes[3] = 3;
    }
    return modes[mode];
}

}  // namespace PPFX

// 0x71004aa260, 0x71004aff30 (lib/yebis/leaf): the depth of field's vignette
// by its numbers and by its range (placeholder types)
struct Unk_4aa260;
s32 Unk_4aa260_set(Unk_4aa260* self, f32 a, f32 b);
struct Unk_4aff30;
u32 Unk_4aff30_update(Unk_4aff30* self, f32 fvalue, f32 farg1);

namespace PPFX {

// 0x7100428220: the depth of field's camera and the depths it covers this
// frame (the union of the ranges of the effects that use it), then the
// depth's scale and bias
// NON_MATCHING: a draft (2672 of 2720 bytes): the tests, calls and their
// arguments are the original's; the registers, the stack slots and the
// block layout are not. The original keeps a stack temporary for field_8f4
// and field_8f8 in the last clamps (here their own addresses are selected).
s32 CPostEffect::Unk_428220() {
    field_895 = false;
    field_1050 = false;
    Unk_42b8a0();
    bool dofIn = false;
    if (field_ce5 && static_cast<u32>(field_ce8 - 1) < 2) {
        dofIn = Unk_4622e0(field_6c4, field_6c8, field_d10, field_d14);
    }
    bool exposureIn = field_f38 && Unk_4622e0(field_6c4, field_6c8, field_f3c, field_f40);
    if (field_198->field_10c >= 0) {
        field_198->field_1f4 = 0;
    }
    s32 count = field_478;
    s32 shafts = 0;
    for (s32 i = 0; i < count; i++) {
        if (!field_858[i].field_60 || field_848 <= 0.0f) {
            continue;
        }
        if (field_858[i].field_0.field_0 <= 0.0f && field_858[i].field_0.field_4 <= 0.0f &&
            field_858[i].field_0.field_8 <= 0.0f) {
            continue;
        }
        shafts += field_858[i].field_60;
    }
    Unk_429f20(false, true);
    field_1078 = -1;
    if (field_ce5 && !field_8b6) {
        field_1078 = field_ce8;
        bool far;
        bool moved;
        bool projection;
        bool rotation;
        bool any;
        Unk_42a590(&far, &moved, &projection, &rotation, &any);
    }
    bool blur = false;
    bool blurIn = false;
    if (field_d80 && field_d84 != 0 && field_d88 != nullptr &&
        (field_d9c.field_0[0].field_0 != 0.0f || field_d9c.field_0[1].field_0 != 0.0f ||
         field_d9c.field_0[2].field_0 != 0.0f || field_d9c.field_0[3].field_0 != 0.0f)) {
        blur = true;
        blurIn = field_de8 && Unk_4622e0(field_6c4, field_6c8, field_de0, field_de4);
    }
    bool other = field_50 != nullptr || field_548;
    bool fog = !(field_ec0 <= 0.0f || field_ecc <= 0.0f || field_ed0 <= 0.0f) && field_eb8 && !other;
    bool scatter = field_f08 && (field_f14 < 1.0f || field_f18 != 1.0f);
    bool fullScreen = field_f0c == 2;
    const Unk_Float& nearPlane = reinterpret_cast<const Unk_Float&>(field_6c4);
    const Unk_Float& farPlane = reinterpret_cast<const Unk_Float&>(field_6c8);
    Unk_Float near = farPlane;
    Unk_Float far = nearPlane;
    bool any = false;
    if (dofIn) {
        f32 low = field_6c4;
        f32 high = field_6c8;
        f32 now = field_d10;
        f32 before = field_d14;
        if (Unk_4622e0(low, high, now, before)) {
            f32 next = now > before ? before : low;
            low = next > low ? next : low;
            next = now < before ? before : high;
            high = next < high ? next : high;
        }
        near.field_0 = low < near.field_0 ? low : near.field_0;
        far.field_0 = high > far.field_0 ? high : far.field_0;
        any = true;
    } else if (field_ce5 && field_ce8 == 2) {
        near = Unk_Min(nearPlane, near);
        far = Unk_Max(farPlane, far);
        any = true;
    }
    if (blurIn) {
        f32 low = field_6c4;
        f32 high = field_6c8;
        f32 now = field_de0;
        f32 before = field_de4;
        if (Unk_4622e0(low, high, now, before)) {
            f32 next = now > before ? before : low;
            low = next > low ? next : low;
            next = now < before ? before : high;
            high = next < high ? next : high;
        }
        near.field_0 = low < near.field_0 ? low : near.field_0;
        far.field_0 = high > far.field_0 ? high : far.field_0;
        any = true;
    } else if (blur) {
        near = Unk_Min(nearPlane, near);
        far = Unk_Max(farPlane, far);
        any = true;
    }
    if (exposureIn) {
        f32 low = field_6c4;
        f32 high = field_6c8;
        f32 now = field_f3c;
        f32 before = field_f40;
        if (Unk_4622e0(low, high, now, before)) {
            f32 next = now > before ? before : low;
            low = next > low ? next : low;
            next = now < before ? before : high;
            high = next < high ? next : high;
        }
        near.field_0 = low < near.field_0 ? low : near.field_0;
        far.field_0 = high > far.field_0 ? high : far.field_0;
        any = true;
    }
    bool clamp = true;
    if (fog) {
        if (Unk_427ad0()) {
            f32 low = field_8f4;
            f32 x = field_90c;
            if (x > 0.0f) {
                f32 high = field_8f8;
                low = x < low ? low : (x > high ? high : x);
                f32 y = field_910;
                if (y > 0.0f) {
                    low = Unk_Less(low, y);
                }
            }
            f32 current = field_6c4;
            f32 before = field_ef0;
            f32 now = field_eec;
            if (Unk_4622e0(current, field_6c8, now, before)) {
                f32 next = now > before ? before : current;
                current = next > current ? next : current;
            }
            low = low > current ? low : current;
            f32 high = field_8f8;
            f32 y = field_910;
            if (y > 0.0f) {
                f32 low2 = field_8f4;
                high = y < low2 ? low2 : (y > high ? high : y);
                f32 x2 = field_90c;
                if (x2 > 0.0f) {
                    high = Unk_Greater(high, x2);
                }
            }
            current = field_6c8;
            before = field_ef0;
            now = field_eec;
            if (Unk_4622e0(field_6c4, current, now, before)) {
                f32 next = now < before ? before : current;
                current = Unk_Less(next, current);
            }
            high = high < current ? high : current;
            near.field_0 = low < near.field_0 ? low : near.field_0;
            far.field_0 = high > far.field_0 ? high : far.field_0;
        } else {
            near = Unk_Min(nearPlane, near);
            far = Unk_Max(farPlane, far);
        }
    } else if (shafts > 0 || (!other && scatter && fullScreen)) {
        if (!any) {
            near = nearPlane;
            far = farPlane;
        }
    } else if (!any) {
        near = nearPlane;
        far = farPlane;
        clamp = false;
    }
    f32 focus = 0.0f;
    if (clamp) {
        near = Unk_Max(near, Unk_Float(field_8f4));
        far = Unk_Min(far, Unk_Float(field_8f8));
        near = Unk_Max(near, nearPlane);
        far = Unk_Min(far, farPlane);
        focus = near.field_0;
    }
    s32 result = 0;
    if (field_1a0 != nullptr) {
        CDepthOfField* dof = reinterpret_cast<CDepthOfField*>(field_1a0);
        result = dof->Unk_4afc40(field_6c4, field_6c8, field_6d0, field_6d4, field_6d8, field_898, field_89c, field_8a4,
                                 Unk_DofCameraMode(field_8a0), field_8a8.field_0[0].field_0,
                                 field_8a8.field_0[1].field_0, field_8b8.field_0[0].field_0,
                                 field_8b8.field_0[1].field_0, focus, field_904, field_908);
        if (field_198 != nullptr && reinterpret_cast<CDepthOfField*>(field_1a0)->field_184) {
            Unk_42b9f0();
        }
        switch (field_918) {
        case 2: {
            f32 size = field_948 * (field_944 * (field_94c ? field_89c : 1.0f) +
                                    reinterpret_cast<CDepthOfField*>(field_1a0)->field_1a8 * field_940);
            result = Unk_4aa260_set(reinterpret_cast<Unk_4aa260*>(field_1a0),
                                    fabsf(field_948) * (field_93c * (field_94c ? field_89c : 1.0f)), size);
            break;
        }
        case 3: {
            f32 scale = 0.41421357f / ((field_6d0 - 0.41421357f) * field_920 + 0.41421357f);
            f32 size = field_950 * scale;
            f32 distance = field_954;
            f32 angle = atanf(field_6d0 * powf(0.41421357f / field_6d0, field_958)) * 2.0f;
            result = reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4afd80(size, distance * size, angle);
            break;
        }
        case 4: {
            f32 a;
            f32 b;
            if (field_960 < 0.0f) {
                a = 0.0f;
                b = -1.0f;
            } else {
                f32 scale = 0.41421357f / ((field_6d0 - 0.41421357f) * field_920 + 0.41421357f);
                f32 low = field_95c * scale;
                f32 high = field_960 * scale;
                f32 sign = field_964 ? -1.0f : 1.0f;
                a = (low + high) * 0.5f;
                b = (high - low) * sign * 0.5f;
            }
            result = Unk_4aff30_update(reinterpret_cast<Unk_4aff30*>(field_1a0), a, b);
            break;
        }
        }
        field_1050 = reinterpret_cast<CDepthOfField*>(field_1a0)->field_184;
        field_1070 = reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4afaa0(field_c74, 1.0f) * 0.5f;
    }
    if (field_8a4 > 0.0f && field_6c4 > 0.0f && field_6c4 < field_6c8 && field_1050) {
        field_104f = field_bcd;
    } else {
        field_104f = false;
    }
    if (field_104f) {
        field_1064 = field_898;
        memcpy(&field_1054, &reinterpret_cast<CDepthOfField*>(field_1a0)->field_1e8, sizeof(Unk_Float4));
    } else {
        field_1064 = near.field_0;
        field_1054 = 1.0f;
        field_1058 = 0.0f;
        s32 index = field_5d8;
        if (index == -1) {
            index = field_190->field_90;
        }
        Unk_RenderTexture* depth = field_190->field_38[index];
        index = field_5e0;
        if (index == -1) {
            index = field_190->field_90;
        }
        Unk_RenderTexture* scene = field_190->field_38[index];
        if ((Unk_IsFloat32Format(depth->field_38) || Unk_IsFloat16Format(depth->field_38)) &&
            (Unk_IsFloat32Format(scene->field_38) || Unk_IsFloat16Format(scene->field_38))) {
            if (field_914) {
                field_1054 = far.field_0 / (far.field_0 - near.field_0) * 64000.0f;
                field_1058 = -64000.0f;
            } else {
                field_1064 = std::min(field_6c4 * 64000.0f, far.field_0);
            }
        }
    }
    field_1060 = -field_1058 / field_1054;
    field_105c = 1.0f / field_1054;
    return result;
}

// 0x710042b9f0: the depth of field's numbers handed to the glare
// NON_MATCHING: only the TU's statics block (its table at 0x71024e0d38): it
// matches once 0x710041afb0's statics exist (checked with a stand-in
// Initialize in a scratch copy)
s32 CPostEffect::Unk_42b9f0() {
    if (field_198 != nullptr) {
        field_198->field_248 = 0.0f;
        field_198->field_24c = 0.0f;
        field_198->field_250 = 0.0f;
        field_198->field_254 = 0.0f;
        field_198->field_264 = 0.0f;
        field_198->field_268 = 0.0f;
    }
    if (field_198 == nullptr || !reinterpret_cast<CDepthOfField*>(field_1a0)->field_184) {
        return 1;
    }
    CDepthOfField* dof = reinterpret_cast<CDepthOfField*>(field_1a0);
    f32 size = dof->field_1a8;
    Unk_Float distance = field_6d0;
    f32 limit = Unk_4afa90_get(reinterpret_cast<const Unk_4afa90*>(dof));
    Unk_Float fNumber = reinterpret_cast<CDepthOfField*>(field_1a0)->field_1b4;
    if (field_884 != 1.0f) {
        f32 t = tanf(field_888 * 0.5f);
        distance = t * powf(field_6d0 / t, field_884);
        f32 fov = atanf(distance.field_0) * 2.0f;
        f32 focus = field_898;
        f32 width = field_89c;
        f32 value = field_8a4;
        f32 coc;
        reinterpret_cast<CDepthOfField*>(field_1a0)
            ->Unk_4af020(Unk_DofCameraMode(field_8a0), fov, focus, width, value, field_8a8.field_0[0].field_0,
                         field_8a8.field_0[1].field_0, field_8b8.field_0[0].field_0, field_8b8.field_0[1].field_0, &size,
                         &fNumber, nullptr, &coc, nullptr, nullptr, 0.0f);
    }
    if (field_88c > 0.0f) {
        fNumber = field_88c;
    }
    f32 range = field_890 > 0.0f ? field_890 : limit;
    f32 ratio = size / fNumber.field_0;
    field_198->field_248 = range > 0.0f ? range / fNumber.field_0 : 0.0f;
    field_198->field_24c = ratio;
    field_198->field_250 = size;
    field_198->field_254 = distance;
    field_198->field_264 = reinterpret_cast<CDepthOfField*>(field_1a0)->field_1b0;
    field_198->field_268 = reinterpret_cast<CDepthOfField*>(field_1a0)->field_1b8;
    return 0;
}

// 0x7100461d60 (GPUTextureUtil.cpp)
s32 FXDCT_GetDepthCastTypeFromDepthFormat(s32 format);

// whether a format is a depth format (inline)
static inline bool Unk_IsDepthFormat(s32 format) {
    switch (format) {
    case 20:
    case 40:
    case 45:
    case 55:
        return true;
    default:
        return false;
    }
}

// the depth cast type of a depth source (a table set up the first time; one
// caller, 0x710042cc90, reads it as it is, the others check it with
// Unk_CheckDepthCastType)
static inline s32 Unk_DepthCastType(s32 source) {
    static bool initialised = false;
    static s32 types[4];
    if (!initialised) {
        initialised = true;
        types[0] = 0;
        types[1] = 1;
        types[2] = 2;
        types[3] = 3;
    }
    return types[source];
}

// 0x710042be10: the velocity of the scene's depth (once a frame)
// NON_MATCHING: 82 instructions (was 224): the frame is 0x10 smaller, the
// first projection's loads are scheduled earlier, and the depth cast type is
// a select (csinv) where the original keeps a switch on it (a jump table
// whose four cases join field_50's test, type spilled as 64 bits). What
// decided the rest: the projections through an inline helper, field_d64's
// address taken early (it is kept in x21), the depth factors through the
// inline Unk_DepthFactors (their array is the frame's top slot) kept in
// locals for the falloff, the falloff's default set in both branches and its
// range read into locals, and one FXDCT call for both depth cases.
s32 CPostEffect::Unk_42be10() {
    if (!field_10da || field_10db) {
        return 0;
    }
    MATRIXT44 projection;
    Unk_Perspective(&projection, field_6c4, field_6c8, field_6d0, field_420, field_6d4, field_6d8);
    MATRIXT44 previous;
    Unk_Perspective(&previous, field_6c4, field_6c8, field_6e8, field_420, field_6ec, field_6f0);
    s32 source = field_58;
    Unk_RenderTexture* external = field_50;
    bool own = source == 8 || external != nullptr;
    Unk_RenderTexture* depth;
    if (source == 8) {
        depth = field_190->field_80[static_cast<s32>(field_190->field_94)];
    } else {
        depth = own ? external : Unk_TextureAt(field_5e0);
    }
    s32 type;
    if (source == 8 || Unk_IsDepthFormat(depth->field_38)) {
        type = FXDCT_GetDepthCastTypeFromDepthFormat(depth->field_38);
    } else {
        type = Unk_CheckDepthCastType(Unk_DepthCastType(own ? source : 3));
    }
    f32 scale;
    f32 bias;
    if (field_50 != nullptr) {
        scale = field_60;
        bias = field_64;
    } else {
        scale = 1.0f;
        bias = 0.0f;
    }
    s32 from;
    if (source == 8) {
        if (field_1014) {
            scale = -1.0f;
            bias = 1.0f;
        }
        from = 0;
    } else {
        bias = own ? bias : 0.0f;
        scale = own ? scale : 1.0f;
        from = own ? 6 : 2;
    }
    Unk_Rect factors = Unk_DepthFactors(from, 0, scale, bias);
    f32 depthMul = factors.field_0;
    f32 depthAdd = factors.field_4;
    Unk_Float2 depthScale(depthMul, depthAdd);
    const Unk_Float2* range = nullptr;
    Unk_Float2 falloff;
    if (field_ce5 && static_cast<u32>(field_ce8 - 1) < 2) {
        bool inside = Unk_4622e0(field_6c4, field_6c8, field_d10, field_d14);
        range = inside ? &field_1084 : nullptr;
        falloff = Unk_Float2(1.0f, 0.0f);
        if (own && inside) {
            Unk_Rect view = Unk_DepthFactors(0, 2, 1.0f, 0.0f);
            f32 a = depthAdd * view.field_0 + view.field_4;
            f32 b = depthMul * view.field_0;
            f32 r0 = range->field_0[0].field_0;
            f32 r1 = range->field_0[1].field_0;
            falloff.field_0[0] = b * r0;
            falloff.field_0[1] = a * r0 + r1;
            range = &falloff;
        }
    } else {
        falloff = Unk_Float2(1.0f, 0.0f);
    }
    Unk_RenderTexture* target = field_d70;
    Unk_RenderTexture* velocity = field_d78;
    const Unk_Float2* jitter = &field_d64;
    s32 mode;
    if (field_d2c == 0) {
        mode = -2;
    } else if (field_d2c == 1) {
        mode = field_d30;
    } else {
        mode = -1;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    s32 result = util->Unk_484f50(field_108c, reinterpret_cast<CRenderTexture*>(depth),
                                  reinterpret_cast<CRenderTexture*>(target), reinterpret_cast<CRenderTexture*>(velocity),
                                  &field_6f4, &field_774, &projection, &previous, type, &depthScale, range, mode,
                                  jitter, false, &field_d6c);
    if (result < 0) {
        return result;
    }
    field_10db = true;
    return 0;
}

// the output format of a tone map's low half (a table set up the first time)
static inline s32 Unk_ToneMapFormat(u32 kind) {
    static bool initialised = false;
    static s32 formats[9];
    if (!initialised) {
        initialised = true;
        formats[0] = 0;
        formats[1] = 1;
        formats[2] = 10;
        formats[3] = 2;
        formats[4] = 4;
        formats[5] = 6;
        formats[6] = 8;
        formats[7] = 14;
        formats[8] = 1;
    }
    return formats[kind];
}

// the shader number that follows some of the tone map's (inline)
static inline s32 Unk_ToneMapShader(s32 shader) {
    switch (shader) {
    case 1:
        return 2;
    case 4:
        return 5;
    case 7:
        return 8;
    case 10:
        return 11;
    case 13:
        return 14;
    default:
        return shader;
    }
}

// 0x710042a0f0: the tone map's output format and shader numbers
// NON_MATCHING: (`field_599 && low == 8`, field_599 tested first, merges the
// defaults' paths and folds the test into one ccmp as in the original;
// `low == 8 && field_599` gets jump-threaded into the defaults) field_106b's conditional store is speculated into a
// select (the original keeps the branch and stores 1 in the block that also
// picks the 0x30001/0x30002 formats); and the shader switch's case 0 is a
// separate test here. The table (0x71024e0dcc) needs the full statics block.
s32 CPostEffect::Unk_42a0f0() {
    u32 toneMap = field_8c8;
    bool b598 = field_598;
    bool b59a = field_59a;
    if (toneMap == 0xffffffff) {
        if (field_59e) {
            toneMap = b59a ? 0x30002 : 0x50005;
        } else {
            toneMap = b598 ? (b59a ? 0x30002 : 0x50008) : 2;
        }
    }
    field_8c8 = toneMap;
    u32 low = toneMap & 0xffff;
    if (field_599 && low == 8) {
        toneMap = (toneMap & 0xffff0000) | (toneMap >> 16);
        field_8c8 = toneMap;
        low = toneMap >> 16;
    }
    u32 high = toneMap >> 16;
    field_106a = low == high;
    field_106b = false;
    bool srgb = false;
    if (field_59d && low != 8) {
        field_106b = true;
        srgb = true;
    }
    s32 format;
    if (srgb && low != high && low != 8) {
        switch (toneMap) {
        case 0x30001:
            format = 12;
            break;
        case 0x30002:
            format = 13;
            break;
        default:
            format = -1;
            break;
        }
    } else {
        format = Unk_ToneMapFormat(low);
        if (srgb) {
            format = Unk_SrgbFormat(format);
        }
    }
    field_6a4 = format;
    field_688 = 0;
    field_68c = 0;
    field_690 = 0;
    u32 kind = toneMap & 0xffff0000;
    s32 shader;
    s32 first;
    s32 second;
    switch (high) {
    case 0:
        shader = 0;
        first = 0;
        second = 0;
        field_694 = 0;
        field_688 = 0;
        field_68c = 0;
        field_680 = 0;
        field_684 = 0;
        break;
        case 3:
            shader = field_104d ? 1 : 2;
            field_688 = shader;
            field_68c = 3;
            field_690 = 16;
            break;
        case 4:
            shader = field_104d ? 4 : 5;
            field_688 = shader;
            field_68c = 6;
            field_690 = 17;
            break;
        case 5:
            shader = field_104d ? 7 : 8;
            field_688 = shader;
            field_68c = 9;
            field_690 = 18;
            break;
        case 6:
            shader = field_104d ? 10 : 11;
            field_688 = shader;
            field_68c = 12;
            field_690 = 19;
            break;
        default:
            if (kind == 0x70000) {
                shader = field_104d ? 13 : 14;
                field_688 = shader;
                field_68c = 15;
                field_690 = 0;
            } else {
                shader = 0;
            }
            break;
        }
    if (high != 0) {
        first = field_59d ? 0 : shader;
        second = field_59d ? shader : 0;
        field_694 = shader;
        field_680 = first;
        field_684 = second;
        if (b598) {
            if (kind == 0x70000) {
                field_680 = shader;
                first = shader;
            } else {
                shader = 0;
                first = 0;
                second = 0;
                field_680 = 0;
                field_684 = 0;
                field_688 = 0;
                field_68c = 0;
            }
        }
        if (b59a) {
            field_680 = 3;
            field_688 = 3;
            field_68c = 1;
            field_690 = 0;
            shader = 3;
            first = 3;
        }
    }
    field_698 = Unk_ToneMapShader(first);
    field_69c = Unk_ToneMapShader(second);
    field_6a0 = Unk_ToneMapShader(shader);
    f32 ratio = field_8cc / field_8d0;
    f32 most = field_59c ? 16.0f : 32.0f;
    ratio = ratio > most ? most : ratio;
    field_f70 = ratio < 0.1f ? 0.1f : ratio;
    return 0;
}


}  // namespace PPFX

// 0x71024e09e0: a flag (placeholder)
extern u8 Unk_24e09e0;

// 0x71004553c0 to 0x7100455560 (lib/yebis/leaf/Unk_455350.cpp): the glare's
// setters
struct Unk_455350;
u32 Unk_4553c0_set(Unk_455350* self, f32 value);
u32 Unk_4553e0_set(Unk_455350* self, f32 value);
u32 Unk_455400_set(Unk_455350* self, f32 value);
u32 Unk_455420_set(Unk_455350* self, f32 value);
u32 Unk_455440_set(Unk_455350* self, f32 value);
u32 Unk_455460_set(Unk_455350* self, f32 value);
u32 Unk_455480_set(Unk_455350* self, f32 value);
u32 Unk_4554a0_set(Unk_455350* self, f32 value);
u32 Unk_455560_set(Unk_455350* self, u32 value, f32 a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8,
                   f32 a9);

namespace PPFX {

// 0x7100478880 (GPUTextureUtil.cpp)
f32 Unk_478880(f32 arg1, f32 arg2, bool flag);

// the glare's quality of a star quality (a table set up the first time)
static inline s32 Unk_GlareQuality(u32 quality) {
    static bool initialised = false;
    static s32 qualities[2];
    if (!initialised) {
        initialised = true;
        qualities[0] = 1;
        qualities[1] = 3;
    }
    return qualities[quality];
}

// a render texture as what it is (inline)
static inline CRenderTexture* Unk_AsTexture(Unk_RenderTexture* texture) {
    return reinterpret_cast<CRenderTexture*>(texture);
}

// the size of a device surface, as this file reads it
struct Unk_SurfaceSize {
    u8 pad_0[0x4c];
    u32 field_4c;
    u32 field_50;
};

// field_1b0's current texture (inline)
static inline Unk_RenderTexture* Unk_WorkTexture(const Unk_4a5d10_Self* textures) {
    s32 index = textures->field_90;
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

// the scene's luminance (inline)
static inline f32 Unk_SceneLuminance(const CPostEffect* self) {
    if (self->field_59a) {
        return self->field_8c0.field_0 * self->field_7fc;
    }
    return self->field_7f8;
}

// whether the output is not an HDR one, or is one in field_970's way (inline)
static inline bool Unk_IsPlainOutput(const CPostEffect* self) {
    if (!self->field_96c && Unk_24e09bc == 0) {
        return true;
    }
    return self->field_96c && self->field_970 != 0;
}

// the blend mode of field_be0 (inline)
static inline s32 Unk_BlendMode(u32 mode) {
    switch (mode) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 0x301:
        return 1;
    case 0x501:
        return 3;
    case 0x801:
        return 5;
    case 0x60101:
        return 4;
    default:
        return -1;
    }
}

// whether a format is a floating point one (inline)
static inline bool Unk_IsFloatFormat(s32 format) {
    return Unk_IsFloat32Format(format) || Unk_IsFloat16Format(format) || format == 26;
}

// the depth of field, then the end when field_8b6 says so (inline)
static inline bool Unk_ApplyDepthOfField(CPostEffect* self, s32* result) {
    if (self->field_104f) {
        *result = self->ApplyEffects_DepthOfField();
    }
    return self->field_8b6;
}

// 0x710042c300: CPostEffect::ApplyEffects_GenerateNormalAndLinearDepth (its
// log line names it): the normal and linear depth of the scene's depth into
// texture field_1f0
// NON_MATCHING: 130 instructions (was 203), mostly register allocation and
// spill slots (mode and offset, the coordinates, the near and far planes);
// the original also keeps the matrix pointer 0xe48 in x2 for the identity
// test. What decided the rest: field_58 read again into a local for the
// depth cast type (CodeGenPrepare makes a branch of `own ? field_58 : 3`
// when the load is in the select's block), field_50 read before field_58,
// the frustum's sides as locals, the flip matrix with its diagonal stored in
// order, the scales and offsets as chained assignments and the texel size
// copied as one object.
s32 CPostEffect::ApplyEffects_GenerateNormalAndLinearDepth() {
    s32 mode;
    Unk_Float offset;
    Unk_Float scale;
    switch (field_df8_i) {
    case 0:
        mode = 2;
        offset = 0.0f;
        scale = 1.0f;
        break;
    case 1:
        mode = 3;
        offset = 0.0f;
        scale = 1.0f;
        break;
    case 2:
        mode = 0;
        offset = 0.0f;
        scale = 1.0f;
        break;
    case 3:
        mode = 1;
        offset = 0.0f;
        scale = 1.0f;
        break;
    default:
        if (field_dfc == 1) {
            mode = 4;
            offset = -1.0f;
            scale = 2.0f;
        } else if (field_dfc == 0) {
            mode = 4;
            offset = 0.0f;
            scale = 1.0f;
        } else {
            mode = -1;
            offset = 0.0f;
            scale = 1.0f;
        }
        break;
    }
    Unk_RenderTexture* external = field_50;
    s32 source = field_58;
    bool own = source == 8 || external != nullptr;
    Unk_RenderTexture* depth;
    if (source == 8) {
        depth = field_190->field_80[static_cast<s32>(field_190->field_94)];
    } else {
        depth = own ? external : Unk_TextureAt(field_5e0);
    }
    Unk_RenderTexture* normal = field_df8_i == 4 ? field_df0 : nullptr;
    Unk_RenderTexture* target = field_1f0;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    s32 type;
    if (source == 8 || Unk_IsDepthFormat(depth->field_38)) {
        type = FXDCT_GetDepthCastTypeFromDepthFormat(depth->field_38);
    } else {
        s32 index = field_58;
        type = Unk_CheckDepthCastType(Unk_DepthCastType(own ? index : 3));
    }
    f32 depthScale = 1.0f;
    f32 depthBias = 0.0f;
    if (field_50 != nullptr) {
        depthScale = field_60;
        depthBias = field_64;
    }
    s32 from;
    if (source == 8) {
        if (field_1014) {
            depthScale = -1.0f;
            depthBias = 1.0f;
        }
        from = 0;
    } else {
        depthBias = own ? depthBias : 0.0f;
        depthScale = own ? depthScale : 1.0f;
        from = own ? 6 : 2;
    }
    Unk_Rect factors = Unk_DepthFactors(from, 0, depthScale, depthBias);
    f32 w = field_6d0 * field_420 * field_6c4;
    f32 h = field_6d0 * field_6c4;
    f32 xw = field_6d4 * w;
    f32 yh = h * field_6d8;
    f32 right = w + xw;
    f32 left = xw - w;
    f32 bottom = yh - h;
    f32 top = h + yh;
    Unk_Float2 size(right - left, top - bottom);
    MATRIXT44 transform;
    Unk_Identity(&transform);
    switch (mode) {
    case 0:
    case 1:
    case 2:
        break;
    default: {
        {
            Unk_Float3 scales;
            scales.field_0[0] = scales.field_0[1] = scales.field_0[2] = scale;
            Unk_Float3 offsets;
            offsets.field_0[0] = offsets.field_0[1] = offsets.field_0[2] = offset;
            MATRIXT44 m;
            Unk_40f660(&m, reinterpret_cast<const Unk_Vector3*>(&scales), reinterpret_cast<const Unk_Vector3*>(&offsets));
            MATRIXT44_MatrixMultiply(&transform, &transform, &m);
        }
        if (!Unk_IsIdentity(Unk_E48())) {
            MATRIXT44_MatrixMultiply(&transform, &transform, &Unk_E48());
        }
        if (field_e00) {
            MATRIXT44 flip;
            flip.field_0[0][1] = flip.field_0[0][2] = flip.field_0[0][3] = flip.field_0[1][0] = flip.field_0[1][2] =
                flip.field_0[1][3] = flip.field_0[2][0] = flip.field_0[2][1] = flip.field_0[2][3] = flip.field_0[3][0] =
                    flip.field_0[3][1] = flip.field_0[3][2] = 0.0f;
            flip.field_0[0][0] = 1.0f;
            flip.field_0[1][1] = 1.0f;
            flip.field_0[2][2] = -1.0f;
            flip.field_0[3][3] = 1.0f;
            MATRIXT44_MatrixMultiply(&transform, &transform, &flip);
        }
        if (Unk_E04() == 1) {
            MATRIXT44_MatrixMultiply(&transform, &transform, &field_734);
        }
        break;
    }
    }
    CRenderTexture* depthTexture = Unk_AsTexture(depth);
    f32 su = depthTexture->field_88;
    f32 sv = depthTexture->field_8c;
    f32 dw = static_cast<f32>(static_cast<u32>(depthTexture->field_54));
    f32 dh = static_cast<f32>(static_cast<u32>(depthTexture->field_58));
    f32 u0 = depthTexture->field_90;
    f32 v0 = depthTexture->field_94;
    f32 nu = 0.0f;
    f32 nv = 0.0f;
    if (normal != nullptr) {
        Unk_GetCoords(Unk_AsTexture(normal), &nu, &nv);
    }
    f32 tw = static_cast<f32>(target->field_54);
    f32 th = static_cast<f32>(target->field_58);
    Unk_Float2 texel = *reinterpret_cast<const Unk_Float2*>(&depthTexture->field_88);
    Unk_SetTarget(Unk_AsTexture(target));
    f32 low = field_8f4;
    f32 x = field_90c;
    if (x > 0.0f) {
        f32 high = field_8f8;
        low = x < low ? low : (x > high ? high : x);
        f32 y = field_910;
        if (y > 0.0f) {
            low = Unk_Less(low, y);
        }
    }
    f32 current = field_6c4;
    f32 before = field_ef0;
    f32 now = field_eec;
    if (Unk_4622e0(current, field_6c8, now, before)) {
        f32 next = now > before ? before : current;
        current = Unk_Greater(next, current);
    }
    f32 nearPlane = low > current ? low : current;
    f32 high = field_8f8;
    f32 y = field_910;
    if (y > 0.0f) {
        f32 low2 = field_8f4;
        high = y < low2 ? low2 : (y > high ? high : y);
        f32 x2 = field_90c;
        if (x2 > 0.0f) {
            high = Unk_Greater(high, x2);
        }
    }
    current = field_6c8;
    before = field_ef0;
    now = field_eec;
    if (Unk_4622e0(field_6c4, current, now, before)) {
        f32 next = now < before ? before : current;
        current = next < current ? next : current;
    }
    f32 u1 = su * dw + u0;
    f32 v1 = sv * dh + v0;
    f32 n = field_6c4;
    f32 f = field_6c8;
    Unk_GPUTexture* depthGpu = Unk_GetTexture(depthTexture);
    Unk_GPUTexture* normalGpu = normal != nullptr ? Unk_GetTexture(Unk_AsTexture(normal)) : nullptr;
    f32 farPlane = high < current ? high : current;
    MATRIXT44 projection;
    if (mode == 2) {
        Unk_Perspective(&projection, n, f, field_6d0, field_420, field_6d4, field_6d8);
    } else {
        Unk_Identity(&projection);
    }
    s32 result = util->Unk_48bbc0(0.0f, 0.0f, tw, th, 0.0f, 0.0f, u1, v1, type, mode,
                                  reinterpret_cast<const Unk_Float2*>(&factors), &size, depthGpu, &texel, normalGpu,
                                  0.0f, 0.0f, nu, nv, n, f, &projection, &transform, nearPlane, farPlane, 0);
    if (result < 0) {
#line 23520
        PPFX_ERROR("CPostEffect::ApplyEffects_GenerateNormalAndLinearDepth(): pTexUtil->DrawRectGPU_GenerateNormalAndLinearDepth() failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    field_10dd = true;
    return 0;
}

// 0x710042cc90: the depth of field's composite (CTextureUtil::Unk_48b1e0, or
// Unk_48b280 for a depth factor source) from `source` (null: texture field_5d8)
// into `target` (null: texture field_5e0), with `mask` (field_80's) and its
// depth spaces; a negative `view` draws for every view
// NON_MATCHING: register allocation and scheduling only (v0 or u0 spilled,
// two operand orders, a few stores scheduled one place off): about 50
// instructions. The depth factors are stored through the elements' floats
// (`.field_0`: stored as element objects they are integers, and the scale
// and bias defaults become integer constants); the declaration order of the
// four (bias2 first) is the closest of the 24, and the size's reads in this
// order the closest a greedy search of single moves found.
s32 CPostEffect::Unk_42cc90(s32 view, bool clear, void* source, void* target, bool keep, void* mask, u32 maskSpace,
                            u32 depthSpace, u32 flags, f32 offset) {
    if (!field_1051 && field_50 == nullptr) {
        return 0;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    CRenderTexture* from = static_cast<CRenderTexture*>(source);
    CRenderTexture* to = static_cast<CRenderTexture*>(target);
    bool other = from != nullptr && from != to;
    bool all = view < 0;
    if (all && !other) {
        s32 index = field_5d8;
        if (index == -1) {
            index = field_190->field_90;
        }
        CRenderTexture* current = Unk_AsTexture(field_190->field_38[index]);
        if (!(reinterpret_cast<Unk_GPUTexture*>(current->field_b8[current->field_a0])->field_5c & 0x80000)) {
            Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
            all = false;
            view = 0;
        }
    }
    if (clear) {
        util->Unk_471410(all ? 1 : 2, 3, 4);
    }
    if (all) {
        Unk_440c00_get(reinterpret_cast<u64>(field_18), 8);
        field_18->vf45(2);
        view = 0;
    } else if (from == nullptr) {
        from = Unk_AsTexture(Unk_TextureAt(field_5d8));
    }
    if (to == nullptr) {
        to = Unk_AsTexture(Unk_TextureAt(field_5e0));
    }
    CRenderTexture* size = from != nullptr ? from : to;
    f32 fw = static_cast<f32>(static_cast<u32>(size->field_54));
    f32 fh = static_cast<f32>(static_cast<u32>(size->field_58));
    f32 su = size->field_88;
    f32 u0 = size->field_90;
    f32 sv = size->field_8c;
    f32 v0 = size->field_94;
    f32 tw = static_cast<f32>(static_cast<u32>(to->field_54));
    f32 th = static_cast<f32>(static_cast<u32>(to->field_58));
    if (from != nullptr || !keep) {
        s32 result = Unk_SetTarget(to);
        if (result < 0) {
            return result;
        }
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* depth;
    if (field_1051) {
        depth = field_190->field_60[static_cast<s32>(field_190->field_94)];
    } else if (field_50 != nullptr) {
        depth = Unk_GetTexture(Unk_AsTexture(field_50));
    } else {
        depth = nullptr;
    }
    Unk_GPUTexture* texture = from != nullptr ? Unk_GetTexture(from) : nullptr;
    f32* params = &field_1054;
    f32 blur = field_1064;
    CDepthOfField* dof = reinterpret_cast<CDepthOfField*>(field_1a0);
    s32 level = dof->field_16c;
    dof->Unk_4aef30();
    depth->vf17(1);
    if (texture != nullptr) {
        texture->vf17(fw == tw && fh == th);
    }
    f32 ratio = Unk_SceneLuminance(this) / field_7f8;
    f32 u1 = su * fw;
    f32 v1 = sv * fh;
    Unk_Float4 colour(ratio, ratio, ratio, 1.0f);
    Unk_Rect maskScale;
    maskScale.field_0 = 1.0f;
    maskScale.field_4 = 0.0f;
    maskScale.field_8 = 1.0f;
    maskScale.field_c = 0.0f;
    Unk_Rect depthScale;
    depthScale.field_0 = 1.0f;
    depthScale.field_4 = 0.0f;
    depthScale.field_8 = 1.0f;
    depthScale.field_c = 0.0f;
    Unk_GPUTexture* maskTexture = nullptr;
    f32 maskV;
    if (mask != nullptr) {
        maskTexture = Unk_GetTexture(static_cast<CRenderTexture*>(mask));
        maskTexture->vf15(4);
        maskScale = Unk_DepthFactors(6, maskSpace, 1.0f, 0.0f);
        f32 bias2 = 0.0f;
        f32 scale2 = 1.0f;
        f32 scale = 1.0f;
        f32 bias = 0.0f;
        if (field_50 != nullptr) {
            scale = field_60;
            bias = field_64;
            scale2 = field_68;
            bias2 = field_6c;
        }
        if (maskSpace == 6) {
            maskScale.field_4 = maskScale.field_4 * scale + bias;
            maskScale.field_0 = maskScale.field_0 * scale;
        }
        depthScale = Unk_DepthFactors(depthSpace, 1, 1.0f, 0.0f);
        if (depthSpace == 6) {
            f32 x = depthScale.field_0;
            f32 y = depthScale.field_4;
            depthScale.field_0 = scale2 * x;
            depthScale.field_4 = bias2 * x + y;
        }
        f32 mw = static_cast<f32>(maskTexture->field_4c);
        f32 mh = static_cast<f32>(maskTexture->field_50);
        f32 k = (mw - 1.0f) / mw;
        f32 x = maskScale.field_0;
        f32 y = maskScale.field_4;
        maskScale.field_4 = 0.5f / mw + k * y;
        maskScale.field_0 = x * k;
        maskV = (offset + 0.5f) / mh;
    } else {
        maskV = 0.5f;
    }
    u1 = u1 + u0;
    v1 = v1 + v0;
    if (field_1051) {
        util->Unk_48b1e0(0.0f, 0.0f, tw, th, 0.0f, 0.0f, u1, v1, field_6c4, field_6c8, blur, depth, level, texture, view,
                         field_1014, params, maskTexture, &maskScale, &depthScale, flags, maskV, &colour, 0);
    } else if (field_50 != nullptr) {
        s32 type = Unk_DepthCastType(field_58);
        Unk_Rect factors;
        if (maskTexture != nullptr) {
            factors = *reinterpret_cast<const Unk_Rect*>(params);
        } else {
            factors = Unk_DepthFactors(6, 2, 1.0f, 0.0f);
        }
        f32 scale = 1.0f;
        f32 bias = 0.0f;
        f32 scale2 = 1.0f;
        f32 bias2 = 0.0f;
        if (field_50 != nullptr) {
            scale = field_60;
            bias = field_64;
            scale2 = field_68;
            bias2 = field_6c;
        }
        Unk_Float4 depthFactors;
        depthFactors.field_0[0].field_0 = scale;
        depthFactors.field_0[1].field_0 = bias;
        depthFactors.field_0[2].field_0 = scale2;
        depthFactors.field_0[3].field_0 = bias2;
        util->Unk_48b280(0.0f, 0.0f, tw, th, 0.0f, 0.0f, u1, v1, depth, texture, &depthFactors, &factors.field_0, type,
                         view, maskTexture, &maskScale, &depthScale, flags, maskV, &colour, 0);
    }
    if (field_50 != nullptr) {
        depth->vf17(0);
    }
    if (texture != nullptr) {
        texture->vf17(0);
    }
    if (all) {
        Unk_440c00_get(reinterpret_cast<u64>(field_18), 15);
        field_18->vf45(0);
    }
    field_1053 = true;
    return 0;
}

// how far the adaptation goes this frame at `speed` (inline)
inline f32 CPostEffect::Unk_AdaptationRate(f32 speed) const {
    f32 rate = 1.0f - powf(1.0f - speed, field_7f4 / 0.15f);
    return rate < 0.0f ? 0.0f : std::min(rate, 0.5f);
}

// 0x710042d490: the active view's auto exposure: the scene's luminance
// measured from `source` every field_68 frames, and the exposure adapted to it
// NON_MATCHING: a draft (266 differing instructions, was 292): the control
// flow is the original's; the frame is 0x10 smaller (the dither's slot is
// not next to the other outputs), and the measurement's stack slots and the
// float chains differ. `delay / 10` is computed before the slots (as there).
s32 CPostEffect::Unk_42d490(Unk_RenderTexture* source) {
    extern Unk_DeviceSettings Unk_24e1500;
    if (field_67b) {
        return 0;
    }
    s32 format;
    f32 dither;
    f32 scale;
    f32 scale2;
    Unk_42df80(&format, &scale, &scale2, &dither, nullptr, nullptr, nullptr, nullptr, true, false);
    s32 view = field_298;
    Unk_429da0_Item* items = field_2a0;
    CTextureLuminanceManage*& luminance = reinterpret_cast<CTextureLuminanceManage*&>(items[view].field_70);
    s32 fmt = format;
    if (luminance != nullptr) {
        Unk_4b79a0_set(reinterpret_cast<Unk_4b79a0*>(luminance->field_40), 2);
    }
    Unk_4b8b40_update(reinterpret_cast<Unk_4b8b40*>(luminance), field_f74 != 0 ? fmt : -1);
    s32 levels;
    if (luminance != nullptr) {
        s32 delay;
        switch (items[view].field_28) {
        case 0: {
            f32 time = items[view].field_2c;
            delay = static_cast<s32>((time < 0.0f ? 0.5f : time) / field_7f4);
            break;
        }
        case 1:
            delay = static_cast<s32>(std::max(items[view].field_2c, 0.0f));
            break;
        default:
            delay = 0;
            break;
        }
        s32 frames = delay / 10;
        s32 slots = field_18 != nullptr ? static_cast<s32>(Unk_24e1500.field_10 > 1 ? Unk_24e1500.field_10 : 1) : -1;
        levels = std::min(std::max(frames / slots, 1), 5);
        items[view].field_68 = levels + 1;
        s32 step = static_cast<s32>(static_cast<f32>((delay - (levels + 1)) / (levels + 1)) + 0.4999f);
        luminance->field_4f8 = std::max(std::min(step, 15), 0);
        f32 rate = 1.0f - powf(0.05f, field_7f4 * static_cast<f32>(items[view].field_68) / 0.1f);
        luminance->field_4fc = rate < 0.5f ? rate : 0.5f;
        luminance->Unk_4b8b50();
    } else {
        levels = 0;
    }
    Unk_429da0_Item* item = &items[view];
    if (item->field_0 != item->field_64) {
        item->field_58 = 0;
    }
    bool now;
    if (Unk_24e1500.field_10 < 2) {
        now = true;
    } else {
        now = field_18->field_28 % Unk_24e1500.field_10 == 0;
    }
    if (field_2a0[field_298].field_0 && now && item->field_24 <= 0.0f) {
        f32 limit = field_f74 == 0 ? 100.0f : 1.0f;
        f32 grey = field_2a0[field_298].field_4;
        f32 exposure = 0.18f / (grey < 0.0001f ? 0.0001f : std::min(grey, limit));
        if (item->field_54 == levels) {
            CRenderTexture* target = luminance->field_48;
            Unk_Float4 area = item->Unk_MeteringArea();
            f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
            f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
            if (field_18->field_58) {
                area.field_0[3] = 1.0f - area.field_0[3].field_0 - area.field_0[1].field_0;
            }
            area.field_0[2] = area.field_0[0].field_0 * 0.0f + area.field_0[2].field_0;
            area.field_0[3] = area.field_0[1].field_0 * 0.0f + area.field_0[3].field_0;
            Unk_SetTarget(target);
            MATRIXT44 matrix = Unk_429c50(true);
            f32 low = item->field_1c;
            f32 high = item->field_20;
            f32 sceneLuminance = Unk_SceneLuminance(this);
            f32 x = width * 0.0f;
            f32 y = height * 0.0f;
            if (field_f74 != 0) {
                CRenderGlare* glare = reinterpret_cast<CRenderGlare*>(field_198);
                bool vignette = glare->field_180;
                glare->field_180 = false;
                Unk_Float4 colour(field_8e8, field_8e8, field_8e8, field_8e8);
                glare->TonemapToSurface(
                    reinterpret_cast<IGPUSurface*>(target->field_b8[target->field_a0]), false,
                    Unk_AsTexture(source), false, fmt, &colour, nullptr, width, height, x, y,
                    dither * item->field_8, 1.0f, scale, scale2, FLT_MAX, &matrix,
                    field_8c0.field_0 / Unk_SceneLuminance(this), &field_8d4, field_8e4, 0.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, false, &area, -1, 0, -1, 0.6f, nullptr);
                reinterpret_cast<CRenderGlare*>(field_198)->field_180 = vignette;
            } else {
                f32 amount = (Unk_434570() ? 1.0f : 0.0f) * reinterpret_cast<CRenderGlare*>(field_198)->field_138;
                f32 compensation = item->field_8;
                CTextureUtil* util = Unk_TextureUtil();
                Unk_410f90 space;
                Unk_CopyColorSpace(&space, &field_b84);
                util->Unk_48de50(width, height, x, y, field_8c0.field_0 / Unk_SceneLuminance(this),
                                 amount * dither * compensation, low * sceneLuminance, high * sceneLuminance,
                                 Unk_AsTexture(source), reinterpret_cast<CRenderGlare*>(field_198)->field_420,
                                 target, &area, &space, &matrix, false, exposure * 100.0f, 0.125f, 0);
            }
            Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        }
        if (item->field_54 >= levels && luminance->Unk_4b89b0() >= 0) {
            item->field_54 = -1;
            luminance->Unk_4b8a40(false, field_8c0.field_0, field_f74 == 0 ? exposure : field_f70, field_6c4,
                                  field_6c8);
        }
        items[view].field_5c = Unk_4b91f0_get(reinterpret_cast<Unk_4b91f0*>(luminance));
    }
    if (field_2a0[field_298].field_0) {
        f32 measured;
        if (field_2a0[field_298].field_24 > 0.0f) {
            measured = field_2a0[field_298].field_24;
        } else if (field_2a0[field_298].field_70 != nullptr) {
            measured = field_2a0[field_298].field_5c;
        } else {
            measured = 0.0f;
        }
        measured += FLT_MIN;
        f32 current = field_8c0.field_0 + FLT_MIN;
        f32 grey;
        if (field_f74 != 0) {
            f32 value = field_2a0[field_298].field_4;
            grey = luminance->Unk_4b8ae0(value < 0.0001f ? 0.0001f : std::min(value, 1.0f), field_f70, 1.0f);
        } else {
            f32 value = field_2a0[field_298].field_4;
            grey = value < 0.0001f ? 0.0001f : std::min(value, 100.0f);
        }
        f32 ratio = grey / measured;
        Unk_429da0_Item* it = &items[view];
        f32 range = ratio < it->field_38 ? it->field_40 : it->field_4c;
        f32 from = logf(current) / 0.6931472f;
        f32 to = logf(ratio) / 0.6931472f;
        f32 border = logf(it->field_38) / 0.6931472f;
        to = border + range * (to - border);
        f32 result;
        if (to > from) {
            f32 rate = Unk_AdaptationRate(it->field_48);
            f32 speed = Unk_AdaptationRate(it->field_48);
            f32 velocity = it->field_58;
            f32 limit = it->field_50 / field_f6c * field_7f4;
            f32 delta = (from + (to - from) * rate) - from;
            limit = delta < limit ? delta : limit;
            f32 next = velocity + speed * (limit - velocity);
            next = next < 0.0f ? 0.0f : (next > limit ? limit : next);
            it->field_58 = next;
            result = from + next;
            if (result >= to) {
                it->field_58 = 0.0f;
                result = to;
            }
        } else {
            f32 rate = Unk_AdaptationRate(it->field_3c);
            f32 speed = Unk_AdaptationRate(it->field_3c);
            f32 limit = -(it->field_44 / field_f6c * field_7f4);
            f32 velocity = it->field_58;
            f32 delta = (from + (to - from) * rate) - from;
            limit = delta > limit ? delta : limit;
            f32 next = velocity + speed * (limit - velocity);
            next = next < limit ? limit : std::min(next, 0.0f);
            result = from + next;
            it->field_58 = result > to ? next : 0.0f;
            result = result > to ? result : to;
        }
        f32 adjusted = exp2f(result);
        items[view].field_60 =
            adjusted < items[view].field_30 ? items[view].field_30
                                             : (adjusted > items[view].field_34 ? items[view].field_34 : adjusted);
        Unk_4b9200_get(reinterpret_cast<Unk_4b9200*>(luminance));
    }
    Unk_429da0_Item* last = &items[view];
    if (now) {
        last->field_54++;
    }
    last->field_54 = std::max(last->field_54, 0);
    last->field_64 = last->field_0;
    return 0;
}

// 0x710042e560: the active view's auto focus: the depth at the focus point
// measured every field_40 frames, and the focus distance (field_38) adapted to
// it within the depth of field's limits
// NON_MATCHING: 256 instructions (was 283): the field_604 case of the depth
// is laid out at the end there, and most of the rest is register allocation
// and scheduling in the float chains. What decided the rest: field_4 is an
// integer mode and the focus point's elements are element objects (the
// point is copied element by element), `delay / 6` is computed before the
// slots, and field_94 is a signed index.
s32 CPostEffect::Unk_42e560() {
    extern Unk_DeviceSettings Unk_24e1500;
    field_679 = true;
    if (field_67b || !field_104f) {
        return 0;
    }
    s32 view = field_298;
    Unk_429e60_Item* items = field_2a8;
    CTextureLuminanceManage*& luminance = reinterpret_cast<CTextureLuminanceManage*&>(items[view].field_48);
    if (luminance != nullptr) {
        Unk_4b79a0_set(reinterpret_cast<Unk_4b79a0*>(luminance->field_40), 2);
    }
    s32 levels;
    if (luminance != nullptr) {
        f32 time = items[view].field_8;
        u32 mode = items[view].field_4;
        s32 delay;
        if (mode != 0 && !(time < 0.0f)) {
            delay = mode == 1 ? static_cast<s32>(time) : 0;
        } else {
            delay = static_cast<s32>((time < 0.0f ? 0.5f : time) / field_7f4);
        }
        s32 frames = delay / 6;
        s32 slots = field_18 != nullptr ? static_cast<s32>(Unk_24e1500.field_10 > 1 ? Unk_24e1500.field_10 : 1) : -1;
        levels = std::min(std::max(frames / slots, 1), 7);
        items[view].field_40 = levels + 1;
        s32 step = static_cast<s32>(static_cast<f32>((delay - (levels + 1)) / (levels + 1)) + 0.4999f);
        luminance->field_4f8 = std::max(std::min(step, 15), 0);
        f32 rate = 1.0f - powf(0.05f, field_7f4 * static_cast<f32>(items[view].field_40) / 0.1f);
        luminance->field_4fc = rate < 0.9f ? rate : 0.9f;
        luminance->Unk_4b8b50();
    } else {
        levels = 0;
    }
    Unk_429e60_Item* item = &items[view];
    if (item->field_0 != item->field_3c) {
        item->field_30 = 0;
    }
    bool now;
    if (Unk_24e1500.field_10 < 2) {
        now = true;
    } else {
        now = field_18->field_28 % Unk_24e1500.field_10 == 0;
    }
    if (field_2a8[field_298].field_0 && now && item->field_1c <= 0.0f) {
        if (item->field_2c >= levels && luminance->Unk_4b89b0() >= 0) {
            CRenderTexture* target = luminance->field_48;
            Unk_RenderTexture* scene = Unk_TextureAt(field_5d8);
            if (Unk_AsTexture(scene)->Unk_Root()->field_a8 == nullptr) {
                scene = Unk_TextureAt(field_5e0);
            }
            bool external;
            bool linear;
            Unk_RenderTexture* depth;
            Unk_GPUTexture* texture;
            if (field_50 != nullptr) {
                depth = field_50;
                texture = Unk_GetTexture(Unk_AsTexture(depth));
                external = true;
                linear = false;
            } else if (field_678) {
                depth = scene;
                texture = reinterpret_cast<Unk_GPUTexture*>(field_190->field_60[static_cast<s32>(field_190->field_94)]);
                external = false;
                linear = true;
            } else {
                depth = Unk_TextureAt(field_604);
                texture = Unk_GetTexture(Unk_AsTexture(depth));
                external = false;
                linear = false;
            }
            Unk_Float2 point(item->field_14, item->field_18);
            if (field_10d5) {
                f32 distance = field_6cc;
                f32 shift;
                switch (field_c14) {
                case 0:
                    distance = field_c18;
                    shift = 0.0f;
                    break;
                case 2:
                    shift = field_c1c;
                    break;
                default:
                    shift = 0.0f;
                    break;
                }
                point = Unk_4786d0(true, &point, field_c04, distance, field_420, field_be8, shift, field_c20,
                                   field_c24, field_c28, field_c08);
            }
            if (field_18->field_58) {
                point.field_0[1] = 1.0f - point.field_0[1].field_0;
            }
            CRenderTexture* source = Unk_AsTexture(depth);
            f32 x = source->field_88 * (point.field_0[0].field_0 * static_cast<f32>(static_cast<u32>(source->field_54)));
            f32 y = source->field_8c * (point.field_0[1].field_0 * static_cast<f32>(static_cast<u32>(source->field_58)));
            f32 left = source->field_90;
            f32 top = source->field_94;
            texture->vf17(1);
            Unk_SetTarget(target);
            reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aef30();
            CTextureUtil* util = Unk_TextureUtil();
            x = left + x;
            y = top + y;
            if (linear) {
                util->Unk_48b540(0.0f, 0.0f, 1.0f, 1.0f, x, y, x, y, texture, field_1014, 0);
            } else {
                s32 type = Unk_DepthCastType(field_58);
                bool own = texture != Unk_GetTexture(Unk_AsTexture(Unk_TextureAt(field_604)));
                Unk_Rect factors = Unk_DepthFactors(own ? 6 : 2, 0, 1.0f, 0.0f);
                Unk_Float2 scale(factors.field_0, factors.field_4);
                if (external && own) {
                    f32 a = 1.0f;
                    f32 b = 0.0f;
                    if (field_50 != nullptr) {
                        a = field_68;
                        b = field_6c;
                    }
                    scale.field_0[0] = factors.field_0 * a;
                    scale.field_0[1] = factors.field_4 + factors.field_0 * b;
                }
                util->Unk_48b6e0(0.0f, 0.0f, 1.0f, 1.0f, x, y, x, y, &scale, texture, type, 0);
            }
            if (field_50 != nullptr) {
                texture->vf17(0);
            }
            item->field_2c = -1;
            luminance->Unk_4b8a40(false, 1.0f, 1.0f, field_6c4, field_6c8);
        }
        items[view].field_34 = Unk_4b91f0_get(reinterpret_cast<Unk_4b91f0*>(luminance));
    }
    if (field_2a8[field_298].field_0) {
        f32 distance = field_898;
        f32 aperture = field_89c;
        Unk_Refresh();
        CDepthOfField* dof = reinterpret_cast<CDepthOfField*>(field_1a0);
        f32 focal = field_1050 ? dof->field_1a8 : 0.0f;
        f32 far = field_6c8;
        f32 near = field_6c4;
        f32 measured;
        if (field_2a8[field_298].field_1c > 0.0f) {
            measured = field_2a8[field_298].field_1c;
        } else if (field_2a8[field_298].field_48 != nullptr) {
            measured = field_2a8[field_298].field_34;
        } else {
            measured = 0.0f;
        }
        Unk_429e60_Item* it = &items[view];
        f32 current = distance * focal / (distance - focal);
        f32 closest = focal * 1.01f;
        measured = measured > closest ? measured : closest;
        f32 low = it->field_c > FLT_MIN ? it->field_c : focal + focal;
        f32 high = it->field_10;
        if (high == FLT_MAX) {
            f32 circle = dof->field_170 != 0 ? 0.0001f : 0.000001f;
            f32 hyperfocal = focal * dof->field_1ac.field_0 / (aperture * circle);
            high = far * 10.0f;
            hyperfocal = hyperfocal < high ? hyperfocal : high;
            if (low < hyperfocal) {
                high = hyperfocal;
            }
        }
        low = low > near ? low : near;
        f32 limit = std::min(far, high);
        f32 nearImage = focal * low / (low - focal);
        f32 farImage = focal * limit / (limit - focal);
        f32 image = focal * measured / (measured - focal);
        f32 maxImage = image > nearImage ? nearImage : image;
        f32 target = image < farImage ? farImage : maxImage;
        f32 rate = 1.0f - powf(1.0f - it->field_20, field_7f4 / 0.05f);
        rate = rate < 0.0f ? 0.0f : std::min(rate, 0.5f);
        f32 speed = 1.0f - powf(1.0f - it->field_20, field_7f4 / 0.05f);
        speed = speed < 0.0f ? 0.0f : std::min(speed, 0.5f);
        f32 velocity = it->field_30;
        f32 maxSpeed = focal * it->field_28 / field_f68 * field_7f4;
        f32 step = current + (target - current) * rate - current;
        f32 sign = step > 0.0f ? 1.0f : (step < 0.0f ? -1.0f : 0.0f);
        f32 size = fabsf(current + (target - current) * rate - current);
        step = sign * (size < maxSpeed ? size : maxSpeed);
        velocity = velocity + speed * (step - velocity);
        velocity = velocity < -maxSpeed ? -maxSpeed : (velocity > maxSpeed ? maxSpeed : velocity);
        it->field_30 = velocity;
        if (step != 0.0f) {
            f32 a = step > 0.0f ? 0.0f : step;
            f32 b = step > 0.0f ? step : 0.0f;
            velocity = velocity < a ? a : (velocity > b ? b : velocity);
            it->field_30 = velocity;
        }
        f32 highImage = focal * high / (high - focal);
        f32 next = current + velocity;
        bool reached = it->field_24 &&
                       ((velocity < 0.0f && next <= target) || (next >= target && velocity > 0.0f));
        f32 lowImage = focal * low / (low - focal);
        highImage = highImage > focal ? highImage : focal;
        if ((velocity < 0.0f && next <= highImage) || (velocity > 0.0f && next >= lowImage)) {
            it->field_30 = 0.0f;
        }
        if (reached) {
            next = target;
            it->field_30 = 0.0f;
        }
        next = next < highImage ? highImage : (next > lowImage ? lowImage : next);
        f32 focus = focal * next / (next - focal);
        it->field_38 = focus < low ? low : (focus > high ? high : focus);
    }
    Unk_429e60_Item* last = &items[view];
    if (now) {
        last->field_2c++;
    }
    last->field_2c = std::max(last->field_2c, 0);
    last->field_3c = last->field_0;
    return 0;
}

// a colour space assigned with a test for itself (0x710042f540's copy of
// field_ba4)
struct Unk_CopiedColorSpace : Unk_410f90 {
    Unk_CopiedColorSpace& operator=(const Unk_410f90& other) {
        if (this != &other) {
            field_0 = other.field_0;
            field_8 = other.field_8;
            field_10 = other.field_10;
            field_18 = other.field_18;
        }
        return *this;
    }
};

// whether a transfer function is one of PFXTBCSM_SCRGB's (6 to 14, and
// PFXEOTF_PQ's 16; inline)
static inline bool Unk_IsScRgbEotf(s32 eotf) {
    return eotf == 16 || (eotf >= 6 && eotf <= 14);
}

// the output modes (Unk_24e09bc) the colour chart's swatch gets its scale bar
// in (inline)
static inline bool Unk_IsScaleBarMode(s32 mode) {
    return (mode == 1) | (mode == 3) | (mode == 5);
}

// CPostEffect::GetEffectiveTonemapBackendColorSpaceMode (its log line names
// it; inline)
inline s32 CPostEffect::Unk_BackendColorSpaceMode() {
    if (field_59c) {
        return 0;
    }
    s32 mode = field_9ac;
    if (mode == 1) {
        if (field_96c && field_978 != 0 && !Unk_IsScRgbEotf(field_978)) {
#line 17924
            PPFX_ERROR("CPostEffect::GetEffectiveTonemapBackendColorSpaceMode(): PFXTBCSM_SCRGB is available only with PFXEOTF_PQ(PFXEOTF_ST2084) or PFXEOTF_SCRGB_LINEAR.\n");
        }
        return 1;
    }
    return mode;
}

// 0x710042f540: part `kind` of the colour chart in the `w` by `h` rectangle
// at `x`, `y` (`width` isn't used): the transfer function's ramps and patches
// (kinds 0 to 4) and the swatch (5), with its scale bar where the output asks
// for one
// NON_MATCHING: a draft (3312 bytes, not 3336): the calls, their arguments
// and the blocks are the original's (three call sites of
// DrawRectGPU_OptoElectronicTransfer, one per group of kinds, as there).
// Left: the new texture util's block is placed after the release here (after
// kinds 1 and 2 there), Unk_IsScaleBarMode's tests become one bit test (the
// original keeps `(mode | 2) == 3` and `mode == 5` as csets, with the load of
// Unk_238c2e0 first), and the registers and spill slots of the parameters.
s32 CPostEffect::Unk_42f540(s32 kind, bool second, bool hdr, const Unk_42f540_Params* params, f32 width, f32 height,
                            f32 x, f32 y, f32 w, f32 h, f32 a, f32 b, f32 c, f32 d) {
    f32 p8 = params->field_8;
    f32 pc = params->field_c;
    f32 p10 = params->field_10;
    void* surface = params->field_0;
    s32 p14 = params->field_14;
    bool pc8 = params->field_c8;
    s32 eotf = params->field_28;
    s32 p2c = params->field_2c;
    f32 pb0 = params->field_b0;
    f32 pb4 = params->field_b4;
    f32 pb8 = params->field_b8;
    f32 pbc = params->field_bc;
    f32 pc0 = params->field_c0;
    f32 pc4 = params->field_c4;
    f32 pd0 = params->field_d0;
    f32 pd4 = params->field_d4;
    f32 pd8 = params->field_d8;
    f32 pdc = params->field_dc;
    Unk_CopiedColorSpace space;
    space = field_ba4;
    s32 backend = Unk_BackendColorSpaceMode();
    f32 luminance = field_9a8;
    bool linear = Unk_IsScRgbEotf(eotf);
    if (field_18->field_58) {
        y = height - y;
        h = -h;
    }
    bool single = p2c == 1;
    CTextureUtil* util = Unk_TextureUtil();
    const Unk_Float4* color = &params->field_18;
    const MATRIXT44* matrix = &params->field_30;
    const MATRIXT44* matrix2 = &params->field_70;
    s32 either = second || single;
    s32 result;
    switch (kind) {
    case 0: {
        CRenderTexture* texture = hdr ? util->field_29b08[1] : util->field_29b00;
        if (second) {
            MATRIXT44 identity;
            Unk_Identity(&identity);
            result = util->DrawRectGPU_OptoElectronicTransfer(
                x, y, w, h, a, b, c, d, 1, nullptr, Unk_GetTexture(texture), surface, eotf, backend, 0, luminance, p8,
                pc, matrix, &identity, &space, 1.0f, pb4, pdc, 1.0f, -3.40282347e+38f, 0.0f, 0.0f, false,
                field_99c, field_9a0, field_9a4, color, either, 0.0f, 0.18f, 1.0f, nullptr,
                false, false, false, 0.0f, 0, false);
            break;
        }
        MATRIXT44 identity;
        Unk_Identity(&identity);
        MATRIXT44 identity2;
        Unk_Identity(&identity2);
        result = util->DrawRectGPU_OptoElectronicTransfer(
            x, y, w, h, a, b, c, d, 1, nullptr, Unk_GetTexture(texture), surface, eotf, backend, 0, luminance, p8, pc,
            &identity, &identity2, &space, 1.0f, linear ? pb4 : pb8, pdc, 1.0f, -3.40282347e+38f, 0.0f, 0.0f, false,
            field_99c, field_9a0, field_9a4, color, either, 0.0f, 0.18f, 100.0f, nullptr, false,
            false, false, 0.0f, 0, false);
        break;
    }
    case 1:
    case 2: {
        CRenderTexture* texture = hdr ? util->field_29b08[2] : util->field_29b08[0];
        result = util->DrawRectGPU_OptoElectronicTransfer(
            x, y, w, h, a, b, c, d, 1, nullptr, Unk_GetTexture(texture), surface, eotf, backend, p14, luminance, p8, pc,
            matrix, matrix2, &space, pb0, pb4, pdc, p10, -3.40282347e+38f, pc0, pc4, pc8,
            field_99c, field_9a0, field_9a4, color, either, pbc, pd4, pd0, nullptr, false, false,
            false, 0.0f, 0, false);
        break;
    }
    case 3:
    case 4:
        field_18->vf44(1);
        if (second) {
            CRenderTexture* texture = kind == 4 ? util->field_29b08[5] : util->field_29b08[7];
            MATRIXT44 identity;
            Unk_Identity(&identity);
            result = util->DrawRectGPU_OptoElectronicTransfer(
                x, y, w, h, a, b, c, d, 1, nullptr, Unk_GetTexture(texture), surface, eotf, backend, 0, luminance, p8,
                pc, matrix, &identity, &space, pb0, pb4, pdc, 1.0f, -3.40282347e+38f, 0.0f, 0.0f, false,
                field_99c, field_9a0, field_9a4, color, either, 0.0f, 0.18f, 1.0f, nullptr,
                false, false, false, 0.0f, 0, false);
        } else {
            CRenderTexture* texture = kind == 4 ? util->field_29b08[4] : util->field_29b08[6];
            MATRIXT44 identity;
            Unk_Identity(&identity);
            MATRIXT44 identity2;
            Unk_Identity(&identity2);
            result = util->DrawRectGPU_OptoElectronicTransfer(
                x, y, w, h, a, b, c, d, 1, nullptr, Unk_GetTexture(texture), surface, eotf, backend, 0, luminance, p8,
                pc, &identity, &identity2, &space, pb0, linear ? pb4 : pb8, pdc, 1.0f, -3.40282347e+38f, 0.0f, 0.0f,
                false, field_99c, field_9a0, field_9a4, color, either, 0.0f, 0.18f, 100.0f,
                nullptr, false, false, false, 0.0f, 0, false);
        }
        field_18->vf44(0);
        break;
    case 5:
        field_18->vf44(1);
        result = util->DrawRectGPU_OptoElectronicTransfer(
            x, y, w, h, a, b, c, d, 1, nullptr, Unk_GetTexture(util->field_29b08[3]), surface, eotf, backend, p14,
            luminance, p8, pc, matrix, matrix2, &space, pb0, pb4, pdc, p10, -3.40282347e+38f, pc0,
            pc4, pc8, field_99c, field_9a0, field_9a4, color, either, pbc, pd4, pd0, nullptr,
            false, false, true, pd8, 0, false);
        if (Unk_238c2e0 != 0 && Unk_IsScaleBarMode(Unk_24e09bc) &&
            Unk_482380_get(reinterpret_cast<const Unk_482380*>(util))) {
            f32 u0 = 0.0f;
            f32 u1 = 1.0f;
            bool split = false;
            if (field_96c) {
                split = field_974 > 1;
                if (split) {
                    u0 = second ? 0.5f : 0.0f;
                    u1 = second ? 1.0f : 0.5f;
                }
            }
            f32 scale = eotf < 6 || eotf == 17 ? 2.0f : 1.0f;
            Unk_Float4 colour(scale, scale, scale, 0.6666666f);
            if (split && Unk_238c2e0 == 2 && Unk_IsScaleBarMode(Unk_24e09bc)) {
                f32 part = w / 3.0f;
                f32 base = u0 / 3.0f;
                for (s32 i = 0; i < 3; i++) {
                    result = util->DrawRectGPU_MadT1_Sn(part * i + x, y, part, h, base + i / 3.0f, 0.0f,
                                                        base + (i / 3.0f + 1.0f / 6.0f), 1.0f, 1, nullptr, &colour,
                                                        Unk_GetTexture(util->field_29b08[8]), 0, 0x10000);
                }
            } else {
                result = util->DrawRectGPU_MadT1_Sn(x, y, w, h, u0, 0.0f, u1, 1.0f, 1, nullptr, &colour,
                                                    Unk_GetTexture(util->field_29b08[8]), 0, 0x10000);
            }
        }
        field_18->vf44(0);
        break;
    default:
        result = -4;
        break;
    }
    return result;
}

// 0x7100430250: the colour chart's parts (0x710042f540) laid out in the
// `width` by `height` area from `x`, `y` (half size for an HDR output)
// NON_MATCHING: a draft; the calls and their arguments are the original's,
// the floating point registers and the order of the arithmetic are not yet
// (about 250 instructions).
s32 CPostEffect::Unk_430250(bool second, bool hdr, bool pq, bool flag, const Unk_42f540_Params* params, f32 x, f32 y,
                            f32 width, f32 height) {
    f32 scale = hdr ? 0.5f : 1.0f;
    f32 boxW = scale * (width * 0.45f);
    f32 boxH = scale * (height * 0.2f);
    f32 margin0 = width * 0.025f;
    f32 margin = margin0;
    f32 top;
    if (hdr) {
        top = (height - height * 0.025f) - boxH;
        margin = scale * margin;
        if (!pq) {
            y = y + scale * (height * -0.21f);
        }
    } else {
        top = height * 0.075f;
    }
    if (!pq) {
        f32 left = margin + x;
        f32 right = (width - boxW) - left;
        Unk_42f540(0, second, hdr, params, width, height, flag ? right : left, y + top, boxW, boxH, 0.0f, 0.0f, 1.0f,
                   1.0f);
        top = scale * (height * 0.21f) + top;
    }
    f32 left = margin + x;
    f32 inner = width - boxW;
    f32 right = inner - left;
    f32 line = boxH * 0.03125f;
    Unk_42f540(0, second, hdr, params, width, height, flag ? right : left, y + top, boxW, line, 0.0f, 0.0f, 1.0f,
               0.03125f);
    top = line + top;
    Unk_42f540(pq ? 2 : 1, second, hdr, params, width, height, flag ? right : left, y + top, boxW, boxH, 0.0f, 0.0f,
               1.0f, 1.0f);
    if (pq) {
        f32 size = boxW * 0.8f;
        f32 dy = hdr ? -(size * 1.05f) : boxH * 1.1f;
        f32 l = scale * margin0 + x;
        f32 r = inner - l;
        return Unk_42f540(5, second, hdr, params, width, height, flag ? r : l, y + (dy + top), boxW, size, 0.0f,
                          0.8f, 1.0f, 0.0f);
    }
    f32 sign = hdr ? -1.0f : 1.0f;
    f32 t = sign * (boxH * 1.1f) + top;
    f32 q = scale * (width * 0.25f);
    f32 q2 = q * 1.05f;
    top = hdr ? t - q2 : t;
    f32 a;
    f32 b;
    if (flag) {
        Unk_42f540(3, second, hdr, params, width, height, (width - q) - left, top + y, q, q, 0.0f, 0.0f, 1.0f, 1.0f);
        a = q * 0.25f + y;
        b = (width - q * 0.75f) - (margin + (q2 + x));
    } else {
        Unk_42f540(3, second, hdr, params, width, height, left, top + y, q, q, 0.0f, 0.0f, 1.0f, 1.0f);
        a = q * 0.25f + y;
        b = margin + (q2 + x);
    }
    return Unk_42f540(4, second, hdr, params, width, height, b, top + a, q * 0.75f, q * 0.75f, 0.0f, 0.0f, 1.0f, 1.0f);
}

// 0x71004306b0: the colour chart (0x7100430250) drawn into `surface` with
// the output's numbers, for each output
s32 CPostEffect::Unk_4306b0(void* surface, f32 a, f32 b, f32 c, s32 arg4, const Unk_Float4* color, s32 arg6,
                            const MATRIXT44* matrix, f32 d, f32 e, f32 f, f32 g) {
    f32 p2;
    f32 p0;
    f32 p1;
    if (field_96c) {
        p0 = field_980;
        p1 = field_984;
        p2 = field_988;
    } else {
        p0 = 1.0f;
        p1 = 1.0f;
        p2 = 1.0f;
    }
    MATRIXT44 conversion = field_1094;
    bool custom = field_999;
    if (custom) {
        switch (field_99c) {
        case 9:
            if (field_9a0 == 2.19921875f) {
                custom = false;
            }
            break;
        case 10:
            if (field_9a0 == 2.6f) {
                custom = false;
            }
            break;
        case 11:
        case 12:
            if (field_9a0 == 1.8f) {
                custom = false;
            }
            break;
        case 13:
            if (field_9a0 == 2.2f) {
                custom = false;
            }
            break;
        case 14:
            if (field_9a0 == 2.4f) {
                custom = false;
            }
            break;
        }
    }
    f32 q2;
    f32 q0;
    f32 q1;
    if (field_96c) {
        q0 = field_98c;
        q1 = field_bc4;
        q2 = field_bc8;
    } else {
        q0 = 0.0f;
        q1 = 0.0f;
        q2 = 0.0f;
    }
    const Unk_SurfaceSize* size = reinterpret_cast<const Unk_SurfaceSize*>(surface);
    f32 width = static_cast<f32>(size->field_4c);
    f32 height = static_cast<f32>(size->field_50);
    s32 mode = Unk_24e09bc;
    bool pq = mode == 3 || mode == 5;
    s32 space = field_96c ? field_974 : 0;
    Unk_42f540_Params params;
    params.field_0 = surface;
    params.field_8 = a;
    params.field_c = b;
    params.field_10 = c;
    bool hdr = static_cast<u32>(mode - 1) < 3;
    params.field_14 = arg4;
    params.field_18 = *color;
    params.field_28 = arg6;
    params.field_2c = space;
    params.field_30 = conversion;
    params.field_70 = *matrix;
    params.field_b0 = p0;
    params.field_b4 = p1;
    params.field_b8 = 100.0f;
    params.field_bc = q0;
    params.field_c0 = q1;
    params.field_c4 = q2;
    params.field_c8 = custom;
    params.field_cc = d;
    params.field_d0 = e;
    params.field_d4 = f;
    params.field_d8 = g;
    params.field_dc = p2;
    if (!(field_96c && field_974 == 1)) {
        Unk_430250(false, hdr, pq, false, &params, 0.0f, 0.0f, width, height);
        if (mode == 1) {
            Unk_430250(false, hdr, true, false, &params, width * 0.25f, 0.0f, width, height);
        }
    }
    if (field_96c) {
        s32 second = field_974;
        if (second != 0) {
            Unk_430250(true, hdr, pq, second != 1, &params, 0.0f, 0.0f, width, height);
            if (mode == 1) {
                Unk_430250(true, hdr, true, second != 1, &params, width * 0.25f, 0.0f, width, height);
            }
        }
    }
    return 0;
}

// a PQ (SMPTE ST 2084) code value's linear light, 1 being 10000 nits (inline)
static inline f32 Unk_PqEotf(f32 value) {
    value = value < 0.0f ? 0.0f : std::min(value, 1.0f);
    f32 numerator = std::max(powf(value, 0.012683313f) + -0.8359375f, 0.0f);
    f32 denominator = 18.8515625f - powf(value, 0.012683313f) * 18.6875f;
    return powf(numerator / denominator, 6.2773948f);
}

// 0x7100430a10: `source` through the output's transfer function into
// `surface` (as the device's only target when `target` is given, with four
// jittered taps when it is resized), with the luminances the output is mapped
// for (measured by field_588's luminance when field_990 is negative), the scale
// bar and the colour chart (`arg4` isn't used)
// NON_MATCHING: a draft (4388 bytes, not 4396): the calls and their arguments
// are the original's; the blocks are placed in another order (the original
// has the luminance's resize loop and its first frame after the colour
// chart's test, before the measurement), and the registers and spill slots
// differ throughout.
s32 CPostEffect::Unk_430a10(Unk_RenderTexture* source_, void* target, void* surface, bool arg4) {
    extern Unk_DeviceSettings Unk_24e1500;
    CRenderTexture* source = reinterpret_cast<CRenderTexture*>(source_);
    CTextureUtil* util = Unk_TextureUtil();
    s32 mode = Unk_24e09bc;
    f32 p0;
    f32 p1;
    f32 p2;
    s32 eotf;
    if (field_96c) {
        p0 = field_980;
        p1 = field_984;
        p2 = field_988;
        eotf = field_978;
    } else {
        eotf = 13;
        p1 = 1.0f;
        p0 = 1.0f;
        p2 = 1.0f;
    }
    bool chart = mode != 0 && eotf != 15;
    s32 format;
    f32 scale;
    f32 scale2;
    f32 dither;
    bool hasGamma;
    f32 gamma;
    MATRIXT44* first;
    MATRIXT44* second;
    Unk_42df80(&format, &scale, &scale2, &dither, &hasGamma, &gamma, &first, &second, false, true);
    gamma = hasGamma ? 1.0f / gamma : 1.0f;
    Unk_Float4 color(field_8e8, 0.0f, 0.0f, 0.0f);
    MATRIXT44 m;
    Unk_Identity(&m);
    bool any = false;
    if (second != nullptr) {
        MATRIXT44_MatrixMultiply(&m, &m, second);
        any = true;
    }
    if (first != nullptr) {
        MATRIXT44_MatrixMultiply(&m, &m, first);
        any = true;
    }
    MATRIXT44 inverse;
    Unk_Identity(&inverse);
    if (any) {
        MATRIXT44 result;
        Unk_4155f0(&result, &m);
        inverse = result;
    }
    MATRIXT44 conversion = field_1094;
    Unk_CopiedColorSpace space;
    space = field_ba4;
    f32 q0 = field_96c ? field_98c : 0.0f;
    f32 white = field_990;
    f32 exposure = field_994;
    bool fixed = field_998;
    CTextureLuminanceManage* luminance = Unk_Luminance588();
    f32 peak = luminance == nullptr && white < 0.0f ? 100.0f : white;
    f32 low = 0.0f;
    f32 mapped;
    if (peak < 0.0f) {
        if (Unk_24e1500.field_10 >= 2 && field_18->field_28 % Unk_24e1500.field_10 != 0) {
            exposure = 0.18f;
            mapped = 100.0f;
            low = 0.0f;
        } else {
            luminance->field_4f8 = 0;
            luminance->Unk_4b8b50();
            if (field_590 != 0 && luminance->Unk_4b89b0() >= 0) {
                s32 count = field_580;
                CRenderTexture* prev = Unk_OetfBase();
                CRenderTexture* next = prev;
                bool done = false;
                for (s32 i = 0; i < count; i++) {
                    u32 width = prev->field_54;
                    next = field_578 != nullptr ? field_578[i] : nullptr;
                    if (width >= 1024) {
                        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
                        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                        util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, prev, next, 0, &ones, 0, false, false, 1, &zero,
                                         nullptr, -1);
                    } else {
                        util->Unk_481540(prev, next, !(done || width > 1023), false);
                    }
                    done = done || width < 1024;
                    prev = next;
                }
                util->Unk_481540(next, luminance->field_48, false, true);
                luminance->Unk_4b8a40(false, 1.0f, 1.0f, 0.0f, 0.0f);
                field_590 = 0;
            } else {
                if (field_590 == 0) {
                    Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
                    Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                    util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, source, Unk_OetfBase(), 0, &ones, 0, false, false, 1,
                                     &zero, nullptr, 1);
                }
                field_590++;
            }
            if (target == nullptr) {
                Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            }
            const f32* measured =
                reinterpret_cast<const f32*>(Unk_4b9210_get(reinterpret_cast<const Unk_4b9210*>(luminance)));
            mapped = Unk_PqEotf(measured[0]) * 3000.0f;
            low = Unk_PqEotf(measured[1]);
            exposure = Unk_PqEotf(measured[2]) * 100.0f;
        }
        peak = mapped * (mapped / Unk_42f320(mapped, second, format));
    } else {
        mapped = peak;
        if (!fixed) {
            mapped = Unk_42f320(peak, second, format);
        }
        if (exposure < 0.0f) {
            Unk_429da0_Item* item = &field_2a0[field_298];
            if (item->field_0) {
                f32 value;
                if (item->field_24 > 0.0f) {
                    value = item->field_24;
                } else if (item->field_70 == nullptr) {
                    value = 0.0f;
                } else {
                    value = item->field_5c;
                }
                exposure = value * field_8c0.field_0;
            }
        }
    }
    if (chart) {
        Unk_431b40();
        if (target == nullptr) {
            Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        }
    }
    f32 q1;
    f32 q2;
    if (field_96c) {
        q1 = field_bc4;
        q2 = field_bc8;
    } else {
        q1 = 0.0f;
        q2 = 0.0f;
    }
    bool custom = field_999;
    if (custom) {
        switch (field_99c) {
        case 9:
            if (field_9a0 == 2.19921875f) {
                custom = false;
            }
            break;
        case 10:
            if (field_9a0 == 2.6f) {
                custom = false;
            }
            break;
        case 11:
        case 12:
            if (field_9a0 == 1.8f) {
                custom = false;
            }
            break;
        case 13:
            if (field_9a0 == 2.2f) {
                custom = false;
            }
            break;
        case 14:
            if (field_9a0 == 2.4f) {
                custom = false;
            }
            break;
        }
    }
    if (Unk_238c2e0 != 0 && Unk_IsScaleBarMode(Unk_24e09bc) &&
        Unk_482380_get(reinterpret_cast<const Unk_482380*>(util))) {
        CRenderTexture* bar = util->field_29b08[9];
        Unk_49b230_Object* barSurface = bar->field_b8[bar->field_a0];
        s32 status = bar->Unk_49d250(0, 0, 1, 0, 0);
        if (status < 0) {
            return status;
        }
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        const Unk_SurfaceSize* barSize = reinterpret_cast<const Unk_SurfaceSize*>(barSurface);
        f32 u1 = source->field_88 * static_cast<f32>(static_cast<u32>(source->field_54)) + source->field_90;
        f32 v1 = source->field_8c * static_cast<f32>(static_cast<u32>(source->field_58)) + source->field_94;
        f32 barWidth = static_cast<f32>(barSize->field_4c);
        f32 barHeight = static_cast<f32>(barSize->field_50);
        util->DrawRectGPU_OptoElectronicTransfer(
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, u1, v1, 1, nullptr, Unk_GetTexture(source), barSurface, eotf, 0,
            format, field_9a8, scale, scale2, &conversion, &inverse, &space, p0, p1, p2, gamma, field_968, q1, q2,
            custom, field_99c, field_9a0, field_9a4, &color, field_96c ? field_974 : 0, q0, exposure, mapped, nullptr,
            false, true, false, 0.0f, 0, false);
        f32 x0;
        f32 y0;
        f32 x1;
        f32 y1;
        util->Unk_47e000(reinterpret_cast<s32*>(&x0), reinterpret_cast<s32*>(&y0), reinterpret_cast<s32*>(&x1),
                         reinterpret_cast<s32*>(&y1));
        util->DrawRectGPU_OptoElectronicTransfer(
            0.0f, 0.0f, barWidth, barHeight, 0.0f, 0.0f, u1, v1, 1, nullptr, Unk_GetTexture(source), barSurface, 5, 0,
            format, field_9a8, scale, scale2, &conversion, &inverse, &space, p0, y0, 1.0f, gamma, field_968, q1, q2,
            custom, field_99c, field_9a0, field_9a4, &color, field_96c ? field_974 : 0, q0, exposure, mapped, nullptr,
            false, true, false, 0.0f, 0, false);
        CRenderTexture* scaleBar = util->field_29b08[8];
        Unk_49b230_Object* scaleSurface = scaleBar->field_b8[scaleBar->field_a0];
        status = scaleBar->Unk_49d250(0, 0, 1, 0, 0);
        if (status < 0) {
            return status;
        }
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        f32 clear[4] = {};
        field_18->vf51(0xff0, clear, 1.0f, 0);
        const Unk_SurfaceSize* scaleSize = reinterpret_cast<const Unk_SurfaceSize*>(scaleSurface);
        util->Unk_481180(0.0f, 0.0f, static_cast<f32>(scaleSize->field_4c), static_cast<f32>(scaleSize->field_50), 0.0f,
                         0.0f, bar->field_88 * static_cast<f32>(static_cast<u32>(bar->field_54)) + bar->field_90,
                         bar->field_8c * static_cast<f32>(static_cast<u32>(bar->field_58)) + bar->field_94, 4.0f,
                         -1.0f, 0.8f, Unk_GetTexture(bar), Unk_238c2e0 == 2 && Unk_IsScaleBarMode(Unk_24e09bc), 0);
        if (target == nullptr) {
            Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        }
    }
    const Unk_SurfaceSize* size = reinterpret_cast<const Unk_SurfaceSize*>(surface);
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    s32 count = field_f30;
    if (count == -1) {
        count = field_f2c;
    }
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 width = static_cast<f32>(size->field_4c);
    f32 height = static_cast<f32>(size->field_50);
    f32 sharpness = field_f34 > 0.0f ? field_f34 : -field_f34;
    bool jitter = (sourceWidth != width || sourceHeight != height) && count == 1;
    s32 taps = jitter ? 4 : 1;
    Unk_Float4 offsets[4];
    if (jitter) {
        f32 k = fminf(sharpness, 1.0f) * 0.5f;
        f32 dx = u1 / sourceWidth * k;
        f32 dy = v1 / sourceHeight * k;
        offsets[0] = Unk_Float4(-dx, -dy, 0.0f, 0.0f);
        offsets[1] = Unk_Float4(dx, -dy, 0.0f, 0.0f);
        offsets[2] = Unk_Float4(-dx, dy, 0.0f, 0.0f);
        offsets[3] = Unk_Float4(dx, dy, 0.0f, 0.0f);
    } else {
        offsets[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (target != nullptr) {
        Unk_SetTarget(static_cast<CRenderTexture*>(target));
    }
    s32 backend = Unk_BackendColorSpaceMode();
    s32 result = util->DrawRectGPU_OptoElectronicTransfer(
        0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, taps, offsets, Unk_GetTexture(source), surface, eotf, backend,
        format, field_9a8, scale, scale2, &conversion, &inverse, &space, p0, p1, p2, gamma, field_968, q1, q2, custom,
        field_99c, field_9a0, field_9a4, &color, field_96c ? field_974 : 0, q0, exposure, mapped, nullptr, false, true,
        false, 0.0f, 0, false);
    util->Unk_47e000(reinterpret_cast<s32*>(&field_1130_0), reinterpret_cast<s32*>(&field_1134),
                     reinterpret_cast<s32*>(&field_1138), reinterpret_cast<s32*>(&field_113c));
    field_1140 = field_1130_0 * 100.0f;
    field_1144 = field_1134 * 100.0f;
    field_1148 = field_1138 * 100.0f;
    field_114c = mapped;
    field_1150 = low;
    field_1154 = exposure;
    field_1158 = p0 * mapped * 100.0f;
    field_115c = p0 * low * 100.0f;
    *reinterpret_cast<f32*>(&field_1160) = p0 * exposure * 100.0f;
    if (chart) {
        Unk_4306b0(surface, scale, scale2, gamma, format, &color, eotf, &inverse, low, mapped, exposure, peak);
        return 0;
    }
    return result;
}


// 0x7100431b40: the colour chart's look-up textures for the output's colour
// spaces, drawn again when they or field_bc4 and field_bc8 changed (what they
// were drawn for is kept in field_10e4); 1 without an HDR output
// NON_MATCHING: the original copies the colour spaces into the state through
// a temporary (stores to it that nothing reads; a temporary or a local copy in
// the source is removed here) and gives gamma's 1 a block of its own (here
// materialised before the test). `hdr` is computed before the PQ test (the
// original keeps `mode - 1`).
s32 CPostEffect::Unk_431b40() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (Unk_24e09bc == 0) {
        return 1;
    }
    util->Unk_46ec80(Unk_TextureAt(field_5d8)->field_30, Unk_TextureAt(field_5d8)->field_34);
    MATRIXT44 conversion;
    {
        MATRIXT44 m2;
        MATRIXT44 m;
        Unk_Identity(&m);
        MATRIXT44_MatrixMultiply(&m, &m, &field_b3c);
        MATRIXT44_MatrixMultiply(&m2, &m, &field_9b4[1]);
        MATRIXT44_MatrixMultiply(&conversion, &m2, &field_9b4[0]);
    }
    f32 gamma;
    if (field_97c != 0 || field_8c4.field_0 <= 0.0f) {
        gamma = 1.0f;
    } else {
        gamma = 2.2f / field_8c4.field_0;
    }
    f32 high = field_1138;
    f32 limit = field_113c;
    s32 mode = Unk_24e09bc;
    bool pq = mode == 1 || mode == 3 || mode == 5;
    bool hdr = static_cast<u32>(mode - 1) < 3;
    if (mode == 1 || mode == 3 || mode == 5) {
        util->Unk_480740(util->field_29b08[3], true, true, &conversion, false, 0, gamma, 4.0f, -1.0f, 0.0f);
    }
    f32 range = pq ? 4.0f : 4.5f;
    f32 low = pq ? -1.0f : -2.0f;
    {
        MATRIXT44 identity;
        Unk_Identity(&identity);
        util->Unk_480740(hdr ? util->field_29b08[1] : util->field_29b00, false, true, &identity, false, 0, 1.0f, range,
                         low, limit);
    }
    s32 result = util->Unk_480740(hdr ? util->field_29b08[2] : util->field_29b08[0], false, true, &conversion, false,
                                  0, gamma, range, low, high);
    struct {
        Unk_410f90 field_0;
        Unk_410f90 field_20;
        f32 field_40;
        f32 field_44;
        f32 field_48;
    } state;
    state.field_0 = field_ba4;
    state.field_20 = field_b84;
    if (field_96c) {
        state.field_40 = field_bc4;
        state.field_44 = field_bc8;
    } else {
        state.field_40 = 0.0f;
        state.field_44 = 0.0f;
    }
    state.field_48 = 1.0f;
    if (memcmp(field_10e4, &state, sizeof(state)) != 0) {
        Unk_Float2 scale(1.0f, 1.0f);
        {
            Unk_Float2 zero(0.0f, 0.0f);
            util->Unk_481000(util->field_29b08[6], false, &zero, &scale, 1.0f, state.field_40, state.field_44,
                             &state.field_0, true, true, &state.field_20, false, 0);
        }
        {
            Unk_Float2 zero(0.0f, 0.0f);
            util->Unk_481000(util->field_29b08[7], false, &zero, &scale, state.field_48, state.field_40,
                             state.field_44, &state.field_20, true, true, &state.field_20, false, 0);
        }
        scale = Unk_Float2(0.75f, 0.75f);
        {
            Unk_Float2 zero(0.0f, 0.0f);
            util->Unk_481000(util->field_29b08[4], true, &zero, &scale, state.field_48, state.field_40,
                             state.field_44, &state.field_0, true, true, &state.field_20, false, 0);
        }
        {
            Unk_Float2 zero(0.0f, 0.0f);
            result = util->Unk_481000(util->field_29b08[5], true, &zero, &scale, state.field_48, state.field_40,
                                      state.field_44, &state.field_20, true, true, &state.field_20, false, 0);
        }
        memcpy(field_10e4, &state, sizeof(state));
    }
    return result;
}

// 0x71004320b0: Unk_48cc30 from `source` and field_1f0 to field_218 (the
// output `target`, else texture field_5f8) with the camera's planes
// NON_MATCHING: register allocation and the scheduling of the parameters'
// loads and spills: about 40 instructions (the projection through the inline
// Unk_Perspective took 7 off). The far plane's last minimum is
// Unk_427ad0's `&` of the two comparisons (one fccmp, as in the original);
// the order of the parameters' reads (depth's flag first) is the closest
// one a greedy search of single moves found (85 to 48 differing).
s32 CPostEffect::Unk_4320b0(Unk_RenderTexture* source, Unk_RenderTexture* target, bool flag, bool force) {
    if (!force && !field_10de) {
        return 0;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_RenderTexture* temp = field_1f0;
    Unk_RenderTexture* copy = field_1f8;
    Unk_RenderTexture* blur0 = field_200;
    Unk_RenderTexture* blur1 = field_208;
    Unk_RenderTexture* composite = field_210;
    Unk_RenderTexture* other = field_218;
    Unk_RenderTexture* output = target != nullptr ? nullptr : Unk_TextureAt(field_5f8);
    MATRIXT44 projection;
    Unk_Perspective(&projection, field_6c4, field_6c8, field_6d0, field_420, field_6d4, field_6d8);
    bool depth = field_10df;
    f32 a0 = field_ec0;
    f32 a3 = field_ecc;
    f32 a4 = field_ed0;
    f32 a5 = field_ed4;
    f32 a6 = field_ed8;
    f32 a1 = field_ec4;
    f32 a2 = field_ec8;
    f32 sigma = field_f00;
    f32 blur2 = field_ef8;
    f32 blur3 = field_efc;
    s32 count = field_ebc;
    if (sigma <= 0.0f) {
        u32 width = field_30->field_8;
        if (field_410 != 0) {
            width = field_410;
        }
        sigma = static_cast<f32>(blur1->field_54) / static_cast<f32>(width) * 4.0f * 2.0f;
    }
    s32 blurCount = field_f04;
    Unk_4320b0_Vector v0 = field_edc_v;
    s32 mode = Unk_E88();
    CRenderTexture* source3 = Unk_E90();
    Unk_4320b0_Vector v1 = Unk_E98();
    Unk_4320b0_Vector v2 = field_ea8_v;
    s32 kind = flag ? 4 : 0;
    f32 low = field_8f4;
    f32 x = field_90c;
    if (x > 0.0f) {
        f32 high = field_8f8;
        low = x < low ? low : (x > high ? high : x);
        f32 y = field_910;
        if (y > 0.0f) {
            low = Unk_Less(low, y);
        }
    }
    f32 current = field_6c4;
    f32 before = field_ef0;
    f32 now = field_eec;
    if (Unk_4622e0(current, field_6c8, now, before)) {
        f32 next = now > before ? before : current;
        current = Unk_Greater(next, current);
    }
    f32 nearPlane = low > current ? low : current;
    f32 high = field_8f8;
    f32 y = field_910;
    if (y > 0.0f) {
        f32 low2 = field_8f4;
        high = y < low2 ? low2 : (y > high ? high : y);
        f32 x2 = field_90c;
        if (x2 > 0.0f) {
            high = Unk_Greater(high, x2);
        }
    }
    current = field_6c8;
    before = field_ef0;
    now = field_eec;
    if (Unk_4622e0(field_6c4, current, now, before)) {
        f32 next = now < before ? before : current;
        if ((now < before) & (next < current)) {
            current = before;
        }
    }
    f32 farPlane = high < current ? high : current;
    f32 fade[2];
    const f32* range = nullptr;
    if (field_eb8 && Unk_4622e0(field_6c4, field_6c8, field_eec, field_ef0)) {
        f32 k = 1.0f / (field_eec - field_ef0);
        fade[1] = 0.0f - field_ef0 * k;
        fade[0] = k;
        range = fade;
    }
    s32 linear = field_ef4 == -2 ? 1 : field_ef4;
    util->Unk_48cc30(field_6c4, field_6c8, field_6d0, a0, a1, a2, a3, a4, Unk_AsTexture(temp), Unk_AsTexture(copy),
                     Unk_AsTexture(blur0), Unk_AsTexture(blur1), Unk_AsTexture(composite), Unk_AsTexture(other),
                     Unk_AsTexture(output), reinterpret_cast<Unk_GPUTexture*>(target), &projection, count, a5, a6,
                     Unk_Frame(field_298), depth, range, nearPlane, farPlane, kind, Unk_AsTexture(source), blurCount,
                     sigma, blur2, blur3, reinterpret_cast<const Unk_Vector3*>(&v0), mode, source3,
                     reinterpret_cast<const Unk_Vector3*>(&v1), reinterpret_cast<const Unk_Vector3*>(&v2), linear,
                     false);
    return 0;
}

// 0x7100432570: the view's adaptation (Unk_48fb40 from texture field_5fc to
// texture field_600 with field_238's texture of the view), then its numbers
// moved on a frame
// NON_MATCHING: the original keeps Unk_CheckDepthCastType's switch as a jump
// table whose four entries all go to the join (here a select, as in
// 0x710042be10), spills the texture util where this keeps it, and schedules
// |field_d64|'s minimum next to the call: about 120 instructions.
s32 CPostEffect::Unk_432570() {
    if (!field_10df) {
        return 0;
    }
    s32 view = field_298;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    s32 active = field_298;
    Unk_RenderTexture* work = field_238[active];
    Unk_RenderTexture* source = Unk_TextureAt(field_5fc);
    Unk_RenderTexture* target = Unk_TextureAt(field_600);
    s32 mode = field_f0c;
    Unk_RenderTexture* history = static_cast<u32>(mode - 1) < 2 ? field_d70 : nullptr;
    f32 speed = field_f28;
    f32 exposure = field_8c0.field_0;
    f32 luminance = Unk_SceneLuminance(this);
    s32 depthSource = field_58;
    Unk_RenderTexture* external = field_50;
    bool own = depthSource == 8 || external != nullptr;
    Unk_RenderTexture* depth;
    s32 type;
    if (depthSource == 8) {
        type = FXDCT_GetDepthCastTypeFromDepthFormat(depth->field_38);
        depth = field_190->field_80[static_cast<s32>(field_190->field_94)];
    } else {
        depth = own ? external : Unk_TextureAt(field_5e0);
        if (Unk_IsDepthFormat(depth->field_38)) {
            type = FXDCT_GetDepthCastTypeFromDepthFormat(depth->field_38);
        } else {
            type = Unk_CheckDepthCastType(Unk_DepthCastType(own ? depthSource : 3));
        }
    }
    f32 ratio = exposure / luminance;
    Unk_Rect depthScale;
    depthScale.field_0 = 1.0f;
    depthScale.field_4 = 0.0f;
    depthScale.field_8 = 1.0f;
    depthScale.field_c = 0.0f;
    Unk_Rect viewScale;
    viewScale.field_0 = 1.0f;
    viewScale.field_4 = 0.0f;
    viewScale.field_8 = 1.0f;
    viewScale.field_c = 0.0f;
    if (mode == 2) {
        f32 scale;
        f32 bias;
        if (field_50 != nullptr) {
            scale = field_60;
            bias = field_64;
        } else {
            bias = 0.0f;
            scale = 1.0f;
        }
        s32 from;
        if (depthSource == 8) {
            if (field_1014) {
                scale = -1.0f;
                bias = 1.0f;
            }
            from = 0;
        } else {
            bias = own ? bias : 0.0f;
            scale = own ? scale : 1.0f;
            from = own ? 6 : 2;
        }
        depthScale = Unk_DepthFactors(from, 0, scale, bias);
        viewScale = field_258[view];
        if (viewScale.field_0 == 0.0f) {
            viewScale = Unk_DepthFactors(2, 0, 1.0f, 0.0f);
        }
    }
    f32 x = field_d64.field_0[0].field_0;
    f32 y = field_d64.field_0[1].field_0;
    f32 size = x < y ? x : y;
    x = x > 0.0f ? x : -x;
    y = y > 0.0f ? y : -y;
    size = field_f1c < size ? field_f1c : size;
    f32 low = field_240[view];
    f32 high = field_248[view];
    f32 width = field_f20;
    f32 height = field_f24;
    {
        Unk_Float4 colour(1.0f, 1.0f, 1.0f, 0.0f);
        Unk_Float4 colour2(1.0f, 1.0f, 1.0f, 0.0f);
        util->Unk_48fb40(ratio, speed, field_6c4, field_6c8, size, low, high, width * 0.5f, Unk_AsTexture(target),
                         Unk_AsTexture(source), Unk_AsTexture(history), Unk_AsTexture(work),
                         Unk_AsTexture(own ? depth : nullptr), mode == 2, field_d6c, &field_d64, type,
                         reinterpret_cast<const Unk_Float2*>(&depthScale), reinterpret_cast<const Unk_Float2*>(&viewScale),
                         width, height * 0.5f, height, field_7f8 / field_250[view], &colour, &colour2, false);
    }
    {
        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, target, Unk_AsTexture(work), 0, &ones, 0, false, false, 1, &zero,
                         nullptr, -1);
    }
    if (field_f10) {
        Unk_Float4 colour(0.1f, 1.0f, 0.1f, 0.0f);
        Unk_Float4 colour2(1.0f, 0.1f, 1.0f, 0.0f);
        util->Unk_48fb40(ratio, speed, field_6c4, field_6c8, size, low, high, width * 0.5f, Unk_AsTexture(target),
                         Unk_AsTexture(source), Unk_AsTexture(history), Unk_AsTexture(work),
                         Unk_AsTexture(own ? depth : nullptr), mode == 2, field_d6c, &field_d64, type,
                         reinterpret_cast<const Unk_Float2*>(&depthScale), reinterpret_cast<const Unk_Float2*>(&viewScale),
                         width, height * 0.5f, height, field_7f8 / field_250[view], &colour, &colour2, false);
    }
    f32 next = 1.0f / (1.0f / field_240[view] + 1.0f);
    field_240[view] = std::max(field_f14, next);
    f32 most = field_f18;
    if (!(most > 0.0f && most <= 1.0f)) {
        most = powf(field_f14, 0.7f);
    }
    f32 next2 = 1.0f / (1.0f / field_248[view] + 1.0f);
    field_248[view] = std::max(most, next2);
    field_250[view] = field_7f8;
    field_258[view] = Unk_DepthFactors(2, 0, 1.0f, 0.0f);
    return 0;
}

// 0x7100433450: the motion blur of field_618's texture into field_620's, in
// field_1078's way (2: from the velocity, made first when it has to be)
// NON_MATCHING: a draft (about 230 of 554 instructions differ; the projections
// go through the inline Unk_Perspective): the velocity mode's
// depth selection and stack slots differ, and the recurrences' minimum is a
// select here where the original keeps GetMaxMotionBlurCameraRecurrences's
// branches; CTextureUtil::Unk_4845c0 is given the range through a cast (its
// parameter is probably a const Unk_Float2*)
s32 CPostEffect::Unk_433450() {
    if (!field_1075) {
        return 0;
    }
    CTextureUtil* util = Unk_TextureUtil();
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
    MATRIXT44 projection;
    {
        Unk_Perspective(&projection, field_6c4, field_6c8, field_6d0, field_420, field_6d4, field_6d8);
    }
    MATRIXT44 previous;
    {
        Unk_Perspective(&previous, field_6c4, field_6c8, field_6e8, field_420, field_6ec, field_6f0);
    }
    f32 x = field_cf0.field_0;
    f32 y = field_cf4.field_0;
    u32 count = field_cfc;
    u32 recurrences = GetMaxMotionBlurCameraRecurrences();
    if (count > recurrences) {
        count = recurrences;
    }
    f32 ratio = field_d00.field_0;
    Unk_RenderTexture* source = Unk_TextureAt(field_618);
    Unk_RenderTexture* target = Unk_TextureAt(field_620);
    Unk_RenderTexture* temp = Unk_TextureAt(field_61c);
    bool inside = false;
    const Unk_Float2* range = nullptr;
    if (field_ce5 && static_cast<u32>(field_ce8 - 1) < 2) {
        inside = Unk_4622e0(field_6c4, field_6c8, field_d10, field_d14);
        range = inside ? &field_1084 : nullptr;
    }
    switch (field_1078) {
    case 0: {
        Unk_Float2 ones(1.0f, 1.0f);
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        util->Unk_482f10(x, y, Unk_AsTexture(source), target, temp, &field_6f4, &field_774, &projection, count,
                         ratio, &ones, 0, &color, false);
        break;
    }
    case 1: {
        Unk_Float2 ones(1.0f, 1.0f);
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        util->Unk_4845c0(x, y, ratio, Unk_AsTexture(source), Unk_AsTexture(target), Unk_AsTexture(temp),
                         &field_6f4, &field_774, &projection, &previous, reinterpret_cast<const f32*>(range), count,
                         &ones, 0, &color, false);
        break;
    }
    case 2: {
        Unk_42be10();
        Unk_RenderTexture* external = field_50;
        s32 kind = field_58;
        bool own = kind == 8 || external != nullptr;
        bool device = false;
        Unk_RenderTexture* depth;
        if (kind == 8) {
            depth = field_190->field_80[static_cast<s32>(field_190->field_94)];
            device = Unk_AsTexture(depth)->Unk_Root()->field_a8->field_54 == 0;
            own = own && device;
            depth = device ? depth : source;
        } else {
            depth = own ? external : Unk_TextureAt(field_5e0);
        }
        f32 scale;
        f32 bias;
        if (field_50 != nullptr) {
            scale = field_60;
            bias = field_64;
        } else {
            scale = 1.0f;
            bias = 0.0f;
        }
        s32 from;
        if (device) {
            bias = field_1014 ? 1.0f : bias;
            scale = field_1014 ? -1.0f : scale;
            from = 0;
        } else {
            bias = own ? bias : 0.0f;
            scale = own ? scale : 1.0f;
            from = own ? 6 : 2;
        }
        f32 factors[4];
        Unk_428cc0(factors, from, 0, scale, bias);
        Unk_Float2 depthScale(factors[0], factors[1]);
        Unk_428cc0(factors, 0, 2, 1.0f, 0.0f);
        Unk_Float2 linear(factors[0], factors[1]);
        s32 type;
        if (device || Unk_IsDepthFormat(depth->field_38)) {
            type = FXDCT_GetDepthCastTypeFromDepthFormat(depth->field_38);
        } else {
            type = Unk_CheckDepthCastType(Unk_DepthCastType(own ? field_58 : 3));
        }
        bool generate = true;
        s32 mode;
        if (field_d2c == 0) {
            mode = -2;
        } else {
            if (field_d2c != 1) {
                generate = false;
            }
            mode = field_d30;
        }
        Unk_Float2 falloff(1.0f, 0.0f);
        if (own && inside) {
            Unk_428cc0(factors, 0, 2, 1.0f, 0.0f);
            f32 a = depthScale.field_0[1].field_0 * factors[0] + factors[1];
            f32 b = depthScale.field_0[0].field_0 * factors[0];
            falloff.field_0[0] = b * range->field_0[0].field_0;
            falloff.field_0[1] = a * range->field_0[0].field_0 + range->field_0[1].field_0;
            range = &falloff;
        }
        Unk_Float2 size(field_d24, field_d28);
        bool reduce = field_d40;
        Unk_RenderTexture* velocity = field_d70;
        Unk_RenderTexture* reduced = field_d78;
        Unk_Float2 offset = field_d64;
        if (!field_10db && generate) {
            util->Unk_484f50(field_108c, Unk_AsTexture(depth), Unk_AsTexture(velocity), Unk_AsTexture(reduced),
                             &field_6f4, &field_774, &projection, &previous, type, &depthScale, range, mode, &offset,
                             false, &field_d6c);
            field_10db = true;
        }
        if (field_10db) {
            reduced = nullptr;
            reduce = false;
            offset = field_d64;
        }
        Unk_Float2 ones(1.0f, 1.0f);
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        util->Unk_485610(x, y, field_d20, field_d04, ratio, Unk_AsTexture(source), Unk_AsTexture(target),
                         Unk_AsTexture(temp), reinterpret_cast<CRenderTextureArray*>(field_1e8),
                         Unk_AsTexture(velocity), Unk_AsTexture(reduced),
                         reinterpret_cast<CRenderTextureArray*>(field_1e0), &field_d48, &field_d50, false,
                         &field_6f4, &field_774, &projection, &previous, Unk_AsTexture(depth), type, &depthScale,
                         &linear, range, mode, &offset, field_d60 != 1, reduce, &size, count, &ones, 0, &color,
                         false);
        field_10db = true;
        break;
    }
    }
    return 0;
}

// 0x7100433d00: `source` tone mapped into the history texture (or into
// field_670's texture, then copied into it)
// NON_MATCHING: register allocation only (s10 to s13, x21/x22) and the
// colour's stores, which come before `space`'s test here (after the aspect's
// division in the original). With the colour read after `space`, as the
// original's order suggests, `space` takes the register of field_96c's test
// and its `mov w9, wzr` block goes (8 bytes shorter); read before it, the
// diamond is the original's.
s32 CPostEffect::Unk_433d00(Unk_RenderTexture* source) {
    field_10e1 = false;
    s32 format;
    f32 scale;
    f32 scale2;
    f32 dither;
    bool hasGamma;
    f32 gamma;
    MATRIXT44* matrix;
    MATRIXT44* matrix2;
    Unk_42df80(&format, &scale, &scale2, &dither, &hasGamma, &gamma, &matrix, &matrix2, false, false);
    f32 width = field_420;
    f32 height = field_424;
    f32 edgeX = field_bf4;
    f32 edgeY = field_bf8;
    if (!field_bec) {
        edgeX = 0.0f;
        edgeY = 0.0f;
    }
    f32 a = field_bfc;
    f32 b = field_c00;
    f32 c = field_bf0;
    f32 step = field_968;
    s32 fmt = format;
    bool flag = field_67b;
    Unk_RenderTexture* history = Unk_428f00();
    Unk_RenderTexture* target;
    if ((!Unk_IsHdrOutput() || Unk_IsHdrDirect())) {
        target = history;
    } else {
        target = Unk_428f00_Previous(field_190);
        Unk_49ad30(reinterpret_cast<CRenderTexture*>(target), 0, 0, 0, 0);
    }
    f32 w = static_cast<f32>(target->field_54);
    f32 h = static_cast<f32>(target->field_58);
    Unk_SetTarget(Unk_AsTexture(target));
    Unk_Float4 colour(field_8e8, field_8e8, field_8e8, field_8e8);
    s32 space = field_96c ? field_974 : 0;
    IGPUSurface* surface =
        reinterpret_cast<IGPUSurface*>(Unk_AsTexture(target)->field_b8[Unk_AsTexture(target)->field_a0]);
    f32 aspect = width / height;
    reinterpret_cast<CRenderGlare*>(field_198)->TonemapToSurface(
        surface, false,
        Unk_AsTexture(source), hasGamma, fmt, &colour, matrix, w, h, 0.0f, 0.0f, dither, gamma, scale, scale2, step,
        matrix2, field_8c0.field_0 / Unk_SceneLuminance(this), &field_8d4, field_8e4, edgeX, edgeY, a, b, c,
        aspect, !flag, nullptr, space, 0, -1, 0.6f, nullptr);
    if (!(!Unk_IsHdrOutput() || Unk_IsHdrDirect())) {
        Unk_430a10(target, history, Unk_AsTexture(history)->field_b8[Unk_AsTexture(history)->field_a0], false);
        Unk_426a50();
    }
    field_10e1 = true;
    return 0;
}

// 0x7100434000: `source` tone mapped into the feedback's tone map texture (or
// field_670's one, then copied into it), then the feedback blended from it
// NON_MATCHING: register allocation only (x21/x22 zeroed in the other order,
// the TonemapToSurface argument stores scheduled differently). The colour is
// read before `space` (as in Unk_433d00: otherwise `space` takes field_96c's
// register and its `mov w9, wzr` block goes) in a scope of its own, which
// keeps the original's frame.
s32 CPostEffect::Unk_434000(Unk_RenderTexture* source) {
    field_10e1 = false;
    Unk_RenderTexture* history = field_268;
    if (history == nullptr) {
        history = Unk_FeedbackTexture();
    }
    Unk_RenderTexture* previous = nullptr;
    Unk_RenderTexture* current = nullptr;
    if (field_260 != nullptr) {
        s32 view = field_298;
        Unk_4a5d10_Self* textures = field_260[view];
        s32 index = field_290[view] & 1;
        current = index < textures->field_30 ? textures->field_38[index] : nullptr;
        index ^= 1;
        previous = index < textures->field_30 ? textures->field_38[index] : nullptr;
    }
    s32 format;
    f32 scale;
    f32 scale2;
    f32 dither;
    bool hasGamma;
    f32 gamma;
    MATRIXT44* matrix;
    MATRIXT44* matrix2;
    Unk_42df80(&format, &scale, &scale2, &dither, &hasGamma, &gamma, &matrix, &matrix2, false, false);
    s32 fmt = format;
    Unk_RenderTexture* target;
    if (!Unk_IsHdrOutput() || Unk_IsHdrDirect()) {
        target = history;
    } else {
        target = Unk_428f00_Previous(field_190);
        Unk_49ad30(reinterpret_cast<CRenderTexture*>(target), 0, 0, 0, 0);
    }
    f32 h = static_cast<f32>(target->field_58);
    f32 w = static_cast<f32>(target->field_54);
    f32 edgeX = field_bf4;
    f32 edgeY = field_bf8;
    if (!field_bec) {
        edgeX = 0.0f;
        edgeY = 0.0f;
    }
    f32 a = field_bfc;
    f32 b = field_c00;
    f32 c = field_bf0;
    f32 width = field_420;
    f32 height = field_424;
    bool flag = field_67b;
    Unk_SetTarget(Unk_AsTexture(target));
    {
        Unk_Float4 colour(field_8e8, field_8e8, field_8e8, field_8e8);
        s32 space = field_96c ? field_974 : 0;
        IGPUSurface* surface =
            reinterpret_cast<IGPUSurface*>(Unk_AsTexture(target)->field_b8[Unk_AsTexture(target)->field_a0]);
        f32 aspect = width / height;
        reinterpret_cast<CRenderGlare*>(field_198)->TonemapToSurface(
            surface, false, Unk_AsTexture(source), hasGamma, fmt, &colour, matrix, w, h, 0.0f, 0.0f, dither, gamma,
            scale, scale2, field_968, matrix2, field_8c0.field_0 / Unk_SceneLuminance(this), &field_8d4, field_8e4,
            edgeX, edgeY, a, b, c, aspect, !flag, nullptr, space, 0, -1, 0.6f, nullptr);
    }
    if (!(!Unk_IsHdrOutput() || Unk_IsHdrDirect())) {
        Unk_430a10(target, history, Unk_AsTexture(history)->field_b8[Unk_AsTexture(history)->field_a0], false);
        Unk_426a50();
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (!field_270) {
        Unk_SetTarget(Unk_AsTexture(current));
    }
    f32 weight = field_bd0;
    f32 weight2 = field_bd4 < 0.0f ? 1.0f - weight : field_bd4;
    if (field_bd8_f > 0.0f) {
        weight = powf(weight, field_7f4 / field_bd8_f);
        weight2 = 1.0f - powf(1.0f - weight2, field_7f4 / field_bd8_f);
    }
    const MATRIXT44* m0 = field_b34[2] ? &field_9b4[2] : nullptr;
    const MATRIXT44* m1 = field_b34[3] ? &field_9b4[3] : nullptr;
    f32 ratio = field_bdc > 0.0f ? field_bdc : field_420;
    util->Unk_4821a0(Unk_AsTexture(previous), Unk_AsTexture(history), Unk_AsTexture(current), field_270, false,
                     reinterpret_cast<const f32*>(m0), const_cast<MATRIXT44*>(m1), weight, weight2, ratio, 0, 0);
    field_10e1 = true;
    return 0;
}

// 0x71004347e0: CPostEffect::EndPostEffectScene_Process (its log lines name
// it): the pre-process, the passes (once more for the second eye), the copy
// into the output and the post-process
// NON_MATCHING: a draft; the calls, their arguments and the log lines are
// the original's, the order of the second eye's saved fields and the copy's
// texture selection are not yet (about 210 instructions).
s32 CPostEffect::EndPostEffectScene_Process(u32 flags, s32 samples) {
    if (!field_0) {
#line 30034
        PPFX_ERROR("CPostEffect::EndPostEffectScene_Process(): EndPostEffectScene() called without BeginPostEffectScene().\n");
        return -1;
    }
    field_0 = false;
    field_678 = false;
    field_679 = false;
    field_67a = false;
    field_10e1 = false;
    Unk_425750();
    field_67b = Unk_24e09b8 || (flags & 0x10) != 0;
    if (field_7f4 <= 0.0f) {
        field_67b = true;
    }
    if (flags & 2) {
        if (!field_104c) {
            Unk_24e53e0 = nullptr;
        }
        s32 result = Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        return result < 0 ? result : 0;
    }
    bool copy = field_5d0 == 2 || field_5c8 != 0 || field_5cc != 0;
    u64 surface = field_1168;
    f32 x = field_5a4;
    f32 y = field_5a8;
    f32 width = field_5ac;
    f32 height = field_5b0;
    if (copy) {
        CRenderTexture* first = Unk_AsTexture(reinterpret_cast<Unk_4a5d10_Self*>(field_1a8)->field_38[0]);
        field_1168 = reinterpret_cast<u64>(first->field_d0[first->field_a0][0]);
        field_5a4 = 1.0f;
        field_5a8 = 1.0f;
        field_5ac = 0.0f;
        field_5b0 = 0.0f;
    }
    s32 result = EndPostEffectScene_PreProcess(flags, samples);
    if (result < 0) {
#line 30160
        PPFX_ERROR("CPostEffect::EndPostEffectScene_Process(): EndPostEffectScene_PreProcess() failed (0x%x: %s).\n", result, Unk_446df0(result));
    }
    result = Unk_435ed0();
    if (result < 0) {
#line 30170
        PPFX_ERROR("CPostEffect::EndPostEffectScene_Process(): EndPostEffectScene_InternalProcess() failed (0x%x: %s).\n", result, Unk_446df0(result));
    }
    if (field_5d0 == 2) {
        field_78 = 1;
        Unk_RenderTexture* scene = field_70;
        Unk_RenderTexture* current = Unk_TextureAt(field_5d8);
        field_70 = scene != nullptr ? scene : current;
        u32 toneMap = field_8c8;
        Unk_Float exposure = field_8c0;
        f32 scale = field_7fc;
        f32 luminance = field_7f8;
        f32 vignette = field_848;
        bool fade = field_eb8;
        MATRIXT44 matrix0 = field_9b4[0];
        MATRIXT44 matrix1 = field_9b4[1];
        f32 b = field_8d0;
        f32 a = field_8cc;
        Unk_Float gamma = field_8c4;
        field_8cc = 1.0f;
        field_8d0 = 1.0f;
        field_8c0 = 1.0f;
        field_8c4 = 1.0f;
        field_7f8 = 1.0f;
        field_7fc = 1.0f;
        field_848 = 0.0f;
        field_eb8 = false;
        field_8c8 = field_59c ? 0x40004 : 1;
        Unk_Identity(&field_9b4[0]);
        Unk_Identity(&field_9b4[1]);
        field_9 = true;
        field_678 = false;
        field_679 = false;
        field_67a = false;
        field_10e1 = false;
        Unk_425750();
        field_67b = true;
        CRenderTexture* second = Unk_AsTexture(reinterpret_cast<Unk_4a5d10_Self*>(field_1a8)->field_38[1]);
        field_1168 = reinterpret_cast<u64>(second->field_d0[second->field_a0][0]);
        result = Unk_435ed0();
        field_9 = false;
        if (result < 0) {
#line 30263
            PPFX_ERROR("CPostEffect::EndPostEffectScene_Process(): EndPostEffectScene_InternalProcess() failed (0x%x: %s).\n", result, Unk_446df0(result));
        }
        field_8c8 = toneMap;
        field_8c0 = exposure;
        field_7fc = scale;
        field_7f8 = luminance;
        field_848 = vignette;
        field_70 = scene;
        field_78 = 0;
        field_8d0 = b;
        field_8cc = a;
        field_8c4 = gamma;
        field_eb8 = fade;
        field_9b4[0] = matrix0;
        field_9b4[1] = matrix1;
    }
    if (copy) {
        field_1168 = surface;
        field_5a4 = x;
        field_5a8 = y;
        field_5ac = width;
        field_5b0 = height;
        s32 left = field_5c8;
        s32 right = field_5d0 == 2 ? field_5cc : 0;
        CRenderTextureArray* outputs = field_1a8;
        CRenderTexture* first = nullptr;
        CRenderTexture* other = nullptr;
        if (reinterpret_cast<Unk_4a5d10_Self*>(outputs)->field_30 >= 1) {
            first = Unk_AsTexture(reinterpret_cast<Unk_4a5d10_Self*>(outputs)->field_38[0]);
            if (field_5d0 == 2 && reinterpret_cast<Unk_4a5d10_Self*>(outputs)->field_30 != 1) {
                other = Unk_AsTexture(reinterpret_cast<Unk_4a5d10_Self*>(outputs)->field_38[1]);
            }
        }
        Unk_RenderTexture* source = field_5b8;
        if (source == nullptr) {
            source = Unk_TextureAt(field_5d8);
            if (field_70 != nullptr) {
                source = field_70;
            }
        }
        Unk_RenderTexture* source2 = field_5c0;
        if (source2 == nullptr) {
            source2 = Unk_TextureAt(field_5d8);
            if (field_70 != nullptr) {
                source2 = field_70;
            }
        }
        f32 amount = field_8d0 * (Unk_434570() ? 1.0f : 0.0f) * field_198->field_138;
        Unk_RenderTexture* glare = amount > 0.0f ? field_198->field_420 : nullptr;
        f32 ratio = field_5d4;
        Unk_RenderTexture* scene = Unk_TextureAt(field_5d8);
        if (field_70 != nullptr) {
            scene = field_70;
        }
        s32 blend = Unk_BlendMode(field_be0);
        const Unk_SurfaceSize* size = reinterpret_cast<const Unk_SurfaceSize*>(field_1168);
        f32 sw = static_cast<f32>(size->field_4c);
        f32 sh = static_cast<f32>(size->field_50);
        f32 value = field_5d0 == 2 ? field_8d4.field_0[3].field_0 : 1.0f;
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        result = util->Unk_498ab0(field_5a4 * sw, field_5a8 * sh, field_5ac * sw, field_5b0 * sh, amount * ratio, value,
                                  reinterpret_cast<void*>(field_1168), true, first, other, Unk_AsTexture(glare), left,
                                  right, Unk_AsTexture(scene), Unk_AsTexture(source), Unk_AsTexture(source2), blend,
                                  false, 0);
    }
    if (field_8b6) {
        return result;
    }
    result = EndPostEffectScene_PostProcess();
    if (result < 0) {
#line 30436
        PPFX_ERROR("CPostEffect::EndPostEffectScene_Process(): EndPostEffectScene_PostProcess() failed (0x%x: %s).\n", result, Unk_446df0(result));
    }
    return result < 0 ? result : 0;
}

// the render buffer's texture after `index` (field_5e0's first is field_5e4,
// the last wraps round to field_5e0; inline)
inline s32 CPostEffect::Unk_NextTexture(s32 index) const {
    return index == field_5e0 ? field_5e4
                              : (static_cast<u32>(index + 1) > field_5e4 + field_444 - 1 ? field_5e0 : index + 1);
}

// the depth of field's textures from `index` on (inline)
inline s32 CPostEffect::Unk_DepthOfFieldTextures(s32 index) {
    field_604 = index;
    field_608 = index;
    if (field_104f && !field_5a1) {
        index = Unk_NextTexture(index);
        field_608 = index;
        if (Unk_4b72c0_get(reinterpret_cast<const Unk_4b72c0*>(field_1a0))) {
            index = Unk_NextTexture(index);
        }
    }
    field_60c = index;
    return index;
}

// the motion blur's textures from `index` on (inline)
inline s32 CPostEffect::Unk_MotionBlurTextures(s32 index) {
    field_618 = index;
    if (field_1075) {
        field_61c = index;
        field_624 = index;
        index = Unk_NextTexture(index);
        if (field_107c >= 2) {
            field_61c = index;
            index = Unk_NextTexture(index);
        }
        if (field_1078 == 2 && field_d38 == nullptr && field_1d8 == nullptr) {
            field_624 = index;
            index = Unk_NextTexture(index);
        }
    }
    field_620 = index;
    return index;
}

// 0x7100435180: CPostEffect::EndPostEffectScene_PreProcess
// (EndPostEffectScene_Process's log line names it): the frame numbers, the
// viewport, which render buffer texture each effect uses this frame, and the
// scene's depth resolved
// NON_MATCHING: a draft (about 500 of 851 instructions differ): the
// original threads the index chain's branches into far more copies
s32 CPostEffect::EndPostEffectScene_PreProcess(u32 flags, s32 samples) {
    if (!field_8 && !field_67b) {
        for (s32 i = 0; i < field_400; i++) {
            if (field_298 == 0x7fffffff || i == field_298) {
                field_290[i]++;
            }
        }
    }
    if ((flags & 1) && field_18->field_14ef5) {
        field_1 = true;
    }
    Unk_PixelContainer* surface = nullptr;
    field_18->vf10(0, &surface);
    s32 result;
    if (surface != nullptr) {
        Unk_Viewport viewport;
        viewport.field_0 = 0;
        viewport.field_4 = 0;
        viewport.field_8 = surface->field_4c;
        viewport.field_c = surface->field_50;
        viewport.field_10 = 0.0f;
        viewport.field_14 = 1.0f;
        result = field_18->vf16(&viewport);
        if (surface != nullptr) {
            surface->vf1();
            surface = nullptr;
        }
    } else {
        result = 0;
    }
    bool direct;
    if (field_70 != nullptr || field_1068) {
        direct = false;
    } else {
        direct = field_59c ? field_106a : true;
    }
    field_106c = direct;
    if (direct) {
        Unk_RenderTexture* scene = Unk_TextureAt(field_5d8);
        Unk_RenderTexture* work = Unk_TextureAt(field_5e0);
        if (scene->field_54 > work->field_54 || scene->field_58 > work->field_58) {
            field_106c = false;
        }
    }
    s32 index = field_106c ? field_5d8 : field_5e0;
    field_5ec = index;
    bool dofFirst = field_10d7;
    field_67c = dofFirst;
    if (field_106d) {
        index = Unk_NextTexture(index);
    }
    field_5f0 = index;
    field_5f4 = index;
    if (field_10de) {
        index = Unk_NextTexture(index);
    }
    field_5f8 = index;
    field_5fc = index;
    if (field_10df) {
        index = Unk_NextTexture(index);
    }
    field_600 = index;
    if (dofFirst) {
        index = Unk_DepthOfFieldTextures(index);
    }
    if (field_1080) {
        index = Unk_MotionBlurTextures(index);
    }
    field_628 = index;
    if (field_1090) {
        index = Unk_NextTexture(index);
    }
    field_62c = index;
    if (!field_67c) {
        index = Unk_DepthOfFieldTextures(index);
    }
    field_610 = index;
    if (field_5a2) {
        index = Unk_NextTexture(index);
    }
    field_614 = index;
    if (!field_1080) {
        index = Unk_MotionBlurTextures(index);
    }
    field_630 = index;
    if (field_106e) {
        index = Unk_NextTexture(index);
        field_634 = index;
        index = Unk_NextTexture(index);
    }
    field_638 = index;
    field_63c = index;
    if (field_1074) {
        index = Unk_NextTexture(index);
        field_640 = index;
        index = Unk_NextTexture(index);
    }
    field_644 = index;
    field_660 = index;
    if (field_f39) {
        index = Unk_NextTexture(index);
    }
    field_664 = index;
    field_650 = index;
    if (field_c2d) {
        index = Unk_NextTexture(index);
    }
    field_654 = index;
    field_658 = index;
    if (field_c35) {
        index = Unk_NextTexture(index);
    }
    field_65c = index;
    field_648 = index;
    if (field_10d5) {
        index = Unk_NextTexture(index);
    }
    field_64c = index;
    field_668 = index;
    field_66c = index;
    if (Unk_IsHdrOutput()) {
        index = Unk_NextTexture(index);
    }
    field_670 = index;
    field_674 = index;
    if (!field_1069) {
        Unk_24e53e0 = nullptr;
    }
    CTextureUtil* util = Unk_TextureUtil();
    field_104e = Unk_24e53e8;
    if (field_104e) {
        if (field_70 != nullptr) {
            result = Unk_49e3a0(0, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        } else {
            result = Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            if (result >= 0 && field_1069) {
                field_678 = true;
            }
        }
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
    }
    util->Unk_471410(0x10, 3, -1);
    Unk_440d50_get(reinterpret_cast<u64>(field_18), 0);
    s32 count = std::min(field_440, samples);
    if (field_70 == nullptr && count != 0) {
        if (field_1069) {
            s32 resolved = Unk_49e290(0, nullptr, 0, nullptr, 1.0f);
            if (resolved < 0) {
#line 31099
                PPFX_ERROR("CPostEffectEndPostEffectScene_PreProcess: CRenderTexture::ResolveCurrentDepthStencilTexture() failed (0x%x: %s).\n", resolved, Unk_446df0(resolved));
            } else if (field_1069) {
                field_678 = true;
            }
        }
        s32 level = field_894 ? field_690 : 0;
        util->Unk_470610(field_8cc, field_8d0);
        if (Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f) >= 0 && field_1069) {
            field_678 = true;
        }
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        result = reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a65a0(
            field_5d8, count < 0 ? field_5e8 : field_5dc, count, level, true, 1.0f);
        field_5e8 = field_5d8;
    }
    if (field_1069 && !field_104e) {
        result = Unk_49e290(0, nullptr, 0, nullptr, 1.0f);
        if (result < 0) {
#line 31255
            PPFX_ERROR("CPostEffectEndPostEffectScene_PreProcess: CRenderTexture::ResolveCurrentDepthStencilTexture() failed (0x%x: %s).\n", result, Unk_446df0(result));
        } else if (field_1069) {
            field_678 = true;
        }
    }
    return result < 0 ? result : 0;
}

// 0x7100435ed0: CPostEffect::EndPostEffectScene_InternalProcess (its log
// lines name it): every effect of the frame, the glare and the tone map
// NON_MATCHING: a first draft; the effects' order and calls are the
// original's, the control flow and registers are not yet. The projection goes
// through the inline Unk_Perspective, with field_734's address taken before it
// (the original keeps it in x26 across the call).
s32 CPostEffect::Unk_435ed0() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    u32 toneMap = field_8c8;
    s32 result;
    bool copy = (field_596 || field_70 != nullptr) ? true : field_104e;
    if (!field_106c && copy) {
        Unk_RenderTexture* scene = Unk_TextureAt(field_5d8);
        if (field_70 != nullptr) {
            scene = field_70;
        }
        Unk_RenderTexture* work = Unk_TextureAt(field_5e0);
        bool found = false;
        if (field_70 == nullptr) {
            s32 index = -1;
            std::vector<CRenderTexture*, Unk_StlAllocator<CRenderTexture*>>& list = Unk_AsTexture(work)->field_108;
            for (CRenderTexture** it = list.data(); it != list.data() + list.size(); it++) {
                index++;
                if (*it == Unk_AsTexture(scene)) {
                    break;
                }
            }
            found = index >= 0;
        }
        bool noTarget = field_c0 != 0 && field_b8 == nullptr;
        if (!found || field_1051 || field_50 != nullptr || noTarget) {
            f32 scale = 1.0f;
            Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
            bool direct = true;
            util->Unk_470610(field_8cc, field_8d0);
            u32 mode = field_680;
            mode = field_78 == 1 ? 21 : mode;
            if (field_10d9) {
                direct = field_1053;
            }
            bool external = true;
            if (!field_1051 && field_50 == nullptr) {
                scale = Unk_SceneLuminance(this) / field_7f8;
                external = false;
            }
            if (direct) {
                direct = field_70 != nullptr && scale == 1.0f && !noTarget;
            }
            scene = Unk_42bbe0(scene);
            Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            if (noTarget) {
                util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, scene, Unk_AsTexture(Unk_WorkTexture(field_1b0)), 0, &ones, 0,
                                 false, false, 1, &zero, nullptr, -1);
                field_d0 = Unk_WorkTexture(field_1b0);
            }
            if (external) {
                f32 a = 0.0f;
                void* b = nullptr;
                u32 c = 0;
                u32 d = 2;
                u32 e = 0;
                if (field_10d7) {
                    a = field_98;
                    b = field_80;
                    c = field_8c;
                    d = field_90;
                    e = field_94;
                }
                if (direct) {
                    util->Unk_471410(0, 3, -1);
                    result = 0;
                    Unk_AsTexture(work)->field_120 = Unk_AsTexture(scene);
                } else {
                    result = Unk_42cc90(mode, 1, scene, nullptr, false, b, c, d, e, a);
                }
            } else {
                Unk_Float4 colour(scale, scale, scale, 1.0f);
                if (direct) {
                    util->Unk_471410(0, 3, -1);
                    result = 0;
                    Unk_AsTexture(work)->field_120 = Unk_AsTexture(scene);
                } else {
                    result = util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, scene, Unk_AsTexture(work), mode, &colour, 0,
                                              true, false, 1, &zero, nullptr, -1);
                }
            }
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }
    if (field_c0 != 0 && field_d0 == nullptr) {
        Unk_RenderTexture* target = field_b8;
        if (target == nullptr || target->field_54 > field_198->field_bc * 2) {
            Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
            target = Unk_WorkTexture(field_1b0);
            Unk_RenderTexture* source = field_b8;
            if (source == nullptr) {
                source = Unk_TextureAt(field_5d8);
                if (field_70 != nullptr) {
                    source = field_70;
                }
            }
            Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, source, Unk_AsTexture(target), 0, &ones, 0, false, false, 1, &zero,
                             nullptr, -1);
        }
        field_d0 = target;
    }
    if (field_10d9) {
        Unk_42cba0(field_10d7);
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        result = 0;
    }
    f32 rotation = Unk_4280e0();
    if (field_1a0 != nullptr) {
        reinterpret_cast<CDepthOfField*>(field_1a0)->field_1bc = rotation;
    }
    if (field_106d) {
        Unk_RenderTexture* source = Unk_TextureAt(field_5ec);
        Unk_RenderTexture* target = Unk_TextureAt(field_5f0);
        f32 scale = 1.0f / (field_8c0.field_0 / Unk_SceneLuminance(this));
        Unk_Float4 colours[4];
        for (s32 i = 0; i < 4; i++) {
            for (s32 j = 0; j < 4; j++) {
                colours[i].field_0[j] = scale * field_ca4[i].field_0[j].field_0;
            }
        }
        result = util->Unk_475320(field_c9c, field_ca0, Unk_AsTexture(source), Unk_AsTexture(target), &colours[0],
                                  &colours[1], &colours[2], &colours[3], 0);
    }
    if (field_10dc) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        result = ApplyEffects_GenerateNormalAndLinearDepth();
    }
    if (field_10de) {
        Unk_4320b0(Unk_TextureAt(field_5f4), nullptr, false, false);
        result = 0;
    }
    if (field_10df) {
        Unk_42be10();
        Unk_432570();
        result = 0;
    }
    if (field_67c) {
        if (Unk_ApplyDepthOfField(this, &result)) {
            return result < 0 ? result : 0;
        }
        if (field_10d7 && field_10d8) {
            result = Unk_42cc90(-1, 0, nullptr, Unk_TextureAt(field_60c),
                                reinterpret_cast<const u8*>(field_18)[0x14efa] != 0, nullptr, 0, 2, 0, 0.0f);
        }
    }
    if (field_1080) {
        Unk_433450();
        result = 0;
    }
    if (field_1090) {
        f32 factors[4];
        Unk_428cc0(factors, 2, 0, 1.0f, 0.0f);
        Unk_RenderTexture* depth = Unk_TextureAt(field_628);
        Unk_RenderTexture* target = Unk_TextureAt(field_62c);
        MATRIXT44 projection;
        bool flip = !field_1091;
        s32 count = field_d84;
        void* data = field_d88;
        const MATRIXT44* camera = &field_734;
        Unk_Perspective(&projection, field_6c4, field_6c8, field_6d0, field_420, field_6d4, field_6d8);
        Unk_Float2 depthScale(factors[0], factors[1]);
        result = util->Unk_488860(field_de4, field_de0, field_d94, field_d98, field_dc4, field_dc8, flip, count, data,
                                  Unk_AsTexture(depth), Unk_AsTexture(target), nullptr, nullptr, camera, &projection,
                                  &depthScale, field_d90, &field_dd0, &field_d9c, &field_dac, &field_db4, field_dc0,
                                  field_dcc);
        if (result < 0) {
#line 31951
            PPFX_ERROR("CPostEffect::EndPostEffectScene_InternalProcess(): pTexUtil->HeatShimmerParticles() failed (0x%x: %s).\n",
                       result, Unk_446df0(result));
        }
    }
    if (!field_67c) {
        if (Unk_ApplyDepthOfField(this, &result)) {
            return result < 0 ? result : 0;
        }
    }
    if (field_5a2) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        Unk_RenderTexture* source = Unk_TextureAt(field_610);
        Unk_RenderTexture* target = Unk_TextureAt(field_614);
        f32 nearSize;
        f32 farSize;
        reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4afae0(&nearSize, &farSize);
        f32 ratio = Unk_478880(field_198->field_124, field_198->field_128, true);
        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
        util->Unk_481db0(Unk_AsTexture(source), 0.0f, nearSize, farSize, field_6cc, ratio, Unk_AsTexture(target),
                         &ones, 0, 0);
    }
    if (field_1075 && !field_1080) {
        Unk_433450();
    }
    Unk_433270();
    if (field_1074) {
        Unk_432ca0(-1.0f, Unk_TextureAt(field_63c), Unk_TextureAt(field_640), nullptr, Unk_TextureAt(field_644),
                   reinterpret_cast<const Unk_Float4*>(&field_c7c), -1, field_c90, field_c91);
    }
    if (field_f39) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        Unk_RenderTexture* source = Unk_TextureAt(field_660);
        Unk_RenderTexture* target = Unk_TextureAt(field_664);
        f32 luminance = field_8c0.field_0;
        f32 scene = Unk_SceneLuminance(this);
        Unk_Float2 range(0.0f, 0.0f);
        const Unk_Float2* fade = nullptr;
        if (field_f38 && Unk_4622e0(field_6c4, field_6c8, field_f3c, field_f40)) {
            f32 near = field_6c4;
            f32 far = field_6c8;
            f32 d = field_1064;
            f32 k = ((far - near) * d) / (far * near);
            f32 m = (1.0f - d / near) / k;
            f32 inverse = 1.0f / k;
            f32 x = field_105c * inverse;
            f32 y = (field_105c * 0.0f + field_1060) * inverse - m;
            f32 zf = (far * (field_f40 - near) / (far - near)) / field_f40;
            f32 zn = (far * (field_f3c - near) / (far - near)) / field_f3c;
            f32 r = 1.0f / (zn - zf);
            range.field_0[0] = x * r;
            range.field_0[1] = y * r + (0.0f - zf * r);
            fade = &range;
        }
        f32 ratio = luminance / scene;
        if (field_f44 == 2) {
            util->Unk_48f230(ratio, field_f48, field_f5c, field_f60, field_f64, field_1064, Unk_AsTexture(target),
                             Unk_AsTexture(source), Unk_AsTexture(field_228), Unk_AsTexture(field_230), fade, field_f4c,
                             field_f50, field_f54, field_f58, &field_1054, false);
        } else if (field_f44 == 1) {
            util->Unk_48edb0(ratio, 0.25f, Unk_AsTexture(target), Unk_AsTexture(source), fade, false);
        }
    }
    if (field_c2d) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        Unk_RenderTexture* source = Unk_TextureAt(field_650);
        Unk_RenderTexture* target = Unk_TextureAt(field_654);
        util->Unk_482010(field_6cc, field_420, field_c60, field_c64, field_c68, Unk_AsTexture(source),
                         Unk_AsTexture(target), field_c30, &field_c38, &field_c40, &field_c48, &field_c58, &field_c50,
                         field_c6c, util->field_29ab8[0], 0, 0);
    }
    if (field_c35) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        Unk_RenderTexture* source = Unk_TextureAt(field_658);
        Unk_RenderTexture* target = Unk_TextureAt(field_65c);
        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, source, Unk_AsTexture(target), 0, &ones, 0, false, false, 1, &zero,
                         nullptr, -1);
    }
    f32 width = field_420;
    f32 height = field_424;
    f32 area = width * height;
    if (field_10d5) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        Unk_RenderTexture* source = Unk_TextureAt(field_648);
        Unk_RenderTexture* target = Unk_TextureAt(field_64c);
        f32 aspect = width / height;
        u32 kind = field_c04;
        f32 distance = field_6cc;
        f32 offset;
        if (field_c14 == 2) {
            offset = field_c1c;
        } else {
            if (field_c14 == 0) {
                distance = field_c18;
            }
            offset = 0.0f;
        }
        f32 factors[4];
        Unk_428cc0(factors, 0, 2, 1.0f, 0.0f);
        f32 angle = field_be4 ? field_be8 : 0.0f;
        f32 depth = factors[0] * 0.0f + factors[1];
        util->Unk_481bc0(distance, area, angle, offset, field_c20, field_c24, field_c28, field_c0c, field_c10, depth,
                         field_c08, 0.0f, field_bf0, aspect, Unk_AsTexture(source), Unk_AsTexture(target), kind, false,
                         field_bf8 != 0.0f, !field_67b, 0, 0);
        field_198->field_26c = field_10d5;
        Unk_455560_set(reinterpret_cast<Unk_455350*>(field_198), kind, distance, area, angle, offset, field_c20,
                       field_c24, field_c28, field_c0c, field_c10, field_c08);
    } else {
        field_198->field_26c = false;
        Unk_455560_set(reinterpret_cast<Unk_455350*>(field_198), 1, 0.78539819f, area, 1.0f, 0.0f, 0.0f, 3.14159274f,
                       1.04719758f, 0.1f, 0.25f, 1.0f);
    }
    s32 index = field_668;
    Unk_RenderTexture* source = Unk_TextureAt(index);
    u32 kind = toneMap & 0xffff0000;
    f32 intensity = field_848;
    f32 divisor = field_8d0;
    if (field_106c) {
        source = Unk_TextureAt(index);
        if (field_59c && Unk_434570()) {
            reinterpret_cast<CRenderGlare*>(field_198)->Unk_453440(field_694, -1, -1);
            util->Unk_470610(field_8cc, field_8d0);
        }
    } else if (field_59d) {
        if (kind == 0x70000) {
            index = field_5d8;
            source = Unk_TextureAt(index);
        }
        if (Unk_434570()) {
            reinterpret_cast<CRenderGlare*>(field_198)->Unk_453440(field_694, -1, -1);
            util->Unk_470610(field_8cc, field_8d0);
        }
    } else if (Unk_434570()) {
        reinterpret_cast<CRenderGlare*>(field_198)->Unk_453440(-1, -1, -1);
    }
    field_198->field_148 = 0.0f;
    field_198->field_14c = 2.0f;
    field_198->field_150 = 1.0f;
    if (Unk_434570()) {
        field_190->field_90 = index;
        f32 starScale = 1.0f;
        if (field_f78 == 1 && field_f7c.field_0 > 1.0f) {
            starScale = field_f7c.field_0;
        }
        f32 threshold = field_844;
        if (field_59c) {
            if (field_84c) {
                threshold *= field_8d0;
            } else {
                threshold = Unk_462c30(Unk_ToneMapFormat(toneMap >> 16), threshold, field_8cc, field_8d0);
            }
        }
        f32 limit = field_1018;
        if (limit > 0.0f) {
            Unk_455350* glare = reinterpret_cast<Unk_455350*>(field_198);
            Unk_4553c0_set(glare, limit);
            Unk_4553e0_set(glare, limit);
            Unk_455400_set(glare, limit);
            Unk_455420_set(glare, limit);
        } else {
            f32 high;
            f32 value;
            if (field_59c) {
                limit = field_8cc;
                value = reinterpret_cast<CRenderGlare*>(field_198)->Unk_45ee20() * field_8d0;
            } else {
                value = reinterpret_cast<CRenderGlare*>(field_198)->Unk_45ee20();
                limit = value;
            }
            high = starScale * value;
            Unk_4385e0(field_198->field_d4);
            if (field_59c) {
                f32 most = starScale * (starScale * (field_8cc / field_101c));
                high = high < most ? high : most;
            } else {
                Unk_4a5d10_Self* textures = field_190;
                s32 work = field_5e0;
                if (work == -1) {
                    work = textures->field_90;
                }
                if (Unk_4385e0(textures->field_38[work]->field_38)) {
                    f32 most = starScale * (starScale * (field_8c0.field_0 / Unk_SceneLuminance(this) / field_101c));
                    limit = limit < most ? limit : most;
                }
            }
            f32 range = high - threshold;
            Unk_4553c0_set(reinterpret_cast<Unk_455350*>(field_198), limit);
            Unk_4553e0_set(reinterpret_cast<Unk_455350*>(field_198), limit);
            Unk_455400_set(reinterpret_cast<Unk_455350*>(field_198), range);
            Unk_455420_set(reinterpret_cast<Unk_455350*>(field_198), range);
            Unk_455440_set(reinterpret_cast<Unk_455350*>(field_198), 1.0f);
            Unk_455460_set(reinterpret_cast<Unk_455350*>(field_198), 1.0f);
            Unk_455480_set(reinterpret_cast<Unk_455350*>(field_198), 1.0f);
            Unk_4554a0_set(reinterpret_cast<Unk_455350*>(field_198), 1.0f);
        }
        f32 gain = field_101c;
        Unk_455350* glare = reinterpret_cast<Unk_455350*>(field_198);
        Unk_455440_set(glare, gain);
        Unk_455460_set(glare, gain);
        Unk_455480_set(glare, gain);
        Unk_4554a0_set(glare, gain);
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
        field_198->field_1ec = field_1020;
        field_198->field_1e4 = field_1024;
        field_198->field_1f0 = 1.0f;
        u32 definition = Unk_GlareDefinition(field_f80);
        const Unk_4a0b00* custom = nullptr;
        if (definition == 0xffffffff) {
            static Unk_4a0b00 s_definition;
            const Unk_4278c0_Data& d = field_f84;
            s_definition.Unk_4a0f10(
                nullptr, Unk_Float4(d.field_0[0], d.field_0[1], d.field_0[2], d.field_0[3]),
                Unk_Float4(d.field_10[0], d.field_10[1], d.field_10[2], d.field_10[3]), d.field_20,
                Unk_Float4(d.field_28[0], d.field_28[1], d.field_28[2], d.field_28[3]), d.field_38, d.field_3c,
                Unk_Float4(d.field_44[0], d.field_44[1], d.field_44[2], d.field_44[3]), 1.0f, d.field_58, d.field_5c,
                d.field_64, d.field_68, d.field_80, Unk_Float4(d.field_70[0], d.field_70[1], d.field_70[2], d.field_70[3]),
                0.0f, d.field_24, d.field_40, d.field_54, d.field_60, d.field_6c);
            custom = &s_definition;
        }
        s32 quality = Unk_GlareQuality(field_f78);
        f32 star = field_f7c.field_0;
        CRenderTexture* reduced = nullptr;
        if (field_104f &&
            (field_850 == 2 || (field_850 == 1 && !field_c2d && !field_c35 && !field_1090 && !field_10d5))) {
            reduced = reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aee10(field_198->field_bc);
        }
        f32 ratio = intensity / divisor;
        field_198->field_410 = !Unk_24e09e0;
        result = reinterpret_cast<CRenderGlare*>(field_198)
                     ->Unk_45ee80(reduced != nullptr ? reduced : Unk_AsTexture(source), field_8c0.field_0,
                                  Unk_SceneLuminance(this), ratio, threshold, quality, star, definition,
                                  reinterpret_cast<const Unk_45_170*>(custom), field_7f4, rotation, field_67b, field_c0,
                                  Unk_AsTexture(field_d0));
        if (result < 0) {
#line 33317
            PPFX_ERROR("CPostEffect::EndPostEffectScene_InternalProcess(): m_pRenderGlare->GenerateGlare() failed (0x%x: %s).\n",
                       result, Unk_446df0(result));
        }
    }
    field_190->field_90 = index;
    s32 format;
    f32 scale;
    f32 scale2;
    f32 dither;
    bool hasGamma;
    f32 gamma;
    MATRIXT44* matrix;
    MATRIXT44* matrix2;
    Unk_42df80(&format, &scale, &scale2, &dither, &hasGamma, &gamma, &matrix, &matrix2, false, false);
    Unk_RenderTexture* target = source;
    if (kind == 0x70000) {
        target = Unk_TextureAt(field_66c);
    }
    Unk_42d490(target);
    if (!field_679) {
        Unk_42e560();
    }
    bool feedback = field_bce;
    if (field_96c && field_970 != 0 && feedback && !Unk_IsFloatFormat(field_518)) {
#line 16846
        PPFX_WARNING("CPostEffect::GetEffectiveFeedbackEnable(): The feedback result will be clamped because the feedback buffer format is not floating point format.\n");
    }
    if (feedback) {
        Unk_434000(target);
    } else {
        s32 frames = field_f30 == -1 ? field_f2c : field_f30;
        Unk_4a5d10_Self* textures = field_190;
        s32 last = field_66c;
        if (last == -1) {
            last = textures->field_90;
        }
        Unk_RenderTexture* texture = textures->field_38[last];
        const Unk_SurfaceSize* size = reinterpret_cast<const Unk_SurfaceSize*>(field_1168);
        bool changed = texture->field_54 != static_cast<u32>(field_5a4 * static_cast<f32>(size->field_4c)) ||
                       texture->field_58 != static_cast<u32>(field_5a8 * static_cast<f32>(size->field_50));
        if ((changed && frames >= 1 && Unk_IsPlainOutput(this)) || field_10d6) {
            Unk_433d00(target);
        }
    }
    void* surface = reinterpret_cast<void*>(field_1168);
    if (field_10e1 || Unk_IsPlainOutput(this)) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    }
    bool hasSurface = surface != nullptr;
    s32 blend = Unk_BlendMode(field_be0);
    Unk_RenderTexture* history;
    CRenderTexture* output = nullptr;
    void* destination;
    s32 frames;
    bool own = false;
    if (field_10e1) {
        history = Unk_428f00();
        hasGamma = false;
        frames = field_f30 == -1 ? field_f2c : field_f30;
        format = -1;
        destination = surface;
    } else if (Unk_IsPlainOutput(this)) {
        history = target;
        frames = -1;
        destination = surface;
    } else {
        history = target;
        output = Unk_AsTexture(Unk_TextureAt(field_670));
        destination = output->field_b8[output->field_a0];
        CRenderTexture* targets[8] = {output};
        Unk_49da70(8, targets, nullptr, nullptr, 0, nullptr, 0, 0, 0, 1.0f);
        hasSurface = false;
        blend = 0;
        frames = -1;
        own = true;
    }
    f32 edgeX = field_bec ? field_bf4 : 0.0f;
    f32 edgeY = field_bec ? field_bf8 : 0.0f;
    void* noise = field_10d6 ? field_178 : nullptr;
    f32 offset = 0.0f;
    if (!field_96c && Unk_24e09bc == 0) {
        offset = field_968;
    }
    const Unk_SurfaceSize* size = reinterpret_cast<const Unk_SurfaceSize*>(destination);
    u32 surfaceHeight = size->field_50;
    u32 h = own ? reinterpret_cast<CRenderTexture*>(output)->field_58 : surfaceHeight;
    u32 w = own ? static_cast<u32>(reinterpret_cast<CRenderTexture*>(output)->field_54) : size->field_4c;
    f32 y = field_5b0 * static_cast<f32>(h);
    if (reinterpret_cast<const u8*>(field_18)[0x58]) {
        y = static_cast<f32>(surfaceHeight) - y - field_5a8 * static_cast<f32>(h);
    }
    s32 space = field_96c ? field_974 : 0;
    Unk_Float4 colour(field_8e8, field_8e8, field_8e8, field_8e8);
    s32 status = reinterpret_cast<CRenderGlare*>(field_198)->TonemapToSurface(
        reinterpret_cast<IGPUSurface*>(destination), hasSurface, reinterpret_cast<CRenderTexture*>(history), hasGamma,
        format, &colour, matrix, field_5a4 * static_cast<f32>(w), field_5a8 * static_cast<f32>(h),
        field_5ac * static_cast<f32>(w), y, dither, gamma, scale, scale2, offset, matrix2,
        field_8c0.field_0 / Unk_SceneLuminance(this), &field_8d4, field_8e4, edgeX, edgeY, field_bfc, field_c00,
        field_bf0, field_420 / field_424, !field_67b, nullptr, space, blend, frames, field_f34, noise);
    if (!field_10e1 && !Unk_IsPlainOutput(this)) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        field_18->vf44(Unk_BlendMode(field_be0));
        status = Unk_430a10(reinterpret_cast<Unk_RenderTexture*>(output), nullptr, surface, false);
        field_18->vf44(0);
        Unk_426a50();
    }
    if (field_5d0 == 1) {
        field_18->vf45(2);
        Unk_RenderTexture* scene = field_70 != nullptr ? field_70 : Unk_TextureAt(field_5d8);
        CRenderTexture* texture = Unk_AsTexture(scene);
        Unk_Float4 colours(1.0f, 1.0f, 1.0f, field_8d4.field_0[3]);
        const Unk_SurfaceSize* screen = reinterpret_cast<const Unk_SurfaceSize*>(surface);
        f32 sw = static_cast<f32>(screen->field_4c);
        f32 sh = static_cast<f32>(screen->field_50);
        f32 u1 = texture->field_90 + texture->field_88 * static_cast<f32>(texture->field_54);
        f32 v1 = texture->field_94 + texture->field_8c * static_cast<f32>(texture->field_58);
        CRenderTexture* last = texture;
        while (last->field_120 != nullptr) {
            last = last->field_120;
        }
        status = util->DrawRectGPU_MadT1_Sn(field_5ac * sw, field_5b0 * sh, field_5a4 * sw, field_5a8 * sh, 0.0f, 0.0f,
                                            u1, v1, 1, nullptr, &colours,
                                            reinterpret_cast<Unk_GPUTexture*>(last->field_a8), 21, 0);
        field_18->vf45(0);
    }
    field_18->vf41(-1, true);
    reinterpret_cast<CRenderGlare*>(field_198)->Unk_453440(-1, -1, -1);
    reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(field_6b4, 0x7fffffff);
    if (status < 0) {
#line 33961
        PPFX_ERROR("CPostEffect::EndPostEffectScene_InternalProcess(): m_pRenderGlare->TonemapToSurface() failed (0x%x: %s).\n",
                   status, Unk_446df0(status));
    }
    DrawDebugBuffers();
    return status < 0 ? status : 0;
}

}  // namespace PPFX
