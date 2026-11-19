// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17b8990_10 {
    u8 _0[0x1c];
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_17b8990_10, field_1c, 0x1c);

struct Unk_17b8990 {
    u8 _0[0x10];
    Unk_17b8990_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_17b8990, field_10, 0x10);

struct Unk_17b89f0_10 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_17b89f0_10, field_88, 0x88);

struct Unk_17b89f0 {
    u8 _0[0x10];
    Unk_17b89f0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_17b89f0, field_10, 0x10);

struct Unk_17b8a00_10 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_17b8a00_10, field_88, 0x88);

struct Unk_17b8a00 {
    u8 _0[0x10];
    Unk_17b8a00_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_17b8a00, field_10, 0x10);

namespace nn {
namespace ui2d {
class ResourceTextureInfo {
public:
    u32 vf5();
    u64 vf7();
    u64 vf8();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b8990
u32 nn::ui2d::ResourceTextureInfo::vf5() {
    const Unk_17b8990* self = reinterpret_cast<const Unk_17b8990*>(this);
    return self->field_10->field_1c;
}

// 0x71017b89f0
u64 nn::ui2d::ResourceTextureInfo::vf7() {
    const Unk_17b89f0* self = reinterpret_cast<const Unk_17b89f0*>(this);
    return self->field_10->field_88;
}

// 0x71017b8a00
u64 nn::ui2d::ResourceTextureInfo::vf8() {
    const Unk_17b8a00* self = reinterpret_cast<const Unk_17b8a00*>(this);
    return self->field_10->field_88;
}
