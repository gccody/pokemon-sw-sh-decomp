// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17399c0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17399c0, field_10, 0x10);

namespace nn {
namespace pia {
namespace transport {
namespace ReliableSlidingWindow {
class MessageHeader {
public:
    u32 vf4();
};
}  // namespace ReliableSlidingWindow
}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x71017399c0
u32 nn::pia::transport::ReliableSlidingWindow::MessageHeader::vf4() {
    const Unk_17399c0* self = reinterpret_cast<const Unk_17399c0*>(this);
    return (self->field_10 << 3) + 9;
}
