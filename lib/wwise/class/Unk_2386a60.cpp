// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

extern u32 Unk_2381488;
struct Unk_405580 {
    u8 _0[0x88];
    u32 field_88;
    u8 _8c[0x54];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_405580, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_405580, field_e0, 0xe0);

void Unk_304740(u32, u64);

class Unk_2386a60 {
public:
    void vf3();
};

// 0x7100405580
void Unk_2386a60::vf3() {
    Unk_405580* self = reinterpret_cast<Unk_405580*>(this);
    if (self->field_e0 != 0) {
        Unk_304740(Unk_2381488, self->field_e0);
        self->field_88 = 0;
        self->field_e0 = 0;
    }
}
