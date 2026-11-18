// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4b79a0 {
    u8 _0[0x98];
    u32 field_98;
};
PKMN_OFFSET_ASSERT(Unk_4b79a0, field_98, 0x98);

// 0x71004b79a0
void Unk_4b79a0_set(Unk_4b79a0* self, u32 value) {
    self->field_98 = value;
}

struct Unk_4b8b40 {
    u8 _0[0x500];
    u32 field_500;
};
PKMN_OFFSET_ASSERT(Unk_4b8b40, field_500, 0x500);

// 0x71004b8b40
u32 Unk_4b8b40_update(Unk_4b8b40* self, u32 value) {
    self->field_500 = value;
    return 0;
}

struct Unk_4b91f0 {
    u8 _0[0x5c];
    f32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_4b91f0, field_5c, 0x5c);

// 0x71004b91f0
f32 Unk_4b91f0_get(const Unk_4b91f0* self) {
    return self->field_5c;
}

struct Unk_4b9200 {
    u8 _0[0x60];
    f32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_4b9200, field_60, 0x60);

// 0x71004b9200
f32 Unk_4b9200_get(const Unk_4b9200* self) {
    return self->field_60;
}

struct Unk_4b9210 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_4b9210, field_64, 0x64);

// 0x71004b9210
const u8* Unk_4b9210_get(const Unk_4b9210* self) {
    return &self->field_64;
}
