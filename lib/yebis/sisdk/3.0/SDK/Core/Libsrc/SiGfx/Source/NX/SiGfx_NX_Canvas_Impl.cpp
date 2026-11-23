// Scope: common
// SiSDK3::SiGfxNXCanvas: its constructor and destructor, its name, its
// buffers and render targets, the accessors of its buffers and of its
// window's textures, the function that makes its own window, and the
// reference counts its header defines, and its slot 26, the resize (its other
// small accessors are lib/yebis/class's).
#define UNK_SIGFX_NX_CANVAS_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Canvas_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <nx_middleware/gfx/nvn.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RenderPassState_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RenderTarget_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Surface_Impl.h>

// 0x71004ceab0: destroys the resources that wait for it (placeholder name and
// type; SiGfx's kernel's translation unit defines it)
void Unk_4ceab0(void* self);
// 0x7100555b40 (leafgen's name and type): the render target's index in its pool
struct Unk_555b40;
bool Unk_555b40_update(Unk_555b40* self, u64 value);
// 0x710055cd30 (leafgen's name and type): a surface of a window's texture
struct Unk_55cd30;
void Unk_55cd30_call(Unk_55cd30* self, u64 canvas, u32 index, u64 texture, u64 view);
namespace SiSDK3 {
// 0x710055cfd0: a surface for a canvas's depth buffer (placeholder name and
// type)
bool Unk_55cfd0(SiGfxNXSurface* surface, SiGfxNXCanvas* canvas);
}  // namespace SiSDK3
// 0x71004ed190: whether a depth format has stencil
bool Unk_4ed190(u32 format);
// 0x7100562ee0: an NVN format of a SiGfx format
u32 Unk_562ee0(u32 value);
// 0x7100555160 (leafgen's name and type): the render pass state's kind
struct Unk_555160;
bool Unk_555160_update(Unk_555160* self, u32 value);

