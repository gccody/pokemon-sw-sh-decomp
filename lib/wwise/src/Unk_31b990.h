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

// What the objects keep in a list at 0x30.
struct Unk_31b990_Item {
    u8 _0[8];
    Unk_31b990_Item* next;
};

// The object at 0x60.
struct Unk_31b990_Ctx {
    u8 _0[8];
    u64 field_8;
    u8 _10[8];
    u8 field_18[0x18];
    u64 field_30;
    u8 field_38;
    u8 _39[0x13];
    f32 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_31b990_Ctx, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_31b990_Ctx, field_4c, 0x4c);

struct Unk_31b990_T {
    void* field_0;  // vptr
    u8 _8[0x10];
    void* field_18;  // vptr
    u8 _20[8];
    void* field_28;  // vptr
    Unk_31b990_Item* field_30;
    u8 _38[0x10];
    u32 field_48;  // reference count
    u8 _4c[0xe];
    u8 field_5a_0 : 1;
    u8 field_5a_1 : 3;
    u8 _5b[5];
    Unk_31b990_Ctx* field_60;
    s64 field_68;
    u8 _70[0x20];
    Unk_237c170* field_90;
};
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_31b990_T, field_68, 0x68);
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

// The node the first class plays: its own functions.
class Unk_237c860 : public Unk_237c170 {
public:
    Unk_310160_T* Unk_30e1a0(void* a1, void* a2, void* a3, bool a4);
};

static inline Unk_237c860* Unk_31b990_Node(Unk_31b990_T* self) {
    return static_cast<Unk_237c860*>(self->field_90);
}

u32 Unk_30ea20(Unk_237c860* self);
u32 Unk_30ea00(Unk_237c860* self);
u32 Unk_30e9f0(u64 self);
s32 Unk_30ec40(Unk_237c860* self, s32 position);

u32 Unk_31bdc0(Unk_31b990_T* self, s32 position);
u32 Unk_31bb90(void* object, u64 a1, u64 a2, u32 position, void* out, u32 a5);
