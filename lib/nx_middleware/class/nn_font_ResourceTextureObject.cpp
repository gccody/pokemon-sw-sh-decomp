// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_177cd10_28 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_177cd10_28, field_88, 0x88);

struct Unk_177cd10 {
    u8 _0[0x28];
    Unk_177cd10_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_177cd10, field_28, 0x28);

struct Unk_177c110_28 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_177c110_28, field_88, 0x88);

struct Unk_177c110 {
    u8 _0[0x28];
    Unk_177c110_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_177c110, field_28, 0x28);

namespace nn {
namespace font {
class ResourceTextureObject {
public:
    u64 vf2();
    u64 vf3();
};
}  // namespace font
}  // namespace nn

// 0x710177c110
u64 nn::font::ResourceTextureObject::vf3() {
    const Unk_177c110* self = reinterpret_cast<const Unk_177c110*>(this);
    return self->field_28->field_88;
}

// 0x710177cd10
u64 nn::font::ResourceTextureObject::vf2() {
    const Unk_177cd10* self = reinterpret_cast<const Unk_177cd10*>(this);
    return self->field_28->field_88;
}
