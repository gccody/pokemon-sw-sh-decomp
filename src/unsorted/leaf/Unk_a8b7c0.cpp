// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100a8b7c0
void Unk_a8b7c0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100a8b7d0
void Unk_a8b7d0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_a8b800 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8b800, field_5cc, 0x5cc);

// 0x7100a8b800
u32 Unk_a8b800_getField5cc(const Unk_a8b800* self) {
    return self->field_5cc;
}

struct Unk_a8b810 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8b810, field_5cc, 0x5cc);

// 0x7100a8b810
void Unk_a8b810_clearField5cc(Unk_a8b810* self) {
    self->field_5cc = 0;
}

void Unk_eb6230(void*, u32);

// 0x7100a8c930
void Unk_a8c930_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100a8c940
void Unk_a8c940_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_a8c970 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8c970, field_5cc, 0x5cc);

// 0x7100a8c970
u32 Unk_a8c970_getField5cc(const Unk_a8c970* self) {
    return self->field_5cc;
}

struct Unk_a8c980 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a8c980, field_5cc, 0x5cc);

// 0x7100a8c980
void Unk_a8c980_clearField5cc(Unk_a8c980* self) {
    self->field_5cc = 0;
}

struct Unk_a8c990 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_a8c990, field_5d0, 0x5d0);

// 0x7100a8c990
void Unk_a8c990_setField5d0(Unk_a8c990* self, u64 value) {
    self->field_5d0 = value;
}

struct Unk_a94040 {
    u8 _0[0x614];
    u32 field_614;
};
PKMN_OFFSET_ASSERT(Unk_a94040, field_614, 0x614);

// 0x7100a94040
u32 Unk_a94040_getField614(const Unk_a94040* self) {
    return self->field_614;
}

void Unk_eb6230(void*, u32);

// 0x7100a96ad0
void Unk_a96ad0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100a96ae0
void Unk_a96ae0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_a96b10 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_a96b10, field_4c0, 0x4c0);

void Unk_1500c40(u64);

// 0x7100a96b10
void Unk_a96b10_call(const Unk_a96b10* self) {
    if (self->field_4c0 != 0) {
        Unk_1500c40(self->field_4c0);
    }
}

struct Unk_a96b20 {
    u8 _0[0x608];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_a96b20, field_608, 0x608);

// 0x7100a96b20
u32 Unk_a96b20_getField608(const Unk_a96b20* self) {
    return self->field_608;
}

struct Unk_a96b30 {
    u8 _0[0x608];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_a96b30, field_608, 0x608);

// 0x7100a96b30
void Unk_a96b30_clearField608(Unk_a96b30* self) {
    self->field_608 = 0;
}

struct Unk_a96b40 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_a96b40, field_5cc, 0x5cc);

// 0x7100a96b40
void Unk_a96b40_setField5cc(Unk_a96b40* self, u32 value) {
    self->field_5cc = value;
}

struct Unk_a96bb0 {
    u8 _0[0x5d0];
    u64 field_5d0;
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_a96bb0, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_a96bb0, field_5d8, 0x5d8);

// 0x7100a96bb0
void Unk_a96bb0_set(Unk_a96bb0* self, u64 value, u64 arg2) {
    self->field_5d0 = value;
    self->field_5d8 = arg2;
}

struct Unk_a96bc0 {
    u8 _0[0x6dc];
    u32 field_6dc;
};
PKMN_OFFSET_ASSERT(Unk_a96bc0, field_6dc, 0x6dc);

// 0x7100a96bc0
void Unk_a96bc0_setField6dc(Unk_a96bc0* self, u32 value) {
    self->field_6dc = value;
}

struct Unk_a96bd0 {
    u8 _0[0x618];
    u32 field_618;
};
PKMN_OFFSET_ASSERT(Unk_a96bd0, field_618, 0x618);

// 0x7100a96bd0
void Unk_a96bd0_setField618(Unk_a96bd0* self, u32 value) {
    self->field_618 = value;
}

struct Unk_a96be0 {
    u8 _0[0x618];
    u32 field_618;
};
PKMN_OFFSET_ASSERT(Unk_a96be0, field_618, 0x618);

// 0x7100a96be0
u32 Unk_a96be0_getField618(const Unk_a96be0* self) {
    return self->field_618;
}

