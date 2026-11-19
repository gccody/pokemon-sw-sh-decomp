// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK322SiGfxShaderGraphObjectE
#include <types.h>

struct Unk_4dc3e0 {
    u8 _0[0x38];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_4dc3e0, field_38, 0x38);

struct Unk_4dc400 {
    u8 _0[0x40];
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4dc400, field_40, 0x40);

struct Unk_4dc410 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_4dc410, field_50, 0x50);

struct Unk_4dc420 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_4dc420, field_80, 0x80);

struct Unk_4dc430 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_4dc430, field_88, 0x88);

namespace SiSDK3 {
class SiGfxShaderGraphObject {
public:
    u32 vf4();
    const u8* vf6();
    const u8* vf10();
    u32 vf11();
    const u8* vf13();
    void vf14();
    void vf15();
};
}  // namespace SiSDK3

// 0x71004dc3e0
u32 SiSDK3::SiGfxShaderGraphObject::vf4() {
    const Unk_4dc3e0* self = reinterpret_cast<const Unk_4dc3e0*>(this);
    return self->field_38;
}

// 0x71004dc400
const u8* SiSDK3::SiGfxShaderGraphObject::vf6() {
    const Unk_4dc400* self = reinterpret_cast<const Unk_4dc400*>(this);
    return &self->field_40;
}

// 0x71004dc410
const u8* SiSDK3::SiGfxShaderGraphObject::vf10() {
    const Unk_4dc410* self = reinterpret_cast<const Unk_4dc410*>(this);
    return &self->field_50;
}

// 0x71004dc420
u32 SiSDK3::SiGfxShaderGraphObject::vf11() {
    const Unk_4dc420* self = reinterpret_cast<const Unk_4dc420*>(this);
    return self->field_80;
}

// 0x71004dc430
const u8* SiSDK3::SiGfxShaderGraphObject::vf13() {
    const Unk_4dc430* self = reinterpret_cast<const Unk_4dc430*>(this);
    return &self->field_88;
}

// 0x71004dcb50
void SiSDK3::SiGfxShaderGraphObject::vf14() {
}

// 0x71004dcb60
void SiSDK3::SiGfxShaderGraphObject::vf15() {
}
