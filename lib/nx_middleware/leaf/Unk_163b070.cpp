// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_163b070_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_163b070_arg1, field_0, 0x0);

void Unk_15ce0f0(u64, u32);

// 0x710163b070
void Unk_163b070_call(void* /*unused*/, const Unk_163b070_arg1* value) {
    Unk_15ce0f0(value->field_0, 3);
}

void Unk_1636d00();

// 0x710163e120
void Unk_163e120_call() {
    Unk_1636d00();
}

struct Unk_163f4a0_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_163f4a0_arg2, field_0, 0x0);

struct Unk_163f4a0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_163f4a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_163f4a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_163f4a0, field_18, 0x18);

// 0x710163f4a0
void Unk_163f4a0_set(Unk_163f4a0* self, u64 value, const Unk_163f4a0_arg2* arg2) {
    self->field_8 = value;
    self->field_10 = arg2->field_0;
    self->field_18 = 1;
}

struct Unk_163f4c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_163f4c0_arg1, field_0, 0x0);

void Unk_163f4d0(u64);

// 0x710163f4c0
void Unk_163f4c0_call(void* /*unused*/, const Unk_163f4c0_arg1* value) {
    Unk_163f4d0(value->field_0);
}

struct Unk_163f860_108 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_163f860_108, field_40, 0x40);

struct Unk_163f860 {
    u8 _0[0x108];
    Unk_163f860_108* field_108;
};
PKMN_OFFSET_ASSERT(Unk_163f860, field_108, 0x108);

// 0x710163f860
bool Unk_163f860_check(const Unk_163f860* self) {
    if (self->field_108 == nullptr) {
        return false;
    }
    return self->field_108->field_40 != 5;
}

struct Unk_163f880_f8 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_163f880_f8, field_40, 0x40);

struct Unk_163f880 {
    u8 _0[0xf8];
    Unk_163f880_f8* field_f8;
};
PKMN_OFFSET_ASSERT(Unk_163f880, field_f8, 0xf8);

// 0x710163f880
bool Unk_163f880_check(const Unk_163f880* self) {
    if (self->field_f8 == nullptr) {
        return false;
    }
    return self->field_f8->field_40 != 5;
}

void Unk_16416a0(void*, u64, u64, u64, u32, u64);

// 0x71016418d0
void Unk_16418d0_call(void* self, u64 value, u64 arg2, u64 arg3, u64 arg4) {
    Unk_16416a0(self, value, arg2, arg3, 0, arg4);
}

void Unk_16416a0(void*, u64, u64, u64, u32, u64);

// 0x71016418e0
void Unk_16418e0_call(void* self, u64 value, u64 arg2, u64 arg3, u64 arg4) {
    Unk_16416a0(self, value, arg2, arg3, 2, arg4);
}

struct Unk_1645560 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1645560, field_0, 0x0);

void Unk_164a700(u64);

// 0x7101645560
void Unk_1645560_call(const Unk_1645560* self) {
    Unk_164a700(self->field_0);
}

void Unk_163ee90();
void Unk_163efb0(void*, u64, u64);

// 0x7101647dc0
void Unk_1647dc0_call(void* self, u64 value, u64 arg2) {
    Unk_163ee90();
    Unk_163efb0(self, value, arg2);
}

struct Unk_1649ad0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1649ad0_arg1, field_0, 0x0);

void Unk_1649ae0(u64, void*);

// 0x7101649ad0
void Unk_1649ad0_call(void* self, const Unk_1649ad0_arg1* value) {
    Unk_1649ae0(value->field_0, self);
}

// 0x710164c190
void Unk_164c190_update() {
}
