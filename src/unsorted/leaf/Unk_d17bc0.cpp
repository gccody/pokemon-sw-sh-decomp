// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d17bc0 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_d17bc0, field_600, 0x600);

// 0x7100d17bc0
bool Unk_d17bc0_check(const Unk_d17bc0* self) {
    return self->field_600 != 0xcbf29ce484222645;
}

// 0x7100d185f0
void Unk_d185f0_update() {}

struct Unk_d18600_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18600_arg1, field_0, 0x0);

struct Unk_d18600 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18600, field_0, 0x0);

// 0x7100d18600
void Unk_d18600_set(const Unk_d18600* self, Unk_d18600_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d18610_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18610_arg1, field_0, 0x0);

struct Unk_d18610 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d18610, field_0, 0x0);

// 0x7100d18610
void Unk_d18610_set(const Unk_d18610* self, Unk_d18610_arg1* value) {
    value->field_0 = self->field_0;
}
