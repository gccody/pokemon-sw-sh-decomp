// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia7session15SessionInfoListINS0_3lan21LanSessionInfoPrivateEEE
#include <types.h>

struct Unk_1663860 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1663860, field_10, 0x10);

struct Unk_1663870 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1663870, field_10, 0x10);

struct Unk_16638a0 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16638a0, field_8, 0x8);

struct Unk_16638b0 {
    u8 _0[0xa];
    u16 field_a;
};
PKMN_OFFSET_ASSERT(Unk_16638b0, field_a, 0xa);

namespace nn { namespace pia { namespace lan { class LanSessionInfoPrivate; } } }
namespace nn { namespace pia { namespace session { template <class T0> class SessionInfoList; } } }

namespace nn {
namespace pia {
namespace session {
template <> class SessionInfoList<nn::pia::lan::LanSessionInfoPrivate> {
public:
    u64 vf2();
    u64 vf3();
    u16 vf6();
    u16 vf7();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x7101663860
u64 nn::pia::session::SessionInfoList<nn::pia::lan::LanSessionInfoPrivate>::vf2() {
    const Unk_1663860* self = reinterpret_cast<const Unk_1663860*>(this);
    return self->field_10;
}

// 0x7101663870
u64 nn::pia::session::SessionInfoList<nn::pia::lan::LanSessionInfoPrivate>::vf3() {
    const Unk_1663870* self = reinterpret_cast<const Unk_1663870*>(this);
    return self->field_10;
}

// 0x71016638a0
u16 nn::pia::session::SessionInfoList<nn::pia::lan::LanSessionInfoPrivate>::vf6() {
    const Unk_16638a0* self = reinterpret_cast<const Unk_16638a0*>(this);
    return self->field_8;
}

// 0x71016638b0
u16 nn::pia::session::SessionInfoList<nn::pia::lan::LanSessionInfoPrivate>::vf7() {
    const Unk_16638b0* self = reinterpret_cast<const Unk_16638b0*>(this);
    return self->field_a;
}
