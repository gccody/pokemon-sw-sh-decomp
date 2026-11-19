// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24bbbc8;
extern u64 Unk_24bbbd0;
void Unk_3b53c0(u64, void*);
void Unk_3bb8e0(u64, void*);

// 0x71003b78c0
void Unk_3b78c0_call(void* self) {
    Unk_3bb8e0(Unk_24bbbc8, self);
    Unk_3b53c0(Unk_24bbbd0, self);
}

extern u64 Unk_24bbbc8;
extern u64 Unk_24bbbd0;
void Unk_3bbe70(u64, u32, u64);
void Unk_3b5280(u64, u32);

// 0x71003b79c0
void Unk_3b79c0_call(void* /*unused*/, u64 value, u32 arg2, u32 arg3) {
    if (arg3 == 1) {
        Unk_3b5280(Unk_24bbbd0, arg2);
        return;
    }
    Unk_3bbe70(Unk_24bbbc8, arg2, value);
}

extern u64 Unk_24bbbd0;
u64 Unk_3b54e0(u64);

// 0x71003baa80
u64 Unk_3baa80_call() {
    u64 r0 = Unk_3b54e0(Unk_24bbbd0);
    return r0 == 0 ? 0 : (r0 + 8);
}

struct Unk_3babc0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    u64 field_18;
    u64 field_20;
    u32 field_28;
    u8 _2c[0x4];
    u64 field_30;
    u64 field_38;
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_3babc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_3babc0, field_40, 0x40);

// 0x71003babc0
void Unk_3babc0_set(Unk_3babc0* self) {
    self->field_10 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_28 = 0;
    self->field_40 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
}

// 0x71003babe0
void Unk_3babe0_update(u64 /*unused*/) {
}

struct Unk_3bd6b0 {
    u64 field_0;
    u8 _8[0x18];
    u32 field_20;
    u8 _24[0x4];
    u64 field_28;
    u64 field_30;
    u8 _38[0x4];
    u32 field_3c;
    u8 field_40;
    u8 _41[0x3];
    u32 field_44;
};
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_3c, 0x3c);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_44, 0x44);

// 0x71003bd6b0
void Unk_3bd6b0_set(Unk_3bd6b0* self) {
    self->field_0 = 0x20000000;
    self->field_28 = 0;
    self->field_30 = 0;
    self->field_3c = 0;
    self->field_20 = 0;
    self->field_44 = 0;
    self->field_40 = self->field_40 & 0xfc;
}

// 0x71003bd6e0
void Unk_3bd6e0_update(u64 /*unused*/) {
}

struct Unk_3bd790 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3bd790, field_0, 0x0);

// 0x71003bd790
u32 Unk_3bd790_get(const Unk_3bd790* self) {
    return (self->field_0 == 0x4000000) | (self->field_0 == 0x2000000);
}

struct Unk_3be190_arg1 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_3be190_arg1, field_3c, 0x3c);

// 0x71003be190
bool Unk_3be190_check(void* /*unused*/, const Unk_3be190_arg1* value) {
    return value->field_3c == 5;
}

extern u32 Unk_24df0e8;

// 0x71003bf640
void Unk_3bf640_set() {
    Unk_24df0e8 = Unk_24df0e8 - 1;
}

extern u32 Unk_24df0ec;

// 0x71003bf660
void Unk_3bf660_set() {
    Unk_24df0ec = Unk_24df0ec + 1;
}

extern u32 Unk_24df0ec;

// 0x71003bf680
void Unk_3bf680_set() {
    Unk_24df0ec = Unk_24df0ec - 1;
}
