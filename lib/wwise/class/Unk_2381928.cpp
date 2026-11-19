// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3743f0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_3743f0, field_80, 0x80);

class Unk_2381928 {
public:
    const u8* vf3();
    void vf5();
};

// 0x71003743f0
const u8* Unk_2381928::vf3() {
    const Unk_3743f0* self = reinterpret_cast<const Unk_3743f0*>(this);
    return &self->field_80;
}

// 0x7100374400
void Unk_2381928::vf5() {
}
