// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3ca1e0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3ca1e0, field_20, 0x20);

class Unk_2383ed8 {
public:
    u64 vf3();
    u32 vf7();
    u32 vf8();
    u32 vf9();
    u64 vf13();
};

// 0x71003ca020
u32 Unk_2383ed8::vf7() {
    return 2;
}

// 0x71003ca030
u32 Unk_2383ed8::vf8() {
    return 0;
}

// 0x71003ca040
u32 Unk_2383ed8::vf9() {
    return 2;
}

// 0x71003ca1e0
u64 Unk_2383ed8::vf3() {
    const Unk_3ca1e0* self = reinterpret_cast<const Unk_3ca1e0*>(this);
    return self->field_20;
}

// 0x71003ca220
u64 Unk_2383ed8::vf13() {
    return 0;
}
