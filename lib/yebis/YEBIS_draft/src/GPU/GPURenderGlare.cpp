// Scope: common
// PPFX::CRenderGlare (C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp, the
// __FILE__ of its log lines).
#include <math.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUGlareDef.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderGlare.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Luminance.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7101b3499c: "CRenderGlare"
extern const char Unk_1b3499c[];

// 0x71004a06e0, 0x71004a1010, 0x71004a15b0, 0x71004a0a30, 0x71004a2b80
void Unk_4a06e0();
void Unk_4a1010();
void Unk_4a15b0();
void Unk_4a0a30();
void Unk_4a2b80();
// 0x71004a1690 (GPUGlareDef.cpp): the glare definitions' styles from their seeds
s32 Unk_4a1690(const s32* seeds);

namespace PPFX {

// an object without members that CRenderGlare's constructor makes and its
// destructor deletes
struct Unk_24e6c68_Class {
    Unk_24e6c68_Class() {
        Unk_4a06e0();
        Unk_4a1010();
    }
    ~Unk_24e6c68_Class() {
        Unk_4a15b0();
        Unk_4a0a30();
        Unk_4a2b80();
    }
};

}  // namespace PPFX

// 0x71024e6c68
extern PPFX::Unk_24e6c68_Class* Unk_24e6c68;

namespace PPFX {

// 0x7100452f00: a description's numbers made valid (defaults for the ones
// that are not set, the rest clamped)
void Unk_452f00(Unk_453_30* desc) {
    if (desc->field_18[5] <= 0) {
        desc->field_18[5] = 8;
    }
    if (desc->field_18[6] <= 0) {
        desc->field_18[6] = 2;
    }
    if (desc->field_18[10] < 0) {
        desc->field_18[10] = 16;
    }
    desc->field_18[10] = desc->field_18[10] < 16 ? desc->field_18[10] : 16;
    if (desc->field_58) {
        desc->field_18[10] = desc->field_18[10] > 1 ? desc->field_18[10] : 1;
    }
    s32 levels = static_cast<s32>(logf(static_cast<f32>(desc->field_c)) / 0.6931472f);
    s32 most = desc->field_18[6] + levels - 2;
    desc->field_18[5] = desc->field_18[5] < most ? desc->field_18[5] : most;
    s32 count = desc->field_4c;
    desc->field_4c = count > 1 ? count : 1;
    u32 width = desc->field_c;
    u32 height = desc->field_10;
    f32 amount = desc->field_18_f[0];
    desc->field_18_f[0] = amount < 0.0f ? 0.0f : (amount > 1.0f ? 1.0f : amount);
    if (desc->field_18[1] == 0) {
        desc->field_18[1] = desc->field_4 >> 1;
    }
    if (width >= static_cast<u32>(desc->field_18[1])) {
        desc->field_18_f[0] = 0.0f;
    }
    if (desc->field_74 <= 0.0f) {
        desc->field_74 = static_cast<f32>(width) / static_cast<f32>(height);
    }
    if (desc->field_78 <= 0.0f) {
        desc->field_78 = 1.0f;
    }
    if (desc->field_18[3] == 0) {
        desc->field_18[3] = desc->field_18[2];
    }
    if (desc->field_18[4] == 0) {
        desc->field_18[4] = desc->field_18[2];
    }
}

// 0x71004530b0
CRenderGlare::CRenderGlare(const char* name) : CGPUResourceManage(nullptr) {
#line 306
    Unk_24e6c68 = UNK_NEW(Unk_24e6c68_Class);
    Unk_4531d0(name);
}

// 0x71004531d0
s32 CRenderGlare::Unk_4531d0(const char* name) {
    if (name != nullptr && name[0] != '\0') {
        field_10 = Unk_TFXString(Unk_1b3499c) + " " + name;
    } else {
        field_10 = Unk_1b3499c;
    }
    Unk_Clear();
    return 0;
}

// 0x7100455750, 0x71004557d0 (deleting)
CRenderGlare::~CRenderGlare() {
    Unk_49ec80();
    UNK_DELETE(Unk_24e6c68);
}

// 0x7100455b00
s32 CRenderGlare::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0) {
        return result;
    }
    if (field_20 == nullptr) {
        return 0;
    }
    result = CreateDeviceResources();
    return result < 0 ? result : 0;
}

}  // namespace PPFX

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);
namespace PPFX {

// 0x7100446ae0 (Unk_447050.cpp): a format's bytes per pixel
u32 Unk_446ae0(s32 format);

// 0x7100461e00 (GPUTextureUtil.cpp): 1 inside `inner`, falling to 0 at the edge
void Unk_461e00(Unk_Float4* out, const Unk_Float2* position, const Unk_Float2* size, const f32* inner);

// texture `index` of a render texture array, or null (inline)
static inline CRenderTexture* Unk_ArrayTexture(const CGPUResourceManage* array, s64 index) {
    const CRenderTextureArray* self = static_cast<const CRenderTextureArray*>(array);
    return index < self->field_30 ? self->field_38[index] : nullptr;
}

// a value from 0 to 1 as a byte (inline)
static inline u32 Unk_ToByte(f32 x, s32 shift) {
    if (x >= 1.0f) {
        return 0xff << shift;
    }
    if (x <= 0.0f) {
        return 0;
    }
    return static_cast<u32>(x * 255.9999f) << shift;
}

// a colour as A8R8G8B8 (inline)
static inline u32 Unk_PackColor(const Unk_Float4& color) {
    u32 r = Unk_ToByte(color.field_0[0].field_0, 16);
    u32 g = Unk_ToByte(color.field_0[1].field_0, 8);
    u32 b = Unk_ToByte(color.field_0[2].field_0, 0);
    u32 a = Unk_ToByte(color.field_0[3].field_0, 24);
    return r | g | b | a;
}

// 0x7100455b50 (its log line names it): the resources' device objects, and
// the 64x64 circle of field_348 (m_pGPUTextureTrimCircle) when it has
// m_pGhostGeneration
s32 CRenderGlare::CreateDeviceResources() {
    if (field_20 == nullptr) {
        return -1;
    }
    s32 result = m_pGlareSource->vf0(field_20);
    if (result < 0) {
        return result;
    }
    result = m_pGlareResult->vf0(field_20);
    if (result < 0) {
        return result;
    }
    if (m_pGlareResultUpsample != nullptr) {
        result = m_pGlareResultUpsample->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pGlareResultAntialias != nullptr) {
        result = m_pGlareResultAntialias->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pGlareResultLensDistortionFalloff != nullptr) {
        result = m_pGlareResultLensDistortionFalloff->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pGlareResultChromaticAberration != nullptr) {
        result = m_pGlareResultChromaticAberration->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        result = m_ppBloomGeneration[i]->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    result = m_pBloomResult->vf0(field_20);
    if (result < 0) {
        return result;
    }
    if (m_pStarGeneration != nullptr) {
        result = m_pStarGeneration->vf0(field_20);
        if (result < 0) {
            return result;
        }
        for (u32 i = 0; i < static_cast<u32>(static_cast<CRenderTextureArray*>(m_pStarGeneration)->field_30); i++) {
            Unk_GPUTexture* texture = Unk_GetTexture(static_cast<CRenderTextureArray*>(m_pStarGeneration)->Unk_Texture(i));
            if (i < static_cast<u32>(field_b0.field_18[10])) {
                texture->vf17(1);
            } else {
                texture->vf17(0);
            }
        }
    }
    if (m_pStarResult != nullptr) {
        result = m_pStarResult->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pAnamorphicFlareResult != nullptr) {
        result = m_pAnamorphicFlareResult->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pGhostGeneration != nullptr) {
        result = m_pGhostGeneration->vf0(field_20);
        if (result < 0) {
            return result;
        }
        for (u32 i = 0; i < static_cast<u32>(static_cast<CRenderTextureArray*>(m_pGhostGeneration)->field_30); i++) {
            Unk_GetTexture(static_cast<CRenderTextureArray*>(m_pGhostGeneration)->Unk_Texture(i))->vf18(0);
        }
        Unk_GetTexture(static_cast<CRenderTextureArray*>(m_pGhostGeneration)->Unk_Texture(0))->vf18(1);
    }
    if (m_pLightGhostLuminance != nullptr) {
        result = m_pLightGhostLuminance->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_ppAfterimageGeneration != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            result = m_ppAfterimageGeneration[i]->vf0(field_20);
            if (result < 0) {
                return result;
            }
        }
    }
    if (m_pLightShaftBlurSource != nullptr) {
        result = m_pLightShaftBlurSource->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pLightShaftResult != nullptr) {
        result = m_pLightShaftResult->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pLightShaftGeneration != nullptr) {
        result = m_pLightShaftGeneration->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (m_pGhostGeneration != nullptr) {
        f32 inner = 0.5f;
        result = field_20->vf60(64, 64, 1, 0, 0x3d, 0, 0, &field_348, 0);
        if (result < 0) {
#line 1849
            PPFX_ERROR("CRenderGlare::CreateDeviceResources(): m_pGPUDevice->CreateTexture(&m_pGPUTextureTrimCircle) failed (0x%x: %s).\n", result, Unk_446df0(result));
        }
        Unk_446ae0(0x3d);
        Unk_Float2 size;
        size.field_0[0].field_0 = 0.015625f;
        size.field_0[1].field_0 = 0.015625f;
#line 1872
        u8* pixels = UNK_NEW_ARRAY(u8, 0x1000);
        for (u32 y = 0; y < 64; y++) {
            f32 v = (static_cast<f32>(y) + 0.5f) * 0.015625f;
            for (u32 x = 0; x < 64; x++) {
                Unk_Float2 position;
                position.field_0[0].field_0 = (static_cast<f32>(x) + 0.5f) * 0.015625f;
                position.field_0[1].field_0 = v;
                Unk_Float4 color;
                Unk_461e00(&color, &position, &size, &inner);
                pixels[y * 64 + x] = Unk_PackColor(color) >> 24;
            }
        }
        IGPUBaseTexture* texture = static_cast<IGPUBaseTexture*>(field_348);
        texture->vf9(pixels, 0, 0, true);
        texture->vf15(0);
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
    }
    return 0;
}

// 0x7100456190: lets go of the device's resources
s32 CRenderGlare::vf1() {
    m_pGlareSource->vf1();
    m_pBloomResult->vf1();
    m_pGlareResult->vf1();
    if (m_pGlareResultChromaticAberration != nullptr) {
        m_pGlareResultChromaticAberration->vf1();
    }
    if (m_pGlareResultLensDistortionFalloff != nullptr) {
        m_pGlareResultLensDistortionFalloff->vf1();
    }
    if (m_pGlareResultAntialias != nullptr) {
        m_pGlareResultAntialias->vf1();
    }
    if (m_pGlareResultUpsample != nullptr) {
        m_pGlareResultUpsample->vf1();
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        m_ppBloomGeneration[i]->vf1();
    }
    if (m_pStarGeneration != nullptr) {
        m_pStarGeneration->vf1();
    }
    if (m_pStarResult != nullptr) {
        m_pStarResult->vf1();
    }
    if (m_pAnamorphicFlareResult != nullptr) {
        m_pAnamorphicFlareResult->vf1();
    }
    if (m_pGhostGeneration != nullptr) {
        m_pGhostGeneration->vf1();
    }
    if (m_pLightGhostLuminance != nullptr) {
        m_pLightGhostLuminance->vf1();
    }
    if (m_ppAfterimageGeneration != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            m_ppAfterimageGeneration[i]->vf1();
        }
    }
    if (m_pLightShaftBlurSource != nullptr) {
        m_pLightShaftBlurSource->vf1();
    }
    if (m_pLightShaftResult != nullptr) {
        m_pLightShaftResult->vf1();
    }
    if (m_pLightShaftGeneration != nullptr) {
        m_pLightShaftGeneration->vf1();
    }
    PPFX_SAFE_RELEASE_INTERFACE(field_348);
    return CGPUResourceManage::vf1();
}

// 0x7100456380
s32 CRenderGlare::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0) {
        return result;
    }
    return Unk_455850() ? 0 : -1;
}

// 0x71004563c0
s32 CRenderGlare::vf3() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    UNK_DELETE(m_pBloomResult);
    UNK_DELETE(m_pGlareResult);
    UNK_DELETE(m_pGlareResultChromaticAberration);
    UNK_DELETE(m_pGlareResultLensDistortionFalloff);
    UNK_DELETE(m_pGlareResultAntialias);
    UNK_DELETE(m_pGlareResultUpsample);
    UNK_DELETE(m_pGlareSource);
    UNK_DELETE(m_pStarGeneration);
    UNK_DELETE(m_pStarResult);
    UNK_DELETE(m_pAnamorphicFlareResult);
    UNK_DELETE(m_pLightShaftBlurSource);
    UNK_DELETE(m_pLightShaftResult);
    UNK_DELETE(m_pLightShaftGeneration);
    UNK_DELETE_ARRAY(field_1f8);
    UNK_DELETE_ARRAY(field_208);
    UNK_DELETE(m_pGhostGeneration);
    UNK_DELETE(m_pLightGhostLuminance);
    if (m_ppAfterimageGeneration != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            UNK_DELETE(m_ppAfterimageGeneration[i]);
        }
        UNK_DELETE_ARRAY(m_ppAfterimageGeneration);
    }
    UNK_DELETE_ARRAY(field_358);
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        UNK_DELETE(m_ppBloomGeneration[i]);
    }
    UNK_DELETE_ARRAY(m_ppBloomGeneration);
    UNK_DELETE_ARRAY(field_320);
    if (field_300 != nullptr) {
        Unk_49fc60(util->field_29a58, field_308, field_300);
        UNK_DELETE_ARRAY(field_300);
        field_308 = 0;
    }
    Unk_Clear();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x7100453440
s32 CRenderGlare::Unk_453440(s32 a, s32 b, s32 c) {
    if (a == -1) {
        a = field_b0.field_18[7];
    }
    field_2e0 = a;
    if (b == -1) {
        b = field_b0.field_18[8];
    }
    field_2e4 = b;
    if (c == -1) {
        c = field_b0.field_18[9];
    }
    field_2e8 = c;
    return 0;
}

// 0x71004534f0
s32 CRenderGlare::Unk_4534f0(f32 fov, f32 a, f32 b) {
    if (fov <= 0.0f) {
        fov = 0.41421356f;
    }
    field_158 = fov;
    field_15c = a;
    field_160 = b;
    field_154 = atanf(field_158) * 2.0f;
    return 0;
}

// 0x7100442bc0 (GPUInterfaceDevice.cpp): the first of some formats that a
// usage can have, or a fallback
s32 Unk_442bc0(IGPUDevice* self, s32 usage, s32 type, const s32* formats, s32 count, s32 fallback);
// 0x71024e55b0: the device (GPUResourceManage.cpp)
extern IGPUDevice* Unk_24e55b0;

// a new object made with one argument (inline: the argument is evaluated
// before the allocation, as GPUDepthOfField.cpp's)
template <class T, class A>
static inline T* Unk_NewWith(A arg, const char* file, int line) {
    return new (Unk_4b99a0(Unk_238d5f8, sizeof(T), file, line, nullptr)) T(arg);
}
#define UNK_NEW_WITH(T, arg) Unk_NewWith<T>(arg, __FILE__, __LINE__)

