// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fd7f20 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_fd7f20, field_60, 0x60);

// 0x7100fd7f20
void Unk_fd7f20_setField60(Unk_fd7f20* self, u64 value) {
    self->field_60 = value;
}

struct Unk_fd7f30 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_fd7f30, field_68, 0x68);

// 0x7100fd7f30
void Unk_fd7f30_setField68(Unk_fd7f30* self, u64 value) {
    self->field_68 = value;
}

struct Unk_fd80a0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_fd80a0, field_78, 0x78);

// 0x7100fd80a0
void Unk_fd80a0_setField78(Unk_fd80a0* self, u64 value) {
    self->field_78 = value;
}

struct Unk_fd80b0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_fd80b0, field_78, 0x78);

// 0x7100fd80b0
u64 Unk_fd80b0_getField78(const Unk_fd80b0* self) {
    return self->field_78;
}
