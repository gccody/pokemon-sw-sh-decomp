#pragma once
// Two classes built on the objects Unk_237c170's slot 76 creates
// (Unk_310160_T): the classes of vtables 0x710237dbc8 and 0x710237dd38. Both
// have three vptrs (at 0, 0x18 and 0x28) and keep a reference to the node
// they play (field_90). Placeholder names.
#include <types.h>

#include "Unk_237c170.h"

// The vtables are data here: each class has one vtable group, with the
// secondary vtables 0x140 and 0x168 bytes in.
extern void* _ZTV11Unk_237dbc8[];
extern void* _ZTV11Unk_237dd38[];

// The base class's constructor and destructor.
void Unk_319190(Unk_310160_T* self, void* a1);
void Unk_3191e0(void* self);

struct Unk_31b990_T {
    void* field_0;  // vptr
    u8 _8[0x10];
    void* field_18;  // vptr
    u8 _20[8];
    void* field_28;  // vptr
    u8 _30[0x60];
    Unk_237c170* field_90;
};
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_90, 0x90);
PKMN_SIZE_ASSERT(Unk_31b990_T, 0x98);

static inline void Unk_31b990_SetVtables(Unk_31b990_T* self, void** vtable) {
    self->field_0 = vtable + 2;
    self->field_18 = vtable + 40;
    self->field_28 = vtable + 45;
}

// What the second class has at 0x98.
struct Unk_3168a0_T {
    u8 _0[0x48];
};

void Unk_3168a0(Unk_3168a0_T* self, Unk_237c170* node);
void Unk_316c50(Unk_3168a0_T* self);
void Unk_3168d0_update(u64 self);

struct Unk_31c020_T : Unk_31b990_T {
    Unk_3168a0_T field_98;
    bool field_e0;
};
PKMN_OFFSET_ASSERT(Unk_31c020_T, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_31c020_T, field_e0, 0xe0);
PKMN_SIZE_ASSERT(Unk_31c020_T, 0xe8);
