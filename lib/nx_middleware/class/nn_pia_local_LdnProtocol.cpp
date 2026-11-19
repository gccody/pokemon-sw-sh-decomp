// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1681dd0_arg1 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1681dd0_arg1, field_c, 0xc);

struct Unk_167f740 {
    u8 _0[0x47c];
    u8 field_47c;
};
PKMN_OFFSET_ASSERT(Unk_167f740, field_47c, 0x47c);

namespace nn {
namespace pia {
namespace local {
class LdnProtocol {
public:
    u32 vf4();
    u32 vf11();
    u32 vf15();
    u32 vf16();
    u32 vf17();
    u32 vf21();
    u32 vf22();
    void vf25(Unk_1681dd0_arg1* value, u32 arg2);
    u32 vf41();
    void vf50();
    void vf59();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167f740
void nn::pia::local::LdnProtocol::vf59() {
    Unk_167f740* self = reinterpret_cast<Unk_167f740*>(this);
    self->field_47c = 0x40;
}

// 0x7101680ab0
u32 nn::pia::local::LdnProtocol::vf17() {
    return 0;
}

// 0x7101681dd0
void nn::pia::local::LdnProtocol::vf25(Unk_1681dd0_arg1* value, u32 arg2) {
    value->field_c = arg2;
}

// 0x7101681de0
u32 nn::pia::local::LdnProtocol::vf41() {
    return 0;
}

// 0x7101682580
u32 nn::pia::local::LdnProtocol::vf4() {
    return 0x24;
}

// 0x7101682590
u32 nn::pia::local::LdnProtocol::vf11() {
    return 0;
}

// 0x71016825a0
u32 nn::pia::local::LdnProtocol::vf15() {
    return 0x5c0;
}

// 0x71016825b0
u32 nn::pia::local::LdnProtocol::vf16() {
    return 0x5b4;
}

// 0x71016825c0
u32 nn::pia::local::LdnProtocol::vf21() {
    return 0x18;
}

// 0x71016825d0
u32 nn::pia::local::LdnProtocol::vf22() {
    return 0x168;
}

// 0x7101682620
void nn::pia::local::LdnProtocol::vf50() {
}
