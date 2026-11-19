// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia7session15SessionInfoListINS0_3nex21NexSessionInfoPrivateEEE
#include <types.h>

struct Unk_16d7ee0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16d7ee0, field_10, 0x10);

struct Unk_16d7ef0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16d7ef0, field_10, 0x10);

struct Unk_16d7f20 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d7f20, field_8, 0x8);

struct Unk_16d7f30 {
    u8 _0[0xa];
    u16 field_a;
};
PKMN_OFFSET_ASSERT(Unk_16d7f30, field_a, 0xa);

namespace nn { namespace pia { namespace nex { class NexSessionInfoPrivate; } } }
namespace nn { namespace pia { namespace session { template <class T0> class SessionInfoList; } } }

namespace nn {
namespace pia {
namespace session {
template <> class SessionInfoList<nn::pia::nex::NexSessionInfoPrivate> {
public:
    u64 vf2();
    u64 vf3();
    u16 vf6();
    u16 vf7();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x71016d7ee0
u64 nn::pia::session::SessionInfoList<nn::pia::nex::NexSessionInfoPrivate>::vf2() {
    const Unk_16d7ee0* self = reinterpret_cast<const Unk_16d7ee0*>(this);
    return self->field_10;
}

// 0x71016d7ef0
u64 nn::pia::session::SessionInfoList<nn::pia::nex::NexSessionInfoPrivate>::vf3() {
    const Unk_16d7ef0* self = reinterpret_cast<const Unk_16d7ef0*>(this);
    return self->field_10;
}

// 0x71016d7f20
u16 nn::pia::session::SessionInfoList<nn::pia::nex::NexSessionInfoPrivate>::vf6() {
    const Unk_16d7f20* self = reinterpret_cast<const Unk_16d7f20*>(this);
    return self->field_8;
}

// 0x71016d7f30
u16 nn::pia::session::SessionInfoList<nn::pia::nex::NexSessionInfoPrivate>::vf7() {
    const Unk_16d7f30* self = reinterpret_cast<const Unk_16d7f30*>(this);
    return self->field_a;
}
