// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_341b70 {
    u8 _0[0xbc];
    u32 field_bc;
};
PKMN_OFFSET_ASSERT(Unk_341b70, field_bc, 0xbc);

// 0x7100341b70
void Unk_341b70_set(Unk_341b70* self, u32 value) {
    self->field_bc = value;
}

struct Unk_341ca0 {
    u8 _0[0xc4];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_341ca0, field_c4, 0xc4);

// 0x7100341ca0
u8 Unk_341ca0_get(const Unk_341ca0* self) {
    return self->field_c4;
}

struct Unk_341cb0 {
    u8 _0[0xc5];
    bool field_c5;
};
PKMN_OFFSET_ASSERT(Unk_341cb0, field_c5, 0xc5);

// 0x7100341cb0
void Unk_341cb0_set(Unk_341cb0* self, bool value) {
    self->field_c5 = value;
}

struct Unk_341cc0 {
    u8 _0[0xb0];
    u64 field_b0;
    u32 field_b8;
    u8 _bc[0x8];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_341cc0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_341cc0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_341cc0, field_c4, 0xc4);

// 0x7100341cc0
void Unk_341cc0_set(Unk_341cc0* self, u64 value, u32 arg2) {
    self->field_b0 = value;
    self->field_b8 = arg2;
    self->field_c4 = 0;
}

struct Unk_341cd0 {
    u8 _0[0xc0];
    u32 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_341cd0, field_c0, 0xc0);

// 0x7100341cd0
void Unk_341cd0_set(Unk_341cd0* self, u32 value) {
    self->field_c0 = value;
}

struct Unk_341d00 {
    u8 _0[0xbc];
    u32 field_bc;
};
PKMN_OFFSET_ASSERT(Unk_341d00, field_bc, 0xbc);

// 0x7100341d00
void Unk_341d00_set(Unk_341d00* self) {
    self->field_bc = 1;
}

extern u32 Unk_237e820;
struct Unk_341f80 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_341f80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_341f80, field_8, 0x8);
void Unk_3047c0(int, void*);

// 0x7100341f80
void Unk_341f80_set(Unk_341f80* self) {
    if (self->field_8 != 0) {
        Unk_3047c0(Unk_237e820, reinterpret_cast<void*>(self->field_0));
    }
    self->field_0 = 0;
    self->field_8 = 0;
}

// 0x7100343eb0
void Unk_343eb0_update() {
}

struct Unk_349940 {
    u8 _0[0xd0];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_349940, field_d0, 0xd0);
void Unk_348df0();

// 0x7100349940
void Unk_349940_update(const Unk_349940* self) {
    if (self->field_d0 != 0) {
        return;
    }
    Unk_348df0();
}

// 0x7100349be0
void Unk_349be0_update() {
}

void Unk_34a670(void*, u32);

// 0x710034a660
void Unk_34a660_call(void* self) {
    Unk_34a670(self, 0xb);
}
