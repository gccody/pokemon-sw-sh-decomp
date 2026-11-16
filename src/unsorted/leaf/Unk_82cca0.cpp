// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82cca0 {
    u8 _0[0xb48];
    u8 field_b48;
};
PKMN_OFFSET_ASSERT(Unk_82cca0, field_b48, 0xb48);

// 0x710082cca0
void Unk_82cca0_clearFieldb48(Unk_82cca0* self) {
    self->field_b48 = 0;
}

struct Unk_82ccb0 {
    u8 _0[0xb48];
    u8 field_b48;
};
PKMN_OFFSET_ASSERT(Unk_82ccb0, field_b48, 0xb48);

// 0x710082ccb0
u8 Unk_82ccb0_getFieldb48(const Unk_82ccb0* self) {
    return self->field_b48;
}
