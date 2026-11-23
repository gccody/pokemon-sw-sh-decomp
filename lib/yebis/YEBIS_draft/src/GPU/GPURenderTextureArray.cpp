// Scope: common
// PPFX::CRenderTextureArray (lib/yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h).
// The TU's statics are the ones every src/GPU TU has (Unk_Statics.h), which
// its static initialiser, 0x71004a6de0 (_GLOBAL__sub_I_GPURenderTextureArray.cpp),
// sets up.
#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPURenderTextureArray.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result);
// 0x7100440cb0, 0x7100440d50 (lib/yebis/leaf)
u32 Unk_440cb0_get(u64 device, u32 arg);
u32 Unk_440d50_get(u64 device, u32 arg);

// one reference less, and the pointer cleared
#define UNK_RELEASE(object)        \
    do {                           \
        if ((object) != nullptr) { \
            (object)->vf1();       \
            (object) = nullptr;    \
        }                          \
    } while (0)
#define UNK_RELEASE_COUNTED(object)   \
    do {                              \
        if ((object) != nullptr) {    \
            (object)->Unk_Release();  \
            (object) = nullptr;       \
        }                             \
    } while (0)

// 0x710049afc0: a render texture's two values (lib/yebis/leaf)
struct Unk_49afc0;
u32 Unk_49afc0_update(Unk_49afc0* self, f32 fvalue, f32 farg1);

namespace PPFX {

// 0x7101eba12c: the class's name
extern const char Unk_1eba12c[];
const char Unk_1eba12c[] = "CRenderTextureArray";

// 0x71004a4660
CRenderTextureArray::CRenderTextureArray(const char* name) : CGPUResourceManage(nullptr) {
    Unk_4a46a0(name);
}

// 0x71004a46a0
s32 CRenderTextureArray::Unk_4a46a0(const char* name) {
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1eba12c) + " " + name;
    else
        field_10 = Unk_1eba12c;
    field_30 = 0;
    field_34 = 0;
    field_38 = nullptr;
    field_40 = nullptr;
    field_48 = 0;
    field_4c = 0;
    field_50 = nullptr;
    field_58 = nullptr;
    field_60 = nullptr;
    field_68 = nullptr;
    field_70 = nullptr;
    field_78 = nullptr;
    field_80 = nullptr;
    field_88 = nullptr;
    field_90 = 0;
    field_94 = 0;
    return 0;
}

// 0x71004a4760, 0x71004a47a0
CRenderTextureArray::~CRenderTextureArray() {
    Unk_49ec80();
}

// 0x71004a52a0
s32 CRenderTextureArray::vf1() {
    for (s32 i = 0; i < field_30; i++) {
        if (field_38[i] != nullptr)
            field_38[i]->vf1();
    }
    for (s32 i = 0; i < field_34; i++)
        field_40[i]->vf1();
    UNK_RELEASE(field_50);
    UNK_RELEASE(field_70);
    UNK_RELEASE(field_58);
    UNK_RELEASE(field_78);
    UNK_RELEASE_COUNTED(field_80);
    UNK_RELEASE(field_60);
    UNK_RELEASE_COUNTED(field_88);
    UNK_RELEASE(field_68);
    field_4c = 0;
    field_94 = 0;
    return CGPUResourceManage::vf1();
}

// 0x71004a5460
s32 CRenderTextureArray::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    if (field_30 == 0)
        return -1;
    return field_38 == nullptr ? -1 : 0;
}

