// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local23LdnCreateSessionSettingE
#include <types.h>

struct Unk_167c160 {
    u8 _0[0xc];
    u16 field_c;
    u8 _e[0x54];
    u16 field_62;
};
PKMN_OFFSET_ASSERT(Unk_167c160, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_167c160, field_62, 0x62);

struct Unk_167c130 {
    u8 _0[0x228];
    u32 field_228;
};
PKMN_OFFSET_ASSERT(Unk_167c130, field_228, 0x228);

struct Unk_167c140 {
    u8 _0[0x230];
    u8 field_230;
};
PKMN_OFFSET_ASSERT(Unk_167c140, field_230, 0x230);

struct Unk_167c170 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_167c170, field_50, 0x50);

namespace nn {
namespace pia {
namespace local {
class LdnCreateSessionSetting {
public:
    void vf3(u16 value);
    u32 vf6();
    u8 vf7();
    void vf9();
    const u8* vf10();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167c130
u32 nn::pia::local::LdnCreateSessionSetting::vf6() {
    const Unk_167c130* self = reinterpret_cast<const Unk_167c130*>(this);
    return self->field_228;
}

// 0x710167c140
u8 nn::pia::local::LdnCreateSessionSetting::vf7() {
    const Unk_167c140* self = reinterpret_cast<const Unk_167c140*>(this);
    return self->field_230;
}

// 0x710167c150
void nn::pia::local::LdnCreateSessionSetting::vf9() {
}

// 0x710167c160
void nn::pia::local::LdnCreateSessionSetting::vf3(u16 value) {
    Unk_167c160* self = reinterpret_cast<Unk_167c160*>(this);
    self->field_c = value;
    self->field_62 = value;
}

// 0x710167c170
const u8* nn::pia::local::LdnCreateSessionSetting::vf10() {
    const Unk_167c170* self = reinterpret_cast<const Unk_167c170*>(this);
    return &self->field_50;
}
