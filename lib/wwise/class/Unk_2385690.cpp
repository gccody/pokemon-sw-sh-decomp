// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3e2b70 {
    u8 _0[0x17c];
    u8 field_17c;
};
PKMN_OFFSET_ASSERT(Unk_3e2b70, field_17c, 0x17c);

struct Unk_3e2360 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_3e2360, field_b8, 0xb8);

class Unk_2385690 {
public:
    u32 vf4();
    u64 vf6();
    void vf7();
    void vf8();
    void vf9();
    u32 vf10();
    void vf11();
    void vf13();
    void vf17();
    void vf18();
    void vf5();
    void vf2();
    void vf3();
};

// 0x71003e2360
u64 Unk_2385690::vf6() {
    const Unk_3e2360* self = reinterpret_cast<const Unk_3e2360*>(this);
    return self->field_b8;
}

// 0x71003e2b70
u32 Unk_2385690::vf4() {
    const Unk_3e2b70* self = reinterpret_cast<const Unk_3e2b70*>(this);
    return (self->field_17c >> 3) & 1;
}

// 0x71003e2b80
void Unk_2385690::vf7() {
}

// 0x71003e2b90
void Unk_2385690::vf8() {
}

// 0x71003e2ba0
void Unk_2385690::vf9() {
}

// 0x71003e2bb0
u32 Unk_2385690::vf10() {
    return 0x2000;
}

// 0x71003e2bc0
void Unk_2385690::vf11() {
}

// 0x71003e2bd0
void Unk_2385690::vf13() {
}

// 0x71003e2be0
void Unk_2385690::vf17() {
}

// 0x71003e2bf0
void Unk_2385690::vf18() {
}

// 0x71003e2c30
void Unk_2385690::vf5() {
}

// 0x71003e2c80
void Unk_2385690::vf2() {
}

// 0x71003e2c90
void Unk_2385690::vf3() {
}
