// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local11LdnProtocolE
#include <types.h>

struct Unk_16825e0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual u32 vf21();
    virtual u32 vf22();
};

struct Unk_1681dd0_arg1 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1681dd0_arg1, field_c, 0xc);

struct Unk_1692f40_300 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(void*);
};

struct Unk_1692f40 {
    u8 _0[0x300];
    Unk_1692f40_300* field_300;
};
PKMN_OFFSET_ASSERT(Unk_1692f40, field_300, 0x300);

struct Unk_1682630 {
    u8 _0[0x418];
    u32 field_418;
    u8 _41c[0x61];
    u8 field_47d;
};
PKMN_OFFSET_ASSERT(Unk_1682630, field_418, 0x418);
PKMN_OFFSET_ASSERT(Unk_1682630, field_47d, 0x47d);

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
    u32 vf23();
    void vf25(Unk_1681dd0_arg1* value, u32 arg2);
    u32 vf41();
    void vf48();
    void vf50();
    bool vf52();
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

// 0x71016825e0
u32 nn::pia::local::LdnProtocol::vf23() {
    Unk_16825e0* self = reinterpret_cast<Unk_16825e0*>(this);
    u32 r0 = self->vf21();
    u32 r1 = self->vf22();
    return r1 + r0;
}

// 0x7101682620
void nn::pia::local::LdnProtocol::vf50() {
}

// 0x7101682630
bool nn::pia::local::LdnProtocol::vf52() {
    const Unk_1682630* self = reinterpret_cast<const Unk_1682630*>(this);
    if (self->field_47d == 0) {
        return false;
    }
    return self->field_418 == 0;
}

// 0x7101692f40
void nn::pia::local::LdnProtocol::vf48() {
    Unk_1692f40* self = reinterpret_cast<Unk_1692f40*>(this);
    self->field_300->vf3(self);
}
