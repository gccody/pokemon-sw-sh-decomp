// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1685930 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1685930, field_8, 0x8);

struct Unk_1685940 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1685940, field_8, 0x8);

struct Unk_1685950 {
    u8 _0[0x8b];
    u8 field_8b;
    u8 _8c[0x1b];
    u8 field_a7;
};
PKMN_OFFSET_ASSERT(Unk_1685950, field_8b, 0x8b);
PKMN_OFFSET_ASSERT(Unk_1685950, field_a7, 0xa7);

struct Unk_1685970 {
    u8 _0[0x2aa];
    u16 field_2aa;
};
PKMN_OFFSET_ASSERT(Unk_1685970, field_2aa, 0x2aa);

struct Unk_1685980 {
    u8 _0[0x2ac];
    u8 field_2ac;
};
PKMN_OFFSET_ASSERT(Unk_1685980, field_2ac, 0x2ac);

struct Unk_1685850 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1685850, field_8, 0x8);

struct Unk_1685860 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1685860, field_8, 0x8);

struct Unk_16859b0 {
    u8 _0[0x4c0];
    u32 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_16859b0, field_4c0, 0x4c0);

struct Unk_16859c0 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16859c0, field_8, 0x8);

struct Unk_16859d0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16859d0, field_10, 0x10);

namespace nn {
namespace pia {
namespace local {
class LdnConnectionStatus {
public:
    bool vf7();
    bool vf8();
    u8 vf9();
    u16 vf10();
    const u8* vf11();
    bool vf14();
    u32 vf15();
    u32 vf17();
    u16 vf19();
    const u8* vf20();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x7101685850
bool nn::pia::local::LdnConnectionStatus::vf14() {
    const Unk_1685850* self = reinterpret_cast<const Unk_1685850*>(this);
    return self->field_8 == 6;
}

// 0x7101685860
u32 nn::pia::local::LdnConnectionStatus::vf15() {
    const Unk_1685860* self = reinterpret_cast<const Unk_1685860*>(this);
    return (self->field_8 == 3) | (self->field_8 == 5);
}

// 0x7101685930
bool nn::pia::local::LdnConnectionStatus::vf7() {
    const Unk_1685930* self = reinterpret_cast<const Unk_1685930*>(this);
    return self->field_8 == 3;
}

// 0x7101685940
bool nn::pia::local::LdnConnectionStatus::vf8() {
    const Unk_1685940* self = reinterpret_cast<const Unk_1685940*>(this);
    return self->field_8 == 5;
}

// 0x7101685950
u8 nn::pia::local::LdnConnectionStatus::vf9() {
    const Unk_1685950* self = reinterpret_cast<const Unk_1685950*>(this);
    if (self->field_8b != 2) {
        return 0;
    }
    return self->field_a7;
}

// 0x7101685970
u16 nn::pia::local::LdnConnectionStatus::vf10() {
    const Unk_1685970* self = reinterpret_cast<const Unk_1685970*>(this);
    return self->field_2aa;
}

// 0x7101685980
const u8* nn::pia::local::LdnConnectionStatus::vf11() {
    const Unk_1685980* self = reinterpret_cast<const Unk_1685980*>(this);
    return &self->field_2ac;
}

// 0x71016859b0
u32 nn::pia::local::LdnConnectionStatus::vf17() {
    const Unk_16859b0* self = reinterpret_cast<const Unk_16859b0*>(this);
    return self->field_4c0;
}

// 0x71016859c0
u16 nn::pia::local::LdnConnectionStatus::vf19() {
    const Unk_16859c0* self = reinterpret_cast<const Unk_16859c0*>(this);
    return self->field_8;
}

// 0x71016859d0
const u8* nn::pia::local::LdnConnectionStatus::vf20() {
    const Unk_16859d0* self = reinterpret_cast<const Unk_16859d0*>(this);
    return &self->field_10;
}
