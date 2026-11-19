// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

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

struct Unk_37aa50 {
    u8 _0[0x125];
    u8 field_125;
};
PKMN_OFFSET_ASSERT(Unk_37aa50, field_125, 0x125);

class Unk_2381cf0 {
public:
    u64 vf3();
    void vf5(u32 /*unused*/, Unk_37a9e0_arg2* arg2, Unk_37a9e0_arg3* arg3);
    void vf6(Unk_37a9f0_arg1* value, Unk_37a9f0_arg2* arg2);
    u32 vf7();
    u32 vf8();
    u32 vf9();
    u8 vf12();
};

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

// 0x710037aa50
u8 Unk_2381cf0::vf12() {
    const Unk_37aa50* self = reinterpret_cast<const Unk_37aa50*>(this);
    return self->field_125;
}

// 0x710037df40
u64 Unk_2381cf0::vf3() {
    return 0;
}
