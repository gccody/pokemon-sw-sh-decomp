// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d14CaptureTextureE
#include <types.h>

struct Unk_17a4330 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_17a4330, field_30, 0x30);

struct Unk_17a4340 {
    u8 _0[0x50];
    u16 field_50;
};
PKMN_OFFSET_ASSERT(Unk_17a4340, field_50, 0x50);

namespace nn {
namespace ui2d {
class CaptureTexture {
public:
    u64 vf6();
    void vf7();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017a4330
u64 nn::ui2d::CaptureTexture::vf6() {
    const Unk_17a4330* self = reinterpret_cast<const Unk_17a4330*>(this);
    return self->field_30;
}

// 0x71017a4340
void nn::ui2d::CaptureTexture::vf7() {
    Unk_17a4340* self = reinterpret_cast<Unk_17a4340*>(this);
    self->field_50 = self->field_50 & 0xfffffff7;
}
