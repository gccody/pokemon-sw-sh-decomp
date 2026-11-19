// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3c9ee0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3c9ee0, field_20, 0x20);

struct Unk_3c9df0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3c9df0_arg1, field_0, 0x0);

struct Unk_3c9df0_arg2 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3c9df0_arg2, field_0, 0x0);

struct Unk_3c9ed0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3c9ed0, field_20, 0x20);

class Unk_2383e40 {
public:
    u64 vf3();
    u32 vf4();
    void vf6(Unk_3c9df0_arg1* value, Unk_3c9df0_arg2* arg2);
    u32 vf7();
    u32 vf8();
    u32 vf9();
    u32 vf12();
    u64 vf13();
};

// 0x71003c9ca0
u32 Unk_2383e40::vf12() {
    return 0;
}

// 0x71003c9cb0
u32 Unk_2383e40::vf4() {
    return 4;
}

// 0x71003c9cd0
u32 Unk_2383e40::vf7() {
    return 2;
}

// 0x71003c9ce0
u32 Unk_2383e40::vf8() {
    return 0;
}

// 0x71003c9cf0
u32 Unk_2383e40::vf9() {
    return 2;
}

// 0x71003c9df0
void Unk_2383e40::vf6(Unk_3c9df0_arg1* value, Unk_3c9df0_arg2* arg2) {
    value->field_0 = 0;
    arg2->field_0 = 0;
}

// 0x71003c9ed0
u64 Unk_2383e40::vf13() {
    const Unk_3c9ed0* self = reinterpret_cast<const Unk_3c9ed0*>(this);
    return self->field_20;
}

// 0x71003c9ee0
u64 Unk_2383e40::vf3() {
    const Unk_3c9ee0* self = reinterpret_cast<const Unk_3c9ee0*>(this);
    return self->field_20;
}
