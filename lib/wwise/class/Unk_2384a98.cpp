// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dc870 {
    u8 _0[0x94];
    u32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_3dc870, field_94, 0x94);

class Unk_2384a98 {
public:
    u32 vf31();
};

// 0x71003dc870
u32 Unk_2384a98::vf31() {
    const Unk_3dc870* self = reinterpret_cast<const Unk_3dc870*>(this);
    return self->field_94;
}
