// Scope: common
// The virtual functions of Unk_2432c78 and the bits of its two tables.
#include "battle/battle_engine/Unk_137c470.h"

// The object field_60 comes from (0x7100b4c070 hands out what it holds at
// +0x3830), as Unk_24ba5a8 holds it.
class Unk_b4c070 : public Unk_239a418 {};

// 0x7100b4c070 (src/unsorted/leaf/Unk_b334b0.cpp)
Unk_239a418_Ref<Unk_b751c0_Self> Unk_b4c070_call(const Unk_b4c070* self);

struct Unk_24ba5a8_Type {
    u8 _0[0x78];
    Unk_b4c070* field_78;
};
PKMN_OFFSET_ASSERT(Unk_24ba5a8_Type, field_78, 0x78);

extern Unk_24ba5a8_Type* Unk_24ba5a8;

// What Unk_24ba4e0 holds at +0x1e8: its byte at +0x105 picks what 0x7100b751c0
// looks in.
class Unk_136b580 : public Unk_239a418 {};

// 0x710136b580 (src/unsorted/leaf/Unk_1361f80.cpp)
u8 Unk_136b580_getField105(const Unk_136b580* self);

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type {
    u8 _0[0x1e8];
    Unk_136b580* field_1e8;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_1e8, 0x1e8);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The block's key in the store.
extern const u32 Unk_1f34580;

// What 0x7100b751c0 fills: field_8 is the bit of the entry it found.
struct Unk_b751c0_Out {
    u8 field_0 = 0;
    u32 field_4 = 0;
    u32 field_8 = 0x3ff;
    u64 field_10 = 0;
    u64 field_18 = 0;
    u64 field_20 = 0;
    u64 field_28 = 0;
    u64 field_30 = 0;
    u32 field_38 = 0;
    u8 _3c[0x104];
};
PKMN_OFFSET_ASSERT(Unk_b751c0_Out, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b751c0_Out, field_38, 0x38);
PKMN_SIZE_ASSERT(Unk_b751c0_Out, 0x140);

// 0x7100b751c0: look the key up in the table of `kind` (0 or 1), at `index`.
bool Unk_b751c0(Unk_b751c0_Self* self, u8 kind, s32 index, const u64& key, Unk_b751c0_Out* out);

static void Unk_Fetch(Unk_2432c78* self, Unk_b4c070* owner) {
    self->field_60 = Unk_b4c070_call(owner).m_ptr;
}

static void Unk_Write(Unk_2432c78* self) {
    Unk_239a418_Ref<Unk_b4c070> owner(Unk_24ba5a8->field_78);
    Unk_Fetch(self, owner.m_ptr);
    Unk_24ba4e0_Type* stores = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(stores, which);
    Unk_137c710_T* data = &self->field_68;
    u64 size = sizeof(self->field_68);
    store->Unk_13456e0(Unk_1f34580, data, size);
}

// 0x710137c470
void Unk_2432c78::vf7() {
    Unk_Reset();
    Unk_Write(this);
}

// 0x710137c560
void Unk_2432c78::vf9() {
    Unk_Write(this);
}

// 0x710137c620
void Unk_2432c78::vf8() {
    Unk_239a418_Ref<Unk_b4c070> owner(Unk_24ba5a8->field_78);
    Unk_Fetch(this, owner.m_ptr);
    Unk_24ba4e0_Type* stores = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(stores, which);
    Unk_137c710_T* data = &field_68;
    u64 size = sizeof(field_68);
    if (!store->Unk_1346030(Unk_1f34580, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f34580);
}

// 0x710137c850
bool Unk_2432c78::Unk_137c850(s32 index, u32 bit) {
    if (index < 0 || index >= 15 || bit >= 1024)
        return false;
    return (field_68.field_0[index][bit / 8] & (1 << (bit % 8))) != 0;
}

static u8 Unk_Kind() {
    Unk_239a418_Ref<Unk_136b580> owner(Unk_24ba4e0->field_1e8);
    return Unk_136b580_getField105(owner.m_ptr);
}

// The bit of the entry of a key.
static bool Unk_FindBit(Unk_2432c78* self, s32 index, const u64& key, u32* bit) {
    if (self->field_60 == nullptr)
        return false;
    u8 kind = Unk_Kind();
    Unk_b751c0_Out out;
    if (!Unk_b751c0(self->field_60, kind, index, key, &out))
        return false;
    *bit = out.field_8;
    return true;
}

// 0x710137c8a0: the bit of the entry of a key.
bool Unk_2432c78::Unk_137c8a0(s32 index, const u64& key) {
    u32 bit;
    if (!Unk_FindBit(this, index, key, &bit))
        return false;
    return Unk_137c850(index, bit);
}

// 0x710137c9c0
void Unk_2432c78::Unk_137c9c0(s32 index, u32 bit, bool value) {
    if (index < 0 || index >= 15 || bit >= 1024)
        return;
    u8& bits = field_68.field_0[index][bit / 8];
    u8 old = bits;
    u8 mask = 1 << (bit % 8);
    if (value)
        bits = old | mask;
    else
        bits = old & ~mask;
}

// 0x710137ca10
// NON_MATCHING: the original sets the bit with a branch on `value` (tbz,
// orr/bic), not the csel the inlined 0x710137c9c0 gives (and that 0x710137c9c0
// itself has); an inline copy of the set code gives the csel too.
void Unk_2432c78::Unk_137ca10(s32 index, const u64& key, bool value) {
    if (field_60 == nullptr)
        return;
    u8 kind = Unk_Kind();
    Unk_b751c0_Out out;
    if (!Unk_b751c0(field_60, kind, index, key, &out))
        return;
    Unk_137c9c0(index, out.field_8, value);
}

// 0x710137cb30: whether a bit of the second table is on (it's kept inverted).
bool Unk_2432c78::Unk_137cb30(s32 index, u32 bit) {
    if (index >= 0 && index < 15) {
        if (bit >= 1024)
            return true;
        return (field_68.field_780[index][bit / 8] & (1 << (bit % 8))) == 0;
    }
    return false;
}

// 0x710137cb80
// NON_MATCHING: the original's orr takes the old byte first (orr w9, w9, w10);
// every way of writing it tried gives the operands swapped, or the orr before
// the bic.
void Unk_2432c78::Unk_137cb80(s32 index, u32 bit, bool value) {
    if (index < 0 || index >= 15 || bit >= 1024)
        return;
    u8& bits = field_68.field_780[index][bit / 8];
    u8 old = bits;
    u8 mask = 1 << (bit % 8);
    bits = value ? old & ~mask : old | mask;
}
