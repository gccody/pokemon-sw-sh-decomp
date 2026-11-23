// Scope: common
// PPFX::CRenderGlare (C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp, the
// __FILE__ of its log lines).
#include <math.h>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderGlare.h>
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

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);
// 0x710049e3a0 (GPURenderTexturePool.cpp)
void Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);
// 0x7100440cf0 (lib/yebis/leaf)
u32 Unk_440cf0_get(u64 device, u32 arg);
// 0x710049c8d0 (lib/yebis/leaf), 0x71004a6160 (GPURenderTextureArray.cpp)
s32 Unk_49c8d0_call(void* self, void* value);
namespace PPFX {
struct Unk_4a5d10_Self;
}
s32 Unk_4a6160(PPFX::Unk_4a5d10_Self* self, void* arg1, s32 arg2, f32 arg3);

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

// texture `index` of a render texture array, or null (inline)
static inline CRenderTexture* Unk_ArrayTexture(const CGPUResourceManage* array, s64 index) {
    const CRenderTextureArray* self = static_cast<const CRenderTextureArray*>(array);
    return index < self->field_30 ? self->field_38[index] : nullptr;
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
