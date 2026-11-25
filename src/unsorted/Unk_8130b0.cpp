// Scope: common
#include <types.h>

struct Unk_8130b0 {
    void* field_0[9];
    u8 _48[4];
    u8 field_4c;
    u8 _4d;
    u8 field_4e;
};
PKMN_OFFSET_ASSERT(Unk_8130b0, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_8130b0, field_4e, 0x4e);

// 0x71008130b0
// Removes the first occurrence of item and moves the rest down.
void Unk_8130b0_remove(Unk_8130b0* self, void* item) {
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->field_0[i] == item) {
            for (u32 j = i + 1; j < self->field_4c; j++)
                self->field_0[j - 1] = self->field_0[j];
            self->field_4c--;
            self->field_4e--;
            return;
        }
    }
}

struct Unk_7ee6b0;

// A list of up to 5 target Pokemon with two amounts and a flag each.
struct Unk_813270 {
    const Unk_7ee6b0* items[5];
    u16 field_28[5];
    u16 field_32[5];
    u8 field_3c[5];
    u16 field_42[5];
    u8 field_4c;
    u8 field_4d;
    u8 field_4e;
    u8 field_4f;
};
PKMN_OFFSET_ASSERT(Unk_813270, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_813270, field_32, 0x32);
PKMN_OFFSET_ASSERT(Unk_813270, field_3c, 0x3c);
PKMN_OFFSET_ASSERT(Unk_813270, field_42, 0x42);
PKMN_OFFSET_ASSERT(Unk_813270, field_4c, 0x4c);
PKMN_SIZE_ASSERT(Unk_813270, 0x50);

// Callers name the same layout after other functions.
struct Unk_830590_Info : Unk_813270 {};
struct Unk_813130 : Unk_813270 {};

extern const u32 Unk_1f126b0[] __attribute__((visibility("hidden")));

// 0x7100812e40
// NON_MATCHING: the original sign-extends the table index straight to 64 bits
// (sbfx x) and orders the mask/shift differently; the count is a signed 5-bit
// field (read signed only for the index), whose source form isn't known yet.
// +0x10 holds a count of up to 5 queued 5-bit values in its low 5 bits, the
// values above it.
void Unk_812e40(unsigned long self, unsigned long value) {
    u32* queue = reinterpret_cast<u32*>(self + 0x10);
    u32 bits = *queue;
    u32 count = bits & 0x1f;
    if (count > 4)
        return;
    s32 index = static_cast<s32>(bits << 27) >> 27;
    bits = (bits & Unk_1f126b0[index]) | ((static_cast<u32>(value) & 0x1f) << (count * 5 + 5));
    *queue = (bits & ~0x1fu) | ((bits + 1) & 0x1f);
}

// 0x7100812ec0
void Unk_812ec0(Unk_830590_Info* self) {
    for (u32 i = 0; i < 5; i++) {
        self->items[i] = nullptr;
        self->field_28[i] = 0;
        self->field_32[i] = 0;
        self->field_3c[i] = 0;
        self->field_42[i] = 0;
    }
    self->field_4c = 0;
    self->field_4d = 0;
    self->field_4e = 0;
    self->field_4f = 0;
}

// 0x7100812ee0
void Unk_812ee0(Unk_813270* self) {
    for (u32 i = 0; i < 5; i++) {
        self->items[i] = nullptr;
        self->field_28[i] = 0;
        self->field_32[i] = 0;
        self->field_3c[i] = 0;
        self->field_42[i] = 0;
    }
    self->field_4c = 0;
    self->field_4d = 0;
    self->field_4e = 0;
    self->field_4f = 0;
}

// 0x7100812f00
// NON_MATCHING: the original compares the count with 4 in 64 bits (cmp x8, #4).
void Unk_812f00_add(Unk_813270* self, const Unk_7ee6b0* item) {
    if (item == nullptr || self->field_4c >= 5)
        return;
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->items[i] == item)
            return;
    }
    self->items[self->field_4c] = item;
    self->field_3c[self->field_4c] = 0;
    self->field_28[self->field_4c] = 0;
    self->field_32[self->field_4c] = 0;
    self->field_4c++;
    if (self->field_4c > self->field_4d)
        self->field_4d = self->field_4c;
}

// 0x7100812f80
void Unk_812f80(Unk_813270* self, const Unk_7ee6b0* item, u16 amount, bool second) {
    Unk_812f00_add(self, item);
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->items[i] == item) {
            if (second) {
                self->field_32[i] += amount;
                self->field_3c[i] = 2;
            } else {
                self->field_28[i] += amount;
                self->field_3c[i] = 1;
            }
        }
    }
}

// 0x7100813110
const Unk_7ee6b0* Unk_813110(const Unk_813270* self, u32 index) {
    if (index < self->field_4c)
        return self->items[index];
    return nullptr;
}

// 0x7100813140
void* Unk_813140(Unk_813130* self) {
    if (self->field_4e < self->field_4c)
        return const_cast<Unk_7ee6b0*>(self->items[self->field_4e++]);
    return nullptr;
}

// 0x7100813170
bool Unk_813170(const Unk_813270* self, const Unk_7ee6b0* poke, u32* out) {
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->items[i] == poke && self->field_3c[i] != 0) {
            *out = self->field_28[i] + self->field_32[i];
            return true;
        }
    }
    return false;
}

// 0x71008131d0
bool Unk_8131d0(const Unk_813270* self, const Unk_7ee6b0* poke, u32* out) {
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->items[i] == poke && self->field_3c[i] == 1) {
            *out = self->field_28[i];
            return true;
        }
    }
    return false;
}

// 0x7100813230
u8 Unk_813230(const Unk_813270* self, const Unk_7ee6b0* poke) {
    for (u32 i = 0; i < self->field_4c; i++) {
        if (self->items[i] == poke)
            return self->field_3c[i];
    }
    return 0;
}