// 0x71004a54b0
s32 CRenderTextureArray::vf3() {
    for (s32 i = 0; i < field_30; i++) {
        UNK_RELEASE_COUNTED(field_38[i]);
        if (field_40 != nullptr)
            UNK_RELEASE_COUNTED(field_40[i]);
    }
    UNK_DELETE_ARRAY(field_38);
    UNK_DELETE_ARRAY(field_40);
    field_90 = 0;
    field_94 = 0;
    field_30 = 0;
    field_34 = 0;
    field_48 = 0;
    field_4c = 0;
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x71004a5f50
s32 CRenderTextureArray::Unk_4a5f50(s32 index, f32 a, f32 b) {
    if (index == -1) {
        index = field_90;
    } else if (index == 0x7fffffff) {
        for (s32 i = 0; i < field_30; i++) {
            if (field_38[i] != nullptr)
                Unk_49afc0_update(reinterpret_cast<Unk_49afc0*>(field_38[i]), a, b);
        }
        return 0;
    }
    Unk_49afc0_update(reinterpret_cast<Unk_49afc0*>(field_38[index]), a, b);
    return 0;
}

// 0x71004a5ff0
s32 CRenderTextureArray::Unk_4a5ff0(s32 value, s32 index) {
    if (index == -1) {
        index = field_90;
    } else if (index == 0x7fffffff) {
        for (s32 i = 0; i < field_30; i++) {
            if (field_38[i] != nullptr)
                field_38[i]->Unk_SetA0(value);
        }
        return 0;
    }
    field_38[index]->Unk_SetA0(value);
    return 0;
}

}  // namespace PPFX

namespace PPFX {
struct Unk_4a5d10_Self;
}

// a render texture's viewport from the fractions of its size (at least one
// pixel; inline, as GPUPostEffect.h's)
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

// 0x71004a5d10: a texture's (-1: the current one's, 0x7fffffff: every
// texture's) viewport
s32 Unk_4a5d10(PPFX::Unk_4a5d10_Self* selfArg, s32 index, f32 width, f32 height, f32 x, f32 y) {
    PPFX::CRenderTextureArray* self = reinterpret_cast<PPFX::CRenderTextureArray*>(selfArg);
    if (index == -1) {
        index = self->field_90;
    } else if (index == 0x7fffffff) {
        for (s32 i = 0; i < self->field_30; i++) {
            if (self->field_38[i] != nullptr)
                Unk_SetViewport(self->field_38[i], width, height, x, y);
        }
        return 0;
    }
    Unk_SetViewport(self->field_38[index], width, height, x, y);
    return 0;
}

// a level's target of one of a texture's sets cleared, with the array's depth
// target when it fits (inline)
static inline s32 Unk_ClearTarget(PPFX::CRenderTextureArray* self, PPFX::Unk_49b230_Object* target,
                                  PPFX::Unk_49b230_Object* const* depthTarget, const f32* color, f32 value,
                                  s32 stencil) {
    s32 result = self->field_20->vf7(0, target, 0);
    if (result < 0) {
        return result;
    }
    PPFX::Unk_49b230_Object* depth = *depthTarget;
    if (depth != nullptr) {
        if (depth->field_4c < target->field_4c || depth->field_50 < target->field_50 ||
            depth->field_54 != target->field_54 || depth->field_58 != target->field_58) {
            depth = nullptr;
        }
    }
    result = self->field_20->vf8(depth);
    if (result < 0) {
        return result;
    }
    u32 flags;
    if (depth != nullptr) {
        flags = self->field_4c == 0x14 || self->field_4c == 0x2d ? 0xff3 : 0xff1;
    } else {
        flags = 0xff0;
    }
    self->field_20->vf51(flags, color, value, stencil);
    return 0;
}

