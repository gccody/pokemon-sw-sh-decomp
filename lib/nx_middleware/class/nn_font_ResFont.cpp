// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_177c140_20 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_177c140_20, field_2, 0x2);

struct Unk_177c140 {
    u8 _0[0x20];
    Unk_177c140_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_177c140, field_20, 0x20);

struct Unk_177c150_20 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_177c150_20, field_1, 0x1);

struct Unk_177c150 {
    u8 _0[0x20];
    Unk_177c150_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_177c150, field_20, 0x20);

struct Unk_177c160_20 {
    u8 _0[0x3];
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_177c160_20, field_3, 0x3);

struct Unk_177c160 {
    u8 _0[0x20];
    Unk_177c160_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_177c160, field_20, 0x20);

struct Unk_177c7f0_20 {
    u8 _0[0xb];
    u8 field_b;
};
PKMN_OFFSET_ASSERT(Unk_177c7f0_20, field_b, 0xb);

struct Unk_177c7f0 {
    u8 _0[0x20];
    Unk_177c7f0_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_177c7f0, field_20, 0x20);

struct Unk_177c870 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_177c870, field_58, 0x58);

struct Unk_177c880 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_177c880, field_58, 0x58);

struct Unk_177c890 {
    u8 _0[0x58];
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_177c890, field_58, 0x58);

struct Unk_177c8a0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_177c8a0, field_3f, 0x3f);

struct Unk_177c8b0 {
    u8 _0[0x3f];
    bool field_3f;
};
PKMN_OFFSET_ASSERT(Unk_177c8b0, field_3f, 0x3f);

namespace nn {
namespace font {
class ResFont {
public:
    u8 vf4();
    u8 vf5();
    u8 vf6();
    u32 vf9();
    u8 vf21();
    u32 vf26();
    u32 vf27();
    u32 vf28();
    u8 vf29();
    void vf30(bool value);
};
}  // namespace font
}  // namespace nn

// 0x710177c140
u8 nn::font::ResFont::vf4() {
    const Unk_177c140* self = reinterpret_cast<const Unk_177c140*>(this);
    return self->field_20->field_2;
}

// 0x710177c150
u8 nn::font::ResFont::vf5() {
    const Unk_177c150* self = reinterpret_cast<const Unk_177c150*>(this);
    return self->field_20->field_1;
}

// 0x710177c160
u8 nn::font::ResFont::vf6() {
    const Unk_177c160* self = reinterpret_cast<const Unk_177c160*>(this);
    return self->field_20->field_3;
}

// 0x710177c200
u32 nn::font::ResFont::vf9() {
    return 1;
}

// 0x710177c7f0
u8 nn::font::ResFont::vf21() {
    const Unk_177c7f0* self = reinterpret_cast<const Unk_177c7f0*>(this);
    return self->field_20->field_b;
}

// 0x710177c870
u32 nn::font::ResFont::vf26() {
    const Unk_177c870* self = reinterpret_cast<const Unk_177c870*>(this);
    return (self->field_58 >> 2) & 1;
}

// 0x710177c880
u32 nn::font::ResFont::vf27() {
    const Unk_177c880* self = reinterpret_cast<const Unk_177c880*>(this);
    return (self->field_58 >> 1) & 1;
}

// 0x710177c890
u32 nn::font::ResFont::vf28() {
    const Unk_177c890* self = reinterpret_cast<const Unk_177c890*>(this);
    return self->field_58;
}

// 0x710177c8a0
u8 nn::font::ResFont::vf29() {
    const Unk_177c8a0* self = reinterpret_cast<const Unk_177c8a0*>(this);
    return self->field_3f;
}

// 0x710177c8b0
void nn::font::ResFont::vf30(bool value) {
    Unk_177c8b0* self = reinterpret_cast<Unk_177c8b0*>(this);
    self->field_3f = value;
}
