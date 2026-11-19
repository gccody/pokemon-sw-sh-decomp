// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1697800_8 {
    u8 _0[0x1];
    u8 field_1;
    u16 field_2;
    u8 _4[0x8];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1697800_8, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_1697800_8, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_1697800_8, field_c, 0xc);

struct Unk_1697800 {
    u8 _0[0x8];
    Unk_1697800_8* field_8;
    u8 _10[0x2];
    u8 field_12;
    u8 _13[0x3];
    u16 field_16;
    u8 _18[0x4];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_1697800, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1697800, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_1697800, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_1697800, field_1c, 0x1c);

namespace nn {
namespace pia {
namespace local {
class LocalAckMessage {
public:
    u32 vf3();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x7101697800
u32 nn::pia::local::LocalAckMessage::vf3() {
    Unk_1697800* self = reinterpret_cast<Unk_1697800*>(this);
    self->field_12 = self->field_8->field_1;
    self->field_16 = self->field_8->field_2;
    self->field_1c = self->field_8->field_c;
    return 1;
}
