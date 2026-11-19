// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK310SiIOKernelE
#include <types.h>

struct Unk_57dd30 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_57dd30, field_10, 0x10);

struct Unk_57d5e0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_57d5e0, field_18, 0x18);

struct Unk_57d5f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_57d5f0, field_28, 0x28);

struct Unk_57d850 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_57d850, field_38, 0x38);

struct Unk_57d860 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_57d860, field_38, 0x38);

struct Unk_57d950 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_57d950, field_48, 0x48);

namespace SiSDK3 {
class SiIOKernel {
public:
    u32 vf4();
    u64 vf6();
    u64 vf7();
    u32 vf13(u64 value);
    u64 vf14();
    u64 vf17(u32 value);
};
}  // namespace SiSDK3

// 0x710057d5e0
u64 SiSDK3::SiIOKernel::vf6() {
    const Unk_57d5e0* self = reinterpret_cast<const Unk_57d5e0*>(this);
    return self->field_18;
}

// 0x710057d5f0
u64 SiSDK3::SiIOKernel::vf7() {
    const Unk_57d5f0* self = reinterpret_cast<const Unk_57d5f0*>(this);
    return self->field_28;
}

// 0x710057d850
u32 SiSDK3::SiIOKernel::vf13(u64 value) {
    Unk_57d850* self = reinterpret_cast<Unk_57d850*>(this);
    self->field_38 = value;
    return 1;
}

// 0x710057d860
u64 SiSDK3::SiIOKernel::vf14() {
    const Unk_57d860* self = reinterpret_cast<const Unk_57d860*>(this);
    return self->field_38;
}

// 0x710057d950
u64 SiSDK3::SiIOKernel::vf17(u32 value) {
    const Unk_57d950* self = reinterpret_cast<const Unk_57d950*>(this);
    if (value != 1) {
        return 0;
    }
    return self->field_48;
}

// 0x710057dd30
u32 SiSDK3::SiIOKernel::vf4() {
    const Unk_57dd30* self = reinterpret_cast<const Unk_57dd30*>(this);
    return self->field_10;
}
