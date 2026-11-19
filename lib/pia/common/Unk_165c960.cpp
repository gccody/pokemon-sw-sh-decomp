// Scope: common
// The big-endian accessors tools/leafgen.py didn't match (see Unk_165c960.h).
#include "pia/common/Unk_165c960.h"

struct Unk_165c960 {
    u8 field_0[8];
};

struct Unk_165c9a0 {
    u64 field_0;
};

struct Unk_165c9d0 {
    u32 field_0;
};

struct Unk_165c9f0 {
    u16 field_0;
};

// 0x710165c960
void Unk_165c960_set(Unk_165c960* self, u64 value) {
    self->field_0[0] = value >> 56;
    self->field_0[1] = value >> 48;
    self->field_0[2] = value >> 40;
    self->field_0[3] = value >> 32;
    self->field_0[4] = value >> 24;
    self->field_0[5] = value >> 16;
    self->field_0[6] = value >> 8;
    self->field_0[7] = value;
}

// 0x710165c9a0
u64 Unk_165c9a0_get(const Unk_165c9a0* self) {
    return __builtin_bswap64(self->field_0);
}

// 0x710165c9d0
u32 Unk_165c9d0_get(const Unk_165c9d0* self) {
    return __builtin_bswap32(self->field_0);
}

// 0x710165c9f0
u16 Unk_165c9f0_get(const Unk_165c9f0* self) {
    return __builtin_bswap16(self->field_0);
}
