// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17a4330 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_17a4330, field_30, 0x30);

namespace nn {
namespace ui2d {
class CaptureTexture {
public:
    u64 vf6();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017a4330
u64 nn::ui2d::CaptureTexture::vf6() {
    const Unk_17a4330* self = reinterpret_cast<const Unk_17a4330*>(this);
    return self->field_30;
}
