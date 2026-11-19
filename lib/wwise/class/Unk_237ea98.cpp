// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_33d620 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_33d620, field_40, 0x40);

class Unk_237ea98 {
public:
    void vf13();
};

// 0x710033d620
void Unk_237ea98::vf13() {
    Unk_33d620* self = reinterpret_cast<Unk_33d620*>(this);
    self->field_40 = 0;
}
