// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x710141be00
void Unk_141be00_call(void* self) {
    Unk_eb6230(self, 2);
}

// 0x710141c3d0
void Unk_141c3d0_update() {}

struct Unk_141c3e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c3e0_arg1, field_0, 0x0);

struct Unk_141c3e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c3e0, field_0, 0x0);

// 0x710141c3e0
void Unk_141c3e0_set(const Unk_141c3e0* self, Unk_141c3e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c3f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c3f0_arg1, field_0, 0x0);

struct Unk_141c3f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c3f0, field_0, 0x0);

// 0x710141c3f0
void Unk_141c3f0_set(const Unk_141c3f0* self, Unk_141c3f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c400_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x11c];
    u8 field_5e4;
};
PKMN_OFFSET_ASSERT(Unk_141c400_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_141c400_0, field_5e4, 0x5e4);

struct Unk_141c400 {
    Unk_141c400_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c400, field_0, 0x0);

void Unk_1500c40(u64);

// 0x710141c400
void Unk_141c400_call(const Unk_141c400* self) {
    Unk_141c400_0* p0 = self->field_0;
    p0->field_5e4 = 1;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x710141c420
void Unk_141c420_update() {}

struct Unk_141c430_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c430_arg1, field_0, 0x0);

struct Unk_141c430 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c430, field_0, 0x0);

// 0x710141c430
void Unk_141c430_set(const Unk_141c430* self, Unk_141c430_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c440_arg1, field_0, 0x0);

struct Unk_141c440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c440, field_0, 0x0);

// 0x710141c440
void Unk_141c440_set(const Unk_141c440* self, Unk_141c440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c450_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x11c];
    u8 field_5e4;
};
PKMN_OFFSET_ASSERT(Unk_141c450_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_141c450_0, field_5e4, 0x5e4);

struct Unk_141c450 {
    Unk_141c450_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c450, field_0, 0x0);

void Unk_1500c40(u64);

// 0x710141c450
void Unk_141c450_call(const Unk_141c450* self) {
    Unk_141c450_0* p0 = self->field_0;
    p0->field_5e4 = 0;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x710141c470
void Unk_141c470_update() {}

struct Unk_141c480_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c480_arg1, field_0, 0x0);

struct Unk_141c480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c480, field_0, 0x0);

// 0x710141c480
void Unk_141c480_set(const Unk_141c480* self, Unk_141c480_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c490_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c490_arg1, field_0, 0x0);

struct Unk_141c490 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c490, field_0, 0x0);

// 0x710141c490
void Unk_141c490_set(const Unk_141c490* self, Unk_141c490_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710141c4b0
void Unk_141c4b0_update() {}

struct Unk_141c4c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c4c0_arg1, field_0, 0x0);

struct Unk_141c4c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c4c0, field_0, 0x0);

// 0x710141c4c0
void Unk_141c4c0_set(const Unk_141c4c0* self, Unk_141c4c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c4d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c4d0_arg1, field_0, 0x0);

struct Unk_141c4d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c4d0, field_0, 0x0);

// 0x710141c4d0
void Unk_141c4d0_set(const Unk_141c4d0* self, Unk_141c4d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710141c4f0
void Unk_141c4f0_update() {}

struct Unk_141c500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c500_arg1, field_0, 0x0);

struct Unk_141c500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c500, field_0, 0x0);

// 0x710141c500
void Unk_141c500_set(const Unk_141c500* self, Unk_141c500_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c510_arg1, field_0, 0x0);

struct Unk_141c510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c510, field_0, 0x0);

// 0x710141c510
void Unk_141c510_set(const Unk_141c510* self, Unk_141c510_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710141c530
void Unk_141c530_update() {}

struct Unk_141c540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c540_arg1, field_0, 0x0);

struct Unk_141c540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c540, field_0, 0x0);

// 0x710141c540
void Unk_141c540_set(const Unk_141c540* self, Unk_141c540_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c550_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c550_arg1, field_0, 0x0);

struct Unk_141c550 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c550, field_0, 0x0);

// 0x710141c550
void Unk_141c550_set(const Unk_141c550* self, Unk_141c550_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710141c570
void Unk_141c570_update() {}

struct Unk_141c580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c580_arg1, field_0, 0x0);

struct Unk_141c580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c580, field_0, 0x0);

// 0x710141c580
void Unk_141c580_set(const Unk_141c580* self, Unk_141c580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141c590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c590_arg1, field_0, 0x0);

struct Unk_141c590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141c590, field_0, 0x0);

// 0x710141c590
void Unk_141c590_set(const Unk_141c590* self, Unk_141c590_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710141ebf0
void Unk_141ebf0_update() {}

struct Unk_141ec00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141ec00_arg1, field_0, 0x0);

struct Unk_141ec00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141ec00, field_0, 0x0);

// 0x710141ec00
void Unk_141ec00_set(const Unk_141ec00* self, Unk_141ec00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_141ec10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141ec10_arg1, field_0, 0x0);

struct Unk_141ec10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_141ec10, field_0, 0x0);

// 0x710141ec10
void Unk_141ec10_set(const Unk_141ec10* self, Unk_141ec10_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710141ee20
void Unk_141ee20_update() {}

struct Unk_141ee30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_141ee30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_141ee30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_141ee30, field_10, 0x10);

// 0x710141ee30
void Unk_141ee30_set(const Unk_141ee30* self, Unk_141ee30* value) {
    *value = *self;
}

struct Unk_141ee50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_141ee50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_141ee50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_141ee50, field_10, 0x10);

// 0x710141ee50
void Unk_141ee50_set(const Unk_141ee50* self, Unk_141ee50* value) {
    *value = *self;
}

struct Unk_14249a0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14249a0, field_68, 0x68);

// 0x71014249a0
u64 Unk_14249a0_getField68(const Unk_14249a0* self) {
    return self->field_68;
}

struct Unk_14249b0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_14249b0, field_b0, 0xb0);

// 0x71014249b0
u64 Unk_14249b0_getFieldb0(const Unk_14249b0* self) {
    return self->field_b0;
}

struct Unk_14249c0 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_14249c0, field_c0, 0xc0);

// 0x71014249c0
u8* Unk_14249c0_getFieldc0Ptr(Unk_14249c0* self) {
    return &self->field_c0;
}

struct Unk_142a1b0 {
    u8 _0[0x74];
    u8 field_74;
};
PKMN_OFFSET_ASSERT(Unk_142a1b0, field_74, 0x74);

// 0x710142a1b0
void Unk_142a1b0_set(Unk_142a1b0* self) {
    self->field_74 = 1;
}
