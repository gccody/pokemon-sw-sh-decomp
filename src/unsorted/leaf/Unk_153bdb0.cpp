// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_153bdb0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_153bdb0, field_60, 0x60);

// 0x710153bdb0
u64 Unk_153bdb0_getField60(const Unk_153bdb0* self) {
    return self->field_60;
}

struct Unk_153bdc0 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_153bdc0, field_88, 0x88);

// 0x710153bdc0
u8* Unk_153bdc0_getField88Ptr(Unk_153bdc0* self) {
    return &self->field_88;
}

struct Unk_153bdd0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_153bdd0, field_6c, 0x6c);

// 0x710153bdd0
void Unk_153bdd0_setField6c(Unk_153bdd0* self, u32 value) {
    self->field_6c = value;
}

struct Unk_153c340 {
    u8 _0[0xb0];
    u32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_153c340, field_b0, 0xb0);

// 0x710153c340
bool Unk_153c340_check(const Unk_153c340* self) {
    return self->field_b0 == 3;
}

struct Unk_153c350 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_153c350, field_a8, 0xa8);

void Unk_1503210(u64);

// 0x710153c350
void Unk_153c350_call(const Unk_153c350* self) {
    Unk_1503210(self->field_a8);
}

struct Unk_153c360 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_153c360, field_b8, 0xb8);

void Unk_151a430(u64, u64, u32);

// 0x710153c360
void Unk_153c360_call(const Unk_153c360* self, u64 value, bool arg2) {
    Unk_151a430(self->field_b8, value, arg2);
}

struct Unk_153c3f0 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_153c3f0, field_b8, 0xb8);

void Unk_151a410(u64);

// 0x710153c3f0
void Unk_153c3f0_call(const Unk_153c3f0* self) {
    Unk_151a410(self->field_b8);
}

struct Unk_153c410 {
    u8 _0[0x780];
    u64 field_780;
};
PKMN_OFFSET_ASSERT(Unk_153c410, field_780, 0x780);

// 0x710153c410
void Unk_153c410_setField780(Unk_153c410* self, u64 value) {
    self->field_780 = value;
}

u32 Unk_eb6530();

// 0x71015407d0
u32 Unk_15407d0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_15407f0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_15407f0, field_5cc, 0x5cc);

// 0x71015407f0
u32 Unk_15407f0_getField5cc(const Unk_15407f0* self) {
    return self->field_5cc;
}

struct Unk_1540800 {
    u8 _0[0x5d8];
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_1540800, field_5d8, 0x5d8);

// 0x7101540800
void Unk_1540800_setField5d8(Unk_1540800* self, u64 value) {
    self->field_5d8 = value;
}

void Unk_eb6230(void*, u32);

// 0x7101542b60
void Unk_1542b60_call(void* self) {
    Unk_eb6230(self, 3);
}

u32 Unk_eb6530();

// 0x7101542b70
u32 Unk_1542b70_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

void Unk_eb6230(void*, u32);

// 0x7101543510
void Unk_1543510_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7101543520
void Unk_1543520_call(void* self) {
    Unk_eb6230(self, 3);
}

u32 Unk_eb6530();

// 0x7101543530
u32 Unk_1543530_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}
