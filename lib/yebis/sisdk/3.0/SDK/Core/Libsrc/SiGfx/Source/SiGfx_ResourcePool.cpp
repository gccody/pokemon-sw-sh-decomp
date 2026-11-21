// Scope: common
// SiSDK3::SiGfxResourcePool: its construction and destruction and the
// reference counts its header defines.
#define UNK_SIGFX_RESOURCEPOOL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ResourcePool.h>

namespace SiSDK3 {

// 0x7100534000
SiGfxResourcePool::SiGfxResourcePool(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(0), field_48(pAllocator, true), field_170(false) {
    field_48.field_120 = true;
}

// 0x71005341b0 (D2), 0x71005343b0 (D0)
SiGfxResourcePool::~SiGfxResourcePool() {
    SiGfxResourcePool::vf6();
}

// 0x7100534430
void SiGfxResourcePool::vf6() {
    Unk_534460();
    field_48.Unk_4be7d0();
}

// 0x7100534460
void SiGfxResourcePool::Unk_534460() {
    Unk_596640 lock(field_18.Unk_Get(), true);
    field_170 = true;
    Unk_534460_Resource* resource = Unk_First();
    while (resource != nullptr) {
        Unk_534460_Resource* next = Unk_Next(resource);
        resource->vf3();
        resource = next;
    }
    field_170 = false;
}

#define UNK_FOR_EACH(Slot, Call)                                                                              \
    void SiGfxResourcePool::Slot() {                                                                          \
        Unk_596640 lock(field_18.Unk_Get(), true);                                                            \
        for (Unk_534460_Resource* resource = Unk_First(); resource != nullptr; resource = Unk_Next(resource)) { \
            resource->Call();                                                                                 \
        }                                                                                                     \
    }

// 0x7100534990 = _ZN6SiSDK317SiGfxResourcePool3vf7Ev
UNK_FOR_EACH(vf7, vf9)
// 0x7100534aa0 = _ZN6SiSDK317SiGfxResourcePool3vf8Ev
UNK_FOR_EACH(vf8, vf10)
// 0x7100534bb0 = _ZN6SiSDK317SiGfxResourcePool3vf9Ev
UNK_FOR_EACH(vf9, vf11)
// 0x7100534cc0 = _ZN6SiSDK317SiGfxResourcePool4vf10Ev
UNK_FOR_EACH(vf10, vf12)
// 0x7100534dd0 = _ZN6SiSDK317SiGfxResourcePool4vf11Ev
UNK_FOR_EACH(vf11, vf13)
// 0x7100534ee0 = _ZN6SiSDK317SiGfxResourcePool4vf12Ev
UNK_FOR_EACH(vf12, vf14)
#undef UNK_FOR_EACH

// 0x7100534ff0
void SiGfxResourcePool::vf13(Unk_534460_Resource* resource) {
    Unk_596640 lock(field_18.Unk_Get(), true);
    if (!field_170) {
        ResourceItem* item = field_48.Unk_Get(resource->vf7());
        item->field_20 = nullptr;
        field_48.Unk_4ff090(item);
    }
}

}  // namespace SiSDK3
