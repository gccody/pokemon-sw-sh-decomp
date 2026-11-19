// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71003a7b70
void Unk_3a7b70_update() {
}

struct Unk_3a7b80 {
    u64 field_0;
    u32 field_8;
    u16 field_c;
    u8 _e[0x2];
    u64 field_10;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_3a7b80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3a7b80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3a7b80, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_3a7b80, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3a7b80, field_18, 0x18);

// 0x71003a7b80
void Unk_3a7b80_set(Unk_3a7b80* self) {
    self->field_18 = 0xffffffff;
    self->field_0 = 0xffffffff00000000;
    self->field_10 = 0;
    self->field_8 = 0;
    self->field_c = self->field_c & 0xf800;
}

// 0x71003a8030
void Unk_3a8030_update() {
}

struct Unk_3b1c80 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3b1c80, field_20, 0x20);

// 0x71003b1c80
void Unk_3b1c80_set(Unk_3b1c80* self, u64 value) {
    self->field_20 = value;
}

struct Unk_3b1c90 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3b1c90, field_20, 0x20);

// 0x71003b1c90
void Unk_3b1c90_set(Unk_3b1c90* self) {
    self->field_20 = 0;
}

struct Unk_3b33a0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3b33a0, field_8, 0x8);

// 0x71003b33a0
bool Unk_3b33a0_check(const Unk_3b33a0* self) {
    return self->field_8 != 0;
}

struct Unk_3b33b0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    bool field_8;
};
PKMN_OFFSET_ASSERT(Unk_3b33b0, field_8, 0x8);

// 0x71003b33b0
void Unk_3b33b0_call(Unk_3b33b0* self, bool value) {
    self->field_8 = value;
    self->vf10();
}
