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

struct Unk_ed30f0 {
    u8 _0[0x150];
    u64 field_150;
};
PKMN_OFFSET_ASSERT(Unk_ed30f0, field_150, 0x150);

void Unk_5e1110(u64);

// 0x7100ed30f0
void Unk_ed30f0_call(const Unk_ed30f0* self) {
    Unk_5e1110(self->field_150);
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

struct Unk_ed32f0 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed32f0, field_148, 0x148);

void Unk_ed3300(u64, u32);

// 0x7100ed32f0
void Unk_ed32f0_call(const Unk_ed32f0* self, bool value) {
    Unk_ed3300(self->field_148, value);
}

struct Unk_ed3380_148_188 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ed3380_148_188, field_78, 0x78);

struct Unk_ed3380_148 {
    u8 _0[0x188];
    Unk_ed3380_148_188* field_188;
};
PKMN_OFFSET_ASSERT(Unk_ed3380_148, field_188, 0x188);

struct Unk_ed3380 {
    u8 _0[0x148];
    Unk_ed3380_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3380, field_148, 0x148);

// 0x7100ed3380
bool Unk_ed3380_check(const Unk_ed3380* self) {
    if (self->field_148->field_188 == nullptr) {
        return false;
    }
    return self->field_148->field_188->field_78 == 0xffffffff;
}

struct Unk_ed33d0 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed33d0, field_148, 0x148);

void Unk_ed33e0(u64);

// 0x7100ed33d0
void Unk_ed33d0_call(const Unk_ed33d0* self) {
    Unk_ed33e0(self->field_148);
}

struct Unk_ed3520_148_130 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ed3520_148_130, field_78, 0x78);

struct Unk_ed3520_148 {
    u8 _0[0x130];
    Unk_ed3520_148_130* field_130;
};
PKMN_OFFSET_ASSERT(Unk_ed3520_148, field_130, 0x130);

struct Unk_ed3520 {
    u8 _0[0x148];
    Unk_ed3520_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3520, field_148, 0x148);

// 0x7100ed3520
bool Unk_ed3520_check(const Unk_ed3520* self) {
    if (self->field_148->field_130 == nullptr) {
        return false;
    }
    return self->field_148->field_130->field_78 == 0xffffffff;
}

struct Unk_ed3650 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3650, field_148, 0x148);

void Unk_ed3660(u64);

// 0x7100ed3650
void Unk_ed3650_call(const Unk_ed3650* self) {
    Unk_ed3660(self->field_148);
}

struct Unk_ed3830 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3830, field_148, 0x148);

void Unk_ed3840(u64);

// 0x7100ed3830
void Unk_ed3830_call(const Unk_ed3830* self) {
    Unk_ed3840(self->field_148);
}

struct Unk_ed3920_148 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_ed3920_148, field_108, 0x108);

struct Unk_ed3920 {
    u8 _0[0x148];
    Unk_ed3920_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3920, field_148, 0x148);

void Unk_68c490(u64);

// 0x7100ed3920
void Unk_ed3920_call(const Unk_ed3920* self) {
    Unk_68c490(self->field_148->field_108);
}

struct Unk_ed3930_148 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_ed3930_148, field_108, 0x108);

struct Unk_ed3930 {
    u8 _0[0x148];
    Unk_ed3930_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3930, field_148, 0x148);

void Unk_68c510(u64);

// 0x7100ed3930
void Unk_ed3930_call(const Unk_ed3930* self) {
    Unk_68c510(self->field_148->field_108);
}

struct Unk_ed3ae0 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3ae0, field_148, 0x148);

void Unk_ed3af0(u64);

// 0x7100ed3ae0
void Unk_ed3ae0_call(const Unk_ed3ae0* self) {
    Unk_ed3af0(self->field_148);
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

struct Unk_ede180 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede180, field_78, 0x78);

void Unk_edb0b0(u64, u64, u64, u64);

// 0x7100ede180
void Unk_ede180_call(const Unk_ede180* self, u64 value, u64 arg2) {
    Unk_edb0b0(self->field_78, value, arg2, 0);
}

struct Unk_ede190 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede190, field_78, 0x78);

void Unk_edb4e0(u64, u64, u64, u64);

// 0x7100ede190
void Unk_ede190_call(const Unk_ede190* self, u64 value, u64 arg2) {
    Unk_edb4e0(self->field_78, value, arg2, 0);
}

struct Unk_ede1a0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1a0, field_78, 0x78);

void Unk_edb910(u64);

// 0x7100ede1a0
void Unk_ede1a0_call(const Unk_ede1a0* self) {
    Unk_edb910(self->field_78);
}

struct Unk_ede1b0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1b0, field_78, 0x78);

void Unk_edb9f0(u64);

// 0x7100ede1b0
void Unk_ede1b0_call(const Unk_ede1b0* self) {
    Unk_edb9f0(self->field_78);
}

struct Unk_ede1c0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1c0, field_78, 0x78);

void Unk_edbad0(u64);

// 0x7100ede1c0
void Unk_ede1c0_call(const Unk_ede1c0* self) {
    Unk_edbad0(self->field_78);
}

struct Unk_ede1d0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1d0, field_78, 0x78);

void Unk_edbbb0(u64);

// 0x7100ede1d0
void Unk_ede1d0_call(const Unk_ede1d0* self) {
    Unk_edbbb0(self->field_78);
}

struct Unk_ede1e0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1e0, field_78, 0x78);

void Unk_edbcc0(u64);

// 0x7100ede1e0
void Unk_ede1e0_call(const Unk_ede1e0* self) {
    Unk_edbcc0(self->field_78);
}

struct Unk_ede1f0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1f0, field_78, 0x78);

void Unk_edbdd0(u64);

// 0x7100ede1f0
void Unk_ede1f0_call(const Unk_ede1f0* self) {
    Unk_edbdd0(self->field_78);
}

struct Unk_ede200 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede200, field_78, 0x78);

void Unk_edc3d0(u64);

// 0x7100ede200
void Unk_ede200_call(const Unk_ede200* self) {
    Unk_edc3d0(self->field_78);
}

struct Unk_ede210 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede210, field_78, 0x78);

void Unk_edc9b0(u64);

// 0x7100ede210
void Unk_ede210_call(const Unk_ede210* self) {
    Unk_edc9b0(self->field_78);
}

struct Unk_ede220 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede220, field_78, 0x78);

void Unk_edcfb0(u64);

// 0x7100ede220
void Unk_ede220_call(const Unk_ede220* self) {
    Unk_edcfb0(self->field_78);
}

struct Unk_ede230 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede230, field_78, 0x78);

void Unk_edd150(u64);

// 0x7100ede230
void Unk_ede230_call(const Unk_ede230* self) {
    Unk_edd150(self->field_78);
}

struct Unk_ede240 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede240, field_78, 0x78);

void Unk_edd2d0(u64);

// 0x7100ede240
void Unk_ede240_call(const Unk_ede240* self) {
    Unk_edd2d0(self->field_78);
}
