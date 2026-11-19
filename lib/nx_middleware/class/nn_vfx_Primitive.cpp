// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3vfx9PrimitiveE
#include <types.h>

struct Unk_17d4c40 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_17d4c40, field_20, 0x20);

struct Unk_17d4c50 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_17d4c50, field_28, 0x28);

struct Unk_17d4c70 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_17d4c70, field_48, 0x48);

namespace nn {
namespace vfx {
class Primitive {
public:
    u64 vf2();
    u64 vf3();
    const u8* vf5();
    u32 vf6();
    u32 vf7();
    u32 vf8();
    u32 vf9();
};
}  // namespace vfx
}  // namespace nn

// 0x71017d4c40
u64 nn::vfx::Primitive::vf2() {
    const Unk_17d4c40* self = reinterpret_cast<const Unk_17d4c40*>(this);
    return self->field_20;
}

// 0x71017d4c50
u64 nn::vfx::Primitive::vf3() {
    const Unk_17d4c50* self = reinterpret_cast<const Unk_17d4c50*>(this);
    return self->field_28;
}

// 0x71017d4c70
const u8* nn::vfx::Primitive::vf5() {
    const Unk_17d4c70* self = reinterpret_cast<const Unk_17d4c70*>(this);
    return &self->field_48;
}

// 0x71017d4c80
u32 nn::vfx::Primitive::vf6() {
    return 1;
}

// 0x71017d4c90
u32 nn::vfx::Primitive::vf7() {
    return 0;
}

// 0x71017d4ca0
u32 nn::vfx::Primitive::vf8() {
    return 0x1905;
}

// 0x71017d4cb0
u32 nn::vfx::Primitive::vf9() {
    return 2;
}
