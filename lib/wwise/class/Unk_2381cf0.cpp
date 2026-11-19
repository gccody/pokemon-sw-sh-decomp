// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_37a9c0_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37a9c0_arg2, field_0, 0x0);

struct Unk_37a9c0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37a9c0_arg1, field_0, 0x0);

struct Unk_37a9c0 {
    u8 _0[0x14];
    u32 field_14;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_37a9c0, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_37a9c0, field_18, 0x18);

struct Unk_37a9e0_arg2 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37a9e0_arg2, field_0, 0x0);

struct Unk_37a9e0_arg3 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37a9e0_arg3, field_0, 0x0);

struct Unk_37a9f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37a9f0_arg1, field_0, 0x0);

struct Unk_37a9f0_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37a9f0_arg2, field_0, 0x0);

struct Unk_37aa40_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_37aa40_arg1, field_0, 0x0);

struct Unk_37aa40 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_37aa40, field_3c, 0x3c);

struct Unk_37aa50 {
    u8 _0[0x125];
    u8 field_125;
};
PKMN_OFFSET_ASSERT(Unk_37aa50, field_125, 0x125);

class Unk_2381cf0 {
public:
    u64 vf3();
    u32 vf4(Unk_37a9c0_arg1* value, Unk_37a9c0_arg2* arg2);
    void vf5(u32 /*unused*/, Unk_37a9e0_arg2* arg2, Unk_37a9e0_arg3* arg3);
    void vf6(Unk_37a9f0_arg1* value, Unk_37a9f0_arg2* arg2);
    u32 vf7();
    u32 vf8();
    u32 vf9();
    u32 vf11(Unk_37aa40_arg1* value);
    u8 vf12();
};

// 0x710037a9c0
u32 Unk_2381cf0::vf4(Unk_37a9c0_arg1* value, Unk_37a9c0_arg2* arg2) {
    const Unk_37a9c0* self = reinterpret_cast<const Unk_37a9c0*>(this);
    arg2->field_0 = self->field_18;
    value->field_0 = self->field_14;
    return 1;
}

// 0x710037a9e0
void Unk_2381cf0::vf5(u32 /*unused*/, Unk_37a9e0_arg2* arg2, Unk_37a9e0_arg3* arg3) {
    arg2->field_0 = 0;
    arg3->field_0 = 0;
}

// 0x710037a9f0
void Unk_2381cf0::vf6(Unk_37a9f0_arg1* value, Unk_37a9f0_arg2* arg2) {
    value->field_0 = 0;
    arg2->field_0 = 0;
}

// 0x710037aa00
u32 Unk_2381cf0::vf7() {
    return 2;
}

// 0x710037aa10
u32 Unk_2381cf0::vf8() {
    return 0;
}

// 0x710037aa20
u32 Unk_2381cf0::vf9() {
    return 2;
}

// 0x710037aa40
u32 Unk_2381cf0::vf11(Unk_37aa40_arg1* value) {
    const Unk_37aa40* self = reinterpret_cast<const Unk_37aa40*>(this);
    value->field_0 = self->field_3c;
    return 1;
}

// 0x710037aa50
u8 Unk_2381cf0::vf12() {
    const Unk_37aa50* self = reinterpret_cast<const Unk_37aa50*>(this);
    return self->field_125;
}

// 0x710037df40
u64 Unk_2381cf0::vf3() {
    return 0;
}
