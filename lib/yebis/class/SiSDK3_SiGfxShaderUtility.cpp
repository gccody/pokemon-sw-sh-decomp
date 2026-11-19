// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4e7910 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4e7910, field_10, 0x10);

struct Unk_4e4090 {
    u8 _0[0x1a0];
    bool field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_4e4090, field_1a0, 0x1a0);

struct Unk_4e40a0 {
    u8 _0[0x1a0];
    u8 field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_4e40a0, field_1a0, 0x1a0);

struct Unk_4e4c20 {
    u8 _0[0x110];
    u8 field_110;
};
PKMN_OFFSET_ASSERT(Unk_4e4c20, field_110, 0x110);

struct Unk_4e61e0 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_4e61e0, field_b8, 0xb8);

namespace SiSDK3 {
class SiGfxShaderUtility {
public:
    u32 vf4();
    void vf9(bool value);
    u8 vf10();
    const u8* vf13();
    u64 vf17();
};
}  // namespace SiSDK3

// 0x71004e4090
void SiSDK3::SiGfxShaderUtility::vf9(bool value) {
    Unk_4e4090* self = reinterpret_cast<Unk_4e4090*>(this);
    self->field_1a0 = value;
}

// 0x71004e40a0
u8 SiSDK3::SiGfxShaderUtility::vf10() {
    const Unk_4e40a0* self = reinterpret_cast<const Unk_4e40a0*>(this);
    return self->field_1a0;
}

// 0x71004e4c20
const u8* SiSDK3::SiGfxShaderUtility::vf13() {
    const Unk_4e4c20* self = reinterpret_cast<const Unk_4e4c20*>(this);
    return &self->field_110;
}

// 0x71004e61e0
u64 SiSDK3::SiGfxShaderUtility::vf17() {
    const Unk_4e61e0* self = reinterpret_cast<const Unk_4e61e0*>(this);
    return self->field_b8;
}

// 0x71004e7910
u32 SiSDK3::SiGfxShaderUtility::vf4() {
    const Unk_4e7910* self = reinterpret_cast<const Unk_4e7910*>(this);
    return self->field_10;
}
