// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_173ad90_arg1 {
    u8 _0[0x5e8];
    u32 field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_173ad90_arg1, field_5e8, 0x5e8);

namespace nn {
namespace pia {
namespace transport {
class PacketReader {
public:
    void vf11();
    u32 vf22(const Unk_173ad90_arg1* value);
    u32 vf23();
    u32 vf24();
};
}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x710173ad90
u32 nn::pia::transport::PacketReader::vf22(const Unk_173ad90_arg1* value) {
    return value->field_5e8;
}

// 0x710173ada0
u32 nn::pia::transport::PacketReader::vf23() {
    return 1;
}

// 0x710173adb0
u32 nn::pia::transport::PacketReader::vf24() {
    return 1;
}

// 0x710173afb0
void nn::pia::transport::PacketReader::vf11() {
}
