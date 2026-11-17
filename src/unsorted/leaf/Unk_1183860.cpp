// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1183860 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1183860, field_68, 0x68);

// 0x7101183860
bool Unk_1183860_check(const Unk_1183860* self) {
    return self->field_68 != 0;
}

struct Unk_1185b20 {
    u8 _0[0x60];
    bool field_60;
};
PKMN_OFFSET_ASSERT(Unk_1185b20, field_60, 0x60);

// 0x7101185b20
void Unk_1185b20_set(Unk_1185b20* self, bool value) {
    self->field_60 = value;
}

struct Unk_1186150_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1186150_arg1, field_0, 0x0);

struct Unk_1186150 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1186150, field_60, 0x60);

// 0x7101186150
void Unk_1186150_set(Unk_1186150* self, const Unk_1186150_arg1* value) {
    self->field_60 = value->field_0;
}
