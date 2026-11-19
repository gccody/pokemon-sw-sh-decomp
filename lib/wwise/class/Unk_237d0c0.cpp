// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_312a40 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_312a40, field_78, 0x78);

class Unk_237d0c0 {
public:
    u64 vf22();
};

// 0x7100312a40
u64 Unk_237d0c0::vf22() {
    const Unk_312a40* self = reinterpret_cast<const Unk_312a40*>(this);
    return self->field_78;
}
