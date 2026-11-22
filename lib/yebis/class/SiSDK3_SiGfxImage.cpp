// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK310SiGfxImageE
// (The name's functions, slots 5 to 7 and their thunks, are SiGfx_Image.cpp's.)
#include <types.h>

struct Unk_4f4690 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4f4690, field_18, 0x18);

struct Unk_4f3dc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_4f3dc0_arg1, field_0, 0x0);

namespace SiSDK3 {
class SiGfxImage {
public:
    u32 vf4();
    u32 vf24(Unk_4f3dc0_arg1* value);
};
}  // namespace SiSDK3

// 0x71004f3dc0
u32 SiSDK3::SiGfxImage::vf24(Unk_4f3dc0_arg1* value) {
    value->field_0 = 0;
    return 1;
}

// 0x71004f4690
u32 SiSDK3::SiGfxImage::vf4() {
    const Unk_4f4690* self = reinterpret_cast<const Unk_4f4690*>(this);
    return self->field_18;
}
