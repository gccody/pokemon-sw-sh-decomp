// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_54edc0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_54edc0, field_10, 0x10);

struct Unk_54ea30 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54ea30, field_18, 0x18);

struct Unk_54ea40 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_54ea40, field_18, 0x18);

struct Unk_54ea50 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_54ea50, field_20, 0x20);

struct Unk_54ed00 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_54ed00, field_78, 0x78);

namespace SiSDK3 {
class SiGfxNXDescriptorSet {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    void vf17();
    u64 vf18();
    u32 vf19();
};
}  // namespace SiSDK3

// 0x710054ea30
u64 SiSDK3::SiGfxNXDescriptorSet::vf5() {
    const Unk_54ea30* self = reinterpret_cast<const Unk_54ea30*>(this);
    return self->field_18;
}

// 0x710054ea40
u64 SiSDK3::SiGfxNXDescriptorSet::vf6() {
    const Unk_54ea40* self = reinterpret_cast<const Unk_54ea40*>(this);
    return self->field_18;
}

// 0x710054ea50
u32 SiSDK3::SiGfxNXDescriptorSet::vf7() {
    const Unk_54ea50* self = reinterpret_cast<const Unk_54ea50*>(this);
    return self->field_20;
}

// 0x710054ecf0
void SiSDK3::SiGfxNXDescriptorSet::vf17() {
}

// 0x710054ed00
u64 SiSDK3::SiGfxNXDescriptorSet::vf18() {
    const Unk_54ed00* self = reinterpret_cast<const Unk_54ed00*>(this);
    return self->field_78;
}

// 0x710054ed10
u32 SiSDK3::SiGfxNXDescriptorSet::vf19() {
    return 0;
}

// 0x710054edc0
u32 SiSDK3::SiGfxNXDescriptorSet::vf4() {
    const Unk_54edc0* self = reinterpret_cast<const Unk_54edc0*>(this);
    return self->field_10;
}
