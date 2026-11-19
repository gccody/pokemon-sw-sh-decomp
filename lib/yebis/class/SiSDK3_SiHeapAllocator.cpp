// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK315SiHeapAllocatorE
#include <types.h>

struct Unk_4c32d0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4c32d0, field_10, 0x10);

struct Unk_4c2e50 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4c2e50, field_18, 0x18);

struct Unk_4c2e60 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4c2e60, field_18, 0x18);

struct Unk_4c3220 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4c3220, field_20, 0x20);

namespace SiSDK3 {
class SiHeapAllocator {
public:
    u32 vf4();
    u32 vf5(u32 value);
    u32 vf6();
    u64 vf20();
};
}  // namespace SiSDK3

// 0x71004c2e50
u32 SiSDK3::SiHeapAllocator::vf5(u32 value) {
    Unk_4c2e50* self = reinterpret_cast<Unk_4c2e50*>(this);
    self->field_18 = value;
    return 1;
}

// 0x71004c2e60
u32 SiSDK3::SiHeapAllocator::vf6() {
    const Unk_4c2e60* self = reinterpret_cast<const Unk_4c2e60*>(this);
    return self->field_18;
}

// 0x71004c3220
u64 SiSDK3::SiHeapAllocator::vf20() {
    const Unk_4c3220* self = reinterpret_cast<const Unk_4c3220*>(this);
    return self->field_20;
}

// 0x71004c32d0
u32 SiSDK3::SiHeapAllocator::vf4() {
    const Unk_4c32d0* self = reinterpret_cast<const Unk_4c32d0*>(this);
    return self->field_10;
}
