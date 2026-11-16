// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1331d50 {
    u8 _0[0x1c0];
    u64 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_1331d50, field_1c0, 0x1c0);

// 0x7101331d50
u64 Unk_1331d50_getField1c0(const Unk_1331d50* self) {
    return self->field_1c0;
}

struct Unk_1331d60 {
    u8 _0[0x1e0];
    u64 field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_1331d60, field_1e0, 0x1e0);

// 0x7101331d60
u64 Unk_1331d60_getField1e0(const Unk_1331d60* self) {
    return self->field_1e0;
}

struct Unk_1331d70 {
    u8 _0[0x200];
    u64 field_200;
};
PKMN_OFFSET_ASSERT(Unk_1331d70, field_200, 0x200);

// 0x7101331d70
u64 Unk_1331d70_getField200(const Unk_1331d70* self) {
    return self->field_200;
}

struct Unk_1331eb0 {
    u8 _0[0x260];
    u8 field_260;
};
PKMN_OFFSET_ASSERT(Unk_1331eb0, field_260, 0x260);

// 0x7101331eb0
u8* Unk_1331eb0_getField260Ptr(Unk_1331eb0* self) {
    return &self->field_260;
}
