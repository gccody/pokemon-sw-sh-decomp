// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK320SiGfxNXRootSignatureE
#include <types.h>

struct Unk_557d20 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_557d20, field_10, 0x10);

struct Unk_556ff0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_556ff0, field_18, 0x18);

struct Unk_557000 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_557000, field_18, 0x18);

struct Unk_557010 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_557010, field_20, 0x20);

struct Unk_5574e0 {
    u8 _0[0x38];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_5574e0, field_38, 0x38);

struct Unk_557b50 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_557b50, field_88, 0x88);

namespace SiSDK3 {
class SiGfxNXRootSignature {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    u32 vf11();
    u32 vf17();
    u32 vf20();
};
}  // namespace SiSDK3

// 0x7100556ff0
u64 SiSDK3::SiGfxNXRootSignature::vf5() {
    const Unk_556ff0* self = reinterpret_cast<const Unk_556ff0*>(this);
    return self->field_18;
}

// 0x7100557000
u64 SiSDK3::SiGfxNXRootSignature::vf6() {
    const Unk_557000* self = reinterpret_cast<const Unk_557000*>(this);
    return self->field_18;
}

// 0x7100557010
u32 SiSDK3::SiGfxNXRootSignature::vf7() {
    const Unk_557010* self = reinterpret_cast<const Unk_557010*>(this);
    return self->field_20;
}

// 0x71005574e0
u32 SiSDK3::SiGfxNXRootSignature::vf11() {
    const Unk_5574e0* self = reinterpret_cast<const Unk_5574e0*>(this);
    return self->field_38;
}

// 0x7100557b50
u32 SiSDK3::SiGfxNXRootSignature::vf17() {
    const Unk_557b50* self = reinterpret_cast<const Unk_557b50*>(this);
    return self->field_88;
}

// 0x7100557c50
u32 SiSDK3::SiGfxNXRootSignature::vf20() {
    return 0;
}

// 0x7100557d20
u32 SiSDK3::SiGfxNXRootSignature::vf4() {
    const Unk_557d20* self = reinterpret_cast<const Unk_557d20*>(this);
    return self->field_10;
}
