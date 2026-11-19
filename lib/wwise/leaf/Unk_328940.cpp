// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_328940_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64);
};

struct Unk_328940 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_328940, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_328940, field_8, 0x8);

// 0x7100328940
void Unk_328940_set(Unk_328940* self, Unk_328940_arg1* value) {
    if (self->field_8 != 0) {
        value->vf3(self->field_8);
        self->field_8 = 0;
    }
    self->field_0 = 0;
}

void Unk_3291d0(void*, u64, u32, u64);

// 0x71003291c0
void Unk_3291c0_call(void* self, u64 value, u64 arg2, u32 arg3) {
    Unk_3291d0(self, value, arg3, arg2);
}

void Unk_3296c0(void*, u64, u32, u64, u64);

// 0x71003296a0
void Unk_3296a0_call(void* self, u64 value, u64 arg2, u64 arg3, u32 arg4) {
    Unk_3296c0(self, value, arg4, arg2, arg3);
}

struct Unk_32ac10_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64);
};

struct Unk_32ac10 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_32ac10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_32ac10, field_8, 0x8);

// 0x710032ac10
void Unk_32ac10_set(Unk_32ac10* self, Unk_32ac10_arg1* value) {
    if (self->field_8 != 0) {
        value->vf3(self->field_8);
        self->field_8 = 0;
    }
    self->field_0 = 0;
}

struct Unk_32b100_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64);
};

struct Unk_32b100 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_32b100, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_32b100, field_8, 0x8);

// 0x710032b100
void Unk_32b100_set(Unk_32b100* self, Unk_32b100_arg1* value) {
    if (self->field_8 != 0) {
        value->vf3(self->field_8);
        self->field_8 = 0;
    }
    self->field_0 = 0;
}
