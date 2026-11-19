// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_499f40_78 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_499f40_78, field_78, 0x78);

struct Unk_499f40 {
    u8 _0[0x78];
    Unk_499f40_78* field_78;
};
PKMN_OFFSET_ASSERT(Unk_499f40, field_78, 0x78);

namespace PPFX {
class IGPUEffect {
public:
    u64 vf9();
    u32 vf13();
};
}  // namespace PPFX

// 0x7100499f40
u64 PPFX::IGPUEffect::vf9() {
    const Unk_499f40* self = reinterpret_cast<const Unk_499f40*>(this);
    return self->field_78->field_78;
}

// 0x7100499f90
u32 PPFX::IGPUEffect::vf13() {
    return 0;
}
