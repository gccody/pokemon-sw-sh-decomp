// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

struct Unk_5518d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u8 field_20;
    u8 _21[0x37];
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u8 field_70;
    u8 _71[0x3];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_5518d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_5518d0, field_74, 0x74);


// 0x71005518d0
void Unk_5518d0_call(Unk_5518d0* self) {
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    Unk_596410(&self->field_20, 0);
    self->field_74 = 0;
    self->field_70 = 0;
    self->field_58 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
}

struct Unk_552080 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_552080, field_5c, 0x5c);

// 0x7100552080
u32 Unk_552080_get(const Unk_552080* self) {
    return self->field_5c;
}

struct Unk_5520b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u8 field_20;
    u8 _21[0x37];
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u8 field_70;
    u8 _71[0x3];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_5520b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_5520b0, field_74, 0x74);


// 0x71005520b0
void Unk_5520b0_call(Unk_5520b0* self) {
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    Unk_596410(&self->field_20, 0);
    self->field_74 = 0;
    self->field_70 = 0;
    self->field_58 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
}

struct Unk_552840 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_552840, field_5c, 0x5c);

// 0x7100552840
u32 Unk_552840_get(const Unk_552840* self) {
    return self->field_5c;
}
