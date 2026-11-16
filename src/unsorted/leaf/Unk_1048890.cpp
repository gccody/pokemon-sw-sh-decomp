// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1048890 {
    u8 _0[0x118];
    u8 field_118;
};
PKMN_OFFSET_ASSERT(Unk_1048890, field_118, 0x118);

// 0x7101048890
u8* Unk_1048890_getField118Ptr(Unk_1048890* self) {
    return &self->field_118;
}

struct Unk_10488a0 {
    u8 _0[0x100];
    u8 field_100;
};
PKMN_OFFSET_ASSERT(Unk_10488a0, field_100, 0x100);

// 0x71010488a0
u8* Unk_10488a0_getField100Ptr(Unk_10488a0* self) {
    return &self->field_100;
}

// 0x71010488b0
void Unk_10488b0() {}

// 0x71010489f0
void Unk_10489f0() {}
