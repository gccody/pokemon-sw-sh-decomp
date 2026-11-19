// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex16NexCommunityInfoE
#include <types.h>

struct Unk_16d8c50 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d8c50, field_8, 0x8);

struct Unk_16d8c70 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_16d8c70, field_c, 0xc);

struct Unk_16d8c90 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_16d8c90, field_d, 0xd);

struct Unk_16d8cb0 {
    u8 _0[0x668];
    u8 field_668;
};
PKMN_OFFSET_ASSERT(Unk_16d8cb0, field_668, 0x668);

struct Unk_16d8d00 {
    u8 _0[0x678];
    u8 field_678;
};
PKMN_OFFSET_ASSERT(Unk_16d8d00, field_678, 0x678);

struct Unk_16d8d50 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_16d8d50, field_28, 0x28);

struct Unk_16d8e00 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_16d8e00, field_30, 0x30);

struct Unk_16d8e20 {
    u8 _0[0x2c];
    u16 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_16d8e20, field_2c, 0x2c);

struct Unk_16d8e40 {
    u8 _0[0x38];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_16d8e40, field_38, 0x38);

struct Unk_16d8e60 {
    u8 _0[0x3a];
    u16 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_16d8e60, field_3a, 0x3a);

struct Unk_16d8e80 {
    u8 _0[0x40];
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_16d8e80, field_40, 0x40);

namespace nn {
namespace pia {
namespace nex {
class NexCommunityInfo {
public:
    u32 vf2();
    u8 vf3();
    u8 vf4();
    const u8* vf5();
    const u8* vf6();
    u32 vf7();
    u64 vf9();
    u16 vf10();
    u16 vf11();
    u16 vf12();
    const u8* vf13();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d8c50
u32 nn::pia::nex::NexCommunityInfo::vf2() {
    const Unk_16d8c50* self = reinterpret_cast<const Unk_16d8c50*>(this);
    return self->field_8;
}

// 0x71016d8c70
u8 nn::pia::nex::NexCommunityInfo::vf3() {
    const Unk_16d8c70* self = reinterpret_cast<const Unk_16d8c70*>(this);
    return self->field_c;
}

// 0x71016d8c90
u8 nn::pia::nex::NexCommunityInfo::vf4() {
    const Unk_16d8c90* self = reinterpret_cast<const Unk_16d8c90*>(this);
    return self->field_d;
}

// 0x71016d8cb0
const u8* nn::pia::nex::NexCommunityInfo::vf5() {
    const Unk_16d8cb0* self = reinterpret_cast<const Unk_16d8cb0*>(this);
    return &self->field_668;
}

// 0x71016d8d00
const u8* nn::pia::nex::NexCommunityInfo::vf6() {
    const Unk_16d8d00* self = reinterpret_cast<const Unk_16d8d00*>(this);
    return &self->field_678;
}

// 0x71016d8d50
u32 nn::pia::nex::NexCommunityInfo::vf7() {
    const Unk_16d8d50* self = reinterpret_cast<const Unk_16d8d50*>(this);
    return self->field_28;
}

// 0x71016d8e00
u64 nn::pia::nex::NexCommunityInfo::vf9() {
    const Unk_16d8e00* self = reinterpret_cast<const Unk_16d8e00*>(this);
    return self->field_30;
}

// 0x71016d8e20
u16 nn::pia::nex::NexCommunityInfo::vf10() {
    const Unk_16d8e20* self = reinterpret_cast<const Unk_16d8e20*>(this);
    return self->field_2c;
}

// 0x71016d8e40
u16 nn::pia::nex::NexCommunityInfo::vf11() {
    const Unk_16d8e40* self = reinterpret_cast<const Unk_16d8e40*>(this);
    return self->field_38;
}

// 0x71016d8e60
u16 nn::pia::nex::NexCommunityInfo::vf12() {
    const Unk_16d8e60* self = reinterpret_cast<const Unk_16d8e60*>(this);
    return self->field_3a;
}

// 0x71016d8e80
const u8* nn::pia::nex::NexCommunityInfo::vf13() {
    const Unk_16d8e80* self = reinterpret_cast<const Unk_16d8e80*>(this);
    return &self->field_40;
}
