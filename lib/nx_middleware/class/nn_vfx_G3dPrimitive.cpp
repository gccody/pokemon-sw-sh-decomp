// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3vfx12G3dPrimitiveE
#include <types.h>

struct Unk_17d4e60 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_17d4e60, field_30, 0x30);

struct Unk_17d4e70_18 {
    u8 _0[0x4d];
    u8 field_4d;
};
PKMN_OFFSET_ASSERT(Unk_17d4e70_18, field_4d, 0x4d);

struct Unk_17d4e70 {
    u8 _0[0x18];
    Unk_17d4e70_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_17d4e70, field_18, 0x18);

struct Unk_17d4ea0_28 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_17d4ea0_28, field_28, 0x28);

struct Unk_17d4ea0 {
    u8 _0[0x28];
    Unk_17d4ea0_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_17d4ea0, field_28, 0x28);

namespace nn {
namespace vfx {
class G3dPrimitive {
public:
    const u8* vf5();
    u8 vf6();
    u32 vf9();
};
}  // namespace vfx
}  // namespace nn

// 0x71017d4e60
const u8* nn::vfx::G3dPrimitive::vf5() {
    const Unk_17d4e60* self = reinterpret_cast<const Unk_17d4e60*>(this);
    return &self->field_30;
}

// 0x71017d4e70
u8 nn::vfx::G3dPrimitive::vf6() {
    const Unk_17d4e70* self = reinterpret_cast<const Unk_17d4e70*>(this);
    return self->field_18->field_4d;
}

// 0x71017d4ea0
u32 nn::vfx::G3dPrimitive::vf9() {
    const Unk_17d4ea0* self = reinterpret_cast<const Unk_17d4ea0*>(this);
    return self->field_28->field_28;
}
