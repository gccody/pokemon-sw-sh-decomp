// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_8ea2b0(void*, u64, u32, u32, u32);

// 0x71008ea3a0
void Unk_8ea3a0_call(void* self, u64 value, bool arg2, bool arg3) {
    Unk_8ea2b0(self, value, arg2, 1, arg3);
}

struct Unk_8eace0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eace0, field_20, 0x20);

void Unk_8ef110(u64, u32, u32);

// 0x71008eace0
void Unk_8eace0_call(const Unk_8eace0* self) {
    Unk_8ef110(self->field_20, 1, 1);
}

struct Unk_8eacf0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eacf0, field_20, 0x20);

void Unk_8ef160(u64, u32, u32);

// 0x71008eacf0
void Unk_8eacf0_call(const Unk_8eacf0* self, u32 value, u32 arg2) {
    Unk_8ef160(self->field_20, value & 0xff, arg2 & 0xff);
}

struct Unk_8ead00 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8ead00, field_20, 0x20);

void Unk_8ef110(u64, u32, u32);

// 0x71008ead00
void Unk_8ead00_call(const Unk_8ead00* self) {
    Unk_8ef110(self->field_20, 1, 0);
}

struct Unk_8eb1e0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eb1e0, field_20, 0x20);

void Unk_8f4820(u64);

// 0x71008eb1e0
void Unk_8eb1e0_call(const Unk_8eb1e0* self) {
    Unk_8f4820(self->field_20);
}
