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

// 0x71012ef820
void Unk_12ef820_update() {}

struct Unk_12ef830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef830_arg1, field_0, 0x0);

struct Unk_12ef830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef830, field_0, 0x0);

// 0x71012ef830
void Unk_12ef830_set(const Unk_12ef830* self, Unk_12ef830_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12ef840_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef840_arg1, field_0, 0x0);

struct Unk_12ef840 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12ef840, field_0, 0x0);

// 0x71012ef840
void Unk_12ef840_set(const Unk_12ef840* self, Unk_12ef840_arg1* value) {
    value->field_0 = self->field_0;
}