struct Unk_a97440 {
    u8 _0[0x614];
    u32 field_614;
};
PKMN_OFFSET_ASSERT(Unk_a97440, field_614, 0x614);

// 0x7100a97440
void Unk_a97440_setField614(Unk_a97440* self, u32 value) {
    self->field_614 = value;
}

struct Unk_aa0b40 {
    u8 _0[0x6d8];
    u16 field_6d8;
    u16 field_6da;
};
PKMN_OFFSET_ASSERT(Unk_aa0b40, field_6d8, 0x6d8);
PKMN_OFFSET_ASSERT(Unk_aa0b40, field_6da, 0x6da);

// 0x7100aa0b40
bool Unk_aa0b40_check(const Unk_aa0b40* self) {
    return self->field_6da == self->field_6d8;
}

struct Unk_aa4660 {
    u8 _0[0x681];
    u8 field_681;
};
PKMN_OFFSET_ASSERT(Unk_aa4660, field_681, 0x681);

// 0x7100aa4660
u8 Unk_aa4660_getField681(const Unk_aa4660* self) {
    return self->field_681;
}

struct Unk_aa4670 {
    u8 _0[0x684];
    u32 field_684;
};
PKMN_OFFSET_ASSERT(Unk_aa4670, field_684, 0x684);

// 0x7100aa4670
u32 Unk_aa4670_getField684(const Unk_aa4670* self) {
    return self->field_684;
}

struct Unk_aa5440 {
    u8 _0[0x688];
    u32 field_688;
};
PKMN_OFFSET_ASSERT(Unk_aa5440, field_688, 0x688);

// 0x7100aa5440
u32 Unk_aa5440_getField688(const Unk_aa5440* self) {
    return self->field_688;
}

struct Unk_aa6650 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_aa6650, field_68c, 0x68c);

// 0x7100aa6650
bool Unk_aa6650_check(const Unk_aa6650* self) {
    return self->field_68c != 1;
}

struct Unk_aa75b0 {
    u8 _0[0x68c];
    u32 field_68c;
};
PKMN_OFFSET_ASSERT(Unk_aa75b0, field_68c, 0x68c);

// 0x7100aa75b0
bool Unk_aa75b0_check(const Unk_aa75b0* self) {
    return self->field_68c == 2;
}

struct Unk_aa89f0 {
    u8 _0[0x5f0];
    u64 field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_aa89f0, field_5f0, 0x5f0);

void Unk_ab18f0(u64, u32);

// 0x7100aa89f0
void Unk_aa89f0_call(const Unk_aa89f0* self) {
    Unk_ab18f0(self->field_5f0, 0);
}

struct Unk_aaa310 {
    u8 _0[0x6da];
    u16 field_6da;
};
PKMN_OFFSET_ASSERT(Unk_aaa310, field_6da, 0x6da);

// 0x7100aaa310
u16 Unk_aaa310_getField6da(const Unk_aaa310* self) {
    return self->field_6da;
}

struct Unk_aab1a0 {
    u8 _0[0x680];
    u8 field_680;
};
PKMN_OFFSET_ASSERT(Unk_aab1a0, field_680, 0x680);

// 0x7100aab1a0
u8 Unk_aab1a0_getField680(const Unk_aab1a0* self) {
    return self->field_680;
}

struct Unk_aab1b0 {
    u8 _0[0x620];
    u8 field_620;
};
PKMN_OFFSET_ASSERT(Unk_aab1b0, field_620, 0x620);

// 0x7100aab1b0
u8 Unk_aab1b0_getField620(const Unk_aab1b0* self) {
    return self->field_620;
}

struct Unk_aab2c0 {
    u8 _0[0x6f8];
    bool field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_aab2c0, field_6f8, 0x6f8);

// 0x7100aab2c0
void Unk_aab2c0_set(Unk_aab2c0* self, bool value) {
    self->field_6f8 = value;
}

struct Unk_aab8b0 {
    u8 _0[0x60c];
    u8 field_60c;
};
PKMN_OFFSET_ASSERT(Unk_aab8b0, field_60c, 0x60c);

// 0x7100aab8b0
u8 Unk_aab8b0_getField60c(const Unk_aab8b0* self) {
    return self->field_60c;
}
