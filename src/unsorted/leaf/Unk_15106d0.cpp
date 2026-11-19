// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_15106d0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_15106d0, field_60, 0x60);

// 0x71015106d0
u64 Unk_15106d0_getField60(const Unk_15106d0* self) {
    return self->field_60;
}

struct Unk_15106e0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_15106e0, field_6c, 0x6c);

// 0x71015106e0
void Unk_15106e0_setField6c(Unk_15106e0* self, u32 value) {
    self->field_6c = value;
}

extern u64 Unk_24ba668;
u32 Unk_105c390(u64);

// 0x71015106f0
u32 Unk_15106f0_call() {
    u32 r0 = Unk_105c390(Unk_24ba668);
    return ~r0 & 1;
}

struct Unk_1510ec0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_1510ec0, field_700, 0x700);

// 0x7101510ec0
void Unk_1510ec0_setField700(Unk_1510ec0* self, u64 value) {
    self->field_700 = value;
}
