// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1794750 {
    u8 _0[0x24];
    bool field_24;
};
PKMN_OFFSET_ASSERT(Unk_1794750, field_24, 0x24);

struct Unk_1795520 {
    u8 _0[0x38];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_1795520, field_38, 0x38);

namespace nn {
namespace ui2d {
class AnimTransformBasic {
public:
    void vf3();
    void vf4(bool value);
    void vf17();
};
}  // namespace ui2d
}  // namespace nn

// 0x7101794740
void nn::ui2d::AnimTransformBasic::vf3() {
}

// 0x7101794750
void nn::ui2d::AnimTransformBasic::vf4(bool value) {
    Unk_1794750* self = reinterpret_cast<Unk_1794750*>(this);
    self->field_24 = value;
}

// 0x7101795520
void nn::ui2d::AnimTransformBasic::vf17() {
    Unk_1795520* self = reinterpret_cast<Unk_1795520*>(this);
    self->field_38 = 0;
}