// 0x7100453540 (its log lines name it): the description made valid, the
// glare's objects and their textures (with two of them, `field_b0.field_0`'s
// bit 28, the textures one after the other take the two flags in turn), then
// the numbers' defaults
// The levels' description count is set by a test of `level >= 0 && extra`
// after `extra` is known: as a select on both, its known bits allow 7
// iterations, and the loop over the four descriptions is unrolled 7 times as
// in the original (with `if (extra) count = 4;` inside the level test it is
// unrolled 4 times).
// NON_MATCHING: the same calls, allocation lines and stores; the frame is
// 0x10 bytes smaller (the shared slot of the strings and descriptions starts
// at sp+0xa8, sp+0xc0 in the original), the bit-28 tests read field_b0
// through `this` instead of a spilled &field_b0, the results of the
// textures' Unk_49ab20 are tested after they are merged into `result` (the
// original tests the call's own result), and register allocation and the
// order of the constant stores at the end differ
s32 CRenderGlare::CreateSystemObjects() {
    Unk_452f00(&field_b0);
    field_3d8 = field_b0.field_18[5];
    field_40c = field_b0.field_18_f[11];
    Unk_4a2b80();
    Unk_4a1690(field_b0.field_68_p);
    if (field_b0.field_18[2] == 0) {
        s32 formats[1] = {26};
        field_b0.field_18[2] = Unk_442bc0(Unk_24e55b0, 0x20001, 3, formats, 1, 26);
    }
    field_130 = false;
    if (field_b0.field_50) {
        f32 x = static_cast<f32>(field_b0.field_c + 1) / static_cast<f32>(field_b0.field_4);
        f32 y = static_cast<f32>(field_b0.field_10 + 1) / static_cast<f32>(field_b0.field_8);
        f32 scale = 1.0f / static_cast<f32>(static_cast<u32>(field_b0.field_54));
        s32 count = static_cast<s32>(ceilf(logf(x > y ? x : y) / logf(scale))) - 1;
        field_308 = count > 0 ? count : 0;
    }
#line 660
    m_pGlareSource = UNK_NEW_WITH(CRenderTextureArray, (field_10 + "::m_pGlareSource").field_8);
    m_pGlareResult = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pGlareResult").field_8);
    if (field_b0.field_7c) {
#line 664
        m_pGlareResultChromaticAberration =
            UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pGlareResultChromaticAberration").field_8);
    }
    if (field_b0.field_14) {
#line 669
        m_pGlareResultAntialias = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pGlareResultAntialias").field_8);
    }
    if (field_b0.field_70) {
#line 671
        m_pGlareResultLensDistortionFalloff =
            UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pGlareResultLensDistortionFalloff").field_8);
    }
    if (field_b0.field_18_f[0] > 0.0f) {
#line 675
        m_pGlareResultUpsample = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pGlareResultUpsample").field_8);
    }
    s32 levels = field_b0.field_18[5];
#line 679
    m_ppBloomGeneration = UNK_NEW_ARRAY(CGPUResourceManage*, levels);
    for (s32 i = 0; i < levels; i++) {
        Unk_TFXString name = field_10 + "::m_ppBloomGeneration[" + Unk_4525a0(i) + "]";
#line 683
        m_ppBloomGeneration[i] = UNK_NEW_WITH(CRenderTextureArray, name.field_8);
    }
#line 690
    m_pBloomResult = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pBloomResult").field_8);
    field_300 = nullptr;
    if (field_308 != 0) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
#line 700
        field_300 = UNK_NEW_ARRAY(CRenderTexture*, field_308);
        memset(field_300, 0, field_308 * sizeof(CRenderTexture*));
        u32 width = field_b0.field_4;
        u32 height = field_b0.field_8;
        for (s32 i = 0; i < field_308; i++) {
            width = static_cast<u32>(static_cast<f32>(width) / static_cast<f32>(static_cast<u32>(field_b0.field_54)) +
                                     0.99f);
            height = static_cast<u32>(
                static_cast<f32>(height) / static_cast<f32>(static_cast<u32>(field_b0.field_54)) + 0.99f);
            u32 flags = 0;
            if (field_b0.field_0 & 0x10000000) {
                flags = (i & 1) ? 0x2000000 : 0x1000000;
            }
            util->field_29a58->Unk_49fc10(&field_300[i], width, height,
                                          field_b0.field_58 ? field_b0.field_18[4] : field_b0.field_18[2], false,
                                          flags, 0);
        }
    }
    if (field_b0.field_18[10] > 0) {
#line 744
        m_pStarGeneration = UNK_NEW_WITH(CRenderTextureArray, (field_10 + "::m_pStarGeneration").field_8);
        m_pStarResult = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pStarResult").field_8);
#line 747
        m_pAnamorphicFlareResult = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pAnamorphicFlareResult").field_8);
    }
    if (field_b0.field_48) {
#line 751
        m_pGhostGeneration = UNK_NEW_WITH(CRenderTextureArray, (field_10 + "::m_pGhostGeneration").field_8);
    }
    field_b0.field_5c = field_b0.field_5c > 1 ? field_b0.field_5c : 1;
    if (field_b0.field_58) {
#line 758
        m_pLightShaftBlurSource = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pLightShaftBlurSource").field_8);
        m_pLightShaftResult = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pLightShaftResult").field_8);
#line 762
        field_1f8 = UNK_NEW_ARRAY(Unk_453_1f8, field_b0.field_5c);
        if (field_b0.field_5c > 1) {
#line 766
            m_pLightShaftGeneration =
                UNK_NEW_WITH(CRenderTextureArray, (field_10 + "::m_pLightShaftGeneration").field_8);
        }
    } else {
        field_b0.field_5c = 0;
    }
    field_b0.field_64 = field_b0.field_64 > 1 ? field_b0.field_64 : 1;
    if (field_b0.field_60_b && field_b0.field_64 > 0) {
#line 779
        field_208 = UNK_NEW_ARRAY(Unk_453_208, field_b0.field_64);
        m_pLightGhostLuminance = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pLightGhostLuminance").field_8);
    }
    if (field_b0.field_49) {
#line 786
        m_ppAfterimageGeneration = UNK_NEW_ARRAY(CRenderTextureArray*, field_b0.field_4c);
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            Unk_TFXString name = field_10 + "::m_pAfterimageGeneration[" + Unk_4525a0(i) + "]";
#line 790
            m_ppAfterimageGeneration[i] = UNK_NEW_WITH(CRenderTextureArray, name.field_8);
        }
    }
#line 793
    field_358 = UNK_NEW_ARRAY(f32, field_b0.field_4c);
    for (u32 i = 0; i < field_b0.field_4c; i++) {
        field_358[i] = 1.0f;
    }

    u32 flags = field_b0.field_0 & 1;
    u32 flags8 = flags | 8;
    s32 format = field_b0.field_18[2];
    s32 resultFormat = field_b0.field_18[3];
    s32 result;
    {
        s32 sourceFormat = field_b0.field_58 ? field_b0.field_18[4] : field_b0.field_18[2];
        s32 width = field_b0.field_c;
        s32 height = field_b0.field_10;
        Unk_49ab20_Desc descs[4];
        descs[0] = Unk_49ab20_Desc(flags, width, height, sourceFormat);
        if (field_b0.field_71) {
            descs[1] = Unk_49ab20_Desc(flags8, width, height, sourceFormat);
        } else {
            descs[1].field_0 = 0x80000000;
        }
        descs[2] = Unk_49ab20_Desc(flags8, width, height, sourceFormat);
        s32 count = 3;
        if (field_b0.field_18_f[11] > 0.0f) {
            descs[3] = Unk_49ab20_Desc(flags8, width, height, format);
            count = 4;
        }
        if (field_b0.field_0 & 0x10000000) {
            for (s32 i = 0; i < count; i++) {
                descs[i].field_0 |= (i & 1) ? 0x1000000 : 0x2000000;
            }
        }
        result = static_cast<CRenderTextureArray*>(m_pGlareSource)->Initialize(count, descs, 0, false, 0);
        if (result < 0) {
            return result;
        }
    }
    {
        u32 width = field_b0.field_c;
        u32 height = field_b0.field_10;
        bool first = true;
        {
            u32 f = flags;
            if (field_b0.field_0 & 0x10000000) {
                f |= first ? 0x1000000 : 0x2000000;
                first = !first;
            }
            Unk_49ab20_Desc desc(f, width, height, resultFormat);
            s32 r = static_cast<CRenderTexture*>(m_pGlareResult)->Unk_49ab20(&desc);
            if (r < 0) {
                return r;
            }
        }
        if (field_b0.field_7c) {
            u32 f = flags;
            if (field_b0.field_0 & 0x10000000) {
                f |= first ? 0x1000000 : 0x2000000;
                first = !first;
            }
            Unk_49ab20_Desc desc(f, width, height, resultFormat);
            s32 r = static_cast<CRenderTexture*>(m_pGlareResultChromaticAberration)->Unk_49ab20(&desc);
            if (r < 0) {
                result = r;
            }
            if (result < 0) {
                return result;
            }
        }
        if (field_b0.field_70) {
            u32 f = flags;
            if (field_b0.field_0 & 0x10000000) {
                f |= first ? 0x1000000 : 0x2000000;
                first = !first;
            }
            Unk_49ab20_Desc desc(f, width, height, resultFormat);
            s32 r = static_cast<CRenderTexture*>(m_pGlareResultLensDistortionFalloff)->Unk_49ab20(&desc);
            if (r < 0) {
                result = r;
            }
            if (result < 0) {
                return result;
            }
        }
        if (field_b0.field_14) {
            u32 f = flags;
            if (field_b0.field_0 & 0x10000000) {
                f |= first ? 0x1000000 : 0x2000000;
                first = !first;
            }
            Unk_49ab20_Desc desc(f, width, height, resultFormat);
            s32 r = static_cast<CRenderTexture*>(m_pGlareResultAntialias)->Unk_49ab20(&desc);
            if (r < 0) {
                result = r;
            }
            if (result < 0) {
                return result;
            }
        }
        if (field_b0.field_18_f[0] > 0.0f) {
            f32 aspect = static_cast<f32>(field_b0.field_c) / static_cast<f32>(field_b0.field_10);
            u32 upWidth = field_b0.field_c * 2 < static_cast<u32>(field_b0.field_18[1]) ? field_b0.field_c * 2
                                                                                         : field_b0.field_18[1];
            u32 f = flags;
            if (field_b0.field_0 & 0x10000000) {
                f |= first ? 0x1000000 : 0x2000000;
                first = !first;
            }
            Unk_49ab20_Desc desc(f, upWidth, static_cast<u32>(static_cast<f32>(upWidth) / aspect), resultFormat);
            s32 r = static_cast<CRenderTexture*>(m_pGlareResultUpsample)->Unk_49ab20(&desc);
            if (r < 0) {
                result = r;
            }
            if (result < 0) {
                return result;
            }
        }
    }
    {
        u32 f = flags | ((field_b0.field_0 & 0x10000000) ? 0x1000000 : 0);
        Unk_49ab20_Desc desc(f, field_b0.field_c, field_b0.field_10, resultFormat);
        s32 r = static_cast<CRenderTexture*>(m_pBloomResult)->Unk_49ab20(&desc);
        if (r < 0) {
            return r;
        }
    }
    if (m_pStarResult != nullptr) {
        u32 f = flags | ((field_b0.field_0 & 0x10000000) ? 0x1000000 : 0);
        u32 width = field_b0.field_c;
        u32 height = field_b0.field_10;
        Unk_49ab20_Desc desc(f, width, height, resultFormat);
        s32 r = static_cast<CRenderTexture*>(m_pStarResult)->Unk_49ab20(&desc);
        if (r < 0) {
            return r;
        }
        if (m_pAnamorphicFlareResult != nullptr) {
            Unk_49ab20_Desc desc2(f, width, height, resultFormat);
            r = static_cast<CRenderTexture*>(m_pAnamorphicFlareResult)->Unk_49ab20(&desc2);
            if (r < 0) {
                return r;
            }
        }
    }
#line 1005
    field_320 = UNK_NEW_ARRAY(Unk_45_320, levels);
    for (s32 i = 0; i < levels; i++) {
        s32 level = i - field_b0.field_18[6];
        f32 scale;
        s32 count;
        if (level >= 0) {
            scale = ldexpf(1.0f, -1 - level);
            count = 3;
        } else {
            scale = 1.0f;
            count = 2;
        }
        u32 width = static_cast<u32>(scale * static_cast<f32>(field_b0.field_c) + 0.99f);
        u32 height = static_cast<u32>(scale * static_cast<f32>(field_b0.field_10) + 0.99f);
        width = width > 3 ? width : 3;
        height = height > 3 ? height : 3;
        bool extra = false;
        if (level >= 0) {
            extra = width <= field_b0.field_4 / 16 || i == levels - 1;
        }
        if (level >= 0 && extra) {
            count = 4;
        }
        Unk_49ab20_Desc descs[4];
        for (s32 j = 0; j < count; j++) {
            u32 f = flags8;
            if (field_b0.field_0 & 0x10000000) {
                f |= (j & 1) ? 0x1000000 : 0x2000000;
            }
            descs[j] = Unk_49ab20_Desc(f, width, height, format);
        }
        if (extra) {
            descs[3].field_4 *= 2;
            descs[3].field_8 *= 2;
        }
        CRenderTextureArray* array = static_cast<CRenderTextureArray*>(m_ppBloomGeneration[i]);
        s32 r = array->Initialize(count, descs, 0, false, 0);
        if (r < 0) {
            return r;
        }
        field_320[i].field_0 = level + 1;
        field_320[i].field_4 = scale;
        field_320[i].field_18 = Unk_ArrayTexture(m_ppBloomGeneration[i], 0);
        field_320[i].field_20 = Unk_ArrayTexture(m_ppBloomGeneration[i], 1);
        field_320[i].field_30 = nullptr;
        field_320[i].field_28 = nullptr;
        if (extra) {
            field_320[i].field_28 = Unk_ArrayTexture(m_ppBloomGeneration[i], 3);
        }
        field_320[i].field_8 = scale * ldexpf(1.0f, i);
        if (level >= 0) {
            field_320[i].field_10 = Unk_ArrayTexture(m_ppBloomGeneration[i], 2);
        } else {
            field_320[i].field_10 = Unk_ArrayTexture(m_pGlareSource, 2);
        }
    }
    if (m_pStarGeneration != nullptr) {
        Unk_49ab20_Desc descs[18];
        s32 count = field_b0.field_18[10] + 2;
        for (s32 j = 0; j < count; j++) {
            u32 f = flags8;
            if (field_b0.field_0 & 0x10000000) {
                f |= (j & 1) ? 0x1000000 : 0x2000000;
            }
            descs[j] = Unk_49ab20_Desc(f, field_b0.field_c, field_b0.field_10, resultFormat);
        }
        s32 r = static_cast<CRenderTextureArray*>(m_pStarGeneration)->Initialize(count, descs, 0, false, 0);
        if (r < 0) {
#line 1221
            PPFX_ERROR("CRenderGlare::CreateSystemObjects(): m_pStarGeneration->Initialize() failed (0x%x: %s).\n", r,
                       Unk_446df0(r));
        }
    }
    if (m_pGhostGeneration != nullptr) {
        Unk_49ab20_Desc desc(flags8, field_b0.field_c, field_b0.field_10, resultFormat);
        s32 r = static_cast<CRenderTextureArray*>(m_pGhostGeneration)->Initialize(2, &desc, 0, true, 0);
        if (r < 0) {
#line 1246
            PPFX_ERROR("CRenderGlare::CreateSystemObjects(): m_pGhostGeneration->Initialize() failed (0x%x: %s).\n", r,
                       Unk_446df0(r));
        }
    }
    if (m_pLightGhostLuminance != nullptr) {
        Unk_49ab20_Desc desc(flags8, 1, 1, 10);
        s32 r = static_cast<CRenderTexture*>(m_pLightGhostLuminance)->Unk_49ab20(&desc);
        if (r < 0) {
            return r;
        }
    }
    if (m_ppAfterimageGeneration != nullptr && field_b0.field_4c != 0) {
        u32 width = field_b0.field_c;
        u32 height = field_b0.field_10;
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            Unk_49ab20_Desc desc(flags8 | 0x400, width, height, resultFormat);
            s32 r = m_ppAfterimageGeneration[i]->Initialize(2, &desc, 0, true, 0);
            if (r < 0) {
#line 1281
                PPFX_ERROR(
                    "CRenderGlare::CreateSystemObjects(): m_ppAfterimageGeneration[%d]->Initialize() failed (0x%x: "
                    "%s).\n",
                    i, r, Unk_446df0(r));
            }
        }
    }
    if (m_pLightShaftBlurSource != nullptr || m_pLightShaftResult != nullptr) {
        u32 width = field_b0.field_c;
        u32 height = field_b0.field_10;
        u32 f = flags8 | ((field_b0.field_0 & 0x10000000) ? 0x1000000 : 0);
        Unk_49ab20_Desc desc(f, width, height, resultFormat);
        s32 r = static_cast<CRenderTexture*>(m_pLightShaftBlurSource)->Unk_49ab20(&desc);
        if (r < 0) {
            return r;
        }
        Unk_49ab20_Desc desc2(flags, width, height, resultFormat);
        r = static_cast<CRenderTexture*>(m_pLightShaftResult)->Unk_49ab20(&desc2);
        if (r < 0) {
            return r;
        }
        if (m_pLightShaftGeneration != nullptr) {
            Unk_49ab20_Desc desc3(flags, width, height, resultFormat);
            r = static_cast<CRenderTextureArray*>(m_pLightShaftGeneration)
                    ->Initialize(field_b0.field_5c, &desc3, 0, true, 0);
            if (r < 0) {
#line 1328
                PPFX_ERROR(
                    "CRenderGlare::CreateSystemObjects(): m_pLightShaftGeneration->Initialize() failed (0x%x: %s).\n",
                    r, Unk_446df0(r));
            }
        }
    }
    Unk_453440(-1, -1, -1);
    field_148 = 0;
    field_14c = 16.0f;
    field_150 = 1.0f;
    field_1ec = 1.0f;
    field_1f0 = 1.0f;
    field_404 = 1.0f;
    field_408 = 0.001f;
    field_410 = true;
    field_411 = false;
    field_1e4 = 1.0f;
    field_1e8 = 0.5f;
    field_3fc = 1.0f;
    field_400 = 0.01f;
    if (m_pGlareResultUpsample != nullptr) {
        field_418 = field_b0.field_18_f[0];
    } else {
        field_418 = 0.0f;
    }
    if (field_b0.field_5c >= 0) {
        field_1f4 = 0;
    }
    for (s32 i = 0; i < field_b0.field_5c; i++) {
        Unk_GlareRect white;
        white.field_0 = 1.0f;
        white.field_4 = 1.0f;
        white.field_8 = 1.0f;
        white.field_c = 1.0f;
        Unk_4552e0(i, &white, 1.0f, 0.25f, 0.999f, 1.0f, 1.0f, 1.0f);
        field_1f8[i].field_24 = 0.4f;
        field_1f8[i].field_30 = 0.2617994f;
        field_1f8[i].field_28 = 0.4f;
        field_1f8[i].field_2c = 1.0f;
        field_1f8[i].field_34 = white;
        field_1f8[i].field_44 = Unk_Float2(0.5f, 0.5f);
    }
    field_3dc = 64.0f;
    field_3e0 = 2048.0f;
    field_3e4 = 128.0f;
    field_3e8 = 64.0f;
    field_3ec = 1.0f;
    field_3f0 = 1.0f;
    field_3f4 = 1.0f;
    field_3f8 = 1.0f;
    field_180 = true;
    field_184 = 1.0f;
    field_188 = 0.05f;
    field_19c = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    field_190 = 1.0f;
    field_194 = 0.0f;
    field_198 = 0.0f;
    field_1b0 = 1.0f;
    field_1c8 = 1.0f;
    field_1b4 = 1.0f;
    field_1b8 = 0.2f;
    field_1bc = 0.2f;
    field_1c0 = 1.0f;
    field_1c4 = 0.0f;
    field_1cc = 0.2f;
    field_1d0 = 0.5f;
    field_1d4 = 1.0f;
    field_1d8 = 0.0f;
    field_18c = false;
    field_1ac = false;
    field_270[0] = 0.7853982f;
    field_270[1] = field_b0.field_74 / field_b0.field_78;
    field_270[2] = 1.0f;
    field_270[3] = 0.0f;
    field_270[4] = 0.0f;
    field_270[5] = 3.1415927f;
    field_270[6] = 1.0471976f;
    field_270[7] = 0.1f;
    field_290 = 0.25f;
    field_294 = 1;
    field_298 = 1.0f;
    field_26c = false;
    field_1dc = 1.0f;
    field_2ec = 0;
    return 0;
}

