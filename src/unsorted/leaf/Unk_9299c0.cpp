// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x71009299c0
void Unk_9299c0_call(void* self) {
    Unk_eb6230(self, 3);
}

// 0x710092a7c0
void Unk_92a7c0_update() {}

struct Unk_92a7d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a7d0_arg1, field_0, 0x0);

struct Unk_92a7d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a7d0, field_0, 0x0);

// 0x710092a7d0
void Unk_92a7d0_set(const Unk_92a7d0* self, Unk_92a7d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92a7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a7e0_arg1, field_0, 0x0);

struct Unk_92a7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a7e0, field_0, 0x0);

// 0x710092a7e0
void Unk_92a7e0_set(const Unk_92a7e0* self, Unk_92a7e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92a7f0_0 {
    u8 _0[0x5d4];
    u8 field_5d4;
};
PKMN_OFFSET_ASSERT(Unk_92a7f0_0, field_5d4, 0x5d4);

struct Unk_92a7f0 {
    Unk_92a7f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a7f0, field_0, 0x0);

// 0x710092a7f0
void Unk_92a7f0_set(const Unk_92a7f0* self) {
    self->field_0->field_5d4 = 1;
}

// 0x710092a800
void Unk_92a800_update() {}

struct Unk_92a810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a810_arg1, field_0, 0x0);

struct Unk_92a810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a810, field_0, 0x0);

// 0x710092a810
void Unk_92a810_set(const Unk_92a810* self, Unk_92a810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_92a820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a820_arg1, field_0, 0x0);

struct Unk_92a820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_92a820, field_0, 0x0);

// 0x710092a820
void Unk_92a820_set(const Unk_92a820* self, Unk_92a820_arg1* value) {
    value->field_0 = self->field_0;
}
