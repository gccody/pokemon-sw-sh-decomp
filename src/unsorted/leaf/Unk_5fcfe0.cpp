// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5fcfe0 {
    u8 _0[0x180];
    f32 field_180;
    u8 _184[0x5c];
    u8 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_5fcfe0, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_5fcfe0, field_1e0, 0x1e0);

// 0x71005fcfe0
void Unk_5fcfe0_set(Unk_5fcfe0* self, f32 fvalue) {
    self->field_180 = fvalue;
    self->field_1e0 = 1;
}

struct Unk_5fcff0 {
    u8 _0[0x173];
    u8 field_173;
    u8 _174[0x6c];
    u8 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_5fcff0, field_173, 0x173);
PKMN_OFFSET_ASSERT(Unk_5fcff0, field_1e0, 0x1e0);

// 0x71005fcff0
void Unk_5fcff0_set(Unk_5fcff0* self, u8 value) {
    self->field_173 = value;
    self->field_1e0 = 1;
}

struct Unk_601800_198 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_601800_198, field_78, 0x78);

struct Unk_601800 {
    u8 _0[0x198];
    Unk_601800_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_601800, field_198, 0x198);

// 0x7100601800
u8* Unk_601800_get(const Unk_601800* self) {
    return &self->field_198->field_78;
}

// 0x7100619490
void Unk_619490() {}