// 0x71004552e0
s32 CRenderGlare::Unk_4552e0(s32 view, const Unk_GlareRect* rect, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    field_1f8[view].field_0 = *rect;
    field_1f8[view].field_1c = a;
    field_1f8[view].field_10 = b;
    field_1f8[view].field_5c = c;
    field_1f8[view].field_20 = d;
    field_1f8[view].field_14 = e;
    field_1f8[view].field_18 = f;
    return 0;
}

// 0x710045d350
f32 CRenderGlare::Unk_45d350() {
    if (field_18c) {
        return 1.0f;
    }
    f32 a;
    f32 b;
    if (field_180) {
        a = field_184;
        b = field_188;
    } else {
        a = 0.0f;
        b = 0.0f;
    }
    return a * (b * (field_158 - 0.41421356f) + 0.41421356f);
}

// 0x710045e8a0
s32 CRenderGlare::Unk_45e8a0(bool a, s32 b, bool c, const u64* d, const u64* e, const u64* f, const u64* g,
                             const u64* h, bool i, f32 j, f32 k, f32 l) {
    field_29c = a;
    field_2a0 = b;
    field_2a4 = c;
    field_2a8 = *d;
    field_2b0 = *e;
    field_2b8 = *f;
    field_2c0 = *g;
    field_2c8 = *h;
    field_2d0 = j;
    field_2d4 = k;
    field_2d8 = l;
    field_2dc = i;
    return 0;
}

// 0x710045e940
s32 CRenderGlare::Unk_45e940(const Unk_GlareRect* a, const Unk_GlarePair* b, const Unk_GlarePair* c) {
    field_36c = *a;
    field_37c = *b;
    field_384 = *c;
    return 0;
}

// 0x7100457650
bool CRenderGlare::Unk_457650() {
    bool a = Unk_456bf0();
    bool b = Unk_456f30();
    bool c = Unk_4570b0();
    bool d = Unk_457370();
    s32 frames = field_1f4;
    bool idle = field_200 < 1 || (field_210 == -1 && field_220 < 1);
    bool released = !field_368 || field_360 == 0;
    if ((idle && released) != true) {
        return false;
    }
    if (a || b || c || d) {
        return false;
    }
    if (frames <= 0 && field_418 == 0.0f && !field_b0.field_14 && !field_26c) {
        return true;
    }
    return false;
}

// The kinds of formats 0x710045ed80 and 0x710045ee20 tell apart (inline)
static inline bool Unk_IsGlareFormatA(s32 format) {
    switch (format) {
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
        return true;
    default:
        return false;
    }
}
static inline bool Unk_IsGlareFormatB(s32 format) {
    return format == 24 || format == 25;
}
static inline bool Unk_IsGlareFormatC(s32 format) {
    switch (format) {
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
        return true;
    default:
        return false;
    }
}

// 0x710045ed80 (the zero test and the second kind's as one `&`: with `&&` the
// zero test is a branch of its own, and the first kind's range test can't
// share a `ccmp` with its bits)
f32 CRenderGlare::Unk_45ed80() {
    if (field_b0.field_4a) {
        return field_3e8 * field_3f8;
    }
    s32 format = field_b0.field_18[3];
    if (Unk_IsGlareFormatA(format)) {
        return field_3e0 * field_3f0;
    }
    if ((format != 0) & Unk_IsGlareFormatB(format)) {
        return field_3e4 * field_3f4;
    }
    if (Unk_IsGlareFormatC(format)) {
        return field_3e8 * field_3f8;
    }
    return field_3dc * field_3ec;
}

// 0x710045ee20 (as 0x710045ed80)
f32 CRenderGlare::Unk_45ee20() {
    s32 format = field_b0.field_18[3];
    if (Unk_IsGlareFormatA(format)) {
        return 2048.0f;
    }
    return (format != 0) & Unk_IsGlareFormatB(format) ? 128.0f : 64.0f;
}

// 0x7100456bf0: whether the glare's ghosts have something to draw
bool CRenderGlare::Unk_456bf0() {
    if (m_pStarGeneration == nullptr) {
        return false;
    }
    if (m_pStarResult == nullptr) {
        return false;
    }
    if (field_138 <= 0.0f) {
        return false;
    }
    const Unk_45_170* color = field_170;
    if (color->field_88 < 1) {
        return false;
    }
    if (color->field_90 <= 0.0f) {
        return false;
    }
    if (field_b0.field_18[10] < 1) {
        return false;
    }
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    if (Unk_Luminance(space, color->field_8) <= 0.0f) {
        return false;
    }
    const Unk_45_170* color2 = field_170;
    Unk_410f90 space2;
    Unk_410f90_set(&space2, 0);
    if (Unk_Luminance(space2, color2->field_4c) <= 0.0f) {
        return false;
    }
    return true;
}

// 0x7100456f30: whether the glare has a colour to draw
bool CRenderGlare::Unk_456f30() {
    if (m_pStarGeneration == nullptr) {
        return false;
    }
    if (m_pAnamorphicFlareResult == nullptr) {
        return false;
    }
    if (!field_1ac) {
        return false;
    }
    if (field_138 <= 0.0f) {
        return false;
    }
    const Unk_45_170* color = field_170;
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    if (Unk_Luminance(space, color->field_8) <= 0.0f) {
        return false;
    }
    return true;
}

// 0x71004570b0
bool CRenderGlare::Unk_4570b0() {
    if (m_pGhostGeneration == nullptr) {
        return false;
    }
    if (field_138 <= 0.0f) {
        return false;
    }
    const Unk_45_170* color = field_170;
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    if (Unk_Luminance(space, color->field_8) <= 0.0f) {
        return false;
    }
    const Unk_45_170* color2 = field_170;
    Unk_410f90 space2;
    Unk_410f90_set(&space2, 0);
    if (Unk_Luminance(space2, color2->field_30) <= 0.0f) {
        return false;
    }
    return true;
}

// 0x7100457370
bool CRenderGlare::Unk_457370() {
    if (m_ppAfterimageGeneration == nullptr) {
        return false;
    }
    if (field_138 <= 0.0f) {
        return false;
    }
    const Unk_45_170* color = field_170;
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    if (Unk_Luminance(space, color->field_8) <= 0.0f) {
        return false;
    }
    const Unk_45_170* color2 = field_170;
    if (color2->field_68 <= 0.0f) {
        return false;
    }
    Unk_410f90 space2;
    Unk_410f90_set(&space2, 0);
    if (Unk_Luminance(space2, color2->field_6c) <= 0.0f) {
        return false;
    }
    return true;
}

// 0x7100458420: the glare's luminance
f32 CRenderGlare::Unk_458420() {
    f32 scale = field_134 * 0.035f;
    const Unk_45_170* color = field_170;
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    return scale * Unk_Luminance(space, color->field_8) * field_138;
}

// 0x7100458250: the luminance of field_170's second colour, times the glare's
f32 CRenderGlare::Unk_458250() {
    const Unk_45_170* color = field_170;
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    f32 value = Unk_Luminance(space, color->field_18) * Unk_458420();
    f32 k = field_1e4;
    if (k != 1.0f) {
        s32 n = field_3d8 - 2;
        n = n > 1 ? n : 1;
        f32 count = static_cast<f32>(n);
        value *= count / (powf(k, count * 0.5f) + count - powf(k, 0.5f));
    }
    return value;
}

// 0x7100458580: the luminance of field_170's third colour, times the glare's
f32 CRenderGlare::Unk_458580() {
    f32 scale;
    if (field_410) {
        scale = 1.0f / (static_cast<f32>(field_b0.field_c) * 0.003125f);
    } else {
        scale = 1.0f;
    }
    const Unk_45_170* color = field_170;
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    f32 value = scale * Unk_Luminance(space, color->field_4c) * (field_b0.field_4a ? 0.1f : 0.04f);
    return Unk_458420() * value;
}

}  // namespace PPFX

// 0x710049e3a0 (GPURenderTexturePool.cpp)
s32 Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);
// 0x7100440cf0 (lib/yebis/leaf)
u32 Unk_440cf0_get(u64 device, u32 arg);
// 0x710049c8d0 (lib/yebis/leaf), 0x71004a6160 (GPURenderTextureArray.cpp)
s32 Unk_49c8d0_call(void* self, void* value);
namespace PPFX {
struct Unk_4a5d10_Self;
}
s32 Unk_4a6160(PPFX::Unk_4a5d10_Self* self, void* arg1, s32 arg2, f32 arg3);
// 0x71024e5948 (GPUGlareDef.cpp): the glare definitions
extern PPFX::Unk_4a0b00* Unk_24e5948;