namespace SiSDK3 {

// The device's slot 19 as the canvas uses it (placeholder): slot 16 is the
// NVN queue.
class Unk_NXCanvasQueues {
public:
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
    virtual void* vf16();
};

// 0x71004fb6d0
SiGfxNXCanvas::SiGfxNXCanvas(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(0), field_38(pAllocator), field_68(0),
      field_108(-1), field_10c(false), field_10d(true), field_110(1), field_114(0), field_118(1), field_11c(0),
      field_140(nullptr), field_148(0), field_170(0), field_198(nullptr), field_240(nullptr), field_398(false) {
    field_6c = 5;
    memset(&field_70, 0, sizeof(field_70));
    for (int i = 0; i < 4; i++) {
        field_120[i] = nullptr;
    }
    for (int i = 0; i < 4; i++) {
        field_150[i] = nullptr;
    }
    for (int i = 0; i < 4; i++) {
        field_178[i] = nullptr;
    }
}

// 0x71004fb850 (D2), 0x71004fbab0 (D0); 0x71004fbaa0 and 0x71004fbae0 are
// their thunks for the second base
SiGfxNXCanvas::~SiGfxNXCanvas() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf19();
}

// 0x71004fcaa0 (0x71004fcae0: its thunk)
bool SiGfxNXCanvas::vf51(const char* name) {
    Unk_4c4700(&field_38, const_cast<char*>(name));
    field_68 = Unk_4c3510(&field_38);
    return true;
}

// 0x71004fcb20 (0x71004fcb30: its thunk)
const SiString<char>* SiGfxNXCanvas::vf52() {
    return &field_38;
}

// 0x71004fcb40 (0x71004fcb50: its thunk)
u32 SiGfxNXCanvas::vf53() {
    return field_68;
}

// An NVN texture's and texture view's storage (placeholder names): zeroed
// when they're made.
struct Unk_NVNTextureStorage {
    u64 field_0[0x18];
};
struct Unk_NVNTextureViewStorage {
    u64 field_0[5];
};

// 0x71004fbb20
// NON_MATCHING: registers and spills: the original spills the window right
// after the window's allocation (sp+0x18) and keeps the textures' count in
// x20 throughout; this keeps the window in a register and spills the count,
// which shuffles four registers around the views' calls in the textures'
// loop (and moves the heap description's stores). The calls, their
// arguments and the cleanups are the original's.
bool SiGfxNXCanvas::Unk_4fbb20(u64 window, const Unk_4f96e0_Desc* desc) {
    field_30 = window;
    field_388 = window;
    field_c0 = *desc;
    void* device = Unk_NXDevice(field_20)->vf85();
    s32 count = static_cast<s32>(desc->field_1c) + 2;
#line 133
    field_198 = field_10.m_pAllocator->vf7(0x180, 0x10, __FILE__, __LINE__);
    if (field_198 == nullptr) {
        return false;
    }
    nvnTextureBuilderSetDefaults(field_288);
    nvnTextureBuilderSetDevice(field_288, device);
    nvnTextureBuilderSetFlags(field_288, 9);
    nvnTextureBuilderSetTarget(field_288, 1);
    nvnTextureBuilderSetFormat(field_288, Unk_562ee0(desc->field_20));
    nvnTextureBuilderSetSize2D(field_288, 1920, 1080);
    field_390 = nvnTextureBuilderGetStorageSize(field_288);
    nvnTextureBuilderSetSize2D(field_288, desc->field_c, desc->field_10);
    field_1a0.Unk_SetCount(count);
    field_1f0.Unk_SetCount(count);
    size_t alignment = nvnTextureBuilderGetStorageAlignment(field_288);
    size_t size = Unk_NXAlign(field_390, alignment);
    field_240 = vf5()->vf30(0, nullptr);
    Unk_NXMemoryHeapDesc heapDesc((size + alignment) * count);
    heapDesc.field_30 = 0xa1;
    if (!field_240->vf8(&heapDesc)) {
        return false;
    }
    for (s32 i = 0; i < count; i++) {
        if (!field_240->Unk_552fc0(static_cast<s32>(size), alignment, &field_248[i].field_0)) {
            return false;
        }
        field_248[i].field_8 = Unk_NXAlign(field_248[i].field_0, alignment);
#line 182
        field_1a0.m_pData[i] = reinterpret_cast<NVNtexture*>(UNK_SI_NEW(field_10.m_pAllocator, 0x10)
                                                                 Unk_NVNTextureStorage());
        nvnTextureBuilderSetStorage(field_288, field_240->vf16(), field_248[i].field_8);
        if (nvnTextureInitialize(field_1a0.m_pData[i], field_288) != 1) {
            for (s32 j = 0; j < i; j++) {
                nvnTextureFinalize(field_1a0.m_pData[j]);
                if (field_1a0.m_pData[j] != nullptr) {
                    if (field_10.m_pAllocator != nullptr) {
#line 190
                        SI_FREE(field_10.m_pAllocator, field_1a0.m_pData[j]);
                    }
                    field_1a0.m_pData[j] = nullptr;
                }
                if (field_1f0.m_pData[j] != nullptr) {
                    if (field_10.m_pAllocator != nullptr) {
#line 191
                        SI_FREE(field_10.m_pAllocator, field_1f0.m_pData[j]);
                    }
                    field_1f0.m_pData[j] = nullptr;
                }
            }
            field_1a0.Unk_FreeAll();
            field_1f0.Unk_FreeAll();
            return false;
        }
#line 200
        field_1f0.m_pData[i] = reinterpret_cast<NVNtextureView*>(UNK_SI_NEW(field_10.m_pAllocator, 0x10)
                                                                     Unk_NVNTextureViewStorage());
        nvnTextureViewSetDefaults(field_1f0.m_pData[i]);
        nvnTextureViewSetFormat(field_1f0.m_pData[i], nvnTextureGetFormat(field_1a0.m_pData[i]));
        nvnTextureViewSetLevels(field_1f0.m_pData[i], 0, nvnTextureGetLevels(field_1a0.m_pData[i]));
        nvnTextureViewSetTarget(field_1f0.m_pData[i], nvnTextureGetTarget(field_1a0.m_pData[i]));
    }
    nvnWindowBuilderSetDefaults(field_308);
    nvnWindowBuilderSetDevice(field_308, device);
    nvnWindowBuilderSetNativeWindow(field_308, window);
    nvnWindowBuilderSetTextures(field_308, count, reinterpret_cast<void* const*>(field_1a0.m_pData));
    nvnWindowBuilderSetPresentInterval(field_308, desc->field_3c);
    if (nvnWindowInitialize(field_198, field_308) != 1) {
        for (s32 j = 0; j < count; j++) {
            nvnTextureFinalize(field_1a0.m_pData[j]);
            if (field_1a0.m_pData[j] != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 221
                    SI_FREE(field_10.m_pAllocator, field_1a0.m_pData[j]);
                }
                field_1a0.m_pData[j] = nullptr;
            }
            if (field_1f0.m_pData[j] != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 222
                    SI_FREE(field_10.m_pAllocator, field_1f0.m_pData[j]);
                }
                field_1f0.m_pData[j] = nullptr;
            }
        }
        field_1a0.Unk_FreeAll();
        field_1f0.Unk_FreeAll();
        return false;
    }
    field_398 = true;
    Unk_4fc4d0();
    Unk_4fc790();
    field_170 = field_11c;
    for (s64 i = 0; i < field_170; i++) {
#line 1282
        SiGfxNXRenderPassState* state =
            UNK_SI_NEW(field_10.m_pAllocator, 0x10) SiGfxNXRenderPassState(field_10.m_pAllocator, field_20);
        Unk_555160_update(reinterpret_cast<Unk_555160*>(state), 1);
        state->vf8();
        *state->vf10() = reinterpret_cast<u64>(field_150[i]);
        state->vf9();
        field_178[i] = state;
    }
    if (nvnSyncInitialize(field_348, device) != 1) {
        return false;
    }
    nvnWindowAcquireTexture(field_198, field_348, &field_114);
    field_118 = (field_114 + 1) % count;
    nvnSyncWait(field_348, -1);
    return true;
}

