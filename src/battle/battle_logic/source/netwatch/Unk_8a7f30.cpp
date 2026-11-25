// Scope: common
#include "battle/battle_logic/source/netwatch/Unk_8a7f30.h"

// A class with only a virtual destructor (vtable 0x71023b8fe8), destroyed in
// src/unsorted/virtual/Unk_8a7fa0.cpp, and a u64 its constructor clears.
class Unk_23b8fe8 {
public:
    Unk_23b8fe8();
    virtual ~Unk_23b8fe8();

    u64 field_8;
};
PKMN_SIZE_ASSERT(Unk_23b8fe8, 0x10);

// 0x71008a7f30
Unk_23b8fe8::Unk_23b8fe8() : field_8(0) {}

// 0x71008a7fc0
Unk_8a7fc0::Unk_8a7fc0(u32 a0, u64 a1, u8 a2)
    : field_0(a0), field_8(a1), field_10(a2), field_11(0), field_12() {}

// 0x71008a7fe0
void Unk_8a7fc0::Unk_8a7fe0(u8 count) {
    for (u8 i = 0; i < count; i++)
        field_12[i] = 2;
}

// 0x71008a8030
Unk_8a8030::Unk_8a8030(const Unk_8a7fc0& record) {
    field_31 = 0;
    field_32 = record.field_10;
    field_0 = record.field_0;
    field_33 = false;
    for (int i = 0; i < 5; i++) {
        field_4[i] = 5;
        field_22[i] = 0;
        field_2c[i] = 0;
    }
}

// 0x71008a8080
void Unk_8a8030::Unk_8a8080(u8 a0, u8 a1) {
    if (field_31 < field_32) {
        field_4[field_31] = field_0;
        field_18[field_31] = a1;
        field_1d[field_31] = a0;
        field_22[field_31] = 0;
        field_2c[field_31] = 0;
        field_31++;
    }
}
