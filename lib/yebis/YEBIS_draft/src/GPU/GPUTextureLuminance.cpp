// Scope: common
// PPFX::CTextureLuminance and PPFX::CTextureLuminanceManage
// (lib/yebis/YEBIS_draft/src/GPU/GPUTextureLuminance.h). The TU's statics
// are the ones every src/GPU TU has (Unk_Statics.h), which its static
// initialiser, 0x71004b94e0 (_GLOBAL__sub_I_GPUTextureLuminance.cpp), sets up.
#include <math.h>
#include <string.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTexturePool.h>
#include <yebis/YEBIS_draft/src/GPU/GPUTextureLuminance.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

// one reference less, and the pointer cleared
#define UNK_RELEASE(object)        \
    do {                           \
        if ((object) != nullptr) { \
            (object)->vf1();       \
            (object) = nullptr;    \
        }                          \
    } while (0)
#define UNK_RELEASE_COUNTED(object)  \
    do {                             \
        if ((object) != nullptr) {   \
            (object)->Unk_Release(); \
            (object) = nullptr;      \
        }                            \
    } while (0)

// 0x7100440d50 (lib/yebis/leaf)
u32 Unk_440d50_get(u64 device, u32 arg);
// 0x710049e3a0 (GPURenderTexture.cpp)
s32 Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);

// 0x710049ca70 (GPURenderTexture.cpp)
void Unk_49ca70(void* self, void* arg1, u32 arg2);

namespace PPFX {

// PPFX::IGPUTexture, as this file calls it
struct Unk_4b7a30_Texture {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual s32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual s32 vf10();
    virtual s32 vf11(bool flag);
    virtual void vf12(s32* value, bool flag);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(u32 filter);
};

// 0x71024e1500: PPFX's settings; field_10 is the number of frame slots
struct Unk_24e1500_Settings {
    u8 _0[0x10];
    u32 field_10;
};
extern Unk_24e1500_Settings Unk_24e1500;

static inline u32 Unk_FrameSlots() {
    return Unk_24e1500.field_10 > 1 ? Unk_24e1500.field_10 : 1;
}

// the device's frame number, as this file reads it
struct Unk_4b7f40_Device {
    u8 _0[0x28];
    u32 field_28;
};

// a surface's device texture and the resource it maps, as this file reads them
struct Unk_4b7f40_Resource {
    u8 _0[0x20];
    void* field_20;  // the buffer
};
struct Unk_4b7f40_Texture {
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
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual Unk_4b7f40_Resource* vf27(s32 level);
};
struct Unk_4b7f40_Surface {
    u8 _0[0xa8];
    Unk_4b7f40_Texture* field_a8;
};

// 0x7101eea4bc, 0x7101eea4ce: the classes' names
extern const char Unk_1eea4bc[];
extern const char Unk_1eea4ce[];
const char Unk_1eea4bc[] = "CTextureLuminance";
const char Unk_1eea4ce[] = "CTextureLuminanceManage";

// 0x71004b75a0
s32 CTextureLuminance::Unk_4b75a0(const char* name) {
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1eea4bc) + " " + name;
    else
        field_10 = Unk_1eea4bc;
    Unk_Reset();
    return 0;
}

// 0x71004b7670: makes the texture it reads back and the chain of smaller
// ones down to it (each `factor` times smaller)
s32 CTextureLuminance::Unk_4b7670(CRenderTexture* target, s32 factor, s32 mode) {
    {
        Unk_TFXString name = field_10 + "::m_pLuminanceTexture";
        const char* text = name.field_8;
#line 151
        field_30 = UNK_NEW(CRenderTexture)(text);
    }
    field_60 = mode;
    s32 result = field_30->Unk_Create(0x4400, 1, 1, 0x1c);
    if (result < 0)
        return result;
    field_80 = 0;
    field_78 = nullptr;
    if (target != nullptr) {
        u32 width = static_cast<s32>(pow(2.0, static_cast<s32>(log(static_cast<f64>(target->field_54)) / log(2.0))));
        f32 scale = static_cast<f32>(static_cast<u32>(factor) > 2 ? static_cast<u32>(factor) : 2);
        u32 height = static_cast<s32>(pow(2.0, static_cast<s32>(log(static_cast<f64>(target->field_58)) / log(2.0))));
        f32 ratio = 1.0f / scale;
        f32 x = 1.0f / static_cast<f32>(width);
        f32 y = 1.0f / static_cast<f32>(height);
        s32 levels = static_cast<s32>(ceilf(logf(x > y ? x : y) / logf(ratio)));
        field_80 = levels - 1 < 0 ? 0 : levels - 1;
        if (levels > 1) {
            CTextureUtil* util = Unk_GetTextureUtil();
            Unk_ReleaseTextureUtil();
#line 223
            field_78 = UNK_NEW_ARRAY(CRenderTexture*, field_80);
            memset(field_78, 0, field_80 * sizeof(CRenderTexture*));
            for (s32 i = 0; i < field_80; i++) {
                width = static_cast<u32>(static_cast<f32>(width) / scale + 0.99f);
                height = static_cast<u32>(static_cast<f32>(height) / scale + 0.99f);
                util->field_29a58->Unk_49fc10(&field_78[i], width, height, 0x1c, true, 0, 0);
            }
        }
    }
    field_98 = 2;
    return 0;
}

