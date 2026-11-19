// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3lan23LanCreateSessionSettingE
#include <types.h>

struct Unk_1723340 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_1723340, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1723340, field_a, 0xa);

struct Unk_1723370 {
    u8 _0[0xc];
    u16 field_c;
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_1723370, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1723370, field_e, 0xe);

struct Unk_1661d50 {
    u8 _0[0x1b0];
    u32 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_1661d50, field_1b0, 0x1b0);

struct Unk_1661d60 {
    u8 _0[0x1b9];
    u8 field_1b9;
};
PKMN_OFFSET_ASSERT(Unk_1661d60, field_1b9, 0x1b9);

namespace nn {
namespace pia {
namespace lan {
class LanCreateSessionSetting {
public:
    void vf2(u16 value);
    void vf3(u16 value);
    u32 vf6();
    u32 vf7();
    void vf9();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101661d50
u32 nn::pia::lan::LanCreateSessionSetting::vf6() {
    const Unk_1661d50* self = reinterpret_cast<const Unk_1661d50*>(this);
    return self->field_1b0;
}

// 0x7101661d60
u32 nn::pia::lan::LanCreateSessionSetting::vf7() {
    const Unk_1661d60* self = reinterpret_cast<const Unk_1661d60*>(this);
    return self->field_1b9 & 1;
}

// 0x7101661ee0
void nn::pia::lan::LanCreateSessionSetting::vf9() {
}

// 0x7101723340
void nn::pia::lan::LanCreateSessionSetting::vf2(u16 value) {
    Unk_1723340* self = reinterpret_cast<Unk_1723340*>(this);
    self->field_8 = value;
    self->field_a = 1;
}

// 0x7101723370
void nn::pia::lan::LanCreateSessionSetting::vf3(u16 value) {
    Unk_1723370* self = reinterpret_cast<Unk_1723370*>(this);
    self->field_c = value;
    self->field_e = 1;
}
