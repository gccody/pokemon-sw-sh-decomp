// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ed29e0_148 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed29e0_148, field_148, 0x148);

struct Unk_ed29e0 {
    u8 _0[0x148];
    Unk_ed29e0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed29e0, field_148, 0x148);

// 0x7100ed29e0
u64 Unk_ed29e0_get(const Unk_ed29e0* self) {
    return self->field_148->field_148;
}

struct Unk_ed2f20_148 {
    u8 _0[0xe0];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_ed2f20_148, field_e0, 0xe0);

struct Unk_ed2f20 {
    u8 _0[0x148];
    Unk_ed2f20_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed2f20, field_148, 0x148);

// 0x7100ed2f20
u32 Unk_ed2f20_get(const Unk_ed2f20* self) {
    return self->field_148->field_e0;
}

struct Unk_ed2f30_148 {
    u8 _0[0xec];
    u8 field_ec;
};
PKMN_OFFSET_ASSERT(Unk_ed2f30_148, field_ec, 0xec);

struct Unk_ed2f30 {
    u8 _0[0x148];
    Unk_ed2f30_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed2f30, field_148, 0x148);

// 0x7100ed2f30
u8 Unk_ed2f30_get(const Unk_ed2f30* self) {
    return self->field_148->field_ec;
}

struct Unk_ed30a0_148 {
    u8 _0[0x151];
    bool field_151;
};
PKMN_OFFSET_ASSERT(Unk_ed30a0_148, field_151, 0x151);

struct Unk_ed30a0 {
    u8 _0[0x148];
    Unk_ed30a0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed30a0, field_148, 0x148);

// 0x7100ed30a0
void Unk_ed30a0_set(const Unk_ed30a0* self, bool value) {
    self->field_148->field_151 = value;
}

struct Unk_ed30b0_148 {
    u8 _0[0x180];
    bool field_180;
};
PKMN_OFFSET_ASSERT(Unk_ed30b0_148, field_180, 0x180);

struct Unk_ed30b0 {
    u8 _0[0x148];
    Unk_ed30b0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed30b0, field_148, 0x148);

// 0x7100ed30b0
void Unk_ed30b0_set(const Unk_ed30b0* self, bool value) {
    self->field_148->field_180 = value;
}

struct Unk_ed30c0_148 {
    u8 _0[0x180];
    u8 field_180;
};
PKMN_OFFSET_ASSERT(Unk_ed30c0_148, field_180, 0x180);

struct Unk_ed30c0 {
    u8 _0[0x148];
    Unk_ed30c0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed30c0, field_148, 0x148);

// 0x7100ed30c0
u8 Unk_ed30c0_get(const Unk_ed30c0* self) {
    return self->field_148->field_180;
}

struct Unk_ed3120_150 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ed3120_150, field_78, 0x78);

struct Unk_ed3120 {
    u8 _0[0x150];
    Unk_ed3120_150* field_150;
};
PKMN_OFFSET_ASSERT(Unk_ed3120, field_150, 0x150);

// 0x7100ed3120
bool Unk_ed3120_check(const Unk_ed3120* self) {
    return self->field_150->field_78 == 0xffffffff;
}

struct Unk_ed3e40_148 {
    u8 _0[0x294];
    bool field_294;
};
PKMN_OFFSET_ASSERT(Unk_ed3e40_148, field_294, 0x294);

struct Unk_ed3e40 {
    u8 _0[0x148];
    Unk_ed3e40_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3e40, field_148, 0x148);

// 0x7100ed3e40
void Unk_ed3e40_set(const Unk_ed3e40* self, bool value) {
    self->field_148->field_294 = value;
}

struct Unk_ed3e50_148 {
    u8 _0[0x294];
    u8 field_294;
};
PKMN_OFFSET_ASSERT(Unk_ed3e50_148, field_294, 0x294);

struct Unk_ed3e50 {
    u8 _0[0x148];
    Unk_ed3e50_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3e50, field_148, 0x148);

// 0x7100ed3e50
u8 Unk_ed3e50_get(const Unk_ed3e50* self) {
    return self->field_148->field_294;
}
