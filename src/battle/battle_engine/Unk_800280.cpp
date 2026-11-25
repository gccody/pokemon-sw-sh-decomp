// Scope: common
// An object with a packed 64-bit value at +0x58, a list of up to 5 5-bit ids
// filled from it (0x1f: none) and the u8 at +0x11 that selects it. Placeholder
// names: rename once the class is known.
#include <types.h>

struct Unk_800280 {
    u8 _0[0x11];
    u8 field_11;
    u8 _12[0x46];
    u64 field_58;
    u8 _60[0x28];
    u32 field_88;
    u8 _8c[0xa4];
    u32 field_130[5];
    u8 _144[0x34];
    u32 field_178;
    u8 _17c[0x24];
    u32 field_1a0;
    u8 _1a4[0x14];
    u16 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_800280, field_11, 0x11);
PKMN_OFFSET_ASSERT(Unk_800280, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_800280, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_800280, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_800280, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_800280, field_1a0, 0x1a0);
PKMN_OFFSET_ASSERT(Unk_800280, field_1b8, 0x1b8);

struct Unk_7f8b70;

u64 Unk_7f8780_get();
u8 Unk_7f88e0(const unsigned long* value);
u8 Unk_7f8960(const unsigned long* value);
u16 Unk_7f89e0(const unsigned long* value);
u32 Unk_7f8b70_get(const Unk_7f8b70* self);

static void Unk_8002a0_Clear(Unk_800280* self) {
    self->field_58 = Unk_7f8780_get();
    self->field_88 = 0;
    self->field_178 = 0;
    self->field_1a0 = 0;
    for (u32 i = 0; i < 5; i++)
        self->field_130[i] = 0x1f;
}

static void Unk_8002a0_Start(Unk_800280* self, u64 value) {
    self->field_1a0 = 1;
    self->field_58 = value;
    self->field_88 = 0;
    self->field_178 = 0;
    for (u32 i = 0; i < 5; i++)
        self->field_130[i] = 0x1f;
}

static void Unk_8002a0_Add(Unk_800280* self, u8 id) {
    if (id == 0x1f || self->field_1a0 == 0)
        return;
    u32 count = self->field_178;
    if (count >= 5)
        return;
    for (u32 i = 0; i < count; i++) {
        if (self->field_130[i] == id)
            return;
    }
    self->field_130[count] = id;
    self->field_178 = count + 1;
}

// 0x71008002a0
// NON_MATCHING: the original takes arg1 as a u8 (it extends it at every use;
// the existing name gives a u32, truncated once here), which also changes the
// frame. With a u8 it still differs in where the id's extension for the list
// compare happens and in two stores' order.
bool Unk_8002a0(void* object, u32 arg1, u64 arg2) {
    Unk_800280* self = static_cast<Unk_800280*>(object);
    u8 value = arg1;
    if (self->field_11 == value)
        return false;
    if (self->field_1a0 != 0)
        Unk_8002a0_Clear(self);
    if (value != 0) {
        self->field_1b8 = value;
        Unk_8002a0_Start(self, arg2);
        Unk_8002a0_Add(self, Unk_7f88e0(&arg2));
    }
    self->field_11 = value;
    return true;
}

// 0x7100800430
u32 Unk_800430(const Unk_800280* self) {
    u32 base = self->field_88;
    u32 n = Unk_7f8960(&self->field_58);
    u32 extra = 0;
    if (n > self->field_88 && n > 0)
        extra = n - self->field_88;
    return base + extra;
}

// 0x71008003e0
u32 Unk_8003e0(const Unk_800280* self) {
    return Unk_800430(self) - self->field_88;
}

// 0x7100800480
u32 Unk_800480(const Unk_800280* self) {
    if (self->field_11 == 0)
        return 0;
    return Unk_7f89e0(&self->field_58);
}

// 0x71008004b0
u32 Unk_8004b0(const Unk_800280* self) {
    if (self->field_11 == 0)
        return 0;
    return Unk_7f8b70_get(reinterpret_cast<const Unk_7f8b70*>(&self->field_58));
}
