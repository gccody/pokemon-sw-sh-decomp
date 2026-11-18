// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4190d0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4190d0, field_40, 0x40);

// 0x71004190d0
bool Unk_4190d0_check(const Unk_4190d0* self) {
    return self->field_40 != 0;
}

struct Unk_423950_arg3 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_423950_arg3, field_0, 0x0);

struct Unk_423950_arg4 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_423950_arg4, field_0, 0x0);

struct Unk_423950_arg5 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_423950_arg5, field_0, 0x0);

struct Unk_423950 {
    u8 _0[0xc30];
    u32 field_c30;
    bool field_c34;
    u8 _c35[0x1];
    bool field_c36;
    u8 _c37[0x1];
    u64 field_c38;
    u64 field_c40;
    u64 field_c48;
};
PKMN_OFFSET_ASSERT(Unk_423950, field_c30, 0xc30);
PKMN_OFFSET_ASSERT(Unk_423950, field_c34, 0xc34);
PKMN_OFFSET_ASSERT(Unk_423950, field_c36, 0xc36);
PKMN_OFFSET_ASSERT(Unk_423950, field_c38, 0xc38);
PKMN_OFFSET_ASSERT(Unk_423950, field_c40, 0xc40);
PKMN_OFFSET_ASSERT(Unk_423950, field_c48, 0xc48);

// 0x7100423950
u32 Unk_423950_update(Unk_423950* self, u32 value, bool arg2, const Unk_423950_arg3* arg3, const Unk_423950_arg4* arg4, const Unk_423950_arg5* arg5, bool arg6) {
    self->field_c30 = value;
    self->field_c34 = arg2;
    self->field_c38 = arg3->field_0;
    self->field_c40 = arg4->field_0;
    self->field_c48 = arg5->field_0;
    self->field_c36 = arg6;
    return 0;
}

struct Unk_423b80 {
    u8 _0[0x198];
    u64 field_198;
};
PKMN_OFFSET_ASSERT(Unk_423b80, field_198, 0x198);

void Unk_4534a0(u64);

// 0x7100423b80
void Unk_423b80_call(const Unk_423b80* self) {
    Unk_4534a0(self->field_198);
}

struct Unk_423b90 {
    u8 _0[0x874];
    u32 field_874;
};
PKMN_OFFSET_ASSERT(Unk_423b90, field_874, 0x874);

// 0x7100423b90
u32 Unk_423b90_update(Unk_423b90* self, u32 value) {
    self->field_874 = value;
    return 0;
}

struct Unk_423da0 {
    u8 _0[0xce8];
    u32 field_ce8;
};
PKMN_OFFSET_ASSERT(Unk_423da0, field_ce8, 0xce8);

// 0x7100423da0
u32 Unk_423da0_update(Unk_423da0* self, u32 value) {
    self->field_ce8 = value;
    return 0;
}

struct Unk_423eb0 {
    u8 _0[0x1c6];
    u8 field_1c6;
    u8 _1c7[0xa09];
    f32 field_bd0;
    f32 field_bd4;
    f32 field_bd8;
};
PKMN_OFFSET_ASSERT(Unk_423eb0, field_1c6, 0x1c6);
PKMN_OFFSET_ASSERT(Unk_423eb0, field_bd0, 0xbd0);
PKMN_OFFSET_ASSERT(Unk_423eb0, field_bd4, 0xbd4);
PKMN_OFFSET_ASSERT(Unk_423eb0, field_bd8, 0xbd8);

// 0x7100423eb0
u32 Unk_423eb0_update(Unk_423eb0* self, f32 fvalue, f32 farg1, f32 farg2) {
    self->field_bd0 = fvalue;
    self->field_bd4 = farg1;
    self->field_bd8 = farg2;
    return self->field_1c6 ^ 1;
}

struct Unk_423ed0 {
    u8 _0[0x70];
    u64 field_70;
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_423ed0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_423ed0, field_78, 0x78);

// 0x7100423ed0
u32 Unk_423ed0_update(Unk_423ed0* self, u64 value, u32 arg2) {
    self->field_70 = value;
    self->field_78 = arg2;
    return 0;
}

struct Unk_424490 {
    u8 _0[0xf80];
    u32 field_f80;
};
PKMN_OFFSET_ASSERT(Unk_424490, field_f80, 0xf80);

// 0x7100424490
u32 Unk_424490_update(Unk_424490* self, u32 value) {
    self->field_f80 = value;
    return 0;
}

