// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f3d7e0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_f3d7e0, field_60, 0x60);

// 0x7100f3d7e0
u64 Unk_f3d7e0_getField60(const Unk_f3d7e0* self) {
    return self->field_60;
}

struct Unk_f3d7f0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_f3d7f0, field_70, 0x70);

// 0x7100f3d7f0
u32 Unk_f3d7f0_getField70(const Unk_f3d7f0* self) {
    return self->field_70;
}

struct Unk_f3d800 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_f3d800, field_6c, 0x6c);

// 0x7100f3d800
void Unk_f3d800_setField6c(Unk_f3d800* self, u32 value) {
    self->field_6c = value;
}

struct Unk_f3d810 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_f3d810, field_70, 0x70);

// 0x7100f3d810
bool Unk_f3d810_check(const Unk_f3d810* self) {
    return self->field_70 == 0;
}

struct Unk_f3db40 {
    u8 _0[0x760];
    u64 field_760;
};
PKMN_OFFSET_ASSERT(Unk_f3db40, field_760, 0x760);

// 0x7100f3db40
void Unk_f3db40_setField760(Unk_f3db40* self, u64 value) {
    self->field_760 = value;
}
