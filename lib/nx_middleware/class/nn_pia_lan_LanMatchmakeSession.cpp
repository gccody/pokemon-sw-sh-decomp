// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16675d0 {
    u8 _0[0x16c0];
    u64 field_16c0;
};
PKMN_OFFSET_ASSERT(Unk_16675d0, field_16c0, 0x16c0);

struct Unk_1722890 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1722890, field_10, 0x10);

struct Unk_17228a0 {
    u8 _0[0x10];
    bool field_10;
};
PKMN_OFFSET_ASSERT(Unk_17228a0, field_10, 0x10);

struct Unk_1722870 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1722870, field_8, 0x8);

struct Unk_1722880 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1722880, field_8, 0x8);

struct Unk_1667570 {
    u8 _0[0x1718];
    u8 field_1718;
};
PKMN_OFFSET_ASSERT(Unk_1667570, field_1718, 0x1718);

namespace nn {
namespace pia {
namespace lan {
class LanMatchmakeSession {
public:
    u64 vf7();
    u64 vf24();
    u32 vf25();
    u64 vf26();
    u8 vf28();
    void vf29(bool value);
    u64 vf30();
    void vf31(u64 value);
    u32 vf33();
    const u8* vf36();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101667570
const u8* nn::pia::lan::LanMatchmakeSession::vf36() {
    const Unk_1667570* self = reinterpret_cast<const Unk_1667570*>(this);
    return &self->field_1718;
}

// 0x71016675d0
u64 nn::pia::lan::LanMatchmakeSession::vf7() {
    const Unk_16675d0* self = reinterpret_cast<const Unk_16675d0*>(this);
    return self->field_16c0;
}

// 0x7101722870
u64 nn::pia::lan::LanMatchmakeSession::vf30() {
    const Unk_1722870* self = reinterpret_cast<const Unk_1722870*>(this);
    return self->field_8;
}

// 0x7101722880
void nn::pia::lan::LanMatchmakeSession::vf31(u64 value) {
    Unk_1722880* self = reinterpret_cast<Unk_1722880*>(this);
    self->field_8 = value;
}

// 0x7101722890
u8 nn::pia::lan::LanMatchmakeSession::vf28() {
    const Unk_1722890* self = reinterpret_cast<const Unk_1722890*>(this);
    return self->field_10;
}

// 0x71017228a0
void nn::pia::lan::LanMatchmakeSession::vf29(bool value) {
    Unk_17228a0* self = reinterpret_cast<Unk_17228a0*>(this);
    self->field_10 = value;
}

// 0x71017228b0
u64 nn::pia::lan::LanMatchmakeSession::vf24() {
    return 0;
}

// 0x71017228c0
u32 nn::pia::lan::LanMatchmakeSession::vf25() {
    return 0;
}

// 0x71017228d0
u64 nn::pia::lan::LanMatchmakeSession::vf26() {
    return 0;
}

// 0x7101722940
u32 nn::pia::lan::LanMatchmakeSession::vf33() {
    return 0;
}
