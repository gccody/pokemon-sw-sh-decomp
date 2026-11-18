// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1248230 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1248230, field_a0, 0xa0);

void Unk_14b9450(u64);

// 0x7101248230
void Unk_1248230_call(const Unk_1248230* self) {
    Unk_14b9450(self->field_a0);
}

// 0x7101248240
void Unk_1248240() {}

struct Unk_1248250 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1248250, field_a0, 0xa0);

void Unk_14b9510(u64);

// 0x7101248250
void Unk_1248250_call(const Unk_1248250* self) {
    Unk_14b9510(self->field_a0);
}

struct Unk_1248260 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1248260, field_a0, 0xa0);

void Unk_14b95d0(u64);

// 0x7101248260
void Unk_1248260_call(const Unk_1248260* self) {
    Unk_14b95d0(self->field_a0);
}

// 0x7101249170
void Unk_1249170_update() {}

struct Unk_1249180_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1249180_arg1, field_0, 0x0);

struct Unk_1249180 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1249180, field_0, 0x0);

// 0x7101249180
void Unk_1249180_set(const Unk_1249180* self, Unk_1249180_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1249190_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1249190_arg1, field_0, 0x0);

struct Unk_1249190 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1249190, field_0, 0x0);

// 0x7101249190
void Unk_1249190_set(const Unk_1249190* self, Unk_1249190_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12491a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12491a0, field_0, 0x0);

void Unk_1248cf0(u64);

// 0x71012491a0
void Unk_12491a0_call(const Unk_12491a0* self) {
    Unk_1248cf0(self->field_0);
}

// 0x71012491b0
void Unk_12491b0_update() {}

struct Unk_12491c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12491c0_arg1, field_0, 0x0);

struct Unk_12491c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12491c0, field_0, 0x0);

// 0x71012491c0
void Unk_12491c0_set(const Unk_12491c0* self, Unk_12491c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_12491d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12491d0_arg1, field_0, 0x0);

struct Unk_12491d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_12491d0, field_0, 0x0);

// 0x71012491d0
void Unk_12491d0_set(const Unk_12491d0* self, Unk_12491d0_arg1* value) {
    value->field_0 = self->field_0;
}
