// Scope: common
// PPFX::IGPUPixelContainer's functions: a YEBIS src/GPU translation unit
// (0x7100445f10 to 0x7100446328), between GPUInterfaceSurface.cpp and
// GPUInterfaceResource.cpp: its name isn't in the executable.
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceResource.h>

namespace PPFX {

// 0x7100445f10
IGPUPixelContainer::IGPUPixelContainer(IGPUDevice* pDevice) : IGPUResource(pDevice) {
    field_68 = 0;
    field_44.field_0 = 0;
    field_44.field_4 = -1;
    field_44.field_8 = 0;
    field_44.field_c = 0;
    field_44.field_10 = 0;
    field_44.field_14 = 0;
    field_5c = 0;
    field_c = 1;
}

// 0x7100445f60, and 0x7100445f70: the deleting destructor of an abstract
// class is a trap
IGPUPixelContainer::~IGPUPixelContainer() {}

// 0x7100445f80
void IGPUPixelContainer::Unk_445f80() {
    field_5c = field_18->vf73(field_c, field_44.field_0);
}

// 0x7100445fd0
// (the format test is written first: the original's -6 is then set before
// the size test, which shares it with the last return, although the sizes
// are still tested first)
s32 IGPUPixelContainer::vf7(void* a1, u32 a2, u32 a3, bool a4) {
    if (a1 == nullptr) {
        return -6;
    }
    if (field_44.field_10 != 0) {
        return -4;
    }
    if (field_44.field_14 != 0) {
        return -4;
    }
    if (field_10 == 1 && (a2 != 0 || a3 != 0)) {
        return -6;
    }
    if (field_44.field_4 == 3 && a3 != 0) {
        return -6;
    }
    return 0;
}

// 0x7100446030
s32 IGPUPixelContainer::vf8(Unk_Desc* pDesc) {
    if (pDesc == nullptr) {
        return -6;
    }
    *pDesc = field_44;
    return 0;
}

// 0x7100446060
s32 IGPUPixelContainer::vf5(void* a1, bool a2) {
    if (a2) {
        s32 result = vf6();
        if (result < 0) {
            return result;
        }
    }
    field_21 = true;
    return 0;
}

// 0x71004460a0
s32 IGPUPixelContainer::vf6() {
    if (field_18 == nullptr) {
        return -1;
    }
    return -4;
}

}  // namespace PPFX

// 0x71004460c0: _GLOBAL__sub_I_Unk_4460c0.cpp