// 0x71004fc790
bool SiGfxNXCanvas::Unk_4fc790() {
    field_148 = field_11c;
    for (s64 i = 0; i < field_148; i++) {
#line 1192
        SiGfxNXRenderTarget* target = UNK_SI_NEW(field_10.m_pAllocator, 0x10)
            SiGfxNXRenderTarget(field_10.m_pAllocator, field_20);
        Unk_555b40_update(reinterpret_cast<Unk_555b40*>(target), 0);
        target->vf18();
        target->vf19(0, reinterpret_cast<Unk_NXAttachment*>(this), i);
        if (field_140 != nullptr) {
            target->vf22(reinterpret_cast<Unk_NXAttachment*>(this), false);
        }
        target->vf25();
        field_150[i] = target;
    }
    return true;
}

// whether there's a depth buffer and whether it has stencil (inline:
// placeholder name)
inline void Unk_SetDepthInfo(SiGfxNXCanvas* self) {
    if (self->field_140 != nullptr) {
        self->field_70.field_4c = true;
        self->field_70.field_4d = Unk_4ed190(self->field_140->vf17()->field_4);
    } else {
        self->field_70.field_4c = false;
        self->field_70.field_4d = false;
    }
}

// NON_MATCHING: the colour buffers' loop keeps the buffers' array's address
// in a register of its own (one more saved register, `str x24, [x25, x26]`);
// the original adds the index's offset to `this` for the store (`add x8, x19,
// x25; str x24, [x8, #0x120]`). Everything else is the original's (the depth
// buffer's information is written out in the test of the depth buffer: the
// original doesn't test it again after the call). Tried: a 32-bit or
// unsigned index, the textures in locals, the store through a pointer,
// pointer arithmetic for the three arrays.
// Also tried: the slot as a reference or pointer taken before the calls,
// `*(field_120 + i)`, the textures in locals, the release loop with a
// reference, a pointer local, an s32/int index or the null store outside
// its test.
// 0x71004fc4d0
bool SiGfxNXCanvas::Unk_4fc4d0() {
    if (field_140 != nullptr) {
        field_140->vf3();
        field_140 = nullptr;
    }
    for (s64 i = 0; i < field_11c; i++) {
        if (field_120[i] != nullptr) {
            field_120[i]->vf3();
            field_120[i] = nullptr;
        }
    }
    s32 count = static_cast<s32>(field_c0.field_1c) + 2;
    field_11c = count;
    field_114 = 0;
    for (s64 i = 0; i < field_11c; i++) {
#line 1060
        SiGfxNXSurface* surface =
            UNK_SI_NEW(field_10.m_pAllocator, 0x10) SiGfxNXSurface(field_10.m_pAllocator, field_20);
        Unk_55cd30_call(reinterpret_cast<Unk_55cd30*>(surface), reinterpret_cast<u64>(this), i,
                        reinterpret_cast<u64>(field_1a0.m_pData[i]), reinterpret_cast<u64>(field_1f0.m_pData[i]));
        field_120[i] = reinterpret_cast<Unk_NXCanvasBuffer*>(surface);
    }
    field_70.field_28 = field_11c;
    field_70.field_2c = field_120[0]->vf17()->field_4;
    field_70.field_20 = field_c0.field_14;
    field_70.field_24 = field_c0.field_18;
    field_70.field_10 = field_c0.field_4;
    field_70.field_14 = field_c0.field_8;
    field_70.field_18 = field_120[0]->vf17()->field_14;
    field_70.field_1c = field_120[0]->vf17()->field_18;
    field_70.field_3c = field_120[0]->vf17()->field_1c;
    field_70.field_40 = field_120[0]->vf17()->field_20;
    field_70.field_44 = field_c0.field_38;
    if (field_140 != nullptr) {
        field_70.field_38 = field_140->vf17()->field_4;
        field_70.field_4c = true;
        field_70.field_4d = Unk_4ed190(field_140->vf17()->field_4);
    } else {
        field_70.field_38 = field_c0.field_24;
        field_70.field_4c = false;
        field_70.field_4d = false;
    }
    field_110 = field_c0.field_3c;
    if (field_c0.field_24 != 0 && field_c0.field_44) {
#line 1099
        SiGfxNXSurface* surface =
            UNK_SI_NEW(field_10.m_pAllocator, 0x10) SiGfxNXSurface(field_10.m_pAllocator, field_20);
        Unk_55cfd0(surface, this);
        field_140 = reinterpret_cast<Unk_NXCanvasBuffer*>(surface);
    }
    Unk_SetDepthInfo(this);
    return true;
}

