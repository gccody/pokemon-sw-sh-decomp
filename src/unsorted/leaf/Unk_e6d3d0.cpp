// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e6d3d0
void Unk_e6d3d0() {}

struct Unk_e6d3e0 {
    u8 _0[0x23];
    u8 field_23;
};
PKMN_OFFSET_ASSERT(Unk_e6d3e0, field_23, 0x23);

// 0x7100e6d3e0
u32 Unk_e6d3e0_get(Unk_e6d3e0* self) {
    if (self->field_23 != 0) {
        self->field_23 = 0;
    }
    return 1;
}

struct Unk_e6d480 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e6d480, field_18, 0x18);

void Unk_ec6070(u64);
void Unk_ec5ec0(u64);

// 0x7100e6d480
void Unk_e6d480_call(const Unk_e6d480* self, bool value) {
    if ((value) != 0) {
        Unk_ec5ec0(self->field_18);
        return;
    }
    Unk_ec6070(self->field_18);
}

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

// 0x7100e6e660
void Unk_e6e660_update() {}

struct Unk_e6e670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e6e670_arg1, field_0, 0x0);

struct Unk_e6e670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e6e670, field_0, 0x0);

// 0x7100e6e670
void Unk_e6e670_set(const Unk_e6e670* self, Unk_e6e670_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e6e680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e6e680_arg1, field_0, 0x0);

struct Unk_e6e680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e6e680, field_0, 0x0);

// 0x7100e6e680
void Unk_e6e680_set(const Unk_e6e680* self, Unk_e6e680_arg1* value) {
    value->field_0 = self->field_0;
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

// 0x7100e6f400
void Unk_e6f400_update() {}

// 0x7100e6f410
void Unk_e6f410_update() {}

// 0x7100e6f420
void Unk_e6f420_update() {}

// 0x7100e6f5e0
void Unk_e6f5e0_update() {}

// 0x7100e6f5f0
void Unk_e6f5f0_update() {}

// 0x7100e6f600
void Unk_e6f600_update() {}

// 0x7100e6f7c0
void Unk_e6f7c0_update() {}

// 0x7100e6f7d0
void Unk_e6f7d0_update() {}

// 0x7100e6f7e0
void Unk_e6f7e0_update() {}

struct Unk_e6fcc0 {
    u8 _0[0x18];
    u64 field_18;
    u8 _20[0x18];
    u64 field_38;
    u8 _40[0x18];
    u64 field_58;
    u8 _60[0x18];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e6fcc0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_e6fcc0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_e6fcc0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_e6fcc0, field_78, 0x78);

void Unk_e70bf0(u64);

// 0x7100e6fcc0
void Unk_e6fcc0_call(const Unk_e6fcc0* self) {
    Unk_e70bf0(self->field_18);
    Unk_e70bf0(self->field_38);
    Unk_e70bf0(self->field_58);
    Unk_e70bf0(self->field_78);
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
