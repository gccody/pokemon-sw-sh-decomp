// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

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
    u16 vf10();
    const u8* vf11();
    u32 vf17();
    u16 vf19();
    const u8* vf20();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

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
