// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e9ddb0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e9ddb0, field_78, 0x78);

// 0x7100e9ddb0
bool Unk_e9ddb0_check(const Unk_e9ddb0* self) {
    return self->field_78 != 0;
}

struct Unk_e9ddc0 {
    u8 _0[0x89];
    u8 field_89;
};
PKMN_OFFSET_ASSERT(Unk_e9ddc0, field_89, 0x89);

// 0x7100e9ddc0
u8 Unk_e9ddc0_getField89(const Unk_e9ddc0* self) {
    return self->field_89;
}

struct Unk_e9fab0_60 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_e9fab0_60, field_108, 0x108);

struct Unk_e9fab0 {
    u8 _0[0x60];
    Unk_e9fab0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e9fab0, field_60, 0x60);

// 0x7100e9fab0
bool Unk_e9fab0_check(const Unk_e9fab0* self) {
    return self->field_60->field_108 != 0;
}
