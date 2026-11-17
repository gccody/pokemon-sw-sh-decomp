// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12ef5d0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef5d0, field_68, 0x68);

void Unk_15032c0(u64);

// 0x71012ef5d0
void Unk_12ef5d0_call(const Unk_12ef5d0* self) {
    Unk_15032c0(self->field_68);
}

struct Unk_12ef5e0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef5e0, field_68, 0x68);

void Unk_1505a30(u64);

// 0x71012ef5e0
void Unk_12ef5e0_call(const Unk_12ef5e0* self) {
    Unk_1505a30(self->field_68);
}

struct Unk_12ef5f0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_12ef5f0, field_68, 0x68);

void Unk_1505cf0(u64);

// 0x71012ef5f0
void Unk_12ef5f0_call(const Unk_12ef5f0* self) {
    Unk_1505cf0(self->field_68);
}
