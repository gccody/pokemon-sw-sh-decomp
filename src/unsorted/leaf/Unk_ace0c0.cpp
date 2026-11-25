// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ace0c0 {
    u8 _0[0x5d8];
    u8 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_ace0c0, field_5d8, 0x5d8);

void Unk_eb6230(void*, u32);

// 0x7100ace0c0
void Unk_ace0c0_call(Unk_ace0c0* self) {
    if (self->field_5d8 != 0) {
        Unk_eb6230(self, 0);
        return;
    }
    Unk_eb6230(self, 2);
}

struct Unk_ace0e0 {
    u8 _0[0x5d8];
    u8 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_ace0e0, field_5d8, 0x5d8);

void Unk_eb6230(void*, u32);

// 0x7100ace0e0
void Unk_ace0e0_call(Unk_ace0e0* self) {
    if (self->field_5d8 != 0) {
        Unk_eb6230(self, 1);
        return;
    }
    Unk_eb6230(self, 3);
}

struct Unk_acf300_638 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_acf300_638, field_58, 0x58);

struct Unk_acf300 {
    u8 _0[0x638];
    Unk_acf300_638* field_638;
};
PKMN_OFFSET_ASSERT(Unk_acf300, field_638, 0x638);

// 0x7100acf300
void Unk_acf300_set(const Unk_acf300* self, bool value) {
    self->field_638->field_58 = (self->field_638->field_58 & 0xfffffffe) | (value);
}

struct Unk_ad0dc0_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ad0dc0_0, field_600, 0x600);

struct Unk_ad0dc0 {
    Unk_ad0dc0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0dc0, field_0, 0x0);

// 0x7100ad0dc0
void Unk_ad0dc0_set(const Unk_ad0dc0* self) {
    self->field_0->field_600 = 1;
}

// 0x7100ad0dd0
void Unk_ad0dd0_update() {}

struct Unk_ad0de0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0de0_arg1, field_0, 0x0);

struct Unk_ad0de0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0de0, field_0, 0x0);

// 0x7100ad0de0
void Unk_ad0de0_set(const Unk_ad0de0* self, Unk_ad0de0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0df0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0df0_arg1, field_0, 0x0);

struct Unk_ad0df0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0df0, field_0, 0x0);

// 0x7100ad0df0
void Unk_ad0df0_set(const Unk_ad0df0* self, Unk_ad0df0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0e00_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ad0e00_0, field_600, 0x600);

struct Unk_ad0e00 {
    Unk_ad0e00_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e00, field_0, 0x0);

// 0x7100ad0e00
void Unk_ad0e00_set(const Unk_ad0e00* self) {
    self->field_0->field_600 = 3;
}

// 0x7100ad0e10
void Unk_ad0e10_update() {}

struct Unk_ad0e20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e20_arg1, field_0, 0x0);

struct Unk_ad0e20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e20, field_0, 0x0);

// 0x7100ad0e20
void Unk_ad0e20_set(const Unk_ad0e20* self, Unk_ad0e20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0e30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e30_arg1, field_0, 0x0);

struct Unk_ad0e30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e30, field_0, 0x0);

// 0x7100ad0e30
void Unk_ad0e30_set(const Unk_ad0e30* self, Unk_ad0e30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0e40_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ad0e40_0, field_600, 0x600);

struct Unk_ad0e40 {
    Unk_ad0e40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e40, field_0, 0x0);

// 0x7100ad0e40
void Unk_ad0e40_set(const Unk_ad0e40* self) {
    self->field_0->field_600 = 4;
}

// 0x7100ad0e50
void Unk_ad0e50_update() {}

struct Unk_ad0e60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e60_arg1, field_0, 0x0);

struct Unk_ad0e60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e60, field_0, 0x0);

// 0x7100ad0e60
void Unk_ad0e60_set(const Unk_ad0e60* self, Unk_ad0e60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0e70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e70_arg1, field_0, 0x0);

struct Unk_ad0e70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e70, field_0, 0x0);

// 0x7100ad0e70
void Unk_ad0e70_set(const Unk_ad0e70* self, Unk_ad0e70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0e80_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ad0e80_0, field_600, 0x600);

struct Unk_ad0e80 {
    Unk_ad0e80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0e80, field_0, 0x0);

// 0x7100ad0e80
void Unk_ad0e80_set(const Unk_ad0e80* self) {
    self->field_0->field_600 = 2;
}

// 0x7100ad0e90
void Unk_ad0e90_update() {}

struct Unk_ad0ea0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0ea0_arg1, field_0, 0x0);

struct Unk_ad0ea0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0ea0, field_0, 0x0);

// 0x7100ad0ea0
void Unk_ad0ea0_set(const Unk_ad0ea0* self, Unk_ad0ea0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad0eb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0eb0_arg1, field_0, 0x0);

struct Unk_ad0eb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad0eb0, field_0, 0x0);

// 0x7100ad0eb0
void Unk_ad0eb0_set(const Unk_ad0eb0* self, Unk_ad0eb0_arg1* value) {
    value->field_0 = self->field_0;
}
