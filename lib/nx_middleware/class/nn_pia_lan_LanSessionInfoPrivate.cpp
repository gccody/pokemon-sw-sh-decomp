// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1678260 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1678260, field_10, 0x10);

struct Unk_1678270 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1678270, field_14, 0x14);

struct Unk_1678280 {
    u8 _0[0x18];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1678280, field_18, 0x18);

struct Unk_1678290 {
    u8 _0[0x1a];
    u16 field_1a;
};
PKMN_OFFSET_ASSERT(Unk_1678290, field_1a, 0x1a);

struct Unk_16782a0 {
    u8 _0[0x1c];
    u16 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_16782a0, field_1c, 0x1c);

struct Unk_16782b0 {
    u8 _0[0x1e];
    u8 field_1e;
};
PKMN_OFFSET_ASSERT(Unk_16782b0, field_1e, 0x1e);

struct Unk_16786e0 {
    u8 _0[0x1dc];
    u32 field_1dc;
};
PKMN_OFFSET_ASSERT(Unk_16786e0, field_1dc, 0x1dc);

namespace nn {
namespace pia {
namespace lan {
class LanSessionInfoPrivate {
public:
    u32 vf2();
    u32 vf3();
    u16 vf4();
    u16 vf5();
    u16 vf6();
    u8 vf7();
    u32 vf9();
    void vf11();
    u32 vf12();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101678260
u32 nn::pia::lan::LanSessionInfoPrivate::vf2() {
    const Unk_1678260* self = reinterpret_cast<const Unk_1678260*>(this);
    return self->field_10;
}

// 0x7101678270
u32 nn::pia::lan::LanSessionInfoPrivate::vf3() {
    const Unk_1678270* self = reinterpret_cast<const Unk_1678270*>(this);
    return self->field_14;
}

// 0x7101678280
u16 nn::pia::lan::LanSessionInfoPrivate::vf4() {
    const Unk_1678280* self = reinterpret_cast<const Unk_1678280*>(this);
    return self->field_18;
}

// 0x7101678290
u16 nn::pia::lan::LanSessionInfoPrivate::vf5() {
    const Unk_1678290* self = reinterpret_cast<const Unk_1678290*>(this);
    return self->field_1a;
}

// 0x71016782a0
u16 nn::pia::lan::LanSessionInfoPrivate::vf6() {
    const Unk_16782a0* self = reinterpret_cast<const Unk_16782a0*>(this);
    return self->field_1c;
}

// 0x71016782b0
u8 nn::pia::lan::LanSessionInfoPrivate::vf7() {
    const Unk_16782b0* self = reinterpret_cast<const Unk_16782b0*>(this);
    return self->field_1e;
}

// 0x71016786e0
u32 nn::pia::lan::LanSessionInfoPrivate::vf9() {
    const Unk_16786e0* self = reinterpret_cast<const Unk_16786e0*>(this);
    return self->field_1dc;
}

// 0x7101678700
u32 nn::pia::lan::LanSessionInfoPrivate::vf12() {
    return 0;
}

// 0x7101679c00
void nn::pia::lan::LanSessionInfoPrivate::vf11() {
}
