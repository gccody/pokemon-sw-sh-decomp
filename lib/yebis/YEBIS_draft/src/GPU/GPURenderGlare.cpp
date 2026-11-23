// Scope: common
// PPFX::CRenderGlare (C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp, the
// __FILE__ of its log lines).
#include <math.h>

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
// field_340
s32 CRenderGlare::CreateDeviceResources() {
    if (field_20 == nullptr) {
        return -1;
    }
    s32 result = field_2f0->vf0(field_20);
    if (result < 0) {
        return result;
    }
    result = field_398->vf0(field_20);
    if (result < 0) {
        return result;
    }
    if (field_3b8 != nullptr) {
        result = field_3b8->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_3b0 != nullptr) {
        result = field_3b0->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_3a8 != nullptr) {
        result = field_3a8->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_3a0 != nullptr) {
        result = field_3a0->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        result = field_310[i]->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    result = field_318->vf0(field_20);
    if (result < 0) {
        return result;
    }
    if (field_328 != nullptr) {
        result = field_328->vf0(field_20);
        if (result < 0) {
            return result;
        }
        for (u32 i = 0; i < static_cast<u32>(static_cast<CRenderTextureArray*>(field_328)->field_30); i++) {
            Unk_GPUTexture* texture = Unk_GetTexture(static_cast<CRenderTextureArray*>(field_328)->Unk_Texture(i));
            if (i < static_cast<u32>(field_b0.field_18[10])) {
                texture->vf17(1);
            } else {
                texture->vf17(0);
            }
        }
    }
    if (field_330 != nullptr) {
        result = field_330->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_338 != nullptr) {
        result = field_338->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_340 != nullptr) {
        result = field_340->vf0(field_20);
        if (result < 0) {
            return result;
        }
        for (u32 i = 0; i < static_cast<u32>(static_cast<CRenderTextureArray*>(field_340)->field_30); i++) {
            Unk_GetTexture(static_cast<CRenderTextureArray*>(field_340)->Unk_Texture(i))->vf18(0);
        }
        Unk_GetTexture(static_cast<CRenderTextureArray*>(field_340)->Unk_Texture(0))->vf18(1);
    }
    if (field_390 != nullptr) {
        result = field_390->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_350 != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            result = field_350[i]->vf0(field_20);
            if (result < 0) {
                return result;
            }
        }
    }
    if (field_3c0 != nullptr) {
        result = field_3c0->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_3d0 != nullptr) {
        result = field_3d0->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_3c8 != nullptr) {
        result = field_3c8->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    if (field_340 != nullptr) {
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
    field_2f0->vf1();
    field_318->vf1();
    field_398->vf1();
    if (field_3a0 != nullptr) {
        field_3a0->vf1();
    }
    if (field_3a8 != nullptr) {
        field_3a8->vf1();
    }
    if (field_3b0 != nullptr) {
        field_3b0->vf1();
    }
    if (field_3b8 != nullptr) {
        field_3b8->vf1();
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        field_310[i]->vf1();
    }
    if (field_328 != nullptr) {
        field_328->vf1();
    }
    if (field_330 != nullptr) {
        field_330->vf1();
    }
    if (field_338 != nullptr) {
        field_338->vf1();
    }
    if (field_340 != nullptr) {
        field_340->vf1();
    }
    if (field_390 != nullptr) {
        field_390->vf1();
    }
    if (field_350 != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            field_350[i]->vf1();
        }
    }
    if (field_3c0 != nullptr) {
        field_3c0->vf1();
    }
    if (field_3d0 != nullptr) {
        field_3d0->vf1();
    }
    if (field_3c8 != nullptr) {
        field_3c8->vf1();
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
    UNK_DELETE(field_318);
    UNK_DELETE(field_398);
    UNK_DELETE(field_3a0);
    UNK_DELETE(field_3a8);
    UNK_DELETE(field_3b0);
    UNK_DELETE(field_3b8);
    UNK_DELETE(field_2f0);
    UNK_DELETE(field_328);
    UNK_DELETE(field_330);
    UNK_DELETE(field_338);
    UNK_DELETE(field_3c0);
    UNK_DELETE(field_3d0);
    UNK_DELETE(field_3c8);
    UNK_DELETE_ARRAY(field_1f8);
    UNK_DELETE_ARRAY(field_208);
    UNK_DELETE(field_340);
    UNK_DELETE(field_390);
    if (field_350 != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            UNK_DELETE(field_350[i]);
        }
        UNK_DELETE_ARRAY(field_350);
    }
    UNK_DELETE_ARRAY(field_358);
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        UNK_DELETE(field_310[i]);
    }
    UNK_DELETE_ARRAY(field_310);
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
// NON_MATCHING: the blocks of the second condition are laid out the other way
// round (`cbz` to the constant), the `and` of the two conditions has its
// operands exchanged, and the last test becomes a `cset` here.
bool CRenderGlare::Unk_457650() {
    bool a = Unk_456bf0();
    bool b = Unk_456f30();
    bool c = Unk_4570b0();
    bool d = Unk_457370();
    s32 frames = field_1f4;
    bool idle = field_200 < 1 || (field_210 == -1 && field_220 < 1);
    bool released = !field_368 || field_360 == 0;
    if ((idle & released) != true) {
        return false;
    }
    if (a || b || c || d) {
        return false;
    }
    if (frames > 0 || field_418 != 0.0f || field_b0.field_14 || field_26c) {
        return false;
    }
    return true;
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

// 0x710045ed80
// NON_MATCHING: the original tests the first kind's range and bits in one
// branch (`cmp #0x3b ; ccmp ... ls ; b.eq`) and the zero test after it; here
// the range test is a branch of its own. A switch, a range expression and a
// bit test were tried, with signed and unsigned formats.
f32 CRenderGlare::Unk_45ed80() {
    if (field_b0.field_4a) {
        return field_3e8 * field_3f8;
    }
    s32 format = field_b0.field_18[3];
    if (Unk_IsGlareFormatA(format)) {
        return field_3e0 * field_3f0;
    }
    if (format != 0 && Unk_IsGlareFormatB(format)) {
        return field_3e4 * field_3f4;
    }
    if (Unk_IsGlareFormatC(format)) {
        return field_3e8 * field_3f8;
    }
    return field_3dc * field_3ec;
}

// 0x710045ee20
// NON_MATCHING: as 0x710045ed80's first test; and the original selects 128 or
// 64 with `fcsel` where this makes a table of the two.
f32 CRenderGlare::Unk_45ee20() {
    s32 format = field_b0.field_18[3];
    if (Unk_IsGlareFormatA(format)) {
        return 2048.0f;
    }
    return format != 0 && Unk_IsGlareFormatB(format) ? 128.0f : 64.0f;
}

// 0x7100456bf0: whether the glare's ghosts have something to draw
bool CRenderGlare::Unk_456bf0() {
    if (field_328 == nullptr) {
        return false;
    }
    if (field_330 == nullptr) {
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
    if (field_328 == nullptr) {
        return false;
    }
    if (field_338 == nullptr) {
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
    if (field_340 == nullptr) {
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
    if (field_350 == nullptr) {
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
    result = Unk_453540();
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
    if (field_330 != nullptr) {
        result = Unk_49c8d0_call(field_330, arg);
    }
    if (field_328 != nullptr) {
        result = Unk_SetArray(field_328, arg);
    }
    if (field_340 != nullptr) {
        result = Unk_SetArray(field_340, arg);
    }
    if (field_3c0 != nullptr) {
        result = Unk_49c8d0_call(field_3c0, arg);
    }
    if (field_3d0 != nullptr) {
        result = Unk_49c8d0_call(field_3d0, arg);
    }
    if (field_3c8 != nullptr) {
        result = Unk_SetArray(field_3c8, arg);
    }
    Unk_49c8d0_call(field_318, arg);
    if (field_350 != nullptr) {
        s32 count = field_b0.field_4c;
        for (s32 i = 0; i < count; i++) {
            if (field_350[i] != nullptr) {
                result = Unk_SetArray(field_350[i], arg);
            }
        }
    }
    Unk_SetArray(field_2f0, arg);
    Unk_49c8d0_call(field_398, arg);
    if (field_3a8 != nullptr) {
        Unk_49c8d0_call(field_3a8, arg);
    }
    if (field_3a0 != nullptr) {
        Unk_49c8d0_call(field_3a0, arg);
    }
    if (field_3b0 != nullptr) {
        Unk_49c8d0_call(field_3b0, arg);
    }
    if (field_3b8 != nullptr) {
        Unk_49c8d0_call(field_3b8, arg);
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        result = Unk_SetArray(field_310[i], arg);
    }
    for (s32 i = 0; i < field_308; i++) {
        result = Unk_49c8d0_call(field_300[i], arg);
    }
    return result;
}

// 0x710045c880: each view's glare, then all of them into field_3d0
// NON_MATCHING: the loop unswitched on `count == 1` is laid out first here
// (the original branches to it), and the test after the loop is `b.le`, not
// `b.eq`
s32 CRenderGlare::Unk_45c880() {
    s32 count = field_1f4;
    if (count < 1) {
        return 0;
    }
    for (s32 i = 0; i < count; i++) {
        Unk_45ca70(count != 1 ? Unk_ArrayTexture(field_3c8, i) : nullptr, i);
    }
    if (count > 1) {
        CRenderTexture* textures[16] = {};
        for (s32 i = 0; i < count; i++) {
            textures[i] = Unk_ArrayTexture(field_3c8, i);
        }
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        util->Unk_48d220(1.0f, 1.0f, field_3d0, count, textures, nullptr, 0, 0);
    }
    return 0;
}

}  // namespace PPFX

// 0x71024e58c0 (GPUGlareDef.cpp): the star definitions
extern PPFX::Unk_4a0540* Unk_24e58c0;

namespace PPFX {

// 0x71004593f0: the glare's star into field_330 (`flag`: the sixth star
// definition into field_338), with field_328's textures; without `flag` only
// when the ghosts changed. The ghosts' colours go into field_2f0's fourth
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
    CRenderTexture* target = Unk_ArrayTexture(field_2f0, 2);
    if (field_b0.field_18_f[11] > 0.0f && field_40c > 0.0f) {
        s32 levels = field_3d8;
        CRenderTexture* sources[3];
        sources[0] = Unk_ArrayTexture(field_2f0, 2);
        const Unk_45_320* items = field_320;
        s32 sourceCount = levels > 1 ? 3 : 2;
        sources[1] = items[0].field_18;
        sources[2] = levels >= 2 ? items[1].field_18 : nullptr;
        target = Unk_ArrayTexture(field_2f0, 3);
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
    CRenderTexture** all = static_cast<CRenderTextureArray*>(field_328)->field_38;
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
    Unk_459730(definition, target, flag ? field_338 : field_330, textures, pairs, 2, flag);
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
            } else if (format != 0 && Unk_IsGlareFormatB(format)) {
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
            util->Unk_48d550(value, value, value, value, field_1f0, static_cast<CRenderTexture*>(texture),
                             outputCount, outputs, reinterpret_cast<const Unk_Float*>(weights), field_2e4, false);
            for (s32 i = 0; i < outputCount; i++) {
                Unk_GetTexture(outputs[i])->vf17(0);
            }
        }
    }
    return 0;
}

// 0x7100458e20: the ghosts' levels, each by its colour, added up into
// field_318 (their textures halved into each other first)
// NON_MATCHING: register allocation of the second loop (the textures', the
// colours' and the levels' pointers and the constant 1 get x23/x25/x26/x28,
// the original x26/x23/x28/x25), and the colour loop's scheduling (the
// original computes the blue difference before the alpha one)
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
    CGPUResourceManage* target = field_318;
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
            f32 r = Unk_Lerp(s_white.field_0[0].field_0, c.field_0[0].field_0, t);
            f32 g = Unk_Lerp(s_white.field_0[1].field_0, c.field_0[1].field_0, t);
            f32 b = Unk_Lerp(s_white.field_0[2].field_0, c.field_0[2].field_0, t);
            f32 a = Unk_Lerp(s_white.field_0[3].field_0, c.field_0[3].field_0, t);
            scale *= 3.0f / (Unk_Abs(r) + Unk_Abs(g) + Unk_Abs(b));
            colors[i].field_0[0].field_0 = r * scale;
            colors[i].field_0[1].field_0 = g * scale;
            colors[i].field_0[2].field_0 = b * scale;
            colors[i].field_0[3].field_0 = a * scale;
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
    if (!Unk_ArrayMade(field_2f0)) {
        return false;
    }
    if (!Unk_TextureMade(field_318)) {
        return false;
    }
    if (!Unk_TextureMade(field_398)) {
        return false;
    }
    if (field_3a0 != nullptr && !Unk_TextureMade(field_3a0)) {
        return false;
    }
    if (field_3b8 != nullptr && !Unk_TextureMade(field_3b8)) {
        return false;
    }
    if (field_3b0 != nullptr && !Unk_TextureMade(field_3b0)) {
        return false;
    }
    if (field_3a8 != nullptr && !Unk_TextureMade(field_3a8)) {
        return false;
    }
    for (s32 i = 0; i < count; i++) {
        if (!Unk_ArrayMade(field_310[i])) {
            return false;
        }
    }
    if (field_328 != nullptr && !Unk_ArrayMade(field_328)) {
        return false;
    }
    if (field_330 != nullptr && !Unk_TextureMade(field_330)) {
        return false;
    }
    if (field_338 != nullptr && !Unk_TextureMade(field_338)) {
        return false;
    }
    if (field_340 != nullptr && !Unk_ArrayMade(field_340)) {
        return false;
    }
    if (field_390 != nullptr && !Unk_TextureMade(field_390)) {
        return false;
    }
    if (field_350 != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            if (!Unk_ArrayMade(field_350[i])) {
                return false;
            }
        }
    }
    if (field_3c0 != nullptr && !Unk_TextureMade(field_3c0)) {
        return false;
    }
    if (field_3d0 != nullptr && !Unk_TextureMade(field_3d0)) {
        return false;
    }
    if (field_3c8 != nullptr && !Unk_ArrayMade(field_3c8)) {
        return false;
    }
    return true;
}

// 0x7100457f00: `source` drawn into each of field_300's textures that is
// narrower than the last one drawn (unless both are floating-point ones),
// then the glare from the last of them
// NON_MATCHING: one instruction: the original combines `format != 26` with the
// negated 32-bit float test as `bic`, here `eor` then `and` (and the code
// after it is 4 bytes later). Tried: the test as `&&`, `&`, a select, `>`, the
// 16-bit test as a value, an int result for the 32-bit one.
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
    CRenderTexture* glare = Unk_ArrayTexture(field_2f0, 2);
    if (arg2) {
        CRenderTexture* texture = Unk_ArrayTexture(field_2f0, 1);
        Unk_457760(source, texture);
        util->Unk_490570(Unk_ArrayTexture(field_2f0, 2), texture, arg3, arg2, false);
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
// NON_MATCHING: scheduling at the start (the original converts the level count
// first and adds 2 after the stores; the clamp and the ratio get s1/s2 there)
// and the operands of `field_404 * k` are exchanged. The rest is the original.
s32 CRenderGlare::Unk_45ee80(CRenderTexture* source, f32 f0, f32 f1, f32 f2, f32 f3, s32 arg2, f32 f4, u32 index,
                             const Unk_45_170* color, f32 f5, f32 f6, bool flag, s32 arg6, CRenderTexture* arg7) {
    s32 levels = static_cast<s32>(logf(static_cast<f32>(field_b0.field_c) / 1280.0f) / 0.693147182f);
    f32 intensity = f2 < 0.0f ? 1.0f : f2;
    f32 aspect = f0 / f1;
    field_140 = arg2;
    bool skip = f5 <= 0.0f || flag;
    field_178 = f5;
    field_17c = f6;
    field_168 = f0;
    field_13c = f3;
    field_144 = f4;
    field_138 = intensity;
    field_164 = aspect;
    field_414 = levels + 2;
    if (index != 0xffffffff) {
        color = reinterpret_cast<const Unk_45_170*>(&Unk_24e5948[index]);
    } else if (color == nullptr) {
        return -1;
    }
    field_170 = color;
    field_134 = Unk_45ed80();
    f32 k = field_b0.field_4a ? 1.8f : 2.2f;
    s32 limit = field_3d8;
    s32 n = field_b0.field_18[6] < limit ? field_b0.field_18[6] : limit;
    field_1e0 = field_404 * k * exp2f(-(static_cast<f32>(n) - 1.0f));
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
        result = Unk_45c1e0();
        if (result < 0) {
            return result;
        }
    }
    Unk_45c880();
    Unk_45d3b0();
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
s32 Unk_49ad30(PPFX::Unk_RenderTexture* texture, s32 width, s32 height, s32 x, s32 y);

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
    return Unk_49ad30(reinterpret_cast<PPFX::Unk_RenderTexture*>(texture), w, h, ix, iy);
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

// 0x710045fbe0: _GLOBAL__sub_I_GPURenderGlare.cpp
