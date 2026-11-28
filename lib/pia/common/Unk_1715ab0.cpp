// Scope: common
// Indexed getters of one of Pia's objects, between the getters
// tools/leafgen.py wrote (lib/nx_middleware/leaf/Unk_170e810.cpp). Names are
// placeholders (lib/pia/README.md).
#include "types.h"

// The object 0x7101715cf0 and 0x7101715d00 read: six u32 from 0x18 and six
// bytes from 0x30.
struct Unk_1715cf0_arg0 {
    u8 _0[0x18];
    u32 field_18[6];
    u8 field_30[6];
};
PKMN_OFFSET_ASSERT(Unk_1715cf0_arg0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1715cf0_arg0, field_30, 0x30);

// 0x7101715cf0
u8 Unk_1715cf0(const Unk_1715cf0_arg0* self, u32 index) {
    return self->field_30[index];
}

// 0x7101715d00
u32 Unk_1715d00(const Unk_1715cf0_arg0* self, u32 index) {
    if (index < 6) {
        return self->field_18[index];
    }
    return 0;
}
