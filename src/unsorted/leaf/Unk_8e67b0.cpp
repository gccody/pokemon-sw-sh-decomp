// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_8e67b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67b0_arg1, field_0, 0x0);

struct Unk_8e67b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67b0, field_0, 0x0);

// 0x71008e67b0
void Unk_8e67b0_call(const Unk_8e67b0* self, Unk_8e67b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8e67d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67d0_arg1, field_0, 0x0);

struct Unk_8e67d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67d0, field_0, 0x0);

// 0x71008e67d0
void Unk_8e67d0_set(Unk_8e67d0* self, Unk_8e67d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_8e6860_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6860_arg1, field_0, 0x0);

struct Unk_8e6860 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6860, field_0, 0x0);

// 0x71008e6860
void Unk_8e6860_call(const Unk_8e6860* self, Unk_8e6860_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8e6880_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6880_arg1, field_0, 0x0);

struct Unk_8e6880 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6880, field_0, 0x0);

// 0x71008e6880
void Unk_8e6880_set(Unk_8e6880* self, Unk_8e6880_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

// 0x71008e84a0
void Unk_8e84a0_update() {}

struct Unk_8e84b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84b0_arg1, field_0, 0x0);

struct Unk_8e84b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84b0, field_0, 0x0);

// 0x71008e84b0
void Unk_8e84b0_set(const Unk_8e84b0* self, Unk_8e84b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8e84c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84c0_arg1, field_0, 0x0);

struct Unk_8e84c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84c0, field_0, 0x0);

// 0x71008e84c0
void Unk_8e84c0_set(const Unk_8e84c0* self, Unk_8e84c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71008e8530
void Unk_8e8530_update() {}

struct Unk_8e8540 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8540, field_8, 0x8);

// 0x71008e8540
void Unk_8e8540_set(const Unk_8e8540* self, Unk_8e8540* value) {
    *value = *self;
}

struct Unk_8e8550 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8550, field_8, 0x8);

// 0x71008e8550
void Unk_8e8550_set(const Unk_8e8550* self, Unk_8e8550* value) {
    *value = *self;
}

// 0x71008e85b0
void Unk_8e85b0_update() {}

struct Unk_8e85c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e85c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e85c0, field_8, 0x8);

// 0x71008e85c0
void Unk_8e85c0_set(const Unk_8e85c0* self, Unk_8e85c0* value) {
    *value = *self;
}

struct Unk_8e85d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e85d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e85d0, field_8, 0x8);

// 0x71008e85d0
void Unk_8e85d0_set(const Unk_8e85d0* self, Unk_8e85d0* value) {
    *value = *self;
}

// 0x71008e8630
void Unk_8e8630_update() {}

struct Unk_8e8640 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8640, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8640, field_8, 0x8);

// 0x71008e8640
void Unk_8e8640_set(const Unk_8e8640* self, Unk_8e8640* value) {
    *value = *self;
}

struct Unk_8e8650 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8650, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8650, field_8, 0x8);

// 0x71008e8650
void Unk_8e8650_set(const Unk_8e8650* self, Unk_8e8650* value) {
    *value = *self;
}

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