namespace PPFX {

// whether a description can be used (inline in Initialize, whose log line
// names it)
static inline s32 ValidateInitParam(const Unk_453_30* desc) {
    if (desc->field_c < 16 || desc->field_10 < 16) {
        return -6;
    }
    if (desc->field_18[5] != 0 && (desc->field_18[5] < 1 || desc->field_18[5] > 16)) {
        return -6;
    }
    if (desc->field_18[10] > 16) {
        return -6;
    }
    if (desc->field_50 && (desc->field_4 == 0 || desc->field_8 == 0)) {
        return -6;
    }
    return 0;
}

// 0x71004555a0
s32 CRenderGlare::Initialize(const Unk_453_30* desc) {
    s32 result = ValidateInitParam(desc);
    if (result < 0) {
#line 1407
        PPFX_ERROR("CRenderGlare::Initialize(): ValidateInitParam() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        return result;
    }
    IGPUDevice* device = field_20;
    Unk_49ec80();
    field_b0 = *desc;
    field_30 = *desc;
    result = CreateSystemObjects();
    if (result < 0) {
        return result;
    }
    return Unk_49ec30(device);
}

// a render texture array of the glare (inline)
static inline s32 Unk_SetArray(CGPUResourceManage* array, void* arg) {
    return Unk_4a6160(reinterpret_cast<Unk_4a5d10_Self*>(array), arg, 0, 1.0f);
}

// 0x710045e980
s32 CRenderGlare::Unk_45e980(void* arg) {
    s32 result = 0;
    if (m_pStarResult != nullptr) {
        result = Unk_49c8d0_call(m_pStarResult, arg);
    }
    if (m_pStarGeneration != nullptr) {
        result = Unk_SetArray(m_pStarGeneration, arg);
    }
    if (m_pGhostGeneration != nullptr) {
        result = Unk_SetArray(m_pGhostGeneration, arg);
    }
    if (m_pLightShaftBlurSource != nullptr) {
        result = Unk_49c8d0_call(m_pLightShaftBlurSource, arg);
    }
    if (m_pLightShaftResult != nullptr) {
        result = Unk_49c8d0_call(m_pLightShaftResult, arg);
    }
    if (m_pLightShaftGeneration != nullptr) {
        result = Unk_SetArray(m_pLightShaftGeneration, arg);
    }
    Unk_49c8d0_call(m_pBloomResult, arg);
    if (m_ppAfterimageGeneration != nullptr) {
        s32 count = field_b0.field_4c;
        for (s32 i = 0; i < count; i++) {
            if (m_ppAfterimageGeneration[i] != nullptr) {
                result = Unk_SetArray(m_ppAfterimageGeneration[i], arg);
            }
        }
    }
    Unk_SetArray(m_pGlareSource, arg);
    Unk_49c8d0_call(m_pGlareResult, arg);
    if (m_pGlareResultLensDistortionFalloff != nullptr) {
        Unk_49c8d0_call(m_pGlareResultLensDistortionFalloff, arg);
    }
    if (m_pGlareResultChromaticAberration != nullptr) {
        Unk_49c8d0_call(m_pGlareResultChromaticAberration, arg);
    }
    if (m_pGlareResultAntialias != nullptr) {
        Unk_49c8d0_call(m_pGlareResultAntialias, arg);
    }
    if (m_pGlareResultUpsample != nullptr) {
        Unk_49c8d0_call(m_pGlareResultUpsample, arg);
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        result = Unk_SetArray(m_ppBloomGeneration[i], arg);
    }
    for (s32 i = 0; i < field_308; i++) {
        result = Unk_49c8d0_call(field_300[i], arg);
    }
    return result;
}

// whether a format is a fixed-point one (inline; defined below)
static inline bool Unk_IsFixedFormat(s32 format);

// whether the glare is drawn in high precision: a float format, or one of the
// first kind (inline)
static inline bool Unk_IsPreciseFormat(s32 format) {
    return !Unk_IsFixedFormat(format) || Unk_IsGlareFormatA(format);
}

// the afterimage's decay factor, and its least fade, for a format (inline)
static inline f32 Unk_AfterimageFactor(s32 format) {
    return Unk_IsPreciseFormat(format) ? 1.6f : 1.2f;
}
static inline f32 Unk_AfterimageLeast(s32 format) {
    return Unk_IsPreciseFormat(format) ? 0.01f : 0.1f;
}

// the view's current glare texture (inline)
static inline CRenderTexture* Unk_ViewTexture(CRenderGlare* self) {
    if (self->m_ppAfterimageGeneration == nullptr) {
        return nullptr;
    }
    return self->m_ppAfterimageGeneration[static_cast<u32>(self->field_2ec)]->Unk_Texture(-1);
}

// a colour's luminance in the default colour space (inline)
static inline f32 Unk_DefaultLuminance(const Unk_Vector3& color) {
    Unk_410f90 space;
    Unk_410f90_set(&space, 0);
    return Unk_Luminance(space, color);
}

// 0x710045c1e0 (its log line names it): the afterimage, the last frame's
// glare faded into this one's
// NON_MATCHING: the original keeps the glare's sizes and coordinates in
// d8-d15 (here three are spilled at once), divides the rate once after the
// float test (here in both of its blocks) and tests the clamps' bounds the
// other way round; the calls and the stores are the same. The factors come
// from inline functions: written in place, the selects of constants let
// InstCombine fold the square, and the format mask isn't hoisted into x22.
// m_ppAfterimageGeneration is an array of CRenderTextureArray pointers: with a cast at the
// load, the null view array (GVN's PRE of m_ppAfterimageGeneration[view]) is not a trap.
s32 CRenderGlare::GenerateGlare_Afterimage() {
    if (!Unk_457370()) {
        return 0;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    CRenderTexture* previous = Unk_ViewTexture(this);
    CRenderTextureArray* array = m_ppAfterimageGeneration[static_cast<u32>(field_2ec)];
    if (array != nullptr) {
        array->field_90 = 1 - array->field_90;
    }
    CRenderTexture* current = Unk_ViewTexture(this);
    CRenderTexture* glare = field_320[0].field_18;
    current->Unk_49d250(0, 0, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    f32 glareWidth = static_cast<f32>(static_cast<u32>(glare->field_54));
    f32 glareHeight = static_cast<f32>(static_cast<u32>(glare->field_58));
    s32 slot = field_2e4;
    f32 scaleU = glare->field_88;
    f32 scaleV = glare->field_8c;
    f32 offsetU = glare->field_90;
    f32 offsetV = glare->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(current->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(current->field_58));
    f32 luminance = Unk_DefaultLuminance(field_170->field_6c);
    f32 level = Unk_458420();
    f32 rate = field_178 / field_170->field_68;
    f32 k = Unk_AfterimageFactor(field_b0.field_18[3]);
    f32 decay = rate * (k * k);
    f32 lag = rate / k;
    f32 brightness = luminance * 0.125f;
    f32 keep = powf(0.5f, lag / 0.05f);
    f32 fade = 1.0f - powf(0.5f, decay / 0.05f);
    fade = fade < 1.0f && fade > 0.0f ? fade : 1.0f;
    keep = keep < 1.0f && keep > 0.0f ? keep : 0.0f;
    f32 least = Unk_AfterimageLeast(field_b0.field_18[3]);
    f32 value = brightness * level * (fade > least ? fade : least);
    Unk_Float hold = keep < 0.999f ? keep : 0.999f;
    s32 format = field_b0.field_18[3];
    Unk_Float bias;
    if (Unk_IsGlareFormatC(format)) {
        bias = -1.0f / 255.0f;
    } else if (format != 0 && Unk_IsGlareFormatB(format)) {
        bias = -1.0f / 1023.0f;
    } else {
        bias = -1.0f / 32767.0f;
    }
    Unk_Float4 colors[2];
    colors[0] = Unk_Float4(value, value, value, value);
    colors[1] = Unk_Float4(hold, hold, hold, hold);
    Unk_Float4 params[3];
    params[0] = Unk_Float4(bias, bias, bias, bias);
    params[1] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    params[2] = Unk_Float4(64512.0f, 64512.0f, 64512.0f, 64512.0f);
    Unk_GPUTexture* textures[2] = {Unk_GetTexture(glare), Unk_GetTexture(previous)};
    s32 result = util->Unk_4776f0(0.0f, 0.0f, width, height, 0.0f, 0.0f, scaleU * glareWidth + offsetU,
                                  scaleV * glareHeight + offsetV, 2, textures, colors, params, slot, 0);
    if (result < 0) {
#line 4956
        PPFX_ERROR("CRenderGlare::GenerateGlare_Afterimage(): pTexUtil->DrawRectGPU_MadOffsetTn() failed (0x%x: %s).\n",
                   result, Unk_446df0(result));
    }
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    return result;
}

// 0x710045c880: each view's glare, then all of them into m_pLightShaftResult.
// The body is inside `if (count > 0)` and both tests are `count > 1`: with an
// early return for `count < 1`, the copy of the loop unswitched for a single
// view is laid out first and the test after the loop becomes `b.le`.
s32 CRenderGlare::Unk_45c880() {
    s32 count = field_1f4;
    if (count > 0) {
        for (s32 i = 0; i < count; i++) {
            Unk_45ca70(count > 1 ? Unk_ArrayTexture(m_pLightShaftGeneration, i) : nullptr, i);
        }
        if (count > 1) {
            CRenderTexture* textures[16] = {};
            for (s32 i = 0; i < count; i++) {
                textures[i] = Unk_ArrayTexture(m_pLightShaftGeneration, i);
            }
            CTextureUtil* util = Unk_GetTextureUtil();
            Unk_ReleaseTextureUtil();
            util->Unk_48d220(1.0f, 1.0f, m_pLightShaftResult, count, textures, nullptr, 0, 0);
        }
    }
    return 0;
}

}  // namespace PPFX

// 0x71024e58c0 (GPUGlareDef.cpp): the star definitions
extern PPFX::Unk_4a0540* Unk_24e58c0;

namespace PPFX {

// 0x71004593f0: the glare's star into m_pStarResult (`flag`: the sixth star
// definition into m_pAnamorphicFlareResult), with m_pStarGeneration's textures; without `flag` only
// when the ghosts changed. The ghosts' colours go into m_pGlareSource's fourth
// texture first, once a frame.
s32 CRenderGlare::Unk_4593f0(bool flag) {
    if (!flag && !Unk_456bf0()) {
        return 0;
    }
    Unk_4a0540 star;
    const Unk_4a0540* definition;
    if (flag) {
        star.Unk_4a0540_Copy(Unk_24e58c0[6]);
        definition = &star;
    } else {
        definition = &reinterpret_cast<const Unk_4a0b00*>(field_170)->field_80;
    }
    s32 lines = definition->field_8;
    s32 count = lines < field_b0.field_18[10] ? lines : field_b0.field_18[10];
    CRenderTexture* target = Unk_ArrayTexture(m_pGlareSource, 2);
    if (field_b0.field_18_f[11] > 0.0f && field_40c > 0.0f) {
        s32 levels = field_3d8;
        CRenderTexture* sources[3];
        sources[0] = Unk_ArrayTexture(m_pGlareSource, 2);
        const Unk_45_320* items = field_320;
        s32 sourceCount = levels > 1 ? 3 : 2;
        sources[1] = items[0].field_18;
        sources[2] = levels >= 2 ? items[1].field_18 : nullptr;
        target = Unk_ArrayTexture(m_pGlareSource, 3);
        if (!field_41c) {
            f32 ghost = field_40c;
            f32 rest = 1.0f - ghost;
            f32 scale = levels > 1 ? rest : 1.0f;
            Unk_Float4 colors[3];
            for (s32 i = 0; i < 4; i++) {
                colors[0].field_0[i].field_0 = rest;
            }
            for (s32 i = 0; i < 4; i++) {
                colors[1].field_0[i].field_0 = ghost * scale;
            }
            for (s32 i = 0; i < 4; i++) {
                colors[2].field_0[i].field_0 = ghost * ghost;
            }
            CTextureUtil* util = Unk_GetTextureUtil();
            Unk_ReleaseTextureUtil();
            util->Unk_48d220(1.0f, 1.0f, target, sourceCount, sources, colors, 0, false);
            field_41c = true;
        }
    }
    CRenderTexture** all = static_cast<CRenderTextureArray*>(m_pStarGeneration)->field_38;
    CRenderTexture** pair = &all[field_b0.field_18[10]];
    CRenderTexture* textures[16];
    if (count > 0) {
        memcpy(textures, all, static_cast<u32>(count) * sizeof(CRenderTexture*));
    }
    for (s32 i = count; i < 16; i++) {
        textures[i] = nullptr;
    }
    CRenderTexture* pairs[2];
    memcpy(pairs, pair, sizeof(pairs));
    Unk_459730(definition, target, flag ? m_pAnamorphicFlareResult : m_pStarResult, textures, pairs, 2, flag);
    return 0;
}

// 0x71004385e0 (GPUPostEffect.cpp): whether a format is a fixed-point one
bool Unk_4385e0(s32 format);

// whether a format's channels are 32-bit floats (inline)
static inline bool Unk_IsFloat32Format(s32 format) {
    switch (format) {
    case 2:
    case 6:
    case 16:
    case 20:
    case 21:
    case 40:
    case 41:
        return true;
    default:
        return false;
    }
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
// whether a format is a fixed-point one (inline)
static inline bool Unk_IsFixedFormat(s32 format) {
    bool f32 = Unk_IsFloat32Format(format);
    if (Unk_IsFloat16Format(format)) {
        return false;
    }
    return !((format == 26) | f32);
}

// whether a render texture has been made (inline)
static inline bool Unk_TextureMade(const CGPUResourceManage* texture) {
    return static_cast<const CRenderTexture*>(texture)->field_2c.field_c != 0;
}
// whether a render texture array has been made (inline)
static inline bool Unk_ArrayMade(const CGPUResourceManage* array) {
    const CRenderTextureArray* self = static_cast<const CRenderTextureArray*>(array);
    return self->field_30 != 0 && self->field_38 != nullptr;
}

}  // namespace PPFX

// 0x71024e58c8, 0x71024e5908 (GPUGlareDef.cpp): the star's colours, and the
// same in another order
extern PPFX::Unk_Float4 Unk_24e58c8[4];
extern PPFX::Unk_Float4 Unk_24e5908[4];
// 0x7100440c40, 0x7100440d50 (lib/yebis/leaf)
u32 Unk_440c40_get(u64 device, u32 arg);
u32 Unk_440d50_get(u64 device, u32 arg);
// 0x7100471460 (lib/yebis/leaf)
void Unk_471460_update(u64 self, u32 arg1, u32 arg2);

namespace PPFX {

// an absolute value (inline)
static inline f32 Unk_Abs(f32 x) {
    return x > 0.0f ? x : -x;
}
// from `a` to `b` by `t` (inline)
static inline f32 Unk_Lerp(f32 a, f32 b, f32 t) {
    return a + t * (b - a);
}

// a colour between white and `color`, `ratio` of the way to white, then
// `t` of the way from white (inline)
static inline void Unk_Float4Lerp(Unk_Float4* out, const Unk_Float4* a, const Unk_Float4* b, f32 t) {
    for (s32 c = 0; c < 4; c++) {
        out->field_0[c].field_0 = a->field_0[c].field_0 + t * (b->field_0[c].field_0 - a->field_0[c].field_0);
    }
}
static inline void Unk_ColorLerp(Unk_Float4* out, const Unk_Float4* white, const Unk_Float4* color, f32 ratio, f32 t) {
    Unk_Float4 x;
    Unk_Float4Lerp(&x, color, white, ratio);
    Unk_Float4Lerp(out, white, &x, t);
}
// 0x7100459730: the star's lines drawn from `target`, each through the
// textures of `pair` in turn, into `textures`, and those added up into
// `texture` (`flag`: the sixth star definition's colours). Its two
// function-local statics (and 0x7100458e20's) complete the TU's merged
// statics, which the static initialiser 0x710045fbe0 needs.
// The fourth case's format test is `(format != 0) & Unk_IsGlareFormatB(format)`
// (closer than `&&`).
// NON_MATCHING: register allocation from the start (`this` in x19, not x21),
// the line loop's blocks are laid out in another order (the format test
// before the line's parameters), the constants the loop uses aren't hoisted
// and spilled as the original does, and the pass loop's two sample loops
// differ; the colour table loop and the format thresholds match the
// original's shape.
s32 CRenderGlare::Unk_459730(const Unk_4a0540* star, CRenderTexture* target, CGPUResourceManage* texture,
                             CRenderTexture** textures, CRenderTexture** pair, s32 count, bool flag) {
    f32 intensity;
    s32 lines;
    if (flag) {
        Unk_410f90 space;
        Unk_410f90_set(&space, 0);
        Unk_Vector3 white = {{1.0f, 1.0f, 1.0f}};
        Unk_Luminance(space, white);
        lines = star->field_8 < field_b0.field_18[10] ? star->field_8 : field_b0.field_18[10];
        f32 scale;
        if (field_410) {
            scale = 1.0f / (static_cast<f32>(field_b0.field_c) * 0.003125f);
        } else {
            scale = 1.0f;
        }
        f32 m = field_1b8 > field_1bc ? field_1b8 : field_1bc;
        m = m > field_1c0 ? m : field_1c0;
        m = m > field_1c4 ? m : field_1c4;
        f32 value = field_1b0 * m;
        if (field_1ac) {
            value = value > 5.9604645e-08f ? value : 5.9604645e-08f;
        }
        value = (field_b0.field_4a ? 0.1f : 0.04f) * (scale * value);
        intensity = Unk_458420() * value;
    } else {
        const Unk_45_170* color = field_170;
        Unk_410f90 space;
        Unk_410f90_set(&space, 0);
        if (!(Unk_Luminance(space, color->field_8) <= 0.0f)) {
            Unk_410f90 space2;
            Unk_410f90_set(&space2, 0);
            Unk_Luminance(space2, color->field_18);
        }
        lines = star->field_8 < field_b0.field_18[10] ? star->field_8 : field_b0.field_18[10];
        intensity = Unk_458580();
    }
    f32 power = powf(intensity, 0.2f);
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    CRenderTexture* last = pair[0];
    f32 size[2];
    size[1] = static_cast<f32>(static_cast<u32>(last->field_54));
    size[0] = static_cast<f32>(static_cast<u32>(last->field_58));
    bool anamorphic = reinterpret_cast<const Unk_4a0b00*>(field_170)->field_64;
    f32 longest = size[1] > size[0] ? size[1] : size[0];
    static Unk_Float4 s_colors[8][4];
    static const Unk_Float4 s_white(1.0f, 1.0f, 1.0f, 1.0f);
    const Unk_Float4* chroma;
    f32 aberration;
    if (flag) {
        chroma = Unk_24e58c8;
        aberration = 0.0f;
    } else {
        f32 a = reinterpret_cast<const Unk_4a0b00*>(field_170)->field_60;
        aberration = fabsf(a);
        chroma = a < 0.0f ? Unk_24e5908 : Unk_24e58c8;
    }
    logf(longest);
    for (s32 p = 0; p < 8; p++) {
        f32 ratio = static_cast<f32>(p + 1) / 8.0f;
        s_colors[p][0] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        for (s32 s = 1; s < 4; s++) {
            Unk_ColorLerp(&s_colors[p][s], &s_white, &chroma[s], ratio, aberration * 1.5f);
        }
    }
    f32 inclination = flag ? 1.5707964f : reinterpret_cast<const Unk_4a0b00*>(field_170)->field_5c;
    if (fabsf(inclination) >= 6.2831855f) {
        inclination = -6.2831855f / static_cast<f32>(lines) * 0.5f;
    }
    if (star->field_18) {
        inclination -= field_17c;
    }
    f32 weights[16];
    CRenderTexture* outputs[16];
    s32 outputCount = 0;
    bool plain = !anamorphic || flag;
    bool single = anamorphic && !flag;
    f32 aspect = static_cast<f32>(field_b0.field_c) / static_cast<f32>(field_b0.field_10) / (size[1] / size[0]);
    for (s32 d = 0; d < lines; d++) {
        f32 length;
        f32 attenuation;
        f32 angle;
        if (star->field_20 != nullptr) {
            const Unk_4a0540_Line& line = star->field_20[d];
            length = line.field_0;
            attenuation = line.field_4;
            angle = line.field_8;
        } else {
            length = star->field_c;
            f32 even = star->field_10;
            f32 odd = star->field_14;
            attenuation = odd > 0.0f && (d & 1) ? odd : even;
            angle = Unk_Radians(360.0f / static_cast<f32>(star->field_8)) * static_cast<f32>(d);
        }
        if (flag) {
            attenuation *= field_1b4;
        }
        f32 rad = inclination - angle;
        if (field_20->field_58) {
            rad = -rad;
        }
        f32 sn = sinf(rad);
        f32 cs = cosf(rad);
        f32 screen = static_cast<f32>(field_b0.field_c) * 0.003125f;
        f32 fov = 1.0f / (field_158 + field_158);
        f32 k = field_1e8;
        if (k != 1.0f) {
            fov = expf(k * logf(fov));
        }
        f32 step = length / (screen * fov) / 6.0f / fmaxf(attenuation, 1e-05f);
        f32 scale = single ? step / 1.5f : step;
        s32 format = last->field_2c.field_c;
        Unk_Float limit = field_408;
        f32 threshold = limit.field_0;
        if (Unk_4385e0(format)) {
            if (Unk_IsGlareFormatA(format)) {
                threshold = limit.field_0 > 1.5259022e-05f ? limit.field_0 : 1.5259022e-05f;
            } else if ((format != 0) & Unk_IsGlareFormatB(format)) {
                threshold = limit.field_0 > 0.0009775171f ? limit.field_0 : 0.0009775171f;
            } else if (Unk_IsGlareFormatC(format)) {
                threshold = limit.field_0 > 0.003921569f ? limit.field_0 : 0.003921569f;
            }
        }
        f32 range = logf(threshold) / -0.6931472f / scale;
        f32 levels = logf(range) / 1.3862944f;
        s32 passes = static_cast<s32>(single ? levels + 1.0f : ceilf(levels));
        s32 samples;
        if (single) {
            samples = 4;
        } else {
            samples = static_cast<s32>(ceilf(range * 4.0f / powf(4.0f, static_cast<f32>(passes))));
            if (samples >= 4 || samples == 0) {
                samples = 4;
            }
        }
        Unk_440c40_get(reinterpret_cast<u64>(field_20), 0);
        field_20->vf44(0);
        CRenderTexture* source = target;
        s32 work = 0;
        Unk_Float stepV0 = aspect * (length / size[0]) * cs;
        Unk_Float stepU0 = length / size[1] * sn;
        Unk_Float stepV = stepV0;
        Unk_Float stepU = stepU0;
        f32 offsetScale = 1.0f / step * 1.5f;
        f32 weight = 1.0f;
        for (s32 p = 0; p < passes; p++) {
            bool lastPass = single ? p == passes - 2 : p == passes - 1;
            if (p != 0) {
                weight *= 1.0f / power;
            }
            f32 base = p == 0 ? 0.1875f : power;
            Unk_Float w[4];
            if (single) {
                if (p == passes - 1) {
                    for (s32 i = 0; i < 4; i++) {
                        w[i] = base * powf(0.5f, static_cast<f32>(i) * 0.25f);
                    }
                } else {
                    for (s32 i = 0; i < 4; i++) {
                        w[i] = base * powf(0.5f, scale * static_cast<f32>(i) * 4.0f);
                    }
                }
            } else {
                for (s32 i = 0; i < 4; i++) {
                    w[i] = base * powf(0.5f, scale * static_cast<f32>(i));
                }
            }
            f32 reach = length * powf(4.0f, static_cast<f32>(p));
            s32 n = static_cast<s32>(ceilf((longest + (reach + -1.0f)) / reach));
            s32 limit = lastPass ? samples : 4;
            n = n < 4 ? n : 4;
            if (single) {
                n = 4;
            }
            n = n < limit ? n : limit;
            CRenderTexture* dest;
            if (p != passes - 1 && n > 3) {
                dest = pair[work];
            } else {
                dest = textures[d];
                weights[outputCount] = weight;
                outputs[outputCount] = dest;
                outputCount++;
            }
            f32 u, v;
            Unk_GetCoords(source, &u, &v);
            dest->Unk_49d250(0, 0, 1, 0, 0);
            f32 width = static_cast<f32>(static_cast<u32>(dest->field_54));
            f32 height = static_cast<f32>(static_cast<u32>(dest->field_58));
            bool current = plain || p != passes - 1;
            Unk_Float curU = current ? stepU : stepU0;
            Unk_Float curV = current ? stepV : stepV0;
            Unk_Float4 offsets[4];
            Unk_Float4 colors[4];
            for (s32 i = 0; i < n; i++) {
                offsets[i].field_0[2].field_0 = 0.0f;
                offsets[i].field_0[3].field_0 = 0.0f;
                if (current) {
                    for (s32 c = 0; c < 4; c++) {
                        colors[i].field_0[c].field_0 = s_colors[7 - p][i].field_0[c].field_0 * w[i].field_0;
                    }
                    offsets[i].field_0[0].field_0 = u * (curU.field_0 * static_cast<f32>(i) + 0.0f);
                    offsets[i].field_0[1].field_0 = v * (curV.field_0 * static_cast<f32>(i) + 0.0f);
                } else {
                    for (s32 c = 0; c < 4; c++) {
                        colors[i].field_0[c].field_0 = chroma[i].field_0[c].field_0 * w[i].field_0;
                    }
                    offsets[i].field_0[0].field_0 = offsetScale * (u * (curU.field_0 * static_cast<f32>(i) + 0.0f));
                    offsets[i].field_0[1].field_0 = offsetScale * (v * (curV.field_0 * static_cast<f32>(i) + 0.0f));
                }
            }
            Unk_GetTexture(source)->vf15(0);
            util->DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u, v, n, offsets, colors,
                                       Unk_GetTexture(source), field_2e4, 0);
            last = dest;
            if (n < 4) {
                break;
            }
            work = (work + 1) % count;
            stepV = stepV.field_0 * 4.0f;
            stepU = stepU.field_0 * 4.0f;
            scale *= 4.0f;
            source = dest;
        }
    }
    if (texture != nullptr) {
        field_428 = outputCount > 0;
        if (outputCount > 0) {
            for (s32 i = 0; i < outputCount; i++) {
                Unk_GetTexture(outputs[i])->vf17(1);
            }
            f32 value = intensity * (16.0f / 3.0f);
            util->Unk_48d550(static_cast<CRenderTexture*>(texture), outputCount, outputs,
                             reinterpret_cast<const Unk_Float*>(weights), value, value, value, value, field_1f0,
                             field_2e4, false);
            for (s32 i = 0; i < outputCount; i++) {
                Unk_GetTexture(outputs[i])->vf17(0);
            }
        }
    }
    return 0;
}

// the smaller of two numbers (inline)
static inline const Unk_Float& Unk_MinFloat(const Unk_Float& a, const Unk_Float& b) {
    return a.field_0 < b.field_0 ? a : b;
}

// a ghost's size, the rest of it zero (inline)
static inline void Unk_SetGhost(Unk_Float4* ghost, f32 size) {
    ghost->field_0[1].field_0 = size;
    ghost->field_0[2].field_0 = 0.0f;
    ghost->field_0[3].field_0 = 0.0f;
}

// the largest of four numbers (inline)
static inline f32 Unk_Max4(f32 a, f32 b, f32 c, f32 d) {
    f32 m = a > b ? a : b;
    m = m > c ? m : c;
    return m > d ? m : d;
}

// the level `offset` after field_414, clamped to the levels, and the scale of
// the colours drawn from it (inline)
static inline s32 Unk_GhostLevel(const CRenderGlare* self, s32 offset, f32* scale) {
    s32 wanted = self->field_414 + offset;
    s32 last = self->field_3d8 - 1;
    s32 level = wanted < 0 ? 0 : (wanted > last ? last : wanted);
    s32 below = level - wanted;
    f32 fade = powf(4.0f, static_cast<f32>(below < 0 ? below : 0));
    f32 n = static_cast<f32>(level);
    *scale = fade * (1.0f / (powf(self->field_1e4, n) * powf(self->field_3fc, n)));
    return level;
}

// 0x710045a820: the light ghosts, from four of the glare's levels into
// m_pGhostGeneration's second texture, then from that (and the bloom and the
// anamorphic flare, if any) into its first
// NON_MATCHING: the same calls, constants and stores; the colours' array is
// 0x10 bytes higher on the stack, the first pass's parameters are stored in
// other pairs, the blocks of field_170->field_48's two cases are laid out
// the other way round and register allocation differs throughout
s32 CRenderGlare::Unk_45a820() {
    if (!Unk_4570b0()) {
        return 0;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    s32 levels = field_3d8;
    f32 shine;
    {
        const Unk_45_170* color = field_170;
        Unk_410f90 space;
        Unk_410f90_set(&space, 0);
        shine = Unk_Luminance(space, color->field_30);
    }
    f32 glare = Unk_458420();
    f32 intensity = field_1c8 * Unk_Max4(field_1cc, field_1d0, field_1d4, field_1d8);
    if (field_1ac) {
        intensity = intensity > 5.96046448e-08f ? intensity : 5.96046448e-08f;
    }
    f32 intensity2 = field_1b0 * Unk_Max4(field_1b8, field_1bc, field_1c0, field_1c4);
    if (field_1ac) {
        intensity2 = intensity2 > 5.96046448e-08f ? intensity2 : 5.96046448e-08f;
    }
    s32 current = field_414;
    f32 second;
    {
        const Unk_45_170* color = field_170;
        Unk_410f90 space;
        Unk_410f90_set(&space, 0);
        second = Unk_Luminance(space, color->field_18);
    }
    f32 second2;
    {
        const Unk_45_170* color = field_170;
        Unk_410f90 space;
        Unk_410f90_set(&space, 0);
        second2 = Unk_Luminance(space, color->field_18);
    }
    f32 half = field_1c8 * Unk_Max4(field_1cc, field_1d0, field_1d4, field_1d8);
    if (field_1ac) {
        half = half > 5.96046448e-08f ? half : 5.96046448e-08f;
    }
    half *= 0.5f;
    bool anamorphic = Unk_456f30();

    // the first pass: each ghost's place on the axis and size, and colour
    Unk_Float4 params[8] = {
        Unk_Float4(-0.33f, -0.33f, -0.33f, -0.33f), Unk_Float4(-0.56f, -0.56f, -0.56f, -0.56f),
        Unk_Float4(-0.75f, -0.75f, -0.75f, -0.75f), Unk_Float4(-0.4f, -0.4f, -0.4f, -0.4f),
        Unk_Float4(-0.85f, -0.85f, -0.85f, -0.85f), Unk_Float4(-0.25f, -0.25f, -0.25f, -0.25f),
        Unk_Float4(-0.5f, -0.5f, -0.5f, -0.5f),     Unk_Float4(-1.0f, -1.0f, -1.0f, -1.0f),
    };
    Unk_SetGhost(&params[0], powf(2.5f, field_1dc * 0.857632875f));
    Unk_SetGhost(&params[1], powf(2.5f, field_1dc * 0.444071203f));
    Unk_SetGhost(&params[2], powf(2.5f, field_1dc * 0.508654892f));
    Unk_SetGhost(&params[3], powf(2.5f, field_1dc * 0.821543097f));
    Unk_SetGhost(&params[4], powf(2.5f, field_1dc * 0.558458388f));
    Unk_SetGhost(&params[5], powf(2.5f, field_1dc * 0.610605538f));
    Unk_SetGhost(&params[6], powf(2.5f, field_1dc * 0.0887189433f));
    Unk_SetGhost(&params[7], powf(2.5f, field_1dc * 0.963040113f));
    Unk_Float4 colors[8] = {
        Unk_Float4(0.05f, 0.02f, 0.03f, 0.0f),    Unk_Float4(0.015f, 0.05f, 0.03f, 0.0f),
        Unk_Float4(0.03f, 0.015f, 0.05f, 0.0f),   Unk_Float4(0.05f, 0.03f, 0.015f, 0.0f),
        Unk_Float4(0.015f, 0.05f, 0.035f, 0.0f),  Unk_Float4(0.0225f, 0.045f, 0.075f, 0.0f),
        Unk_Float4(0.015f, 0.05f, 0.025f, 0.0f),  Unk_Float4(0.175f, 0.125f, 0.25f, 0.0f),
    };
    CRenderTexture* sources[4];
    f32 scale;
    if (field_170->field_48) {
        sources[0] = Unk_ArrayTexture(m_pGlareSource, 2);
        s32 wanted = current + 1;
        s32 level = wanted < 0 ? 0 : (wanted > levels - 1 ? levels - 1 : wanted);
        f32 n = static_cast<f32>(level);
        scale = 1.0f / (powf(field_1e4, n) * powf(field_3fc, n));
        for (s32 i = 3; i < 5; i++) {
            for (s32 j = 0; j < 4; j++) {
                colors[i].field_0[j].field_0 *= scale;
            }
        }
        sources[1] = field_320[level].Unk_Texture28();
        scale = 1.0f / (powf(field_1e4, n) * powf(field_3fc, n));
        sources[2] = field_320[level].Unk_Texture28();
    } else {
        s32 level = Unk_GhostLevel(this, 0, &scale);
        sources[0] = field_320[level].field_18;
        for (s32 i = 0; i < 3; i++) {
            for (s32 j = 0; j < 4; j++) {
                colors[i].field_0[j].field_0 *= scale;
            }
        }
        level = Unk_GhostLevel(this, 1, &scale);
        sources[1] = field_320[level].field_18;
        for (s32 i = 3; i < 5; i++) {
            for (s32 j = 0; j < 4; j++) {
                colors[i].field_0[j].field_0 *= scale;
            }
        }
        level = Unk_GhostLevel(this, 2, &scale);
        sources[2] = field_320[level].field_18;
    }
    for (s32 i = 5; i < 7; i++) {
        for (s32 j = 0; j < 4; j++) {
            colors[i].field_0[j].field_0 *= scale;
        }
    }
    s32 level = Unk_GhostLevel(this, 2, &scale);
    sources[3] = field_320[level].field_18;
    for (s32 j = 0; j < 4; j++) {
        colors[7].field_0[j].field_0 = scale * colors[7].field_0[j].field_0 * 0.3333f;
    }
    // the sizes by the field of view
    f32 fov = field_250_f > 0.0f ? field_268 / field_250_f * 0.5f : field_158;
    f32 zoom = logf(fov);
    params[1].field_0[0].field_0 *= cosf(zoom * 1.5f) * 0.25f + 0.75f;
    params[3].field_0[0].field_0 *= cosf(zoom * -2.5f + 0.0f) * 0.5f + 1.5f;
    params[4].field_0[0].field_0 *= cosf(zoom * -0.9f + -0.2f) * 0.25f + 0.7f;
    params[6].field_0[0].field_0 *= cosf(zoom * -1.3f + 0.4f) * 0.3f + 0.7f;
    for (s32 i = 0; i < 8; i++) {
        params[i].field_0[0].field_0 = std::max(-1.0f, params[i].field_0[0].field_0);
    }
    f32 size = field_170->field_44;
    if (field_1dc == 0.0f) {
        size *= 0.5f;
    }
    s32 result = util->Unk_488d90(sources[0], sources[1], sources[2], sources[3],
                                  reinterpret_cast<Unk_GPUTexture*>(field_348),
                                  Unk_ArrayTexture(m_pGhostGeneration, 1), params, colors, size * 2.0f, field_2e4, 0);
    if (result < 0) {
        return result;
    }

    // the second pass, with the anamorphic flare's colours
    f32 product = intensity * intensity2 * 0.5f;
    f32 bright = glare * (shine * 0.05f * 20.0f);
    f32 blue = 0.5f / second2 * 0.125f;
    f32 red = product / second;
    Unk_Float4 flare(red * 0.1299f, red * 0.09806f, red * 0.6682f, red * 0.0f);
    Unk_Float4 streak(blue * 0.267f, blue * 0.128f, blue * 0.586f, blue * 0.0f);
    Unk_Float4 color(field_1cc * half, field_1d0 * half, field_1d4 * half, field_1d8 * half);
    params[0].field_0[0].field_0 = 1.0f;
    Unk_SetGhost(&params[0], exp2f(field_1dc * 0.999957085f));
    params[1].field_0[0].field_0 = 0.2f;
    Unk_SetGhost(&params[1], exp2f(field_1dc * 0.937521279f));
    params[2].field_0[0].field_0 = -0.3f;
    Unk_SetGhost(&params[2], exp2f(field_1dc * 0.943598986f));
    params[3].field_0[0].field_0 = -1.0f;
    Unk_SetGhost(&params[3], exp2f(field_1dc * 0.797693849f));
    params[4].field_0[0].field_0 = -7.0f;
    Unk_SetGhost(&params[4], exp2f(field_1dc * 0.115039289f));
    params[5].field_0[0].field_0 = 4.0f;
    Unk_SetGhost(&params[5], exp2f(field_1dc * 0.57916832f));
    params[6].field_0[0].field_0 = 2.0f;
    Unk_SetGhost(&params[6], exp2f(field_1dc * 0.100258522f));
    params[7].field_0[0].field_0 = -1.6f;
    Unk_SetGhost(&params[7], exp2f(field_1dc * 0.11453905f));
    colors[0] = Unk_Float4(bright * 0.15f, bright * 0.375f, bright * 1.5f, bright * 0.0f);
    colors[1] = Unk_Float4(bright * 1.0f, bright * 0.2f, bright * 0.5f, bright * 0.0f);
    colors[2] = Unk_Float4(bright * 0.6f, bright * 1.8f, bright * 1.6f, bright * 0.0f);
    colors[3] = Unk_Float4(bright * 1.44f, bright * 0.72f, bright * 4.08f, bright * 0.0f);
    colors[4] = Unk_Float4(bright * 0.032f, bright * 0.008f, bright * 0.16f, bright * 0.0f);
    colors[5] = Unk_Float4(bright * 0.014f, bright * 0.002f, bright * 0.02f, bright * 0.0f);
    colors[6] = Unk_Float4(bright * 0.001f, bright * 0.004f, bright * 0.02f, bright * 0.0f);
    colors[7] = Unk_Float4(bright * 0.01f, bright * 0.0005f, bright * 0.002f, bright * 0.0f);
    CRenderTexture* first = Unk_ArrayTexture(m_pGhostGeneration, 1);
    CRenderTexture* bloom;
    CRenderTexture* flareSource;
    if (field_170->field_48) {
        params[5].field_0[0].field_0 = -3.0f;
        params[4].field_0[0].field_0 = -1.0f;
        level = Unk_GhostLevel(this, 0, &scale);
        bloom = field_320[level].field_18;
        bool shown = false;
        if (anamorphic) {
            const Unk_45_170* color = field_170;
            Unk_410f90 space;
            Unk_410f90_set(&space, 0);
            shown = Unk_Luminance(space, color->field_18) > 0.0f;
        }
        if (shown) {
            bloom = static_cast<CRenderTexture*>(m_pBloomResult);
            params[4].field_0[0].field_0 = -1.0f;
            params[5].field_0[0].field_0 = -1.8f;
            params[5].field_0[3].field_0 = 0.98f;
            params[6].field_0[0].field_0 = -1.8f;
            params[6].field_0[3].field_0 = 0.98f;
            for (s32 j = 0; j < 4; j++) {
                colors[4].field_0[j].field_0 = streak.field_0[j].field_0 * 2.0f;
                colors[5].field_0[j].field_0 = flare.field_0[j].field_0 * 0.4f * 2.0f;
                colors[6].field_0[j].field_0 = flare.field_0[j].field_0 * 2.0f;
            }
            colors[5].field_0[2].field_0 *= 1.5f;
        } else {
            for (s32 j = 0; j < 4; j++) {
                colors[4].field_0[j].field_0 = scale * colors[4].field_0[j].field_0 * 8.0f;
            }
        }
        for (s32 j = 0; j < 4; j++) {
            colors[5].field_0[j].field_0 = scale * (colors[5].field_0[j].field_0 * 2.0f);
        }
        level = Unk_GhostLevel(this, 0, &scale);
        if (anamorphic) {
            flareSource = static_cast<CRenderTexture*>(m_pAnamorphicFlareResult);
            params[7].field_0[0].field_0 = -1.0f;
            colors[7] = color;
        } else {
            flareSource = field_320[level].field_18;
            for (s32 j = 0; j < 4; j++) {
                colors[7].field_0[j].field_0 *= scale;
            }
        }
    } else {
        level = Unk_GhostLevel(this, 2, &scale);
        f32 falloff = field_170->field_40 * 1.414f;
        f32 factor = 1.0f;
        if (falloff != 1.0f) {
            factor = powf(falloff, static_cast<f32>(level - field_414));
        }
        scale *= factor;
        bloom = field_320[level].field_18;
        bool shown = false;
        if (anamorphic) {
            const Unk_45_170* color = field_170;
            Unk_410f90 space;
            Unk_410f90_set(&space, 0);
            shown = Unk_Luminance(space, color->field_18) > 0.0f;
        }
        if (shown) {
            bloom = static_cast<CRenderTexture*>(m_pBloomResult);
            params[4].field_0[0].field_0 = -1.0f;
            params[5].field_0[0].field_0 = -1.8f;
            params[5].field_0[3].field_0 = 0.98f;
            params[6].field_0[0].field_0 = -1.8f;
            params[6].field_0[3].field_0 = 0.98f;
            for (s32 j = 0; j < 4; j++) {
                colors[4].field_0[j].field_0 = streak.field_0[j].field_0 * 0.5f;
                colors[5].field_0[j].field_0 = flare.field_0[j].field_0 * 0.4f;
                colors[6].field_0[j].field_0 = flare.field_0[j].field_0;
            }
            colors[5].field_0[2].field_0 *= 1.5f;
        } else {
            for (s32 j = 0; j < 4; j++) {
                colors[4].field_0[j].field_0 *= scale;
            }
        }
        for (s32 j = 0; j < 4; j++) {
            colors[5].field_0[j].field_0 *= scale;
        }
        level = Unk_GhostLevel(this, 0, &scale);
        if (anamorphic) {
            flareSource = static_cast<CRenderTexture*>(m_pAnamorphicFlareResult);
            params[7].field_0[0].field_0 = -1.0f;
            for (s32 j = 0; j < 4; j++) {
                colors[7].field_0[j].field_0 = color.field_0[j].field_0 * 0.5f;
            }
        } else {
            flareSource = field_320[level].field_18;
            for (s32 j = 0; j < 4; j++) {
                colors[7].field_0[j].field_0 *= scale;
            }
        }
    }
    for (s32 j = 0; j < 4; j++) {
        colors[6].field_0[j].field_0 *= scale;
    }
    size = field_170->field_44;
    if (field_1dc == 0.0f) {
        size *= 0.5f;
    }
    result = util->Unk_489690(first, bloom, flareSource,
                              m_pGhostGeneration != nullptr ? Unk_ArrayTexture(m_pGhostGeneration, 0) : nullptr,
                              params, colors, size * 0.0f, field_2e4, 0);
    return result < 0 ? result : 0;
}

// 0x7100458720: the ghosts' levels blurred, each from the one before (field_3fc
// their ratio), then added up by 0x7100458e20
// The ratio's format test is `(format != 0) & Unk_IsGlareFormatB(format)`
// (closer than `&&`).
// NON_MATCHING: the original keeps `weight` on the stack (an integer `csel`
// for its clamp, reloaded after every call) and all eight constants in d8-d15;
// here it is a register and three constants are spilled, so registers, the
// loop's block order and the white colour's stores differ
s32 CRenderGlare::Unk_458720() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (!Unk_IsFixedFormat(field_b0.field_18[2])) {
        field_3fc = 1.0f;
    } else {
        f32 ratio = powf(Unk_458250(), 1.0f / static_cast<f32>(field_3d8));
        s32 format = field_b0.field_18[2];
        if (Unk_IsGlareFormatC(format) || ((format != 0) & Unk_IsGlareFormatB(format))) {
            ratio = 2.0f;
        } else {
            ratio = fminf(ratio, 2.0f);
        }
        field_3fc = ratio;
    }
    s32 levels = field_3d8;
    s32 count = Unk_LevelCount();
    s32 slot = field_2e4;
    f32 factor = 1.0f;
    if (field_1e4 != 1.0f) {
        f32 size = field_404 * (field_b0.field_4a ? 1.8f : 2.2f) / static_cast<f32>(field_b0.field_10);
        f32 e = logf(size) / -0.6931472f + -4.0f;
        factor = 1.0f / powf(field_1e4, e);
    }
    Unk_Float weight = 1.0f;
    s32 result = 0;
    for (s32 i = 0; i < levels; i++) {
        Unk_45_320* entry = &field_320[i];
        CRenderTexture* low = entry->field_10;
        CRenderTexture* work = entry->field_20;
        CRenderTexture* blur = entry->field_18;
        f32 scale = 1.0f;
        if (i != 0) {
            scale = field_b0.field_4a ? 1.5f : 1.0f;
        }
        bool down = false;
        if (i >= count) {
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, field_320[i - 1].field_18, low, 0, &color, 1, false, false, 1,
                             &offset, nullptr, -1);
            weight.field_0 = weight.field_0 + -1.0f;
            down = true;
        }
        CRenderTexture* source = low;
        f32 radius;
        if (i != 0 && i < count) {
            source = field_320[i - 1].field_18;
            radius = field_1e0 * field_320[i].field_8 * 0.8660254f;
        } else {
            radius = field_1e0 * field_320[i].field_8;
            if (down) {
                radius *= 0.8660254f;
            }
        }
        scale = factor * scale;
        if (field_130 || (i == 0 && field_b0.field_4a)) {
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            if (i == 0) {
                s32 r = util->Unk_493f30(scale, weight, source, blur, slot, &color, false, false, 0, 0);
                if (r < 0) {
                    result = r;
                }
                factor *= field_1e4 * field_3fc;
            } else {
                if (i == 1) {
                    util->Unk_493f30(sqrtf(scale), 1.0f, source, work, slot, &color, false, false, 0, 0);
                } else {
                    util->Unk_493f30(sqrtf(scale), 1.0f, source, blur, slot, &color, false, false, 0, 0);
                    util->Unk_493f30(1.0f, 1.0f, blur, work, slot, &color, false, false, 0, 0);
                }
                s32 r = util->Unk_493f30(sqrtf(scale), 2.0f, work, blur, slot, &color, false, false, 0, 0);
                if (r < 0) {
                    result = r;
                }
            }
        } else {
            f32 red = radius * 6.15e-7f;
            f32 green = radius * 5.4e-7f;
            f32 blue = radius * 4.65e-7f;
            Unk_Float4 offset(-(red / 6.15e-7f), green / 6.15e-7f, blue / 6.15e-7f, 0.0f);
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            s32 r = util->Unk_497b20(scale, field_400, source, work, blur, &offset, slot, &color, false, false, false,
                                     0, 0);
            if (r < 0) {
                result = r;
            }
            if (i == 0) {
                factor *= field_1e4 * field_3fc;
            }
        }
        if (i >= count) {
            weight = Unk_MinFloat(Unk_Float(weight.field_0 + 1.0f), Unk_Float(4.0f));
        }
        if (field_320[i].field_28 != nullptr) {
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_47dfa0(0.0f, 0.0f, 0.375f, 1.0f, blur, field_320[i].field_28, 0, &color, 0, false, false, 1,
                             &offset, nullptr, -1);
        }
    }
    s32 r = Unk_458e20();
    if (r < 0) {
        return r;
    }
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    return result < 0 ? result : 0;
}

// 0x7100458e20: the ghosts' levels, each by its colour, added up into
// m_pBloomResult (their textures halved into each other first). The tinted
// colour is lerped into the array by Unk_Float4Lerp and scaled in place
// there (with four scalar lerps the colour loop's schedule and the second
// loop's registers differ).
s32 CRenderGlare::Unk_458e20() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    s32 count = field_3d8;
    s32 slot = field_2e4;
    CRenderTexture* textures[16];
    for (s32 i = 0; i < count; i++) {
        textures[i] = field_320[i].Unk_Texture28();
    }
    for (s32 i = count; i < 16; i++) {
        textures[i] = nullptr;
    }
    bool same = Unk_457650();
    CGPUResourceManage* target = m_pBloomResult;
    bool skip = true;
    if (Unk_IsGlareFormatC(field_b0.field_18[3])) {
        if (same) {
            if (field_411) {
                Unk_440d50_get(reinterpret_cast<u64>(field_20), 0);
            }
            skip = false;
        }
    }
    f32 value = Unk_458250();
    static const Unk_Float4 s_white(1.0f, 1.0f, 1.0f, 1.0f);
    s32 last = reinterpret_cast<const Unk_4a0b00*>(field_170)->field_2c + field_414 - 1;
    u32 first = last < count - 3 ? last : count - 3;
    Unk_Float4 colors[16];
    for (s32 i = 0; i < count; i++) {
        f32 scale = value * (1.0f / powf(field_3fc, static_cast<f32>(i)));
        f32 t;
        if (i >= first && (t = reinterpret_cast<const Unk_4a0b00*>(field_170)->field_28) > 0.0f) {
            s32 k = i - first;
            k = k > 0 ? k : 0;
            const Unk_Float4& c = Unk_24e58c8[k % 3 + 1];
            Unk_Float4Lerp(&colors[i], &s_white, &c, t);
            scale *= 3.0f / (Unk_Abs(colors[i].field_0[0].field_0) + Unk_Abs(colors[i].field_0[1].field_0) +
                             Unk_Abs(colors[i].field_0[2].field_0));
            colors[i].field_0[0].field_0 *= scale;
            colors[i].field_0[1].field_0 *= scale;
            colors[i].field_0[2].field_0 *= scale;
            colors[i].field_0[3].field_0 *= scale;
        } else {
            colors[i].field_0[0].field_0 = scale;
            colors[i].field_0[1].field_0 = scale;
            colors[i].field_0[2].field_0 = scale;
            colors[i].field_0[3].field_0 = scale;
        }
    }
    for (s32 i = count - 1; i > 0; i--) {
        if (field_320[i - 1].field_30 != nullptr) {
            CRenderTexture** pair = &textures[i - 1];
            Unk_Float4 ratio;
            for (s32 c = 0; c < 4; c++) {
                ratio.field_0[c].field_0 = colors[i].field_0[c].field_0 / colors[i - 1].field_0[c].field_0;
            }
            CRenderTexture* previous = pair[0];
            pair[0] = field_320[i - 1].Unk_Texture30();
            Unk_Float4 inverse(1.0f / ratio.field_0[0].field_0, 1.0f / ratio.field_0[1].field_0,
                               1.0f / ratio.field_0[2].field_0, 1.0f / ratio.field_0[3].field_0);
            util->Unk_47dfa0(0.0f, 0.0f, 0.375f, 1.0f, pair[1], pair[0], 0, &ratio, 0, false, false, 1,
                             &inverse, previous, -1);
            count--;
        }
    }
    for (s32 i = 0; i < Unk_LevelCount(); i++) {
        Unk_GetTexture(textures[i])->vf17(1);
    }
    s32 result = util->Unk_48d220(1.0f, field_1ec, target, count, textures, colors, slot, false);
    for (s32 i = 0; i < Unk_LevelCount(); i++) {
        Unk_GetTexture(textures[i])->vf17(0);
    }
    if (result < 0) {
        return result;
    }
    if (!skip && field_411) {
        Unk_471460_update(reinterpret_cast<u64>(util), 16, 0);
    }
    return 0;
}

// 0x7100455850: whether the settings are in range and every resource that
// they need has been made
bool CRenderGlare::Unk_455850() {
    if (field_b0.field_c < 16) {
        return false;
    }
    if (field_b0.field_10 < 16) {
        return false;
    }
    s32 count = field_b0.field_18[5];
    if (count != 0 && (count < 1 || count > 16)) {
        return false;
    }
    if (field_b0.field_18[10] > 16) {
        return false;
    }
    if (field_b0.field_50) {
        if (field_b0.field_4 == 0) {
            return false;
        }
        if (field_b0.field_8 == 0) {
            return false;
        }
    }
    if (!Unk_ArrayMade(m_pGlareSource)) {
        return false;
    }
    if (!Unk_TextureMade(m_pBloomResult)) {
        return false;
    }
    if (!Unk_TextureMade(m_pGlareResult)) {
        return false;
    }
    if (m_pGlareResultChromaticAberration != nullptr && !Unk_TextureMade(m_pGlareResultChromaticAberration)) {
        return false;
    }
    if (m_pGlareResultUpsample != nullptr && !Unk_TextureMade(m_pGlareResultUpsample)) {
        return false;
    }
    if (m_pGlareResultAntialias != nullptr && !Unk_TextureMade(m_pGlareResultAntialias)) {
        return false;
    }
    if (m_pGlareResultLensDistortionFalloff != nullptr && !Unk_TextureMade(m_pGlareResultLensDistortionFalloff)) {
        return false;
    }
    for (s32 i = 0; i < count; i++) {
        if (!Unk_ArrayMade(m_ppBloomGeneration[i])) {
            return false;
        }
    }
    if (m_pStarGeneration != nullptr && !Unk_ArrayMade(m_pStarGeneration)) {
        return false;
    }
    if (m_pStarResult != nullptr && !Unk_TextureMade(m_pStarResult)) {
        return false;
    }
    if (m_pAnamorphicFlareResult != nullptr && !Unk_TextureMade(m_pAnamorphicFlareResult)) {
        return false;
    }
    if (m_pGhostGeneration != nullptr && !Unk_ArrayMade(m_pGhostGeneration)) {
        return false;
    }
    if (m_pLightGhostLuminance != nullptr && !Unk_TextureMade(m_pLightGhostLuminance)) {
        return false;
    }
    if (m_ppAfterimageGeneration != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            if (!Unk_ArrayMade(m_ppAfterimageGeneration[i])) {
                return false;
            }
        }
    }
    if (m_pLightShaftBlurSource != nullptr && !Unk_TextureMade(m_pLightShaftBlurSource)) {
        return false;
    }
    if (m_pLightShaftResult != nullptr && !Unk_TextureMade(m_pLightShaftResult)) {
        return false;
    }
    if (m_pLightShaftGeneration != nullptr && !Unk_ArrayMade(m_pLightShaftGeneration)) {
        return false;
    }
    return true;
}

// 0x7100478880 (GPUTextureUtil.cpp): a ratio (the flag is not read)
f32 Unk_478880(f32 a, f32 b, bool flag);

// whether one of the glare's formats (field_2e0) is an sRGB one, and the
// linear format of one (inline)
static inline bool Unk_IsGlareSrgb(s32 format) {
    switch (format) {
    case 2:
    case 5:
    case 8:
    case 11:
    case 14:
        return true;
    default:
        return false;
    }
}
static inline s32 Unk_GlareLinear(s32 format) {
    switch (format) {
    case 8:
        return 7;
    case 2:
        return 1;
    case 5:
        return 4;
    case 11:
        return 10;
    case 14:
        return 13;
    default:
        return format;
    }
}

// 0x7100457760: `source` tone mapped into `target` (field_140 the mode),
// through m_pGlareSource's first texture when the sizes differ
// The two scaled colours are filled element by element (2, 1, 0, then 3):
// the DAG then pairs the stores of elements 1 and 2 as the original does.
// NON_MATCHING: the original tests `resize` with `tbz` (its known bits are
// lost: a phi at instruction selection; here it is a select and `cbz`), and
// swaps two registers of the size tests (w11/w12: the sRGB mask's shift and
// the source's width). Tried: every order of the declarations before
// `unscaled`, the sRGB test as a switch, an `||` chain, a local format, and
// `resize` as an if/else, an int, a u8 and a negated select.
s32 CRenderGlare::Unk_457760(CRenderTexture* source, CRenderTexture* target) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    s32 mode = field_140;
    if (mode == 3 && field_144 == 1.0f) {
        mode = 2;
    }
    if ((mode == 1 || mode == 2) && field_13c == 0.0f) {
        mode = 0;
    }
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    bool srgb = Unk_IsGlareSrgb(field_2e0);
    CRenderTexture* first = static_cast<CRenderTextureArray*>(m_pGlareSource)->field_38[0];
    bool filtered = (texture->field_5c & 0x20000) != 0;
    bool larger = static_cast<u32>(source->field_54) > static_cast<u32>(first->field_54) * 2 + 1 ||
                  static_cast<u32>(source->field_58) > static_cast<u32>(first->field_58) * 2 + 1;
    bool shrink = larger & (field_308 == 0);
    bool differ = source->field_54 != first->field_54 || source->field_58 != first->field_58;
    bool shaft = field_180;
    bool resize = filtered ? shrink : differ;
    bool unscaled = !srgb || field_164 / field_134 == 1.0f;
    bool copy = (mode == 0) & unscaled & !shaft;
    Unk_Float4 rect;
    if (shaft) {
        bool vignette = field_18c && field_198 >= 0.0f;
        f32 ratio = Unk_478880(field_b0.field_74, field_b0.field_78, vignette);
        f32 s = Unk_45d350();
        f32 sx = ratio * s;
        f32 cx = field_15c * (sx + sx) * 0.5f;
        f32 cy = field_160 * (s + s) * 0.5f;
        rect = Unk_Float4(-sx - cx, -s - cy, sx - cx, s - cy);
    }
    Unk_Float4* shaftRect = shaft ? &rect : nullptr;
    f32 angle = field_18c ? field_158 : 0.0f;
    Unk_440cf0_get(reinterpret_cast<u64>(field_20), 0);
    field_20->vf46(0);
    bool fixed = false;
    switch (field_b0.field_18[3]) {
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
        fixed = true;
        break;
    }
    s32 format = field_2e0;
    u64 device = reinterpret_cast<u64>(field_20);
    if (copy) {
        if (fixed && field_411) {
            Unk_440d50_get(device, 1);
        }
        f32 k = field_164 / field_134;
        Unk_Float4 color;
        color.field_0[2] = k;
        color.field_0[1] = k;
        color.field_0[0] = k;
        color.field_0[3] = 1.0f;
        Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
        util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, source, target, format, &color, 1, false, false, 1, &offset,
                         nullptr, -1);
        field_2f8 = target;
    } else if (resize) {
        Unk_440cf0_get(device, 0);
        field_20->vf46(0);
        f32 scale = 0.0f;
        f32 k = 1.0f;
        s32 format = 0;
        if (!srgb) {
            scale = 1.0f / (field_134 + field_13c);
            k = field_164 * scale;
            format = field_2e0;
        }
        CRenderTexture* work = Unk_ArrayTexture(m_pGlareSource, 0);
        Unk_Float4 color;
        color.field_0[2] = k;
        color.field_0[1] = k;
        color.field_0[0] = k;
        color.field_0[3] = 1.0f;
        Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
        util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, source, work, format, &color, 0, false, false, 1, &offset,
                         nullptr, -1);
        field_2f8 = work;
        f32 intensity;
        s32 linear;
        if (srgb) {
            linear = Unk_GlareLinear(field_2e0);
            intensity = field_164;
        } else {
            intensity = 1.0f / scale;
            linear = 0;
        }
        f32 step = 1.0f / field_134;
        Unk_GetTexture(work)->vf17(1);
        if (fixed && field_411) {
            Unk_440d50_get(reinterpret_cast<u64>(field_20), 1);
        }
        util->Unk_48e260(work, target, intensity, step, field_13c, field_144, angle, field_190, field_194,
                         field_198, mode, shaftRect, linear, 1, false);
        Unk_GetTexture(work)->vf17(0);
    } else {
        s32 linear = Unk_GlareLinear(format);
        if (source->field_54 == target->field_54 && source->field_58 == target->field_58) {
            Unk_GetTexture(source)->vf17(1);
        }
        if (fixed && field_411) {
            Unk_440d50_get(reinterpret_cast<u64>(field_20), 1);
        }
        util->Unk_48e260(source, target, field_164, 1.0f / field_134, field_13c, field_144, angle, field_190,
                         field_194, field_198, mode, shaftRect, linear, 1, false);
        field_2f8 = target;
        Unk_GetTexture(source)->vf17(0);
    }
    if (fixed && field_411) {
        Unk_471460_update(reinterpret_cast<u64>(util), 16, 1);
    }
    return 0;
}