// 0x71004fc8a0
bool SiGfxNXCanvas::Unk_4fc8a0(u64 window, const Unk_4f96e0_Desc* desc) {
    field_30 = reinterpret_cast<u64>(nvnWindowGetNativeWindow(reinterpret_cast<void*>(window)));
    field_388 = field_30;
    field_c0 = *desc;
#line 272
    field_198 = field_10.m_pAllocator->vf7(0x180, 0x10, __FILE__, __LINE__);
    if (field_198 == nullptr) {
        return false;
    }
    field_398 = true;
    Unk_4fc4d0();
    Unk_4fc790();
    field_170 = field_11c;
    for (s64 i = 0; i < field_170; i++) {
#line 1282
        SiGfxNXRenderPassState* state =
            UNK_SI_NEW(field_10.m_pAllocator, 0x10) SiGfxNXRenderPassState(field_10.m_pAllocator, field_20);
        Unk_555160_update(reinterpret_cast<Unk_555160*>(state), 1);
        state->vf8();
        *state->vf10() = reinterpret_cast<u64>(field_150[i]);
        state->vf9();
        field_178[i] = state;
    }
    void* device = Unk_NXDevice(field_20)->vf85();
    if (nvnSyncInitialize(field_348, device) != 1) {
        return false;
    }
    s32 count = desc->field_1c + 2;
    nvnWindowAcquireTexture(field_198, field_348, &field_114);
    field_118 = (field_114 + 1) % count;
    nvnSyncWait(field_348, -1);
    return true;
}

