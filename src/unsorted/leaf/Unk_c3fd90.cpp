// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c3fd90 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_c3fd90, field_60, 0x60);

// 0x7100c3fd90
u64 Unk_c3fd90_getField60(const Unk_c3fd90* self) {
    return self->field_60;
}

struct Unk_c3fda0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_c3fda0, field_6c, 0x6c);

// 0x7100c3fda0
void Unk_c3fda0_setField6c(Unk_c3fda0* self, u32 value) {
    self->field_6c = value;
}

struct Unk_c41280 {
    u8 _0[0x720];
    u64 field_720;
};
PKMN_OFFSET_ASSERT(Unk_c41280, field_720, 0x720);

// 0x7100c41280
void Unk_c41280_setField720(Unk_c41280* self, u64 value) {
    self->field_720 = value;
}

struct Unk_c44510_50 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(u64, u32, u64);
};

struct Unk_c44510 {
    u8 _0[0x50];
    Unk_c44510_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_c44510, field_50, 0x50);

// 0x7100c44510
void Unk_c44510_call(const Unk_c44510* self, u64 value, bool arg2, u64 arg3) {
    self->field_50->vf13(value, arg2, arg3);
}

// 0x7100c471d0
void Unk_c471d0_update() {}

struct Unk_c471e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c471e0_arg1, field_0, 0x0);

struct Unk_c471e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c471e0, field_0, 0x0);

// 0x7100c471e0
void Unk_c471e0_set(const Unk_c471e0* self, Unk_c471e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c471f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c471f0_arg1, field_0, 0x0);

struct Unk_c471f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c471f0, field_0, 0x0);

// 0x7100c471f0
void Unk_c471f0_set(const Unk_c471f0* self, Unk_c471f0_arg1* value) {
    value->field_0 = self->field_0;
}
