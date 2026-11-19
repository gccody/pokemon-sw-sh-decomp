// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_36c780_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x2];
    u8 field_b;
};
PKMN_OFFSET_ASSERT(Unk_36c780_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_36c780_arg1, field_b, 0xb);

class Unk_2381690 {
public:
    u32 vf8();
    bool vf9(const Unk_36c780_arg1* value);
};

// 0x710036c780
bool Unk_2381690::vf9(const Unk_36c780_arg1* value) {
    if (value->field_8 != 0) {
        if (value->field_8 == 0x90) {
            return value->field_b != 0;
        }
        return 0;
    }
    return 1;
}

// 0x710036d550
u32 Unk_2381690::vf8() {
    return 0;
}
