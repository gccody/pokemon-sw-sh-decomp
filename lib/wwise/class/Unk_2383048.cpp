// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3a72b0 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_3a72b0, field_b8, 0xb8);

class Unk_2383048 {
public:
    u32 vf4();
    void vf12();
    u32 vf17();
    bool vf18();
};

// 0x71003a6a70
u32 Unk_2383048::vf17() {
    return 3;
}

// 0x71003a6e90
u32 Unk_2383048::vf4() {
    return 4;
}

// 0x71003a72a0
void Unk_2383048::vf12() {
}

// 0x71003a72b0
bool Unk_2383048::vf18() {
    const Unk_3a72b0* self = reinterpret_cast<const Unk_3a72b0*>(this);
    return self->field_b8 != 0;
}
