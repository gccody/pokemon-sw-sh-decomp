// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_362340_10 {
    u8 _0[0x30];
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_362340_10, field_30, 0x30);

struct Unk_362340 {
    u8 _0[0x10];
    Unk_362340_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_362340, field_10, 0x10);

class Unk_2380be8 {
public:
    u32 vf2();
};

// 0x7100362340
u32 Unk_2380be8::vf2() {
    const Unk_362340* self = reinterpret_cast<const Unk_362340*>(this);
    if (self->field_10 == nullptr) {
        return 0;
    }
    return self->field_10->field_30;
}
