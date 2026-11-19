// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_16c1b60 {
    u8 _0[0x38];
    u32 field_38;
    u8 _3c[0xc];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_16c1b60, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_16c1b60, field_48, 0x48);

// 0x71016c1b60
void Unk_16c1b60_set(Unk_16c1b60* self, u32 value) {
    if (self->field_38 >= value) {
        self->field_48 = value;
    }
}

// 0x71016c1b80
void Unk_16c1b80_update() {
}

struct Unk_16c1b90 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1b90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16c1b90, field_8, 0x8);

// 0x71016c1b90
void Unk_16c1b90_set(Unk_16c1b90* self) {
    self->field_0 = 0;
    self->field_8 = 0;
}

// 0x71016c1ba0
void Unk_16c1ba0_update() {
}

struct Unk_16c1c00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_16c1c00_arg1, field_0, 0x0);

struct Unk_16c1c00 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1c00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16c1c00, field_8, 0x8);

// 0x71016c1c00
void Unk_16c1c00_set(Unk_16c1c00* self, const Unk_16c1c00_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = 1;
}

struct Unk_16c1c20 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16c1c20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16c1c20, field_8, 0x8);

// 0x71016c1c20
void Unk_16c1c20_set(Unk_16c1c20* self) {
    self->field_8 = 0;
    self->field_0 = 0;
}

extern u8 Unk_27fb30c __attribute__((visibility("hidden")));

// 0x71016c4040
u8 Unk_16c4040_get() {
    return Unk_27fb30c;
}

extern u8 Unk_27fb30d __attribute__((visibility("hidden")));

// 0x71016c4100
u8 Unk_16c4100_get() {
    return Unk_27fb30d;
}

extern u8 Unk_27fb2f8;

// 0x71016c4110
u8* Unk_16c4110_get() {
    return &Unk_27fb2f8;
}