// 0x71004a6160: every texture's targets cleared (with `color`, `depth` and
// `stencil`)
// (the inner loop over the two sets is unrolled only after the outer loops
// are optimised, which decides the registers)
s32 Unk_4a6160(PPFX::Unk_4a5d10_Self* selfArg, void* color, s32 stencil, f32 depth) {
    PPFX::CRenderTextureArray* self = reinterpret_cast<PPFX::CRenderTextureArray*>(selfArg);
    if (self->field_20 == nullptr) {
        return -2;
    }
    s32 current = self->field_90;
    PPFX::Unk_PixelContainer* target;
    PPFX::IGPUInterface* depthTarget;
    self->field_20->vf10(0, &target);
    s32 status = self->field_20->vf11(&depthTarget);
    if (status == -0x100) {
        depthTarget = nullptr;
    }
    self->field_20->vf33(0);
    for (s32 i = 0; i < self->field_30; i++) {
        if (self->field_38[i] == nullptr) {
            continue;
        }
        for (u32 level = 0; level < self->field_38[i]->field_98; level++) {
            for (s32 set = 0; set < 2; set++) {
                if (set != 0 && self->field_38[i]->field_d0[1][level] == self->field_38[i]->field_d0[0][level])
                    break;
                s32 result = Unk_ClearTarget(self, self->field_38[i]->field_d0[set][level], &(&self->field_50)[set],
                                             static_cast<const f32*>(color), depth, stencil);
                if (result < 0) {
                    return result;
                }
                self->field_38[i]->Unk_49cfa0(0, level, 0x10000, 0x10000, 0, true, nullptr, 0, nullptr, 0, nullptr,
                                              1.0f, 1.0f);
            }
        }
    }
    for (s32 i = 0; i < self->field_34; i++) {
        PPFX::CRenderTexture* texture = self->field_40[i];
        self->field_20->vf7(0, texture->field_b8[texture->field_a0], 0);
        s32 result = self->field_20->vf8(nullptr);
        if (result < 0) {
            return result;
        }
        self->field_20->vf51(0xff0, static_cast<const f32*>(color), depth, stencil);
    }
    self->field_90 = current;
    self->field_20->vf7(0, target, 0);
    self->field_20->vf8(depthTarget);
    UNK_RELEASE(target);
    UNK_RELEASE(depthTarget);
    return status < 0 ? status : 0;
}

namespace PPFX {

// 0x71004a6070
s32 CRenderTextureArray::Unk_4a6070(s32 index, bool depth, s32 arg2, void* arg3, s32 arg4, s32 slot, s32 arg6,
                                    s32 arg7, f32 arg8) {
    if (index == -1)
        index = field_90;
    field_90 = index;
    if (field_20 == nullptr)
        return -2;
    Unk_49b230_Object* first;
    Unk_49b230_Object* second;
    if (depth) {
        first = (&field_50)[field_38[index]->field_a0];
        second = (&field_60)[field_94];
    } else {
        first = nullptr;
        second = nullptr;
    }
    CRenderTexture* texture = index < field_30 ? field_38[index] : nullptr;
    CRenderTexture* targets[8] = {slot == 0 ? texture : nullptr, slot == 1 ? texture : nullptr,
                                  slot == 2 ? texture : nullptr, slot == 3 ? texture : nullptr};
    s32 result = Unk_49da70(8, targets, first, second, arg2, arg3, arg4, arg6, arg7, arg8);
    return result < 0 ? result : 0;
}

// 0x71004a65a0
// NON_MATCHING: two spots: the search for the largest count that has a
// technique tests `n != 0` before it reads the table (the original reads
// first and tests both with one ccmp), and with no device the original
// passes a constant null to Unk_442c50_get from its own block.
s32 CRenderTextureArray::Unk_4a65a0(s32 target, s32 source, u32 count, s32 index, bool flag, f32 scale) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (flag)
        util->Unk_471410(count, 0, 4);
    Unk_440cb0_get(reinterpret_cast<u64>(field_20), 1);
    Unk_440d50_get(reinterpret_cast<u64>(field_20), 0);
    field_20->vf42(0);
    CRenderTexture* dst = Unk_Texture(target);
    CRenderTexture* src = Unk_Texture(source);
    Unk_GPUTexture* textures[16];
    Unk_Float4 weights[16];
    f32 total = static_cast<f32>(count);
    for (u32 i = 0; i < count; i++) {
        CRenderTexture* texture = Unk_Texture(source + i);
        while (texture->field_120 != nullptr)
            texture = texture->field_120;
        textures[i] = reinterpret_cast<Unk_GPUTexture*>(texture->field_a8);
        f32 weight = scale / total;
        weights[i] = Unk_Float4(weight, weight, weight, weight);
    }
    f32 srcWidth = static_cast<f32>(static_cast<u32>(src->field_54));
    f32 srcHeight = static_cast<f32>(static_cast<u32>(src->field_58));
    f32 x = src->field_88 * srcWidth + src->field_90;
    f32 y = src->field_8c * srcHeight + src->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(dst->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(dst->field_58));
    for (u32 i = 0; i < count; i++)
        textures[i]->vf17(1);
    Unk_4a6070(target, false, 0, nullptr, 0, 0, 0, 0, 1.0f);
    if (!Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        u32 n = count;
        while (util->field_30.field_48a8[static_cast<s32>(n - 1)][index] == 0 && n != 0)
            n--;
        if (n < count) {
            count = n;
            f32 factor = total / static_cast<f32>(count);
            for (u32 i = 0; i < count; i++) {
                weights[i].field_0[0].field_0 *= factor;
                weights[i].field_0[1].field_0 *= factor;
                weights[i].field_0[2].field_0 *= factor;
                weights[i].field_0[3].field_0 *= factor;
            }
        }
    }
    s32 result = util->Unk_4768b0(0.0f, 0.0f, width, height, 0.0f, 0.0f, x, y,
                                  count, textures, weights, index, 0x10000);
    for (u32 i = 0; i < count; i++)
        textures[i]->vf17(0);
    return result;
}