// 0x71004fcc20: lets go of its window, its textures and its buffers
void SiGfxNXCanvas::vf19() {
    if (field_398) {
        nvnSyncWait(field_348, -1);
        if (field_198 != nullptr) {
            nvnWindowFinalize(field_198);
            if (field_198 != nullptr) {
#line 467
                UNK_FREE(field_10.m_pAllocator, field_198);
            }
        }
        for (s64 i = 0; i < field_70.field_28; i++) {
            if (field_1a0.m_pData[i] != nullptr) {
                nvnTextureFinalize(field_1a0.m_pData[i]);
                if (field_1a0.m_pData[i] != nullptr) {
                    if (field_10.m_pAllocator != nullptr) {
#line 475
                        SI_FREE(field_10.m_pAllocator, field_1a0.m_pData[i]);
                    }
                    field_1a0.m_pData[i] = nullptr;
                }
                if (field_1f0.m_pData[i] != nullptr) {
                    if (field_10.m_pAllocator != nullptr) {
#line 476
                        SI_FREE(field_10.m_pAllocator, field_1f0.m_pData[i]);
                    }
                    field_1f0.m_pData[i] = nullptr;
                }
            }
            field_240->Unk_553010(field_248[i].field_0);
            field_248[i].field_0 = 0;
            field_248[i].field_8 = 0;
        }
        field_1a0.Unk_FreeAll();
        field_1f0.Unk_FreeAll();
        nvnSyncFinalize(field_348);
        field_398 = false;
    }
    if (field_240 != nullptr) {
        field_240->vf3();
        field_240 = nullptr;
    }
    for (s64 i = 0; i < field_170; i++) {
        if (field_178[i] != nullptr) {
            field_178[i]->vf3();
            field_178[i] = nullptr;
        }
    }
    field_170 = 0;
    for (s64 i = 0; i < field_148; i++) {
        if (field_150[i] != nullptr) {
            field_150[i]->vf3();
            field_150[i] = nullptr;
        }
    }
    field_148 = 0;
    if (field_140 != nullptr) {
        field_140->vf3();
        field_140 = nullptr;
    }
    for (s64 i = 0; i < field_11c; i++) {
        if (field_120[i] != nullptr) {
            field_120[i]->vf3();
            field_120[i] = nullptr;
        }
    }
    field_11c = 0;
}

// 0x71004fcf60
bool SiGfxNXCanvas::vf22() {
    void* queue = reinterpret_cast<Unk_NXCanvasQueues*>(field_20->vf19())->vf16();
    nvnQueuePresentTexture(queue, field_198, field_114);
    nvnWindowAcquireTexture(field_198, field_348, &field_114);
    field_118 = (field_114 + 1) % field_11c;
    nvnSyncWait(field_348, -1);
    Unk_4ceab0(Unk_4cbec0());
    return true;
}

// 0x71004fd030
Unk_NXCanvasBuffer* SiGfxNXCanvas::vf24(s32 index) {
    if (index < 0) {
        return nullptr;
    }
    if ((index > 3) | (index >= field_11c)) {
        return nullptr;
    }
    return field_120[index];
}

