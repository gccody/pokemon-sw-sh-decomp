// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100934e50
void Unk_934e50_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100934e60
void Unk_934e60_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_934e70 {
    u8 _0[0x618];
    u32 field_618;
    u8 _61c[0x16c];
    u8 field_788;
};
PKMN_OFFSET_ASSERT(Unk_934e70, field_618, 0x618);
PKMN_OFFSET_ASSERT(Unk_934e70, field_788, 0x788);

void Unk_934e90(void*, u32);

// 0x7100934e70
void Unk_934e70_call(Unk_934e70* self, u32 value) {
    self->field_788 = 0;
    self->field_618 = value == 0xff ? 0 : value;
    Unk_934e90(self, value == 0xff ? 0 : value);
}

struct Unk_936440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_936440, field_0, 0x0);

void Unk_9356c0(u64);

// 0x7100936440
void Unk_936440_call(const Unk_936440* self) {
    Unk_9356c0(self->field_0);
}

// 0x7100936450
void Unk_936450_update() {}

struct Unk_936460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_936460_arg1, field_0, 0x0);

struct Unk_936460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_936460, field_0, 0x0);

// 0x7100936460
void Unk_936460_set(const Unk_936460* self, Unk_936460_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_936470_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_936470_arg1, field_0, 0x0);

struct Unk_936470 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_936470, field_0, 0x0);

// 0x7100936470
void Unk_936470_set(const Unk_936470* self, Unk_936470_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100936490
void Unk_936490_update() {}

struct Unk_9364a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9364a0_arg1, field_0, 0x0);

struct Unk_9364a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9364a0, field_0, 0x0);

// 0x71009364a0
void Unk_9364a0_set(const Unk_9364a0* self, Unk_9364a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9364b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9364b0_arg1, field_0, 0x0);

struct Unk_9364b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9364b0, field_0, 0x0);

// 0x71009364b0
void Unk_9364b0_set(const Unk_9364b0* self, Unk_9364b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100936640
void Unk_936640_update() {}

struct Unk_936650 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_936650, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_936650, field_8, 0x8);

// 0x7100936650
void Unk_936650_set(const Unk_936650* self, Unk_936650* value) {
    *value = *self;
}

struct Unk_936660 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_936660, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_936660, field_8, 0x8);

// 0x7100936660
void Unk_936660_set(const Unk_936660* self, Unk_936660* value) {
    *value = *self;
}
