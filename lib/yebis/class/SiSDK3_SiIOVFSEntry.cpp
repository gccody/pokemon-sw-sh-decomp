// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK312SiIOVFSEntryE
#include <types.h>

struct Unk_587a50 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_587a50, field_10, 0x10);

struct Unk_587650 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_587650, field_18, 0x18);

struct Unk_587660 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_587660, field_18, 0x18);

struct Unk_587670 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_587670, field_20, 0x20);

struct Unk_587680 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_587680, field_20, 0x20);

struct Unk_587690 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_587690, field_28, 0x28);

struct Unk_5876a0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_5876a0, field_58, 0x58);

struct Unk_5876b0 {
    u8 _0[0x8c];
    u8 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_5876b0, field_8c, 0x8c);

struct Unk_5876c0 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_5876c0, field_d8, 0xd8);

struct Unk_5876f0 {
    u8 _0[0x128];
    u64 field_128;
};
PKMN_OFFSET_ASSERT(Unk_5876f0, field_128, 0x128);

struct Unk_587720 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_587720, field_98, 0x98);

namespace SiSDK3 {
class SiIOVFSEntry {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u64 vf7();
    u64 vf8();
    const u8* vf9();
    const u8* vf10();
    u8 vf11();
    u64 vf12();
    u64 vf15();
    u64 vf18();
};
}  // namespace SiSDK3

// 0x7100587650
u64 SiSDK3::SiIOVFSEntry::vf5() {
    const Unk_587650* self = reinterpret_cast<const Unk_587650*>(this);
    return self->field_18;
}

// 0x7100587660
u64 SiSDK3::SiIOVFSEntry::vf6() {
    const Unk_587660* self = reinterpret_cast<const Unk_587660*>(this);
    return self->field_18;
}

// 0x7100587670
u64 SiSDK3::SiIOVFSEntry::vf7() {
    const Unk_587670* self = reinterpret_cast<const Unk_587670*>(this);
    return self->field_20;
}

// 0x7100587680
u64 SiSDK3::SiIOVFSEntry::vf8() {
    const Unk_587680* self = reinterpret_cast<const Unk_587680*>(this);
    return self->field_20;
}

// 0x7100587690
const u8* SiSDK3::SiIOVFSEntry::vf9() {
    const Unk_587690* self = reinterpret_cast<const Unk_587690*>(this);
    return &self->field_28;
}

// 0x71005876a0
const u8* SiSDK3::SiIOVFSEntry::vf10() {
    const Unk_5876a0* self = reinterpret_cast<const Unk_5876a0*>(this);
    return &self->field_58;
}

// 0x71005876b0
u8 SiSDK3::SiIOVFSEntry::vf11() {
    const Unk_5876b0* self = reinterpret_cast<const Unk_5876b0*>(this);
    return self->field_8c;
}

// 0x71005876c0
u64 SiSDK3::SiIOVFSEntry::vf12() {
    const Unk_5876c0* self = reinterpret_cast<const Unk_5876c0*>(this);
    return self->field_d8;
}

// 0x71005876f0
u64 SiSDK3::SiIOVFSEntry::vf15() {
    const Unk_5876f0* self = reinterpret_cast<const Unk_5876f0*>(this);
    return self->field_128;
}

// 0x7100587720
u64 SiSDK3::SiIOVFSEntry::vf18() {
    const Unk_587720* self = reinterpret_cast<const Unk_587720*>(this);
    return self->field_98;
}

// 0x7100587a50
u32 SiSDK3::SiIOVFSEntry::vf4() {
    const Unk_587a50* self = reinterpret_cast<const Unk_587a50*>(this);
    return self->field_10;
}
