// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1697360_8 {
    u8 _0[0x1];
    u8 field_1;
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_1697360_8, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_1697360_8, field_2, 0x2);

struct Unk_1697360 {
    u8 _0[0x8];
    Unk_1697360_8* field_8;
    u8 _10[0x2];
    u8 field_12;
    u8 _13[0x3];
    u16 field_16;
};
PKMN_OFFSET_ASSERT(Unk_1697360, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1697360, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_1697360, field_16, 0x16);

namespace nn {
namespace pia {
namespace local {
class LocalMessage {
public:
    u32 vf3();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x7101697360
u32 nn::pia::local::LocalMessage::vf3() {
    Unk_1697360* self = reinterpret_cast<Unk_1697360*>(this);
    self->field_12 = self->field_8->field_1;
    self->field_16 = self->field_8->field_2;
    return 1;
}
