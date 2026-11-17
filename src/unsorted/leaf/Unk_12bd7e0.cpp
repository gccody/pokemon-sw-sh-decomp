// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12bd7e0 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_12bd7e0, field_600, 0x600);

void Unk_14e69a0(u64);

// 0x71012bd7e0
void Unk_12bd7e0_call(const Unk_12bd7e0* self) {
    Unk_14e69a0(self->field_600);
}

struct Unk_12bedf0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_12bedf0, field_70, 0x70);

void Unk_1505660(u64);

// 0x71012bedf0
void Unk_12bedf0_call(const Unk_12bedf0* self) {
    Unk_1505660(self->field_70);
}
