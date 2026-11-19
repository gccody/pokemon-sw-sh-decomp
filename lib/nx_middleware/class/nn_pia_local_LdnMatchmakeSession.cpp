// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_167e7c0 {
    u8 _0[0x550];
    u64 field_550;
};
PKMN_OFFSET_ASSERT(Unk_167e7c0, field_550, 0x550);

struct Unk_167e450 {
    u8 _0[0x558];
    u64 field_558;
};
PKMN_OFFSET_ASSERT(Unk_167e450, field_558, 0x558);

struct Unk_167e860 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_167e860, field_78, 0x78);

namespace nn {
namespace pia {
namespace local {
class LdnMatchmakeSession {
public:
    u32 vf4();
    u64 vf7();
    u32 vf21();
    u64 vf36();
    u32 vf38();
    const u8* vf44();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167e450
u64 nn::pia::local::LdnMatchmakeSession::vf36() {
    const Unk_167e450* self = reinterpret_cast<const Unk_167e450*>(this);
    return self->field_558;
}

// 0x710167e7c0
u64 nn::pia::local::LdnMatchmakeSession::vf7() {
    const Unk_167e7c0* self = reinterpret_cast<const Unk_167e7c0*>(this);
    return self->field_550;
}

// 0x710167e850
u32 nn::pia::local::LdnMatchmakeSession::vf38() {
    return 0;
}

// 0x710167e860
const u8* nn::pia::local::LdnMatchmakeSession::vf44() {
    const Unk_167e860* self = reinterpret_cast<const Unk_167e860*>(this);
    return &self->field_78;
}

// 0x710168cac0
u32 nn::pia::local::LdnMatchmakeSession::vf4() {
    return 0;
}

// 0x710168d620
u32 nn::pia::local::LdnMatchmakeSession::vf21() {
    return 0;
}