// 0x71004b79b0, 0x71004b79f0
CTextureLuminance::~CTextureLuminance() {
    Unk_49ec80();
}

// 0x71004b7a30
s32 CTextureLuminance::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0)
        return result;
    if (field_20 == nullptr)
        return 0;
    result = field_30->vf0(field_20);
    if (result < 0)
        return result;
    CRenderTexture* texture = field_30;
    while (texture->field_120 != nullptr)
        texture = texture->field_120;
    reinterpret_cast<Unk_4b7a30_Texture*>(texture->field_a8)->vf15(5);
    field_60 = 5;
    field_3c = 0;
    field_74 = 0.0f;
    return 0;
}

// 0x71004b7ac0
s32 CTextureLuminance::vf1() {
    field_30->vf1();
    field_88 = 0;
    UNK_RELEASE(field_40);
    UNK_RELEASE(field_48);
    UNK_RELEASE(field_50);
    UNK_RELEASE(field_58);
    return CGPUResourceManage::vf1();
}

// 0x71004b7b60
s32 CTextureLuminance::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    return field_30 == nullptr ? -1 : 0;
}

// 0x71004b7b90
s32 CTextureLuminance::vf3() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    UNK_RELEASE_COUNTED(field_30);
    if (field_78 != nullptr) {
        Unk_49fc60(util->field_29a58, field_80, field_78);
        UNK_DELETE_ARRAY(field_78);
        field_80 = 0;
    }
    Unk_Reset();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x71004b7d60
s32 CTextureLuminance::Unk_4b7d60(CRenderTexture* source) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    bool drawn = false;
    CRenderTexture* current = source;
    CRenderTexture* texture;
    for (s32 i = 0; i < field_80; i++) {
        texture = field_78[i];
        if (static_cast<u32>(texture->field_54) < static_cast<u32>(current->field_54)) {
            drawn = true;
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, texture, 0, &color, 0, false, false, 1, &zero, nullptr,
                             -1);
            current = texture;
        }
    }
    field_88 = drawn ? texture : source;
    return 0;
}

// the colour read back from the target's buffer into field_90 (inline)
static inline void Unk_ReadBack(CTextureLuminance* self) {
    Unk_SiGfxDrawContext* context = self->field_20->field_30;
    Unk_4b7f40_Resource* resource =
        reinterpret_cast<Unk_4b7f40_Surface*>(self->field_30->field_b8[self->field_30->field_a0])->field_a8->vf27(0);
    void* buffer = resource->field_20;
    IGPUBuffer::Unk_MapInfo info;
    info.field_8 = 4;
    info.field_0 = 1;
    if (context->vf69(buffer, &info)) {
        u32 value = *reinterpret_cast<const u32*>(info.field_20);
        u8 b = value;
        u8 g = value >> 8;
        u8 r = value >> 16;
        u8 a = value >> 24;
        self->field_90[2] = b;
        self->field_90[0] = r;
        self->field_90[1] = g;
        self->field_90[3] = a;
        context->vf70(buffer, &info);
    }
}

// 0x71004b7f40
s32 CTextureLuminance::Unk_4b7f40() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    CRenderTexture* source = field_88;
    CRenderTexture* target = field_30;
    if (field_60 == 3) {
        reinterpret_cast<Unk_4b7a30_Texture*>(field_40)->vf7();
        reinterpret_cast<Unk_4b7a30_Texture*>(field_40)->vf9();
    }
    {
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, source, target, 0, &color, 0, false, false, 1, &zero, nullptr, -1);
    }
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    field_9c = reinterpret_cast<Unk_4b7f40_Device*>(field_20)->field_28 % Unk_FrameSlots();
    switch (field_60) {
    case 3: {
        s32 result = reinterpret_cast<Unk_4b7a30_Texture*>(field_40)->vf10();
        if (result < 0)
            return result;
        break;
    }
    case 4: {
        s32 result = util->Unk_48d7f0(Unk_GetTexture(field_30), &field_40, field_38, nullptr);
        if (result < 0)
            return result;
        break;
    }
    case 2:
        Unk_ReadBack(this);
        break;
    }
    if (field_60 == 5)
        field_94 = 0;
    return 0;
}