// NON_MATCHING: registers and spills: the original spills the width and
// height at once (`stp w1, w2, [sp, #0x18]`) and keeps the textures' count
// array's address (`&field_1a0.m_itemCount`) and the sync's address in stack
// slots, where this keeps them in callee-saved registers for a while, which
// moves a dozen spills and reloads (the heap description's zero stores pair
// as the original's since its constructor's shape was fixed). The calls, their arguments, the
// cleanups and the blocks are the original's. (The heap and its textures are
// in a block of their own: with the description's lifetime ending before the
// window's failure path, that path's cleanup keeps its own copy, as the
// original's does, instead of being merged with the textures' one.)
// 0x71004fd080: makes its window's textures again for another size
bool SiGfxNXCanvas::vf26(u32 width, u32 height) {
    if (!field_398) {
        return false;
    }
    if (field_70.field_18 == width && field_70.field_1c == height) {
        return false;
    }
    for (s64 i = 0; i < field_170; i++) {
        if (field_178[i] != nullptr) {
            field_178[i]->vf3();
            field_178[i] = nullptr;
        }
    }
    field_170 = 0;
    if (field_140 != nullptr) {
        field_140->vf3();
        field_140 = nullptr;
    }
    for (s64 i = 0; i < field_11c; i++) {
        if (field_120[i] != nullptr) {
            field_120[i]->vf3();
            field_120[i] = nullptr;
        }
    }
    field_11c = 0;
    for (s64 i = 0; i < field_148; i++) {
        if (field_150[i] != nullptr) {
            field_150[i]->vf3();
            field_150[i] = nullptr;
        }
    }
    field_148 = 0;
    void* device = Unk_NXDevice(field_20)->vf85();
    s32 count = field_70.field_28;
    nvnSyncWait(field_348, -1);
    if (field_198 != nullptr) {
        nvnWindowFinalize(field_198);
    }
    for (s64 i = 0; i < field_70.field_28; i++) {
        if (field_1a0.m_pData[i] != nullptr) {
            nvnTextureFinalize(field_1a0.m_pData[i]);
            if (field_1a0.m_pData[i] != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 634
                    SI_FREE(field_10.m_pAllocator, field_1a0.m_pData[i]);
                }
                field_1a0.m_pData[i] = nullptr;
            }
            if (field_1f0.m_pData[i] != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 635
                    SI_FREE(field_10.m_pAllocator, field_1f0.m_pData[i]);
                }
                field_1f0.m_pData[i] = nullptr;
            }
        }
        field_240->Unk_553010(field_248[i].field_0);
        field_248[i].field_0 = 0;
        field_248[i].field_8 = 0;
    }
    field_1a0.Unk_FreeAll();
    field_1f0.Unk_FreeAll();
    nvnSyncFinalize(field_348);
    if (field_240 != nullptr) {
        field_240->vf3();
        field_240 = nullptr;
    }
    nvnTextureBuilderSetDefaults(field_288);
    nvnTextureBuilderSetDevice(field_288, device);
    nvnTextureBuilderSetFlags(field_288, 9);
    nvnTextureBuilderSetTarget(field_288, 1);
    nvnTextureBuilderSetFormat(field_288, Unk_562ee0(field_c0.field_20));
    nvnTextureBuilderSetSize2D(field_288, width, height);
    field_390 = nvnTextureBuilderGetStorageSize(field_288);
    nvnTextureBuilderSetSize2D(field_288, width, height);
    field_1a0.Unk_SetCount(count);
    field_1f0.Unk_SetCount(count);
    size_t alignment = nvnTextureBuilderGetStorageAlignment(field_288);
    size_t size = Unk_NXAlign(field_390, alignment);
    field_240 = vf5()->vf30(0, nullptr);
    {
        Unk_NXMemoryHeapDesc heapDesc((size + alignment) * count);
        heapDesc.field_30 = 0xa1;
        if (!field_240->vf8(&heapDesc)) {
            return false;
        }
        for (s32 i = 0; i < count; i++) {
            if (!field_240->Unk_552fc0(static_cast<s32>(size), alignment, &field_248[i].field_0)) {
                return false;
            }
            field_248[i].field_8 = Unk_NXAlign(field_248[i].field_0, alignment);
#line 692
            field_1a0.m_pData[i] = reinterpret_cast<NVNtexture*>(UNK_SI_NEW(field_10.m_pAllocator, 0x10)
                                                                     Unk_NVNTextureStorage());
            nvnTextureBuilderSetStorage(field_288, field_240->vf16(), field_248[i].field_8);
            if (nvnTextureInitialize(field_1a0.m_pData[i], field_288) != 1) {
                for (s32 j = 0; j < i; j++) {
                    nvnTextureFinalize(field_1a0.m_pData[j]);
                    if (field_1a0.m_pData[j] != nullptr) {
                        if (field_10.m_pAllocator != nullptr) {
#line 700
                            SI_FREE(field_10.m_pAllocator, field_1a0.m_pData[j]);
                        }
                        field_1a0.m_pData[j] = nullptr;
                    }
                    if (field_1f0.m_pData[j] != nullptr) {
                        if (field_10.m_pAllocator != nullptr) {
#line 701
                            SI_FREE(field_10.m_pAllocator, field_1f0.m_pData[j]);
                        }
                        field_1f0.m_pData[j] = nullptr;
                    }
                }
                field_1a0.Unk_FreeAll();
                field_1f0.Unk_FreeAll();
                return false;
            }
#line 710
            field_1f0.m_pData[i] = reinterpret_cast<NVNtextureView*>(UNK_SI_NEW(field_10.m_pAllocator, 0x10)
                                                                         Unk_NVNTextureViewStorage());
            nvnTextureViewSetDefaults(field_1f0.m_pData[i]);
            nvnTextureViewSetFormat(field_1f0.m_pData[i], nvnTextureGetFormat(field_1a0.m_pData[i]));
            nvnTextureViewSetLevels(field_1f0.m_pData[i], 0, nvnTextureGetLevels(field_1a0.m_pData[i]));
            nvnTextureViewSetTarget(field_1f0.m_pData[i], nvnTextureGetTarget(field_1a0.m_pData[i]));
        }
    }
    nvnWindowBuilderSetDefaults(field_308);
    nvnWindowBuilderSetDevice(field_308, device);
    nvnWindowBuilderSetNativeWindow(field_308, field_388);
    nvnWindowBuilderSetTextures(field_308, count, reinterpret_cast<void* const*>(field_1a0.m_pData));
    nvnWindowBuilderSetPresentInterval(field_308, field_c0.field_3c);
    if (nvnWindowInitialize(field_198, field_308) != 1) {
        for (s32 j = 0; j < count; j++) {
            nvnTextureFinalize(field_1a0.m_pData[j]);
            if (field_1a0.m_pData[j] != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 731
                    SI_FREE(field_10.m_pAllocator, field_1a0.m_pData[j]);
                }
                field_1a0.m_pData[j] = nullptr;
            }
            if (field_1f0.m_pData[j] != nullptr) {
                if (field_10.m_pAllocator != nullptr) {
#line 732
                    SI_FREE(field_10.m_pAllocator, field_1f0.m_pData[j]);
                }
                field_1f0.m_pData[j] = nullptr;
            }
        }
        field_1a0.Unk_FreeAll();
        field_1f0.Unk_FreeAll();
        return false;
    }
    Unk_4fc4d0();
    Unk_4fc790();
    field_170 = field_11c;
    for (s64 i = 0; i < field_170; i++) {
#line 1282
        SiGfxNXRenderPassState* state =
            UNK_SI_NEW(field_10.m_pAllocator, 0x10) SiGfxNXRenderPassState(field_10.m_pAllocator, field_20);
        Unk_555160_update(reinterpret_cast<Unk_555160*>(state), 1);
        state->vf8();
        *state->vf10() = reinterpret_cast<u64>(field_150[i]);
        state->vf9();
        field_178[i] = state;
    }
    if (nvnSyncInitialize(field_348, device) != 1) {
        return false;
    }
    nvnWindowAcquireTexture(field_198, field_348, &field_114);
    field_118 = (field_114 + 1) % count;
    nvnSyncWait(field_348, -1);
    field_70.field_18 = width;
    field_70.field_1c = height;
    return true;
}