struct Unk_427a60 {
    u8 _0[0xbe8];
    f32 field_be8;
    u8 _bec[0x28];
    u32 field_c14;
    f32 field_c18;
};
PKMN_OFFSET_ASSERT(Unk_427a60, field_be8, 0xbe8);
PKMN_OFFSET_ASSERT(Unk_427a60, field_c14, 0xc14);
PKMN_OFFSET_ASSERT(Unk_427a60, field_c18, 0xc18);

// 0x7100427a60
u32 Unk_427a60_update(Unk_427a60* self, f32 fvalue, f32 farg1) {
    self->field_c14 = 0;
    self->field_be8 = fvalue;
    self->field_c18 = farg1;
    return 0;
}

struct Unk_427a80 {
    u8 _0[0xbe8];
    f32 field_be8;
    u8 _bec[0x28];
    u32 field_c14;
    u8 _c18[0x4];
    f32 field_c1c;
    f32 field_c20;
    f32 field_c24;
    f32 field_c28;
};
PKMN_OFFSET_ASSERT(Unk_427a80, field_be8, 0xbe8);
PKMN_OFFSET_ASSERT(Unk_427a80, field_c14, 0xc14);
PKMN_OFFSET_ASSERT(Unk_427a80, field_c1c, 0xc1c);
PKMN_OFFSET_ASSERT(Unk_427a80, field_c20, 0xc20);
PKMN_OFFSET_ASSERT(Unk_427a80, field_c24, 0xc24);
PKMN_OFFSET_ASSERT(Unk_427a80, field_c28, 0xc28);

// 0x7100427a80
u32 Unk_427a80_update(Unk_427a80* self, f32 fvalue, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    self->field_c14 = 2;
    self->field_be8 = fvalue;
    self->field_c1c = farg1;
    self->field_c20 = farg2;
    self->field_c24 = farg3;
    self->field_c28 = farg4;
    return 0;
}

struct Unk_427ab0 {
    u8 _0[0xc04];
    u32 field_c04;
    f32 field_c08;
};
PKMN_OFFSET_ASSERT(Unk_427ab0, field_c04, 0xc04);
PKMN_OFFSET_ASSERT(Unk_427ab0, field_c08, 0xc08);

// 0x7100427ab0
u32 Unk_427ab0_update(Unk_427ab0* self, u32 value, f32 fvalue) {
    self->field_c04 = value;
    self->field_c08 = fvalue;
    return 0;
}

struct Unk_427ac0 {
    u8 _0[0xc0c];
    f32 field_c0c;
    f32 field_c10;
};
PKMN_OFFSET_ASSERT(Unk_427ac0, field_c0c, 0xc0c);
PKMN_OFFSET_ASSERT(Unk_427ac0, field_c10, 0xc10);

// 0x7100427ac0
u32 Unk_427ac0_update(Unk_427ac0* self, f32 fvalue, f32 farg1) {
    self->field_c0c = fvalue;
    self->field_c10 = farg1;
    return 0;
}

struct Unk_43a0e0 {
    u8 _0[0x120];
    u64 field_120;
    u64 field_128;
    u64 field_130;
    u8 _138[0x1030];
    u64 field_1168;
};
PKMN_OFFSET_ASSERT(Unk_43a0e0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_43a0e0, field_128, 0x128);
PKMN_OFFSET_ASSERT(Unk_43a0e0, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_43a0e0, field_1168, 0x1168);

// 0x710043a0e0
u32 Unk_43a0e0_update(Unk_43a0e0* self, u64 value) {
    self->field_1168 = 0;
    self->field_120 = 0;
    self->field_128 = 0;
    self->field_130 = value;
    return 0;
}

struct Unk_43b9b0 {
    u8 _0[0x1200];
    u64 field_1200;
};
PKMN_OFFSET_ASSERT(Unk_43b9b0, field_1200, 0x1200);

// 0x710043b9b0
u32 Unk_43b9b0_update(Unk_43b9b0* self, u64 value) {
    self->field_1200 = value;
    return 0;
}

struct Unk_43b9c0 {
    u8 _0[0x1200];
    u64 field_1200;
};
PKMN_OFFSET_ASSERT(Unk_43b9c0, field_1200, 0x1200);

// 0x710043b9c0
u64 Unk_43b9c0_get(const Unk_43b9c0* self) {
    return self->field_1200;
}
