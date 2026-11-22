// Scope: common
// PPFX::IGPUSurface (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceSurface.cpp,
// the __FILE__ of its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceSurface.h>

namespace PPFX {

// 0x71004437f0, 0x71004438f0 (deleting)
IGPUSurface::~IGPUSurface() {
    PPFX_SAFE_RELEASE_INTERFACE(field_70);
    vf14();
    if (field_c0) {
        if (field_b8 != nullptr) {
            field_b8->vf3();
            field_b8 = nullptr;
        }
    }
    if (field_b0) {
        if (field_a8 != nullptr) {
            field_a8->vf3();
            field_a8 = nullptr;
        }
    }
}

// 0x7100443c70: hands the surface to a user, after the one that has it
// lets go
s32 IGPUSurface::vf12(s32 index, Unk_SurfaceUser* user) {
    s32 result = vf13(index);
    if (user != nullptr) {
        result = user->vf15(this, index);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100443cd0
s32 IGPUSurface::vf13(s32 index) {
    if (field_80 == nullptr) {
        return 0;
    }
    if (index == -1) {
        return -6;
    }
    Unk_SurfaceUser* user = field_80[index];
    if (user == nullptr) {
        return 0;
    }
    s32 result = user->vf16(this, index);
    return result < 0 ? result : 0;
}

}  // namespace PPFX

// 0x7100445620: a surface for a render target SiGfx made
PPFX::IGPUSurface* Unk_445620(void* device, void* deviceSurface, u32 width, u32 height, u32 format, u32 msaa, u32 quality) {
    using namespace PPFX;
    if (width == 0 || height == 0) {
        return nullptr;
    }
#line 5480
    IGPUSurface* surface = UNK_NEW(IGPUSurface)(static_cast<IGPUDevice*>(device));
    Unk_SiGfxRenderTarget* target = static_cast<Unk_SiGfxRenderTarget*>(deviceSurface);
    if (target != nullptr) {
        surface->field_a8 = *target->vf11();
    }
    surface->field_b0 = false;
    surface->field_b8 = target;
    surface->field_c0 = false;
    surface->field_44.field_0 = format;
    surface->field_44.field_4 = surface->field_c;
    surface->field_44.field_8 = width;
    surface->field_44.field_c = height;
    surface->field_44.field_10 = msaa;
    surface->field_44.field_14 = quality;
    surface->Unk_445f80();
    return surface;
}

// 0x7100445b50: _GLOBAL__sub_I_GPUInterfaceSurface.cpp
