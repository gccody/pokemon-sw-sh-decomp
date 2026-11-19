// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3a5d60_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_3a5d60_arg1, field_0, 0x0);

struct Unk_3a5db0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3a5db0, field_10, 0x10);

class Unk_2382f10 {
public:
    u32 vf8(Unk_3a5d60_arg1* value);
    void vf9();
    void vf10();
    u32 vf11();
    void vf12();
    const u8* vf13();
    void vf14();
    void vf15();
};

// 0x71003a5d60
u32 Unk_2382f10::vf8(Unk_3a5d60_arg1* value) {
    value->field_0 = 1;
    return 1;
}

// 0x71003a5d70
void Unk_2382f10::vf9() {
}

// 0x71003a5d80
void Unk_2382f10::vf10() {
}

// 0x71003a5d90
u32 Unk_2382f10::vf11() {
    return 0;
}

// 0x71003a5da0
void Unk_2382f10::vf12() {
}

// 0x71003a5db0
const u8* Unk_2382f10::vf13() {
    const Unk_3a5db0* self = reinterpret_cast<const Unk_3a5db0*>(this);
    return &self->field_10;
}

// 0x71003a5dc0
void Unk_2382f10::vf14() {
}

// 0x71003a5dd0
void Unk_2382f10::vf15() {
}
