// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N4pead14SafeStringBaseIcEE
#include <types.h>

struct Unk_171b250_arg1 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_171b250_arg1, field_8, 0x8);

struct Unk_171b250 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_171b250, field_8, 0x8);

namespace pead { template <class T0> class SafeStringBase; }

namespace pead {
template <> class SafeStringBase<char> {
public:
    void vf2(const Unk_171b250_arg1* value);
    void vf3();
};
}  // namespace pead

// 0x7101652930
void pead::SafeStringBase<char>::vf3() {
}

// 0x710171b250
void pead::SafeStringBase<char>::vf2(const Unk_171b250_arg1* value) {
    Unk_171b250* self = reinterpret_cast<Unk_171b250*>(this);
    self->field_8 = value->field_8;
}
