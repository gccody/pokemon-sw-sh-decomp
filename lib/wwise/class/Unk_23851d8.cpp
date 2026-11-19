// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

extern u32 Unk_2381488;
struct Unk_3df580 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_3df580, field_88, 0x88);

void Unk_304740(u32, u64);

class Unk_23851d8 {
public:
    void vf3();
};

// 0x71003df580
void Unk_23851d8::vf3() {
    Unk_3df580* self = reinterpret_cast<Unk_3df580*>(this);
    if (self->field_88 != 0) {
        Unk_304740(Unk_2381488, self->field_88);
        self->field_88 = 0;
    }
}
