// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK322SiGfxNXDescriptorTableE
#include <types.h>

struct Unk_550ff0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_550ff0, field_10, 0x10);

struct Unk_550210 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_550210, field_18, 0x18);

struct Unk_550220 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_550220, field_18, 0x18);

struct Unk_550230 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_550230, field_20, 0x20);

struct Unk_550650 {
    u8 _0[0xa0];
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_550650, field_a0, 0xa0);

struct Unk_5507d0 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_5507d0, field_48, 0x48);

struct Unk_550950 {
    u8 _0[0xf8];
    u32 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_550950, field_f8, 0xf8);

struct Unk_550ad0 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_550ad0, field_150, 0x150);

struct Unk_550f30 {
    u8 _0[0x190];
    u64 field_190;
};
PKMN_OFFSET_ASSERT(Unk_550f30, field_190, 0x190);

namespace SiSDK3 {
class SiGfxNXDescriptorTable {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u32 vf7();
    u32 vf11();
    u32 vf15();
    u32 vf19();
    u32 vf23();
    u64 vf31();
    u32 vf32();
};
}  // namespace SiSDK3

// 0x7100550210
u64 SiSDK3::SiGfxNXDescriptorTable::vf5() {
    const Unk_550210* self = reinterpret_cast<const Unk_550210*>(this);
    return self->field_18;
}

// 0x7100550220
u64 SiSDK3::SiGfxNXDescriptorTable::vf6() {
    const Unk_550220* self = reinterpret_cast<const Unk_550220*>(this);
    return self->field_18;
}

// 0x7100550230
u32 SiSDK3::SiGfxNXDescriptorTable::vf7() {
    const Unk_550230* self = reinterpret_cast<const Unk_550230*>(this);
    return self->field_20;
}

// 0x7100550650
u32 SiSDK3::SiGfxNXDescriptorTable::vf11() {
    const Unk_550650* self = reinterpret_cast<const Unk_550650*>(this);
    return self->field_a0;
}

// 0x71005507d0
u32 SiSDK3::SiGfxNXDescriptorTable::vf15() {
    const Unk_5507d0* self = reinterpret_cast<const Unk_5507d0*>(this);
    return self->field_48;
}

// 0x7100550950
u32 SiSDK3::SiGfxNXDescriptorTable::vf19() {
    const Unk_550950* self = reinterpret_cast<const Unk_550950*>(this);
    return self->field_f8;
}

// 0x7100550ad0
u32 SiSDK3::SiGfxNXDescriptorTable::vf23() {
    const Unk_550ad0* self = reinterpret_cast<const Unk_550ad0*>(this);
    return self->field_150;
}

// 0x7100550f30
u64 SiSDK3::SiGfxNXDescriptorTable::vf31() {
    const Unk_550f30* self = reinterpret_cast<const Unk_550f30*>(this);
    return self->field_190;
}

// 0x7100550f40
u32 SiSDK3::SiGfxNXDescriptorTable::vf32() {
    return 0;
}

// 0x7100550ff0
u32 SiSDK3::SiGfxNXDescriptorTable::vf4() {
    const Unk_550ff0* self = reinterpret_cast<const Unk_550ff0*>(this);
    return self->field_10;
}
