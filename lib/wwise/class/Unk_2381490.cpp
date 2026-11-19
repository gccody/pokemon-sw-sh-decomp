// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_369bf0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_369bf0, field_8, 0x8);

struct Unk_369c10 {
    u8 _0[0x2a0];
    u32 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_369c10, field_2a0, 0x2a0);

struct Unk_369c30 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_369c30, field_60, 0x60);

struct Unk_369c40 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_369c40, field_60, 0x60);

struct Unk_369c00 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_369c00, field_8, 0x8);

class Unk_2381490 {
public:
    const u8* vf3();
    u32 vf4();
    u64 vf6();
    void vf7(u64 value);
    const u8* vf33();
};

// 0x7100369bf0
const u8* Unk_2381490::vf3() {
    const Unk_369bf0* self = reinterpret_cast<const Unk_369bf0*>(this);
    return &self->field_8;
}

// 0x7100369c00
const u8* Unk_2381490::vf33() {
    const Unk_369c00* self = reinterpret_cast<const Unk_369c00*>(this);
    return &self->field_8;
}

// 0x7100369c10
u32 Unk_2381490::vf4() {
    const Unk_369c10* self = reinterpret_cast<const Unk_369c10*>(this);
    return self->field_2a0;
}

// 0x7100369c30
u64 Unk_2381490::vf6() {
    const Unk_369c30* self = reinterpret_cast<const Unk_369c30*>(this);
    return self->field_60;
}

// 0x7100369c40
void Unk_2381490::vf7(u64 value) {
    Unk_369c40* self = reinterpret_cast<Unk_369c40*>(this);
    self->field_60 = value;
}
