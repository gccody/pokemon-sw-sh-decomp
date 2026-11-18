// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x710091f4a0
void Unk_91f4a0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x710091f4b0
void Unk_91f4b0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_91f910 {
    u8 _0[0x5f0];
    u64 field_5f0;
    u8 _5f8[0x8];
    u32 field_600;
    u8 _604[0x4];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_91f910, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_91f910, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_91f910, field_608, 0x608);

// 0x710091f910
void Unk_91f910_set(Unk_91f910* self) {
    self->field_5f0 = 0;
    self->field_600 = 0;
    self->field_608 = 0;
}

struct Unk_91ff50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ff50, field_0, 0x0);

void Unk_91f920(u64);

// 0x710091ff50
void Unk_91ff50_call(const Unk_91ff50* self) {
    Unk_91f920(self->field_0);
}

// 0x710091ff60
void Unk_91ff60_update() {}

struct Unk_91ff70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ff70_arg1, field_0, 0x0);

struct Unk_91ff70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ff70, field_0, 0x0);

// 0x710091ff70
void Unk_91ff70_set(const Unk_91ff70* self, Unk_91ff70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_91ff80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ff80_arg1, field_0, 0x0);

struct Unk_91ff80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ff80, field_0, 0x0);

// 0x710091ff80
void Unk_91ff80_set(const Unk_91ff80* self, Unk_91ff80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_91ff90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ff90, field_0, 0x0);

void Unk_91fa70(u64);

// 0x710091ff90
void Unk_91ff90_call(const Unk_91ff90* self) {
    Unk_91fa70(self->field_0);
}

// 0x710091ffa0
void Unk_91ffa0_update() {}

struct Unk_91ffb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ffb0_arg1, field_0, 0x0);

struct Unk_91ffb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ffb0, field_0, 0x0);

// 0x710091ffb0
void Unk_91ffb0_set(const Unk_91ffb0* self, Unk_91ffb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_91ffc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ffc0_arg1, field_0, 0x0);

struct Unk_91ffc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_91ffc0, field_0, 0x0);

// 0x710091ffc0
void Unk_91ffc0_set(const Unk_91ffc0* self, Unk_91ffc0_arg1* value) {
    value->field_0 = self->field_0;
}