// the least level a light shaft's steps fade to, for a format (inline)
static inline f32 Unk_ShaftLeast(s32 format) {
    if (!Unk_4385e0(format)) {
        return 0.001f;
    }
    if (Unk_IsGlareFormatA(format)) {
        return 0.001f;
    }
    if (format != 0 && Unk_IsGlareFormatB(format)) {
        return 0.001f;
    }
    if (Unk_IsGlareFormatC(format)) {
        return 1.0f / 255.0f;
    }
    return 0.001f;
}

// 0x710045ca70: the light shaft of view `index` (field_1f8's), blurred out
// from its centre in up to eight passes of four steps through m_pStarGeneration's
// textures, into `target` (m_pLightShaftResult for none)
// The tint is applied by a loop over the colour's channels, which keeps
// `color` in memory as the original does.
// The view loop's index is `s64` and the taps' `u32` (closer than `s32`).
// NON_MATCHING: a first draft with the original's calls and arithmetic. The
// original spills `this` instead of keeping it in x20 (the registers differ
// from there on), and branches out of the level loop
// before the step and the ping-pong index are updated (here they become
// selects folded into the loop's exit test).
s32 CRenderGlare::Unk_45ca70(CRenderTexture* target, s32 index) {
    if (target == nullptr) {
        target = static_cast<CRenderTexture*>(m_pLightShaftResult);
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    CRenderTexture* glare = Unk_ArrayTexture(m_pGlareSource, 2);
    CRenderTexture* source = static_cast<CRenderTexture*>(m_pLightShaftBlurSource);
    s32 result = util->Unk_48e4e0(field_1f8[index].field_5c, field_168 / field_134, field_1f8[index].field_10,
                                  field_1f8[index].field_14, field_1f8[index].field_18, field_154,
                                  field_1f8[index].field_20, source, glare,
                                  &field_1f8[index].field_44, field_1f8[index].field_4c, false);
    f32 length = field_1f8[index].field_1c;
    f32 least = Unk_ShaftLeast(source->field_2c.field_c);
    result = result < 0 ? result : 0;
    f32 size = static_cast<f32>(field_b0.field_c) / 320.0f * (1.0f / (field_158 + field_158));
    f32 step = 1.0f / size * 0.0625f / length;
    f32 steps = logf(least) / -0.6931472f / step;
    s32 levels = static_cast<s32>(ceilf(logf(steps) / 1.3862944f));
    s32 count = levels < 8 ? levels : 8;
    s32 last = static_cast<s32>(ceilf(steps * 4.0f / powf(4.0f, static_cast<f32>(count))));
    if (last == 0) {
        last = 4;
    }
    f32 scale = powf(field_158 * 0.25f, 1.0f / static_cast<f32>(count));
    CRenderTextureArray* array = static_cast<CRenderTextureArray*>(m_pStarGeneration);
    CRenderTexture* pair[2] = {array->field_38[field_b0.field_18[10]], array->field_38[field_b0.field_18[10] + 1]};
    f32 a = field_1f8[index].field_24;
    Unk_GlareRect tint = field_1f8[index].field_34;
    f32 b = field_1f8[index].field_28;
    f32 c = field_1f8[index].field_2c;
    f32 d = field_1f8[index].field_30;
    Unk_GlareRect color = field_1f8[index].field_0;
    if (a == 0.0f && (tint.field_0 != 1.0f || tint.field_4 != 1.0f || tint.field_8 != 1.0f)) {
        f32* c = &color.field_0;
        const f32* t = &tint.field_0;
        for (s32 n = 0; n < 3; n++) {
            c[n] *= t[n];
        }
    }
    s32 k = 0;
    for (s64 i = 0; i < count; i++) {
        f32 level = i == 0 ? scale * 0.25f : scale;
        f32 weights[4];
        weights[0] = level * powf(0.5f, step * 0.0f);
        weights[1] = level * powf(0.5f, step);
        weights[2] = level * powf(0.5f, step + step);
        weights[3] = level * powf(0.5f, step * 3.0f);
        s32 taps = last < 4 && i == count - 1 ? last : 4;
        bool final = i == count - 1 || taps < 4;
        CRenderTexture* dest = a == 0.0f && final ? target : pair[k];
        u32 width = dest->field_54;
        f32 height = static_cast<f32>(static_cast<u32>(dest->field_58));
        f32 maxU;
        f32 maxV;
        Unk_GetCoords(source, &maxU, &maxV);
        dest->Unk_49d250(0, 0, 1, 0, 0);
        f32 cy = field_20->field_58 ? 1.0f - field_1f8[index].field_44.field_0[1].field_0
                                    : field_1f8[index].field_44.field_0[1].field_0;
        Unk_Float4 colors[4];
        f32 u0[4];
        f32 v0[4];
        f32 u1[4];
        f32 v1[4];
        if (taps >= 1) {
            f32 cu = source->field_90 + source->field_88 * (field_1f8[index].field_44.field_0[0].field_0 *
                                                            static_cast<f32>(static_cast<u32>(source->field_54)));
            f32 cv = source->field_94 + source->field_8c * (cy * static_cast<f32>(static_cast<u32>(source->field_58)));
            for (u32 j = 0; j < taps; j++) {
                f32 w = weights[j];
                if (final) {
                    colors[j] = Unk_Float4(color.field_0 * w, color.field_4 * w, color.field_8 * w, color.field_c * w);
                    f32 f = Unk_458420() * 0.25f * (320.0f / static_cast<f32>(field_b0.field_c)) * 4.0f;
                    for (s32 n = 0; n < 4; n++) {
                        colors[j].field_0[n].field_0 *= f;
                    }
                } else {
                    colors[j] = Unk_Float4(w, w, w, w);
                }
                f32 t = 1.0f / ((static_cast<f32>(j) * static_cast<f32>(static_cast<s32>(
                                                          powf(4.0f, static_cast<f32>(i)))) + height) / height);
                u0[j] = Unk_Lerp(cu, 0.0f, t);
                v0[j] = Unk_Lerp(cv, 0.0f, t);
                u1[j] = Unk_Lerp(cu, maxU, t);
                v1[j] = Unk_Lerp(cv, maxV, t);
            }
        }
        Unk_GetTexture(source)->vf15(0);
        s32 r = util->DrawRectGPU_TexCoordMadT1_Sn(0.0f, 0.0f, static_cast<f32>(width), height, u0, v0, u1, v1, taps,
                                                   colors, Unk_GetTexture(source), field_2e4, 0);
        if (r < 0) {
            result = r;
        }
        source = dest;
        if (taps < 4) {
            break;
        }
        step *= 4.0f;
        k = (k + 1) % 2;
    }
    if (a != 0.0f) {
        s32 r = util->Unk_48e9a0(a, b, c, d, target, field_154, source, &tint, &field_1f8[index].field_44, false);
        if (r < 0) {
            result = r;
        }
    }
    return result;
}

}  // namespace PPFX

