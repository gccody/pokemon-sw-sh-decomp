// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia7session15SessionInfoListINS0_5local14LdnSessionInfoEEE
#include <types.h>

struct Unk_167ce40 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_167ce40, field_10, 0x10);

struct Unk_167ce50 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_167ce50, field_10, 0x10);

struct Unk_167ce80 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_167ce80, field_8, 0x8);

struct Unk_167ce90 {
    u8 _0[0xa];
    u16 field_a;
};
PKMN_OFFSET_ASSERT(Unk_167ce90, field_a, 0xa);

namespace nn { namespace pia { namespace local { class LdnSessionInfo; } } }
namespace nn { namespace pia { namespace session { template <class T0> class SessionInfoList; } } }

namespace nn {
namespace pia {
namespace session {
template <> class SessionInfoList<nn::pia::local::LdnSessionInfo> {
public:
    u64 vf2();
    u64 vf3();
    u16 vf6();
    u16 vf7();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x710167ce40
u64 nn::pia::session::SessionInfoList<nn::pia::local::LdnSessionInfo>::vf2() {
    const Unk_167ce40* self = reinterpret_cast<const Unk_167ce40*>(this);
    return self->field_10;
}

// 0x710167ce50
u64 nn::pia::session::SessionInfoList<nn::pia::local::LdnSessionInfo>::vf3() {
    const Unk_167ce50* self = reinterpret_cast<const Unk_167ce50*>(this);
    return self->field_10;
}

// 0x710167ce80
u16 nn::pia::session::SessionInfoList<nn::pia::local::LdnSessionInfo>::vf6() {
    const Unk_167ce80* self = reinterpret_cast<const Unk_167ce80*>(this);
    return self->field_8;
}

// 0x710167ce90
u16 nn::pia::session::SessionInfoList<nn::pia::local::LdnSessionInfo>::vf7() {
    const Unk_167ce90* self = reinterpret_cast<const Unk_167ce90*>(this);
    return self->field_a;
}
