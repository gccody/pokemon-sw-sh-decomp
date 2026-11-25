// Scope: common
//
// The tail of a TU of game/pokecamp (0x7101240830 to 0x7101243470, the rest
// in src/unsorted/Unk_1240830.cpp and Unk_12424f0.cpp).
//
// The virtual functions here (0x7101242cb0 to 0x7101243270: Unk_2426208's
// thunks at +0x50, and Unk_2426310's) aren't written yet: their classes have
// internal linkage, and their vtables are only emitted where an object is
// made, inside vf8s that aren't decompiled yet (see Unk_12424f0.cpp).
#include <types.h>

// src/unsorted/leaf/Unk_11575f0.cpp
struct Unk_115a6e0;
u64 Unk_115a6e0_getField308(const Unk_115a6e0* self);
// Not decompiled yet: 0x710115a6f0 (field_310, or a lookup of field_308).
u8 Unk_115a6f0(const Unk_115a6e0* self);

// What the callback fills: a value and a flag per object.
struct Unk_1243310_Entry {
    u64 field_0;
    u32 field_8;
};
static_assert(sizeof(Unk_1243310_Entry) == 0x10, "Unk_1243310_Entry");

// What it holds: the entries and their count, by reference. The callback is
// a lambda of 0x7101240a30, which hands its address on; a placeholder free
// function here.
struct Unk_1243310 {
    Unk_1243310_Entry* entries;
    s32* count;
};
PKMN_OFFSET_ASSERT(Unk_1243310, count, 0x8);

// 0x7101243310
void Unk_1243310_call(const Unk_1243310* self, const Unk_115a6e0* const* object) {
    const Unk_115a6e0* p = *object;
    u64 value = Unk_115a6e0_getField308(p);
    u32 flag = Unk_115a6f0(p);
    Unk_1243310_Entry& entry = self->entries[*self->count];
    ++*self->count;
    entry.field_0 = value;
    entry.field_8 = flag;
}
