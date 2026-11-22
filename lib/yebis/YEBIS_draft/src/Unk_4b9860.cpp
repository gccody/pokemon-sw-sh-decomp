// Scope: common
// PPFX::IPfxInterface's functions: a YEBIS translation unit (0x71004b9750 to
// 0x71004b98f0) whose name isn't in the executable. Its two accessors
// (0x71004b9840, 0x71004b9850) are lib/yebis/leaf's.
#include <yebis/YEBIS_draft/src/GPU/Unk_StaticsBase.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>
#include <yebis/YEBIS_draft/src/Unk_4b9860.h>

namespace PPFX {

// 0x71004b9750
s32 IPfxInterface::vf0() {
    return ++field_8;
}

// 0x71004b9770
s32 IPfxInterface::vf1() {
    s32 count = --field_8;
    if (count == 0) {
        // (the allocator is read after the destructor has run)
        this->~IPfxInterface();
        Unk_4b9a60(Unk_238d5f8, this);
    }
    return count;
}

// 0x71004b97d0
IPfxInterface::IPfxInterface() : field_8(1), field_10(nullptr) {}

// 0x71004b97f0, 0x71004b9810 (deleting)
// (The original stores the vtable pointer here, which clang only does for a
// destructor whose body isn't empty: it had a statement that compiles to
// nothing, an assert or a log line the build leaves out.)
IPfxInterface::~IPfxInterface() {
    ;
}

// 0x71004b9820
s32 IPfxInterface::vf2() {
    return field_8;
}

// 0x71004b9830
s32 IPfxInterface::vf5() {
    return field_10 != nullptr;
}

}  // namespace PPFX

// 0x71004b9860: _GLOBAL__sub_I_Unk_4b9860.cpp
