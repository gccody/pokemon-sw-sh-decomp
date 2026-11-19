// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local25LocalUpdateSessionMessageE
#include <types.h>

struct Unk_16975e0_8 {
    u8 _0[0x1];
    u8 field_1;
    u16 field_2;
    u8 _4[0x8];
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u8 _1c[0x4];
    u64 field_20;
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_16975e0_8, field_28, 0x28);

struct Unk_16975e0 {
    u8 _0[0x8];
    Unk_16975e0_8* field_8;
    u8 _10[0x2];
    u8 field_12;
    u8 _13[0x3];
    u16 field_16;
    u8 _18[0x4];
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u8 _2c[0x4];
    u64 field_30;
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_16975e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_16975e0, field_38, 0x38);

namespace nn {
namespace pia {
namespace local {
class LocalUpdateSessionMessage {
public:
    u32 vf3();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x71016975e0
u32 nn::pia::local::LocalUpdateSessionMessage::vf3() {
    Unk_16975e0* self = reinterpret_cast<Unk_16975e0*>(this);
    self->field_12 = self->field_8->field_1;
    self->field_16 = self->field_8->field_2;
    self->field_1c = self->field_8->field_c;
    self->field_20 = self->field_8->field_10;
    self->field_24 = self->field_8->field_14;
    self->field_28 = self->field_8->field_18;
    self->field_30 = self->field_8->field_20;
    self->field_38 = self->field_8->field_28;
    return 1;
}
