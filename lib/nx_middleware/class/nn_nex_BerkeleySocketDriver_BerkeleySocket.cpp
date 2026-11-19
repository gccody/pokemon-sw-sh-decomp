// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20BerkeleySocketDriver14BerkeleySocketE
#include <types.h>

struct Unk_1617390 {
    u8 _0[0x14];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1617390, field_14, 0x14);

struct Unk_1621f90 {
    u8 _0[0x15];
    u8 field_15;
};
PKMN_OFFSET_ASSERT(Unk_1621f90, field_15, 0x15);

struct Unk_16177a0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_16177a0, field_c, 0xc);

namespace nn { namespace socket { u64 SetSockOpt(s32, s32, s32, const void*, u32); } }

struct Unk_1621fc0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1621fc0, field_c, 0xc);

namespace nn {
namespace nex {
namespace BerkeleySocketDriver {
class BerkeleySocket {
public:
    u8 vf9();
    u8 vf10();
    u32 vf11();
    u32 vf15();
    bool vf16(u8 value);
    void vf17();
    u32 vf18();
    const char* vf19();
    void vf20();
    void vf21();
};
}  // namespace BerkeleySocketDriver
}  // namespace nex
}  // namespace nn

// 0x7101616bf0
void nn::nex::BerkeleySocketDriver::BerkeleySocket::vf21() {
}

// 0x7101617390
u8 nn::nex::BerkeleySocketDriver::BerkeleySocket::vf9() {
    const Unk_1617390* self = reinterpret_cast<const Unk_1617390*>(this);
    return self->field_14;
}

// 0x7101617790
u32 nn::nex::BerkeleySocketDriver::BerkeleySocket::vf15() {
    return 1;
}

// 0x71016177a0
bool nn::nex::BerkeleySocketDriver::BerkeleySocket::vf16(u8 value) {
    const Unk_16177a0* self = reinterpret_cast<const Unk_16177a0*>(this);
    u32 l4;
    l4 = value;
    u32 r0 = nn::socket::SetSockOpt(self->field_c, 0, 4, &l4, 4);
    return r0 == 0;
}

// 0x7101621f90
u8 nn::nex::BerkeleySocketDriver::BerkeleySocket::vf10() {
    const Unk_1621f90* self = reinterpret_cast<const Unk_1621f90*>(this);
    return self->field_15;
}

// 0x7101621fa0
u32 nn::nex::BerkeleySocketDriver::BerkeleySocket::vf11() {
    return 1;
}

// 0x7101621fb0
void nn::nex::BerkeleySocketDriver::BerkeleySocket::vf17() {
}

// 0x7101621fc0
u32 nn::nex::BerkeleySocketDriver::BerkeleySocket::vf18() {
    const Unk_1621fc0* self = reinterpret_cast<const Unk_1621fc0*>(this);
    return self->field_c;
}

// 0x7101621fd0
const char* nn::nex::BerkeleySocketDriver::BerkeleySocket::vf19() {
    return "BerkeleySocketDriver::BerkeleySocket";
}

// 0x7101621fe0
void nn::nex::BerkeleySocketDriver::BerkeleySocket::vf20() {
}
