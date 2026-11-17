// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12ffd80 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12ffd80, field_8, 0x8);

// 0x71012ffd80
u32 Unk_12ffd80_getField8(const Unk_12ffd80* self) {
    return self->field_8;
}

struct Unk_1305db0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1305db0, field_58, 0x58);

// 0x7101305db0
u64 Unk_1305db0_getField58(const Unk_1305db0* self) {
    return self->field_58;
}

void Unk_1306cf0();

// 0x7101306ce0
void Unk_1306ce0_call() {
    Unk_1306cf0();
}

struct Unk_13077f0 {
    u8 _0[0xaf8];
    u32 field_af8;
};
PKMN_OFFSET_ASSERT(Unk_13077f0, field_af8, 0xaf8);

// 0x71013077f0
bool Unk_13077f0_check(const Unk_13077f0* self, u32 value) {
    return ((self->field_af8 == 3) | value) != 1;
}

void Unk_1307de0(void*, u64, u32, u32);

// 0x7101307dd0
void Unk_1307dd0_call(void* self, u64 value, bool arg2) {
    Unk_1307de0(self, value, 0xa, arg2);
}

struct Unk_13091c0 {
    u8 _0[0x20];
    u8 field_20;
    u8 _21[0xf];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_13091c0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_13091c0, field_30, 0x30);

// 0x71013091c0
void Unk_13091c0_set(Unk_13091c0* self) {
    self->field_30 = 0;
    self->field_20 = 0;
}

struct Unk_1309a60 {
    u8 _0[0x178];
    bool field_178;
};
PKMN_OFFSET_ASSERT(Unk_1309a60, field_178, 0x178);

// 0x7101309a60
void Unk_1309a60_set(Unk_1309a60* self, bool value) {
    self->field_178 = value;
}

struct Unk_1309a70 {
    u8 _0[0x179];
    bool field_179;
};
PKMN_OFFSET_ASSERT(Unk_1309a70, field_179, 0x179);

// 0x7101309a70
void Unk_1309a70_set(Unk_1309a70* self, bool value) {
    self->field_179 = value;
}

struct Unk_1309a80 {
    u8 _0[0x17a];
    u8 field_17a;
};
PKMN_OFFSET_ASSERT(Unk_1309a80, field_17a, 0x17a);

// 0x7101309a80
void Unk_1309a80_set(Unk_1309a80* self) {
    self->field_17a = 1;
}

// 0x710130abe0
void Unk_130abe0() {}

void Unk_67c4e0();

// 0x710130ac20
void Unk_130ac20_call() {
    Unk_67c4e0();
}

void Unk_130adb0(void*, u64, u64, u32, u32);

// 0x710130ada0
void Unk_130ada0_call(void* self, u64 value, u32 arg2, u32 arg3) {
    Unk_130adb0(self, value, 0, arg2, arg3);
}