// whether the device and the four objects are ready
inline s32 CTextureLuminance::Unk_CheckReady() {
    if (field_20 == nullptr || field_74 < 0.0f)
        return -3;
    for (s32 i = 0; i < field_3c; i++) {
        s32 result = reinterpret_cast<Unk_4b7a30_Texture*>((&field_40)[i])->vf7();
        if (result < 0)
            return result;
    }
    return 0;
}

// 0x71004b8240
s32 CTextureLuminance::Unk_4b8240(CRenderTexture* source, bool flag) {
    s32 result = Unk_CheckReady();
    if (result < 0)
        return result;
    field_74 = -1.0f;
    if (source == nullptr)
        source = field_88;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (flag)
        util->Unk_471410(1, 3, -1);
    Unk_440d50_get(reinterpret_cast<u64>(field_20), 0);
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    Unk_4b7d60(source);
    result = Unk_4b7f40();
    if (result < 0)
        return result;
    Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    return 0;
}

// 0x71004b8450: the luminance from what was read back
// NON_MATCHING: register allocation in the conversion of the colour (the
// original keeps red, green, blue and alpha in s0 to s3 and 1/255 in s4).
s32 CTextureLuminance::Unk_4b8450(bool flag) {
    if (field_74 >= 0.0f) {
        return 0;
    }
    s32 mode = field_60;
    if (mode == 1 || mode == 2) {
    } else if (mode == 3 || mode == 4) {
        s32 values[4] = {0, 0, 0, 0};
        for (s32 i = 0; i < field_3c; i++) {
            reinterpret_cast<Unk_4b7a30_Texture*>((&field_40)[i])->vf12(&values[i], flag);
            values[i] = values[i] < 0xff ? values[i] : 0xff;
        }
        if (mode == 3) {
            Unk_GetTexture(field_30);
        } else if (mode == 4) {
            if (field_3c > 2) {
                field_90[0] = values[2];
                field_90[1] = values[1];
                field_90[2] = values[0];
                field_90[3] = values[3];
            } else {
                for (s32 k = 0; k < 3; k++) {
                    field_90[k] = values[0];
                }
                field_90[3] = values[1];
            }
        }
    } else if (mode == 5) {
        Unk_ReadBack(this);
    }
    if (field_74 >= 0.0f) {
        return 0;
    }
    f32 r = field_90[2] * (1.0f / 255.0f);
    f32 b = field_90[0] * (1.0f / 255.0f);
    f32 a = field_90[3] * (1.0f / 255.0f);
    f32 g = field_90[1] * (1.0f / 255.0f);
    field_6c = b;
    field_70 = a;
    field_64 = r;
    field_68 = g;
    field_74 = r * 0.2126f + g * 0.7152f + b * 0.0722f;
    return 0;
}

// 0x71004b86d0
CTextureLuminanceManage::CTextureLuminanceManage(const char* name) : CGPUResourceManage(nullptr) {
    Unk_4b8710(name);
}

// 0x71004b8710
s32 CTextureLuminanceManage::Unk_4b8710(const char* name) {
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1eea4ce) + " " + name;
    else
        field_10 = Unk_1eea4ce;
    memset(&field_2c, 0, sizeof(field_2c));
    field_58 = 0;
    field_40 = nullptr;
    field_48 = nullptr;
    field_50 = 0;
    field_54 = false;
    return 0;
}

// 0x71004b87d0
s32 CTextureLuminanceManage::Unk_4b87d0(const Unk_Desc* desc) {
    IGPUDevice* device = field_20;
    Unk_49ec80();
    memmove(&field_2c, desc, sizeof(field_2c));
    s32 result = Unk_4b8830();
    if (result < 0)
        return result;
    return Unk_49ec30(device);
}

// 0x71004b8830
s32 CTextureLuminanceManage::Unk_4b8830() {
    {
        Unk_TFXString name = field_10 + "::m_pQueryLuminance";
        const char* text = name.field_8;
#line 1920
        field_40 = UNK_NEW(CTextureLuminance)(text);
    }
    {
        Unk_TFXString name = field_10 + "::m_pTargetTexture";
        const char* text = name.field_8;
#line 1921
        field_48 = UNK_NEW(CRenderTexture)(text);
    }
    s32 result = field_48->Unk_Create(0x400, field_2c.field_4, field_2c.field_8, 0x1c);
    if (result < 0)
        return result;
    s32 count = field_2c.field_0;
    switch (count) {
    case 0:
        break;
    case 1:
        count = 3;
        break;
    default:
        count--;
        break;
    }
    result = field_40->Unk_Create(field_48, count, field_2c.field_c);
    return result < 0 ? result : 0;
}

