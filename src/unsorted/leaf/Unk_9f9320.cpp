// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9f9320 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9320, field_10, 0x10);

void Unk_140c020(u64, u32, u32);

// 0x71009f9320
void Unk_9f9320_call(const Unk_9f9320* self) {
    Unk_140c020(self->field_10, 0xffffffff, 1);
}

struct Unk_9f9330 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9330, field_10, 0x10);

void Unk_140c020(u64, u32, u32);

// 0x71009f9330
void Unk_9f9330_call(const Unk_9f9330* self) {
    Unk_140c020(self->field_10, 0xffffffff, 0);
}

struct Unk_9f9340 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9340, field_10, 0x10);

void Unk_140bff0(u64);

// 0x71009f9340
void Unk_9f9340_call(const Unk_9f9340* self) {
    Unk_140bff0(self->field_10);
}

struct Unk_9f9350 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9350, field_10, 0x10);

// 0x71009f9350
bool Unk_9f9350_check(const Unk_9f9350* self) {
    return self->field_10 == 0;
}
