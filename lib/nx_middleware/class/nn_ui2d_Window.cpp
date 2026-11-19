// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17bbff0 {
    u8 _0[0x109];
    u8 field_109;
};
PKMN_OFFSET_ASSERT(Unk_17bbff0, field_109, 0x109);

namespace nn {
namespace ui2d {
class Window {
public:
    u32 vf10();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017bbff0
u32 nn::ui2d::Window::vf10() {
    const Unk_17bbff0* self = reinterpret_cast<const Unk_17bbff0*>(this);
    return self->field_109 + 1;
}
