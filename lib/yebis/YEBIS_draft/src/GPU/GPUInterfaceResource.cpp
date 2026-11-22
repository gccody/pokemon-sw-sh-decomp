// Scope: common
// PPFX::IGPUResource (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceResource.cpp, the __FILE__ of its log lines).
#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceResource.h>

// 0x71024e1500: PPFX's settings; field_10 is the number of frame slots
struct Unk_24e1500_Settings {
    u8 _0[0x10];
    u32 field_10;
};
extern Unk_24e1500_Settings Unk_24e1500;

static inline u32 Unk_FrameSlots() {
    return Unk_24e1500.field_10 > 1 ? Unk_24e1500.field_10 : 1;
}

namespace PPFX {

// 0x7100446330: the device lists it
IGPUResource::IGPUResource(IGPUDevice* pDevice)
    : field_c(0), field_10(-1), field_18(pDevice), field_20(false), field_21(false), field_24(0), field_28(0),
      field_30(nullptr), field_38(nullptr), field_40(true) {
    IGPUResource* self = this;
    field_18->field_10.push_back(self);
#line 1577
    field_30 = UNK_NEW_ARRAY(bool, Unk_FrameSlots());
    for (u32 i = 0; i < Unk_FrameSlots(); i++) {
        field_30[i] = false;
    }
}

// 0x7100446440, 0x7100446530 (deleting)
// NON_MATCHING: 0x7100446440 only, in one branch: for an empty list the
// original goes straight to the end, this to the test after the search (the
// deleting destructor, which has this one inline, matches).
IGPUResource::~IGPUResource() {
    if (field_38 != nullptr) {
        field_38->vf3();
        field_38 = nullptr;
    }
    UNK_DELETE_ARRAY(field_30);
    Unk_List& list = field_18->field_10;
    IGPUResource* self = this;
    Unk_List::iterator it = std::find(list.begin(), list.end(), self);
    if (it != list.end()) {
        list.erase(it);
    }
}

}  // namespace PPFX

// 0x7100446620: a resource's device, with a reference for the caller
s32 Unk_446620(void* resource, PPFX::IGPUDevice** device) {
    if (device != nullptr) {
        *device = static_cast<PPFX::IGPUResource*>(resource)->field_18;
        if (*device == nullptr) {
            return -3;
        }
        (*device)->vf0();
    }
    return 0;
}

namespace PPFX {

// 0x7100446660
s32 IGPUResource::vf5(void* a1, bool a2) {
    return -4;
}

// 0x7100446670
s32 IGPUResource::vf6() {
    return -4;
}

// 0x7100446680
u32 IGPUResource::vf4() {
    u32 kind = field_c;
    u32 flags = 0;
    if (field_28 & 0x10000000) {
        flags |= 0x100;
    }
    if (field_24 & 1) {
        flags |= 0x10;
    }
    if (field_28 & 0x100) {
        flags |= 0x200;
    }
    if (field_24 & 2) {
        flags |= 0x20;
    }
    if (field_24 & 4) {
        flags |= 0x40;
    }
    if (kind == 3 || kind == 4) {
        flags |= 4;
    }
    return flags;
}

}  // namespace PPFX

// 0x7100446820: _GLOBAL__sub_I_GPUInterfaceResource.cpp
