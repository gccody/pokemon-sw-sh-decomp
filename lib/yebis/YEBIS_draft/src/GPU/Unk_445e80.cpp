// Scope: common
// PPFX::IGPUInterface's functions: a YEBIS src/GPU translation unit
// (0x7100445dc0 to 0x7100445f10) between GPUInterfaceSurface.cpp and
// Unk_4460c0.cpp, whose name isn't in the executable.
#include <yebis/YEBIS_draft/include/PPFX/Unk_Primaries.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>

namespace PPFX {

// 0x7100445dc0
IGPUInterface::IGPUInterface() {
    field_8 = 1;
}

// 0x7100445de0, 0x7100445df0 (deleting)
IGPUInterface::~IGPUInterface() {}

// 0x7100445e00
s32 IGPUInterface::vf0() {
    return ++field_8;
}

// 0x7100445e20
s32 IGPUInterface::vf1() {
    s32 count = --field_8;
    if (count == 0) {
        PPFX_DELETE(this);
    }
    return count;
}

}  // namespace PPFX

// 0x7100445e80: _GLOBAL__sub_I_Unk_445e80.cpp
