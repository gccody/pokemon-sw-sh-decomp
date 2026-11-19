// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia9transport21ReliableSlidingWindowE
#include <types.h>

struct Unk_1744720 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u64);
    u8 _8[0x328];
    u64 field_330;
};
PKMN_OFFSET_ASSERT(Unk_1744720, field_330, 0x330);

struct Unk_1747b90 {
    u8 _0[0x330];
    u64 field_330;
};
PKMN_OFFSET_ASSERT(Unk_1747b90, field_330, 0x330);

namespace nn {
namespace pia {
namespace transport {
class ReliableSlidingWindow {
public:
    void vf4();
    u64 vf6();
    u32 vf8();
    u32 vf11();
};
}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x7101744720
void nn::pia::transport::ReliableSlidingWindow::vf4() {
    Unk_1744720* self = reinterpret_cast<Unk_1744720*>(this);
    self->vf5(self->field_330);
}

// 0x7101746cb0
u32 nn::pia::transport::ReliableSlidingWindow::vf8() {
    return 0;
}

// 0x71017474f0
u32 nn::pia::transport::ReliableSlidingWindow::vf11() {
    return 0;
}

// 0x7101747b90
u64 nn::pia::transport::ReliableSlidingWindow::vf6() {
    const Unk_1747b90* self = reinterpret_cast<const Unk_1747b90*>(this);
    return self->field_330;
}
