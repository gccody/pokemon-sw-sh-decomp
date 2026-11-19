// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3f4d30_8_38_28 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3f4d30_8_38_28, field_20, 0x20);
struct Unk_3f4d30_8_38 {
    u8 _0[0x28];
    Unk_3f4d30_8_38_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_3f4d30_8_38, field_28, 0x28);
struct Unk_3f4d30_8 {
    u8 _0[0x38];
    Unk_3f4d30_8_38* field_38;
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_3f4d30_8, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_3f4d30_8, field_40, 0x40);
struct Unk_3f4d30 {
    u8 _0[0x8];
    Unk_3f4d30_8* field_8;
    u8 _10[0x10];
    u64 field_20;
    u8 _28[0x41];
    u8 field_69;
};
PKMN_OFFSET_ASSERT(Unk_3f4d30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3f4d30, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_3f4d30, field_69, 0x69);

class Unk_2385968 {
public:
    u32 vf2();
};

// 0x71003f4d30
u32 Unk_2385968::vf2() {
    Unk_3f4d30* self = reinterpret_cast<Unk_3f4d30*>(this);
    if (self->field_8->field_40 >= 6) {
        if (self->field_8->field_38->field_28 != nullptr) {
            self->field_20 = self->field_8->field_38->field_28->field_20;
            self->field_69 = 1;
            return 1;
        }
        return 1;
    }
    return 1;
}