// 0x71024e5950 (GPUGlareDef.cpp): the light ghost presets
extern PPFX::Unk_GlareGhostDef* Unk_24e5950;

namespace PPFX {

// 0x710045d3b0 (its log lines name it): the glare's parts added up into
// m_pGlareResult (or m_pBloomResult alone), then the lens distortion, its chromatic
// aberration's blur, the bloom, the blur and the light ghosts; the result goes
// to field_420
// `idle`'s second test, the Unk_456bf0 test and the fixed-format test are
// `&` of their parts (closer than `&&`).
// NON_MATCHING: a first draft with the original's calls, log lines and
// arithmetic; the stack layout (the colour space temporaries, the colours and
// the textures), the registers and the block layout of the tests at the top
// differ.
s32 CRenderGlare::GenerateGlare_Composite() {
    if (Unk_457650()) {
        field_420 = static_cast<CRenderTexture*>(m_pBloomResult);
    } else {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        bool ghosts = Unk_456bf0();
        bool color = Unk_456f30();
        bool streaks = Unk_4570b0();
        bool afterimage = Unk_457370();
        s32 frames = field_1f4;
        bool idle = field_200 < 1 || ((field_210 == -1) & (field_220 < 1));
        bool released = !field_368 || field_360 == 0;
        CRenderTexture* source = static_cast<CRenderTexture*>(m_pBloomResult);
        if ((idle & released) != true || (ghosts | color | streaks | afterimage) || frames >= 1) {
            f32 baseWidth = static_cast<f32>(static_cast<u32>(source->field_54));
            f32 baseHeight = static_cast<f32>(static_cast<u32>(source->field_58));
            f32 scaleU = source->field_88;
            f32 scaleV = source->field_8c;
            f32 offsetU = source->field_90;
            f32 offsetV = source->field_94;
            CRenderTexture* target = static_cast<CRenderTexture*>(m_pGlareResult);
            f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
            f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
            target->Unk_49d250(0, 0, 1, 0, 0);
            CRenderTexture::Unk_49cf50(nullptr, nullptr);
            bool fixed = Unk_IsGlareFormatC(field_b0.field_18[3]);
            if (fixed && field_411) {
                Unk_440d50_get(reinterpret_cast<u64>(field_20), 0);
            }
            CRenderTexture* textures[8];
            Unk_Float4 colors[8];
            for (s32 i = 0; i < 8; i++) {
                colors[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            }
            const Unk_45_170* def = field_170;
            Unk_410f90 space;
            Unk_410f90_set(&space, 0);
            f32 inverse = 1.0f / Unk_Luminance(space, def->field_8);
            f32 r = def->field_8.field_0[0] * inverse;
            f32 g = inverse * def->field_8.field_0[1];
            f32 b = inverse * def->field_8.field_0[2];
            f32 a = inverse * def->field_14;
            textures[0] = static_cast<CRenderTexture*>(m_pBloomResult);
            def = field_170;
            f32 cr = r * def->field_18.field_0[0];
            f32 cg = g * def->field_18.field_0[1];
            f32 cb = b * def->field_18.field_0[2];
            f32 ca = a * def->field_24;
            Unk_410f90 colorSpace;
            Unk_410f90_set(&colorSpace, 0);
            f32 k = 1.0f / Unk_Luminance(colorSpace, def->field_18);
            colors[0] = Unk_Float4(cr * k, cg * k, cb * k, ca * k);
            u32 count = 1;
            if (Unk_456bf0() & field_428) {
                textures[1] = static_cast<CRenderTexture*>(m_pStarResult);
                def = field_170;
                Unk_410f90 colorSpace;
                Unk_410f90_set(&colorSpace, 0);
                f32 k = 1.0f / Unk_Luminance(colorSpace, def->field_4c);
                colors[1] = Unk_Float4(r * def->field_4c.field_0[0] * k, g * def->field_4c.field_0[1] * k,
                                       b * def->field_4c.field_0[2] * k, a * def->field_58 * k);
                count = 2;
            }
            if (Unk_456f30()) {
                textures[count] = static_cast<CRenderTexture*>(m_pAnamorphicFlareResult);
                colors[count] = Unk_Float4((r * field_1b8) + (r * field_1b8), (g * field_1bc) + (g * field_1bc),
                                           (b * field_1c0) + (b * field_1c0), (a * field_1c4) + (a * field_1c4));
                count++;
            }
            if (Unk_4570b0()) {
                textures[count] = m_pGhostGeneration != nullptr ? Unk_ArrayTexture(m_pGhostGeneration, 0) : nullptr;
                def = field_170;
                Unk_410f90 colorSpace;
                Unk_410f90_set(&colorSpace, 0);
                f32 k = 1.0f / Unk_Luminance(colorSpace, def->field_30);
                colors[count] = Unk_Float4(r * def->field_30.field_0[0] * k, g * def->field_30.field_0[1] * k,
                                           b * def->field_30.field_0[2] * k, a * def->field_3c * k);
                count++;
            }
            if (Unk_457370()) {
                textures[count] = Unk_ViewTexture(this);
                def = field_170;
                Unk_410f90 colorSpace;
                Unk_410f90_set(&colorSpace, 0);
                f32 k = 1.0f / Unk_Luminance(colorSpace, def->field_6c);
                colors[count] = Unk_Float4(r * def->field_6c.field_0[0] * k, g * def->field_6c.field_0[1] * k,
                                           b * def->field_6c.field_0[2] * k, a * def->field_78 * k);
                count++;
            }
            f32 u1 = scaleU * baseWidth + offsetU;
            f32 v1 = scaleV * baseHeight + offsetV;
            if (field_1f4 >= 1) {
                textures[count] = static_cast<CRenderTexture*>(m_pLightShaftResult);
                count++;
            }
            for (u32 i = 0; i < count; i++) {
                Unk_GetTexture(textures[i])->vf17(1);
            }
            s32 filters[8];
            for (u32 i = 0; i < count; i++) {
                CRenderTexture* texture = textures[i];
                Unk_GPUTexture* gpu = Unk_GetTexture(texture);
                filters[i] = gpu->vf16();
                gpu->vf17(texture->field_54 == target->field_54 && texture->field_58 == target->field_58);
                gpu->vf18(1);
            }
            s32 dirt = field_148;
            if (dirt) {
                util->Unk_470610(field_14c, field_150);
            }
            if (field_368 && field_360 != 0) {
                s32 result = util->DrawRectGPU_MadLumGammaWithLensDirtTn(
                    0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 1.0f,
                    Unk_Float4(field_36c.field_0, field_36c.field_4, field_36c.field_8, field_36c.field_c),
                    Unk_Float4(field_37c.field_0, field_37c.field_4, field_384.field_0, field_384.field_4), count,
                    textures, reinterpret_cast<CRenderTexture*>(field_360), colors, dirt, 0);
                if (result < 0) {
#line 6194
                    PPFX_ERROR("CRenderGlare::GenerateGlare_Composite(): pTexUtil->DrawRectGPU_MadLumGammaWithLensDirtTn() failed (0x%x: %s).\n", result, Unk_446df0(result));
                }
            } else {
                s32 result =
                    util->DrawRectGPU_MadLumGammaTn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 1.0f, count, textures, colors, dirt, 0);
                if (result < 0) {
#line 6210
                    PPFX_ERROR("CRenderGlare::GenerateGlare_Composite(): pTexUtil->DrawRectGPU_MadLumGammaTn() failed (0x%x: %s).\n", result, Unk_446df0(result));
                }
            }
            for (u32 i = 0; i < count; i++) {
                Unk_GetTexture(textures[i])->vf15(filters[i]);
            }
            for (u32 i = 0; i < count; i++) {
                Unk_GetTexture(textures[i])->vf17(0);
            }
            if (fixed & field_411) {
                Unk_471460_update(reinterpret_cast<u64>(util), 16, 0);
            }
            source = static_cast<CRenderTexture*>(m_pGlareResult);
        }
        CRenderTexture* result = source;
        if (field_29c) {
            CRenderTexture* target = static_cast<CRenderTexture*>(m_pGlareResultChromaticAberration);
            util->Unk_482010(field_154,
                             static_cast<f32>(field_b0.field_c) / static_cast<f32>(field_b0.field_10), field_2d0,
                             field_2d4, field_2d8, source, target, field_2a0, &field_2a8, &field_2b0, &field_2b8,
                             &field_2c8, &field_2c0, field_2dc, util->field_29ab8[0], 0, 0);
            result = target;
            if (field_2a4) {
                CRenderTexture* blur = static_cast<CRenderTextureArray*>(m_pStarGeneration)->field_38[0];
                if (blur == nullptr) {
#line 6338
                    PPFX_WARNING("GenerateGlare_Composite(): pGlareResultChromaticAberrationBlur is NULL.\n");
                } else {
                    Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                    Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
                    util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, target, blur, 0, &white, 0, false, false, 1, &offset,
                                     nullptr, -1);
                    result = blur;
                }
            }
        }
        if (field_26c) {
            CRenderTexture* target = static_cast<CRenderTexture*>(m_pGlareResultLensDistortionFalloff);
            util->Unk_481bc0(field_270[0], field_270[1], field_270[2], field_270[3], field_270[4], field_270[5],
                             field_270[6], field_270[7], field_290, 0.0f, field_298, 0.0f, 1.0f, 0.0f, result, target,
                             field_294, true, false, true, 0, 0);
            result = target;
        }
        if (field_b0.field_14) {
            CRenderTexture* target = static_cast<CRenderTexture*>(m_pGlareResultAntialias);
            util->Unk_48edb0(field_164, 0.25f, target, result, nullptr, false);
            result = target;
        }
        if (field_418 > 0.0f) {
            CRenderTexture* target = static_cast<CRenderTexture*>(m_pGlareResultUpsample);
            Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_47dfa0(0.0f, 0.0f, field_418 * 0.5f, 1.0f, result, target, 0, &white, 0, false, false, 1,
                             &offset, nullptr, -1);
            result = target;
        }
        if (field_200 >= 1 && (field_210 != -1 || field_220 >= 1)) {
            CRenderTexture::Unk_49cf50(nullptr, nullptr);
            u32 ghostCount = field_b0.field_64;
            for (u32 i = 0; i < ghostCount; i++) {
                Unk_453_208* ghost = &field_208[i];
                if (!ghost->field_0) {
                    continue;
                }
                CRenderTexture* luminance = static_cast<CRenderTexture*>(m_pLightGhostLuminance);
                Unk_GPUTexture* texture = Unk_GetTexture(luminance);
                if (ghost->field_24 == 2) {
                    texture = reinterpret_cast<Unk_GPUTexture*>(util->field_29a70[4]);
                } else {
                    CRenderTexture* glare = Unk_ArrayTexture(m_pGlareSource, 2);
                    luminance->Unk_49d250(0, 0, 1, 0, 0);
                    s32 r = util->DrawLightGhostLuminance(0.0f, 0.0f, 1.0f, 1.0f, Unk_GetTexture(glare),
                                             static_cast<f32>(static_cast<u32>(glare->field_54)),
                                             static_cast<f32>(static_cast<u32>(glare->field_58)), &ghost->field_14,
                                             ghost->field_28, ghost->field_2c, ghost->field_24, 0, 0);
                    if (r < 0) {
#line 6437
                        PPFX_ERROR("CRenderGlare::GenerateGlare_Composite(): pTexUtil->DrawLightGhostLuminance() failed (0x%x: %s).\n", r, Unk_446df0(r));
                    }
                }
                const void* presets;
                s32 presetCount;
                if (field_210 == -1) {
                    presets = reinterpret_cast<const void*>(field_218);
                    presetCount = field_220;
                } else {
                    presets = &Unk_24e5950[field_210];
                    presetCount = Unk_24e5950[field_210].field_1b00;
                }
                f32 falloff = field_25c;
                if (field_258 == 0 && field_248_f > 0.0f) {
                    f32 base = powf(10.0f, -(field_25c + field_25c + -1.0f));
                    falloff = powf(base, field_248_f < 0.0f ? 0.0f : fminf(field_248_f, 1.0f));
                }
                f32 spread;
                if (field_250_f > 0.0f) {
                    spread = field_268 / field_250_f * 0.5f;
                } else if (field_254 > 0.0f) {
                    spread = field_254;
                } else {
                    spread = field_158;
                }
                f32 fov = field_254 > 0.0f ? field_254 : field_158;
                f32 level = ghost->field_24 == 0 ? field_134 : field_168;
                f32 zoom = fov / field_158;
                f32 scale = 1.0f / (zoom * zoom) *
                            (ghost->field_28 * ghost->field_28 * 3.14159274f * (level * field_138));
                Unk_Float4 ghostColor(field_224.field_0 * ghost->field_4[0] * scale,
                                      field_224.field_4 * ghost->field_4[1] * scale,
                                      field_224.field_8 * ghost->field_4[2] * scale,
                                      field_224.field_c * ghost->field_4[3] * scale);
                Unk_Float2 position = ghost->field_14;
                Unk_Float2 position2 = ghost->field_1c;
                if (field_20->field_58) {
                    position.field_0[1] = 1.0f - position.field_0[1].field_0;
                    position2.field_0[1] = 1.0f - position2.field_0[1].field_0;
                }
                f32 aspect = field_268 > 0.0f ? field_24c / field_268 : 1.0f;
                f32 width = static_cast<f32>(static_cast<u32>(result->field_54));
                f32 height = static_cast<f32>(static_cast<u32>(result->field_58));
                f32 ratio = field_24c > 0.0f ? field_250_f / field_24c : 1.0f;
                f32 strength = field_248_f * ratio;
                result->Unk_49d250(0, 0, 1, 0, 0);
                f32 amount = field_248_f;
                amount = amount < 1.0f && amount > 0.0f ? amount : 1.0f;
                s32 r = util->DrawLightGhost(width, height, field_234, field_238, field_23c, field_240, field_244,
                                             fov, texture, presetCount, presets, &position, &ghostColor, &position2,
                                             field_260, spread, field_17c, falloff, aspect, amount,
                                             ratio > strength ? ratio : strength, 0, 0);
                if (r < 0) {
#line 6547
                    PPFX_ERROR("CRenderGlare::GenerateGlare_Composite(): pTexUtil->DrawLightGhost() failed (0x%x: %s).\n", r, Unk_446df0(r));
                }
            }
        }
        field_420 = result;
    }
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    return 0;
}