// 0x71004b89b0
s32 CTextureLuminanceManage::Unk_4b89b0() {
    CTextureLuminance* luminance = field_40;
    if (luminance->field_20 == nullptr || luminance->field_74 < 0.0f)
        return -3;
    for (s32 i = 0; i < luminance->field_3c; i++) {
        s32 result = reinterpret_cast<Unk_4b7a30_Texture*>((&luminance->field_40)[i])->vf7();
        if (result < 0)
            return result;
    }
    return 0;
}

// 0x71004b8a40
s32 CTextureLuminanceManage::Unk_4b8a40(bool flag, f32 a, f32 b, f32 c, f32 d) {
    s32 result = field_40->Unk_4b8240(field_48, flag);
    if (result < 0)
        return result;
    s32 index = field_50 % 17;
    field_3e8[index] = a;
    field_42c[index] = b;
    field_470[index] = c;
    field_4b4[index] = d;
    field_54 = true;
    return 0;
}

// 0x71004b8ae0
f32 CTextureLuminanceManage::Unk_4b8ae0(f32 a, f32 b, f32 c) {
    s32 mode = field_500;
    f32 value;
    if (mode < 0) {
        f32 scale = b * 100.0f;
        value = expf(a * 8.0f) / scale;
    } else {
        value = Unk_462c30(mode, a, b, 1.0f);
    }
    return value / c;
}

// whether what was measured can be read back
inline s32 CTextureLuminance::Unk_Poll() {
    if (field_74 >= 0.0f)
        return 0;
    switch (field_60) {
    case 3:
    case 4:
        for (s32 i = field_3c - 1; i < field_3c; i++) {
            s32 result = reinterpret_cast<Unk_4b7a30_Texture*>((&field_40)[i])->vf11(false);
            if (result != 0)
                return result;
        }
        break;
    case 5:
        if (field_94 < field_98 * Unk_FrameSlots()) {
            field_94++;
            return 1;
        }
        break;
    }
    if (reinterpret_cast<Unk_4b7f40_Device*>(field_20)->field_28 % Unk_FrameSlots() != field_9c)
        return 1;
    return 0;
}

static inline f32 Unk_Lerp(f32 a, f32 b, f32 t) {
    return a + t * (b - a);
}

static inline CTextureLuminanceManage::Unk_Value Unk_LerpValue(const CTextureLuminanceManage::Unk_Value& a,
                                                               const CTextureLuminanceManage::Unk_Value& b, f32 t) {
    CTextureLuminanceManage::Unk_Value r;
    for (s32 i = 0; i < 4; i++)
        r.field_0[i] = b.field_0[i] - a.field_0[i];
    for (s32 i = 0; i < 4; i++)
        r.field_0[i] = t * r.field_0[i];
    for (s32 i = 0; i < 4; i++)
        r.field_0[i] = a.field_0[i] + r.field_0[i];
    return r;
}

