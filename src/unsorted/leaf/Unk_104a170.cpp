// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104a170 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_104a170, field_0, 0x0);

// 0x710104a170
u32 Unk_104a170_getField0(const Unk_104a170* self) {
    return self->field_0;
}

struct Unk_104a180 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_104a180, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_104a180, field_10, 0x10);

// 0x710104a180
u64 Unk_104a180_get(const Unk_104a180* self) {
    return self->field_10 - self->field_8;
}

struct Unk_104a190 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_104a190, field_8, 0x8);

// 0x710104a190
u64 Unk_104a190_getField8(const Unk_104a190* self) {
    return self->field_8;
}

struct Unk_104a300 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_104a300, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_104a300, field_10, 0x10);

void Unk_65c700(u64, u64);

// 0x710104a300
void Unk_104a300_call(const Unk_104a300* self) {
    Unk_65c700(self->field_8, self->field_10 - self->field_8);
}
