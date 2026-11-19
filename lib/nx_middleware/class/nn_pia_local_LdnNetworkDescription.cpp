// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local21LdnNetworkDescriptionE
#include <types.h>

struct Unk_167e8c0 {
    u8 _0[0x53];
    u8 field_53;
    u8 _54[0x16];
    u8 field_6a;
};
PKMN_OFFSET_ASSERT(Unk_167e8c0, field_53, 0x53);
PKMN_OFFSET_ASSERT(Unk_167e8c0, field_6a, 0x6a);

struct Unk_167e8f0 {
    u8 _0[0x50];
    u16 field_50;
};
PKMN_OFFSET_ASSERT(Unk_167e8f0, field_50, 0x50);

struct Unk_167e930 {
    u8 _0[0x12];
    u16 field_12;
    u8 _14[0x3f];
    u8 field_53;
};
PKMN_OFFSET_ASSERT(Unk_167e930, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_167e930, field_53, 0x53);

namespace nn {
namespace pia {
namespace local {
class LdnNetworkDescription {
public:
    bool vf2();
    u16 vf3();
    u16 vf5();
    void vf6();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167e8c0
bool nn::pia::local::LdnNetworkDescription::vf2() {
    const Unk_167e8c0* self = reinterpret_cast<const Unk_167e8c0*>(this);
    if (self->field_53 != 2) {
        return false;
    }
    return self->field_6a == 0;
}

// 0x710167e8f0
u16 nn::pia::local::LdnNetworkDescription::vf3() {
    const Unk_167e8f0* self = reinterpret_cast<const Unk_167e8f0*>(this);
    return self->field_50;
}

// 0x710167e930
u16 nn::pia::local::LdnNetworkDescription::vf5() {
    const Unk_167e930* self = reinterpret_cast<const Unk_167e930*>(this);
    if (self->field_53 != 2) {
        return 0;
    }
    return self->field_12;
}

// 0x710167e970
void nn::pia::local::LdnNetworkDescription::vf6() {
}
