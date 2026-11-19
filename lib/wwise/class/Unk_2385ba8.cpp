// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3fb540_arg1 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_3fb540_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3fb540_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3fb540_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3fb540_arg1, field_18, 0x18);

struct Unk_3fb540_50 {
    u8 _0[0x618];
    u32 field_618;
};
PKMN_OFFSET_ASSERT(Unk_3fb540_50, field_618, 0x618);

struct Unk_3fb540_20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3fb540_20, field_0, 0x0);

struct Unk_3fb540 {
    u8 _0[0x20];
    Unk_3fb540_20* field_20;
    u8 _28[0x28];
    Unk_3fb540_50* field_50;
    u64 field_58;
    u8 _60[0x9];
    u8 field_69;
};
PKMN_OFFSET_ASSERT(Unk_3fb540, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_3fb540, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_3fb540, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_3fb540, field_69, 0x69);

struct Unk_3fe070 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3fe070, field_20, 0x20);

struct Unk_3fb700 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_3fb700, field_60, 0x60);

struct Unk_3fb720_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3fb720_arg1, field_0, 0x0);

struct Unk_3fb720 {
    u8 _0[0x67];
    u8 field_67;
    u8 _68[0x10];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_3fb720, field_67, 0x67);
PKMN_OFFSET_ASSERT(Unk_3fb720, field_78, 0x78);

struct Unk_3fbcb0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3fbcb0_arg1, field_0, 0x0);

struct Unk_3fbcb0 {
    u8 _0[0x80];
    u64 field_80;
    u8 _88[0x8];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_3fbcb0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_3fbcb0, field_90, 0x90);

struct Unk_3fbcd0 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_3fbcd0, field_a8, 0xa8);

struct Unk_3fbcc0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3fbcc0_arg1, field_0, 0x0);

struct Unk_3fbcc0 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0x8];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3fbcc0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3fbcc0, field_20, 0x20);

struct Unk_3fbce0 {
    u8 _0[0x38];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_3fbce0, field_38, 0x38);

class Unk_2385ba8 {
public:
    void vf14(Unk_3fb540_arg1* value);
    u64 vf15();
    u32 vf17();
    u64 vf20(Unk_3fb720_arg1* value);
    u64 vf22(Unk_3fbcb0_arg1* value);
    u32 vf23();
    u64 vf12(Unk_3fbcc0_arg1* value);
    u32 vf13();
};

// 0x71003fb540
void Unk_2385ba8::vf14(Unk_3fb540_arg1* value) {
    const Unk_3fb540* self = reinterpret_cast<const Unk_3fb540*>(this);
    value->field_0 = self->field_50->field_618;
    value->field_8 = self->field_58;
    value->field_10 = self->field_20->field_0;
    value->field_18 = self->field_69;
}

// 0x71003fb700
u32 Unk_2385ba8::vf17() {
    const Unk_3fb700* self = reinterpret_cast<const Unk_3fb700*>(this);
    return self->field_60;
}

// 0x71003fb720
u64 Unk_2385ba8::vf20(Unk_3fb720_arg1* value) {
    const Unk_3fb720* self = reinterpret_cast<const Unk_3fb720*>(this);
    if (value != nullptr) {
        value->field_0 = self->field_67;
    }
    return self->field_78;
}

// 0x71003fbcb0
u64 Unk_2385ba8::vf22(Unk_3fbcb0_arg1* value) {
    const Unk_3fbcb0* self = reinterpret_cast<const Unk_3fbcb0*>(this);
    value->field_0 = self->field_90;
    return self->field_80;
}

// 0x71003fbcc0
u64 Unk_2385ba8::vf12(Unk_3fbcc0_arg1* value) {
    const Unk_3fbcc0* self = reinterpret_cast<const Unk_3fbcc0*>(this);
    value->field_0 = self->field_20;
    return self->field_10;
}

// 0x71003fbcd0
u32 Unk_2385ba8::vf23() {
    const Unk_3fbcd0* self = reinterpret_cast<const Unk_3fbcd0*>(this);
    return self->field_a8;
}

// 0x71003fbce0
u32 Unk_2385ba8::vf13() {
    const Unk_3fbce0* self = reinterpret_cast<const Unk_3fbce0*>(this);
    return self->field_38;
}

// 0x71003fe070
u64 Unk_2385ba8::vf15() {
    const Unk_3fe070* self = reinterpret_cast<const Unk_3fe070*>(this);
    return self->field_20;
}
