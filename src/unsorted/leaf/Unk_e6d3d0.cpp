// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e6d3d0
void Unk_e6d3d0() {}

struct Unk_e6d490 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e6d490, field_18, 0x18);

void Unk_ec6220(u64);

// 0x7100e6d490
void Unk_e6d490_call(const Unk_e6d490* self) {
    Unk_ec6220(self->field_18);
}

struct Unk_e6da00 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e6da00, field_18, 0x18);

void Unk_e6e330(u64);

// 0x7100e6da00
void Unk_e6da00_call(const Unk_e6da00* self) {
    if (self->field_18 != 0) {
        Unk_e6e330(self->field_18);
    }
}

// 0x7100e6da10
u32 Unk_e6da10_get() {
    return 1;
}

struct Unk_e6e3d0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_e6e3d0, field_5cc, 0x5cc);

// 0x7100e6e3d0
bool Unk_e6e3d0_check(const Unk_e6e3d0* self) {
    return self->field_5cc == 0;
}

// 0x7100e6e820
void Unk_e6e820() {}

struct Unk_e6e8b0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_e6e8b0, field_10, 0x10);

void Unk_ec6b00(u64);

// 0x7100e6e8b0
void Unk_e6e8b0_call(const Unk_e6e8b0* self) {
    Unk_ec6b00(self->field_10);
}

struct Unk_e6e8c0 {
    u8 _0[0x10];
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_e6e8c0, field_10, 0x10);

void Unk_ec6e20_call(void*);

// 0x7100e6e8c0
void Unk_e6e8c0_call(const Unk_e6e8c0* self) {
    Unk_ec6e20_call(self->field_10);
}

struct Unk_ec6e30;
struct Unk_e6e8d0 {
    u8 _0[0x10];
    Unk_ec6e30* field_10;
};
PKMN_OFFSET_ASSERT(Unk_e6e8d0, field_10, 0x10);

u32 Unk_ec6e30_get(const Unk_ec6e30*);

// 0x7100e6e8d0
void Unk_e6e8d0_call(const Unk_e6e8d0* self) {
    Unk_ec6e30_get(self->field_10);
}

// 0x7100e6f180
u32 Unk_e6f180_get() {
    return 1;
}

struct Unk_e6fe80 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e6fe80, field_18, 0x18);

void Unk_e70bf0(u64);

// 0x7100e6fe80
void Unk_e6fe80_call(const Unk_e6fe80* self) {
    Unk_e70bf0(self->field_18);
}

struct Unk_e6fe90 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e6fe90, field_18, 0x18);

void Unk_e70c10(u64);

// 0x7100e6fe90
void Unk_e6fe90_call(const Unk_e6fe90* self) {
    Unk_e70c10(self->field_18);
}
