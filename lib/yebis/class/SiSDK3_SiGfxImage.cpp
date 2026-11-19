// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK310SiGfxImageE
#include <types.h>

struct Unk_4f4690 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4f4690, field_18, 0x18);

struct Unk_4f1870 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4f1870, field_20, 0x20);

struct Unk_4f1890 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_4f1890, field_50, 0x50);

struct Unk_4f3dc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_4f3dc0_arg1, field_0, 0x0);

struct Unk_4f1880 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4f1880, field_18, 0x18);

namespace SiSDK3 {
class SiGfxImage {
public:
    u32 vf4();
    const u8* vf6();
    u32 vf7();
    u32 vf24(Unk_4f3dc0_arg1* value);
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x71004f1870
const u8* SiSDK3::SiGfxImage::vf6() {
    const Unk_4f1870* self = reinterpret_cast<const Unk_4f1870*>(this);
    return &self->field_20;
}

// 0x71004f1880
const u8* SiSDK3::SiGfxImage::vf3() {
    const Unk_4f1880* self = reinterpret_cast<const Unk_4f1880*>(this);
    return &self->field_18;
}

// 0x71004f1890
u32 SiSDK3::SiGfxImage::vf7() {
    const Unk_4f1890* self = reinterpret_cast<const Unk_4f1890*>(this);
    return self->field_50;
}

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
