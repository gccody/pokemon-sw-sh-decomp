// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia9transport13PacketHandlerE
#include <types.h>

struct Unk_16a99f0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16a99f0, field_8, 0x8);

struct Unk_16a9a00 {
    u8 _0[0x2c];
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_16a9a00, field_2c, 0x2c);

struct Unk_16a9a10 {
    u8 _0[0x2d];
    u8 field_2d;
};
PKMN_OFFSET_ASSERT(Unk_16a9a10, field_2d, 0x2d);

namespace nn {
namespace pia {
namespace transport {
class PacketHandler {
public:
    void vf10(u64 value);
    u8 vf12();
    u8 vf13();
    void vf11();
};
}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x71016a99f0
void nn::pia::transport::PacketHandler::vf10(u64 value) {
    Unk_16a99f0* self = reinterpret_cast<Unk_16a99f0*>(this);
    self->field_8 = value;
}

// 0x71016a9a00
u8 nn::pia::transport::PacketHandler::vf12() {
    const Unk_16a9a00* self = reinterpret_cast<const Unk_16a9a00*>(this);
    return self->field_2c;
}

// 0x71016a9a10
u8 nn::pia::transport::PacketHandler::vf13() {
    const Unk_16a9a10* self = reinterpret_cast<const Unk_16a9a10*>(this);
    return self->field_2d;
}

// 0x710173b2f0
void nn::pia::transport::PacketHandler::vf11() {
}
