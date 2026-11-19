// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3a6470 {
    u8 _0[0x1c];
    u8 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_3a6470, field_1c, 0x1c);

struct Unk_3a6480 {
    u8 _0[0x1c];
    u8 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_3a6480, field_1c, 0x1c);

struct Unk_3a6540 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_3a6540, field_28, 0x28);

class Unk_2382fa0 {
public:
    u8 vf11();
    void vf12();
    const u8* vf13();
};

// 0x71003a6470
u8 Unk_2382fa0::vf11() {
    const Unk_3a6470* self = reinterpret_cast<const Unk_3a6470*>(this);
    return self->field_1c;
}

// 0x71003a6480
void Unk_2382fa0::vf12() {
    Unk_3a6480* self = reinterpret_cast<Unk_3a6480*>(this);
    self->field_1c = 0;
}

// 0x71003a6540
const u8* Unk_2382fa0::vf13() {
    const Unk_3a6540* self = reinterpret_cast<const Unk_3a6540*>(this);
    return &self->field_28;
}