// what CopyToSurface calls of the device and the surface
struct Unk_4a6aa0_Device {
    virtual void vf0();
    virtual s32 vf1();  // one reference less
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual s32 vf7(u32 index, void* target, s32 arg3);  // sets a render target
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual s32 vf17(Unk_Viewport* viewport);  // the viewport
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual s32 vf38(bool enable);
};
struct Unk_4a6aa0_Surface {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual s32 vf8(Unk_Viewport* desc);  // its size
};

// 0x71004a6aa0
// NON_MATCHING: the rectangle's four values are loaded late and get other registers;
// the flag of the same size is tested with tbnz (cbnz in the original).
s32 CRenderTextureArray::CopyToSurface(Unk_49b230_Object* surface, Unk_GPUTexture* source, s32 index, f32 scale,
                                       const Unk_Float4* rect, f32 u1, bool arg4, f32 v1, s32 arg5) {
    IGPUDevice* device;
    s32 result = Unk_446620(source, &device);
    if (result < 0) {
#line 2650
        PPFX_ERROR("CRenderTextureArray::CopyToSurface(): pSrcTexture->GetDevice() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        return result;
    }
    reinterpret_cast<Unk_4a6aa0_Device*>(device)->vf1();
    Unk_Viewport desc;
    if (surface != nullptr) {
        reinterpret_cast<Unk_4a6aa0_Surface*>(surface)->vf8(&desc);
    } else {
        Unk_Viewport viewport;
        reinterpret_cast<Unk_4a6aa0_Device*>(device)->vf17(&viewport);
        desc.field_8 = viewport.field_8;
        desc.field_c = viewport.field_c;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->Unk_471410(1, arg5, -1);
    reinterpret_cast<Unk_4a6aa0_Device*>(device)->vf38(arg4);
    if (surface != nullptr) {
        reinterpret_cast<Unk_4a6aa0_Device*>(device)->vf7(0, surface, 0);
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
    }
    f32 width = static_cast<f32>(desc.field_8);
    f32 height = static_cast<f32>(desc.field_c);
    Unk_Float4 colors(scale, scale, scale, scale);
    Unk_Float4 values(0.0f, 0.0f, 0.0f, 1.0f);
    f32 rw = rect->field_0[0].field_0;
    f32 rh = rect->field_0[1].field_0;
    f32 rx = rect->field_0[2].field_0;
    f32 ry = rect->field_0[3].field_0;
    f32 w = rw * width;
    f32 h = rh * height;
    bool same = w == static_cast<f32>(source->field_4c) && h == static_cast<f32>(source->field_50);
    f32 x = rx * width;
    f32 y = ry * height;
    s32 filter = source->vf19();
    if (arg5 != 0 && !same)
        source->vf17(0);
    else
        source->vf17(1);
    result = util->DrawRectGPU_MadT1_Sn(x, y, w, h, 0.0f, 0.0f, u1, v1, 1, &values, &colors, source, index, 0x10000);
    source->vf17(filter);
    return result;
}

// 0x71004a6a50
s32 CRenderTextureArray::Unk_4a6a50(Unk_49b230_Object* surface, CRenderTexture* source, s32 index,
                                    const Unk_Float4* rect, bool arg4, s32 arg5, f32 scale) {
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    if (texture == nullptr)
        return 1;
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    return CopyToSurface(surface, texture, index, scale, rect, u1, arg4, v1, arg5);
}

}  // namespace PPFX
