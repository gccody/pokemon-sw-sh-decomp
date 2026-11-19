// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3fde70 {
    u8 _0[0x69];
    u8 field_69;
};
PKMN_OFFSET_ASSERT(Unk_3fde70, field_69, 0x69);

class Unk_2385b28 {
public:
    void vf4();
    void vf8();
    u32 vf9();
    u32 vf10();
    void vf11();
    u32 vf12();
    u32 vf13();
};

// 0x71003fde70
void Unk_2385b28::vf4() {
    Unk_3fde70* self = reinterpret_cast<Unk_3fde70*>(this);
    self->field_69 = 1;
}

// 0x71003fe010
void Unk_2385b28::vf8() {
}

// 0x71003fe020
u32 Unk_2385b28::vf9() {
    return 0;
}

// 0x71003fe030
u32 Unk_2385b28::vf10() {
    return 0;
}

// 0x71003fe040
void Unk_2385b28::vf11() {
}

// 0x71003fe050
u32 Unk_2385b28::vf12() {
    return 0;
}

// 0x71003fe060
u32 Unk_2385b28::vf13() {
    return 0;
}