// 0x71004b8b50
// NON_MATCHING: scheduling and registers: the colour's address is computed
// before the luminance object's call, &field_360[i1] isn't computed before
// the kind test (the original addresses the history as base + index) and the
// history indices' sums are computed in another order.
s32 CTextureLuminanceManage::Unk_4b8b50() {
    field_58++;
    s32 result = 0;
    if (field_54) {
        result = field_40->Unk_Poll();
        if (result == 0) {
            s32 index = field_50 % 17;
            field_74[index] = field_58;
            field_1c8[index] = field_40->Unk_GetLuminance();
            memmove(&field_b8[index], field_40->Unk_GetColor(), sizeof(Unk_Value));
            if (field_2c.field_0 == 1) {
                f32 depth =
                    field_b8[index].field_0[1] * 255.0f / 256.0f + field_b8[index].field_0[2] * 255.0f / 65536.0f;
                f32 far = field_4b4[index];
                f32 near = field_470[index];
                field_20c[index] = -(far * near) / ((far - near) * depth - far);
            } else {
                field_20c[index] = Unk_4b8ae0(field_1c8[index], field_42c[index], field_3e8[index]);
            }
            f32* ratio = &field_20c[index];
            s32 previous = (field_50 + 1) % 17;
            u32 mode = field_2c.field_0;
            f32 t = field_4fc;
            field_360[index] = Unk_Lerp(field_360[previous], field_1c8[index], t);
            f32 a = field_3a4[previous] + 1.17549435e-38f;
            f32 value;
            if (mode == 1) {
                f32 b = *ratio + 1.17549435e-38f;
                value = 1.0f / Unk_Lerp(1.0f / a, 1.0f / b, t);
            } else {
                f32 la = logf(a);
                value = expf(Unk_Lerp(la, logf(*ratio + 1.17549435e-38f), t));
            }
            field_3a4[index] = value - 1.17549435e-38f;
            field_250[index] = Unk_LerpValue(field_250[previous], field_b8[index], t);
            field_54 = false;
            field_58 = 0;
            field_50 = field_50 - 1 < 0 ? 16 : field_50 - 1;
        }
    }
    s32 offset2 = field_4f8 + 2;
    if (offset2 < 0)
        offset2 = 16;
    s32 offset1 = field_4f8 + 1;
    if (offset1 < 0)
        offset1 = 16;
    s32 i2 = (offset2 + field_50) % 17;
    s32 i1 = (offset1 + field_50) % 17;
    f32 t = static_cast<f32>(field_58) / static_cast<f32>(field_74[i1]);
    t = t < 0.0f ? 0.0f : std::min(t, 1.0f);
    if (field_2c.field_0 == 1) {
        f32 la = logf(field_360[i2] + 1.17549435e-38f);
        field_60 = expf(Unk_Lerp(la, logf(field_360[i1] + 1.17549435e-38f), t)) - 1.17549435e-38f;
        f32 lb = logf(field_3a4[i2] + 1.17549435e-38f);
        field_5c = expf(Unk_Lerp(lb, logf(field_3a4[i1] + 1.17549435e-38f), t)) - 1.17549435e-38f;
    } else {
        field_60 = Unk_Lerp(field_360[i2], field_360[i1], t);
        field_5c = Unk_Lerp(field_3a4[i2], field_3a4[i1], t);
    }
    field_64 = Unk_LerpValue(field_250[i2], field_250[i1], t);
    if (field_2c.field_0 != 1) {
        f32 value = Unk_4b8ae0(field_60, Unk_Lerp(field_42c[i2], field_42c[i1], t), Unk_Lerp(field_3e8[i2], field_3e8[i1], t));
        if (field_500 >= 0)
            field_5c = value;
    }
    return result < 0 ? result : 0;
}

// 0x71004b9140
s32 CTextureLuminanceManage::Unk_4b9140(const Unk_Value* value, bool flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 ratio = a;
    if (field_2c.field_0 != 1)
        ratio = a / b;
    field_5c = ratio;
    field_60 = a;
    memmove(&field_64, value, sizeof(field_64));
    for (s32 i = 0; i < 17; i++) {
        field_74[i] = 1;
        field_20c[i] = ratio;
        field_1c8[i] = a;
        memmove(&field_b8[i], value, sizeof(Unk_Value));
        field_3a4[i] = ratio;
        field_360[i] = a;
        memmove(&field_250[i], value, sizeof(Unk_Value));
        field_3e8[i] = b;
        field_42c[i] = c;
        field_470[i] = d;
        field_4b4[i] = e;
    }
    if (flag && field_48 != nullptr)
        Unk_49ca70(field_48, nullptr, 0xffffffff);
    return 0;
}

// 0x71004b9220, 0x71004b9260
CTextureLuminanceManage::~CTextureLuminanceManage() {
    Unk_49ec80();
}

// 0x71004b92a0
s32 CTextureLuminanceManage::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0)
        return result;
    if (field_20 == nullptr)
        return 0;
    result = field_48->vf0(field_20);
    if (result < 0)
        return result;
    result = field_40->vf0(field_20);
    if (result < 0)
        return result;
    field_4f8 = 4;
    field_4fc = 0.25f;
    field_500 = -1;
    Unk_Reset(Unk_Value(0.0f, 0.0f, 0.0f, 0.0f), 0.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    return 0;
}

// 0x71004b9380
s32 CTextureLuminanceManage::vf1() {
    field_48->vf1();
    field_40->vf1();
    return CGPUResourceManage::vf1();
}

// 0x71004b93c0
s32 CTextureLuminanceManage::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    if (field_40 == nullptr)
        return -1;
    return field_48 == nullptr ? -1 : 0;
}

// 0x71004b9410
s32 CTextureLuminanceManage::vf3() {
    UNK_RELEASE_COUNTED(field_48);
    UNK_RELEASE_COUNTED(field_40);
    memset(&field_2c, 0, sizeof(field_2c));
    field_58 = 0;
    field_40 = nullptr;
    field_48 = nullptr;
    field_50 = 0;
    field_54 = false;
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

}  // namespace PPFX
