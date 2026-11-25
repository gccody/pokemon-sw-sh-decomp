// Scope: common
// Battle engine helpers of the TU of 0x7100812bd0-0x71008139c0: a small set
// of byte ids and a record that Unk_812d00 fills from a Pokemon and its
// targets.
#include <types.h>

struct Unk_7ee6b0;
struct Unk_813270;
struct Unk_813280;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u32 Unk_813270_getField4c(const Unk_813270* self);
u32 Unk_813280_getField4d(const Unk_813280* self);
const Unk_7ee6b0* Unk_813110(const Unk_813270* self, u32 index);
u8 Unk_803600(void* self, u8 id);

// A set of up to 30 byte ids (Unk_812c50 refuses ids above 0x1d).
struct Unk_812bf0 {
    u8 _0[0x8];
    u8 count;
    u8 items[30];
};
PKMN_OFFSET_ASSERT(Unk_812bf0, count, 0x8);
PKMN_OFFSET_ASSERT(Unk_812bf0, items, 0x9);

// 0x7100812bf0
u8* Unk_812bf0_get(Unk_812bf0* self, u32 index) {
    if (index < self->count)
        return &self->items[index];
    return &self->items[0];
}

// 0x7100812c10
bool Unk_812c10_contains(const Unk_812bf0* self, u8 id) {
    for (u32 i = 0; i < self->count; i++) {
        if (self->items[i] == id)
            return true;
    }
    return false;
}

// 0x7100812c50
void Unk_812c50_add(Unk_812bf0* self, u8 id) {
    if (id > 0x1d)
        return;
    if (Unk_812c10_contains(self, id))
        return;
    self->items[self->count] = id;
    self->count++;
}

struct Unk_812cc0 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 _b;
    u16 field_c;
    u8 field_e;
    u8 _f;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_812cc0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_812cc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_812cc0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_812cc0, field_e, 0xe);
PKMN_SIZE_ASSERT(Unk_812cc0, 0x14);

// 0x7100812cc0
void Unk_812cc0_init(Unk_812cc0* self) {
    self->field_0 = 0;
    self->field_4 = 5;
    self->field_5 = 5;
    self->field_6 = 0;
    self->field_7 = 0;
    self->field_8 = 0;
    self->field_9 = 0;
    self->field_a = 0;
    self->field_c = 0xffff;
    self->field_e = 0;
    self->field_10 = 0;
}

// 0x7100812d00
void Unk_812d00(Unk_812cc0* self, const Unk_7ee6b0* poke, const Unk_813270* targets, void* arg3) {
    u32 kind = Unk_813280_getField4d(reinterpret_cast<const Unk_813280*>(targets));
    self->field_4 = Unk_803600(arg3, Unk_7ee6b0_getField7d(poke));
    self->field_5 = 5;
    self->field_8 = 0;
    self->field_9 = 0;
    self->field_a = 0;
    self->field_e = 0;
    self->field_10 = 0;
    if (kind == 1 && Unk_813270_getField4c(targets) != 0) {
        const Unk_7ee6b0* target = Unk_813110(targets, 0);
        if (target != nullptr)
            self->field_5 = Unk_803600(arg3, Unk_7ee6b0_getField7d(target));
    }
}

// 0x7100812df0
void Unk_812df0(Unk_812cc0* self) {
    if (self->field_9 == 0) {
        self->field_9 = 1;
        self->field_a = 1;
    }
}