// 0x71004fdce0
void* SiGfxNXCanvas::vf32(s32 index) {
    return Unk_Get150(index);
}

// 0x71004fdd20
void* SiGfxNXCanvas::vf33(s32 index) {
    return Unk_Get150(index);
}

// 0x71004fdd60
void* SiGfxNXCanvas::vf34() {
    return Unk_Get150(field_114);
}

// 0x71004fdda0
void* SiGfxNXCanvas::vf35() {
    return Unk_Get150(field_114);
}

// 0x71004fdde0
void* SiGfxNXCanvas::vf36() {
    return Unk_Get150(field_118);
}

// 0x71004fde20
void* SiGfxNXCanvas::vf37() {
    return Unk_Get150(field_118);
}

// 0x71004fde60
void* SiGfxNXCanvas::vf38(s32 index) {
    return Unk_Get178(index);
}

// 0x71004fdea0
void* SiGfxNXCanvas::vf39(s32 index) {
    return Unk_Get178(index);
}

// 0x71004fdee0
void* SiGfxNXCanvas::vf40() {
    return Unk_Get178(field_114);
}

// 0x71004fdf20
void* SiGfxNXCanvas::vf41() {
    return Unk_Get178(field_114);
}

// 0x71004fdf60
void* SiGfxNXCanvas::vf42() {
    return Unk_Get178(field_118);
}

// 0x71004fdfa0
void* SiGfxNXCanvas::vf43() {
    return Unk_Get178(field_118);
}

// 0x71004fdfe0
u32 SiGfxNXCanvas::vf44(u64 a1, s32 index) {
    if (index < 0 || field_11c <= index) {
        return 0;
    }
    Unk_NXCanvasBuffer* pBuffer = field_120[index];
    if (pBuffer == nullptr) {
        return 0;
    }
    return pBuffer->vf24(a1);
}

// 0x71004fe130
void* SiGfxNXCanvas::vf49(s32 index) {
    if (index < 0 || field_1a0.m_itemCount < static_cast<size_t>(index)) {
        return nullptr;
    }
    return field_1a0.m_pData[index];
}

// 0x71004fe160
void* SiGfxNXCanvas::vf50(s32 index) {
    if (index < 0 || field_1f0.m_itemCount < static_cast<size_t>(index)) {
        return nullptr;
    }
    return field_1f0.m_pData[index];
}

}  // namespace SiSDK3