// 0x7100457f00: `source` drawn into each of field_300's textures that is
// narrower than the last one drawn (unless both are floating-point ones),
// then the glare from the last of them
// NON_MATCHING: one instruction: the original combines `format != 26` with the
// negated 32-bit float test as `bic`, here `eor` then `and` (and the code
// after it is 4 bytes later). Tried: the test as `&&`, `&`, a select, `>`, the
// 16-bit test as a value, an int result for the 32-bit one, and 33 more forms
// of Unk_IsFixedFormat. In IR, `or i1 %f32, %eq26` gives the bic; every
// source form ends `or i1 %eq26, %f32` (Reassociate ranks the switch's phi
// above the compare).
s32 CRenderGlare::Unk_457f00(CRenderTexture* source, s32 arg2, CRenderTexture* arg3) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (field_308 >= 1 &&
        (Unk_IsFixedFormat(source->field_2c.field_c) || !Unk_4385e0(field_300[0]->field_2c.field_c))) {
        bool drawn = false;
        CRenderTexture* current = source;
        CRenderTexture* target;
        for (s32 i = 0; i < field_308; i++) {
            target = field_300[i];
            if (static_cast<u32>(target->field_54) < static_cast<u32>(current->field_54)) {
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
                drawn = true;
                util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, target, 0, &color, 0, false, false, 1, &offset,
                                 nullptr, -1);
                current = target;
            }
        }
        if (drawn) {
            source = target;
        }
    }
    CRenderTexture* glare = Unk_ArrayTexture(m_pGlareSource, 2);
    if (arg2) {
        CRenderTexture* texture = Unk_ArrayTexture(m_pGlareSource, 1);
        Unk_457760(source, texture);
        util->Unk_490570(Unk_ArrayTexture(m_pGlareSource, 2), texture, arg3, arg2, false);
    } else {
        Unk_457760(source, glare);
    }
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    Unk_440cf0_get(reinterpret_cast<u64>(field_20), 0);
    field_20->vf46(0);
    return 0;
}

