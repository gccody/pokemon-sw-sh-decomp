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

namespace SiSDK3 {
// (SiGfx_Image.h's, as far as slot 24 uses it)
struct Unk_ImageConvertDesc {
    u32 field_0;
    s32 field_4;
    s32 field_8;
    struct Unk_Pair {
        s32 field_0;
        u32 field_4;
    };
    Unk_Pair field_c;
    bool field_14;
    bool field_15;
    bool field_16;
};
PKMN_SIZE_ASSERT(Unk_ImageConvertDesc, 0x18);

class SiGfxImage {
public:
    u32 vf4();
    bool vf24(SiGfxImage** pConverted, Unk_ImageConvertDesc desc);
};
}  // namespace SiSDK3

// 0x71004f3dc0
bool SiSDK3::SiGfxImage::vf24(SiGfxImage** pConverted, Unk_ImageConvertDesc) {
    *pConverted = nullptr;
    return true;
}

// 0x71004f4690
u32 SiSDK3::SiGfxImage::vf4() {
    const Unk_4f4690* self = reinterpret_cast<const Unk_4f4690*>(this);
    return self->field_18;
}
