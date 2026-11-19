// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_596380 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_596380, field_10, 0x10);

struct Unk_596270 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_596270, field_18, 0x18);

struct Unk_5962c0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5962c0, field_28, 0x28);

struct Unk_5962d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5962d0, field_18, 0x18);

namespace SiSDK3 {
class SiOSSharedMemory {
public:
    u32 vf4();
    const u8* vf9();
    u64 vf12();
    u64 vf13();
    u32 vf14();
};
}  // namespace SiSDK3

// 0x71005961b0
u32 SiSDK3::SiOSSharedMemory::vf14() {
    return 1;
}

// 0x7100596270
const u8* SiSDK3::SiOSSharedMemory::vf9() {
    const Unk_596270* self = reinterpret_cast<const Unk_596270*>(this);
    return &self->field_18;
}

// 0x71005962c0
u64 SiSDK3::SiOSSharedMemory::vf12() {
    const Unk_5962c0* self = reinterpret_cast<const Unk_5962c0*>(this);
    return self->field_28;
}

// 0x71005962d0
u64 SiSDK3::SiOSSharedMemory::vf13() {
    const Unk_5962d0* self = reinterpret_cast<const Unk_5962d0*>(this);
    return self->field_18;
}

// 0x7100596380
u32 SiSDK3::SiOSSharedMemory::vf4() {
    const Unk_596380* self = reinterpret_cast<const Unk_596380*>(this);
    return self->field_10;
}