// 0x710045ee80: the glare of a frame. field_170 points to one of
// GPUGlareDef.cpp's definitions (Unk_24e5948, Unk_45_170 is how this file
// reads it), `index` -1 taking `color` instead.
s32 CRenderGlare::Unk_45ee80(CRenderTexture* source, f32 f0, f32 f1, f32 f2, f32 f3, s32 arg2, f32 f4, u32 index,
                             const Unk_45_170* color, f32 f5, f32 f6, bool flag, s32 arg6, CRenderTexture* arg7) {
    s32 levels = static_cast<s32>(logf(static_cast<f32>(field_b0.field_c) / 1280.0f) / 0.693147182f);
    f32 intensity = f2 < 0.0f ? 1.0f : f2;
    f32 aspect = f0 / f1;
    field_140 = arg2;
    field_178 = f5;
    field_17c = f6;
    field_168 = f0;
    field_13c = f3;
    field_144 = f4;
    field_138 = intensity;
    field_164 = aspect;
    field_414 = levels + 2;
    bool skip = f5 <= 0.0f || flag;
    if (index != 0xffffffff) {
        color = reinterpret_cast<const Unk_45_170*>(&Unk_24e5948[index]);
    } else if (color == nullptr) {
        return -1;
    }
    field_170 = color;
    field_134 = Unk_45ed80();
    f32 k = field_b0.field_4a ? 1.8f : 2.2f;
    field_1e0 = field_404 * k * exp2f(-(static_cast<f32>(Unk_LevelCount()) - 1.0f));
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->Unk_471410(0x10, 3, 4);
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    Unk_457f00(source, arg6, arg7);
    s32 result = Unk_458720();
    if (result < 0) {
        return result;
    }
    field_41c = false;
    Unk_4593f0(false);
    if (Unk_456f30()) {
        Unk_4593f0(true);
    }
    result = Unk_45a820();
    if (result < 0) {
        return result;
    }
    if (!skip) {
        result = GenerateGlare_Afterimage();
        if (result < 0) {
            return result;
        }
    }
    Unk_45c880();
    GenerateGlare_Composite();
    field_358[static_cast<u32>(field_2ec)] = field_164;
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    return 0;
}

}  // namespace PPFX

// 0x71004534a0: the glare's numbers that the post effect sets (its first
// argument is the glare)
s32 Unk_4534a0(void* self_, const PPFX::Unk_GlareRect* rect, f32 a, f32 b, f32 c, f32 d, f32 e) {
    PPFX::CRenderGlare* self = static_cast<PPFX::CRenderGlare*>(self_);
    self->field_224 = *rect;
    self->field_234 = a;
    self->field_238 = b;
    self->field_23c = c;
    self->field_240 = d;
    self->field_244 = e;
    return 0;
}

namespace PPFX {
struct Unk_45eb90_Self;
struct Unk_RenderTexture;
}  // namespace PPFX
// 0x710049ad30 (GPURenderTexture.cpp): a render texture's viewport
s32 Unk_49ad30(PPFX::CRenderTexture* texture, s32 width, s32 height, s32 x, s32 y);

// a render texture's viewport from the fractions (at least one pixel; inline)
static inline s32 Unk_SetViewport(PPFX::CRenderTexture* texture, f32 width, f32 height, f32 x, f32 y) {
    s32 w = static_cast<s32>(width * static_cast<f32>(static_cast<u32>(texture->field_2c.field_4)));
    s32 h = static_cast<s32>(height * static_cast<f32>(static_cast<u32>(texture->field_2c.field_8)));
    s32 ix = static_cast<s32>(x * static_cast<f32>(static_cast<u32>(texture->field_2c.field_4)));
    s32 iy = static_cast<s32>(y * static_cast<f32>(static_cast<u32>(texture->field_2c.field_8)));
    if (width > 0.0f) {
        w = w > 1 ? w : 1;
    }
    if (height > 0.0f) {
        h = h > 1 ? h : 1;
    }
    return Unk_49ad30(texture, w, h, ix, iy);
}

// 0x710045eb90: the viewports of the glare's textures (its first argument is
// the glare)
s32 Unk_45eb90(PPFX::Unk_45eb90_Self* self_, f32 width, f32 height, f32 x, f32 y) {
    PPFX::CRenderGlare* self = reinterpret_cast<PPFX::CRenderGlare*>(self_);
    s32 result = 0;
    for (s32 i = 0; i < self->field_308; i++) {
        s32 r = Unk_SetViewport(self->field_300[i], width, height, x, y);
        if (r < 0) {
            result = r;
        }
    }
    return result;
}

// 0x7100440c60 (lib/yebis/leaf)
u32 Unk_440c60_get(u64 device, u32 arg1, u32 arg2);

namespace PPFX {

// whether a surface format is one the hardware converts to sRGB (inline)
static inline bool Unk_IsSrgbFormat(s32 format) {
    switch (format) {
    case 72:
    case 75:
    case 78:
    case 91:
    case 93:
    case 99:
    case 29:
        return true;
    default:
        return false;
    }
}

// the smallest step of a surface format's channels (inline)
static inline f32 Unk_SurfaceStep(s32 format) {
    if (Unk_IsGlareFormatA(format)) {
        return 1.0f / 65535.0f;
    }
    if (format != 0 && Unk_IsGlareFormatB(format)) {
        return 1.0f / 1023.0f;
    }
    if (Unk_IsGlareFormatC(format)) {
        return 1.0f / 255.0f;
    }
    if (format != 0 && (format == 85 || format == 86)) {
        return 1.0f / 31.0f;
    }
    return 0.0f;
}

// `x` clamped to 0 and `high` (inline)
static inline f32 Unk_ClampTo(f32 x, f32 high) {
    return x < 0.0f ? 0.0f : (x > high ? high : x);
}

// a rectangle narrowed to the part `rect` gives (its size, then its offset; inline)
static inline void Unk_SubRect(Unk_Float4* r, const Unk_Float4* rect) {
    f32 w = r->field_0[2].field_0 - r->field_0[0].field_0;
    f32 h = r->field_0[3].field_0 - r->field_0[1].field_0;
    r->field_0[0].field_0 = r->field_0[0].field_0 + w * rect->field_0[2].field_0;
    r->field_0[1].field_0 = r->field_0[1].field_0 + h * rect->field_0[3].field_0;
    r->field_0[2].field_0 = r->field_0[0].field_0 + w * rect->field_0[0].field_0;
    r->field_0[3].field_0 = r->field_0[1].field_0 + h * rect->field_0[1].field_0;
}

// 0x710045f1c0 (its caller's log line names it)
// The light shaft's two field_18c tests are `&` of their parts (closer than `&&`).
// NON_MATCHING: a first draft: the calls, their arguments and the stores are
// the original's; the registers, the spill slots and the order of the
// blocks are not yet (the viewport is clamped in other registers, the
// rectangles of `rect` interleaved otherwise, the copy's weights filled by a
// loop the original unrolls differently)
s32 CRenderGlare::TonemapToSurface(IGPUSurface* surface, bool hasSurface, CRenderTexture* source, bool hasGamma,
                                   s32 format, const Unk_Float4* color, const MATRIXT44* matrix, f32 width, f32 height,
                                   f32 x, f32 y, f32 intensity, f32 gamma, f32 exposure, f32 white, f32 step,
                                   const MATRIXT44* matrix2, f32 luminance, const Unk_Float4* arg17, f32 arg18,
                                   f32 arg19, f32 arg20, f32 arg21, f32 arg22, f32 arg23, f32 aspect, bool arg25,
                                   const Unk_Float4* rect, s32 space, s32 blend, s32 frames, f32 arg30, void* arg31) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->Unk_471410(2, 3, 3);
    IGPUPixelContainer* pixels = reinterpret_cast<IGPUPixelContainer*>(surface);
    f32 g = hasGamma ? gamma : 1.0f;
    bool srgb = false;
    bool forced = false;
    if (surface != nullptr && (pixels->field_5c & 0x40000) != 0) {
        if (Unk_IsSrgbFormat(pixels->field_44.field_0)) {
            srgb = true;
        } else if (g == 0.0f && field_20->field_14ef7) {
            srgb = true;
            forced = true;
        }
    }
    if (g == 0.0f) {
        g = 2.2f;
    }
    f32 encode = srgb ? g * 0.454545438f : g;
    if (hasSurface) {
        field_20->vf8(nullptr);
        if (surface != nullptr) {
            field_20->vf7(0, surface, 0);
        }
    }
    if (forced) {
        field_20->vf38(srgb);
    }
    if (surface != nullptr && step == -3.40282347e+38f) {
        step = Unk_SurfaceStep(pixels->field_44.field_0);
    }
    if (surface != nullptr) {
        if (width == 0.0f) {
            width = static_cast<f32>(pixels->field_44.field_8);
        }
        if (height == 0.0f) {
            height = static_cast<f32>(pixels->field_44.field_c);
        }
    }
    Unk_Viewport current;
    field_20->vf17(&current);
    f32 right = x + width;
    f32 bottom = y + height;
    f32 left = right < x ? right : x;
    f32 far = right < x ? x : right;
    f32 top = bottom < y ? bottom : y;
    f32 low = bottom < y ? y : bottom;
    f32 vw = static_cast<f32>(current.field_8);
    f32 vh = static_cast<f32>(current.field_c);
    Unk_Viewport viewport;
    f32 l = Unk_ClampTo(left, vw);
    viewport.field_0 = static_cast<u32>(l);
    f32 t = Unk_ClampTo(top, vh);
    viewport.field_4 = static_cast<u32>(t);
    viewport.field_8 = static_cast<u32>(Unk_ClampTo(far, vw) - l);
    viewport.field_c = static_cast<u32>(Unk_ClampTo(low, vh) - t);
    viewport.field_10 = 0.0f;
    viewport.field_14 = 1.0f;
    field_20->vf16(&viewport);
    CRenderTexture* glare = nullptr;
    if (field_138 * intensity > 0.0f) {
        glare = field_420;
    }
    f32 glareHeight = 0.0f;
    f32 glareWidth = 0.0f;
    Unk_GPUTexture* glareTexture;
    if (glare != nullptr) {
        glareWidth = static_cast<f32>(static_cast<u32>(glare->field_54));
        glareHeight = static_cast<f32>(static_cast<u32>(glare->field_58));
        glareTexture = Unk_GetTexture(glare);
    } else {
        glareTexture = reinterpret_cast<Unk_GPUTexture*>(util->field_29a70[2]);
    }
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    Unk_Float4 rects[3];
    rects[0] = Unk_Float4(0.0f, 0.0f, source->field_88 * sourceWidth + source->field_90,
                          source->field_8c * sourceHeight + source->field_94);
    if (glare != nullptr) {
        rects[1] = Unk_Float4(0.0f, 0.0f, glare->field_88 * glareWidth + glare->field_90,
                              glare->field_8c * glareHeight + glare->field_94);
    } else {
        rects[1] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (field_180) {
        f32 ratio = Unk_478880(field_b0.field_74, field_b0.field_78, field_18c & (field_198 >= 0.0f));
        f32 s = 1.0f;
        if (!field_18c) {
            f32 a = field_180 ? field_184 : 0.0f;
            f32 b = field_180 ? field_188 : 0.0f;
            s = a * (b * (field_158 - 0.414213568f) + 0.414213568f);
        }
        f32 sx = ratio * s;
        f32 cx = field_15c * (sx + sx) * 0.5f;
        f32 cy = (s + s) * field_160 * 0.5f;
        rects[2] = Unk_Float4(-sx - cx, -s - cy, sx - cx, s - cy);
    } else {
        rects[2] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    f32 vignette = 0.0f;
    f32 radius = field_198;
    if (field_18c & (radius >= 0.0f)) {
        vignette = field_158;
        f32 least = 1.0f / height;
        radius = least < radius ? radius : least;
    }
    bool sameSource = width == sourceWidth && height == sourceHeight;
    bool sameGlare = width == glareWidth && height == glareHeight;
    if (rect != nullptr) {
        for (s32 i = 0; i < 3; i++) {
            Unk_SubRect(&rects[i], rect);
        }
        sameSource = false;
        sameGlare = false;
    }
    field_20->vf44(blend);
    if (blend != 0) {
        Unk_440c40_get(reinterpret_cast<u64>(field_20), 1);
        u32 a = 2;
        u32 b = 1;
        switch (blend) {
        case 1:
            a = 5;
            b = 6;
            break;
        case 2:
            a = 2;
            b = 2;
            break;
        case 3:
            a = 2;
            b = 4;
            break;
        case 4:
            a = 9;
            b = 1;
            break;
        case 5:
            a = 2;
            b = 14;
            break;
        }
        Unk_440c60_get(reinterpret_cast<u64>(field_20), a, b);
    } else {
        Unk_440c40_get(reinterpret_cast<u64>(field_20), 0);
    }
    bool plain = glareTexture == reinterpret_cast<Unk_GPUTexture*>(util->field_29a70[2]);
    if (luminance < 0.0f) {
        luminance = field_164;
    }
    f32 dx = x - static_cast<f32>(static_cast<u32>(viewport.field_0));
    f32 dy = y - static_cast<f32>(static_cast<u32>(viewport.field_4));
    s32 result;
    if (format != -1) {
        result = util->DrawRectGPU_TonemapHDR(
            dx, dy, width, height, luminance, intensity, encode, exposure, rects, Unk_GetTexture(source),
            glareTexture, format, &color->field_0[0].field_0, matrix, matrix2, white, step, vignette, field_190,
            field_194, radius, &field_19c, field_2e8, field_178, g, arg17, arg18, sameSource, sameGlare || plain,
            arg19, arg20, arg21, arg22, arg23, aspect, arg25, 0);
    } else {
        f32 spread = arg30 > 0.0f ? arg30 : -arg30;
        s32 count = sameSource ? 1 : (frames == 1 ? 4 : 1);
        f32 weight = 1.0f / static_cast<f32>(count);
        Unk_Float4 weights[4];
        for (s32 i = 0; i < count; i++) {
            weights[i] = Unk_Float4(weight, weight, weight, weight);
        }
        Unk_Float4 offsets[4];
        if (count == 4) {
            f32 half = fminf(spread, 1.0f) * 0.5f;
            f32 ox = half * (rects[0].field_0[2].field_0 / sourceWidth);
            f32 oy = half * (rects[0].field_0[3].field_0 / sourceHeight);
            offsets[0] = Unk_Float4(-ox, -oy, 0.0f, 0.0f);
            offsets[1] = Unk_Float4(ox, -oy, 0.0f, 0.0f);
            offsets[2] = Unk_Float4(-ox, oy, 0.0f, 0.0f);
            offsets[3] = Unk_Float4(ox, oy, 0.0f, 0.0f);
        } else if (count == 1) {
            offsets[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
        result = util->Unk_475560(dx, dy, width, height, rects[0].field_0[0].field_0, rects[0].field_0[1].field_0,
                                  rects[0].field_0[2].field_0, rects[0].field_0[3].field_0, count, offsets, weights,
                                  Unk_GetTexture(source), static_cast<Unk_GPUTexture*>(arg31), 0, 0);
    }
    if (blend != 0) {
        field_20->vf44(0);
    }
    if (forced) {
        field_20->vf38(0);
    }
    return result < 0 ? result : 0;
}

}  // namespace PPFX

// 0x710045fbe0: _GLOBAL__sub_I_GPURenderGlare.cpp
