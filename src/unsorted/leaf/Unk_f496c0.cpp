// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_eb6530();

// 0x7100f496c0
u32 Unk_f496c0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_f497a0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f497a0, field_5cc, 0x5cc);

// 0x7100f497a0
void Unk_f497a0_clearField5cc(Unk_f497a0* self) {
    self->field_5cc = 0;
}

struct Unk_f498c0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f498c0, field_5cc, 0x5cc);

// 0x7100f498c0
u32 Unk_f498c0_getField5cc(const Unk_f498c0* self) {
    return self->field_5cc;
}

void Unk_f498d0(void*, u64, u64);

// 0x7100f499f0
void Unk_f499f0_call(void* self) {
    Unk_f498d0(self, 0x307f2287c63245da, 0xcc0cfcb797e44c58);
    Unk_f498d0(self, 0x307b9d87c62f2e04, 0x5f635651ac509cb1);
}

u32 Unk_eb6530();

// 0x7100f4a350
u32 Unk_f4a350_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

u32 Unk_eb6530();

// 0x7100f4b430
u32 Unk_f4b430_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

void Unk_f4ae60();

// 0x7100f4b450
void Unk_f4b450_call() {
    Unk_f4ae60();
}

struct Unk_f4b560 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4b560, field_5cc, 0x5cc);

// 0x7100f4b560
u32 Unk_f4b560_getField5cc(const Unk_f4b560* self) {
    return self->field_5cc;
}

struct Unk_f4b570 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4b570, field_5cc, 0x5cc);

// 0x7100f4b570
void Unk_f4b570_clearField5cc(Unk_f4b570* self) {
    self->field_5cc = 0;
}

// 0x7100f4bbe0
void Unk_f4bbe0_update() {}

struct Unk_f4bbf0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_f4bbf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f4bbf0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_f4bbf0, field_10, 0x10);

// 0x7100f4bbf0
void Unk_f4bbf0_set(const Unk_f4bbf0* self, Unk_f4bbf0* value) {
    *value = *self;
}

struct Unk_f4bc10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_f4bc10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f4bc10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_f4bc10, field_10, 0x10);

// 0x7100f4bc10
void Unk_f4bc10_set(const Unk_f4bc10* self, Unk_f4bc10* value) {
    *value = *self;
}

u32 Unk_eb6530();

// 0x7100f4c7f0
u32 Unk_f4c7f0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

void Unk_f4c3d0();

// 0x7100f4c810
void Unk_f4c810_call() {
    Unk_f4c3d0();
}

struct Unk_f4c920 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4c920, field_5cc, 0x5cc);

// 0x7100f4c920
u32 Unk_f4c920_getField5cc(const Unk_f4c920* self) {
    return self->field_5cc;
}

struct Unk_f4c930 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4c930, field_5cc, 0x5cc);

// 0x7100f4c930
void Unk_f4c930_clearField5cc(Unk_f4c930* self) {
    self->field_5cc = 0;
}

// 0x7100f4cfa0
void Unk_f4cfa0_update() {}

struct Unk_f4cfb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_f4cfb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f4cfb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_f4cfb0, field_10, 0x10);

// 0x7100f4cfb0
void Unk_f4cfb0_set(const Unk_f4cfb0* self, Unk_f4cfb0* value) {
    *value = *self;
}

struct Unk_f4cfd0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_f4cfd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f4cfd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_f4cfd0, field_10, 0x10);

// 0x7100f4cfd0
void Unk_f4cfd0_set(const Unk_f4cfd0* self, Unk_f4cfd0* value) {
    *value = *self;
}
