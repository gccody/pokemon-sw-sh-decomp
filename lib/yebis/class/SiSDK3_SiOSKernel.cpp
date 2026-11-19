// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_596040 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_596040, field_10, 0x10);

struct Unk_595e00 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_595e00, field_18, 0x18);

struct Unk_595e10 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_595e10, field_28, 0x28);

struct Unk_595ee0 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_595ee0, field_38, 0x38);

namespace SiSDK3 {
class SiOSKernel {
public:
    u32 vf4();
    u64 vf6();
    u64 vf7();
    u64 vf10();
};
}  // namespace SiSDK3

// 0x7100595e00
u64 SiSDK3::SiOSKernel::vf6() {
    const Unk_595e00* self = reinterpret_cast<const Unk_595e00*>(this);
    return self->field_18;
}

// 0x7100595e10
u64 SiSDK3::SiOSKernel::vf7() {
    const Unk_595e10* self = reinterpret_cast<const Unk_595e10*>(this);
    return self->field_28;
}

// 0x7100595ee0
u64 SiSDK3::SiOSKernel::vf10() {
    const Unk_595ee0* self = reinterpret_cast<const Unk_595ee0*>(this);
    return self->field_38;
}

// 0x7100596040
u32 SiSDK3::SiOSKernel::vf4() {
    const Unk_596040* self = reinterpret_cast<const Unk_596040*>(this);
    return self->field_10;
}
