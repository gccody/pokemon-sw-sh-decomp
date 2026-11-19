// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17b8e00 {
    u8 _0[0xd0];
    u32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_17b8e00, field_d0, 0xd0);

struct Unk_17b8e20 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_17b8e20, field_20, 0x20);

struct Unk_17b8e30 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_17b8e30, field_20, 0x20);

struct Unk_17b8e40 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_17b8e40, field_38, 0x38);

namespace nn {
namespace ui2d {
class RenderTargetTextureInfo {
public:
    u32 vf5();
    u64 vf7();
    u64 vf8();
    u64 vf9();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b8e00
u32 nn::ui2d::RenderTargetTextureInfo::vf5() {
    const Unk_17b8e00* self = reinterpret_cast<const Unk_17b8e00*>(this);
    return self->field_d0;
}

// 0x71017b8e20
u64 nn::ui2d::RenderTargetTextureInfo::vf7() {
    const Unk_17b8e20* self = reinterpret_cast<const Unk_17b8e20*>(this);
    return self->field_20;
}

// 0x71017b8e30
u64 nn::ui2d::RenderTargetTextureInfo::vf8() {
    const Unk_17b8e30* self = reinterpret_cast<const Unk_17b8e30*>(this);
    return self->field_20;
}

// 0x71017b8e40
u64 nn::ui2d::RenderTargetTextureInfo::vf9() {
    const Unk_17b8e40* self = reinterpret_cast<const Unk_17b8e40*>(this);
    return self->field_38;
}
